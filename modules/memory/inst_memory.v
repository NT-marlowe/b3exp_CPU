module inst_memory (
    input wire clk,
    input wire [31:0] pc, 
    output reg [31:0] ir, 
);

    reg [31:0] mem [0:16385];

    // initial $readmemh("/home/username/workspace/test.hex", mem);
    always @(posedge clk) begin
        r_data <= mem[r_addr[15:0] >> 2];
    end
    
endmodule