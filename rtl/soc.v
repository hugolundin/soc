`timescale 1us/1us

module soc (
  input logic clock, d,
  output logic q
);

always @(posedge clock) begin
  q <= d;
end

endmodule
