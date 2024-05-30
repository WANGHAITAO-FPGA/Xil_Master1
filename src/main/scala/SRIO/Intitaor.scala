package SRIO

import spinal.core._
import spinal.lib.fsm._
import spinal.lib.{Delay, StreamFifo, master, slave}
import spinal.lib.misc.Timer

import scala.util.Random

case class Intitaor(fifo_depth:Int) extends Component{
  val io = new Bundle{
    val intiator = master(Intitaor_Interface())
    val usercmd = slave (UserCmd())
    val send_start = in Bool()
    val iresp_stream = master Stream (Bits(64 bits))
    val rsp_received = out Bool()
    val request_autocheck_error = out Bool()
  }
  noIoPrefix()

  io.intiator.intiator_req_common.tkeep := B"xFF"
  io.intiator.intiator_req_common.tuser := B"x00FF00FF"

  val current_addr = io.usercmd.user_addr
  val current_ftype = io.usercmd.user_ftype
  val current_ttype = io.usercmd.user_ttype
  val current_size = io.usercmd.user_size
  val current_prio = io.usercmd.user_prio
  val current_tid = io.usercmd.user_tid

  val streamfifo = new StreamFifo(Bits(64 bits),fifo_depth)
  streamfifo.io.push << io.usercmd.user_data

  val header_beat = current_tid ## current_ftype ## current_ttype ## B"0" ## current_prio ## B"0" ## current_size ## B"2'x0" ## current_addr

  val current_beat_cnt = Reg(UInt(6 bits)) init 0
  when(io.intiator.intiator_req_stream.fire && io.intiator.intiator_req_stream.last){
    current_beat_cnt := 0
  }elsewhen(io.intiator.intiator_req_stream.fire){
    current_beat_cnt := current_beat_cnt + 1
  }otherwise{
    current_beat_cnt := current_beat_cnt
  }

  val number_of_data_beats = current_size(7 downto 3)

  val ireq_tlast = Reg(Bool()) init False

  when(((current_ftype === SrioFtype.NREAD)||(current_ftype === SrioFtype.DOORB))&&(current_beat_cnt === 0)){
    ireq_tlast := !(io.intiator.intiator_req_stream.fire && io.intiator.intiator_req_stream.last)
  }elsewhen((current_beat_cnt === number_of_data_beats.asUInt) && io.intiator.intiator_req_stream.fire){
    ireq_tlast := !ireq_tlast
  }elsewhen(io.intiator.intiator_req_stream.ready === False){
    ireq_tlast := ireq_tlast
  }elsewhen(io.intiator.intiator_req_stream.ready || (!io.intiator.intiator_req_stream.valid)){
    ireq_tlast := False
  }otherwise{
    ireq_tlast := ireq_tlast
  }
  io.intiator.intiator_req_stream.last := ireq_tlast

  val ireq_tdata = Reg(Bits(64 bits))
  when((current_beat_cnt === 0) && !(io.intiator.intiator_req_stream.fire)){
    ireq_tdata := header_beat
  }otherwise{
    ireq_tdata := streamfifo.io.pop.payload
  }
  io.intiator.intiator_req_stream.payload.fragment := ireq_tdata

  val user_data_ready = Reg(Bool()) init False
  val ireq_tvalid = Reg(Bool()) init False
  val send_start_d = RegNext(io.send_start) init False
  when(io.intiator.intiator_req_stream.fire && io.intiator.intiator_req_stream.last){
    ireq_tvalid := False
    user_data_ready := False
  }elsewhen(io.send_start && (!send_start_d)){
    ireq_tvalid := True
    user_data_ready := True
  }otherwise{
    ireq_tvalid := ireq_tvalid
    user_data_ready := user_data_ready
  }
  io.intiator.intiator_req_stream.valid := ireq_tvalid
  //streamfifo.io.pop.ready := io.intiator.intiator_req_stream.fire && (current_beat_cnt =/= 0)
  streamfifo.io.pop.ready := io.intiator.intiator_req_stream.fire

  /***********************Response Side Check*****************/
  val write_queue_data_d = B"44'x0" ## current_tid ## current_ftype ## current_size
  val write_queue_data = RegNext(write_queue_data_d)
  val expecting_a_response = Reg(Bool()) init False
  when((current_beat_cnt === 0) && (io.intiator.intiator_req_stream.fire)){
    expecting_a_response := (current_ftype === SrioFtype.NREAD)||
      (current_ftype === SrioFtype.DOORB)||
      ((current_ftype===SrioFtype.NWRITE)&&(current_ttype===SrioTtype.TNWR_R))||
      (current_ftype===SrioFtype.MESSG)
  }otherwise{
    expecting_a_response := False
  }

  val read_queue_data = RegNextWhen(write_queue_data,expecting_a_response)
  val expected_tid = read_queue_data(19 downto 12)
  val expected_ftype = read_queue_data(11 downto 8)
  val expected_size = read_queue_data(7 downto 0)

  val compare_received = Reg(Bool()) init True
  when(io.intiator.intiator_resp_stream.fire && io.intiator.intiator_resp_stream.last){
    compare_received := True
  }elsewhen(io.intiator.intiator_resp_stream.fire){
    compare_received := False
  }otherwise{
    compare_received := compare_received
  }

  io.rsp_received := io.intiator.intiator_resp_stream.fire && io.intiator.intiator_resp_stream.last

  val request_autocheck_error = Reg(Bool()) init False
  when(compare_received && io.intiator.intiator_resp_stream.fire){
    request_autocheck_error := (expected_tid =/= io.intiator.intiator_resp_stream.payload.fragment(63 downto 56))||
      ((expected_ftype === SrioFtype.NREAD.asBits)&&(io.intiator.intiator_resp_stream.payload.fragment(51 downto 48) =/= SrioTtype.TWDATA.asBits))||
      ((expected_ftype === SrioFtype.NWRITE.asBits)&&(io.intiator.intiator_resp_stream.payload.fragment(51 downto 48) =/= SrioTtype.TNDATA.asBits))||
      ((expected_ftype === SrioFtype.DOORB.asBits)&&(io.intiator.intiator_resp_stream.payload.fragment(51 downto 48) =/= SrioTtype.TNDATA.asBits))
  }otherwise{
    request_autocheck_error := False
  }

  io.request_autocheck_error := request_autocheck_error

//  val iresp_tready = Reg(Bool()) init False
//  when(io.intiator.intiator_resp_stream.fire && io.intiator.intiator_resp_stream.last){
//    iresp_tready := False
//  }otherwise{
//    iresp_tready := True
//  }
//  io.intiator.intiator_resp_stream.ready := iresp_tready

  val nread_iresp_write = Reg(Bool()) init False
  when(compare_received && (expected_ftype === SrioFtype.NREAD.asBits) && io.intiator.intiator_resp_stream.fire){
    nread_iresp_write := True
  }elsewhen(io.intiator.intiator_resp_stream.fire && io.intiator.intiator_resp_stream.last){
    nread_iresp_write := False
  }otherwise{
    nread_iresp_write := nread_iresp_write
  }

  val fifo = new StreamFifo(Bits(64 bits),256)
  fifo.io.push.valid := nread_iresp_write && io.intiator.intiator_resp_stream.fire
  fifo.io.push.payload := io.intiator.intiator_resp_stream.payload.fragment
  io.intiator.intiator_resp_stream.ready := fifo.io.push.ready

//  io.iresp_stream.payload := io.intiator.intiator_resp_stream.payload.fragment
//  io.iresp_stream.valid := nread_iresp_write && io.intiator.intiator_resp_stream.fire
  io.iresp_stream.payload := fifo.io.pop.payload
  io.iresp_stream.valid := fifo.io.pop.valid
  fifo.io.pop.ready := io.iresp_stream.ready
}


