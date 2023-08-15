package Common.Xil_BlackBox

import Common.PHPA.regFileGen.{genRegFileByMarkdown, regInsert}
import ZYNQ.AxiLite4DataConfig
import spinal.core.{Reg, _}
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.{Counter, IMasterSlave, master, slave}

case class Ad7606_Interface(withos : Boolean = true, withrange : Boolean = false, withwr : Boolean = false, datawidth : Int) extends Bundle with IMasterSlave{
  val data = Bits(datawidth bits)
  val busy = Bool()
  val firstdata = Bool()
  val os = if(withos) UInt(3 bits) else null
  val cs = Bool()
  val rd = Bool()
  val reset = Bool()
  val convsta = Bool()
  val convstb = Bool()
  val range = if(withrange) Bool() else null
  val wr = if(withwr) Bool() else null
  override def asMaster(): Unit = {
    out(cs,rd,reset,convsta,convstb)
    in(data,busy,firstdata)
    if(withos) out(os) else null
    if(withrange) out(range) else null
    if(withwr) out(wr) else null
  }
}

case class AD7606(withos : Boolean = true, withrange : Boolean = false, withwr : Boolean = false) extends Component{
  val io = new Bundle{
    val ad_7606 = master(Ad7606_Interface(withos,withrange,withwr,16))
    val adc_data = master Flow(Vec(Bits(16 bits),8))
  }
  noIoPrefix()

  val ad7606 = new BlackBox {
    setDefinitionName("AD7606_DATA")
    val clk = in Bool()
    val reset = in Bool()
    val sample_en = in Bool()
    val ad_data = in UInt(16 bits)
    val ad_busy = in Bool()
    val first_data = in Bool()
    val ad_os = out UInt(3 bits)
    val ad_cs = out Bool()
    val ad_rd = out Bool()
    val ad_reset = out Bool()
    val ad_convsta = out Bool()
    val ad_convstb = out Bool()
    val ad_range = out Bool()
    val ad_ch1_o = out UInt(16 bits)
    val ad_ch2_o = out UInt(16 bits)
    val ad_ch3_o = out UInt(16 bits)
    val ad_ch4_o = out UInt(16 bits)
    val ad_ch5_o = out UInt(16 bits)
    val ad_ch6_o = out UInt(16 bits)
    val ad_ch7_o = out UInt(16 bits)
    val ad_ch8_o = out UInt(16 bits)
    val ad_data_valid_o = out Bool()
    mapClockDomain(clock = clk,reset = reset)
    addRTLPath("D:/SCALA/SRIO/CYP1401/AD7606_DATA.v")
  }
  ad7606.sample_en := True
  ad7606.ad_data := io.ad_7606.data.asUInt
  ad7606.ad_busy := io.ad_7606.busy
  ad7606.first_data := io.ad_7606.firstdata
  if(withos) io.ad_7606.os := ad7606.ad_os else null
  io.ad_7606.cs := ad7606.ad_cs
  io.ad_7606.rd := ad7606.ad_rd
  io.ad_7606.reset := ad7606.ad_reset
  io.ad_7606.convsta := ad7606.ad_convsta
  io.ad_7606.convstb := ad7606.ad_convstb
  io.adc_data.payload(0) := ad7606.ad_ch1_o.asBits
  io.adc_data.payload(1) := ad7606.ad_ch2_o.asBits
  io.adc_data.payload(2) := ad7606.ad_ch3_o.asBits
  io.adc_data.payload(3) := ad7606.ad_ch4_o.asBits
  io.adc_data.payload(4) := ad7606.ad_ch5_o.asBits
  io.adc_data.payload(5) := ad7606.ad_ch6_o.asBits
  io.adc_data.payload(6) := ad7606.ad_ch7_o.asBits
  io.adc_data.payload(7) := ad7606.ad_ch8_o.asBits
  io.adc_data.valid := ad7606.ad_data_valid_o
}

