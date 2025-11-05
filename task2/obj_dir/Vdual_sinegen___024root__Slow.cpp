// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdual_sinegen.h for the primary calling header

#include "verilated.h"

#include "Vdual_sinegen__Syms.h"
#include "Vdual_sinegen___024root.h"

void Vdual_sinegen___024root___ctor_var_reset(Vdual_sinegen___024root* vlSelf);

Vdual_sinegen___024root::Vdual_sinegen___024root(Vdual_sinegen__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdual_sinegen___024root___ctor_var_reset(this);
}

void Vdual_sinegen___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vdual_sinegen___024root::~Vdual_sinegen___024root() {
}
