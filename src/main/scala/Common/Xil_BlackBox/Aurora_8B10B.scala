package Common.Xil_BlackBox

import Common.PrintXDC
import spinal.core._
import spinal.lib._

case class Gtx_IO(lanwidth : Int) extends Bundle{
  val rx = Seq.fill(lanwidth)(GT_SERIAL_RX())
  val tx = Seq.fill(lanwidth)(GT_SERIAL_TX())
  for(i <- 0 until lanwidth){
    rx(i).rxn.setName(s"rxn$i")
    rx(i).rxp.setName(s"rxp$i")
    tx(i).txn.setName(s"txn$i")
    tx(i).txp.setName(s"txp$i")
  }
//  PrintXDC(s"set_property PACKAGE_PIN C9 [get_ports ${rx(0).rxn.getName()}]\n")
}

case class USER_DATA_S_AXI_TX(datawidth : Int) extends Bundle{
  val s_axi_tx = slave(Stream(Fragment(Bits(datawidth bits))))
  val s_axi_tx_tkeep = in Bits(datawidth/8 bits)
  s_axi_tx.payload.fragment.setName("s_axi_tx_tdata")
  s_axi_tx.payload.last.setName("s_axi_tx_tlast")
  s_axi_tx.valid.setName("s_axi_tx_tvalid")
  s_axi_tx.ready.setName("s_axi_tx_tready")
  s_axi_tx_tkeep.setName("s_axi_tx_tkeep")
}

case class USER_DATA_M_AXI_RX(datawidth : Int) extends Bundle{
  val m_axi_rx = master(Flow(Fragment(Bits(datawidth bits))))
  val m_axi_rx_tkeep = out Bits(datawidth/8 bits)
  m_axi_rx.payload.fragment.setName("m_axi_rx_tdata")
  m_axi_rx.payload.last.setName("m_axi_rx_tlast")
  m_axi_rx.valid.setName("m_axi_rx_tvalid")
  m_axi_rx_tkeep.setName("m_axi_rx_tkeep")
}

case class GTO_DRP_IF() extends Bundle{
  val drpaddr_in = in Bits(9 bits)
  val drpen_in = in Bool()
  val drpdi_in = in Bits(16 bits)
  val drpwe_in = in Bool()
  val drpclk_in = in Bool()
  val drprdy_out = out Bool()
  val drpdo_out = out Bits(16 bits)
  val all = Seq(drpaddr_in, drpen_in, drpdi_in, drpwe_in, drpclk_in, drprdy_out, drpdo_out)
  all.foreach(signal => signal.setName(signal.getPartialName()))
}

case class CORE_CONTROL() extends Bundle{
  val loopback = in Bits(3 bits)
  val power_down = in Bool()
  val all = Seq(loopback, power_down)
  all.foreach(signal => signal.setName(signal.getPartialName()))
}

case class GT_SERIAL_RX() extends Bundle{
  val rxn = in Bool()
  val rxp = in Bool()
}

case class GT_SERIAL_TX() extends Bundle{
  val txn = out Bool()
  val txp = out Bool()
}

case class CORE_STATUS() extends Bundle{
  val channel_up = out Bool()
  val frame_err = out Bool()
  val hard_err = out Bool()
  val lane_up = out Bool()
  val rx_resetdone_out = out Bool()
  val soft_err = out Bool()
  val tx_lock = out Bool()
  val tx_resetdone_out = out Bool()
  val all = Seq(channel_up, frame_err, hard_err, lane_up, rx_resetdone_out, soft_err, tx_lock,tx_resetdone_out)
  all.foreach(signal => signal.setName(signal.getPartialName()))
}

