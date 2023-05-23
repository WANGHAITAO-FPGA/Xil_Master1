package Common.Xil_BlackBox

import Common.PHPA.SawToothWaveGenerator
import spinal.core._
import spinal.core.sim._
import spinal.lib._
import spinal.sim._
object SawToothWaveGeneratorSim extends App {
  SimConfig.withWave.doSim(SawToothWaveGenerator(8)){ dut =>
    dut.clockDomain.forkStimulus(10)
    dut.io.direction #= true
    dut.io.step #= 250
    dut.io.start #= false
    dut.io.stop #= false
    dut.io.init #= false
    dut.clockDomain.waitSampling(100)
    dut.io.start #= true
    dut.clockDomain.waitSampling(3000)
    dut.io.start #= false
    dut.io.stop #= true
    dut.clockDomain.waitSampling(500)
    dut.io.direction #= false
    dut.io.stop #= false
    dut.clockDomain.waitSampling()
    dut.io.start #= true
    dut.clockDomain.waitSampling()
    dut.io.start #= false
    dut.clockDomain.waitSampling(3000)
    dut.io.stop #= false
    dut.clockDomain.waitSampling(100)
    dut.io.init #= true
    dut.clockDomain.waitSampling(50)
    dut.io.init #= false
    dut.clockDomain.waitSampling(500)
  }
}