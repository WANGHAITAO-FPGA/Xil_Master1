package ZYNQ

import Common.BISSC.BisscSlave
import Common.PHPA.BissCInterface
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.slave

case class Bissc_Slave_Ctrl(bissc_num : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val s_bissc = Seq.fill(bissc_num)(slave(BissCInterface()))
    val m_postion = Seq.fill(bissc_num)(in Bits(32 bits))

    def driveFrom(bus: BusSlaveFactoryDelayed, baseAddress: Int = 0) = new Area {
      require(bus.busDataWidth == 32)
      for(i <- 0 until bissc_num){
        bus.driveAndRead(m_postion(i),4*i,0,s"bissc_data $i")
      }
    }
  }
  noIoPrefix()

  val bissc_slave = Seq.fill(bissc_num)(new BisscSlave(32,0))
  for(i <- 0 until bissc_num){
    bissc_slave(i).io.s_bissc <> io.s_bissc(i)
    bissc_slave(i).io.m_postion := io.m_postion(i)
    io.s_bissc(i).clk.setName(s"bissc_clk_$i")
    io.s_bissc(i).data.setName(s"bissc_data_$i")
  }
}
case class AxiLite_Bissc_Slave(bissc_num : Int) extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val s_bissc = Seq.fill(bissc_num)(slave(BissCInterface()))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val bissc_ctrl = Bissc_Slave_Ctrl(4,0)
  for (i <- 0 until bissc_num) {
    io.s_bissc(i) <> bissc_ctrl.io.s_bissc(i)
    io.s_bissc(i).clk.setName(s"clk_$i")
    io.s_bissc(i).data.setName(s"data_$i")
  }
  val bridge = bissc_ctrl.io.driveFrom(bus_ctrl)
}

object AxiLite_Bissc_Slave extends App{
  SpinalVerilog(AxiLite_Bissc_Slave(4))
}
