project(
    'soc',
    'cpp',
    version: '0.0.1',
    license: 'MIT',
    default_options : ['cpp_std=c++11']
)

verilator_path = get_option('verilator')
verilator_sources = [
    f'@verilator_path@/verilated.cpp',
    f'@verilator_path@/verilated_vcd_c.cpp'
]

includes = include_directories([
    'src',
    verilator_path,
    '.'
])

subdir('rtl')
subdir('src')
subdir('tests')
