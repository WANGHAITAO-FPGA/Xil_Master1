package Common.Xil_BlackBox

import Common.BISSC._
import spinal.core._

case class BisscTest() extends Component{
  val io = new Bundle{
    val m_postion = in Bits(32 bits)
    val postion = out Bits(32 bits)
    val error = in Bool()
    val warm = in Bool()
  }
  noIoPrefix()

  val bissc_master = BisscMaster(32,10,2000)
  //val bissc_master = BISSC()
  val bissc_slave = BisscSlave(32,200)
  bissc_slave.io.error := io.error
  bissc_slave.io.warm := io.warm
  bissc_slave.io.s_bissc <> bissc_master.io.bissc
  bissc_slave.io.m_postion := io.m_postion
  io.postion := bissc_master.io.postion
}

object BisscTest{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(new BisscTest){dut=>
      dut.clockDomain.forkStimulus(10)
      dut.io.m_postion #= 0x17e4c169
      dut.io.error #= true
      dut.io.warm #= true
      dut.clockDomain.waitSampling(3000)
      dut.io.m_postion #= 0x17e4c16a
      dut.clockDomain.waitSampling(3000)
      dut.io.m_postion #= 0x17e61f4b
      dut.clockDomain.waitSampling(3000)
      dut.io.m_postion #= 0x18767df
      dut.clockDomain.waitSampling(30000)
    }
  }

}