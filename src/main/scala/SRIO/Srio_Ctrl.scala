package SRIO

import ZYNQ.AxiLite4DataConfig
import spinal.core.{Bits, _}
import spinal.lib._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactory

case class UserBusCmd() extends Bundle with IMasterSlave{
  val user_addr = Bits(32 bits)
  val user_ftype = SrioFtype()
  val user_ttype = SrioTtype()
  val user_size = Bits(8 bits)
  val user_prio = Bits(2 bits)
  val user_tid  = Bits(8 bits)
  val user_data = Stream(Bits(32 bits))

  override def asMaster(): Unit = {
    out(user_addr,user_ftype,user_ttype,user_size,user_prio,user_tid)
    master(user_data)
  }
}
case class Srio_Ctrl_Bundle() extends Bundle{
  val io = new Bundle{
    val usercmd = slave(UserBusCmd())
    val start_cmd = in Bool()
    val flush = in Bool()
    val iresp_stream = master Stream (Bits(32 bits))
    val iresp_occupancy = out Bits(32 bits)
    def driveFrom(bus: BusSlaveFactory) = new Area{
      require(bus.busDataWidth == 32)
      usercmd.user_data << bus.createAndDriveFlow(Bits(32 bits), 0x00).toStream
      bus.driveAndRead(usercmd.user_addr(31 downto 0),4,0,"user_addr")
      bus.driveAndRead(usercmd.user_tid,8,0,"user_tid")
      bus.driveAndRead(usercmd.user_ftype,12,0,"user_ftype")
      bus.driveAndRead(usercmd.user_ttype,16,0,"user_ttype")
      bus.driveAndRead(usercmd.user_prio,20,0,"user_prio")
      bus.driveAndRead(usercmd.user_size,24,0,"user_size")
      bus.driveAndRead(start_cmd,28,0,"start_cmd")
      iresp_stream.ready := False
      bus.onRead(32) {
        iresp_stream.ready := True
      }
      bus.read(iresp_stream.payload, 32)
      bus.driveAndRead(flush, 36, 0) init(True)
      bus.read(iresp_occupancy,40)
    }
  }
}

case class Srio_Ctrl(buscd : ClockDomain, sriocd : ClockDomain) extends Component{
  val io = new Bundle{
    val ctrl = new Srio_Ctrl_Bundle()
    val ireq_stream = master Stream (Bits(64 bits))
    val iresp_stream = slave Stream (Bits(64 bits))
    val user_addr = out(Bits(34 bits))
    val user_ftype = out(SrioFtype())
    val user_ttype = out(SrioTtype())
    val user_size = out(Bits(8 bits))
    val user_prio = out(Bits(2 bits))
    val user_tid = out(Bits(8 bits))
    val start_cmd = out Bool()
  }
  noIoPrefix()

  val ctrlClockDomain = this.clockDomain
  val busReset = ResetCtrl.asyncAssertSyncDeassert(
    input = ClockDomain.current.isResetActive || io.ctrl.io.flush,
    clockDomain = buscd
  )
  val busClockDomain = buscd.copy(reset = busReset)
  val srioClockDomain = sriocd.copy(reset = busReset)

  val txFront = busClockDomain on new Area {
    val start_cmd = Reg(Bool()) init False
    start_cmd := io.ctrl.io.start_cmd
    val srio_txbuffer = StreamFifoCC(Bits(64 bits), 32, buscd, sriocd)
    StreamWidthAdapter(io.ctrl.io.usercmd.user_data, srio_txbuffer.io.push)
    io.user_addr := io.ctrl.io.usercmd.user_addr.resized
    io.user_ftype := io.ctrl.io.usercmd.user_ftype
    io.user_ttype := io.ctrl.io.usercmd.user_ttype
    io.user_size := io.ctrl.io.usercmd.user_size
    io.user_prio := io.ctrl.io.usercmd.user_prio
    io.user_tid := io.ctrl.io.usercmd.user_tid
    val pluse = new PulseCCByToggle(busClockDomain, srioClockDomain)
    pluse.io.pulseIn := start_cmd.rise()
  }
  val txBack = srioClockDomain on new Area {
    io.ireq_stream << txFront.srio_txbuffer.io.pop
    io.start_cmd := txFront.pluse.io.pulseOut
  }

  val rxFront = srioClockDomain on new Area {
    val srio_iresprxbuffer = StreamFifoCC(Bits(64 bits),32,sriocd,buscd)
    srio_iresprxbuffer.io.push << io.iresp_stream
  }
  val rxBack = busClockDomain on new Area {
    val rx_buffer = StreamFifoCC(Bits(32 bits),32,buscd,buscd)
    StreamWidthAdapter(rxFront.srio_iresprxbuffer.io.pop, rx_buffer.io.push)
    io.ctrl.io.iresp_stream << rx_buffer.io.pop
    io.ctrl.io.iresp_occupancy := rx_buffer.io.popOccupancy.asBits.resized
  }
}

case class Axi4_Srio() extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val ireq_stream = master Stream (Bits(64 bits))
    val iresp_stream = slave Stream (Bits(64 bits))
    val user_addr = out(Bits(34 bits))
    val user_ftype = out(SrioFtype())
    val user_ttype = out(SrioTtype())
    val user_size = out(Bits(8 bits))
    val user_prio = out(Bits(2 bits))
    val user_tid = out(Bits(8 bits))
    val start_cmd = out Bool()
    val clk = in Bool()
    val srio_clk = in Bool()
    val reset = in Bool()
    val srio_reset = in Bool()
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()
  val bus_clkdomain = ClockDomain(io.clk,io.reset)
  val srio_clkdomain = ClockDomain(io.srio_clk,io.srio_reset)
  val area = new ClockingArea(bus_clkdomain){
    val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
    val srio_ctrl = Srio_Ctrl(bus_clkdomain, srio_clkdomain)
    io.user_addr := srio_ctrl.io.user_addr
    io.user_ftype := srio_ctrl.io.user_ftype
    io.user_ttype := srio_ctrl.io.user_ttype
    io.user_size := srio_ctrl.io.user_size
    io.user_prio := srio_ctrl.io.user_prio
    io.user_tid := srio_ctrl.io.user_tid
    io.start_cmd := srio_ctrl.io.start_cmd
    io.ireq_stream << srio_ctrl.io.ireq_stream
    srio_ctrl.io.iresp_stream << io.iresp_stream
    val bridge = srio_ctrl.io.ctrl.io.driveFrom(bus_ctrl)
  }

  io.ireq_stream.valid.setName("m_axis_usercmd_tvalid")
  io.ireq_stream.payload.setName("m_axis_usercmd_tdata")
  io.ireq_stream.ready.setName("m_axis_usercmd_tready")

  io.iresp_stream.ready.setName("s_axis_rspstream_tready")
  io.iresp_stream.valid.setName("s_axis_rspstream_tvalid")
  io.iresp_stream.payload.setName("s_axis_rspstream_tdata")
}

object Axi4_Srio extends App{
  SpinalVerilog(Axi4_Srio())
}