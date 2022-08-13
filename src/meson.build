
subdir('verilog')

executable('simulator',
    ['simulator.cpp']  + verilator_sources + rtl_headers,
    include_directories: [includes],
    link_with: rtl_libraries + [verilog],
    cpp_args: '-Wno-non-virtual-dtor'
)

