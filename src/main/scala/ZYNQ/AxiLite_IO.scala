package ZYNQ

import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import spinal.lib.{master, slave}

case class IO_Ctrl(samplingSize : Int) extends Component{
  val io = new Bundle{
    val IO = master(ZYNQ_IO())
    val M_Fault_TTL_Filter = out Bits (8 bits)
    val FPGA_DI_Filter = out Bits (16 bits)
    val M_TTL_EN = in Bits (8 bits)
    val M_OPTO_EN = in Bits (16 bits)
    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      bus.read(M_Fault_TTL_Filter,0,0,"TTL_IN")
      bus.read(FPGA_DI_Filter,4,0,"OPTO_IN")
      bus.driveAndRead(M_TTL_EN,8,0,"TTL_IO_Out")
      bus.driveAndRead(M_OPTO_EN,12,0,"OPT_IO_Out")
    }
  }
  noIoPrefix()

  val io_filter = Seq.fill(24)(new IoFilter(samplingSize))

  val M_Fault_TTL_Filter = Reg(Bits(8 bits)) init 0
  val FPGA_DI_Filter = Reg(Bits(16 bits)) init 0

  for (i <- 0 until 8) {
    io_filter(i).io.io_in := io.IO.TTL_IO_In(i)
    M_Fault_TTL_Filter(i) := io_filter(i).io.io_out
  }
  io.M_Fault_TTL_Filter := M_Fault_TTL_Filter

  for (i <- 8 until 24) {
    io_filter(i).io.io_in := io.IO.OPT_IO_In(i - 8)
    FPGA_DI_Filter(i - 8) := io_filter(i).io.io_out
  }
  io.FPGA_DI_Filter := FPGA_DI_Filter

  io.IO.TTL_IO_Out := io.M_TTL_EN
  io.IO.OPT_IO_Out := io.M_OPTO_EN
}

case class AxiLite_IO(samplingSize : Int) extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val IO = master(ZYNQ_IO())
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val io_ctrl = IO_Ctrl(samplingSize)
  io_ctrl.io.IO <> io.IO
  val bridge = io_ctrl.io.driveFrom(bus_ctrl)
}

object AxiLite_IO extends App{
  SpinalVerilog(AxiLite_IO(5))
}