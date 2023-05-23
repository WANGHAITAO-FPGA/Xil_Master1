package Common.Endat

import spinal.core._
import spinal.lib.com.spi.{SpiKind, SpiMaster, SpiMasterCtrl, SpiMasterCtrlCmdMode, SpiMasterCtrlConfig, SpiMasterCtrlGenerics}
import spinal.lib.fsm.{EntryPoint, State, StateMachine}
import spinal.lib.misc.Timer
import spinal.lib.{Counter, StreamFifo, master, slave}

case class SPI_Ctrl(generics : SpiMasterCtrlGenerics) extends Component{
  val io = new Bundle{
    val spi = master(SpiMaster(generics.ssWidth))
    val config = in(SpiMasterCtrlConfig(generics))
    val cmd = slave Stream(Bits(generics.dataWidth bits))
    val rsp = master Stream(Bits(generics.dataWidth bits))
    val occupancy = out UInt (log2Up(65) bits)
  }
  noIoPrefix()

  val timer = new Area{
    val counter = Reg(UInt(generics.timerWidth bits))
    val reset = Reg(Bool())
    val ss = if(generics.ssGen) new Area{
      val setupHit    = counter === io.config.ss.setup
      val holdHit     = counter === io.config.ss.hold
      val disableHit  = counter === io.config.ss.disable
    } else null
    val sclkToogleHit = counter === io.config.sclkToogle
    counter := counter + 1
    when(reset){
      counter := 0
    }
  }

  val wr_fifo = StreamFifo(Bits(16 bits),64)
  wr_fifo.io.push.valid := io.cmd.valid
  wr_fifo.io.push.payload := io.cmd.payload
  io.cmd.ready := wr_fifo.io.push.ready

  val rd_fifo = StreamFifo(Bits(16 bits),64)

  val wr_ready = Reg(Bool())
  wr_ready := False
  wr_fifo.io.pop.ready := wr_ready

  val flush = Reg(Bool())
  flush := False
  wr_fifo.io.flush := flush
  rd_fifo.io.flush := flush

  val init_timer_tick = Reg(Bool()) init False

  val init_timer = Timer(32)
  init_timer.io.tick := init_timer_tick
  init_timer.io.limit := 500
  when(init_timer.io.value >= init_timer.io.limit){
    init_timer.io.clear := True
  }otherwise{
    init_timer.io.clear := False
  }

  val fsm = new StateMachine{
    val counter = Counter(generics.dataWidth*2)
    val buffer = Reg(Bits(generics.dataWidth bits))
    val ss = RegInit(B((1 << generics.ssWidth)-1, generics.ssWidth bits))
    val wr_payload = Reg(Bits(generics.dataWidth bits))
    val rsp_valid = Reg(Bool())
    rsp_valid := False
    timer.reset := False

    val Fifo_Init: State = new State with EntryPoint {
      whenIsActive{
        flush := True
        init_timer_tick := True
        when(init_timer.io.full){
          init_timer_tick := False
          goto(Init_Start)
        }
      }
    }
    val Init_Start: State = new State{
      whenIsActive{
        when(wr_fifo.io.occupancy =/= 0){
          ss(0) := False
          timer.reset := True
          goto(Active_CS)
        }
      }
    }
    val Active_CS: State = new State{
      whenIsActive{
        when(timer.ss.setupHit){
          counter := 0
          wr_ready := True
          wr_payload := wr_fifo.io.pop.payload
          timer.reset := True
          goto(Send_Data)
        }
      }
    }
    val Send_Data: State = new State{
      whenIsActive{
        when(timer.sclkToogleHit) {
          timer.reset := True
          counter.increment()
          when(counter.lsb) {
            buffer := (buffer ## io.spi.miso).resized
          }
          when(counter === (2*generics.dataWidth-1)){
            goto(Disable_CS)
          }
        }
      }
    }
    val Disable_CS: State = new State{
      whenIsActive{
        when(timer.ss.holdHit){
          rsp_valid := True
          timer.reset := True
          ss(0) := True
          goto(Dummy_State)
        }
      }
    }
    val Dummy_State: State = new State{
      whenIsActive{
        when(timer.ss.disableHit){
          timer.reset := True
          goto(Init_Start)
        }
      }
    }
  }


  rd_fifo.io.push.valid   := fsm.rsp_valid
  rd_fifo.io.push.payload := fsm.buffer

  io.rsp.payload := rd_fifo.io.pop.payload
  io.rsp.valid := rd_fifo.io.pop.valid
  rd_fifo.io.pop.ready := io.rsp.ready
  io.occupancy := rd_fifo.io.occupancy
  //Idle states

  io.spi.ss(0) := fsm.ss(0) ^ io.config.ss.activeHigh.asBool
  io.spi.sclk := RegNext(((fsm.counter.lsb ^ io.config.kind.cpha)) ^ io.config.kind.cpol)
  io.spi.mosi := RegNext(fsm.wr_payload(generics.dataWidth-1 - (fsm.counter >> 1)))
}

case class Endat_CtrlCmdData(dataWidth : Int) extends Bundle{
  val Identity_Addr = Bits(dataWidth bits)
  val CmdData = Vec(Bits(dataWidth bits),4)
  val Bytenumber = UInt(6 bits)
}

case class Endat_CtrlRspData(dataWidth : Int) extends Bundle{
  val RspData = Vec(Bits(dataWidth bits),5)
}

case class Endat_SPI_Ctrl(dataWidth : Int) extends Component{
  val io = new Bundle{
    val spi = master(SpiMaster(1))
    val cmddata = slave Flow(Endat_CtrlCmdData(dataWidth))
    val rspdata = master Flow(Endat_CtrlRspData(dataWidth))
  }
  noIoPrefix()

  val spictrl = new SPI_Ctrl(SpiMasterCtrlGenerics(1,8,dataWidth))
  spictrl.io.spi <> io.spi
  spictrl.io.config.ss.hold := 3
  spictrl.io.config.ss.activeHigh := 0
  spictrl.io.config.ss.setup := 3
  spictrl.io.config.ss.disable := 3
  spictrl.io.config.kind.cpha := False
  spictrl.io.config.kind.cpol := True
  spictrl.io.config.sclkToogle := 0

  val init_timer_tick = Reg(Bool()) init False

  val init_timer = Timer(32)
  init_timer.io.tick := init_timer_tick
  init_timer.io.limit := 500
  when(init_timer.io.value >= init_timer.io.limit){
    init_timer.io.clear := True
  }otherwise{
    init_timer.io.clear := False
  }

  val fsm = new StateMachine{
    val Identity_Addr = Reg(Bits(dataWidth bits)) init 0
    val CmdData = Vec(Reg(Bits(dataWidth bits)),4)
    val Cycle = Reg(UInt(3 bits))
    val counter = Reg(UInt(4 bits)) init 0
    val rdfifo_ready = Reg(Bool())
    rdfifo_ready := False

    val spi_cmd_valid = Reg(Bool())
    spi_cmd_valid := False
    val spi_cmd_payload = Reg(Bits(dataWidth bits)) init 0
    val rspData = Reg(Vec(Bits(dataWidth bits),5))

    val Dummy_State: State = new State with EntryPoint {
      whenIsActive{
        init_timer_tick := True
        when(init_timer.io.full) {
          init_timer_tick := False
          goto(Init_Start)
        }
      }
    }
    val Init_Start: State = new State{
      whenIsActive{
        when(io.cmddata.valid){
          Identity_Addr := io.cmddata.payload.Identity_Addr
          CmdData := io.cmddata.payload.CmdData
          Cycle := ((io.cmddata.payload.Bytenumber+1)>>1).resized
          counter := 0
          goto(Send_Identity_Addr)
        }otherwise{
          rdfifo_ready := True
        }
      }
    }
    val Send_Identity_Addr: State = new State{
      whenIsActive{
        spi_cmd_valid := True
        spi_cmd_payload := Identity_Addr
        goto(Send_RegData)
      }
    }
    val Send_RegData: State = new State{
      whenIsActive{
        when(counter < Cycle){
          spi_cmd_valid := True
          spi_cmd_payload := CmdData(counter.resized)
          counter := counter + 1
        }otherwise{
          spi_cmd_valid := False
          counter := 0
          goto(Wait_Rsp)
        }
      }
    }
    val Wait_Rsp: State = new State{
      whenIsActive{
        when(spictrl.io.occupancy >= (Cycle+1)){
          rdfifo_ready := True
          goto(Rd_Rsp)
        }
      }
    }
    val Rd_Rsp: State = new State{
      whenIsActive{
        when(counter < (Cycle+1)){
          rspData(counter.resized) := spictrl.io.rsp.payload
          counter := counter + 1
        }
        when(spictrl.io.occupancy =/= 0){
          rdfifo_ready := True
        }otherwise{
          goto(Init_Start)
        }
      }
    }
  }
  spictrl.io.cmd.payload := fsm.spi_cmd_payload
  spictrl.io.cmd.valid := fsm.spi_cmd_valid

  spictrl.io.rsp.ready := fsm.rdfifo_ready

  io.rspdata.valid := spictrl.io.rsp.valid
  io.rspdata.payload.RspData := fsm.rspData
}

//object SPI_Ctrl{
//  import spinal.core.sim._
//  def main(args: Array[String]): Unit = {
//    SimConfig.withWave.doSim(new SPI_Ctrl(SpiMasterCtrlGenerics(1,8,16))){dut=>
//      dut.clockDomain.forkStimulus(10)
//      dut.io.cmd.valid #= false
//      dut.io.config.ss.hold #= 100
//      dut.io.config.ss.activeHigh #= 0
//      dut.io.config.ss.setup #= 100
//      dut.io.config.ss.disable #= 200
//      dut.io.config.kind.cpha #= true
//      dut.io.config.kind.cpol #= false
//      dut.io.config.sclkToogle #= 100
//      dut.clockDomain.waitSampling(50)
//      dut.io.cmd.valid #= true
//      dut.io.cmd.payload #= 0x1234
//      dut.clockDomain.waitSampling()
//      dut.io.cmd.valid #= true
//      dut.io.cmd.payload #= 0x5678
//      dut.clockDomain.waitSampling()
//      dut.io.cmd.valid #= false
//      for(i <- 0 until 10000){
//        dut.clockDomain.waitSampling()
//        var k = dut.io.spi.mosi
//        dut.io.spi.miso #= k.toBoolean
//      }
//    }
//  }
//}

object Endat_SPI_Ctrl{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new Endat_SPI_Ctrl(16)){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.cmddata.valid #= false
      dut.clockDomain.waitSampling(5000)
      dut.io.cmddata.payload.Bytenumber #= 4
      dut.io.cmddata.payload.Identity_Addr #= 0x1234
      dut.io.cmddata.payload.CmdData(0) #= 0x5678
      dut.io.cmddata.payload.CmdData(1) #= 0X9ABC
      dut.io.cmddata.payload.CmdData(2) #= 0X0102
      dut.io.cmddata.valid #= true
      dut.clockDomain.waitSampling()
      dut.io.cmddata.payload.CmdData(2) #= 0
      dut.io.cmddata.valid #= false
      for(i <- 0 until 10000){
        dut.clockDomain.waitSampling()
        var k = dut.io.spi.mosi
        dut.io.spi.miso #= k.toBoolean
      }
      dut.io.cmddata.payload.Bytenumber #= 4
      dut.io.cmddata.payload.Identity_Addr #= 0x0102
      dut.io.cmddata.payload.CmdData(0) #= 0x0304
      dut.io.cmddata.payload.CmdData(1) #= 0X0708
      dut.io.cmddata.payload.CmdData(2) #= 0X090a
      dut.io.cmddata.valid #= true
      dut.clockDomain.waitSampling()
      dut.io.cmddata.payload.CmdData(2) #= 0
      dut.io.cmddata.valid #= false
      for(i <- 0 until 10000){
        dut.clockDomain.waitSampling()
        var k = dut.io.spi.mosi
        dut.io.spi.miso #= k.toBoolean
      }
    }
  }
}