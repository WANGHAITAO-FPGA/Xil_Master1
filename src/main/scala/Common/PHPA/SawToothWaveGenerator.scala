package Common.PHPA

import Common.PHPA.ila_test.ila
import Common.PHPA.regFileGen.regInsert
import Common.Xil_BlackBox.{AD5544, AD5544_Ctrl, Ad5544Interface}
import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.misc.Timer

case class SawToothWaveGeneratorIO(stepBits: Int) extends Bundle{
  val direction = in Bool()
  val step = in UInt(stepBits bits)
  val start = in Bool()
  val stop = in Bool()
  val init = in Bool()
}


case class SawToothWaveGenerator(stepBits: Int) extends Component {
  val io = new Bundle {
    val sawtooth_io = SawToothWaveGeneratorIO(stepBits)
    val output = out UInt(16 bits)
    val tick = in Bool()
  }
  val step = Reg(UInt(stepBits bits)) init 0
  step := io.sawtooth_io.step
  val sawtooth = Reg(UInt(15 bits)) init (0)
  val isRunning = RegInit(False)

  val start = Reg(Bool()) init False
  start := io.sawtooth_io.start
  val stop = Reg(Bool()) init False
  stop := io.sawtooth_io.stop
  val init = Reg(Bool()) init False
  init := io.sawtooth_io.init

  val tick = Reg(Bool()) init False
  tick := io.tick

  when((init.rise())||(stop.rise())){
    isRunning := False
  }elsewhen(start.rise()){
    isRunning := True
  }otherwise{
    isRunning := isRunning
  }
  when(init){
    sawtooth := 0
  }

  when(tick.rise()){
    when(isRunning){
      when(io.sawtooth_io.direction){
        when(sawtooth > 32767 -step){
          sawtooth := 0
        }otherwise{
          sawtooth := sawtooth + step
        }
      }otherwise{
        when(sawtooth < step){
          sawtooth := 32767
        }otherwise{
          sawtooth := sawtooth - step
        }
      }
    }
  }
  io.output := (sawtooth + 0x8000).resized
}

case class SawToothData(data_num : Int) extends Bundle{
  val data = Seq.fill(data_num)(Bits(16 bits))
}

case class SawTooth(stepBits : Int = 15, data_num : Int) extends Component{
  val io = new Bundle{
    val sawtooth_io = Seq.fill(data_num)(SawToothWaveGeneratorIO(stepBits))
    val sawtooth_data = master Flow(SawToothData(data_num))
  }
  noIoPrefix()

  val counter = CounterFreeRun(400)
  val tick = Reg(Bool())
  tick := False
  when(counter.willOverflow){
    tick := True
  }
  val sawtoothwavegenerator = Seq.fill(data_num)(SawToothWaveGenerator(stepBits))
  for(i <- 0 until data_num){
    sawtoothwavegenerator(i).io.sawtooth_io <> io.sawtooth_io(i)
    sawtoothwavegenerator(i).io.tick := tick
    io.sawtooth_data.payload.data(i) := sawtoothwavegenerator(i).io.output.asBits
  }
  io.sawtooth_data.valid := Delay(tick,2,init = False)

//  val ila_probe=ila("1",io.sawtooth_io(0).start,io.sawtooth_io(0).step,io.sawtooth_io(0).stop,io.sawtooth_io(0).step,io.sawtooth_io(0).init,
//    io.sawtooth_data.payload.data(0),io.sawtooth_data.valid)
}

