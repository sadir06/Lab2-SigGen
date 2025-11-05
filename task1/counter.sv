module counter (
    input logic clk,
    input logic rst, 
    input logic en, 
    input logic [7:0] incr, //Amount to increment by
    output logic [7:0] count
);

    // This is a sequential block that triggers on
    // the positive edge of the clock OR the positive edge of reset.

    always_ff @ (posedge clk or posedge rst) begin
        if (rst)
            count <= 8'b0; // Reset count to 0 (this is now asynchronous)
        else if (en)
            count <= count + incr; // Add the increment value to count
    end

endmodule
