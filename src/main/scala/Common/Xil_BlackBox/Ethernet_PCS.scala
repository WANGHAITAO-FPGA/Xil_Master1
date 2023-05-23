package Common.Xil_BlackBox

import spinal.core._
import spinal.lib.{IMasterSlave, master}

case class Gmii_Pcs_Pma() extends Bundle with IMasterSlave{
  val gmii_rx_dv = Bool()
  val gmii_rx_er = Bool()
  val gmii_rxd = Bits(8 bits)
  val gmii_tx_en = Bool()
  val gmii_tx_er = Bool()
  val gmii_txd = Bits(8 bits)
  override def asMaster(): Unit = {
    in(gmii_tx_en,gmii_tx_er,gmii_txd)
    out(gmii_rx_dv,gmii_rx_er,gmii_rxd)
  }
}

case class GmiiClk() extends Bundle{
  val gtrefclk_n = in Bool()
  val gtrefclk_p = in Bool()
  val independent_clock_bufg = in Bool()  //200M
  val reset = in Bool()
}

/** xilinx.com pg047
 * configuration_vector
 *    bit0 : 0 ---normal_mode ; bit1 : loopback --active "1"; bit2 : powerdown; bit3 : isolate---0;bit4: auto-negotiation-enable----active 1
 * signal_detect
 *    1 ---表示不是光口
 * an_adv_config_vector
 *    bit5 : FULL duplex mode ----- active 1
 * an_restart_config----0
 *
 */

case class Config() extends Bundle{
  val configuration_vector = in Bits(5 bits)
  val an_adv_config_vector = in Bits(16 bits)
  val an_restart_config = in Bool()
  val signal_detect = in Bool()
  val status_vector = out Bits(16 bits)
}

case class Sfp() extends Bundle{
  val rxn = in Bool()
  val rxp = in Bool()
  val txn = out Bool()
  val txp = out Bool()
}

case class QPLL_CONTROL() extends Bundle{
  val gtrefclk_out = out Bool()
  val gtrefclk_bufg_out = out Bool()
  val userclk_out = out Bool()
  val userclk2_out = out Bool()
  val rxuserclk_out = out Bool()
  val rxuserclk2_out = out Bool()
  val resetdone = out Bool()
  val pma_reset_out = out Bool()
  val mmcm_locked_out = out Bool()
  val gmii_isolate = out Bool()
  val an_interrupt = out Bool()
  val gt0_pll0outclk_out = out Bool()
  val gt0_pll0outrefclk_out = out Bool()
  val gt0_pll1outclk_out = out Bool()
  val gt0_pll1outrefclk_out = out Bool()
  val gt0_pll0lock_out = out Bool()
  val gt0_pll0refclklost_out = out Bool()
}

case class Ethernet_PCS() extends Component{
  val io = new Bundle{
    val gmii_pcs_pma = master(Gmii_Pcs_Pma())
    val gmii_clk = GmiiClk()
    val config = Config()
    val sfp = Sfp()
    val user_clk = out Bool()
    val all = Seq(gmii_pcs_pma.gmii_rx_dv, gmii_pcs_pma.gmii_rx_er, gmii_pcs_pma.gmii_rxd, gmii_pcs_pma.gmii_tx_en, gmii_pcs_pma.gmii_tx_er, gmii_pcs_pma.gmii_txd,
      gmii_clk.gtrefclk_n, gmii_clk.gtrefclk_p, gmii_clk.independent_clock_bufg, gmii_clk.reset,config.configuration_vector, config.an_adv_config_vector, config.an_restart_config,
      config.signal_detect,config.status_vector,sfp.rxn, sfp.rxp, sfp.txn, sfp.txp)
    all.foreach(signal => signal.setName(signal.getPartialName()))
  }
  noIoPrefix()
  val ethernet = new BlackBox{
    setDefinitionName("gig_ethernet_pcs_pma_0")
    val gmii_pcs_pma = master(Gmii_Pcs_Pma())
    val gmii_clk = GmiiClk()
    val config = Config()
    val sfp = Sfp()
    val qpll_control = QPLL_CONTROL()

    val all = Seq(gmii_pcs_pma.gmii_rx_dv, gmii_pcs_pma.gmii_rx_er, gmii_pcs_pma.gmii_rxd, gmii_pcs_pma.gmii_tx_en, gmii_pcs_pma.gmii_tx_er, gmii_pcs_pma.gmii_txd,
      gmii_clk.gtrefclk_n, gmii_clk.gtrefclk_p, gmii_clk.independent_clock_bufg, gmii_clk.reset,config.configuration_vector, config.an_adv_config_vector, config.an_restart_config,
      config.signal_detect,config.status_vector,sfp.rxn, sfp.rxp, sfp.txn, sfp.txp,qpll_control.gtrefclk_out, qpll_control.gtrefclk_bufg_out, qpll_control.userclk_out,
      qpll_control.userclk2_out,qpll_control.rxuserclk_out,qpll_control.rxuserclk2_out,qpll_control.resetdone,qpll_control.pma_reset_out,qpll_control.mmcm_locked_out,
      qpll_control.gmii_isolate,qpll_control.an_interrupt,qpll_control.gt0_pll0outclk_out,qpll_control.gt0_pll0outrefclk_out,qpll_control.gt0_pll1outclk_out,qpll_control.gt0_pll1outrefclk_out,
      qpll_control.gt0_pll0lock_out,qpll_control.gt0_pll0refclklost_out)
    all.foreach(signal => signal.setName(signal.getPartialName()))
  }
  io.gmii_pcs_pma <> ethernet.gmii_pcs_pma
  io.gmii_clk <> ethernet.gmii_clk
  io.config <> ethernet.config
  io.sfp <> ethernet.sfp
  io.user_clk <> ethernet.qpll_control.userclk_out
}

object Ethernet_PCS extends App{
  SpinalVerilog(Ethernet_PCS())
}

