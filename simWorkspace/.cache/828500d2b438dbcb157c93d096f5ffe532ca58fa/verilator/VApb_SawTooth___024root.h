// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VApb_SawTooth.h for the primary calling header

#ifndef VERILATED_VAPB_SAWTOOTH___024ROOT_H_
#define VERILATED_VAPB_SAWTOOTH___024ROOT_H_  // guard

#include "verilated.h"

class VApb_SawTooth__Syms;
VL_MODULE(VApb_SawTooth___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(reset,0,0);
        VL_IN8(clk,0,0);
        VL_IN8(apb_PADDR,7,0);
        VL_IN8(apb_PSEL,0,0);
        VL_IN8(apb_PENABLE,0,0);
        VL_OUT8(apb_PREADY,0,0);
        VL_IN8(apb_PWRITE,0,0);
        VL_OUT8(apb_PSLVERROR,0,0);
        VL_OUT8(ad5544_CS,0,0);
        VL_OUT8(ad5544_LDAC,0,0);
        VL_OUT8(ad5544_RS,0,0);
        VL_OUT8(ad5544_SCLK,0,0);
        VL_OUT8(ad5544_SDIN,0,0);
        CData/*0:0*/ Apb_SawTooth__DOT__bus_ctrl_doWrite;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_analog_mode_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__when_SawToothWaveGenerator_l113;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_1;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_1_1;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_2;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_1_2;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_2_1;
        CData/*0:0*/ Apb_SawTooth__DOT__bridge_triger_temp_delay_3;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_0_start_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_0_stop_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_0_init_driver;
        CData/*7:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_0_step_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_0_direction_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_1_start_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_1_stop_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_1_init_driver;
        CData/*7:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_1_step_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_1_direction_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_2_start_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_2_stop_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_2_init_driver;
        CData/*7:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_2_step_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_2_direction_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_3_start_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_3_stop_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_3_init_driver;
        CData/*7:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_3_step_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_sawtooth_io_3_direction_driver;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__trigger;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__tick;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__tick_delay_1;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__tick_delay_2;
        CData/*7:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__step;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__isRunning;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__start;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__stop;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__init;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__tick;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__init_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__stop_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__start_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__tick_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l54;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__when_SawToothWaveGenerator_l60;
        CData/*7:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__step;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__isRunning;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__start;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__stop;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__init;
    };
    struct {
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__tick;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__init_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__stop_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__start_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__tick_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__when_SawToothWaveGenerator_l54;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__when_SawToothWaveGenerator_l60;
        CData/*7:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__step;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__isRunning;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__start;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__stop;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__init;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__tick;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__init_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__stop_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__start_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__tick_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__when_SawToothWaveGenerator_l54;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__when_SawToothWaveGenerator_l60;
        CData/*7:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__step;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__isRunning;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__start;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__stop;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__init;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__tick;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__init_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__stop_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__start_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__tick_regNext;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__when_SawToothWaveGenerator_l54;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__when_SawToothWaveGenerator_l60;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544_AD5544_CS;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544_AD5544_LDAC;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544_AD5544_RS;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544_AD5544_SCLK;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544_AD5544_SDIN;
        CData/*3:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__channel;
        CData/*6:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__curr_state;
        CData/*6:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__next_state;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__ad5544_trig_reg1;
        CData/*0:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__ad5544_trig_reg2;
        CData/*0:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__isRunning;
        CData/*0:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__isRunning;
        CData/*0:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__isRunning;
        CData/*0:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__isRunning;
        CData/*3:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__channel;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__reset;
        VL_IN16(apb_PWDATA,15,0);
        VL_OUT16(apb_PRDATA,15,0);
        SData/*15:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_analog_setdata_0_driver;
        SData/*15:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_analog_setdata_1_driver;
        SData/*15:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_analog_setdata_2_driver;
        SData/*15:0*/ Apb_SawTooth__DOT__toplevel_ad5544_1_analog_setdata_3_driver;
        SData/*15:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__set_data_0;
        SData/*15:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__set_data_1;
        SData/*15:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__set_data_2;
        SData/*15:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__set_data_3;
        SData/*8:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__counter_valueNext;
        SData/*8:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__counter_value;
        SData/*14:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__sawtooth_1;
        SData/*14:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__sawtooth_1;
        SData/*14:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__sawtooth_1;
        SData/*14:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__sawtooth_1;
    };
    struct {
        SData/*9:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__cnt;
        SData/*14:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_0__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_1_1__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_2_1__DOT__sawtooth_1;
        SData/*14:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__sawtooth_1__DOT__sawtoothwavegenerator_3_1__DOT__sawtooth_1;
        SData/*9:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__cnt;
        IData/*17:0*/ Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__AD5544_SDIN_reg;
        IData/*17:0*/ __Vdly__Apb_SawTooth__DOT__ad5544_1__DOT__da5544__DOT__da5544__DOT__AD5544_SDIN_reg;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    VApb_SawTooth__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VApb_SawTooth___024root(const char* name);
    ~VApb_SawTooth___024root();
    VL_UNCOPYABLE(VApb_SawTooth___024root);

    // INTERNAL METHODS
    void __Vconfigure(VApb_SawTooth__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
