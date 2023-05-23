// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VGRATING_RULER_H_
#define _VGRATING_RULER_H_  // guard

#include "verilated.h"

//==========

class VGrating_Ruler__Syms;
class VGrating_Ruler_VerilatedVcd;


//----------

VL_MODULE(VGrating_Ruler) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(config_valid,0,0);
    VL_IN8(config_payload_mode,1,0);
    VL_IN8(grating_io_IO_A_READ,0,0);
    VL_OUT8(grating_io_IO_A_WRITE,0,0);
    VL_OUT8(grating_io_IO_A_WRITEENABLE,0,0);
    VL_IN8(grating_io_IO_B_READ,0,0);
    VL_OUT8(grating_io_IO_B_WRITE,0,0);
    VL_OUT8(grating_io_IO_B_WRITEENABLE,0,0);
    VL_IN8(grating_io_IO_C_READ,0,0);
    VL_OUT8(grating_io_IO_C_WRITE,0,0);
    VL_OUT8(grating_io_IO_C_WRITEENABLE,0,0);
    VL_IN8(bissc_clk,0,0);
    VL_OUT8(bissc_data,0,0);
    VL_OUT8(encoder_aphase,0,0);
    VL_OUT8(encoder_bphase,0,0);
    VL_OUT8(encoder_iphase,0,0);
    VL_IN8(endat_clk,0,0);
    VL_OUT8(endat_read,0,0);
    VL_IN8(endat_write,0,0);
    VL_IN8(endat_writeEnable,0,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VGrating_Ruler__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VGrating_Ruler);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VGrating_Ruler(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VGrating_Ruler();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VGrating_Ruler__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VGrating_Ruler__Syms* symsp, bool first);
  private:
    static QData _change_request(VGrating_Ruler__Syms* __restrict vlSymsp);
    static QData _change_request_1(VGrating_Ruler__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(VGrating_Ruler__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VGrating_Ruler__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VGrating_Ruler__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VGrating_Ruler__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VGrating_Ruler__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VGrating_Ruler__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
