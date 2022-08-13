
executable('simulator',
    ['simulator.cpp', 'utilities.cpp']  + verilator_sources + rtl_headers,
    include_directories: [includes],
    link_with: rtl_libraries,
    cpp_args: '-Wno-non-virtual-dtor'
)
