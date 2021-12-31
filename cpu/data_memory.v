`include "define.vh"

module data_memory (
    input clk,
    input [3:0] we,
    input [16:0] r_addr, w_addr, // 17ビット
    input [31:0] w_data,
    output reg [31:0] r_data
);  
    // 128KiB分取ってしまってもいい
    reg [31:0] mem [0:32780];
    initial $readmemh("/home/denjo/WorkSpace/irie_jikken/b3exp/benchmarks/Coremark_for_Synthesis/data.hex", mem);
    wire [16:0] r_addr_shited, w_addr_shited;
    always @(negedge clk) begin
        if (we[0]) mem[w_addr_shited[15:0]][ 7: 0] <= w_data[ 7: 0];
        if (we[1]) mem[w_addr_shited[15:0]][15: 8] <= w_data[15: 8];
        if (we[2]) mem[w_addr_shited[15:0]][23:16] <= w_data[23:16];
        if (we[3]) mem[w_addr_shited[15:0]][31:24] <= w_data[31:24];
        r_data <= mem[r_addr_shited[15:0]];
    end

    assign r_addr_shited = r_addr >> 2;
    assign w_addr_shited = w_addr >> 2;
endmodule
