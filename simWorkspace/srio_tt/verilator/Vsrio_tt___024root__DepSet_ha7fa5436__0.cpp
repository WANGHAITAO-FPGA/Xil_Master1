// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsrio_tt.h for the primary calling header

#include "verilated.h"

#include "Vsrio_tt___024root.h"

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__1(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__1\n"); );
    // Init
    QData/*63:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
    // Body
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter 
        = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0 = 0U;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0 = 0U;
    __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 = 0U;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 = 0U;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram
        [vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext];
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__2(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__2\n"); );
    // Init
    QData/*63:0*/ __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
    CData/*7:0*/ __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0;
    QData/*63:0*/ __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0;
    CData/*7:0*/ __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0;
    QData/*63:0*/ __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0;
    // Body
    if ((IData)(((0xa0000000000000ULL == (0xf0000000000000ULL 
                                          & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)) 
                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)))) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_info_1 
            = (0xffffU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                  >> 0x10U)));
    }
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter 
        = (vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter 
           + vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT___zz_counter);
    if (vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_clear) {
        vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter = 0U;
    }
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats 
        = ((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))
            ? (0x1fU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                >> 3U))) : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats));
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1) {
        __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data;
        vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0 = 1U;
        __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value;
    }
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_1) {
        __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0;
        vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0 = 1U;
        __Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value;
    }
    __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata 
        = (((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)) 
            & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid)))
            ? (0xd0000000000000ULL | (((QData)((IData)(
                                                       (0xffU 
                                                        & (IData)(
                                                                  (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                   >> 0xcU))))) 
                                       << 0x38U) | 
                                      (((QData)((IData)(
                                                        ((2U 
                                                          == 
                                                          (0xfU 
                                                           & (IData)(
                                                                     (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                      >> 8U))))
                                                          ? 8U
                                                          : 0U))) 
                                        << 0x30U) | 
                                       ((QData)((IData)(
                                                        (3U 
                                                         & (IData)(
                                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                                    >> 0x14U))))) 
                                        << 0x2dU))))
            : (((IData)((0x80000200ULL == (0x80000f00ULL 
                                           & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out))) 
                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))
                ? vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData
                : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata));
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_1) {
        vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
        vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 = 1U;
        vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value;
    }
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1) {
        vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata;
        vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 = 1U;
        vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value;
    }
    if (vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram[__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0] 
            = __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata 
        = __Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata;
    vlSelf->iresp_stream_payload = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata 
        = (((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
            & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)))
            ? (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
                << 0x38U) | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                              << 0x34U) | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype)) 
                                            << 0x30U) 
                                           | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio)) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)) 
                                                  << 0x24U) 
                                                 | vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr)))))
            : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram
        [vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext];
    if (vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram[__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0] 
            = __Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0;
    }
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__4(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__4\n"); );
    // Body
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter 
        = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready 
        = ((~ (IData)(vlSelf->reset)) & ((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73)) 
                                         & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76) 
                                            | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt 
        = ((IData)(vlSelf->reset) ? 0U : (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
                                           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast))
                                           ? 0U : (0x3fU 
                                                   & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))
                                                       : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat 
        = ((IData)(vlSelf->reset) | (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid) 
                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast)) 
                                     | ((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)) 
                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt 
        = ((IData)(vlSelf->reset) ? 0U : (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
                                           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast))
                                           ? 0U : (0x3fU 
                                                   & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt))
                                                       : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_intr_1 
        = ((~ (IData)(vlSelf->reset)) & (IData)(((0xa0000000000000ULL 
                                                  == 
                                                  (0xf0000000000000ULL 
                                                   & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)) 
                                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                                          & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))
                                          ? ((6U == 
                                              (0xfU 
                                               & (IData)(
                                                         (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                          >> 0x34U)))) 
                                             | (5U 
                                                == 
                                                (0xfU 
                                                 & (IData)(
                                                           (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                            >> 0x34U)))))
                                          : ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid) 
                                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast))) 
                                             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr 
        = ((IData)(vlSelf->reset) ? 0U : (0x1ffU & 
                                          (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                                            & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))
                                            ? (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)
                                            : ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)
                                                ? (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_waddr)
                                                : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                                          & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))) 
                                         | ((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__when_Target_l147)) 
                                            & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull = 0U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull 
            = (0x7d0U == vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter);
        if ((0x7d0U <= vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter)) {
            vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull = 0U;
        }
    }
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid 
        = ((~ (IData)(vlSelf->reset)) & ((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73)) 
                                         & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76) 
                                            | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d) 
                                          & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))) 
                                         | ((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast)) 
                                            & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast 
        = (1U & ((~ (IData)(vlSelf->reset)) & ((0U 
                                                == 
                                                ((2U 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(
                                                             (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                              >> 8U))))
                                                  ? 8U
                                                  : 0U))
                                                ? (~ 
                                                   ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_m_axis_tresp_tlast)))
                                                : (
                                                   (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt) 
                                                     == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats)) 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid)) 
                                                   & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast))))));
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received 
        = ((IData)(vlSelf->reset) | ((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))) 
                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast)) 
                                     | ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                            & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))) 
                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received))));
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError = 0U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError 
            = (1U & ((0x100U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                      ? (IData)((0U != (0xffU & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                      : ((0x80U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                          ? ((0x40U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                              ? ((0x20U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                  ? ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))))
                                  : ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))))
                              : ((0x20U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                  ? ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))))
                                  : ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))))))
                          : ((0x40U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                              ? ((0x20U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                  ? ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))))
                                  : ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))))
                              : ((0x20U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                  ? ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))))
                                  : ((0x10U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                      ? ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))
                                      : ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                          ? (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))))
                                          : (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)))))))))));
        if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError = 0U;
        }
    }
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__5(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__5\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy = 0U;
    } else if (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing) 
                != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping))) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start));
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value = 0U;
    } else {
        if (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing) 
             != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing;
        }
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast 
        = (1U & ((~ (IData)(vlSelf->reset)) & ((((2U 
                                                  == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                                 | (0xaU 
                                                    == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype))) 
                                                & (0U 
                                                   == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)))
                                                ? (~ 
                                                   ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast)))
                                                : (
                                                   (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt) 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size) 
                                                         >> 3U))) 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)) 
                                                   & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast))))));
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy = 0U;
    } else if (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing) 
                != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping))) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlSelf->reset)) & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value)));
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy = 0U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext;
        if (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing) 
             != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing;
        }
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlSelf->reset)) & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value 
        = ((IData)(vlSelf->reset) ? 0U : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlSelf->reset)) & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData 
        = ((IData)(vlSelf->reset) ? 0ULL : ((0x100U 
                                             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                             ? ((0x80U 
                                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                 ? 0ULL
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                  ? 0ULL
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                   ? 0ULL
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 0ULL
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 0ULL
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15))))))))
                                             : ((0x80U 
                                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                 ? 
                                                ((0x40U 
                                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                  ? 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11)))))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7))))))
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3)))))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0)))
                                                     : 0ULL))))
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                  ? 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                   ? 0ULL
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 0ULL
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x13880ULL)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x11170ULL))))))
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0xea60ULL)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0xc350ULL))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x9c40ULL)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x7530ULL)))))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x4e2aULL)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x4e20ULL))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x2710ULL)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                      ? 0ULL
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                       ? 0ULL
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))
                                                        ? 0ULL
                                                        : 0x202206011514ULL))))))))));
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__6(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__6\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__request_autocheck_error_1 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                                          & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                             & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))) 
                                         & (((((0xffU 
                                                & (IData)(
                                                          (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
                                                           >> 0xcU))) 
                                               != (0xffU 
                                                   & (IData)(
                                                             (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 
                                                              >> 0x38U)))) 
                                              | (IData)(
                                                        ((0x200ULL 
                                                          == 
                                                          (0xf00ULL 
                                                           & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data)) 
                                                         & (8U 
                                                            != 
                                                            (0xfU 
                                                             & (IData)(
                                                                       (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 
                                                                        >> 0x30U))))))) 
                                             | (IData)(
                                                       ((0x500ULL 
                                                         == 
                                                         (0xf00ULL 
                                                          & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data)) 
                                                        & (0U 
                                                           != 
                                                           (0xfU 
                                                            & (IData)(
                                                                      (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 
                                                                       >> 0x30U))))))) 
                                            | (IData)(
                                                      ((0xa00ULL 
                                                        == 
                                                        (0xf00ULL 
                                                         & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data)) 
                                                       & (0U 
                                                          != 
                                                          (0xfU 
                                                           & (IData)(
                                                                     (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 
                                                                      >> 0x30U)))))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value 
        = ((IData)(vlSelf->reset) ? 0U : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write 
        = ((~ (IData)(vlSelf->reset)) & ((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                                           & (0x200ULL 
                                              == (0xf00ULL 
                                                  & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data))) 
                                          & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                             & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))) 
                                         | ((~ (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))) 
                                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast))) 
                                            & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_io_pop_valid 
        = ((~ (IData)(vlSelf->reset)) & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext) 
                                         == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d 
        = ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_m_axis_tresp_tlast 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast;
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 0U;
        vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10 = 0ULL;
    } else {
        if ((8U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
            if ((1U & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg)))) {
                        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 0U;
                    }
                }
            }
        } else if ((4U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
            if ((2U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
                if ((1U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
                    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid = 0U;
                    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 1U;
                } else {
                    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)));
                    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid = 1U;
                    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data 
                        = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT___zz_srio_area_user_data;
                }
            } else if ((1U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr = 0x120088ULL;
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid = 1U;
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data = 0xa1a2a3a4ULL;
            } else {
                vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)));
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 0U;
                if (vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l163) {
                    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = 0U;
                }
            }
        } else if ((2U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
            if ((1U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr = 0x20000ULL;
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 1U;
                vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = 0U;
            } else {
                vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)));
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 0U;
                if (vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l140) {
                    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))) {
            if (vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full) {
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr = 0x120000ULL;
                vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = 1U;
                vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = 0U;
            }
        }
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext;
        if (((0x100U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xf8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xf0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xe8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xe0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xd8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
    }
}

extern const VlUnpacked<QData/*47:0*/, 16> Vsrio_tt__ConstPool__TABLE_had2ae999_0;

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__7(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__7\n"); );
    // Init
    CData/*3:0*/ __Vtableidx3;
    // Body
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0 = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value = 0U;
    } else {
        if (((0xd0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xc8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xc0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xb8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xb0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xa8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0xa0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0x98U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0x90U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        if (((0x88U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))) {
            vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0 
                = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0;
        }
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr 
            = (0x1ffU & (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                          & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))
                          ? (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr)
                          : (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                              & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))
                              ? (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr)
                              : (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                         >> 0x16U)))));
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT___zz_srio_area_user_data 
        = (1ULL + vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d)));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l140 
        = (0x190U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l163 
        = (0xc8U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_waddr 
        = (0x1ffU & ((IData)(8U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr 
        = (0x1ffU & ((IData)(8U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__when_Target_l147 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
        = ((IData)(vlSelf->reset) ? 0ULL : vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    __Vtableidx3 = ((2U == (0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                            >> 8U))))
                     ? 8U : 0U);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx3];
    if (vlSelf->reset) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d = 0ULL;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp = 0U;
    } else if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp = 0U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 0U;
    }
    vlSelf->iresp_stream_valid = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement = 0U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast 
        = ((1U == ((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy) 
                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch)) 
                    << 8U) | (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                                       - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value))))) 
           & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
              & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing 
        = (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write) 
            & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid)) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)));
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__8(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__8\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response 
        = ((~ (IData)(vlSelf->reset)) & ((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                                           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)) 
                                          & (0x120000ULL 
                                             == (0xff0000ULL 
                                                 & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0))) 
                                         & ((((2U == 
                                               (0xfU 
                                                & (IData)(
                                                          (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                           >> 0x34U)))) 
                                              | (0xaU 
                                                 == 
                                                 (0xfU 
                                                  & (IData)(
                                                            (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                             >> 0x34U))))) 
                                             | (0xbU 
                                                == 
                                                (0xfU 
                                                 & (IData)(
                                                           (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                            >> 0x34U))))) 
                                            | (IData)(
                                                      (0x55000000000000ULL 
                                                       == 
                                                       (0xff000000000000ULL 
                                                        & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement = 0U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement)));
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data;
        vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast 
            = (1U == ((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy) 
                        & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch)) 
                       << 8U) | (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                                          - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value)))));
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement = 0U;
    }
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__11(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__11\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_clear 
        = (0x7d0U <= vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT___zz_counter 
        = (0x7d0U != vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram
        [vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext];
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
            = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in 
        = (0xff00000000ULL | (QData)((IData)((((0x12U 
                                                == 
                                                (0xffU 
                                                 & (IData)(
                                                           (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                            >> 0x10U)))) 
                                               << 0x1fU) 
                                              | ((0x7fc00000U 
                                                  & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0) 
                                                     << 0x16U)) 
                                                 | ((0x300000U 
                                                     & (((IData)(1U) 
                                                         + (IData)(
                                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                    >> 0x2dU))) 
                                                        << 0x14U)) 
                                                    | ((0xff000U 
                                                        & ((IData)(
                                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                    >> 0x38U)) 
                                                           << 0xcU)) 
                                                       | ((0xf00U 
                                                           & ((IData)(
                                                                      (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                       >> 0x34U)) 
                                                              << 8U)) 
                                                          | (0xffU 
                                                             & (IData)(
                                                                       (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                                        >> 0x24U)))))))))));
    if (vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram[vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0] 
            = vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data 
        = (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
            << 0xcU) | (QData)((IData)((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype) 
                                         << 8U) | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram
        [vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext];
    if (vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram[vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0] 
            = vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0;
    }
}

VL_INLINE_OPT void Vsrio_tt___024root___combo__TOP__12(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___combo__TOP__12\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid) 
           & (IData)(vlSelf->iresp_stream_ready));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement)));
}

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__13(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__13\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response 
        = ((~ (IData)(vlSelf->reset)) & (((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
                                          & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)) 
                                         & ((((2U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                              | (0xaU 
                                                 == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype))) 
                                             | ((5U 
                                                 == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                                & (5U 
                                                   == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype)))) 
                                            | (0xbU 
                                               == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid 
        = vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping 
        = (((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))) 
            & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid) 
                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full))))) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 0U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement)));
}

