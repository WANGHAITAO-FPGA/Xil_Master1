package SRIO

import spinal.core._
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.{StreamFifo, master, slave}
import spinal.lib.misc.Timer

import scala.util.Random

case class Srio_Top() extends Component{
  val io = new Bundle{
    val srio_clk = in Bool()
    val reset = in Bool()
    val srio = master(Srio_Interface())
    val usercmd = slave(UserCmd())
    val send_start = in Bool()
    val iresp_stream = master Stream (Bits(64 bits))
//    val rsp_received = out Bool()
//    val request_autocheck_error = out Bool()
    val data_in = Seq.fill(16)(in Bits (64 bits))
    val data_out = Seq.fill(16)(out Bits (64 bits))
    val busy = out Bool()
    val doorbell_info = out Bits (16 bits)
    val doorbell_intr = out Bool()
  }
  noIoPrefix()

  val srio_clkdomain = ClockDomain(io.srio_clk,io.reset)
  val srio_area = new ClockingArea(srio_clkdomain){
    val srio_reg = new Srio_Regif(9)
    val target = new Target(9,0)
//    target.io.target <> io.srio.target
    target.io.simplebus <> srio_reg.io.simplebus
    target.io.target.target_resp_common <> io.srio.target.target_resp_common
    target.io.target.target_req_common <> io.srio.target.target_req_common
    target.io.target.target_req_stream <> io.srio.target.target_req_stream

    val target_fifo = new StreamFifo(Bits(64 bits),256)
    target_fifo.logic.ram.addAttribute("ram_style", "block")
    target_fifo.io.push.payload := target.io.target.target_resp_stream.payload.fragment
    target_fifo.io.push.valid := target.io.target.target_resp_stream.valid
    target.io.target.target_resp_stream.ready := True

    io.srio.target.target_resp_stream.payload.fragment := target_fifo.io.pop.payload
    io.srio.target.target_resp_stream.valid := target_fifo.io.pop.valid
    target_fifo.io.pop.ready := io.srio.target.target_resp_stream.ready
    io.srio.target.target_resp_stream.payload.last := (target_fifo.io.occupancy === 1) & io.srio.target.target_resp_stream.fire

    val streamfifo = new StreamFifo(Bits(64 bits),256)

    val intitaor = new Intitaor(256)
    intitaor.io.intiator.intiator_req_common <> io.srio.intiator.intiator_req_common
    intitaor.io.intiator.intiator_resp_common <> io.srio.intiator.intiator_resp_common
    intitaor.io.intiator.intiator_resp_stream <> io.srio.intiator.intiator_resp_stream
    intitaor.io.send_start := io.send_start
    intitaor.io.usercmd <> io.usercmd
    intitaor.io.iresp_stream <> io.iresp_stream

    streamfifo.logic.ram.addAttribute("ram_style", "block")
    streamfifo.io.push.payload := intitaor.io.intiator.intiator_req_stream.payload.fragment
    streamfifo.io.push.valid := intitaor.io.intiator.intiator_req_stream.valid
    intitaor.io.intiator.intiator_req_stream.ready := True

    io.srio.intiator.intiator_req_stream.payload.fragment := streamfifo.io.pop.payload
    io.srio.intiator.intiator_req_stream.valid := streamfifo.io.pop.valid
    streamfifo.io.pop.ready := io.srio.intiator.intiator_req_stream.ready
    io.srio.intiator.intiator_req_stream.payload.last := (streamfifo.io.occupancy === 1) & io.srio.intiator.intiator_req_stream.fire

    io.usercmd.user_data.valid.setName("s_axis_usercmd_tvalid")
    io.usercmd.user_data.payload.setName("s_axis_usercmd_tdata")
    io.usercmd.user_data.ready.setName("s_axis_usercmd_tready")

    io.iresp_stream.ready.setName("m_axis_rspstream_tready")
    io.iresp_stream.valid.setName("m_axis_rspstream_tvalid")
    io.iresp_stream.payload.setName("m_axis_rspstream_tdata")
//    io.rsp_received := intitaor.io.rsp_received
//    io.request_autocheck_error := intitaor.io.request_autocheck_error
    for(i <- 0 until 16){
      io.data_out(i) <> srio_reg.io.data_out(i)
      io.data_in(i) <> srio_reg.io.data_in(i)
    }
    io.busy := target.io.busy
    io.doorbell_intr := target.io.doorbell_intr
    io.doorbell_info := target.io.doorbell_info
  }
}


