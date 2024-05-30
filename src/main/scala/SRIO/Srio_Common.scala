package SRIO

import Board_Test._
import spinal.core._
import spinal.lib.bus.regif.AccessType.{RO, RW}
import spinal.lib.bus.regif.HtmlGenerator
import spinal.lib._
import spinal.lib.fsm.{EntryPoint, State, StateMachine}

case class Srio_Common(addrwidth : Int) extends Component{
  val io = new Bundle{
    val simplebus = slave(SimpleBus(SimpleBusConfig(addrwidth,64)))
    val data_in = Seq.fill(16)(in Bits(64 bits))
    val data_out = Seq.fill(16)(out Bits(64 bits))
  }
  noIoPrefix()

  val busslave = SpBusInterface(io.simplebus,(0x0000, 1000 Byte))

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
  busslave.accept(HtmlGenerator("srio_commonreg.html", "srio_commonreg"))
}

case class Srio_FifoCc(addrwidth : Int) extends Component{
  val io = new Bundle{
    val ccin_rxbundle = master(Ram_RxBundle(addrwidth, 64))
    val ccout_txbundle = master(Ram_TxBundle(addrwidth,64))
    val tx_tick = in Bool()
    val ccin_clk = in Bool()
    val ccout_clk = in Bool()
    val reset = in Bool()
  }
  noIoPrefix()

  val ccin_clkdomain = ClockDomain(io.ccin_clk,io.reset)
  val ccout_clkdomain = ClockDomain(io.ccout_clk,io.reset)
  val srio_area = new ClockingArea(ccin_clkdomain){
    val trigger = Reg(Bool()) init False
    val RENABLE = Reg(Bool()) init False
    val RADDR = Reg(UInt(addrwidth bits)) init 0
    val streamfifo = new StreamFifoCC(Bits(64 bits), 64,ccin_clkdomain,ccout_clkdomain)

    val tx_tick = Reg(Bool()) init False
    tx_tick := io.tx_tick

    val last = Reg(Bool())
    last := False

    val send_length = Reg(UInt(8 bits)) init 0

    val fsm = new StateMachine {
      val Wait_Start: State = new State with EntryPoint {
        whenIsActive {
          when(tx_tick.rise()) {
            RADDR := 0
            RENABLE := True
            goto(Send_Data)
          }
          trigger := False
        }
      }
      val Send_Data: State = new State {
        whenIsActive {
          RADDR := RADDR + 8
          send_length := send_length + 1
          when(send_length === 15) {
            last := True
            RENABLE := False
            goto(End)
          }
        }
      }
      val End: State = new State {
        whenIsActive {
          send_length := 0
          RENABLE := False
          trigger := True
          goto(Wait_Start)
        }
      }
    }
    io.ccin_rxbundle.RADDR := RADDR
    io.ccin_rxbundle.RENABLE := RENABLE
    streamfifo.io.push.payload := io.ccin_rxbundle.RDATA
    streamfifo.io.push.valid := RegNext(RENABLE)
  }

  val gtx_area = new ClockingArea(ccout_clkdomain){
      val waddr = Reg(UInt(addrwidth bits)) init 0x80
      val wdata = Reg(Bits(64 bits))
      val wenable = Reg(Bool()) init False
      val ready = Reg(Bool()) init False
      val pluse = new PulseCCByToggle(ccin_clkdomain,ccout_clkdomain)
      pluse.io.pulseIn := srio_area.trigger
      val pluse_out = Reg(Bool()) init False
      pluse_out :=  pluse.io.pulseOut

      when(pluse_out.rise()){
        ready := True
      }elsewhen(srio_area.streamfifo.io.popOccupancy === 0){
        ready := False
        waddr := 0x80
      }otherwise{
        ready := ready
      }

      srio_area.streamfifo.io.pop.ready := ready
      wenable := srio_area.streamfifo.io.pop.fire
      wdata := srio_area.streamfifo.io.pop.payload
      when(srio_area.streamfifo.io.pop.fire){
        waddr := waddr + 8
      }
      io.ccout_txbundle.WENABLE := wenable
      io.ccout_txbundle.WDATA := wdata
      io.ccout_txbundle.WADDR := RegNext(waddr)
  }
}

