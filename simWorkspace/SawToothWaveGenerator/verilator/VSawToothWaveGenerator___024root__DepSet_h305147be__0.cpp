// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSawToothWaveGenerator.h for the primary calling header

#include "verilated.h"

#include "VSawToothWaveGenerator___024root.h"

VL_INLINE_OPT void VSawToothWaveGenerator___024root___sequent__TOP__0(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___sequent__TOP__0\n"); );
    // Init
    SData/*14:0*/ __Vdly__SawToothWaveGenerator__DOT__sawtooth;
    CData/*0:0*/ __Vdly__SawToothWaveGenerator__DOT__isRunning;
    // Body
    __Vdly__SawToothWaveGenerator__DOT__isRunning = vlSelf->SawToothWaveGenerator__DOT__isRunning;
    __Vdly__SawToothWaveGenerator__DOT__sawtooth = vlSelf->SawToothWaveGenerator__DOT__sawtooth;
    if (vlSelf->reset) {
        __Vdly__SawToothWaveGenerator__DOT__sawtooth = 0U;
        __Vdly__SawToothWaveGenerator__DOT__isRunning = 0U;
        vlSelf->SawToothWaveGenerator__DOT__isRunning 
            = __Vdly__SawToothWaveGenerator__DOT__isRunning;
        vlSelf->SawToothWaveGenerator__DOT__sawtooth 
            = __Vdly__SawToothWaveGenerator__DOT__sawtooth;
        vlSelf->io_output = vlSelf->SawToothWaveGenerator__DOT__sawtooth;
        vlSelf->SawToothWaveGenerator__DOT__step = 0U;
    } else {
        __Vdly__SawToothWaveGenerator__DOT__isRunning 
            = ((~ (((IData)(vlSelf->SawToothWaveGenerator__DOT__init) 
                    & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__init_regNext))) 
                   | ((IData)(vlSelf->SawToothWaveGenerator__DOT__stop) 
                      & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__stop_regNext))))) 
               & (((IData)(vlSelf->SawToothWaveGenerator__DOT__start) 
                   & (~ (IData)(vlSelf->SawToothWaveGenerator__DOT__start_regNext))) 
                  | (IData)(vlSelf->SawToothWaveGenerator__DOT__isRunning)));
        if (vlSelf->SawToothWaveGenerator__DOT__init) {
            __Vdly__SawToothWaveGenerator__DOT__sawtooth = 0U;
        }
        if (vlSelf->SawToothWaveGenerator__DOT__isRunning) {
            __Vdly__SawToothWaveGenerator__DOT__sawtooth 
                = (0x7fffU & ((IData)(vlSelf->io_direction)
                               ? ((IData)(vlSelf->SawToothWaveGenerator__DOT__sawtooth) 
                                  + (IData)(vlSelf->SawToothWaveGenerator__DOT__step))
                               : ((IData)(vlSelf->SawToothWaveGenerator__DOT__sawtooth) 
                                  - (IData)(vlSelf->SawToothWaveGenerator__DOT__step))));
        }
        vlSelf->SawToothWaveGenerator__DOT__isRunning 
            = __Vdly__SawToothWaveGenerator__DOT__isRunning;
        vlSelf->SawToothWaveGenerator__DOT__sawtooth 
            = __Vdly__SawToothWaveGenerator__DOT__sawtooth;
        vlSelf->io_output = vlSelf->SawToothWaveGenerator__DOT__sawtooth;
        vlSelf->SawToothWaveGenerator__DOT__step = vlSelf->io_step;
    }
}

VL_INLINE_OPT void VSawToothWaveGenerator___024root___sequent__TOP__1(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->SawToothWaveGenerator__DOT__start_regNext 
        = vlSelf->SawToothWaveGenerator__DOT__start;
    vlSelf->SawToothWaveGenerator__DOT__stop_regNext 
        = vlSelf->SawToothWaveGenerator__DOT__stop;
    vlSelf->SawToothWaveGenerator__DOT__init_regNext 
        = vlSelf->SawToothWaveGenerator__DOT__init;
}

VL_INLINE_OPT void VSawToothWaveGenerator___024root___sequent__TOP__2(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->SawToothWaveGenerator__DOT__start = ((~ (IData)(vlSelf->reset)) 
                                                 & (IData)(vlSelf->io_start));
    vlSelf->SawToothWaveGenerator__DOT__stop = ((~ (IData)(vlSelf->reset)) 
                                                & (IData)(vlSelf->io_stop));
    vlSelf->SawToothWaveGenerator__DOT__init = ((~ (IData)(vlSelf->reset)) 
                                                & (IData)(vlSelf->io_init));
}

void VSawToothWaveGenerator___024root___eval(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        VSawToothWaveGenerator___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VSawToothWaveGenerator___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        VSawToothWaveGenerator___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

#ifdef VL_DEBUG
void VSawToothWaveGenerator___024root___eval_debug_assertions(VSawToothWaveGenerator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSawToothWaveGenerator___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->io_direction & 0xfeU))) {
        Verilated::overWidthError("io_direction");}
    if (VL_UNLIKELY((vlSelf->io_start & 0xfeU))) {
        Verilated::overWidthError("io_start");}
    if (VL_UNLIKELY((vlSelf->io_stop & 0xfeU))) {
        Verilated::overWidthError("io_stop");}
    if (VL_UNLIKELY((vlSelf->io_init & 0xfeU))) {
        Verilated::overWidthError("io_init");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
