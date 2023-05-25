// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSawToothTop.h for the primary calling header

#ifndef VERILATED_VSAWTOOTHTOP___024ROOT_H_
#define VERILATED_VSAWTOOTHTOP___024ROOT_H_  // guard

#include "verilated.h"

class VSawToothTop__Syms;
VL_MODULE(VSawToothTop___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(reset,0,0);
        VL_IN8(clk,0,0);
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__clk_out;
        VL_IN8(sawtooth_io_0_direction,0,0);
        VL_IN8(sawtooth_io_0_step,7,0);
        VL_IN8(sawtooth_io_0_start,0,0);
        VL_IN8(sawtooth_io_0_stop,0,0);
        VL_IN8(sawtooth_io_0_init,0,0);
        VL_IN8(sawtooth_io_1_direction,0,0);
        VL_IN8(sawtooth_io_1_step,7,0);
        VL_IN8(sawtooth_io_1_start,0,0);
        VL_IN8(sawtooth_io_1_stop,0,0);
        VL_IN8(sawtooth_io_1_init,0,0);
        VL_IN8(sawtooth_io_2_direction,0,0);
        VL_IN8(sawtooth_io_2_step,7,0);
        VL_IN8(sawtooth_io_2_start,0,0);
        VL_IN8(sawtooth_io_2_stop,0,0);
        VL_IN8(sawtooth_io_2_init,0,0);
        VL_IN8(sawtooth_io_3_direction,0,0);
        VL_IN8(sawtooth_io_3_step,7,0);
        VL_IN8(sawtooth_io_3_start,0,0);
        VL_IN8(sawtooth_io_3_stop,0,0);
        VL_IN8(sawtooth_io_3_init,0,0);
        VL_OUT8(ad5544_CS,0,0);
        VL_OUT8(ad5544_LDAC,0,0);
        VL_OUT8(ad5544_RS,0,0);
        VL_OUT8(ad5544_SCLK,0,0);
        VL_OUT8(ad5544_SDIN,0,0);
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__tick;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__tick_delay_1;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__tick_delay_2;
        CData/*7:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__step;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__isRunning;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__start;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__stop;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__init;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__tick;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__init_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__stop_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__start_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__tick_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l52;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l58;
        CData/*7:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__step;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__isRunning;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__start;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__stop;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__init;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__tick;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__init_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__stop_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__start_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__tick_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__when_SawToothWaveGenerator_l52;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__when_SawToothWaveGenerator_l58;
        CData/*7:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__step;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__isRunning;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__start;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__stop;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__init;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__tick;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__init_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__stop_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__start_regNext;
    };
    struct {
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__tick_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__when_SawToothWaveGenerator_l52;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__when_SawToothWaveGenerator_l58;
        CData/*7:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__step;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__isRunning;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__start;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__stop;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__init;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__tick;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__init_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__stop_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__start_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__tick_regNext;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__when_SawToothWaveGenerator_l52;
        CData/*0:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__when_SawToothWaveGenerator_l58;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544_AD5544_CS;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544_AD5544_LDAC;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544_AD5544_RS;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544_AD5544_SCLK;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544_AD5544_SDIN;
        CData/*3:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__channel;
        CData/*6:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__curr_state;
        CData/*6:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__next_state;
        CData/*3:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__clk_dvidecnt;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__ad5544_trig_reg1;
        CData/*0:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__ad5544_trig_reg2;
        CData/*3:0*/ __Vdly__SawToothTop__DOT__da5544__DOT__da5544__DOT__channel;
        CData/*0:0*/ __VinpClk__TOP__SawToothTop__DOT__da5544__DOT__da5544__DOT__clk_out;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__reset;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__SawToothTop__DOT__da5544__DOT__da5544__DOT__clk_out;
        CData/*0:0*/ __Vchglast__TOP__SawToothTop__DOT__da5544__DOT__da5544__DOT__clk_out;
        SData/*8:0*/ SawToothTop__DOT__sawtooth_1__DOT__counter_valueNext;
        SData/*8:0*/ SawToothTop__DOT__sawtooth_1__DOT__counter_value;
        SData/*14:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__sawtooth_1;
        SData/*14:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__sawtooth_1;
        SData/*14:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__sawtooth_1;
        SData/*14:0*/ SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__sawtooth_1;
        SData/*9:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__cnt;
        SData/*14:0*/ __Vdly__SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__SawToothTop__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__sawtooth_1;
        SData/*9:0*/ __Vdly__SawToothTop__DOT__da5544__DOT__da5544__DOT__cnt;
        IData/*17:0*/ SawToothTop__DOT__da5544__DOT__da5544__DOT__AD5544_SDIN_reg;
        IData/*17:0*/ __Vdly__SawToothTop__DOT__da5544__DOT__da5544__DOT__AD5544_SDIN_reg;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    VSawToothTop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VSawToothTop___024root(const char* name);
    ~VSawToothTop___024root();
    VL_UNCOPYABLE(VSawToothTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(VSawToothTop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
