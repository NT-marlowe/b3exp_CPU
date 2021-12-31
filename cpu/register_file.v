`include "define.vh"
module register_file (
    input clk,reg_we,
    input [4:0] rs1_addr, rs2_addr, 
    input [4:0] w_addr,
    input [31:0] w_data,

    output wire [31:0] rs1_data, rs2_data
);

    reg [31:0] mem [0:31];

    initial mem[0] = 32'd0;
    always @(posedge clk) begin
        if (reg_we == `ENABLE && w_addr != 5'd0) begin
            mem[w_addr] <= w_data;
        end
    end
    assign rs1_data = mem[rs1_addr];
    assign rs2_data = mem[rs2_addr];

endmodule