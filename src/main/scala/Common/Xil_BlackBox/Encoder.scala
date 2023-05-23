package Common.Xil_BlackBox

import Common.PHPA.EncoderInterface
import spinal.core._
import spinal.lib._

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

object Encoder extends App{
  SpinalVerilog(new EncoderTop())
}