case class Intitaor_Test(timerl_imit : Int) extends Component{
  val io = new Bundle{
    val usercmd = master (UserCmd())
    val send_start = out Bool()
  }
  noIoPrefix()

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
    val counter = Reg(UInt(8 bits)) init 0
    val Init_Start: State = new State with EntryPoint {
      whenIsActive {
        when(timer.io.full) {
          user_addr := B"34'x120000"
          user_ftype := SrioFtype.NREAD
          user_ttype := SrioTtype.TNWR
          user_size := 15
          user_prio := 1
          user_tid := B"8'xFF"
          start := True
          counter := 0
          goto(Send_Read)
        }
      }
    }
    val Send_Read: State = new State {
      whenIsActive {
        start := False
        counter := counter + 1
        when(counter > 100) {
          counter := 0
          goto(Init_Start)
        }
      }
    }
//    val DoorBeel: State = new State {
//      whenIsActive {
//        user_addr := B"34'x20000"
//        user_ftype := SrioFtype.DOORB
//        user_ttype := SrioTtype.TNDATA
//        user_size := 0
//        user_prio := 1
//        user_tid := B"8'xFF"
//        start := True
//        counter := 0
//        goto(Send_DoorBeel)
//      }
//    }
//    val Send_DoorBeel: State = new State {
//      whenIsActive {
//        start := False
//        counter := counter + 1
//        when(counter > 100) {
//          counter := 0
//          goto(Nwrite)
//        }
//      }
//    }
//    val Nwrite: State = new State {
//      whenIsActive {
//        user_addr := B"34'x120020"
//        user_ftype := SrioFtype.NWRITE
//        user_ttype := SrioTtype.TNWR_R
//        user_size := 15
//        user_prio := 1
//        user_tid := B"8'xFF"
//        user_valid := True
//        user_data := B"64'xa1a2a3a4"
//        goto(Send_Data)
//      }
//    }
//    val Send_Data: State = new State {
//      whenIsActive {
//        user_valid := True
//        user_data := B"64'xa4a3a2a1"
//        goto(Send_Stream)
//      }
//    }
//    val Send_Stream: State = new State {
//      whenIsActive {
//        user_valid := False
//        start := True
//        goto(Send_Nwrite)
//      }
//    }
//    val Send_Nwrite: State = new State {
//      whenIsActive {
//        start := False
//        goto(Init_Start)
//      }
//    }

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
}

