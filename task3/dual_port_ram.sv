module dual_port_ram(
    input logic clk,

    //Write Port
    input logic we, //Write Enable
    input logic [8:0] waddr, //9-bit Write Address
    input logic [7:0] din, //8-bit Data Input

    //Read Port
    input logic [8:0] raddr, //9-bit Read Address
    output logic [7:0] dout //8-bit Data output
);

    //Declare the 512-word x 8-bit memory
    logic[7:0] mem [512];

    //On the clock edge, if write is enabled, write data to waddr
    always_ff @(posedge clk) begin
        if (we) begin
            mem[waddr] <= din;
        end
    end

    //On clock edge, ouput the data from raddr
    always_ff @(posedge clk) begin
        dout <= mem[raddr];
    end

endmodule


