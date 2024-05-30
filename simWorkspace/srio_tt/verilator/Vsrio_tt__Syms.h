// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSRIO_TT__SYMS_H_
#define VERILATED_VSRIO_TT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsrio_tt.h"

// INCLUDE MODULE CLASSES
#include "Vsrio_tt___024root.h"

// SYMS CLASS (contains all model state)
class Vsrio_tt__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsrio_tt* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsrio_tt___024root             TOP;

    // CONSTRUCTORS
    Vsrio_tt__Syms(VerilatedContext* contextp, const char* namep, Vsrio_tt* modelp);
    ~Vsrio_tt__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
