// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFullStep.h for the primary calling header

#include "verilated.h"

#include "VFullStep___024root.h"

VL_INLINE_OPT void VFullStep___024root___sequent__TOP__0(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__FullStep__DOT__i = vlSelf->FullStep__DOT__i;
    vlSelf->__Vdly__FullStep__DOT__i = ((IData)(vlSelf->reset)
                                         ? 0U : ((IData)(vlSelf->FullStep__DOT__when_FullStep_l70)
                                                  ? 
                                                 (0x1ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->FullStep__DOT__i)))
                                                  : 0U));
}

VL_INLINE_OPT void VFullStep___024root___sequent__TOP__1(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___sequent__TOP__1\n"); );
    // Body
    if ((0x15fU >= (IData)(vlSelf->FullStep__DOT__i))) {
        vlSelf->FullStep__DOT___zz_c_rom_port0 = vlSelf->FullStep__DOT__c_rom
            [vlSelf->FullStep__DOT__i];
        vlSelf->FullStep__DOT___zz_d1_rom_port1 = vlSelf->FullStep__DOT__d1_rom
            [vlSelf->FullStep__DOT__i];
        vlSelf->FullStep__DOT___zz_d1_rom_port0 = vlSelf->FullStep__DOT__d1_rom
            [vlSelf->FullStep__DOT__i];
    } else {
        vlSelf->FullStep__DOT___zz_c_rom_port0 = vlSelf->FullStep__DOT____Vxrand_h96d11303__0;
        vlSelf->FullStep__DOT___zz_d1_rom_port1 = vlSelf->FullStep__DOT____Vxrand_h96d11303__2;
        vlSelf->FullStep__DOT___zz_d1_rom_port0 = vlSelf->FullStep__DOT____Vxrand_h96d11303__1;
    }
    vlSelf->c_data = vlSelf->FullStep__DOT___zz_c_rom_port0;
    vlSelf->d2_data = (0xffffU & VL_MULS_III(17, (IData)(0x1ffffU), 
                                             (0x1ffffU 
                                              & VL_EXTENDS_II(17,16, (IData)(vlSelf->FullStep__DOT___zz_d1_rom_port1)))));
    vlSelf->d1_data = vlSelf->FullStep__DOT___zz_d1_rom_port0;
}

VL_INLINE_OPT void VFullStep___024root___sequent__TOP__2(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->FullStep__DOT__i = vlSelf->__Vdly__FullStep__DOT__i;
    vlSelf->FullStep__DOT__when_FullStep_l70 = (0x15fU 
                                                > (IData)(vlSelf->FullStep__DOT__i));
}

void VFullStep___024root___eval(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        VFullStep___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VFullStep___024root___sequent__TOP__1(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        VFullStep___024root___sequent__TOP__2(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

#ifdef VL_DEBUG
void VFullStep___024root___eval_debug_assertions(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
