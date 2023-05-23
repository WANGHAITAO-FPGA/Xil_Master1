package Common.Xil_BlackBox

import Common.PrintXDC
import spinal.core._
import spinal.lib._
import spinal.lib.blackbox.xilinx.s7.{BUFG, IBUF, IOBUFDS}

case class MMCME2() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val reset = in Bool()
    val clk_100M = out Bool()
    val clk_out1 = out Bool()
    val locked = out Bool()
  }
  noIoPrefix()

  val attr = new MMCME2Attrs
  attr.CLKIN1_PERIOD = 40.0
  attr.CLKFBOUT_MULT_F = 40
  attr.CLKOUT0_DIVIDE_F = 10.0
  attr.CLKOUT1_DIVIDE = 10

  val sysclk = BUFG.on(io.sysclk)

  val mmcm = MMCME2_BASE(attr).setName("MMCME2_BASE")
  mmcm.CLKIN1 := sysclk
  mmcm.RST := io.reset
  mmcm.PWRDWN := False
  mmcm.CLKFBIN := mmcm.CLKFBOUT
  io.clk_100M := IBUF.on(mmcm.CLKOUT0)
  io.clk_out1 := IBUF.on(mmcm.CLKOUT1)
  io.locked := mmcm.LOCKED
}

case class Auro_Test() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val gt_io = Gtx_IO(2)
    val gt_ref_clkp = in Bool()
    val gt_ref_clkn = in Bool()
    val panel_led = out Bits(8 bits)
    val reset_n = in Bool()
  }
  noIoPrefix()

  val mmcmarea = new ClockingArea(ClockDomain(io.sysclk,io.reset_n,config = ClockDomainConfig(resetActiveLevel = LOW))){
    val mmcm = MMCME2()
    mmcm.io.sysclk := io.sysclk

    val mmcm_resetUnbuffered  = False
    val Counter = Reg(UInt(8 bits)) init(0) addTag(crossClockDomain)
    when(Counter =/= U(Counter.range -> true)){
      Counter := Counter + 1
      mmcm_resetUnbuffered := True
    }

    mmcm.io.reset := RegNext(mmcm_resetUnbuffered)|(~io.reset_n)

    val idbuf = new IBUFDS_GTE2
    idbuf.I := io.gt_ref_clkp
    idbuf.IB := io.gt_ref_clkn
    idbuf.CEB := False

    val gt_ref_clk = idbuf.O

    val resetCtrlClockDomain = ClockDomain(mmcm.io.clk_100M,mmcm.io.locked,config = ClockDomainConfig(resetActiveLevel = LOW))
    val resetCtrl = new ClockingArea(resetCtrlClockDomain) {
      val link_status = Reg(Bool()) init False
      val resetUnbuffered   = False
      val gt_resetUnbuffered  = False

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
    }

    val auro = Aurora_8B10B_Master_A7(32)

    val auro_slave = Aurora_8B10B_Slave_A7(32)

    auro.init()
    auro.gt_reset := resetCtrl.gt_reset
    auro.reset := resetCtrl.reset
    auro.init_clk_in := mmcm.io.clk_100M
    auro.drp.drpclk_in := mmcm.io.clk_100M
    auro.gt_refclk1 := gt_ref_clk
    auro.gt_rx <> io.gt_io.rx(0)
    auro.gt_tx <> io.gt_io.tx(0)

    val lane_up = RegNext(auro.status.lane_up)  addTag(crossClockDomain)
    lane_up.addAttribute("MARK_DEBUG","TRUE")

    val channel_up = RegNext(auro.status.channel_up)  addTag(crossClockDomain)
    channel_up.addAttribute("MARK_DEBUG","TRUE")

    auro.s_axi_tx.s_axi_tx.valid := False
    auro.s_axi_tx.s_axi_tx.payload.fragment := 0
    auro.s_axi_tx.s_axi_tx.payload.last := False

    auro_slave.qpll_control <> auro.qpll_control

    auro_slave.init()
    auro_slave.gt_reset := resetCtrl.gt_reset
    auro_slave.reset := resetCtrl.reset
    auro_slave.init_clk_in := mmcm.io.clk_100M
    auro_slave.gt_rx <> io.gt_io.rx(1)
    auro_slave.gt_tx <> io.gt_io.tx(1)
    auro_slave.gt_refclk1 := gt_ref_clk
    auro_slave.drp.drpclk_in := mmcm.io.clk_100M

    auro_slave.s_axi_tx.s_axi_tx.valid := False
    auro_slave.s_axi_tx.s_axi_tx.payload.fragment := 0
    auro_slave.s_axi_tx.s_axi_tx.payload.last := False

    val lane_up_1 = RegNext(auro_slave.status.lane_up)  addTag(crossClockDomain)
    lane_up_1.addAttribute("MARK_DEBUG","TRUE")

    val channel_up_1 = RegNext(auro_slave.status.channel_up) addTag(crossClockDomain)
    channel_up_1.addAttribute("MARK_DEBUG","TRUE")

    io.panel_led(0) := lane_up
    io.panel_led(1) := channel_up
    io.panel_led(2) := lane_up_1
    io.panel_led(3) := channel_up_1
    io.panel_led(4) := True
    io.panel_led(5) := True
    io.panel_led(6) := True
    io.panel_led(7) := True

    resetCtrl.link_status := lane_up & channel_up & lane_up_1 & channel_up_1
  }
}

object auro_demo extends App{
  SpinalConfig(headerWithDate = true,targetDirectory = "E:/TEST/auro_test/auro_test.srcs/sources_1/imports/Xil_Master/").generateVerilog(Auro_Test())
  PrintXDC("xdc","route.xdc")
}
