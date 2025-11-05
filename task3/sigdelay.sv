module sigdelay (
    input logic clk, 
    input logic rst, 

    input logic wr,
    input logic rd, 
    input logic [7:0] mic_signal,
    input logic [8:0] offset, 
    output logic [7:0] delayed_signal
);

    //Internal Wires
    logic [8:0] write_addr; //9-bit address from counter
    logic [8:0] read_addr; //9-bit address for reading

    //Instantiate the 9-bit counter
    counter_param #(
        .WIDTH(9)
    ) u_counter (
        .clk(clk),
        .rst(rst),
        .en(rd), //The read signal acts as the counter enable
        .count(write_addr)
    );

    //Calculate the read address
    assign read_addr = write_addr - offset;

    //Instantiate the Dual-Port RAM
    dual_port_ram u_ram (
        .clk(clk),
        .we(wr),
        .waddr(write_addr),
        .din(mic_signal),

        .raddr(read_addr),
        .dout(delayed_signal)
    );

endmodule


