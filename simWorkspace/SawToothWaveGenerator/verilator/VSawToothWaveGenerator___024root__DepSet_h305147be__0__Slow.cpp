// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSawToothWaveGenerator.h for the primary calling header

#include "verilated.h"

#include "VSawToothWaveGenerator___024root.h"

VL_ATTR_COLD void VSawToothWaveGenerator___024root___settle__TOP__0(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->io_output = vlSelf->SawToothWaveGenerator__DOT__sawtooth;
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root___eval_initial(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = (1U & (~ (IData)(vlSelf->clk)));
    vlSelf->__Vclklast__TOP__reset = (1U & (~ (IData)(vlSelf->reset)));
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root___eval_settle(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___eval_settle\n"); );
    // Body
    VSawToothWaveGenerator___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root___final(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___final\n"); );
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root___ctor_var_reset(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->io_direction = VL_RAND_RESET_I(1);
    vlSelf->io_step = VL_RAND_RESET_I(8);
    vlSelf->io_start = VL_RAND_RESET_I(1);
    vlSelf->io_stop = VL_RAND_RESET_I(1);
    vlSelf->io_init = VL_RAND_RESET_I(1);
    vlSelf->io_output = VL_RAND_RESET_I(15);
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->SawToothWaveGenerator__DOT__step = VL_RAND_RESET_I(8);
    vlSelf->SawToothWaveGenerator__DOT__sawtooth = VL_RAND_RESET_I(15);
    vlSelf->SawToothWaveGenerator__DOT__isRunning = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__stop = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__init = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__init_regNext = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__stop_regNext = VL_RAND_RESET_I(1);
    vlSelf->SawToothWaveGenerator__DOT__start_regNext = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
