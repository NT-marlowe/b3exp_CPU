#!/bin/sh
verilator --cc cpu.v -exe test_bench.cpp
make -C obj_dir -f Vcpu.mk
#timeout 1 ./obj_dir/Vcpu > opAndResult.trace
./obj_dir/Vcpu 


