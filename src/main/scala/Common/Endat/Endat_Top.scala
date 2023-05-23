package Common.Endat

import Common.PHPA.ila_test.ila
import Common.PHPA.{EndatInterface, PHPA_MMCME2}
import Common.Xil_BlackBox.ENDAT22_IP
import spinal.core._
import spinal.lib.com.spi.SpiMasterCtrlGenerics
import spinal.lib.{CounterFreeRun, master}

case class Endat_Top() extends Component{
  val io = new Bundle{
    val sysclk = in Bool()
    val led = out Bool()
    val endat = master(EndatInterface())
  }
  noIoPrefix()

  val mmcmarea = new ClockingArea(ClockDomain(io.sysclk,config = ClockDomainConfig(resetActiveLevel = LOW))){
    val mmcm = PHPA_MMCME2()
    mmcm.io.sysclk := io.sysclk
    mmcm.io.reset := False

    val area = new ClockingArea(ClockDomain(mmcm.io.clk_100M,~mmcm.io.locked)){
      val endat_ctrl = Endat_Ctrl(16,4000)
      val endat_ip = ENDAT22_IP(SpiMasterCtrlGenerics(1,8,16))
      endat_ip.io.spi <> endat_ctrl.io.spi
      endat_ip.io.endat <> io.endat
      endat_ip.io.clk := mmcm.io.clk_100M
      endat_ip.io.reset := mmcm.io.locked
      endat_ip.io.nstr := endat_ctrl.io.endat_ip_trigger

      val ledtemp = Reg(Bool()) init False

      val counter =  CounterFreeRun(50000000)
      when(counter.willOverflow){
        counter.clear()
        ledtemp := ~ledtemp;
      }
      io.led := ledtemp
    }
  }
}

object Endat_Top extends App{
  SpinalConfig(
    anonymSignalPrefix = "temp",
    headerWithDate = true,
    targetDirectory = "E:/YW/Endat_IP_Test/Endat_IP_Test.srcs/sources_1/new/",
    nameWhenByFile = false,
    genLineComments = false
  ).generateVerilog(Endat_Top())
}