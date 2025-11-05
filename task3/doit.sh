#!/bin/sh

# 1. Go to the task3 directory
cd /mnt/c/Users/sadir/Documents/Github_Projects_2/Lab2-SigGen/task3

# 2. Cleanup
rm -rf obj_dir
rm -f sigdelay.vcd

# 3. Run Verilator
#    List all THREE .sv files for Task 3
verilator -Wall --cc --trace \
    --top-module sigdelay \
    sigdelay.sv counter_param.sv dual_port_ram.sv \
    --exe sigdelay_tb.cpp

# 4. Build the C++ project
#    The makefile and target are now Vsigdelay
make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay

# 5. Run the executable
obj_dir/Vsigdelay

