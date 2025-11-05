#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vdual_sinegen.h"  // Changed: Include new module
#include "vbuddy.cpp"

#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    // Changed: Instantiate new module
    Vdual_sinegen* top = new Vdual_sinegen;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    // Changed: New VCD filename
    tfp->open("dual_sinegen.vcd");
 
    if (vbdOpen() != 1) return(-1);
    // Changed: New Vbuddy header
    vbdHeader("L2T2: Dual Sine/Cosine");

    // Initialize inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    // Note: 'incr' is now fixed at 1 inside the Verilog
    // 'offset' is our new variable input
    top->offset = 0; 

    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {
        
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }
        
        // --- Key Change ---
        // The rotary encoder now controls the phase OFFSET,
        // not the frequency increment.
        top->offset = vbdValue();
        
        // --- Key Change ---
        // Plot BOTH waveforms
        vbdPlot(int(top->dout1), 0, 255);
        vbdPlot(int(top->dout2), 0, 255);

        vbdCycle(simcyc);

        if ((Verilated::gotFinish()) || (vbdGetkey() == 'q')) {
            exit(0);
        }
    }

    vbdClose();
    tfp->close();
    exit(0);
}
