// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Intitaor_TestDemo
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module Intitaor_TestDemo (
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
  output              iresp_stream_valid,
  input               iresp_stream_ready,
  output     [63:0]   iresp_stream_payload,
  input               clk,
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

  wire       [33:0]   intitaor_test_1_usercmd_user_addr;
  wire       [3:0]    intitaor_test_1_usercmd_user_ftype;
  wire       [3:0]    intitaor_test_1_usercmd_user_ttype;
  wire       [7:0]    intitaor_test_1_usercmd_user_size;
  wire       [1:0]    intitaor_test_1_usercmd_user_prio;
  wire       [7:0]    intitaor_test_1_usercmd_user_tid;
  wire                intitaor_test_1_usercmd_user_data_valid;
  wire       [63:0]   intitaor_test_1_usercmd_user_data_payload;
  wire                intitaor_test_1_send_start;
  wire                intitaor_1_m_axis_ireq_tvalid;
  wire                intitaor_1_m_axis_ireq_tlast;
  wire       [63:0]   intitaor_1_m_axis_ireq_tdata;
  wire       [7:0]    intitaor_1_m_axis_ireq_tkeep;
  wire       [31:0]   intitaor_1_m_axis_ireq_tuser;
  wire                intitaor_1_s_axis_iresp_tready;
  wire                intitaor_1_usercmd_user_data_ready;
  wire                intitaor_1_iresp_stream_valid;
  wire       [63:0]   intitaor_1_iresp_stream_payload;

  Intitaor_Test intitaor_test_1 (
    .usercmd_user_addr         (intitaor_test_1_usercmd_user_addr[33:0]        ), //o
    .usercmd_user_ftype        (intitaor_test_1_usercmd_user_ftype[3:0]        ), //o
    .usercmd_user_ttype        (intitaor_test_1_usercmd_user_ttype[3:0]        ), //o
    .usercmd_user_size         (intitaor_test_1_usercmd_user_size[7:0]         ), //o
    .usercmd_user_prio         (intitaor_test_1_usercmd_user_prio[1:0]         ), //o
    .usercmd_user_tid          (intitaor_test_1_usercmd_user_tid[7:0]          ), //o
    .usercmd_user_data_valid   (intitaor_test_1_usercmd_user_data_valid        ), //o
    .usercmd_user_data_ready   (intitaor_1_usercmd_user_data_ready             ), //i
    .usercmd_user_data_payload (intitaor_test_1_usercmd_user_data_payload[63:0]), //o
    .send_start                (intitaor_test_1_send_start                     ), //o
    .clk                       (clk                                            ), //i
    .reset                     (reset                                          )  //i
  );
  Intitaor intitaor_1 (
    .m_axis_ireq_tvalid        (intitaor_1_m_axis_ireq_tvalid                  ), //o
    .m_axis_ireq_tready        (m_axis_ireq_tready                             ), //i
    .m_axis_ireq_tlast         (intitaor_1_m_axis_ireq_tlast                   ), //o
    .m_axis_ireq_tdata         (intitaor_1_m_axis_ireq_tdata[63:0]             ), //o
    .m_axis_ireq_tkeep         (intitaor_1_m_axis_ireq_tkeep[7:0]              ), //o
    .m_axis_ireq_tuser         (intitaor_1_m_axis_ireq_tuser[31:0]             ), //o
    .s_axis_iresp_tvalid       (s_axis_iresp_tvalid                            ), //i
    .s_axis_iresp_tready       (intitaor_1_s_axis_iresp_tready                 ), //o
    .s_axis_iresp_tlast        (s_axis_iresp_tlast                             ), //i
    .s_axis_iresp_tdata        (s_axis_iresp_tdata[63:0]                       ), //i
    .s_axis_iresp_tkeep        (s_axis_iresp_tkeep[7:0]                        ), //i
    .s_axis_iresp_tuser        (s_axis_iresp_tuser[31:0]                       ), //i
    .usercmd_user_addr         (intitaor_test_1_usercmd_user_addr[33:0]        ), //i
    .usercmd_user_ftype        (intitaor_test_1_usercmd_user_ftype[3:0]        ), //i
    .usercmd_user_ttype        (intitaor_test_1_usercmd_user_ttype[3:0]        ), //i
    .usercmd_user_size         (intitaor_test_1_usercmd_user_size[7:0]         ), //i
    .usercmd_user_prio         (intitaor_test_1_usercmd_user_prio[1:0]         ), //i
    .usercmd_user_tid          (intitaor_test_1_usercmd_user_tid[7:0]          ), //i
    .usercmd_user_data_valid   (intitaor_test_1_usercmd_user_data_valid        ), //i
    .usercmd_user_data_ready   (intitaor_1_usercmd_user_data_ready             ), //o
    .usercmd_user_data_payload (intitaor_test_1_usercmd_user_data_payload[63:0]), //i
    .send_start                (intitaor_test_1_send_start                     ), //i
    .iresp_stream_valid        (intitaor_1_iresp_stream_valid                  ), //o
    .iresp_stream_ready        (iresp_stream_ready                             ), //i
    .iresp_stream_payload      (intitaor_1_iresp_stream_payload[63:0]          ), //o
    .clk                       (clk                                            ), //i
    .reset                     (reset                                          )  //i
  );
  assign m_axis_ireq_tvalid = intitaor_1_m_axis_ireq_tvalid; // @[Intitaor.scala 277:15]
  assign m_axis_ireq_tlast = intitaor_1_m_axis_ireq_tlast; // @[Intitaor.scala 277:15]
  assign m_axis_ireq_tdata = intitaor_1_m_axis_ireq_tdata; // @[Intitaor.scala 277:15]
  assign m_axis_ireq_tkeep = intitaor_1_m_axis_ireq_tkeep; // @[Intitaor.scala 277:15]
  assign m_axis_ireq_tuser = intitaor_1_m_axis_ireq_tuser; // @[Intitaor.scala 277:15]
  assign s_axis_iresp_tready = intitaor_1_s_axis_iresp_tready; // @[Intitaor.scala 277:15]
  assign iresp_stream_valid = intitaor_1_iresp_stream_valid; // @[Intitaor.scala 278:19]
  assign iresp_stream_payload = intitaor_1_iresp_stream_payload; // @[Intitaor.scala 278:19]

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
  input               clk,
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

  wire                streamfifo_1_io_push_ready;
  wire                streamfifo_1_io_pop_valid;
  wire       [63:0]   streamfifo_1_io_pop_payload;
  wire       [8:0]    streamfifo_1_io_occupancy;
  wire       [8:0]    streamfifo_1_io_availability;
  wire       [5:0]    _zz_when_Intitaor_l49;
  wire       [4:0]    _zz_when_Intitaor_l49_1;
  wire       [3:0]    _zz_request_autocheck_error;
  wire       [3:0]    _zz_request_autocheck_error_1;
  wire       [63:0]   header_beat;
  reg        [5:0]    current_beat_cnt;
  wire                intiator_intiator_req_stream_fire;
  wire                when_Intitaor_l35;
  wire                intiator_intiator_req_stream_fire_1;
  wire       [4:0]    number_of_data_beats;
  reg                 ireq_tlast;
  wire                when_Intitaor_l47;
  wire                intiator_intiator_req_stream_fire_2;
  wire                intiator_intiator_req_stream_fire_3;
  wire                when_Intitaor_l49;
  wire                when_Intitaor_l51;
  wire                when_Intitaor_l53;
  reg        [63:0]   ireq_tdata;
  wire                intiator_intiator_req_stream_fire_4;
  wire                when_Intitaor_l61;
  reg                 user_data_ready;
  reg                 ireq_tvalid;
  reg                 send_start_d;
  wire                intiator_intiator_req_stream_fire_5;
  wire                when_Intitaor_l71;
  wire                when_Intitaor_l74;
  wire                intiator_intiator_req_stream_fire_6;
  wire       [63:0]   write_queue_data_d;
  reg        [63:0]   write_queue_data;
  reg                 expecting_a_response;
  wire                intiator_intiator_req_stream_fire_7;
  wire                when_Intitaor_l89;
  reg        [63:0]   read_queue_data;
  wire       [7:0]    expected_tid;
  wire       [3:0]    expected_ftype;
  wire       [7:0]    expected_size;
  reg                 compare_received;
  wire                intiator_intiator_resp_stream_fire;
  wire                when_Intitaor_l104;
  wire                intiator_intiator_resp_stream_fire_1;
  reg                 request_autocheck_error;
  wire                intiator_intiator_resp_stream_fire_2;
  wire                when_Intitaor_l113;
  reg                 iresp_tready;
  wire                intiator_intiator_resp_stream_fire_3;
  wire                when_Intitaor_l123;
  reg                 nread_iresp_write;
  wire                intiator_intiator_resp_stream_fire_4;
  wire                when_Intitaor_l131;
  wire                intiator_intiator_resp_stream_fire_5;
  wire                when_Intitaor_l133;
  wire                intiator_intiator_resp_stream_fire_6;
  `ifndef SYNTHESIS
  reg [47:0] usercmd_user_ftype_string;
  reg [47:0] usercmd_user_ttype_string;
  `endif


  assign _zz_when_Intitaor_l49_1 = number_of_data_beats;
  assign _zz_when_Intitaor_l49 = {1'd0, _zz_when_Intitaor_l49_1};
  assign _zz_request_autocheck_error = SrioFtype_NREAD;
  assign _zz_request_autocheck_error_1 = SrioTtype_TWDATA;
  StreamFifo streamfifo_1 (
    .io_push_valid   (usercmd_user_data_valid            ), //i
    .io_push_ready   (streamfifo_1_io_push_ready         ), //o
    .io_push_payload (usercmd_user_data_payload[63:0]    ), //i
    .io_pop_valid    (streamfifo_1_io_pop_valid          ), //o
    .io_pop_ready    (intiator_intiator_req_stream_fire_6), //i
    .io_pop_payload  (streamfifo_1_io_pop_payload[63:0]  ), //o
    .io_flush        (1'b0                               ), //i
    .io_occupancy    (streamfifo_1_io_occupancy[8:0]     ), //o
    .io_availability (streamfifo_1_io_availability[8:0]  ), //o
    .clk             (clk                                ), //i
    .reset           (reset                              )  //i
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

  assign m_axis_ireq_tkeep = 8'hff; // @[Intitaor.scala 19:41]
  assign m_axis_ireq_tuser = 32'h00ff00ff; // @[Intitaor.scala 20:41]
  assign usercmd_user_data_ready = streamfifo_1_io_push_ready; // @[Stream.scala 295:16]
  assign header_beat = {{{{{{{{usercmd_user_tid,usercmd_user_ftype},usercmd_user_ttype},1'b0},usercmd_user_prio},1'b0},usercmd_user_size},2'b00},usercmd_user_addr}; // @[BaseType.scala 299:24]
  assign intiator_intiator_req_stream_fire = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l35 = (intiator_intiator_req_stream_fire && m_axis_ireq_tlast); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_1 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign number_of_data_beats = usercmd_user_size[7 : 3]; // @[BaseType.scala 299:24]
  assign when_Intitaor_l47 = (((usercmd_user_ftype == SrioFtype_NREAD) || (usercmd_user_ftype == SrioFtype_DOORB)) && (current_beat_cnt == 6'h0)); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_2 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign intiator_intiator_req_stream_fire_3 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l49 = ((current_beat_cnt == _zz_when_Intitaor_l49) && intiator_intiator_req_stream_fire_3); // @[BaseType.scala 305:24]
  assign when_Intitaor_l51 = (m_axis_ireq_tready == 1'b0); // @[BaseType.scala 305:24]
  assign when_Intitaor_l53 = (m_axis_ireq_tready || (! m_axis_ireq_tvalid)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tlast = ireq_tlast; // @[Intitaor.scala 58:40]
  assign intiator_intiator_req_stream_fire_4 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l61 = ((current_beat_cnt == 6'h0) && (! intiator_intiator_req_stream_fire_4)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tdata = ireq_tdata; // @[Intitaor.scala 66:52]
  assign intiator_intiator_req_stream_fire_5 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l71 = (intiator_intiator_req_stream_fire_5 && m_axis_ireq_tlast); // @[BaseType.scala 305:24]
  assign when_Intitaor_l74 = (send_start && (! send_start_d)); // @[BaseType.scala 305:24]
  assign m_axis_ireq_tvalid = ireq_tvalid; // @[Intitaor.scala 81:41]
  assign intiator_intiator_req_stream_fire_6 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign write_queue_data_d = {{{44'h0,usercmd_user_tid},usercmd_user_ftype},usercmd_user_size}; // @[BaseType.scala 299:24]
  assign intiator_intiator_req_stream_fire_7 = (m_axis_ireq_tvalid && m_axis_ireq_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l89 = ((current_beat_cnt == 6'h0) && intiator_intiator_req_stream_fire_7); // @[BaseType.scala 305:24]
  assign expected_tid = read_queue_data[19 : 12]; // @[BaseType.scala 299:24]
  assign expected_ftype = read_queue_data[11 : 8]; // @[BaseType.scala 299:24]
  assign expected_size = read_queue_data[7 : 0]; // @[BaseType.scala 299:24]
  assign intiator_intiator_resp_stream_fire = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l104 = (intiator_intiator_resp_stream_fire && s_axis_iresp_tlast); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_1 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_2 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l113 = (compare_received && intiator_intiator_resp_stream_fire_2); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_3 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l123 = (intiator_intiator_resp_stream_fire_3 && s_axis_iresp_tlast); // @[BaseType.scala 305:24]
  assign s_axis_iresp_tready = iresp_tready; // @[Intitaor.scala 128:42]
  assign intiator_intiator_resp_stream_fire_4 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l131 = ((compare_received && (expected_ftype == SrioFtype_NREAD)) && intiator_intiator_resp_stream_fire_4); // @[BaseType.scala 305:24]
  assign intiator_intiator_resp_stream_fire_5 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign when_Intitaor_l133 = (intiator_intiator_resp_stream_fire_5 && s_axis_iresp_tlast); // @[BaseType.scala 305:24]
  assign iresp_stream_payload = s_axis_iresp_tdata; // @[Intitaor.scala 139:27]
  assign intiator_intiator_resp_stream_fire_6 = (s_axis_iresp_tvalid && s_axis_iresp_tready); // @[BaseType.scala 305:24]
  assign iresp_stream_valid = (nread_iresp_write && intiator_intiator_resp_stream_fire_6); // @[Intitaor.scala 140:25]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      current_beat_cnt <= 6'h0; // @[Data.scala 400:33]
      ireq_tlast <= 1'b0; // @[Data.scala 400:33]
      user_data_ready <= 1'b0; // @[Data.scala 400:33]
      ireq_tvalid <= 1'b0; // @[Data.scala 400:33]
      send_start_d <= 1'b0; // @[Data.scala 400:33]
      expecting_a_response <= 1'b0; // @[Data.scala 400:33]
      compare_received <= 1'b1; // @[Data.scala 400:33]
      request_autocheck_error <= 1'b0; // @[Data.scala 400:33]
      iresp_tready <= 1'b0; // @[Data.scala 400:33]
      nread_iresp_write <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(when_Intitaor_l35) begin
        current_beat_cnt <= 6'h0; // @[Intitaor.scala 36:22]
      end else begin
        if(intiator_intiator_req_stream_fire_1) begin
          current_beat_cnt <= (current_beat_cnt + 6'h01); // @[Intitaor.scala 38:22]
        end else begin
          current_beat_cnt <= current_beat_cnt; // @[Intitaor.scala 40:22]
        end
      end
      if(when_Intitaor_l47) begin
        ireq_tlast <= (! (intiator_intiator_req_stream_fire_2 && m_axis_ireq_tlast)); // @[Intitaor.scala 48:16]
      end else begin
        if(when_Intitaor_l49) begin
          ireq_tlast <= (! ireq_tlast); // @[Intitaor.scala 50:16]
        end else begin
          if(when_Intitaor_l51) begin
            ireq_tlast <= ireq_tlast; // @[Intitaor.scala 52:16]
          end else begin
            if(when_Intitaor_l53) begin
              ireq_tlast <= 1'b0; // @[Intitaor.scala 54:16]
            end else begin
              ireq_tlast <= ireq_tlast; // @[Intitaor.scala 56:16]
            end
          end
        end
      end
      send_start_d <= send_start; // @[Reg.scala 39:30]
      if(when_Intitaor_l71) begin
        ireq_tvalid <= 1'b0; // @[Intitaor.scala 72:17]
        user_data_ready <= 1'b0; // @[Intitaor.scala 73:21]
      end else begin
        if(when_Intitaor_l74) begin
          ireq_tvalid <= 1'b1; // @[Intitaor.scala 75:17]
          user_data_ready <= 1'b1; // @[Intitaor.scala 76:21]
        end else begin
          ireq_tvalid <= ireq_tvalid; // @[Intitaor.scala 78:17]
          user_data_ready <= user_data_ready; // @[Intitaor.scala 79:21]
        end
      end
      if(when_Intitaor_l89) begin
        expecting_a_response <= ((((usercmd_user_ftype == SrioFtype_NREAD) || (usercmd_user_ftype == SrioFtype_DOORB)) || ((usercmd_user_ftype == SrioFtype_NWRITE) && (usercmd_user_ttype == SrioTtype_TNWR_R))) || (usercmd_user_ftype == SrioFtype_MESSG)); // @[Intitaor.scala 90:26]
      end else begin
        expecting_a_response <= 1'b0; // @[Intitaor.scala 95:26]
      end
      if(when_Intitaor_l104) begin
        compare_received <= 1'b1; // @[Intitaor.scala 105:22]
      end else begin
        if(intiator_intiator_resp_stream_fire_1) begin
          compare_received <= 1'b0; // @[Intitaor.scala 107:22]
        end else begin
          compare_received <= compare_received; // @[Intitaor.scala 109:22]
        end
      end
      if(when_Intitaor_l113) begin
        request_autocheck_error <= ((((expected_tid != s_axis_iresp_tdata[63 : 56]) || ((expected_ftype == _zz_request_autocheck_error) && (s_axis_iresp_tdata[51 : 48] != _zz_request_autocheck_error_1))) || ((expected_ftype == SrioFtype_NWRITE) && (s_axis_iresp_tdata[51 : 48] != SrioTtype_TNDATA))) || ((expected_ftype == SrioFtype_DOORB) && (s_axis_iresp_tdata[51 : 48] != SrioTtype_TNDATA))); // @[Intitaor.scala 114:29]
      end else begin
        request_autocheck_error <= 1'b0; // @[Intitaor.scala 119:29]
      end
      if(when_Intitaor_l123) begin
        iresp_tready <= 1'b0; // @[Intitaor.scala 124:18]
      end else begin
        iresp_tready <= 1'b1; // @[Intitaor.scala 126:18]
      end
      if(when_Intitaor_l131) begin
        nread_iresp_write <= 1'b1; // @[Intitaor.scala 132:23]
      end else begin
        if(when_Intitaor_l133) begin
          nread_iresp_write <= 1'b0; // @[Intitaor.scala 134:23]
        end else begin
          nread_iresp_write <= nread_iresp_write; // @[Intitaor.scala 136:23]
        end
      end
    end
  end

  always @(posedge clk) begin
    if(when_Intitaor_l61) begin
      ireq_tdata <= header_beat; // @[Intitaor.scala 62:16]
    end else begin
      ireq_tdata <= streamfifo_1_io_pop_payload; // @[Intitaor.scala 64:16]
    end
    write_queue_data <= write_queue_data_d; // @[Reg.scala 39:30]
    if(expecting_a_response) begin
      read_queue_data <= write_queue_data; // @[Intitaor.scala 98:36]
    end
  end


endmodule

module Intitaor_Test (
  output     [33:0]   usercmd_user_addr,
  output     [3:0]    usercmd_user_ftype,
  output     [3:0]    usercmd_user_ttype,
  output     [7:0]    usercmd_user_size,
  output     [1:0]    usercmd_user_prio,
  output     [7:0]    usercmd_user_tid,
  output              usercmd_user_data_valid,
  input               usercmd_user_data_ready,
  output     [63:0]   usercmd_user_data_payload,
  output              send_start,
  input               clk,
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
  localparam fsm_enumDef_BOOT = 3'd0;
  localparam fsm_enumDef_Init_Start = 3'd1;
  localparam fsm_enumDef_Nwrite = 3'd2;
  localparam fsm_enumDef_Send_Data = 3'd3;
  localparam fsm_enumDef_Send_Stream = 3'd4;
  localparam fsm_enumDef_Send_Nwrite = 3'd5;

  reg                 timer_1_io_clear;
  wire                timer_1_io_full;
  wire       [31:0]   timer_1_io_value;
  wire                when_Intitaor_l154;
  reg        [33:0]   user_addr;
  reg        [3:0]    user_ftype;
  reg        [3:0]    user_ttype;
  reg        [7:0]    user_size;
  reg        [1:0]    user_prio;
  reg        [7:0]    user_tid;
  reg                 user_valid;
  reg        [63:0]   user_data;
  reg                 start;
  wire                fsm_wantExit;
  reg                 fsm_wantStart;
  wire                fsm_wantKill;
  reg        [7:0]    fsm_counter;
  reg        [2:0]    fsm_stateReg;
  reg        [2:0]    fsm_stateNext;
  `ifndef SYNTHESIS
  reg [47:0] usercmd_user_ftype_string;
  reg [47:0] usercmd_user_ttype_string;
  reg [47:0] user_ftype_string;
  reg [47:0] user_ttype_string;
  reg [87:0] fsm_stateReg_string;
  reg [87:0] fsm_stateNext_string;
  `endif


  Timer timer_1 (
    .io_tick  (1'b1                  ), //i
    .io_clear (timer_1_io_clear      ), //i
    .io_limit (32'h000007d0          ), //i
    .io_full  (timer_1_io_full       ), //o
    .io_value (timer_1_io_value[31:0]), //o
    .clk      (clk                   ), //i
    .reset    (reset                 )  //i
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
    case(user_ftype)
      SrioFtype_NREAD : user_ftype_string = "NREAD ";
      SrioFtype_NWRITE : user_ftype_string = "NWRITE";
      SrioFtype_SWRITE : user_ftype_string = "SWRITE";
      SrioFtype_DOORB : user_ftype_string = "DOORB ";
      SrioFtype_MESSG : user_ftype_string = "MESSG ";
      SrioFtype_RESP : user_ftype_string = "RESP  ";
      SrioFtype_FTYPE9 : user_ftype_string = "FTYPE9";
      default : user_ftype_string = "??????";
    endcase
  end
  always @(*) begin
    case(user_ttype)
      SrioTtype_TNWR : user_ttype_string = "TNWR  ";
      SrioTtype_TNWR_R : user_ttype_string = "TNWR_R";
      SrioTtype_TNDATA : user_ttype_string = "TNDATA";
      SrioTtype_TWDATA : user_ttype_string = "TWDATA";
      default : user_ttype_string = "??????";
    endcase
  end
  always @(*) begin
    case(fsm_stateReg)
      fsm_enumDef_BOOT : fsm_stateReg_string = "BOOT       ";
      fsm_enumDef_Init_Start : fsm_stateReg_string = "Init_Start ";
      fsm_enumDef_Nwrite : fsm_stateReg_string = "Nwrite     ";
      fsm_enumDef_Send_Data : fsm_stateReg_string = "Send_Data  ";
      fsm_enumDef_Send_Stream : fsm_stateReg_string = "Send_Stream";
      fsm_enumDef_Send_Nwrite : fsm_stateReg_string = "Send_Nwrite";
      default : fsm_stateReg_string = "???????????";
    endcase
  end
  always @(*) begin
    case(fsm_stateNext)
      fsm_enumDef_BOOT : fsm_stateNext_string = "BOOT       ";
      fsm_enumDef_Init_Start : fsm_stateNext_string = "Init_Start ";
      fsm_enumDef_Nwrite : fsm_stateNext_string = "Nwrite     ";
      fsm_enumDef_Send_Data : fsm_stateNext_string = "Send_Data  ";
      fsm_enumDef_Send_Stream : fsm_stateNext_string = "Send_Stream";
      fsm_enumDef_Send_Nwrite : fsm_stateNext_string = "Send_Nwrite";
      default : fsm_stateNext_string = "???????????";
    endcase
  end
  `endif

  assign when_Intitaor_l154 = (32'h000007d0 <= timer_1_io_value); // @[BaseType.scala 305:24]
  always @(*) begin
    if(when_Intitaor_l154) begin
      timer_1_io_clear = 1'b1; // @[Intitaor.scala 155:20]
    end else begin
      timer_1_io_clear = 1'b0; // @[Intitaor.scala 157:20]
    end
  end

  assign fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
      end
      fsm_enumDef_Nwrite : begin
      end
      fsm_enumDef_Send_Data : begin
      end
      fsm_enumDef_Send_Stream : begin
      end
      fsm_enumDef_Send_Nwrite : begin
      end
      default : begin
        fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign usercmd_user_ftype = user_ftype; // @[Intitaor.scala 256:25]
  assign usercmd_user_ttype = user_ttype; // @[Intitaor.scala 257:25]
  assign usercmd_user_addr = user_addr; // @[Intitaor.scala 258:24]
  assign usercmd_user_tid = user_tid; // @[Intitaor.scala 259:23]
  assign usercmd_user_prio = user_prio; // @[Intitaor.scala 260:24]
  assign usercmd_user_size = user_size; // @[Intitaor.scala 261:24]
  assign usercmd_user_data_valid = user_valid; // @[Intitaor.scala 262:30]
  assign usercmd_user_data_payload = user_data; // @[Intitaor.scala 263:32]
  assign send_start = start; // @[Intitaor.scala 264:17]
  always @(*) begin
    fsm_stateNext = fsm_stateReg; // @[StateMachine.scala 217:17]
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
        if(timer_1_io_full) begin
          fsm_stateNext = fsm_enumDef_Nwrite; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_Nwrite : begin
        fsm_stateNext = fsm_enumDef_Send_Data; // @[Enum.scala 148:67]
      end
      fsm_enumDef_Send_Data : begin
        fsm_stateNext = fsm_enumDef_Send_Stream; // @[Enum.scala 148:67]
      end
      fsm_enumDef_Send_Stream : begin
        fsm_stateNext = fsm_enumDef_Send_Nwrite; // @[Enum.scala 148:67]
      end
      fsm_enumDef_Send_Nwrite : begin
        fsm_stateNext = fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
      end
      default : begin
      end
    endcase
    if(fsm_wantStart) begin
      fsm_stateNext = fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
    end
    if(fsm_wantKill) begin
      fsm_stateNext = fsm_enumDef_BOOT; // @[Enum.scala 148:67]
    end
  end

  always @(posedge clk or posedge reset) begin
    if(reset) begin
      user_addr <= 34'h0; // @[Data.scala 400:33]
      user_valid <= 1'b0; // @[Data.scala 400:33]
      user_data <= 64'h0; // @[Data.scala 400:33]
      start <= 1'b0; // @[Data.scala 400:33]
      fsm_counter <= 8'h0; // @[Data.scala 400:33]
      fsm_stateReg <= fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      fsm_stateReg <= fsm_stateNext; // @[StateMachine.scala 212:14]
      case(fsm_stateReg)
        fsm_enumDef_Init_Start : begin
          if(timer_1_io_full) begin
            fsm_counter <= 8'h0; // @[Intitaor.scala 182:19]
          end
        end
        fsm_enumDef_Nwrite : begin
          user_addr <= 34'h000120020; // @[Intitaor.scala 222:19]
          user_valid <= 1'b1; // @[Intitaor.scala 228:20]
          user_data <= 64'h00000000a1a2a3a4; // @[Intitaor.scala 229:19]
        end
        fsm_enumDef_Send_Data : begin
          user_valid <= 1'b1; // @[Intitaor.scala 235:20]
          user_data <= 64'h00000000a4a3a2a1; // @[Intitaor.scala 236:19]
        end
        fsm_enumDef_Send_Stream : begin
          user_valid <= 1'b0; // @[Intitaor.scala 242:20]
          start <= 1'b1; // @[Intitaor.scala 243:15]
        end
        fsm_enumDef_Send_Nwrite : begin
          start <= 1'b0; // @[Intitaor.scala 249:15]
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge clk) begin
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
      end
      fsm_enumDef_Nwrite : begin
        user_ftype <= SrioFtype_NWRITE; // @[Enum.scala 148:67]
        user_ttype <= SrioTtype_TNWR_R; // @[Enum.scala 148:67]
        user_size <= 8'h0f; // @[Intitaor.scala 225:19]
        user_prio <= 2'b01; // @[Intitaor.scala 226:19]
        user_tid <= 8'hff; // @[Intitaor.scala 227:18]
      end
      fsm_enumDef_Send_Data : begin
      end
      fsm_enumDef_Send_Stream : begin
      end
      fsm_enumDef_Send_Nwrite : begin
      end
      default : begin
      end
    endcase
  end


endmodule

module StreamFifo (
  input               io_push_valid,
  output              io_push_ready,
  input      [63:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [63:0]   io_pop_payload,
  input               io_flush,
  output     [8:0]    io_occupancy,
  output     [8:0]    io_availability,
  input               clk,
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
  always @(posedge clk) begin
    if(_zz_io_pop_payload) begin
      _zz_logic_ram_port0 <= logic_ram[logic_popPtr_valueNext];
    end
  end

  always @(posedge clk) begin
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
  always @(posedge clk or posedge reset) begin
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
