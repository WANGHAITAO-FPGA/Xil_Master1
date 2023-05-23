package Common.Endat

import Common.Endat.Identity.{Get_Bytenumber, Identity_Addr}
import Common.PHPA.ila_test.ila
import spinal.core._
import spinal.lib.com.spi.SpiMaster
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.misc.Timer
import spinal.lib.{Flow, master, slave}

case class Endat_Ctrl(dataWidth : Int, Wait_Tcnt : Int) extends Component{
  val io = new Bundle{
    val spi = master(SpiMaster(1))
    val postion = out Bits(64 bits)
    val endat_ip_trigger = out Bool()
  }
  noIoPrefix()

  val init_timer_tick = Reg(Bool()) init False

  val init_timer = Timer(32)
  init_timer.io.tick := init_timer_tick
  init_timer.io.limit := 5000
  when(init_timer.io.value >= init_timer.io.limit){
    init_timer.io.clear := True
  }otherwise{
    init_timer.io.clear := False
  }

  val cmddata = Reg(Flow(Endat_CtrlCmdData(dataWidth)))

  val endat_spi_ctrl = Endat_SPI_Ctrl(16)
  endat_spi_ctrl.io.spi <> io.spi

  val rsp_valid = Reg(Bool()) init False
  rsp_valid := endat_spi_ctrl.io.rspdata.valid

  val postion = Reg(Bits(64 bits)) init 0

  val status = Reg(Bits(48 bits)) init 0

  val endat_ip_trigger = Reg(Bool())
  endat_ip_trigger := True

  val fsm = new StateMachine{
    val counter = Reg(UInt(log2Up(Wait_Tcnt)+1 bits)) init 0
    val Init_Start: State = new State with EntryPoint {
      whenIsActive{
        cmddata.valid := False
        cmddata.payload.Bytenumber := 0
        init_timer_tick := True
        when(init_timer.io.full){
          init_timer_tick := False
          goto(Config_Reg1)
        }
      }
    }
    val Config_Reg1: State = new State{
      whenIsActive{
        cmddata.payload.Identity_Addr := Identity_Addr(false,Endat_Register.Config_Reg1)
//      CMD_DATA Config High 16 bits   EnDat/SSI set(2 bits) ## IC reset(1 bits) ## fSYS(3 bits) ## Free(1 bits) ## Delay comp(1 bits) ## Cable propagation time(8 bits)
        cmddata.payload.CmdData(0) := B"2'b10"##B"1'b0"##B"3'b110"##B"1'b0"##B"1'b0"##B"8'b00000000"
//      CMD_DATA Config Low 16 bits   Auto reset(1 bits) ## Reset Window(1 bits) ## Data word length(6 bits) ## FTCLK(4 bits) ## Free(1 bits) ## DT(1 bits) ## DU(1 bits) ## HW strobe(1 bits)
        cmddata.payload.CmdData(1) := B"1'b0"##B"1'b1"##B"6'b110000"##B"4'b0010"##B"1'b0"##B"1'b0"##B"1'b1"##B"1'b0"
        cmddata.payload.CmdData(2) := B"16'xFFFF"
        cmddata.payload.CmdData(3) := B"16'xFFFF"
        cmddata.payload.Bytenumber := Get_Bytenumber(Endat_Register.Config_Reg1)
        cmddata.valid := True
        goto(Wait_Config_Reg1_Done)
      }
    }
    val Wait_Config_Reg1_Done: State = new State{
      whenIsActive{
        cmddata.valid := False
        when(rsp_valid.fall()){
          goto(Dummy_State)
        }
      }
    }
    val Dummy_State: State = new State{
      whenIsActive{
        counter := counter + 1
        when(counter > Wait_Tcnt){
          counter := 0
          goto(Load_Send_Reg)
        }
      }
    }
    val Load_Send_Reg: State = new State{
      whenIsActive{
        cmddata.payload.Identity_Addr := Identity_Addr(false,Endat_Register.Send_Reg)
        cmddata.payload.Bytenumber := Get_Bytenumber(Endat_Register.Send_Reg)
        cmddata.payload.CmdData(0) := B"16'x3800"
        cmddata.payload.CmdData(1) := B"16'x0000"
        cmddata.payload.CmdData(2) := B"16'xFFFF"
        cmddata.payload.CmdData(3) := B"16'xFFFF"
        cmddata.valid := True
        goto(Wait_Load_Send_Reg_Done)
      }
    }
    val Wait_Load_Send_Reg_Done: State = new State{
      whenIsActive{
        cmddata.valid := False
        when(rsp_valid.fall()){
          goto(Dummy_State_2)
        }
      }
    }
    val Dummy_State_2: State = new State{
      whenIsActive{
        counter := counter + 1
        when(counter > 50){
          counter := 0
          goto(Load_SW_Strobe)
//          goto(Rd_Receive_Status_Reg)
        }
      }
    }
    val Load_SW_Strobe: State = new State{
      whenIsActive{
        cmddata.payload.Identity_Addr := Identity_Addr(false,Endat_Register.Sw_Strobe)
        cmddata.payload.Bytenumber := Get_Bytenumber(Endat_Register.Sw_Strobe)
        cmddata.payload.CmdData(0) := B"16'xFFFF"
        cmddata.payload.CmdData(1) := B"16'xFFFF"
        cmddata.payload.CmdData(2) := B"16'xFFFF"
        cmddata.payload.CmdData(3) := B"16'xFFFF"
        cmddata.valid := True
        goto(Wait_SW_Strobe_Done)
      }
    }
    val Wait_SW_Strobe_Done: State = new State{
      whenIsActive{
        cmddata.valid := False
        when(rsp_valid.fall()){
          goto(Dummy_State_3)
        }
      }
    }
    val Dummy_State_3: State = new State{
      whenIsActive{
        counter := counter + 1
        when(counter > 10){
          counter := 0
          goto(Rd_Receive_Status_Reg)
        }
      }
    }
    val Rd_Receive_Status_Reg: State = new State{
      whenIsActive{
        cmddata.payload.Identity_Addr := Identity_Addr(true,Endat_Register.Status_Reg)
        cmddata.payload.Bytenumber := Get_Bytenumber(Endat_Register.Status_Reg)
        cmddata.payload.CmdData(0) := B"16'xFFFF"
        cmddata.payload.CmdData(1) := B"16'xFFFF"
        cmddata.payload.CmdData(2) := B"16'xFFFF"
        cmddata.payload.CmdData(3) := B"16'xFFFF"
        cmddata.valid := True
        goto(Wait_Rd_Status_Reg_Done)
      }
    }
    val Wait_Rd_Status_Reg_Done: State = new State{
      whenIsActive{
        cmddata.valid := False
        when(rsp_valid.fall()){
          status := endat_spi_ctrl.io.rspdata.payload.RspData(1)##endat_spi_ctrl.io.rspdata.payload.RspData(2)##endat_spi_ctrl.io.rspdata.payload.RspData(3)
          goto(Dummy_State_4)
        }
      }
    }
    val Dummy_State_4: State = new State{
      whenIsActive{
        counter := counter + 1
        when(counter > 10){
          counter := 0
          goto(Rd_Receive_Reg1)
        }
      }
    }
    val Rd_Receive_Reg1: State = new State{
      whenIsActive{
        cmddata.payload.Identity_Addr := Identity_Addr(true,Endat_Register.Receive_Reg1)
        cmddata.payload.Bytenumber := Get_Bytenumber(Endat_Register.Receive_Reg1)
        cmddata.payload.CmdData(0) := B"16'xFFFF"
        cmddata.payload.CmdData(1) := B"16'xFFFF"
        cmddata.payload.CmdData(2) := B"16'xFFFF"
        cmddata.payload.CmdData(3) := B"16'xFFFF"
        cmddata.valid := True
        goto(Wait_Rd_Receive_Reg1_Done)
      }
    }
    val Wait_Rd_Receive_Reg1_Done: State = new State{
      whenIsActive{
        cmddata.valid := False
        when(rsp_valid.fall()){
          postion := endat_spi_ctrl.io.rspdata.payload.RspData(1)##endat_spi_ctrl.io.rspdata.payload.RspData(2)##endat_spi_ctrl.io.rspdata.payload.RspData(3)##endat_spi_ctrl.io.rspdata.payload.RspData(4)
          goto(Dummy_State_2)
        }
      }
    }
    io.postion := postion
  }
  endat_spi_ctrl.io.cmddata := cmddata
  io.endat_ip_trigger := True
//  val ila_probe=ila("1",io.postion,status)
}

object Endat_Ctrl extends App{
  SpinalVerilog(Endat_Ctrl(16,500))
}