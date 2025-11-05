module sinegen (
    input logic clk, 
    input logic rst, 
    input logic en, 
    input logic [7:0] incr,
    output logic [7:0] dout
);

    //This connects the counter's output to the ROM's input
    logic [7:0] rom_address;

    //We connect this file's top-level inputs
    //and it's output to oour internal wire
    counter u_counter (
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(incr),
        .count(rom_address) //Output goes to the wire
    );

    //Finally, we instantiate the ROM
    //We connect its clock, its address input
    //From out internal wire, and its output to the top-level output
    rom u_rom (
        .clk(clk),
        .addr(rom_address), //Input comes from the wire
        .dout(dout) 
    );

endmodule


