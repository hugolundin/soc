#include <verilated.h>
#include <verilated_vcd_c.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "verilog/doctest.h"

#include "Vsoc.h"
#include "verilog/utilities.h"
#include "verilog/testbench.h"

TEST_CASE("soc")
{
    Testbench<Vsoc> tb;
    
    tb.test("clock", [&]{
        REQUIRE(tb.dut().clk == 0);
    });
}
