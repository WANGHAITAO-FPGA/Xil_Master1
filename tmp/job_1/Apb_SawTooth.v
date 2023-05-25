// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Apb_SawTooth
// Git hash  : 0fd1febc8346d779f50a61815c7871e1da7e653f

`timescale 1ns/1ps

module Apb_SawTooth (
  input      [7:0]    apb_PADDR,
  input      [0:0]    apb_PSEL,
  input               apb_PENABLE,
  output              apb_PREADY,
  input               apb_PWRITE,
  input      [15:0]   apb_PWDATA,
  output reg [15:0]   apb_PRDATA,
  output              apb_PSLVERROR,
  output              ad5544_CS,
  output              ad5544_LDAC,
  output              ad5544_RS,
  output              ad5544_SCLK,
  output              ad5544_SDIN,
  input               reset,
  input               clk
);

  wire                ad5544_1_analog_trigger;
  wire                ad5544_1_ad5544_CS;
  wire                ad5544_1_ad5544_LDAC;
  wire                ad5544_1_ad5544_RS;
  wire                ad5544_1_ad5544_SCLK;
  wire                ad5544_1_ad5544_SDIN;
  wire                bus_ctrl_readErrorFlag;
  wire                bus_ctrl_writeErrorFlag;
  wire                bus_ctrl_askWrite;
  wire                bus_ctrl_askRead;
  wire                bus_ctrl_doWrite;
  wire                bus_ctrl_doRead;
  reg                 bridge_triger_temp;
  reg        [15:0]   toplevel_ad5544_1_analog_setdata_0_driver;
  reg        [15:0]   toplevel_ad5544_1_analog_setdata_1_driver;
  reg        [15:0]   toplevel_ad5544_1_analog_setdata_2_driver;
  reg        [15:0]   toplevel_ad5544_1_analog_setdata_3_driver;
  reg                 toplevel_ad5544_1_analog_mode_driver;
  reg                 when_SawToothWaveGenerator_l113;
  reg                 bridge_triger_temp_delay_1;
  reg                 bridge_triger_temp_delay_1_1;
  reg                 bridge_triger_temp_delay_2;
  reg                 bridge_triger_temp_delay_1_2;
  reg                 bridge_triger_temp_delay_2_1;
  reg                 bridge_triger_temp_delay_3;
  reg                 toplevel_ad5544_1_sawtooth_io_0_start_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_0_stop_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_0_init_driver;
  reg        [7:0]    toplevel_ad5544_1_sawtooth_io_0_step_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_0_direction_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_1_start_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_1_stop_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_1_init_driver;
  reg        [7:0]    toplevel_ad5544_1_sawtooth_io_1_step_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_1_direction_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_2_start_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_2_stop_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_2_init_driver;
  reg        [7:0]    toplevel_ad5544_1_sawtooth_io_2_step_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_2_direction_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_3_start_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_3_stop_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_3_init_driver;
  reg        [7:0]    toplevel_ad5544_1_sawtooth_io_3_step_driver;
  reg                 toplevel_ad5544_1_sawtooth_io_3_direction_driver;

  SawToothTop ad5544_1 (
    .sawtooth_io_0_direction (toplevel_ad5544_1_sawtooth_io_0_direction_driver), //i
    .sawtooth_io_0_step      (toplevel_ad5544_1_sawtooth_io_0_step_driver[7:0]), //i
    .sawtooth_io_0_start     (toplevel_ad5544_1_sawtooth_io_0_start_driver    ), //i
    .sawtooth_io_0_stop      (toplevel_ad5544_1_sawtooth_io_0_stop_driver     ), //i
    .sawtooth_io_0_init      (toplevel_ad5544_1_sawtooth_io_0_init_driver     ), //i
    .sawtooth_io_1_direction (toplevel_ad5544_1_sawtooth_io_1_direction_driver), //i
    .sawtooth_io_1_step      (toplevel_ad5544_1_sawtooth_io_1_step_driver[7:0]), //i
    .sawtooth_io_1_start     (toplevel_ad5544_1_sawtooth_io_1_start_driver    ), //i
    .sawtooth_io_1_stop      (toplevel_ad5544_1_sawtooth_io_1_stop_driver     ), //i
    .sawtooth_io_1_init      (toplevel_ad5544_1_sawtooth_io_1_init_driver     ), //i
    .sawtooth_io_2_direction (toplevel_ad5544_1_sawtooth_io_2_direction_driver), //i
    .sawtooth_io_2_step      (toplevel_ad5544_1_sawtooth_io_2_step_driver[7:0]), //i
    .sawtooth_io_2_start     (toplevel_ad5544_1_sawtooth_io_2_start_driver    ), //i
    .sawtooth_io_2_stop      (toplevel_ad5544_1_sawtooth_io_2_stop_driver     ), //i
    .sawtooth_io_2_init      (toplevel_ad5544_1_sawtooth_io_2_init_driver     ), //i
    .sawtooth_io_3_direction (toplevel_ad5544_1_sawtooth_io_3_direction_driver), //i
    .sawtooth_io_3_step      (toplevel_ad5544_1_sawtooth_io_3_step_driver[7:0]), //i
    .sawtooth_io_3_start     (toplevel_ad5544_1_sawtooth_io_3_start_driver    ), //i
    .sawtooth_io_3_stop      (toplevel_ad5544_1_sawtooth_io_3_stop_driver     ), //i
    .sawtooth_io_3_init      (toplevel_ad5544_1_sawtooth_io_3_init_driver     ), //i
    .ad5544_CS               (ad5544_1_ad5544_CS                              ), //o
    .ad5544_LDAC             (ad5544_1_ad5544_LDAC                            ), //o
    .ad5544_RS               (ad5544_1_ad5544_RS                              ), //o
    .ad5544_SCLK             (ad5544_1_ad5544_SCLK                            ), //o
    .ad5544_SDIN             (ad5544_1_ad5544_SDIN                            ), //o
    .analog_mode             (toplevel_ad5544_1_analog_mode_driver            ), //i
    .analog_setdata_0        (toplevel_ad5544_1_analog_setdata_0_driver[15:0] ), //i
    .analog_setdata_1        (toplevel_ad5544_1_analog_setdata_1_driver[15:0] ), //i
    .analog_setdata_2        (toplevel_ad5544_1_analog_setdata_2_driver[15:0] ), //i
    .analog_setdata_3        (toplevel_ad5544_1_analog_setdata_3_driver[15:0] ), //i
    .analog_trigger          (ad5544_1_analog_trigger                         ), //i
    .reset                   (reset                                           ), //i
    .clk                     (clk                                             )  //i
  );
  assign bus_ctrl_readErrorFlag = 1'b0; // @[BusSlaveFactory.scala 105:29]
  assign bus_ctrl_writeErrorFlag = 1'b0; // @[BusSlaveFactory.scala 106:30]
  assign apb_PREADY = 1'b1; // @[Apb3SlaveFactory.scala 38:14]
  always @(*) begin
    apb_PRDATA = 16'h0; // @[Apb3SlaveFactory.scala 39:68]
    case(apb_PADDR)
      8'h0 : begin
        apb_PRDATA[15 : 0] = toplevel_ad5544_1_analog_setdata_0_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h04 : begin
        apb_PRDATA[15 : 0] = toplevel_ad5544_1_analog_setdata_1_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h08 : begin
        apb_PRDATA[15 : 0] = toplevel_ad5544_1_analog_setdata_2_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h0c : begin
        apb_PRDATA[15 : 0] = toplevel_ad5544_1_analog_setdata_3_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h10 : begin
        apb_PRDATA[0 : 0] = bridge_triger_temp; // @[BusSlaveFactory.scala 942:69]
      end
      8'h14 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_analog_mode_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h18 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_0_start_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[4 : 4] = toplevel_ad5544_1_sawtooth_io_0_stop_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[8 : 8] = toplevel_ad5544_1_sawtooth_io_0_init_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h1c : begin
        apb_PRDATA[7 : 0] = toplevel_ad5544_1_sawtooth_io_0_step_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h20 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_0_direction_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h24 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_1_start_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[4 : 4] = toplevel_ad5544_1_sawtooth_io_1_stop_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[8 : 8] = toplevel_ad5544_1_sawtooth_io_1_init_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h28 : begin
        apb_PRDATA[7 : 0] = toplevel_ad5544_1_sawtooth_io_1_step_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h2c : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_1_direction_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h30 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_2_start_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[4 : 4] = toplevel_ad5544_1_sawtooth_io_2_stop_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[8 : 8] = toplevel_ad5544_1_sawtooth_io_2_init_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h34 : begin
        apb_PRDATA[7 : 0] = toplevel_ad5544_1_sawtooth_io_2_step_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h38 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_2_direction_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h3c : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_3_start_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[4 : 4] = toplevel_ad5544_1_sawtooth_io_3_stop_driver; // @[BusSlaveFactory.scala 942:69]
        apb_PRDATA[8 : 8] = toplevel_ad5544_1_sawtooth_io_3_init_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h40 : begin
        apb_PRDATA[7 : 0] = toplevel_ad5544_1_sawtooth_io_3_step_driver; // @[BusSlaveFactory.scala 942:69]
      end
      8'h44 : begin
        apb_PRDATA[0 : 0] = toplevel_ad5544_1_sawtooth_io_3_direction_driver; // @[BusSlaveFactory.scala 942:69]
      end
      default : begin
      end
    endcase
  end

  assign bus_ctrl_askWrite = ((apb_PSEL[0] && apb_PENABLE) && apb_PWRITE); // @[BaseType.scala 305:24]
  assign bus_ctrl_askRead = ((apb_PSEL[0] && apb_PENABLE) && (! apb_PWRITE)); // @[BaseType.scala 305:24]
  assign bus_ctrl_doWrite = (((apb_PSEL[0] && apb_PENABLE) && apb_PREADY) && apb_PWRITE); // @[BaseType.scala 305:24]
  assign bus_ctrl_doRead = (((apb_PSEL[0] && apb_PENABLE) && apb_PREADY) && (! apb_PWRITE)); // @[BaseType.scala 305:24]
  assign apb_PSLVERROR = ((bus_ctrl_doWrite && bus_ctrl_writeErrorFlag) || (bus_ctrl_doRead && bus_ctrl_readErrorFlag)); // @[Apb3SlaveFactory.scala 46:47]
  assign ad5544_CS = ad5544_1_ad5544_CS; // @[SawToothWaveGenerator.scala 170:20]
  assign ad5544_LDAC = ad5544_1_ad5544_LDAC; // @[SawToothWaveGenerator.scala 170:20]
  assign ad5544_RS = ad5544_1_ad5544_RS; // @[SawToothWaveGenerator.scala 170:20]
  assign ad5544_SCLK = ad5544_1_ad5544_SCLK; // @[SawToothWaveGenerator.scala 170:20]
  assign ad5544_SDIN = ad5544_1_ad5544_SDIN; // @[SawToothWaveGenerator.scala 170:20]
  always @(*) begin
    when_SawToothWaveGenerator_l113 = 1'b0; // @[BusSlaveFactory.scala 204:15]
    case(apb_PADDR)
      8'h10 : begin
        if(bus_ctrl_doWrite) begin
          when_SawToothWaveGenerator_l113 = 1'b1; // @[BusSlaveFactory.scala 205:27]
        end
      end
      default : begin
      end
    endcase
  end

  assign ad5544_1_analog_trigger = (((bridge_triger_temp || bridge_triger_temp_delay_1) || bridge_triger_temp_delay_2) || bridge_triger_temp_delay_3); // @[SawToothWaveGenerator.scala 118:22]
  always @(posedge clk) begin
    if(when_SawToothWaveGenerator_l113) begin
      bridge_triger_temp <= 1'b1; // @[SawToothWaveGenerator.scala 114:21]
    end else begin
      bridge_triger_temp <= 1'b0; // @[SawToothWaveGenerator.scala 116:21]
    end
    case(apb_PADDR)
      8'h0 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_analog_setdata_0_driver <= apb_PWDATA[15 : 0]; // @[Bits.scala 133:56]
        end
      end
      8'h04 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_analog_setdata_1_driver <= apb_PWDATA[15 : 0]; // @[Bits.scala 133:56]
        end
      end
      8'h08 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_analog_setdata_2_driver <= apb_PWDATA[15 : 0]; // @[Bits.scala 133:56]
        end
      end
      8'h0c : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_analog_setdata_3_driver <= apb_PWDATA[15 : 0]; // @[Bits.scala 133:56]
        end
      end
      8'h14 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_analog_mode_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
        end
      end
      8'h18 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_0_start_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_0_stop_driver <= apb_PWDATA[4]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_0_init_driver <= apb_PWDATA[8]; // @[Bool.scala 189:10]
        end
      end
      8'h1c : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_0_step_driver <= apb_PWDATA[7 : 0]; // @[UInt.scala 381:56]
        end
      end
      8'h20 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_0_direction_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
        end
      end
      8'h24 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_1_start_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_1_stop_driver <= apb_PWDATA[4]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_1_init_driver <= apb_PWDATA[8]; // @[Bool.scala 189:10]
        end
      end
      8'h28 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_1_step_driver <= apb_PWDATA[7 : 0]; // @[UInt.scala 381:56]
        end
      end
      8'h2c : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_1_direction_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
        end
      end
      8'h30 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_2_start_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_2_stop_driver <= apb_PWDATA[4]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_2_init_driver <= apb_PWDATA[8]; // @[Bool.scala 189:10]
        end
      end
      8'h34 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_2_step_driver <= apb_PWDATA[7 : 0]; // @[UInt.scala 381:56]
        end
      end
      8'h38 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_2_direction_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
        end
      end
      8'h3c : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_3_start_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_3_stop_driver <= apb_PWDATA[4]; // @[Bool.scala 189:10]
          toplevel_ad5544_1_sawtooth_io_3_init_driver <= apb_PWDATA[8]; // @[Bool.scala 189:10]
        end
      end
      8'h40 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_3_step_driver <= apb_PWDATA[7 : 0]; // @[UInt.scala 381:56]
        end
      end
      8'h44 : begin
        if(bus_ctrl_doWrite) begin
          toplevel_ad5544_1_sawtooth_io_3_direction_driver <= apb_PWDATA[0]; // @[Bool.scala 189:10]
        end
      end
      default : begin
      end
    endcase
  end

  always @(posedge clk or posedge reset) begin
    if(reset) begin
      bridge_triger_temp_delay_1 <= 1'b0; // @[Data.scala 400:33]
      bridge_triger_temp_delay_1_1 <= 1'b0; // @[Data.scala 400:33]
      bridge_triger_temp_delay_2 <= 1'b0; // @[Data.scala 400:33]
      bridge_triger_temp_delay_1_2 <= 1'b0; // @[Data.scala 400:33]
      bridge_triger_temp_delay_2_1 <= 1'b0; // @[Data.scala 400:33]
      bridge_triger_temp_delay_3 <= 1'b0; // @[Data.scala 400:33]
    end else begin
      bridge_triger_temp_delay_1 <= bridge_triger_temp; // @[Reg.scala 39:30]
      bridge_triger_temp_delay_1_1 <= bridge_triger_temp; // @[Reg.scala 39:30]
      bridge_triger_temp_delay_2 <= bridge_triger_temp_delay_1_1; // @[Reg.scala 39:30]
      bridge_triger_temp_delay_1_2 <= bridge_triger_temp; // @[Reg.scala 39:30]
      bridge_triger_temp_delay_2_1 <= bridge_triger_temp_delay_1_2; // @[Reg.scala 39:30]
      bridge_triger_temp_delay_3 <= bridge_triger_temp_delay_2_1; // @[Reg.scala 39:30]
    end
  end


endmodule

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