extern const VlUnpacked<CData/*4:0*/, 32> Vsrio_tt__ConstPool__TABLE_h98aff62a_0;
extern const VlUnpacked<CData/*3:0*/, 32> Vsrio_tt__ConstPool__TABLE_ha177074c_0;
extern const VlUnpacked<CData/*3:0*/, 32> Vsrio_tt__ConstPool__TABLE_h298eda62_0;
extern const VlUnpacked<CData/*7:0*/, 32> Vsrio_tt__ConstPool__TABLE_hb1a981f5_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsrio_tt__ConstPool__TABLE_h481dbf04_0;
extern const VlUnpacked<CData/*7:0*/, 32> Vsrio_tt__ConstPool__TABLE_h09bda5cc_0;
extern const VlUnpacked<QData/*47:0*/, 16> Vsrio_tt__ConstPool__TABLE_h28429b45_0;

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__14(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__14\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    CData/*3:0*/ __Vtableidx2;
    CData/*3:0*/ __Vtableidx4;
    CData/*3:0*/ __Vtableidx5;
    CData/*3:0*/ __Vtableidx6;
    CData/*3:0*/ __Vtableidx7;
    CData/*3:0*/ __Vtableidx8;
    CData/*3:0*/ __Vtableidx9;
    CData/*4:0*/ __Vtableidx14;
    // Body
    __Vtableidx14 = (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full) 
                      << 4U) | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg));
    if ((1U & Vsrio_tt__ConstPool__TABLE_h98aff62a_0
         [__Vtableidx14])) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype 
            = Vsrio_tt__ConstPool__TABLE_ha177074c_0
            [__Vtableidx14];
    }
    if ((2U & Vsrio_tt__ConstPool__TABLE_h98aff62a_0
         [__Vtableidx14])) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype 
            = Vsrio_tt__ConstPool__TABLE_h298eda62_0
            [__Vtableidx14];
    }
    if ((4U & Vsrio_tt__ConstPool__TABLE_h98aff62a_0
         [__Vtableidx14])) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size 
            = Vsrio_tt__ConstPool__TABLE_hb1a981f5_0
            [__Vtableidx14];
    }
    if ((8U & Vsrio_tt__ConstPool__TABLE_h98aff62a_0
         [__Vtableidx14])) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio 
            = Vsrio_tt__ConstPool__TABLE_h481dbf04_0
            [__Vtableidx14];
    }
    if ((0x10U & Vsrio_tt__ConstPool__TABLE_h98aff62a_0
         [__Vtableidx14])) {
        vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid 
            = Vsrio_tt__ConstPool__TABLE_h09bda5cc_0
            [__Vtableidx14];
    }
    __Vtableidx1 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx1];
    __Vtableidx4 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx4];
    __Vtableidx6 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx6];
    __Vtableidx8 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx8];
    __Vtableidx2 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx2];
    __Vtableidx5 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx5];
    __Vtableidx7 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx7];
    __Vtableidx9 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx9];
}

