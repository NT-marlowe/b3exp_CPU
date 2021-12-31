module distributed_ram(
    input wire clk,
    input wire we,
    input wire [4:0] r_addr,
    input wire [4:0] w_addr,
    input wire [31:0] r_data,
    output wire [31:0] r_data
);
    reg [31:0] mem[0:31];

    always @(posedge clk) begin
        if (we) mem[w_addr] <= w_data;
    end
    
    assign r_data = mem[r_addr];
    
endmodule