package Common.Xil_BlackBox

import Common.PHPA.BissCInterface
import Common.PHPA.regFileGen.regInsert
import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed

case class BISSC() extends Component{
  val io = new Bundle{
    val bissc = master(BissCInterface())
    val postion = out Bits(32 bits)
  }
  noIoPrefix()

  val bissc = new BlackBox{
    setDefinitionName("BISS_Position")
    val clk = in Bool()
    val reset = in Bool()
    val enc_data = in Bool()
    val sample_en = in Bool()
    val enc_clk = out Bool()
    val enc_position_all = out Bits(41 bits)
    val enc_position_out = out Bits(32 bits)
    val erro_flag = out Bool()
    val warn_flag = out Bool()
    val crc_flag = out Bool()

    mapClockDomain(clock = clk,reset = reset)

    addRTLPath("D:/SpinalWorkSpace/Xil_Master1/rtl/BISS_Position.v")
  }

  io.bissc.clk <> bissc.enc_clk
  io.bissc.data <> bissc.enc_data
  io.postion := bissc.enc_position_out
  bissc.sample_en := True
}

case class BISSC_Ctrl(bissc_num : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val bissc = Seq.fill(bissc_num)(master(BissCInterface()))
    val postion = Seq.fill(bissc_num)(out Bits(32 bits))
    val busy = in Bool()
    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val postion_temp = Seq.fill(bissc_num)(Reg(Bits(32 bits)))
      when(!busy){
        for(i <- 0 until bissc_num){
          postion_temp(i) := postion(i)
        }
      }
      bus.busDataWidth match {
        case 16 =>
          for(i <- 0 until bissc_num){
            bus.read(postion_temp(i)(31 downto 16),2*(2*i),0,s"bissc_data $i [31:16]")
            bus.read(postion_temp(i)(15 downto 0),2*(2*i+1),0,s"bissc_data $i [15:0]")
          }
        case 32 =>
          for(i <- 0 until bissc_num){
            bus.read(postion_temp(i),4*i,0,s"bissc_data $i")
          }
      }
      bus.addDataModel("Bissc_Ctrl",baseaddr)
    }
  }
  noIoPrefix()

  val bissc = Seq.fill(bissc_num)(new BISSC())
  for(i <- 0 until bissc_num){
    bissc(i).io.bissc <> io.bissc(i)
    io.postion(i) := bissc(i).io.postion
    io.bissc(i).clk.setName(s"bissc_clk_$i")
    io.bissc(i).data.setName(s"bissc_data_$i")
  }
}

case class Apb3_Bissc(addrwidth : Int, datawidth : Int, bissc_num : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val bissc = Seq.fill(bissc_num)(master(BissCInterface()))
  }
  noIoPrefix()
  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val bissc_ctrl = BISSC_Ctrl(bissc_num,baseaddr)
  for(i <- 0 until bissc_num){
    io.bissc(i) <> bissc_ctrl.io.bissc(i)
    io.bissc(i).clk.setName(s"bissc_clk_$i")
    io.bissc(i).data.setName(s"bissc_data_$i")
  }
  val bridge = bissc_ctrl.io.driveFrom(bus_ctrl)
  bissc_ctrl.io.busy := bus_ctrl.askRead || bus_ctrl.doRead
}

object BISSC extends App{
  SpinalVerilog(Apb3_Bissc(8,16,4))
}

object test extends App{
  SpinalVerilog(new BISSC())
}

