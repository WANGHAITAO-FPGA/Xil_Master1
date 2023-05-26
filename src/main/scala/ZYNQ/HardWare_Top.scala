package ZYNQ

import Common.PHPA.ila_test.ila
import Common.PHPA.{BissCInterface, EncoderInterface}
import Common.Xil_BlackBox.{AD5544, AD7606, Ad5544Interface, Ad7606_Interface, BISSC, EncoderTop}
import spinal.core._
import spinal.lib.{IMasterSlave, master}

case class ZYNQ_IO() extends Bundle with IMasterSlave{
  val TTL_IO_In = Bits(8 bits)
  val TTL_IO_Out = Bits(8 bits)
  val OPT_IO_In = Bits(16 bits)
  val OPT_IO_Out = Bits(16 bits)
  override def asMaster(): Unit = {
    in(TTL_IO_In,OPT_IO_In)
    out(TTL_IO_Out,OPT_IO_Out)
  }
}

case class HardWare_Top(ad7606_num : Int = 3, bissc_num : Int = 4, encoder_num : Int = 4, ad5544_num : Int = 0) extends Component{
  val io = new Bundle{
    val AD7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(true,false,false)))
    val BISSC = Seq.fill(bissc_num)(master(BissCInterface()))
    val ENCODER = Seq.fill(encoder_num)(master(EncoderInterface()))
    val AD5544 = Seq.fill(ad5544_num)(master(Ad5544Interface()))
    val IO = master(ZYNQ_IO())
    val clk = in Bool()
    val reset = in Bool()
    val clk_2 = in Bool()
    val Bissc_Pos = Seq.fill(bissc_num)(out Bits(32 bits))
    val adc_data = Seq.fill(ad7606_num)(master Flow(Vec(Bits(16 bits),8)))
    val M_Fault_TTL_Filter = out Bits(8 bits)
    val FPGA_DI_Filter = out Bits(16 bits)
    val Encoder_Pos = Seq.fill(encoder_num)(out Bits(32 bits))
    val Encoder_Zero_Keep = Seq.fill(encoder_num)(out Bits(1 bits))
    val Encoder_Clr = Seq.fill(encoder_num)(in Bits(1 bits))
    val Dac_Data = Seq.fill(ad5544_num)(in Vec(Bits(16 bits),4))
    val Dac_triger = Seq.fill(ad5544_num)(in Bool())
    val M_EN_TTL = in Bits(8 bits)
    val FPGA_DO = in Bits(16 bits)
  }
  noIoPrefix()

  val area = new ClockingArea(ClockDomain(io.clk,io.reset)){
    val bissc = Seq.fill(bissc_num)(new BISSC())
    for(i <- 0 until bissc_num){
      bissc(i).io.bissc <> io.BISSC(i)
      io.Bissc_Pos(i) <> bissc(i).io.postion
    }

    val ad7606 = Seq.fill(ad7606_num)(new AD7606())
    for(i <- 0 until ad7606_num){
      ad7606(i).io.ad_7606 <> io.AD7606(i)
      ad7606(i).io.adc_data <> io.adc_data(i)
    }

    val encoder = Seq.fill(encoder_num)(new EncoderTop())
    for(i <- 0 until encoder_num){
      encoder(i).io.encoder <> io.ENCODER(i)
      encoder(i).io.zero_counter := 40000
      encoder(i).io.filter_clk := io.clk_2
      io.Encoder_Pos(i) := encoder(i).io.postion
      io.Encoder_Zero_Keep(i) := encoder(i).io.zero_singal.asBits
      encoder(i).io.postion_reset := io.Encoder_Clr(i).asBool
    }

    val da5544 = Seq.fill(ad5544_num)(AD5544())
    for(i <- 0 until ad5544_num){
      da5544(i).io.ad5544 <> io.AD5544(i)
      da5544(i).io.set_dadata <> io.Dac_Data(i)
      da5544(i).io.triger <> io.Dac_triger(i)
      io.AD5544(i).CS.setName(s"AD5544_CS_$i")
      io.AD5544(i).LDAC.setName(s"AD5544_LDAC_$i")
      //io.ad5544(i).MSB.setName(s"AD5544_MSB_$i")
      io.AD5544(i).RS.setName(s"AD5544_RS_$i")
      io.AD5544(i).SCLK.setName(s"AD5544_SCLK_$i")
      io.AD5544(i).SDIN.setName(s"AD5544_SDIN_$i")
      io.Dac_Data(i)(0).setName(s"DA_OUT_${0+4*i}")
      io.Dac_Data(i)(1).setName(s"DA_OUT_${1+4*i}")
      io.Dac_Data(i)(2).setName(s"DA_OUT_${2+4*i}")
      io.Dac_Data(i)(3).setName(s"DA_OUT_${3+4*i}")
    }

    val iofilter = new ZYNQ_Ioin_Filter(40)
    iofilter.io.M_Fault_TTL := io.IO.TTL_IO_In
    iofilter.io.FPGA_DI := io.IO.OPT_IO_In
    io.M_Fault_TTL_Filter := iofilter.io.M_Fault_TTL_Filter
    io.FPGA_DI_Filter := iofilter.io.FPGA_DI_Filter

    io.IO.TTL_IO_Out := io.M_EN_TTL
    io.IO.OPT_IO_Out := io.FPGA_DO

    val ila_probe=ila("0",io.adc_data(0).payload(0),io.adc_data(0).payload(1),io.adc_data(0).payload(2),io.adc_data(0).payload(3),io.adc_data(0).payload(4),io.adc_data(0).payload(5),io.adc_data(0).payload(6),io.adc_data(0).payload(7),
      io.adc_data(1).payload(0),io.adc_data(1).payload(1),io.adc_data(1).payload(2),io.adc_data(1).payload(3),io.adc_data(1).payload(4),io.adc_data(1).payload(5),io.adc_data(1).payload(6),io.adc_data(1).payload(7))
  }
}

object HardWare_Top extends App{
  SpinalVerilog(new HardWare_Top)
}