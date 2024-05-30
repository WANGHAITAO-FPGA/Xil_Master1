// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsrio_tt.h for the primary calling header

#ifndef VERILATED_VSRIO_TT___024ROOT_H_
#define VERILATED_VSRIO_TT___024ROOT_H_  // guard

#include "verilated.h"

class Vsrio_tt__Syms;
VL_MODULE(Vsrio_tt___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(srio_clk,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(iresp_stream_valid,0,0);
        VL_IN8(iresp_stream_ready,0,0);
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_m_axis_tresp_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_intr_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen;
        CData/*5:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt;
        CData/*5:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__when_Target_l147;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid;
        CData/*5:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__request_autocheck_error_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext;
    };
    struct {
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_1;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_io_pop_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_clear;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full;
        CData/*3:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
        CData/*3:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size;
        CData/*1:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio;
        CData/*7:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart;
        CData/*3:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg;
        CData/*3:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l140;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l163;
        CData/*0:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull;
        CData/*5:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt;
        CData/*0:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d;
        CData/*0:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat;
        CData/*0:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid;
        CData/*5:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt;
        CData/*0:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid;
        CData/*0:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received;
        CData/*5:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats;
        CData/*7:0*/ __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0;
        CData/*0:0*/ __Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0;
        CData/*7:0*/ __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0;
        CData/*0:0*/ __Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0;
        CData/*0:0*/ __Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0;
        CData/*0:0*/ __Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0;
        CData/*0:0*/ __Vclklast__TOP__srio_clk;
        CData/*0:0*/ __Vclklast__TOP__reset;
        SData/*8:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_waddr;
        SData/*8:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr;
        SData/*15:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_info_1;
        SData/*8:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr;
        SData/*8:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr;
        SData/*15:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter;
        SData/*8:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr;
        SData/*15:0*/ __Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter;
        VlWide<4>/*103:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string;
        VlWide<4>/*103:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string;
    };
    struct {
        IData/*31:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT___zz_counter;
        IData/*31:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter;
        IData/*31:0*/ __Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter;
        VL_OUT64(iresp_stream_payload,63,0);
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_dout;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_test__DOT___zz_srio_area_user_data;
        QData/*33:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr;
        QData/*63:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string;
        QData/*47:0*/ srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string;
        QData/*63:0*/ __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0;
        QData/*63:0*/ __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0;
        VlUnpacked<QData/*63:0*/, 256> srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram;
        VlUnpacked<QData/*63:0*/, 256> srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram;
        VlUnpacked<QData/*63:0*/, 256> srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram;
        VlUnpacked<QData/*63:0*/, 256> srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vsrio_tt__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vsrio_tt___024root(const char* name);
    ~Vsrio_tt___024root();
    VL_UNCOPYABLE(Vsrio_tt___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vsrio_tt__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
