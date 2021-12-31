`include "define.vh"

module data_memory (
    input clk,
    input [3:0] we, // 書き込むバイトは1, 書き込まないでそのままにするバイトは0を指定
    input [5:0] alucode,
    input [16:0] r_addr, w_addr, // 15ビット
    input [31:0] w_data,
    output reg [31:0] r_data
);  
    // 128KiB分取ってしまってもいい
    reg [31:0] mem [0:32780];
    // initial $readmemh("/home/username/workspace/test.hex", mem);
    always @(negedge clk) begin
        if(we[0]) mem[w_addr][ 7: 0] <= w_data[ 7: 0];
        if(we[1]) mem[w_addr][15: 8] <= w_data[15: 8];
        if(we[2]) mem[w_addr][23:16] <= w_data[23:16];
        if(we[3]) mem[w_addr][31:24] <= w_data[31:24];
        
        case (alucode)
            `ALU_LB : begin
                if (r_addr >> 2 % 3'd4 == 0) begin
                    r_data <= { {24{mem[r_addr >> 2][31]}}, mem[r_addr >> 2][31:24]};
                end
                else if (r_addr >> 2 % 3'd4 == 1) begin
                    r_data <= { {24{mem[r_addr >> 2][23]}}, mem[r_addr >> 2][23:16]};
                end
                else if (r_addr >> 2 % 3'd4 == 2) begin
                    r_data <= { {24{mem[r_addr >> 2][15]}}, mem[r_addr >> 2][15:8]};
                end
                else if (r_addr >> 2 % 3'd4 == 3) begin
                    r_data <= { {24{mem[r_addr >> 2][7]}}, mem[r_addr >> 2][7:0]};
                end
                else begin
                    r_data <= 32'd0;
                end
            end

            `ALU_LBU : begin
                if (r_addr >> 2 % 3'd4 == 0) begin
                    r_data <= { 24'b0, mem[r_addr >> 2][31:24]};
                end
                else if (r_addr >> 2 % 3'd4 == 1) begin
                    r_data <= { 24'b0, mem[r_addr >> 2][23:16]};
                end
                else if (r_addr >> 2 % 3'd4 == 2) begin
                    r_data <= { 24'b0, mem[r_addr >> 2][15:8]};
                end
                else if (r_addr >> 2 % 3'd4 == 3) begin
                    r_data <= { 24'b0, mem[r_addr >> 2][7:0]};
                end
                else begin
                    r_data <= 32'd0;
                end
            end

            `ALU_LH : begin
                if (r_addr >> 2 % 3'd4 == 0) begin
                    r_data <= { {16{mem[r_addr >> 2][23]}}, mem[r_addr >> 2][23:16], mem[r_addr >> 2][31:24]};
                end
                else if (r_addr >> 2 % 3'd4 == 1) begin
                    r_data <= { {16{mem[r_addr >> 2][15]}}, mem[r_addr >> 2][15:8], mem[r_addr >> 2][23:16]};
                end
                else if (r_addr >> 2 % 3'd4 == 2) begin
                    r_data <= { {16{mem[r_addr >> 2][7]}}, mem[r_addr >> 2][7:0], mem[r_addr >> 2][15:8]};
                end
                else begin
                    r_data <= 32'd0;
                end
            end

            `ALU_LHU : begin
                if (r_addr >> 2 % 3'd4 == 0) begin
                    r_data <= { 16'd0, mem[r_addr >> 2][23:16], mem[r_addr >> 2][31:24]};
                end
                else if (r_addr >> 2 % 3'd4 == 1) begin
                    r_data <= { 16'd0, mem[r_addr >> 2][15:8], mem[r_addr >> 2][23:16]};
                end
                else if (r_addr >> 2 % 3'd4 == 2) begin
                    r_data <= { 16'd0, mem[r_addr >> 2][7:0], mem[r_addr >> 2][15:8]};
                end
                else begin
                    r_data <= 32'd0;
                end
            end

            `ALU_LW : begin
                r_data <= { mem[r_addr >> 2][7:0], mem[r_addr >> 2][15:8], mem[r_addr >> 2][23:16], mem[r_addr >> 2][31:24]};
            end

            default : begin
                r_data <= 32'd0;
            end
        endcase
    end


endmodule
