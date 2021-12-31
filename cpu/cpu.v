`include "define.vh"
module cpu (
    input sysclk,
    input cpu_resetn,
    output uart_rx_out 
);

    wire [31:0] ir;
    wire [4:0] srcreg1_num, srcreg2_num, dstreg_num;
    wire [31:0] imm;
    wire [31:0] ma_load_data; // ハードウェアカウンタ
    reg [31:0] pc;
    wire [6:0] opcode;
    wire [5:0] alucode;
    wire [1:0] aluop1_type, aluop2_type;
    wire reg_we; 
    wire is_load;
    wire is_store;
    wire is_halt;

    wire [31:0] rs1_data, rs2_data;
    wire [31:0] w_data;
    wire [31:0] r_data_unprocessed;
    
    wire [31:0] alu_result;
    wire br_taken;
    
    wire [31:0] npc;
    always @(posedge sysclk) begin
        if (!cpu_resetn) pc <= 32'h07ffc;
        else pc <= npc;
        
        // $write("0x%h", pc[15:0], ": ","0x%h",ir," # ");
        // if (dstreg_num == 5'h0)begin
        //     $write("(no destination)"); 
        // end
        // else begin
        //     if (dstreg_num < 5'd10)begin
        //         $write("x0%1d = 0x%h", dstreg_num, w_data);
        //     end
        //     else begin
        //         $write("x%d = 0x%h",dstreg_num, w_data);
        //     end
        // end
        // if (is_store)begin
        //     case (alucode)
        //         // `ALU_SB: $write("SB; mem[0x%h] <- 0x%h", alu_result, rs2_data[7:0]);
        //         // `ALU_SH: $write("SH; mem[0x%h] <- 0x%h", alu_result, rs2_data[15:0]);
        //         // `ALU_SW: $write("SW; mem[0x%h] <- 0x%h", alu_result, rs2_data);
        //         `ALU_SB: $write("; mem[0x%h] <- 0x%h", alu_result, rs2_data[7:0]);
        //         `ALU_SH: $write("; mem[0x%h] <- 0x%h", alu_result, rs2_data[15:0]);
        //         `ALU_SW: $write("; mem[0x%h] <- 0x%h", alu_result, rs2_data); 
        //         default : ;
        //     endcase
        // end
        // if (is_load)begin
        //     case (alucode)
        //         // `ALU_LB,`ALU_LBU:  $write("LB;            0x%h <- mem[0x%h]", w_data[7:0], alu_result);
        //         // `ALU_LH,`ALU_LHU:  $write("LH;          0x%h <- mem[0x%h]", w_data[15:0], alu_result);
        //         // `ALU_LW: $write(";      0x%h <- mem[0x%h]", w_data, alu_result); 
        //         default : ;
        //         `ALU_LB,`ALU_LBU:  $write(";            0x%h <- mem[0x%h]", w_data[7:0], alu_result);
        //         `ALU_LH,`ALU_LHU:  $write(";          0x%h <- mem[0x%h]", w_data[15:0], alu_result);
        //         `ALU_LW: $write(";      0x%h <- mem[0x%h]", w_data, alu_result); 
        //     endcase
        // end
        // $write("\n");
    end
    
    wire [7:0] uart_IN_data;
    wire uart_we;
    wire uart_OUT_data;
    uart uart_0 (
        .sys_clk_i(sysclk),
        .sys_rstn_i(cpu_resetn),
        .uart_wr_i(uart_we),
        .uart_data_i(uart_IN_data),
        .uart_rx_out(uart_OUT_data)
    );


    wire [31:0] hc_OUT_data;
    hardware_counter hardware_counter0 (
        .CLK_IP(sysclk),
        .RSTN_IP(cpu_resetn),
        .COUNTER_OP(hc_OUT_data)
    );


    decoder decoder_0 (
        .ir(ir),
        .srcreg1_num(srcreg1_num),
        .srcreg2_num(srcreg2_num),
        .dstreg_num(dstreg_num),
        .imm(imm),
        .opcode(opcode),
        .alucode(alucode),
        .aluop1_type(aluop1_type),
        .aluop2_type(aluop2_type),
        .reg_we(reg_we),
        .is_load(is_load),
        .is_store(is_store),
        .is_halt(is_halt)
    );


    register_file register_file0 (
        .clk(sysclk),
        .reg_we(reg_we),
        .rs1_addr(srcreg1_num),
        .rs2_addr(srcreg2_num),
        .w_addr(dstreg_num),
        .w_data(w_data),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    wire [31:0] npc_op1, npc_op2;
    wire [31:0] alu_op1, alu_op2;

    mux_4in mux_4in0 (
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm(imm),
        .pc(pc),
        .opcode(opcode),
        .op1_type(aluop1_type),
        .op2_type(aluop2_type),
        .npc_op1(npc_op1),
        .npc_op2(npc_op2),
        .alu_op1(alu_op1),
        .alu_op2(alu_op2)
    );


    alu alu0 (
        .alucode(alucode),
        .op1(alu_op1),
        .op2(alu_op2),
        .alu_result(alu_result),
        .br_taken(br_taken)
    );


    nextPC nextPC0 (
        .br_taken(br_taken),
        .npc_op1(npc_op1), 
        .npc_op2(npc_op2), 
        .pc(pc),
        .npc(npc)
    );

    wire [3:0] we;
    wire [31:0] r_data_processed, w_data_processed;

    IO_data_memory IO_data_memory0 (
        .is_load(is_load),
        .is_store(is_store),
        .alucode(alucode),
        .shift_r(alu_result[1:0]),
        .shift_w(alu_result[1:0]),
        .w_data_unprocessed(rs2_data),
        .r_data_unprocessed(r_data_unprocessed),
        .w_data_processed(w_data_processed),
        .r_data_processed(r_data_processed),
        .we(we)
    );

    data_memory data_memory0 (
        .clk(sysclk),
        .we(we),
        .r_addr(alu_result[16:0]),
        .w_addr(alu_result[16:0]),
        .w_data(w_data_processed),
        .r_data(r_data_unprocessed)
    );

    mux_2in mux_2in0 (
        .opcode(opcode),
        .mux_ALU_out(alu_result),
        .mux_load_data(ma_load_data),
        .w_data(w_data)
    );

    inst_memory inst_memory (
        .clk(sysclk),
        .pc(npc),
        .ir(ir)
    );

    // ストアするデータ：rs2_data(data_memoryのw_data)
    // ストア先のアドレス：alu_result[16:0](data_memoryのw_addr)
    // `UART_ADDRが32ビットなので比較のためにalu_resultをすべて取る．
    assign uart_IN_data = rs2_data[7:0];
    assign uart_we = ( (alu_result == `UART_ADDR) && (is_store == `ENABLE) ) ? 1'b1 : 1'b0;
    assign uart_rx_out = uart_OUT_data;

    // ハードウェアカウンタの出力
    assign ma_load_data = ( (alucode == `ALU_LW) && (alu_result == `HARDWARE_COUNTER_ADDR)) ? hc_OUT_data : r_data_processed;

endmodule