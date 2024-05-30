package Common.BISSC

import Common.CRCCORE.{CRC6, CRCCombinational, CRCCombinationalCmdMode, CRCCombinationalConfig}
import Common.PHPA.BissCInterface
import spinal.core._
import spinal.lib._
import spinal.lib.fsm.{EntryPoint, State, StateMachine}

case class BisscSlave(datawidth: Int,timecnt : Int) extends Component{
  val io = new Bundle{
    val s_bissc = slave(BissCInterface())
    val m_postion = in Bits(datawidth bits)
    val error = in Bool()
    val warm = in Bool()
    val currentState = out (Bits(4 bits))
  }
  noIoPrefix()

  val bisscdata = Reg(Bool()) init True
  val clkrise_cnt = Reg(UInt(6 bits)) init 0
  val timeout_cnt = Reg(UInt(16 bits)) init 0
  val postion_reg = Reg(Bits(datawidth+2 bits))

  val crc_cal = new CRCCombinational(CRCCombinationalConfig(CRC6.BISSC, 1 bits))
  val crc_valid = Reg(Bool()) init False
  val crc_payload = Reg(Bits(1 bits)) init 0
  val crc_mode = CRCCombinationalCmdMode
  crc_cal.io.cmd.valid := crc_valid
  crc_cal.io.cmd.data := crc_payload
  crc_cal.io.cmd.mode := crc_mode.INIT

  val enc_clk = Reg(Bool()) init False
  enc_clk := io.s_bissc.clk

  val fsm = new StateMachine{
    val Wait_Start:State = new State with EntryPoint{
      whenIsActive{
        bisscdata := True
        when(enc_clk.fall()){
          bisscdata := True
          postion_reg := io.m_postion##io.error.asBits##io.warm.asBits
          clkrise_cnt := 0
          timeout_cnt := 0
          crc_valid := False
          goto(Slo)
        }
      }
    }
    val Slo:State = new State{
      whenIsActive{
        timeout_cnt := timeout_cnt+1
        when(enc_clk.rise()){
          timeout_cnt := 0
          bisscdata := False
          clkrise_cnt := clkrise_cnt + 1
          when(clkrise_cnt === 1){
            bisscdata := False
            clkrise_cnt := 0
            goto(Ack)
          }
        }
        when(timeout_cnt > 1000){
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val Ack:State = new State{
      whenIsActive{
        timeout_cnt := timeout_cnt + 1
        when(enc_clk.rise()){
          timeout_cnt := 0
          bisscdata := True
          goto(Start)
        }
        when(timeout_cnt > 1000){
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val Start:State = new State{
      whenIsActive{
        timeout_cnt := timeout_cnt + 1
        when(enc_clk.rise()){
          timeout_cnt := 0
          bisscdata := False
          goto(Zero)
        }
        when(timeout_cnt > 1000){
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val Zero:State = new State{
      whenIsActive{
        crc_cal.io.cmd.mode := crc_mode.UPDATE
        timeout_cnt := timeout_cnt + 1
        when(enc_clk.rise()){
          timeout_cnt := 0
          bisscdata := postion_reg((datawidth+2-clkrise_cnt-1).resized)
          crc_valid := True
          crc_payload := postion_reg((datawidth+2-clkrise_cnt-1).resized).asBits
          clkrise_cnt := clkrise_cnt + 1
          goto(PostionOut)
        }otherwise{
          crc_valid := False
        }
        when(timeout_cnt > 1000){
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val PostionOut:State = new State{
      whenIsActive{
        crc_cal.io.cmd.mode := crc_mode.UPDATE
        timeout_cnt := timeout_cnt + 1
        when(enc_clk.rise()){
          timeout_cnt := 0
          clkrise_cnt := clkrise_cnt + 1
          bisscdata := postion_reg((datawidth+2-clkrise_cnt-1).resized)
          crc_valid := True
          crc_payload := postion_reg((datawidth+2-clkrise_cnt-1).resized).asBits
          when(clkrise_cnt === datawidth+2){
            clkrise_cnt := 1
            bisscdata := crc_cal.io.crc(5)
            timeout_cnt := 0
            crc_valid := False
            goto(SendCrc)
          }
        }otherwise{
          crc_valid := False
        }
        when(timeout_cnt > 1000){
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val SendCrc:State = new State {
      whenIsActive {
        timeout_cnt := timeout_cnt + 1
        when(enc_clk.rise()) {
          timeout_cnt := 0
          clkrise_cnt := clkrise_cnt + 1
          bisscdata := crc_cal.io.crc((6-clkrise_cnt-1).resized)
          when(clkrise_cnt === 6) {
            bisscdata := False
            timeout_cnt := 0
            goto(TimeOut)
          }
        }
        when(timeout_cnt > 1000) {
          timeout_cnt := 0
          goto(Wait_Start)
        }
      }
    }
    val TimeOut:State = new State{
      whenIsActive{
        crc_valid := True
        when((enc_clk.rise()||enc_clk.fall())){
          timeout_cnt := 0
        }otherwise{
          when(timeout_cnt > timecnt){
            timeout_cnt := 0
            bisscdata := True
            goto(Wait_Start)
          }otherwise{
            timeout_cnt := timeout_cnt+1
          }
        }
      }
    }
  }
  io.s_bissc.data := bisscdata
  addPrePopTask(()=>io.currentState.assignFromBits(fsm.stateReg.asBits))
}

//case class BissC_Slave(datawidth: Int,timecnt : Int) extends Component{
//  val io = new Bundle{
//    val s_bissc = slave(BissCInterface())
//    val m_postion = in Bits(datawidth bits)
//    val currentState = out (Bits(3 bits))
//    val postion_temp = out (UInt(datawidth bits))
//  }
//  noIoPrefix()
//
//  val bisscdata = Reg(Bool()) init True
//  val clkrise_cnt = Reg(UInt(6 bits)) init 0
//  val timeout_cnt = Reg(UInt(16 bits)) init 0
//  val postion_reg = Reg(Bits(datawidth bits))
//
//  io.postion_temp := postion_reg.asUInt
//
//  val enc_clk = Reg(Bool()) init False
//  enc_clk := io.s_bissc.clk
//
//  val fsm = new StateMachine{
//    val Wait_Start:State = new State with EntryPoint{
//      whenIsActive{
//        //bisscdata := True
//        when(enc_clk.rise()){
//          bisscdata := True
//          postion_reg := io.m_postion
//          clkrise_cnt := clkrise_cnt + 1
//          timeout_cnt := 0
//          when(clkrise_cnt >= 2){
//            clkrise_cnt := 0
//            bisscdata := False
//            goto(Ack)
//          }
//        }
//      }
//    }
//    val Ack:State = new State{
//      whenIsActive{
//        timeout_cnt := timeout_cnt + 1
//        when(enc_clk.rise()){
//          timeout_cnt := 0
//          bisscdata := True
//          goto(Start)
//        }
//        when(timeout_cnt > 1000){
//          timeout_cnt := 0
//          goto(Wait_Start)
//        }
//      }
//    }
//    val Start:State = new State{
//      whenIsActive{
//        timeout_cnt := timeout_cnt + 1
//        when(enc_clk.rise()){
//          timeout_cnt := 0
//          bisscdata := False
//          goto(Zero)
//        }
//        when(timeout_cnt > 1000){
//          timeout_cnt := 0
//          goto(Wait_Start)
//        }
//      }
//    }
//    val Zero:State = new State{
//      whenIsActive{
//        timeout_cnt := timeout_cnt + 1
//        when(enc_clk.rise()){
//          timeout_cnt := 0
//          bisscdata := postion_reg((datawidth-clkrise_cnt-1).resized)
//          clkrise_cnt := clkrise_cnt + 1
//          goto(PostionOut)
//        }
//        when(timeout_cnt > 1000){
//          timeout_cnt := 0
//          goto(Wait_Start)
//        }
//      }
//    }
//    val PostionOut:State = new State{
//      whenIsActive{
//        timeout_cnt := timeout_cnt + 1
//        when(enc_clk.rise()){
//          timeout_cnt := 0
//          clkrise_cnt := clkrise_cnt + 1
//          bisscdata := postion_reg((datawidth-clkrise_cnt-1).resized)
//          when(clkrise_cnt === datawidth){
//            bisscdata := False
//            timeout_cnt := 0
//            goto(TimeOut)
//          }
//        }
//        when(timeout_cnt > 1000){
//          timeout_cnt := 0
//          goto(Wait_Start)
//        }
//      }
//    }
//    val TimeOut:State = new State{
//      whenIsActive{
//        when((enc_clk.rise()||enc_clk.fall())){
//          timeout_cnt := 0
//        }otherwise{
//          when(timeout_cnt > timecnt){
//            timeout_cnt := 0
//            bisscdata := True
//            goto(Wait_Start)
//          }otherwise{
//            timeout_cnt := timeout_cnt+1
//          }
//        }
//      }
//    }
//  }
//  io.s_bissc.data := bisscdata
//  addPrePopTask(()=>io.currentState.assignFromBits(fsm.stateReg.asBits))
//}