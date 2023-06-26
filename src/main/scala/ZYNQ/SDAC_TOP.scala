package ZYNQ

import Common.PHPA.{BissCInterface, EncoderInterface, PHPA82_NEW}
import Common.Xil_BlackBox.{Ad5544Interface, Ad7606_Interface, SramLayout}
import spinal.core._
import spinal.lib.io.InOutWrapper
import spinal.lib.{Fragment, Stream, master, slave}

case class SDAC_TOP() extends Component{
  val io = new Bundle{
    val AD7606 = Seq.fill(3)(master(Ad7606_Interface(true,false,false)))
    val BISSC = Seq.fill(4)(master(BissCInterface()))
    val ENCODER = Seq.fill(4)(master(EncoderInterface()))
    val AD5544 = Seq.fill(3)(master(Ad5544Interface()))
    val IO = master(ZYNQ_IO())
    val reset = in Bool()
    val clk_2 = in Bool()
    val gtx_clk = in Bool()
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
  }
  noIoPrefix()

  val hardware_area = new ClockingArea(ClockDomain(io.gtx_clk,io.reset)){

    val hardware_t = HardWare_Top()

    val gtx_txrx = ZYNQ_SDAC_TXRX(false)
    gtx_txrx.io.input <> io.input
    gtx_txrx.io.output <> io.output
    gtx_txrx.io.frame_head := B"64'x00F1F2F30000000F"
    gtx_txrx.io.tx_head := B"32'x00000032"

    for(i <- 0 until 4){
      hardware_t.io.BISSC(i) <> io.BISSC(i)
      gtx_txrx.io.Bissc_Pos(i) <> hardware_t.io.Bissc_Pos(i)
    }
    for(i <- 0 until 4){
      hardware_t.io.ENCODER(i) <> io.ENCODER(i)
      gtx_txrx.io.Encoder_Pos(i) <> hardware_t.io.Encoder_Pos(i)
      gtx_txrx.io.Encoder_Zero_Keep(i) <> hardware_t.io.Encoder_Zero_Keep(i)
      gtx_txrx.io.Encoder_Clr(i) <> hardware_t.io.Encoder_Clr(i)
    }
    for(i <- 0 until 3){
      hardware_t.io.AD7606(i) <> io.AD7606(i)
      gtx_txrx.io.AD7606_DATA(i) := hardware_t.io.adc_data(i).payload
    }
    for(i <- 0 until 3){
      gtx_txrx.io.AD5544_DATA(i) <> hardware_t.io.Dac_Data(i)
      gtx_txrx.io.AD5544_TRIGER(i) <> hardware_t.io.Dac_triger(i)
      hardware_t.io.AD5544(i) <> io.AD5544(i)
    }
    gtx_txrx.io.M_Fault_TTL_Filter <> hardware_t.io.M_Fault_TTL_Filter
    gtx_txrx.io.FPGA_DI_Filter <> hardware_t.io.FPGA_DI_Filter
    gtx_txrx.io.M_EN_TTL <> hardware_t.io.M_EN_TTL
    gtx_txrx.io.FPGA_DO <> hardware_t.io.FPGA_DO

    hardware_t.io.IO <> io.IO
    hardware_t.io.clk_2 <> io.clk_2
    hardware_t.io.clk <> io.gtx_clk
    hardware_t.io.reset <> io.reset
  }
}

object SDAC_TOP extends App{
  SpinalConfig(anonymSignalPrefix = "temp",
    headerWithDate = true,
    targetDirectory = "D:/TZ/TZ_V1.00/MDCB_2.srcs/sources_1/imports/Xil_Master/",
    nameWhenByFile = false,
    enumPrefixEnable = false,
    genLineComments = false
  ).generateVerilog(SDAC_TOP())
}