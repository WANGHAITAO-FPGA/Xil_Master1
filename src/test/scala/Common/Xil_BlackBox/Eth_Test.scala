package Common.Xil_BlackBox

import spinal.core._
import spinal.lib.blackbox.xilinx.s7.{BUFG, IBUF}

case class Eth_MMCME2() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val reset = in Bool()
    val clk_200M = out Bool()
    val locked = out Bool()
  }
  noIoPrefix()

  val attr = new MMCME2Attrs
  attr.CLKIN1_PERIOD = 40.0
  attr.CLKFBOUT_MULT_F = 40
  attr.CLKOUT0_DIVIDE_F = 5

  val sysclk = BUFG.on(io.sysclk)

  val mmcm = MMCME2_BASE(attr).setName("MMCME2_BASE")
  mmcm.CLKIN1 := sysclk
  mmcm.RST := io.reset
  mmcm.PWRDWN := False
  mmcm.CLKFBIN := mmcm.CLKFBOUT
  io.clk_200M := IBUF.on(mmcm.CLKOUT0)
  io.locked := mmcm.LOCKED
}


case class Eth_Test() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val sfp = Sfp()
    val gtrefclk_n = in Bool()
    val gtrefclk_p = in Bool()
  }
  noIoPrefix()

  val eth_area = new ClockingArea(ClockDomain(io.sysclk)){
    val mmcm = Eth_MMCME2()
    mmcm.io.sysclk := io.sysclk
    mmcm.io.reset := False

    val resetCtrlClockDomain = ClockDomain(mmcm.io.clk_200M,mmcm.io.locked,config = ClockDomainConfig(resetActiveLevel = LOW))
    val resetCtrl = new ClockingArea(resetCtrlClockDomain) {
      val resetUnbuffered   = False
      val ResetCounter = Reg(UInt(8 bits)) init(0)
      when(ResetCounter =/= U(ResetCounter.range -> true)){
        ResetCounter := ResetCounter + 1
        resetUnbuffered := True
      }
      val reset = RegNext(resetUnbuffered)
    }

    val eth_pcs = Ethernet_PCS()
    eth_pcs.io.sfp <> io.sfp
    eth_pcs.io.config.configuration_vector := B"5'x10"
    eth_pcs.io.config.an_adv_config_vector := B"x0021"
    eth_pcs.io.config.an_restart_config := False
    eth_pcs.io.config.signal_detect := True

    eth_pcs.io.gmii_clk.gtrefclk_n := io.gtrefclk_n
    eth_pcs.io.gmii_clk.gtrefclk_p := io.gtrefclk_p

    eth_pcs.io.gmii_clk.independent_clock_bufg := mmcm.io.clk_200M
    eth_pcs.io.gmii_clk.reset := resetCtrl.reset

    eth_pcs.io.gmii_pcs_pma.gmii_tx_en := False
    eth_pcs.io.gmii_pcs_pma.gmii_txd := 0
    eth_pcs.io.gmii_pcs_pma.gmii_tx_er := False
  }
}

object Eth_Test extends App{
  SpinalVerilog(new Eth_Test())
}