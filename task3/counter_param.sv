module counter_param #(
    parameter WIDTH = 9 //Default to 9 bits
) (
    input logic clk,
    input logic rst,
    input logic en,
    output logic [WIDTH-1:0] count
);

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            count <= 0;
        else if (en)
            count <= count + 1;
    end

endmodule

