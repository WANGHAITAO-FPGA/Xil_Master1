// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : FullStep

`timescale 1ns/1ps

module FullStep (
  output     [15:0]   c_data,
  output     [15:0]   d1_data,
  input               clk,
  input               reset
);

  reg        [15:0]   _zz_c_rom_port0;
  reg        [15:0]   _zz_d1_rom_port0;
  wire                _zz_c_rom_port;
  wire                _zz_c_data;
  wire                _zz_d1_rom_port;
  wire                _zz_d1_data;
  wire       [15:0]   Sample;
  reg        [8:0]    i;
  wire                when_FullStep_l57;
  reg [15:0] c_rom [0:357];
  reg [15:0] d1_rom [0:357];

  assign _zz_c_data = 1'b1;
  assign _zz_d1_data = 1'b1;
  initial begin
    $readmemb("FullStep.v_toplevel_c_rom.bin",c_rom);
  end
  always @(posedge clk) begin
    if(_zz_c_data) begin
      _zz_c_rom_port0 <= c_rom[i];
    end
  end

  initial begin
    $readmemb("FullStep.v_toplevel_d1_rom.bin",d1_rom);
  end
  always @(posedge clk) begin
    if(_zz_d1_data) begin
      _zz_d1_rom_port0 <= d1_rom[i];
    end
  end

  assign when_FullStep_l57 = (i < 9'h165); // @[BaseType.scala 305:24]
  assign c_data = _zz_c_rom_port0; // @[FullStep.scala 63:13]
  assign d1_data = _zz_d1_rom_port0; // @[FullStep.scala 64:14]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      i <= 9'h0; // @[Data.scala 400:33]
    end else begin
      if(when_FullStep_l57) begin
        i <= (i + 9'h001); // @[FullStep.scala 58:7]
      end else begin
        i <= 9'h0; // @[FullStep.scala 60:7]
      end
    end
  end


endmodule
