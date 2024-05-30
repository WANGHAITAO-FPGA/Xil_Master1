import spinal.core._
import spinal.lib.{Stream, _}

case class DataConv() extends Component{
  val io = new Bundle{
    val datain = slave(Flow(Bits(32 bits)))
    val intr = in Bool()
    val dataout = master(Stream(Fragment(Bits(32 bits))))
  }
  noIoPrefix()

  val streamfifo = new StreamFifo(Bits(32 bits), 4096)
  streamfifo.logic.ram.addAttribute("ram_style", "block")

  val intr = Reg(Bool()) init False
  intr := io.intr
  val ready = Reg(Bool()) init False
  when(intr.rise()){
    ready := True
  }
  when(streamfifo.io.occupancy  === 0){
    ready := False
  }
  streamfifo.io.push.payload := io.datain.payload
  streamfifo.io.push.valid := io.datain.valid
  io.dataout.payload.fragment := streamfifo.io.pop.payload
  io.dataout.valid := streamfifo.io.pop.valid && ready
  streamfifo.io.pop.ready := io.dataout.ready && ready
  io.dataout.payload.last := (streamfifo.io.occupancy === 1) & io.dataout.fire
}

object DataConv{
  import spinal.core.sim._
  def main(args: Array[String]): Unit = {
    SimConfig.withWave.doSim(DataConv()) { dut =>
      dut.clockDomain.forkStimulus(10)
      dut.io.datain.valid #= false
      dut.io.dataout.ready #= true
      dut.io.intr #= false
      dut.clockDomain.waitSampling(50)
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x01
      dut.clockDomain.waitSampling()
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x02
      dut.clockDomain.waitSampling()
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x03
      dut.clockDomain.waitSampling()
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x04
      dut.clockDomain.waitSampling()
      dut.io.intr #= true
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x05
      dut.clockDomain.waitSampling()
      dut.io.datain.valid #= true
      dut.io.datain.payload #= 0x06
      dut.clockDomain.waitSampling()
      dut.io.datain.valid #= false
      dut.clockDomain.waitSampling(50)
    }
  }
}