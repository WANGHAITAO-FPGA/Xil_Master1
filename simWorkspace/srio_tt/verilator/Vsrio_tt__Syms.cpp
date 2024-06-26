// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsrio_tt__Syms.h"
#include "Vsrio_tt.h"
#include "Vsrio_tt___024root.h"

// FUNCTIONS
Vsrio_tt__Syms::~Vsrio_tt__Syms()
{
}

Vsrio_tt__Syms::Vsrio_tt__Syms(VerilatedContext* contextp, const char* namep,Vsrio_tt* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
