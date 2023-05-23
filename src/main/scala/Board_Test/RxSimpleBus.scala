package Board_Test

import spinal.core._
import spinal.lib._
import spinal.lib.com.eth.{Crc, CrcKind}

case class Rx_Preamble(datawidth : Int) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(datawidth bits))))
    val frame_head = in Bits(64 bits)
    val output = master(Stream(Fragment(Bits(datawidth bits))))
  }
  noIoPrefix()

  val frame_head = Reg(Bits(64 bits))
  frame_head := io.frame_head
  val startDelimiter = frame_head(31 downto 0)##frame_head(63 downto 32)
  val startDelimiterWidth = datawidth*2
  val history = History(io.input, 0 until startDelimiterWidth/datawidth, when = io.input.fire)
  val historyDataCat = B(Cat(history.map(_.payload.fragment).reverse))
  val hit = history.map(_.valid).andR && historyDataCat === startDelimiter
  val inFrame = RegInit(False)

  io.output.valid := False
  io.output.payload  := io.input.payload
  io.input.ready := !inFrame || io.output.ready
  io.output.last := io.input.last

  when(!inFrame){
    when(hit){
      inFrame := True
    }
  } otherwise {
    when(io.input.valid) {
      io.output.valid := True
      when(io.output.ready && io.input.last){
        inFrame := False
      }
    }
  }
}

case class Rx_Checker(dataWidth : Int) extends Component {
  val io = new Bundle {
    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
    val output = master(Stream(Fragment(Bits(dataWidth bits))))
    val error = out Bool()
  }

  val crc = Crc(CrcKind.Crc32, dataWidth)
  crc.io.input.valid := io.input.valid
  crc.io.input.payload := EndiannessSwap(io.input.payload.fragment)
//  crc.io.input.payload := io.input.payload.fragment
  crc.io.flush := io.output.lastFire

  io.output.valid := io.input.valid
  io.output.last := io.input.last
  io.output.payload.fragment := io.input.payload.fragment
  io.input.ready := io.output.ready
  io.error := io.input.last && (crc.io.result =/= io.input.payload.fragment)
}

case class Rx_Final(dataWidth : Int, usecrc : Boolean = true) extends Component {
  val io = new Bundle {
    val input = slave(Stream(Fragment(Bits(dataWidth bits))))
    val output = master(Stream(Fragment(Bits(dataWidth bits))))
    val crc_error = in Bool()
  }
  noIoPrefix()

  val streamfifo = new StreamFifo(Bits(dataWidth bits),64)
  streamfifo.logic.ram.addAttribute("ram_style", "block")

  streamfifo.io.push.payload := io.input.payload.fragment
  streamfifo.io.push.valid := io.input.valid
  io.input.ready := True

  val ready = Reg(Bool()) init False
  val last = Reg(Bool()) init False
  last := io.input.payload.last

  when(last.rise()){
    ready := True
  }elsewhen(io.input.valid){
    ready := False
  }otherwise{
    ready := ready
  }

  if(usecrc){
    streamfifo.io.flush := io.input.payload.last && io.crc_error
  }else{
    streamfifo.io.flush := False
  }

  io.output.payload.fragment := streamfifo.io.pop.payload
  io.output.valid := streamfifo.io.pop.fire
  streamfifo.io.pop.ready := io.output.ready && ready
  io.output.payload.last := (streamfifo.io.occupancy === 1) & io.output.fire
}

case class RxSimpleBus(addrwidth : Int, datawidth : Int, usecrc : Boolean = true) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(datawidth bits))))
    val frame_head = in Bits(64 bits)
    val ram_txbundle = master(Ram_TxBundle(addrwidth,datawidth))
  }
  noIoPrefix()

  val rxpreamble = Rx_Preamble(datawidth)
  rxpreamble.io.frame_head := io.frame_head
  rxpreamble.io.input << io.input

  val rxchecker = Rx_Checker(datawidth)
  rxchecker.io.input << rxpreamble.io.output

  val rx_final = Rx_Final(datawidth,usecrc)
  rx_final.io.input << rxchecker.io.output
  rx_final.io.crc_error := rxchecker.io.error
  rx_final.io.output.ready := True

  val waddr   = Reg(UInt(addrwidth bits)) init 0
  val wdata   = Reg(Bits(datawidth bits))
  val wenable = Reg(Bool()) init False
  val a_flag = Reg(Bool()) init False

  wenable := rx_final.io.output.fire && !rx_final.io.output.payload.last
  when(rx_final.io.output.fire){
    when(!a_flag){
      waddr := 0x100
      a_flag := True
    }otherwise{
      waddr := waddr + 4
    }
    when(rx_final.io.output.payload.last){
      waddr := 0
      a_flag := False
    }
  }
  wdata := rx_final.io.output.payload.fragment

  io.ram_txbundle.WADDR := waddr
  io.ram_txbundle.WDATA := wdata
  io.ram_txbundle.WENABLE := wenable
}