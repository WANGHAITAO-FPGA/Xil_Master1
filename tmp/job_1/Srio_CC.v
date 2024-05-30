// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Srio_CC
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module Srio_CC (
  input      [63:0]   data_in_cc1_0,
  input      [63:0]   data_in_cc1_1,
  input      [63:0]   data_in_cc1_2,
  input      [63:0]   data_in_cc1_3,
  input      [63:0]   data_in_cc1_4,
  input      [63:0]   data_in_cc1_5,
  input      [63:0]   data_in_cc1_6,
  input      [63:0]   data_in_cc1_7,
  input      [63:0]   data_in_cc1_8,
  input      [63:0]   data_in_cc1_9,
  input      [63:0]   data_in_cc1_10,
  input      [63:0]   data_in_cc1_11,
  input      [63:0]   data_in_cc1_12,
  input      [63:0]   data_in_cc1_13,
  input      [63:0]   data_in_cc1_14,
  input      [63:0]   data_in_cc1_15,
  output     [63:0]   data_out_cc1_0,
  output     [63:0]   data_out_cc1_1,
  output     [63:0]   data_out_cc1_2,
  output     [63:0]   data_out_cc1_3,
  output     [63:0]   data_out_cc1_4,
  output     [63:0]   data_out_cc1_5,
  output     [63:0]   data_out_cc1_6,
  output     [63:0]   data_out_cc1_7,
  output     [63:0]   data_out_cc1_8,
  output     [63:0]   data_out_cc1_9,
  output     [63:0]   data_out_cc1_10,
  output     [63:0]   data_out_cc1_11,
  output     [63:0]   data_out_cc1_12,
  output     [63:0]   data_out_cc1_13,
  output     [63:0]   data_out_cc1_14,
  output     [63:0]   data_out_cc1_15,
  input      [63:0]   data_in_cc2_0,
  input      [63:0]   data_in_cc2_1,
  input      [63:0]   data_in_cc2_2,
  input      [63:0]   data_in_cc2_3,
  input      [63:0]   data_in_cc2_4,
  input      [63:0]   data_in_cc2_5,
  input      [63:0]   data_in_cc2_6,
  input      [63:0]   data_in_cc2_7,
  input      [63:0]   data_in_cc2_8,
  input      [63:0]   data_in_cc2_9,
  input      [63:0]   data_in_cc2_10,
  input      [63:0]   data_in_cc2_11,
  input      [63:0]   data_in_cc2_12,
  input      [63:0]   data_in_cc2_13,
  input      [63:0]   data_in_cc2_14,
  input      [63:0]   data_in_cc2_15,
  output     [63:0]   data_out_cc2_0,
  output     [63:0]   data_out_cc2_1,
  output     [63:0]   data_out_cc2_2,
  output     [63:0]   data_out_cc2_3,
  output     [63:0]   data_out_cc2_4,
  output     [63:0]   data_out_cc2_5,
  output     [63:0]   data_out_cc2_6,
  output     [63:0]   data_out_cc2_7,
  output     [63:0]   data_out_cc2_8,
  output     [63:0]   data_out_cc2_9,
  output     [63:0]   data_out_cc2_10,
  output     [63:0]   data_out_cc2_11,
  output     [63:0]   data_out_cc2_12,
  output     [63:0]   data_out_cc2_13,
  output     [63:0]   data_out_cc2_14,
  output     [63:0]   data_out_cc2_15,
  input               tx_tick_cc1,
  input               tx_tick_cc2,
  input               ccin_clk,
  input               ccout_clk,
  input               reset
);

  wire       [63:0]   cc1_area_cc1_reg_simplebus_RDATA;
  wire       [63:0]   cc1_area_cc1_reg_data_out_0;
  wire       [63:0]   cc1_area_cc1_reg_data_out_1;
  wire       [63:0]   cc1_area_cc1_reg_data_out_2;
  wire       [63:0]   cc1_area_cc1_reg_data_out_3;
  wire       [63:0]   cc1_area_cc1_reg_data_out_4;
  wire       [63:0]   cc1_area_cc1_reg_data_out_5;
  wire       [63:0]   cc1_area_cc1_reg_data_out_6;
  wire       [63:0]   cc1_area_cc1_reg_data_out_7;
  wire       [63:0]   cc1_area_cc1_reg_data_out_8;
  wire       [63:0]   cc1_area_cc1_reg_data_out_9;
  wire       [63:0]   cc1_area_cc1_reg_data_out_10;
  wire       [63:0]   cc1_area_cc1_reg_data_out_11;
  wire       [63:0]   cc1_area_cc1_reg_data_out_12;
  wire       [63:0]   cc1_area_cc1_reg_data_out_13;
  wire       [63:0]   cc1_area_cc1_reg_data_out_14;
  wire       [63:0]   cc1_area_cc1_reg_data_out_15;
  wire       [8:0]    cc1_area_fifo_cc1_ccin_rxbundle_RADDR;
  wire                cc1_area_fifo_cc1_ccin_rxbundle_RENABLE;
  wire       [8:0]    cc1_area_fifo_cc1_ccout_txbundle_WADDR;
  wire       [63:0]   cc1_area_fifo_cc1_ccout_txbundle_WDATA;
  wire                cc1_area_fifo_cc1_ccout_txbundle_WENABLE;
  wire       [63:0]   cc2_area_cc2_reg_simplebus_RDATA;
  wire       [63:0]   cc2_area_cc2_reg_data_out_0;
  wire       [63:0]   cc2_area_cc2_reg_data_out_1;
  wire       [63:0]   cc2_area_cc2_reg_data_out_2;
  wire       [63:0]   cc2_area_cc2_reg_data_out_3;
  wire       [63:0]   cc2_area_cc2_reg_data_out_4;
  wire       [63:0]   cc2_area_cc2_reg_data_out_5;
  wire       [63:0]   cc2_area_cc2_reg_data_out_6;
  wire       [63:0]   cc2_area_cc2_reg_data_out_7;
  wire       [63:0]   cc2_area_cc2_reg_data_out_8;
  wire       [63:0]   cc2_area_cc2_reg_data_out_9;
  wire       [63:0]   cc2_area_cc2_reg_data_out_10;
  wire       [63:0]   cc2_area_cc2_reg_data_out_11;
  wire       [63:0]   cc2_area_cc2_reg_data_out_12;
  wire       [63:0]   cc2_area_cc2_reg_data_out_13;
  wire       [63:0]   cc2_area_cc2_reg_data_out_14;
  wire       [63:0]   cc2_area_cc2_reg_data_out_15;
  wire       [8:0]    cc2_area_fifo_cc2_ccin_rxbundle_RADDR;
  wire                cc2_area_fifo_cc2_ccin_rxbundle_RENABLE;
  wire       [8:0]    cc2_area_fifo_cc2_ccout_txbundle_WADDR;
  wire       [63:0]   cc2_area_fifo_cc2_ccout_txbundle_WDATA;
  wire                cc2_area_fifo_cc2_ccout_txbundle_WENABLE;

  Srio_Common_1 cc1_area_cc1_reg (
    .simplebus_RADDR   (cc1_area_fifo_cc1_ccin_rxbundle_RADDR[8:0]  ), //i
    .simplebus_RDATA   (cc1_area_cc1_reg_simplebus_RDATA[63:0]      ), //o
    .simplebus_RENABLE (cc1_area_fifo_cc1_ccin_rxbundle_RENABLE     ), //i
    .simplebus_WADDR   (cc2_area_fifo_cc2_ccout_txbundle_WADDR[8:0] ), //i
    .simplebus_WDATA   (cc2_area_fifo_cc2_ccout_txbundle_WDATA[63:0]), //i
    .simplebus_WENABLE (cc2_area_fifo_cc2_ccout_txbundle_WENABLE    ), //i
    .data_in_0         (data_in_cc1_0[63:0]                         ), //i
    .data_in_1         (data_in_cc1_1[63:0]                         ), //i
    .data_in_2         (data_in_cc1_2[63:0]                         ), //i
    .data_in_3         (data_in_cc1_3[63:0]                         ), //i
    .data_in_4         (data_in_cc1_4[63:0]                         ), //i
    .data_in_5         (data_in_cc1_5[63:0]                         ), //i
    .data_in_6         (data_in_cc1_6[63:0]                         ), //i
    .data_in_7         (data_in_cc1_7[63:0]                         ), //i
    .data_in_8         (data_in_cc1_8[63:0]                         ), //i
    .data_in_9         (data_in_cc1_9[63:0]                         ), //i
    .data_in_10        (data_in_cc1_10[63:0]                        ), //i
    .data_in_11        (data_in_cc1_11[63:0]                        ), //i
    .data_in_12        (data_in_cc1_12[63:0]                        ), //i
    .data_in_13        (data_in_cc1_13[63:0]                        ), //i
    .data_in_14        (data_in_cc1_14[63:0]                        ), //i
    .data_in_15        (data_in_cc1_15[63:0]                        ), //i
    .data_out_0        (cc1_area_cc1_reg_data_out_0[63:0]           ), //o
    .data_out_1        (cc1_area_cc1_reg_data_out_1[63:0]           ), //o
    .data_out_2        (cc1_area_cc1_reg_data_out_2[63:0]           ), //o
    .data_out_3        (cc1_area_cc1_reg_data_out_3[63:0]           ), //o
    .data_out_4        (cc1_area_cc1_reg_data_out_4[63:0]           ), //o
    .data_out_5        (cc1_area_cc1_reg_data_out_5[63:0]           ), //o
    .data_out_6        (cc1_area_cc1_reg_data_out_6[63:0]           ), //o
    .data_out_7        (cc1_area_cc1_reg_data_out_7[63:0]           ), //o
    .data_out_8        (cc1_area_cc1_reg_data_out_8[63:0]           ), //o
    .data_out_9        (cc1_area_cc1_reg_data_out_9[63:0]           ), //o
    .data_out_10       (cc1_area_cc1_reg_data_out_10[63:0]          ), //o
    .data_out_11       (cc1_area_cc1_reg_data_out_11[63:0]          ), //o
    .data_out_12       (cc1_area_cc1_reg_data_out_12[63:0]          ), //o
    .data_out_13       (cc1_area_cc1_reg_data_out_13[63:0]          ), //o
    .data_out_14       (cc1_area_cc1_reg_data_out_14[63:0]          ), //o
    .data_out_15       (cc1_area_cc1_reg_data_out_15[63:0]          ), //o
    .ccin_clk          (ccin_clk                                    ), //i
    .reset             (reset                                       )  //i
  );
  Srio_FifoCc_1 cc1_area_fifo_cc1 (
    .ccin_rxbundle_RENABLE  (cc1_area_fifo_cc1_ccin_rxbundle_RENABLE     ), //o
    .ccin_rxbundle_RADDR    (cc1_area_fifo_cc1_ccin_rxbundle_RADDR[8:0]  ), //o
    .ccin_rxbundle_RDATA    (cc1_area_cc1_reg_simplebus_RDATA[63:0]      ), //i
    .ccout_txbundle_WADDR   (cc1_area_fifo_cc1_ccout_txbundle_WADDR[8:0] ), //o
    .ccout_txbundle_WDATA   (cc1_area_fifo_cc1_ccout_txbundle_WDATA[63:0]), //o
    .ccout_txbundle_WENABLE (cc1_area_fifo_cc1_ccout_txbundle_WENABLE    ), //o
    .tx_tick                (tx_tick_cc1                                 ), //i
    .ccin_clk               (ccin_clk                                    ), //i
    .ccout_clk              (ccout_clk                                   ), //i
    .reset                  (reset                                       )  //i
  );
  Srio_Common cc2_area_cc2_reg (
    .simplebus_RADDR   (cc2_area_fifo_cc2_ccin_rxbundle_RADDR[8:0]  ), //i
    .simplebus_RDATA   (cc2_area_cc2_reg_simplebus_RDATA[63:0]      ), //o
    .simplebus_RENABLE (cc2_area_fifo_cc2_ccin_rxbundle_RENABLE     ), //i
    .simplebus_WADDR   (cc1_area_fifo_cc1_ccout_txbundle_WADDR[8:0] ), //i
    .simplebus_WDATA   (cc1_area_fifo_cc1_ccout_txbundle_WDATA[63:0]), //i
    .simplebus_WENABLE (cc1_area_fifo_cc1_ccout_txbundle_WENABLE    ), //i
    .data_in_0         (data_in_cc2_0[63:0]                         ), //i
    .data_in_1         (data_in_cc2_1[63:0]                         ), //i
    .data_in_2         (data_in_cc2_2[63:0]                         ), //i
    .data_in_3         (data_in_cc2_3[63:0]                         ), //i
    .data_in_4         (data_in_cc2_4[63:0]                         ), //i
    .data_in_5         (data_in_cc2_5[63:0]                         ), //i
    .data_in_6         (data_in_cc2_6[63:0]                         ), //i
    .data_in_7         (data_in_cc2_7[63:0]                         ), //i
    .data_in_8         (data_in_cc2_8[63:0]                         ), //i
    .data_in_9         (data_in_cc2_9[63:0]                         ), //i
    .data_in_10        (data_in_cc2_10[63:0]                        ), //i
    .data_in_11        (data_in_cc2_11[63:0]                        ), //i
    .data_in_12        (data_in_cc2_12[63:0]                        ), //i
    .data_in_13        (data_in_cc2_13[63:0]                        ), //i
    .data_in_14        (data_in_cc2_14[63:0]                        ), //i
    .data_in_15        (data_in_cc2_15[63:0]                        ), //i
    .data_out_0        (cc2_area_cc2_reg_data_out_0[63:0]           ), //o
    .data_out_1        (cc2_area_cc2_reg_data_out_1[63:0]           ), //o
    .data_out_2        (cc2_area_cc2_reg_data_out_2[63:0]           ), //o
    .data_out_3        (cc2_area_cc2_reg_data_out_3[63:0]           ), //o
    .data_out_4        (cc2_area_cc2_reg_data_out_4[63:0]           ), //o
    .data_out_5        (cc2_area_cc2_reg_data_out_5[63:0]           ), //o
    .data_out_6        (cc2_area_cc2_reg_data_out_6[63:0]           ), //o
    .data_out_7        (cc2_area_cc2_reg_data_out_7[63:0]           ), //o
    .data_out_8        (cc2_area_cc2_reg_data_out_8[63:0]           ), //o
    .data_out_9        (cc2_area_cc2_reg_data_out_9[63:0]           ), //o
    .data_out_10       (cc2_area_cc2_reg_data_out_10[63:0]          ), //o
    .data_out_11       (cc2_area_cc2_reg_data_out_11[63:0]          ), //o
    .data_out_12       (cc2_area_cc2_reg_data_out_12[63:0]          ), //o
    .data_out_13       (cc2_area_cc2_reg_data_out_13[63:0]          ), //o
    .data_out_14       (cc2_area_cc2_reg_data_out_14[63:0]          ), //o
    .data_out_15       (cc2_area_cc2_reg_data_out_15[63:0]          ), //o
    .ccout_clk         (ccout_clk                                   ), //i
    .reset             (reset                                       )  //i
  );
  Srio_FifoCc cc2_area_fifo_cc2 (
    .ccin_rxbundle_RENABLE  (cc2_area_fifo_cc2_ccin_rxbundle_RENABLE     ), //o
    .ccin_rxbundle_RADDR    (cc2_area_fifo_cc2_ccin_rxbundle_RADDR[8:0]  ), //o
    .ccin_rxbundle_RDATA    (cc2_area_cc2_reg_simplebus_RDATA[63:0]      ), //i
    .ccout_txbundle_WADDR   (cc2_area_fifo_cc2_ccout_txbundle_WADDR[8:0] ), //o
    .ccout_txbundle_WDATA   (cc2_area_fifo_cc2_ccout_txbundle_WDATA[63:0]), //o
    .ccout_txbundle_WENABLE (cc2_area_fifo_cc2_ccout_txbundle_WENABLE    ), //o
    .tx_tick                (tx_tick_cc2                                 ), //i
    .ccin_clk               (ccout_clk                                   ), //i
    .ccout_clk              (ccin_clk                                    ), //i
    .reset                  (reset                                       )  //i
  );
  assign data_out_cc1_0 = cc1_area_cc1_reg_data_out_0; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_1 = cc1_area_cc1_reg_data_out_1; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_2 = cc1_area_cc1_reg_data_out_2; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_3 = cc1_area_cc1_reg_data_out_3; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_4 = cc1_area_cc1_reg_data_out_4; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_5 = cc1_area_cc1_reg_data_out_5; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_6 = cc1_area_cc1_reg_data_out_6; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_7 = cc1_area_cc1_reg_data_out_7; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_8 = cc1_area_cc1_reg_data_out_8; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_9 = cc1_area_cc1_reg_data_out_9; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_10 = cc1_area_cc1_reg_data_out_10; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_11 = cc1_area_cc1_reg_data_out_11; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_12 = cc1_area_cc1_reg_data_out_12; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_13 = cc1_area_cc1_reg_data_out_13; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_14 = cc1_area_cc1_reg_data_out_14; // @[Srio_Common.scala 156:26]
  assign data_out_cc1_15 = cc1_area_cc1_reg_data_out_15; // @[Srio_Common.scala 156:26]
  assign data_out_cc2_0 = cc2_area_cc2_reg_data_out_0; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_1 = cc2_area_cc2_reg_data_out_1; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_2 = cc2_area_cc2_reg_data_out_2; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_3 = cc2_area_cc2_reg_data_out_3; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_4 = cc2_area_cc2_reg_data_out_4; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_5 = cc2_area_cc2_reg_data_out_5; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_6 = cc2_area_cc2_reg_data_out_6; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_7 = cc2_area_cc2_reg_data_out_7; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_8 = cc2_area_cc2_reg_data_out_8; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_9 = cc2_area_cc2_reg_data_out_9; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_10 = cc2_area_cc2_reg_data_out_10; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_11 = cc2_area_cc2_reg_data_out_11; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_12 = cc2_area_cc2_reg_data_out_12; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_13 = cc2_area_cc2_reg_data_out_13; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_14 = cc2_area_cc2_reg_data_out_14; // @[Srio_Common.scala 175:26]
  assign data_out_cc2_15 = cc2_area_cc2_reg_data_out_15; // @[Srio_Common.scala 175:26]

