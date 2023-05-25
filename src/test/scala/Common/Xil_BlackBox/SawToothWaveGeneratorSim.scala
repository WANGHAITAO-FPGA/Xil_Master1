package Common.Xil_BlackBox

import Common.PHPA.{Apb_SawTooth, SawTooth, SawToothTop, SawToothWaveGenerator}
import spinal.core._
import spinal.core.sim._
import spinal.lib._
import spinal.lib.bus.amba3.apb.sim.Apb3Driver
import spinal.sim._
object SawToothWaveGeneratorSim extends App {
  SimConfig.withWave.doSim(SawToothTop()){ dut =>
    dut.clockDomain.forkStimulus(10)
    dut.io.sawtooth_io(0).direction #= true
    dut.io.sawtooth_io(0).step #= 250
    dut.io.sawtooth_io(0).start #= false
    dut.io.sawtooth_io(0).stop #= false
    dut.io.sawtooth_io(0).init #= false
    dut.clockDomain.waitSampling(100)
    dut.io.sawtooth_io(0).start #= true
    dut.clockDomain.waitSampling(10000)
    dut.io.sawtooth_io(0).start #= false
    dut.io.sawtooth_io(0).stop #= true
    dut.clockDomain.waitSampling(500)
    dut.io.sawtooth_io(0).direction #= false
    dut.io.sawtooth_io(0).stop #= false
    dut.clockDomain.waitSampling()
    dut.io.sawtooth_io(0).start #= true
    dut.clockDomain.waitSampling()
    dut.io.sawtooth_io(0).start #= false
    dut.clockDomain.waitSampling(10000)
    dut.io.sawtooth_io(0).stop #= false
    dut.clockDomain.waitSampling(100)
    dut.io.sawtooth_io(0).init #= true
    dut.clockDomain.waitSampling(50)
    dut.io.sawtooth_io(0).init #= false
    dut.clockDomain.waitSampling(500)
  }
}

object Apb_SawToothSim extends App{
    SimConfig.withWave.doSim(Apb_SawTooth(8,16,0)) { dut =>
      dut.clockDomain.forkStimulus(10)
      val testapb = new Apb3Driver(dut.io.apb,dut.clockDomain)
      testapb.write(24,0)
      testapb.write(20,1)
      testapb.write(28,0x0020)
      testapb.write(32,1)
      dut.clockDomain.waitSampling(5000)
      testapb.write(24,1)
      dut.clockDomain.waitSampling(50000)
      testapb.write(32,0)
      dut.clockDomain.waitSampling(50000)

      testapb.write(24,0x0010)
      dut.clockDomain.waitSampling(5000)
    }
}