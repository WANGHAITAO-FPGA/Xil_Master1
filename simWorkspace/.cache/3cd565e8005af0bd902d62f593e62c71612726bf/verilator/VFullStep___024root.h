// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFullStep.h for the primary calling header

#ifndef VERILATED_VFULLSTEP___024ROOT_H_
#define VERILATED_VFULLSTEP___024ROOT_H_  // guard

#include "verilated.h"

class VFullStep__Syms;
VL_MODULE(VFullStep___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ FullStep__DOT__when_FullStep_l70;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    VL_OUT16(c_data,15,0);
    VL_OUT16(d1_data,15,0);
    VL_OUT16(d2_data,15,0);
    SData/*15:0*/ FullStep__DOT____Vxrand_h96d11303__2;
    SData/*15:0*/ FullStep__DOT____Vxrand_h96d11303__1;
    SData/*15:0*/ FullStep__DOT____Vxrand_h96d11303__0;
    SData/*15:0*/ FullStep__DOT___zz_c_rom_port0;
    SData/*15:0*/ FullStep__DOT___zz_d1_rom_port0;
    SData/*15:0*/ FullStep__DOT___zz_d2_rom_port0;
    SData/*15:0*/ FullStep__DOT__Sample;
    SData/*8:0*/ FullStep__DOT__i;
    SData/*8:0*/ __Vdly__FullStep__DOT__i;
    VlUnpacked<SData/*15:0*/, 352> FullStep__DOT__c_rom;
    VlUnpacked<SData/*15:0*/, 352> FullStep__DOT__d1_rom;
    VlUnpacked<SData/*15:0*/, 352> FullStep__DOT__d2_rom;

    // INTERNAL VARIABLES
    VFullStep__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VFullStep___024root(const char* name);
    ~VFullStep___024root();
    VL_UNCOPYABLE(VFullStep___024root);

    // INTERNAL METHODS
    void __Vconfigure(VFullStep__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
