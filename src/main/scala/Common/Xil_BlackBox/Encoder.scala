package Common.Xil_BlackBox

import Common.PHPA.regFileGen.regInsert
import Common.PHPA.{EncoderInterface, Grating_IO, Grating_Mode}
import spinal.core._
import spinal.lib._
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import Common.PHPA.ZeroClear_Type.AUTO
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}

object ZeroState extends SpinalEnum {
  val ZIDLE, ZWAIT, ZSTOP = newElement()
}

case class ZeroSensor() extends Component {
  val io = new Bundle{
    val zerosensor_in = in Bool()
    val zerosensor_out = out Bool()
    val zero_counter = in UInt(16 bits)
  }
  noIoPrefix()

  val counter = new Counter(0,65535)
  val zerosensor_temp = Reg(Bool()) init False  addTag(crossClockDomain)

  import ZeroState._

  val stateMachine = new Area {
    val state = RegInit(ZIDLE)
    switch(state) {
      is(ZIDLE) {
        when(io.zerosensor_in.rise()){
          state := ZWAIT
          counter.clear()
          zerosensor_temp := True
        }
      }
      is(ZWAIT){
        counter.increment()
        when(counter.value >= io.zero_counter){
          state := ZSTOP
        }
      }
      is(ZSTOP){
        state := ZIDLE
        zerosensor_temp := False
      }
    }
  }
  io.zerosensor_out := zerosensor_temp
}

case class EncoderTop() extends Component{
  val io = new Bundle{
    val encoder = master(EncoderInterface())
    val postion = out Bits(32 bits)
    val zero_singal = out Bool()
    val filter_clk = in Bool()
    val postion_reset = in Bool()
    val zero_counter = in UInt(16 bits)
  }
  noIoPrefix()

  val encoder = new BlackBox {
    setDefinitionName("encoder")
    val clk80m = in Bool()
    val resetn = in Bool()
    val enc_rstn = in Bool()
    val enca = in Bool()
    val encb = in Bool()
    val encx = in Bool()
    val encoder_position_out = out Bits(32 bits)
    val enc_udn = out Bool()
    val enc_cas = out Bool()
    val count_enable = out Bool()
    val count_direction = out Bool()
    val clk160m = in Bool()
    mapClockDomain(clock = clk80m,reset = resetn,resetActiveLevel = LOW)
    addRTLPath("D:/SCALA/Xil_Master/rtl/encoder.v")
  }
  encoder.enca := io.encoder.aphase
  encoder.encb := io.encoder.bphase
  encoder.encx := False
  encoder.clk160m := io.filter_clk
  encoder.enc_rstn := ~io.postion_reset

  val zerosensor = new ZeroSensor()
  zerosensor.io.zerosensor_in := io.encoder.iphase
  io.zero_singal := zerosensor.io.zerosensor_out
  zerosensor.io.zero_counter := io.zero_counter

  io.postion := encoder.encoder_position_out
}

case class EncoderCtrl(baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val config = slave Flow(Grating_Mode())
    val encoder = master(EncoderInterface())
    val encoder_postion = out Bits(32 bits)
    val encoder_zero_singal = out Bool()
    val encoder_filter_clk = in Bool()
    val encoder_postion_reset = in Bool()
    val busy = in Bool()

    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val encoder_postion_temp = Reg(Bits(32 bits)) init 0
      val encoder_zero_singal_temp = Reg(Bool()) init False
      val encoder_postion_reset_temp = Reg(Bool()) init False
      encoder_postion_reset := encoder_postion_reset_temp

      when(!busy){
        encoder_postion_temp := encoder_postion
        encoder_zero_singal_temp := encoder_zero_singal
      }
      bus.busDataWidth match {
        case 16 =>
          bus.read(encoder_postion_temp(31 downto 16),4,0,"Encoder Postion bit(31:16)")
          bus.read(encoder_postion_temp(15 downto 0),6,0,"Encoder Postion bit(15:0)")
        case 32 =>
          bus.read(encoder_postion_temp(31 downto 0),4,0,"Encoder Postion bit(31:0)")
      }
      bus.read(encoder_zero_singal_temp,16,0,"encoder_zero_singal")
      bus.driveAndRead(encoder_postion_reset_temp,20,0,"encoder_postion_reset")

      bus.driveAndRead(config.payload.mode,28,0,"no__use")
      bus.driveAndRead(config.payload.zeroclear_mode,32,0,"encoder zero clear mode,0---AUTO,1----MANUAL")
      bus.driveAndRead(config.payload.zero_counter,36,0,"encoder zero hold time_cnt, time= clk * time_cnt")
      bus.addDataModel("Encoder_Ctrl",baseaddr)
    }
  }

  val encoder = EncoderTop()
  encoder.io.encoder <> io.encoder
  io.encoder_postion := encoder.io.postion
  io.encoder_zero_singal := encoder.io.zero_singal
  encoder.io.filter_clk := io.encoder_filter_clk
  encoder.io.zero_counter := io.config.zero_counter
  encoder.io.postion_reset := Mux((io.config.zeroclear_mode === AUTO),encoder.io.zero_singal,io.encoder_postion_reset)
}

case class Apb3_Encoder(addrwidth : Int, datawidth : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val encoder = master(EncoderInterface())
    val encoder_filter_clk = in Bool()
  }
  noIoPrefix()
  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val encoder_ctrl = EncoderCtrl(baseaddr)
  io.encoder <> encoder_ctrl.io.encoder
  encoder_ctrl.io.encoder_filter_clk := io.encoder_filter_clk

  val bridge = encoder_ctrl.io.driveFrom(bus_ctrl)
  encoder_ctrl.io.busy := bus_ctrl.askRead || bus_ctrl.doRead
}


object Encoder extends App{
  SpinalVerilog(new Apb3_Encoder(8,16))
}