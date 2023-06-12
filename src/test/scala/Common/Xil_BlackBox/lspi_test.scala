package Common.Xil_BlackBox

import Common.Endat.LSPI_Ctrl

object lspi_test {
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new LSPI_Ctrl(16,5)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.kind.cpol #= true
      dut.io.kind.cpha #= true
      dut.io.postion #= 0x1235
      dut.io.tick #= false
      dut.clockDomain.waitSampling(100)
      dut.io.tick #= false
      dut.clockDomain.waitSampling(100)
      dut.io.tick #= true
      dut.clockDomain.waitSampling()
      dut.io.tick #= false
      dut.clockDomain.waitSampling(1000)
      dut.io.postion #= 0xabcd
      dut.io.tick #= true
      dut.clockDomain.waitSampling()
      dut.io.tick #= false
      dut.clockDomain.waitSampling(1000)

    }
  }

}
