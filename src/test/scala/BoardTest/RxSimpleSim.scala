package BoardTest

import Board_Test.{RxSimpleBus, Rx_Preamble}
import spinal.core.sim._

object Rx_PreambleSim{
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Rx_Preamble(32)){dut=>
      dut.clockDomain.forkStimulus(8)
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.io.frame_head #= BigInt(0x00f1f2f30000000fL)
      dut.io.output.ready #= true
      dut.clockDomain.waitSampling(20)
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.output.ready #= false
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x0f
      dut.clockDomain.waitSampling()
      dut.io.output.ready #= true
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x0f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf3f2f1
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.last #= true
      dut.io.input.payload.fragment #= 0x0a
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.clockDomain.waitSampling(200)
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.output.ready #= false
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf3f2f1
      dut.clockDomain.waitSampling()
      dut.io.output.ready #= true
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf3f2f1
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0xf1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x0f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.last #= true
      dut.io.input.payload.fragment #= 0x0a
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false

      dut.clockDomain.waitSampling(200)
    }
  }
}


object RxSimpleSim {
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new RxSimpleBus(9,32,false)) { dut =>
      dut.clockDomain.forkStimulus(10)
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.io.frame_head #= BigInt(0x00f1f2f30000000fL)
      dut.clockDomain.waitSampling(50)
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00f3f2f1
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x0000000f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00f1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x0000000f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000104
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000108
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.last #= true
      dut.io.input.payload.fragment #= BigInt(0x4C3E137F)
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.clockDomain.waitSampling(500)
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00f1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x0000000f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00f3f2f1
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x0000000f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000104
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000108
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.last #= true
      dut.io.input.payload.fragment #= BigInt(0x0C3E137F)
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.clockDomain.waitSampling(500)
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00f1f2f3
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x0000000f
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000104
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.fragment #= 0x00000108
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.fragment #= 0x12345678
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= true
      dut.io.input.payload.last #= true
      dut.io.input.payload.fragment #= BigInt(0x4C3E137F)
      dut.clockDomain.waitSampling()
      dut.io.input.valid #= false
      dut.io.input.payload.last #= false
      dut.clockDomain.waitSampling(500)
    }
  }
}
