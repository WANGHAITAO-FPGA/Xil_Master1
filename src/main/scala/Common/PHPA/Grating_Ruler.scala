package Common.PHPA

import spinal.core._
import spinal.lib._

object Grating_Type extends SpinalEnum{
  val BISSC,ENCODER,ENDAT = newElement()
}
import Grating_Type._

object ZeroClear_Type extends SpinalEnum{
  val AUTO,MANUAL = newElement()
}
import ZeroClear_Type._

case class Grating_Mode() extends Bundle{
  val mode = Grating_Type()
  val zeroclear_mode = ZeroClear_Type()
  val zero_counter = UInt(16 bits)
}

case class BissCInterface() extends Bundle with IMasterSlave{
  val clk = Bool
  val data = Bool
  override def asMaster(): Unit = {
    out(clk)
    in(data)
  }
}

case class EncoderInterface() extends Bundle with IMasterSlave{
  val aphase = Bool()
  val bphase = Bool()
  val iphase = Bool()
  override def asMaster(): Unit = {
    in(aphase,bphase,iphase)
  }
}

case class EndatInterface() extends Bundle with IMasterSlave{
  val clk = Bool()
  val read = Bool()
  val write = Bool()
  val writeEnable = Bool()
  override def asMaster(): Unit = {
    out(clk,write,writeEnable)
    in(read)
  }
}

case class Grating_IO() extends Bundle with IMasterSlave{
  val IO_A_READ = Bool()
  val IO_A_WRITE = Bool()
  val IO_A_WRITEENABLE = Bool()
  val IO_B_READ = Bool()
  val IO_B_WRITE = Bool()
  val IO_B_WRITEENABLE = Bool()
  val IO_C_READ = Bool()
  val IO_C_WRITE = Bool()
  val IO_C_WRITEENABLE = Bool()
  override def asMaster(): Unit = {
    in(IO_A_READ,IO_B_READ,IO_C_READ)
    out(IO_A_WRITE,IO_A_WRITEENABLE,IO_B_WRITE,IO_B_WRITEENABLE,IO_C_WRITE,IO_C_WRITEENABLE)
  }
}

case class Grating_Ruler(nameid : Int) extends Component{
  val io = new Bundle{
    val config = slave Flow(Grating_Mode())
    val grating_io = master(Grating_IO())
    val bissc = slave(BissCInterface())
    val encoder = slave(EncoderInterface())
    val endat = slave(EndatInterface())
    grating_io.IO_A_READ.setName(s"grating_read_a$nameid")
    grating_io.IO_A_WRITE.setName(s"grating_write_a$nameid")
    grating_io.IO_A_WRITEENABLE.setName(s"grating_we_a$nameid")
    grating_io.IO_B_READ.setName(s"grating_read_b$nameid")
    grating_io.IO_B_WRITE.setName(s"grating_write_b$nameid")
    grating_io.IO_B_WRITEENABLE.setName(s"grating_we_b$nameid")
    grating_io.IO_C_READ.setName(s"grating_read_c$nameid")
    grating_io.IO_C_WRITE.setName(s"grating_write_c$nameid")
    grating_io.IO_C_WRITEENABLE.setName(s"grating_we_c$nameid")
  }
  noIoPrefix()

  io.grating_io.IO_A_WRITE := Mux(io.config.mode=== BISSC,io.bissc.clk,Mux(io.config.mode=== ENDAT,io.endat.clk,False))

  io.grating_io.IO_A_WRITEENABLE := Mux((io.config.mode=== BISSC)||(io.config.mode=== ENDAT),True,False)

  io.grating_io.IO_B_WRITE := io.endat.write

  io.grating_io.IO_B_WRITEENABLE := Mux((io.config.mode=== BISSC)||(io.config.mode=== ENCODER),False,io.endat.writeEnable)

  io.bissc.data := Mux(io.config.mode=== BISSC,io.grating_io.IO_B_READ,False)

  io.encoder.aphase := Mux(io.config.mode=== ENCODER,io.grating_io.IO_A_READ,False)
  io.encoder.bphase := Mux(io.config.mode=== ENCODER,io.grating_io.IO_B_READ,False)

  io.endat.read := Mux(io.config.mode=== ENDAT,io.grating_io.IO_B_READ,False)

  io.grating_io.IO_C_WRITE := False
  io.grating_io.IO_C_WRITEENABLE := False
  io.encoder.iphase := io.grating_io.IO_C_READ
}

object Grating_Ruler extends App{
  SpinalVerilog(new Grating_Ruler(0))
}

