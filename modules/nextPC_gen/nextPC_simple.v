`include "define.vh"

module nextPC (
    input br_taken,
    input [31:0] npc_op1, npc_op2, pc,
    output [31:0] npc
);
    assign npc = br_taken ? npc_op1 + npc_op2 : pc + 32'd4;
endmodule