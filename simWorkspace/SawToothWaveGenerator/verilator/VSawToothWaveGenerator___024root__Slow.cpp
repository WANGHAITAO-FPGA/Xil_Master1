// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSawToothWaveGenerator.h for the primary calling header

#include "verilated.h"

#include "VSawToothWaveGenerator__Syms.h"
#include "VSawToothWaveGenerator___024root.h"

void VSawToothWaveGenerator___024root___ctor_var_reset(VSawToothWaveGenerator___024root* vlSelf);

VSawToothWaveGenerator___024root::VSawToothWaveGenerator___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VSawToothWaveGenerator___024root___ctor_var_reset(this);
}

void VSawToothWaveGenerator___024root::__Vconfigure(VSawToothWaveGenerator__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VSawToothWaveGenerator___024root::~VSawToothWaveGenerator___024root() {
}
