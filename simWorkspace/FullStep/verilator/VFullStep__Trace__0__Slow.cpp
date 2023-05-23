// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFullStep__Syms.h"


VL_ATTR_COLD void VFullStep___024root__trace_init_sub__TOP__0(VFullStep___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"c_data", false,-1, 15,0);
    tracep->declBus(c+2,"d1_data", false,-1, 15,0);
    tracep->declBus(c+3,"d2_data", false,-1, 15,0);
    tracep->declBit(c+4,"clk", false,-1);
    tracep->declBit(c+5,"reset", false,-1);
    tracep->pushNamePrefix("FullStep ");
    tracep->declBus(c+1,"c_data", false,-1, 15,0);
    tracep->declBus(c+2,"d1_data", false,-1, 15,0);
    tracep->declBus(c+3,"d2_data", false,-1, 15,0);
    tracep->declBit(c+4,"clk", false,-1);
    tracep->declBit(c+5,"reset", false,-1);
    tracep->declBus(c+8,"Sample", false,-1, 15,0);
    tracep->declBus(c+6,"i", false,-1, 8,0);
    tracep->declBit(c+7,"when_FullStep_l70", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VFullStep___024root__trace_init_top(VFullStep___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_init_top\n"); );
    // Body
    VFullStep___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VFullStep___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VFullStep___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VFullStep___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VFullStep___024root__trace_register(VFullStep___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VFullStep___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VFullStep___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VFullStep___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VFullStep___024root__trace_full_sub_0(VFullStep___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VFullStep___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_full_top_0\n"); );
    // Init
    VFullStep___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFullStep___024root*>(voidSelf);
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VFullStep___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VFullStep___024root__trace_full_sub_0(VFullStep___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullSData(oldp+1,(vlSelf->c_data),16);
    tracep->fullSData(oldp+2,(vlSelf->d1_data),16);
    tracep->fullSData(oldp+3,(vlSelf->d2_data),16);
    tracep->fullBit(oldp+4,(vlSelf->clk));
    tracep->fullBit(oldp+5,(vlSelf->reset));
    tracep->fullSData(oldp+6,(vlSelf->FullStep__DOT__i),9);
    tracep->fullBit(oldp+7,((0x15fU > (IData)(vlSelf->FullStep__DOT__i))));
    tracep->fullSData(oldp+8,(vlSelf->FullStep__DOT__Sample),16);
}
