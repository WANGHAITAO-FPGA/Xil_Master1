// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : SawToothWaveGenerator
// Git hash  : 0fd1febc8346d779f50a61815c7871e1da7e653f

`timescale 1ns/1ps

module SawToothWaveGenerator (
  input               io_sawtooth_io_direction,
  input      [7:0]    io_sawtooth_io_step,
  input               io_sawtooth_io_start,
  input               io_sawtooth_io_stop,
  input               io_sawtooth_io_init,
  output     [15:0]   io_output,
  input               io_tick,
  input               clk,
  input               reset
);

  wire       [14:0]   _zz_when_SawToothWaveGenerator_l52;
  wire       [14:0]   _zz_when_SawToothWaveGenerator_l52_1;
  wire       [14:0]   _zz_sawtooth;
  wire       [14:0]   _zz_when_SawToothWaveGenerator_l58;
  wire       [14:0]   _zz_sawtooth_1;
  wire       [15:0]   _zz_io_output;
  reg        [7:0]    step;
  reg        [14:0]   sawtooth;
  reg                 isRunning;
  reg                 start;
  reg                 stop;
  reg                 init;
  reg                 tick;
  reg                 init_regNext;
  reg                 stop_regNext;
  wire                when_SawToothWaveGenerator_l38;
  reg                 start_regNext;
  wire                when_SawToothWaveGenerator_l40;
  reg                 tick_regNext;
  wire                when_SawToothWaveGenerator_l49;
  wire                when_SawToothWaveGenerator_l52;
  wire                when_SawToothWaveGenerator_l58;

  assign _zz_when_SawToothWaveGenerator_l52 = (15'h7fff - _zz_when_SawToothWaveGenerator_l52_1);
  assign _zz_when_SawToothWaveGenerator_l52_1 = {7'd0, step};
  assign _zz_sawtooth = {7'd0, step};
  assign _zz_when_SawToothWaveGenerator_l58 = {7'd0, step};
  assign _zz_sawtooth_1 = {7'd0, step};
  assign _zz_io_output = {1'd0, sawtooth};
  assign when_SawToothWaveGenerator_l38 = ((init && (! init_regNext)) || (stop && (! stop_regNext))); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l40 = (start && (! start_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l49 = (tick && (! tick_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l52 = (_zz_when_SawToothWaveGenerator_l52 < sawtooth); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l58 = (sawtooth < _zz_when_SawToothWaveGenerator_l58); // @[BaseType.scala 305:24]
  assign io_output = (_zz_io_output + 16'h8000); // @[SawToothWaveGenerator.scala 66:13]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      step <= 8'h0; // @[Data.scala 400:33]
      sawtooth <= 15'h0; // @[Data.scala 400:33]
      isRunning <= 1'b0; // @[Data.scala 400:33]
      start <= 1'b0; // @[Data.scala 400:33]
      stop <= 1'b0; // @[Data.scala 400:33]
      init <= 1'b0; // @[Data.scala 400:33]
      tick <= 1'b0; // @[Data.scala 400:33]
    end else begin
      step <= io_sawtooth_io_step; // @[SawToothWaveGenerator.scala 24:8]
      start <= io_sawtooth_io_start; // @[SawToothWaveGenerator.scala 29:9]
      stop <= io_sawtooth_io_stop; // @[SawToothWaveGenerator.scala 31:8]
      init <= io_sawtooth_io_init; // @[SawToothWaveGenerator.scala 33:8]
      tick <= io_tick; // @[SawToothWaveGenerator.scala 36:8]
      if(when_SawToothWaveGenerator_l38) begin
        isRunning <= 1'b0; // @[SawToothWaveGenerator.scala 39:15]
      end else begin
        if(when_SawToothWaveGenerator_l40) begin
          isRunning <= 1'b1; // @[SawToothWaveGenerator.scala 41:15]
        end else begin
          isRunning <= isRunning; // @[SawToothWaveGenerator.scala 43:15]
        end
      end
      if(init) begin
        sawtooth <= 15'h0; // @[SawToothWaveGenerator.scala 46:14]
      end
      if(when_SawToothWaveGenerator_l49) begin
        if(isRunning) begin
          if(io_sawtooth_io_direction) begin
            if(when_SawToothWaveGenerator_l52) begin
              sawtooth <= 15'h0; // @[SawToothWaveGenerator.scala 53:20]
            end else begin
              sawtooth <= (sawtooth + _zz_sawtooth); // @[SawToothWaveGenerator.scala 55:20]
            end
          end else begin
            if(when_SawToothWaveGenerator_l58) begin
              sawtooth <= 15'h7fff; // @[SawToothWaveGenerator.scala 59:20]
            end else begin
              sawtooth <= (sawtooth - _zz_sawtooth_1); // @[SawToothWaveGenerator.scala 61:20]
            end
          end
        end
      end
    end
  end

  always @(posedge clk) begin
    init_regNext <= init; // @[Reg.scala 39:30]
    stop_regNext <= stop; // @[Reg.scala 39:30]
    start_regNext <= start; // @[Reg.scala 39:30]
    tick_regNext <= tick; // @[Reg.scala 39:30]
  end


endmodule
