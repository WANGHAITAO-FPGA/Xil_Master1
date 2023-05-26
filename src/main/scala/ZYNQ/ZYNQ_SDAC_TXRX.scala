package ZYNQ

import Board_Test.{RxSimpleBus, TxSimpleTop}
import spinal.core._
import spinal.lib.{Fragment, Stream, master, slave}

case class ZYNQ_SDAC_TXRX(usecrc : Boolean, endcoder_num : Int = 4, bissc_num : Int = 4, ad7606_num : Int = 3) extends Component{
  val io = new Bundle{
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
    val tx_head = in Bits(32 bits)
    val frame_head = in Bits(64 bits)
    val Encoder_Pos = Seq.fill(endcoder_num)(in Bits(32 bits))
    val Encoder_Zero_Keep = Seq.fill(endcoder_num)(in Bits(1 bits))
    val Encoder_Clr = Seq.fill(endcoder_num)(out Bits(1 bits))
    val Bissc_Pos = Seq.fill(bissc_num)(in Bits(32 bits))
    val AD7606_DATA = Seq.fill(ad7606_num)(in (Vec(Bits(16 bits),8)))
    val M_Fault_TTL_Filter = in Bits(8 bits)
    val FPGA_DI_Filter = in Bits(16 bits)
    val M_EN_TTL = out Bits(8 bits)
    val FPGA_DO = out Bits(16 bits)
  }
  noIoPrefix()

  val tx_simple = TxSimpleTop(10,32)

  val rx_simple = RxSimpleBus(10,32,usecrc)

  val sdac_reg = SDAC_REG()

  rx_simple.io.input << io.input
  rx_simple.io.frame_head := io.frame_head

  io.output << tx_simple.io.output
  tx_simple.io.tx_tick := rx_simple.io.trigger
  tx_simple.io.tx_head := io.tx_head
  tx_simple.io.frame_head := io.frame_head

  sdac_reg.io.simplebus.WADDR := rx_simple.io.ram_txbundle.WADDR
  sdac_reg.io.simplebus.WDATA := rx_simple.io.ram_txbundle.WDATA
  sdac_reg.io.simplebus.WENABLE := rx_simple.io.ram_txbundle.WENABLE
  sdac_reg.io.simplebus.RADDR := tx_simple.io.ram_rxbundle.RADDR
  sdac_reg.io.simplebus.RENABLE := tx_simple.io.ram_rxbundle.RENABLE
  tx_simple.io.ram_rxbundle.RDATA := sdac_reg.io.simplebus.RDATA

  for(i <- 0 until endcoder_num){
    sdac_reg.io.Encoder_Pos(i) <> io.Encoder_Pos(i)
    sdac_reg.io.Encoder_Zero_Keep(i) <> io.Encoder_Zero_Keep(i)
    sdac_reg.io.Encoder_Clr(i) <> io.Encoder_Clr(i)
  }

  for(i <- 0 until bissc_num){
    sdac_reg.io.Bissc_Pos(i) <> io.Bissc_Pos(i)
  }

  for(i <- 0 until ad7606_num){
    sdac_reg.io.AD7606_DATA(i) <> io.AD7606_DATA(i)
  }

  io.M_Fault_TTL_Filter <> sdac_reg.io.M_Fault_TTL_Filter
  io.FPGA_DI_Filter <> sdac_reg.io.FPGA_DI_Filter
  io.M_EN_TTL <> sdac_reg.io.M_EN_TTL
  io.FPGA_DO <> sdac_reg.io.FPGA_DO
}