case class QPLL_CONTROL_A7() extends Bundle with IMasterSlave{
  val gt0_pll0outclk = Bool()
  val gt0_pll1outclk = Bool()
  val gt0_pll0outrefclk = Bool()
  val gt0_pll1outrefclk = Bool()
  val gt0_pll0refclklost = Bool()
  val quad1_common_lock = Bool()
  val pll_not_locked = Bool()
  val user_clk = Bool()
  val sync_clk = Bool()

  override def asMaster(): Unit = {
    out(gt0_pll0outclk, gt0_pll1outclk, gt0_pll0outrefclk, gt0_pll1outrefclk, gt0_pll0refclklost, quad1_common_lock,pll_not_locked,user_clk,sync_clk)
    val gt0_pll = Seq(gt0_pll0outclk, gt0_pll1outclk, gt0_pll0outrefclk, gt0_pll1outrefclk, gt0_pll0refclklost, quad1_common_lock)
    val clk = Seq(pll_not_locked,user_clk,sync_clk)
    gt0_pll.foreach(signal => signal.setName(signal.getPartialName()+"_out"))
    clk.foreach(signal => signal.setName(signal.getPartialName()+"_out"))
  }
  override def asSlave(): Unit = {
    in(gt0_pll0outclk, gt0_pll1outclk, gt0_pll0outrefclk, gt0_pll1outrefclk, gt0_pll0refclklost, quad1_common_lock,pll_not_locked,user_clk,sync_clk)
    val gt0_pll = Seq(gt0_pll0outclk, gt0_pll1outclk, gt0_pll0outrefclk, gt0_pll1outrefclk, gt0_pll0refclklost, quad1_common_lock)
    val clk = Seq(pll_not_locked,user_clk,sync_clk)
    gt0_pll.foreach(signal => signal.setName(signal.getPartialName()+"_in"))
    clk.foreach(signal => signal.setName(signal.getPartialName()))
  }
}

case class QPLL_CONTROL_ZYNQ() extends Bundle with IMasterSlave{
  val gt0_qplllock = Bool()
  val gt0_qpllrefclklost = Bool()
  val gt_qpllclk_quad1 = Bool()
  val gt_qpllrefclk_quad1 = Bool()
  val pll_not_locked = Bool()
  val user_clk = Bool()
  val sync_clk = Bool()

  override def asMaster(): Unit = {
    out(gt0_qplllock, gt0_qpllrefclklost, gt_qpllclk_quad1, gt_qpllrefclk_quad1,pll_not_locked,user_clk,sync_clk)
    val gt0_pll = Seq(gt0_qplllock, gt0_qpllrefclklost, gt_qpllclk_quad1, gt_qpllrefclk_quad1)
    val clk = Seq(pll_not_locked,user_clk,sync_clk)
    gt0_pll.foreach(signal => signal.setName(signal.getPartialName()+"_out"))
    clk.foreach(signal => signal.setName(signal.getPartialName()+"_out"))
  }
  override def asSlave(): Unit = {
    in(gt0_qplllock, gt0_qpllrefclklost, gt_qpllclk_quad1, gt_qpllrefclk_quad1,pll_not_locked,user_clk,sync_clk)
    val gt0_pll = Seq(gt0_qplllock, gt0_qpllrefclklost, gt_qpllclk_quad1, gt_qpllrefclk_quad1)
    val clk = Seq(pll_not_locked,user_clk,sync_clk)
    gt0_pll.foreach(signal => signal.setName(signal.getPartialName()+"_in"))
    clk.foreach(signal => signal.setName(signal.getPartialName()))
  }
}

case class AURO_CLK_SLAVE() extends Bundle{
  val pll_not_locked = in Bool()
  val user_clk = in Bool()
  val sync_clk = in Bool()
  val all = Seq(pll_not_locked, user_clk, sync_clk)
  all.foreach(signal => signal.setName(signal.getPartialName()))
}


case class Aurora_8B10B_Master_A7(datawidth : Int) extends BlackBox{
  val s_axi_tx = USER_DATA_S_AXI_TX(datawidth)
  val drp = GTO_DRP_IF()
  val core_control = CORE_CONTROL()
  val gt_rx = GT_SERIAL_RX()
  val init_clk_in = in Bool()
  val gt_refclk1 = in Bool()
  val reset = in Bool()
  val gt_reset = in Bool()

  val m_axi_rx = USER_DATA_M_AXI_RX(datawidth)
  val status = CORE_STATUS()
  val gt_tx = GT_SERIAL_TX()
  val qpll_control = master(QPLL_CONTROL_A7())
  val link_reset_out = out Bool()
  val sys_reset_out = out Bool()
  val gt_reset_out = out Bool()

  def init() = {
    core_control.loopback := 0
    core_control.power_down := False
    drp.drpaddr_in := 0
    drp.drpen_in := False
    drp.drpdi_in := 0
    drp.drpwe_in := False
    s_axi_tx.s_axi_tx_tkeep := (1 << datawidth/8)-1
    gt_rx.rxn.setName("rxn")
    gt_rx.rxp.setName("rxp")
    gt_tx.txn.setName("txn")
    gt_tx.txp.setName("txp")
  }
}

