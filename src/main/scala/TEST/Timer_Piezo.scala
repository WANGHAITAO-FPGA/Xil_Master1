package TEST

import spinal.core.{in, _}
import spinal.lib._
import spinal.lib.fsm._
import spinal.lib.misc.Timer

case class Timer_Piezo() extends Component{
  val io = new Bundle{
    val dt_s = in UInt(16 bits)
    val tick = in Bool()
    val trigger = out Bool()
  }
  noIoPrefix()

  val timer_reset = Reg(Bool()) init True
  timer_reset := False

  val timer = new Timer(16)
  timer.io.limit := io.dt_s
  io.trigger := timer.io.full
  when(timer.io.full) {
    timer_reset := True
  }
  timer.io.clear := timer_reset
  timer.io.tick := io.tick
}

case class Piezo_Relax() extends Component{
  val io = new Bundle{
    val trigger = in Bool()
    val relax_st = in Bool()
    val c1_val_in = in UInt(16 bits)
    val c2_val_in = in UInt(16 bits)
    val d1_val_in = in UInt(16 bits)
    val d2_val_in = in UInt(16 bits)
    val clamp_maxvalue = in UInt(16 bits)
    val clamp_minvalue = in UInt(16 bits)
    val step_value = in UInt(16 bits)
    val tick = out Bool()
    val c1_val_out = out UInt (16 bits)
    val c2_val_out = out UInt (16 bits)
    val d1_val_out = out UInt (16 bits)
    val d2_val_out = out UInt (16 bits)
  }
  noIoPrefix()

  val relax_st = Reg(Bool()) init False
  relax_st := io.relax_st

  val trigger = Reg(Bool()) init False
  trigger := io.trigger

  val tick = Reg(Bool()) init False

  val step_value = Reg(UInt (16 bits)) init 0x1000

  val c1_val_in = Reg(UInt (16 bits))
  val c2_val_in = Reg(UInt (16 bits))
  val d1_val_in = Reg(UInt (16 bits))
  val d2_val_in = Reg(UInt (16 bits))

  val clamp_maxvalue = Reg(UInt(16 bits))
  val clamp_minvalue = Reg(UInt(16 bits))

  val fsm = new StateMachine{
    val Initial_Start: State = new State with EntryPoint {
      whenIsActive{
        when(relax_st.rise()) {
          tick := True
          c1_val_in := io.c1_val_in
          c2_val_in := io.c2_val_in
          d1_val_in := io.d1_val_in
          d2_val_in := io.d2_val_in
          clamp_maxvalue := io.clamp_maxvalue
          clamp_minvalue := io.clamp_minvalue
          step_value := io.step_value
          goto(STEP1)
        }
      }
    }
    val STEP1: State = new State{
      whenIsActive{
        when(trigger.rise()){
          when((c1_val_in -clamp_minvalue) > step_value){
            c1_val_in := c1_val_in - step_value
            c2_val_in := c2_val_in + step_value
          }otherwise{
            c1_val_in := clamp_minvalue
            c2_val_in := clamp_maxvalue
            goto(STEP2)
          }
        }
      }
    }
    val STEP2: State = new State{
      whenIsActive{
        when(trigger.rise()){
          when(d1_val_in > 0x8000){
            when((d1_val_in - 0x8000) > step_value){
              d1_val_in := d1_val_in - step_value
            }otherwise{
              d1_val_in := 0x8000
              goto(STEP3)
            }
          }otherwise{
            when((0x8000 - d1_val_in) > step_value) {
              d1_val_in := d1_val_in + step_value
            } otherwise {
              d1_val_in := 0x8000
              goto(STEP3)
            }
          }
        }
      }
    }
    val STEP3: State = new State{
      whenIsActive{
        when(trigger.rise()) {
          when((clamp_maxvalue - c1_val_in) > step_value) {
            c1_val_in := c1_val_in + step_value
            c2_val_in := c2_val_in - step_value
          } otherwise {
            c1_val_in := clamp_maxvalue
            c2_val_in := clamp_minvalue
            goto(STEP4)
          }
        }
      }
    }
    val STEP4: State = new State{
      whenIsActive{
        when(trigger.rise()) {
          when(d2_val_in > 0x8000) {
            when((d2_val_in - 0x8000) > step_value) {
              d2_val_in := d2_val_in - step_value
            } otherwise {
              d2_val_in := 0x8000
              goto(STEP5)
            }
          } otherwise {
            when((0x8000 - d2_val_in) > step_value) {
              d2_val_in := d2_val_in + step_value
            } otherwise {
              d2_val_in := 0x8000
              goto(STEP5)
            }
          }
        }
      }
    }
    val STEP5: State = new State{
      whenIsActive {
        when(trigger.rise()) {
          when((c1_val_in - 0x8000) > step_value) {
            c1_val_in := c1_val_in - step_value
            c2_val_in := c2_val_in + step_value
          } otherwise {
            c1_val_in := 0x8000
            c2_val_in := 0x8000
            tick := False
            goto(Initial_Start)
          }
        }
      }
    }
  }
  io.tick := tick
  io.c1_val_out := c1_val_in
  io.c2_val_out := c2_val_in
  io.d1_val_out := d1_val_in
  io.d2_val_out := d2_val_in
}

