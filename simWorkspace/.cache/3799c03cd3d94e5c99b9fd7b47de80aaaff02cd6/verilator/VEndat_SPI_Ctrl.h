// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VENDAT_SPI_CTRL_H_
#define _VENDAT_SPI_CTRL_H_  // guard

#include "verilated.h"

//==========

class VEndat_SPI_Ctrl__Syms;
class VEndat_SPI_Ctrl_VerilatedVcd;


//----------

VL_MODULE(VEndat_SPI_Ctrl) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(spi_ss,0,0);
    VL_OUT8(spi_sclk,0,0);
    VL_OUT8(spi_mosi,0,0);
    VL_IN8(spi_miso,0,0);
    VL_IN8(cmd_valid,0,0);
    VL_IN16(cmd_payload,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl_io_cmd_ready;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo_io_pop_valid;
    CData/*6:0*/ Endat_SPI_Ctrl__DOT__wr_fifo_io_occupancy;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__mode;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__index;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__valid;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__fsm_wantStart;
    CData/*2:0*/ Endat_SPI_Ctrl__DOT__fsm_stateReg;
    CData/*2:0*/ Endat_SPI_Ctrl__DOT__fsm_stateNext;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_reset;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_willIncrement;
    CData/*4:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_valueNext;
    CData/*4:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_counter_value;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_ss;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_io_rsp_valid;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__when_SpiMasterCtrl_l232;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_io_spi_sclk;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_io_spi_mosi;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT___zz_1;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement;
    CData/*5:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext;
    CData/*5:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_value;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement;
    CData/*5:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext;
    CData/*5:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_value;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_ptrMatch;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_risingOccupancy;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushing;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_popping;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_full;
    CData/*0:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT___zz_io_pop_valid;
    SData/*9:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__timer_counter;
    SData/*15:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT__fsm_buffer;
    SData/*15:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT___zz_logic_ram_port0;
    WData/*95:0*/ Endat_SPI_Ctrl__DOT__fsm_stateReg_string[3];
    WData/*95:0*/ Endat_SPI_Ctrl__DOT__fsm_stateNext_string[3];
    IData/*16:0*/ Endat_SPI_Ctrl__DOT__spictrl__DOT___zz_fsm_buffer;
    SData/*15:0*/ Endat_SPI_Ctrl__DOT__wr_fifo__DOT__logic_ram[64];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ __Vtableidx1;
    CData/*2:0*/ __Vtableidx2;
    CData/*2:0*/ __Vtableidx3;
    CData/*5:0*/ __Vtableidx4;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*31:0*/ __Vm_traceActivity;
    CData/*0:0*/ __Vtablechg5[16];
    static WData/*95:0*/ __Vtable1_Endat_SPI_Ctrl__DOT__fsm_stateReg_string[8][3];
    static WData/*95:0*/ __Vtable2_Endat_SPI_Ctrl__DOT__fsm_stateNext_string[8][3];
    static CData/*0:0*/ __Vtable3_Endat_SPI_Ctrl__DOT__fsm_wantStart[8];
    static CData/*2:0*/ __Vtable4_Endat_SPI_Ctrl__DOT__fsm_stateNext[64];
    static CData/*0:0*/ __Vtable5_Endat_SPI_Ctrl__DOT__mode[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VEndat_SPI_Ctrl__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VEndat_SPI_Ctrl);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VEndat_SPI_Ctrl(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VEndat_SPI_Ctrl();
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
    static void _eval_initial_loop(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VEndat_SPI_Ctrl__Syms* symsp, bool first);
  private:
    static QData _change_request(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
    static QData _change_request_1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__5(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__10(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VEndat_SPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
