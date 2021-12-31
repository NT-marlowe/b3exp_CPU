// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

VL_CTOR_IMP(Vcpu) {
    Vcpu__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu__Syms(this, name());
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu::__Vconfigure(Vcpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcpu::~Vcpu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vcpu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu::eval\n"); );
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.v", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu::_eval_initial_loop(Vcpu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.v", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu::_initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__1\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*671:0*/ __Vtemp1[21];
    WData/*671:0*/ __Vtemp2[21];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x636f6465U;
    __Vtemp1[2U] = 0x7369732fU;
    __Vtemp1[3U] = 0x6e746865U;
    __Vtemp1[4U] = 0x725f5379U;
    __Vtemp1[5U] = 0x6b5f666fU;
    __Vtemp1[6U] = 0x656d6172U;
    __Vtemp1[7U] = 0x2f436f72U;
    __Vtemp1[8U] = 0x61726b73U;
    __Vtemp1[9U] = 0x6e63686dU;
    __Vtemp1[0xaU] = 0x702f6265U;
    __Vtemp1[0xbU] = 0x62336578U;
    __Vtemp1[0xcU] = 0x6b656e2fU;
    __Vtemp1[0xdU] = 0x5f6a696bU;
    __Vtemp1[0xeU] = 0x69726965U;
    __Vtemp1[0xfU] = 0x6163652fU;
    __Vtemp1[0x10U] = 0x726b5370U;
    __Vtemp1[0x11U] = 0x6f2f576fU;
    __Vtemp1[0x12U] = 0x64656e6aU;
    __Vtemp1[0x13U] = 0x6f6d652fU;
    __Vtemp1[0x14U] = 0x2f68U;
    VL_READMEM_N(true, 32, 24581, 0, VL_CVT_PACK_STR_NW(21, __Vtemp1)
                 , vlTOPp->cpu__DOT__F_stage0__DOT__inst_memory0__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x64617461U;
    __Vtemp2[2U] = 0x7369732fU;
    __Vtemp2[3U] = 0x6e746865U;
    __Vtemp2[4U] = 0x725f5379U;
    __Vtemp2[5U] = 0x6b5f666fU;
    __Vtemp2[6U] = 0x656d6172U;
    __Vtemp2[7U] = 0x2f436f72U;
    __Vtemp2[8U] = 0x61726b73U;
    __Vtemp2[9U] = 0x6e63686dU;
    __Vtemp2[0xaU] = 0x702f6265U;
    __Vtemp2[0xbU] = 0x62336578U;
    __Vtemp2[0xcU] = 0x6b656e2fU;
    __Vtemp2[0xdU] = 0x5f6a696bU;
    __Vtemp2[0xeU] = 0x69726965U;
    __Vtemp2[0xfU] = 0x6163652fU;
    __Vtemp2[0x10U] = 0x726b5370U;
    __Vtemp2[0x11U] = 0x6f2f576fU;
    __Vtemp2[0x12U] = 0x64656e6aU;
    __Vtemp2[0x13U] = 0x6f6d652fU;
    __Vtemp2[0x14U] = 0x2f68U;
    VL_READMEM_N(true, 32, 32781, 0, VL_CVT_PACK_STR_NW(21, __Vtemp2)
                 , vlTOPp->cpu__DOT__E_stage0__DOT__data_memory0__DOT__mem
                 , 0, ~VL_ULL(0));
}

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__sysclk = vlTOPp->sysclk;
}

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__sysclk = vlTOPp->sysclk;
}

void Vcpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::final\n"); );
    // Variables
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu::_eval_settle(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_settle\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vcpu::_change_request(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sysclk & 0xfeU))) {
        Verilated::overWidthError("sysclk");}
    if (VL_UNLIKELY((cpu_resetn & 0xfeU))) {
        Verilated::overWidthError("cpu_resetn");}
}
#endif  // VL_DEBUG

void Vcpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_ctor_var_reset\n"); );
    // Body
    sysclk = VL_RAND_RESET_I(1);
    cpu_resetn = VL_RAND_RESET_I(1);
    uart_rx_out = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<24581; ++__Vi0) {
            cpu__DOT__F_stage0__DOT__inst_memory0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32781; ++__Vi0) {
            cpu__DOT__E_stage0__DOT__data_memory0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
