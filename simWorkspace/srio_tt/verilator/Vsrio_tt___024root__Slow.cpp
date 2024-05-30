// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsrio_tt.h for the primary calling header

#include "verilated.h"

#include "Vsrio_tt__Syms.h"
#include "Vsrio_tt___024root.h"

void Vsrio_tt___024root___ctor_var_reset(Vsrio_tt___024root* vlSelf);

Vsrio_tt___024root::Vsrio_tt___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vsrio_tt___024root___ctor_var_reset(this);
}

void Vsrio_tt___024root::__Vconfigure(Vsrio_tt__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vsrio_tt___024root::~Vsrio_tt___024root() {
}
