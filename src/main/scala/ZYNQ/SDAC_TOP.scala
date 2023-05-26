package ZYNQ

import Common.PHPA.{BissCInterface, EncoderInterface, PHPA82_NEW}
import Common.Xil_BlackBox.{Ad7606_Interface, SramLayout}
import spinal.core._
import spinal.lib.io.InOutWrapper
import spinal.lib.{Fragment, Stream, master, slave}

case class SDAC_TOP() extends Component{
  val io = new Bundle{
    val AD7606 = Seq.fill(3)(master(Ad7606_Interface(true,false,false)))
    val BISSC = Seq.fill(4)(master(BissCInterface()))
    val ENCODER = Seq.fill(4)(master(EncoderInterface()))
    val IO = master(ZYNQ_IO())
    val clk = in Bool()
    val reset = in Bool()
    val clk_2 = in Bool()
    val gtx_clk = in Bool()
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
  }
  noIoPrefix()

  val hardware_area = new ClockingArea(ClockDomain(io.clk,io.reset)){
    val hardware_t = HardWare_Top()

    val bissc_pos = Vec((Reg(Bits(32 bits)) init 0),4) addTag(crossClockDomain)
    val adc_data = Vec(Vec((Reg(Bits(16 bits)) init 0),8),3) addTag(crossClockDomain)
    val encoder_pos = Vec((Reg(Bits(32 bits)) init 0),4) addTag(crossClockDomain)
    val encoder_zero_single = Vec((Reg(Bits(1 bits)) init 0),4) addTag(crossClockDomain)
    val encoder_clr = Vec((Reg(Bits(1 bits)) init 0),4)  addTag(crossClockDomain)

    val ttl_in_filter = Reg(Bits(8 bits)) init 0  addTag(crossClockDomain)
    val opt_in_fliter = Reg(Bits(16 bits)) init 0  addTag(crossClockDomain)
    val ttl_out = Reg(Bits(8 bits)) init 0  addTag(crossClockDomain)
    val opt_out = Reg(Bits(16 bits)) init 0  addTag(crossClockDomain)

    for(i <- 0 until 3){
      hardware_t.io.AD7606(i) <> io.AD7606(i)
      adc_data(i) := hardware_t.io.adc_data(i).payload
    }
    for(i <- 0 until 4){
      hardware_t.io.BISSC(i) <> io.BISSC(i)
      bissc_pos(i) := hardware_t.io.Bissc_Pos(i)
    }
    for(i <- 0 until 4){
      hardware_t.io.ENCODER(i) <> io.ENCODER(i)
      encoder_pos(i) := hardware_t.io.Encoder_Pos(i)
      encoder_zero_single(i) := hardware_t.io.Encoder_Zero_Keep(i)
      hardware_t.io.Encoder_Clr(i) := encoder_clr(i)
    }

    ttl_in_filter := hardware_t.io.M_Fault_TTL_Filter
    opt_in_fliter := hardware_t.io.FPGA_DI_Filter
    hardware_t.io.M_EN_TTL := ttl_out
    hardware_t.io.FPGA_DO := opt_out

    hardware_t.io.IO <> io.IO
    hardware_t.io.clk_2 <> io.clk_2
    hardware_t.io.clk <> io.clk
    hardware_t.io.reset <> io.reset
  }

  val gtx_area = new ClockingArea(ClockDomain(io.gtx_clk,io.reset)){
    val gtx_txrx = ZYNQ_SDAC_TXRX(false)
    gtx_txrx.io.input <> io.input
    gtx_txrx.io.output <> io.output
    gtx_txrx.io.frame_head := B"64'x00F3F2F10000000F"
    gtx_txrx.io.tx_head := B"32'x00000020"

    for(i <- 0 until 4){
      gtx_txrx.io.Bissc_Pos(i) <> hardware_area.bissc_pos(i)
    }
    for(i <- 0 until 4){
      gtx_txrx.io.Encoder_Pos(i) <> hardware_area.encoder_pos(i)
      gtx_txrx.io.Encoder_Zero_Keep(i) <> hardware_area.encoder_zero_single(i)
      gtx_txrx.io.Encoder_Clr(i) <> hardware_area.encoder_clr(i)
    }
    for(i <- 0 until 3){
      gtx_txrx.io.AD7606_DATA(i) := hardware_area.adc_data(i)
    }
    gtx_txrx.io.M_Fault_TTL_Filter <> hardware_area.ttl_in_filter
    gtx_txrx.io.FPGA_DI_Filter <> hardware_area.opt_in_fliter
    gtx_txrx.io.M_EN_TTL <> hardware_area.ttl_out
    gtx_txrx.io.FPGA_DO <> hardware_area.opt_out
  }
}

object SDAC_TOP extends App{
  SpinalConfig(anonymSignalPrefix = "temp",
    headerWithDate = true,
//    targetDirectory = "E:/TZ/TZ_SDAC_V1.00/MDCB_2.srcs/sources_1/imports/Xil_Master/",
    genLineComments = false
  ).generateVerilog(SDAC_TOP())
}