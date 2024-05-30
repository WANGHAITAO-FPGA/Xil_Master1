package SRIO

import Board_Test._
import spinal.core._
import spinal.lib.{master, slave}

case class Target(addressWidth : Int, addressLowBit : Int) extends Component{
  val io = new Bundle{
    val target = master(Target_Interface())
    val simplebus = master(SimpleBus(SimpleBusConfig(addressWidth,64)))
    val doorbell_info = out Bits(16 bits)
    val doorbell_intr = out Bool()
    val busy = out Bool()
  }
  noIoPrefix()

  val busy = Reg(Bool()) init False
  val doorbell_intr = Reg(Bool()) init False

  val current_tid = io.target.target_req_stream.payload.fragment(63 downto 56)                   //8 bits
  val current_ftype = io.target.target_req_stream.payload.fragment(55 downto 52)                 //4 bits
  val current_ttype = io.target.target_req_stream.payload.fragment(51 downto 48)                 //4 bits
  val current_size = io.target.target_req_stream.payload.fragment(43 downto 36)                  //8 bits
  val current_prio = io.target.target_req_stream.payload.fragment(46 downto 45).asUInt + 1       //2 bits
  val current_addr = io.target.target_req_stream.payload.fragment(33 downto 0).asBits            //34 bits
  val current_srcid = io.target.target_req_common.tuser(31 downto 16)

  val response_data_in_d = current_srcid ## (current_addr(23 downto 16) === B"8'x12") ## current_addr(addressLowBit+addressWidth-1 downto addressLowBit) ## current_prio ## current_tid ## current_ftype ## current_size  addTag(crossClockDomain)
  val response_data_in = RegNext(response_data_in_d)

  val doorbell_info_d = io.target.target_req_stream.payload.fragment(31 downto 16)
  val doorbell_info = RegNextWhen(doorbell_info_d,current_ftype === SrioFtype.DOORB.asBits && io.target.target_req_stream.fire)
  io.doorbell_info := doorbell_info

  doorbell_intr := (current_ftype === SrioFtype.DOORB.asBits) && io.target.target_req_stream.fire
  io.doorbell_intr := doorbell_intr

  val first_beat = Reg(Bool()) init True

  when(io.target.target_req_stream.fire && io.target.target_req_stream.last){
    first_beat := True
  }elsewhen(io.target.target_req_stream.fire){
    first_beat := False
  }otherwise{
    first_beat := first_beat
  }

  val generate_a_response = Reg(Bool()) init False
  when(first_beat && io.target.target_req_stream.fire && current_addr(23 downto 16) === B"8'x12"){
    generate_a_response := (current_ftype === SrioFtype.NREAD.asBits)||
      (current_ftype === SrioFtype.DOORB.asBits)||
      (current_ftype === SrioFtype.MESSG.asBits)||
      ((current_ftype === SrioFtype.NWRITE.asBits)&&(current_ttype === SrioTtype.TNWR_R.asBits))
  }otherwise{
    generate_a_response := False
  }

  val capture_data = Reg(Bool()) init False
  when(first_beat && io.target.target_req_stream.fire){
    capture_data := (current_ftype === SrioFtype.SWRITE.asBits)||(current_ftype === SrioFtype.NWRITE.asBits)
  }elsewhen(io.target.target_req_stream.fire && io.target.target_req_stream.last){
    capture_data := False
  }otherwise{
    capture_data := capture_data
  }

  val data_store_wen = capture_data && io.target.target_req_stream.fire

  val data_store_waddr = Reg(Bits(addressWidth bits)) init 0
  when(first_beat && io.target.target_req_stream.fire){
    data_store_waddr := current_addr(addressLowBit+addressWidth-1 downto addressLowBit)
  }elsewhen(io.target.target_req_stream.fire){
    data_store_waddr := (data_store_waddr.asUInt + 8).asBits
  }otherwise{
    data_store_waddr := data_store_waddr
  }
  io.target.target_req_stream.ready := True

  val response_data_out_d = RegNextWhen(response_data_in,generate_a_response) init 0
  val response_data_out = RegNext(response_data_out_d) init 0
  val response_tid = response_data_out(19 downto 12)
  val response_ftype = response_data_out(11 downto 8)
  val response_size = response_data_out(7 downto 0)
  val response_prio = response_data_out(21 downto 20)
  val starting_read_addr = response_data_out(21+addressWidth downto 22)
//  val dest_id = response_data_out(37+addressWidth downto 23+addressWidth)

  val pull_from_store = Mux((response_ftype === SrioFtype.NREAD.asBits) && response_data_out(22+addressWidth),True,False)

  val responding_ttype = Mux((response_ftype === SrioFtype.NREAD.asBits),SrioTtype.TWDATA,SrioTtype.TNDATA)

  val current_beat_cnt = Reg(UInt(6 bits)) init 0
  val number_of_data_beats = Reg(UInt(6 bits))

  when(current_beat_cnt === 0){
    number_of_data_beats := response_size(7 downto 3).asUInt.resized
  }otherwise{
    number_of_data_beats := number_of_data_beats
  }

  when(io.target.target_resp_stream.fire && io.target.target_resp_stream.last){
    current_beat_cnt := 0
  }elsewhen(io.target.target_resp_stream.fire){
    current_beat_cnt := current_beat_cnt + 1
  }otherwise{
    current_beat_cnt := current_beat_cnt
  }

  val tresp_tlast = Reg(Bool()) init False
  when(responding_ttype === SrioTtype.TNDATA){
    tresp_tlast := !(io.target.target_resp_stream.fire && io.target.target_resp_stream.last)
  }elsewhen((current_beat_cnt === number_of_data_beats) && io.target.target_resp_stream.fire){
    tresp_tlast := !tresp_tlast
  }elsewhen(io.target.target_resp_stream.ready||(!io.target.target_resp_stream.valid)){
    tresp_tlast := False
  }otherwise{
    tresp_tlast := tresp_tlast
  }
  io.target.target_resp_stream.last := tresp_tlast

  val generate_rsp = RegNext(generate_a_response) init False
  val generate_rsp_d = RegNext(generate_rsp) init False

  val pull_from_store_d = Reg(Bool()) init False
  when(generate_rsp_d && (current_beat_cnt === 0)){
    pull_from_store_d := True
  }elsewhen(io.target.target_resp_stream.last){
    pull_from_store_d := False
  }otherwise{
    pull_from_store_d := pull_from_store_d
  }

  io.busy := pull_from_store_d

  val data_store_raddr = Reg(Bits(addressWidth bits)) init 0
  when(pull_from_store_d && (current_beat_cnt === 0)) {
    data_store_raddr := (data_store_raddr.asUInt + 8).asBits
  } elsewhen (pull_from_store_d && io.target.target_resp_stream.fire) {
    data_store_raddr := (data_store_raddr.asUInt + 8).asBits
  } otherwise {
    data_store_raddr := starting_read_addr
  }

  val tresp_tvalid = Reg(Bool()) init False
  when(pull_from_store_d && (current_beat_cnt === 0)){
    tresp_tvalid := True
  }elsewhen(io.target.target_resp_stream.fire && io.target.target_resp_stream.last){
    tresp_tvalid := False
  }otherwise{
    tresp_tvalid := tresp_tvalid
  }
  io.target.target_resp_stream.valid := tresp_tvalid

  val header_beat = response_tid ## SrioFtype.RESP ## responding_ttype ## B"0" ## response_prio ## B"45'x0"

  /*val rspmem = Mem(Bits(64 bits), BigInt(1) << addressWidth)
  rspmem.write(data_store_waddr.asUInt,io.target.target_resp_stream.payload.fragment,data_store_wen)
  rspmem.addAttribute("ram_style", "block")*/

  //val srio_reg = new Srio_Regif(addressWidth)
  io.simplebus.RADDR := data_store_raddr.asUInt
  io.simplebus.RENABLE := True
  io.simplebus.WENABLE := data_store_wen
  io.simplebus.WADDR := data_store_waddr.asUInt
  io.simplebus.WDATA := io.target.target_req_stream.payload.fragment

  val tresp_tdata = Reg(Bits(64 bits))
  val data_store_dout = Reg(Bits(64 bits))
  when((current_beat_cnt === 0) &&(!io.target.target_resp_stream.fire)){
    tresp_tdata := header_beat
  }elsewhen(pull_from_store && io.target.target_resp_stream.fire){
    //tresp_tdata := rspmem.readAsync(data_store_raddr.asUInt)
    tresp_tdata := io.simplebus.RDATA
  }otherwise{
    tresp_tdata := tresp_tdata
  }
//  io.target.target_resp_stream.payload.fragment := tresp_tdata

  io.target.target_resp_stream.payload.fragment := tresp_tdata

  io.target.target_resp_common.tkeep := B"xFF"
  io.target.target_resp_common.tuser := B"x000000FF"

//  val ila_probe=ila("1",io.doorbell_info)
}

object Target_Demo extends App{
  SpinalVerilog(Target(8,0))
}