case class Srio_CC(addrwidth : Int) extends Component{
  val io = new Bundle{
    val data_in_cc1 = Seq.fill(16)(in Bits (64 bits))
    val data_out_cc1 = Seq.fill(16)(out Bits (64 bits))
    val data_in_cc2 = Seq.fill(16)(in Bits (64 bits))
    val data_out_cc2 = Seq.fill(16)(out Bits (64 bits))
    val tx_tick_cc1 = in Bool()
    val tx_tick_cc2 = in Bool()
    val ccin_clk = in Bool()
    val ccout_clk = in Bool()
    val reset = in Bool()
  }
  noIoPrefix()

  val ccin_clkdomain = ClockDomain(io.ccin_clk, io.reset)
  val ccout_clkdomain = ClockDomain(io.ccout_clk, io.reset)
  val cc1_area = new ClockingArea(ccin_clkdomain){
    val cc1_reg = Srio_Common(addrwidth)
    val fifo_cc1 = Srio_FifoCc(addrwidth)
  }
  val cc2_area = new ClockingArea(ccout_clkdomain){
    val cc2_reg = Srio_Common(addrwidth)
    val fifo_cc2 = Srio_FifoCc(addrwidth)
  }

  val srio_area = new ClockingArea(ccin_clkdomain){
    for(i <- 0 until 16){
      cc1_area.cc1_reg.io.data_in(i) := io.data_in_cc1(i)
      io.data_out_cc1(i) := cc1_area.cc1_reg.io.data_out(i)
    }
    cc1_area.fifo_cc1.io.tx_tick := io.tx_tick_cc1
    cc1_area.fifo_cc1.io.ccin_clk := io.ccin_clk
    cc1_area.fifo_cc1.io.ccout_clk := io.ccout_clk
    cc1_area.fifo_cc1.io.reset := io.reset

    cc1_area.cc1_reg.io.simplebus.RENABLE := cc1_area.fifo_cc1.io.ccin_rxbundle.RENABLE
    cc1_area.cc1_reg.io.simplebus.RADDR := cc1_area.fifo_cc1.io.ccin_rxbundle.RADDR
    cc1_area.fifo_cc1.io.ccin_rxbundle.RDATA := cc1_area.cc1_reg.io.simplebus.RDATA

    cc1_area.cc1_reg.io.simplebus.WDATA := cc2_area.fifo_cc2.io.ccout_txbundle.WDATA
    cc1_area.cc1_reg.io.simplebus.WENABLE := cc2_area.fifo_cc2.io.ccout_txbundle.WENABLE
    cc1_area.cc1_reg.io.simplebus.WADDR := cc2_area.fifo_cc2.io.ccout_txbundle.WADDR
  }

  val gtx_area = new ClockingArea(ccout_clkdomain){
    for (i <- 0 until 16) {
      cc2_area.cc2_reg.io.data_in(i) := io.data_in_cc2(i)
      io.data_out_cc2(i) := cc2_area.cc2_reg.io.data_out(i)
    }
    cc2_area.fifo_cc2.io.tx_tick := io.tx_tick_cc2
    cc2_area.fifo_cc2.io.ccin_clk := io.ccout_clk
    cc2_area.fifo_cc2.io.ccout_clk := io.ccin_clk
    cc2_area.fifo_cc2.io.reset := io.reset
    cc2_area.cc2_reg.io.simplebus.RENABLE := cc2_area.fifo_cc2.io.ccin_rxbundle.RENABLE
    cc2_area.cc2_reg.io.simplebus.RADDR := cc2_area.fifo_cc2.io.ccin_rxbundle.RADDR
    cc2_area.fifo_cc2.io.ccin_rxbundle.RDATA := cc2_area.cc2_reg.io.simplebus.RDATA

    cc2_area.cc2_reg.io.simplebus.WDATA := cc1_area.fifo_cc1.io.ccout_txbundle.WDATA
    cc2_area.cc2_reg.io.simplebus.WENABLE := cc1_area.fifo_cc1.io.ccout_txbundle.WENABLE
    cc2_area.cc2_reg.io.simplebus.WADDR := cc1_area.fifo_cc1.io.ccout_txbundle.WADDR
  }
}

object Srio_CC extends App{
  SpinalVerilog(Srio_CC(8))
}

object Srio_CC_Test{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Srio_CC(9)){dut=>
      dut.ccin_clkdomain.forkStimulus(10)
      var kk = 100
      dut.ccout_clkdomain.forkStimulus(15)
      dut.ccout_clkdomain.waitSampling(200)

      for(idex <- 0 until 20){
        for (i <- 100 until 116) {
          dut.io.data_in_cc1(i - 100) #= i + kk
        }
        for (i <- 200 until 216) {
          dut.io.data_in_cc2(i - 200) #= i + kk
        }
        kk = kk + 10
        dut.io.tx_tick_cc1 #= false
        dut.io.tx_tick_cc2 #= false
        dut.ccin_clkdomain.waitSampling(100)
        dut.io.tx_tick_cc1 #= true
        dut.ccin_clkdomain.waitSampling()
        dut.io.tx_tick_cc1 #= false
        dut.ccout_clkdomain.waitSampling(3000)
        dut.io.tx_tick_cc2 #= true
        dut.ccout_clkdomain.waitSampling()
        dut.io.tx_tick_cc2 #= false
        dut.ccout_clkdomain.waitSampling(3000)
      }


    }
  }
}