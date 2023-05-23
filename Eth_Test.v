// Generator : SpinalHDL v1.7.3    git head : aeaeece704fe43c766e0d36a93f2ecbb8a9f2003
// Component : Eth_Test

`timescale 1ns/1ps

module Eth_Test (
  input               sysclk,
  input               sfp_rxn,
  input               sfp_rxp,
  output              sfp_txn,
  output              sfp_txp,
  input               gtrefclk_n,
  input               gtrefclk_p
);

  wire                eth_area_mmcm_clk_200M;
  wire                eth_area_mmcm_locked;
  wire                eth_area_eth_pcs_gmii_rx_dv;
  wire                eth_area_eth_pcs_gmii_rx_er;
  wire       [7:0]    eth_area_eth_pcs_gmii_rxd;
  wire       [15:0]   eth_area_eth_pcs_status_vector;
  wire                eth_area_eth_pcs_txn;
  wire                eth_area_eth_pcs_txp;
  wire                eth_area_eth_pcs_user_clk;
  reg                 eth_area_resetCtrl_resetUnbuffered;
  reg        [7:0]    eth_area_resetCtrl_ResetCounter;
  wire       [7:0]    _zz_when_Eth_Test_l50;
  wire                when_Eth_Test_l50;
  reg                 eth_area_resetCtrl_reset;

  Eth_MMCME2 eth_area_mmcm (
    .sysclk   (sysclk                ), //i
    .reset    (1'b0                  ), //i
    .clk_200M (eth_area_mmcm_clk_200M), //o
    .locked   (eth_area_mmcm_locked  )  //o
  );
  Ethernet_PCS eth_area_eth_pcs (
    .gmii_rx_dv             (eth_area_eth_pcs_gmii_rx_dv         ), //o
    .gmii_rx_er             (eth_area_eth_pcs_gmii_rx_er         ), //o
    .gmii_rxd               (eth_area_eth_pcs_gmii_rxd[7:0]      ), //o
    .gmii_tx_en             (1'b0                                ), //i
    .gmii_tx_er             (1'b0                                ), //i
    .gmii_txd               (8'h0                                ), //i
    .gtrefclk_n             (gtrefclk_n                          ), //i
    .gtrefclk_p             (gtrefclk_p                          ), //i
    .independent_clock_bufg (eth_area_mmcm_clk_200M              ), //i
    .reset                  (eth_area_resetCtrl_reset            ), //i
    .configuration_vector   (5'h10                               ), //i
    .an_adv_config_vector   (16'h8821                            ), //i
    .an_restart_config      (1'b0                                ), //i
    .signal_detect          (1'b1                                ), //i
    .status_vector          (eth_area_eth_pcs_status_vector[15:0]), //o
    .rxn                    (sfp_rxn                             ), //i
    .rxp                    (sfp_rxp                             ), //i
    .txn                    (eth_area_eth_pcs_txn                ), //o
    .txp                    (eth_area_eth_pcs_txp                ), //o
    .user_clk               (eth_area_eth_pcs_user_clk           )  //o
  );
  always @(*) begin
    eth_area_resetCtrl_resetUnbuffered = 1'b0;
    if(when_Eth_Test_l50) begin
      eth_area_resetCtrl_resetUnbuffered = 1'b1;
    end
  end

  assign _zz_when_Eth_Test_l50[7 : 0] = 8'hff;
  assign when_Eth_Test_l50 = (eth_area_resetCtrl_ResetCounter != _zz_when_Eth_Test_l50);
  assign sfp_txn = eth_area_eth_pcs_txn;
  assign sfp_txp = eth_area_eth_pcs_txp;
  always @(posedge eth_area_mmcm_clk_200M or negedge eth_area_mmcm_locked) begin
    if(!eth_area_mmcm_locked) begin
      eth_area_resetCtrl_ResetCounter <= 8'h0;
    end else begin
      if(when_Eth_Test_l50) begin
        eth_area_resetCtrl_ResetCounter <= (eth_area_resetCtrl_ResetCounter + 8'h01);
      end
    end
  end

  always @(posedge eth_area_mmcm_clk_200M) begin
    eth_area_resetCtrl_reset <= eth_area_resetCtrl_resetUnbuffered;
  end


endmodule

module Ethernet_PCS (
  output              gmii_rx_dv,
  output              gmii_rx_er,
  output     [7:0]    gmii_rxd,
  input               gmii_tx_en,
  input               gmii_tx_er,
  input      [7:0]    gmii_txd,
  input               gtrefclk_n,
  input               gtrefclk_p,
  input               independent_clock_bufg,
  input               reset,
  input      [4:0]    configuration_vector,
  input      [15:0]   an_adv_config_vector,
  input               an_restart_config,
  input               signal_detect,
  output     [15:0]   status_vector,
  input               rxn,
  input               rxp,
  output              txn,
  output              txp,
  output              user_clk
);

  wire                ethernet_gmii_rx_dv;
  wire                ethernet_gmii_rx_er;
  wire       [7:0]    ethernet_gmii_rxd;
  wire       [15:0]   ethernet_status_vector;
  wire                ethernet_txn;
  wire                ethernet_txp;
  wire                ethernet_gtrefclk_out;
  wire                ethernet_gtrefclk_bufg_out;
  wire                ethernet_userclk_out;
  wire                ethernet_userclk2_out;
  wire                ethernet_rxuserclk_out;
  wire                ethernet_rxuserclk2_out;
  wire                ethernet_resetdone;
  wire                ethernet_pma_reset_out;
  wire                ethernet_mmcm_locked_out;
  wire                ethernet_gmii_isolate;
  wire                ethernet_an_interrupt;
  wire                ethernet_gt0_pll0outclk_out;
  wire                ethernet_gt0_pll0outrefclk_out;
  wire                ethernet_gt0_pll1outclk_out;
  wire                ethernet_gt0_pll1outrefclk_out;
  wire                ethernet_gt0_pll0lock_out;
  wire                ethernet_gt0_pll0refclklost_out;

  gig_ethernet_pcs_pma_0 ethernet (
    .gmii_rx_dv             (ethernet_gmii_rx_dv            ), //o
    .gmii_rx_er             (ethernet_gmii_rx_er            ), //o
    .gmii_rxd               (ethernet_gmii_rxd[7:0]         ), //o
    .gmii_tx_en             (gmii_tx_en                     ), //i
    .gmii_tx_er             (gmii_tx_er                     ), //i
    .gmii_txd               (gmii_txd[7:0]                  ), //i
    .gtrefclk_n             (gtrefclk_n                     ), //i
    .gtrefclk_p             (gtrefclk_p                     ), //i
    .independent_clock_bufg (independent_clock_bufg         ), //i
    .reset                  (reset                          ), //i
    .configuration_vector   (configuration_vector[4:0]      ), //i
    .an_adv_config_vector   (an_adv_config_vector[15:0]     ), //i
    .an_restart_config      (an_restart_config              ), //i
    .signal_detect          (signal_detect                  ), //i
    .status_vector          (ethernet_status_vector[15:0]   ), //o
    .rxn                    (rxn                            ), //i
    .rxp                    (rxp                            ), //i
    .txn                    (ethernet_txn                   ), //o
    .txp                    (ethernet_txp                   ), //o
    .gtrefclk_out           (ethernet_gtrefclk_out          ), //o
    .gtrefclk_bufg_out      (ethernet_gtrefclk_bufg_out     ), //o
    .userclk_out            (ethernet_userclk_out           ), //o
    .userclk2_out           (ethernet_userclk2_out          ), //o
    .rxuserclk_out          (ethernet_rxuserclk_out         ), //o
    .rxuserclk2_out         (ethernet_rxuserclk2_out        ), //o
    .resetdone              (ethernet_resetdone             ), //o
    .pma_reset_out          (ethernet_pma_reset_out         ), //o
    .mmcm_locked_out        (ethernet_mmcm_locked_out       ), //o
    .gmii_isolate           (ethernet_gmii_isolate          ), //o
    .an_interrupt           (ethernet_an_interrupt          ), //o
    .gt0_pll0outclk_out     (ethernet_gt0_pll0outclk_out    ), //o
    .gt0_pll0outrefclk_out  (ethernet_gt0_pll0outrefclk_out ), //o
    .gt0_pll1outclk_out     (ethernet_gt0_pll1outclk_out    ), //o
    .gt0_pll1outrefclk_out  (ethernet_gt0_pll1outrefclk_out ), //o
    .gt0_pll0lock_out       (ethernet_gt0_pll0lock_out      ), //o
    .gt0_pll0refclklost_out (ethernet_gt0_pll0refclklost_out)  //o
  );
  assign gmii_rx_dv = ethernet_gmii_rx_dv;
  assign gmii_rx_er = ethernet_gmii_rx_er;
  assign gmii_rxd = ethernet_gmii_rxd;
  assign status_vector = ethernet_status_vector;
  assign txn = ethernet_txn;
  assign txp = ethernet_txp;
  assign user_clk = ethernet_userclk_out;

endmodule

module Eth_MMCME2 (
  input               sysclk,
  input               reset,
  output              clk_200M,
  output              locked
);

  wire                sysclk_BUFG_O;
  wire                MMCME2_BASE_1_CLKOUT0;
  wire                MMCME2_BASE_1_CLKOUT0B;
  wire                MMCME2_BASE_1_CLKOUT1;
  wire                MMCME2_BASE_1_CLKOUT1B;
  wire                MMCME2_BASE_1_CLKOUT2;
  wire                MMCME2_BASE_1_CLKOUT2B;
  wire                MMCME2_BASE_1_CLKOUT3;
  wire                MMCME2_BASE_1_CLKOUT3B;
  wire                MMCME2_BASE_1_CLKOUT4;
  wire                MMCME2_BASE_1_CLKOUT5;
  wire                MMCME2_BASE_1_CLKOUT6;
  wire                MMCME2_BASE_1_CLKFBOUT;
  wire                MMCME2_BASE_1_CLKFBOUTB;
  wire                MMCME2_BASE_1_LOCKED;
  wire                MMCME2_BASE_1_CLKOUT0_IBUF_O;

  BUFG sysclk_BUFG (
    .I (sysclk       ), //i
    .O (sysclk_BUFG_O)  //o
  );
  MMCME2_BASE #(
    .BANDWIDTH("OPTIMIZED"),
    .CLKFBOUT_MULT_F(40.0),
    .CLKFBOUT_PHASE(0.0),
    .CLKIN1_PERIOD(40.0),
    .CLKOUT1_DIVIDE(1),
    .CLKOUT2_DIVIDE(1),
    .CLKOUT3_DIVIDE(1),
    .CLKOUT4_DIVIDE(1),
    .CLKOUT5_DIVIDE(1),
    .CLKOUT6_DIVIDE(1),
    .CLKOUT0_DIVIDE_F(5.0),
    .CLKOUT0_DUTY_CYCLE(0.5),
    .CLKOUT1_DUTY_CYCLE(0.5),
    .CLKOUT2_DUTY_CYCLE(0.5),
    .CLKOUT3_DUTY_CYCLE(0.5),
    .CLKOUT4_DUTY_CYCLE(0.5),
    .CLKOUT5_DUTY_CYCLE(0.5),
    .CLKOUT6_DUTY_CYCLE(0.5),
    .CLKOUT0_PHASE(0.0),
    .CLKOUT1_PHASE(0.0),
    .CLKOUT2_PHASE(0.0),
    .CLKOUT3_PHASE(0.0),
    .CLKOUT4_PHASE(0.0),
    .CLKOUT5_PHASE(0.0),
    .CLKOUT6_PHASE(0.0),
    .CLKOUT4_CASCADE("FALSE"),
    .DIVCLK_DIVIDE(1),
    .REF_JITTER1(0.0),
    .STARTUP_WAIT("FALSE")
  ) MMCME2_BASE_1 (
    .CLKOUT0   (MMCME2_BASE_1_CLKOUT0  ), //o
    .CLKOUT0B  (MMCME2_BASE_1_CLKOUT0B ), //o
    .CLKOUT1   (MMCME2_BASE_1_CLKOUT1  ), //o
    .CLKOUT1B  (MMCME2_BASE_1_CLKOUT1B ), //o
    .CLKOUT2   (MMCME2_BASE_1_CLKOUT2  ), //o
    .CLKOUT2B  (MMCME2_BASE_1_CLKOUT2B ), //o
    .CLKOUT3   (MMCME2_BASE_1_CLKOUT3  ), //o
    .CLKOUT3B  (MMCME2_BASE_1_CLKOUT3B ), //o
    .CLKOUT4   (MMCME2_BASE_1_CLKOUT4  ), //o
    .CLKOUT5   (MMCME2_BASE_1_CLKOUT5  ), //o
    .CLKOUT6   (MMCME2_BASE_1_CLKOUT6  ), //o
    .CLKFBOUT  (MMCME2_BASE_1_CLKFBOUT ), //o
    .CLKFBOUTB (MMCME2_BASE_1_CLKFBOUTB), //o
    .LOCKED    (MMCME2_BASE_1_LOCKED   ), //o
    .CLKIN1    (sysclk_BUFG_O          ), //i
    .PWRDWN    (1'b0                   ), //i
    .RST       (reset                  ), //i
    .CLKFBIN   (MMCME2_BASE_1_CLKFBOUT )  //i
  );
  BUFG MMCME2_BASE_1_CLKOUT0_IBUF (
    .I (MMCME2_BASE_1_CLKOUT0       ), //i
    .O (MMCME2_BASE_1_CLKOUT0_IBUF_O)  //o
  );
  assign clk_200M = MMCME2_BASE_1_CLKOUT0_IBUF_O;
  assign locked = MMCME2_BASE_1_LOCKED;

endmodule
