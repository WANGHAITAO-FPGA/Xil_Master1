package Common.Endat

import Common.CRCCORE.{CRC5, CRC6, CRCCombinational, CRCCombinationalCmdMode, CRCCombinationalConfig}
import Common.PHPA.ila_test.ila
import spinal.core._
import spinal.lib.com.spi.SpiKind
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.{Counter, IMasterSlave, master}

import scala.math.pow

case class LspiInterface() extends Bundle with IMasterSlave{
  val sclk = Bool()
  val mosi = Bool()
  override def asMaster(): Unit = {
    out(sclk,mosi)
  }
}

case class LSPI_Ctrl(datawidth : Int, sclkToogle : Int) extends Component{
  val io = new Bundle{
    val lspi = master(LspiInterface())
    val kind = in(SpiKind())
    val postion = in Bits(datawidth bits)
    val tick = in Bool()
  }
  noIoPrefix()

  val timer = new Area{
    val counter = Reg(UInt(8 bits))
    val reset = Reg(Bool())
    val sclkToogleHit = counter === sclkToogle
    counter := counter + 1
    when(reset){
      counter := 0
    }
  }
  timer.reset := False

  val tick = Reg(Bool()) init False
  tick := io.tick

  val crc_cal = new CRCCombinational(CRCCombinationalConfig(CRC5.ENDAT, 1 bits))
  val crc_valid = Reg(Bool()) init False
  val crc_payload = Reg(Bits(1 bits)) init 0
  val crc_mode = CRCCombinationalCmdMode
  crc_cal.io.cmd.valid := crc_valid
  crc_cal.io.cmd.data := crc_payload
  crc_cal.io.cmd.mode := crc_mode.INIT

  val sclk = Reg(Bool()) init True
  val postion_temp = Reg(Bits(datawidth bits)) init (1<<datawidth)-1

  val fsm = new StateMachine{
    val counter = Counter(datawidth*2)
    val Wait_Start: State = new State with EntryPoint {
      whenIsActive{
        when(tick.rise()){
          counter := 0
          postion_temp := 0
          timer.reset := True
          crc_valid := False
          goto(Send_Zero)
        }
      }
    }
    val Send_Zero: State = new State{
      whenIsActive{
        when(timer.sclkToogleHit) {
          timer.reset := True
          counter.increment()
          when(counter === (1)){
            postion_temp := io.postion
            counter := 0
            goto(Send_Data)
          }
        }
      }
    }
    val Send_Data: State = new State{
      whenIsActive{
        crc_cal.io.cmd.mode := crc_mode.UPDATE
        when(timer.sclkToogleHit) {
          timer.reset := True
          counter.increment()
          when(!counter.lsb){
            crc_valid := True
          }
          when(counter === (2*datawidth-1)){
            counter := 0
            postion_temp := crc_cal.io.crc.resizeLeft(datawidth)
            goto(Send_Crc)
          }
        }otherwise{
          crc_valid := False
        }
      }
    }
    val Send_Crc: State = new State{
      whenIsActive{
        when(timer.sclkToogleHit) {
          timer.reset := True
          counter.increment()
          when(counter === (2*5-1)){
            postion_temp := ((1<<datawidth) - 1)
            crc_valid := True
            goto(Wait_Start)
          }
        }
      }
    }
  }
  io.lspi.sclk := RegNext(((fsm.counter.lsb ^ io.kind.cpha)) ^ io.kind.cpol)
  io.lspi.mosi := RegNext(postion_temp(datawidth-1 - (fsm.counter >> 1)))
  crc_payload := RegNext(postion_temp(datawidth-1 - (fsm.counter >> 1))).asBits
//  val ila_probe=ila("1",io.postion,postion_temp,io.tick,
//    io.lspi.sclk,io.lspi.mosi)
}
