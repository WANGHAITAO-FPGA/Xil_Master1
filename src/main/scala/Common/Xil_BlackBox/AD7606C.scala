package Common.Xil_BlackBox

import Common.PHPA.regFileGen.{genRegFileByMarkdown, regInsert}
import ZYNQ.AxiLite4DataConfig
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.fsm._
import spinal.lib.misc.Timer
import spinal.lib.{PulseCCByToggle, master, slave}

case class AD7606C(clk_divide: Int,Wait_Tcnt: Int,withos : Boolean = false, withrange : Boolean = false, withwr : Boolean = false) extends Component{
  val io = new Bundle{
    val ad_7606 = master(Ad7606_Interface(withos,withrange,withwr,16))
    val sample_en = in Bool()
    val adc_data = master Flow(Vec(Bits(18 bits),8))
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
    val data = Vec(Reg(Bits(16 bits)),16)  addTag(crossClockDomain)
    val data_payload = Vec(Reg(Bits(18 bits)),8) addTag(crossClockDomain)
    val i = Reg(UInt(5 bits)) init 0
    val valid = Reg(Bool())
    valid := False

    val reset = Reg(Bool()) init False

    val timer_sample =  Timer(32)
    timer_sample.io.tick := True
    timer_sample.io.limit := 52
    when(timer_sample.io.value >= timer_sample.io.limit) {
      timer_sample.io.clear := True
    } otherwise {
      timer_sample.io.clear := False
    }

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
          when(timer_sample.io.full.rise()){
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
          when(i < 16){
            data(i.resized) := io.ad_7606.data
            i := i + 1
            goto(Rd_Data_Low)
          }otherwise{
            i := 0
            valid := True
            for (i <- 0 until 8) {
              data_payload(i) := data(2*i)(15 downto 0)##data(2*i+1)(15 downto 14)
            }
            goto(Wait_Dummy)
          }
        }
      }
      val Wait_Dummy: State = new State{
        whenIsActive{
          cs := True
//          counter := counter + 1
//          when(counter >= Wait_Tcnt){
//            counter := 0
            goto(Wait_Start)
//          }
        }
      }
    }
    io.ad_7606.cs := cs
    io.ad_7606.rd := rd
    io.ad_7606.convsta := convst
    io.ad_7606.convstb := convst
    io.ad_7606.reset := reset
    for(i <- 0 until 8){
      io.adc_data.payload(i) := data_payload(i)
    }

    if(withos) io.ad_7606.os := 0 else null
    if(withwr) io.ad_7606.wr := True else null
    if(withrange) io.ad_7606.range := True else null
  }
  val pluse = new PulseCCByToggle(ClockDomain(sample_clk,this.clockDomain.reset),this.clockDomain)
  pluse.io.pulseIn := sample_area.valid
  io.adc_data.valid := pluse.io.pulseOut
}

object AD7606C extends App{
  SpinalVerilog(AD7606C(5,20))
}

case class AD7606C_Ctrl(ad7606_num : Int, baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val ad_7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(false,false,false,16)))
    val adc_data = Seq.fill(ad7606_num)(master Flow(Vec(Bits(18 bits),8)))
    val busy = in Bool()

    def driveFrom(bus: BusSlaveFactoryDelayed, baseAddress: Int = 0) = new Area {
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val adc_data_temp = Seq.fill(ad7606_num)(Reg(Vec(Bits(18 bits), 8)))
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

  val ad7606 = Seq.fill(ad7606_num)(AD7606C(5,20))
  for(i <- 0 until ad7606_num){
    ad7606(i).io.ad_7606 <> io.ad_7606(i)
    io.adc_data(i) <> ad7606(i).io.adc_data
    ad7606(i).io.sample_en := True
  }
}


case class AxiLite_AD7606C(ad7606_num : Int) extends Component{
  val io =new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val ad_7606 = Seq.fill(ad7606_num)(master(Ad7606_Interface(false,false,false,16)))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val ad7606 = AD7606C_Ctrl(ad7606_num)
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

object AxiLite_AD7606C extends App{
  SpinalConfig(
    headerWithDate = true,
    nameWhenByFile = false,
    enumPrefixEnable = false,
    genLineComments = false
  ).generateVerilog(AxiLite_AD7606C(2))
}