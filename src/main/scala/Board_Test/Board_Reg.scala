package Board_Test

import SimpleBus._
import spinal.core._
import spinal.lib.bus.regif.AccessType.{RO, RW}
import spinal.lib.bus.regif.HtmlGenerator
import spinal.lib.slave

case class Board_Reg(addrwidth : Int, datawidth : Int) extends Component{
  val io = new Bundle{
    val simplebus = slave(SimpleBus(SimpleBusConfig(addrwidth,datawidth)))
    val Board_TxData = in Vec(Bits(datawidth bits),64)
    val Board_RxData = out Vec(Bits(datawidth bits),64)
  }
  noIoPrefix()

  val busslave = SpBusInterface(io.simplebus,(0x0000, 1000 Byte))

  val My_Reg_Tx = (0 until 64).map { i =>
    val Tx_data = busslave.newReg(doc=s"Tx_data$i Tx_data")
    val Board_TxData = Tx_data.field(32 bits,RO,0,s"Board_TxData$i Board_TxData")
    Board_TxData := io.Board_TxData(i)
  }

  val My_Reg_Rx = (0 until 64).map { i =>
    val Rx_data = busslave.newReg(doc=s"Rx_data$i Rx_data")
    val Board_RxData = Rx_data.field(32 bits,RW,0,s"Board_RxData$i Board_RxData")
    io.Board_RxData(i) := Board_RxData
  }

  busslave.accept(HtmlGenerator("board_reg.html", "board_reg"))
}

case class PHPA_Board_Reg() extends Component{
  val io = new Bundle{
    val simplebus = slave(SimpleBus(SimpleBusConfig(10,32)))
    val Board_TxData = in Vec(Bits(16 bits),128)
    val Board_RxData = out Vec(Bits(16 bits),128)
  }
  noIoPrefix()

  val busslave = SpBusInterface(io.simplebus,(0x0000, 1000 Byte))

  val My_Reg_Tx = (0 until 64).map { i =>
    val Tx_data = busslave.newReg(doc=s"Tx_data$i Tx_data")
    val Board_TxData = Tx_data.field(32 bits,RO,0,s"Board_TxData$i Board_TxData")
    Board_TxData(31 downto 16) := io.Board_TxData(2*i)
    Board_TxData(15 downto 0) := io.Board_TxData(2*i+1)
  }

  val My_Reg_Rx = (0 until 64).map { i =>
    val Rx_data = busslave.newReg(doc=s"Rx_data$i Rx_data")
    val Board_RxData = Rx_data.field(32 bits,RW,0,s"Board_RxData$i Board_RxData")
    io.Board_RxData(2*i) := Board_RxData(31 downto 16)
    io.Board_RxData(2*i+1) := Board_RxData(15 downto 0)
  }

  busslave.accept(HtmlGenerator("board_reg.html", "board_reg"))
}


object Board_Reg extends App{
  SpinalVerilog(PHPA_Board_Reg())
}