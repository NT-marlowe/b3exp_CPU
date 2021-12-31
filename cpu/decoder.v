`include "define.vh"

module decoder(
    input wire [31:0] ir,
    output wire [4:0] srcreg1_num,
    output wire [4:0] srcreg2_num,
    output wire [4:0] dstreg_num,
    output wire [31:0] imm,
    output reg [6:0] opcode, // オペコードがnextPCの生成に必要だった．
    output reg [5:0] alucode,
    output reg [1:0] aluop1_type,
    output reg [1:0] aluop2_type,
    output reg reg_we, // レジスタ書き込みの有無
    output reg is_load,
    output reg is_store,
    output reg is_halt
);  
    // オペコード
    wire [6:0] op1 = ir[6:0];

    wire [2:0] op2 = ir[14:12];
    wire [6:0] op3 = ir[31:25];

    function [4:0] reg1;
        input [31:0] ir;
        input [6:0] opcode;
        case (opcode) 
            `LUI, `AUIPC, `JAL : reg1 = 5'b0;
            `JALR, `BRANCH, `LOAD, `STORE, `OPIMM, `OP : reg1 = ir[19:15];
            default : reg1 = 5'b0;
        endcase
    endfunction

    function [4:0] reg2;
        input [31:0] ir;
        input [6:0] opcode;
        case (opcode)
            `BRANCH, `STORE, `OP : reg2 = ir[24:20];
            `LUI, `AUIPC, `JAL, `JALR, `LOAD, `OPIMM : reg2 = 5'b0;
            default : reg2 = 5'b0;
        endcase
    endfunction

    function [4:0] dstreg;
        input [31:0] ir;
        input [6:0] opcode;
        case (opcode)
            `BRANCH, `STORE : dstreg = 5'b0;
            `LUI, `AUIPC, `JAL, `JALR, `LOAD, `OPIMM, `OP : dstreg = ir[11:7];
            default : dstreg = 5'b0;
        endcase
    endfunction

    function [31:0] imm_func;
        input [31:0] ir;
        input [6:0] opcode;
        case (opcode) 
            `OPIMM : begin
                case (ir[14:12])
                    3'b001, 3'b101 : imm_func = {{27{ir[24]}}, ir[24:20]};
                    3'b000, 3'b010, 3'b011, 3'b100, 3'b110, 3'b111 : imm_func = { {20{ir[31]}}, ir[31:20] };
                    default : imm_func = 32'b0;
                endcase
            end
            
            `OP : begin
                imm_func = 32'b0;
            end

            `LUI, `AUIPC : imm_func = { ir[31:12] , {12{1'b0}} };

            `JAL : imm_func = { {12{ir[31]}}, ir[19:12], ir[20], ir[30:21], 1'b0};

            `JALR, `LOAD : imm_func = { {20{ir[31]}}, ir[31:20] };

            `BRANCH : imm_func = { {19{ir[31]}}, ir[31], ir[7], ir[30:25], ir[11:8], {1'b0} };

            `STORE : imm_func = { {20{ir[31]}}, ir[31:25], ir[11:7]};

            default : imm_func = 32'b0;
        endcase
    endfunction

    assign srcreg1_num = reg1(ir, op1);
    assign srcreg2_num = reg2(ir, op1);
    assign dstreg_num = dstreg(ir, op1);
    assign imm = imm_func(ir, op1);
    
    always @(*) begin
        opcode = op1;
        case (op1) 
            `LUI : begin
                alucode = `ALU_LUI;
                aluop1_type = `OP_TYPE_NONE;
                aluop2_type = `OP_TYPE_IMM;
                reg_we = `ENABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `AUIPC : begin
                alucode = `ALU_ADD;
                aluop1_type = `OP_TYPE_IMM;
                aluop2_type = `OP_TYPE_PC;
                reg_we = `ENABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `JAL : begin 
                alucode = `ALU_JAL;
                aluop1_type = `OP_TYPE_NONE;
                aluop2_type = `OP_TYPE_PC;
                reg_we = (dstreg_num != 5'b0)? `ENABLE : `DISABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `JALR : begin 
                alucode = `ALU_JALR;
                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_PC;
                reg_we = (dstreg_num != 5'b0)? `ENABLE : `DISABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `BRANCH : begin
                case (op2) 
                    3'b000 : alucode = `ALU_BEQ;
                    3'b001 : alucode = `ALU_BNE;
                    3'b100 : alucode = `ALU_BLT;
                    3'b101 : alucode = `ALU_BGE;
                    3'b110 : alucode = `ALU_BLTU;
                    3'b111 : alucode = `ALU_BGEU;
                    default : alucode = `ALU_NOP;
                endcase
                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_REG;
                reg_we = `DISABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `LOAD : begin
                case (op2) 
                    3'b000 : alucode = `ALU_LB;
                    3'b001 : alucode = `ALU_LH;
                    3'b010 : alucode = `ALU_LW;
                    3'b100 : alucode = `ALU_LBU;
                    3'b101 : alucode = `ALU_LHU;
                    default : alucode = `ALU_NOP;
                endcase
                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_IMM;
                reg_we = `ENABLE;
                is_load = `ENABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `STORE : begin
                case (op2) 
                    3'b000 : alucode = `ALU_SB;
                    3'b001 : alucode = `ALU_SH;
                    3'b010 : alucode = `ALU_SW;
                    default : alucode = `ALU_NOP;
                endcase
                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_IMM;
                reg_we = `DISABLE;
                is_load = `DISABLE;
                is_store = `ENABLE;
                is_halt = `DISABLE;
            end

            `OPIMM : begin
                case (op2) 
                    3'b000 : alucode = `ALU_ADD;
                    3'b001 : alucode = `ALU_SLL;
                    3'b101 : begin
                        case (op3) 
                            7'b0000000 : alucode = `ALU_SRL;
                            7'b0100000 : alucode = `ALU_SRA;
                            default : alucode = `ALU_NOP;
                        endcase
                    end
                    3'b010 : alucode = `ALU_SLT;
                    3'b011 : alucode = `ALU_SLTU;
                    3'b100 : alucode = `ALU_XOR;
                    3'b110 : alucode = `ALU_OR;
                    3'b111 : alucode = `ALU_AND;
                    default : alucode = `ALU_NOP;
                endcase
                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_IMM;
                reg_we = `ENABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            `OP : begin
                if (op3 == 7'b0000001) begin
                    case (op2) 
                        3'b000 : alucode = `ALU_MUL;
                        3'b001 : alucode = `ALU_MULH;
                        3'b010 : alucode = `ALU_MULHSU;
                        3'b011 : alucode = `ALU_MULHU;
                        3'b100 : alucode = `ALU_DIV;
                        3'b101 : alucode = `ALU_DIVU;
                        3'b110 : alucode = `ALU_REM;
                        3'b111 : alucode = `ALU_REMU;
                        default: alucode = `ALU_NOP;
                    endcase
                end
                else begin
                    case (op2) 
                        3'b000 : begin
                            case (op3) 
                                7'b0000000 : alucode = `ALU_ADD;
                                7'b0100000 : alucode = `ALU_SUB;
                                default : alucode = `ALU_NOP;
                            endcase
                        end
                        3'b001 : alucode = `ALU_SLL;
                        3'b010 : alucode = `ALU_SLT;
                        3'b011 : alucode = `ALU_SLTU;
                        3'b100 : alucode = `ALU_XOR;
                        3'b101 : begin
                            case (op3) 
                                7'b0000000 : alucode = `ALU_SRL;
                                7'b0100000 : alucode = `ALU_SRA;
                                default : alucode = `ALU_NOP;
                            endcase
                        end
                        3'b110 : alucode = `ALU_OR;
                        3'b111 : alucode = `ALU_AND;
                        default : alucode = `ALU_NOP;
                    endcase
                end

                aluop1_type = `OP_TYPE_REG;
                aluop2_type = `OP_TYPE_REG;
                reg_we = `ENABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end

            default : begin
                alucode = `ALU_NOP;
                aluop1_type = `OP_TYPE_NONE;
                aluop2_type = `OP_TYPE_NONE;
                reg_we = `DISABLE;
                is_load = `DISABLE;
                is_store = `DISABLE;
                is_halt = `DISABLE;
            end
            
        endcase
    end


endmodule

