// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : SawToothTop
// Git hash  : 0fd1febc8346d779f50a61815c7871e1da7e653f

`timescale 1ns/1ps

module SawToothTop (
  input               sawtooth_io_0_direction,
  input      [7:0]    sawtooth_io_0_step,
  input               sawtooth_io_0_start,
  input               sawtooth_io_0_stop,
  input               sawtooth_io_0_init,
  input               sawtooth_io_1_direction,
  input      [7:0]    sawtooth_io_1_step,
  input               sawtooth_io_1_start,
  input               sawtooth_io_1_stop,
  input               sawtooth_io_1_init,
  input               sawtooth_io_2_direction,
  input      [7:0]    sawtooth_io_2_step,
  input               sawtooth_io_2_start,
  input               sawtooth_io_2_stop,
  input               sawtooth_io_2_init,
  input               sawtooth_io_3_direction,
  input      [7:0]    sawtooth_io_3_step,
  input               sawtooth_io_3_start,
  input               sawtooth_io_3_stop,
  input               sawtooth_io_3_init,
  output              ad5544_CS,
  output              ad5544_LDAC,
  output              ad5544_RS,
  output              ad5544_SCLK,
  output              ad5544_SDIN,
  input               analog_mode,
  input      [15:0]   analog_setdata_0,
  input      [15:0]   analog_setdata_1,
  input      [15:0]   analog_setdata_2,
  input      [15:0]   analog_setdata_3,
  input               analog_trigger,
  input               reset,
  input               clk
);

  wire                sawtooth_1_sawtooth_data_valid;
  wire       [15:0]   sawtooth_1_sawtooth_data_payload_data_0;
  wire       [15:0]   sawtooth_1_sawtooth_data_payload_data_1;
  wire       [15:0]   sawtooth_1_sawtooth_data_payload_data_2;
  wire       [15:0]   sawtooth_1_sawtooth_data_payload_data_3;
  wire                da5544_ad5544_CS;
  wire                da5544_ad5544_LDAC;
  wire                da5544_ad5544_RS;
  wire                da5544_ad5544_SCLK;
  wire                da5544_ad5544_SDIN;
  reg        [15:0]   set_data_0;
  reg        [15:0]   set_data_1;
  reg        [15:0]   set_data_2;
  reg        [15:0]   set_data_3;
  reg                 trigger;

  SawTooth sawtooth_1 (
    .sawtooth_io_0_direction      (sawtooth_io_0_direction                      ), //i
    .sawtooth_io_0_step           (sawtooth_io_0_step[7:0]                      ), //i
    .sawtooth_io_0_start          (sawtooth_io_0_start                          ), //i
    .sawtooth_io_0_stop           (sawtooth_io_0_stop                           ), //i
    .sawtooth_io_0_init           (sawtooth_io_0_init                           ), //i
    .sawtooth_io_1_direction      (sawtooth_io_1_direction                      ), //i
    .sawtooth_io_1_step           (sawtooth_io_1_step[7:0]                      ), //i
    .sawtooth_io_1_start          (sawtooth_io_1_start                          ), //i
    .sawtooth_io_1_stop           (sawtooth_io_1_stop                           ), //i
    .sawtooth_io_1_init           (sawtooth_io_1_init                           ), //i
    .sawtooth_io_2_direction      (sawtooth_io_2_direction                      ), //i
    .sawtooth_io_2_step           (sawtooth_io_2_step[7:0]                      ), //i
    .sawtooth_io_2_start          (sawtooth_io_2_start                          ), //i
    .sawtooth_io_2_stop           (sawtooth_io_2_stop                           ), //i
    .sawtooth_io_2_init           (sawtooth_io_2_init                           ), //i
    .sawtooth_io_3_direction      (sawtooth_io_3_direction                      ), //i
    .sawtooth_io_3_step           (sawtooth_io_3_step[7:0]                      ), //i
    .sawtooth_io_3_start          (sawtooth_io_3_start                          ), //i
    .sawtooth_io_3_stop           (sawtooth_io_3_stop                           ), //i
    .sawtooth_io_3_init           (sawtooth_io_3_init                           ), //i
    .sawtooth_data_valid          (sawtooth_1_sawtooth_data_valid               ), //o
    .sawtooth_data_payload_data_0 (sawtooth_1_sawtooth_data_payload_data_0[15:0]), //o
    .sawtooth_data_payload_data_1 (sawtooth_1_sawtooth_data_payload_data_1[15:0]), //o
    .sawtooth_data_payload_data_2 (sawtooth_1_sawtooth_data_payload_data_2[15:0]), //o
    .sawtooth_data_payload_data_3 (sawtooth_1_sawtooth_data_payload_data_3[15:0]), //o
    .clk                          (clk                                          ), //i
    .reset                        (reset                                        )  //i
  );
  AD5544 da5544 (
    .ad5544_CS    (da5544_ad5544_CS  ), //o
    .ad5544_LDAC  (da5544_ad5544_LDAC), //o
    .ad5544_RS    (da5544_ad5544_RS  ), //o
    .ad5544_SCLK  (da5544_ad5544_SCLK), //o
    .ad5544_SDIN  (da5544_ad5544_SDIN), //o
    .set_dadata_0 (set_data_0[15:0]  ), //i
    .set_dadata_1 (set_data_1[15:0]  ), //i
    .set_dadata_2 (set_data_2[15:0]  ), //i
    .set_dadata_3 (set_data_3[15:0]  ), //i
    .triger       (trigger           ), //i
    .reset        (reset             ), //i
    .clk          (clk               )  //i
  );
  assign ad5544_CS = da5544_ad5544_CS; // @[SawToothWaveGenerator.scala 137:20]
  assign ad5544_LDAC = da5544_ad5544_LDAC; // @[SawToothWaveGenerator.scala 137:20]
  assign ad5544_RS = da5544_ad5544_RS; // @[SawToothWaveGenerator.scala 137:20]
  assign ad5544_SCLK = da5544_ad5544_SCLK; // @[SawToothWaveGenerator.scala 137:20]
  assign ad5544_SDIN = da5544_ad5544_SDIN; // @[SawToothWaveGenerator.scala 137:20]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      trigger <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(analog_mode) begin
        trigger <= sawtooth_1_sawtooth_data_valid; // @[SawToothWaveGenerator.scala 146:13]
      end else begin
        trigger <= analog_trigger; // @[SawToothWaveGenerator.scala 152:13]
      end
    end
  end

  always @(posedge clk) begin
    if(analog_mode) begin
      set_data_0 <= sawtooth_1_sawtooth_data_payload_data_0; // @[SawToothWaveGenerator.scala 142:17]
      set_data_1 <= sawtooth_1_sawtooth_data_payload_data_1; // @[SawToothWaveGenerator.scala 143:17]
      set_data_2 <= sawtooth_1_sawtooth_data_payload_data_2; // @[SawToothWaveGenerator.scala 144:17]
      set_data_3 <= sawtooth_1_sawtooth_data_payload_data_3; // @[SawToothWaveGenerator.scala 145:17]
    end else begin
      set_data_0 <= analog_setdata_0; // @[SawToothWaveGenerator.scala 148:17]
      set_data_1 <= analog_setdata_1; // @[SawToothWaveGenerator.scala 149:17]
      set_data_2 <= analog_setdata_2; // @[SawToothWaveGenerator.scala 150:17]
      set_data_3 <= analog_setdata_3; // @[SawToothWaveGenerator.scala 151:17]
    end
  end


endmodule

module AD5544 (
  output              ad5544_CS,
  output              ad5544_LDAC,
  output              ad5544_RS,
  output              ad5544_SCLK,
  output              ad5544_SDIN,
  input      [15:0]   set_dadata_0,
  input      [15:0]   set_dadata_1,
  input      [15:0]   set_dadata_2,
  input      [15:0]   set_dadata_3,
  input               triger,
  input               reset,
  input               clk
);

  wire                da5544_AD5544_CS;
  wire                da5544_AD5544_LDAC;
  wire                da5544_AD5544_MSB;
  wire                da5544_AD5544_RS;
  wire                da5544_AD5544_SCLK;
  wire                da5544_AD5544_SDIN;

  dac_ad5544 da5544 (
    .clk             (clk               ), //i
    .reset           (reset             ), //i
    .AD5544_CS       (da5544_AD5544_CS  ), //o
    .AD5544_LDAC     (da5544_AD5544_LDAC), //o
    .AD5544_MSB      (da5544_AD5544_MSB ), //o
    .AD5544_RS       (da5544_AD5544_RS  ), //o
    .AD5544_SCLK     (da5544_AD5544_SCLK), //o
    .AD5544_SDIN     (da5544_AD5544_SDIN), //o
    .ad5544_trig     (triger            ), //i
    .AD5544_DATA_IN1 (set_dadata_0[15:0]), //i
    .AD5544_DATA_IN2 (set_dadata_1[15:0]), //i
    .AD5544_DATA_IN3 (set_dadata_2[15:0]), //i
    .AD5544_DATA_IN4 (set_dadata_3[15:0])  //i
  );
  assign ad5544_CS = da5544_AD5544_CS; // @[AD5544.scala 48:16]
  assign ad5544_LDAC = da5544_AD5544_LDAC; // @[AD5544.scala 49:18]
  assign ad5544_RS = da5544_AD5544_RS; // @[AD5544.scala 51:16]
  assign ad5544_SCLK = da5544_AD5544_SCLK; // @[AD5544.scala 52:18]
  assign ad5544_SDIN = da5544_AD5544_SDIN; // @[AD5544.scala 53:18]

endmodule

module SawTooth (
  input               sawtooth_io_0_direction,
  input      [7:0]    sawtooth_io_0_step,
  input               sawtooth_io_0_start,
  input               sawtooth_io_0_stop,
  input               sawtooth_io_0_init,
  input               sawtooth_io_1_direction,
  input      [7:0]    sawtooth_io_1_step,
  input               sawtooth_io_1_start,
  input               sawtooth_io_1_stop,
  input               sawtooth_io_1_init,
  input               sawtooth_io_2_direction,
  input      [7:0]    sawtooth_io_2_step,
  input               sawtooth_io_2_start,
  input               sawtooth_io_2_stop,
  input               sawtooth_io_2_init,
  input               sawtooth_io_3_direction,
  input      [7:0]    sawtooth_io_3_step,
  input               sawtooth_io_3_start,
  input               sawtooth_io_3_stop,
  input               sawtooth_io_3_init,
  output              sawtooth_data_valid,
  output     [15:0]   sawtooth_data_payload_data_0,
  output     [15:0]   sawtooth_data_payload_data_1,
  output     [15:0]   sawtooth_data_payload_data_2,
  output     [15:0]   sawtooth_data_payload_data_3,
  input               clk,
  input               reset
);

  wire       [15:0]   sawtoothwavegenerator_0_io_output;
  wire       [15:0]   sawtoothwavegenerator_1_1_io_output;
  wire       [15:0]   sawtoothwavegenerator_2_1_io_output;
  wire       [15:0]   sawtoothwavegenerator_3_1_io_output;
  wire       [4:0]    _zz_counter_valueNext;
  wire       [0:0]    _zz_counter_valueNext_1;
  wire                counter_willIncrement;
  wire                counter_willClear;
  reg        [4:0]    counter_valueNext;
  reg        [4:0]    counter_value;
  wire                counter_willOverflowIfInc;
  wire                counter_willOverflow;
  reg                 tick;
  reg                 tick_delay_1;
  reg                 tick_delay_2;

  assign _zz_counter_valueNext_1 = counter_willIncrement;
  assign _zz_counter_valueNext = {4'd0, _zz_counter_valueNext_1};
  SawToothWaveGenerator_3 sawtoothwavegenerator_0 (
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
  SawToothWaveGenerator_3 sawtoothwavegenerator_1_1 (
    .io_sawtooth_io_direction (sawtooth_io_1_direction                  ), //i
    .io_sawtooth_io_step      (sawtooth_io_1_step[7:0]                  ), //i
    .io_sawtooth_io_start     (sawtooth_io_1_start                      ), //i
    .io_sawtooth_io_stop      (sawtooth_io_1_stop                       ), //i
    .io_sawtooth_io_init      (sawtooth_io_1_init                       ), //i
    .io_output                (sawtoothwavegenerator_1_1_io_output[15:0]), //o
    .io_tick                  (tick                                     ), //i
    .clk                      (clk                                      ), //i
    .reset                    (reset                                    )  //i
  );
  SawToothWaveGenerator_3 sawtoothwavegenerator_2_1 (
    .io_sawtooth_io_direction (sawtooth_io_2_direction                  ), //i
    .io_sawtooth_io_step      (sawtooth_io_2_step[7:0]                  ), //i
    .io_sawtooth_io_start     (sawtooth_io_2_start                      ), //i
    .io_sawtooth_io_stop      (sawtooth_io_2_stop                       ), //i
    .io_sawtooth_io_init      (sawtooth_io_2_init                       ), //i
    .io_output                (sawtoothwavegenerator_2_1_io_output[15:0]), //o
    .io_tick                  (tick                                     ), //i
    .clk                      (clk                                      ), //i
    .reset                    (reset                                    )  //i
  );
  SawToothWaveGenerator_3 sawtoothwavegenerator_3_1 (
    .io_sawtooth_io_direction (sawtooth_io_3_direction                  ), //i
    .io_sawtooth_io_step      (sawtooth_io_3_step[7:0]                  ), //i
    .io_sawtooth_io_start     (sawtooth_io_3_start                      ), //i
    .io_sawtooth_io_stop      (sawtooth_io_3_stop                       ), //i
    .io_sawtooth_io_init      (sawtooth_io_3_init                       ), //i
    .io_output                (sawtoothwavegenerator_3_1_io_output[15:0]), //o
    .io_tick                  (tick                                     ), //i
    .clk                      (clk                                      ), //i
    .reset                    (reset                                    )  //i
  );
  assign counter_willClear = 1'b0; // @[Utils.scala 537:19]
  assign counter_willOverflowIfInc = (counter_value == 5'h13); // @[BaseType.scala 305:24]
  assign counter_willOverflow = (counter_willOverflowIfInc && counter_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    if(counter_willOverflow) begin
      counter_valueNext = 5'h0; // @[Utils.scala 552:17]
    end else begin
      counter_valueNext = (counter_value + _zz_counter_valueNext); // @[Utils.scala 554:17]
    end
    if(counter_willClear) begin
      counter_valueNext = 5'h0; // @[Utils.scala 558:15]
    end
  end

  assign counter_willIncrement = 1'b1; // @[Utils.scala 540:41]
  assign sawtooth_data_payload_data_0 = sawtoothwavegenerator_0_io_output; // @[SawToothWaveGenerator.scala 92:38]
  assign sawtooth_data_payload_data_1 = sawtoothwavegenerator_1_1_io_output; // @[SawToothWaveGenerator.scala 92:38]
  assign sawtooth_data_payload_data_2 = sawtoothwavegenerator_2_1_io_output; // @[SawToothWaveGenerator.scala 92:38]
  assign sawtooth_data_payload_data_3 = sawtoothwavegenerator_3_1_io_output; // @[SawToothWaveGenerator.scala 92:38]
  assign sawtooth_data_valid = tick_delay_2; // @[SawToothWaveGenerator.scala 94:26]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      counter_value <= 5'h0; // @[Data.scala 400:33]
      tick_delay_1 <= 1'b0; // @[Data.scala 400:33]
      tick_delay_2 <= 1'b0; // @[Data.scala 400:33]
    end else begin
      counter_value <= counter_valueNext; // @[Reg.scala 39:30]
      tick_delay_1 <= tick; // @[Reg.scala 39:30]
      tick_delay_2 <= tick_delay_1; // @[Reg.scala 39:30]
    end
  end

  always @(posedge clk) begin
    tick <= 1'b0; // @[SawToothWaveGenerator.scala 84:8]
    if(counter_willOverflow) begin
      tick <= 1'b1; // @[SawToothWaveGenerator.scala 86:10]
    end
  end


endmodule

//SawToothWaveGenerator_3 replaced by SawToothWaveGenerator_3

//SawToothWaveGenerator_3 replaced by SawToothWaveGenerator_3

//SawToothWaveGenerator_3 replaced by SawToothWaveGenerator_3

module SawToothWaveGenerator_3 (
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

  wire       [14:0]   _zz_when_SawToothWaveGenerator_l54;
  wire       [14:0]   _zz_when_SawToothWaveGenerator_l54_1;
  wire       [14:0]   _zz_sawtooth_1;
  wire       [14:0]   _zz_when_SawToothWaveGenerator_l60;
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
  wire                when_SawToothWaveGenerator_l40;
  reg                 start_regNext;
  wire                when_SawToothWaveGenerator_l42;
  reg                 tick_regNext;
  wire                when_SawToothWaveGenerator_l51;
  wire                when_SawToothWaveGenerator_l54;
  wire                when_SawToothWaveGenerator_l60;

  assign _zz_when_SawToothWaveGenerator_l54 = (15'h7fff - _zz_when_SawToothWaveGenerator_l54_1);
  assign _zz_when_SawToothWaveGenerator_l54_1 = {7'd0, step};
  assign _zz_sawtooth_1 = {7'd0, step};
  assign _zz_when_SawToothWaveGenerator_l60 = {7'd0, step};
  assign _zz_sawtooth_1_1 = {7'd0, step};
  assign _zz_io_output = {1'd0, sawtooth_1};
  assign when_SawToothWaveGenerator_l40 = ((init && (! init_regNext)) || (stop && (! stop_regNext))); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l42 = (start && (! start_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l51 = (tick && (! tick_regNext)); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l54 = (_zz_when_SawToothWaveGenerator_l54 < sawtooth_1); // @[BaseType.scala 305:24]
  assign when_SawToothWaveGenerator_l60 = (sawtooth_1 < _zz_when_SawToothWaveGenerator_l60); // @[BaseType.scala 305:24]
  assign io_output = (_zz_io_output + 16'h8000); // @[SawToothWaveGenerator.scala 68:13]
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
      step <= io_sawtooth_io_step; // @[SawToothWaveGenerator.scala 26:8]
      start <= io_sawtooth_io_start; // @[SawToothWaveGenerator.scala 31:9]
      stop <= io_sawtooth_io_stop; // @[SawToothWaveGenerator.scala 33:8]
      init <= io_sawtooth_io_init; // @[SawToothWaveGenerator.scala 35:8]
      tick <= io_tick; // @[SawToothWaveGenerator.scala 38:8]
      if(when_SawToothWaveGenerator_l40) begin
        isRunning <= 1'b0; // @[SawToothWaveGenerator.scala 41:15]
      end else begin
        if(when_SawToothWaveGenerator_l42) begin
          isRunning <= 1'b1; // @[SawToothWaveGenerator.scala 43:15]
        end else begin
          isRunning <= isRunning; // @[SawToothWaveGenerator.scala 45:15]
        end
      end
      if(init) begin
        sawtooth_1 <= 15'h0; // @[SawToothWaveGenerator.scala 48:14]
      end
      if(when_SawToothWaveGenerator_l51) begin
        if(isRunning) begin
          if(io_sawtooth_io_direction) begin
            if(when_SawToothWaveGenerator_l54) begin
              sawtooth_1 <= 15'h0; // @[SawToothWaveGenerator.scala 55:20]
            end else begin
              sawtooth_1 <= (sawtooth_1 + _zz_sawtooth_1); // @[SawToothWaveGenerator.scala 57:20]
            end
          end else begin
            if(when_SawToothWaveGenerator_l60) begin
              sawtooth_1 <= 15'h7fff; // @[SawToothWaveGenerator.scala 61:20]
            end else begin
              sawtooth_1 <= (sawtooth_1 - _zz_sawtooth_1_1); // @[SawToothWaveGenerator.scala 63:20]
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
