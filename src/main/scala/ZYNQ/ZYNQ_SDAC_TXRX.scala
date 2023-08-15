package ZYNQ

import Board_Test.{RxSimpleBus, TxSimpleTop}
import spinal.core._
import spinal.lib.misc.Timer
import spinal.lib.{Fragment, Stream, master, slave}

case class ZYNQ_SDAC_TXRX(usecrc : Boolean, endcoder_num : Int = 4, bissc_num : Int = 4, ad7606_num : Int = 3, ad5544_num : Int = 3) extends Component{
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
    val AD5544_DATA = Seq.fill(ad5544_num)(out (Vec(Bits(16 bits),4)))
    val AD5544_TRIGER = Seq.fill(ad5544_num)(out Bool())
  }
  noIoPrefix()

  val tx_simple = TxSimpleTop(10,32)

  val rx_simple = RxSimpleBus(10,32,usecrc)

  val sdac_reg = SDAC_REG(10,endcoder_num,bissc_num,ad7606_num,ad5544_num)

  val timer = Timer(32)
  timer.io.tick := True
  timer.io.limit := 6250
  when(timer.io.value >= timer.io.limit){
    timer.io.clear := True
  }otherwise{
    timer.io.clear := False
  }

  rx_simple.io.input << io.input
  rx_simple.io.frame_head := io.frame_head

  io.output << tx_simple.io.output
//  tx_simple.io.tx_tick := rx_simple.io.trigger
  tx_simple.io.tx_tick := timer.io.full
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

  for(i <- 0 until ad5544_num){
    sdac_reg.io.AD5544_DATA(i) <> io.AD5544_DATA(i)
    sdac_reg.io.AD5544_TRIGER(i) <> io.AD5544_TRIGER(i)
  }

  io.M_Fault_TTL_Filter <> sdac_reg.io.M_Fault_TTL_Filter
  io.FPGA_DI_Filter <> sdac_reg.io.FPGA_DI_Filter
  io.M_EN_TTL <> sdac_reg.io.M_EN_TTL
  io.FPGA_DO <> sdac_reg.io.FPGA_DO
}