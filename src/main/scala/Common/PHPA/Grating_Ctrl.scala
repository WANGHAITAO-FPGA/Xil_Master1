package Common.PHPA

import Common.PHPA.ZeroClear_Type.AUTO
import Common.Xil_BlackBox.{BISSC, EncoderTop, Endat}
import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config, Apb3SlaveFactory}
import spinal.lib.bus.misc.BusSlaveFactoryDelayed
import Common.PHPA.regFileGen._

case class Grating_Ctrl(nameid : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val config = slave Flow(Grating_Mode())
    val grating_io = master(Grating_IO())

    val bissc_postion = out Bits(32 bits)

    val encoder_postion = out Bits(32 bits)
    val encoder_zero_singal = out Bool()
    val encoder_filter_clk = in Bool()
    val encoder_postion_reset = in Bool()

    val endat_postion = out Bits(38 bits)
    val endat_index = out Bool()

    val busy = in Bool()

    grating_io.IO_A_READ.setName("IO_A_READ")
    grating_io.IO_A_WRITE.setName("IO_A_WRITE")
    grating_io.IO_A_WRITEENABLE.setName("IO_A_WE")
    grating_io.IO_B_READ.setName("IO_B_READ")
    grating_io.IO_B_WRITE.setName("IO_B_WRITE")
    grating_io.IO_B_WRITEENABLE.setName("IO_B_WE")
    grating_io.IO_C_READ.setName("IO_C_READ")
    grating_io.IO_C_WRITE.setName("IO_C_WRITE")
    grating_io.IO_C_WRITEENABLE.setName("IO_C_WE")

    def driveFrom(bus : BusSlaveFactoryDelayed, baseAddress : Int = 0)= new Area{
      require(bus.busDataWidth == 16 || bus.busDataWidth == 32)
      val bissc_postion_temp = Reg(Bits(32 bits)) init 0
      val encoder_postion_temp = Reg(Bits(32 bits)) init 0
      val endat_postion_temp = Reg(Bits(38 bits)) init 0
      val encoder_zero_singal_temp = Reg(Bool()) init False
      val encoder_postion_reset_temp = Reg(Bool()) init False
      encoder_postion_reset := encoder_postion_reset_temp
      val endat_index_temp = Reg(Bool()) init False
      when(!busy){
        bissc_postion_temp := bissc_postion
        encoder_postion_temp := encoder_postion
        endat_postion_temp := endat_postion
        encoder_zero_singal_temp := encoder_zero_singal
        endat_index_temp := endat_index
      }
      bus.busDataWidth match {
        case 16 =>
          bus.read(bissc_postion_temp(31 downto 16),0,0,"BISS_C Postion bit(31:16)")
          bus.read(bissc_postion_temp(15 downto 0),2,0,"BISS_C Postion bit(15:0)")
          bus.read(encoder_postion_temp(31 downto 16),4,0,"Encoder Postion bit(31:16)")
          bus.read(encoder_postion_temp(15 downto 0),6,0,"Encoder Postion bit(15:0)")

          bus.read(endat_postion_temp(37 downto 32),10,0,"Endat Postion bit(38:32)")
          bus.read(endat_postion_temp(31 downto 16),12,0,"Endat Postion bit(31:16)")
          bus.read(endat_postion_temp(15 downto 0),14,0,"Endat Postion bit(15:0)")
        case 32 =>
          bus.read(bissc_postion_temp(31 downto 0),0,0,"BISS_C Postion bit(31:0)")
          bus.read(encoder_postion_temp(31 downto 0),4,0,"Encoder Postion bit(31:0)")
          bus.read(endat_postion_temp(37 downto 32),8,0,"Endat Postion bit(38:32)")
          bus.read(endat_postion_temp(31 downto 0),12,0,"Endat Postion bit(31:0)")
      }
      bus.read(encoder_zero_singal_temp,16,0,"encoder_zero_singal")
      bus.driveAndRead(encoder_postion_reset_temp,20,0,"encoder_postion_reset")
      bus.read(endat_index_temp,24,0,"endat_index")
      bus.driveAndRead(config.payload.mode,28,0,"config grating mode,0---bissc,1----encoder,2----endat")
      bus.driveAndRead(config.payload.zeroclear_mode,32,0,"encoder zero clear mode,0---AUTO,1----MANUAL")
      bus.driveAndRead(config.payload.zero_counter,36,0,"encoder zero hold time_cnt, time= clk * time_cnt")
      bus.addDataModel("Grating_Ctrl",baseaddr)
    }
  }
  noIoPrefix()

  val grating_ruler = Grating_Ruler(nameid)
  io.config <> grating_ruler.io.config
  io.grating_io <> grating_ruler.io.grating_io

  val bissc = new BISSC()
  bissc.io.bissc <> grating_ruler.io.bissc
  io.bissc_postion := bissc.io.postion

  val encoder = EncoderTop()
  encoder.io.encoder <> grating_ruler.io.encoder
  io.encoder_postion := encoder.io.postion
  io.encoder_zero_singal := encoder.io.zero_singal
  encoder.io.filter_clk := io.encoder_filter_clk
  encoder.io.zero_counter := io.config.zero_counter
  //encoder.io.postion_reset := io.encoder_postion_reset
  encoder.io.postion_reset := Mux((io.config.zeroclear_mode === AUTO),encoder.io.zero_singal,io.encoder_postion_reset)

  val endat = Endat(15,6,38,250)
  endat.io.endat <> grating_ruler.io.endat
  io.endat_postion := endat.io.postion
  io.endat_index := endat.io.index
}

case class Apb3_Grating(addrwidth : Int, datawidth : Int,nameid : Int,baseaddr : Long = 0) extends Component{
  val io = new Bundle{
    val apb  = slave(Apb3(Apb3Config(addrwidth,datawidth)))
    val grating_io = master(Grating_IO())
    val encoder_filter_clk = in Bool()
  }
  noIoPrefix()

  val bus_ctrl = Apb3SlaveFactory(io.apb)
  val grating_ctrl = Grating_Ctrl(nameid,baseaddr)
  grating_ctrl.io.grating_io <> io.grating_io
  grating_ctrl.io.encoder_filter_clk := io.encoder_filter_clk

  val bridge = grating_ctrl.io.driveFrom(bus_ctrl)
  grating_ctrl.io.busy := bus_ctrl.askRead || bus_ctrl.doRead
//  addPrePopTask(()=>genRegFileByMarkdown("Grating"))
}

object Grating_Ctrl extends App{
  SpinalConfig(anonymSignalPrefix = "temp",headerWithDate = true,enumPrefixEnable = false).generateVerilog(Apb3_Grating(8,16,0))
}
