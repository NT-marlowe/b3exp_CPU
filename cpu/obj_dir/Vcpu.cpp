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
            VL_FATAL_MT("cpu.v", 2, "",
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
            VL_FATAL_MT("cpu.v", 2, "",
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
    vlTOPp->cpu__DOT__register_file0__DOT__mem[0U] = 0U;
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
                 , vlTOPp->cpu__DOT__inst_memory__DOT__mem
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
                 , vlTOPp->cpu__DOT__data_memory0__DOT__mem
                 , 0, ~VL_ULL(0));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__2\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__cpu__DOT__uart_0__DOT__bitcount;
    SData/*8:0*/ __Vdly__cpu__DOT__uart_0__DOT__shifter;
    // Body
    __Vdly__cpu__DOT__uart_0__DOT__bitcount = vlTOPp->cpu__DOT__uart_0__DOT__bitcount;
    __Vdly__cpu__DOT__uart_0__DOT__shifter = vlTOPp->cpu__DOT__uart_0__DOT__shifter;
    vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles 
        = ((IData)(vlTOPp->cpu_resetn) ? ((IData)(1U) 
                                          + vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles)
            : 0U);
    if (vlTOPp->cpu_resetn) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(vlTOPp->cpu__DOT__uart_0__DOT__uart_busy)))) {
            __Vdly__cpu__DOT__uart_0__DOT__bitcount = 0xbU;
        }
        if (((IData)(vlTOPp->cpu__DOT__uart_0__DOT__sending) 
             & (~ (vlTOPp->cpu__DOT__uart_0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart_0__DOT__bitcount 
                = (0xfU & ((IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__cpu__DOT__uart_0__DOT__bitcount = 0U;
    }
    if (vlTOPp->cpu_resetn) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(
                                                             (0U 
                                                              != 
                                                              (7U 
                                                               & ((IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount) 
                                                                  >> 1U))))))) {
            __Vdly__cpu__DOT__uart_0__DOT__shifter 
                = (0x1feU & (vlTOPp->cpu__DOT__rs2_data 
                             << 1U));
        }
        if (((0U != (IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount)) 
             & (~ (vlTOPp->cpu__DOT__uart_0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart_0__DOT__shifter 
                = (0x100U | (0xffU & ((IData)(vlTOPp->cpu__DOT__uart_0__DOT__shifter) 
                                      >> 1U)));
            vlTOPp->cpu__DOT__uart_OUT_data = (1U & (IData)(vlTOPp->cpu__DOT__uart_0__DOT__shifter));
        }
    } else {
        __Vdly__cpu__DOT__uart_0__DOT__shifter = 0U;
        vlTOPp->cpu__DOT__uart_OUT_data = 1U;
    }
    vlTOPp->cpu__DOT__uart_0__DOT__shifter = __Vdly__cpu__DOT__uart_0__DOT__shifter;
    vlTOPp->cpu__DOT__uart_0__DOT__bitcount = __Vdly__cpu__DOT__uart_0__DOT__bitcount;
    vlTOPp->uart_rx_out = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart_0__DOT__uart_busy = (0U 
                                                != 
                                                (7U 
                                                 & ((IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount) 
                                                    >> 1U)));
    vlTOPp->cpu__DOT__uart_0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount));
    vlTOPp->cpu__DOT__uart_0__DOT__d = ((IData)(vlTOPp->cpu_resetn)
                                         ? vlTOPp->cpu__DOT__uart_0__DOT__dNxt
                                         : 0U);
    vlTOPp->cpu__DOT__uart_0__DOT__dNxt = (0x1fffffffU 
                                           & (vlTOPp->cpu__DOT__uart_0__DOT__d 
                                              + ((0x10000000U 
                                                  & vlTOPp->cpu__DOT__uart_0__DOT__d)
                                                  ? 0x1c200U
                                                  : 0xfa0be100U)));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__3(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__3\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v3;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v3;
    // Body
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v3 = 0U;
    vlTOPp->cpu__DOT__r_data_unprocessed = ((0x800cU 
                                             >= (0x7fffU 
                                                 & (vlTOPp->cpu__DOT__alu_result 
                                                    >> 2U)))
                                             ? vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                            [(0x7fffU 
                                              & (vlTOPp->cpu__DOT__alu_result 
                                                 >> 2U))]
                                             : 0U);
    if ((1U & (IData)(vlTOPp->cpu__DOT__we))) {
        vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound1 
            = (0xffU & vlTOPp->cpu__DOT__w_data_processed);
        if ((0x800cU >= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                                    >> 2U)))) {
            __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0 
                = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound1;
            __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0 = 1U;
            __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0 = 0U;
            __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0 
                = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                              >> 2U));
        }
    }
    if ((2U & (IData)(vlTOPp->cpu__DOT__we))) {
        vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound2 
            = (0xffU & (vlTOPp->cpu__DOT__w_data_processed 
                        >> 8U));
        if ((0x800cU >= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                                    >> 2U)))) {
            __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1 
                = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound2;
            __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1 = 1U;
            __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1 = 8U;
            __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1 
                = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                              >> 2U));
        }
    }
    if ((4U & (IData)(vlTOPp->cpu__DOT__we))) {
        vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound3 
            = (0xffU & (vlTOPp->cpu__DOT__w_data_processed 
                        >> 0x10U));
        if ((0x800cU >= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                                    >> 2U)))) {
            __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2 
                = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound3;
            __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2 = 1U;
            __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2 
                = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                              >> 2U));
        }
    }
    if ((8U & (IData)(vlTOPp->cpu__DOT__we))) {
        vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound4 
            = (0xffU & (vlTOPp->cpu__DOT__w_data_processed 
                        >> 0x18U));
        if ((0x800cU >= (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                                    >> 2U)))) {
            __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v3 
                = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound4;
            __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v3 = 1U;
            __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v3 
                = (0x7fffU & (vlTOPp->cpu__DOT__alu_result 
                              >> 2U));
        }
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0)));
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1)));
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v2))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v2)));
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v3) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v3))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v3)));
    }
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__4(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__4\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0;
    // Body
    __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0 = 0U;
    vlTOPp->cpu__DOT__pc = ((IData)(vlTOPp->cpu_resetn)
                             ? vlTOPp->cpu__DOT__npc
                             : 0x7ffcU);
    if (((IData)(vlTOPp->cpu__DOT__reg_we) & (0U != (IData)(vlTOPp->cpu__DOT__dstreg_num)))) {
        __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0 
            = vlTOPp->cpu__DOT__w_data;
        __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0 
            = vlTOPp->cpu__DOT__dstreg_num;
    }
    vlTOPp->cpu__DOT__ir = ((0x6004U >= (0x7fffU & 
                                         (vlTOPp->cpu__DOT__npc 
                                          >> 2U))) ? 
                            vlTOPp->cpu__DOT__inst_memory__DOT__mem
                            [(0x7fffU & (vlTOPp->cpu__DOT__npc 
                                         >> 2U))] : 0U);
    if (__Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0) {
        vlTOPp->cpu__DOT__register_file0__DOT__mem[__Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0] 
            = __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0;
    }
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                      ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                          ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 
                                                 (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                  >> 7U)
                                                  : 0U)
                                              : 0U)
                                          : 0U) : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                      >> 7U)
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)))
                         : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                   ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                       ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                     >> 7U)
                                                     : 0U)
                                                    : 0U))
                                       : 0U) : ((0x10U 
                                                 & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                 ? 
                                                ((8U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                    >> 7U)
                                                    : 0U)
                                                   : 0U))
                                                 : 
                                                ((8U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                     >> 7U)
                                                     : 0U)
                                                    : 0U)))))));
    vlTOPp->cpu__DOT__dstreg_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout;
    vlTOPp->cpu__DOT__is_store = (1U & ((~ (vlTOPp->cpu__DOT__ir 
                                            >> 6U)) 
                                        & ((vlTOPp->cpu__DOT__ir 
                                            >> 5U) 
                                           & ((~ (vlTOPp->cpu__DOT__ir 
                                                  >> 4U)) 
                                              & ((~ 
                                                  (vlTOPp->cpu__DOT__ir 
                                                   >> 3U)) 
                                                 & ((~ 
                                                     (vlTOPp->cpu__DOT__ir 
                                                      >> 2U)) 
                                                    & ((vlTOPp->cpu__DOT__ir 
                                                        >> 1U) 
                                                       & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->cpu__DOT__alucode = ((0x40U & vlTOPp->cpu__DOT__ir)
                                  ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x10U & vlTOPp->cpu__DOT__ir)
                                          ? 0x3fU : 
                                         ((8U & vlTOPp->cpu__DOT__ir)
                                           ? ((4U & vlTOPp->cpu__DOT__ir)
                                               ? ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 1U
                                                    : 0x3fU)
                                                   : 0x3fU)
                                               : 0x3fU)
                                           : ((4U & vlTOPp->cpu__DOT__ir)
                                               ? ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 2U
                                                    : 0x3fU)
                                                   : 0x3fU)
                                               : ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x4000U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 8U
                                                       : 7U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 6U
                                                       : 5U))
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 4U
                                                       : 3U)))
                                                    : 0x3fU)
                                                   : 0x3fU))))
                                      : 0x3fU) : ((0x20U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 0U
                                                        : 0x3fU)
                                                       : 0x3fU)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x17U
                                                           : 0x16U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x19U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x1aU
                                                             : 0x3fU))
                                                           : 0x15U))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x14U
                                                           : 0x13U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x18U
                                                           : 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x11U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x12U
                                                             : 0x3fU)))))
                                                        : 0x3fU)
                                                       : 0x3fU)))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__ir 
                                                             >> 0xcU)))
                                                         ? 0xeU
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__ir 
                                                              >> 0xcU)))
                                                          ? 0xfU
                                                          : 
                                                         ((2U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__ir 
                                                               >> 0xcU)))
                                                           ? 0x10U
                                                           : 0x3fU)))
                                                        : 0x3fU)
                                                       : 0x3fU))))
                                                   : 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 0x11U
                                                        : 0x3fU)
                                                       : 0x3fU)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x17U
                                                           : 0x16U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x19U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x1aU
                                                             : 0x3fU))
                                                           : 0x15U))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x14U
                                                           : 0x13U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x18U
                                                           : 0x11U)))
                                                        : 0x3fU)
                                                       : 0x3fU)))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 0x3fU
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0xdU
                                                           : 0xcU))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x3fU
                                                           : 0xbU)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0xaU
                                                           : 9U)))
                                                        : 0x3fU)
                                                       : 0x3fU))))));
    vlTOPp->cpu__DOT__aluop1_type = ((0x40U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                          ? ((0x10U 
                                              & vlTOPp->cpu__DOT__ir)
                                              ? 0U : 
                                             ((8U & vlTOPp->cpu__DOT__ir)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U))))
                                          : 0U) : (
                                                   (0x20U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))))
                                                    : 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))))));
    vlTOPp->cpu__DOT__aluop2_type = ((0x40U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                          ? ((0x10U 
                                              & vlTOPp->cpu__DOT__ir)
                                              ? 0U : 
                                             ((8U & vlTOPp->cpu__DOT__ir)
                                               ? ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 3U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)
                                               : ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 3U
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U))))
                                          : 0U) : (
                                                   (0x20U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U))))
                                                    : 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 3U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U))))));
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                      ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 
                                                   (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                    >> 0x14U)
                                                    : 0U)
                                                   : 0U))))
                         : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                   ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                       ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                           ? 0U : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                      >> 0x14U)
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                           ? 0U : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                      >> 0x14U)
                                                      : 0U)
                                                     : 0U))))
                                   : 0U)));
    vlTOPp->cpu__DOT__srcreg2_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                    ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                         ? ((0xfff00000U 
                                             & (VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                        >> 0x1fU)))) 
                                                << 0x14U)) 
                                            | ((0xff000U 
                                                & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir) 
                                               | ((0x800U 
                                                   & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                        >> 0x14U)))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0xfffff000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                               >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                         >> 0x14U)))
                                                   : 0U)
                                               : 0U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0xffffe000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                               >> 0x1fU)))) 
                                                       << 0xdU)) 
                                                   | ((0x1000U 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                          >> 0x13U)) 
                                                      | ((0x800U 
                                                          & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                             << 4U)) 
                                                         | ((0x7e0U 
                                                             & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                >> 0x14U)) 
                                                            | (0x1eU 
                                                               & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                  >> 7U))))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                   : 0U)
                                               : 0U)
                                           : 0U)) : 
                             ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                               ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                        ? 0U : ((2U 
                                                 & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                  ? 
                                                 ((0xfffff000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                              >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                   : 0U)
                                               : 0U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0x2000U 
                                                    & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                    ? 
                                                   ((0xfffff000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | (0xfffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                          >> 0x14U)))
                                                    : 
                                                   ((0x1000U 
                                                     & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                     ? 
                                                    ((0xffffffe0U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x18U)))) 
                                                         << 5U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))
                                                     : 
                                                    ((0xfffff000U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))))
                                                   : 0U)
                                               : 0U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                     ? 
                                                    ((0xfffff000U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->cpu__DOT__imm = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                      ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                   ? 
                                                  (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                   >> 0xfU)
                                                   : 0U)
                                               : 0U)))
                         : 0U) : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                   ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                     >> 0xfU)
                                                     : 0U)
                                                    : 0U)))
                                   : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                     >> 0xfU)
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->cpu__DOT__srcreg1_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout;
    vlTOPp->cpu__DOT__reg_we = (1U & ((0x40U & vlTOPp->cpu__DOT__ir)
                                       ? ((vlTOPp->cpu__DOT__ir 
                                           >> 5U) & 
                                          ((~ (vlTOPp->cpu__DOT__ir 
                                               >> 4U)) 
                                           & ((8U & vlTOPp->cpu__DOT__ir)
                                               ? ((vlTOPp->cpu__DOT__ir 
                                                   >> 2U) 
                                                  & ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & (vlTOPp->cpu__DOT__ir 
                                                        & (0U 
                                                           != (IData)(vlTOPp->cpu__DOT__dstreg_num)))))
                                               : ((vlTOPp->cpu__DOT__ir 
                                                   >> 2U) 
                                                  & ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & (vlTOPp->cpu__DOT__ir 
                                                        & (0U 
                                                           != (IData)(vlTOPp->cpu__DOT__dstreg_num))))))))
                                       : ((0x20U & vlTOPp->cpu__DOT__ir)
                                           ? ((vlTOPp->cpu__DOT__ir 
                                               >> 4U) 
                                              & ((~ 
                                                  (vlTOPp->cpu__DOT__ir 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     : 
                                                    ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & vlTOPp->cpu__DOT__ir))))
                                           : ((0x10U 
                                               & vlTOPp->cpu__DOT__ir)
                                               ? ((~ 
                                                   (vlTOPp->cpu__DOT__ir 
                                                    >> 3U)) 
                                                  & ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((vlTOPp->cpu__DOT__ir 
                                                       >> 1U) 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      : 
                                                     ((vlTOPp->cpu__DOT__ir 
                                                       >> 1U) 
                                                      & vlTOPp->cpu__DOT__ir)))
                                               : ((~ 
                                                   (vlTOPp->cpu__DOT__ir 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->cpu__DOT__ir 
                                                       >> 2U)) 
                                                     & ((vlTOPp->cpu__DOT__ir 
                                                         >> 1U) 
                                                        & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->cpu__DOT__rs2_data = vlTOPp->cpu__DOT__register_file0__DOT__mem
        [vlTOPp->cpu__DOT__srcreg2_num];
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                    ? 4U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                         ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                         : 4U) : 4U)
                                 : 4U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                                   : 4U)
                                               : 4U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                                   : 4U)
                                               : 4U))))
                : 4U) : 4U);
    vlTOPp->cpu__DOT__npc_op1 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout;
    vlTOPp->cpu__DOT__rs1_data = vlTOPp->cpu__DOT__register_file0__DOT__mem
        [vlTOPp->cpu__DOT__srcreg1_num];
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data 
        = vlTOPp->cpu__DOT__rs2_data;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type 
        = vlTOPp->cpu__DOT__aluop2_type;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout 
        = ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
            ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm)
            : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data
                : 0U));
    vlTOPp->cpu__DOT__alu_op2 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                    ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc
                    : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                        ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc
                        : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                                    ? vlTOPp->cpu__DOT__rs1_data
                                    : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
                                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
                            : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)))
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
            : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc);
    vlTOPp->cpu__DOT__npc_op2 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data 
        = vlTOPp->cpu__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type 
        = vlTOPp->cpu__DOT__aluop1_type;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout 
        = ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
            ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm)
            : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data
                : 0U));
    vlTOPp->cpu__DOT__alu_op1 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout;
    vlTOPp->cpu__DOT__br_taken = (1U & ((~ ((IData)(vlTOPp->cpu__DOT__alucode) 
                                            >> 5U)) 
                                        & ((~ ((IData)(vlTOPp->cpu__DOT__alucode) 
                                               >> 4U)) 
                                           & ((8U & (IData)(vlTOPp->cpu__DOT__alucode))
                                               ? ((~ 
                                                   ((IData)(vlTOPp->cpu__DOT__alucode) 
                                                    >> 2U)) 
                                                  & ((~ 
                                                      ((IData)(vlTOPp->cpu__DOT__alucode) 
                                                       >> 1U)) 
                                                     & ((~ (IData)(vlTOPp->cpu__DOT__alucode)) 
                                                        & (vlTOPp->cpu__DOT__alu_op1 
                                                           >= vlTOPp->cpu__DOT__alu_op2))))
                                               : ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     < vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    VL_GTES_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     != vlTOPp->cpu__DOT__alu_op2)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((~ (IData)(vlTOPp->cpu__DOT__alucode)) 
                                                    | (vlTOPp->cpu__DOT__alu_op1 
                                                       == vlTOPp->cpu__DOT__alu_op2))
                                                    : (IData)(vlTOPp->cpu__DOT__alucode)))))));
    vlTOPp->cpu__DOT__alu_result = ((0x20U & (IData)(vlTOPp->cpu__DOT__alucode))
                                     ? 0U : ((0x10U 
                                              & (IData)(vlTOPp->cpu__DOT__alucode))
                                              ? ((8U 
                                                  & (IData)(vlTOPp->cpu__DOT__alucode))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 0U
                                                     : 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__alu_op1, 
                                                                   (0x1fU 
                                                                    & vlTOPp->cpu__DOT__alu_op2)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->cpu__DOT__alu_op2))
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     << 
                                                     (0x1fU 
                                                      & vlTOPp->cpu__DOT__alu_op2)))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     & vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     | vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     ^ vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    ((vlTOPp->cpu__DOT__alu_op1 
                                                      < vlTOPp->cpu__DOT__alu_op2)
                                                      ? 1U
                                                      : 0U)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     - vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)))))
                                              : ((8U 
                                                  & (IData)(vlTOPp->cpu__DOT__alucode))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2)
                                                    : 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : 0U)))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 0U
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : vlTOPp->cpu__DOT__alu_op2))))));
    vlTOPp->cpu__DOT__npc = ((IData)(vlTOPp->cpu__DOT__br_taken)
                              ? (vlTOPp->cpu__DOT__npc_op1 
                                 + vlTOPp->cpu__DOT__npc_op2)
                              : ((IData)(4U) + vlTOPp->cpu__DOT__pc));
    vlTOPp->cpu__DOT__uart_we = ((0xf6fff070U == vlTOPp->cpu__DOT__alu_result) 
                                 & (IData)(vlTOPp->cpu__DOT__is_store));
    vlTOPp->cpu__DOT__w_data_processed = ((0x1fU >= 
                                           (0x18U & 
                                            (vlTOPp->cpu__DOT__alu_result 
                                             << 3U)))
                                           ? (vlTOPp->cpu__DOT__rs2_data 
                                              << (0x18U 
                                                  & (vlTOPp->cpu__DOT__alu_result 
                                                     << 3U)))
                                           : 0U);
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w 
        = (3U & vlTOPp->cpu__DOT__alu_result);
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode 
        = vlTOPp->cpu__DOT__alucode;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store 
        = vlTOPp->cpu__DOT__is_store;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store)
            ? ((0xeU == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                    ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                        ? 8U : 4U) : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                                       ? 2U : 1U)) : 
               ((0xfU == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                 ? ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                     ? 3U : ((1U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                              ? 6U : ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                                       ? 0xcU : 0U)))
                 : ((0x10U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                     ? ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                         ? 0xfU : 0U) : 0U))) : 0U);
    vlTOPp->cpu__DOT__we = vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout;
}

