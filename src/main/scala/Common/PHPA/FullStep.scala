package Common.PHPA

import spinal.core._

case class FullStep(samplewidth: Int, samplecount: Int) extends Component {
  val io = new Bundle {
    val c_data = out(Bits(samplewidth bits))
    val d1_data = out(Bits(samplewidth bits))
    val d2_data = out(Bits(samplewidth bits))
//    val addr = in(Bits(log2Up(samplecount) bits))
  }
  noIoPrefix()
  val Sample = Bits(samplewidth bits)
  // 前三个分段的斜率是定值
  val c_slope1 = 1.0 / (samplecount / 16)
  val c_slope3 = -1.0 / (samplecount / 16)
  // 前三个分段的值是定值
  val c_line1 = 0.0
  val c_line2 = 1.0
  val c_line3 = 8.0
  // 计算后两个分段的值
  val c_line4 = -1.0
  val c_line5 = -16.0

  val d1_slope2 = 1.0/(samplecount/16*3)
  val d1_slope4 = -1.0/(samplecount/16*3)
  val d1_line1 = -1.0
  val d1_line2 = -1.333
  val d1_line3 = 1.0
  val d1_line4 = 4
  val d1_line5 = -1.0

  val c_romSamples = (0 until samplecount).map { sampleid =>
    val c_line = sampleid match {
      case i if i < samplecount / 16 => c_line1 + c_slope1 * i
      case i if i <= samplecount / 16 * 7 - 1 => c_line2
      case i if i <= samplecount / 16 * 9 => c_line3 + c_slope3 * i
      case i if i <= samplecount / 16 * 15 => c_line4
      case _ => c_line5 + c_slope1 * sampleid
    }
    BigInt((c_line * (Math.pow(2.0, samplewidth - 1) - 1)).toLong)
  }

  val d1_romSamples = (0 until samplecount).map { sampleid =>
    val d1_line = sampleid match {
      case i if i < samplecount / 16 => d1_line1
      case i if i <= samplecount / 16 * 7 - 1 => d1_line2 + d1_slope2 * i
      case i if i <= samplecount / 16 * 9 => d1_line3
      case i if i <= samplecount / 16 * 15 => d1_line4 + d1_slope4 * i
      case _ => d1_line5
    }
    BigInt((d1_line * (Math.pow(2.0, samplewidth - 1) - 1)).toLong)
  }

//  val d2_romSamples = (0 until samplecount).map { sampleid =>
//    val d2_line = sampleid match {
//      case i if i < samplecount / 16 => -d1_line1
//      case i if i <= samplecount / 16 * 7 - 1 => -(d1_line2 + d1_slope2 * i)
//      case i if i <= samplecount / 16 * 9 => -d1_line3
//      case i if i <= samplecount / 16 * 15 => -(d1_line4 + d1_slope4 * i)
//      case _ => -d1_line5
//    }
//    BigInt((d2_line * (Math.pow(2.0, samplewidth - 1) - 1)).toLong)
//  }
  val c_rom = Mem(Sample, samplecount).initBigInt(c_romSamples,true)
  val d1_rom = Mem(Sample, samplecount).initBigInt(d1_romSamples,true)

  val i = Reg(UInt(log2Up(samplecount) bits)) init 0
  when(i < samplecount -1){
    i := i + 1
  }otherwise{
    i := 0
  }
  io.c_data := c_rom.readSync(i)
  io.d1_data := d1_rom.readSync(i)
  io.d2_data := (d1_rom.readSync(i).asSInt * -1).asBits.resized
}

object FullStep extends App{
  SpinalVerilog(FullStep(16,358))
}