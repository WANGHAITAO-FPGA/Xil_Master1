// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : TxInterFrame
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module TxInterFrame (
  input               io_input_valid,
  output              io_input_ready,
  input               io_input_payload_last,
  input      [31:0]   io_input_payload_fragment,
  output              io_output_valid,
  input               io_output_ready,
  output              io_output_payload_last,
  output     [31:0]   io_output_payload_fragment,
  input               clk,
  input               reset
);

  reg                 io_input_payload_last_regNext;
  reg                 io_input_payload_last_regNext_1;

  assign io_output_payload_fragment = io_input_payload_fragment; // @[TxSimpleBus.scala 207:30]
  assign io_output_valid = (io_input_valid || io_input_payload_last_regNext); // @[TxSimpleBus.scala 208:19]
  assign io_input_ready = io_output_ready; // @[TxSimpleBus.scala 209:18]
  assign io_output_payload_last = io_input_payload_last_regNext_1; // @[TxSimpleBus.scala 210:26]
  always @(posedge clk) begin
    io_input_payload_last_regNext <= io_input_payload_last; // @[Reg.scala 39:30]
    io_input_payload_last_regNext_1 <= io_input_payload_last; // @[Reg.scala 39:30]
  end


endmodule
