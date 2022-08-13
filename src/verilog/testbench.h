#pragma once

#include <string>
#include <sstream>
#include <functional>

#include "doctest.h"

template <class DUT>
class Testbench {
public:
    Testbench()
    {
        if (trace()) {
            Verilated::traceEverOn(true);
            m_dut.trace(&m_trace, 10);
        }
    }

    ~Testbench()
    {
        m_dut.final();
    }

    DUT& dut() { return m_dut; }

    void wait_for_rising_edge()
    {
        
        while (true) {
            m_time += 1;
            m_dut.clk ^= 1;
            m_dut.eval();
            dump_if_enabled();

            if (m_dut.clk == 1) {
                break;
            }
        }
    }

    void wait_for_rising_edges(size_t count)
    {
        for (int i = 0; i < count; i++) {
            wait_for_rising_edge();
        }
    }

    void test(const std::string &name, std::function<void()> test)
    {
        std::stringstream trace_name;
        trace_name << name << ".vcd";

        if (trace()) {    
            m_trace.open(trace_name.str().c_str());
            
            // We want to dump the initial state before clocking.
            m_dut.eval();
            dump_if_enabled();
        }

        SUBCASE(name.c_str()) {
            test();
        }

        if (trace()) {
            std::stringstream command;
            command << "gtkwave " << trace_name.str();

            m_trace.close();
            system(command.str().c_str());
        }
    }

private:
    DUT m_dut;
    bool m_waves;
    vluint64_t m_time = 0;
    VerilatedVcdC m_trace;

    void dump_if_enabled()
    {
        if (trace()) {
            m_trace.dump(m_time);
        }
    }

    bool trace()
    {
        if (getenv("TRACE")) {
            return true;
        }

        return false;
    }
};
