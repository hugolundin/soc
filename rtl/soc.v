`timescale 1us/1us

module soc (
  input logic clk, d,
  output logic q
);

always @(posedge clk) begin
  q <= d;
end

endmodule
