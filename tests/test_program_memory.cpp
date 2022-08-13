#include <verilated.h>
#include <verilated_vcd_c.h>

#include "verilog/doctest.h"

#include "Vprogram_memory.h"
#include "verilog/utilities.h"
#include "verilog/testbench.h"

TEST_CASE("PM")
{
    Testbench<Vprogram_memory> tb;
    tb.wait_for_rising_edge();
    tb.wait_for_rising_edge();
    tb.wait_for_rising_edge();
    tb.wait_for_rising_edge();

    tb.test("clock", [&]{
        REQUIRE(tb.dut().clock == 0);
    });
}
