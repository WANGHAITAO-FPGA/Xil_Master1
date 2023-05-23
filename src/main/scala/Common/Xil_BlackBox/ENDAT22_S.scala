package Common.Xil_BlackBox

import Common.PHPA.EndatInterface
import Common.PHPA.ila_test.ila
import spinal.core._
import spinal.lib.com.spi.{SpiMaster, SpiMasterCtrlGenerics}
import spinal.lib.{master, slave}

case class ENDAT22_S_0() extends BlackBox{
  val clk,n_rs,M16,sck,n_ss,mosi,data_rc,nstr,n_int6,n_int7 = in Bool()
  val miso,n_int1,data_dv,tclk,de,ntimer,clk2,dui,tst_out_pin,n_si,RTM_START_O,RTM_STOPP_O = out Bool()
  mapClockDomain(clock = clk,reset = n_rs)
}

case class ENDAT22_IP(generics : SpiMasterCtrlGenerics) extends Component{
  val io = new Bundle{
    val spi = slave(SpiMaster(generics.ssWidth))
    val endat = master(EndatInterface())
    val clk2 = out Bool()
    val clk = in Bool()
    val reset = in Bool()
    val nstr = in Bool()
  }
  noIoPrefix()

  val area = new ClockingArea(ClockDomain(io.clk,io.reset)){
    val endat22_s = ENDAT22_S_0()

    endat22_s.n_ss := io.spi.ss(0)
    endat22_s.mosi := io.spi.mosi
    endat22_s.sck := io.spi.sclk
    io.spi.miso := endat22_s.miso

    io.endat.clk := endat22_s.tclk
    io.endat.write := endat22_s.data_dv
    io.endat.writeEnable := endat22_s.de
    endat22_s.data_rc := io.endat.read

    endat22_s.M16 := True
    io.clk2 := endat22_s.clk2

    endat22_s.nstr := io.nstr
    endat22_s.n_int6 := False
    endat22_s.n_int7 := False

    val ila_probe=ila("0",io.spi.ss(0),io.spi.mosi,io.spi.sclk,io.spi.miso,io.clk2,io.endat.clk,io.endat.write,io.endat.writeEnable,io.endat.read,io.nstr)
  }
}

object ENDAT22_IP extends App{
  SpinalVerilog(ENDAT22_IP(SpiMasterCtrlGenerics(1,8,16)))
}