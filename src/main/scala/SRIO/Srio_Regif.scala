package SRIO

import Board_Test._
import spinal.core._
import spinal.lib.bus.regif.AccessType.{RO, RW}
import spinal.lib.bus.regif.HtmlGenerator
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.{Fragment, Stream, StreamFifoCC, master, slave}

case class Srio_Regif(addrwidth : Int) extends Component{
  val io = new Bundle{
    val simplebus = slave(SimpleBus(SimpleBusConfig(addrwidth,64)))
    val data_in = Seq.fill(16)(in Bits(64 bits))
    val data_out = Seq.fill(16)(out Bits(64 bits))
  }
  noIoPrefix()

  val busslave = SpBusInterface(io.simplebus,(0x0000, 1000 Byte))

  val My_Reg_Version = busslave.newReg(doc="软件版本号")
  val Version = My_Reg_Version.field(64 bits,RO,0,"软件版本号")
  Version := B"x0000202206011514"

  val my_Reg_DataIn = (0 until 16).map{i=>
    val reg_data_in = busslave.newReg(doc = s"data_in$i 输入数据")
    val data_in = reg_data_in.field(64 bits,RO,0,s"data_in$i 输入数据")
    data_in := io.data_in(i)
  }

  val my_Reg_DataOut = (0 until 16).map { i =>
    val reg_data_out = busslave.newReg(doc = s"data_out$i 输出数据")
    val data_out = reg_data_out.field(64 bits, RW, 0, s"data_in$i 输出数据")
    io.data_out(i) := data_out
  }

  busslave.accept(HtmlGenerator("srio_reg.html", "srio_reg"))
}


//case class Srio_FifoCc() extends Component{
//  val io = new Bundle{
//    val srio_clk = in Bool()
//    val gtx_clk = in Bool()
//    val srio_reset = in Bool()
//    val start_cc = in Bool()
//    val data_in = Seq.fill(16)(in Bits(64 bits))
//    val stream_out = master(Stream((Bits(64 bits))))
//  }
//  noIoPrefix()
//
//  val srio_clkdomain = ClockDomain(io.srio_clk,io.srio_reset)
//  val gtx_clkdomain = ClockDomain(io.gtx_clk,io.srio_reset)
//  val srio_area = new ClockingArea(srio_clkdomain){
//    val data_in = Seq.fill(16)(Reg(Bits(64 bits)) init 0)
//    val start_cc = Reg(Bool()) init False
//    start_cc := io.start_cc
//    val fifo = StreamFifoCC(Bits(64 bits),64,srio_clkdomain,gtx_clkdomain)
//    val valid = Reg(Bool()) init False
//    val fifo_data = Reg(Bits(64 bits)) init 0
//
//    val fsm = new StateMachine {
//      val counter = Reg(UInt(8 bits)) init 0
//      val Init_Start: State = new State with EntryPoint {
//        whenIsActive {
//          when(start_cc.rise()){
//            for(idex <- 0 until 16){
//              data_in(idex) := io.data_in(idex)
//            }
//            valid := False
//            counter := 0
//            goto(Send_data0)
//          }
//        }
//      }
//      val Send_data0: State = new State{
//        whenIsActive {
//          fifo_data := data_in(0)
//          valid := True
//          goto(Send_data1)
//        }
//      }
//      val Send_data1: State = new State {
//        whenIsActive {
//          fifo_data := data_in(1)
//          valid := True
//          goto(Send_data2)
//        }
//      }
//      val Send_data2: State = new State {
//        whenIsActive {
//          fifo_data := data_in(2)
//          valid := True
//          goto(Send_data3)
//        }
//      }
//    }
//    fifo.io.push.valid := valid
//    fifo.io.push.payload := fifo_data
//
//    io.stream_out.payload := fifo.io.pop.payload
//    io.stream_out.valid := fifo.io.pop.valid
//    fifo.io.pop.ready := io.stream_out.ready
//  }
//}

//object Srio_FifoCc extends App{
//  SpinalVerilog(Srio_FifoCc())
//}


object Srio_Regif extends App {
  SpinalVerilog(new Srio_Regif(9))
}