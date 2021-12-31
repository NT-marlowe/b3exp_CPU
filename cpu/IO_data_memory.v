`include "define.vh"

module IO_data_memory (
    input is_load, is_store,
    input [5:0] alucode,
    input [1:0] shift_r, shift_w,
    input [31:0] w_data_unprocessed, r_data_unprocessed,
    output [31:0] w_data_processed,  r_data_processed,
    output [3:0] we
);  

    function [31:0] r_data_processing;
        input is_load;
        input [5:0] alucode;
        input [1:0] shit_r;
        input [31:0] r_data_unprocessed;
        if (is_load == `ENABLE) begin
            case (alucode) 
                `ALU_LB : begin
                    if (shift_r == 2'd0) begin
                        r_data_processing = { {24{r_data_unprocessed[ 7]}}, r_data_unprocessed[ 7: 0] };
                    end
                    else if (shift_r == 2'd1) begin
                        r_data_processing = { {24{r_data_unprocessed[15]}}, r_data_unprocessed[15: 8] };
                    end
                    else if (shift_r == 2'd2) begin
                        r_data_processing = { {24{r_data_unprocessed[23]}}, r_data_unprocessed[23:16] };
                    end
                    else if (shift_r == 2'd3) begin
                        r_data_processing = { {24{r_data_unprocessed[31]}}, r_data_unprocessed[31:24] };
                    end
                    else begin
                        r_data_processing = 32'd0;
                    end
                end

                `ALU_LBU : begin
                    if (shift_r == 2'd0) begin
                        r_data_processing = { 24'd0, r_data_unprocessed[ 7: 0] };
                    end
                    else if (shift_r == 2'd1) begin
                        r_data_processing = { 24'd0, r_data_unprocessed[15: 8] };
                    end 
                    else if (shift_r == 2'd2) begin
                        r_data_processing = { 24'd0, r_data_unprocessed[23:16] };
                    end 
                    else if (shift_r == 2'd3) begin
                        r_data_processing = { 24'd0, r_data_unprocessed[31:24] };
                    end
                    else begin
                        r_data_processing = 32'd0;
                    end
                end

                `ALU_LH : begin
                    if (shift_r == 2'd0) begin
                        r_data_processing = { {16{r_data_unprocessed[15]}}, r_data_unprocessed[15: 0] };
                    end
                    else if (shift_r == 2'd1) begin
                        r_data_processing = { {16{r_data_unprocessed[23]}}, r_data_unprocessed[23: 8] };
                    end
                    else if (shift_r == 2'd2) begin
                        r_data_processing = { {16{r_data_unprocessed[31]}}, r_data_unprocessed[31: 16] };
                    end
                    else begin
                        r_data_processing = 32'd0;
                    end
                end

                `ALU_LHU : begin
                    if (shift_r == 2'd0) begin
                        r_data_processing = { 16'd0, r_data_unprocessed[15: 0] };
                    end
                    else if (shift_r == 2'd1) begin
                        r_data_processing = { 16'd0, r_data_unprocessed[23: 8] };
                    end
                    else if (shift_r == 2'd2) begin
                        r_data_processing = { 16'd0, r_data_unprocessed[31: 16] };
                    end
                    else begin
                        r_data_processing = 32'd0;
                    end
                end

                `ALU_LW : begin
                    if (shift_r == 2'd0) begin
                        r_data_processing = r_data_unprocessed;
                    end
                    else begin
                        r_data_processing = 32'd0;
                    end
                end

                default : begin
                    r_data_processing = 32'd0;
                end
            endcase
        end
        else begin
            r_data_processing = 32'd0;
        end
    endfunction


    function [3:0] generate_we;
        input is_store;
        input [5:0] alucode;
        input [1:0] shift_w;
        if (is_store == `ENABLE) begin
            case (alucode) 
                `ALU_SB : begin
                    case (shift_w) 
                        2'd0 : generate_we = 4'b0001;
                        2'd1 : generate_we = 4'b0010;
                        2'd2 : generate_we = 4'b0100;
                        2'd3 : generate_we = 4'b1000;
                        default : generate_we = 4'b0000;
                    endcase
                end

                `ALU_SH : begin
                    case (shift_w)
                        2'd0 : generate_we = 4'b0011;
                        2'd1 : generate_we = 4'b0110;
                        2'd2 : generate_we = 4'b1100;
                        default : generate_we = 4'b0000;
                    endcase
                end

                `ALU_SW : begin
                    if (shift_w == 2'd0) generate_we = 4'b1111;
                    else generate_we = 4'b0000;
                end
                
                default : generate_we = 4'b0000;
            endcase
        end
        else begin
            generate_we = 4'b0000;
        end
    endfunction


    assign r_data_processed = r_data_processing(is_load, alucode, shift_r, r_data_unprocessed);
    assign w_data_processed = w_data_unprocessed << (8 * shift_w);
    assign we = generate_we(is_store, alucode, shift_w);
    
endmodule