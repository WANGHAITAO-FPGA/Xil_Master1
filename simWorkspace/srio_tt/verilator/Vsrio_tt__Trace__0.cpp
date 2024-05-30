// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsrio_tt__Syms.h"


void Vsrio_tt___024root__trace_chg_sub_0(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);
void Vsrio_tt___024root__trace_chg_sub_1(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);
void Vsrio_tt___024root__trace_chg_sub_2(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);

void Vsrio_tt___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_chg_top_0\n"); );
    // Init
    Vsrio_tt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsrio_tt___024root*>(voidSelf);
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsrio_tt___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
    Vsrio_tt___024root__trace_chg_sub_1((&vlSymsp->TOP), tracep);
    Vsrio_tt___024root__trace_chg_sub_2((&vlSymsp->TOP), tracep);
}

void Vsrio_tt___024root__trace_chg_sub_0(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgQData(oldp+0,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT___zz_logic_ram_port0),64);
        tracep->chgSData(oldp+2,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_info_1),16);
        tracep->chgQData(oldp+3,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tdata),64);
        tracep->chgQData(oldp+5,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tdata),64);
        tracep->chgQData(oldp+7,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_logic_ram_port0),64);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgBit(oldp+9,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid));
        tracep->chgBit(oldp+10,(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast));
        tracep->chgBit(oldp+11,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))));
        tracep->chgBit(oldp+12,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid));
        tracep->chgBit(oldp+13,(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast));
        tracep->chgBit(oldp+14,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full)))));
        tracep->chgBit(oldp+15,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo_io_pop_valid));
        tracep->chgQData(oldp+16,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_0),64);
        tracep->chgQData(oldp+18,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_1),64);
        tracep->chgQData(oldp+20,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_2),64);
        tracep->chgQData(oldp+22,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_3),64);
        tracep->chgQData(oldp+24,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_4),64);
        tracep->chgQData(oldp+26,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_5),64);
        tracep->chgQData(oldp+28,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_6),64);
        tracep->chgQData(oldp+30,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_7),64);
        tracep->chgQData(oldp+32,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_8),64);
        tracep->chgQData(oldp+34,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_9),64);
        tracep->chgQData(oldp+36,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_10),64);
        tracep->chgQData(oldp+38,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_11),64);
        tracep->chgQData(oldp+40,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_12),64);
        tracep->chgQData(oldp+42,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_13),64);
        tracep->chgQData(oldp+44,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_14),64);
        tracep->chgQData(oldp+46,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT___zz_data_out_15),64);
        tracep->chgBit(oldp+48,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d));
        tracep->chgBit(oldp+49,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__doorbell_intr_1));
        tracep->chgQData(oldp+50,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr),34);
        tracep->chgBit(oldp+52,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_valid));
        tracep->chgQData(oldp+53,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_data),64);
        tracep->chgBit(oldp+55,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_start));
        tracep->chgSData(oldp+56,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter),16);
        tracep->chgBit(oldp+57,((0x190U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
        tracep->chgBit(oldp+58,((0xc8U < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
        tracep->chgBit(oldp+59,((0xeU < (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_counter))));
        tracep->chgBit(oldp+60,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__inhibitFull));
        tracep->chgQData(oldp+61,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readData),64);
        tracep->chgBit(oldp+63,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid));
        tracep->chgBit(oldp+64,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast));
        tracep->chgSData(oldp+65,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr),9);
        tracep->chgBit(oldp+66,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen));
        tracep->chgSData(oldp+67,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr),9);
        tracep->chgBit(oldp+68,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full)))));
        tracep->chgSData(oldp+69,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value))))),9);
        tracep->chgSData(oldp+70,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value))))),9);
        tracep->chgBit(oldp+71,((1U & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full)))));
        tracep->chgSData(oldp+72,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value))))),9);
        tracep->chgSData(oldp+73,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value))))),9);
        tracep->chgBit(oldp+74,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast));
        tracep->chgBit(oldp+75,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_tresp_tlast))));
        tracep->chgBit(oldp+76,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__request_autocheck_error_1));
        tracep->chgBit(oldp+77,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full)))));
        tracep->chgBit(oldp+78,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write) 
                                 & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                    & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
        tracep->chgBit(oldp+79,((1U & ((~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                                           & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))) 
                                       & (~ ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT___zz_io_pop_valid) 
                                             & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full))))))));
        tracep->chgSData(oldp+80,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value))))),9);
        tracep->chgSData(oldp+81,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value))))),9);
        tracep->chgSData(oldp+82,(((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value))))),9);
        tracep->chgSData(oldp+83,(((((~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch)) 
                                    << 8U) | (0xffU 
                                              & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value) 
                                                 - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value))))),9);
        tracep->chgBit(oldp+84,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__user_data_ready));
        tracep->chgBit(oldp+85,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__send_start_d));
        tracep->chgBit(oldp+86,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l76));
        tracep->chgBit(oldp+87,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received));
        tracep->chgBit(oldp+88,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                                 & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                    & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
        tracep->chgBit(oldp+89,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__nread_iresp_write));
        tracep->chgBit(oldp+90,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement));
        tracep->chgCData(oldp+91,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_valueNext),8);
        tracep->chgCData(oldp+92,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value),8);
        tracep->chgBit(oldp+93,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value))));
        tracep->chgBit(oldp+94,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_willIncrement))));
        tracep->chgCData(oldp+95,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value),8);
        tracep->chgBit(oldp+96,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value))));
        tracep->chgBit(oldp+97,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch));
        tracep->chgBit(oldp+98,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy));
        tracep->chgBit(oldp+99,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing));
        tracep->chgBit(oldp+100,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_ptrMatch) 
                                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_risingOccupancy)))));
        tracep->chgBit(oldp+101,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full));
        tracep->chgCData(oldp+102,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushPtr_value) 
                                             - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value)))),8);
        tracep->chgBit(oldp+103,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement));
        tracep->chgCData(oldp+104,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_valueNext),8);
        tracep->chgCData(oldp+105,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value),8);
        tracep->chgBit(oldp+106,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value))));
        tracep->chgBit(oldp+107,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_willIncrement))));
        tracep->chgCData(oldp+108,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value),8);
        tracep->chgBit(oldp+109,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value))));
        tracep->chgBit(oldp+110,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch));
        tracep->chgBit(oldp+111,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy));
        tracep->chgBit(oldp+112,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing));
        tracep->chgBit(oldp+113,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_ptrMatch) 
                                  & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_risingOccupancy)))));
        tracep->chgBit(oldp+114,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_full));
        tracep->chgCData(oldp+115,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushPtr_value) 
                                             - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value)))),8);
        tracep->chgBit(oldp+116,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_srio_reg__DOT__busslave_readError));
        tracep->chgBit(oldp+117,((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+118,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+119,((8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+120,(((8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+121,((0x10U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+122,(((0x10U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+123,((0x18U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+124,(((0x18U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+125,((0x20U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+126,(((0x20U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+127,((0x28U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+128,(((0x28U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+129,((0x30U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+130,(((0x30U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+131,((0x38U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+132,(((0x38U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+133,((0x40U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+134,(((0x40U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+135,((0x48U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+136,(((0x48U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+137,((0x50U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+138,(((0x50U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+139,((0x58U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+140,(((0x58U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+141,((0x60U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+142,(((0x60U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+143,((0x68U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+144,(((0x68U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+145,((0x70U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+146,(((0x70U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+147,((0x78U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+148,(((0x78U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+149,((0x80U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+150,(((0x80U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+151,((0x88U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+152,(((0x88U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+153,((0x90U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+154,(((0x90U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                  & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
    }
}

void Vsrio_tt___024root__trace_chg_sub_1(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_chg_sub_1\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 156);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgBit(oldp+0,((0x98U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+1,(((0x98U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+2,((0xa0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+3,(((0xa0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+4,((0xa8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+5,(((0xa8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+6,((0xb0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+7,(((0xb0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+8,((0xb8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+9,(((0xb8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+10,((0xc0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+11,(((0xc0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+12,((0xc8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+13,(((0xc8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+14,((0xd0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+15,(((0xd0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+16,((0xd8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+17,(((0xd8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+18,((0xe0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+19,(((0xe0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+20,((0xe8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+21,(((0xe8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+22,((0xf0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+23,(((0xf0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+24,((0xf8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+25,(((0xf8U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgBit(oldp+26,((0x100U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_raddr))));
        tracep->chgBit(oldp+27,(((0x100U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_waddr)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__data_store_wen))));
        tracep->chgCData(oldp+28,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value),8);
        tracep->chgBit(oldp+29,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value))));
        tracep->chgBit(oldp+30,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement));
        tracep->chgCData(oldp+31,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value),8);
        tracep->chgBit(oldp+32,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value))));
        tracep->chgBit(oldp+33,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_willIncrement))));
        tracep->chgBit(oldp+34,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch));
        tracep->chgBit(oldp+35,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy));
        tracep->chgBit(oldp+36,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_ptrMatch) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_risingOccupancy)))));
        tracep->chgBit(oldp+37,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_full));
        tracep->chgCData(oldp+38,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_value)))),8);
        tracep->chgBit(oldp+39,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat));
        tracep->chgBit(oldp+40,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top_m_axis_ireq_tlast))));
        tracep->chgBit(oldp+41,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_a_response));
        tracep->chgBit(oldp+42,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__capture_data));
        tracep->chgBit(oldp+43,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))));
        tracep->chgQData(oldp+44,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out_d),48);
        tracep->chgQData(oldp+46,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out),48);
        tracep->chgCData(oldp+48,((0xffU & (IData)(
                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                    >> 0xcU)))),8);
        tracep->chgCData(oldp+49,((0xfU & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                   >> 8U)))),4);
        tracep->chgCData(oldp+50,((0xffU & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out))),8);
        tracep->chgCData(oldp+51,((3U & (IData)((vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                 >> 0x14U)))),2);
        tracep->chgSData(oldp+52,((0x1ffU & (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                     >> 0x16U)))),9);
        tracep->chgBit(oldp+53,((IData)((0x80000200ULL 
                                         == (0x80000f00ULL 
                                             & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out)))));
        tracep->chgCData(oldp+54,(((2U == (0xfU & (IData)(
                                                          (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                           >> 8U))))
                                    ? 8U : 0U)),4);
        tracep->chgCData(oldp+55,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt),6);
        tracep->chgBit(oldp+56,((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt))));
        tracep->chgBit(oldp+57,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tlast))));
        tracep->chgBit(oldp+58,((0U == ((2U == (0xfU 
                                                & (IData)(
                                                          (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out 
                                                           >> 8U))))
                                         ? 8U : 0U))));
        tracep->chgBit(oldp+59,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp));
        tracep->chgBit(oldp+60,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d));
        tracep->chgBit(oldp+61,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__generate_rsp_d) 
                                 & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))));
        tracep->chgBit(oldp+62,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                                 & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)))));
        tracep->chgBit(oldp+63,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__pull_from_store_d) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
        tracep->chgQData(oldp+64,((0xd0000000000000ULL 
                                   | (((QData)((IData)(
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
                                        << 0x2dU))))),64);
        tracep->chgBit(oldp+66,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt)) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid)))));
        tracep->chgBit(oldp+67,(((IData)((0x80000200ULL 
                                          == (0x80000f00ULL 
                                              & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_out))) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
        tracep->chgQData(oldp+68,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__responding_ttype_string),48);
        tracep->chgBit(oldp+70,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement));
        tracep->chgCData(oldp+71,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_valueNext),8);
        tracep->chgCData(oldp+72,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value),8);
        tracep->chgBit(oldp+73,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value))));
        tracep->chgBit(oldp+74,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_willIncrement))));
        tracep->chgBit(oldp+75,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement));
        tracep->chgCData(oldp+76,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value),8);
        tracep->chgBit(oldp+77,((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value))));
        tracep->chgBit(oldp+78,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_willIncrement))));
        tracep->chgBit(oldp+79,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch));
        tracep->chgBit(oldp+80,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy));
        tracep->chgBit(oldp+81,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing));
        tracep->chgBit(oldp+82,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping));
        tracep->chgBit(oldp+83,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_ptrMatch) 
                                 & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_risingOccupancy)))));
        tracep->chgBit(oldp+84,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_full));
        tracep->chgBit(oldp+85,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushing) 
                                 != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popping))));
        tracep->chgCData(oldp+86,((0xffU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_pushPtr_value) 
                                            - (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_value)))),8);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        tracep->chgBit(oldp+87,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tlast))));
        tracep->chgBit(oldp+88,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement))));
        tracep->chgBit(oldp+89,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_pushing) 
                                 != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping))));
        tracep->chgBit(oldp+90,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_value)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement))));
        tracep->chgBit(oldp+91,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing) 
                                 != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        tracep->chgQData(oldp+92,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0),64);
        tracep->chgQData(oldp+94,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT___zz_logic_ram_port0),64);
        tracep->chgBit(oldp+96,((0x7d0U <= vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter)));
        tracep->chgIData(oldp+97,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter),32);
        tracep->chgBit(oldp+98,((0x7d0U == vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer__DOT__counter)));
        tracep->chgQData(oldp+99,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__write_queue_data),64);
        tracep->chgQData(oldp+101,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data),64);
        tracep->chgCData(oldp+103,((0xffU & (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
                                                     >> 0xcU)))),8);
        tracep->chgCData(oldp+104,((0xfU & (IData)(
                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data 
                                                    >> 8U)))),4);
        tracep->chgCData(oldp+105,((0xffU & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data))),8);
        tracep->chgCData(oldp+106,((0xffU & (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                     >> 0x38U)))),8);
        tracep->chgCData(oldp+107,((0xfU & (IData)(
                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                    >> 0x34U)))),4);
        tracep->chgCData(oldp+108,((0xfU & (IData)(
                                                   (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                    >> 0x30U)))),4);
        tracep->chgCData(oldp+109,((0xffU & (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                     >> 0x24U)))),8);
        tracep->chgCData(oldp+110,((3U & ((IData)(1U) 
                                          + (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                     >> 0x2dU))))),2);
        tracep->chgQData(oldp+111,((0x3ffffffffULL 
                                    & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)),34);
        tracep->chgQData(oldp+113,((0xff00000000ULL 
                                    | (QData)((IData)(
                                                      (((0x12U 
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
                                                                                >> 0x24U)))))))))))),48);
    }
}

void Vsrio_tt___024root__trace_chg_sub_2(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_chg_sub_2\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 271);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        tracep->chgQData(oldp+0,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__response_data_in),48);
        tracep->chgSData(oldp+2,((0xffffU & (IData)(
                                                    (vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0 
                                                     >> 0x10U)))),16);
        tracep->chgCData(oldp+3,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats),6);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        tracep->chgBit(oldp+4,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement));
        tracep->chgCData(oldp+5,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_valueNext),8);
        tracep->chgBit(oldp+6,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        tracep->chgBit(oldp+7,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid));
        tracep->chgCData(oldp+8,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt),6);
        tracep->chgBit(oldp+9,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
                                & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid)))));
        tracep->chgBit(oldp+10,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__when_Intitaor_l73));
        tracep->chgBit(oldp+11,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__expecting_a_response));
        tracep->chgBit(oldp+12,(((0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)) 
                                 & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid))));
        tracep->chgBit(oldp+13,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_willIncrement));
        tracep->chgCData(oldp+14,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popPtr_valueNext),8);
        tracep->chgBit(oldp+15,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__streamfifo_4__DOT__logic_popping));
        tracep->chgBit(oldp+16,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_willIncrement));
        tracep->chgCData(oldp+17,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushPtr_valueNext),8);
        tracep->chgCData(oldp+18,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_popPtr_valueNext),8);
        tracep->chgBit(oldp+19,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT__logic_pushing));
        tracep->chgCData(oldp+20,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo__DOT__logic_popPtr_valueNext),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        tracep->chgCData(oldp+21,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype),4);
        tracep->chgCData(oldp+22,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype),4);
        tracep->chgCData(oldp+23,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size),8);
        tracep->chgCData(oldp+24,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio),2);
        tracep->chgCData(oldp+25,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid),8);
        tracep->chgQData(oldp+26,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ftype_string),48);
        tracep->chgQData(oldp+28,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__usercmd_user_ttype_string),48);
        tracep->chgQData(oldp+30,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype_string),48);
        tracep->chgQData(oldp+32,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype_string),48);
        tracep->chgQData(oldp+34,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ftype_string),48);
        tracep->chgQData(oldp+36,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__usercmd_user_ttype_string),48);
        tracep->chgCData(oldp+38,((0x1fU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size) 
                                            >> 3U))),5);
        tracep->chgQData(oldp+39,((((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
                                    << 0xcU) | (QData)((IData)(
                                                               (((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype) 
                                                                 << 8U) 
                                                                | (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)))))),64);
        tracep->chgQData(oldp+41,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ftype_string),48);
        tracep->chgQData(oldp+43,(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__usercmd_user_ttype_string),48);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[7U])) {
        tracep->chgBit(oldp+45,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_timer_io_full));
        tracep->chgBit(oldp+46,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_wantStart));
        tracep->chgCData(oldp+47,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg),4);
        tracep->chgCData(oldp+48,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext),4);
        tracep->chgWData(oldp+49,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateReg_string),104);
        tracep->chgWData(oldp+53,(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_fsm_stateNext_string),104);
    }
    tracep->chgBit(oldp+57,(vlSelf->srio_clk));
    tracep->chgBit(oldp+58,(vlSelf->reset));
    tracep->chgBit(oldp+59,(vlSelf->iresp_stream_valid));
    tracep->chgBit(oldp+60,(vlSelf->iresp_stream_ready));
    tracep->chgQData(oldp+61,(vlSelf->iresp_stream_payload),64);
    tracep->chgQData(oldp+63,((((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_tid)) 
                                << 0x38U) | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                                              << 0x34U) 
                                             | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ttype)) 
                                                 << 0x30U) 
                                                | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_prio)) 
                                                    << 0x2dU) 
                                                   | (((QData)((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size)) 
                                                       << 0x24U) 
                                                      | vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_addr)))))),64);
    tracep->chgBit(oldp+65,((((2U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype)) 
                              | (0xaU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_ftype))) 
                             & (0U == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt)))));
    tracep->chgBit(oldp+66,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__current_beat_cnt) 
                              == (0x1fU & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_test__DOT__srio_area_user_size) 
                                           >> 3U))) 
                             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__ireq_tvalid))));
    tracep->chgBit(oldp+67,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__compare_received) 
                              & (0x200ULL == (0xf00ULL 
                                              & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__read_queue_data))) 
                             & ((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target_fifo_io_pop_valid) 
                                & (~ (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_full))))));
    tracep->chgBit(oldp+68,(((0xffU == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_value)) 
                             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popPtr_willIncrement))));
    tracep->chgBit(oldp+69,(((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_pushing) 
                             != (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_intitaor__DOT__fifo__DOT__logic_popping))));
    tracep->chgBit(oldp+70,((IData)(((0xa0000000000000ULL 
                                      == (0xf0000000000000ULL 
                                          & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)) 
                                     & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)))));
    tracep->chgBit(oldp+71,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__first_beat) 
                              & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo_io_pop_valid)) 
                             & (0x120000ULL == (0xff0000ULL 
                                                & vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_streamfifo__DOT___zz_logic_ram_port0)))));
    tracep->chgBit(oldp+72,((((IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__current_beat_cnt) 
                              == (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__number_of_data_beats)) 
                             & (IData)(vlSelf->srio_tt__DOT__srio_area_srio_top__DOT__srio_area_target__DOT__tresp_tvalid))));
}

void Vsrio_tt___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsrio_tt___024root__trace_cleanup\n"); );
    // Init
    Vsrio_tt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsrio_tt___024root*>(voidSelf);
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
