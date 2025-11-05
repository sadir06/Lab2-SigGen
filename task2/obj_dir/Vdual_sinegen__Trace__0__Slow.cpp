// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdual_sinegen__Syms.h"


VL_ATTR_COLD void Vdual_sinegen___024root__trace_init_sub__TOP__0(Vdual_sinegen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"offset", false,-1, 7,0);
    tracep->declBus(c+5,"dout1", false,-1, 7,0);
    tracep->declBus(c+6,"dout2", false,-1, 7,0);
    tracep->pushNamePrefix("dual_sinegen ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"offset", false,-1, 7,0);
    tracep->declBus(c+5,"dout1", false,-1, 7,0);
    tracep->declBus(c+6,"dout2", false,-1, 7,0);
    tracep->declBus(c+7,"counter_out", false,-1, 7,0);
    tracep->declBus(c+8,"offset_addr", false,-1, 7,0);
    tracep->pushNamePrefix("u_counter ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+9,"incr", false,-1, 7,0);
    tracep->declBus(c+7,"count", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_rom ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBus(c+7,"addr1", false,-1, 7,0);
    tracep->declBus(c+8,"addr2", false,-1, 7,0);
    tracep->declBus(c+5,"dout1", false,-1, 7,0);
    tracep->declBus(c+6,"dout2", false,-1, 7,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdual_sinegen___024root__trace_init_top(Vdual_sinegen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root__trace_init_top\n"); );
    // Body
    Vdual_sinegen___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdual_sinegen___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdual_sinegen___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdual_sinegen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdual_sinegen___024root__trace_register(Vdual_sinegen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdual_sinegen___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdual_sinegen___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdual_sinegen___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdual_sinegen___024root__trace_full_sub_0(Vdual_sinegen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdual_sinegen___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root__trace_full_top_0\n"); );
    // Init
    Vdual_sinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdual_sinegen___024root*>(voidSelf);
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdual_sinegen___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdual_sinegen___024root__trace_full_sub_0(Vdual_sinegen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_sinegen___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->en));
    bufp->fullCData(oldp+4,(vlSelf->offset),8);
    bufp->fullCData(oldp+5,(vlSelf->dout1),8);
    bufp->fullCData(oldp+6,(vlSelf->dout2),8);
    bufp->fullCData(oldp+7,(vlSelf->dual_sinegen__DOT__counter_out),8);
    bufp->fullCData(oldp+8,((0xffU & ((IData)(vlSelf->dual_sinegen__DOT__counter_out) 
                                      + (IData)(vlSelf->offset)))),8);
    bufp->fullCData(oldp+9,(1U),8);
}
