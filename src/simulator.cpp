#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>

#include "Vsoc.h"
#include "verilog/utilities.h"
const int MAX_CYCLES = 20;

int main(int argc, char** argv, char** env)
{
    Vsoc soc;

    for (vluint64_t sim_time = 0; sim_time < MAX_CYCLES; sim_time++) {
        soc.clock ^= 1;
        soc.eval();
        std::cout << soc.clock << std::endl;
    }

    soc.final();
    return 0;
}
