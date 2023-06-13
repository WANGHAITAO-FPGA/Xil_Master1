package Common.Endat

import Board_Test.TxRx_Top
import Common.PHPA.ila_test.ila
import Common.PHPA.{EndatInterface, PHPA_MMCME2}
import Common.Xil_BlackBox.{Aurora_8B10B_Master_A7, ENDAT22_IP, Gtx_IO, IBUFDS_GTE2}
import spinal.core._
import spinal.lib.com.spi.SpiMasterCtrlGenerics
import spinal.lib.misc.Timer
import spinal.lib.{CounterFreeRun, StreamCCByToggle, master}

case class Endat_Top(endat_num : Int) extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val led = out Bool()
    val endat = Seq.fill(endat_num)(master(EndatInterface()))
    val lspi = Seq.fill(endat_num)(master(LspiInterface()))
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

      val postion_fifo = Seq.fill(endat_num)(StreamCCByToggle(Bits(38 bits),ClockDomain(mmcm.io.clk_100M,~mmcm.io.locked),ClockDomain(auro.qpll_control.user_clk,gt_reset)))
      val rm_fifo = Seq.fill(endat_num)(StreamCCByToggle(Bits(32 bits),ClockDomain(mmcm.io.clk_100M,~mmcm.io.locked),ClockDomain(auro.qpll_control.user_clk,gt_reset)))

      val endat_ipctrl = Seq.fill(endat_num)(Endat_IpCtrl(true))
      for(i <- 0 until endat_num){
        endat_ipctrl(i).io.endat <> io.endat(i)
        endat_ipctrl(i).io.clk <> mmcm.io.clk_100M
        endat_ipctrl(i).io.reset <> ~mmcm.io.locked
        endat_ipctrl(i).io.lspi <> io.lspi(i)

        postion_fifo(i).io.input.payload := endat_ipctrl(i).io.postion
        postion_fifo(i).io.input.valid := endat_ipctrl(i).io.tick
        postion_fifo(i).io.output.ready := True

        rm_fifo(i).io.input.payload := endat_ipctrl(i).io.rm.asBits.resized
        rm_fifo(i).io.input.valid := endat_ipctrl(i).io.tick
        rm_fifo(i).io.output.ready := True
      }

      val gtx_area = new ClockingArea(ClockDomain(auro.qpll_control.user_clk,gt_reset)){
        val timer_A = Timer(32)
        timer_A.io.tick := True
        timer_A.io.limit := 6250
        when(timer_A.io.value >= timer_A.io.limit){
          timer_A.io.clear := True
        }otherwise{
          timer_A.io.clear := False
        }

        val tx_rx = TxRx_Top(32,true)
        tx_rx.io.input << auro.m_axi_rx.m_axi_rx.toStream
//        tx_rx.io.input.ready := True
        auro.s_axi_tx.s_axi_tx << tx_rx.io.output
        tx_rx.io.tx_tick := timer_A.io.full
        tx_rx.io.tx_head := B"32'x00000009"
        tx_rx.io.frame_head := B"64'x00F1F2F30000000F"

        val endat_postin = Vec(Reg(Bits(38 bits)),endat_num)

        when(!tx_rx.io.busy){
          for(i <- 0 until endat_num){
            endat_postin(i) := postion_fifo(i).io.output.payload
          }
        }
        for(i <- 0 until endat_num){
          tx_rx.io.Board_TxData(3*i) := endat_postin(i)(37 downto 32).resized
          tx_rx.io.Board_TxData(3*i+1) := endat_postin(i)(31 downto 0)
          tx_rx.io.Board_TxData(3*i+2) := rm_fifo(i).io.output.payload
        }

        for(i <- 3*endat_num until 64){
          tx_rx.io.Board_TxData(i) := 0
        }

        val ila_probe=ila("1",auro.s_axi_tx.s_axi_tx.ready,auro.s_axi_tx.s_axi_tx.valid,
          auro.s_axi_tx.s_axi_tx.payload.fragment,auro.s_axi_tx.s_axi_tx.payload.last,
          auro.m_axi_rx.m_axi_rx.valid,auro.m_axi_rx.m_axi_rx.payload.fragment,
          auro.m_axi_rx.m_axi_rx.payload.last,auro.status.lane_up,auro.status.channel_up)
      }

      val ledtemp = Reg(Bool()) init False

      val counter =  CounterFreeRun(50000000)
      when(counter.willOverflow){
        counter.clear()
        ledtemp := ~ledtemp;
      }
      io.led := ledtemp
    }
  }
}

object Endat_Top extends App{
  SpinalConfig(
    anonymSignalPrefix = "temp",
    headerWithDate = true,
    targetDirectory = "D:/YW/Endat_IP_Test/Endat_IP_Test.srcs/sources_1/new/",
    nameWhenByFile = false,
    genLineComments = false
  ).generateVerilog(Endat_Top(3))
}