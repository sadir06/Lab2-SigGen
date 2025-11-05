#!/bin/sh

# 1. Go to the correct (task2) directory
cd /mnt/c/Users/sadir/Documents/Github_Projects_2/Lab2-SigGen/task2

# 2. Cleanup old files
rm -rf obj_dir
rm -f dual_sinegen.vcd

# 3. Run Verilator with the correct files for Task 2
#    We list all .sv files: dual_sinegen.sv, counter.sv, dual_port_rom.sv
#    We specify our new top module and testbench
verilator -Wall --cc --trace \
    --top-module dual_sinegen \
    dual_sinegen.sv counter.sv dual_port_rom.sv \
    --exe dual_sinegen_tb.cpp

# 4. Build the C++ project
#    Note: Verilator names the makefile "Vdual_sinegen.mk"
make -j -C obj_dir/ -f Vdual_sinegen.mk Vdual_sinegen

# 5. Run the executable
#    Note: Verilator names the executable "Vdual_sinegen"
obj_dir/Vdual_sinegen

