package Common.Endat

import Common.Endat.Endat_Register.{Identification_Reg, Sw_Strobe}
import spinal.core._

object Endat_Register extends Enumeration {
  val Send_Reg, Receive_Reg1, Receive_Reg2, Receive_Reg3, Config_Reg1,
  Config_Reg2, Config_Reg3, Status_Reg, Interrupt_Mask, Test_Reg1, Test_Reg2, Receive_Reg4,
  Sw_Strobe, Identification_Reg = Value
}


object Identity{
  def Identity(valid : Boolean, rw : Boolean, bytenumber : Int):Int = {
    val k = (valid.toInt<<7) + (rw.toInt<<6) + bytenumber
    return k
  }

  def Get_Bytenumber(addr:Endat_Register.Value):Int={
    var bytenumber = 0
    addr match {
      case Endat_Register.Send_Reg => bytenumber = 4
      case Endat_Register.Receive_Reg1 => bytenumber = 8
      case Endat_Register.Receive_Reg2 => bytenumber = 4
      case Endat_Register.Receive_Reg3 => bytenumber = 4
      case Endat_Register.Config_Reg1 =>  bytenumber = 4
      case Endat_Register.Config_Reg2 =>  bytenumber = 4
      case Endat_Register.Config_Reg3 =>  bytenumber = 4
      case Endat_Register.Status_Reg =>   bytenumber = 4
      case Endat_Register.Interrupt_Mask => bytenumber = 4
      case Endat_Register.Test_Reg1 => bytenumber = 4
      case Endat_Register.Test_Reg2 => bytenumber = 4
      case Endat_Register.Receive_Reg4 => bytenumber = 8
      case Endat_Register.Sw_Strobe => bytenumber = 4
      case Endat_Register.Identification_Reg => bytenumber = 4
      case _ => bytenumber = 4
    }
    return bytenumber
  }

  def Identity_Addr(rw : Boolean, addr:Endat_Register.Value):Int={
    var k = 0
    var bytenumber = 0
    addr match {
      case Endat_Register.Send_Reg => k = 0
      case Endat_Register.Receive_Reg1 => k = 4
      case Endat_Register.Receive_Reg2 => k = 12
      case Endat_Register.Receive_Reg3 => k = 16
      case Endat_Register.Config_Reg1 => k = 20
      case Endat_Register.Config_Reg2 => k = 24
      case Endat_Register.Config_Reg3 => k = 28
      case Endat_Register.Status_Reg => k = 32
      case Endat_Register.Interrupt_Mask => k = 36
      case Endat_Register.Test_Reg1 => k = 40
      case Endat_Register.Test_Reg2 => k = 44
      case Endat_Register.Receive_Reg4 => k = 48
      case Endat_Register.Sw_Strobe => k = 56
      case Endat_Register.Identification_Reg => k = 60
      case _ => k = 0
    }
    val identity = Identity(false,rw,Get_Bytenumber(addr))
    return (identity<<8)+k
  }

  def main(args:Array[String]): Unit ={
    println(Identity(false,false,10))
    println(Identity_Addr(true,Endat_Register.Receive_Reg1))
  }
}


