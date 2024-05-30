package Board_Test

import spinal.core._
import spinal.lib._
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.{EndiannessSwap, Fragment, IMasterSlave, Stream, StreamFifo, master, slave, traversableOncePimped}
import spinal.lib
import spinal.lib.com.eth._



case class Ram_RxBundle(addrwidth : Int, datawidth : Int) extends Bundle with IMasterSlave{
  val RENABLE = Bool()
  val RADDR = UInt(addrwidth bits)
  val RDATA = Bits(datawidth bits)

  override def asMaster(): Unit = {
    out(RADDR, RENABLE)
    in(RDATA)
  }
}

case class Ram_TxBundle(addrwidth : Int, datawidth : Int) extends Bundle with IMasterSlave{
  val WADDR   = UInt(addrwidth bits)
  val WDATA   = Bits(datawidth bits)
  val WENABLE = Bool()

  override def asMaster(): Unit = {
    out(WADDR, WDATA, WENABLE)
  }
}

case class TxSimpleBus(addrwidth : Int, datawidth : Int) extends Component{
  val io = new Bundle{
    val output = master(Stream(Fragment(Bits(datawidth bits))))
    val ram_rxbundle = master(Ram_RxBundle(addrwidth,datawidth))
    val tx_tick = in Bool()
    val tx_head = in Bits(datawidth bits)
  }
  noIoPrefix()

  val RENABLE = Reg(Bool()) init False
  val RADDR = Reg(UInt(addrwidth bits)) init 0
  val RDATA = Reg(Bits(datawidth bits))
  val send_length = Reg(UInt(8 bits)) init 0

  val tx_tick = Reg(Bool()) init False
  tx_tick := io.tx_tick

  val tx_length = Reg(UInt(8 bits)) init 0
  tx_length := io.tx_head(7 downto 0).resized.asUInt

  val last = Reg(Bool())
  last := False

  val streamfifo = new StreamFifo(Bits(datawidth bits),64)
  streamfifo.logic.ram.addAttribute("ram_style", "block")

  val fsm =new StateMachine{
    val Wait_Start: State = new State with EntryPoint {
      whenIsActive{
        when(tx_tick.rise()){
          RADDR := 0
          RENABLE := True
          send_length := 0
          goto(Send_Data)
        }
      }
    }
    val Send_Data: State = new State{
      whenIsActive{
        RADDR := RADDR + 4
        send_length := send_length + 1
        when(send_length === tx_length-1){
          last := True
          RENABLE := False
          goto(End)
        }
      }
    }
    val End: State = new State{
      whenIsActive{
        send_length := 0
        RENABLE := False
        goto(Wait_Start)
      }
    }
  }
  io.ram_rxbundle.RADDR := RADDR
  io.ram_rxbundle.RENABLE := RENABLE

  streamfifo.io.push.payload := io.ram_rxbundle.RDATA
  streamfifo.io.push.valid := RegNext(RENABLE)

  io.output.payload.fragment := streamfifo.io.pop.payload
  io.output.valid := streamfifo.io.pop.valid
  streamfifo.io.pop.ready := io.output.ready
  io.output.payload.last := (streamfifo.io.occupancy === 1) & io.output.fire
}


case class Tx_Crc(dataWidth : Int) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
    val output = master(Stream(Fragment(Bits(dataWidth bits))))
  }
  noIoPrefix()
  val emitCrc = RegInit(False) setWhen(io.input.lastFire) clearWhen(io.output.lastFire)
  val crc = Crc(CrcKind.Crc32, dataWidth)
//  crc.io.input << io.input.toFlowFire.translateWith(EndiannessSwap(io.input.payload))
  crc.io.input << io.input.toFlowFire.translateWith((io.input.payload))
  crc.io.flush := io.output.lastFire

  io.output.last := False
  when(!emitCrc) {
    io.output.valid := io.input.valid
    io.output.fragment := io.input.fragment
    io.input.ready := io.output.ready
  } otherwise {
    io.input.ready := False
    io.output.valid := True
    io.output.fragment := crc.io.result
    io.output.last := True
    emitCrc := False
  }
}

case class Tx_Header(dataWidth : Int) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
    val output = master(Stream(Fragment(Bits(dataWidth bits))))
    val frame_header = in Bits(64 bits)
  }
  noIoPrefix()
  val header = io.frame_header  //64bits
  val headerWordsNumber = 64/dataWidth
  val state = Reg(UInt(log2Up(headerWordsNumber+1) bits)) init(0)
  io.output.valid := io.input.valid
  io.output.last := False
  io.input.ready := False
  when(state === headerWordsNumber){
    io.input.ready := io.output.ready
    io.output.payload := io.input.payload
  } otherwise {
    io.output.fragment := header.subdivideIn(dataWidth bits).reverse.read(state.resized)
    when(io.output.fire) {
      state := state + 1
    }
  }
  when(io.input.lastFire){
    state := 0
  }
}

case class Tx_Final(dataWidth : Int) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
    val output = master(Stream(Fragment(Bits(dataWidth bits))))
  }
  noIoPrefix()

  val streamfifo = new StreamFifo(Bits(dataWidth bits),64)
  streamfifo.logic.ram.addAttribute("ram_style", "block")
  streamfifo.io.push.payload := io.input.payload.fragment
  streamfifo.io.push.valid := io.input.valid
  io.input.ready := True

  io.output.payload.fragment := streamfifo.io.pop.payload
  io.output.valid := streamfifo.io.pop.valid
  streamfifo.io.pop.ready := io.output.ready
  io.output.payload.last := (streamfifo.io.occupancy === 1) & io.output.fire
}

case class TxSimpleTop(addrwidth : Int, datawidth : Int) extends Component{
  val io = new Bundle{
    val output = master(Stream(Fragment(Bits(datawidth bits))))
    val ram_rxbundle = master(Ram_RxBundle(addrwidth,datawidth))
    val tx_tick = in Bool()
    val tx_head = in Bits(datawidth bits)
    val frame_head = in Bits(64 bits)
  }
  noIoPrefix()

  val txSimplebus = TxSimpleBus(addrwidth,datawidth)
  txSimplebus.io.tx_tick := io.tx_tick
  txSimplebus.io.tx_head := io.tx_head
  txSimplebus.io.ram_rxbundle <> io.ram_rxbundle

  val txcrc = Tx_Crc(datawidth)
  txcrc.io.input << txSimplebus.io.output

  val txcrc2 = Tx_Crc(datawidth)
  txcrc2.io.input << txcrc.io.output

//  val txheader = Tx_Header(datawidth)
//  txheader.io.input << txcrc2.io.output
//  txheader.io.frame_header := io.frame_head

  val tx_final = Tx_Final(datawidth)
//  tx_final.io.input << txheader.io.output
  tx_final.io.input << txcrc2.io.output

  io.output << tx_final.io.output
}

//case class TxInterFrame(dataWidth : Int) extends Component{
//  val io = new Bundle{
//    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
//    val output = master(Stream(Fragment(Bits(dataWidth bits))))
//  }
//
//  io.output.payload.fragment := io.input.payload.fragment
//  io.output.valid := io.input.valid || RegNext(io.input.last)
//  io.input.ready := io.output.ready
//  io.output.payload.last := RegNext(io.input.last)
//}

object TxSimpleTop extends App{
  SpinalConfig(headerWithDate = true,
    nameWhenByFile = false,
    enumGlobalEnable = false,
    genLineComments = false
  ).generateVerilog(new TxSimpleTop(8,32))
}