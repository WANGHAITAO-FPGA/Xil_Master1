package Common.Xil_BlackBox

import Common.Endat.Endat_Ctrl
import spinal.core.sim._

object Endat_Ctrl_Sim {
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Endat_Ctrl(16,1000)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.clockDomain.waitSampling(50)
      dut.clockDomain.waitSampling(20000)
    }
  }
}
