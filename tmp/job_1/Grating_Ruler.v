// Generator : SpinalHDL v1.7.3    git head : aeaeece704fe43c766e0d36a93f2ecbb8a9f2003
// Component : Grating_Ruler

`timescale 1ns/1ps

module Grating_Ruler (
  input               config_valid,
  input      [1:0]    config_payload_mode,
  input               grating_io_IO_A_READ,
  output              grating_io_IO_A_WRITE,
  output              grating_io_IO_A_WRITEENABLE,
  input               grating_io_IO_B_READ,
  output              grating_io_IO_B_WRITE,
  output              grating_io_IO_B_WRITEENABLE,
  input               grating_io_IO_C_READ,
  output              grating_io_IO_C_WRITE,
  output              grating_io_IO_C_WRITEENABLE,
  input               bissc_clk,
  output              bissc_data,
  output              encoder_aphase,
  output              encoder_bphase,
  output              encoder_iphase,
  input               endat_clk,
  output              endat_read,
  input               endat_write,
  input               endat_writeEnable
);
  localparam Grating_Type_BISSC = 2'd0;
  localparam Grating_Type_ENCODER = 2'd1;
  localparam Grating_Type_ENDAT = 2'd2;

  `ifndef SYNTHESIS
  reg [55:0] config_payload_mode_string;
  `endif


  `ifndef SYNTHESIS
  always @(*) begin
    case(config_payload_mode)
      Grating_Type_BISSC : config_payload_mode_string = "BISSC  ";
      Grating_Type_ENCODER : config_payload_mode_string = "ENCODER";
      Grating_Type_ENDAT : config_payload_mode_string = "ENDAT  ";
      default : config_payload_mode_string = "???????";
    endcase
  end
  `endif

  assign grating_io_IO_A_WRITE = ((config_payload_mode == Grating_Type_BISSC) ? bissc_clk : ((config_payload_mode == Grating_Type_ENDAT) ? endat_clk : 1'b0));
  assign grating_io_IO_A_WRITEENABLE = (((config_payload_mode == Grating_Type_BISSC) || (config_payload_mode == Grating_Type_ENDAT)) ? 1'b1 : 1'b0);
  assign grating_io_IO_B_WRITE = endat_write;
  assign grating_io_IO_B_WRITEENABLE = (((config_payload_mode == Grating_Type_BISSC) || (config_payload_mode == Grating_Type_ENCODER)) ? 1'b0 : endat_writeEnable);
  assign bissc_data = ((config_payload_mode == Grating_Type_BISSC) ? grating_io_IO_B_READ : 1'b0);
  assign encoder_aphase = ((config_payload_mode == Grating_Type_ENCODER) ? grating_io_IO_A_READ : 1'b0);
  assign encoder_bphase = ((config_payload_mode == Grating_Type_ENCODER) ? grating_io_IO_B_READ : 1'b0);
  assign endat_read = ((config_payload_mode == Grating_Type_ENDAT) ? grating_io_IO_B_READ : 1'b0);
  assign grating_io_IO_C_WRITE = 1'b0;
  assign grating_io_IO_C_WRITEENABLE = 1'b0;
  assign encoder_iphase = grating_io_IO_C_READ;

endmodule