case class Piezo_Ctrl() extends Component{
  val io = new Bundle{
    val dt_s = in UInt(16 bits)
    val c1_val_in = in UInt (16 bits)
    val c2_val_in = in UInt (16 bits)
    val d1_val_in = in UInt (16 bits)
    val d2_val_in = in UInt (16 bits)
    val clamp_maxvalue = in UInt (16 bits)
    val clamp_minvalue = in UInt (16 bits)
    val step_value = in UInt (16 bits)
    val relax_st = in Bool()
    val c1_val_out = out UInt (16 bits)
    val c2_val_out = out UInt (16 bits)
    val d1_val_out = out UInt (16 bits)
    val d2_val_out = out UInt (16 bits)
  }
  noIoPrefix()

  val timer_ctrl = Timer_Piezo()
  val relax_ctrl = Piezo_Relax()
  relax_ctrl.io.relax_st := io.relax_st
  relax_ctrl.io.c1_val_out <> io.c1_val_out
  relax_ctrl.io.c2_val_out <> io.c2_val_out
  relax_ctrl.io.d1_val_out <> io.d1_val_out
  relax_ctrl.io.d2_val_out <> io.d2_val_out
  relax_ctrl.io.c1_val_in <> io.c1_val_in
  relax_ctrl.io.c2_val_in <> io.c2_val_in
  relax_ctrl.io.d1_val_in <> io.d1_val_in
  relax_ctrl.io.d2_val_in <> io.d2_val_in
  relax_ctrl.io.clamp_maxvalue <> io.clamp_maxvalue
  relax_ctrl.io.clamp_minvalue <> io.clamp_minvalue
  relax_ctrl.io.step_value <> io.step_value
  timer_ctrl.io.tick := relax_ctrl.io.tick
  relax_ctrl.io.trigger := timer_ctrl.io.trigger
  timer_ctrl.io.dt_s := io.dt_s
}

object Piezo_Ctrl{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Piezo_Ctrl){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.dt_s #= 100
      dut.io.step_value #= 0x1000
      dut.io.clamp_maxvalue #= 0xffff
      dut.io.clamp_minvalue #= 0
      dut.io.c1_val_in #= 0
      dut.io.c2_val_in #= 0
      dut.io.d1_val_in #= 0
      dut.io.d2_val_in #= 0
      dut.io.relax_st #= false
      dut.clockDomain.waitSampling(100)
      dut.io.relax_st #= true
      dut.clockDomain.waitSampling()
      dut.io.relax_st #= false
      dut.clockDomain.waitSampling(10000)

    }
  }
}



object Timer_Piezo{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Timer_Piezo()){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.dt_s #= 100
      dut.io.tick #= true
      dut.clockDomain.waitSampling(100)
      dut.io.dt_s #= 200
      dut.clockDomain.waitSampling(500)
      dut.io.dt_s #= 400
      dut.clockDomain.waitSampling(15000)
    }
  }
}