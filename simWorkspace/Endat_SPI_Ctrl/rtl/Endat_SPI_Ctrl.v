// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Endat_SPI_Ctrl

`timescale 1ns/1ps

module Endat_SPI_Ctrl (
  output     [0:0]    spi_ss,
  output              spi_sclk,
  output              spi_mosi,
  input               spi_miso,
  input               cmddata_valid,
  input      [15:0]   cmddata_payload_Identity_Addr,
  input      [15:0]   cmddata_payload_CmdData_0,
  input      [15:0]   cmddata_payload_CmdData_1,
  input      [15:0]   cmddata_payload_CmdData_2,
  input      [15:0]   cmddata_payload_CmdData_3,
  input      [5:0]    cmddata_payload_Bytenumber,
  output              rspdata_valid,
  output     [15:0]   rspdata_payload_RspData_0,
  output     [15:0]   rspdata_payload_RspData_1,
  output     [15:0]   rspdata_payload_RspData_2,
  output     [15:0]   rspdata_payload_RspData_3,
  output     [15:0]   rspdata_payload_RspData_4,
  input               clk,
  input               reset
);
  localparam fsm_enumDef_BOOT = 3'd0;
  localparam fsm_enumDef_Init_Start = 3'd1;
  localparam fsm_enumDef_Send_Identity_Addr = 3'd2;
  localparam fsm_enumDef_Send_RegData = 3'd3;
  localparam fsm_enumDef_Wait_Rsp = 3'd4;
  localparam fsm_enumDef_Rd_Rsp = 3'd5;

  wire                spictrl_spi_sclk;
  wire                spictrl_spi_mosi;
  wire       [0:0]    spictrl_spi_ss;
  wire                spictrl_cmd_ready;
  wire                spictrl_rsp_valid;
  wire       [15:0]   spictrl_rsp_payload;
  wire       [6:0]    spictrl_occupancy;
  wire       [4:0]    _zz_fsm_Cycle;
  wire       [3:0]    _zz_when_Endat_SPI_Ctrl_l183;
  reg        [15:0]   _zz_fsm_spi_cmd_payload;
  wire       [1:0]    _zz_fsm_spi_cmd_payload_1;
  wire       [6:0]    _zz_when_Endat_SPI_Ctrl_l196;
  wire       [1:0]    _zz_when_Endat_SPI_Ctrl_l196_1;
  wire       [3:0]    _zz_when_Endat_SPI_Ctrl_l204;
  wire       [1:0]    _zz_when_Endat_SPI_Ctrl_l204_1;
  wire       [2:0]    _zz__zz_1;
  wire                fsm_wantExit;
  reg                 fsm_wantStart;
  wire                fsm_wantKill;
  reg        [15:0]   fsm_Identity_Addr;
  reg        [15:0]   fsm_CmdData_0;
  reg        [15:0]   fsm_CmdData_1;
  reg        [15:0]   fsm_CmdData_2;
  reg        [15:0]   fsm_CmdData_3;
  reg        [1:0]    fsm_Cycle;
  reg        [3:0]    fsm_counter;
  reg                 fsm_rdfifo_ready;
  reg                 fsm_spi_cmd_valid;
  reg        [15:0]   fsm_spi_cmd_payload;
  reg        [15:0]   fsm_rspData_0;
  reg        [15:0]   fsm_rspData_1;
  reg        [15:0]   fsm_rspData_2;
  reg        [15:0]   fsm_rspData_3;
  reg        [15:0]   fsm_rspData_4;
  reg        [2:0]    fsm_stateReg;
  reg        [2:0]    fsm_stateNext;
  wire                when_Endat_SPI_Ctrl_l183;
  wire                when_Endat_SPI_Ctrl_l196;
  wire                when_Endat_SPI_Ctrl_l204;
  wire       [7:0]    _zz_1;
  wire                when_Endat_SPI_Ctrl_l208;
  `ifndef SYNTHESIS
  reg [143:0] fsm_stateReg_string;
  reg [143:0] fsm_stateNext_string;
  `endif


  assign _zz_fsm_Cycle = (cmddata_payload_Bytenumber >>> 1);
  assign _zz_when_Endat_SPI_Ctrl_l183 = {2'd0, fsm_Cycle};
  assign _zz_fsm_spi_cmd_payload_1 = fsm_counter[1:0];
  assign _zz_when_Endat_SPI_Ctrl_l196_1 = (fsm_Cycle + 2'b01);
  assign _zz_when_Endat_SPI_Ctrl_l196 = {5'd0, _zz_when_Endat_SPI_Ctrl_l196_1};
  assign _zz_when_Endat_SPI_Ctrl_l204_1 = (fsm_Cycle + 2'b01);
  assign _zz_when_Endat_SPI_Ctrl_l204 = {2'd0, _zz_when_Endat_SPI_Ctrl_l204_1};
  assign _zz__zz_1 = fsm_counter[2:0];
  SPI_Ctrl spictrl (
    .spi_ss               (spictrl_spi_ss           ), //o
    .spi_sclk             (spictrl_spi_sclk         ), //o
    .spi_mosi             (spictrl_spi_mosi         ), //o
    .spi_miso             (spi_miso                 ), //i
    .config_kind_cpol     (1'b0                     ), //i
    .config_kind_cpha     (1'b0                     ), //i
    .config_sclkToogle    (8'h0a                    ), //i
    .config_ss_activeHigh (1'b0                     ), //i
    .config_ss_setup      (8'h64                    ), //i
    .config_ss_hold       (8'h64                    ), //i
    .config_ss_disable    (8'hc8                    ), //i
    .cmd_valid            (fsm_spi_cmd_valid        ), //i
    .cmd_ready            (spictrl_cmd_ready        ), //o
    .cmd_payload          (fsm_spi_cmd_payload[15:0]), //i
    .rsp_valid            (spictrl_rsp_valid        ), //o
    .rsp_ready            (fsm_rdfifo_ready         ), //i
    .rsp_payload          (spictrl_rsp_payload[15:0]), //o
    .occupancy            (spictrl_occupancy[6:0]   ), //o
    .clk                  (clk                      ), //i
    .reset                (reset                    )  //i
  );
  always @(*) begin
    case(_zz_fsm_spi_cmd_payload_1)
      2'b00 : _zz_fsm_spi_cmd_payload = fsm_CmdData_0;
      2'b01 : _zz_fsm_spi_cmd_payload = fsm_CmdData_1;
      2'b10 : _zz_fsm_spi_cmd_payload = fsm_CmdData_2;
      default : _zz_fsm_spi_cmd_payload = fsm_CmdData_3;
    endcase
  end

  `ifndef SYNTHESIS
  always @(*) begin
    case(fsm_stateReg)
      fsm_enumDef_BOOT : fsm_stateReg_string = "BOOT              ";
      fsm_enumDef_Init_Start : fsm_stateReg_string = "Init_Start        ";
      fsm_enumDef_Send_Identity_Addr : fsm_stateReg_string = "Send_Identity_Addr";
      fsm_enumDef_Send_RegData : fsm_stateReg_string = "Send_RegData      ";
      fsm_enumDef_Wait_Rsp : fsm_stateReg_string = "Wait_Rsp          ";
      fsm_enumDef_Rd_Rsp : fsm_stateReg_string = "Rd_Rsp            ";
      default : fsm_stateReg_string = "??????????????????";
    endcase
  end
  always @(*) begin
    case(fsm_stateNext)
      fsm_enumDef_BOOT : fsm_stateNext_string = "BOOT              ";
      fsm_enumDef_Init_Start : fsm_stateNext_string = "Init_Start        ";
      fsm_enumDef_Send_Identity_Addr : fsm_stateNext_string = "Send_Identity_Addr";
      fsm_enumDef_Send_RegData : fsm_stateNext_string = "Send_RegData      ";
      fsm_enumDef_Wait_Rsp : fsm_stateNext_string = "Wait_Rsp          ";
      fsm_enumDef_Rd_Rsp : fsm_stateNext_string = "Rd_Rsp            ";
      default : fsm_stateNext_string = "??????????????????";
    endcase
  end
  `endif

  assign spi_ss = spictrl_spi_ss; // @[Endat_SPI_Ctrl.scala 139:18]
  assign spi_sclk = spictrl_spi_sclk; // @[Endat_SPI_Ctrl.scala 139:18]
  assign spi_mosi = spictrl_spi_mosi; // @[Endat_SPI_Ctrl.scala 139:18]
  assign fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
      end
      fsm_enumDef_Send_Identity_Addr : begin
      end
      fsm_enumDef_Send_RegData : begin
      end
      fsm_enumDef_Wait_Rsp : begin
      end
      fsm_enumDef_Rd_Rsp : begin
      end
      default : begin
        fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign rspdata_valid = spictrl_rsp_valid; // @[Endat_SPI_Ctrl.scala 221:20]
  assign rspdata_payload_RspData_0 = fsm_rspData_0; // @[Endat_SPI_Ctrl.scala 222:30]
  assign rspdata_payload_RspData_1 = fsm_rspData_1; // @[Endat_SPI_Ctrl.scala 222:30]
  assign rspdata_payload_RspData_2 = fsm_rspData_2; // @[Endat_SPI_Ctrl.scala 222:30]
  assign rspdata_payload_RspData_3 = fsm_rspData_3; // @[Endat_SPI_Ctrl.scala 222:30]
  assign rspdata_payload_RspData_4 = fsm_rspData_4; // @[Endat_SPI_Ctrl.scala 222:30]
  always @(*) begin
    fsm_stateNext = fsm_stateReg; // @[StateMachine.scala 217:17]
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
        if(cmddata_valid) begin
          fsm_stateNext = fsm_enumDef_Send_Identity_Addr; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_Send_Identity_Addr : begin
        fsm_stateNext = fsm_enumDef_Send_RegData; // @[Enum.scala 148:67]
      end
      fsm_enumDef_Send_RegData : begin
        if(!when_Endat_SPI_Ctrl_l183) begin
          fsm_stateNext = fsm_enumDef_Wait_Rsp; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_Wait_Rsp : begin
        if(when_Endat_SPI_Ctrl_l196) begin
          fsm_stateNext = fsm_enumDef_Rd_Rsp; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_Rd_Rsp : begin
        if(!when_Endat_SPI_Ctrl_l208) begin
          fsm_stateNext = fsm_enumDef_Init_Start; // @[Enum.scala 148:67]
        end
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

  assign when_Endat_SPI_Ctrl_l183 = (fsm_counter < _zz_when_Endat_SPI_Ctrl_l183); // @[BaseType.scala 305:24]
  assign when_Endat_SPI_Ctrl_l196 = (_zz_when_Endat_SPI_Ctrl_l196 <= spictrl_occupancy); // @[BaseType.scala 305:24]
  assign when_Endat_SPI_Ctrl_l204 = (fsm_counter < _zz_when_Endat_SPI_Ctrl_l204); // @[BaseType.scala 305:24]
  assign _zz_1 = ({7'd0,1'b1} <<< _zz__zz_1); // @[BaseType.scala 299:24]
  assign when_Endat_SPI_Ctrl_l208 = (spictrl_occupancy != 7'h0); // @[BaseType.scala 305:24]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      fsm_Identity_Addr <= 16'h0; // @[Data.scala 400:33]
      fsm_counter <= 4'b0000; // @[Data.scala 400:33]
      fsm_spi_cmd_payload <= 16'h0; // @[Data.scala 400:33]
      fsm_stateReg <= fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      fsm_stateReg <= fsm_stateNext; // @[StateMachine.scala 212:14]
      case(fsm_stateReg)
        fsm_enumDef_Init_Start : begin
          if(cmddata_valid) begin
            fsm_Identity_Addr <= cmddata_payload_Identity_Addr; // @[Endat_SPI_Ctrl.scala 164:25]
            fsm_counter <= 4'b0000; // @[Endat_SPI_Ctrl.scala 167:19]
          end
        end
        fsm_enumDef_Send_Identity_Addr : begin
          fsm_spi_cmd_payload <= fsm_Identity_Addr; // @[Endat_SPI_Ctrl.scala 177:25]
        end
        fsm_enumDef_Send_RegData : begin
          if(when_Endat_SPI_Ctrl_l183) begin
            fsm_spi_cmd_payload <= _zz_fsm_spi_cmd_payload; // @[Endat_SPI_Ctrl.scala 185:27]
            fsm_counter <= (fsm_counter + 4'b0001); // @[Endat_SPI_Ctrl.scala 186:19]
          end else begin
            fsm_counter <= 4'b0000; // @[Endat_SPI_Ctrl.scala 189:19]
          end
        end
        fsm_enumDef_Wait_Rsp : begin
        end
        fsm_enumDef_Rd_Rsp : begin
          if(when_Endat_SPI_Ctrl_l204) begin
            fsm_counter <= (fsm_counter + 4'b0001); // @[Endat_SPI_Ctrl.scala 206:19]
          end
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge clk) begin
    fsm_rdfifo_ready <= 1'b0; // @[Endat_SPI_Ctrl.scala 154:18]
    fsm_spi_cmd_valid <= 1'b0; // @[Endat_SPI_Ctrl.scala 157:19]
    case(fsm_stateReg)
      fsm_enumDef_Init_Start : begin
        if(cmddata_valid) begin
          fsm_CmdData_0 <= cmddata_payload_CmdData_0; // @[Endat_SPI_Ctrl.scala 165:19]
          fsm_CmdData_1 <= cmddata_payload_CmdData_1; // @[Endat_SPI_Ctrl.scala 165:19]
          fsm_CmdData_2 <= cmddata_payload_CmdData_2; // @[Endat_SPI_Ctrl.scala 165:19]
          fsm_CmdData_3 <= cmddata_payload_CmdData_3; // @[Endat_SPI_Ctrl.scala 165:19]
          fsm_Cycle <= _zz_fsm_Cycle[1:0]; // @[Endat_SPI_Ctrl.scala 166:17]
        end else begin
          fsm_rdfifo_ready <= 1'b1; // @[Endat_SPI_Ctrl.scala 170:24]
        end
      end
      fsm_enumDef_Send_Identity_Addr : begin
        fsm_spi_cmd_valid <= 1'b1; // @[Endat_SPI_Ctrl.scala 176:23]
      end
      fsm_enumDef_Send_RegData : begin
        if(when_Endat_SPI_Ctrl_l183) begin
          fsm_spi_cmd_valid <= 1'b1; // @[Endat_SPI_Ctrl.scala 184:25]
        end else begin
          fsm_spi_cmd_valid <= 1'b0; // @[Endat_SPI_Ctrl.scala 188:25]
        end
      end
      fsm_enumDef_Wait_Rsp : begin
        if(when_Endat_SPI_Ctrl_l196) begin
          fsm_rdfifo_ready <= 1'b1; // @[Endat_SPI_Ctrl.scala 197:24]
        end
      end
      fsm_enumDef_Rd_Rsp : begin
        if(when_Endat_SPI_Ctrl_l204) begin
          if(_zz_1[0]) begin
            fsm_rspData_0 <= spictrl_rsp_payload; // @[Endat_SPI_Ctrl.scala 205:36]
          end
          if(_zz_1[1]) begin
            fsm_rspData_1 <= spictrl_rsp_payload; // @[Endat_SPI_Ctrl.scala 205:36]
          end
          if(_zz_1[2]) begin
            fsm_rspData_2 <= spictrl_rsp_payload; // @[Endat_SPI_Ctrl.scala 205:36]
          end
          if(_zz_1[3]) begin
            fsm_rspData_3 <= spictrl_rsp_payload; // @[Endat_SPI_Ctrl.scala 205:36]
          end
          if(_zz_1[4]) begin
            fsm_rspData_4 <= spictrl_rsp_payload; // @[Endat_SPI_Ctrl.scala 205:36]
          end
        end
        if(when_Endat_SPI_Ctrl_l208) begin
          fsm_rdfifo_ready <= 1'b1; // @[Endat_SPI_Ctrl.scala 209:24]
        end
      end
      default : begin
      end
    endcase
  end


endmodule

module SPI_Ctrl (
  output     [0:0]    spi_ss,
  output              spi_sclk,
  output              spi_mosi,
  input               spi_miso,
  input               config_kind_cpol,
  input               config_kind_cpha,
  input      [7:0]    config_sclkToogle,
  input      [0:0]    config_ss_activeHigh,
  input      [7:0]    config_ss_setup,
  input      [7:0]    config_ss_hold,
  input      [7:0]    config_ss_disable,
  input               cmd_valid,
  output              cmd_ready,
  input      [15:0]   cmd_payload,
  output              rsp_valid,
  input               rsp_ready,
  output     [15:0]   rsp_payload,
  output     [6:0]    occupancy,
  input               clk,
  input               reset
);
  localparam fsm_enumDef_1_BOOT = 3'd0;
  localparam fsm_enumDef_1_Init_Start = 3'd1;
  localparam fsm_enumDef_1_Active_CS = 3'd2;
  localparam fsm_enumDef_1_Send_Data = 3'd3;
  localparam fsm_enumDef_1_Disable_CS = 3'd4;
  localparam fsm_enumDef_1_Dummy_State = 3'd5;

  wire                wr_fifo_io_push_ready;
  wire                wr_fifo_io_pop_valid;
  wire       [15:0]   wr_fifo_io_pop_payload;
  wire       [6:0]    wr_fifo_io_occupancy;
  wire       [6:0]    wr_fifo_io_availability;
  wire                rd_fifo_io_push_ready;
  wire                rd_fifo_io_pop_valid;
  wire       [15:0]   rd_fifo_io_pop_payload;
  wire       [6:0]    rd_fifo_io_occupancy;
  wire       [6:0]    rd_fifo_io_availability;
  wire       [4:0]    _zz_fsm_counter_valueNext;
  wire       [0:0]    _zz_fsm_counter_valueNext_1;
  wire       [3:0]    _zz__zz_spi_mosi;
  wire       [3:0]    _zz__zz_spi_mosi_1;
  wire       [16:0]   _zz_fsm_buffer;
  reg        [7:0]    timer_counter;
  reg                 timer_reset;
  wire                timer_ss_setupHit;
  wire                timer_ss_holdHit;
  wire                timer_ss_disableHit;
  wire                timer_sclkToogleHit;
  reg                 wr_ready;
  wire                fsm_wantExit;
  reg                 fsm_wantStart;
  wire                fsm_wantKill;
  reg                 fsm_counter_willIncrement;
  wire                fsm_counter_willClear;
  reg        [4:0]    fsm_counter_valueNext;
  reg        [4:0]    fsm_counter_value;
  wire                fsm_counter_willOverflowIfInc;
  wire                fsm_counter_willOverflow;
  reg        [15:0]   fsm_buffer;
  reg        [0:0]    fsm_ss;
  reg        [15:0]   fsm_wr_payload;
  reg                 fsm_rsp_valid;
  reg                 _zz_spi_sclk;
  reg                 _zz_spi_mosi;
  reg        [2:0]    fsm_stateReg;
  reg        [2:0]    fsm_stateNext;
  wire                when_Endat_SPI_Ctrl_l53;
  wire                when_Endat_SPI_Ctrl_l76;
  wire                when_Endat_SPI_Ctrl_l79;
  `ifndef SYNTHESIS
  reg [87:0] fsm_stateReg_string;
  reg [87:0] fsm_stateNext_string;
  `endif


  assign _zz_fsm_counter_valueNext_1 = fsm_counter_willIncrement;
  assign _zz_fsm_counter_valueNext = {4'd0, _zz_fsm_counter_valueNext_1};
  assign _zz__zz_spi_mosi = (4'b1111 - _zz__zz_spi_mosi_1);
  assign _zz__zz_spi_mosi_1 = (fsm_counter_value >>> 1);
  assign _zz_fsm_buffer = {fsm_buffer,spi_miso};
  StreamFifo_1 wr_fifo (
    .io_push_valid   (cmd_valid                   ), //i
    .io_push_ready   (wr_fifo_io_push_ready       ), //o
    .io_push_payload (cmd_payload[15:0]           ), //i
    .io_pop_valid    (wr_fifo_io_pop_valid        ), //o
    .io_pop_ready    (wr_ready                    ), //i
    .io_pop_payload  (wr_fifo_io_pop_payload[15:0]), //o
    .io_flush        (1'b0                        ), //i
    .io_occupancy    (wr_fifo_io_occupancy[6:0]   ), //o
    .io_availability (wr_fifo_io_availability[6:0]), //o
    .clk             (clk                         ), //i
    .reset           (reset                       )  //i
  );
  StreamFifo_1 rd_fifo (
    .io_push_valid   (fsm_rsp_valid               ), //i
    .io_push_ready   (rd_fifo_io_push_ready       ), //o
    .io_push_payload (fsm_buffer[15:0]            ), //i
    .io_pop_valid    (rd_fifo_io_pop_valid        ), //o
    .io_pop_ready    (rsp_ready                   ), //i
    .io_pop_payload  (rd_fifo_io_pop_payload[15:0]), //o
    .io_flush        (1'b0                        ), //i
    .io_occupancy    (rd_fifo_io_occupancy[6:0]   ), //o
    .io_availability (rd_fifo_io_availability[6:0]), //o
    .clk             (clk                         ), //i
    .reset           (reset                       )  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(fsm_stateReg)
      fsm_enumDef_1_BOOT : fsm_stateReg_string = "BOOT       ";
      fsm_enumDef_1_Init_Start : fsm_stateReg_string = "Init_Start ";
      fsm_enumDef_1_Active_CS : fsm_stateReg_string = "Active_CS  ";
      fsm_enumDef_1_Send_Data : fsm_stateReg_string = "Send_Data  ";
      fsm_enumDef_1_Disable_CS : fsm_stateReg_string = "Disable_CS ";
      fsm_enumDef_1_Dummy_State : fsm_stateReg_string = "Dummy_State";
      default : fsm_stateReg_string = "???????????";
    endcase
  end
  always @(*) begin
    case(fsm_stateNext)
      fsm_enumDef_1_BOOT : fsm_stateNext_string = "BOOT       ";
      fsm_enumDef_1_Init_Start : fsm_stateNext_string = "Init_Start ";
      fsm_enumDef_1_Active_CS : fsm_stateNext_string = "Active_CS  ";
      fsm_enumDef_1_Send_Data : fsm_stateNext_string = "Send_Data  ";
      fsm_enumDef_1_Disable_CS : fsm_stateNext_string = "Disable_CS ";
      fsm_enumDef_1_Dummy_State : fsm_stateNext_string = "Dummy_State";
      default : fsm_stateNext_string = "???????????";
    endcase
  end
  `endif

  assign timer_ss_setupHit = (timer_counter == config_ss_setup); // @[BaseType.scala 305:24]
  assign timer_ss_holdHit = (timer_counter == config_ss_hold); // @[BaseType.scala 305:24]
  assign timer_ss_disableHit = (timer_counter == config_ss_disable); // @[BaseType.scala 305:24]
  assign timer_sclkToogleHit = (timer_counter == config_sclkToogle); // @[BaseType.scala 305:24]
  assign cmd_ready = wr_fifo_io_push_ready; // @[Endat_SPI_Ctrl.scala 36:16]
  assign fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(fsm_stateReg)
      fsm_enumDef_1_Init_Start : begin
      end
      fsm_enumDef_1_Active_CS : begin
      end
      fsm_enumDef_1_Send_Data : begin
      end
      fsm_enumDef_1_Disable_CS : begin
      end
      fsm_enumDef_1_Dummy_State : begin
      end
      default : begin
        fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  always @(*) begin
    fsm_counter_willIncrement = 1'b0; // @[Utils.scala 536:23]
    case(fsm_stateReg)
      fsm_enumDef_1_Init_Start : begin
      end
      fsm_enumDef_1_Active_CS : begin
      end
      fsm_enumDef_1_Send_Data : begin
        if(timer_sclkToogleHit) begin
          fsm_counter_willIncrement = 1'b1; // @[Utils.scala 540:41]
        end
      end
      fsm_enumDef_1_Disable_CS : begin
      end
      fsm_enumDef_1_Dummy_State : begin
      end
      default : begin
      end
    endcase
  end

  assign fsm_counter_willClear = 1'b0; // @[Utils.scala 537:19]
  assign fsm_counter_willOverflowIfInc = (fsm_counter_value == 5'h1f); // @[BaseType.scala 305:24]
  assign fsm_counter_willOverflow = (fsm_counter_willOverflowIfInc && fsm_counter_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    fsm_counter_valueNext = (fsm_counter_value + _zz_fsm_counter_valueNext); // @[Utils.scala 548:15]
    if(fsm_counter_willClear) begin
      fsm_counter_valueNext = 5'h0; // @[Utils.scala 558:15]
    end
  end

  assign rsp_payload = rd_fifo_io_pop_payload; // @[Endat_SPI_Ctrl.scala 109:18]
  assign rsp_valid = rd_fifo_io_pop_valid; // @[Endat_SPI_Ctrl.scala 110:16]
  assign occupancy = rd_fifo_io_occupancy; // @[Endat_SPI_Ctrl.scala 112:16]
  assign spi_ss[0] = (fsm_ss[0] ^ config_ss_activeHigh[0]); // @[Endat_SPI_Ctrl.scala 115:16]
  assign spi_sclk = _zz_spi_sclk; // @[Endat_SPI_Ctrl.scala 116:15]
  assign spi_mosi = _zz_spi_mosi; // @[Endat_SPI_Ctrl.scala 117:15]
  always @(*) begin
    fsm_stateNext = fsm_stateReg; // @[StateMachine.scala 217:17]
    case(fsm_stateReg)
      fsm_enumDef_1_Init_Start : begin
        if(when_Endat_SPI_Ctrl_l53) begin
          fsm_stateNext = fsm_enumDef_1_Active_CS; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_1_Active_CS : begin
        if(timer_ss_setupHit) begin
          fsm_stateNext = fsm_enumDef_1_Send_Data; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_1_Send_Data : begin
        if(timer_sclkToogleHit) begin
          if(when_Endat_SPI_Ctrl_l79) begin
            fsm_stateNext = fsm_enumDef_1_Disable_CS; // @[Enum.scala 148:67]
          end
        end
      end
      fsm_enumDef_1_Disable_CS : begin
        if(timer_ss_holdHit) begin
          fsm_stateNext = fsm_enumDef_1_Dummy_State; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_1_Dummy_State : begin
        if(timer_ss_disableHit) begin
          fsm_stateNext = fsm_enumDef_1_Init_Start; // @[Enum.scala 148:67]
        end
      end
      default : begin
      end
    endcase
    if(fsm_wantStart) begin
      fsm_stateNext = fsm_enumDef_1_Init_Start; // @[Enum.scala 148:67]
    end
    if(fsm_wantKill) begin
      fsm_stateNext = fsm_enumDef_1_BOOT; // @[Enum.scala 148:67]
    end
  end

  assign when_Endat_SPI_Ctrl_l53 = (wr_fifo_io_occupancy != 7'h0); // @[BaseType.scala 305:24]
  assign when_Endat_SPI_Ctrl_l76 = fsm_counter_value[0]; // @[BaseType.scala 305:24]
  assign when_Endat_SPI_Ctrl_l79 = (fsm_counter_value == 5'h1f); // @[BaseType.scala 305:24]
  always @(posedge clk) begin
    timer_counter <= (timer_counter + 8'h01); // @[Endat_SPI_Ctrl.scala 27:13]
    if(timer_reset) begin
      timer_counter <= 8'h0; // @[Endat_SPI_Ctrl.scala 29:15]
    end
    wr_ready <= 1'b0; // @[Endat_SPI_Ctrl.scala 39:12]
    fsm_rsp_valid <= 1'b0; // @[Endat_SPI_Ctrl.scala 48:15]
    timer_reset <= 1'b0; // @[Endat_SPI_Ctrl.scala 49:17]
    _zz_spi_sclk <= ((fsm_counter_value[0] ^ config_kind_cpha) ^ config_kind_cpol); // @[Reg.scala 39:30]
    _zz_spi_mosi <= fsm_wr_payload[_zz__zz_spi_mosi]; // @[Reg.scala 39:30]
    case(fsm_stateReg)
      fsm_enumDef_1_Init_Start : begin
        if(when_Endat_SPI_Ctrl_l53) begin
          timer_reset <= 1'b1; // @[Endat_SPI_Ctrl.scala 55:23]
        end
      end
      fsm_enumDef_1_Active_CS : begin
        if(timer_ss_setupHit) begin
          wr_ready <= 1'b1; // @[Endat_SPI_Ctrl.scala 64:20]
          fsm_wr_payload <= wr_fifo_io_pop_payload; // @[Endat_SPI_Ctrl.scala 65:22]
          timer_reset <= 1'b1; // @[Endat_SPI_Ctrl.scala 66:23]
        end
      end
      fsm_enumDef_1_Send_Data : begin
        if(timer_sclkToogleHit) begin
          timer_reset <= 1'b1; // @[Endat_SPI_Ctrl.scala 74:23]
          if(when_Endat_SPI_Ctrl_l76) begin
            fsm_buffer <= _zz_fsm_buffer[15:0]; // @[Endat_SPI_Ctrl.scala 77:20]
          end
        end
      end
      fsm_enumDef_1_Disable_CS : begin
        if(timer_ss_holdHit) begin
          fsm_rsp_valid <= 1'b1; // @[Endat_SPI_Ctrl.scala 88:21]
          timer_reset <= 1'b1; // @[Endat_SPI_Ctrl.scala 89:23]
        end
      end
      fsm_enumDef_1_Dummy_State : begin
        if(timer_ss_disableHit) begin
          timer_reset <= 1'b1; // @[Endat_SPI_Ctrl.scala 98:23]
        end
      end
      default : begin
      end
    endcase
  end

  always @(posedge clk or posedge reset) begin
    if(reset) begin
      fsm_counter_value <= 5'h0; // @[Data.scala 400:33]
      fsm_ss <= 1'b1; // @[Data.scala 400:33]
      fsm_stateReg <= fsm_enumDef_1_BOOT; // @[Data.scala 400:33]
    end else begin
      fsm_counter_value <= fsm_counter_valueNext; // @[Reg.scala 39:30]
      fsm_stateReg <= fsm_stateNext; // @[StateMachine.scala 212:14]
      case(fsm_stateReg)
        fsm_enumDef_1_Init_Start : begin
          if(when_Endat_SPI_Ctrl_l53) begin
            fsm_ss[0] <= 1'b0; // @[Endat_SPI_Ctrl.scala 54:17]
          end
        end
        fsm_enumDef_1_Active_CS : begin
          if(timer_ss_setupHit) begin
            fsm_counter_value <= 5'h0; // @[Endat_SPI_Ctrl.scala 63:19]
          end
        end
        fsm_enumDef_1_Send_Data : begin
        end
        fsm_enumDef_1_Disable_CS : begin
          if(timer_ss_holdHit) begin
            fsm_ss[0] <= 1'b1; // @[Endat_SPI_Ctrl.scala 90:17]
          end
        end
        fsm_enumDef_1_Dummy_State : begin
        end
        default : begin
        end
      endcase
    end
  end


endmodule

//StreamFifo_1 replaced by StreamFifo_1

module StreamFifo_1 (
  input               io_push_valid,
  output              io_push_ready,
  input      [15:0]   io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [15:0]   io_pop_payload,
  input               io_flush,
  output     [6:0]    io_occupancy,
  output     [6:0]    io_availability,
  input               clk,
  input               reset
);

  reg        [15:0]   _zz_logic_ram_port0;
  wire       [5:0]    _zz_logic_pushPtr_valueNext;
  wire       [0:0]    _zz_logic_pushPtr_valueNext_1;
  wire       [5:0]    _zz_logic_popPtr_valueNext;
  wire       [0:0]    _zz_logic_popPtr_valueNext_1;
  wire                _zz_logic_ram_port;
  wire                _zz_io_pop_payload;
  wire       [5:0]    _zz_io_availability;
  reg                 _zz_1;
  reg                 logic_pushPtr_willIncrement;
  reg                 logic_pushPtr_willClear;
  reg        [5:0]    logic_pushPtr_valueNext;
  reg        [5:0]    logic_pushPtr_value;
  wire                logic_pushPtr_willOverflowIfInc;
  wire                logic_pushPtr_willOverflow;
  reg                 logic_popPtr_willIncrement;
  reg                 logic_popPtr_willClear;
  reg        [5:0]    logic_popPtr_valueNext;
  reg        [5:0]    logic_popPtr_value;
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
  wire       [5:0]    logic_ptrDif;
  reg [15:0] logic_ram [0:63];

  assign _zz_logic_pushPtr_valueNext_1 = logic_pushPtr_willIncrement;
  assign _zz_logic_pushPtr_valueNext = {5'd0, _zz_logic_pushPtr_valueNext_1};
  assign _zz_logic_popPtr_valueNext_1 = logic_popPtr_willIncrement;
  assign _zz_logic_popPtr_valueNext = {5'd0, _zz_logic_popPtr_valueNext_1};
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

  assign logic_pushPtr_willOverflowIfInc = (logic_pushPtr_value == 6'h3f); // @[BaseType.scala 305:24]
  assign logic_pushPtr_willOverflow = (logic_pushPtr_willOverflowIfInc && logic_pushPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_pushPtr_valueNext = (logic_pushPtr_value + _zz_logic_pushPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_pushPtr_willClear) begin
      logic_pushPtr_valueNext = 6'h0; // @[Utils.scala 558:15]
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

  assign logic_popPtr_willOverflowIfInc = (logic_popPtr_value == 6'h3f); // @[BaseType.scala 305:24]
  assign logic_popPtr_willOverflow = (logic_popPtr_willOverflowIfInc && logic_popPtr_willIncrement); // @[BaseType.scala 305:24]
  always @(*) begin
    logic_popPtr_valueNext = (logic_popPtr_value + _zz_logic_popPtr_valueNext); // @[Utils.scala 548:15]
    if(logic_popPtr_willClear) begin
      logic_popPtr_valueNext = 6'h0; // @[Utils.scala 558:15]
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
      logic_pushPtr_value <= 6'h0; // @[Data.scala 400:33]
      logic_popPtr_value <= 6'h0; // @[Data.scala 400:33]
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
