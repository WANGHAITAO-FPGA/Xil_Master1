package Board_Test

import Common.PHPA.ila_test.ila
import spinal.core._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.{Flow, Fragment, PulseCCByToggle, Stream, master, slave}

case class TxRx_Top(usecrc : Boolean = true) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
    val tx_tick = in Bool()
    val tx_head = in Bits(32 bits)
    val frame_head = in Bits(64 bits)
    val Board_TxData = in Vec(Bits(16 bits),128)
    val Board_RxData = out Vec(Bits(16 bits),128)
//    val gtx_clk = in Bool()
  }
  noIoPrefix()

//  val gtx_area = new ClockingArea(ClockDomain(io.gtx_clk,this.clockDomain.reset)){
    val tx_simple = TxSimpleTop(10,32)

    val rx_simple = RxSimpleBus(10,32,usecrc)

    val board_reg = PHPA_Board_Reg()

    io.output << tx_simple.io.output
    tx_simple.io.tx_tick := io.tx_tick
    tx_simple.io.tx_head := io.tx_head
    tx_simple.io.frame_head := io.frame_head

    rx_simple.io.input << io.input
    rx_simple.io.frame_head := io.frame_head

    board_reg.io.simplebus.WADDR := rx_simple.io.ram_txbundle.WADDR
    board_reg.io.simplebus.WDATA := rx_simple.io.ram_txbundle.WDATA
    board_reg.io.simplebus.WENABLE := rx_simple.io.ram_txbundle.WENABLE
    board_reg.io.simplebus.RADDR := tx_simple.io.ram_rxbundle.RADDR
    board_reg.io.simplebus.RENABLE := tx_simple.io.ram_rxbundle.RENABLE
    tx_simple.io.ram_rxbundle.RDATA := board_reg.io.simplebus.RDATA

    board_reg.io.Board_TxData := io.Board_TxData
    io.Board_RxData := board_reg.io.Board_RxData
//  }
}

object BoardConfig{
  def getApb3Config() = Apb3Config(addressWidth = 10,dataWidth = 16)
}

case class Apb_TxRxSimple(lookback : Boolean = false) extends Component{
  val io = new Bundle{
    val apb = slave(Apb3(BoardConfig.getApb3Config()))
    val input = if(!lookback) slave(Flow(Fragment(Bits(32 bits)))) else null
    val output = if(!lookback)  master(Stream(Fragment(Bits(32 bits)))) else null
    val gtx_clk = in Bool()
  }
  noIoPrefix()

  val busctrl = Apb3SlaveFactory(io.apb)

  val gtx_clkdomain = ClockDomain(io.gtx_clk,this.clockDomain.reset)

  val tx_tick = Reg(Bits(16 bits))
  val tx_head = Reg(Bits(32 bits))  addTag(crossClockDomain)
  val frame_head = Reg(Bits(64 bits))  addTag(crossClockDomain)

  val Board_TxData = Reg(Vec(Bits(16 bits),128)) addTag(crossClockDomain)
  val Board_RxData = Reg(Vec(Bits(16 bits),128)) addTag(crossClockDomain)

  val tx_tick_touch = Reg(Bool()) init False
  tx_tick_touch := False

  val gtx_area = new ClockingArea(gtx_clkdomain){
    val txrx = TxRx_Top()
  }

  val pulse = new PulseCCByToggle(this.clockDomain,gtx_clkdomain)
  pulse.io.pulseIn := tx_tick_touch

  if(!lookback){
    gtx_area.txrx.io.input.valid := io.input.valid
    gtx_area.txrx.io.input.payload := io.input.payload
    gtx_area.txrx.io.output <> io.output
  }else{
    gtx_area.txrx.io.input.valid := gtx_area.txrx.io.output.valid
    gtx_area.txrx.io.input.payload := gtx_area.txrx.io.output.payload
    gtx_area.txrx.io.output.ready := True
  }


  gtx_area.txrx.io.Board_TxData := Board_TxData
//  Board_RxData := txrx.io.Board_RxData
  gtx_area.txrx.io.tx_tick := pulse.io.pulseOut

  gtx_area.txrx.io.frame_head := frame_head

  when(tx_head(7 downto 0).asUInt > 64){
    gtx_area.txrx.io.tx_head := 0
  }otherwise{
    gtx_area.txrx.io.tx_head := tx_head
  }

  when(!((busctrl.askRead)||(busctrl.doRead))){
    Board_RxData := gtx_area.txrx.io.Board_RxData
  }

  for(i <- 0 until 128){
    busctrl.driveAndRead(Board_TxData(i), 2*i,bitOffset = 0,documentation = "Board_TxData")
  }
  for(i <- 0 until 128){
    busctrl.read(Board_RxData(i),256+2*i,0,documentation = "Board_RxData")
  }

  when(busctrl.isWriting(520)){
    tx_tick_touch := True
  }

  busctrl.driveAndRead(tx_tick,520,0,documentation = "tx_tick")

  busctrl.driveAndRead(tx_head(31 downto 16),524,0,documentation = "tx_head(31 downto 16)")
  busctrl.driveAndRead(tx_head(15 downto 0),526,0,documentation = "tx_head(15 downto 0)")

  busctrl.driveAndRead(frame_head(63 downto 48),530,0,documentation = "frame_head(63 downto 48)")
  busctrl.driveAndRead(frame_head(47 downto 32),532,0,documentation = "frame_head(47 downto 32)")
  busctrl.driveAndRead(frame_head(31 downto 16),534,0,documentation = "frame_head(31 downto 16)")
  busctrl.driveAndRead(frame_head(15 downto 0),536,0,documentation = "frame_head(15 downto 0)")


  val ila_probe=ila("1",tx_tick_touch,tx_head,frame_head,io.apb.PADDR,io.apb.PENABLE,
    io.apb.PREADY,io.apb.PSEL,io.apb.PWDATA,io.apb.PRDATA)
}

object Apb_TxRxSimple extends App{
  SpinalConfig(
    headerWithDate = true,
    enumPrefixEnable = false,
    nameWhenByFile = false,
    genLineComments = false
  ).generateVerilog(Apb_TxRxSimple())
}