package Common.PHPA

import Board_Test.Apb_TxRxSimple
import Common.PHPA.ila_test.ila
import Common.PHPA.regFileGen.genRegFileByMarkdown
import Common.Xil_BlackBox._
import spinal.core._
import spinal.lib.blackbox.xilinx.s7.{BUFG, IBUF}
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Decoder}
import spinal.lib.bus.misc.SizeMapping
import spinal.lib.io.InOutWrapper
import spinal.lib.{CounterFreeRun, master}

import scala.collection.mutable.ArrayBuffer

case class PHPA_MMCME2() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val reset = in Bool()
    val clk_100M = out Bool()
    val clk_200M = out Bool()
    val locked = out Bool()
  }
  noIoPrefix()

  val attr = new MMCME2Attrs
  attr.CLKIN1_PERIOD = 40.0
  attr.CLKFBOUT_MULT_F = 40
  attr.CLKOUT0_DIVIDE_F = 10.0
  attr.CLKOUT1_DIVIDE = 5

  val sysclk = BUFG.on(io.sysclk)

  val mmcm = MMCME2_BASE(attr).setName("MMCME2_BASE")
  mmcm.CLKIN1 := sysclk
  mmcm.RST := io.reset
  mmcm.PWRDWN := False
  mmcm.CLKFBIN := mmcm.CLKFBOUT
  io.clk_100M := IBUF.on(mmcm.CLKOUT0)
  io.clk_200M := IBUF.on(mmcm.CLKOUT1)
  io.locked := mmcm.LOCKED
}

