// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : srio_tt
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module srio_tt (
  input               srio_clk,
  input               reset,
  output              iresp_stream_valid,
  input               iresp_stream_ready,
  output     [63:0]   iresp_stream_payload
);
  localparam SrioFtype_NREAD = 4'd2;
  localparam SrioFtype_NWRITE = 4'd5;
  localparam SrioFtype_SWRITE = 4'd6;
  localparam SrioFtype_DOORB = 4'd10;
  localparam SrioFtype_MESSG = 4'd11;
  localparam SrioFtype_RESP = 4'd13;
  localparam SrioFtype_FTYPE9 = 4'd9;
  localparam SrioTtype_TNWR = 4'd4;
  localparam SrioTtype_TNWR_R = 4'd5;
  localparam SrioTtype_TNDATA = 4'd0;
  localparam SrioTtype_TWDATA = 4'd8;

  wire                srio_area_srio_top_m_axis_ireq_tvalid;
  wire                srio_area_srio_top_m_axis_ireq_tlast;
  wire       [63:0]   srio_area_srio_top_m_axis_ireq_tdata;
  wire       [7:0]    srio_area_srio_top_m_axis_ireq_tkeep;
  wire       [31:0]   srio_area_srio_top_m_axis_ireq_tuser;
  wire                srio_area_srio_top_s_axis_iresp_tready;
  wire                srio_area_srio_top_m_axis_tresp_tvalid;
  wire                srio_area_srio_top_m_axis_tresp_tlast;
  wire       [63:0]   srio_area_srio_top_m_axis_tresp_tdata;
  wire       [7:0]    srio_area_srio_top_m_axis_tresp_tkeep;
  wire       [31:0]   srio_area_srio_top_m_axis_tresp_tuser;
  wire                srio_area_srio_top_s_axis_treq_tready;
  wire                srio_area_srio_top_s_axis_usercmd_tready;
  wire                srio_area_srio_top_m_axis_rspstream_tvalid;
  wire       [63:0]   srio_area_srio_top_m_axis_rspstream_tdata;
  wire       [63:0]   srio_area_srio_top_data_out_0;
  wire       [63:0]   srio_area_srio_top_data_out_1;
  wire       [63:0]   srio_area_srio_top_data_out_2;
  wire       [63:0]   srio_area_srio_top_data_out_3;
  wire       [63:0]   srio_area_srio_top_data_out_4;
  wire       [63:0]   srio_area_srio_top_data_out_5;
  wire       [63:0]   srio_area_srio_top_data_out_6;
  wire       [63:0]   srio_area_srio_top_data_out_7;
  wire       [63:0]   srio_area_srio_top_data_out_8;
  wire       [63:0]   srio_area_srio_top_data_out_9;
  wire       [63:0]   srio_area_srio_top_data_out_10;
  wire       [63:0]   srio_area_srio_top_data_out_11;
  wire       [63:0]   srio_area_srio_top_data_out_12;
  wire       [63:0]   srio_area_srio_top_data_out_13;
  wire       [63:0]   srio_area_srio_top_data_out_14;
  wire       [63:0]   srio_area_srio_top_data_out_15;
  wire                srio_area_srio_top_busy;
  wire       [15:0]   srio_area_srio_top_doorbell_info;
  wire                srio_area_srio_top_doorbell_intr;
  wire       [33:0]   srio_area_srio_test_usercmd_user_addr;
  wire       [3:0]    srio_area_srio_test_usercmd_user_ftype;
  wire       [3:0]    srio_area_srio_test_usercmd_user_ttype;
  wire       [7:0]    srio_area_srio_test_usercmd_user_size;
  wire       [1:0]    srio_area_srio_test_usercmd_user_prio;
  wire       [7:0]    srio_area_srio_test_usercmd_user_tid;
  wire                srio_area_srio_test_m_axis_usercmd_tvalid;
  wire       [63:0]   srio_area_srio_test_m_axis_usercmd_tdata;
  wire                srio_area_srio_test_send_start;

  Srio_Top srio_area_srio_top (
    .srio_clk                (srio_clk                                       ), //i
    .reset                   (reset                                          ), //i
    .m_axis_ireq_tvalid      (srio_area_srio_top_m_axis_ireq_tvalid          ), //o
    .m_axis_ireq_tready      (srio_area_srio_top_s_axis_treq_tready          ), //i
    .m_axis_ireq_tlast       (srio_area_srio_top_m_axis_ireq_tlast           ), //o
    .m_axis_ireq_tdata       (srio_area_srio_top_m_axis_ireq_tdata[63:0]     ), //o
    .m_axis_ireq_tkeep       (srio_area_srio_top_m_axis_ireq_tkeep[7:0]      ), //o
    .m_axis_ireq_tuser       (srio_area_srio_top_m_axis_ireq_tuser[31:0]     ), //o
    .s_axis_iresp_tvalid     (srio_area_srio_top_m_axis_tresp_tvalid         ), //i
    .s_axis_iresp_tready     (srio_area_srio_top_s_axis_iresp_tready         ), //o
    .s_axis_iresp_tlast      (srio_area_srio_top_m_axis_tresp_tlast          ), //i
    .s_axis_iresp_tdata      (srio_area_srio_top_m_axis_tresp_tdata[63:0]    ), //i
    .s_axis_iresp_tkeep      (srio_area_srio_top_m_axis_tresp_tkeep[7:0]     ), //i
    .s_axis_iresp_tuser      (srio_area_srio_top_m_axis_tresp_tuser[31:0]    ), //i
    .m_axis_tresp_tvalid     (srio_area_srio_top_m_axis_tresp_tvalid         ), //o
    .m_axis_tresp_tready     (srio_area_srio_top_s_axis_iresp_tready         ), //i
    .m_axis_tresp_tlast      (srio_area_srio_top_m_axis_tresp_tlast          ), //o
    .m_axis_tresp_tdata      (srio_area_srio_top_m_axis_tresp_tdata[63:0]    ), //o
    .m_axis_tresp_tkeep      (srio_area_srio_top_m_axis_tresp_tkeep[7:0]     ), //o
    .m_axis_tresp_tuser      (srio_area_srio_top_m_axis_tresp_tuser[31:0]    ), //o
    .s_axis_treq_tvalid      (srio_area_srio_top_m_axis_ireq_tvalid          ), //i
    .s_axis_treq_tready      (srio_area_srio_top_s_axis_treq_tready          ), //o
    .s_axis_treq_tlast       (srio_area_srio_top_m_axis_ireq_tlast           ), //i
    .s_axis_treq_tdata       (srio_area_srio_top_m_axis_ireq_tdata[63:0]     ), //i
    .s_axis_treq_tkeep       (srio_area_srio_top_m_axis_ireq_tkeep[7:0]      ), //i
    .s_axis_treq_tuser       (srio_area_srio_top_m_axis_ireq_tuser[31:0]     ), //i
    .usercmd_user_addr       (srio_area_srio_test_usercmd_user_addr[33:0]    ), //i
    .usercmd_user_ftype      (srio_area_srio_test_usercmd_user_ftype[3:0]    ), //i
    .usercmd_user_ttype      (srio_area_srio_test_usercmd_user_ttype[3:0]    ), //i
    .usercmd_user_size       (srio_area_srio_test_usercmd_user_size[7:0]     ), //i
    .usercmd_user_prio       (srio_area_srio_test_usercmd_user_prio[1:0]     ), //i
    .usercmd_user_tid        (srio_area_srio_test_usercmd_user_tid[7:0]      ), //i
    .s_axis_usercmd_tvalid   (srio_area_srio_test_m_axis_usercmd_tvalid      ), //i
    .s_axis_usercmd_tready   (srio_area_srio_top_s_axis_usercmd_tready       ), //o
    .s_axis_usercmd_tdata    (srio_area_srio_test_m_axis_usercmd_tdata[63:0] ), //i
    .send_start              (srio_area_srio_test_send_start                 ), //i
    .m_axis_rspstream_tvalid (srio_area_srio_top_m_axis_rspstream_tvalid     ), //o
    .m_axis_rspstream_tready (iresp_stream_ready                             ), //i
    .m_axis_rspstream_tdata  (srio_area_srio_top_m_axis_rspstream_tdata[63:0]), //o
    .data_in_0               (64'h0000000000002710                           ), //i
    .data_in_1               (64'h0000000000004e20                           ), //i
    .data_in_2               (64'h0000000000004e2a                           ), //i
    .data_in_3               (64'h0000000000007530                           ), //i
    .data_in_4               (64'h0000000000009c40                           ), //i
    .data_in_5               (64'h000000000000c350                           ), //i
    .data_in_6               (64'h000000000000ea60                           ), //i
    .data_in_7               (64'h0000000000011170                           ), //i
    .data_in_8               (64'h0000000000013880                           ), //i
    .data_in_9               (64'h0                                          ), //i
    .data_in_10              (64'h0                                          ), //i
    .data_in_11              (64'h0                                          ), //i
    .data_in_12              (64'h0                                          ), //i
    .data_in_13              (64'h0                                          ), //i
    .data_in_14              (64'h0                                          ), //i
    .data_in_15              (64'h0                                          ), //i
    .data_out_0              (srio_area_srio_top_data_out_0[63:0]            ), //o
    .data_out_1              (srio_area_srio_top_data_out_1[63:0]            ), //o
    .data_out_2              (srio_area_srio_top_data_out_2[63:0]            ), //o
    .data_out_3              (srio_area_srio_top_data_out_3[63:0]            ), //o
    .data_out_4              (srio_area_srio_top_data_out_4[63:0]            ), //o
    .data_out_5              (srio_area_srio_top_data_out_5[63:0]            ), //o
    .data_out_6              (srio_area_srio_top_data_out_6[63:0]            ), //o
    .data_out_7              (srio_area_srio_top_data_out_7[63:0]            ), //o
    .data_out_8              (srio_area_srio_top_data_out_8[63:0]            ), //o
    .data_out_9              (srio_area_srio_top_data_out_9[63:0]            ), //o
    .data_out_10             (srio_area_srio_top_data_out_10[63:0]           ), //o
    .data_out_11             (srio_area_srio_top_data_out_11[63:0]           ), //o
    .data_out_12             (srio_area_srio_top_data_out_12[63:0]           ), //o
    .data_out_13             (srio_area_srio_top_data_out_13[63:0]           ), //o
    .data_out_14             (srio_area_srio_top_data_out_14[63:0]           ), //o
    .data_out_15             (srio_area_srio_top_data_out_15[63:0]           ), //o
    .busy                    (srio_area_srio_top_busy                        ), //o
    .doorbell_info           (srio_area_srio_top_doorbell_info[15:0]         ), //o
    .doorbell_intr           (srio_area_srio_top_doorbell_intr               )  //o
  );
  Srio_Test srio_area_srio_test (
    .srio_clk              (srio_clk                                      ), //i
    .reset                 (reset                                         ), //i
    .usercmd_user_addr     (srio_area_srio_test_usercmd_user_addr[33:0]   ), //o
    .usercmd_user_ftype    (srio_area_srio_test_usercmd_user_ftype[3:0]   ), //o
    .usercmd_user_ttype    (srio_area_srio_test_usercmd_user_ttype[3:0]   ), //o
    .usercmd_user_size     (srio_area_srio_test_usercmd_user_size[7:0]    ), //o
    .usercmd_user_prio     (srio_area_srio_test_usercmd_user_prio[1:0]    ), //o
    .usercmd_user_tid      (srio_area_srio_test_usercmd_user_tid[7:0]     ), //o
    .m_axis_usercmd_tvalid (srio_area_srio_test_m_axis_usercmd_tvalid     ), //o
    .m_axis_usercmd_tready (srio_area_srio_top_s_axis_usercmd_tready      ), //i
    .m_axis_usercmd_tdata  (srio_area_srio_test_m_axis_usercmd_tdata[63:0]), //o
    .send_start            (srio_area_srio_test_send_start                )  //o
  );
  assign iresp_stream_valid = srio_area_srio_top_m_axis_rspstream_tvalid; // @[Srio_Test_Top.scala 278:30]
  assign iresp_stream_payload = srio_area_srio_top_m_axis_rspstream_tdata; // @[Srio_Test_Top.scala 278:30]

endmodule

module Srio_Test (
  input               srio_clk,
  input               reset,
  output     [33:0]   usercmd_user_addr,
  output     [3:0]    usercmd_user_ftype,
  output     [3:0]    usercmd_user_ttype,
  output     [7:0]    usercmd_user_size,
  output     [1:0]    usercmd_user_prio,
  output     [7:0]    usercmd_user_tid,
  output              m_axis_usercmd_tvalid,
  input               m_axis_usercmd_tready,
  output     [63:0]   m_axis_usercmd_tdata,
  output              send_start
);
  localparam SrioFtype_NREAD = 4'd2;
  localparam SrioFtype_NWRITE = 4'd5;
  localparam SrioFtype_SWRITE = 4'd6;
  localparam SrioFtype_DOORB = 4'd10;
  localparam SrioFtype_MESSG = 4'd11;
  localparam SrioFtype_RESP = 4'd13;
  localparam SrioFtype_FTYPE9 = 4'd9;
  localparam SrioTtype_TNWR = 4'd4;
  localparam SrioTtype_TNWR_R = 4'd5;
  localparam SrioTtype_TNDATA = 4'd0;
  localparam SrioTtype_TWDATA = 4'd8;
  localparam srio_area_fsm_enumDef_BOOT = 4'd0;
  localparam srio_area_fsm_enumDef_Init_Start = 4'd1;
  localparam srio_area_fsm_enumDef_Send_Read = 4'd2;
  localparam srio_area_fsm_enumDef_DoorBeel = 4'd3;
  localparam srio_area_fsm_enumDef_Send_DoorBeel = 4'd4;
  localparam srio_area_fsm_enumDef_Nwrite = 4'd5;
  localparam srio_area_fsm_enumDef_Send_Data = 4'd6;
  localparam srio_area_fsm_enumDef_Send_Stream = 4'd7;
  localparam srio_area_fsm_enumDef_Send_Nwrite = 4'd8;

  reg                 srio_area_timer_io_clear;
  wire                srio_area_timer_io_full;
  wire       [31:0]   srio_area_timer_io_value;
  wire       [63:0]   _zz_srio_area_user_data;
  wire                when_Srio_Test_Top_l103;
  reg        [33:0]   srio_area_user_addr;
  reg        [3:0]    srio_area_user_ftype;
  reg        [3:0]    srio_area_user_ttype;
  reg        [7:0]    srio_area_user_size;
  reg        [1:0]    srio_area_user_prio;
  reg        [7:0]    srio_area_user_tid;
  reg                 srio_area_user_valid;
  reg        [63:0]   srio_area_user_data;
  reg                 srio_area_start;
  wire                srio_area_fsm_wantExit;
  reg                 srio_area_fsm_wantStart;
  wire                srio_area_fsm_wantKill;
  reg        [15:0]   srio_area_fsm_counter;
  reg        [3:0]    srio_area_fsm_stateReg;
  reg        [3:0]    srio_area_fsm_stateNext;
  wire                when_Srio_Test_Top_l140;
  wire                when_Srio_Test_Top_l163;
  wire                when_Srio_Test_Top_l187;
  `ifndef SYNTHESIS
  reg [47:0] usercmd_user_ftype_string;
  reg [47:0] usercmd_user_ttype_string;
  reg [47:0] srio_area_user_ftype_string;
  reg [47:0] srio_area_user_ttype_string;
  reg [103:0] srio_area_fsm_stateReg_string;
  reg [103:0] srio_area_fsm_stateNext_string;
  `endif


  assign _zz_srio_area_user_data = (srio_area_user_data + 64'h0000000000000001);
  Timer srio_area_timer (
    .io_tick  (1'b1                          ), //i
    .io_clear (srio_area_timer_io_clear      ), //i
    .io_limit (32'h000007d0                  ), //i
    .io_full  (srio_area_timer_io_full       ), //o
    .io_value (srio_area_timer_io_value[31:0]), //o
    .srio_clk (srio_clk                      ), //i
    .reset    (reset                         )  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(usercmd_user_ftype)
      SrioFtype_NREAD : usercmd_user_ftype_string = "NREAD ";
      SrioFtype_NWRITE : usercmd_user_ftype_string = "NWRITE";
      SrioFtype_SWRITE : usercmd_user_ftype_string = "SWRITE";
      SrioFtype_DOORB : usercmd_user_ftype_string = "DOORB ";
      SrioFtype_MESSG : usercmd_user_ftype_string = "MESSG ";
      SrioFtype_RESP : usercmd_user_ftype_string = "RESP  ";
      SrioFtype_FTYPE9 : usercmd_user_ftype_string = "FTYPE9";
      default : usercmd_user_ftype_string = "??????";
    endcase
  end
  always @(*) begin
    case(usercmd_user_ttype)
      SrioTtype_TNWR : usercmd_user_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : usercmd_user_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : usercmd_user_ttype_string = "TNDATA";
      SrioTtype_TWDATA : usercmd_user_ttype_string = "TWDATA";
      default : usercmd_user_ttype_string = "??????";
    endcase
  end
  always @(*) begin
    case(srio_area_user_ftype)
      SrioFtype_NREAD : srio_area_user_ftype_string = "NREAD ";
      SrioFtype_NWRITE : srio_area_user_ftype_string = "NWRITE";
      SrioFtype_SWRITE : srio_area_user_ftype_string = "SWRITE";
      SrioFtype_DOORB : srio_area_user_ftype_string = "DOORB ";
      SrioFtype_MESSG : srio_area_user_ftype_string = "MESSG ";
      SrioFtype_RESP : srio_area_user_ftype_string = "RESP  ";
      SrioFtype_FTYPE9 : srio_area_user_ftype_string = "FTYPE9";
      default : srio_area_user_ftype_string = "??????";
    endcase
  end
  always @(*) begin
    case(srio_area_user_ttype)
      SrioTtype_TNWR : srio_area_user_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : srio_area_user_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : srio_area_user_ttype_string = "TNDATA";
      SrioTtype_TWDATA : srio_area_user_ttype_string = "TWDATA";
      default : srio_area_user_ttype_string = "??????";
    endcase
  end
  always @(*) begin
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateReg_string = "BOOT         ";
      srio_area_fsm_enumDef_Init_Start : srio_area_fsm_stateReg_string = "Init_Start   ";
      srio_area_fsm_enumDef_Send_Read : srio_area_fsm_stateReg_string = "Send_Read    ";
      srio_area_fsm_enumDef_DoorBeel : srio_area_fsm_stateReg_string = "DoorBeel     ";
      srio_area_fsm_enumDef_Send_DoorBeel : srio_area_fsm_stateReg_string = "Send_DoorBeel";
      srio_area_fsm_enumDef_Nwrite : srio_area_fsm_stateReg_string = "Nwrite       ";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateReg_string = "Send_Data    ";
      srio_area_fsm_enumDef_Send_Stream : srio_area_fsm_stateReg_string = "Send_Stream  ";
      srio_area_fsm_enumDef_Send_Nwrite : srio_area_fsm_stateReg_string = "Send_Nwrite  ";
      default : srio_area_fsm_stateReg_string = "?????????????";
    endcase
  end
  always @(*) begin
    case(srio_area_fsm_stateNext)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateNext_string = "BOOT         ";
      srio_area_fsm_enumDef_Init_Start : srio_area_fsm_stateNext_string = "Init_Start   ";
      srio_area_fsm_enumDef_Send_Read : srio_area_fsm_stateNext_string = "Send_Read    ";
      srio_area_fsm_enumDef_DoorBeel : srio_area_fsm_stateNext_string = "DoorBeel     ";
      srio_area_fsm_enumDef_Send_DoorBeel : srio_area_fsm_stateNext_string = "Send_DoorBeel";
      srio_area_fsm_enumDef_Nwrite : srio_area_fsm_stateNext_string = "Nwrite       ";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateNext_string = "Send_Data    ";
      srio_area_fsm_enumDef_Send_Stream : srio_area_fsm_stateNext_string = "Send_Stream  ";
      srio_area_fsm_enumDef_Send_Nwrite : srio_area_fsm_stateNext_string = "Send_Nwrite  ";
      default : srio_area_fsm_stateNext_string = "?????????????";
    endcase
  end
  `endif

  assign when_Srio_Test_Top_l103 = (32'h000007d0 <= srio_area_timer_io_value); // @[BaseType.scala 305:24]
  always @(*) begin
    if(when_Srio_Test_Top_l103) begin
      srio_area_timer_io_clear = 1'b1; // @[Srio_Test_Top.scala 104:22]
    end else begin
      srio_area_timer_io_clear = 1'b0; // @[Srio_Test_Top.scala 106:22]
    end
  end

  assign srio_area_fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    srio_area_fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Init_Start : begin
      end
      srio_area_fsm_enumDef_Send_Read : begin
      end
      srio_area_fsm_enumDef_DoorBeel : begin
      end
      srio_area_fsm_enumDef_Send_DoorBeel : begin
      end
      srio_area_fsm_enumDef_Nwrite : begin
      end
      srio_area_fsm_enumDef_Send_Data : begin
      end
      srio_area_fsm_enumDef_Send_Stream : begin
      end
      srio_area_fsm_enumDef_Send_Nwrite : begin
      end
      default : begin
        srio_area_fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign srio_area_fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign usercmd_user_ftype = srio_area_user_ftype; // @[Srio_Test_Top.scala 208:27]
  assign usercmd_user_ttype = srio_area_user_ttype; // @[Srio_Test_Top.scala 209:27]
  assign usercmd_user_addr = srio_area_user_addr; // @[Srio_Test_Top.scala 210:26]
  assign usercmd_user_tid = srio_area_user_tid; // @[Srio_Test_Top.scala 211:25]
  assign usercmd_user_prio = srio_area_user_prio; // @[Srio_Test_Top.scala 212:26]
  assign usercmd_user_size = srio_area_user_size; // @[Srio_Test_Top.scala 213:26]
  assign m_axis_usercmd_tvalid = srio_area_user_valid; // @[Srio_Test_Top.scala 214:32]
  assign m_axis_usercmd_tdata = srio_area_user_data; // @[Srio_Test_Top.scala 215:34]
  assign send_start = srio_area_start; // @[Srio_Test_Top.scala 216:19]
  always @(*) begin
    srio_area_fsm_stateNext = srio_area_fsm_stateReg; // @[StateMachine.scala 217:17]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Init_Start : begin
        if(srio_area_timer_io_full) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Read; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_Send_Read : begin
        if(when_Srio_Test_Top_l140) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_DoorBeel : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_DoorBeel; // @[Enum.scala 148:67]
      end
      srio_area_fsm_enumDef_Send_DoorBeel : begin
        if(when_Srio_Test_Top_l163) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_Nwrite : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Data; // @[Enum.scala 148:67]
      end
      srio_area_fsm_enumDef_Send_Data : begin
        if(when_Srio_Test_Top_l187) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Stream; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_Send_Stream : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Nwrite; // @[Enum.scala 148:67]
      end
      srio_area_fsm_enumDef_Send_Nwrite : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
      end
      default : begin
      end
    endcase
    if(srio_area_fsm_wantStart) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
    end
    if(srio_area_fsm_wantKill) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_BOOT; // @[Enum.scala 148:67]
    end
  end

  assign when_Srio_Test_Top_l140 = (16'h0190 < srio_area_fsm_counter); // @[BaseType.scala 305:24]
  assign when_Srio_Test_Top_l163 = (16'h00c8 < srio_area_fsm_counter); // @[BaseType.scala 305:24]
  assign when_Srio_Test_Top_l187 = (16'h000e < srio_area_fsm_counter); // @[BaseType.scala 305:24]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      srio_area_user_addr <= 34'h0; // @[Data.scala 400:33]
      srio_area_user_valid <= 1'b0; // @[Data.scala 400:33]
      srio_area_user_data <= 64'h0; // @[Data.scala 400:33]
      srio_area_start <= 1'b0; // @[Data.scala 400:33]
      srio_area_fsm_counter <= 16'h0; // @[Data.scala 400:33]
      srio_area_fsm_stateReg <= srio_area_fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      srio_area_fsm_stateReg <= srio_area_fsm_stateNext; // @[StateMachine.scala 212:14]
      case(srio_area_fsm_stateReg)
        srio_area_fsm_enumDef_Init_Start : begin
          if(srio_area_timer_io_full) begin
            srio_area_user_addr <= 34'h000120000; // @[Srio_Test_Top.scala 124:23]
            srio_area_start <= 1'b1; // @[Srio_Test_Top.scala 130:19]
            srio_area_fsm_counter <= 16'h0; // @[Srio_Test_Top.scala 131:21]
          end
        end
        srio_area_fsm_enumDef_Send_Read : begin
          srio_area_start <= 1'b0; // @[Srio_Test_Top.scala 138:17]
          srio_area_fsm_counter <= (srio_area_fsm_counter + 16'h0001); // @[Srio_Test_Top.scala 139:19]
          if(when_Srio_Test_Top_l140) begin
            srio_area_fsm_counter <= 16'h0; // @[Srio_Test_Top.scala 141:21]
          end
        end
        srio_area_fsm_enumDef_DoorBeel : begin
          srio_area_user_addr <= 34'h000020000; // @[Srio_Test_Top.scala 148:21]
          srio_area_start <= 1'b1; // @[Srio_Test_Top.scala 154:17]
          srio_area_fsm_counter <= 16'h0; // @[Srio_Test_Top.scala 155:19]
        end
        srio_area_fsm_enumDef_Send_DoorBeel : begin
          srio_area_start <= 1'b0; // @[Srio_Test_Top.scala 161:17]
          srio_area_fsm_counter <= (srio_area_fsm_counter + 16'h0001); // @[Srio_Test_Top.scala 162:19]
          if(when_Srio_Test_Top_l163) begin
            srio_area_fsm_counter <= 16'h0; // @[Srio_Test_Top.scala 164:21]
          end
        end
        srio_area_fsm_enumDef_Nwrite : begin
          srio_area_user_addr <= 34'h000120088; // @[Srio_Test_Top.scala 171:21]
          srio_area_user_valid <= 1'b1; // @[Srio_Test_Top.scala 177:22]
          srio_area_user_data <= 64'h00000000a1a2a3a4; // @[Srio_Test_Top.scala 178:21]
        end
        srio_area_fsm_enumDef_Send_Data : begin
          srio_area_user_valid <= 1'b1; // @[Srio_Test_Top.scala 184:22]
          srio_area_user_data <= _zz_srio_area_user_data; // @[Srio_Test_Top.scala 185:21]
          srio_area_fsm_counter <= (srio_area_fsm_counter + 16'h0001); // @[Srio_Test_Top.scala 186:19]
        end
        srio_area_fsm_enumDef_Send_Stream : begin
          srio_area_user_valid <= 1'b0; // @[Srio_Test_Top.scala 194:22]
          srio_area_start <= 1'b1; // @[Srio_Test_Top.scala 195:17]
        end
        srio_area_fsm_enumDef_Send_Nwrite : begin
          srio_area_start <= 1'b0; // @[Srio_Test_Top.scala 201:17]
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge srio_clk) begin
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Init_Start : begin
        if(srio_area_timer_io_full) begin
          srio_area_user_ftype <= SrioFtype_NREAD; // @[Enum.scala 148:67]
          srio_area_user_ttype <= SrioTtype_TNWR; // @[Enum.scala 148:67]
          srio_area_user_size <= 8'h3f; // @[Srio_Test_Top.scala 127:23]
          srio_area_user_prio <= 2'b01; // @[Srio_Test_Top.scala 128:23]
          srio_area_user_tid <= 8'hff; // @[Srio_Test_Top.scala 129:22]
        end
      end
      srio_area_fsm_enumDef_Send_Read : begin
      end
      srio_area_fsm_enumDef_DoorBeel : begin
        srio_area_user_ftype <= SrioFtype_DOORB; // @[Enum.scala 148:67]
        srio_area_user_ttype <= SrioTtype_TNDATA; // @[Enum.scala 148:67]
        srio_area_user_size <= 8'h0; // @[Srio_Test_Top.scala 151:21]
        srio_area_user_prio <= 2'b01; // @[Srio_Test_Top.scala 152:21]
        srio_area_user_tid <= 8'hff; // @[Srio_Test_Top.scala 153:20]
      end
      srio_area_fsm_enumDef_Send_DoorBeel : begin
      end
      srio_area_fsm_enumDef_Nwrite : begin
        srio_area_user_ftype <= SrioFtype_NWRITE; // @[Enum.scala 148:67]
        srio_area_user_ttype <= SrioTtype_TNWR_R; // @[Enum.scala 148:67]
        srio_area_user_size <= 8'h7f; // @[Srio_Test_Top.scala 174:21]
        srio_area_user_prio <= 2'b01; // @[Srio_Test_Top.scala 175:21]
        srio_area_user_tid <= 8'hff; // @[Srio_Test_Top.scala 176:20]
      end
      srio_area_fsm_enumDef_Send_Data : begin
      end
      srio_area_fsm_enumDef_Send_Stream : begin
      end
      srio_area_fsm_enumDef_Send_Nwrite : begin
      end
      default : begin
      end
    endcase
  end


endmodule

module Srio_Top (
  input               srio_clk,
  input               reset,
  output              m_axis_ireq_tvalid,
  input               m_axis_ireq_tready,
  output              m_axis_ireq_tlast,
  output     [63:0]   m_axis_ireq_tdata,
  output     [7:0]    m_axis_ireq_tkeep,
  output     [31:0]   m_axis_ireq_tuser,
  input               s_axis_iresp_tvalid,
  output              s_axis_iresp_tready,
  input               s_axis_iresp_tlast,
  input      [63:0]   s_axis_iresp_tdata,
  input      [7:0]    s_axis_iresp_tkeep,
  input      [31:0]   s_axis_iresp_tuser,
  output              m_axis_tresp_tvalid,
  input               m_axis_tresp_tready,
  output              m_axis_tresp_tlast,
  output     [63:0]   m_axis_tresp_tdata,
  output     [7:0]    m_axis_tresp_tkeep,
  output     [31:0]   m_axis_tresp_tuser,
  input               s_axis_treq_tvalid,
  output              s_axis_treq_tready,
  input               s_axis_treq_tlast,
  input      [63:0]   s_axis_treq_tdata,
  input      [7:0]    s_axis_treq_tkeep,
  input      [31:0]   s_axis_treq_tuser,
  input      [33:0]   usercmd_user_addr,
  input      [3:0]    usercmd_user_ftype,
  input      [3:0]    usercmd_user_ttype,
  input      [7:0]    usercmd_user_size,
  input      [1:0]    usercmd_user_prio,
  input      [7:0]    usercmd_user_tid,
  input               s_axis_usercmd_tvalid,
  output              s_axis_usercmd_tready,
  input      [63:0]   s_axis_usercmd_tdata,
  input               send_start,
  output              m_axis_rspstream_tvalid,
  input               m_axis_rspstream_tready,
  output     [63:0]   m_axis_rspstream_tdata,
  input      [63:0]   data_in_0,
  input      [63:0]   data_in_1,
  input      [63:0]   data_in_2,
  input      [63:0]   data_in_3,
  input      [63:0]   data_in_4,
  input      [63:0]   data_in_5,
  input      [63:0]   data_in_6,
  input      [63:0]   data_in_7,
  input      [63:0]   data_in_8,
  input      [63:0]   data_in_9,
  input      [63:0]   data_in_10,
  input      [63:0]   data_in_11,
  input      [63:0]   data_in_12,
  input      [63:0]   data_in_13,
  input      [63:0]   data_in_14,
  input      [63:0]   data_in_15,
  output     [63:0]   data_out_0,
  output     [63:0]   data_out_1,
  output     [63:0]   data_out_2,
  output     [63:0]   data_out_3,
  output     [63:0]   data_out_4,
  output     [63:0]   data_out_5,
  output     [63:0]   data_out_6,
  output     [63:0]   data_out_7,
  output     [63:0]   data_out_8,
  output     [63:0]   data_out_9,
  output     [63:0]   data_out_10,
  output     [63:0]   data_out_11,
  output     [63:0]   data_out_12,
  output     [63:0]   data_out_13,
  output     [63:0]   data_out_14,
  output     [63:0]   data_out_15,
  output              busy,
  output     [15:0]   doorbell_info,
  output              doorbell_intr
);
  localparam SrioFtype_NREAD = 4'd2;
  localparam SrioFtype_NWRITE = 4'd5;
  localparam SrioFtype_SWRITE = 4'd6;
  localparam SrioFtype_DOORB = 4'd10;
  localparam SrioFtype_MESSG = 4'd11;
  localparam SrioFtype_RESP = 4'd13;
  localparam SrioFtype_FTYPE9 = 4'd9;
  localparam SrioTtype_TNWR = 4'd4;
  localparam SrioTtype_TNWR_R = 4'd5;
  localparam SrioTtype_TNDATA = 4'd0;
  localparam SrioTtype_TWDATA = 4'd8;

  wire       [63:0]   srio_area_srio_reg_simplebus_RDATA;
  wire       [63:0]   srio_area_srio_reg_data_out_0;
  wire       [63:0]   srio_area_srio_reg_data_out_1;
  wire       [63:0]   srio_area_srio_reg_data_out_2;
  wire       [63:0]   srio_area_srio_reg_data_out_3;
  wire       [63:0]   srio_area_srio_reg_data_out_4;
  wire       [63:0]   srio_area_srio_reg_data_out_5;
  wire       [63:0]   srio_area_srio_reg_data_out_6;
  wire       [63:0]   srio_area_srio_reg_data_out_7;
  wire       [63:0]   srio_area_srio_reg_data_out_8;
  wire       [63:0]   srio_area_srio_reg_data_out_9;
  wire       [63:0]   srio_area_srio_reg_data_out_10;
  wire       [63:0]   srio_area_srio_reg_data_out_11;
  wire       [63:0]   srio_area_srio_reg_data_out_12;
  wire       [63:0]   srio_area_srio_reg_data_out_13;
  wire       [63:0]   srio_area_srio_reg_data_out_14;
  wire       [63:0]   srio_area_srio_reg_data_out_15;
  wire                srio_area_target_m_axis_tresp_tvalid;
  wire                srio_area_target_m_axis_tresp_tlast;
  wire       [63:0]   srio_area_target_m_axis_tresp_tdata;
  wire       [7:0]    srio_area_target_m_axis_tresp_tkeep;
  wire       [31:0]   srio_area_target_m_axis_tresp_tuser;
  wire                srio_area_target_s_axis_treq_tready;
  wire       [8:0]    srio_area_target_simplebus_WADDR;
  wire       [63:0]   srio_area_target_simplebus_WDATA;
  wire                srio_area_target_simplebus_WENABLE;
  wire       [8:0]    srio_area_target_simplebus_RADDR;
  wire                srio_area_target_simplebus_RENABLE;
  wire       [15:0]   srio_area_target_doorbell_info;
  wire                srio_area_target_doorbell_intr;
  wire                srio_area_target_busy;
  wire                srio_area_target_fifo_io_push_ready;
  wire                srio_area_target_fifo_io_pop_valid;
  wire       [63:0]   srio_area_target_fifo_io_pop_payload;
  wire       [8:0]    srio_area_target_fifo_io_occupancy;
  wire       [8:0]    srio_area_target_fifo_io_availability;
  wire                srio_area_streamfifo_io_push_ready;
  wire                srio_area_streamfifo_io_pop_valid;
  wire       [63:0]   srio_area_streamfifo_io_pop_payload;
  wire       [8:0]    srio_area_streamfifo_io_occupancy;
  wire       [8:0]    srio_area_streamfifo_io_availability;
  wire                srio_area_intitaor_m_axis_ireq_tvalid;
  wire                srio_area_intitaor_m_axis_ireq_tlast;
  wire       [63:0]   srio_area_intitaor_m_axis_ireq_tdata;
  wire       [7:0]    srio_area_intitaor_m_axis_ireq_tkeep;
  wire       [31:0]   srio_area_intitaor_m_axis_ireq_tuser;
  wire                srio_area_intitaor_s_axis_iresp_tready;
  wire                srio_area_intitaor_usercmd_user_data_ready;
  wire                srio_area_intitaor_iresp_stream_valid;
  wire       [63:0]   srio_area_intitaor_iresp_stream_payload;
  wire                srio_area_intitaor_rsp_received;
  wire                srio_area_intitaor_request_autocheck_error;
  wire                srio_target_target_resp_stream_fire;
  wire                srio_intiator_intiator_req_stream_fire;
  `ifndef SYNTHESIS
  reg [47:0] usercmd_user_ftype_string;
  reg [47:0] usercmd_user_ttype_string;
  `endif


  Srio_Regif srio_area_srio_reg (
    .simplebus_RADDR   (srio_area_target_simplebus_RADDR[8:0]   ), //i
    .simplebus_RDATA   (srio_area_srio_reg_simplebus_RDATA[63:0]), //o
    .simplebus_RENABLE (srio_area_target_simplebus_RENABLE      ), //i
    .simplebus_WADDR   (srio_area_target_simplebus_WADDR[8:0]   ), //i
    .simplebus_WDATA   (srio_area_target_simplebus_WDATA[63:0]  ), //i
    .simplebus_WENABLE (srio_area_target_simplebus_WENABLE      ), //i
    .data_in_0         (data_in_0[63:0]                         ), //i
    .data_in_1         (data_in_1[63:0]                         ), //i
    .data_in_2         (data_in_2[63:0]                         ), //i
    .data_in_3         (data_in_3[63:0]                         ), //i
    .data_in_4         (data_in_4[63:0]                         ), //i
    .data_in_5         (data_in_5[63:0]                         ), //i
    .data_in_6         (data_in_6[63:0]                         ), //i
    .data_in_7         (data_in_7[63:0]                         ), //i
    .data_in_8         (data_in_8[63:0]                         ), //i
    .data_in_9         (data_in_9[63:0]                         ), //i
    .data_in_10        (data_in_10[63:0]                        ), //i
    .data_in_11        (data_in_11[63:0]                        ), //i
    .data_in_12        (data_in_12[63:0]                        ), //i
    .data_in_13        (data_in_13[63:0]                        ), //i
    .data_in_14        (data_in_14[63:0]                        ), //i
    .data_in_15        (data_in_15[63:0]                        ), //i
    .data_out_0        (srio_area_srio_reg_data_out_0[63:0]     ), //o
    .data_out_1        (srio_area_srio_reg_data_out_1[63:0]     ), //o
    .data_out_2        (srio_area_srio_reg_data_out_2[63:0]     ), //o
    .data_out_3        (srio_area_srio_reg_data_out_3[63:0]     ), //o
    .data_out_4        (srio_area_srio_reg_data_out_4[63:0]     ), //o
    .data_out_5        (srio_area_srio_reg_data_out_5[63:0]     ), //o
    .data_out_6        (srio_area_srio_reg_data_out_6[63:0]     ), //o
    .data_out_7        (srio_area_srio_reg_data_out_7[63:0]     ), //o
    .data_out_8        (srio_area_srio_reg_data_out_8[63:0]     ), //o
    .data_out_9        (srio_area_srio_reg_data_out_9[63:0]     ), //o
    .data_out_10       (srio_area_srio_reg_data_out_10[63:0]    ), //o
    .data_out_11       (srio_area_srio_reg_data_out_11[63:0]    ), //o
    .data_out_12       (srio_area_srio_reg_data_out_12[63:0]    ), //o
    .data_out_13       (srio_area_srio_reg_data_out_13[63:0]    ), //o
    .data_out_14       (srio_area_srio_reg_data_out_14[63:0]    ), //o
    .data_out_15       (srio_area_srio_reg_data_out_15[63:0]    ), //o
    .srio_clk          (srio_clk                                ), //i
    .reset             (reset                                   )  //i
  );
  Target srio_area_target (
    .m_axis_tresp_tvalid (srio_area_target_m_axis_tresp_tvalid     ), //o
    .m_axis_tresp_tready (1'b1                                     ), //i
    .m_axis_tresp_tlast  (srio_area_target_m_axis_tresp_tlast      ), //o
    .m_axis_tresp_tdata  (srio_area_target_m_axis_tresp_tdata[63:0]), //o
    .m_axis_tresp_tkeep  (srio_area_target_m_axis_tresp_tkeep[7:0] ), //o
    .m_axis_tresp_tuser  (srio_area_target_m_axis_tresp_tuser[31:0]), //o
    .s_axis_treq_tvalid  (s_axis_treq_tvalid                       ), //i
    .s_axis_treq_tready  (srio_area_target_s_axis_treq_tready      ), //o
    .s_axis_treq_tlast   (s_axis_treq_tlast                        ), //i
    .s_axis_treq_tdata   (s_axis_treq_tdata[63:0]                  ), //i
    .s_axis_treq_tkeep   (s_axis_treq_tkeep[7:0]                   ), //i
    .s_axis_treq_tuser   (s_axis_treq_tuser[31:0]                  ), //i
    .simplebus_RADDR     (srio_area_target_simplebus_RADDR[8:0]    ), //o
    .simplebus_RDATA     (srio_area_srio_reg_simplebus_RDATA[63:0] ), //i
    .simplebus_RENABLE   (srio_area_target_simplebus_RENABLE       ), //o
    .simplebus_WADDR     (srio_area_target_simplebus_WADDR[8:0]    ), //o
    .simplebus_WDATA     (srio_area_target_simplebus_WDATA[63:0]   ), //o
    .simplebus_WENABLE   (srio_area_target_simplebus_WENABLE       ), //o
    .doorbell_info       (srio_area_target_doorbell_info[15:0]     ), //o
    .doorbell_intr       (srio_area_target_doorbell_intr           ), //o
    .busy                (srio_area_target_busy                    ), //o
    .srio_clk            (srio_clk                                 ), //i
    .reset               (reset                                    )  //i
  );
  StreamFifo_1 srio_area_target_fifo (
    .io_push_valid   (srio_area_target_m_axis_tresp_tvalid      ), //i
    .io_push_ready   (srio_area_target_fifo_io_push_ready       ), //o
    .io_push_payload (srio_area_target_m_axis_tresp_tdata[63:0] ), //i
    .io_pop_valid    (srio_area_target_fifo_io_pop_valid        ), //o
    .io_pop_ready    (m_axis_tresp_tready                       ), //i
    .io_pop_payload  (srio_area_target_fifo_io_pop_payload[63:0]), //o
    .io_flush        (1'b0                                      ), //i
    .io_occupancy    (srio_area_target_fifo_io_occupancy[8:0]   ), //o
    .io_availability (srio_area_target_fifo_io_availability[8:0]), //o
    .srio_clk        (srio_clk                                  ), //i
    .reset           (reset                                     )  //i
  );
  StreamFifo_1 srio_area_streamfifo (
    .io_push_valid   (srio_area_intitaor_m_axis_ireq_tvalid     ), //i
    .io_push_ready   (srio_area_streamfifo_io_push_ready        ), //o
    .io_push_payload (srio_area_intitaor_m_axis_ireq_tdata[63:0]), //i
    .io_pop_valid    (srio_area_streamfifo_io_pop_valid         ), //o
    .io_pop_ready    (m_axis_ireq_tready                        ), //i
    .io_pop_payload  (srio_area_streamfifo_io_pop_payload[63:0] ), //o
    .io_flush        (1'b0                                      ), //i
    .io_occupancy    (srio_area_streamfifo_io_occupancy[8:0]    ), //o
    .io_availability (srio_area_streamfifo_io_availability[8:0] ), //o
    .srio_clk        (srio_clk                                  ), //i
    .reset           (reset                                     )  //i
  );
  Intitaor srio_area_intitaor (
    .m_axis_ireq_tvalid        (srio_area_intitaor_m_axis_ireq_tvalid        ), //o
    .m_axis_ireq_tready        (1'b1                                         ), //i
    .m_axis_ireq_tlast         (srio_area_intitaor_m_axis_ireq_tlast         ), //o
    .m_axis_ireq_tdata         (srio_area_intitaor_m_axis_ireq_tdata[63:0]   ), //o
    .m_axis_ireq_tkeep         (srio_area_intitaor_m_axis_ireq_tkeep[7:0]    ), //o
    .m_axis_ireq_tuser         (srio_area_intitaor_m_axis_ireq_tuser[31:0]   ), //o
    .s_axis_iresp_tvalid       (s_axis_iresp_tvalid                          ), //i
    .s_axis_iresp_tready       (srio_area_intitaor_s_axis_iresp_tready       ), //o
    .s_axis_iresp_tlast        (s_axis_iresp_tlast                           ), //i
    .s_axis_iresp_tdata        (s_axis_iresp_tdata[63:0]                     ), //i
    .s_axis_iresp_tkeep        (s_axis_iresp_tkeep[7:0]                      ), //i
    .s_axis_iresp_tuser        (s_axis_iresp_tuser[31:0]                     ), //i
    .usercmd_user_addr         (usercmd_user_addr[33:0]                      ), //i
    .usercmd_user_ftype        (usercmd_user_ftype[3:0]                      ), //i
    .usercmd_user_ttype        (usercmd_user_ttype[3:0]                      ), //i
    .usercmd_user_size         (usercmd_user_size[7:0]                       ), //i
    .usercmd_user_prio         (usercmd_user_prio[1:0]                       ), //i
    .usercmd_user_tid          (usercmd_user_tid[7:0]                        ), //i
    .usercmd_user_data_valid   (s_axis_usercmd_tvalid                        ), //i
    .usercmd_user_data_ready   (srio_area_intitaor_usercmd_user_data_ready   ), //o
    .usercmd_user_data_payload (s_axis_usercmd_tdata[63:0]                   ), //i
    .send_start                (send_start                                   ), //i
    .iresp_stream_valid        (srio_area_intitaor_iresp_stream_valid        ), //o
    .iresp_stream_ready        (m_axis_rspstream_tready                      ), //i
    .iresp_stream_payload      (srio_area_intitaor_iresp_stream_payload[63:0]), //o
    .rsp_received              (srio_area_intitaor_rsp_received              ), //o
    .request_autocheck_error   (srio_area_intitaor_request_autocheck_error   ), //o
    .srio_clk                  (srio_clk                                     ), //i
    .reset                     (reset                                        )  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(usercmd_user_ftype)
      SrioFtype_NREAD : usercmd_user_ftype_string = "NREAD ";
      SrioFtype_NWRITE : usercmd_user_ftype_string = "NWRITE";
      SrioFtype_SWRITE : usercmd_user_ftype_string = "SWRITE";
      SrioFtype_DOORB : usercmd_user_ftype_string = "DOORB ";
      SrioFtype_MESSG : usercmd_user_ftype_string = "MESSG ";
      SrioFtype_RESP : usercmd_user_ftype_string = "RESP  ";
      SrioFtype_FTYPE9 : usercmd_user_ftype_string = "FTYPE9";
      default : usercmd_user_ftype_string = "??????";
    endcase
  end
  always @(*) begin
    case(usercmd_user_ttype)
      SrioTtype_TNWR : usercmd_user_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : usercmd_user_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : usercmd_user_ttype_string = "TNDATA";
      SrioTtype_TWDATA : usercmd_user_ttype_string = "TWDATA";
      default : usercmd_user_ttype_string = "??????";
    endcase
  end
  `endif

  assign m_axis_tresp_tkeep = srio_area_target_m_axis_tresp_tkeep; // @[Srio_Test_Top.scala 34:41]
  assign m_axis_tresp_tuser = srio_area_target_m_axis_tresp_tuser; // @[Srio_Test_Top.scala 34:41]
  assign s_axis_treq_tready = srio_area_target_s_axis_treq_tready; // @[Srio_Test_Top.scala 36:40]
  assign m_axis_tresp_tdata = srio_area_target_fifo_io_pop_payload; // @[Srio_Test_Top.scala 44:56]
  assign m_axis_tresp_tvalid = srio_area_target_fifo_io_pop_valid; // @[Srio_Test_Top.scala 45:45]
  assign srio_target_target_resp_stream_fire = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign m_axis_tresp_tlast = ((srio_area_target_fifo_io_occupancy == 9'h001) && srio_target_target_resp_stream_fire); // @[Srio_Test_Top.scala 47:52]
  assign m_axis_ireq_tkeep = srio_area_intitaor_m_axis_ireq_tkeep; // @[Srio_Test_Top.scala 52:46]
  assign m_axis_ireq_tuser = srio_area_intitaor_m_axis_ireq_tuser; // @[Srio_Test_Top.scala 52:46]
  assign s_axis_iresp_tready = srio_area_intitaor_s_axis_iresp_tready; // @[Srio_Test_Top.scala 54:47]
  assign s_axis_usercmd_tready = srio_area_intitaor_usercmd_user_data_ready; // @[Srio_Test_Top.scala 56:25]
  assign m_axis_rspstream_tvalid = srio_area_intitaor_iresp_stream_valid; // @[Srio_Test_Top.scala 57:30]
  assign m_axis_rspstream_tdata = srio_area_intitaor_iresp_stream_payload; // @[Srio_Test_Top.scala 57:30]
  assign m_axis_ireq_tdata = srio_area_streamfifo_io_pop_payload; // @[Srio_Test_Top.scala 64:59]
  assign m_axis_ireq_tvalid = srio_area_streamfifo_io_pop_valid; // @[Srio_Test_Top.scala 65:48]
  assign srio_intiator_intiator_req_stream_fire = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tlast = ((srio_area_streamfifo_io_occupancy == 9'h001) && srio_intiator_intiator_req_stream_fire); // @[Srio_Test_Top.scala 67:55]
  assign data_out_0 = srio_area_srio_reg_data_out_0; // @[Srio_Test_Top.scala 79:22]
  assign data_out_1 = srio_area_srio_reg_data_out_1; // @[Srio_Test_Top.scala 79:22]
  assign data_out_2 = srio_area_srio_reg_data_out_2; // @[Srio_Test_Top.scala 79:22]
  assign data_out_3 = srio_area_srio_reg_data_out_3; // @[Srio_Test_Top.scala 79:22]
  assign data_out_4 = srio_area_srio_reg_data_out_4; // @[Srio_Test_Top.scala 79:22]
  assign data_out_5 = srio_area_srio_reg_data_out_5; // @[Srio_Test_Top.scala 79:22]
  assign data_out_6 = srio_area_srio_reg_data_out_6; // @[Srio_Test_Top.scala 79:22]
  assign data_out_7 = srio_area_srio_reg_data_out_7; // @[Srio_Test_Top.scala 79:22]
  assign data_out_8 = srio_area_srio_reg_data_out_8; // @[Srio_Test_Top.scala 79:22]
  assign data_out_9 = srio_area_srio_reg_data_out_9; // @[Srio_Test_Top.scala 79:22]
  assign data_out_10 = srio_area_srio_reg_data_out_10; // @[Srio_Test_Top.scala 79:22]
  assign data_out_11 = srio_area_srio_reg_data_out_11; // @[Srio_Test_Top.scala 79:22]
  assign data_out_12 = srio_area_srio_reg_data_out_12; // @[Srio_Test_Top.scala 79:22]
  assign data_out_13 = srio_area_srio_reg_data_out_13; // @[Srio_Test_Top.scala 79:22]
  assign data_out_14 = srio_area_srio_reg_data_out_14; // @[Srio_Test_Top.scala 79:22]
  assign data_out_15 = srio_area_srio_reg_data_out_15; // @[Srio_Test_Top.scala 79:22]
  assign busy = srio_area_target_busy; // @[Srio_Test_Top.scala 82:13]
  assign doorbell_intr = srio_area_target_doorbell_intr; // @[Srio_Test_Top.scala 83:22]
  assign doorbell_info = srio_area_target_doorbell_info; // @[Srio_Test_Top.scala 84:22]

endmodule

module Timer (
  input               io_tick,
  input               io_clear,
  input      [31:0]   io_limit,
  output              io_full,
  output     [31:0]   io_value,
  input               srio_clk,
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
  always @(posedge srio_clk or posedge reset) begin
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

  always @(posedge srio_clk) begin
    if(io_tick) begin
      counter <= (counter + _zz_counter); // @[Timer.scala 21:13]
    end
    if(io_clear) begin
      counter <= 32'h0; // @[Timer.scala 24:13]
    end
  end


endmodule

module Intitaor (
  output              m_axis_ireq_tvalid,
  input               m_axis_ireq_tready,
  output              m_axis_ireq_tlast,
  output     [63:0]   m_axis_ireq_tdata,
  output     [7:0]    m_axis_ireq_tkeep,
  output     [31:0]   m_axis_ireq_tuser,
  input               s_axis_iresp_tvalid,
  output              s_axis_iresp_tready,
  input               s_axis_iresp_tlast,
  input      [63:0]   s_axis_iresp_tdata,
  input      [7:0]    s_axis_iresp_tkeep,
  input      [31:0]   s_axis_iresp_tuser,
  input      [33:0]   usercmd_user_addr,
  input      [3:0]    usercmd_user_ftype,
  input      [3:0]    usercmd_user_ttype,
  input      [7:0]    usercmd_user_size,
  input      [1:0]    usercmd_user_prio,
  input      [7:0]    usercmd_user_tid,
  input               usercmd_user_data_valid,
  output              usercmd_user_data_ready,
  input      [63:0]   usercmd_user_data_payload,
  input               send_start,
  output              iresp_stream_valid,
  input               iresp_stream_ready,
  output     [63:0]   iresp_stream_payload,
  output              rsp_received,
  output              request_autocheck_error,
  input               srio_clk,
  input               reset
);
  localparam SrioFtype_NREAD = 4'd2;
  localparam SrioFtype_NWRITE = 4'd5;
  localparam SrioFtype_SWRITE = 4'd6;
  localparam SrioFtype_DOORB = 4'd10;
  localparam SrioFtype_MESSG = 4'd11;
  localparam SrioFtype_RESP = 4'd13;
  localparam SrioFtype_FTYPE9 = 4'd9;
  localparam SrioTtype_TNWR = 4'd4;
  localparam SrioTtype_TNWR_R = 4'd5;
  localparam SrioTtype_TNDATA = 4'd0;
  localparam SrioTtype_TWDATA = 4'd8;

  wire                fifo_io_push_valid;
  wire                streamfifo_4_io_push_ready;
  wire                streamfifo_4_io_pop_valid;
  wire       [63:0]   streamfifo_4_io_pop_payload;
  wire       [8:0]    streamfifo_4_io_occupancy;
  wire       [8:0]    streamfifo_4_io_availability;
  wire                fifo_io_push_ready;
  wire                fifo_io_pop_valid;
  wire       [63:0]   fifo_io_pop_payload;
  wire       [8:0]    fifo_io_occupancy;
  wire       [8:0]    fifo_io_availability;
  wire       [5:0]    _zz_when_Intitaor_l51;
  wire       [4:0]    _zz_when_Intitaor_l51_1;
  wire       [3:0]    _zz_request_autocheck_error_1;
  wire       [3:0]    _zz_request_autocheck_error_1_1;
  wire       [63:0]   header_beat;
  reg        [5:0]    current_beat_cnt;
  wire                intiator_intiator_req_stream_fire;
  wire                when_Intitaor_l37;
  wire                intiator_intiator_req_stream_fire_1;
  wire       [4:0]    number_of_data_beats;
  reg                 ireq_tlast;
  wire                when_Intitaor_l49;
  wire                intiator_intiator_req_stream_fire_2;
  wire                intiator_intiator_req_stream_fire_3;
  wire                when_Intitaor_l51;
  wire                when_Intitaor_l53;
  wire                when_Intitaor_l55;
  reg        [63:0]   ireq_tdata;
  wire                intiator_intiator_req_stream_fire_4;
  wire                when_Intitaor_l63;
  reg                 user_data_ready;
  reg                 ireq_tvalid;
  reg                 send_start_d;
  wire                intiator_intiator_req_stream_fire_5;
  wire                when_Intitaor_l73;
  wire                when_Intitaor_l76;
  wire                intiator_intiator_req_stream_fire_6;
  wire       [63:0]   write_queue_data_d;
  reg        [63:0]   write_queue_data;
  reg                 expecting_a_response;
  wire                intiator_intiator_req_stream_fire_7;
  wire                when_Intitaor_l91;
  reg        [63:0]   read_queue_data;
  wire       [7:0]    expected_tid;
  wire       [3:0]    expected_ftype;
  wire       [7:0]    expected_size;
  reg                 compare_received;
  wire                intiator_intiator_resp_stream_fire;
  wire                when_Intitaor_l106;
  wire                intiator_intiator_resp_stream_fire_1;
  wire                intiator_intiator_resp_stream_fire_2;
  reg                 request_autocheck_error_1;
  wire                intiator_intiator_resp_stream_fire_3;
  wire                when_Intitaor_l117;
  reg                 nread_iresp_write;
  wire                intiator_intiator_resp_stream_fire_4;
  wire                when_Intitaor_l137;
  wire                intiator_intiator_resp_stream_fire_5;
  wire                when_Intitaor_l139;
  wire                intiator_intiator_resp_stream_fire_6;
  `ifndef SYNTHESIS
  reg [47:0] usercmd_user_ftype_string;
  reg [47:0] usercmd_user_ttype_string;
  `endif


  assign _zz_when_Intitaor_l51_1 = number_of_data_beats;
  assign _zz_when_Intitaor_l51 = {1'd0, _zz_when_Intitaor_l51_1};
  assign _zz_request_autocheck_error_1 = SrioFtype_NREAD;
  assign _zz_request_autocheck_error_1_1 = SrioTtype_TWDATA;
  StreamFifo_3 streamfifo_4 (
    .io_push_valid   (usercmd_user_data_valid            ), //i
    .io_push_ready   (streamfifo_4_io_push_ready         ), //o
    .io_push_payload (usercmd_user_data_payload[63:0]    ), //i
    .io_pop_valid    (streamfifo_4_io_pop_valid          ), //o
    .io_pop_ready    (intiator_intiator_req_stream_fire_6), //i
    .io_pop_payload  (streamfifo_4_io_pop_payload[63:0]  ), //o
    .io_flush        (1'b0                               ), //i
    .io_occupancy    (streamfifo_4_io_occupancy[8:0]     ), //o
    .io_availability (streamfifo_4_io_availability[8:0]  ), //o
    .srio_clk        (srio_clk                           ), //i
    .reset           (reset                              )  //i
  );
  StreamFifo_3 fifo (
    .io_push_valid   (fifo_io_push_valid       ), //i
    .io_push_ready   (fifo_io_push_ready       ), //o
    .io_push_payload (s_axis_iresp_tdata[63:0] ), //i
    .io_pop_valid    (fifo_io_pop_valid        ), //o
    .io_pop_ready    (iresp_stream_ready       ), //i
    .io_pop_payload  (fifo_io_pop_payload[63:0]), //o
    .io_flush        (1'b0                     ), //i
    .io_occupancy    (fifo_io_occupancy[8:0]   ), //o
    .io_availability (fifo_io_availability[8:0]), //o
    .srio_clk        (srio_clk                 ), //i
    .reset           (reset                    )  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(usercmd_user_ftype)
      SrioFtype_NREAD : usercmd_user_ftype_string = "NREAD ";
      SrioFtype_NWRITE : usercmd_user_ftype_string = "NWRITE";
      SrioFtype_SWRITE : usercmd_user_ftype_string = "SWRITE";
      SrioFtype_DOORB : usercmd_user_ftype_string = "DOORB ";
      SrioFtype_MESSG : usercmd_user_ftype_string = "MESSG ";
      SrioFtype_RESP : usercmd_user_ftype_string = "RESP  ";
      SrioFtype_FTYPE9 : usercmd_user_ftype_string = "FTYPE9";
      default : usercmd_user_ftype_string = "??????";
    endcase
  end
  always @(*) begin
    case(usercmd_user_ttype)
      SrioTtype_TNWR : usercmd_user_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : usercmd_user_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : usercmd_user_ttype_string = "TNDATA";
      SrioTtype_TWDATA : usercmd_user_ttype_string = "TWDATA";
      default : usercmd_user_ttype_string = "??????";
    endcase
  end
  `endif

  assign m_axis_ireq_tkeep = 8'hff; // @[Intitaor.scala 21:41]
  assign m_axis_ireq_tuser = 32'h00ff00ff; // @[Intitaor.scala 22:41]
  assign usercmd_user_data_ready = streamfifo_4_io_push_ready; // @[Stream.scala 295:16]
  assign header_beat = {{{{{{{{usercmd_user_tid,usercmd_user_ftype},usercmd_user_ttype},1'b0},usercmd_user_prio},1'b0},usercmd_user_size},2'b00},usercmd_user_addr}; // @[BaseType.scala 299:24]
  assign intiator_intiator_req_stream_fire = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l37 = (intiator_intiator_req_stream_fire && m_axis_ireq_tlast); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_1 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign number_of_data_beats = usercmd_user_size[7 : 3]; // @[BaseType.scala 299:24]
  assign when_Intitaor_l49 = (((usercmd_user_ftype == SrioFtype_NREAD) || (usercmd_user_ftype == SrioFtype_DOORB)) && (current_beat_cnt == 6'h0)); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_2 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_3 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l51 = ((current_beat_cnt == _zz_when_Intitaor_l51) && intiator_intiator_req_stream_fire_3); // @[BaseType.scala 305:24]
  assign when_Intitaor_l53 = (m_axis_ireq_tready == 1'b0); // @[BaseType.scala 305:24]
  assign when_Intitaor_l55 = (m_axis_ireq_tready || (! m_axis_ireq_tvalid)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tlast = ireq_tlast; // @[Intitaor.scala 60:40]
  assign intiator_intiator_req_stream_fire_4 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l63 = ((current_beat_cnt == 6'h0) && (! intiator_intiator_req_stream_fire_4)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tdata = ireq_tdata; // @[Intitaor.scala 68:52]
  assign intiator_intiator_req_stream_fire_5 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l73 = (intiator_intiator_req_stream_fire_5 && m_axis_ireq_tlast); // @[BaseType.scala 305:24]
  assign when_Intitaor_l76 = (send_start && (! send_start_d)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tvalid = ireq_tvalid; // @[Intitaor.scala 83:41]
  assign intiator_intiator_req_stream_fire_6 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign write_queue_data_d = {{{44'h0,usercmd_user_tid},usercmd_user_ftype},usercmd_user_size}; // @[BaseType.scala 299:24]
  assign intiator_intiator_req_stream_fire_7 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l91 = ((current_beat_cnt == 6'h0) && intiator_intiator_req_stream_fire_7); // @[BaseType.scala 305:24]
  assign expected_tid = read_queue_data[19 : 12]; // @[BaseType.scala 299:24]
  assign expected_ftype = read_queue_data[11 : 8]; // @[BaseType.scala 299:24]
  assign expected_size = read_queue_data[7 : 0]; // @[BaseType.scala 299:24]
  assign intiator_intiator_resp_stream_fire = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l106 = (intiator_intiator_resp_stream_fire && s_axis_iresp_tlast); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_1 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_2 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign rsp_received = (intiator_intiator_resp_stream_fire_2 && s_axis_iresp_tlast); // @[Intitaor.scala 114:19]
  assign intiator_intiator_resp_stream_fire_3 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l117 = (compare_received && intiator_intiator_resp_stream_fire_3); // @[BaseType.scala 305:24]
  assign request_autocheck_error = request_autocheck_error_1; // @[Intitaor.scala 126:30]
  assign intiator_intiator_resp_stream_fire_4 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l137 = ((compare_received && (expected_ftype == SrioFtype_NREAD)) && intiator_intiator_resp_stream_fire_4); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_5 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l139 = (intiator_intiator_resp_stream_fire_5 && s_axis_iresp_tlast); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_6 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign fifo_io_push_valid = (nread_iresp_write && intiator_intiator_resp_stream_fire_6); // @[Intitaor.scala 146:22]
  assign s_axis_iresp_tready = fifo_io_push_ready; // @[Intitaor.scala 148:42]
  assign iresp_stream_payload = fifo_io_pop_payload; // @[Intitaor.scala 152:27]
  assign iresp_stream_valid = fifo_io_pop_valid; // @[Intitaor.scala 153:25]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      current_beat_cnt <= 6'h0; // @[Data.scala 400:33]
      ireq_tlast <= 1'b0; // @[Data.scala 400:33]
      user_data_ready <= 1'b0; // @[Data.scala 400:33]
      ireq_tvalid <= 1'b0; // @[Data.scala 400:33]
      send_start_d <= 1'b0; // @[Data.scala 400:33]
      expecting_a_response <= 1'b0; // @[Data.scala 400:33]
      compare_received <= 1'b1; // @[Data.scala 400:33]
      request_autocheck_error_1 <= 1'b0; // @[Data.scala 400:33]
      nread_iresp_write <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(when_Intitaor_l37) begin
        current_beat_cnt <= 6'h0; // @[Intitaor.scala 38:22]
      end else begin
        if(intiator_intiator_req_stream_fire_1) begin
          current_beat_cnt <= (current_beat_cnt + 6'h01); // @[Intitaor.scala 40:22]
        end else begin
          current_beat_cnt <= current_beat_cnt; // @[Intitaor.scala 42:22]
        end
      end
      if(when_Intitaor_l49) begin
        ireq_tlast <= (! (intiator_intiator_req_stream_fire_2 && m_axis_ireq_tlast)); // @[Intitaor.scala 50:16]
      end else begin
        if(when_Intitaor_l51) begin
          ireq_tlast <= (! ireq_tlast); // @[Intitaor.scala 52:16]
        end else begin
          if(when_Intitaor_l53) begin
            ireq_tlast <= ireq_tlast; // @[Intitaor.scala 54:16]
          end else begin
            if(when_Intitaor_l55) begin
              ireq_tlast <= 1'b0; // @[Intitaor.scala 56:16]
            end else begin
              ireq_tlast <= ireq_tlast; // @[Intitaor.scala 58:16]
            end
          end
        end
      end
      send_start_d <= send_start; // @[Reg.scala 39:30]
      if(when_Intitaor_l73) begin
        ireq_tvalid <= 1'b0; // @[Intitaor.scala 74:17]
        user_data_ready <= 1'b0; // @[Intitaor.scala 75:21]
      end else begin
        if(when_Intitaor_l76) begin
          ireq_tvalid <= 1'b1; // @[Intitaor.scala 77:17]
          user_data_ready <= 1'b1; // @[Intitaor.scala 78:21]
        end else begin
          ireq_tvalid <= ireq_tvalid; // @[Intitaor.scala 80:17]
          user_data_ready <= user_data_ready; // @[Intitaor.scala 81:21]
        end
      end
      if(when_Intitaor_l91) begin
        expecting_a_response <= ((((usercmd_user_ftype == SrioFtype_NREAD) || (usercmd_user_ftype == SrioFtype_DOORB)) || ((usercmd_user_ftype == SrioFtype_NWRITE) && (usercmd_user_ttype == SrioTtype_TNWR_R))) || (usercmd_user_ftype == SrioFtype_MESSG)); // @[Intitaor.scala 92:26]
      end else begin
        expecting_a_response <= 1'b0; // @[Intitaor.scala 97:26]
      end
      if(when_Intitaor_l106) begin
        compare_received <= 1'b1; // @[Intitaor.scala 107:22]
      end else begin
        if(intiator_intiator_resp_stream_fire_1) begin
          compare_received <= 1'b0; // @[Intitaor.scala 109:22]
        end else begin
          compare_received <= compare_received; // @[Intitaor.scala 111:22]
        end
      end
      if(when_Intitaor_l117) begin
        request_autocheck_error_1 <= ((((expected_tid != s_axis_iresp_tdata[63 : 56]) || ((expected_ftype == _zz_request_autocheck_error_1) && (s_axis_iresp_tdata[51 : 48] != _zz_request_autocheck_error_1_1))) || ((expected_ftype == SrioFtype_NWRITE) && (s_axis_iresp_tdata[51 : 48] != SrioTtype_TNDATA))) || ((expected_ftype == SrioFtype_DOORB) && (s_axis_iresp_tdata[51 : 48] != SrioTtype_TNDATA))); // @[Intitaor.scala 118:29]
      end else begin
        request_autocheck_error_1 <= 1'b0; // @[Intitaor.scala 123:29]
      end
      if(when_Intitaor_l137) begin
        nread_iresp_write <= 1'b1; // @[Intitaor.scala 138:23]
      end else begin
        if(when_Intitaor_l139) begin
          nread_iresp_write <= 1'b0; // @[Intitaor.scala 140:23]
        end else begin
          nread_iresp_write <= nread_iresp_write; // @[Intitaor.scala 142:23]
        end
      end
    end
  end

  always @(posedge srio_clk) begin
    if(when_Intitaor_l63) begin
      ireq_tdata <= header_beat; // @[Intitaor.scala 64:16]
    end else begin
      ireq_tdata <= streamfifo_4_io_pop_payload; // @[Intitaor.scala 66:16]
    end
    write_queue_data <= write_queue_data_d; // @[Reg.scala 39:30]
    if(expecting_a_response) begin
      read_queue_data <= write_queue_data; // @[Intitaor.scala 100:36]
    end
  end


endmodule

//StreamFifo_1 replaced by StreamFifo_1

module StreamFifo_1 (
  input               io_push_valid,
  output              io_push_ready,
  input      [63:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [63:0]   io_pop_payload,
  input               io_flush,
  output     [8:0]    io_occupancy,
  output     [8:0]    io_availability,
  input               srio_clk,
  input               reset
);

  reg        [63:0]   _zz_logic_ram_port0;
  wire       [7:0]    _zz_logic_pushPtr_valueNext;
  wire       [0:0]    _zz_logic_pushPtr_valueNext_1;
  wire       [7:0]    _zz_logic_popPtr_valueNext;
  wire       [0:0]    _zz_logic_popPtr_valueNext_1;
  wire                _zz_logic_ram_port;
  wire                _zz_io_pop_payload;
  wire       [7:0]    _zz_io_availability;
  reg                 _zz_1;
  reg                 logic_pushPtr_willIncrement;
  reg                 logic_pushPtr_willClear;
  reg        [7:0]    logic_pushPtr_valueNext;
  reg        [7:0]    logic_pushPtr_value;
  wire                logic_pushPtr_willOverflowIfInc;
  wire                logic_pushPtr_willOverflow;
  reg                 logic_popPtr_willIncrement;
  reg                 logic_popPtr_willClear;
  reg        [7:0]    logic_popPtr_valueNext;
  reg        [7:0]    logic_popPtr_value;
  wire                logic_popPtr_willOverflowIfInc;
  wire                logic_popPtr_willOverflow;
  wire                logic_ptrMatch;
  reg                 logic_risingOccupancy;
  wire                logic_pushing;
  wire                logic_popping;
  wire                logic_empty;
  wire                logic_full;
  reg                 _zz_io_pop_valid;
  wire                when_Stream_l1101;
  wire       [7:0]    logic_ptrDif;
  (* ram_style = "block" *) reg [63:0] logic_ram [0:255];

  assign _zz_logic_pushPtr_valueNext_1 = logic_pushPtr_willIncrement;
  assign _zz_logic_pushPtr_valueNext = {7'd0, _zz_logic_pushPtr_valueNext_1};
  assign _zz_logic_popPtr_valueNext_1 = logic_popPtr_willIncrement;
  assign _zz_logic_popPtr_valueNext = {7'd0, _zz_logic_popPtr_valueNext_1};
  assign _zz_io_availability = (logic_popPtr_value - logic_pushPtr_value);
  assign _zz_io_pop_payload = 1'b1;
  always @(posedge srio_clk) begin
    if(_zz_io_pop_payload) begin
      _zz_logic_ram_port0 <= logic_ram[logic_popPtr_valueNext];
    end
  end

  always @(posedge srio_clk) begin
    if(_zz_1) begin
      logic_ram[logic_pushPtr_value] <= io_push_payload;
    end
  end

  always @(*) begin
    _zz_1 = 1'b0; // @[when.scala 47:16]
    if(logic_pushing) begin
      _zz_1 = 1'b1; // @[when.scala 52:10]
    end
  end

  always @(*) begin
    logic_pushPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_pushing) begin
      logic_pushPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_pushPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_pushPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_pushPtr_willOverflowIfInc = (logic_pushPtr_value == 8'hff); // @[BaseType.scala 305:24]
  assign logic_pushPtr_willOverflow = (logic_pushPtr_willOverflowIfInc && logic_pushPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_pushPtr_valueNext = (logic_pushPtr_value + _zz_logic_pushPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_pushPtr_willClear) begin
      logic_pushPtr_valueNext = 8'h0; // @[Utils.scala 558:15]
    end
  end

  always @(*) begin
    logic_popPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_popping) begin
      logic_popPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_popPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_popPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_popPtr_willOverflowIfInc = (logic_popPtr_value == 8'hff); // @[BaseType.scala 305:24]
  assign logic_popPtr_willOverflow = (logic_popPtr_willOverflowIfInc && logic_popPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_popPtr_valueNext = (logic_popPtr_value + _zz_logic_popPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_popPtr_willClear) begin
      logic_popPtr_valueNext = 8'h0; // @[Utils.scala 558:15]
    end
  end

  assign logic_ptrMatch = (logic_pushPtr_value == logic_popPtr_value); // @[BaseType.scala 305:24]
  assign logic_pushing = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign logic_popping = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign logic_empty = (logic_ptrMatch && (! logic_risingOccupancy)); // @[BaseType.scala 305:24]
  assign logic_full = (logic_ptrMatch && logic_risingOccupancy); // @[BaseType.scala 305:24]
  assign io_push_ready = (! logic_full); // @[Stream.scala 1097:19]
  assign io_pop_valid = ((! logic_empty) && (! (_zz_io_pop_valid && (! logic_full)))); // @[Stream.scala 1098:18]
  assign io_pop_payload = _zz_logic_ram_port0; // @[Stream.scala 1099:20]
  assign when_Stream_l1101 = (logic_pushing != logic_popping); // @[BaseType.scala 305:24]
  assign logic_ptrDif = (logic_pushPtr_value - logic_popPtr_value); // @[BaseType.scala 299:24]
  assign io_occupancy = {(logic_risingOccupancy && logic_ptrMatch),logic_ptrDif}; // @[Stream.scala 1114:20]
  assign io_availability = {((! logic_risingOccupancy) && logic_ptrMatch),_zz_io_availability}; // @[Stream.scala 1115:23]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      logic_pushPtr_value <= 8'h0; // @[Data.scala 400:33]
      logic_popPtr_value <= 8'h0; // @[Data.scala 400:33]
      logic_risingOccupancy <= 1'b0; // @[Data.scala 400:33]
      _zz_io_pop_valid <= 1'b0; // @[Data.scala 400:33]
    end else begin
      logic_pushPtr_value <= logic_pushPtr_valueNext; // @[Reg.scala 39:30]
      logic_popPtr_value <= logic_popPtr_valueNext; // @[Reg.scala 39:30]
      _zz_io_pop_valid <= (logic_popPtr_valueNext == logic_pushPtr_value); // @[Reg.scala 39:30]
      if(when_Stream_l1101) begin
        logic_risingOccupancy <= logic_pushing; // @[Stream.scala 1102:23]
      end
      if(io_flush) begin
        logic_risingOccupancy <= 1'b0; // @[Stream.scala 1129:23]
      end
    end
  end


endmodule

module Target (
  output              m_axis_tresp_tvalid,
  input               m_axis_tresp_tready,
  output              m_axis_tresp_tlast,
  output     [63:0]   m_axis_tresp_tdata,
  output     [7:0]    m_axis_tresp_tkeep,
  output     [31:0]   m_axis_tresp_tuser,
  input               s_axis_treq_tvalid,
  output              s_axis_treq_tready,
  input               s_axis_treq_tlast,
  input      [63:0]   s_axis_treq_tdata,
  input      [7:0]    s_axis_treq_tkeep,
  input      [31:0]   s_axis_treq_tuser,
  output     [8:0]    simplebus_RADDR,
  input      [63:0]   simplebus_RDATA,
  output              simplebus_RENABLE,
  output     [8:0]    simplebus_WADDR,
  output     [63:0]   simplebus_WDATA,
  output              simplebus_WENABLE,
  output     [15:0]   doorbell_info,
  output              doorbell_intr,
  output              busy,
  input               srio_clk,
  input               reset
);
  localparam SrioFtype_NREAD = 4'd2;
  localparam SrioFtype_NWRITE = 4'd5;
  localparam SrioFtype_SWRITE = 4'd6;
  localparam SrioFtype_DOORB = 4'd10;
  localparam SrioFtype_MESSG = 4'd11;
  localparam SrioFtype_RESP = 4'd13;
  localparam SrioFtype_FTYPE9 = 4'd9;
  localparam SrioTtype_TNWR = 4'd4;
  localparam SrioTtype_TNWR_R = 4'd5;
  localparam SrioTtype_TNDATA = 4'd0;
  localparam SrioTtype_TWDATA = 4'd8;

  wire       [8:0]    _zz_data_store_waddr;
  wire       [4:0]    _zz_number_of_data_beats;
  wire       [8:0]    _zz_data_store_raddr;
  wire       [8:0]    _zz_data_store_raddr_1;
  wire                busy_1;
  reg                 doorbell_intr_1;
  wire       [7:0]    current_tid;
  wire       [3:0]    current_ftype;
  wire       [3:0]    current_ttype;
  wire       [7:0]    current_size;
  wire       [1:0]    current_prio;
  wire       [33:0]   current_addr;
  wire       [15:0]   current_srcid;
  wire       [47:0]   response_data_in_d;
  reg        [47:0]   response_data_in;
  wire       [15:0]   doorbell_info_d;
  wire                target_target_req_stream_fire;
  wire                when_Target_l32;
  reg        [15:0]   doorbell_info_1;
  wire                target_target_req_stream_fire_1;
  reg                 first_beat;
  wire                target_target_req_stream_fire_2;
  wire                when_Target_l40;
  wire                target_target_req_stream_fire_3;
  reg                 generate_a_response;
  wire                target_target_req_stream_fire_4;
  wire                when_Target_l49;
  reg                 capture_data;
  wire                target_target_req_stream_fire_5;
  wire                when_Target_l59;
  wire                target_target_req_stream_fire_6;
  wire                when_Target_l61;
  wire                target_target_req_stream_fire_7;
  wire                data_store_wen;
  reg        [8:0]    data_store_waddr;
  wire                target_target_req_stream_fire_8;
  wire                when_Target_l70;
  wire                target_target_req_stream_fire_9;
  reg        [47:0]   response_data_out_d;
  reg        [47:0]   response_data_out;
  wire       [7:0]    response_tid;
  wire       [3:0]    response_ftype;
  wire       [7:0]    response_size;
  wire       [1:0]    response_prio;
  wire       [8:0]    starting_read_addr;
  wire                pull_from_store;
  wire       [3:0]    responding_ttype;
  reg        [5:0]    current_beat_cnt;
  reg        [5:0]    number_of_data_beats;
  wire                when_Target_l95;
  wire                target_target_resp_stream_fire;
  wire                when_Target_l101;
  wire                target_target_resp_stream_fire_1;
  reg                 tresp_tlast;
  wire                when_Target_l110;
  wire                target_target_resp_stream_fire_2;
  wire                target_target_resp_stream_fire_3;
  wire                when_Target_l112;
  wire                when_Target_l114;
  reg                 generate_rsp;
  reg                 generate_rsp_d;
  reg                 pull_from_store_d;
  wire                when_Target_l125;
  reg        [8:0]    data_store_raddr;
  wire                when_Target_l136;
  wire                target_target_resp_stream_fire_4;
  wire                when_Target_l138;
  reg                 tresp_tvalid;
  wire                when_Target_l145;
  wire                target_target_resp_stream_fire_5;
  wire                when_Target_l147;
  wire       [63:0]   header_beat;
  reg        [63:0]   tresp_tdata;
  reg        [63:0]   data_store_dout;
  wire                target_target_resp_stream_fire_6;
  wire                when_Target_l169;
  wire                target_target_resp_stream_fire_7;
  wire                when_Target_l171;
  `ifndef SYNTHESIS
  reg [47:0] responding_ttype_string;
  `endif


  assign _zz_data_store_waddr = (data_store_waddr + 9'h008);
  assign _zz_number_of_data_beats = response_size[7 : 3];
  assign _zz_data_store_raddr = (data_store_raddr + 9'h008);
  assign _zz_data_store_raddr_1 = (data_store_raddr + 9'h008);
  `ifndef SYNTHESIS
  always @(*) begin
    case(responding_ttype)
      SrioTtype_TNWR : responding_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : responding_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : responding_ttype_string = "TNDATA";
      SrioTtype_TWDATA : responding_ttype_string = "TWDATA";
      default : responding_ttype_string = "??????";
    endcase
  end
  `endif

  assign busy_1 = 1'b0;
  assign current_tid = s_axis_treq_tdata[63 : 56]; // @[BaseType.scala 299:24]
  assign current_ftype = s_axis_treq_tdata[55 : 52]; // @[BaseType.scala 299:24]
  assign current_ttype = s_axis_treq_tdata[51 : 48]; // @[BaseType.scala 299:24]
  assign current_size = s_axis_treq_tdata[43 : 36]; // @[BaseType.scala 299:24]
  assign current_prio = (s_axis_treq_tdata[46 : 45] + 2'b01); // @[BaseType.scala 299:24]
  assign current_addr = s_axis_treq_tdata[33 : 0]; // @[Bits.scala 152:9]
  assign current_srcid = s_axis_treq_tuser[31 : 16]; // @[BaseType.scala 299:24]
  assign response_data_in_d = {{{{{{current_srcid,(current_addr[23 : 16] == 8'h12)},current_addr[8 : 0]},current_prio},current_tid},current_ftype},current_size}; // @[BaseType.scala 299:24]
  assign doorbell_info_d = s_axis_treq_tdata[31 : 16]; // @[BaseType.scala 299:24]
  assign target_target_req_stream_fire = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l32 = ((current_ftype == SrioFtype_DOORB) && target_target_req_stream_fire); // @[BaseType.scala 305:24]
  assign doorbell_info = doorbell_info_1; // @[Target.scala 33:20]
  assign target_target_req_stream_fire_1 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign doorbell_intr = doorbell_intr_1; // @[Target.scala 36:20]
  assign target_target_req_stream_fire_2 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l40 = (target_target_req_stream_fire_2 && s_axis_treq_tlast); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_3 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_4 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l49 = ((first_beat && target_target_req_stream_fire_4) && (current_addr[23 : 16] == 8'h12)); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_5 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l59 = (first_beat && target_target_req_stream_fire_5); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_6 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l61 = (target_target_req_stream_fire_6 && s_axis_treq_tlast); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_7 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign data_store_wen = (capture_data && target_target_req_stream_fire_7); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_8 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign when_Target_l70 = (first_beat && target_target_req_stream_fire_8); // @[BaseType.scala 305:24]
  assign target_target_req_stream_fire_9 = (s_axis_treq_tvalid && s_axis_treq_tready); // @[BaseType.scala 305:24]
  assign s_axis_treq_tready = 1'b1; // @[Target.scala 77:37]
  assign response_tid = response_data_out[19 : 12]; // @[BaseType.scala 299:24]
  assign response_ftype = response_data_out[11 : 8]; // @[BaseType.scala 299:24]
  assign response_size = response_data_out[7 : 0]; // @[BaseType.scala 299:24]
  assign response_prio = response_data_out[21 : 20]; // @[BaseType.scala 299:24]
  assign starting_read_addr = response_data_out[30 : 22]; // @[BaseType.scala 299:24]
  assign pull_from_store = (((response_ftype == SrioFtype_NREAD) && response_data_out[31]) ? 1'b1 : 1'b0); // @[Expression.scala 1420:25]
  assign responding_ttype = ((response_ftype == SrioFtype_NREAD) ? SrioTtype_TWDATA : SrioTtype_TNDATA); // @[Expression.scala 1420:25]
  assign when_Target_l95 = (current_beat_cnt == 6'h0); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l101 = (target_target_resp_stream_fire && m_axis_tresp_tlast); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_1 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l110 = (responding_ttype == SrioTtype_TNDATA); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_2 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_3 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l112 = ((current_beat_cnt == number_of_data_beats) && target_target_resp_stream_fire_3); // @[BaseType.scala 305:24]
  assign when_Target_l114 = (m_axis_tresp_tready || (! m_axis_tresp_tvalid)); // @[BaseType.scala 305:24]
  assign m_axis_tresp_tlast = tresp_tlast; // @[Target.scala 119:37]
  assign when_Target_l125 = (generate_rsp_d && (current_beat_cnt == 6'h0)); // @[BaseType.scala 305:24]
  assign busy = pull_from_store_d; // @[Target.scala 133:11]
  assign when_Target_l136 = (pull_from_store_d && (current_beat_cnt == 6'h0)); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_4 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l138 = (pull_from_store_d && target_target_resp_stream_fire_4); // @[BaseType.scala 305:24]
  assign when_Target_l145 = (pull_from_store_d && (current_beat_cnt == 6'h0)); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_5 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l147 = (target_target_resp_stream_fire_5 && m_axis_tresp_tlast); // @[BaseType.scala 305:24]
  assign m_axis_tresp_tvalid = tresp_tvalid; // @[Target.scala 152:38]
  assign header_beat = {{{{{response_tid,SrioFtype_RESP},responding_ttype},1'b0},response_prio},45'h0}; // @[BaseType.scala 299:24]
  assign simplebus_RADDR = data_store_raddr; // @[Target.scala 161:22]
  assign simplebus_RENABLE = 1'b1; // @[Target.scala 162:24]
  assign simplebus_WENABLE = data_store_wen; // @[Target.scala 163:24]
  assign simplebus_WADDR = data_store_waddr; // @[Target.scala 164:22]
  assign simplebus_WDATA = s_axis_treq_tdata; // @[Target.scala 165:22]
  assign target_target_resp_stream_fire_6 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l169 = ((current_beat_cnt == 6'h0) && (! target_target_resp_stream_fire_6)); // @[BaseType.scala 305:24]
  assign target_target_resp_stream_fire_7 = (m_axis_tresp_tvalid && m_axis_tresp_tready); // @[BaseType.scala 305:24]
  assign when_Target_l171 = (pull_from_store && target_target_resp_stream_fire_7); // @[BaseType.scala 305:24]
  assign m_axis_tresp_tdata = tresp_tdata; // @[Target.scala 179:49]
  assign m_axis_tresp_tkeep = 8'hff; // @[Target.scala 181:38]
  assign m_axis_tresp_tuser = 32'h000000ff; // @[Target.scala 182:38]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      doorbell_intr_1 <= 1'b0; // @[Data.scala 400:33]
      first_beat <= 1'b1; // @[Data.scala 400:33]
      generate_a_response <= 1'b0; // @[Data.scala 400:33]
      capture_data <= 1'b0; // @[Data.scala 400:33]
      data_store_waddr <= 9'h0; // @[Data.scala 400:33]
      response_data_out_d <= 48'h0; // @[Data.scala 400:33]
      response_data_out <= 48'h0; // @[Data.scala 400:33]
      current_beat_cnt <= 6'h0; // @[Data.scala 400:33]
      tresp_tlast <= 1'b0; // @[Data.scala 400:33]
      generate_rsp <= 1'b0; // @[Data.scala 400:33]
      generate_rsp_d <= 1'b0; // @[Data.scala 400:33]
      pull_from_store_d <= 1'b0; // @[Data.scala 400:33]
      data_store_raddr <= 9'h0; // @[Data.scala 400:33]
      tresp_tvalid <= 1'b0; // @[Data.scala 400:33]
    end else begin
      doorbell_intr_1 <= ((current_ftype == SrioFtype_DOORB) && target_target_req_stream_fire_1); // @[Target.scala 35:17]
      if(when_Target_l40) begin
        first_beat <= 1'b1; // @[Target.scala 41:16]
      end else begin
        if(target_target_req_stream_fire_3) begin
          first_beat <= 1'b0; // @[Target.scala 43:16]
        end else begin
          first_beat <= first_beat; // @[Target.scala 45:16]
        end
      end
      if(when_Target_l49) begin
        generate_a_response <= ((((current_ftype == SrioFtype_NREAD) || (current_ftype == SrioFtype_DOORB)) || (current_ftype == SrioFtype_MESSG)) || ((current_ftype == SrioFtype_NWRITE) && (current_ttype == SrioTtype_TNWR_R))); // @[Target.scala 50:25]
      end else begin
        generate_a_response <= 1'b0; // @[Target.scala 55:25]
      end
      if(when_Target_l59) begin
        capture_data <= ((current_ftype == SrioFtype_SWRITE) || (current_ftype == SrioFtype_NWRITE)); // @[Target.scala 60:18]
      end else begin
        if(when_Target_l61) begin
          capture_data <= 1'b0; // @[Target.scala 62:18]
        end else begin
          capture_data <= capture_data; // @[Target.scala 64:18]
        end
      end
      if(when_Target_l70) begin
        data_store_waddr <= current_addr[8 : 0]; // @[Target.scala 71:22]
      end else begin
        if(target_target_req_stream_fire_9) begin
          data_store_waddr <= _zz_data_store_waddr; // @[Target.scala 73:22]
        end else begin
          data_store_waddr <= data_store_waddr; // @[Target.scala 75:22]
        end
      end
      if(generate_a_response) begin
        response_data_out_d <= response_data_in; // @[Target.scala 79:40]
      end
      response_data_out <= response_data_out_d; // @[Reg.scala 39:30]
      if(when_Target_l101) begin
        current_beat_cnt <= 6'h0; // @[Target.scala 102:22]
      end else begin
        if(target_target_resp_stream_fire_1) begin
          current_beat_cnt <= (current_beat_cnt + 6'h01); // @[Target.scala 104:22]
        end else begin
          current_beat_cnt <= current_beat_cnt; // @[Target.scala 106:22]
        end
      end
      if(when_Target_l110) begin
        tresp_tlast <= (! (target_target_resp_stream_fire_2 && m_axis_tresp_tlast)); // @[Target.scala 111:17]
      end else begin
        if(when_Target_l112) begin
          tresp_tlast <= (! tresp_tlast); // @[Target.scala 113:17]
        end else begin
          if(when_Target_l114) begin
            tresp_tlast <= 1'b0; // @[Target.scala 115:17]
          end else begin
            tresp_tlast <= tresp_tlast; // @[Target.scala 117:17]
          end
        end
      end
      generate_rsp <= generate_a_response; // @[Reg.scala 39:30]
      generate_rsp_d <= generate_rsp; // @[Reg.scala 39:30]
      if(when_Target_l125) begin
        pull_from_store_d <= 1'b1; // @[Target.scala 126:23]
      end else begin
        if(m_axis_tresp_tlast) begin
          pull_from_store_d <= 1'b0; // @[Target.scala 128:23]
        end else begin
          pull_from_store_d <= pull_from_store_d; // @[Target.scala 130:23]
        end
      end
      if(when_Target_l136) begin
        data_store_raddr <= _zz_data_store_raddr; // @[Target.scala 137:22]
      end else begin
        if(when_Target_l138) begin
          data_store_raddr <= _zz_data_store_raddr_1; // @[Target.scala 139:22]
        end else begin
          data_store_raddr <= starting_read_addr; // @[Target.scala 141:22]
        end
      end
      if(when_Target_l145) begin
        tresp_tvalid <= 1'b1; // @[Target.scala 146:18]
      end else begin
        if(when_Target_l147) begin
          tresp_tvalid <= 1'b0; // @[Target.scala 148:18]
        end else begin
          tresp_tvalid <= tresp_tvalid; // @[Target.scala 150:18]
        end
      end
    end
  end

  always @(posedge srio_clk) begin
    response_data_in <= response_data_in_d; // @[Reg.scala 39:30]
    if(when_Target_l32) begin
      doorbell_info_1 <= doorbell_info_d; // @[Target.scala 32:34]
    end
    if(when_Target_l95) begin
      number_of_data_beats <= {1'd0, _zz_number_of_data_beats}; // @[Target.scala 96:26]
    end else begin
      number_of_data_beats <= number_of_data_beats; // @[Target.scala 98:26]
    end
    if(when_Target_l169) begin
      tresp_tdata <= header_beat; // @[Target.scala 170:17]
    end else begin
      if(when_Target_l171) begin
        tresp_tdata <= simplebus_RDATA; // @[Target.scala 173:17]
      end else begin
        tresp_tdata <= tresp_tdata; // @[Target.scala 175:17]
      end
    end
  end


endmodule

module Srio_Regif (
  input      [8:0]    simplebus_RADDR,
  output     [63:0]   simplebus_RDATA,
  input               simplebus_RENABLE,
  input      [8:0]    simplebus_WADDR,
  input      [63:0]   simplebus_WDATA,
  input               simplebus_WENABLE,
  input      [63:0]   data_in_0,
  input      [63:0]   data_in_1,
  input      [63:0]   data_in_2,
  input      [63:0]   data_in_3,
  input      [63:0]   data_in_4,
  input      [63:0]   data_in_5,
  input      [63:0]   data_in_6,
  input      [63:0]   data_in_7,
  input      [63:0]   data_in_8,
  input      [63:0]   data_in_9,
  input      [63:0]   data_in_10,
  input      [63:0]   data_in_11,
  input      [63:0]   data_in_12,
  input      [63:0]   data_in_13,
  input      [63:0]   data_in_14,
  input      [63:0]   data_in_15,
  output     [63:0]   data_out_0,
  output     [63:0]   data_out_1,
  output     [63:0]   data_out_2,
  output     [63:0]   data_out_3,
  output     [63:0]   data_out_4,
  output     [63:0]   data_out_5,
  output     [63:0]   data_out_6,
  output     [63:0]   data_out_7,
  output     [63:0]   data_out_8,
  output     [63:0]   data_out_9,
  output     [63:0]   data_out_10,
  output     [63:0]   data_out_11,
  output     [63:0]   data_out_12,
  output     [63:0]   data_out_13,
  output     [63:0]   data_out_14,
  output     [63:0]   data_out_15,
  input               srio_clk,
  input               reset
);

  reg                 busslave_readError;
  reg        [63:0]   busslave_readData;
  wire                read_hit_0x0000;
  wire                write_hit_0x0000;
  wire       [63:0]   Version;
  wire                read_hit_0x0008;
  wire                write_hit_0x0008;
  wire                read_hit_0x0010;
  wire                write_hit_0x0010;
  wire                read_hit_0x0018;
  wire                write_hit_0x0018;
  wire                read_hit_0x0020;
  wire                write_hit_0x0020;
  wire                read_hit_0x0028;
  wire                write_hit_0x0028;
  wire                read_hit_0x0030;
  wire                write_hit_0x0030;
  wire                read_hit_0x0038;
  wire                write_hit_0x0038;
  wire                read_hit_0x0040;
  wire                write_hit_0x0040;
  wire                read_hit_0x0048;
  wire                write_hit_0x0048;
  wire                read_hit_0x0050;
  wire                write_hit_0x0050;
  wire                read_hit_0x0058;
  wire                write_hit_0x0058;
  wire                read_hit_0x0060;
  wire                write_hit_0x0060;
  wire                read_hit_0x0068;
  wire                write_hit_0x0068;
  wire                read_hit_0x0070;
  wire                write_hit_0x0070;
  wire                read_hit_0x0078;
  wire                write_hit_0x0078;
  wire                read_hit_0x0080;
  wire                write_hit_0x0080;
  wire                read_hit_0x0088;
  wire                write_hit_0x0088;
  reg        [63:0]   _zz_data_out_0;
  wire                read_hit_0x0090;
  wire                write_hit_0x0090;
  reg        [63:0]   _zz_data_out_1;
  wire                read_hit_0x0098;
  wire                write_hit_0x0098;
  reg        [63:0]   _zz_data_out_2;
  wire                read_hit_0x00a0;
  wire                write_hit_0x00a0;
  reg        [63:0]   _zz_data_out_3;
  wire                read_hit_0x00a8;
  wire                write_hit_0x00a8;
  reg        [63:0]   _zz_data_out_4;
  wire                read_hit_0x00b0;
  wire                write_hit_0x00b0;
  reg        [63:0]   _zz_data_out_5;
  wire                read_hit_0x00b8;
  wire                write_hit_0x00b8;
  reg        [63:0]   _zz_data_out_6;
  wire                read_hit_0x00c0;
  wire                write_hit_0x00c0;
  reg        [63:0]   _zz_data_out_7;
  wire                read_hit_0x00c8;
  wire                write_hit_0x00c8;
  reg        [63:0]   _zz_data_out_8;
  wire                read_hit_0x00d0;
  wire                write_hit_0x00d0;
  reg        [63:0]   _zz_data_out_9;
  wire                read_hit_0x00d8;
  wire                write_hit_0x00d8;
  reg        [63:0]   _zz_data_out_10;
  wire                read_hit_0x00e0;
  wire                write_hit_0x00e0;
  reg        [63:0]   _zz_data_out_11;
  wire                read_hit_0x00e8;
  wire                write_hit_0x00e8;
  reg        [63:0]   _zz_data_out_12;
  wire                read_hit_0x00f0;
  wire                write_hit_0x00f0;
  reg        [63:0]   _zz_data_out_13;
  wire                read_hit_0x00f8;
  wire                write_hit_0x00f8;
  reg        [63:0]   _zz_data_out_14;
  wire                read_hit_0x0100;
  wire                write_hit_0x0100;
  reg        [63:0]   _zz_data_out_15;

  assign simplebus_RDATA = busslave_readData; // @[SimpleBus.scala 47:13]
  assign read_hit_0x0000 = ((simplebus_RADDR == 9'h0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0000 = ((simplebus_WADDR == 9'h0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign Version = 64'h0000202206011514; // @[Srio_Regif.scala 22:11]
  assign read_hit_0x0008 = ((simplebus_RADDR == 9'h008) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0008 = ((simplebus_WADDR == 9'h008) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0010 = ((simplebus_RADDR == 9'h010) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0010 = ((simplebus_WADDR == 9'h010) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0018 = ((simplebus_RADDR == 9'h018) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0018 = ((simplebus_WADDR == 9'h018) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0020 = ((simplebus_RADDR == 9'h020) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0020 = ((simplebus_WADDR == 9'h020) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0028 = ((simplebus_RADDR == 9'h028) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0028 = ((simplebus_WADDR == 9'h028) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0030 = ((simplebus_RADDR == 9'h030) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0030 = ((simplebus_WADDR == 9'h030) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0038 = ((simplebus_RADDR == 9'h038) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0038 = ((simplebus_WADDR == 9'h038) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0040 = ((simplebus_RADDR == 9'h040) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0040 = ((simplebus_WADDR == 9'h040) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0048 = ((simplebus_RADDR == 9'h048) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0048 = ((simplebus_WADDR == 9'h048) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0050 = ((simplebus_RADDR == 9'h050) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0050 = ((simplebus_WADDR == 9'h050) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0058 = ((simplebus_RADDR == 9'h058) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0058 = ((simplebus_WADDR == 9'h058) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0060 = ((simplebus_RADDR == 9'h060) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0060 = ((simplebus_WADDR == 9'h060) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0068 = ((simplebus_RADDR == 9'h068) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0068 = ((simplebus_WADDR == 9'h068) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0070 = ((simplebus_RADDR == 9'h070) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0070 = ((simplebus_WADDR == 9'h070) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0078 = ((simplebus_RADDR == 9'h078) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0078 = ((simplebus_WADDR == 9'h078) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0080 = ((simplebus_RADDR == 9'h080) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0080 = ((simplebus_WADDR == 9'h080) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign read_hit_0x0088 = ((simplebus_RADDR == 9'h088) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0088 = ((simplebus_WADDR == 9'h088) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_0 = _zz_data_out_0; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x0090 = ((simplebus_RADDR == 9'h090) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0090 = ((simplebus_WADDR == 9'h090) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_1 = _zz_data_out_1; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x0098 = ((simplebus_RADDR == 9'h098) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0098 = ((simplebus_WADDR == 9'h098) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_2 = _zz_data_out_2; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00a0 = ((simplebus_RADDR == 9'h0a0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a0 = ((simplebus_WADDR == 9'h0a0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_3 = _zz_data_out_3; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00a8 = ((simplebus_RADDR == 9'h0a8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a8 = ((simplebus_WADDR == 9'h0a8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_4 = _zz_data_out_4; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00b0 = ((simplebus_RADDR == 9'h0b0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b0 = ((simplebus_WADDR == 9'h0b0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_5 = _zz_data_out_5; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00b8 = ((simplebus_RADDR == 9'h0b8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b8 = ((simplebus_WADDR == 9'h0b8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_6 = _zz_data_out_6; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00c0 = ((simplebus_RADDR == 9'h0c0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c0 = ((simplebus_WADDR == 9'h0c0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_7 = _zz_data_out_7; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00c8 = ((simplebus_RADDR == 9'h0c8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c8 = ((simplebus_WADDR == 9'h0c8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_8 = _zz_data_out_8; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00d0 = ((simplebus_RADDR == 9'h0d0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d0 = ((simplebus_WADDR == 9'h0d0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_9 = _zz_data_out_9; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00d8 = ((simplebus_RADDR == 9'h0d8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d8 = ((simplebus_WADDR == 9'h0d8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_10 = _zz_data_out_10; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00e0 = ((simplebus_RADDR == 9'h0e0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e0 = ((simplebus_WADDR == 9'h0e0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_11 = _zz_data_out_11; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00e8 = ((simplebus_RADDR == 9'h0e8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e8 = ((simplebus_WADDR == 9'h0e8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_12 = _zz_data_out_12; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00f0 = ((simplebus_RADDR == 9'h0f0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f0 = ((simplebus_WADDR == 9'h0f0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_13 = _zz_data_out_13; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x00f8 = ((simplebus_RADDR == 9'h0f8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f8 = ((simplebus_WADDR == 9'h0f8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_14 = _zz_data_out_14; // @[Srio_Regif.scala 33:20]
  assign read_hit_0x0100 = ((simplebus_RADDR == 9'h100) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0100 = ((simplebus_WADDR == 9'h100) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_15 = _zz_data_out_15; // @[Srio_Regif.scala 33:20]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      busslave_readError <= 1'b0; // @[Data.scala 400:33]
      busslave_readData <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_0 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_1 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_2 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_3 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_4 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_5 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_6 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_7 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_8 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_9 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_10 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_11 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_12 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_13 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_14 <= 64'h0; // @[Data.scala 400:33]
      _zz_data_out_15 <= 64'h0; // @[Data.scala 400:33]
    end else begin
      if(write_hit_0x0088) begin
        _zz_data_out_0 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0090) begin
        _zz_data_out_1 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0098) begin
        _zz_data_out_2 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a0) begin
        _zz_data_out_3 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a8) begin
        _zz_data_out_4 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b0) begin
        _zz_data_out_5 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b8) begin
        _zz_data_out_6 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c0) begin
        _zz_data_out_7 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c8) begin
        _zz_data_out_8 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d0) begin
        _zz_data_out_9 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d8) begin
        _zz_data_out_10 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e0) begin
        _zz_data_out_11 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e8) begin
        _zz_data_out_12 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f0) begin
        _zz_data_out_13 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f8) begin
        _zz_data_out_14 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0100) begin
        _zz_data_out_15 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(simplebus_RENABLE) begin
        case(simplebus_RADDR)
          9'h0 : begin
            busslave_readData <= Version; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h008 : begin
            busslave_readData <= data_in_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h010 : begin
            busslave_readData <= data_in_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h018 : begin
            busslave_readData <= data_in_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h020 : begin
            busslave_readData <= data_in_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h028 : begin
            busslave_readData <= data_in_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h030 : begin
            busslave_readData <= data_in_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h038 : begin
            busslave_readData <= data_in_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h040 : begin
            busslave_readData <= data_in_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h048 : begin
            busslave_readData <= data_in_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h050 : begin
            busslave_readData <= data_in_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h058 : begin
            busslave_readData <= data_in_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h060 : begin
            busslave_readData <= data_in_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h068 : begin
            busslave_readData <= data_in_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h070 : begin
            busslave_readData <= data_in_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h078 : begin
            busslave_readData <= data_in_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h080 : begin
            busslave_readData <= data_in_15; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h088 : begin
            busslave_readData <= _zz_data_out_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h090 : begin
            busslave_readData <= _zz_data_out_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h098 : begin
            busslave_readData <= _zz_data_out_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a0 : begin
            busslave_readData <= _zz_data_out_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a8 : begin
            busslave_readData <= _zz_data_out_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b0 : begin
            busslave_readData <= _zz_data_out_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b8 : begin
            busslave_readData <= _zz_data_out_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c0 : begin
            busslave_readData <= _zz_data_out_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c8 : begin
            busslave_readData <= _zz_data_out_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d0 : begin
            busslave_readData <= _zz_data_out_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d8 : begin
            busslave_readData <= _zz_data_out_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e0 : begin
            busslave_readData <= _zz_data_out_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e8 : begin
            busslave_readData <= _zz_data_out_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f0 : begin
            busslave_readData <= _zz_data_out_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f8 : begin
            busslave_readData <= _zz_data_out_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h100 : begin
            busslave_readData <= _zz_data_out_15; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          default : begin
            busslave_readData <= 64'h0; // @[BusIfBase.scala 258:23]
            busslave_readError <= 1'b1; // @[BusIfBase.scala 259:23]
          end
        endcase
      end
      if(simplebus_WENABLE) begin
        busslave_readError <= 1'b0; // @[BusIfBase.scala 263:26]
      end
    end
  end


endmodule

//StreamFifo_3 replaced by StreamFifo_3

module StreamFifo_3 (
  input               io_push_valid,
  output              io_push_ready,
  input      [63:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [63:0]   io_pop_payload,
  input               io_flush,
  output     [8:0]    io_occupancy,
  output     [8:0]    io_availability,
  input               srio_clk,
  input               reset
);

  reg        [63:0]   _zz_logic_ram_port0;
  wire       [7:0]    _zz_logic_pushPtr_valueNext;
  wire       [0:0]    _zz_logic_pushPtr_valueNext_1;
  wire       [7:0]    _zz_logic_popPtr_valueNext;
  wire       [0:0]    _zz_logic_popPtr_valueNext_1;
  wire                _zz_logic_ram_port;
  wire                _zz_io_pop_payload;
  wire       [7:0]    _zz_io_availability;
  reg                 _zz_1;
  reg                 logic_pushPtr_willIncrement;
  reg                 logic_pushPtr_willClear;
  reg        [7:0]    logic_pushPtr_valueNext;
  reg        [7:0]    logic_pushPtr_value;
  wire                logic_pushPtr_willOverflowIfInc;
  wire                logic_pushPtr_willOverflow;
  reg                 logic_popPtr_willIncrement;
  reg                 logic_popPtr_willClear;
  reg        [7:0]    logic_popPtr_valueNext;
  reg        [7:0]    logic_popPtr_value;
  wire                logic_popPtr_willOverflowIfInc;
  wire                logic_popPtr_willOverflow;
  wire                logic_ptrMatch;
  reg                 logic_risingOccupancy;
  wire                logic_pushing;
  wire                logic_popping;
  wire                logic_empty;
  wire                logic_full;
  reg                 _zz_io_pop_valid;
  wire                when_Stream_l1101;
  wire       [7:0]    logic_ptrDif;
  reg [63:0] logic_ram [0:255];

  assign _zz_logic_pushPtr_valueNext_1 = logic_pushPtr_willIncrement;
  assign _zz_logic_pushPtr_valueNext = {7'd0, _zz_logic_pushPtr_valueNext_1};
  assign _zz_logic_popPtr_valueNext_1 = logic_popPtr_willIncrement;
  assign _zz_logic_popPtr_valueNext = {7'd0, _zz_logic_popPtr_valueNext_1};
  assign _zz_io_availability = (logic_popPtr_value - logic_pushPtr_value);
  assign _zz_io_pop_payload = 1'b1;
  always @(posedge srio_clk) begin
    if(_zz_io_pop_payload) begin
      _zz_logic_ram_port0 <= logic_ram[logic_popPtr_valueNext];
    end
  end

  always @(posedge srio_clk) begin
    if(_zz_1) begin
      logic_ram[logic_pushPtr_value] <= io_push_payload;
    end
  end

  always @(*) begin
    _zz_1 = 1'b0; // @[when.scala 47:16]
    if(logic_pushing) begin
      _zz_1 = 1'b1; // @[when.scala 52:10]
    end
  end

  always @(*) begin
    logic_pushPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_pushing) begin
      logic_pushPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_pushPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_pushPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_pushPtr_willOverflowIfInc = (logic_pushPtr_value == 8'hff); // @[BaseType.scala 305:24]
  assign logic_pushPtr_willOverflow = (logic_pushPtr_willOverflowIfInc && logic_pushPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_pushPtr_valueNext = (logic_pushPtr_value + _zz_logic_pushPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_pushPtr_willClear) begin
      logic_pushPtr_valueNext = 8'h0; // @[Utils.scala 558:15]
    end
  end

  always @(*) begin
    logic_popPtr_willIncrement = 1'b0; // @[Utils.scala 536:23]
    if(logic_popping) begin
      logic_popPtr_willIncrement = 1'b1; // @[Utils.scala 540:41]
    end
  end

  always @(*) begin
    logic_popPtr_willClear = 1'b0; // @[Utils.scala 537:19]
    if(io_flush) begin
      logic_popPtr_willClear = 1'b1; // @[Utils.scala 539:33]
    end
  end

  assign logic_popPtr_willOverflowIfInc = (logic_popPtr_value == 8'hff); // @[BaseType.scala 305:24]
  assign logic_popPtr_willOverflow = (logic_popPtr_willOverflowIfInc && logic_popPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_popPtr_valueNext = (logic_popPtr_value + _zz_logic_popPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_popPtr_willClear) begin
      logic_popPtr_valueNext = 8'h0; // @[Utils.scala 558:15]
    end
  end

  assign logic_ptrMatch = (logic_pushPtr_value == logic_popPtr_value); // @[BaseType.scala 305:24]
  assign logic_pushing = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign logic_popping = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign logic_empty = (logic_ptrMatch && (! logic_risingOccupancy)); // @[BaseType.scala 305:24]
  assign logic_full = (logic_ptrMatch && logic_risingOccupancy); // @[BaseType.scala 305:24]
  assign io_push_ready = (! logic_full); // @[Stream.scala 1097:19]
  assign io_pop_valid = ((! logic_empty) && (! (_zz_io_pop_valid && (! logic_full)))); // @[Stream.scala 1098:18]
  assign io_pop_payload = _zz_logic_ram_port0; // @[Stream.scala 1099:20]
  assign when_Stream_l1101 = (logic_pushing != logic_popping); // @[BaseType.scala 305:24]
  assign logic_ptrDif = (logic_pushPtr_value - logic_popPtr_value); // @[BaseType.scala 299:24]
  assign io_occupancy = {(logic_risingOccupancy && logic_ptrMatch),logic_ptrDif}; // @[Stream.scala 1114:20]
  assign io_availability = {((! logic_risingOccupancy) && logic_ptrMatch),_zz_io_availability}; // @[Stream.scala 1115:23]
  always @(posedge srio_clk or posedge reset) begin
    if(reset) begin
      logic_pushPtr_value <= 8'h0; // @[Data.scala 400:33]
      logic_popPtr_value <= 8'h0; // @[Data.scala 400:33]
      logic_risingOccupancy <= 1'b0; // @[Data.scala 400:33]
      _zz_io_pop_valid <= 1'b0; // @[Data.scala 400:33]
    end else begin
      logic_pushPtr_value <= logic_pushPtr_valueNext; // @[Reg.scala 39:30]
      logic_popPtr_value <= logic_popPtr_valueNext; // @[Reg.scala 39:30]
      _zz_io_pop_valid <= (logic_popPtr_valueNext == logic_pushPtr_value); // @[Reg.scala 39:30]
      if(when_Stream_l1101) begin
        logic_risingOccupancy <= logic_pushing; // @[Stream.scala 1102:23]
      end
      if(io_flush) begin
        logic_risingOccupancy <= 1'b0; // @[Stream.scala 1129:23]
      end
    end
  end


endmodule
