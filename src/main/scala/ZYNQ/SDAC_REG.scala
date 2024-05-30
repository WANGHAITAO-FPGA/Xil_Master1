package ZYNQ

import Board_Test.{SimpleBus, SimpleBusConfig, SpBusInterface}
import SimpleBus._
import spinal.core._
import spinal.lib._
import spinal.lib.bus.regif.AccessType.{RO, RW}
import spinal.lib.bus.regif.{CHeaderGenerator, HtmlGenerator}
import Common.PHPA.ila_test.ila

import java.time.LocalDate

case class SDAC_REG(addrwidth : Int = 10, endcoder_num : Int = 4, bissc_num : Int = 4, ad7606_num : Int = 3, ad5544_num : Int = 3) extends Component{
  val io = new Bundle{
    val simplebus = slave(SimpleBus(SimpleBusConfig(addrwidth,32)))
    val Encoder_Pos = if(endcoder_num != 0) Seq.fill(endcoder_num)(in Bits(32 bits)) else null
    val Encoder_Zero_Keep = if(endcoder_num != 0) Seq.fill(endcoder_num)(in Bits(1 bits)) else null
    val Encoder_Clr = if(endcoder_num != 0) Seq.fill(endcoder_num)(out Bits(1 bits)) else null
    val Bissc_Pos = Seq.fill(bissc_num)(in Bits(32 bits))
    val AD7606_DATA = Seq.fill(ad7606_num)(in (Vec(Bits(16 bits),8)))
    val M_Fault_TTL_Filter = in Bits(8 bits)
    val FPGA_DI_Filter = in Bits(16 bits)
    val M_EN_TTL = out Bits(8 bits)
    val FPGA_DO = out Bits(16 bits)
    val AD5544_DATA = Seq.fill(ad5544_num)(out (Vec(Bits(16 bits),4)))
    val AD5544_TRIGER = Seq.fill(ad5544_num)(out Bool())
    val Tx_Cnt = in Bits(32 bits)
  }
  noIoPrefix()

  val busslave = SpBusInterface(io.simplebus,(0x0000, 1000 Byte))

  /**********************************************************************************************
   * SDAC 光纤发送数据
   * 包含BISS-C光栅尺、ENCODER增量尺，AD采集数据，IO输入数据
   *********************************************************************************************/
  val My_Reg_Header = busslave.newRegAt(address = 0x0000,doc="帧头")
  val HEADER = My_Reg_Header.field(32 bits,RO,0,"帧头")
  HEADER := B"32'xD1D2D3D4"

  val My_Reg_Slaveid = busslave.newRegAt(address = 0x0004, doc = "ID")
  val SLAVEID = My_Reg_Slaveid.field(32 bits, RO, 0, "ID")
  SLAVEID := B"32'x0000000F"

  val My_Reg_VERSION = busslave.newRegAt(address = 0x0008,doc="软件版本号")
  val VERSION = My_Reg_VERSION.field(32 bits,RO,0,"软件版本号")
  VERSION := LocalDate.now().getYear<<16 | LocalDate.now().getMonthValue<<8 | LocalDate.now().getDayOfMonth

  val My_Reg_Bissc = (0 until bissc_num).map { i =>
    val Bissc_Pos = busslave.newReg(doc=s"Bissc$i 光栅尺位置信号")
    val Bissc_Pos_Data = Bissc_Pos.field(32 bits,RO,0,s"光栅尺,Bissc$i 光栅尺位置信号")
    Bissc_Pos_Data := io.Bissc_Pos(i)
  }

  val My_Reg_Ad7606 = (0 until ad7606_num).map { i =>
    for (j <- 0 until 8) {
      val Ad7606_Pos = busslave.newReg(doc = s"Ad7606_$i 传感器信号")
      val Ad7606_Pos_Data = Ad7606_Pos.field(32 bits, RO, 0, s"ad7606_$i-$j 模拟量信号")
      Ad7606_Pos_Data := io.AD7606_DATA(i)(j).resized
    }
  }

  val My_Reg_TTL_Single = busslave.newReg(doc="8路外部输入TTL信号（例如：PA FAULT输入，限位传感器输入），M_Fault_TTL")
  val TTL1_Single = My_Reg_TTL_Single.fieldAt(0,bc = 1 bits,RO,0,"外部TTL1输入信号，M_Fault_TTL1")
  TTL1_Single := io.M_Fault_TTL_Filter(0).asBits
  val TTL2_Single = My_Reg_TTL_Single.fieldAt(1,bc = 1 bits,RO,0,"外部TTL2输入信号，M_Fault_TTL2")
  TTL2_Single := io.M_Fault_TTL_Filter(1).asBits
  val TTL3_Single = My_Reg_TTL_Single.fieldAt(2,bc = 1 bits,RO,0,"外部TTL3输入信号，M_Fault_TTL3")
  TTL3_Single := io.M_Fault_TTL_Filter(2).asBits
  val TTL4_Single = My_Reg_TTL_Single.fieldAt(3,bc = 1 bits,RO,0,"外部TTL4输入信号，M_Fault_TTL4")
  TTL4_Single := io.M_Fault_TTL_Filter(3).asBits
  val TTL5_Single = My_Reg_TTL_Single.fieldAt(4,bc = 1 bits,RO,0,"外部TTL5输入信号，M_Fault_TTL5")
  TTL5_Single := io.M_Fault_TTL_Filter(4).asBits
  val TTL6_Single = My_Reg_TTL_Single.fieldAt(5,bc = 1 bits,RO,0,"外部TTL6输入信号，M_Fault_TTL6")
  TTL6_Single := io.M_Fault_TTL_Filter(5).asBits
  val TTL7_Single = My_Reg_TTL_Single.fieldAt(6,bc = 1 bits,RO,0,"外部TTL7输入信号，M_Fault_TTL7")
  TTL7_Single := io.M_Fault_TTL_Filter(6).asBits
  val TTL8_Single = My_Reg_TTL_Single.fieldAt(7,bc = 1 bits,RO,0,"外部TTL8输入信号，M_Fault_TTL8")
  TTL8_Single := io.M_Fault_TTL_Filter(7).asBits

  val My_Reg_Opt_Single = busslave.newReg(doc="16路外部输入光耦信号），FPGA_DI(FPGA_B34_IO_IN)")
  val Opt1_Single = My_Reg_Opt_Single.fieldAt(0,bc = 1 bits,RO,0,"外部光耦1输入信号，FPGA_DI1")
  Opt1_Single := io.FPGA_DI_Filter(0).asBits
  val Opt2_Single = My_Reg_Opt_Single.fieldAt(1,bc = 1 bits,RO,0,"外部光耦2输入信号，FPGA_DI2")
  Opt2_Single := io.FPGA_DI_Filter(1).asBits
  val Opt3_Single = My_Reg_Opt_Single.fieldAt(2,bc = 1 bits,RO,0,"外部光耦3输入信号，FPGA_DI3")
  Opt3_Single := io.FPGA_DI_Filter(2).asBits
  val Opt4_Single = My_Reg_Opt_Single.fieldAt(3,bc = 1 bits,RO,0,"外部光耦4输入信号，FPGA_DI4")
  Opt4_Single := io.FPGA_DI_Filter(3).asBits
  val Opt5_Single = My_Reg_Opt_Single.fieldAt(4,bc = 1 bits,RO,0,"外部光耦5输入信号，FPGA_DI5")
  Opt5_Single := io.FPGA_DI_Filter(4).asBits
  val Opt6_Single = My_Reg_Opt_Single.fieldAt(5,bc = 1 bits,RO,0,"外部光耦6输入信号，FPGA_DI6")
  Opt6_Single := io.FPGA_DI_Filter(5).asBits
  val Opt7_Single = My_Reg_Opt_Single.fieldAt(6,bc = 1 bits,RO,0,"外部光耦7输入信号，FPGA_DI7")
  Opt7_Single := io.FPGA_DI_Filter(6).asBits
  val Opt8_Single = My_Reg_Opt_Single.fieldAt(7,bc = 1 bits,RO,0,"外部光耦8输入信号，FPGA_DI8")
  Opt8_Single := io.FPGA_DI_Filter(7).asBits
  val Opt9_Single = My_Reg_Opt_Single.fieldAt(8,bc = 1 bits,RO,0,"外部光耦9输入信号，FPGA_DI9")
  Opt9_Single := io.FPGA_DI_Filter(8).asBits
  val Opt10_Single = My_Reg_Opt_Single.fieldAt(9,bc = 1 bits,RO,0,"外部光耦10输入信号，FPGA_DI10")
  Opt10_Single := io.FPGA_DI_Filter(9).asBits
  val Opt11_Single = My_Reg_Opt_Single.fieldAt(10,bc = 1 bits,RO,0,"外部光耦11输入信号，FPGA_DI11")
  Opt11_Single := io.FPGA_DI_Filter(10).asBits
  val Opt12_Single = My_Reg_Opt_Single.fieldAt(11,bc = 1 bits,RO,0,"外部光耦12输入信号，FPGA_DI12")
  Opt12_Single := io.FPGA_DI_Filter(11).asBits
  val Opt13_Single = My_Reg_Opt_Single.fieldAt(12,bc = 1 bits,RO,0,"外部光耦13输入信号，FPGA_DI13")
  Opt13_Single := io.FPGA_DI_Filter(12).asBits
  val Opt14_Single = My_Reg_Opt_Single.fieldAt(13,bc = 1 bits,RO,0,"外部光耦14输入信号，FPGA_DI14")
  Opt14_Single := io.FPGA_DI_Filter(13).asBits
  val Opt15_Single = My_Reg_Opt_Single.fieldAt(14,bc = 1 bits,RO,0,"外部光耦15输入信号，FPGA_DI15")
  Opt15_Single := io.FPGA_DI_Filter(14).asBits
  val Opt16_Single = My_Reg_Opt_Single.fieldAt(15,bc = 1 bits,RO,0,"外部光耦16输入信号，FPGA_DI16")
  Opt16_Single := io.FPGA_DI_Filter(15).asBits

  if(endcoder_num != 0){
    val My_Reg_Encoder_ZeroSingle = busslave.newReg(doc = "4路增量式光栅尺零位信号")
    val Encoder1_ZeroSingle = My_Reg_Encoder_ZeroSingle.fieldAt(0, bc = 1 bits, RO, 0, "Encoder1零位信号，LE_R_I1")
    Encoder1_ZeroSingle := io.Encoder_Zero_Keep(0)
    val Encoder2_ZeroSingle = My_Reg_Encoder_ZeroSingle.fieldAt(8, bc = 1 bits, RO, 0, "Encoder2零位信号，LE_R_I2")
    Encoder2_ZeroSingle := io.Encoder_Zero_Keep(1)
    val Encoder3_ZeroSingle = My_Reg_Encoder_ZeroSingle.fieldAt(16, bc = 1 bits, RO, 0, "Encoder3零位信号，LE_R_I3")
    Encoder3_ZeroSingle := io.Encoder_Zero_Keep(2)
    val Encoder4_ZeroSingle = My_Reg_Encoder_ZeroSingle.fieldAt(24, bc = 1 bits, RO, 0, "Encoder4零位信号，LE_R_I4")
    Encoder4_ZeroSingle := io.Encoder_Zero_Keep(3)

    val My_Reg_Encoder = (0 until endcoder_num).map { i =>
      val Encoder_Pos = busslave.newReg(doc = s"Encoder$i 增量式光栅尺位置信号")
      val Encoder_Pos_Data = Encoder_Pos.field(32 bits, RO, 0, s"Encoder$i 增量式光栅尺位置信号")
      Encoder_Pos_Data := io.Encoder_Pos(i)
    }
  }

  val My_Reg_AD5544_Loop = busslave.newReg("AD5544 CHANNEL 1##2信号回环信号，AD5544_LOOP")
  val AD5544_temp1_loop = My_Reg_AD5544_Loop.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(0)DA数据通道1回环")
  AD5544_temp1_loop := io.AD5544_DATA(0)(0)
  val AD5544_temp2_loop = My_Reg_AD5544_Loop.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(0)DA数据通道2回环")
  AD5544_temp2_loop := io.AD5544_DATA(0)(1)

  val My_Reg_AD5544_Loop1 = busslave.newReg("AD5544 CHANNEL 3##4信号回环信号，AD5544_LOOP")
  val AD5544_temp3_loop = My_Reg_AD5544_Loop1.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(0)DA数据通道3回环")
  AD5544_temp3_loop := io.AD5544_DATA(0)(2)
  val AD5544_temp4_loop = My_Reg_AD5544_Loop1.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(0)DA数据通道4回环")
  AD5544_temp4_loop := io.AD5544_DATA(0)(3)

  val My_Reg_AD5544_Loop2 = busslave.newReg("AD5544_1 CHANNEL 1##2信号回环信号，AD5544_LOOP")
  val AD5544_temp5_loop = My_Reg_AD5544_Loop2.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(1)DA数据通道1回环")
  AD5544_temp5_loop := io.AD5544_DATA(1)(0)
  val AD5544_temp6_loop = My_Reg_AD5544_Loop2.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(1)DA数据通道2回环")
  AD5544_temp6_loop := io.AD5544_DATA(1)(1)

  val My_Reg_AD5544_Loop3 = busslave.newReg("AD5544_1 CHANNEL 3##4信号回环信号，AD5544_LOOP")
  val AD5544_temp7_loop = My_Reg_AD5544_Loop3.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(1)DA数据通道3回环")
  AD5544_temp7_loop := io.AD5544_DATA(1)(2)
  val AD5544_temp8_loop = My_Reg_AD5544_Loop3.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(1)DA数据通道4回环")
  AD5544_temp8_loop := io.AD5544_DATA(1)(3)

  val My_Reg_AD5544_Loop4 = busslave.newReg("AD5544_2 CHANNEL 1##2信号回环信号，AD5544_LOOP")
  val AD5544_temp9_loop = My_Reg_AD5544_Loop4.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(2)DA数据通道1回环")
  AD5544_temp9_loop := io.AD5544_DATA(2)(0)
  val AD5544_temp10_loop = My_Reg_AD5544_Loop4.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(2)DA数据通道2回环")
  AD5544_temp10_loop := io.AD5544_DATA(2)(1)

  val My_Reg_AD5544_Loop5 = busslave.newReg("AD5544_2 CHANNEL 3##4信号回环信号，AD5544_LOOP")
  val AD5544_temp11_loop = My_Reg_AD5544_Loop5.fieldAt(0,bc = 16 bits,RO,0x8000,"AD5544(2)DA数据通道3回环")
  AD5544_temp11_loop := io.AD5544_DATA(2)(2)
  val AD5544_temp12_loop = My_Reg_AD5544_Loop5.fieldAt(16,bc = 16 bits,RO,0x8000,"AD5544(2)DA数据通道4回环")
  AD5544_temp12_loop := io.AD5544_DATA(2)(3)

  val My_Reg_EN_TTL_LOOP = busslave.newReg("6路外部输出TTL信号回环信号，M_EN_TTL_LOOP")
  val TTL1_Loop = My_Reg_EN_TTL_LOOP.fieldAt(0,bc = 1 bits,RO,0,"外部TTL1输出回环信号")
  TTL1_Loop := io.M_EN_TTL(0).asBits
  val TTL2_Loop = My_Reg_EN_TTL_LOOP.fieldAt(1,bc = 1 bits,RO,0,"外部TTL2输出回环信号")
  TTL2_Loop := io.M_EN_TTL(1).asBits
  val TTL3_Loop = My_Reg_EN_TTL_LOOP.fieldAt(2,bc = 1 bits,RO,0,"外部TTL3输出回环信号")
  TTL3_Loop := io.M_EN_TTL(2).asBits
  val TTL4_Loop = My_Reg_EN_TTL_LOOP.fieldAt(3,bc = 1 bits,RO,0,"外部TTL4输出回环信号")
  TTL4_Loop := io.M_EN_TTL(3).asBits
  val TTL5_Loop = My_Reg_EN_TTL_LOOP.fieldAt(4,bc = 1 bits,RO,0,"外部TTL5输出回环信号")
  TTL5_Loop := io.M_EN_TTL(4).asBits
  val TTL6_Loop = My_Reg_EN_TTL_LOOP.fieldAt(5,bc = 1 bits,RO,0,"外部TTL6输出回环信号")
  TTL6_Loop := io.M_EN_TTL(5).asBits
  val TTL7_Loop = My_Reg_EN_TTL_LOOP.fieldAt(6,bc = 1 bits,RO,0,"外部TTL7输出回环信号")
  TTL7_Loop := io.M_EN_TTL(6).asBits
  val TTL8_Loop = My_Reg_EN_TTL_LOOP.fieldAt(7,bc = 1 bits,RO,0,"外部TTL8输出回环信号")
  TTL8_Loop := io.M_EN_TTL(7).asBits

  val My_Reg_Opt_Loop = busslave.newReg(doc="16路外部输入光耦回环信号）")
  val Opt1_Loop = My_Reg_Opt_Loop.fieldAt(0,bc = 1 bits,RO,0,"外部光耦1输出回环信号")
  Opt1_Loop := io.FPGA_DO(0).asBits
  val Opt2_Loop = My_Reg_Opt_Loop.fieldAt(1,bc = 1 bits,RO,0,"外部光耦2输出回环信号")
  Opt2_Loop := io.FPGA_DO(1).asBits
  val Opt3_Loop = My_Reg_Opt_Loop.fieldAt(2,bc = 1 bits,RO,0,"外部光耦3输出回环信号")
  Opt3_Loop := io.FPGA_DO(2).asBits
  val Opt4_Loop = My_Reg_Opt_Loop.fieldAt(3,bc = 1 bits,RO,0,"外部光耦4输出回环信号")
  Opt4_Loop := io.FPGA_DO(3).asBits
  val Opt5_Loop = My_Reg_Opt_Loop.fieldAt(4,bc = 1 bits,RO,0,"外部光耦5输出回环信号")
  Opt5_Loop := io.FPGA_DO(4).asBits
  val Opt6_Loop = My_Reg_Opt_Loop.fieldAt(5,bc = 1 bits,RO,0,"外部光耦6输出回环信号")
  Opt6_Loop := io.FPGA_DO(5).asBits
  val Opt7_Loop = My_Reg_Opt_Loop.fieldAt(6,bc = 1 bits,RO,0,"外部光耦7输出回环信号")
  Opt7_Loop := io.FPGA_DO(6).asBits
  val Opt8_Loop = My_Reg_Opt_Loop.fieldAt(7,bc = 1 bits,RO,0,"外部光耦8输出回环信号")
  Opt8_Loop := io.FPGA_DO(7).asBits
  val Opt9_Loop = My_Reg_Opt_Loop.fieldAt(8,bc = 1 bits,RO,0,"外部光耦9输出回环信号")
  Opt9_Loop := io.FPGA_DO(8).asBits
  val Opt10_Loop = My_Reg_Opt_Loop.fieldAt(9,bc = 1 bits,RO,0,"外部光耦10输出回环信号")
  Opt10_Loop := io.FPGA_DO(9).asBits
  val Opt11_Loop = My_Reg_Opt_Loop.fieldAt(10,bc = 1 bits,RO,0,"外部光耦11输出回环信号")
  Opt11_Loop := io.FPGA_DO(10).asBits
  val Opt12_Loop = My_Reg_Opt_Loop.fieldAt(11,bc = 1 bits,RO,0,"外部光耦12输出回环信号")
  Opt12_Loop := io.FPGA_DO(11).asBits
  val Opt13_Loop = My_Reg_Opt_Loop.fieldAt(12,bc = 1 bits,RO,0,"外部光耦13输出回环信号")
  Opt13_Loop := io.FPGA_DO(12).asBits
  val Opt14_Loop = My_Reg_Opt_Loop.fieldAt(13,bc = 1 bits,RO,0,"外部光耦14输出回环信号")
  Opt14_Loop := io.FPGA_DO(13).asBits
  val Opt15_Loop = My_Reg_Opt_Loop.fieldAt(14,bc = 1 bits,RO,0,"外部光耦15输出回环信号")
  Opt15_Loop := io.FPGA_DO(14).asBits
  val Opt16_Loop = My_Reg_Opt_Loop.fieldAt(15,bc = 1 bits,RO,0,"外部光耦16输出回环信号")
  Opt16_Loop := io.FPGA_DO(15).asBits

  if(endcoder_num != 0){
    val My_Reg_Encoder_Pos_Clr_Loop = busslave.newReg(doc = "4路增量式光栅尺位置清零控制回环信号")
    val Encoder1_Pos_Clr_Loop = My_Reg_Encoder_Pos_Clr_Loop.fieldAt(0, bc = 1 bits, RO, 0, "Encoder1位置清零回环")
    Encoder1_Pos_Clr_Loop := io.Encoder_Clr(0)

    val Encoder2_Pos_Clr_Loop = My_Reg_Encoder_Pos_Clr_Loop.fieldAt(8, bc = 1 bits, RO, 0, "Encoder2位置清零回环")
    Encoder2_Pos_Clr_Loop := io.Encoder_Clr(1)

    val Encoder3_Pos_Clr_Loop = My_Reg_Encoder_Pos_Clr_Loop.fieldAt(16, bc = 1 bits, RO, 0, "Encoder3位置清零回环")
    Encoder3_Pos_Clr_Loop := io.Encoder_Clr(2)

    val Encoder4_Pos_Clr_Loop = My_Reg_Encoder_Pos_Clr_Loop.fieldAt(24, bc = 1 bits, RO, 0, "Encoder4位置清零回环")
    Encoder4_Pos_Clr_Loop := io.Encoder_Clr(3)
  }

  val My_Reg_Tx_Cnt = busslave.newReg("tx_cnt")
  val Tx_Cnt_Data = My_Reg_Tx_Cnt.field(32 bits,RO,0,s"tx_cnt")
  Tx_Cnt_Data := io.Tx_Cnt
  /**********************************************************************************************
   * SDAC 光纤接受数据
   *
   *********************************************************************************************/
  val My_Reg_AD5544_Datatemp12 = busslave.newRegAt(address = 0x010c,doc="AD5544(U73)DA数据输出")
  val AD5544_Datatemp1 = My_Reg_AD5544_Datatemp12.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U73)DA数据通道1输出")
  io.AD5544_DATA(0)(0) := AD5544_Datatemp1
  val AD5544_Datatemp2 = My_Reg_AD5544_Datatemp12.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U73)DA数据通道2输出")
  io.AD5544_DATA(0)(1) := AD5544_Datatemp2

  val My_Reg_AD5544_Datatemp34 = busslave.newReg(doc="AD5544(U73)DA数据输出")
  val AD5544_Datatemp3 = My_Reg_AD5544_Datatemp34.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U73)DA数据通道3输出")
  io.AD5544_DATA(0)(2) := AD5544_Datatemp3
  val AD5544_Datatemp4 = My_Reg_AD5544_Datatemp34.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U73)DA数据通道4输出")
  io.AD5544_DATA(0)(3) := AD5544_Datatemp4

  val AD5544_Triger1_Temp =  My_Reg_AD5544_Datatemp12.hitDoWrite | My_Reg_AD5544_Datatemp34.hitDoWrite
  io.AD5544_TRIGER(0) := (AD5544_Triger1_Temp|Delay(AD5544_Triger1_Temp,1)|Delay(AD5544_Triger1_Temp,2)|Delay(AD5544_Triger1_Temp,3))

  val My_Reg_AD5544_Datatemp56 = busslave.newReg(doc="AD5544(U83)DA数据输出")
  val AD5544_Datatemp5 = My_Reg_AD5544_Datatemp56.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U83)DA数据通道1输出")
  io.AD5544_DATA(1)(0) := AD5544_Datatemp5
  val AD5544_Datatemp6 = My_Reg_AD5544_Datatemp56.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U83)DA数据通道2输出")
  io.AD5544_DATA(1)(1) := AD5544_Datatemp6

  val My_Reg_AD5544_Datatemp78 = busslave.newReg(doc="AD5544(U83)DA数据输出")
  val AD5544_Datatemp7 = My_Reg_AD5544_Datatemp78.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U83)DA数据通道3输出")
  io.AD5544_DATA(1)(2) := AD5544_Datatemp7
  val AD5544_Datatemp8 = My_Reg_AD5544_Datatemp78.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U83)DA数据通道4输出")
  io.AD5544_DATA(1)(3) := AD5544_Datatemp8

  val AD5544_Triger2_Temp =  My_Reg_AD5544_Datatemp56.hitDoWrite | My_Reg_AD5544_Datatemp78.hitDoWrite
  io.AD5544_TRIGER(1) := (AD5544_Triger2_Temp|Delay(AD5544_Triger2_Temp,1)|Delay(AD5544_Triger2_Temp,2)|Delay(AD5544_Triger2_Temp,3))

  val My_Reg_AD5544_Datatemp910 = busslave.newReg(doc="AD5544(U93)DA数据输出")
  val AD5544_Datatemp9 = My_Reg_AD5544_Datatemp910.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U93)DA数据通道1输出")
  io.AD5544_DATA(2)(0) := AD5544_Datatemp9
  val AD5544_Datatemp10 = My_Reg_AD5544_Datatemp910.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U93)DA数据通道2输出")
  io.AD5544_DATA(2)(1) := AD5544_Datatemp10

  val My_Reg_AD5544_Datatemp1112 = busslave.newReg(doc="AD5544(U93)DA数据输出")
  val AD5544_Datatemp11 = My_Reg_AD5544_Datatemp1112.fieldAt(0,bc = 16 bits,RW,0x8000,"AD5544(U93)DA数据通道3输出")
  io.AD5544_DATA(2)(2) := AD5544_Datatemp11
  val AD5544_Datatemp12 = My_Reg_AD5544_Datatemp1112.fieldAt(16,bc = 16 bits,RW,0x8000,"AD5544(U93)DA数据通道4输出")
  io.AD5544_DATA(2)(3) := AD5544_Datatemp12
  val AD5544_Triger3_Temp =  My_Reg_AD5544_Datatemp910.hitDoWrite | My_Reg_AD5544_Datatemp1112.hitDoWrite
  io.AD5544_TRIGER(2) := (AD5544_Triger3_Temp|Delay(AD5544_Triger3_Temp,1)|Delay(AD5544_Triger3_Temp,2)|Delay(AD5544_Triger3_Temp,3))


  val My_Reg_M_EN_TTL = busslave.newRegAt(address = 0x0124,doc="6路外部输出TTL信号（例如：PA 使能），M_EN_TTL")
  val M_EN_TTL1 = My_Reg_M_EN_TTL.fieldAt(0,bc = 1 bits,RW,0,"外部TTL1输出信号，M_EN_TTL1")
  io.M_EN_TTL(0) := M_EN_TTL1.asBool
  val M_EN_TTL2 = My_Reg_M_EN_TTL.fieldAt(1,bc = 1 bits,RW,0,"外部TTL2输出信号，M_EN_TTL2")
  io.M_EN_TTL(1) := M_EN_TTL2.asBool
  val M_EN_TTL3 = My_Reg_M_EN_TTL.fieldAt(2,bc = 1 bits,RW,0,"外部TTL3输出信号，M_EN_TTL3")
  io.M_EN_TTL(2) := M_EN_TTL3.asBool
  val M_EN_TTL4 = My_Reg_M_EN_TTL.fieldAt(3,bc = 1 bits,RW,0,"外部TTL4输出信号，M_EN_TTL4")
  io.M_EN_TTL(3) := M_EN_TTL4.asBool
  val M_EN_TTL5 = My_Reg_M_EN_TTL.fieldAt(4,bc = 1 bits,RW,0,"外部TTL5输出信号，M_EN_TTL5")
  io.M_EN_TTL(4) := M_EN_TTL5.asBool
  val M_EN_TTL6 = My_Reg_M_EN_TTL.fieldAt(5,bc = 1 bits,RW,0,"外部TTL6输出信号，M_EN_TTL6")
  io.M_EN_TTL(5) := M_EN_TTL6.asBool
  val M_EN_TTL7 = My_Reg_M_EN_TTL.fieldAt(6,bc = 1 bits,RW,0,"外部TTL7输出信号，M_EN_TTL7")
  io.M_EN_TTL(6) := M_EN_TTL7.asBool
  val M_EN_TTL8 = My_Reg_M_EN_TTL.fieldAt(7,bc = 1 bits,RW,0,"外部TTL8输出信号，M_EN_TTL8")
  io.M_EN_TTL(7) := M_EN_TTL8.asBool

  val My_Reg_FPGA_DO = busslave.newReg(doc="16路外部输出光耦信号），FPGA_DO(FPGA_B33_IO_OUT)")
  val FPGA_DO_0 = My_Reg_FPGA_DO.fieldAt(0,bc = 1 bits,RW,0,"外部光耦1输入信号，FPGA_DO1")
  io.FPGA_DO(0) := FPGA_DO_0.asBool
  val FPGA_DO_1 = My_Reg_FPGA_DO.fieldAt(1,bc = 1 bits,RW,0,"外部光耦2输入信号，FPGA_DO2")
  io.FPGA_DO(1) := FPGA_DO_1.asBool
  val FPGA_DO_2 = My_Reg_FPGA_DO.fieldAt(2,bc = 1 bits,RW,0,"外部光耦3输入信号，FPGA_DO3")
  io.FPGA_DO(2) := FPGA_DO_2.asBool
  val FPGA_DO_3 = My_Reg_FPGA_DO.fieldAt(3,bc = 1 bits,RW,0,"外部光耦4输入信号，FPGA_DO4")
  io.FPGA_DO(3) := FPGA_DO_3.asBool
  val FPGA_DO_4 = My_Reg_FPGA_DO.fieldAt(4,bc = 1 bits,RW,0,"外部光耦5输入信号，FPGA_DO5")
  io.FPGA_DO(4) := FPGA_DO_4.asBool
  val FPGA_DO_5 = My_Reg_FPGA_DO.fieldAt(5,bc = 1 bits,RW,0,"外部光耦6输入信号，FPGA_DO6")
  io.FPGA_DO(5) := FPGA_DO_5.asBool
  val FPGA_DO_6 = My_Reg_FPGA_DO.fieldAt(6,bc = 1 bits,RW,0,"外部光耦7输入信号，FPGA_DO7")
  io.FPGA_DO(6) := FPGA_DO_6.asBool
  val FPGA_DO_7 = My_Reg_FPGA_DO.fieldAt(7,bc = 1 bits,RW,0,"外部光耦8输入信号，FPGA_DO8")
  io.FPGA_DO(7) := FPGA_DO_7.asBool
  val FPGA_DO_8 = My_Reg_FPGA_DO.fieldAt(8,bc = 1 bits,RW,0,"外部光耦9输入信号，FPGA_DO9")
  io.FPGA_DO(8) := FPGA_DO_8.asBool
  val FPGA_DO_9 = My_Reg_FPGA_DO.fieldAt(9,bc = 1 bits,RW,0,"外部光耦10输入信号，FPGA_DO10")
  io.FPGA_DO(9) := FPGA_DO_9.asBool
  val FPGA_DO_10 = My_Reg_FPGA_DO.fieldAt(10,bc = 1 bits,RW,0,"外部光耦11输入信号，FPGA_DO11")
  io.FPGA_DO(10) := FPGA_DO_10.asBool
  val FPGA_DO_11 = My_Reg_FPGA_DO.fieldAt(11,bc = 1 bits,RW,0,"外部光耦12输入信号，FPGA_DO12")
  io.FPGA_DO(11) := FPGA_DO_11.asBool
  val FPGA_DO_12 = My_Reg_FPGA_DO.fieldAt(12,bc = 1 bits,RW,0,"外部光耦13输入信号，FPGA_DO13")
  io.FPGA_DO(12) := FPGA_DO_12.asBool
  val FPGA_DO_13 = My_Reg_FPGA_DO.fieldAt(13,bc = 1 bits,RW,0,"外部光耦14输入信号，FPGA_DO14")
  io.FPGA_DO(13) := FPGA_DO_13.asBool
  val FPGA_DO_14 = My_Reg_FPGA_DO.fieldAt(14,bc = 1 bits,RW,0,"外部光耦15输入信号，FPGA_DO15")
  io.FPGA_DO(14) := FPGA_DO_14.asBool
  val FPGA_DO_15 = My_Reg_FPGA_DO.fieldAt(15,bc = 1 bits,RW,0,"外部光耦16输入信号，FPGA_DO16")
  io.FPGA_DO(15) := FPGA_DO_15.asBool

  if(endcoder_num != 0){
    val My_Reg_Encoder_Pos_Clr = busslave.newReg(doc = "4路增量式光栅尺位置清零控制信号")
    val Encoder1_Pos_Clr = My_Reg_Encoder_Pos_Clr.fieldAt(0, bc = 1 bits, RW, 0, "Encoder1位置清零")
    io.Encoder_Clr(0) := Encoder1_Pos_Clr

    val Encoder2_Pos_Clr = My_Reg_Encoder_Pos_Clr.fieldAt(8, bc = 1 bits, RW, 0, "Encoder2位置清零")
    io.Encoder_Clr(1) := Encoder2_Pos_Clr

    val Encoder3_Pos_Clr = My_Reg_Encoder_Pos_Clr.fieldAt(16, bc = 1 bits, RW, 0, "Encoder3位置清零")
    io.Encoder_Clr(2) := Encoder3_Pos_Clr

    val Encoder4_Pos_Clr = My_Reg_Encoder_Pos_Clr.fieldAt(24, bc = 1 bits, RW, 0, "Encoder4位置清零")
    io.Encoder_Clr(3) := Encoder4_Pos_Clr
  }
  busslave.accept(HtmlGenerator("E-PAC-1A", "E-PAC-1A_Reg"))
  busslave.accept(CHeaderGenerator("E_PAC_1A","E_PAC_1A"))
}

object SDAC_REG extends App{
  SpinalVerilog(SDAC_REG(10,0,4,2,3))
}