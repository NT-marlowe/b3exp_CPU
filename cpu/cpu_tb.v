`timescale 1ns / 1ps
module cpu_tb;

    reg sysclk;
    reg cpu_resetn;
    wire uart_rx_out;

    parameter CYCLE = 100;
    parameter LONG_TIME = 1000000;

    always #(CYCLE / 2) sysclk = ~sysclk;

    cpu cpu0 (
        .sysclk(sysclk),
        .cpu_resetn(cpu_resetn),
        .uart_rx_out(uart_rx_out)
    );

    initial begin
        #10     sysclk = 1'd0;
                cpu_resetn = 1'd0;
        #(CYCLE) cpu_resetn = 1'd1;
        #(LONG_TIME) $finish;
    end
    
endmodule