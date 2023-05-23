// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFullStep__Syms.h"


void VFullStep___024root__trace_chg_sub_0(VFullStep___024root* vlSelf, VerilatedVcd* tracep);

void VFullStep___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_chg_top_0\n"); );
    // Init
    VFullStep___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFullStep___024root*>(voidSelf);
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VFullStep___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VFullStep___024root__trace_chg_sub_0(VFullStep___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    tracep->chgSData(oldp+0,(vlSelf->c_data),16);
    tracep->chgSData(oldp+1,(vlSelf->d1_data),16);
    tracep->chgSData(oldp+2,(vlSelf->d2_data),16);
    tracep->chgBit(oldp+3,(vlSelf->clk));
    tracep->chgBit(oldp+4,(vlSelf->reset));
    tracep->chgSData(oldp+5,(vlSelf->FullStep__DOT__i),9);
    tracep->chgBit(oldp+6,((0x15fU > (IData)(vlSelf->FullStep__DOT__i))));
}

void VFullStep___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_cleanup\n"); );
    // Init
    VFullStep___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFullStep___024root*>(voidSelf);
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