case class SawToothTop(baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val sawtooth_io = Seq.fill(4)(SawToothWaveGeneratorIO(15))
    val ad5544 = master(Ad5544Interface())
    val analog_mode = in Bool()
    val analog_setdata = in Vec(Bits(16 bits),4)
    val analog_trigger = in Bool()
    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val triger_temp = Reg(Bool())
      bus.driveAndRead(analog_setdata(0),0,0,s"analog_setdata_1，模拟量模式通道1")
      bus.driveAndRead(analog_setdata(1),4,0,s"analog_setdata_2，模拟量模式通道2")
      bus.driveAndRead(analog_setdata(2),8,0,s"analog_setdata_3，模拟量模式通道3")
      bus.driveAndRead(analog_setdata(3),12,0,s"analog_setdata_4，模拟量模式通道4")
      bus.read(triger_temp,16,0,s"analog_trigger，模拟量模式trigger")
      bus.driveAndRead(analog_mode,20,0,s"analog_mode,0----模拟量模式，1-----自动发送波形")
      when(bus.isWriting(16)){
        triger_temp := True
      }otherwise{
        triger_temp := False
      }
      analog_trigger := triger_temp|Delay(triger_temp,1,init = False)|Delay(triger_temp,2,init = False)|Delay(triger_temp,3,init = False)

      for(i <- 0 until 4){
        bus.driveAndRead(sawtooth_io(i).start,4*(3*i+6),0,"sawtooth_io start，0x0001----start")
        bus.driveAndRead(sawtooth_io(i).stop,4*(3*i+6),4,"sawtooth_io stop,0x0010------stop")
        bus.driveAndRead(sawtooth_io(i).init,4*(3*i+6),8,"sawtooth_io init,0x0100-----reset")

        bus.driveAndRead(sawtooth_io(i).step,4*(3*i+7),0,"sawtooth_io step,步长 0---255")
        bus.driveAndRead(sawtooth_io(i).direction,4*(3*i+8),0,"sawtooth_io direction，1----正向运动，0----负向运动")
      }
      bus.addDataModel("AD5544_Ctrl",baseaddr)
    }
  }
  noIoPrefix()

  val sawtooth = SawTooth(15,4)
  for(i <- 0 until 4){
    sawtooth.io.sawtooth_io(i) <> io.sawtooth_io(i)
  }
  val da5544 = AD5544()
  da5544.io.ad5544 <> io.ad5544

//  val set_data = Vec(Reg(Bits(16 bits)),4)
//  val trigger = Reg(Bool()) init False
//  when(io.analog_mode){
//    set_data(0) := sawtooth.io.sawtooth_data.payload.data(0)
//    set_data(1) := sawtooth.io.sawtooth_data.payload.data(1)
//    set_data(2) := sawtooth.io.sawtooth_data.payload.data(2)
//    set_data(3) := sawtooth.io.sawtooth_data.payload.data(3)
//    trigger := sawtooth.io.sawtooth_data.valid
//  }otherwise{
//    set_data(0) := io.analog_setdata(0)
//    set_data(1) := io.analog_setdata(1)
//    set_data(2) := io.analog_setdata(2)
//    set_data(3) := io.analog_setdata(3)
//    trigger := io.analog_trigger
//  }
//  da5544.io.set_dadata(0) := set_data(0)
//  da5544.io.set_dadata(1) := set_data(1)
//  da5544.io.set_dadata(2) := set_data(2)
//  da5544.io.set_dadata(3) := set_data(3)
//  da5544.io.triger := trigger
  val valid = Reg(Bool()) init False
  valid := sawtooth.io.sawtooth_data.valid|Delay(sawtooth.io.sawtooth_data.valid,1,init = False)|Delay(sawtooth.io.sawtooth_data.valid,2,init = False)|Delay(sawtooth.io.sawtooth_data.valid,3,init = False)

  da5544.io.set_dadata(0) := Mux(io.analog_mode, sawtooth.io.sawtooth_data.payload.data(0), io.analog_setdata(0))
  da5544.io.set_dadata(1) := Mux(io.analog_mode, sawtooth.io.sawtooth_data.payload.data(1), io.analog_setdata(1))
  da5544.io.set_dadata(2) := Mux(io.analog_mode, sawtooth.io.sawtooth_data.payload.data(2), io.analog_setdata(2))
  da5544.io.set_dadata(3) := Mux(io.analog_mode, sawtooth.io.sawtooth_data.payload.data(3), io.analog_setdata(3))
  da5544.io.triger := Mux(io.analog_mode, valid, io.analog_trigger)
}

case class Apb_SawTooth(addrwidth : Int, datawidth : Int, baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val ad5544 = master(Ad5544Interface())
  }
  noIoPrefix()

  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val ad5544 = SawToothTop(baseaddr)
  ad5544.io.ad5544 <> io.ad5544
  val bridge = ad5544.io.driveFrom(bus_ctrl)
}


object SawToothWaveGenerator extends App{
  SpinalVerilog(Apb_SawTooth(8,16,0))
}