case class Srio_Test() extends Component{
  val io = new Bundle{
    val srio_clk = in Bool()
    val reset = in Bool()
    val usercmd = master(UserCmd())
    val send_start = out Bool()
  }
  noIoPrefix()

  val srio_clkdomain = ClockDomain(io.srio_clk, io.reset)
  val srio_area = new ClockingArea(srio_clkdomain) {
    val timer = Timer(32)
    timer.io.tick := True
    timer.io.limit := 2000
    when(timer.io.value >= timer.io.limit) {
      timer.io.clear := True
    } otherwise {
      timer.io.clear := False
    }

    val user_addr = Reg(Bits(34 bits)) init 0
    val user_ftype = Reg(SrioFtype())
    val user_ttype = Reg(SrioTtype())
    val user_size = Reg(Bits(8 bits))
    val user_prio = Reg(Bits(2 bits))
    val user_tid = Reg(Bits(8 bits))
    val user_valid = Reg(Bool()) init False
    val user_data = Reg(Bits(64 bits)) init 0
    val start = Reg(Bool()) init False

    val fsm = new StateMachine {
      val counter = Reg(UInt(16 bits)) init 0
      val Init_Start: State = new State with EntryPoint {
        whenIsActive {
          when(timer.io.full) {
            user_addr := B"34'x120000"
            user_ftype := SrioFtype.NREAD
            user_ttype := SrioTtype.TNWR
            user_size := 63
            user_prio := 1
            user_tid := B"8'xFF"
            start := True
            counter := 0
            goto(Send_Read)
          }
        }
      }
      val Send_Read: State = new State{
        whenIsActive {
          start := False
          counter := counter + 1
          when(counter > 400){
            counter := 0
            goto(Init_Start)
          }
        }
      }
      val DoorBeel: State = new State{
        whenIsActive {
          user_addr := B"34'x20000"
          user_ftype := SrioFtype.DOORB
          user_ttype := SrioTtype.TNDATA
          user_size := 0
          user_prio := 1
          user_tid := B"8'xFF"
          start := True
          counter := 0
          goto(Send_DoorBeel)
        }
      }
      val Send_DoorBeel: State = new State {
        whenIsActive {
          start := False
          counter := counter + 1
          when(counter > 200) {
            counter := 0
            goto(Init_Start)
          }
        }
      }
      val Nwrite: State = new State {
        whenIsActive {
          user_addr := B"34'x120088"
          user_ftype := SrioFtype.NWRITE
          user_ttype := SrioTtype.TNWR_R
          user_size := 127
          user_prio := 1
          user_tid := B"8'xFF"
          user_valid := True
          user_data := B"64'xa1a2a3a4"
          goto(Send_Data)
        }
      }
      val Send_Data: State = new State {
        whenIsActive {
          user_valid := True
          user_data := (user_data.asUInt + 1).asBits
          counter := counter + 1
          when(counter > 14){
            goto(Send_Stream)
          }
        }
      }
      val Send_Stream: State = new State {
        whenIsActive {
          user_valid := False
          start := True
          goto(Send_Nwrite)
        }
      }
      val Send_Nwrite: State = new State {
        whenIsActive {
          start := False
          goto(Init_Start)
        }
      }

    }

    io.usercmd.user_ftype := user_ftype
    io.usercmd.user_ttype := user_ttype
    io.usercmd.user_addr := user_addr
    io.usercmd.user_tid := user_tid
    io.usercmd.user_prio := user_prio
    io.usercmd.user_size := user_size
    io.usercmd.user_data.valid := user_valid
    io.usercmd.user_data.payload := user_data
    io.send_start := start

    io.usercmd.user_data.valid.setName("m_axis_usercmd_tvalid")
    io.usercmd.user_data.payload.setName("m_axis_usercmd_tdata")
    io.usercmd.user_data.ready.setName("m_axis_usercmd_tready")
  }
}


object Srio_Test_Top extends App{
  SpinalVerilog(new Srio_Top)
}


object Srio_Test extends App{
  SpinalVerilog(new Srio_Test)
}

