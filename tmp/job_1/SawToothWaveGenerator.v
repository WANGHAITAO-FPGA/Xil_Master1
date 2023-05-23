// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : SawToothWaveGenerator

`timescale 1ns/1ps

module SawToothWaveGenerator (
  input               io_direction,
  input      [7:0]    io_step,
  input               io_start,
  input               io_stop,
  input               io_init,
  output     [14:0]   io_output,
  input               clk,
  input               reset
);

  wire       [14:0]   _zz_sawtooth;
  wire       [14:0]   _zz_sawtooth_1;
  reg        [7:0]    step;
  reg        [14:0]   sawtooth;
  reg                 isRunning;
  reg                 start;
  reg                 stop;
  reg                 init;
  reg                 init_regNext;
  reg                 stop_regNext;
  wire                when_SawToothWaveGenerator_l27;
  reg                 start_regNext;
  wire                when_SawToothWaveGenerator_l29;

  assign _zz_sawtooth = {7'd0, step};
  assign _zz_sawtooth_1 = {7'd0, step};
  assign when_SawToothWaveGenerator_l27 = ((init && (! init_regNext)) || (stop && (! stop_regNext))); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l29 = (start && (! start_regNext)); // @[BaseType.scala 305:24]
  assign io_output = sawtooth; // @[SawToothWaveGenerator.scala 45:13]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      step <= 8'h0; // @[Data.scala 400:33]
      sawtooth <= 15'h0; // @[Data.scala 400:33]
      isRunning <= 1'b0; // @[Data.scala 400:33]
      start <= 1'b0; // @[Data.scala 400:33]
      stop <= 1'b0; // @[Data.scala 400:33]
      init <= 1'b0; // @[Data.scala 400:33]
    end else begin
      step <= io_step; // @[SawToothWaveGenerator.scala 16:8]
      start <= io_start; // @[SawToothWaveGenerator.scala 21:9]
      stop <= io_stop; // @[SawToothWaveGenerator.scala 23:8]
      init <= io_init; // @[SawToothWaveGenerator.scala 25:8]
      if(when_SawToothWaveGenerator_l27) begin
        isRunning <= 1'b0; // @[SawToothWaveGenerator.scala 28:15]
      end else begin
        if(when_SawToothWaveGenerator_l29) begin
          isRunning <= 1'b1; // @[SawToothWaveGenerator.scala 30:15]
        end else begin
          isRunning <= isRunning; // @[SawToothWaveGenerator.scala 32:15]
        end
      end
      if(init) begin
        sawtooth <= 15'h0; // @[SawToothWaveGenerator.scala 35:14]
      end
      if(isRunning) begin
        if(io_direction) begin
          sawtooth <= (sawtooth + _zz_sawtooth); // @[SawToothWaveGenerator.scala 40:16]
        end else begin
          sawtooth <= (sawtooth - _zz_sawtooth_1); // @[SawToothWaveGenerator.scala 42:16]
        end
      end
    end
  end

  always @(posedge clk) begin
    init_regNext <= init; // @[Reg.scala 39:30]
    stop_regNext <= stop; // @[Reg.scala 39:30]
    start_regNext <= start; // @[Reg.scala 39:30]
  end


endmodule
