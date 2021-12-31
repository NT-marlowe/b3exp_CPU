`define cpu_clock_Hz 10000000

module uart(
    // Input
    input sys_clk_i,   // System clock, 100 MHz
    input sys_rstn_i,   // System reset
    input uart_wr_i,   // Raise to transmit byte
    input [7:0] uart_data_i,  // 8-bit data

    // Outputs
    // uart_busy,   // High means UART is transmitting
    output reg uart_rx_out    // UART transmit wire
);

    reg [3:0] bitcount;
    reg [8:0] shifter;
    // reg uart_rx_out;

    wire uart_busy = |bitcount[3:1];
    wire sending = |bitcount;


    // sys_clk_i is 100MHz.  We want a 115200Hz clock
    reg [28:0] d;
    wire [28:0] dInc = d[28] ? (115200) : (115200 - `cpu_clock_Hz);
    wire [28:0] dNxt = d + dInc;
    always @(posedge sys_clk_i or negedge sys_rstn_i) begin
        if (!sys_rstn_i) begin
            d <= 29'b0;
        end 
        else begin
            d <= dNxt;
        end
    end
    wire ser_clk = ~d[28]; // this is the 115200 Hz clock

    always @(posedge sys_clk_i or negedge sys_rstn_i) begin
        if (!sys_rstn_i) begin
            uart_rx_out <= 1;
            bitcount <= 0;
            shifter <= 0;
        end 
        else begin
            // just got a new byte
            if (uart_wr_i & ~uart_busy) begin
                shifter <= { uart_data_i[7:0], 1'h0 };
                bitcount <= (1 + 8 + 2);
            end

            if (sending & ser_clk) begin
                { shifter, uart_rx_out } <= { 1'h1, shifter };
                bitcount <= bitcount - 1;
            end
        end
    end

endmodule