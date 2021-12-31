module inst_memory (
    input wire clk,
    input wire [31:0] pc, 
    output reg [31:0] ir
);

    reg [31:0] mem [0:24580];
    wire [31:0] pc_shifted;
    initial $readmemh("/home/denjo/WorkSpace/irie_jikken/b3exp/benchmarks/Coremark_for_Synthesis/code.hex", mem);
//    initial $readmemh("/home/denjo/WorkSpace/irie_jikken/b3exp/benchmarks/tests/Uart/code.hex", mem);
    always @(posedge clk) begin
        ir <= mem[pc_shifted[14:0]];
    end

    assign pc_shifted = pc >> 2;
endmodule