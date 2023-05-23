package Common.Xil_BlackBox

import Common.PHPA.regFileGen.{genRegFileByMarkdown, regInsert}
import spinal.core._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.{IMasterSlave, master, slave}

case class Ad5544Interface() extends Bundle with IMasterSlave{
  val CS = Bool
  val LDAC = Bool
  //val MSB  = Bool
  val RS  = Bool
  val SCLK  = Bool
  val SDIN  = Bool
  override def asMaster(): Unit = {
    out(CS,LDAC,RS,SCLK,SDIN)
  }
}

case class AD5544() extends Component{
  val io = new Bundle{
    val ad5544 = master(Ad5544Interface())
    val set_dadata = in Vec(Bits(16 bits),4)
    val triger = in Bool()
  }
  noIoPrefix()

  val da5544 = new BlackBox {
    setDefinitionName("dac_ad5544")
    val clk = in Bool()
    val reset = in Bool()
    val AD5544_CS = out Bool()
    val AD5544_LDAC = out Bool()
    val AD5544_MSB = out Bool()
    val AD5544_RS = out Bool()
    val AD5544_SCLK = out Bool()
    val AD5544_SDIN = out Bool()
    val ad5544_trig = in Bool()
    val AD5544_DATA_IN1 = in Bits(16 bits)
    val AD5544_DATA_IN2 = in Bits(16 bits)
    val AD5544_DATA_IN3 = in Bits(16 bits)
    val AD5544_DATA_IN4 = in Bits(16 bits)
    mapClockDomain(clock = clk,reset = reset)
    addRTLPath("D:/SCALA/Xil_Master/rtl/dac_ad5544.v")
  }

  io.ad5544.CS := da5544.AD5544_CS
  io.ad5544.LDAC := da5544.AD5544_LDAC
  //io.ad5544.MSB := da5544.AD5544_MSB
  io.ad5544.RS := da5544.AD5544_RS
  io.ad5544.SCLK := da5544.AD5544_SCLK
  io.ad5544.SDIN := da5544.AD5544_SDIN

  da5544.AD5544_DATA_IN1 := io.set_dadata(0)
  da5544.AD5544_DATA_IN2 := io.set_dadata(1)
  da5544.AD5544_DATA_IN3 := io.set_dadata(2)
  da5544.AD5544_DATA_IN4 := io.set_dadata(3)
  da5544.ad5544_trig := io.triger
}

case class AD5544_Ctrl(ad5544_num : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val ad5544 = Seq.fill(ad5544_num)(master(Ad5544Interface()))
    val set_dacdata = Seq.fill(ad5544_num)(in Vec(Bits(16 bits),4))
    val triger = Seq.fill(ad5544_num)(in Bool())

    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val triger_temp = Seq.fill(ad5544_num)(Reg(Bool()))
      for(i <- 0 until ad5544_num){
        bus.driveAndRead(set_dacdata(i)(0),4*(5*i),0,s"DAC_OUT_${0+4*i}")
        bus.driveAndRead(set_dacdata(i)(1),4*(5*i+1),0,s"DAC_OUT_${1+4*i}")
        bus.driveAndRead(set_dacdata(i)(2),4*(5*i+2),0,s"DAC_OUT_${2+4*i}")
        bus.driveAndRead(set_dacdata(i)(3),4*(5*i+3),0,s"DAC_OUT_${3+4*i}")
        bus.driveAndRead(triger_temp(i),4*(5*i+4),0,s"Trigger_$i")
        triger(i) := triger_temp(i) && bus.isWriting(4*(5*i+4))
      }
      bus.addDataModel("AD5544_Ctrl",baseaddr)
    }
  }
  noIoPrefix()

  val da5544 = Seq.fill(ad5544_num)(AD5544())
  for(i <- 0 until ad5544_num){
    da5544(i).io.ad5544 <> io.ad5544(i)
    da5544(i).io.set_dadata <> io.set_dacdata(i)
    da5544(i).io.triger <> io.triger(i)
    io.ad5544(i).CS.setName(s"AD5544_CS_$i")
    io.ad5544(i).LDAC.setName(s"AD5544_LDAC_$i")
    //io.ad5544(i).MSB.setName(s"AD5544_MSB_$i")
    io.ad5544(i).RS.setName(s"AD5544_RS_$i")
    io.ad5544(i).SCLK.setName(s"AD5544_SCLK_$i")
    io.ad5544(i).SDIN.setName(s"AD5544_SDIN_$i")
    io.set_dacdata(i)(0).setName(s"DA_OUT_${0+4*i}")
    io.set_dacdata(i)(1).setName(s"DA_OUT_${1+4*i}")
    io.set_dacdata(i)(2).setName(s"DA_OUT_${2+4*i}")
    io.set_dacdata(i)(3).setName(s"DA_OUT_${3+4*i}")
  }
}


object AD5544 extends App{
  SpinalVerilog(AD5544_Ctrl(3))
}

case class Apb3_AD5544(addrwidth : Int, datawidth : Int,ad5544_num : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val ad5544 = Seq.fill(ad5544_num)(master(Ad5544Interface()))
  }
  noIoPrefix()

  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val ad5544 = AD5544_Ctrl(ad5544_num,baseaddr)
  for(i <- 0 until ad5544_num){
    ad5544.io.ad5544(i) <> io.ad5544(i)
  }
  val bridge = ad5544.io.driveFrom(bus_ctrl)
//  addPrePopTask(()=>genRegFileByMarkdown("AD5544"))
}

object Apb_AD5544 extends App{
  SpinalVerilog(Apb3_AD5544(8,32,3))
}