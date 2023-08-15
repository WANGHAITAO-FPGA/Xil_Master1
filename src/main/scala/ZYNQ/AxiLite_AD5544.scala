package ZYNQ

import Common.PHPA.regFileGen.genRegFileByMarkdown
import Common.Xil_BlackBox.Ad5544Interface
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.{master, slave}
import Common.Xil_BlackBox._
import xilinx._

case class AxiLite_AD5544(ad5544_num : Int) extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val ad5544 = Seq.fill(ad5544_num)(master(Ad5544Interface()))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val ad5544 = AD5544_Ctrl(ad5544_num, 0)
  for (i <- 0 until ad5544_num) {
    ad5544.io.ad5544(i) <> io.ad5544(i)
    io.ad5544(i).CS.setName(s"CS_$i")
    io.ad5544(i).RS.setName(s"RS_$i")
    io.ad5544(i).LDAC.setName(s"LDAC_$i")
    io.ad5544(i).SCLK.setName(s"SCLK_$i")
    io.ad5544(i).SDIN.setName(s"SDIN_$i")
  }
  val bridge = ad5544.io.driveFrom(bus_ctrl)
  addPrePopTask(()=>genRegFileByMarkdown("AD5544"))
}

object AxiLite_AD5544 extends App{
  SpinalConfig(
    headerWithDate = true,
    nameWhenByFile = false,
    enumPrefixEnable = false,
    genLineComments = false
  ).generateVerilog(AxiLite_AD5544(3))
}

//object AxiLite_AD5544{
//  def main(args: Array[String]): Unit = {
//    def VivadoSynth[T <: Component](gen: => T, name: String = "temp"): Unit = {
//      val report = VivadoFlow(design = gen, name, s"D:/synthWorkspace/$name").doit()
//      report.printArea()
//      report.printFMax()
//    }
//    VivadoSynth(AxiLite_AD5544(3), name = "AxiLite_AD5544")
//  }
//}

