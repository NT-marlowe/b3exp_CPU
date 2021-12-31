`include "define.vh"

module data_memory (
    input clk,
    input [3:0] we,
    input [14:0] r_addr, w_addr, // 15ビット
    input [31:0] w_data,
    output reg [31:0] r_data
);  
    // 128KiB分取ってしまってもいい
    reg [31:0] mem [0:32780];
    // initial $readmemh("/home/denjo/WorkSpace/irie_jikken/b3exp/benchmarks/Coremark/data.hex", mem);
    
    always @(posedge clk) begin
        if (we[0]) mem[w_addr][ 7: 0] <= w_data[ 7: 0];
        if (we[1]) mem[w_addr][15: 8] <= w_data[15: 8];
        if (we[2]) mem[w_addr][23:16] <= w_data[23:16];
        if (we[3]) mem[w_addr][31:24] <= w_data[31:24];
        r_data <= mem[r_addr];
    end
endmodule
