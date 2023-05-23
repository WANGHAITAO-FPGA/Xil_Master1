package Common.Xil_BlackBox

import spinal.core._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config}
import spinal.lib.io.TriState
import spinal.lib.{Delay, IMasterSlave, master}

case class SramLayout(addressWidth: Int, dataWidth : Int) {
  val capacity = BigInt(1) << (addressWidth + log2Up(dataWidth/8))
}

case class SramInterface(g : SramLayout) extends Bundle with IMasterSlave{
  val emif_addr = UInt((g.addressWidth) bits)
  val emif_data = TriState(Bits(g.dataWidth bits))
  val emif_cs  = Bool
  val emif_we  = Bool
  val emif_oe  = Bool

  override def asMaster(): Unit = {
    in(emif_addr,emif_cs,emif_we,emif_oe)
    master(emif_data)
  }
  emif_addr.setName("emif_addr")
  emif_cs.setName("emif_cs")
  emif_we.setName("emif_we")
  emif_oe.setName("emif_oe")
  emif_data.setName("emif_data")
}

class Emif_Apb(sramLayout : SramLayout) extends Component {
  val io = new Bundle{
    val emif = master(SramInterface(sramLayout))
    val apb = master(Apb3(Apb3Config(addressWidth = sramLayout.addressWidth,dataWidth = sramLayout.dataWidth)))
  }
  noIoPrefix()

  val penable = Reg(Bool()) init False

  penable := (!io.emif.emif_oe)|(!io.emif.emif_we)

  io.apb.PADDR := ((io.emif.emif_addr)<<1).resize(sramLayout.addressWidth)
  io.apb.PSEL := ~(io.emif.emif_cs.asBits)
  io.apb.PENABLE := Mux(penable.rise(),penable,False)
  io.apb.PWRITE := (!io.emif.emif_we)&io.emif.emif_oe

  val rd_data_temp = Reg(Bits(sramLayout.dataWidth bits))

  when(io.apb.PENABLE){
    rd_data_temp := io.apb.PRDATA
  }otherwise{
    rd_data_temp := rd_data_temp
  }

  io.emif.emif_data.writeEnable := !io.emif.emif_oe
  io.emif.emif_data.write := rd_data_temp

  io.apb.PWDATA := io.emif.emif_data.read
}


//case class EMIF32_Apb(sramLayout : SramLayout) extends Component{
//  val io = new Bundle{
//    val emif = master(SramInterface(sramLayout))
//    val apb = master(Apb3(Apb3Config(addressWidth = sramLayout.addressWidth,dataWidth = sramLayout.dataWidth*2)))
//  }
//  noIoPrefix()
//
//  val penable = Reg(Bool()) init False
//
//  val wr_datatemp = Reg(Bits(sramLayout.dataWidth*2 bits)) init 0
//
//  val rd_datatemp = Reg(Bits(sramLayout.dataWidth bits)) init 0
//
//  penable := Delay((!io.emif.emif_oe)|(!io.emif.emif_we),1,init = False)
//  io.apb.PADDR := (io.emif.emif_addr(sramLayout.addressWidth-2 downto 0)<<2).resized
//  io.apb.PSEL := ~(io.emif.emif_cs.asBits)
//  io.apb.PENABLE := Mux(penable.rise(),penable,False)
//  io.apb.PWRITE := (!io.emif.emif_we)&&io.emif.emif_oe&&io.emif.emif_addr.msb&&io.apb.PENABLE
//
//  io.emif.emif_data.writeEnable := (!io.emif.emif_oe) & (!io.emif.emif_cs)
//
//  io.emif.emif_data.write := Mux(!io.emif.emif_addr.msb,io.apb.PRDATA(15 downto 0),io.apb.PRDATA(31 downto 16))
//
//  wr_datatemp(15 downto 0) := Mux((!io.emif.emif_we)&io.emif.emif_oe&(!io.emif.emif_addr.msb),io.emif.emif_data.read,wr_datatemp(15 downto 0))
//  wr_datatemp(31 downto 16) := Mux((!io.emif.emif_we)&io.emif.emif_oe&(io.emif.emif_addr.msb),io.emif.emif_data.read,wr_datatemp(31 downto 16))
//
//  io.apb.PWDATA := wr_datatemp
//}