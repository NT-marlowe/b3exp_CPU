`include "define.vh"
module nextPC (
    input wire clk,
    input wire [6:0] opcode, 
    input wire [31:0] oldPC,
    input wire [31:0] rs1_data, imm,
    input wire br_taken, // 分岐の有無
    output reg [31:0] nPC
);

    always @(posedge clk) begin
        case (opcode)
            `LUI, `AUIPC, `LOAD, `STORE, `OPIMM, `OP : begin
                nPC <= oldPC + 3'd4;
            end

            `JAL : begin
                nPC <= oldPC + imm;
            end

            `JALR : begin
                nPC <= rs1_data + imm;
            end

            `BRANCH : begin
                if (br_taken == `ENABLE) nPC <= oldPC + imm; 
                else if (br_taken == `DISABLE) nPC <= oldPC + 3'd4;
                else nPC <= oldPC + 3'd4;
            end

            default : begin
                nPC <= oldPC + 3'd4;
            end

        endcase
    end

endmodule