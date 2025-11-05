// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDUAL_SINEGEN__SYMS_H_
#define VERILATED_VDUAL_SINEGEN__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdual_sinegen.h"

// INCLUDE MODULE CLASSES
#include "Vdual_sinegen___024root.h"

// SYMS CLASS (contains all model state)
class Vdual_sinegen__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdual_sinegen* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdual_sinegen___024root        TOP;

    // CONSTRUCTORS
    Vdual_sinegen__Syms(VerilatedContext* contextp, const char* namep, Vdual_sinegen* modelp);
    ~Vdual_sinegen__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
