testbench = library('libtestbench',
    ['testbench.h', 'doctest.h']
)

tests = executable('tests',
    ['test_soc.cpp'] + verilator_sources + rtl_headers,
    link_with: rtl_libraries + [testbench],
    include_directories: includes,
    cpp_args: '-Wno-non-virtual-dtor'
)

test('soc', tests)
