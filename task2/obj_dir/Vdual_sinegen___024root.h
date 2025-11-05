// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdual_sinegen.h for the primary calling header

#ifndef VERILATED_VDUAL_SINEGEN___024ROOT_H_
#define VERILATED_VDUAL_SINEGEN___024ROOT_H_  // guard

#include "verilated.h"

class Vdual_sinegen__Syms;

class Vdual_sinegen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_IN8(offset,7,0);
    VL_OUT8(dout1,7,0);
    VL_OUT8(dout2,7,0);
    CData/*7:0*/ dual_sinegen__DOT__counter_out;
    CData/*7:0*/ __Vdly__dual_sinegen__DOT__counter_out;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VlUnpacked<CData/*7:0*/, 256> dual_sinegen__DOT__u_rom__DOT__mem;

    // INTERNAL VARIABLES
    Vdual_sinegen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdual_sinegen___024root(Vdual_sinegen__Syms* symsp, const char* name);
    ~Vdual_sinegen___024root();
    VL_UNCOPYABLE(Vdual_sinegen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
