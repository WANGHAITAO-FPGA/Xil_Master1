name := "Xil_Master"

version := "0.1"

scalaVersion := "2.12.16"

val spinalVersion = "1.8.0"

libraryDependencies ++= Seq(
  "com.github.spinalhdl" % "spinalhdl-core_2.12" % spinalVersion,
  "com.github.spinalhdl" % "spinalhdl-lib_2.12" % spinalVersion,
  compilerPlugin("com.github.spinalhdl" % "spinalhdl-idsl-plugin_2.12" % spinalVersion),
  "org.scalatest" %% "scalatest" % "3.0.8" % "test",
  "com.github.wookietreiber" %% "scala-chart" % "latest.integration"
)

fork := true