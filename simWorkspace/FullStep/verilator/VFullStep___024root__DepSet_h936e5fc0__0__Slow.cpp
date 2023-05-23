// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFullStep.h for the primary calling header

#include "verilated.h"

#include "VFullStep___024root.h"

extern const VlWide<15>/*479:0*/ VFullStep__ConstPool__CONST_hcecb7db8_0;
extern const VlWide<15>/*479:0*/ VFullStep__ConstPool__CONST_h74f3d68a_0;

VL_ATTR_COLD void VFullStep___024root___initial__TOP__0(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->FullStep__DOT____Vxrand_h96d11303__2 = 
        (0xffffU & VL_RAND_RESET_I(16));
    vlSelf->FullStep__DOT____Vxrand_h96d11303__1 = 
        (0xffffU & VL_RAND_RESET_I(16));
    vlSelf->FullStep__DOT____Vxrand_h96d11303__0 = 
        (0xffffU & VL_RAND_RESET_I(16));
    VL_READMEM_N(false, 16, 352, 0, VL_CVT_PACK_STR_NW(15, VFullStep__ConstPool__CONST_hcecb7db8_0)
                 ,  &(vlSelf->FullStep__DOT__c_rom)
                 , 0, ~0ULL);
    VL_READMEM_N(false, 16, 352, 0, VL_CVT_PACK_STR_NW(15, VFullStep__ConstPool__CONST_h74f3d68a_0)
                 ,  &(vlSelf->FullStep__DOT__d1_rom)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VFullStep___024root___settle__TOP__0(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->FullStep__DOT__when_FullStep_l70 = (0x15fU 
                                                > (IData)(vlSelf->FullStep__DOT__i));
    vlSelf->c_data = vlSelf->FullStep__DOT___zz_c_rom_port0;
    vlSelf->d1_data = vlSelf->FullStep__DOT___zz_d1_rom_port0;
    vlSelf->d2_data = (0xffffU & VL_MULS_III(17, (IData)(0x1ffffU), 
                                             (0x1ffffU 
                                              & VL_EXTENDS_II(17,16, (IData)(vlSelf->FullStep__DOT___zz_d1_rom_port1)))));
}

VL_ATTR_COLD void VFullStep___024root___eval_initial(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = (1U & (~ (IData)(vlSelf->clk)));
    vlSelf->__Vclklast__TOP__reset = (1U & (~ (IData)(vlSelf->reset)));
    VFullStep___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void VFullStep___024root___eval_settle(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___eval_settle\n"); );
    // Body
    VFullStep___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VFullStep___024root___final(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___final\n"); );
}

VL_ATTR_COLD void VFullStep___024root___ctor_var_reset(VFullStep___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFullStep___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->c_data = VL_RAND_RESET_I(16);
    vlSelf->d1_data = VL_RAND_RESET_I(16);
    vlSelf->d2_data = VL_RAND_RESET_I(16);
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->FullStep__DOT____Vxrand_h96d11303__2 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT____Vxrand_h96d11303__1 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT____Vxrand_h96d11303__0 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT___zz_c_rom_port0 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT___zz_d1_rom_port0 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT___zz_d1_rom_port1 = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT__Sample = VL_RAND_RESET_I(16);
    vlSelf->FullStep__DOT__i = VL_RAND_RESET_I(9);
    vlSelf->FullStep__DOT__when_FullStep_l70 = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<352; ++__Vi0) {
        vlSelf->FullStep__DOT__c_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0=0; __Vi0<352; ++__Vi0) {
        vlSelf->FullStep__DOT__d1_rom[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__Vdly__FullStep__DOT__i = VL_RAND_RESET_I(9);
}
