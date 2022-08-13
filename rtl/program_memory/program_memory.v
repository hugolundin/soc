/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
`timescale 1us/1us

module program_memory #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 4
) (
    input logic clock,
    input logic reset,
    input [ADDRESS_WIDTH-1:0] address,
    output [DATA_WIDTH-1:0] data
);

reg [DATA_WIDTH-1:0] memory [0:2**ADDRESS_WIDTH];

initial begin
    $readmemb("memory.list", memory);
end

always @(posedge clock) begin
    
end

endmodule