case class AD7606_N(clk_divide: Int,Wait_Tcnt: Int,withos : Boolean = true, withrange : Boolean = false, withwr : Boolean = false, datawidth : Int = 16) extends Component{
  val io = new Bundle{
    val ad_7606 = master(Ad7606_Interface(withos,withrange,withwr,datawidth))
    val sample_en = in Bool()
    val adc_data = master Flow(Vec(Bits(datawidth bits),8))
  }
  noIoPrefix()

  val sample_clk = Reg(Bool()) init False

  val timer = new Area{
    val counter = Reg(UInt(log2Up(clk_divide)+1 bits)) init 0
    val reset = False
    val sample_clkToogleHit = counter === clk_divide
    counter := counter + 1
    when(reset){
      counter := 0
    }
  }

  when(timer.sample_clkToogleHit){
    sample_clk := !sample_clk
    timer.reset := True
  }

  val sample_area = new ClockingArea(ClockDomain(sample_clk,this.clockDomain.reset)){
    val cs = Reg(Bool()) init True
    val rd = Reg(Bool()) init True
    val convst = Reg(Bool()) init True
    val counter = Reg(UInt(log2Up(Wait_Tcnt)+1 bits)) init 0
    val data = Vec(Reg(Bits(datawidth bits)),8) addTag(crossClockDomain)
    val i = Reg(UInt(4 bits)) init 0
    val valid = Reg(Bool())
    valid := False

    val reset = Reg(Bool()) init False

    val fsm = new StateMachine{
      val Reset_Start: State = new State with EntryPoint {
        whenIsActive{
          counter := counter + 1
          reset := True
          when(counter > 20){
            counter := 0
            reset := False
            goto(Wait_Start)
          }
        }
      }
      val Wait_Start: State = new State{
        whenIsActive{
          when(io.sample_en){
            counter := 0
            goto(Convst_State)
          }
        }
      }
      val Convst_State: State = new State{
        whenIsActive{
          counter := counter+1
          when(counter === 5){
            convst := False
          }elsewhen(counter === 7){
            convst := True
          }elsewhen(counter === 12){
            counter := 0
            goto(Wait_Busy)
          }
        }
      }
      val Wait_Busy: State = new State{
        whenIsActive{
          when(!io.ad_7606.busy){
            goto(CsRd_State)
          }
        }
      }
      val CsRd_State: State = new State{
        whenIsActive{
          cs := False
          rd := False
          goto(Wait_Frstdata)
        }
      }
      val Wait_Frstdata: State = new State{
        whenIsActive{
          when(io.ad_7606.firstdata){
            rd := True
            i := i + 1
            data(0) := io.ad_7606.data
            goto(Rd_Data_Low)
          }
        }
      }
      val Rd_Data_Low: State = new State{
        whenIsActive{
          rd := False
          goto(Rd_Data_High)
        }
      }
      val Rd_Data_High: State = new State{
        whenIsActive{
          rd := True
          when(i < 8){
            data(i.resized) := io.ad_7606.data
            i := i + 1
            goto(Rd_Data_Low)
          }otherwise{
            i := 0
            valid := True
            goto(Wait_Dummy)
          }
        }
      }
      val Wait_Dummy: State = new State{
        whenIsActive{
          cs := True
          counter := counter + 1
          when(counter >= Wait_Tcnt){
            counter := 0
            goto(Wait_Start)
          }
        }
      }
    }
    io.ad_7606.cs := cs
    io.ad_7606.rd := rd
    io.ad_7606.convsta := convst
    io.ad_7606.convstb := convst
    io.ad_7606.reset := reset
    for(i <- 0 until 8){
      io.adc_data.payload(i) := data(i)
    }
    io.adc_data.valid := valid
    if(withos) io.ad_7606.os := 0 else null
    if(withwr) io.ad_7606.wr := True else null
    if(withrange) io.ad_7606.range := True else null
  }
}

