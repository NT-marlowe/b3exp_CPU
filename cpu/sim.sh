#!/bin/sh
​
verilator --cc cpu.v -exe test_bench.cpp
make -C obj_dir -f Vcpu.mk
timeout 1 ./obj_dir/Vcpu > ans.trace
sed -e '1d' -i ans.trace
sed -e '765001,$d' -i ans.trace
diff /home/denjo/WorkSpace/irie_jikken/CoreMark_RV32I.trace ans.trace > diff.trace
