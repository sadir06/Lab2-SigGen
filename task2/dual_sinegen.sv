module dual_sinegen (
    input  logic       clk,
    input  logic       rst,
    input  logic       en,
    input  logic [7:0] offset, // NEW: Phase offset from Vbuddy
    output logic [7:0] dout1,  // NEW: Output for wave 1
    output logic [7:0] dout2   // NEW: Output for wave 2
);

    // Internal wires
    logic [7:0] counter_out; // Address 1
    logic [7:0] offset_addr; // Address 2

    // 1. Instantiate the counter
    // This runs at a fixed speed (incr=1 from testbench)
    counter u_counter (
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(1), // We use a fixed increment of 1
        .count(counter_out)
    );
    
    // 2. Calculate the second address
    // This is just Address 1 + the phase offset
    assign offset_addr = counter_out + offset;

    // 3. Instantiate the Dual-Port ROM
    dual_port_rom u_rom (
        .clk(clk),
        .addr1(counter_out), // Port 1 gets the direct counter address
        .addr2(offset_addr), // Port 2 gets the offset address
        .dout1(dout1),       // Output for wave 1
        .dout2(dout2)        // Output for wave 2
    );

endmodule