case class Aurora_8B10B_Slave_A7(datawidth : Int) extends BlackBox{
  val s_axi_tx = USER_DATA_S_AXI_TX(datawidth)
  val drp = GTO_DRP_IF()
  val core_control = CORE_CONTROL()
  val gt_rx = GT_SERIAL_RX()
  val init_clk_in = in Bool()
  val gt_refclk1 = in Bool()
  val reset = in Bool()
  val gt_reset = in Bool()

  val m_axi_rx = USER_DATA_M_AXI_RX(datawidth)
  val status = CORE_STATUS()
  val gt_tx = GT_SERIAL_TX()
  val qpll_control = slave(QPLL_CONTROL_A7())
  val link_reset_out = out Bool()
  val sys_reset_out = out Bool()
  val gt_common_reset_out = out Bool()

  def init() = {
    core_control.loopback := 0
    core_control.power_down := False
    drp.drpaddr_in := 0
    drp.drpen_in := False
    drp.drpdi_in := 0
    drp.drpwe_in := False
    s_axi_tx.s_axi_tx_tkeep := (1 << datawidth/8)-1
    gt_rx.rxn.setName("rxn")
    gt_rx.rxp.setName("rxp")
    gt_tx.txn.setName("txn")
    gt_tx.txp.setName("txp")
  }
}

case class Aurora_8B10B_Master_ZYNQ(datawidth : Int) extends BlackBox{
  val s_axi_tx = USER_DATA_S_AXI_TX(datawidth)
  val drp = GTO_DRP_IF()
  val core_control = CORE_CONTROL()
  val gt_rx = GT_SERIAL_RX()
  val init_clk_in = in Bool()
  val gt_refclk1 = in Bool()
  val reset = in Bool()
  val gt_reset = in Bool()

  val m_axi_rx = USER_DATA_M_AXI_RX(datawidth)
  val status = CORE_STATUS()
  val gt_tx = GT_SERIAL_TX()
  val qpll_control = master(QPLL_CONTROL_ZYNQ())
  val link_reset_out = out Bool()
  val sys_reset_out = out Bool()
  val gt_reset_out = out Bool()

  def init() = {
    core_control.loopback := 0
    core_control.power_down := False
    drp.drpaddr_in := 0
    drp.drpen_in := False
    drp.drpdi_in := 0
    drp.drpwe_in := False
    s_axi_tx.s_axi_tx_tkeep := (1 << datawidth/8)-1
    gt_rx.rxn.setName("rxn")
    gt_rx.rxp.setName("rxp")
    gt_tx.txn.setName("txn")
    gt_tx.txp.setName("txp")
  }
}

case class Aurora_8B10B_Slave_ZYNQ(datawidth : Int) extends BlackBox{
  val s_axi_tx = USER_DATA_S_AXI_TX(datawidth)
  val drp = GTO_DRP_IF()
  val core_control = CORE_CONTROL()
  val gt_rx = GT_SERIAL_RX()
  val init_clk_in = in Bool()
  val gt_refclk1 = in Bool()
  val reset = in Bool()
  val gt_reset = in Bool()

  val m_axi_rx = USER_DATA_M_AXI_RX(datawidth)
  val status = CORE_STATUS()
  val gt_tx = GT_SERIAL_TX()
  val qpll_control = slave(QPLL_CONTROL_ZYNQ())
  val link_reset_out = out Bool()
  val sys_reset_out = out Bool()
  val tx_out_clk = out Bool()
  val gt0_qpllreset_out = out Bool()

  def init() = {
    core_control.loopback := 0
    core_control.power_down := False
    drp.drpaddr_in := 0
    drp.drpen_in := False
    drp.drpdi_in := 0
    drp.drpwe_in := False
    s_axi_tx.s_axi_tx_tkeep := (1 << datawidth/8)-1
    gt_rx.rxn.setName("rxn")
    gt_rx.rxp.setName("rxp")
    gt_tx.txn.setName("txn")
    gt_tx.txp.setName("txp")
  }
}