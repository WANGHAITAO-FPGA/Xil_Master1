// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : SawTooth
// Git hash  : 0fd1febc8346d779f50a61815c7871e1da7e653f

`timescale 1ns/1ps

module SawTooth (
  input               sawtooth_io_0_direction,
  input      [7:0]    sawtooth_io_0_step,
  input               sawtooth_io_0_start,
  input               sawtooth_io_0_stop,
  input               sawtooth_io_0_init,
  output              sawtooth_data_valid,
  output     [15:0]   sawtooth_data_payload_data_0,
  input               clk,
  input               reset
);

  wire       [15:0]   sawtoothwavegenerator_0_io_output;
  wire       [7:0]    _zz_counter_valueNext;
  wire       [0:0]    _zz_counter_valueNext_1;
  wire                counter_willIncrement;
  wire                counter_willClear;
  reg        [7:0]    counter_valueNext;
  reg        [7:0]    counter_value;
  wire                counter_willOverflowIfInc;
  wire                counter_willOverflow;
  reg                 tick;
  reg                 tick_delay_1;
  reg                 tick_delay_2;

  assign _zz_counter_valueNext_1 = counter_willIncrement;
  assign _zz_counter_valueNext = {7'd0, _zz_counter_valueNext_1};
  SawToothWaveGenerator sawtoothwavegenerator_0 (
    .io_sawtooth_io_direction (sawtooth_io_0_direction                ), //i
    .io_sawtooth_io_step      (sawtooth_io_0_step[7:0]                ), //i
    .io_sawtooth_io_start     (sawtooth_io_0_start                    ), //i
    .io_sawtooth_io_stop      (sawtooth_io_0_stop                     ), //i
    .io_sawtooth_io_init      (sawtooth_io_0_init                     ), //i
    .io_output                (sawtoothwavegenerator_0_io_output[15:0]), //o
    .io_tick                  (tick                                   ), //i
    .clk                      (clk                                    ), //i
    .reset                    (reset                                  )  //i
  );
  assign counter_willClear = 1'b0; // @[Utils.scala 537:19]
  assign counter_willOverflowIfInc = (counter_value == 8'hc7); // @[BaseType.scala 305:24]
  assign counter_willOverflow = (counter_willOverflowIfInc && counter_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    if(counter_willOverflow) begin
      counter_valueNext = 8'h0; // @[Utils.scala 552:17]
    end else begin
      counter_valueNext = (counter_value + _zz_counter_valueNext); // @[Utils.scala 554:17]
    end
    if(counter_willClear) begin
      counter_valueNext = 8'h0; // @[Utils.scala 558:15]
    end
  end

  assign counter_willIncrement = 1'b1; // @[Utils.scala 540:41]
  assign sawtooth_data_payload_data_0 = sawtoothwavegenerator_0_io_output; // @[SawToothWaveGenerator.scala 90:38]
  assign sawtooth_data_valid = tick_delay_2; // @[SawToothWaveGenerator.scala 92:26]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      counter_value <= 8'h0; // @[Data.scala 400:33]
      tick_delay_1 <= 1'b0; // @[Data.scala 400:33]
      tick_delay_2 <= 1'b0; // @[Data.scala 400:33]
    end else begin
      counter_value <= counter_valueNext; // @[Reg.scala 39:30]
      tick_delay_1 <= tick; // @[Reg.scala 39:30]
      tick_delay_2 <= tick_delay_1; // @[Reg.scala 39:30]
    end
  end

  always @(posedge clk) begin
    tick <= 1'b0; // @[SawToothWaveGenerator.scala 82:8]
    if(counter_willOverflow) begin
      tick <= 1'b1; // @[SawToothWaveGenerator.scala 84:10]
    end
  end


endmodule

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
  wire       [14:0]   _zz_sawtooth_1;
  wire       [14:0]   _zz_when_SawToothWaveGenerator_l58;
  wire       [14:0]   _zz_sawtooth_1_1;
  wire       [15:0]   _zz_io_output;
  reg        [7:0]    step;
  reg        [14:0]   sawtooth_1;
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
  assign _zz_sawtooth_1 = {7'd0, step};
  assign _zz_when_SawToothWaveGenerator_l58 = {7'd0, step};
  assign _zz_sawtooth_1_1 = {7'd0, step};
  assign _zz_io_output = {1'd0, sawtooth_1};
  assign when_SawToothWaveGenerator_l38 = ((init && (! init_regNext)) || (stop && (! stop_regNext))); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l40 = (start && (! start_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l49 = (tick && (! tick_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l52 = (_zz_when_SawToothWaveGenerator_l52 < sawtooth_1); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l58 = (sawtooth_1 < _zz_when_SawToothWaveGenerator_l58); // @[BaseType.scala 305:24]
  assign io_output = (_zz_io_output + 16'h8000); // @[SawToothWaveGenerator.scala 66:13]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      step <= 8'h0; // @[Data.scala 400:33]
      sawtooth_1 <= 15'h0; // @[Data.scala 400:33]
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
        sawtooth_1 <= 15'h0; // @[SawToothWaveGenerator.scala 46:14]
      end
      if(when_SawToothWaveGenerator_l49) begin
        if(isRunning) begin
          if(io_sawtooth_io_direction) begin
            if(when_SawToothWaveGenerator_l52) begin
              sawtooth_1 <= 15'h0; // @[SawToothWaveGenerator.scala 53:20]
            end else begin
              sawtooth_1 <= (sawtooth_1 + _zz_sawtooth_1); // @[SawToothWaveGenerator.scala 55:20]
            end
          end else begin
            if(when_SawToothWaveGenerator_l58) begin
              sawtooth_1 <= 15'h7fff; // @[SawToothWaveGenerator.scala 59:20]
            end else begin
              sawtooth_1 <= (sawtooth_1 - _zz_sawtooth_1_1); // @[SawToothWaveGenerator.scala 61:20]
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
