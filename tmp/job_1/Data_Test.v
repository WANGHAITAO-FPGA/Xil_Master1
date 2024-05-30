// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Data_Test
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module Data_Test (
  output reg [63:0]   data_out_0,
  output reg [63:0]   data_out_1,
  output reg [63:0]   data_out_2,
  output reg [63:0]   data_out_3,
  output reg [63:0]   data_out_4,
  output reg [63:0]   data_out_5,
  output reg [63:0]   data_out_6,
  output reg [63:0]   data_out_7,
  input               busy,
  input               clk,
  input               reset
);

  reg                 timer_1_io_clear;
  wire                timer_1_io_full;
  wire       [31:0]   timer_1_io_value;
  wire       [63:0]   _zz_data_out_0_1;
  wire       [63:0]   _zz_data_out_1_1;
  wire       [63:0]   _zz_data_out_2_1;
  wire       [63:0]   _zz_data_out_3_1;
  wire       [63:0]   _zz_data_out_4_1;
  wire       [63:0]   _zz_data_out_5_1;
  wire       [63:0]   _zz_data_out_6_1;
  wire       [63:0]   _zz_data_out_7_1;
  wire                when_Srio_Test_Top_l288;
  reg        [63:0]   data_out_0_1;
  reg        [63:0]   data_out_1_1;
  reg        [63:0]   data_out_2_1;
  reg        [63:0]   data_out_3_1;
  reg        [63:0]   data_out_4_1;
  reg        [63:0]   data_out_5_1;
  reg        [63:0]   data_out_6_1;
  reg        [63:0]   data_out_7_1;
  reg                 toplevel_timer_1_io_full_regNext;
  wire                when_Srio_Test_Top_l296;
  wire                when_Srio_Test_Top_l301;

  assign _zz_data_out_0_1 = (data_out_0_1 + 64'h00000000000003e8);
  assign _zz_data_out_1_1 = (data_out_1_1 + 64'h00000000000003e8);
  assign _zz_data_out_2_1 = (data_out_2_1 + 64'h00000000000003e8);
  assign _zz_data_out_3_1 = (data_out_3_1 + 64'h00000000000003e8);
  assign _zz_data_out_4_1 = (data_out_4_1 + 64'h00000000000003e8);
  assign _zz_data_out_5_1 = (data_out_5_1 + 64'h00000000000003e8);
  assign _zz_data_out_6_1 = (data_out_6_1 + 64'h00000000000003e8);
  assign _zz_data_out_7_1 = (data_out_7_1 + 64'h00000000000003e8);
  Timer timer_1 (
    .io_tick  (1'b1                  ), //i
    .io_clear (timer_1_io_clear      ), //i
    .io_limit (32'h002faf08          ), //i
    .io_full  (timer_1_io_full       ), //o
    .io_value (timer_1_io_value[31:0]), //o
    .clk      (clk                   ), //i
    .reset    (reset                 )  //i
  );
  assign when_Srio_Test_Top_l288 = (32'h002faf08 <= timer_1_io_value); // @[BaseType.scala 305:24]
  always @(*) begin
    if(when_Srio_Test_Top_l288) begin
      timer_1_io_clear = 1'b1; // @[Srio_Test_Top.scala 289:20]
    end else begin
      timer_1_io_clear = 1'b0; // @[Srio_Test_Top.scala 291:20]
    end
  end

  assign when_Srio_Test_Top_l296 = (timer_1_io_full && (! toplevel_timer_1_io_full_regNext)); // @[BaseType.scala 305:24]
  assign when_Srio_Test_Top_l301 = (! busy); // @[BaseType.scala 299:24]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      data_out_0_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_1_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_2_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_3_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_4_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_5_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_6_1 <= 64'h0; // @[Data.scala 400:33]
      data_out_7_1 <= 64'h0; // @[Data.scala 400:33]
    end else begin
      if(when_Srio_Test_Top_l296) begin
        data_out_0_1 <= _zz_data_out_0_1; // @[Srio_Test_Top.scala 298:19]
        data_out_1_1 <= _zz_data_out_1_1; // @[Srio_Test_Top.scala 298:19]
        data_out_2_1 <= _zz_data_out_2_1; // @[Srio_Test_Top.scala 298:19]
        data_out_3_1 <= _zz_data_out_3_1; // @[Srio_Test_Top.scala 298:19]
        data_out_4_1 <= _zz_data_out_4_1; // @[Srio_Test_Top.scala 298:19]
        data_out_5_1 <= _zz_data_out_5_1; // @[Srio_Test_Top.scala 298:19]
        data_out_6_1 <= _zz_data_out_6_1; // @[Srio_Test_Top.scala 298:19]
        data_out_7_1 <= _zz_data_out_7_1; // @[Srio_Test_Top.scala 298:19]
      end
    end
  end

  always @(posedge clk) begin
    toplevel_timer_1_io_full_regNext <= timer_1_io_full; // @[Reg.scala 39:30]
    if(when_Srio_Test_Top_l301) begin
      data_out_0 <= data_out_0_1; // @[Srio_Test_Top.scala 303:22]
      data_out_1 <= data_out_1_1; // @[Srio_Test_Top.scala 303:22]
      data_out_2 <= data_out_2_1; // @[Srio_Test_Top.scala 303:22]
      data_out_3 <= data_out_3_1; // @[Srio_Test_Top.scala 303:22]
      data_out_4 <= data_out_4_1; // @[Srio_Test_Top.scala 303:22]
      data_out_5 <= data_out_5_1; // @[Srio_Test_Top.scala 303:22]
      data_out_6 <= data_out_6_1; // @[Srio_Test_Top.scala 303:22]
      data_out_7 <= data_out_7_1; // @[Srio_Test_Top.scala 303:22]
    end
  end


endmodule

module Timer (
  input               io_tick,
  input               io_clear,
  input      [31:0]   io_limit,
  output              io_full,
  output     [31:0]   io_value,
  input               clk,
  input               reset
);

  wire       [31:0]   _zz_counter;
  wire       [0:0]    _zz_counter_1;
  reg        [31:0]   counter;
  wire                limitHit;
  reg                 inhibitFull;

  assign _zz_counter_1 = (! limitHit);
  assign _zz_counter = {31'd0, _zz_counter_1};
  assign limitHit = (counter == io_limit); // @[BaseType.scala 305:24]
  assign io_full = ((limitHit && io_tick) && (! inhibitFull)); // @[Timer.scala 27:12]
  assign io_value = counter; // @[Timer.scala 28:12]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      inhibitFull <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(io_tick) begin
        inhibitFull <= limitHit; // @[Timer.scala 20:17]
      end
      if(io_clear) begin
        inhibitFull <= 1'b0; // @[Timer.scala 25:17]
      end
    end
  end

  always @(posedge clk) begin
    if(io_tick) begin
      counter <= (counter + _zz_counter); // @[Timer.scala 21:13]
    end
    if(io_clear) begin
      counter <= 32'h0; // @[Timer.scala 24:13]
    end
  end


endmodule
