// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_H_
#define _VCPU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcpu__Syms;

//----------

VL_MODULE(Vcpu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(sysclk,0,0);
    VL_IN8(cpu_resetn,0,0);
    VL_OUT8(uart_rx_out,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ cpu__DOT__srcreg1_num;
    CData/*4:0*/ cpu__DOT__srcreg2_num;
    CData/*4:0*/ cpu__DOT__dstreg_num;
    CData/*5:0*/ cpu__DOT__alucode;
    CData/*1:0*/ cpu__DOT__aluop1_type;
    CData/*1:0*/ cpu__DOT__aluop2_type;
    CData/*0:0*/ cpu__DOT__reg_we;
    CData/*0:0*/ cpu__DOT__is_store;
    CData/*0:0*/ cpu__DOT__br_taken;
    CData/*0:0*/ cpu__DOT__uart_we;
    CData/*0:0*/ cpu__DOT__uart_OUT_data;
    CData/*3:0*/ cpu__DOT__we;
    CData/*3:0*/ cpu__DOT__uart_0__DOT__bitcount;
    CData/*0:0*/ cpu__DOT__uart_0__DOT__uart_busy;
    CData/*0:0*/ cpu__DOT__uart_0__DOT__sending;
    SData/*8:0*/ cpu__DOT__uart_0__DOT__shifter;
    IData/*31:0*/ cpu__DOT__ir;
    IData/*31:0*/ cpu__DOT__imm;
    IData/*31:0*/ cpu__DOT__pc;
    IData/*31:0*/ cpu__DOT__rs1_data;
    IData/*31:0*/ cpu__DOT__rs2_data;
    IData/*31:0*/ cpu__DOT__w_data;
    IData/*31:0*/ cpu__DOT__r_data_unprocessed;
    IData/*31:0*/ cpu__DOT__alu_result;
    IData/*31:0*/ cpu__DOT__npc;
    IData/*31:0*/ cpu__DOT__npc_op1;
    IData/*31:0*/ cpu__DOT__npc_op2;
    IData/*31:0*/ cpu__DOT__alu_op1;
    IData/*31:0*/ cpu__DOT__alu_op2;
    IData/*31:0*/ cpu__DOT__r_data_processed;
    IData/*31:0*/ cpu__DOT__w_data_processed;
    IData/*28:0*/ cpu__DOT__uart_0__DOT__d;
    IData/*28:0*/ cpu__DOT__uart_0__DOT__dNxt;
    IData/*31:0*/ cpu__DOT__hardware_counter0__DOT__cycles;
    IData/*31:0*/ cpu__DOT__register_file0__DOT__mem[32];
    IData/*31:0*/ cpu__DOT__data_memory0__DOT__mem[32781];
    IData/*31:0*/ cpu__DOT__inst_memory__DOT__mem[24581];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ cpu__DOT__data_memory0__DOT____Vlvbound1;
    CData/*7:0*/ cpu__DOT__data_memory0__DOT____Vlvbound2;
    CData/*7:0*/ cpu__DOT__data_memory0__DOT____Vlvbound3;
    CData/*7:0*/ cpu__DOT__data_memory0__DOT____Vlvbound4;
    CData/*4:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__Vfuncout;
    CData/*6:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__opcode;
    CData/*4:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__Vfuncout;
    CData/*6:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__opcode;
    CData/*4:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__Vfuncout;
    CData/*6:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__opcode;
    CData/*6:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__opcode;
    CData/*6:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__opcode;
    CData/*6:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__opcode;
    CData/*1:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__op1_type;
    CData/*1:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__op2_type;
    CData/*0:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__is_load;
    CData/*5:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__alucode;
    CData/*3:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__Vfuncout;
    CData/*0:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__is_store;
    CData/*5:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__alucode;
    CData/*1:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__generate_we__11__shift_w;
    CData/*6:0*/ __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__opcode;
    CData/*0:0*/ __Vclklast__TOP__cpu_resetn;
    CData/*0:0*/ __Vclklast__TOP__sysclk;
    IData/*31:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg1__0__ir;
    IData/*31:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__reg2__1__ir;
    IData/*31:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__dstreg__2__ir;
    IData/*31:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__decoder_0__DOT__imm_func__3__ir;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op1_func__4__imm;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__npc_op2_func__5__pc;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__rs1_data;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__imm;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op1_func__6__pc;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__rs2_data;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__imm;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_4in0__DOT__alu_op2_func__7__pc;
    IData/*31:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__IO_data_memory0__DOT__r_data_processing__10__r_data_unprocessed;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_a;
    IData/*31:0*/ __Vfunc_cpu__DOT__mux_2in0__DOT__w_data_func__12__in_b;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__6(Vcpu__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__7(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vcpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
