// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSawToothWaveGenerator.h for the primary calling header

#ifndef VERILATED_VSAWTOOTHWAVEGENERATOR___024ROOT_H_
#define VERILATED_VSAWTOOTHWAVEGENERATOR___024ROOT_H_  // guard

#include "verilated.h"

class VSawToothWaveGenerator__Syms;
VL_MODULE(VSawToothWaveGenerator___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_direction,0,0);
    VL_IN8(io_step,7,0);
    VL_IN8(io_start,0,0);
    VL_IN8(io_stop,0,0);
    VL_IN8(io_init,0,0);
    CData/*7:0*/ SawToothWaveGenerator__DOT__step;
    CData/*0:0*/ SawToothWaveGenerator__DOT__isRunning;
    CData/*0:0*/ SawToothWaveGenerator__DOT__start;
    CData/*0:0*/ SawToothWaveGenerator__DOT__stop;
    CData/*0:0*/ SawToothWaveGenerator__DOT__init;
    CData/*0:0*/ SawToothWaveGenerator__DOT__init_regNext;
    CData/*0:0*/ SawToothWaveGenerator__DOT__stop_regNext;
    CData/*0:0*/ SawToothWaveGenerator__DOT__start_regNext;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    VL_OUT16(io_output,14,0);
    SData/*14:0*/ SawToothWaveGenerator__DOT__sawtooth;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VSawToothWaveGenerator__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VSawToothWaveGenerator___024root(const char* name);
    ~VSawToothWaveGenerator___024root();
    VL_UNCOPYABLE(VSawToothWaveGenerator___024root);

    // INTERNAL METHODS
    void __Vconfigure(VSawToothWaveGenerator__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
