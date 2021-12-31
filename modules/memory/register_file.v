module register_file (
    input wire clk,reg_we,
    input wire [4:0] rs1_addr, rs2_addr, 
    input [4:0] w_addr,
    input [31:0] w_data,

    output wire [31:0] rs1_data, rs2_data
);

    // initial $readmemh("/home/username/workspace/test.hex", mem);

    // reg [31:0] mem [0:31];
    reg [31:0] mem [0:31];
    always @(posedge clk) begin
        if (reg_we) begin
            mem[w_addr] <= w_data;
        end
    end
    assign rs1_data = mem[rs1_addr];
    assign rs2_data = mem[rs2_addr];

endmodule