// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSPI_CTRL_H_
#define _VSPI_CTRL_H_  // guard

#include "verilated.h"

//==========

class VSPI_Ctrl__Syms;
class VSPI_Ctrl_VerilatedVcd;


//----------

VL_MODULE(VSPI_Ctrl) {
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
    VL_IN8(config_kind_cpol,0,0);
    VL_IN8(config_kind_cpha,0,0);
    VL_IN8(config_sclkToogle,7,0);
    VL_IN8(config_ss_activeHigh,0,0);
    VL_IN8(config_ss_setup,7,0);
    VL_IN8(config_ss_hold,7,0);
    VL_IN8(config_ss_disable,7,0);
    VL_IN8(cmd_valid,0,0);
    VL_OUT8(cmd_ready,0,0);
    VL_OUT8(rsp_valid,0,0);
    VL_IN8(rsp_ready,0,0);
    VL_IN16(cmd_payload,15,0);
    VL_OUT16(rsp_payload,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*6:0*/ SPI_Ctrl__DOT__wr_fifo_io_occupancy;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo_io_pop_valid;
    CData/*7:0*/ SPI_Ctrl__DOT__timer_counter;
    CData/*0:0*/ SPI_Ctrl__DOT__timer_reset;
    CData/*0:0*/ SPI_Ctrl__DOT__timer_ss_setupHit;
    CData/*0:0*/ SPI_Ctrl__DOT__timer_ss_holdHit;
    CData/*0:0*/ SPI_Ctrl__DOT__timer_ss_disableHit;
    CData/*0:0*/ SPI_Ctrl__DOT__timer_sclkToogleHit;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_ready;
    CData/*0:0*/ SPI_Ctrl__DOT__fsm_wantStart;
    CData/*0:0*/ SPI_Ctrl__DOT__fsm_counter_willIncrement;
    CData/*4:0*/ SPI_Ctrl__DOT__fsm_counter_valueNext;
    CData/*4:0*/ SPI_Ctrl__DOT__fsm_counter_value;
    CData/*0:0*/ SPI_Ctrl__DOT__fsm_ss;
    CData/*0:0*/ SPI_Ctrl__DOT___zz_spi_sclk;
    CData/*0:0*/ SPI_Ctrl__DOT___zz_spi_mosi;
    CData/*2:0*/ SPI_Ctrl__DOT__fsm_stateReg;
    CData/*2:0*/ SPI_Ctrl__DOT__fsm_stateNext;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT___zz_1;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_willIncrement;
    CData/*5:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_valueNext;
    CData/*5:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushPtr_value;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_willIncrement;
    CData/*5:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_valueNext;
    CData/*5:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_popPtr_value;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_ptrMatch;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_risingOccupancy;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_pushing;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_popping;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_full;
    CData/*0:0*/ SPI_Ctrl__DOT__wr_fifo__DOT___zz_io_pop_valid;
    CData/*5:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_pushPtr_valueNext;
    CData/*5:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_pushPtr_value;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_popPtr_willIncrement;
    CData/*5:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_popPtr_valueNext;
    CData/*5:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_popPtr_value;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_ptrMatch;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_risingOccupancy;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_popping;
    CData/*0:0*/ SPI_Ctrl__DOT__rd_fifo__DOT___zz_io_pop_valid;
    SData/*15:0*/ SPI_Ctrl__DOT__fsm_buffer;
    SData/*15:0*/ SPI_Ctrl__DOT__wr_fifo__DOT___zz_logic_ram_port0;
    SData/*15:0*/ SPI_Ctrl__DOT__rd_fifo__DOT___zz_logic_ram_port0;
    IData/*16:0*/ SPI_Ctrl__DOT___zz_fsm_buffer;
    WData/*87:0*/ SPI_Ctrl__DOT__fsm_stateReg_string[3];
    WData/*87:0*/ SPI_Ctrl__DOT__fsm_stateNext_string[3];
    SData/*15:0*/ SPI_Ctrl__DOT__wr_fifo__DOT__logic_ram[64];
    SData/*15:0*/ SPI_Ctrl__DOT__rd_fifo__DOT__logic_ram[64];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ __Vtableidx1;
    CData/*2:0*/ __Vtableidx2;
    CData/*2:0*/ __Vtableidx3;
    CData/*3:0*/ __Vtableidx4;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*31:0*/ __Vm_traceActivity;
    static WData/*87:0*/ __Vtable1_SPI_Ctrl__DOT__fsm_stateReg_string[8][3];
    static WData/*87:0*/ __Vtable2_SPI_Ctrl__DOT__fsm_stateNext_string[8][3];
    static CData/*0:0*/ __Vtable3_SPI_Ctrl__DOT__fsm_wantStart[8];
    static CData/*0:0*/ __Vtable4_SPI_Ctrl__DOT__fsm_counter_willIncrement[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSPI_Ctrl__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSPI_Ctrl);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSPI_Ctrl(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSPI_Ctrl();
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
    static void _eval_initial_loop(VSPI_Ctrl__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSPI_Ctrl__Syms* symsp, bool first);
  private:
    static QData _change_request(VSPI_Ctrl__Syms* __restrict vlSymsp);
    static QData _change_request_1(VSPI_Ctrl__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__5(VSPI_Ctrl__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSPI_Ctrl__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VSPI_Ctrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(VSPI_Ctrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VSPI_Ctrl__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(VSPI_Ctrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VSPI_Ctrl__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
