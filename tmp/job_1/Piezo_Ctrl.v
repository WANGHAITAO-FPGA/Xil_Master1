// Generator : SpinalHDL v1.8.0    git head : 4e3563a282582b41f4eaafc503787757251d23ea
// Component : Piezo_Ctrl
// Git hash  : f5ddcb1ebf9f3ce9c9d1466683ee01761d80916d

`timescale 1ns/1ps

module Piezo_Ctrl (
  input      [15:0]   dt_s,
  input      [15:0]   c1_val_in,
  input      [15:0]   c2_val_in,
  input      [15:0]   d1_val_in,
  input      [15:0]   d2_val_in,
  input      [15:0]   clamp_maxvalue,
  input      [15:0]   clamp_minvalue,
  input      [15:0]   step_value,
  input               relax_st,
  output     [15:0]   c1_val_out,
  output     [15:0]   c2_val_out,
  output     [15:0]   d1_val_out,
  output     [15:0]   d2_val_out,
  input               clk,
  input               reset
);

  wire                timer_ctrl_trigger;
  wire                relax_ctrl_tick;
  wire       [15:0]   relax_ctrl_c1_val_out;
  wire       [15:0]   relax_ctrl_c2_val_out;
  wire       [15:0]   relax_ctrl_d1_val_out;
  wire       [15:0]   relax_ctrl_d2_val_out;

  Timer_Piezo timer_ctrl (
    .dt_s    (dt_s[15:0]        ), //i
    .tick    (relax_ctrl_tick   ), //i
    .trigger (timer_ctrl_trigger), //o
    .clk     (clk               ), //i
    .reset   (reset             )  //i
  );
  Piezo_Relax relax_ctrl (
    .trigger        (timer_ctrl_trigger         ), //i
    .relax_st       (relax_st                   ), //i
    .c1_val_in      (c1_val_in[15:0]            ), //i
    .c2_val_in      (c2_val_in[15:0]            ), //i
    .d1_val_in      (d1_val_in[15:0]            ), //i
    .d2_val_in      (d2_val_in[15:0]            ), //i
    .clamp_maxvalue (clamp_maxvalue[15:0]       ), //i
    .clamp_minvalue (clamp_minvalue[15:0]       ), //i
    .step_value     (step_value[15:0]           ), //i
    .tick           (relax_ctrl_tick            ), //o
    .c1_val_out     (relax_ctrl_c1_val_out[15:0]), //o
    .c2_val_out     (relax_ctrl_c2_val_out[15:0]), //o
    .d1_val_out     (relax_ctrl_d1_val_out[15:0]), //o
    .d2_val_out     (relax_ctrl_d2_val_out[15:0]), //o
    .clk            (clk                        ), //i
    .reset          (reset                      )  //i
  );
  assign c1_val_out = relax_ctrl_c1_val_out; // @[Timer_Piezo.scala 196:28]
  assign c2_val_out = relax_ctrl_c2_val_out; // @[Timer_Piezo.scala 197:28]
  assign d1_val_out = relax_ctrl_d1_val_out; // @[Timer_Piezo.scala 198:28]
  assign d2_val_out = relax_ctrl_d2_val_out; // @[Timer_Piezo.scala 199:28]

endmodule

module Piezo_Relax (
  input               trigger,
  input               relax_st,
  input      [15:0]   c1_val_in,
  input      [15:0]   c2_val_in,
  input      [15:0]   d1_val_in,
  input      [15:0]   d2_val_in,
  input      [15:0]   clamp_maxvalue,
  input      [15:0]   clamp_minvalue,
  input      [15:0]   step_value,
  output              tick,
  output     [15:0]   c1_val_out,
  output     [15:0]   c2_val_out,
  output     [15:0]   d1_val_out,
  output     [15:0]   d2_val_out,
  input               clk,
  input               reset
);
  localparam fsm_enumDef_BOOT = 3'd0;
  localparam fsm_enumDef_Initial_Start = 3'd1;
  localparam fsm_enumDef_STEP1 = 3'd2;
  localparam fsm_enumDef_STEP2 = 3'd3;
  localparam fsm_enumDef_STEP3 = 3'd4;
  localparam fsm_enumDef_STEP4 = 3'd5;
  localparam fsm_enumDef_STEP5 = 3'd6;

  wire       [15:0]   _zz_when_Timer_Piezo_l85;
  wire       [15:0]   _zz_when_Timer_Piezo_l100;
  wire       [15:0]   _zz_when_Timer_Piezo_l107;
  wire       [15:0]   _zz_when_Timer_Piezo_l120;
  wire       [15:0]   _zz_when_Timer_Piezo_l135;
  wire       [15:0]   _zz_when_Timer_Piezo_l142;
  wire       [15:0]   _zz_when_Timer_Piezo_l155;
  reg                 relax_st_1;
  reg                 trigger_1;
  reg                 tick_1;
  reg        [15:0]   step_value_1;
  reg        [15:0]   c1_val_in_1;
  reg        [15:0]   c2_val_in_1;
  reg        [15:0]   d1_val_in_1;
  reg        [15:0]   d2_val_in_1;
  reg        [15:0]   clamp_maxvalue_1;
  reg        [15:0]   clamp_minvalue_1;
  wire                fsm_wantExit;
  reg                 fsm_wantStart;
  wire                fsm_wantKill;
  reg        [2:0]    fsm_stateReg;
  reg        [2:0]    fsm_stateNext;
  reg                 relax_st_1_regNext;
  wire                when_Timer_Piezo_l69;
  reg                 trigger_1_regNext;
  wire                when_Timer_Piezo_l84;
  wire                when_Timer_Piezo_l85;
  reg                 trigger_1_regNext_1;
  wire                when_Timer_Piezo_l98;
  wire                when_Timer_Piezo_l99;
  wire                when_Timer_Piezo_l100;
  wire                when_Timer_Piezo_l107;
  reg                 trigger_1_regNext_2;
  wire                when_Timer_Piezo_l119;
  wire                when_Timer_Piezo_l120;
  reg                 trigger_1_regNext_3;
  wire                when_Timer_Piezo_l133;
  wire                when_Timer_Piezo_l134;
  wire                when_Timer_Piezo_l135;
  wire                when_Timer_Piezo_l142;
  reg                 trigger_1_regNext_4;
  wire                when_Timer_Piezo_l154;
  wire                when_Timer_Piezo_l155;
  `ifndef SYNTHESIS
  reg [103:0] fsm_stateReg_string;
  reg [103:0] fsm_stateNext_string;
  `endif


  assign _zz_when_Timer_Piezo_l85 = (c1_val_in_1 - clamp_minvalue_1);
  assign _zz_when_Timer_Piezo_l100 = (d1_val_in_1 - 16'h8000);
  assign _zz_when_Timer_Piezo_l107 = (16'h8000 - d1_val_in_1);
  assign _zz_when_Timer_Piezo_l120 = (clamp_maxvalue_1 - c1_val_in_1);
  assign _zz_when_Timer_Piezo_l135 = (d2_val_in_1 - 16'h8000);
  assign _zz_when_Timer_Piezo_l142 = (16'h8000 - d2_val_in_1);
  assign _zz_when_Timer_Piezo_l155 = (c1_val_in_1 - 16'h8000);
  `ifndef SYNTHESIS
  always @(*) begin
    case(fsm_stateReg)
      fsm_enumDef_BOOT : fsm_stateReg_string = "BOOT         ";
      fsm_enumDef_Initial_Start : fsm_stateReg_string = "Initial_Start";
      fsm_enumDef_STEP1 : fsm_stateReg_string = "STEP1        ";
      fsm_enumDef_STEP2 : fsm_stateReg_string = "STEP2        ";
      fsm_enumDef_STEP3 : fsm_stateReg_string = "STEP3        ";
      fsm_enumDef_STEP4 : fsm_stateReg_string = "STEP4        ";
      fsm_enumDef_STEP5 : fsm_stateReg_string = "STEP5        ";
      default : fsm_stateReg_string = "?????????????";
    endcase
  end
  always @(*) begin
    case(fsm_stateNext)
      fsm_enumDef_BOOT : fsm_stateNext_string = "BOOT         ";
      fsm_enumDef_Initial_Start : fsm_stateNext_string = "Initial_Start";
      fsm_enumDef_STEP1 : fsm_stateNext_string = "STEP1        ";
      fsm_enumDef_STEP2 : fsm_stateNext_string = "STEP2        ";
      fsm_enumDef_STEP3 : fsm_stateNext_string = "STEP3        ";
      fsm_enumDef_STEP4 : fsm_stateNext_string = "STEP4        ";
      fsm_enumDef_STEP5 : fsm_stateNext_string = "STEP5        ";
      default : fsm_stateNext_string = "?????????????";
    endcase
  end
  `endif

  assign fsm_wantExit = 1'b0; // @[StateMachine.scala 151:28]
  always @(*) begin
    fsm_wantStart = 1'b0; // @[StateMachine.scala 152:19]
    case(fsm_stateReg)
      fsm_enumDef_Initial_Start : begin
      end
      fsm_enumDef_STEP1 : begin
      end
      fsm_enumDef_STEP2 : begin
      end
      fsm_enumDef_STEP3 : begin
      end
      fsm_enumDef_STEP4 : begin
      end
      fsm_enumDef_STEP5 : begin
      end
      default : begin
        fsm_wantStart = 1'b1; // @[StateMachine.scala 362:15]
      end
    endcase
  end

  assign fsm_wantKill = 1'b0; // @[StateMachine.scala 153:18]
  assign tick = tick_1; // @[Timer_Piezo.scala 168:11]
  assign c1_val_out = c1_val_in_1; // @[Timer_Piezo.scala 169:17]
  assign c2_val_out = c2_val_in_1; // @[Timer_Piezo.scala 170:17]
  assign d1_val_out = d1_val_in_1; // @[Timer_Piezo.scala 171:17]
  assign d2_val_out = d2_val_in_1; // @[Timer_Piezo.scala 172:17]
  always @(*) begin
    fsm_stateNext = fsm_stateReg; // @[StateMachine.scala 217:17]
    case(fsm_stateReg)
      fsm_enumDef_Initial_Start : begin
        if(when_Timer_Piezo_l69) begin
          fsm_stateNext = fsm_enumDef_STEP1; // @[Enum.scala 148:67]
        end
      end
      fsm_enumDef_STEP1 : begin
        if(when_Timer_Piezo_l84) begin
          if(!when_Timer_Piezo_l85) begin
            fsm_stateNext = fsm_enumDef_STEP2; // @[Enum.scala 148:67]
          end
        end
      end
      fsm_enumDef_STEP2 : begin
        if(when_Timer_Piezo_l98) begin
          if(when_Timer_Piezo_l99) begin
            if(!when_Timer_Piezo_l100) begin
              fsm_stateNext = fsm_enumDef_STEP3; // @[Enum.scala 148:67]
            end
          end else begin
            if(!when_Timer_Piezo_l107) begin
              fsm_stateNext = fsm_enumDef_STEP3; // @[Enum.scala 148:67]
            end
          end
        end
      end
      fsm_enumDef_STEP3 : begin
        if(when_Timer_Piezo_l119) begin
          if(!when_Timer_Piezo_l120) begin
            fsm_stateNext = fsm_enumDef_STEP4; // @[Enum.scala 148:67]
          end
        end
      end
      fsm_enumDef_STEP4 : begin
        if(when_Timer_Piezo_l133) begin
          if(when_Timer_Piezo_l134) begin
            if(!when_Timer_Piezo_l135) begin
              fsm_stateNext = fsm_enumDef_STEP5; // @[Enum.scala 148:67]
            end
          end else begin
            if(!when_Timer_Piezo_l142) begin
              fsm_stateNext = fsm_enumDef_STEP5; // @[Enum.scala 148:67]
            end
          end
        end
      end
      fsm_enumDef_STEP5 : begin
        if(when_Timer_Piezo_l154) begin
          if(!when_Timer_Piezo_l155) begin
            fsm_stateNext = fsm_enumDef_Initial_Start; // @[Enum.scala 148:67]
          end
        end
      end
      default : begin
      end
    endcase
    if(fsm_wantStart) begin
      fsm_stateNext = fsm_enumDef_Initial_Start; // @[Enum.scala 148:67]
    end
    if(fsm_wantKill) begin
      fsm_stateNext = fsm_enumDef_BOOT; // @[Enum.scala 148:67]
    end
  end

  assign when_Timer_Piezo_l69 = (relax_st_1 && (! relax_st_1_regNext)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l84 = (trigger_1 && (! trigger_1_regNext)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l85 = (step_value_1 < _zz_when_Timer_Piezo_l85); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l98 = (trigger_1 && (! trigger_1_regNext_1)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l99 = (16'h8000 < d1_val_in_1); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l100 = (step_value_1 < _zz_when_Timer_Piezo_l100); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l107 = (step_value_1 < _zz_when_Timer_Piezo_l107); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l119 = (trigger_1 && (! trigger_1_regNext_2)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l120 = (step_value_1 < _zz_when_Timer_Piezo_l120); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l133 = (trigger_1 && (! trigger_1_regNext_3)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l134 = (16'h8000 < d2_val_in_1); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l135 = (step_value_1 < _zz_when_Timer_Piezo_l135); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l142 = (step_value_1 < _zz_when_Timer_Piezo_l142); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l154 = (trigger_1 && (! trigger_1_regNext_4)); // @[BaseType.scala 305:24]
  assign when_Timer_Piezo_l155 = (step_value_1 < _zz_when_Timer_Piezo_l155); // @[BaseType.scala 305:24]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      relax_st_1 <= 1'b0; // @[Data.scala 400:33]
      trigger_1 <= 1'b0; // @[Data.scala 400:33]
      tick_1 <= 1'b0; // @[Data.scala 400:33]
      step_value_1 <= 16'h1000; // @[Data.scala 400:33]
      fsm_stateReg <= fsm_enumDef_BOOT; // @[Data.scala 400:33]
    end else begin
      relax_st_1 <= relax_st; // @[Timer_Piezo.scala 49:12]
      trigger_1 <= trigger; // @[Timer_Piezo.scala 52:11]
      fsm_stateReg <= fsm_stateNext; // @[StateMachine.scala 212:14]
      case(fsm_stateReg)
        fsm_enumDef_Initial_Start : begin
          if(when_Timer_Piezo_l69) begin
            tick_1 <= 1'b1; // @[Timer_Piezo.scala 70:16]
            step_value_1 <= step_value; // @[Timer_Piezo.scala 77:22]
          end
        end
        fsm_enumDef_STEP1 : begin
        end
        fsm_enumDef_STEP2 : begin
        end
        fsm_enumDef_STEP3 : begin
        end
        fsm_enumDef_STEP4 : begin
        end
        fsm_enumDef_STEP5 : begin
          if(when_Timer_Piezo_l154) begin
            if(!when_Timer_Piezo_l155) begin
              tick_1 <= 1'b0; // @[Timer_Piezo.scala 161:18]
            end
          end
        end
        default : begin
        end
      endcase
    end
  end

  always @(posedge clk) begin
    relax_st_1_regNext <= relax_st_1; // @[Reg.scala 39:30]
  end

  always @(posedge clk) begin
    case(fsm_stateReg)
      fsm_enumDef_Initial_Start : begin
        if(when_Timer_Piezo_l69) begin
          c1_val_in_1 <= c1_val_in; // @[Timer_Piezo.scala 71:21]
          c2_val_in_1 <= c2_val_in; // @[Timer_Piezo.scala 72:21]
          d1_val_in_1 <= d1_val_in; // @[Timer_Piezo.scala 73:21]
          d2_val_in_1 <= d2_val_in; // @[Timer_Piezo.scala 74:21]
          clamp_maxvalue_1 <= clamp_maxvalue; // @[Timer_Piezo.scala 75:26]
          clamp_minvalue_1 <= clamp_minvalue; // @[Timer_Piezo.scala 76:26]
        end
      end
      fsm_enumDef_STEP1 : begin
        if(when_Timer_Piezo_l84) begin
          if(when_Timer_Piezo_l85) begin
            c1_val_in_1 <= (c1_val_in_1 - step_value_1); // @[Timer_Piezo.scala 86:23]
            c2_val_in_1 <= (c2_val_in_1 + step_value_1); // @[Timer_Piezo.scala 87:23]
          end else begin
            c1_val_in_1 <= clamp_minvalue_1; // @[Timer_Piezo.scala 89:23]
            c2_val_in_1 <= clamp_maxvalue_1; // @[Timer_Piezo.scala 90:23]
          end
        end
      end
      fsm_enumDef_STEP2 : begin
        if(when_Timer_Piezo_l98) begin
          if(when_Timer_Piezo_l99) begin
            if(when_Timer_Piezo_l100) begin
              d1_val_in_1 <= (d1_val_in_1 - step_value_1); // @[Timer_Piezo.scala 101:25]
            end else begin
              d1_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 103:25]
            end
          end else begin
            if(when_Timer_Piezo_l107) begin
              d1_val_in_1 <= (d1_val_in_1 + step_value_1); // @[Timer_Piezo.scala 108:25]
            end else begin
              d1_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 110:25]
            end
          end
        end
      end
      fsm_enumDef_STEP3 : begin
        if(when_Timer_Piezo_l119) begin
          if(when_Timer_Piezo_l120) begin
            c1_val_in_1 <= (c1_val_in_1 + step_value_1); // @[Timer_Piezo.scala 121:23]
            c2_val_in_1 <= (c2_val_in_1 - step_value_1); // @[Timer_Piezo.scala 122:23]
          end else begin
            c1_val_in_1 <= clamp_maxvalue_1; // @[Timer_Piezo.scala 124:23]
            c2_val_in_1 <= clamp_minvalue_1; // @[Timer_Piezo.scala 125:23]
          end
        end
      end
      fsm_enumDef_STEP4 : begin
        if(when_Timer_Piezo_l133) begin
          if(when_Timer_Piezo_l134) begin
            if(when_Timer_Piezo_l135) begin
              d2_val_in_1 <= (d2_val_in_1 - step_value_1); // @[Timer_Piezo.scala 136:25]
            end else begin
              d2_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 138:25]
            end
          end else begin
            if(when_Timer_Piezo_l142) begin
              d2_val_in_1 <= (d2_val_in_1 + step_value_1); // @[Timer_Piezo.scala 143:25]
            end else begin
              d2_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 145:25]
            end
          end
        end
      end
      fsm_enumDef_STEP5 : begin
        if(when_Timer_Piezo_l154) begin
          if(when_Timer_Piezo_l155) begin
            c1_val_in_1 <= (c1_val_in_1 - step_value_1); // @[Timer_Piezo.scala 156:23]
            c2_val_in_1 <= (c2_val_in_1 + step_value_1); // @[Timer_Piezo.scala 157:23]
          end else begin
            c1_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 159:23]
            c2_val_in_1 <= 16'h8000; // @[Timer_Piezo.scala 160:23]
          end
        end
      end
      default : begin
      end
    endcase
  end

  always @(posedge clk) begin
    trigger_1_regNext <= trigger_1; // @[Reg.scala 39:30]
  end

  always @(posedge clk) begin
    trigger_1_regNext_1 <= trigger_1; // @[Reg.scala 39:30]
  end

  always @(posedge clk) begin
    trigger_1_regNext_2 <= trigger_1; // @[Reg.scala 39:30]
  end

  always @(posedge clk) begin
    trigger_1_regNext_3 <= trigger_1; // @[Reg.scala 39:30]
  end

  always @(posedge clk) begin
    trigger_1_regNext_4 <= trigger_1; // @[Reg.scala 39:30]
  end


endmodule

module Timer_Piezo (
  input      [15:0]   dt_s,
  input               tick,
  output              trigger,
  input               clk,
  input               reset
);

  wire                timer_1_io_full;
  wire       [15:0]   timer_1_io_value;
  reg                 timer_reset;

  Timer timer_1 (
    .io_tick  (tick                  ), //i
    .io_clear (timer_reset           ), //i
    .io_limit (dt_s[15:0]            ), //i
    .io_full  (timer_1_io_full       ), //o
    .io_value (timer_1_io_value[15:0]), //o
    .clk      (clk                   ), //i
    .reset    (reset                 )  //i
  );
  assign trigger = timer_1_io_full; // @[Timer_Piezo.scala 21:14]
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      timer_reset <= 1'b1; // @[Data.scala 400:33]
    end else begin
      timer_reset <= 1'b0; // @[Timer_Piezo.scala 17:15]
      if(timer_1_io_full) begin
        timer_reset <= 1'b1; // @[Timer_Piezo.scala 23:17]
      end
    end
  end


endmodule

module Timer (
  input               io_tick,
  input               io_clear,
  input      [15:0]   io_limit,
  output              io_full,
  output     [15:0]   io_value,
  input               clk,
  input               reset
);

  wire       [15:0]   _zz_counter;
  wire       [0:0]    _zz_counter_1;
  reg        [15:0]   counter;
  wire                limitHit;
  reg                 inhibitFull;

  assign _zz_counter_1 = (! limitHit);
  assign _zz_counter = {15'd0, _zz_counter_1};
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
      counter <= 16'h0; // @[Timer.scala 24:13]
    end
  end


endmodule
