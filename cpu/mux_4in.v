`include "define.vh"
module  mux_4in (
    input [31:0] rs1_data, rs2_data, imm, pc, 
    input [6:0] opcode,
    input [1:0] op1_type, op2_type,
    output [31:0] npc_op1, npc_op2,
    output [31:0] alu_op1, alu_op2
);

    function [31:0] npc_op1_func;
        input [6:0] opcode;
        input [31:0] imm;
        case (opcode) 
            `LUI, `AUIPC, `LOAD, `STORE, `OPIMM, `OP : npc_op1_func = 32'd4;
            `JAL, `JALR : npc_op1_func = imm; 
            `BRANCH : npc_op1_func = imm;
            default : npc_op1_func = 32'd4;
        endcase
    endfunction

    function [31:0] npc_op2_func;
        input [6:0] opcode;
        input [31:0] rs2_data, pc;
        case (opcode) 
            `LUI, `AUIPC, `BRANCH, `LOAD, `STORE, `OPIMM, `OP : npc_op2_func = pc;
            `JAL : npc_op2_func = pc;
            `JALR : npc_op2_func = rs1_data;
            default : npc_op2_func = pc;
        endcase
    endfunction


    function [31:0] alu_op1_func;
        input [1:0] op1_type;
        input [31:0] rs1_data, imm, pc;

        case (op1_type) 
            `OP_TYPE_NONE : alu_op1_func = 32'd0;
            `OP_TYPE_REG : alu_op1_func = rs1_data;
            `OP_TYPE_IMM : alu_op1_func = imm;
            `OP_TYPE_PC : alu_op1_func = pc;
            default : alu_op1_func = 32'd0;
        endcase
    endfunction


    function [31:0] alu_op2_func;
        input [1:0] op2_type;
        input [31:0] rs2_data, imm, pc;

        case (op2_type) 
            `OP_TYPE_NONE : alu_op2_func = 32'd0;
            `OP_TYPE_REG : alu_op2_func= rs2_data;
            `OP_TYPE_IMM : alu_op2_func = imm;
            `OP_TYPE_PC : alu_op2_func = pc;
            default : alu_op2_func = 32'd0;
        endcase
    endfunction
    
    assign npc_op1 = npc_op1_func(opcode, imm);
    assign npc_op2 = npc_op2_func(opcode, rs1_data, pc);
    assign alu_op1 = alu_op1_func(op1_type, rs1_data, imm, pc);
    assign alu_op2 = alu_op2_func(op2_type, rs2_data, imm, pc);
    

endmodule