void Vcpu::_settle__TOP__5(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_settle__TOP__5\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->uart_rx_out = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart_0__DOT__uart_busy = (0U 
                                                != 
                                                (7U 
                                                 & ((IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount) 
                                                    >> 1U)));
    vlTOPp->cpu__DOT__uart_0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart_0__DOT__bitcount));
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                      ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                          ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 
                                                 (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                  >> 7U)
                                                  : 0U)
                                              : 0U)
                                          : 0U) : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                      >> 7U)
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)))
                         : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                   ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                       ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                     >> 7U)
                                                     : 0U)
                                                    : 0U))
                                       : 0U) : ((0x10U 
                                                 & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                 ? 
                                                ((8U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                    >> 7U)
                                                    : 0U)
                                                   : 0U))
                                                 : 
                                                ((8U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir 
                                                     >> 7U)
                                                     : 0U)
                                                    : 0U)))))));
    vlTOPp->cpu__DOT__dstreg_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout;
    vlTOPp->cpu__DOT__is_store = (1U & ((~ (vlTOPp->cpu__DOT__ir 
                                            >> 6U)) 
                                        & ((vlTOPp->cpu__DOT__ir 
                                            >> 5U) 
                                           & ((~ (vlTOPp->cpu__DOT__ir 
                                                  >> 4U)) 
                                              & ((~ 
                                                  (vlTOPp->cpu__DOT__ir 
                                                   >> 3U)) 
                                                 & ((~ 
                                                     (vlTOPp->cpu__DOT__ir 
                                                      >> 2U)) 
                                                    & ((vlTOPp->cpu__DOT__ir 
                                                        >> 1U) 
                                                       & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->cpu__DOT__alucode = ((0x40U & vlTOPp->cpu__DOT__ir)
                                  ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x10U & vlTOPp->cpu__DOT__ir)
                                          ? 0x3fU : 
                                         ((8U & vlTOPp->cpu__DOT__ir)
                                           ? ((4U & vlTOPp->cpu__DOT__ir)
                                               ? ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 1U
                                                    : 0x3fU)
                                                   : 0x3fU)
                                               : 0x3fU)
                                           : ((4U & vlTOPp->cpu__DOT__ir)
                                               ? ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 2U
                                                    : 0x3fU)
                                                   : 0x3fU)
                                               : ((2U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x4000U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 8U
                                                       : 7U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 6U
                                                       : 5U))
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 4U
                                                       : 3U)))
                                                    : 0x3fU)
                                                   : 0x3fU))))
                                      : 0x3fU) : ((0x20U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 0U
                                                        : 0x3fU)
                                                       : 0x3fU)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x17U
                                                           : 0x16U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x19U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x1aU
                                                             : 0x3fU))
                                                           : 0x15U))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x14U
                                                           : 0x13U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x18U
                                                           : 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x11U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x12U
                                                             : 0x3fU)))))
                                                        : 0x3fU)
                                                       : 0x3fU)))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__ir 
                                                             >> 0xcU)))
                                                         ? 0xeU
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__ir 
                                                              >> 0xcU)))
                                                          ? 0xfU
                                                          : 
                                                         ((2U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__ir 
                                                               >> 0xcU)))
                                                           ? 0x10U
                                                           : 0x3fU)))
                                                        : 0x3fU)
                                                       : 0x3fU))))
                                                   : 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 0x11U
                                                        : 0x3fU)
                                                       : 0x3fU)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x17U
                                                           : 0x16U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 
                                                          ((0U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->cpu__DOT__ir 
                                                                >> 0x19U)))
                                                            ? 0x19U
                                                            : 
                                                           ((0x20U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->cpu__DOT__ir 
                                                                 >> 0x19U)))
                                                             ? 0x1aU
                                                             : 0x3fU))
                                                           : 0x15U))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x14U
                                                           : 0x13U)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x18U
                                                           : 0x11U)))
                                                        : 0x3fU)
                                                       : 0x3fU)))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 0x3fU
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0x3fU
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 0x3fU
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0xdU
                                                           : 0xcU))
                                                         : 
                                                        ((0x2000U 
                                                          & vlTOPp->cpu__DOT__ir)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0x3fU
                                                           : 0xbU)
                                                          : 
                                                         ((0x1000U 
                                                           & vlTOPp->cpu__DOT__ir)
                                                           ? 0xaU
                                                           : 9U)))
                                                        : 0x3fU)
                                                       : 0x3fU))))));
    vlTOPp->cpu__DOT__aluop1_type = ((0x40U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                          ? ((0x10U 
                                              & vlTOPp->cpu__DOT__ir)
                                              ? 0U : 
                                             ((8U & vlTOPp->cpu__DOT__ir)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U))))
                                          : 0U) : (
                                                   (0x20U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))))
                                                    : 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))))));
    vlTOPp->cpu__DOT__aluop2_type = ((0x40U & vlTOPp->cpu__DOT__ir)
                                      ? ((0x20U & vlTOPp->cpu__DOT__ir)
                                          ? ((0x10U 
                                              & vlTOPp->cpu__DOT__ir)
                                              ? 0U : 
                                             ((8U & vlTOPp->cpu__DOT__ir)
                                               ? ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 3U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)
                                               : ((4U 
                                                   & vlTOPp->cpu__DOT__ir)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 3U
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U))))
                                          : 0U) : (
                                                   (0x20U 
                                                    & vlTOPp->cpu__DOT__ir)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U))))
                                                    : 
                                                   ((0x10U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 3U
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U)))
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->cpu__DOT__ir)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->cpu__DOT__ir)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->cpu__DOT__ir)
                                                         ? 2U
                                                         : 0U)
                                                        : 0U))))));
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                      ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 
                                                   (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                    >> 0x14U)
                                                    : 0U)
                                                   : 0U))))
                         : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                   ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                       ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                           ? 0U : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                      >> 0x14U)
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                           ? 0U : (
                                                   (4U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode))
                                                      ? 
                                                     (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir 
                                                      >> 0x14U)
                                                      : 0U)
                                                     : 0U))))
                                   : 0U)));
    vlTOPp->cpu__DOT__srcreg2_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                    ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                         ? ((0xfff00000U 
                                             & (VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                        >> 0x1fU)))) 
                                                << 0x14U)) 
                                            | ((0xff000U 
                                                & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir) 
                                               | ((0x800U 
                                                   & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                        >> 0x14U)))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0xfffff000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                               >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                         >> 0x14U)))
                                                   : 0U)
                                               : 0U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0xffffe000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                               >> 0x1fU)))) 
                                                       << 0xdU)) 
                                                   | ((0x1000U 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                          >> 0x13U)) 
                                                      | ((0x800U 
                                                          & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                             << 4U)) 
                                                         | ((0x7e0U 
                                                             & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                >> 0x14U)) 
                                                            | (0x1eU 
                                                               & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                  >> 7U))))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                   : 0U)
                                               : 0U)
                                           : 0U)) : 
                             ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                               ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                        ? 0U : ((2U 
                                                 & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                  ? 
                                                 ((0xfffff000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                              >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                   : 0U)
                                               : 0U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                   ? 
                                                  ((0x2000U 
                                                    & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                    ? 
                                                   ((0xfffff000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | (0xfffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                          >> 0x14U)))
                                                    : 
                                                   ((0x1000U 
                                                     & vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir)
                                                     ? 
                                                    ((0xffffffe0U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x18U)))) 
                                                         << 5U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))
                                                     : 
                                                    ((0xfffff000U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))))
                                                   : 0U)
                                               : 0U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                  ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode))
                                                     ? 
                                                    ((0xfffff000U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                                                >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir 
                                                           >> 0x14U)))
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->cpu__DOT__imm = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
        = vlTOPp->cpu__DOT__ir;
    vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout 
        = (0x1fU & ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                     ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                         ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                             ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                      ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                   ? 
                                                  (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                   >> 0xfU)
                                                   : 0U)
                                               : 0U)))
                         : 0U) : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                   ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                     >> 0xfU)
                                                     : 0U)
                                                    : 0U)))
                                   : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode))
                                                     ? 
                                                    (vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir 
                                                     >> 0xfU)
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->cpu__DOT__srcreg1_num = vlTOPp->__Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout;
    vlTOPp->cpu__DOT__uart_0__DOT__dNxt = (0x1fffffffU 
                                           & (vlTOPp->cpu__DOT__uart_0__DOT__d 
                                              + ((0x10000000U 
                                                  & vlTOPp->cpu__DOT__uart_0__DOT__d)
                                                  ? 0x1c200U
                                                  : 0xfa0be100U)));
    vlTOPp->cpu__DOT__reg_we = (1U & ((0x40U & vlTOPp->cpu__DOT__ir)
                                       ? ((vlTOPp->cpu__DOT__ir 
                                           >> 5U) & 
                                          ((~ (vlTOPp->cpu__DOT__ir 
                                               >> 4U)) 
                                           & ((8U & vlTOPp->cpu__DOT__ir)
                                               ? ((vlTOPp->cpu__DOT__ir 
                                                   >> 2U) 
                                                  & ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & (vlTOPp->cpu__DOT__ir 
                                                        & (0U 
                                                           != (IData)(vlTOPp->cpu__DOT__dstreg_num)))))
                                               : ((vlTOPp->cpu__DOT__ir 
                                                   >> 2U) 
                                                  & ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & (vlTOPp->cpu__DOT__ir 
                                                        & (0U 
                                                           != (IData)(vlTOPp->cpu__DOT__dstreg_num))))))))
                                       : ((0x20U & vlTOPp->cpu__DOT__ir)
                                           ? ((vlTOPp->cpu__DOT__ir 
                                               >> 4U) 
                                              & ((~ 
                                                  (vlTOPp->cpu__DOT__ir 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     ? 
                                                    ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & vlTOPp->cpu__DOT__ir)
                                                     : 
                                                    ((vlTOPp->cpu__DOT__ir 
                                                      >> 1U) 
                                                     & vlTOPp->cpu__DOT__ir))))
                                           : ((0x10U 
                                               & vlTOPp->cpu__DOT__ir)
                                               ? ((~ 
                                                   (vlTOPp->cpu__DOT__ir 
                                                    >> 3U)) 
                                                  & ((4U 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      ? 
                                                     ((vlTOPp->cpu__DOT__ir 
                                                       >> 1U) 
                                                      & vlTOPp->cpu__DOT__ir)
                                                      : 
                                                     ((vlTOPp->cpu__DOT__ir 
                                                       >> 1U) 
                                                      & vlTOPp->cpu__DOT__ir)))
                                               : ((~ 
                                                   (vlTOPp->cpu__DOT__ir 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->cpu__DOT__ir 
                                                       >> 2U)) 
                                                     & ((vlTOPp->cpu__DOT__ir 
                                                         >> 1U) 
                                                        & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->cpu__DOT__rs2_data = vlTOPp->cpu__DOT__register_file0__DOT__mem
        [vlTOPp->cpu__DOT__srcreg2_num];
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                    ? 4U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                         ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                         : 4U) : 4U)
                                 : 4U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                                   : 4U)
                                               : 4U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm
                                                   : 4U)
                                               : 4U))))
                : 4U) : 4U);
    vlTOPp->cpu__DOT__npc_op1 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout;
    vlTOPp->cpu__DOT__rs1_data = vlTOPp->cpu__DOT__register_file0__DOT__mem
        [vlTOPp->cpu__DOT__srcreg1_num];
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data 
        = vlTOPp->cpu__DOT__rs2_data;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type 
        = vlTOPp->cpu__DOT__aluop2_type;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout 
        = ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
            ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm)
            : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data
                : 0U));
    vlTOPp->cpu__DOT__alu_op2 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                    ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc
                    : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                        ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc
                        : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode))
                                    ? vlTOPp->cpu__DOT__rs1_data
                                    : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
                                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
                            : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)))
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc)
            : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc);
    vlTOPp->cpu__DOT__npc_op2 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc 
        = vlTOPp->cpu__DOT__pc;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm 
        = vlTOPp->cpu__DOT__imm;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data 
        = vlTOPp->cpu__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type 
        = vlTOPp->cpu__DOT__aluop1_type;
    vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout 
        = ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
            ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc
                : vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm)
            : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type))
                ? vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data
                : 0U));
    vlTOPp->cpu__DOT__alu_op1 = vlTOPp->__Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout;
    vlTOPp->cpu__DOT__br_taken = (1U & ((~ ((IData)(vlTOPp->cpu__DOT__alucode) 
                                            >> 5U)) 
                                        & ((~ ((IData)(vlTOPp->cpu__DOT__alucode) 
                                               >> 4U)) 
                                           & ((8U & (IData)(vlTOPp->cpu__DOT__alucode))
                                               ? ((~ 
                                                   ((IData)(vlTOPp->cpu__DOT__alucode) 
                                                    >> 2U)) 
                                                  & ((~ 
                                                      ((IData)(vlTOPp->cpu__DOT__alucode) 
                                                       >> 1U)) 
                                                     & ((~ (IData)(vlTOPp->cpu__DOT__alucode)) 
                                                        & (vlTOPp->cpu__DOT__alu_op1 
                                                           >= vlTOPp->cpu__DOT__alu_op2))))
                                               : ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     < vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    VL_GTES_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     != vlTOPp->cpu__DOT__alu_op2)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((~ (IData)(vlTOPp->cpu__DOT__alucode)) 
                                                    | (vlTOPp->cpu__DOT__alu_op1 
                                                       == vlTOPp->cpu__DOT__alu_op2))
                                                    : (IData)(vlTOPp->cpu__DOT__alucode)))))));
    vlTOPp->cpu__DOT__alu_result = ((0x20U & (IData)(vlTOPp->cpu__DOT__alucode))
                                     ? 0U : ((0x10U 
                                              & (IData)(vlTOPp->cpu__DOT__alucode))
                                              ? ((8U 
                                                  & (IData)(vlTOPp->cpu__DOT__alucode))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 0U
                                                     : 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__alu_op1, 
                                                                   (0x1fU 
                                                                    & vlTOPp->cpu__DOT__alu_op2)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->cpu__DOT__alu_op2))
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     << 
                                                     (0x1fU 
                                                      & vlTOPp->cpu__DOT__alu_op2)))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     & vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     | vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     ^ vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    ((vlTOPp->cpu__DOT__alu_op1 
                                                      < vlTOPp->cpu__DOT__alu_op2)
                                                      ? 1U
                                                      : 0U)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__alu_op1, vlTOPp->cpu__DOT__alu_op2)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     - vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)))))
                                              : ((8U 
                                                  & (IData)(vlTOPp->cpu__DOT__alucode))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2)
                                                    : 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__alu_op1 
                                                    + vlTOPp->cpu__DOT__alu_op2)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__alu_op1 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : 0U)))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->cpu__DOT__alucode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->cpu__DOT__alucode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 0U
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlTOPp->cpu__DOT__alu_op2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->cpu__DOT__alucode))
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlTOPp->cpu__DOT__alu_op2)
                                                     : vlTOPp->cpu__DOT__alu_op2))))));
    vlTOPp->cpu__DOT__npc = ((IData)(vlTOPp->cpu__DOT__br_taken)
                              ? (vlTOPp->cpu__DOT__npc_op1 
                                 + vlTOPp->cpu__DOT__npc_op2)
                              : ((IData)(4U) + vlTOPp->cpu__DOT__pc));
    vlTOPp->cpu__DOT__uart_we = ((0xf6fff070U == vlTOPp->cpu__DOT__alu_result) 
                                 & (IData)(vlTOPp->cpu__DOT__is_store));
    vlTOPp->cpu__DOT__w_data_processed = ((0x1fU >= 
                                           (0x18U & 
                                            (vlTOPp->cpu__DOT__alu_result 
                                             << 3U)))
                                           ? (vlTOPp->cpu__DOT__rs2_data 
                                              << (0x18U 
                                                  & (vlTOPp->cpu__DOT__alu_result 
                                                     << 3U)))
                                           : 0U);
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w 
        = (3U & vlTOPp->cpu__DOT__alu_result);
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode 
        = vlTOPp->cpu__DOT__alucode;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store 
        = vlTOPp->cpu__DOT__is_store;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store)
            ? ((0xeU == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                    ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                        ? 8U : 4U) : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                                       ? 2U : 1U)) : 
               ((0xfU == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                 ? ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                     ? 3U : ((1U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                              ? 6U : ((2U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                                       ? 0xcU : 0U)))
                 : ((0x10U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode))
                     ? ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w))
                         ? 0xfU : 0U) : 0U))) : 0U);
    vlTOPp->cpu__DOT__we = vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
        = vlTOPp->cpu__DOT__r_data_unprocessed;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode 
        = vlTOPp->cpu__DOT__alucode;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load 
        = (1U & ((~ (vlTOPp->cpu__DOT__ir >> 6U)) & 
                 ((~ (vlTOPp->cpu__DOT__ir >> 5U)) 
                  & ((~ (vlTOPp->cpu__DOT__ir >> 4U)) 
                     & ((~ (vlTOPp->cpu__DOT__ir >> 3U)) 
                        & ((~ (vlTOPp->cpu__DOT__ir 
                               >> 2U)) & ((vlTOPp->cpu__DOT__ir 
                                           >> 1U) & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load)
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                ? 0U : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                         ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                  ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                      ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    (0xffffU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                        >> 8U))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->cpu__DOT__alu_result))
                                                      ? 
                                                     (0xffffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 0x10U))
                                                      : 0U)))
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                        >> 8U))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->cpu__DOT__alu_result))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 0x10U))
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->cpu__DOT__alu_result))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x18U))
                                                       : 0U))))))
                                      : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                              ? ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed
                                                  : 0U)
                                              : ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? 
                                                 ((0xffff0000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                              >> 0xfU)))) 
                                                      << 0x10U)) 
                                                  | (0xffffU 
                                                     & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->cpu__DOT__alu_result))
                                                   ? 
                                                  ((0xffff0000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                               >> 0x17U)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 8U)))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x1fU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x10U)))
                                                    : 0U))))
                                          : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                              ? ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? 
                                                 ((0xffffff00U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                              >> 7U)))) 
                                                      << 8U)) 
                                                  | (0xffU 
                                                     & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->cpu__DOT__alu_result))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                               >> 0xfU)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 8U)))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   ((0xffffff00U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x17U)))) 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x10U)))
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    ((0xffffff00U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x1fU)))) 
                                                         << 8U)) 
                                                     | (0xffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                           >> 0x18U)))
                                                     : 0U))))
                                              : 0U)))
                                  : 0U))) : 0U);
    vlTOPp->cpu__DOT__r_data_processed = vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout;
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b 
        = (((0xbU == (IData)(vlTOPp->cpu__DOT__alucode)) 
            & (0xffffff00U == vlTOPp->cpu__DOT__alu_result))
            ? vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles
            : vlTOPp->cpu__DOT__r_data_processed);
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a 
        = vlTOPp->cpu__DOT__alu_result;
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                         ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                         : 0U) : 0U)
                                 : 0U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                                   : 0U)
                                               : 0U)
                                           : 0U))) : 0U)
            : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                        ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                     : 0U) : 0U)) : 0U)
                : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                        ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                     : 0U) : 0U)) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                     ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                              ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                           ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b
                                           : 0U) : 0U))))));
    vlTOPp->cpu__DOT__w_data = vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout;
}

