package TEST

import ZYNQ.AxiLite4DataConfig
import spinal.core
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.slave
case class AddTest() extends Component{
  val io = new Bundle{
    val datain1 = in Bits (32 bits)
    val datain2 = in Bits(32 bits)
    val dataout = out Bits(32 bits)
    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0) = new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      bus.driveAndRead(datain1,0,0,"datain1")
      bus.driveAndRead(datain2,4,0,"datain2")
      bus.read(dataout,8,0,"dataout")
    }
  }
  noIoPrefix()

  io.dataout := (io.datain1.asUInt + io.datain2.asUInt + 100).asBits
}

case class Axilite_Add() extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val addtest = AddTest()
  val bridge = addtest.io.driveFrom(bus_ctrl)
}

object Axilite_Add extends App{
  SpinalVerilog(Axilite_Add())
}