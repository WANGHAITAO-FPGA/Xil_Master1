// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : AxiLite_Bissc
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module AxiLite_Bissc (
  input               s_axi_awvalid,
  output              s_axi_awready,
  input      [15:0]   s_axi_awaddr,
  input      [2:0]    s_axi_awprot,
  input               s_axi_wvalid,
  output              s_axi_wready,
  input      [31:0]   s_axi_wdata,
  input      [3:0]    s_axi_wstrb,
  output              s_axi_bvalid,
  input               s_axi_bready,
  output     [1:0]    s_axi_bresp,
  input               s_axi_arvalid,
  output reg          s_axi_arready,
  input      [15:0]   s_axi_araddr,
  input      [2:0]    s_axi_arprot,
  output              s_axi_rvalid,
  input               s_axi_rready,
  output     [31:0]   s_axi_rdata,
  output     [1:0]    s_axi_rresp,
  output              clk_0,
  input               data_0,
  input               reset,
  input               clk
);

  wire                bissc_ctrl_1_bissc_clk_0;
  wire       [31:0]   bissc_ctrl_1_postion_0;
  wire                bus_ctrl_readErrorFlag;
  wire                bus_ctrl_writeErrorFlag;
  wire                bus_ctrl_readHaltRequest;
  wire                bus_ctrl_writeHaltRequest;
  wire                bus_ctrl_writeJoinEvent_valid;
  wire                bus_ctrl_writeJoinEvent_ready;
  wire                bus_ctrl_writeJoinEvent_fire;
  reg        [1:0]    bus_ctrl_writeRsp_resp;
  wire                bus_ctrl_writeJoinEvent_translated_valid;
  wire                bus_ctrl_writeJoinEvent_translated_ready;
  wire       [1:0]    bus_ctrl_writeJoinEvent_translated_payload_resp;
  wire                _zz_bus_ctrl_writeJoinEvent_translated_ready;
  reg                 _zz_bus_ctrl_writeJoinEvent_translated_ready_1;
  wire                _zz_s_axi_bvalid;
  reg                 _zz_s_axi_bvalid_1;
  reg        [1:0]    _zz_s_axi_bresp;
  wire                when_Stream_l368;
  wire                bus_ctrl_readDataStage_valid;
  wire                bus_ctrl_readDataStage_ready;
  wire       [15:0]   bus_ctrl_readDataStage_payload_addr;
  wire       [2:0]    bus_ctrl_readDataStage_payload_prot;
  reg                 s_axi_ar_rValid;
  reg        [15:0]   s_axi_ar_rData_addr;
  reg        [2:0]    s_axi_ar_rData_prot;
  wire                when_Stream_l368_1;
  reg        [31:0]   bus_ctrl_readRsp_data;
  reg        [1:0]    bus_ctrl_readRsp_resp;
  wire                _zz_s_axi_rvalid;
  wire       [15:0]   bus_ctrl_readAddressMasked;
  wire       [15:0]   bus_ctrl_writeAddressMasked;
  wire                bus_ctrl_writeOccur;
  wire                bus_ctrl_readOccur;
  reg        [31:0]   bridge_postion_temp_0;
  wire                when_BISSC_l49;

  BISSC_Ctrl bissc_ctrl_1 (
    .bissc_clk_0  (bissc_ctrl_1_bissc_clk_0    ), //o
    .bissc_data_0 (data_0                      ), //i
    .postion_0    (bissc_ctrl_1_postion_0[31:0]), //o
    .busy         (1'b0                        ), //i
    .reset        (reset                       ), //i
    .clk          (clk                         )  //i
  );
  assign bus_ctrl_readErrorFlag = 1'b0; // @[BusSlaveFactory.scala 105:29]
  assign bus_ctrl_writeErrorFlag = 1'b0; // @[BusSlaveFactory.scala 106:30]
  assign bus_ctrl_readHaltRequest = 1'b0; // @[AxiLite4SlaveFactory.scala 13:25]
  assign bus_ctrl_writeHaltRequest = 1'b0; // @[AxiLite4SlaveFactory.scala 14:26]
  assign bus_ctrl_writeJoinEvent_fire = (bus_ctrl_writeJoinEvent_valid && bus_ctrl_writeJoinEvent_ready); // @[BaseType.scala 305:24]
  assign bus_ctrl_writeJoinEvent_valid = (s_axi_awvalid && s_axi_wvalid); // @[Stream.scala 1043:17]
  assign s_axi_awready = bus_ctrl_writeJoinEvent_fire; // @[Stream.scala 1044:29]
  assign s_axi_wready = bus_ctrl_writeJoinEvent_fire; // @[Stream.scala 1044:29]
  assign bus_ctrl_writeJoinEvent_translated_valid = bus_ctrl_writeJoinEvent_valid; // @[Stream.scala 303:16]
  assign bus_ctrl_writeJoinEvent_ready = bus_ctrl_writeJoinEvent_translated_ready; // @[Stream.scala 304:16]
  assign bus_ctrl_writeJoinEvent_translated_payload_resp = bus_ctrl_writeRsp_resp; // @[Stream.scala 324:18]
  assign _zz_bus_ctrl_writeJoinEvent_translated_ready = (! bus_ctrl_writeHaltRequest); // @[BaseType.scala 299:24]
  assign bus_ctrl_writeJoinEvent_translated_ready = (_zz_bus_ctrl_writeJoinEvent_translated_ready_1 && _zz_bus_ctrl_writeJoinEvent_translated_ready); // @[Stream.scala 427:16]
  always @(*) begin
    _zz_bus_ctrl_writeJoinEvent_translated_ready_1 = s_axi_bready; // @[Stream.scala 367:16]
    if(when_Stream_l368) begin
      _zz_bus_ctrl_writeJoinEvent_translated_ready_1 = 1'b1; // @[Stream.scala 368:35]
    end
  end

  assign when_Stream_l368 = (! _zz_s_axi_bvalid); // @[BaseType.scala 299:24]
  assign _zz_s_axi_bvalid = _zz_s_axi_bvalid_1; // @[Stream.scala 370:19]
  assign s_axi_bvalid = _zz_s_axi_bvalid; // @[Stream.scala 294:16]
  assign s_axi_bresp = _zz_s_axi_bresp; // @[Stream.scala 296:18]
  always @(*) begin
    s_axi_arready = bus_ctrl_readDataStage_ready; // @[Stream.scala 367:16]
    if(when_Stream_l368_1) begin
      s_axi_arready = 1'b1; // @[Stream.scala 368:35]
    end
  end

  assign when_Stream_l368_1 = (! bus_ctrl_readDataStage_valid); // @[BaseType.scala 299:24]
  assign bus_ctrl_readDataStage_valid = s_axi_ar_rValid; // @[Stream.scala 370:19]
  assign bus_ctrl_readDataStage_payload_addr = s_axi_ar_rData_addr; // @[Stream.scala 371:21]
  assign bus_ctrl_readDataStage_payload_prot = s_axi_ar_rData_prot; // @[Stream.scala 371:21]
  assign _zz_s_axi_rvalid = (! bus_ctrl_readHaltRequest); // @[BaseType.scala 299:24]
  assign bus_ctrl_readDataStage_ready = (s_axi_rready && _zz_s_axi_rvalid); // @[Stream.scala 427:16]
  assign s_axi_rvalid = (bus_ctrl_readDataStage_valid && _zz_s_axi_rvalid); // @[Stream.scala 294:16]
  assign s_axi_rdata = bus_ctrl_readRsp_data; // @[Stream.scala 296:18]
  assign s_axi_rresp = bus_ctrl_readRsp_resp; // @[Stream.scala 296:18]
  always @(*) begin
    if(bus_ctrl_writeErrorFlag) begin
      bus_ctrl_writeRsp_resp = 2'b10; // @[AxiLite4.scala 140:33]
    end else begin
      bus_ctrl_writeRsp_resp = 2'b00; // @[AxiLite4.scala 138:33]
    end
  end

  always @(*) begin
    if(bus_ctrl_readErrorFlag) begin
      bus_ctrl_readRsp_resp = 2'b10; // @[AxiLite4.scala 169:33]
    end else begin
      bus_ctrl_readRsp_resp = 2'b00; // @[AxiLite4.scala 167:33]
    end
  end

  always @(*) begin
    bus_ctrl_readRsp_data = 32'h0; // @[AxiLite4SlaveFactory.scala 36:16]
    case(bus_ctrl_readAddressMasked)
      16'h0 : begin
        bus_ctrl_readRsp_data[31 : 0] = bridge_postion_temp_0; // @[BusSlaveFactory.scala 942:69]
      end
      default : begin
      end
    endcase
  end

  assign bus_ctrl_readAddressMasked = (bus_ctrl_readDataStage_payload_addr & (~ 16'h0003)); // @[BaseType.scala 299:24]
  assign bus_ctrl_writeAddressMasked = (s_axi_awaddr & (~ 16'h0003)); // @[BaseType.scala 299:24]
  assign bus_ctrl_writeOccur = (bus_ctrl_writeJoinEvent_valid && bus_ctrl_writeJoinEvent_ready); // @[BaseType.scala 305:24]
  assign bus_ctrl_readOccur = (s_axi_rvalid && s_axi_rready); // @[BaseType.scala 305:24]
  assign clk_0 = bissc_ctrl_1_bissc_clk_0; // @[AxiLite_Bissc.scala 20:17]
  assign when_BISSC_l49 = (! 1'b0); // @[BaseType.scala 299:24]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      _zz_s_axi_bvalid_1 <= 1'b0; // @[Data.scala 400:33]
      s_axi_ar_rValid <= 1'b0; // @[Data.scala 400:33]
    end else begin
      if(_zz_bus_ctrl_writeJoinEvent_translated_ready_1) begin
        _zz_s_axi_bvalid_1 <= (bus_ctrl_writeJoinEvent_translated_valid && _zz_bus_ctrl_writeJoinEvent_translated_ready); // @[Stream.scala 361:29]
      end
      if(s_axi_arready) begin
        s_axi_ar_rValid <= s_axi_arvalid; // @[Stream.scala 361:29]
      end
    end
  end

  always @(posedge clk) begin
    if(_zz_bus_ctrl_writeJoinEvent_translated_ready_1) begin
      _zz_s_axi_bresp <= bus_ctrl_writeJoinEvent_translated_payload_resp; // @[Stream.scala 362:28]
    end
    if(s_axi_arready) begin
      s_axi_ar_rData_addr <= s_axi_araddr; // @[Stream.scala 362:28]
      s_axi_ar_rData_prot <= s_axi_arprot; // @[Stream.scala 362:28]
    end
    if(when_BISSC_l49) begin
      bridge_postion_temp_0 <= bissc_ctrl_1_postion_0; // @[BISSC.scala 51:27]
    end
  end


endmodule

module BISSC_Ctrl (
  output              bissc_clk_0,
  input               bissc_data_0,
  output     [31:0]   postion_0,
  input               busy,
  input               reset,
  input               clk
);

  wire                bissc_0_bissc_clk;
  wire       [31:0]   bissc_0_postion;

  BISSC bissc_0 (
    .bissc_clk  (bissc_0_bissc_clk    ), //o
    .bissc_data (bissc_data_0         ), //i
    .postion    (bissc_0_postion[31:0]), //o
    .reset      (reset                ), //i
    .clk        (clk                  )  //i
  );
  assign bissc_clk_0 = bissc_0_bissc_clk; // @[BISSC.scala 72:23]
  assign postion_0 = bissc_0_postion; // @[BISSC.scala 73:19]

endmodule

module BISSC (
  output              bissc_clk,
  input               bissc_data,
  output     [31:0]   postion,
  input               reset,
  input               clk
);

  wire                bissc_1_enc_clk;
  wire       [40:0]   bissc_1_enc_position_all;
  wire       [31:0]   bissc_1_enc_position_out;
  wire                bissc_1_erro_flag;
  wire                bissc_1_warn_flag;
  wire                bissc_1_crc_flag;

  BISS_Position bissc_1 (
    .clk              (clk                           ), //i
    .reset            (reset                         ), //i
    .enc_data         (bissc_data                    ), //i
    .sample_en        (1'b1                          ), //i
    .enc_clk          (bissc_1_enc_clk               ), //o
    .enc_position_all (bissc_1_enc_position_all[40:0]), //o
    .enc_position_out (bissc_1_enc_position_out[31:0]), //o
    .erro_flag        (bissc_1_erro_flag             ), //o
    .warn_flag        (bissc_1_warn_flag             ), //o
    .crc_flag         (bissc_1_crc_flag              )  //o
  );
  assign bissc_clk = bissc_1_enc_clk; // @[BISSC.scala 35:16]
  assign postion = bissc_1_enc_position_out; // @[BISSC.scala 37:14]

endmodule
