package Common.BISSC

import Common.CRCCORE.{CRC6, CRCCombinational, CRCCombinationalCmdMode, CRCCombinationalConfig}
import Common.PHPA.BissCInterface
import spinal.core._
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.master

case class BisscMaster(datawidth : Int, bissc_clkToogle : Int, Wait_Tcnt : Int) extends Component{
  val io = new Bundle{
    val bissc = master(BissCInterface())
    val postion = out Bits(datawidth bits)
    val status = out Bits(2 bits)
  }
  noIoPrefix()

  val timer = new Area{
    val counter = Reg(UInt(log2Up(bissc_clkToogle)+1 bits))
    val reset = False
    val bissc_clkToogleHit = counter === bissc_clkToogle
    counter := counter + 1
    when(reset){
      counter := 0
    }
  }

  val postion = Reg(Bits(datawidth bits))
  val status = Reg(Bits(2 bits)) init 0

  val bissc_clk = Reg(Bool()) init True
  val bissc_data = Reg(Bool()) init True
  bissc_data := io.bissc.data

  val buffer = Reg(Bits(datawidth+2 bits)) init 0
  val crc_cal = new CRCCombinational(CRCCombinationalConfig(CRC6.BISSC, 1 bits))
  val crc_valid = Reg(Bool()) init False
  val crc_payload = Reg(Bits(1 bits)) init 0
  val crc_mode = CRCCombinationalCmdMode
  crc_cal.io.cmd.valid := crc_valid
  crc_cal.io.cmd.data := crc_payload
  crc_cal.io.cmd.mode := crc_mode.INIT

  val crc = Reg(Bits(6 bits)) init 0

  val crc_check = Reg(Bool()) init False


  val fsm = new StateMachine{
    val counter = Reg(UInt(log2Up(Wait_Tcnt)+1 bits)) init 0
    val Initial_Start: State = new State with EntryPoint {
      whenIsActive{
        when(bissc_data){
          bissc_clk := True
          timer.reset := True
          crc_valid := False
          buffer := 0
          counter := 0
          crc_check := False
          goto(Wait_Ack)
        }
      }
    }
    val Wait_Ack : State = new State{
      whenIsActive{
        when(timer.bissc_clkToogleHit){
          bissc_clk := ~bissc_clk
          timer.reset := True
        }
        when(!bissc_data && bissc_clk){
          goto(Wait_Ack_End)
        }
      }
    }
    val Wait_Ack_End : State = new State{
      whenIsActive{
        when(timer.bissc_clkToogleHit){
          bissc_clk := ~bissc_clk
          timer.reset := True
         }
        when(bissc_data && bissc_clk){
          goto(Wait_Start)
        }
      }
    }
    val Wait_Start : State = new State{
      whenIsActive{
        when(timer.bissc_clkToogleHit){
          bissc_clk := ~bissc_clk
          timer.reset := True
          counter := counter + 1
          when(counter === 1){
            counter := 0
            goto(Wait_Cds)
          }
        }
      }
    }
    val Wait_Cds : State = new State{
      whenIsActive{
        when(timer.bissc_clkToogleHit){
          bissc_clk := ~bissc_clk
          timer.reset := True
          counter := counter + 1
          when(counter === 1){
            counter := 0
            goto(Get_Data)
          }
        }
      }
    }
    val Get_Data : State = new State{
      whenIsActive{
          crc_cal.io.cmd.mode := crc_mode.UPDATE
          when(timer.bissc_clkToogleHit){
            counter := counter + 1
            bissc_clk := ~bissc_clk
            timer.reset := True
            when(!counter.lsb){
              buffer := (buffer##bissc_data).resized
              crc_valid := True
              crc_payload := bissc_data.asBits
            }
            when(counter === (2*(datawidth+2)-1)){
              counter := 0
              crc := 0
              goto(Read_Crc)
            }
          }otherwise{
            crc_valid := False
          }
      }
    }
    val Read_Crc: State = new State{
      whenIsActive{
        when(timer.bissc_clkToogleHit){
          counter := counter + 1
          bissc_clk := ~bissc_clk
          timer.reset := True
          postion := buffer(datawidth-1 downto 2).resized
          status := buffer(1 downto 0)
          when(counter.lsb){
            crc := (crc##bissc_data).resized
          }
          when(counter === (2*6-1)){
            counter := 0
            goto(Dummy_OneCLk)
          }
        }
      }
    }
    val Dummy_OneCLk: State = new State{
      whenIsActive {
        when(timer.bissc_clkToogleHit) {
          counter := counter + 1
          bissc_clk := ~bissc_clk
          timer.reset := True
          when(counter === (2 * 1 - 1)) {
            counter := 0
            goto(Wait_Reset)
          }
        }
      }
    }
    val Wait_Reset: State = new State{
      whenIsActive{
        crc_check := crc === crc_cal.io.crc
        counter := counter + 1
        when(counter > Wait_Tcnt) {
          crc_valid := True
          counter := 0
          goto(Initial_Start)
        }
      }
    }
  }
  io.postion := RegNextWhen(postion,crc_check)
//  io.postion := postion
  io.status := status
  io.bissc.clk := bissc_clk
}

object BisscMaster extends App{
  SpinalConfig(
    nameWhenByFile = false,
    genLineComments = false,
    enumPrefixEnable = false,
    rtlHeader = "BisscMaster"
  ).generateVerilog(new BisscMaster(32,10,100))
}