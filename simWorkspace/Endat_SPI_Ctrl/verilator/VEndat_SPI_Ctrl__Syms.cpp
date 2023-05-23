// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VEndat_SPI_Ctrl__Syms.h"
#include "VEndat_SPI_Ctrl.h"



// FUNCTIONS
VEndat_SPI_Ctrl__Syms::VEndat_SPI_Ctrl__Syms(VEndat_SPI_Ctrl* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
