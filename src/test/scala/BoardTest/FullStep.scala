package BoardTest

import Common.PHPA.FullStep
import spinal.core.sim._

object FullStep {
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new FullStep(16,352)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.clockDomain.waitSampling(5000)

    }
  }

}