VL_INLINE_OPT void Vcpu::_multiclk__TOP__6(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_multiclk__TOP__6\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
        = vlTOPp->cpu__DOT__r_data_unprocessed;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode 
        = vlTOPp->cpu__DOT__alucode;
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load 
        = (1U & ((~ (vlTOPp->cpu__DOT__ir >> 6U)) & 
                 ((~ (vlTOPp->cpu__DOT__ir >> 5U)) 
                  & ((~ (vlTOPp->cpu__DOT__ir >> 4U)) 
                     & ((~ (vlTOPp->cpu__DOT__ir >> 3U)) 
                        & ((~ (vlTOPp->cpu__DOT__ir 
                               >> 2U)) & ((vlTOPp->cpu__DOT__ir 
                                           >> 1U) & vlTOPp->cpu__DOT__ir)))))));
    vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load)
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                ? 0U : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                         ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                  ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                      ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    (0xffffU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                        >> 8U))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->cpu__DOT__alu_result))
                                                      ? 
                                                     (0xffffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 0x10U))
                                                      : 0U)))
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   (0xffU 
                                                    & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    (0xffU 
                                                     & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                        >> 8U))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->cpu__DOT__alu_result))
                                                      ? 
                                                     (0xffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 0x10U))
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->cpu__DOT__alu_result))
                                                       ? 
                                                      (0xffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x18U))
                                                       : 0U))))))
                                      : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                              ? ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed
                                                  : 0U)
                                              : ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? 
                                                 ((0xffff0000U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                              >> 0xfU)))) 
                                                      << 0x10U)) 
                                                  | (0xffffU 
                                                     & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->cpu__DOT__alu_result))
                                                   ? 
                                                  ((0xffff0000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                               >> 0x17U)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 8U)))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x1fU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x10U)))
                                                    : 0U))))
                                          : ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode))
                                              ? ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->cpu__DOT__alu_result))
                                                  ? 
                                                 ((0xffffff00U 
                                                   & (VL_NEGATE_I((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                              >> 7U)))) 
                                                      << 8U)) 
                                                  | (0xffU 
                                                     & vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->cpu__DOT__alu_result))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                               >> 0xfU)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                         >> 8U)))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 
                                                   ((0xffffff00U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x17U)))) 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                          >> 0x10U)))
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 
                                                    ((0xffffff00U 
                                                      & (VL_NEGATE_I((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                                                >> 0x1fU)))) 
                                                         << 8U)) 
                                                     | (0xffU 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed 
                                                           >> 0x18U)))
                                                     : 0U))))
                                              : 0U)))
                                  : 0U))) : 0U);
    vlTOPp->cpu__DOT__r_data_processed = vlTOPp->__Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout;
}

