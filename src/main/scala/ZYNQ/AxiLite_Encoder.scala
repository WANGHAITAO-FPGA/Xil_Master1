package ZYNQ

import Common.PHPA.EncoderInterface
import Common.PHPA.regFileGen.genRegFileByMarkdown
import Common.Xil_BlackBox.EncoderN_Ctrl
import spinal.core._
import spinal.lib.bus.amba4.axilite.{AxiLite4, AxiLite4SlaveFactory, AxiLite4SpecRenamer}
import spinal.lib.{master, slave}
case class AxiLite_Encoder(encoder_num : Int) extends Component{
  val io = new Bundle{
    val s_axi = slave(AxiLite4(AxiLite4DataConfig.getaxi4liteconfig))
    val encoder = Seq.fill(encoder_num)(master(EncoderInterface()))
    val encoder_filter_clk = in Bool()
    AxiLite4SpecRenamer(s_axi)
  }
  noIoPrefix()

  val bus_ctrl = new AxiLite4SlaveFactory(io.s_axi)
  val encoder = EncoderN_Ctrl(encoder_num)
  encoder.io.encoder_filter_clk <> io.encoder_filter_clk
  for(i <- 0 until encoder_num){
    encoder.io.encoder(i) <> io.encoder(i)
    io.encoder(i).aphase.setName(s"aphase_$i")
    io.encoder(i).bphase.setName(s"bphase_$i")
    io.encoder(i).iphase.setName(s"iphase_$i")
  }
  val bridge = encoder.io.driveFrom(bus_ctrl)
  encoder.io.busy := False
  addPrePopTask(()=>genRegFileByMarkdown("Encoder"))
}

object AxiLite_Encoder extends App{
  SpinalVerilog(AxiLite_Encoder(4))
}