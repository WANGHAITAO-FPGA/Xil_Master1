// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFullStep.h for the primary calling header

#include "verilated.h"

#include "VFullStep__Syms.h"
#include "VFullStep___024root.h"

void VFullStep___024root___ctor_var_reset(VFullStep___024root* vlSelf);

VFullStep___024root::VFullStep___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VFullStep___024root___ctor_var_reset(this);
}

void VFullStep___024root::__Vconfigure(VFullStep__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VFullStep___024root::~VFullStep___024root() {
}