extern const VlUnpacked<VlWide<4>/*103:0*/, 16> Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vsrio_tt__ConstPool__TABLE_he9d575b8_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vsrio_tt__ConstPool__TABLE_hfff72819_0;

VL_INLINE_OPT void Vsrio_tt___024root___sequent__TOP__15(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___sequent__TOP__15\n"); );
    // Init
    CData/*3:0*/ __Vtableidx10;
    CData/*3:0*/ __Vtableidx11;
    CData/*3:0*/ __Vtableidx12;
    SData/*8:0*/ __Vtableidx13;
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full 
        = ((0x7d0U == vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull)));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg 
        = ((IData)(vlSelf->reset) ? 0U : (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext));
    __Vtableidx10 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string[0U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx10][0U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string[1U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx10][1U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string[2U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx10][2U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string[3U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx10][3U];
    __Vtableidx12 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart 
        = Vsrio_tt__ConstPool__TABLE_he9d575b8_0[__Vtableidx12];
    __Vtableidx13 = (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart) 
                      << 8U) | (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full) 
                                 << 7U) | (((0x190U 
                                             < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)) 
                                            << 6U) 
                                           | (((0xc8U 
                                                < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)) 
                                               << 5U) 
                                              | (((0xeU 
                                                   < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter)) 
                                                  << 4U) 
                                                 | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg))))));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext 
        = Vsrio_tt__ConstPool__TABLE_hfff72819_0[__Vtableidx13];
    __Vtableidx11 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[0U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][0U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[1U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][1U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[2U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][2U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[3U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][3U];
}

void Vsrio_tt___024root___eval(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk)))) {
        Vsrio_tt___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        Vsrio_tt___024root___sequent__TOP__2(vlSelf);
    }
    if ((((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))) 
         | ((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk))))) {
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vsrio_tt___024root___sequent__TOP__4(vlSelf);
        Vsrio_tt___024root___sequent__TOP__5(vlSelf);
        Vsrio_tt___024root___sequent__TOP__6(vlSelf);
        Vsrio_tt___024root___sequent__TOP__7(vlSelf);
        Vsrio_tt___024root___sequent__TOP__8(vlSelf);
    }
    if (((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk)))) {
        Vsrio_tt___024root___sequent__TOP__11(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    Vsrio_tt___024root___combo__TOP__12(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    if ((((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))) 
         | ((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk))))) {
        Vsrio_tt___024root___sequent__TOP__13(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if (((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk)))) {
        Vsrio_tt___024root___sequent__TOP__14(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))) 
         | ((IData)(vlSelf->srio_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__srio_clk))))) {
        Vsrio_tt___024root___sequent__TOP__15(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__srio_clk = vlSelf->srio_clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

#ifdef VL_DEBUG
void Vsrio_tt___024root___eval_debug_assertions(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->srio_clk & 0xfeU))) {
        Verilated::overWidthError("srio_clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->iresp_stream_ready & 0xfeU))) {
        Verilated::overWidthError("iresp_stream_ready");}
}
#endif  // VL_DEBUG
