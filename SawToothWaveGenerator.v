// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : SawToothWaveGenerator

`timescale 1ns/1ps

module SawToothWaveGenerator (
  input               io_direction,
  input      [4:0]    io_step,
  input               io_start,
  input               io_stop,
  input               io_reset,
  output     [14:0]   io_output,
  input               clk,
  input               reset_1
);

  wire       [4:0]    _zz_step;
  wire       [4:0]    _zz_step_1;
  wire       [4:0]    _zz_step_2;
  wire       [14:0]   _zz_sawtooth;
  wire       [4:0]    _zz_sawtooth_1;
  wire       [4:0]    step;
  reg        [14:0]   sawtooth;
  reg                 isRunning;
  wire                start;
  wire                stop;
  wire                reset;
  reg                 stop_regNext;
  reg                 reset_regNext;
  wire                when_SawToothWaveGenerator_l23;
  reg                 start_regNext;
  wire                when_SawToothWaveGenerator_l25;
  reg                 reset_regNext_1;
  wire                when_SawToothWaveGenerator_l31;

  assign _zz_step = (- _zz_step_1);
  assign _zz_step_1 = io_step;
  assign _zz_step_2 = io_step;
  assign _zz_sawtooth_1 = step;
  assign _zz_sawtooth = {10'd0, _zz_sawtooth_1};
  assign step = (io_direction ? _zz_step : _zz_step_2); // @[Expression.scala 1420:25]
  assign start = 1'b0;
  assign stop = 1'b0;
  assign reset = 1'b0;
  assign when_SawToothWaveGenerator_l23 = ((stop && (! stop_regNext)) || (reset && (! reset_regNext))); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l25 = (start && (! start_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l31 = (reset && (! reset_regNext_1)); // @[BaseType.scala 305:24]
  assign io_output = sawtooth; // @[SawToothWaveGenerator.scala 39:13]
  always @(posedge clk or posedge reset_1) begin
    if(reset_1) begin
      sawtooth <= 15'h0; // @[Data.scala 400:33]
      isRunning <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(when_SawToothWaveGenerator_l23) begin
        isRunning <= 1'b0; // @[SawToothWaveGenerator.scala 24:15]
      end else begin
        if(when_SawToothWaveGenerator_l25) begin
          isRunning <= 1'b1; // @[SawToothWaveGenerator.scala 26:15]
        end else begin
          isRunning <= isRunning; // @[SawToothWaveGenerator.scala 28:15]
        end
      end
      if(when_SawToothWaveGenerator_l31) begin
        sawtooth <= 15'h0; // @[SawToothWaveGenerator.scala 32:14]
      end
      if(isRunning) begin
        sawtooth <= (sawtooth + _zz_sawtooth); // @[SawToothWaveGenerator.scala 36:14]
      end
    end
  end

  always @(posedge clk) begin
    stop_regNext <= stop; // @[Reg.scala 39:30]
    reset_regNext <= reset; // @[Reg.scala 39:30]
    start_regNext <= start; // @[Reg.scala 39:30]
    reset_regNext_1 <= reset; // @[Reg.scala 39:30]
  end


endmodule
