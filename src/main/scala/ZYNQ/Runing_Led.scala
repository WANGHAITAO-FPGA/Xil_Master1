package ZYNQ

import spinal.core._
import spinal.lib._
case class Runing(tick_count : Int) extends Component{
  val io = new Bundle{
    val tick = in Bool()
    val led  = out Bool()
  }
  noIoPrefix()
  val ledtemp = Reg(Bool()) init False
  val counter =  Counter(0,50000)
  when(io.tick.rise()){
    counter.increment()
  }
  when(counter.value > tick_count){
    counter.clear()
    ledtemp := ~ledtemp;
  }
  io.led := ledtemp
}


case class Error_Check(tick_count : Int) extends Component{
  val io = new Bundle{
    val tick = in Bool()
    val led  = out Bool()
  }
  noIoPrefix()

  val ledtemp = Reg(Bool()) init True

  val counter =  Counter(0,800000000)

  when(io.tick.rise()){
    counter.clear()
    ledtemp := True
  }

  when(counter.value > tick_count){
    ledtemp := False
  }otherwise{
    counter.increment()
  }
  io.led := ledtemp
}

object Error_Check extends App{
  SpinalVerilog(new Error_Check(625000000))
}

object Runing extends App{
  SpinalVerilog(Runing(2500))
}