endmodule

module Srio_FifoCc (
  output              ccin_rxbundle_RENABLE,
  output     [8:0]    ccin_rxbundle_RADDR,
  input      [63:0]   ccin_rxbundle_RDATA,
  output     [8:0]    ccout_txbundle_WADDR,
  output     [63:0]   ccout_txbundle_WDATA,
  output              ccout_txbundle_WENABLE,
  input               tx_tick,
  input               ccin_clk,
  input               ccout_clk,
  input               reset
);
  localparam srio_area_fsm_enumDef_BOOT = 2'd0;
  localparam srio_area_fsm_enumDef_Wait_Start = 2'd1;
  localparam srio_area_fsm_enumDef_Send_Data = 2'd2;
  localparam srio_area_fsm_enumDef_End_1 = 2'd3;

  wire                srio_area_streamfifo_io_push_ready;
  wire                srio_area_streamfifo_io_pop_valid;
  wire       [63:0]   srio_area_streamfifo_io_pop_payload;
  wire       [6:0]    srio_area_streamfifo_io_pushOccupancy;
  wire       [6:0]    srio_area_streamfifo_io_popOccupancy;
  wire                srio_area_streamfifo_srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1;
  wire                gtx_area_pluse_io_pulseOut;
  reg                 srio_area_trigger;
  reg                 srio_area_RENABLE;
  reg        [8:0]    srio_area_RADDR;
  reg                 srio_area_tx_tick;
  reg                 srio_area_last;
  reg        [7:0]    srio_area_send_length;
  wire                srio_area_fsm_wantExit;
  reg                 srio_area_fsm_wantStart;
  wire                srio_area_fsm_wantKill;
  reg                 srio_area_RENABLE_regNext;
  reg        [8:0]    gtx_area_waddr;
  reg        [63:0]   gtx_area_wdata;
  reg                 gtx_area_wenable;
  reg                 gtx_area_ready;
  reg                 gtx_area_pluse_out;
  reg                 gtx_area_pluse_out_regNext;
  wire                when_Srio_Common_l107;
  wire                when_Srio_Common_l109;
  wire                cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire;
  wire                cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire_1;
  reg        [8:0]    gtx_area_waddr_regNext;
  reg        [1:0]    srio_area_fsm_stateReg;
  reg        [1:0]    srio_area_fsm_stateNext;
  reg                 srio_area_tx_tick_regNext;
  wire                when_Srio_Common_l63;
  wire                when_Srio_Common_l75;
  `ifndef SYNTHESIS
  reg [79:0] srio_area_fsm_stateReg_string;
  reg [79:0] srio_area_fsm_stateNext_string;
  `endif


  StreamFifoCC srio_area_streamfifo (
    .io_push_valid                                              (srio_area_RENABLE_regNext                                                      ), //i
    .io_push_ready                                              (srio_area_streamfifo_io_push_ready                                             ), //o
    .io_push_payload                                            (ccin_rxbundle_RDATA[63:0]                                                      ), //i
    .io_pop_valid                                               (srio_area_streamfifo_io_pop_valid                                              ), //o
    .io_pop_ready                                               (gtx_area_ready                                                                 ), //i
    .io_pop_payload                                             (srio_area_streamfifo_io_pop_payload[63:0]                                      ), //o
    .io_pushOccupancy                                           (srio_area_streamfifo_io_pushOccupancy[6:0]                                     ), //o
    .io_popOccupancy                                            (srio_area_streamfifo_io_popOccupancy[6:0]                                      ), //o
    .ccin_clk                                                   (ccin_clk                                                                       ), //i
    .reset                                                      (reset                                                                          ), //i
    .ccout_clk                                                  (ccout_clk                                                                      ), //i
    .srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1 (srio_area_streamfifo_srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1)  //o
  );
  PulseCCByToggle gtx_area_pluse (
    .io_pulseIn                                               (srio_area_trigger                                                              ), //i
    .io_pulseOut                                              (gtx_area_pluse_io_pulseOut                                                     ), //o
    .ccin_clk                                                 (ccin_clk                                                                       ), //i
    .reset                                                    (reset                                                                          ), //i
    .ccout_clk                                                (ccout_clk                                                                      ), //i
    .srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized (srio_area_streamfifo_srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1)  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateReg_string = "BOOT      ";
      srio_area_fsm_enumDef_Wait_Start : srio_area_fsm_stateReg_string = "Wait_Start";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateReg_string = "Send_Data ";
      srio_area_fsm_enumDef_End_1 : srio_area_fsm_stateReg_string = "End_1     ";
      default : srio_area_fsm_stateReg_string = "??????????";
    endcase
  end
  always @(*) begin
    case(srio_area_fsm_stateNext)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateNext_string = "BOOT      ";
      srio_area_fsm_enumDef_Wait_Start : srio_area_fsm_stateNext_string = "Wait_Start";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateNext_string = "Send_Data ";
      srio_area_fsm_enumDef_End_1 : srio_area_fsm_stateNext_string = "End_1     ";
      default : srio_area_fsm_stateNext_string = "??????????";
    endcase
  end
  `endif

  assign srio_area_fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    srio_area_fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
      end
      srio_area_fsm_enumDef_Send_Data : begin
      end
      srio_area_fsm_enumDef_End_1 : begin
      end
      default : begin
        srio_area_fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign srio_area_fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign ccin_rxbundle_RADDR = srio_area_RADDR; // @[Srio_Common.scala 91:28]
  assign ccin_rxbundle_RENABLE = srio_area_RENABLE; // @[Srio_Common.scala 92:30]
  assign when_Srio_Common_l107 = (gtx_area_pluse_out && (! gtx_area_pluse_out_regNext)); // @[BaseType.scala 305:24]
  assign when_Srio_Common_l109 = (srio_area_streamfifo_io_popOccupancy == 7'h0); // @[BaseType.scala 305:24]
  assign cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire = (srio_area_streamfifo_io_pop_valid && gtx_area_ready); // @[BaseType.scala 305:24]
  assign cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire_1 = (srio_area_streamfifo_io_pop_valid && gtx_area_ready); // @[BaseType.scala 305:24]
  assign ccout_txbundle_WENABLE = gtx_area_wenable; // @[Srio_Common.scala 122:33]
  assign ccout_txbundle_WDATA = gtx_area_wdata; // @[Srio_Common.scala 123:31]
  assign ccout_txbundle_WADDR = gtx_area_waddr_regNext; // @[Srio_Common.scala 124:31]
  always @(*) begin
    srio_area_fsm_stateNext = srio_area_fsm_stateReg; // @[StateMachine.scala 217:17]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
        if(when_Srio_Common_l63) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Data; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_Send_Data : begin
        if(when_Srio_Common_l75) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_End_1; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_End_1 : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Wait_Start; // @[Enum.scala 148:67]
      end
      default : begin
      end
    endcase
    if(srio_area_fsm_wantStart) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_Wait_Start; // @[Enum.scala 148:67]
    end
    if(srio_area_fsm_wantKill) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_BOOT; // @[Enum.scala 148:67]
    end
  end

  assign when_Srio_Common_l63 = (srio_area_tx_tick && (! srio_area_tx_tick_regNext)); // @[BaseType.scala 305:24]
  assign when_Srio_Common_l75 = (srio_area_send_length == 8'h0f); // @[BaseType.scala 305:24]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      srio_area_trigger <= 1'b0; // @[Data.scala 400:33]
      srio_area_RENABLE <= 1'b0; // @[Data.scala 400:33]
      srio_area_RADDR <= 9'h0; // @[Data.scala 400:33]
      srio_area_tx_tick <= 1'b0; // @[Data.scala 400:33]
      srio_area_send_length <= 8'h0; // @[Data.scala 400:33]
      srio_area_fsm_stateReg <= srio_area_fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      srio_area_tx_tick <= tx_tick; // @[Srio_Common.scala 53:13]
      srio_area_fsm_stateReg <= srio_area_fsm_stateNext; // @[StateMachine.scala 212:14]
      case(srio_area_fsm_stateReg)
        srio_area_fsm_enumDef_Wait_Start : begin
          if(when_Srio_Common_l63) begin
            srio_area_RADDR <= 9'h0; // @[Srio_Common.scala 64:19]
            srio_area_RENABLE <= 1'b1; // @[Srio_Common.scala 65:21]
          end
          srio_area_trigger <= 1'b0; // @[Srio_Common.scala 68:19]
        end
        srio_area_fsm_enumDef_Send_Data : begin
          srio_area_RADDR <= (srio_area_RADDR + 9'h008); // @[Srio_Common.scala 73:17]
          srio_area_send_length <= (srio_area_send_length + 8'h01); // @[Srio_Common.scala 74:23]
          if(when_Srio_Common_l75) begin
            srio_area_RENABLE <= 1'b0; // @[Srio_Common.scala 77:21]
          end
        end
        srio_area_fsm_enumDef_End_1 : begin
          srio_area_send_length <= 8'h0; // @[Srio_Common.scala 84:23]
          srio_area_RENABLE <= 1'b0; // @[Srio_Common.scala 85:19]
          srio_area_trigger <= 1'b1; // @[Srio_Common.scala 86:19]
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge ccin_clk) begin
    srio_area_last <= 1'b0; // @[Srio_Common.scala 56:10]
    srio_area_RENABLE_regNext <= srio_area_RENABLE; // @[Reg.scala 39:30]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
      end
      srio_area_fsm_enumDef_Send_Data : begin
        if(when_Srio_Common_l75) begin
          srio_area_last <= 1'b1; // @[Srio_Common.scala 76:18]
        end
      end
      srio_area_fsm_enumDef_End_1 : begin
      end
      default : begin
      end
    endcase
  end

  always @(posedge ccout_clk or posedge reset) begin
    if(reset) begin
      gtx_area_waddr <= 9'h080; // @[Data.scala 400:33]
      gtx_area_wenable <= 1'b0; // @[Data.scala 400:33]
      gtx_area_ready <= 1'b0; // @[Data.scala 400:33]
      gtx_area_pluse_out <= 1'b0; // @[Data.scala 400:33]
    end else begin
      gtx_area_pluse_out <= gtx_area_pluse_io_pulseOut; // @[Srio_Common.scala 105:17]
      if(when_Srio_Common_l107) begin
        gtx_area_ready <= 1'b1; // @[Srio_Common.scala 108:15]
      end else begin
        if(when_Srio_Common_l109) begin
          gtx_area_ready <= 1'b0; // @[Srio_Common.scala 110:15]
          gtx_area_waddr <= 9'h080; // @[Srio_Common.scala 111:15]
        end else begin
          gtx_area_ready <= gtx_area_ready; // @[Srio_Common.scala 113:15]
        end
      end
      gtx_area_wenable <= cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire; // @[Srio_Common.scala 117:15]
      if(cc2_area_fifo_cc2_srio_area_streamfifo_io_pop_fire_1) begin
        gtx_area_waddr <= (gtx_area_waddr + 9'h008); // @[Srio_Common.scala 120:15]
      end
    end
  end

  always @(posedge ccout_clk) begin
    gtx_area_pluse_out_regNext <= gtx_area_pluse_out; // @[Reg.scala 39:30]
    gtx_area_wdata <= srio_area_streamfifo_io_pop_payload; // @[Srio_Common.scala 118:13]
    gtx_area_waddr_regNext <= gtx_area_waddr; // @[Reg.scala 39:30]
  end

  always @(posedge ccin_clk) begin
    srio_area_tx_tick_regNext <= srio_area_tx_tick; // @[Reg.scala 39:30]
  end


endmodule

module Srio_Common (
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
  input               ccout_clk,
  input               reset
);

  reg                 busslave_readError;
  reg        [63:0]   busslave_readData;
  wire                read_hit_0x0000;
  wire                write_hit_0x0000;
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
  reg        [63:0]   _zz_data_out_0;
  wire                read_hit_0x0088;
  wire                write_hit_0x0088;
  reg        [63:0]   _zz_data_out_1;
  wire                read_hit_0x0090;
  wire                write_hit_0x0090;
  reg        [63:0]   _zz_data_out_2;
  wire                read_hit_0x0098;
  wire                write_hit_0x0098;
  reg        [63:0]   _zz_data_out_3;
  wire                read_hit_0x00a0;
  wire                write_hit_0x00a0;
  reg        [63:0]   _zz_data_out_4;
  wire                read_hit_0x00a8;
  wire                write_hit_0x00a8;
  reg        [63:0]   _zz_data_out_5;
  wire                read_hit_0x00b0;
  wire                write_hit_0x00b0;
  reg        [63:0]   _zz_data_out_6;
  wire                read_hit_0x00b8;
  wire                write_hit_0x00b8;
  reg        [63:0]   _zz_data_out_7;
  wire                read_hit_0x00c0;
  wire                write_hit_0x00c0;
  reg        [63:0]   _zz_data_out_8;
  wire                read_hit_0x00c8;
  wire                write_hit_0x00c8;
  reg        [63:0]   _zz_data_out_9;
  wire                read_hit_0x00d0;
  wire                write_hit_0x00d0;
  reg        [63:0]   _zz_data_out_10;
  wire                read_hit_0x00d8;
  wire                write_hit_0x00d8;
  reg        [63:0]   _zz_data_out_11;
  wire                read_hit_0x00e0;
  wire                write_hit_0x00e0;
  reg        [63:0]   _zz_data_out_12;
  wire                read_hit_0x00e8;
  wire                write_hit_0x00e8;
  reg        [63:0]   _zz_data_out_13;
  wire                read_hit_0x00f0;
  wire                write_hit_0x00f0;
  reg        [63:0]   _zz_data_out_14;
  wire                read_hit_0x00f8;
  wire                write_hit_0x00f8;
  reg        [63:0]   _zz_data_out_15;

  assign simplebus_RDATA = busslave_readData; // @[SimpleBus.scala 47:13]
  assign read_hit_0x0000 = ((simplebus_RADDR == 9'h0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0000 = ((simplebus_WADDR == 9'h0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
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
  assign data_out_0 = _zz_data_out_0; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0088 = ((simplebus_RADDR == 9'h088) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0088 = ((simplebus_WADDR == 9'h088) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_1 = _zz_data_out_1; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0090 = ((simplebus_RADDR == 9'h090) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0090 = ((simplebus_WADDR == 9'h090) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_2 = _zz_data_out_2; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0098 = ((simplebus_RADDR == 9'h098) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0098 = ((simplebus_WADDR == 9'h098) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_3 = _zz_data_out_3; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00a0 = ((simplebus_RADDR == 9'h0a0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a0 = ((simplebus_WADDR == 9'h0a0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_4 = _zz_data_out_4; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00a8 = ((simplebus_RADDR == 9'h0a8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a8 = ((simplebus_WADDR == 9'h0a8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_5 = _zz_data_out_5; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00b0 = ((simplebus_RADDR == 9'h0b0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b0 = ((simplebus_WADDR == 9'h0b0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_6 = _zz_data_out_6; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00b8 = ((simplebus_RADDR == 9'h0b8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b8 = ((simplebus_WADDR == 9'h0b8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_7 = _zz_data_out_7; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00c0 = ((simplebus_RADDR == 9'h0c0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c0 = ((simplebus_WADDR == 9'h0c0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_8 = _zz_data_out_8; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00c8 = ((simplebus_RADDR == 9'h0c8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c8 = ((simplebus_WADDR == 9'h0c8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_9 = _zz_data_out_9; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00d0 = ((simplebus_RADDR == 9'h0d0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d0 = ((simplebus_WADDR == 9'h0d0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_10 = _zz_data_out_10; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00d8 = ((simplebus_RADDR == 9'h0d8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d8 = ((simplebus_WADDR == 9'h0d8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_11 = _zz_data_out_11; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00e0 = ((simplebus_RADDR == 9'h0e0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e0 = ((simplebus_WADDR == 9'h0e0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_12 = _zz_data_out_12; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00e8 = ((simplebus_RADDR == 9'h0e8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e8 = ((simplebus_WADDR == 9'h0e8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_13 = _zz_data_out_13; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00f0 = ((simplebus_RADDR == 9'h0f0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f0 = ((simplebus_WADDR == 9'h0f0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_14 = _zz_data_out_14; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00f8 = ((simplebus_RADDR == 9'h0f8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f8 = ((simplebus_WADDR == 9'h0f8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_15 = _zz_data_out_15; // @[Srio_Common.scala 28:20]
  always @(posedge ccout_clk or posedge reset) begin
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
      if(write_hit_0x0080) begin
        _zz_data_out_0 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0088) begin
        _zz_data_out_1 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0090) begin
        _zz_data_out_2 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0098) begin
        _zz_data_out_3 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a0) begin
        _zz_data_out_4 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a8) begin
        _zz_data_out_5 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b0) begin
        _zz_data_out_6 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b8) begin
        _zz_data_out_7 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c0) begin
        _zz_data_out_8 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c8) begin
        _zz_data_out_9 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d0) begin
        _zz_data_out_10 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d8) begin
        _zz_data_out_11 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e0) begin
        _zz_data_out_12 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e8) begin
        _zz_data_out_13 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f0) begin
        _zz_data_out_14 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f8) begin
        _zz_data_out_15 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(simplebus_RENABLE) begin
        case(simplebus_RADDR)
          9'h0 : begin
            busslave_readData <= data_in_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h008 : begin
            busslave_readData <= data_in_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h010 : begin
            busslave_readData <= data_in_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h018 : begin
            busslave_readData <= data_in_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h020 : begin
            busslave_readData <= data_in_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h028 : begin
            busslave_readData <= data_in_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h030 : begin
            busslave_readData <= data_in_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h038 : begin
            busslave_readData <= data_in_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h040 : begin
            busslave_readData <= data_in_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h048 : begin
            busslave_readData <= data_in_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h050 : begin
            busslave_readData <= data_in_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h058 : begin
            busslave_readData <= data_in_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h060 : begin
            busslave_readData <= data_in_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h068 : begin
            busslave_readData <= data_in_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h070 : begin
            busslave_readData <= data_in_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h078 : begin
            busslave_readData <= data_in_15; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h080 : begin
            busslave_readData <= _zz_data_out_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h088 : begin
            busslave_readData <= _zz_data_out_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h090 : begin
            busslave_readData <= _zz_data_out_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h098 : begin
            busslave_readData <= _zz_data_out_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a0 : begin
            busslave_readData <= _zz_data_out_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a8 : begin
            busslave_readData <= _zz_data_out_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b0 : begin
            busslave_readData <= _zz_data_out_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b8 : begin
            busslave_readData <= _zz_data_out_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c0 : begin
            busslave_readData <= _zz_data_out_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c8 : begin
            busslave_readData <= _zz_data_out_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d0 : begin
            busslave_readData <= _zz_data_out_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d8 : begin
            busslave_readData <= _zz_data_out_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e0 : begin
            busslave_readData <= _zz_data_out_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e8 : begin
            busslave_readData <= _zz_data_out_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f0 : begin
            busslave_readData <= _zz_data_out_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f8 : begin
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

module Srio_FifoCc_1 (
  output              ccin_rxbundle_RENABLE,
  output     [8:0]    ccin_rxbundle_RADDR,
  input      [63:0]   ccin_rxbundle_RDATA,
  output     [8:0]    ccout_txbundle_WADDR,
  output     [63:0]   ccout_txbundle_WDATA,
  output              ccout_txbundle_WENABLE,
  input               tx_tick,
  input               ccin_clk,
  input               ccout_clk,
  input               reset
);
  localparam srio_area_fsm_enumDef_BOOT = 2'd0;
  localparam srio_area_fsm_enumDef_Wait_Start = 2'd1;
  localparam srio_area_fsm_enumDef_Send_Data = 2'd2;
  localparam srio_area_fsm_enumDef_End_1 = 2'd3;

  wire                srio_area_streamfifo_io_push_ready;
  wire                srio_area_streamfifo_io_pop_valid;
  wire       [63:0]   srio_area_streamfifo_io_pop_payload;
  wire       [6:0]    srio_area_streamfifo_io_pushOccupancy;
  wire       [6:0]    srio_area_streamfifo_io_popOccupancy;
  wire                srio_area_streamfifo_srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1;
  wire                gtx_area_pluse_io_pulseOut;
  reg                 srio_area_trigger;
  reg                 srio_area_RENABLE;
  reg        [8:0]    srio_area_RADDR;
  reg                 srio_area_tx_tick;
  reg                 srio_area_last;
  reg        [7:0]    srio_area_send_length;
  wire                srio_area_fsm_wantExit;
  reg                 srio_area_fsm_wantStart;
  wire                srio_area_fsm_wantKill;
  reg                 srio_area_RENABLE_regNext;
  reg        [8:0]    gtx_area_waddr;
  reg        [63:0]   gtx_area_wdata;
  reg                 gtx_area_wenable;
  reg                 gtx_area_ready;
  reg                 gtx_area_pluse_out;
  reg                 gtx_area_pluse_out_regNext;
  wire                when_Srio_Common_l107;
  wire                when_Srio_Common_l109;
  wire                cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire;
  wire                cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire_1;
  reg        [8:0]    gtx_area_waddr_regNext;
  reg        [1:0]    srio_area_fsm_stateReg;
  reg        [1:0]    srio_area_fsm_stateNext;
  reg                 srio_area_tx_tick_regNext;
  wire                when_Srio_Common_l63;
  wire                when_Srio_Common_l75;
  `ifndef SYNTHESIS
  reg [79:0] srio_area_fsm_stateReg_string;
  reg [79:0] srio_area_fsm_stateNext_string;
  `endif


  StreamFifoCC_1 srio_area_streamfifo (
    .io_push_valid                                              (srio_area_RENABLE_regNext                                                      ), //i
    .io_push_ready                                              (srio_area_streamfifo_io_push_ready                                             ), //o
    .io_push_payload                                            (ccin_rxbundle_RDATA[63:0]                                                      ), //i
    .io_pop_valid                                               (srio_area_streamfifo_io_pop_valid                                              ), //o
    .io_pop_ready                                               (gtx_area_ready                                                                 ), //i
    .io_pop_payload                                             (srio_area_streamfifo_io_pop_payload[63:0]                                      ), //o
    .io_pushOccupancy                                           (srio_area_streamfifo_io_pushOccupancy[6:0]                                     ), //o
    .io_popOccupancy                                            (srio_area_streamfifo_io_popOccupancy[6:0]                                      ), //o
    .ccin_clk                                                   (ccin_clk                                                                       ), //i
    .reset                                                      (reset                                                                          ), //i
    .ccout_clk                                                  (ccout_clk                                                                      ), //i
    .srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1 (srio_area_streamfifo_srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1)  //o
  );
  PulseCCByToggle_1 gtx_area_pluse (
    .io_pulseIn                                               (srio_area_trigger                                                              ), //i
    .io_pulseOut                                              (gtx_area_pluse_io_pulseOut                                                     ), //o
    .ccin_clk                                                 (ccin_clk                                                                       ), //i
    .reset                                                    (reset                                                                          ), //i
    .ccout_clk                                                (ccout_clk                                                                      ), //i
    .srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized (srio_area_streamfifo_srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1)  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateReg_string = "BOOT      ";
      srio_area_fsm_enumDef_Wait_Start : srio_area_fsm_stateReg_string = "Wait_Start";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateReg_string = "Send_Data ";
      srio_area_fsm_enumDef_End_1 : srio_area_fsm_stateReg_string = "End_1     ";
      default : srio_area_fsm_stateReg_string = "??????????";
    endcase
  end
  always @(*) begin
    case(srio_area_fsm_stateNext)
      srio_area_fsm_enumDef_BOOT : srio_area_fsm_stateNext_string = "BOOT      ";
      srio_area_fsm_enumDef_Wait_Start : srio_area_fsm_stateNext_string = "Wait_Start";
      srio_area_fsm_enumDef_Send_Data : srio_area_fsm_stateNext_string = "Send_Data ";
      srio_area_fsm_enumDef_End_1 : srio_area_fsm_stateNext_string = "End_1     ";
      default : srio_area_fsm_stateNext_string = "??????????";
    endcase
  end
  `endif

  assign srio_area_fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    srio_area_fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
      end
      srio_area_fsm_enumDef_Send_Data : begin
      end
      srio_area_fsm_enumDef_End_1 : begin
      end
      default : begin
        srio_area_fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign srio_area_fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign ccin_rxbundle_RADDR = srio_area_RADDR; // @[Srio_Common.scala 91:28]
  assign ccin_rxbundle_RENABLE = srio_area_RENABLE; // @[Srio_Common.scala 92:30]
  assign when_Srio_Common_l107 = (gtx_area_pluse_out && (! gtx_area_pluse_out_regNext)); // @[BaseType.scala 305:24]
  assign when_Srio_Common_l109 = (srio_area_streamfifo_io_popOccupancy == 7'h0); // @[BaseType.scala 305:24]
  assign cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire = (srio_area_streamfifo_io_pop_valid && gtx_area_ready); // @[BaseType.scala 305:24]
  assign cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire_1 = (srio_area_streamfifo_io_pop_valid && gtx_area_ready); // @[BaseType.scala 305:24]
  assign ccout_txbundle_WENABLE = gtx_area_wenable; // @[Srio_Common.scala 122:33]
  assign ccout_txbundle_WDATA = gtx_area_wdata; // @[Srio_Common.scala 123:31]
  assign ccout_txbundle_WADDR = gtx_area_waddr_regNext; // @[Srio_Common.scala 124:31]
  always @(*) begin
    srio_area_fsm_stateNext = srio_area_fsm_stateReg; // @[StateMachine.scala 217:17]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
        if(when_Srio_Common_l63) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_Send_Data; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_Send_Data : begin
        if(when_Srio_Common_l75) begin
          srio_area_fsm_stateNext = srio_area_fsm_enumDef_End_1; // @[Enum.scala 148:67]
        end
      end
      srio_area_fsm_enumDef_End_1 : begin
        srio_area_fsm_stateNext = srio_area_fsm_enumDef_Wait_Start; // @[Enum.scala 148:67]
      end
      default : begin
      end
    endcase
    if(srio_area_fsm_wantStart) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_Wait_Start; // @[Enum.scala 148:67]
    end
    if(srio_area_fsm_wantKill) begin
      srio_area_fsm_stateNext = srio_area_fsm_enumDef_BOOT; // @[Enum.scala 148:67]
    end
  end

  assign when_Srio_Common_l63 = (srio_area_tx_tick && (! srio_area_tx_tick_regNext)); // @[BaseType.scala 305:24]
  assign when_Srio_Common_l75 = (srio_area_send_length == 8'h0f); // @[BaseType.scala 305:24]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      srio_area_trigger <= 1'b0; // @[Data.scala 400:33]
      srio_area_RENABLE <= 1'b0; // @[Data.scala 400:33]
      srio_area_RADDR <= 9'h0; // @[Data.scala 400:33]
      srio_area_tx_tick <= 1'b0; // @[Data.scala 400:33]
      srio_area_send_length <= 8'h0; // @[Data.scala 400:33]
      srio_area_fsm_stateReg <= srio_area_fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      srio_area_tx_tick <= tx_tick; // @[Srio_Common.scala 53:13]
      srio_area_fsm_stateReg <= srio_area_fsm_stateNext; // @[StateMachine.scala 212:14]
      case(srio_area_fsm_stateReg)
        srio_area_fsm_enumDef_Wait_Start : begin
          if(when_Srio_Common_l63) begin
            srio_area_RADDR <= 9'h0; // @[Srio_Common.scala 64:19]
            srio_area_RENABLE <= 1'b1; // @[Srio_Common.scala 65:21]
          end
          srio_area_trigger <= 1'b0; // @[Srio_Common.scala 68:19]
        end
        srio_area_fsm_enumDef_Send_Data : begin
          srio_area_RADDR <= (srio_area_RADDR + 9'h008); // @[Srio_Common.scala 73:17]
          srio_area_send_length <= (srio_area_send_length + 8'h01); // @[Srio_Common.scala 74:23]
          if(when_Srio_Common_l75) begin
            srio_area_RENABLE <= 1'b0; // @[Srio_Common.scala 77:21]
          end
        end
        srio_area_fsm_enumDef_End_1 : begin
          srio_area_send_length <= 8'h0; // @[Srio_Common.scala 84:23]
          srio_area_RENABLE <= 1'b0; // @[Srio_Common.scala 85:19]
          srio_area_trigger <= 1'b1; // @[Srio_Common.scala 86:19]
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge ccin_clk) begin
    srio_area_last <= 1'b0; // @[Srio_Common.scala 56:10]
    srio_area_RENABLE_regNext <= srio_area_RENABLE; // @[Reg.scala 39:30]
    case(srio_area_fsm_stateReg)
      srio_area_fsm_enumDef_Wait_Start : begin
      end
      srio_area_fsm_enumDef_Send_Data : begin
        if(when_Srio_Common_l75) begin
          srio_area_last <= 1'b1; // @[Srio_Common.scala 76:18]
        end
      end
      srio_area_fsm_enumDef_End_1 : begin
      end
      default : begin
      end
    endcase
  end

  always @(posedge ccout_clk or posedge reset) begin
    if(reset) begin
      gtx_area_waddr <= 9'h080; // @[Data.scala 400:33]
      gtx_area_wenable <= 1'b0; // @[Data.scala 400:33]
      gtx_area_ready <= 1'b0; // @[Data.scala 400:33]
      gtx_area_pluse_out <= 1'b0; // @[Data.scala 400:33]
    end else begin
      gtx_area_pluse_out <= gtx_area_pluse_io_pulseOut; // @[Srio_Common.scala 105:17]
      if(when_Srio_Common_l107) begin
        gtx_area_ready <= 1'b1; // @[Srio_Common.scala 108:15]
      end else begin
        if(when_Srio_Common_l109) begin
          gtx_area_ready <= 1'b0; // @[Srio_Common.scala 110:15]
          gtx_area_waddr <= 9'h080; // @[Srio_Common.scala 111:15]
        end else begin
          gtx_area_ready <= gtx_area_ready; // @[Srio_Common.scala 113:15]
        end
      end
      gtx_area_wenable <= cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire; // @[Srio_Common.scala 117:15]
      if(cc1_area_fifo_cc1_srio_area_streamfifo_io_pop_fire_1) begin
        gtx_area_waddr <= (gtx_area_waddr + 9'h008); // @[Srio_Common.scala 120:15]
      end
    end
  end

  always @(posedge ccout_clk) begin
    gtx_area_pluse_out_regNext <= gtx_area_pluse_out; // @[Reg.scala 39:30]
    gtx_area_wdata <= srio_area_streamfifo_io_pop_payload; // @[Srio_Common.scala 118:13]
    gtx_area_waddr_regNext <= gtx_area_waddr; // @[Reg.scala 39:30]
  end

  always @(posedge ccin_clk) begin
    srio_area_tx_tick_regNext <= srio_area_tx_tick; // @[Reg.scala 39:30]
  end


endmodule

module Srio_Common_1 (
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
  input               ccin_clk,
  input               reset
);

  reg                 busslave_readError;
  reg        [63:0]   busslave_readData;
  wire                read_hit_0x0000;
  wire                write_hit_0x0000;
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
  reg        [63:0]   _zz_data_out_0;
  wire                read_hit_0x0088;
  wire                write_hit_0x0088;
  reg        [63:0]   _zz_data_out_1;
  wire                read_hit_0x0090;
  wire                write_hit_0x0090;
  reg        [63:0]   _zz_data_out_2;
  wire                read_hit_0x0098;
  wire                write_hit_0x0098;
  reg        [63:0]   _zz_data_out_3;
  wire                read_hit_0x00a0;
  wire                write_hit_0x00a0;
  reg        [63:0]   _zz_data_out_4;
  wire                read_hit_0x00a8;
  wire                write_hit_0x00a8;
  reg        [63:0]   _zz_data_out_5;
  wire                read_hit_0x00b0;
  wire                write_hit_0x00b0;
  reg        [63:0]   _zz_data_out_6;
  wire                read_hit_0x00b8;
  wire                write_hit_0x00b8;
  reg        [63:0]   _zz_data_out_7;
  wire                read_hit_0x00c0;
  wire                write_hit_0x00c0;
  reg        [63:0]   _zz_data_out_8;
  wire                read_hit_0x00c8;
  wire                write_hit_0x00c8;
  reg        [63:0]   _zz_data_out_9;
  wire                read_hit_0x00d0;
  wire                write_hit_0x00d0;
  reg        [63:0]   _zz_data_out_10;
  wire                read_hit_0x00d8;
  wire                write_hit_0x00d8;
  reg        [63:0]   _zz_data_out_11;
  wire                read_hit_0x00e0;
  wire                write_hit_0x00e0;
  reg        [63:0]   _zz_data_out_12;
  wire                read_hit_0x00e8;
  wire                write_hit_0x00e8;
  reg        [63:0]   _zz_data_out_13;
  wire                read_hit_0x00f0;
  wire                write_hit_0x00f0;
  reg        [63:0]   _zz_data_out_14;
  wire                read_hit_0x00f8;
  wire                write_hit_0x00f8;
  reg        [63:0]   _zz_data_out_15;

  assign simplebus_RDATA = busslave_readData; // @[SimpleBus.scala 47:13]
  assign read_hit_0x0000 = ((simplebus_RADDR == 9'h0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0000 = ((simplebus_WADDR == 9'h0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
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
  assign data_out_0 = _zz_data_out_0; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0088 = ((simplebus_RADDR == 9'h088) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0088 = ((simplebus_WADDR == 9'h088) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_1 = _zz_data_out_1; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0090 = ((simplebus_RADDR == 9'h090) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0090 = ((simplebus_WADDR == 9'h090) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_2 = _zz_data_out_2; // @[Srio_Common.scala 28:20]
  assign read_hit_0x0098 = ((simplebus_RADDR == 9'h098) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x0098 = ((simplebus_WADDR == 9'h098) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_3 = _zz_data_out_3; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00a0 = ((simplebus_RADDR == 9'h0a0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a0 = ((simplebus_WADDR == 9'h0a0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_4 = _zz_data_out_4; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00a8 = ((simplebus_RADDR == 9'h0a8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00a8 = ((simplebus_WADDR == 9'h0a8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_5 = _zz_data_out_5; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00b0 = ((simplebus_RADDR == 9'h0b0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b0 = ((simplebus_WADDR == 9'h0b0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_6 = _zz_data_out_6; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00b8 = ((simplebus_RADDR == 9'h0b8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00b8 = ((simplebus_WADDR == 9'h0b8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_7 = _zz_data_out_7; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00c0 = ((simplebus_RADDR == 9'h0c0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c0 = ((simplebus_WADDR == 9'h0c0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_8 = _zz_data_out_8; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00c8 = ((simplebus_RADDR == 9'h0c8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00c8 = ((simplebus_WADDR == 9'h0c8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_9 = _zz_data_out_9; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00d0 = ((simplebus_RADDR == 9'h0d0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d0 = ((simplebus_WADDR == 9'h0d0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_10 = _zz_data_out_10; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00d8 = ((simplebus_RADDR == 9'h0d8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00d8 = ((simplebus_WADDR == 9'h0d8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_11 = _zz_data_out_11; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00e0 = ((simplebus_RADDR == 9'h0e0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e0 = ((simplebus_WADDR == 9'h0e0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_12 = _zz_data_out_12; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00e8 = ((simplebus_RADDR == 9'h0e8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00e8 = ((simplebus_WADDR == 9'h0e8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_13 = _zz_data_out_13; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00f0 = ((simplebus_RADDR == 9'h0f0) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f0 = ((simplebus_WADDR == 9'h0f0) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_14 = _zz_data_out_14; // @[Srio_Common.scala 28:20]
  assign read_hit_0x00f8 = ((simplebus_RADDR == 9'h0f8) && simplebus_RENABLE); // @[BaseType.scala 305:24]
  assign write_hit_0x00f8 = ((simplebus_WADDR == 9'h0f8) && simplebus_WENABLE); // @[BaseType.scala 305:24]
  assign data_out_15 = _zz_data_out_15; // @[Srio_Common.scala 28:20]
  always @(posedge ccin_clk or posedge reset) begin
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
      if(write_hit_0x0080) begin
        _zz_data_out_0 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0088) begin
        _zz_data_out_1 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0090) begin
        _zz_data_out_2 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x0098) begin
        _zz_data_out_3 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a0) begin
        _zz_data_out_4 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00a8) begin
        _zz_data_out_5 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b0) begin
        _zz_data_out_6 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00b8) begin
        _zz_data_out_7 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c0) begin
        _zz_data_out_8 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00c8) begin
        _zz_data_out_9 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d0) begin
        _zz_data_out_10 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00d8) begin
        _zz_data_out_11 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e0) begin
        _zz_data_out_12 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00e8) begin
        _zz_data_out_13 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f0) begin
        _zz_data_out_14 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(write_hit_0x00f8) begin
        _zz_data_out_15 <= simplebus_WDATA[63 : 0]; // @[RegInst.scala 385:11]
      end
      if(simplebus_RENABLE) begin
        case(simplebus_RADDR)
          9'h0 : begin
            busslave_readData <= data_in_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h008 : begin
            busslave_readData <= data_in_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h010 : begin
            busslave_readData <= data_in_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h018 : begin
            busslave_readData <= data_in_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h020 : begin
            busslave_readData <= data_in_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h028 : begin
            busslave_readData <= data_in_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h030 : begin
            busslave_readData <= data_in_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h038 : begin
            busslave_readData <= data_in_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h040 : begin
            busslave_readData <= data_in_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h048 : begin
            busslave_readData <= data_in_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h050 : begin
            busslave_readData <= data_in_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h058 : begin
            busslave_readData <= data_in_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h060 : begin
            busslave_readData <= data_in_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h068 : begin
            busslave_readData <= data_in_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h070 : begin
            busslave_readData <= data_in_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h078 : begin
            busslave_readData <= data_in_15; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h080 : begin
            busslave_readData <= _zz_data_out_0; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h088 : begin
            busslave_readData <= _zz_data_out_1; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h090 : begin
            busslave_readData <= _zz_data_out_2; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h098 : begin
            busslave_readData <= _zz_data_out_3; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a0 : begin
            busslave_readData <= _zz_data_out_4; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0a8 : begin
            busslave_readData <= _zz_data_out_5; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b0 : begin
            busslave_readData <= _zz_data_out_6; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0b8 : begin
            busslave_readData <= _zz_data_out_7; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c0 : begin
            busslave_readData <= _zz_data_out_8; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0c8 : begin
            busslave_readData <= _zz_data_out_9; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d0 : begin
            busslave_readData <= _zz_data_out_10; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0d8 : begin
            busslave_readData <= _zz_data_out_11; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e0 : begin
            busslave_readData <= _zz_data_out_12; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0e8 : begin
            busslave_readData <= _zz_data_out_13; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f0 : begin
            busslave_readData <= _zz_data_out_14; // @[BusIfBase.scala 252:27]
            busslave_readError <= 1'b0; // @[BusIfBase.scala 253:27]
          end
          9'h0f8 : begin
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

module PulseCCByToggle (
  input               io_pulseIn,
  output              io_pulseOut,
  input               ccin_clk,
  input               reset,
  input               ccout_clk,
  input               srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized
);

  wire                inArea_target_buffercc_io_dataOut;
  reg                 inArea_target;
  wire                outArea_target;
  reg                 outArea_target_regNext;

  BufferCC inArea_target_buffercc (
    .io_dataIn                                                (inArea_target                                           ), //i
    .io_dataOut                                               (inArea_target_buffercc_io_dataOut                       ), //o
    .ccout_clk                                                (ccout_clk                                               ), //i
    .srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized (srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized)  //i
  );
  assign outArea_target = inArea_target_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign io_pulseOut = (outArea_target ^ outArea_target_regNext); // @[CrossClock.scala 68:17]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      inArea_target <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(io_pulseIn) begin
        inArea_target <= (! inArea_target); // @[CrossClock.scala 60:33]
      end
    end
  end

  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
    if(srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
      outArea_target_regNext <= 1'b0; // @[Data.scala 400:33]
    end else begin
      outArea_target_regNext <= outArea_target; // @[Reg.scala 39:30]
    end
  end


endmodule

module StreamFifoCC (
  input               io_push_valid,
  output              io_push_ready,
  input      [63:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [63:0]   io_pop_payload,
  output     [6:0]    io_pushOccupancy,
  output     [6:0]    io_popOccupancy,
  input               ccin_clk,
  input               reset,
  input               ccout_clk,
  output              srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1
);

  reg        [63:0]   _zz_ram_port1;
  wire       [6:0]    popToPushGray_buffercc_io_dataOut;
  wire                bufferCC_8_io_dataOut;
  wire       [6:0]    pushToPopGray_buffercc_io_dataOut;
  wire       [6:0]    _zz_pushCC_pushPtrGray;
  wire       [5:0]    _zz_ram_port;
  wire       [6:0]    _zz_popCC_popPtrGray;
  wire       [5:0]    _zz_ram_port_1;
  wire                _zz_ram_port_2;
  wire       [5:0]    _zz_io_pop_payload_1;
  wire                _zz_io_pop_payload_2;
  reg                 _zz_1;
  wire       [6:0]    popToPushGray;
  wire       [6:0]    pushToPopGray;
  reg        [6:0]    pushCC_pushPtr;
  wire       [6:0]    pushCC_pushPtrPlus;
  wire                io_push_fire;
  reg        [6:0]    pushCC_pushPtrGray;
  wire       [6:0]    pushCC_popPtrGray;
  wire                pushCC_full;
  wire                io_push_fire_1;
  wire                _zz_io_pushOccupancy;
  wire                _zz_io_pushOccupancy_1;
  wire                _zz_io_pushOccupancy_2;
  wire                _zz_io_pushOccupancy_3;
  wire                _zz_io_pushOccupancy_4;
  wire                _zz_io_pushOccupancy_5;
  wire                srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized;
  reg        [6:0]    popCC_popPtr;
  wire       [6:0]    popCC_popPtrPlus;
  wire                io_pop_fire;
  reg        [6:0]    popCC_popPtrGray;
  wire       [6:0]    popCC_pushPtrGray;
  wire                popCC_empty;
  wire                io_pop_fire_1;
  wire       [6:0]    _zz_io_pop_payload;
  wire                io_pop_fire_2;
  wire                _zz_io_popOccupancy;
  wire                _zz_io_popOccupancy_1;
  wire                _zz_io_popOccupancy_2;
  wire                _zz_io_popOccupancy_3;
  wire                _zz_io_popOccupancy_4;
  wire                _zz_io_popOccupancy_5;
  reg [63:0] ram [0:63];

  assign _zz_pushCC_pushPtrGray = (pushCC_pushPtrPlus >>> 1'b1);
  assign _zz_ram_port = pushCC_pushPtr[5:0];
  assign _zz_popCC_popPtrGray = (popCC_popPtrPlus >>> 1'b1);
  assign _zz_io_pop_payload_1 = _zz_io_pop_payload[5:0];
  assign _zz_io_pop_payload_2 = 1'b1;
  always @(posedge ccin_clk) begin
    if(_zz_1) begin
      ram[_zz_ram_port] <= io_push_payload;
    end
  end

  always @(posedge ccout_clk) begin
    if(_zz_io_pop_payload_2) begin
      _zz_ram_port1 <= ram[_zz_io_pop_payload_1];
    end
  end

  BufferCC_7 popToPushGray_buffercc (
    .io_dataIn  (popToPushGray[6:0]                    ), //i
    .io_dataOut (popToPushGray_buffercc_io_dataOut[6:0]), //o
    .ccin_clk   (ccin_clk                              ), //i
    .reset      (reset                                 )  //i
  );
  BufferCC_6 bufferCC_8 (
    .io_dataIn  (1'b0                 ), //i
    .io_dataOut (bufferCC_8_io_dataOut), //o
    .ccout_clk  (ccout_clk            ), //i
    .reset      (reset                )  //i
  );
  BufferCC_1 pushToPopGray_buffercc (
    .io_dataIn                                                (pushToPopGray[6:0]                                      ), //i
    .io_dataOut                                               (pushToPopGray_buffercc_io_dataOut[6:0]                  ), //o
    .ccout_clk                                                (ccout_clk                                               ), //i
    .srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized (srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized)  //i
  );
  always @(*) begin
    _zz_1 = 1'b0; // @[when.scala 47:16]
    if(io_push_fire_1) begin
      _zz_1 = 1'b1; // @[when.scala 52:10]
    end
  end

  assign pushCC_pushPtrPlus = (pushCC_pushPtr + 7'h01); // @[BaseType.scala 299:24]
  assign io_push_fire = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign pushCC_popPtrGray = popToPushGray_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign pushCC_full = ((pushCC_pushPtrGray[6 : 5] == (~ pushCC_popPtrGray[6 : 5])) && (pushCC_pushPtrGray[4 : 0] == pushCC_popPtrGray[4 : 0])); // @[BaseType.scala 305:24]
  assign io_push_ready = (! pushCC_full); // @[Stream.scala 1334:19]
  assign io_push_fire_1 = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign _zz_io_pushOccupancy = (pushCC_popPtrGray[1] ^ _zz_io_pushOccupancy_1); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_1 = (pushCC_popPtrGray[2] ^ _zz_io_pushOccupancy_2); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_2 = (pushCC_popPtrGray[3] ^ _zz_io_pushOccupancy_3); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_3 = (pushCC_popPtrGray[4] ^ _zz_io_pushOccupancy_4); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_4 = (pushCC_popPtrGray[5] ^ _zz_io_pushOccupancy_5); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_5 = pushCC_popPtrGray[6]; // @[Utils.scala 381:14]
  assign io_pushOccupancy = (pushCC_pushPtr - {_zz_io_pushOccupancy_5,{_zz_io_pushOccupancy_4,{_zz_io_pushOccupancy_3,{_zz_io_pushOccupancy_2,{_zz_io_pushOccupancy_1,{_zz_io_pushOccupancy,(pushCC_popPtrGray[0] ^ _zz_io_pushOccupancy)}}}}}}); // @[Stream.scala 1341:22]
  assign srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized = bufferCC_8_io_dataOut; // @[CrossClock.scala 13:9]
  assign popCC_popPtrPlus = (popCC_popPtr + 7'h01); // @[BaseType.scala 299:24]
  assign io_pop_fire = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign popCC_pushPtrGray = pushToPopGray_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign popCC_empty = (popCC_popPtrGray == popCC_pushPtrGray); // @[BaseType.scala 305:24]
  assign io_pop_valid = (! popCC_empty); // @[Stream.scala 1352:20]
  assign io_pop_fire_1 = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign _zz_io_pop_payload = (io_pop_fire_1 ? popCC_popPtrPlus : popCC_popPtr); // @[Data.scala 450:19]
  assign io_pop_payload = _zz_ram_port1; // @[Stream.scala 1353:20]
  assign io_pop_fire_2 = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign _zz_io_popOccupancy = (popCC_pushPtrGray[1] ^ _zz_io_popOccupancy_1); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_1 = (popCC_pushPtrGray[2] ^ _zz_io_popOccupancy_2); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_2 = (popCC_pushPtrGray[3] ^ _zz_io_popOccupancy_3); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_3 = (popCC_pushPtrGray[4] ^ _zz_io_popOccupancy_4); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_4 = (popCC_pushPtrGray[5] ^ _zz_io_popOccupancy_5); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_5 = popCC_pushPtrGray[6]; // @[Utils.scala 381:14]
  assign io_popOccupancy = ({_zz_io_popOccupancy_5,{_zz_io_popOccupancy_4,{_zz_io_popOccupancy_3,{_zz_io_popOccupancy_2,{_zz_io_popOccupancy_1,{_zz_io_popOccupancy,(popCC_pushPtrGray[0] ^ _zz_io_popOccupancy)}}}}}} - popCC_popPtr); // @[Stream.scala 1359:21]
  assign pushToPopGray = pushCC_pushPtrGray; // @[Stream.scala 1362:17]
  assign popToPushGray = popCC_popPtrGray; // @[Stream.scala 1363:17]
  assign srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized_1 = srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized; // @[Data.scala 235:16]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      pushCC_pushPtr <= 7'h0; // @[Data.scala 400:33]
      pushCC_pushPtrGray <= 7'h0; // @[Data.scala 400:33]
    end else begin
      if(io_push_fire) begin
        pushCC_pushPtrGray <= (_zz_pushCC_pushPtrGray ^ pushCC_pushPtrPlus); // @[Stream.scala 1330:34]
      end
      if(io_push_fire_1) begin
        pushCC_pushPtr <= pushCC_pushPtrPlus; // @[Stream.scala 1338:15]
      end
    end
  end

  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
    if(srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
      popCC_popPtr <= 7'h0; // @[Data.scala 400:33]
      popCC_popPtrGray <= 7'h0; // @[Data.scala 400:33]
    end else begin
      if(io_pop_fire) begin
        popCC_popPtrGray <= (_zz_popCC_popPtrGray ^ popCC_popPtrPlus); // @[Stream.scala 1348:34]
      end
      if(io_pop_fire_2) begin
        popCC_popPtr <= popCC_popPtrPlus; // @[Stream.scala 1356:14]
      end
    end
  end


endmodule

module PulseCCByToggle_1 (
  input               io_pulseIn,
  output              io_pulseOut,
  input               ccin_clk,
  input               reset,
  input               ccout_clk,
  input               srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized
);

  wire                inArea_target_buffercc_io_dataOut;
  reg                 inArea_target;
  wire                outArea_target;
  reg                 outArea_target_regNext;

  BufferCC_4 inArea_target_buffercc (
    .io_dataIn                                                (inArea_target                                           ), //i
    .io_dataOut                                               (inArea_target_buffercc_io_dataOut                       ), //o
    .ccout_clk                                                (ccout_clk                                               ), //i
    .srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized (srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized)  //i
  );
  assign outArea_target = inArea_target_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign io_pulseOut = (outArea_target ^ outArea_target_regNext); // @[CrossClock.scala 68:17]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      inArea_target <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(io_pulseIn) begin
        inArea_target <= (! inArea_target); // @[CrossClock.scala 60:33]
      end
    end
  end

  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
    if(srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
      outArea_target_regNext <= 1'b0; // @[Data.scala 400:33]
    end else begin
      outArea_target_regNext <= outArea_target; // @[Reg.scala 39:30]
    end
  end


endmodule

module StreamFifoCC_1 (
  input               io_push_valid,
  output              io_push_ready,
  input      [63:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [63:0]   io_pop_payload,
  output     [6:0]    io_pushOccupancy,
  output     [6:0]    io_popOccupancy,
  input               ccin_clk,
  input               reset,
  input               ccout_clk,
  output              srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1
);

  reg        [63:0]   _zz_ram_port1;
  wire       [6:0]    popToPushGray_buffercc_io_dataOut;
  wire                bufferCC_8_io_dataOut;
  wire       [6:0]    pushToPopGray_buffercc_io_dataOut;
  wire       [6:0]    _zz_pushCC_pushPtrGray;
  wire       [5:0]    _zz_ram_port;
  wire       [6:0]    _zz_popCC_popPtrGray;
  wire       [5:0]    _zz_ram_port_1;
  wire                _zz_ram_port_2;
  wire       [5:0]    _zz_io_pop_payload_1;
  wire                _zz_io_pop_payload_2;
  reg                 _zz_1;
  wire       [6:0]    popToPushGray;
  wire       [6:0]    pushToPopGray;
  reg        [6:0]    pushCC_pushPtr;
  wire       [6:0]    pushCC_pushPtrPlus;
  wire                io_push_fire;
  reg        [6:0]    pushCC_pushPtrGray;
  wire       [6:0]    pushCC_popPtrGray;
  wire                pushCC_full;
  wire                io_push_fire_1;
  wire                _zz_io_pushOccupancy;
  wire                _zz_io_pushOccupancy_1;
  wire                _zz_io_pushOccupancy_2;
  wire                _zz_io_pushOccupancy_3;
  wire                _zz_io_pushOccupancy_4;
  wire                _zz_io_pushOccupancy_5;
  wire                srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized;
  reg        [6:0]    popCC_popPtr;
  wire       [6:0]    popCC_popPtrPlus;
  wire                io_pop_fire;
  reg        [6:0]    popCC_popPtrGray;
  wire       [6:0]    popCC_pushPtrGray;
  wire                popCC_empty;
  wire                io_pop_fire_1;
  wire       [6:0]    _zz_io_pop_payload;
  wire                io_pop_fire_2;
  wire                _zz_io_popOccupancy;
  wire                _zz_io_popOccupancy_1;
  wire                _zz_io_popOccupancy_2;
  wire                _zz_io_popOccupancy_3;
  wire                _zz_io_popOccupancy_4;
  wire                _zz_io_popOccupancy_5;
  reg [63:0] ram [0:63];

  assign _zz_pushCC_pushPtrGray = (pushCC_pushPtrPlus >>> 1'b1);
  assign _zz_ram_port = pushCC_pushPtr[5:0];
  assign _zz_popCC_popPtrGray = (popCC_popPtrPlus >>> 1'b1);
  assign _zz_io_pop_payload_1 = _zz_io_pop_payload[5:0];
  assign _zz_io_pop_payload_2 = 1'b1;
  always @(posedge ccin_clk) begin
    if(_zz_1) begin
      ram[_zz_ram_port] <= io_push_payload;
    end
  end

  always @(posedge ccout_clk) begin
    if(_zz_io_pop_payload_2) begin
      _zz_ram_port1 <= ram[_zz_io_pop_payload_1];
    end
  end

  BufferCC_7 popToPushGray_buffercc (
    .io_dataIn  (popToPushGray[6:0]                    ), //i
    .io_dataOut (popToPushGray_buffercc_io_dataOut[6:0]), //o
    .ccin_clk   (ccin_clk                              ), //i
    .reset      (reset                                 )  //i
  );
  BufferCC_6 bufferCC_8 (
    .io_dataIn  (1'b0                 ), //i
    .io_dataOut (bufferCC_8_io_dataOut), //o
    .ccout_clk  (ccout_clk            ), //i
    .reset      (reset                )  //i
  );
  BufferCC_5 pushToPopGray_buffercc (
    .io_dataIn                                                (pushToPopGray[6:0]                                      ), //i
    .io_dataOut                                               (pushToPopGray_buffercc_io_dataOut[6:0]                  ), //o
    .ccout_clk                                                (ccout_clk                                               ), //i
    .srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized (srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized)  //i
  );
  always @(*) begin
    _zz_1 = 1'b0; // @[when.scala 47:16]
    if(io_push_fire_1) begin
      _zz_1 = 1'b1; // @[when.scala 52:10]
    end
  end

  assign pushCC_pushPtrPlus = (pushCC_pushPtr + 7'h01); // @[BaseType.scala 299:24]
  assign io_push_fire = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign pushCC_popPtrGray = popToPushGray_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign pushCC_full = ((pushCC_pushPtrGray[6 : 5] == (~ pushCC_popPtrGray[6 : 5])) && (pushCC_pushPtrGray[4 : 0] == pushCC_popPtrGray[4 : 0])); // @[BaseType.scala 305:24]
  assign io_push_ready = (! pushCC_full); // @[Stream.scala 1334:19]
  assign io_push_fire_1 = (io_push_valid && io_push_ready); // @[BaseType.scala 305:24]
  assign _zz_io_pushOccupancy = (pushCC_popPtrGray[1] ^ _zz_io_pushOccupancy_1); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_1 = (pushCC_popPtrGray[2] ^ _zz_io_pushOccupancy_2); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_2 = (pushCC_popPtrGray[3] ^ _zz_io_pushOccupancy_3); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_3 = (pushCC_popPtrGray[4] ^ _zz_io_pushOccupancy_4); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_4 = (pushCC_popPtrGray[5] ^ _zz_io_pushOccupancy_5); // @[Utils.scala 379:14]
  assign _zz_io_pushOccupancy_5 = pushCC_popPtrGray[6]; // @[Utils.scala 381:14]
  assign io_pushOccupancy = (pushCC_pushPtr - {_zz_io_pushOccupancy_5,{_zz_io_pushOccupancy_4,{_zz_io_pushOccupancy_3,{_zz_io_pushOccupancy_2,{_zz_io_pushOccupancy_1,{_zz_io_pushOccupancy,(pushCC_popPtrGray[0] ^ _zz_io_pushOccupancy)}}}}}}); // @[Stream.scala 1341:22]
  assign srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized = bufferCC_8_io_dataOut; // @[CrossClock.scala 13:9]
  assign popCC_popPtrPlus = (popCC_popPtr + 7'h01); // @[BaseType.scala 299:24]
  assign io_pop_fire = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign popCC_pushPtrGray = pushToPopGray_buffercc_io_dataOut; // @[CrossClock.scala 13:9]
  assign popCC_empty = (popCC_popPtrGray == popCC_pushPtrGray); // @[BaseType.scala 305:24]
  assign io_pop_valid = (! popCC_empty); // @[Stream.scala 1352:20]
  assign io_pop_fire_1 = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign _zz_io_pop_payload = (io_pop_fire_1 ? popCC_popPtrPlus : popCC_popPtr); // @[Data.scala 450:19]
  assign io_pop_payload = _zz_ram_port1; // @[Stream.scala 1353:20]
  assign io_pop_fire_2 = (io_pop_valid && io_pop_ready); // @[BaseType.scala 305:24]
  assign _zz_io_popOccupancy = (popCC_pushPtrGray[1] ^ _zz_io_popOccupancy_1); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_1 = (popCC_pushPtrGray[2] ^ _zz_io_popOccupancy_2); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_2 = (popCC_pushPtrGray[3] ^ _zz_io_popOccupancy_3); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_3 = (popCC_pushPtrGray[4] ^ _zz_io_popOccupancy_4); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_4 = (popCC_pushPtrGray[5] ^ _zz_io_popOccupancy_5); // @[Utils.scala 379:14]
  assign _zz_io_popOccupancy_5 = popCC_pushPtrGray[6]; // @[Utils.scala 381:14]
  assign io_popOccupancy = ({_zz_io_popOccupancy_5,{_zz_io_popOccupancy_4,{_zz_io_popOccupancy_3,{_zz_io_popOccupancy_2,{_zz_io_popOccupancy_1,{_zz_io_popOccupancy,(popCC_pushPtrGray[0] ^ _zz_io_popOccupancy)}}}}}} - popCC_popPtr); // @[Stream.scala 1359:21]
  assign pushToPopGray = pushCC_pushPtrGray; // @[Stream.scala 1362:17]
  assign popToPushGray = popCC_popPtrGray; // @[Stream.scala 1363:17]
  assign srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized_1 = srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized; // @[Data.scala 235:16]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      pushCC_pushPtr <= 7'h0; // @[Data.scala 400:33]
      pushCC_pushPtrGray <= 7'h0; // @[Data.scala 400:33]
    end else begin
      if(io_push_fire) begin
        pushCC_pushPtrGray <= (_zz_pushCC_pushPtrGray ^ pushCC_pushPtrPlus); // @[Stream.scala 1330:34]
      end
      if(io_push_fire_1) begin
        pushCC_pushPtr <= pushCC_pushPtrPlus; // @[Stream.scala 1338:15]
      end
    end
  end

  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
    if(srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
      popCC_popPtr <= 7'h0; // @[Data.scala 400:33]
      popCC_popPtrGray <= 7'h0; // @[Data.scala 400:33]
    end else begin
      if(io_pop_fire) begin
        popCC_popPtrGray <= (_zz_popCC_popPtrGray ^ popCC_popPtrPlus); // @[Stream.scala 1348:34]
      end
      if(io_pop_fire_2) begin
        popCC_popPtr <= popCC_popPtrPlus; // @[Stream.scala 1356:14]
      end
    end
  end


endmodule

module BufferCC (
  input               io_dataIn,
  output              io_dataOut,
  input               ccout_clk,
  input               srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized
);

  (* async_reg = "true" *) reg                 buffers_0;
  (* async_reg = "true" *) reg                 buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
    if(srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
      buffers_0 <= 1'b0; // @[Data.scala 400:33]
      buffers_1 <= 1'b0; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule

module BufferCC_1 (
  input      [6:0]    io_dataIn,
  output     [6:0]    io_dataOut,
  input               ccout_clk,
  input               srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized
);

  (* async_reg = "true" *) reg        [6:0]    buffers_0;
  (* async_reg = "true" *) reg        [6:0]    buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
    if(srio_area_streamfifo_cc2_area_fifo_cc2_reset_syncronized) begin
      buffers_0 <= 7'h0; // @[Data.scala 400:33]
      buffers_1 <= 7'h0; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule

//BufferCC_6 replaced by BufferCC_6

//BufferCC_7 replaced by BufferCC_7

module BufferCC_4 (
  input               io_dataIn,
  output              io_dataOut,
  input               ccout_clk,
  input               srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized
);

  (* async_reg = "true" *) reg                 buffers_0;
  (* async_reg = "true" *) reg                 buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
    if(srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
      buffers_0 <= 1'b0; // @[Data.scala 400:33]
      buffers_1 <= 1'b0; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule

module BufferCC_5 (
  input      [6:0]    io_dataIn,
  output     [6:0]    io_dataOut,
  input               ccout_clk,
  input               srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized
);

  (* async_reg = "true" *) reg        [6:0]    buffers_0;
  (* async_reg = "true" *) reg        [6:0]    buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccout_clk or posedge srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
    if(srio_area_streamfifo_cc1_area_fifo_cc1_reset_syncronized) begin
      buffers_0 <= 7'h0; // @[Data.scala 400:33]
      buffers_1 <= 7'h0; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule

module BufferCC_6 (
  input               io_dataIn,
  output              io_dataOut,
  input               ccout_clk,
  input               reset
);

  (* async_reg = "true" *) reg                 buffers_0;
  (* async_reg = "true" *) reg                 buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccout_clk or posedge reset) begin
    if(reset) begin
      buffers_0 <= 1'b1; // @[Data.scala 400:33]
      buffers_1 <= 1'b1; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule

module BufferCC_7 (
  input      [6:0]    io_dataIn,
  output     [6:0]    io_dataOut,
  input               ccin_clk,
  input               reset
);

  (* async_reg = "true" *) reg        [6:0]    buffers_0;
  (* async_reg = "true" *) reg        [6:0]    buffers_1;

  assign io_dataOut = buffers_1; // @[CrossClock.scala 38:14]
  always @(posedge ccin_clk or posedge reset) begin
    if(reset) begin
      buffers_0 <= 7'h0; // @[Data.scala 400:33]
      buffers_1 <= 7'h0; // @[Data.scala 400:33]
    end else begin
      buffers_0 <= io_dataIn; // @[CrossClock.scala 31:14]
      buffers_1 <= buffers_0; // @[CrossClock.scala 34:16]
    end
  end


endmodule