case class Intitaor_TestDemo() extends Component{
  val io = new Bundle{
    val intiator = master(Intitaor_Interface())
    val iresp_stream = master Stream (Bits(64 bits))
  }
  noIoPrefix()

  val intitaor_test = Intitaor_Test(500)
  val intitaor = Intitaor(256)
  intitaor.io.usercmd <> intitaor_test.io.usercmd
  io.intiator <> intitaor.io.intiator
  io.iresp_stream <> intitaor.io.iresp_stream
  intitaor.io.send_start := intitaor_test.io.send_start
  //intitaor.io.send_start.addAttribute("MARK_DEBUG","TRUE")
}

object Intitaor_TestDemo{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Intitaor_TestDemo()){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.intiator.intiator_req_stream.ready #= true
      dut.io.iresp_stream.ready #= true
      dut.io.intiator.intiator_resp_stream.valid #= false
      dut.io.intiator.intiator_resp_stream.payload.last #= false
      dut.clockDomain.waitSampling(100)

//      dut.io.intiator.intiator_resp_stream.payload.fragment #= B"64'xffd8400000000000"
//      dut.io.intiator.intiator_resp_stream.valid #= true
//      dut.clockDomain.waitSampling()
//      dut.io.intiator.intiator_resp_stream.payload.fragment #= B"64'x0000000000f1f2f3"
//      dut.io.intiator.intiator_resp_stream.valid #= true
//      dut.clockDomain.waitSampling()
//      dut.io.intiator.intiator_resp_stream.payload.fragment #= B"64'x000000000000000f"
//      dut.io.intiator.intiator_resp_stream.valid #= true
//      dut.io.intiator.intiator_resp_stream.payload.last #= true
//      dut.clockDomain.waitSampling()

      var a = 0
      for(a <- 0 to 10000){
//          dut.io.intiator.intiator_req_stream.ready #= Random.nextBoolean()
          dut.clockDomain.waitSampling()
      }

    }
  }
}
