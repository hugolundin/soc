
tests = executable('tests',
    ['test_soc.cpp', 'test_program_memory.cpp'] + verilator_sources + rtl_headers,
    link_with: rtl_libraries + [verilog],
    include_directories: includes,
    cpp_args: '-Wno-non-virtual-dtor'
)

test('soc', tests)
