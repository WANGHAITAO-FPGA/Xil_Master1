package TEST

import java.io._
import scalax.chart.api._
import sourcecode.Line


import scala.Console.{BLUE, RED}

object Bin_Test {
  def main(args: Array[String]): Unit = {
    val file = new File("D:/data.bin")
    val inputStream = new FileInputStream(file)
    val bytes = Stream.continually(inputStream.read).take(200*4).map(_.toByte).toArray
    val floats = bytes.grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray

    val writer = new PrintWriter(new File("output.txt"))
    for (f <- floats) {
      writer.write(f.toString + "\n")
    }
    writer.close()

    val data = io.Source.fromFile("output.txt").getLines().map(_.toDouble).toArray
    val chart = XYLineChart(data.zipWithIndex.map{case (y, x) => (x.toDouble, y)}.toSeq)

    chart.title = "Data Plot"
    chart.show()
  }
}


