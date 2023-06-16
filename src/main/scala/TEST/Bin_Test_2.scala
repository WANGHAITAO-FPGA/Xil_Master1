package TEST

import org.jfree.data.xy.{XYDataset, XYSeries, XYSeriesCollection}
import org.jfree.chart.{ChartFactory, ChartFrame}
import org.jfree.chart.plot.{PlotOrientation, XYPlot}
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer
import spinal.core.fiber.Handle.initImplicit

import java.io.{File, FileInputStream, PrintWriter}
// Create a dataset of XYData

//object Bin_Test_2{
//  def main(args: Array[String]): Unit = {
////    val file = new File("D:/data.bin")
////    val inputStream = new FileInputStream(file)
////    val bytes = Stream.continually(inputStream.read).take(200 * 4).map(_.toByte).toArray
////    val floats = bytes.grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray
////
////    val writer = new PrintWriter(new File("output.txt"))
////    for (f <- floats) {
////      writer.write(f.toString + "\n")
////    }
////    writer.close()
////
////    val file1 = new File("D:/data2.bin")
////    val inputStream1 = new FileInputStream(file1)
////    val bytes1 = Stream.continually(inputStream1.read).take(200 * 4).map(_.toByte).toArray
////    val floats1 = bytes1.grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray
////
////    val writer1 = new PrintWriter(new File("output1.txt"))
////    for (f <- floats1) {
////      writer1.write(f.toString + "\n")
////    }
////    writer1.close()
//    val file = new File("D:/data.bin")
//    val inputStream = new FileInputStream(file)
//    val bytes = Stream.continually(inputStream.read).take(400 * 4).map(_.toByte).toArray
//
//    // Split bytes into two arrays: one for odd bytes, one for even bytes
//    val (oddBytes, evenBytes) = bytes.zipWithIndex.partition(_._2 % 2 == 0)
//    val oddFloats = oddBytes.map(_._1).grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray
//    val evenFloats = evenBytes.map(_._1).grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray
//
//    // Write odd floats to one file, even floats to another file
//    val oddWriter = new PrintWriter(new File("odd_output.txt"))
//    val evenWriter = new PrintWriter(new File("even_output.txt"))
//    for (f <- oddFloats) {
//      oddWriter.write(f.toString + "\n")
//    }
//    for (f <- evenFloats) {
//      evenWriter.write(f.toString + "\n")
//    }
//    oddWriter.close()
//    evenWriter.close()
//
//    val data: Array[Double] = io.Source.fromFile("odd_output.txt").getLines().map(_.toDouble).toArray
//    // Create the first line
//    val series1: XYSeries = new XYSeries("Data Plot")
//    for (i <- data.indices) {
//      series1.add(i.toDouble, data(i))
//    }
//    // Create the second line
//    val data1: Array[Double] = io.Source.fromFile("even_output.txt").getLines().map(_.toDouble).toArray
//    val series2: XYSeries = new XYSeries("Second Line")
//    for (i <- data1.indices) {
//      series2.add(i.toDouble, data1(i))
//    }
//    // Create the dataset
//    val dataset: XYSeriesCollection = new XYSeriesCollection()
//    dataset.addSeries(series1)
//    dataset.addSeries(series2)
//    // Create the chart
//    val chart = ChartFactory.createXYLineChart(
//      "Data Plot", // chart title
//      "X", // x-axis label
//      "Y", // y-axis label
//      dataset, // data
//      PlotOrientation.VERTICAL,
//      true, // include legend
//      true, // tooltips
//      false // urls
//    )
//    // Set the color of the second line to blue
//    val plot: XYPlot = chart.getXYPlot()
//    val renderer: XYLineAndShapeRenderer = new XYLineAndShapeRenderer()
//    renderer.setSeriesPaint(1, java.awt.Color.BLUE)
//    plot.setRenderer(renderer)
//    // Display the chart
//    val frame = new ChartFrame("Data Plot", chart)
//    frame.pack()
//    frame.setVisible(true)
//  }
//}

object Bin_Test_2{
  def main(args: Array[String]): Unit = {
    val file = new File("D:/data.bin")
    val inputStream = new FileInputStream(file)
    val bytes = Stream.continually(inputStream.read).take(400 * 4).map(_.toByte).toArray
    val floats = bytes.grouped(4).map(_.reverse).map(java.nio.ByteBuffer.wrap(_).getFloat).toArray

    // Split bytes into two arrays: one for odd bytes, one for even bytes
    val oddFloats = floats.zipWithIndex.filter(_._2 % 2 != 0).map(_._1)
    val evenFloats = floats.zipWithIndex.filter(_._2 % 2 == 0).map(_._1)

    val data: Array[Double] = oddFloats.map(_.toDouble)
    // Create the first line
    val series1: XYSeries = new XYSeries("Data Plot")
    for (i <- data.indices) {
      series1.add(i.toDouble, data(i))
    }
    // Create the second line
    val data1: Array[Double] = evenFloats.map(_.toDouble)
    val series2: XYSeries = new XYSeries("Second Line")
    for (i <- data1.indices) {
      series2.add(i.toDouble, data1(i))
    }
    // Create the dataset
    val dataset: XYSeriesCollection = new XYSeriesCollection()
    dataset.addSeries(series1)
    dataset.addSeries(series2)
    // Create the chart
    val chart = ChartFactory.createXYLineChart(
      "Data Plot", // chart title
      "X", // x-axis label
      "Y", // y-axis label
      dataset, // data
      PlotOrientation.VERTICAL,
      true, // include legend
      true, // tooltips
      false // urls
    )
    // Set the color of the second line to blue
    val plot: XYPlot = chart.getXYPlot()
    val renderer: XYLineAndShapeRenderer = new XYLineAndShapeRenderer()
    renderer.setSeriesPaint(1, java.awt.Color.BLUE)
    plot.setRenderer(renderer)
    // Display the chart
    val frame = new ChartFrame("Data Plot", chart)
    frame.pack()
    frame.setVisible(true)
  }
}


