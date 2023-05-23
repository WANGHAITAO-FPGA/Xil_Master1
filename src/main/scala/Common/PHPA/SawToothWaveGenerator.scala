package Common.PHPA

import spinal.core._
import spinal.lib._
case class SawToothWaveGenerator(stepBits: Int) extends Component {
  val io = new Bundle {
    val direction = in Bool()
    val step = in UInt(stepBits bits)
    val start = in Bool()
    val stop = in Bool()
    val init = in Bool()
    val output = out UInt(15 bits)
  }

  val step = Reg(UInt(stepBits bits)) init 0
  step := io.step
  val sawtooth = Reg(UInt(15 bits)) init (0)
  val isRunning = RegInit(False)

  val start = Reg(Bool()) init False
  start := io.start
  val stop = Reg(Bool()) init False
  stop := io.stop
  val init = Reg(Bool()) init False
  init := io.init

  when((init.rise())||(stop.rise())){
    isRunning := False
  }elsewhen(start.rise()){
    isRunning := True
  }otherwise{
    isRunning := isRunning
  }
  when(init){
    sawtooth := 0
  }

  when(isRunning){
    when(io.direction){
      sawtooth := sawtooth + step
    }otherwise{
      sawtooth := sawtooth - step
    }
  }
  io.output := sawtooth
}


object SawToothWaveGenerator extends App{
  SpinalVerilog(SawToothWaveGenerator(5))
}