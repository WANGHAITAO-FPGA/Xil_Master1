package BoardTest

import Board_Test.{Rx_Checker, Rx_Final, Rx_Preamble, TxSimpleBus, TxSimpleTop, Tx_Crc, Tx_Final, Tx_Header}
import spinal.core._
import spinal.lib._
import spinal.lib.misc.Timer

import scala.util.Random

case class TxSimpleSim() extends Component{
  val io = new Bundle{
    val output = master(Stream(Fragment(Bits(32 bits))))
  }
  noIoPrefix()

  val txsimple = TxSimpleTop(8,32)


  val meminitvalue = for(i <- 0 until (BigInt(1) << 8).toInt)yield{
    val initdata = i + 256
    BigInt(initdata)
  }
  val rams = Mem(Bits(32 bits), BigInt(1) << 8) initBigInt(meminitvalue)
  rams.addAttribute("ram_style", "block")
  txsimple.io.ram_rxbundle.RDATA := rams.readSync(txsimple.io.ram_rxbundle.RADDR,txsimple.io.ram_rxbundle.RENABLE)

  val timer = Timer(32)
  timer.io.tick := True
  timer.io.limit := 1000
  when(timer.io.value >= timer.io.limit){
    timer.io.clear := True
  }otherwise{
    timer.io.clear := False
  }

  txsimple.io.tx_tick := timer.io.full
  txsimple.io.tx_head := 2
  txsimple.io.frame_head := B"64'x00f1f2f30000000f"
//  io.output << txsimple.io.output

  val rxpreamble = Rx_Preamble(32)
  rxpreamble.io.frame_head := B"64'x00f1f2f30000000f"
  rxpreamble.io.input << txsimple.io.output

  val rxchecker = Rx_Checker(32)
  rxchecker.io.input << rxpreamble.io.output

  val rx_final = Rx_Final(32)
  rx_final.io.input << rxchecker.io.output
  rx_final.io.crc_error := rxchecker.io.error

  io.output << rx_final.io.output
}

object TxSimpleSim{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new TxSimpleSim()){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.output.ready #= false
      dut.clockDomain.waitSampling(10)
      for(idex <- 0 until 5000){
        dut.io.output.ready #= Random.nextBoolean()
//        dut.io.output.ready #= true
        dut.clockDomain.waitSampling()
      }
    }
  }
}