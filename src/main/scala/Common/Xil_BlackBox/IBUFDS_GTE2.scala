package Common.Xil_BlackBox

import spinal.core._

case class IBUFDS_GTE2() extends BlackBox{
  val generic: Generic = new Generic {
    val CLKCM_CFG = "TRUE"
    val CLKRCV_TRST = "TRUE"
    val CLKSWING_CFG = 3
  }
  val I,IB,CEB = in Bool()
  val O,ODIV2 = out Bool()
}
