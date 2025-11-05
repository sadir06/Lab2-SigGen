module rom (
    input  logic       clk,
    input  logic [7:0] addr,  // 8-bit address (for 2^8 = 256 words)
    output logic [7:0] dout   // 8-bit data output
);

    // 1. Declare the 256-word x 8-bit memory
    logic [7:0] mem [256];

    // 2. Initialize the memory from the .mem file
    // This runs once at the start of the simulation
    initial begin
        $readmemh("sinerom.mem", mem);
    end

    // 3. Read from the memory (Synchronous read)
    // On the positive edge of the clock,
    // output the data at the given address.
    always_ff @(posedge clk) begin
        dout <= mem[addr];
    end

endmodule

