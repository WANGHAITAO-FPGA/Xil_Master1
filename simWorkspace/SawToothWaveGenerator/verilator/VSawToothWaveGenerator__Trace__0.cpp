// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSawToothWaveGenerator__Syms.h"


void VSawToothWaveGenerator___024root__trace_chg_sub_0(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep);

void VSawToothWaveGenerator___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_chg_top_0\n"); );
    // Init
    VSawToothWaveGenerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSawToothWaveGenerator___024root*>(voidSelf);
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VSawToothWaveGenerator___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void VSawToothWaveGenerator___024root__trace_chg_sub_0(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgCData(oldp+0,(vlSelf->SawToothWaveGenerator__DOT__step),8);
        tracep->chgSData(oldp+1,(vlSelf->SawToothWaveGenerator__DOT__sawtooth),15);
        tracep->chgBit(oldp+2,(vlSelf->SawToothWaveGenerator__DOT__isRunning));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgBit(oldp+3,(vlSelf->SawToothWaveGenerator__DOT__init_regNext));
        tracep->chgBit(oldp+4,(vlSelf->SawToothWaveGenerator__DOT__stop_regNext));
        tracep->chgBit(oldp+5,(vlSelf->SawToothWaveGenerator__DOT__start_regNext));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        tracep->chgBit(oldp+6,(vlSelf->SawToothWaveGenerator__DOT__start));
        tracep->chgBit(oldp+7,(vlSelf->SawToothWaveGenerator__DOT__stop));
        tracep->chgBit(oldp+8,(vlSelf->SawToothWaveGenerator__DOT__init));
    }
    tracep->chgBit(oldp+9,(vlSelf->io_direction));
    tracep->chgCData(oldp+10,(vlSelf->io_step),8);
    tracep->chgBit(oldp+11,(vlSelf->io_start));
    tracep->chgBit(oldp+12,(vlSelf->io_stop));
    tracep->chgBit(oldp+13,(vlSelf->io_init));
    tracep->chgSData(oldp+14,(vlSelf->io_output),15);
    tracep->chgBit(oldp+15,(vlSelf->clk));
    tracep->chgBit(oldp+16,(vlSelf->reset));
    tracep->chgBit(oldp+17,((((IData)(vlSelf->SawToothWaveGenerator__DOT__init) 
                              & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__init_regNext))) 
                             | ((IData)(vlSelf->SawToothWaveGenerator__DOT__stop) 
                                & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__stop_regNext))))));
    tracep->chgBit(oldp+18,(((IData)(vlSelf->SawToothWaveGenerator__DOT__start) 
                             & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__start_regNext)))));
}

void VSawToothWaveGenerator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_cleanup\n"); );
    // Init
    VSawToothWaveGenerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSawToothWaveGenerator___024root*>(voidSelf);
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
