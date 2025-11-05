module dual_port_rom ( //A 256-word by 8-bit DAUL-PORT Read-Only Memory
    input logic clk,
    input logic [7:0] addr1, 
    input logic [7:0] addr2, 
    output logic [7:0] dout1, 
    output logic [7:0] dout2
);

    //Declare the 256-word x 8-bit memory (shared)
    logic [7:0] mem [256];

    //Initialise the memory from the .mem file
    initial begin
        $readmemh("sinerom.mem", mem);
    end

    //Read logic
    //Both ports read from the same memory on the same clock.
    always_ff @ (posedge clk) begin
        dout1 <= mem[addr1];
        dout2 <= mem[addr2];
    end

endmodule