case class srio_tt() extends Component{
  val io = new Bundle{
    val srio_clk = in Bool()
    val reset = in Bool()
    val iresp_stream = master Stream (Bits(64 bits))
  }
  noIoPrefix()

  val srio_clkdomain = ClockDomain(io.srio_clk, io.reset)
  val srio_area = new ClockingArea(srio_clkdomain) {

    val srio_top = Srio_Top()
    val srio_test = Srio_Test()

    srio_top.io.srio_clk := io.srio_clk
    srio_top.io.reset := io.reset
    srio_test.io.srio_clk := io.srio_clk
    srio_test.io.reset := io.reset

//    for(i <- 0 until 16){
//      srio_top.io.data_in(i) := srio_top.io.data_out(i)
//    }

    srio_top.io.data_in(0) := 10000
    srio_top.io.data_in(1) := 20000
    srio_top.io.data_in(2) := 20010
    srio_top.io.data_in(3) := 30000
    srio_top.io.data_in(4) := 40000
    srio_top.io.data_in(5) := 50000
    srio_top.io.data_in(6) := 60000
    srio_top.io.data_in(7) := 70000
    srio_top.io.data_in(8) := 80000
    for(i <- 9 until 16){
      srio_top.io.data_in(i) := 0
    }

    srio_top.io.send_start <> srio_test.io.send_start
    srio_top.io.usercmd <> srio_test.io.usercmd
    srio_top.io.srio.intiator.intiator_req_stream <> srio_top.io.srio.target.target_req_stream
    srio_top.io.srio.target.target_resp_stream <> srio_top.io.srio.intiator.intiator_resp_stream

    srio_top.io.srio.intiator.intiator_req_common <> srio_top.io.srio.target.target_req_common
    srio_top.io.srio.intiator.intiator_resp_common <> srio_top.io.srio.target.target_resp_common

    srio_top.io.iresp_stream <> io.iresp_stream
  }
}

object srio_tt{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new srio_tt){dut=>
      dut.srio_clkdomain.forkStimulus(10)
      dut.io.iresp_stream.ready #= true
      for(i <- 0 until 5000){
        dut.io.iresp_stream.ready #= Random.nextBoolean()
        dut.srio_clkdomain.waitSampling()
      }
    }
  }
}

case class Data_Test() extends Component{
  val io = new Bundle{
    val data_out = Seq.fill(8)(out Bits (64 bits) setAsReg())
    val busy = in Bool()
    val st = out Bool()
    val test_st = in Bool()
  }
  noIoPrefix()

  val timer = Timer(32)
  timer.io.tick := io.test_st
  timer.io.limit := 3125
  when(timer.io.value >= timer.io.limit) {
    timer.io.clear := True
  } otherwise {
    timer.io.clear := False
  }
  val st = Reg(Bool()) init False
  st := False
  val data_out = Seq.fill(8)(Reg(Bits (64 bits)) init 0)

  when(timer.io.full.rise()){
    st := True
    data_out(0) := (data_out(0).asUInt + 1000).asBits
    data_out(1) := (data_out(1).asUInt + 1010).asBits
    data_out(2) := (data_out(2).asUInt + 1020).asBits
    data_out(3) := (data_out(3).asUInt + 1030).asBits
    data_out(4) := (data_out(4).asUInt + 1040).asBits
    data_out(5) := (data_out(5).asUInt + 1050).asBits
    data_out(6) := (data_out(6).asUInt + 1060).asBits
    data_out(7) := (data_out(7).asUInt + 1070).asBits
  }
  when(!io.busy){
    for(i <- 0 until 8){
      io.data_out(i) := data_out(i)
    }
  }
  io.st := st
}

object Data_Test extends App{
  SpinalVerilog(Data_Test())
}

object Data_Test_Sim{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(Data_Test()){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.busy #= false
      dut.clockDomain.waitSampling(10000)
    }
  }
}

case class Test() extends Component{
  val io = new Bundle{
    val start_in = in Bool()
    val data_out = out UInt(32 bits)
  }
  noIoPrefix()

  val reg_st = Reg(Bool()) init False
  reg_st := io.start_in

  val data_reg = Reg(UInt(32 bits)) init 0

  when(reg_st.rise()){
    data_reg := data_reg + 1
  }
  io.data_out := data_reg
}

object Test extends App{
  SpinalVerilog(Test())
}