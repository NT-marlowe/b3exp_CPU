`include "define.vh"

`define MINUS_ONE 32'hffffffff
`define SIGNED_MIN_VALUE 32'hf0000000
`define UNSIGNED_MAX_VALUE 32'hffffffff

module alu(
    input wire [5:0] alucode,
    input wire [31:0] op1,
    input wire [31:0] op2,
    output reg [31:0] alu_result,
    output reg br_taken // 分岐の有無
);  
    reg [63:0] mul_result;
    wire signed [31:0] abs_signed_op1, abs_signed_op2;

    always @(*) begin
        case (alucode) 
            `ALU_LUI : begin
                alu_result = op2;
                br_taken = `DISABLE;
            end

            `ALU_JAL : begin
                alu_result = op2 + 32'd4;
                br_taken = `ENABLE;
            end

            `ALU_JALR : begin
                alu_result = op2 + 32'd4;
                br_taken = `ENABLE;
            end

            `ALU_BEQ : begin
                alu_result = 32'b0;
                br_taken = (op1 == op2)? `ENABLE : `DISABLE;
            end

            `ALU_BNE : begin
                alu_result = 32'b0;
                br_taken = (op1 != op2)? `ENABLE : `DISABLE;
            end

            `ALU_BLT : begin
                alu_result = 32'b0;
                br_taken = ($signed(op1) < $signed(op2))? `ENABLE : `DISABLE;
            end

            `ALU_BGE : begin
                alu_result = 32'b0;
                br_taken = ($signed(op1) >= $signed(op2))? `ENABLE : `DISABLE;
            end

            `ALU_BLTU : begin
                alu_result = 32'b0;
                br_taken = (op1 < op2)? `ENABLE : `DISABLE;
            end

            `ALU_BGEU : begin
                alu_result = 32'b0;
                br_taken = (op1 >= op2)? `ENABLE : `DISABLE;
            end

            `ALU_LB, `ALU_LH, `ALU_LW, `ALU_LBU, `ALU_LHU : begin
                alu_result = op1 + op2;
                br_taken = `DISABLE;
            end

            `ALU_SB, `ALU_SH, `ALU_SW : begin
                alu_result = op1 + op2;
                br_taken = `DISABLE;
            end

            `ALU_ADD : begin
                alu_result = op1 + op2;
                br_taken = `DISABLE;
            end

            `ALU_SUB : begin
                alu_result = op1 - op2;
                br_taken = `DISABLE;
            end

            `ALU_SLT :begin
                alu_result = ($signed(op1) < $signed(op2))? 32'b1 : 32'b0;
                br_taken = `DISABLE;
            end

            `ALU_SLTU : begin 
                alu_result = (op1 < op2)? 32'b1 : 32'b0;
                br_taken = `DISABLE;
            end

            `ALU_XOR : begin
                alu_result = op1 ^ op2;
                br_taken = `DISABLE;
            end

            `ALU_OR : begin
                alu_result = op1 | op2;
                br_taken = `DISABLE;
            end
            
            `ALU_AND : begin
                alu_result = op1 & op2;
                br_taken = `DISABLE;
            end

            `ALU_SLL : begin 
                alu_result = op1 << op2[4:0];
                br_taken = `DISABLE;
            end

            `ALU_SRL : begin
                alu_result = op1 >> op2[4:0];
                br_taken = `DISABLE;
            end

            `ALU_SRA : begin
                alu_result = ($signed(op1) >>> op2[4:0]);
                br_taken = `DISABLE;
            end

            `ALU_MUL : begin
                mul_result = op1 * op2;
                alu_result = mul_result[31:0];
                br_taken = `DISABLE;
            end

            `ALU_MULH : begin
                mul_result = $signed(op1) * $signed(op2);
                alu_result = $signed(mul_result[63:32]);
                br_taken = `DISABLE;
            end

            `ALU_MULHSU : begin
                mul_result = $signed(op1) * op2;
                alu_result = $signed(mul_result[63:32]);
                br_taken = `DISABLE;
            end

            `ALU_MULHU : begin
                mul_result = op1 * op2;
                alu_result = mul_result[63:32];
                br_taken = `DISABLE;
            end

            `ALU_DIV : begin
                if (op2 == 0) alu_result = $signed(-1);
                else if ($signed(op1) == `SIGNED_MIN_VALUE && $signed(op2) == `MINUS_ONE) alu_result = `SIGNED_MIN_VALUE;
                else alu_result = $signed($signed(op1) / $signed(op2));
                br_taken = `DISABLE;
            end

            `ALU_DIVU : begin
                if (op2 == 0) alu_result = `UNSIGNED_MAX_VALUE;
                else alu_result = op1 / op2;
                br_taken = `DISABLE;
            end

            `ALU_REM : begin
                if (op2 == 0) alu_result = op1;
                else if ($signed(op1) == `SIGNED_MIN_VALUE && op2 == `MINUS_ONE) alu_result = 0;
                else begin
                    if (op1[31] == 1'b1) begin // signed(op1) < 0
                        alu_result = -(abs_signed_op1 % abs_signed_op2);
                    end
                    else begin
                        alu_result = abs_signed_op1 % abs_signed_op2;
                    end
                end
                br_taken = `DISABLE;
            end

            `ALU_REMU : begin
                if (op2 == 0) alu_result = op1;
                else alu_result = op1 % op2;
                br_taken = `DISABLE;
            end
            
            `ALU_NOP : begin
                alu_result = 32'b0;
                br_taken = `DISABLE;
            end

            default : begin
                alu_result = 32'b0;
                br_taken = `DISABLE;
            end
        endcase
    end

    function [31:0] abs;
        input signed [31:0] val;
        if (val < 0) abs = -val;
        else abs = val;
    endfunction

    assign abs_signed_op1 = abs($signed(op1));
    assign abs_signed_op2 = abs($signed(op2));

endmodule