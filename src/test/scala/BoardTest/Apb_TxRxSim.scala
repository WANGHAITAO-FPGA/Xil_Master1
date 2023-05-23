package BoardTest

import Board_Test.Apb_TxRxSimple
import spinal.core.sim._
import spinal.lib.bus.amba3.apb.sim.Apb3Driver

object Apb_TxRxSim {
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Apb_TxRxSimple(true)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.gtx_area.clockDomain.forkStimulus(8)
//      dut.io.output.ready #= true
      val testapb = new Apb3Driver(dut.io.apb,dut.clockDomain)
      testapb.write(520,0x0000)
      dut.clockDomain.waitSampling(500)
      testapb.write(0x00,0x1234)
      testapb.write(0x02,0x5678)
      testapb.write(0x04,0x1234)
      testapb.write(0x06,0x5678)
      testapb.write(524,0x0000)
      testapb.write(526,0x0002)
      testapb.write(530,0x00f1)
      testapb.write(532,0xf2f3)
      testapb.write(534,0x0000)
      testapb.write(536,0x000f)
      testapb.write(520,0x0001)
      dut.clockDomain.waitSampling(500)
    }
  }

}
