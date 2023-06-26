package TEST

import spinal.core._
import spinal.lib.experimental.math.{Floating32, RecFloating, RecFloating32}

case class fix_test() extends Component{
  val io = new Bundle{
    val data_in = in SInt(10 bits)
    val data_out = out SInt(5 bits)
  }
  noIoPrefix()

  val t_data = io.data_in.fixTo(7 downto 3).setAsReg()
  io.data_out := t_data
}

object fix_test extends App{
  SpinalVerilog(fix_test())
}

object fix_sim{
  def main(args: Array[String]): Unit = {
    import spinal.core.sim._
    SimConfig.withWave.doSim(fix_test()){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.data_in #= 250
      dut.clockDomain.waitSampling(1000)
    }
  }
}