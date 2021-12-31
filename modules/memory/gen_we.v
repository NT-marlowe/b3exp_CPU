`include "define.vh"

// data_memoryに渡すためのweと書き込みデータを作る
module gen_we (
    input is_store,
    input [5:0] alucode,
    output [3:0] we,
    output [31:0] w_data
);

    function [3:0] we;
        input is_store;
        input [5:0] alucode;

        if (is_store == `ENABLE) begin
            case (alucode) 
                `ALU_SB : we = 4'b1000;
                `ALU_SH : we = 4'b1100;
                `ALU_SW : we = 4'b1111;
                `ALU_LUI, `ALU_JAL, `ALU_JALR, `ALU_BEQ, 
                    `ALU_BNE, `ALU_BLT, `ALU_BGE, `ALU_BLTU,
                    `ALU_BGEU, `ALU_LB, `ALU_LH, `ALU_LW,
                    `ALU_LBU, `ALU_LHU, `ALU_ADD, `ALU_SUB,
                    `ALU_SLT, `ALU_SLTU, `ALU_XOR, `ALU_OR, 
                    `ALU_AND, `ALU_SLL, `ALU_SRL, `ALU_SRA, 
                    `ALU_NOP : we = 4'b0000;
                default : we = 4'b0000;
            endcase
        end
        else begin
            we = 4'b0000;
        end
    endfunction

    assign we = we(is_load, is_store, alucode);

endmodule