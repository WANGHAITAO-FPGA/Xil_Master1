// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSawToothWaveGenerator.h"
#include "VSawToothWaveGenerator__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSawToothWaveGenerator::VSawToothWaveGenerator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VSawToothWaveGenerator__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , io_direction{vlSymsp->TOP.io_direction}
    , io_step{vlSymsp->TOP.io_step}
    , io_start{vlSymsp->TOP.io_start}
    , io_stop{vlSymsp->TOP.io_stop}
    , io_init{vlSymsp->TOP.io_init}
    , io_output{vlSymsp->TOP.io_output}
    , rootp{&(vlSymsp->TOP)}
{
}

VSawToothWaveGenerator::VSawToothWaveGenerator(const char* _vcname__)
    : VSawToothWaveGenerator(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VSawToothWaveGenerator::~VSawToothWaveGenerator() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VSawToothWaveGenerator___024root___eval_initial(VSawToothWaveGenerator___024root* vlSelf);
void VSawToothWaveGenerator___024root___eval_settle(VSawToothWaveGenerator___024root* vlSelf);
void VSawToothWaveGenerator___024root___eval(VSawToothWaveGenerator___024root* vlSelf);
#ifdef VL_DEBUG
void VSawToothWaveGenerator___024root___eval_debug_assertions(VSawToothWaveGenerator___024root* vlSelf);
#endif  // VL_DEBUG
void VSawToothWaveGenerator___024root___final(VSawToothWaveGenerator___024root* vlSelf);

static void _eval_initial_loop(VSawToothWaveGenerator__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VSawToothWaveGenerator___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VSawToothWaveGenerator___024root___eval_settle(&(vlSymsp->TOP));
        VSawToothWaveGenerator___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VSawToothWaveGenerator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSawToothWaveGenerator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSawToothWaveGenerator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VSawToothWaveGenerator___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VSawToothWaveGenerator::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VSawToothWaveGenerator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VSawToothWaveGenerator::final() {
    VSawToothWaveGenerator___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void VSawToothWaveGenerator___024root__trace_init_top(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSawToothWaveGenerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSawToothWaveGenerator___024root*>(voidSelf);
    VSawToothWaveGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VSawToothWaveGenerator___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VSawToothWaveGenerator___024root__trace_register(VSawToothWaveGenerator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSawToothWaveGenerator::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSawToothWaveGenerator___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
