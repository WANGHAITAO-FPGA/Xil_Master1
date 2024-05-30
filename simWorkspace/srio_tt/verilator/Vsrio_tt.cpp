// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsrio_tt.h"
#include "Vsrio_tt__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsrio_tt::Vsrio_tt(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vsrio_tt__Syms(_vcontextp__, _vcname__, this)}
    , srio_clk{vlSymsp->TOP.srio_clk}
    , reset{vlSymsp->TOP.reset}
    , iresp_stream_valid{vlSymsp->TOP.iresp_stream_valid}
    , iresp_stream_ready{vlSymsp->TOP.iresp_stream_ready}
    , iresp_stream_payload{vlSymsp->TOP.iresp_stream_payload}
    , rootp{&(vlSymsp->TOP)}
{
}

Vsrio_tt::Vsrio_tt(const char* _vcname__)
    : Vsrio_tt(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vsrio_tt::~Vsrio_tt() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsrio_tt___024root___eval_initial(Vsrio_tt___024root* vlSelf);
void Vsrio_tt___024root___eval_settle(Vsrio_tt___024root* vlSelf);
void Vsrio_tt___024root___eval(Vsrio_tt___024root* vlSelf);
#ifdef VL_DEBUG
void Vsrio_tt___024root___eval_debug_assertions(Vsrio_tt___024root* vlSelf);
#endif  // VL_DEBUG
void Vsrio_tt___024root___final(Vsrio_tt___024root* vlSelf);

static void _eval_initial_loop(Vsrio_tt__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsrio_tt___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsrio_tt___024root___eval_settle(&(vlSymsp->TOP));
        Vsrio_tt___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsrio_tt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsrio_tt::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsrio_tt___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsrio_tt___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vsrio_tt::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vsrio_tt::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsrio_tt::final() {
    Vsrio_tt___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vsrio_tt___024root__trace_init_top(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsrio_tt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsrio_tt___024root*>(voidSelf);
    Vsrio_tt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsrio_tt___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsrio_tt___024root__trace_register(Vsrio_tt___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsrio_tt::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsrio_tt___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
