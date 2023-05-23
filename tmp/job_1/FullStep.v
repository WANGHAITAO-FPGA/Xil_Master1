// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : FullStep

`timescale 1ns/1ps

module FullStep (
  output     [15:0]   c_data,
  output     [15:0]   d1_data,
  output     [15:0]   d2_data,
  input               clk,
  input               reset
);

  reg        [15:0]   _zz_c_rom_port0;
  reg        [15:0]   _zz_d1_rom_port0;
  reg        [15:0]   _zz_d1_rom_port1;
  wire                _zz_c_rom_port;
  wire                _zz_c_data;
  wire                _zz_d1_rom_port;
  wire                _zz_d1_data;
  wire                _zz_d1_rom_port_1;
  wire       [16:0]   _zz_d2_data;
  wire       [16:0]   _zz_d2_data_1;
  wire       [15:0]   _zz_d2_data_2;
  wire                _zz_d2_data_3;
  wire       [0:0]    _zz_d2_data_4;
  wire       [15:0]   Sample;
  reg        [8:0]    i;
  wire                when_FullStep_l70;
  reg [15:0] c_rom [0:351];
  reg [15:0] d1_rom [0:351];

  assign _zz_d2_data = _zz_d2_data_1;
  assign _zz_d2_data_1 = ($signed(_zz_d2_data_2) * $signed(_zz_d2_data_4));
  assign _zz_d2_data_2 = _zz_d1_rom_port1;
  assign _zz_d2_data_4 = 1'b1;
  assign _zz_c_data = 1'b1;
  assign _zz_d1_data = 1'b1;
  assign _zz_d2_data_3 = 1'b1;
  initial begin
    $readmemb("D:\\SCALA\\Xil_Master\\tmp\\job_1\\FullStep.v_toplevel_c_rom.bin",c_rom);
  end
  always @(posedge clk) begin
    if(_zz_c_data) begin
      _zz_c_rom_port0 <= c_rom[i];
    end
  end

  initial begin
    $readmemb("D:\\SCALA\\Xil_Master\\tmp\\job_1\\FullStep.v_toplevel_d1_rom.bin",d1_rom);
  end
  always @(posedge clk) begin
    if(_zz_d1_data) begin
      _zz_d1_rom_port0 <= d1_rom[i];
    end
  end

  always @(posedge clk) begin
    if(_zz_d2_data_3) begin
      _zz_d1_rom_port1 <= d1_rom[i];
    end
  end

  assign when_FullStep_l70 = (i < 9'h15f); // @[BaseType.scala 305:24]
  assign c_data = _zz_c_rom_port0; // @[FullStep.scala 75:13]
  assign d1_data = _zz_d1_rom_port0; // @[FullStep.scala 76:14]
  assign d2_data = _zz_d2_data[15:0]; // @[FullStep.scala 77:14]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      i <= 9'h0; // @[Data.scala 400:33]
    end else begin
      if(when_FullStep_l70) begin
        i <= (i + 9'h001); // @[FullStep.scala 71:7]
      end else begin
        i <= 9'h0; // @[FullStep.scala 73:7]
      end
    end
  end


endmodule
