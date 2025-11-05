// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdual_sinegen.h for the primary calling header

#include "verilated.h"

#include "Vdual_sinegen___024root.h"

VL_INLINE_OPT void Vdual_sinegen___024root___sequent__TOP__0(Vdual_sinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__dual_sinegen__DOT__counter_out 
        = vlSelf->dual_sinegen__DOT__counter_out;
    if (vlSelf->rst) {
        vlSelf->__Vdly__dual_sinegen__DOT__counter_out = 0U;
    } else if (vlSelf->en) {
        vlSelf->__Vdly__dual_sinegen__DOT__counter_out 
            = (0xffU & ((IData)(1U) + (IData)(vlSelf->dual_sinegen__DOT__counter_out)));
    }
}

VL_INLINE_OPT void Vdual_sinegen___024root___sequent__TOP__1(Vdual_sinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->dout1 = vlSelf->dual_sinegen__DOT__u_rom__DOT__mem
        [vlSelf->dual_sinegen__DOT__counter_out];
    vlSelf->dout2 = vlSelf->dual_sinegen__DOT__u_rom__DOT__mem
        [(0xffU & ((IData)(vlSelf->dual_sinegen__DOT__counter_out) 
                   + (IData)(vlSelf->offset)))];
}

VL_INLINE_OPT void Vdual_sinegen___024root___sequent__TOP__2(Vdual_sinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->dual_sinegen__DOT__counter_out = vlSelf->__Vdly__dual_sinegen__DOT__counter_out;
}

void Vdual_sinegen___024root___eval(Vdual_sinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vdual_sinegen___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdual_sinegen___024root___sequent__TOP__1(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vdual_sinegen___024root___sequent__TOP__2(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vdual_sinegen___024root___eval_debug_assertions(Vdual_sinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
