package ZYNQ

import Board_Test.{RxSimpleBus, SimpleBus, SimpleBusConfig, TxSimpleTop}
import spinal.core._
import spinal.lib._

case class ZYNQ_TxRx_Simple(usecrc : Boolean = true) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
    val tx_head = in Bits(32 bits)
    val frame_head = in Bits(64 bits)
    val simplebus = master(SimpleBus(SimpleBusConfig(10,32)))
  }
  noIoPrefix()

  val tx_simple = TxSimpleTop(10,32)

  val rx_simple = RxSimpleBus(10,32,usecrc)

  rx_simple.io.input << io.input
  rx_simple.io.frame_head := io.frame_head

  io.output << tx_simple.io.output
  tx_simple.io.tx_tick := rx_simple.io.trigger
  tx_simple.io.tx_head := io.tx_head
  tx_simple.io.frame_head := io.frame_head

  io.simplebus.WADDR := rx_simple.io.ram_txbundle.WADDR
  io.simplebus.WDATA := rx_simple.io.ram_txbundle.WDATA
  io.simplebus.WENABLE := rx_simple.io.ram_txbundle.WENABLE
  io.simplebus.RADDR := tx_simple.io.ram_rxbundle.RADDR
  io.simplebus.RENABLE := tx_simple.io.ram_rxbundle.RENABLE
  tx_simple.io.ram_rxbundle.RDATA := io.simplebus.RDATA
}




object ZYNQ_TxRx_Simple extends App{
  SpinalVerilog(new ZYNQ_SDAC_TXRX(false))
}
