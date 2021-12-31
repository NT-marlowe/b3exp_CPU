`include "define.vh"

module mux_2in (
    input [6:0] opcode, 
    input [31:0] mux_ALU_out, mux_load_data,
    output [31:0] w_data
);

    function [31:0] w_data_func;
        input [6:0] opcode;
        input [31:0] in_a;
        input [31:0] in_b;
        case (opcode)
            `LUI, `AUIPC, `JAL, `JALR, `OPIMM, `OP : begin
                w_data_func = in_a;
            end
            `LOAD : begin
                w_data_func = in_b;
            end
            `BRANCH, `STORE : begin
                w_data_func = 32'd0;
            end
            default : begin
                w_data_func = 32'd0;
            end
        endcase
    endfunction

    assign w_data = w_data_func(opcode, mux_ALU_out, mux_load_data);
    
endmodule