VL_INLINE_OPT void Vcpu::_multiclk__TOP__7(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_multiclk__TOP__7\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b 
        = (((0xbU == (IData)(vlTOPp->cpu__DOT__alucode)) 
            & (0xffffff00U == vlTOPp->cpu__DOT__alu_result))
            ? vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles
            : vlTOPp->cpu__DOT__r_data_processed);
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a 
        = vlTOPp->cpu__DOT__alu_result;
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode 
        = (0x7fU & vlTOPp->cpu__DOT__ir);
    vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? 0U : ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                             ? ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                         ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                         : 0U) : 0U)
                                 : 0U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                                   ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                                   : 0U)
                                               : 0U)
                                           : 0U))) : 0U)
            : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                        ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                     : 0U) : 0U)) : 0U)
                : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                        ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                 ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                     ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a
                                     : 0U) : 0U)) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                     ? 0U : ((4U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                              ? 0U : ((2U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode))
                                           ? vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b
                                           : 0U) : 0U))))));
    vlTOPp->cpu__DOT__w_data = vlTOPp->__Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout;
}

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((~ (IData)(vlTOPp->cpu_resetn)) & (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
         | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->sysclk)) & (IData)(vlTOPp->__Vclklast__TOP__sysclk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->sysclk) ^ (IData)(vlTOPp->__Vclklast__TOP__sysclk))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->cpu_resetn)) & (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
         | ((IData)(vlTOPp->sysclk) ^ (IData)(vlTOPp->__Vclklast__TOP__sysclk)))) {
        vlTOPp->_multiclk__TOP__7(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__cpu_resetn = vlTOPp->cpu_resetn;
    vlTOPp->__Vclklast__TOP__sysclk = vlTOPp->sysclk;
}

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__cpu_resetn = vlTOPp->cpu_resetn;
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
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
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
    cpu__DOT__ir = VL_RAND_RESET_I(32);
    cpu__DOT__srcreg1_num = VL_RAND_RESET_I(5);
    cpu__DOT__srcreg2_num = VL_RAND_RESET_I(5);
    cpu__DOT__dstreg_num = VL_RAND_RESET_I(5);
    cpu__DOT__imm = VL_RAND_RESET_I(32);
    cpu__DOT__pc = VL_RAND_RESET_I(32);
    cpu__DOT__alucode = VL_RAND_RESET_I(6);
    cpu__DOT__aluop1_type = VL_RAND_RESET_I(2);
    cpu__DOT__aluop2_type = VL_RAND_RESET_I(2);
    cpu__DOT__reg_we = VL_RAND_RESET_I(1);
    cpu__DOT__is_store = VL_RAND_RESET_I(1);
    cpu__DOT__rs1_data = VL_RAND_RESET_I(32);
    cpu__DOT__rs2_data = VL_RAND_RESET_I(32);
    cpu__DOT__w_data = VL_RAND_RESET_I(32);
    cpu__DOT__r_data_unprocessed = VL_RAND_RESET_I(32);
    cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    cpu__DOT__br_taken = VL_RAND_RESET_I(1);
    cpu__DOT__npc = VL_RAND_RESET_I(32);
    cpu__DOT__uart_we = VL_RAND_RESET_I(1);
    cpu__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    cpu__DOT__npc_op1 = VL_RAND_RESET_I(32);
    cpu__DOT__npc_op2 = VL_RAND_RESET_I(32);
    cpu__DOT__alu_op1 = VL_RAND_RESET_I(32);
    cpu__DOT__alu_op2 = VL_RAND_RESET_I(32);
    cpu__DOT__we = VL_RAND_RESET_I(4);
    cpu__DOT__r_data_processed = VL_RAND_RESET_I(32);
    cpu__DOT__w_data_processed = VL_RAND_RESET_I(32);
    cpu__DOT__uart_0__DOT__bitcount = VL_RAND_RESET_I(4);
    cpu__DOT__uart_0__DOT__shifter = VL_RAND_RESET_I(9);
    cpu__DOT__uart_0__DOT__uart_busy = VL_RAND_RESET_I(1);
    cpu__DOT__uart_0__DOT__sending = VL_RAND_RESET_I(1);
    cpu__DOT__uart_0__DOT__d = VL_RAND_RESET_I(29);
    cpu__DOT__uart_0__DOT__dNxt = VL_RAND_RESET_I(29);
    cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu__DOT__register_file0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32781; ++__Vi0) {
            cpu__DOT__data_memory0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__data_memory0__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    cpu__DOT__data_memory0__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    cpu__DOT__data_memory0__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    cpu__DOT__data_memory0__DOT____Vlvbound4 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<24581; ++__Vi0) {
            cpu__DOT__inst_memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load = VL_RAND_RESET_I(1);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode = VL_RAND_RESET_I(6);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout = VL_RAND_RESET_I(4);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store = VL_RAND_RESET_I(1);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode = VL_RAND_RESET_I(6);
    __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b = VL_RAND_RESET_I(32);
}
