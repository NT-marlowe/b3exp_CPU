`include "define.vh"

module data_memory (
    input clk,
    input is_load, is_store,
    input [5:0] alucode,
    input [16:0] r_addr, w_addr, // 17ビット
    input [31:0] w_data,
    output reg [31:0] r_data
);  
    // 128KiB分取ってしまってもいい
    reg [31:0] mem [0:32780];
    wire [16:0] w_addr_shifted, r_addr_shifted;


    initial $readmemh("/home/denjo/WorkSpace/irie_jikken/b3exp/benchmarks/Coremark/data.hex", mem);

    always @(negedge clk) begin
        if (is_store == `ENABLE) begin
            case (alucode) 
                `ALU_SB : begin
                    if (w_addr % 4 == 0) begin
                        mem[w_addr_shifted[15:0]][ 7: 0] <= w_data[7:0];
                    end 
                    else if (w_addr % 4 == 1) begin
                        mem[w_addr_shifted[15:0]][15: 8] <= w_data[7:0];
                    end
                    else if (w_addr % 4 == 2) begin
                        mem[w_addr_shifted[15:0]][23:16] <= w_data[7:0];
                    end
                    else if (w_addr % 4 == 3) begin
                        mem[w_addr_shifted[15:0]][31:24] <= w_data[7:0];
                    end 
                    else begin
                        mem[w_addr_shifted[15:0]] <= mem[w_addr_shifted[15:0]];
                    end
                end

                `ALU_SH : begin
                    if (w_addr % 4 == 0) begin
                        mem[w_addr_shifted[15:0]][15: 0] <= w_data[15: 0];
                        // mem[w_addr_shifted[15:0]][15: 8] <= w_data[15:8];
                    end
                    else if (w_addr % 4 == 1) begin
                        mem[w_addr_shifted[15:0]][23: 8] <= w_data[15: 0];
                        // mem[w_addr_shifted[15:0]][23:16] <= w_data[15:8];
                    end
                    else if (w_addr % 4 == 2) begin
                        mem[w_addr_shifted[15:0]][31:16] <= w_data[15: 0];
                        // mem[w_addr_shifted[15:0]][31:24] <= w_data[15:8];
                    end
                    else begin
                        mem[w_addr_shifted[15:0]] <= mem[w_addr_shifted[15:0]];
                    end
                end 

                `ALU_SW : begin
                    if (w_addr % 4 == 0) begin
                        mem[w_addr_shifted[15:0]] <= w_data;
                    end
                    else begin
                        mem[w_addr_shifted[15:0]] <= mem[w_addr_shifted[15:0]];
                    end
                end

                default : begin
                    mem[w_addr_shifted[15:0]] <= mem[w_addr_shifted[15:0]];
                end
            endcase
        end

        if (is_load == `ENABLE) begin
            case (alucode)
                `ALU_LB : begin
                    if (r_addr % 4 == 0) begin
                        r_data <= { {24{mem[r_addr_shifted[15:0]][ 7]}}, mem[r_addr_shifted[15:0]][ 7: 0]};
                    end
                    else if (r_addr % 4 == 1) begin
                        r_data <= { {24{mem[r_addr_shifted[15:0]][15]}}, mem[r_addr_shifted[15:0]][15: 8]};
                    end
                    else if (r_addr % 4 == 2) begin
                        r_data <= { {24{mem[r_addr_shifted[15:0]][23]}}, mem[r_addr_shifted[15:0]][23:16]};
                    end
                    else if (r_addr % 4 == 3) begin
                        r_data <= { {24{mem[r_addr_shifted[15:0]][31]}}, mem[r_addr_shifted[15:0]][31:24]};
                    end
                    else begin
                        r_data <= 32'd0;
                    end
                end

                `ALU_LBU : begin
                    if (r_addr % 4 == 0) begin
                        r_data <= { 24'b0, mem[r_addr_shifted[15:0]][ 7: 0]};
                    end
                    else if (r_addr % 4 == 1) begin
                        r_data <= { 24'b0, mem[r_addr_shifted[15:0]][15: 8]};
                    end
                    else if (r_addr % 4 == 2) begin
                        r_data <= { 24'b0, mem[r_addr_shifted[15:0]][23:16]};
                    end
                    else if (r_addr % 4 == 3) begin
                        r_data <= { 24'b0, mem[r_addr_shifted[15:0]][31:24]};
                    end
                    else begin
                        r_data <= 32'd0;
                    end
                end

                `ALU_LH : begin
                    if (r_addr % 4 == 0) begin
                        r_data <= { {16{mem[r_addr_shifted[15:0]][15]}}, mem[r_addr_shifted[15:0]][15: 0]};
                    end
                    else if (r_addr % 4 == 1) begin
                        r_data <= { {16{mem[r_addr_shifted[15:0]][23]}}, mem[r_addr_shifted[15:0]][23: 8]};
                    end
                    else if (r_addr % 4 == 2) begin
                        r_data <= { {16{mem[r_addr_shifted[15:0]][31]}}, mem[r_addr_shifted[15:0]][31:16]};
                    end
                    else begin
                        r_data <= 32'd0;
                    end
                end

                `ALU_LHU : begin
                    if (r_addr % 4 == 0) begin
                        r_data <= { 16'd0, mem[r_addr_shifted[15:0]][15: 0]};
                    end
                    else if (r_addr % 4 == 1) begin
                        r_data <= { 16'd0, mem[r_addr_shifted[15:0]][23: 8]};
                    end
                    else if (r_addr % 4 == 2) begin
                        r_data <= { 16'd0, mem[r_addr_shifted[15:0]][31:16]};
                    end
                    else begin
                        r_data <= 32'd0;
                    end
                end

                `ALU_LW : begin
                    r_data <= mem[r_addr_shifted[15:0]];
                end
                
                default : begin
                    r_data <= 32'd0;
                end
                // `ALU_LUI, `ALU_JAL, `ALU_JALR, `ALU_BEQ, `ALU_BNE, `ALU_BLT,
                // `ALU_BGE, `ALU_BLTU, `ALU_BGEU,
                // `ALU_ADD, `ALU_SUB, `ALU_SLT, `ALU_SLTU, 
                // `ALU_XOR, `ALU_OR, `ALU_AND, `ALU_SLL, `ALU_SRL, `ALU_SRA, 
                // `ALU_NOP : begin
                //     r_data <= 32'd0;
                // end
            endcase
        end
    end

    assign r_addr_shifted = r_addr >> 2;
    assign w_addr_shifted = w_addr >> 2;

endmodule