case class AD7606_Ctrl(ad7606_num : Int, datawidth : Int, baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val ad_7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(false,false,false,datawidth)))
    val adc_data = Seq.fill(ad7606_num)(master Flow(Vec(Bits(datawidth bits),8)))
    val busy = in Bool()

    def driveFrom(bus: BusSlaveFactoryDelayed, baseAddress: Int = 0) = new Area {
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val adc_data_temp = Seq.fill(ad7606_num)(Reg(Vec(Bits(datawidth bits), 8)))
      when(!busy) {
        for (i <- 0 until ad7606_num) {
          adc_data_temp(i)(0) := adc_data(i).payload(0)
          adc_data_temp(i)(1) := adc_data(i).payload(1)
          adc_data_temp(i)(2) := adc_data(i).payload(2)
          adc_data_temp(i)(3) := adc_data(i).payload(3)
          adc_data_temp(i)(4) := adc_data(i).payload(4)
          adc_data_temp(i)(5) := adc_data(i).payload(5)
          adc_data_temp(i)(6) := adc_data(i).payload(6)
          adc_data_temp(i)(7) := adc_data(i).payload(7)
        }
      }
      for (i <- 0 until ad7606_num) {
        bus.read(adc_data_temp(i)(0), 4 * (8*i), 0, s"ad7606_data(0)_$i")
        bus.read(adc_data_temp(i)(1), 4 * (8*i+1), 0, s"ad7606_data(1)_$i")
        bus.read(adc_data_temp(i)(2), 4 * (8*i+2), 0, s"ad7606_data(2)_$i")
        bus.read(adc_data_temp(i)(3), 4 * (8*i+3), 0, s"ad7606_data(3)_$i")
        bus.read(adc_data_temp(i)(4), 4 * (8*i+4), 0, s"ad7606_data(4)_$i")
        bus.read(adc_data_temp(i)(5), 4 * (8*i+5), 0, s"ad7606_data(5)_$i")
        bus.read(adc_data_temp(i)(6), 4 * (8*i+6), 0, s"ad7606_data(6)_$i")
        bus.read(adc_data_temp(i)(7), 4 * (8*i+7), 0, s"ad7606_data(7)_$i")
      }
      bus.addDataModel("AD7606_Ctrl", baseaddr)
    }
  }
  noIoPrefix()

  val ad7606 = Seq.fill(ad7606_num)(AD7606_N(5,20,false,datawidth = datawidth))
  for(i <- 0 until ad7606_num){
    ad7606(i).io.ad_7606 <> io.ad_7606(i)
    io.adc_data(i) <> ad7606(i).io.adc_data
    ad7606(i).io.sample_en := True
  }
}

case class Apb_AD7606(addrwidth : Int, datawidth : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val ad_7606 = master(Ad7606_Interface(true,false,false,16))
  }
  noIoPrefix()

  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val ad7606 = AD7606_Ctrl(1,16)
  ad7606.io.ad_7606(0) <> io.ad_7606

  val bridge = ad7606.io.driveFrom(bus_ctrl)
  ad7606.io.busy := bus_ctrl.askRead || bus_ctrl.doRead
//  addPrePopTask(()=>genRegFileByMarkdown("AD7606"))
}

object Apb_AD7606 extends App{
  SpinalConfig(anonymSignalPrefix = "temp",headerWithDate = true,enumPrefixEnable = false).generateVerilog(Apb_AD7606(8,16))
}

case class AxiLite_AD7606(ad7606_num : Int) extends Component{
  val io =new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val ad_7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(false,false,false,18)))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val ad7606 = AD7606_Ctrl(3,18)
  for (i <- 0 until ad7606_num) {
    ad7606.io.ad_7606(i) <> io.ad_7606(i)
    io.ad_7606(i).data.setName(s"data_$i")
    io.ad_7606(i).reset.setName(s"reset_$i")
//    io.ad_7606(i).os.setName(s"os_$i")
    io.ad_7606(i).cs.setName(s"cs_$i")
    io.ad_7606(i).busy.setName(s"busy_$i")
    io.ad_7606(i).convsta.setName(s"convsta_$i")
    io.ad_7606(i).convstb.setName(s"convstb_$i")
    io.ad_7606(i).rd.setName(s"rd_$i")
    io.ad_7606(i).firstdata.setName(s"firstdata_$i")
  }
  val bridge = ad7606.io.driveFrom(bus_ctrl)
  ad7606.io.busy := False
  addPrePopTask(()=>genRegFileByMarkdown("AD7606"))
}

object AxiLite_AD7606 extends App{
  SpinalConfig(
    headerWithDate = true,
    nameWhenByFile = false,
    enumPrefixEnable = false,
    genLineComments = false
  ).generateVerilog(AxiLite_AD7606(3))
}