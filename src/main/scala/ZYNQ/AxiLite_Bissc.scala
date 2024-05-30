package ZYNQ

import Common.PHPA.BissCInterface
import Common.PHPA.regFileGen.genRegFileByMarkdown
import Common.Xil_BlackBox.BISSC_Ctrl
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.{master, slave}
case class AxiLite_Bissc(bissc_num : Int) extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val bissc = Seq.fill(bissc_num)(master(BissCInterface()))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val bissc_ctrl = BISSC_Ctrl(bissc_num, 0)
  for (i <- 0 until bissc_num) {
    io.bissc(i) <> bissc_ctrl.io.bissc(i)
    io.bissc(i).clk.setName(s"clk_$i")
    io.bissc(i).data.setName(s"data_$i")
  }
  val bridge = bissc_ctrl.io.driveFrom(bus_ctrl)
  bissc_ctrl.io.busy := False
  addPrePopTask(()=>genRegFileByMarkdown("BISSC"))
}

object AxiLite_Bissc extends App{
  SpinalVerilog(AxiLite_Bissc(4))
}

object  AxiLite_Bissc_Sim{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(AxiLite_Bissc(1)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.clockDomain.waitSampling(10000)
    }
  }
}