#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsinegen.h"      // Include the Verilated model of our top-level module

#include "vbuddy.cpp"      // include vbuddy code
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 8    // Note: This is for documentation, not used by C++
#define ROM_SZ 256         // Note: This is for documentation, not used by C++

int main(int argc, char **argv, char **env) {
    int simcyc; // Simulation clock count
    int tick;   // each clk cycle has two ticks for two edges

    // Initialize Verilator and command line arguments
    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vsinegen* top = new Vsinegen;
    
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen.vcd"); // Corrected: This line MUST have quotes
 
    // init Vbuddy
    if (vbdOpen() != 1) return(-1);
    vbdHeader("L2T1: SigGen");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = 1;

    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {
        
        // dump variables into VCD file and toggle clock
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }
        
        // Read rotary encoder and update increment value
        top->incr = vbdValue();
        
        // plot ROM output and print cycle count
        vbdPlot(int(top->dout), 0, 255);
        vbdCycle(simcyc);

        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()) || (vbdGetkey() == 'q')) {
            exit(0); // ... exit if finish OR 'q' pressed
        }
    }

    // Cleanup
    vbdClose();
    tfp->close();
    exit(0);
}
