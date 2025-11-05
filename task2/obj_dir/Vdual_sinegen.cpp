// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdual_sinegen.h"
#include "Vdual_sinegen__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdual_sinegen::Vdual_sinegen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdual_sinegen__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , offset{vlSymsp->TOP.offset}
    , dout1{vlSymsp->TOP.dout1}
    , dout2{vlSymsp->TOP.dout2}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdual_sinegen::Vdual_sinegen(const char* _vcname__)
    : Vdual_sinegen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdual_sinegen::~Vdual_sinegen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdual_sinegen___024root___eval_initial(Vdual_sinegen___024root* vlSelf);
void Vdual_sinegen___024root___eval_settle(Vdual_sinegen___024root* vlSelf);
void Vdual_sinegen___024root___eval(Vdual_sinegen___024root* vlSelf);
#ifdef VL_DEBUG
void Vdual_sinegen___024root___eval_debug_assertions(Vdual_sinegen___024root* vlSelf);
#endif  // VL_DEBUG
void Vdual_sinegen___024root___final(Vdual_sinegen___024root* vlSelf);

static void _eval_initial_loop(Vdual_sinegen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdual_sinegen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdual_sinegen___024root___eval_settle(&(vlSymsp->TOP));
        Vdual_sinegen___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vdual_sinegen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdual_sinegen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdual_sinegen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdual_sinegen___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vdual_sinegen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdual_sinegen::final() {
    Vdual_sinegen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdual_sinegen::hierName() const { return vlSymsp->name(); }
const char* Vdual_sinegen::modelName() const { return "Vdual_sinegen"; }
unsigned Vdual_sinegen::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdual_sinegen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdual_sinegen___024root__trace_init_top(Vdual_sinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdual_sinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdual_sinegen___024root*>(voidSelf);
    Vdual_sinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdual_sinegen___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdual_sinegen___024root__trace_register(Vdual_sinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdual_sinegen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdual_sinegen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
