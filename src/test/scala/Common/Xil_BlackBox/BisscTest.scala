package Common.Xil_BlackBox

import Common.BISSC.{BisscMaster, BisscSlave}
import spinal.core._

case class BisscTest() extends Component{
  val io = new Bundle{
    val m_postion = in Bits(34 bits)
    val postion = out Bits(32 bits)
  }
  noIoPrefix()

  val bissc_master = BisscMaster(32,10,700)
  val bissc_slave = BisscSlave(34,100)
  bissc_slave.io.s_bissc <> bissc_master.io.bissc
  bissc_slave.io.m_postion := io.m_postion
  io.postion := bissc_master.io.postion
}

object BisscTest{
  import spinal.core.sim._

  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new BisscTest){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.clockDomain.waitSampling(100)
      dut.io.m_postion #= 0x76543211
      dut.clockDomain.waitSampling(5000)
    }
  }

}