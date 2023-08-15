package ZYNQ

import spinal.core._
import spinal.lib.bus.amba4.axi.{Axi4Bus, Axi4SpecRenamer}
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4Config, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.slave

object AxiLite4DataConfig {
  def getaxi4liteconfig = AxiLite4Config(16,32)
}
case class AxiLite_Data() extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val s_data = in Vec(Bits(32 bits),4)
    val m_data = out Vec(Bits(32 bits),4)
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()
  val ctrl = new AxiLite4SlaveFactory(io.s_axi)
  ctrl.read(io.s_data(0),0)
  ctrl.read(io.s_data(1),4)
  ctrl.read(io.s_data(2),8)
  ctrl.read(io.s_data(3),12)
  ctrl.driveAndRead(io.m_data(0),16)
  ctrl.driveAndRead(io.m_data(1),20)
  ctrl.driveAndRead(io.m_data(2),24)
  ctrl.driveAndRead(io.m_data(3),28)
}

object AxiLite_Data extends App{
  SpinalVerilog(AxiLite_Data())
}
