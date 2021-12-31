`include "define.vh"

module mux_4in (
    input [1:0] mux_s,
    input [31:0] mux_in_a, mux_in_b, mux_in_c, mux_in_d,
    output [31:0] mux_out
);  
    assign mux_out = (mux_s == 2'b00) ? mux_in_a : 
                        ((mux_s == 2'b01) ? mux_in_b : 
                            ((mux_s == 2'b10) ? mux_in_c : 
                                ((mux_s == 2'b11) ? mux_in_d : 32'b0)));

    // always @(*) begin
        // case (mux_s) 
        //     2'b00 : assign mux_out = mux_in_a;
        //     2'b01 : assign mux_out = mux_in_b;
        //     2'b10 : assign mux_out = mux_in_c;
        //     2'b11 : assign mux_out = mux_in_d;
        //     default : assign mux_out = 32'b0;
        // endcase
    // end

    // assign mux_out = ()
    // if (mux_s == 2'b00) begin
    //     assign mux_out = mux_in_a;
    // end

    // else if (mux_s == 2'b01) begin
    //     assign mux_out = mux_in_b;
    // end
    
    // else if (mux_s == 2'b10) begin
    //     assign mux_out = mux_in_c;
    // end
    
    // else if (mux_s == 2'b11) begin
    //     assign mux_out = mux_in_d;
    // end
    
    // else begin
    //     assign mux_out = 32'b0;
    // end
endmodule