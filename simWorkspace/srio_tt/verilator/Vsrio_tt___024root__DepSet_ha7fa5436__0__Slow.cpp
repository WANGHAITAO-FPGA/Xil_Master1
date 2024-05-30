// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsrio_tt.h for the primary calling header

#include "verilated.h"

#include "Vsrio_tt___024root.h"

extern const VlUnpacked<QData/*47:0*/, 16> Vsrio_tt__ConstPool__TABLE_h28429b45_0;
extern const VlUnpacked<QData/*47:0*/, 16> Vsrio_tt__ConstPool__TABLE_had2ae999_0;
extern const VlUnpacked<VlWide<4>/*103:0*/, 16> Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vsrio_tt__ConstPool__TABLE_he9d575b8_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vsrio_tt__ConstPool__TABLE_hfff72819_0;

VL_ATTR_COLD void Vsrio_tt___024root___settle__TOP__9(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___settle__TOP__9\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    CData/*3:0*/ __Vtableidx2;
    CData/*3:0*/ __Vtableidx3;
    CData/*3:0*/ __Vtableidx4;
    CData/*3:0*/ __Vtableidx5;
    CData/*3:0*/ __Vtableidx6;
    CData/*3:0*/ __Vtableidx7;
    CData/*3:0*/ __Vtableidx8;
    CData/*3:0*/ __Vtableidx9;
    CData/*3:0*/ __Vtableidx10;
    CData/*3:0*/ __Vtableidx11;
    CData/*3:0*/ __Vtableidx12;
    SData/*8:0*/ __Vtableidx13;
    // Body
    vlSelf->iresp_stream_payload = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_m_axis_tresp_tlast 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast 
        = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_clear 
        = (0x7d0U <= vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT___zz_counter 
        = (0x7d0U != vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
           == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_waddr 
        = (0x1ffU & ((IData)(8U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr 
        = (0x1ffU & ((IData)(8U) + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr)));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT___zz_srio_area_user_data 
        = (1ULL + vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l140 
        = (0x190U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l163 
        = (0xc8U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__when_Target_l147 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d)));
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full 
        = ((0x7d0U == vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull)));
    __Vtableidx1 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx1];
    __Vtableidx2 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx2];
    __Vtableidx3 = ((2U == (0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                            >> 8U))))
                     ? 8U : 0U);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx3];
    __Vtableidx4 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx4];
    __Vtableidx5 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx5];
    __Vtableidx6 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx6];
    __Vtableidx7 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx7];
    __Vtableidx8 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string 
        = Vsrio_tt__ConstPool__TABLE_h28429b45_0[__Vtableidx8];
    __Vtableidx9 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string 
        = Vsrio_tt__ConstPool__TABLE_had2ae999_0[__Vtableidx9];
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
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping 
        = (((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))) 
            & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid) 
                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full))))) 
           & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid 
        = (1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch) 
                     & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)))) 
                 & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_io_pop_valid) 
                       & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full))))));
    __Vtableidx11 = vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext;
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[0U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][0U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[1U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][1U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[2U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][2U];
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string[3U] 
        = Vsrio_tt__ConstPool__TABLE_hb9c3dca5_0[__Vtableidx11][3U];
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement = 1U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = 0U;
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1 = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1 = 1U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 0U;
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 1U;
    } else {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = 0U;
    }
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
    vlSelf->iresp_stream_valid = vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid;
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping 
        = ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid) 
           & (IData)(vlSelf->iresp_stream_ready));
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
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement = 0U;
    if (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement = 1U;
    }
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
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement)));
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement)));
}

VL_ATTR_COLD void Vsrio_tt___024root___settle__TOP__10(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___settle__TOP__10\n"); );
    // Body
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext 
        = (0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                    + (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement)));
}

VL_ATTR_COLD void Vsrio_tt___024root___eval_initial(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__srio_clk = (1U & (~ (IData)(vlSelf->srio_clk)));
    vlSelf->__Vclklast__TOP__reset = (1U & (~ (IData)(vlSelf->reset)));
}

VL_ATTR_COLD void Vsrio_tt___024root___eval_settle(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___eval_settle\n"); );
    // Body
    Vsrio_tt___024root___settle__TOP__9(vlSelf);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    Vsrio_tt___024root___settle__TOP__10(vlSelf);
}

VL_ATTR_COLD void Vsrio_tt___024root___final(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___final\n"); );
}

VL_ATTR_COLD void Vsrio_tt___024root___ctor_var_reset(Vsrio_tt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->srio_clk = 0;
    vlSelf->reset = 0;
    vlSelf->iresp_stream_valid = VL_RAND_RESET_I(1);
    vlSelf->iresp_stream_ready = VL_RAND_RESET_I(1);
    vlSelf->iresp_stream_payload = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_m_axis_tresp_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor_m_axis_ireq_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_waddr = VL_RAND_RESET_I(9);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT___zz_data_store_raddr = VL_RAND_RESET_I(9);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_intr_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_info_1 = VL_RAND_RESET_I(16);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr = VL_RAND_RESET_I(9);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt = VL_RAND_RESET_I(6);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats = VL_RAND_RESET_I(6);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr = VL_RAND_RESET_I(9);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__when_Target_l147 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_dout = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt = VL_RAND_RESET_I(6);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__request_autocheck_error_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0 = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_1 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_io_pop_valid = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_clear = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT___zz_srio_area_user_data = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr = VL_RAND_RESET_Q(34);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype = VL_RAND_RESET_I(4);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype = VL_RAND_RESET_I(4);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio = VL_RAND_RESET_I(2);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid = VL_RAND_RESET_I(8);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data = VL_RAND_RESET_Q(64);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = VL_RAND_RESET_I(16);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg = VL_RAND_RESET_I(4);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext = VL_RAND_RESET_I(4);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l140 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__when_Srio_Test_Top_l163 = VL_RAND_RESET_I(1);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string = VL_RAND_RESET_Q(48);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string = VL_RAND_RESET_Q(48);
    VL_RAND_RESET_W(104, vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string);
    VL_RAND_RESET_W(104, vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT___zz_counter = VL_RAND_RESET_I(32);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt = VL_RAND_RESET_I(6);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt = VL_RAND_RESET_I(6);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats = VL_RAND_RESET_I(6);
    vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 = VL_RAND_RESET_Q(64);
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdlyvdim0__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdlyvval__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 = VL_RAND_RESET_Q(64);
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdlyvset__srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ram__v0 = 0;
    vlSelf->__Vdly__srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
