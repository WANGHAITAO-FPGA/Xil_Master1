// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFullStep.h"
#include "VFullStep__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VFullStep::VFullStep(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VFullStep__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , c_data{vlSymsp->TOP.c_data}
    , d1_data{vlSymsp->TOP.d1_data}
    , d2_data{vlSymsp->TOP.d2_data}
    , rootp{&(vlSymsp->TOP)}
{
}

VFullStep::VFullStep(const char* _vcname__)
    : VFullStep(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VFullStep::~VFullStep() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VFullStep___024root___eval_initial(VFullStep___024root* vlSelf);
void VFullStep___024root___eval_settle(VFullStep___024root* vlSelf);
void VFullStep___024root___eval(VFullStep___024root* vlSelf);
#ifdef VL_DEBUG
void VFullStep___024root___eval_debug_assertions(VFullStep___024root* vlSelf);
#endif  // VL_DEBUG
void VFullStep___024root___final(VFullStep___024root* vlSelf);

static void _eval_initial_loop(VFullStep__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VFullStep___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VFullStep___024root___eval_settle(&(vlSymsp->TOP));
        VFullStep___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VFullStep::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFullStep::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFullStep___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VFullStep___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VFullStep::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VFullStep::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VFullStep::final() {
    VFullStep___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void VFullStep___024root__trace_init_top(VFullStep___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFullStep___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFullStep___024root*>(voidSelf);
    VFullStep__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VFullStep___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VFullStep___024root__trace_register(VFullStep___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VFullStep::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VFullStep___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
