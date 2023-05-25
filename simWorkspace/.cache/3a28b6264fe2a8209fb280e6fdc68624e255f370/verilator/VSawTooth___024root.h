// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSawTooth.h for the primary calling header

#ifndef VERILATED_VSAWTOOTH___024ROOT_H_
#define VERILATED_VSAWTOOTH___024ROOT_H_  // guard

#include "verilated.h"

class VSawTooth__Syms;
VL_MODULE(VSawTooth___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(sawtooth_io_0_direction,0,0);
    VL_IN8(sawtooth_io_0_step,7,0);
    VL_IN8(sawtooth_io_0_start,0,0);
    VL_IN8(sawtooth_io_0_stop,0,0);
    VL_IN8(sawtooth_io_0_init,0,0);
    VL_OUT8(sawtooth_data_valid,0,0);
    CData/*7:0*/ SawTooth__DOT__counter_valueNext;
    CData/*7:0*/ SawTooth__DOT__counter_value;
    CData/*0:0*/ SawTooth__DOT__tick;
    CData/*0:0*/ SawTooth__DOT__tick_delay_1;
    CData/*0:0*/ SawTooth__DOT__tick_delay_2;
    CData/*7:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__step;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__isRunning;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__start;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__stop;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__init;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__tick;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__init_regNext;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__stop_regNext;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__start_regNext;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__tick_regNext;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l52;
    CData/*0:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l58;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    VL_OUT16(sawtooth_data_payload_data_0,15,0);
    SData/*14:0*/ SawTooth__DOT__sawtoothwavegenerator_0__DOT__sawtooth_1;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VSawTooth__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VSawTooth___024root(const char* name);
    ~VSawTooth___024root();
    VL_UNCOPYABLE(VSawTooth___024root);

    // INTERNAL METHODS
    void __Vconfigure(VSawTooth__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
