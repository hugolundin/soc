modules = {
    'soc': ['soc.v'],
    'program_memory': ['program_memory/program_memory.v']
}

rtl_headers = []
rtl_libraries = []
verilator = find_program('verilator', required: true)

foreach name, sources : modules
    top = f'V@name@'
    header = f'@top@.h'
    library = f'@top@__ALL.a'
    
    rtl = custom_target(name,
        input: sources,
        output: [header, library],
        command: [
            verilator, 
            '--CFLAGS', '-DVL_TIME_STAMP64',
            '-Wall',
            '--cc',
            '--build', '@INPUT@',
            '--Mdir', 'rtl',
            '--trace',
            '--timescale-override', '/1fs',
            '--clk', 'clock'
        ],
        build_by_default: true
    )

    rtl_headers += rtl[0]
    rtl_libraries += rtl[1]
endforeach
