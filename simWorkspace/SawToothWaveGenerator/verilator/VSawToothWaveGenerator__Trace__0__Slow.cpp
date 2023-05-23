// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSawToothWaveGenerator__Syms.h"


VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_init_sub__TOP__0(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+10,"io_direction", false,-1);
    tracep->declBus(c+11,"io_step", false,-1, 7,0);
    tracep->declBit(c+12,"io_start", false,-1);
    tracep->declBit(c+13,"io_stop", false,-1);
    tracep->declBit(c+14,"io_init", false,-1);
    tracep->declBus(c+15,"io_output", false,-1, 14,0);
    tracep->declBit(c+16,"clk", false,-1);
    tracep->declBit(c+17,"reset", false,-1);
    tracep->pushNamePrefix("SawToothWaveGenerator ");
    tracep->declBit(c+10,"io_direction", false,-1);
    tracep->declBus(c+11,"io_step", false,-1, 7,0);
    tracep->declBit(c+12,"io_start", false,-1);
    tracep->declBit(c+13,"io_stop", false,-1);
    tracep->declBit(c+14,"io_init", false,-1);
    tracep->declBus(c+15,"io_output", false,-1, 14,0);
    tracep->declBit(c+16,"clk", false,-1);
    tracep->declBit(c+17,"reset", false,-1);
    tracep->declBus(c+1,"step", false,-1, 7,0);
    tracep->declBus(c+2,"sawtooth", false,-1, 14,0);
    tracep->declBit(c+3,"isRunning", false,-1);
    tracep->declBit(c+7,"start", false,-1);
    tracep->declBit(c+8,"stop", false,-1);
    tracep->declBit(c+9,"init", false,-1);
    tracep->declBit(c+4,"init_regNext", false,-1);
    tracep->declBit(c+5,"stop_regNext", false,-1);
    tracep->declBit(c+18,"when_SawToothWaveGenerator_l27", false,-1);
    tracep->declBit(c+6,"start_regNext", false,-1);
    tracep->declBit(c+19,"when_SawToothWaveGenerator_l29", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_init_top(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_init_top\n"); );
    // Body
    VSawToothWaveGenerator___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VSawToothWaveGenerator___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VSawToothWaveGenerator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_register(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VSawToothWaveGenerator___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VSawToothWaveGenerator___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VSawToothWaveGenerator___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_full_sub_0(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_full_top_0\n"); );
    // Init
    VSawToothWaveGenerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSawToothWaveGenerator___024root*>(voidSelf);
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VSawToothWaveGenerator___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_full_sub_0(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+1,(vlSelf->SawToothWaveGenerator__DOT__step),8);
    tracep->fullSData(oldp+2,(vlSelf->SawToothWaveGenerator__DOT__sawtooth),15);
    tracep->fullBit(oldp+3,(vlSelf->SawToothWaveGenerator__DOT__isRunning));
    tracep->fullBit(oldp+4,(vlSelf->SawToothWaveGenerator__DOT__init_regNext));
    tracep->fullBit(oldp+5,(vlSelf->SawToothWaveGenerator__DOT__stop_regNext));
    tracep->fullBit(oldp+6,(vlSelf->SawToothWaveGenerator__DOT__start_regNext));
    tracep->fullBit(oldp+7,(vlSelf->SawToothWaveGenerator__DOT__start));
    tracep->fullBit(oldp+8,(vlSelf->SawToothWaveGenerator__DOT__stop));
    tracep->fullBit(oldp+9,(vlSelf->SawToothWaveGenerator__DOT__init));
    tracep->fullBit(oldp+10,(vlSelf->io_direction));
    tracep->fullCData(oldp+11,(vlSelf->io_step),8);
    tracep->fullBit(oldp+12,(vlSelf->io_start));
    tracep->fullBit(oldp+13,(vlSelf->io_stop));
    tracep->fullBit(oldp+14,(vlSelf->io_init));
    tracep->fullSData(oldp+15,(vlSelf->io_output),15);
    tracep->fullBit(oldp+16,(vlSelf->clk));
    tracep->fullBit(oldp+17,(vlSelf->reset));
    tracep->fullBit(oldp+18,((((IData)(vlSelf->SawToothWaveGenerator__DOT__init) 
                               & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__init_regNext))) 
                              | ((IData)(vlSelf->SawToothWaveGenerator__DOT__stop) 
                                 & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__stop_regNext))))));
    tracep->fullBit(oldp+19,(((IData)(vlSelf->SawToothWaveGenerator__DOT__start) 
                              & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__start_regNext)))));
}
