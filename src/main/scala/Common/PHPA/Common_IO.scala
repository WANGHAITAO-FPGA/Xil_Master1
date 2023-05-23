package Common.PHPA

import spinal.core._
import spinal.lib.slave

//case class CommonIoInterface() extends Bundle{
//  val IO_InA = in Bool()
//  val IO_InB = in Bool()
//  val IO_InC = in Bool()
//  val IO_InD = in Bool()
//  val IO_OutA = out Bool()
//  val IO_OutB = out Bool()
//  val IO_OutC = out Bool()
//  val IO_OutD = out Bool()
//}
//
//case class Common_IO() extends Component{
//  val io = new Bundle{
//    val commonio = CommonIoInterface()
//    val bissc = slave(BissCInterface())
//    val encoder = slave(EncoderInterface())
//  }
//  noIoPrefix()
//}
