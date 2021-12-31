`include "define.vh"

module data_memory (
    input wire clk,
    input wire [5:0] alucode,
    // input wire [4:0] rs1_addr, rs2_addr, rd_addr,
    input wire [31:0] rs1_data, rs2_data, imm,
    input wire is_load, is_store, 
    output reg [31:0] rd_data
);  

    reg [7:0] mem [0:65540]; // データメモリは64KiB=2^16=65536のインデックス
    reg [32:0] mem_addr;

    always @(negedge clk) begin
        mem_addr <= rs1_data + imm - 32'h0010_0000;  // データメモリのインデックスを0から始めたいので，オフセットを引く
        if (is_store == `ENABLE) begin
            rd_data <= 32'b0;

            case (alucode) 
                `ALU_SB : begin
                    mem[mem_addr] <= rs2_data[7:0];
                end

                `ALU_SH : begin 
                    mem[mem_addr] <= rs2_data[7:0];
                    mem[mem_addr + 1] <= rs2_data[15:8];
                end

                `ALU_SW : begin
                    mem[mem_addr] <= rs2_data[7:0];
                    mem[mem_addr + 1] <= rs2_data[15:8];
                    mem[mem_addr + 2] <= rs2_data[23:16];
                    mem[mem_addr + 3] <= rs2_data[31:24];
                end

                default : begin
                    ;
                end
            endcase
        end

        if (is_load == `ENABLE) begin
            case (alucode) 
                `ALU_LB : begin
                    rd_data <= { {24{mem[mem_addr][7]}}, mem[mem_addr] };
                end

                `ALU_LBU : begin
                    rd_data <= { 24'b0, mem[mem_addr] };
                end

                `ALU_LH : begin
                    rd_data <= { {16{mem[mem_addr][7]}}, mem[mem_addr+1], mem[mem_addr]};
                end

                `ALU_LHU : begin
                    rd_data <= { 16'b0, mem[mem_addr+1], mem[mem_addr]};
                end

                `ALU_LW : begin
                    rd_data <= { mem[mem_addr+3], mem[mem_addr+2], mem[mem_addr+1], mem[mem_addr]};
                end

                default : begin
                    rd_data <= 32'b0;
                end
            endcase
        end
    end

endmodule