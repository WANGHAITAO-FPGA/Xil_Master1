package ZYNQ

import Common.PHPA.{BissCInterface, EncoderInterface, PHPA82_NEW}
import Common.Xil_BlackBox.{Ad5544Interface, Ad7606_Interface, SramLayout}
import spinal.core._
import spinal.lib._
import spinal.lib.{Fragment, Stream, master, slave}

case class E_PAC_TOP(encoder_num : Int = 4, bissc_num : Int = 4, ad7606_num : Int = 3, ad5544_num : Int = 3) extends Component{
  val io = new Bundle{
    val AD7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(false,false,false,16)))
    val BISSC = Seq.fill(bissc_num)(master(BissCInterface()))
    val ENCODER = Seq.fill(encoder_num)(master(EncoderInterface()))
    val AD5544 = Seq.fill(ad5544_num)(master(Ad5544Interface()))
    val IO = master(ZYNQ_IO())
    val reset = in Bool()
    val clk_2 = in Bool()
    val gtx_clk = in Bool()
    val input = slave(Stream(Fragment(Bits(32 bits))))
    val output = master(Stream(Fragment(Bits(32 bits))))
    val rxruning_led = out Bool()
    val txruning_led = out Bool()
    val runing_led = out Bool()
    val led = out Bool()
  }
  noIoPrefix()

  val hardware_area = new ClockingArea(ClockDomain(io.gtx_clk,io.reset)){

    val hardware_t = HardWare_Top(ad7606_num,bissc_num,encoder_num,ad5544_num)

    val gtx_txrx = ZYNQ_SDAC_TXRX(false,encoder_num,bissc_num,ad7606_num,ad5544_num)
    gtx_txrx.io.input <> io.input
    gtx_txrx.io.output <> io.output
    gtx_txrx.io.frame_head := B"64'xD1D2D3D40000000F"
    gtx_txrx.io.tx_head := B"32'x00000028"

    for(i <- 0 until bissc_num){
      hardware_t.io.BISSC(i) <> io.BISSC(i)
      gtx_txrx.io.Bissc_Pos(i) <> hardware_t.io.Bissc_Pos(i)
    }

    if(encoder_num != 0){
      for (i <- 0 until encoder_num) {
        hardware_t.io.ENCODER(i) <> io.ENCODER(i)
        gtx_txrx.io.Encoder_Pos(i) <> hardware_t.io.Encoder_Pos(i)
        gtx_txrx.io.Encoder_Zero_Keep(i) <> hardware_t.io.Encoder_Zero_Keep(i)
        gtx_txrx.io.Encoder_Clr(i) <> hardware_t.io.Encoder_Clr(i)
      }
    }

    for(i <- 0 until ad7606_num){
      hardware_t.io.AD7606(i) <> io.AD7606(i)
      gtx_txrx.io.AD7606_DATA(i) := hardware_t.io.adc_data(i).payload
    }
    for(i <- 0 until ad5544_num){
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

    val runing = Runing(10000)
    runing.io.tick := io.output.payload.last
    io.runing_led := runing.io.led

    io.rxruning_led <> gtx_txrx.io.rxruning_led

    val tx_runing = Runing(2500)
    tx_runing.io.tick := io.output.payload.last
    io.txruning_led := tx_runing.io.led

//    val error_Check_tx = Error_Check(62500000)
//    error_Check_tx.io.tick := io.output.payload.last
//    io.error_led_tx := error_Check_tx.io.led
//
//    val error_Check_rx = Error_Check(62500000)
//    error_Check_rx.io.tick := io.input.payload.last
//    io.error_led_rx := error_Check_rx.io.led

    val ledtemp = Reg(Bool()) init False

    val counter = CounterFreeRun(62500000)
    when(counter.willOverflow) {
      counter.clear()
      ledtemp := ~ledtemp;
    }
    io.led := ledtemp
  }
}

object E_PAC_TOP_ extends App{
  SpinalConfig(anonymSignalPrefix = "temp",
    headerWithDate = true,
    targetDirectory = "D:/XilinxWorkSpace/E_PAC/E_PAC.srcs/sources_1/new/",
    nameWhenByFile = false,
    enumPrefixEnable = false,
    genLineComments = false
  ).generateVerilog(E_PAC_TOP(4,4,2,3))
}