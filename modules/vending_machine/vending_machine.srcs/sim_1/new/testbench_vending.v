`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/29/2021 01:58:58 PM
// Design Name: 
// Module Name: testbench_vending
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench_vending();
    reg clk;
    reg rst;
    reg [7:0] sw;
    wire [7:0] led;
    
    wire [1:0] oldSw, currentState;
    wire [1:0] result;
    
    assign oldSw = sw[1:0];
    assign result = led[1:0];
//    assign currentState
    top_module T0(
        .sysclk(clk),
        .cpu_resetn(rst),
        .sw(sw),
        .led(led)   
    );
    
    initial begin
        clk <= 1'b0;
        rst <= 1'b0;
        sw <= 8'b0;
        #7;
        rst <= 1'b1; 
    end
    
    always #5 begin
        clk <= ~clk;
    end    
    
    task wait_posedge_clk;
        input   n;
        integer n;

        begin
            for(n=n; n>0; n=n-1) begin
                @(posedge clk)
                    ;
            end
        end
    endtask
    
    
    initial begin
        wait_posedge_clk(4);
        // 100 yen in 
        sw <= 8'b00000010;
//        wait_posedge_clk(10);
        wait_posedge_clk(10);
        sw <= 8'b00000000;
        // 100 yen in 
        wait_posedge_clk(10);

        sw <= 8'b00000010;
        wait_posedge_clk(10);
        // 50 yen in 
//        sw <= 8'b00110101;
//        wait_posedge_clk(10);
//        // 50 yen in 
//        sw <= 8'b01010101;
//        wait_posedge_clk(10);
//        sw <= 8'b01010101;  
     
        $finish;
    end    
    
endmodule