case class PHPA82_NEW(sramLayout : SramLayout) extends Component{
  val io = new Bundle{
    val emif = master(SramInterface(sramLayout))
    val ad5544 = Seq.fill(3)(master(Ad5544Interface()))
    val ad7606 = master(Ad7606_Interface(true,false,false))
    val grating_io = Seq.fill(2)(master(Grating_IO()))
    val bissc = Seq.fill(4)(master(BissCInterface()))
    val sysclk = in Bool()
    //val reset_n = in Bool()
    val led = out Bool()
    for(i <- 0 until 2){
      grating_io(i).IO_A_READ.setName(s"IO_A_READ_$i")
      grating_io(i).IO_A_WRITE.setName(s"IO_A_WRITE_$i")
      grating_io(i).IO_A_WRITEENABLE.setName(s"IO_A_WE_$i")
      grating_io(i).IO_B_READ.setName(s"IO_B_READ_$i")
      grating_io(i).IO_B_WRITE.setName(s"IO_B_WRITE_$i")
      grating_io(i).IO_B_WRITEENABLE.setName(s"IO_B_WE_$i")
      grating_io(i).IO_C_READ.setName(s"IO_C_READ_$i")
      grating_io(i).IO_C_WRITE.setName(s"IO_C_WRITE_$i")
      grating_io(i).IO_C_WRITEENABLE.setName(s"IO_C_WE_$i")
    }
    val gt_io = Gtx_IO(1)
    val gt_ref_clkp = in Bool()
    val gt_ref_clkn = in Bool()
  }
  noIoPrefix()

  val mmcmarea = new ClockingArea(ClockDomain(io.sysclk,config = ClockDomainConfig(resetActiveLevel = LOW))){
    val mmcm = PHPA_MMCME2()
    mmcm.io.sysclk := io.sysclk
    mmcm.io.reset := False

    val idbuf = new IBUFDS_GTE2
    idbuf.I := io.gt_ref_clkp
    idbuf.IB := io.gt_ref_clkn
    idbuf.CEB := False

    val gt_ref_clk = idbuf.O

    val area = new ClockingArea(ClockDomain(mmcm.io.clk_100M,~mmcm.io.locked)){
      val link_status = Reg(Bool()) init False
      val resetUnbuffered   = False
      val gt_resetUnbuffered  = False
      val Counter = Reg(UInt(8 bits)) init(0)

      val ResetCounter = Reg(UInt(8 bits)) init(0)
      when(ResetCounter =/= U(ResetCounter.range -> true)){
        ResetCounter := ResetCounter + 1
        resetUnbuffered := True
      }

      val link_resetCounter = Reg(UInt(20 bits)) init(0)
      val Gt_ResetCounter = Reg(UInt(9 bits)) init(0)
      when(Gt_ResetCounter =/= U(Gt_ResetCounter.range -> true)){
        Gt_ResetCounter := Gt_ResetCounter + 1
        gt_resetUnbuffered := True
      }otherwise{
        when(!link_status){
          when(link_resetCounter(19)){
            Counter := 0
          }otherwise{
            link_resetCounter := link_resetCounter + 1
          }
        }
      }

      val reset = RegNext(resetUnbuffered)
      val gt_reset = RegNext(gt_resetUnbuffered)

      val auro = Aurora_8B10B_Master_A7(32)
      auro.init()
      auro.gt_reset := gt_reset
      auro.reset := reset
      auro.init_clk_in := mmcm.io.clk_100M
      auro.drp.drpclk_in := mmcm.io.clk_100M
      auro.gt_refclk1 := gt_ref_clk
      auro.gt_rx <> io.gt_io.rx(0)
      auro.gt_tx <> io.gt_io.tx(0)

      val emif_interface = new Emif_Apb(sramLayout)
      io.emif <> emif_interface.io.emif

      val apbMapping = ArrayBuffer[(Apb3, SizeMapping)]()
      val ad5544_ctrl = Apb3_AD5544(8,16,3,0x000100)
      for(i <- 0 until 3){
        ad5544_ctrl.io.ad5544(i) <> io.ad5544(i)
        io.ad5544(i).CS.setName(s"AD5544_CS_$i")
        io.ad5544(i).LDAC.setName(s"AD5544_LDAC_$i")
        //io.ad5544(i).MSB.setName(s"AD5544_MSB_$i")
        io.ad5544(i).RS.setName(s"AD5544_RS_$i")
        io.ad5544(i).SCLK.setName(s"AD5544_SCLK_$i")
        io.ad5544(i).SDIN.setName(s"AD5544_SDIN_$i")
      }
      apbMapping += ad5544_ctrl.io.apb -> (0x000100, 256 Bytes)

      val ad7606_ctrl = Apb_AD7606(8,16,baseaddr = 0x000200)
      ad7606_ctrl.io.ad_7606 <> io.ad7606
      apbMapping += ad7606_ctrl.io.apb -> (0x000200, 256 Bytes)

      val grating_a_ctrl = Apb3_Grating(8,16,0,0x000300)
      grating_a_ctrl.io.grating_io <> io.grating_io(0)
      grating_a_ctrl.io.encoder_filter_clk := mmcm.io.clk_200M
      apbMapping += grating_a_ctrl.io.apb -> (0x000300, 256 Bytes)

      val grating_b_ctrl = Apb3_Grating(8,16,1,0x000400)
      grating_b_ctrl.io.grating_io <> io.grating_io(1)
      grating_b_ctrl.io.encoder_filter_clk := mmcm.io.clk_200M
      apbMapping += grating_b_ctrl.io.apb -> (0x000400, 256 Bytes)

      val bissc_ctrl = Apb3_Bissc(8,16,4,0x000500)
      for(i <- 0 until 4){
        io.bissc(i) <> bissc_ctrl.io.bissc(i)
        io.bissc(i).clk.setName(s"bissc_clk_$i")
        io.bissc(i).data.setName(s"bissc_data_$i")
      }
      apbMapping += bissc_ctrl.io.apb -> (0x000500, 256 Bytes)

      val gtx_ctrl = Apb_TxRxSimple()
      auro.s_axi_tx.s_axi_tx << gtx_ctrl.io.output
      gtx_ctrl.io.input << auro.m_axi_rx.m_axi_rx
      gtx_ctrl.io.gtx_clk := auro.qpll_control.user_clk
      apbMapping += gtx_ctrl.io.apb -> (0x001000, 1024 Bytes)

      val apbDecoder = Apb3Decoder(
        master = emif_interface.io.apb,
        slaves = apbMapping
      )

      val ledtemp = Reg(Bool()) init False

      val counter =  CounterFreeRun(50000000)
      when(counter.willOverflow){
        counter.clear()
        ledtemp := ~ledtemp;
      }
      io.led := ledtemp

//      val ila_probe=ila("1",io.emif.emif_cs,io.emif.emif_oe,io.emif.emif_we,io.emif.emif_data.write,io.emif.emif_data.writeEnable,io.emif.emif_data.read,io.emif.emif_addr,emif_interface.io.apb.PADDR,emif_interface.io.apb.PENABLE,
//        emif_interface.io.apb.PREADY,emif_interface.io.apb.PSEL,emif_interface.io.apb.PWDATA,emif_interface.io.apb.PRDATA)
//      io.ad5544(0).addAttribute("MARK_DEBUG","TRUE")
//      io.ad5544(1).addAttribute("MARK_DEBUG","TRUE")
//      io.ad5544(2).addAttribute("MARK_DEBUG","TRUE")
      gtx_ctrl.io.input.addAttribute("MARK_DEBUG","TRUE")
      gtx_ctrl.io.output.addAttribute("MARK_DEBUG","TRUE")
      auro.status.addAttribute("MARK_DEBUG","TRUE")

    }
    addPrePopTask(()=>genRegFileByMarkdown("PHPA82_NEWBOARD"))
  }
}

object PHPA82_NEW extends App{
  SpinalConfig(anonymSignalPrefix = "temp",headerWithDate = true,targetDirectory = "E:/PHPA82/PHPA82_NEW_HSSL/PHPA82_NEWBOARD.srcs/sources_1/new/").generateVerilog(InOutWrapper(PHPA82_NEW(SramLayout(19, 16))))
}