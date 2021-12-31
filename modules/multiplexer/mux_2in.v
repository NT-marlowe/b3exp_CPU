`include "define.vh"

module mux_2in (
    // input mux_s, 
    input [6:0] opcode, 
    input [31:0] mux_ALU_out, mux_load_data,
    output [31:0] mux_out
);

    // assign mux_out = (mux_s == 1'b0) ? mux_ALU_out : mux_load_data;
    function [31:0] mux_out_func;
        input [6:0] opcode;
        input [31:0] in_a;
        input [31:0] in_b;
        case (opcode)
            `LUI, `AUIPC, `JAL, `JALR, `OPIMM, `OP : begin
                mux_out_func = in_a;
            end
            `LOAD : begin
                mux_out_func = in_b;
            end
            `BRANCH, `STORE : begin
                mux_out_func = 32'd0;
            end
            default : begin
                mux_out_func = 32'd0;
            end
        endcase
    endfunction

    assign mux_out = mux_out_func(opcode, mux_ALU_out, mux_load_data);
    
endmodule