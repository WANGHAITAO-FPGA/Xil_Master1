import Common.PrintXDC
import spinal.core.widthOf
import spinal.lib.bus.misc.{BusSlaveFactoryDelayed, BusSlaveFactoryRead, BusSlaveFactoryWrite}

import java.io._
package object Common {
  object PrintXDC {
    private var xdc : List[String] = List()

    def apply(input : String) {
      xdc = xdc :+ input
    }
    def apply(address : String, FileName : String) {
      val file = new File(address)
      if(!file.exists()) {
        file.mkdir()
      }
      val writer = new PrintWriter(new File(address + System.getProperty("file.separator") + FileName ))
      xdc.map(x => writer.write(x))
      writer.close
    }
    def clear() = {xdc = List();}
    def get(): String = {
      val ret = xdc.reduce(_+_)
      ret
    }
  }
}


object test extends App{
  PrintXDC(s"set_property LOC DSP48E2_X [get_cells _reg]\n")
//  PrintXDC("xdc","route.xdc")
}
