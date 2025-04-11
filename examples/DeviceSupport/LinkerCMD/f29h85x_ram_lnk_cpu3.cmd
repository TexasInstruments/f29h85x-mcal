--entry_point="code_start"
--retain="reset_vector"


/* Specify the system memory map */

MEMORY
{
    SRAM_CDA2_11    : o=0x20128000, l=0x28000
    SRAM_CPA1       : o=0x20118000, l=0x8000
}

/* Specify the sections allocation into memory */

SECTIONS
{
    resetvector : {} > 0x20118000,  palign(8)
    codestart   : {} > SRAM_CPA1,   palign(8)
    .text       : {} > SRAM_CPA1,   palign(8)
    .binit      : {} > SRAM_CPA1,   palign(8)
    .cinit      : {} > SRAM_CPA1,   palign(8)
    .const      : {} > SRAM_CPA1,   palign(8)
    .rodata     : {} > SRAM_CPA1,   palign(8)
    .init_array : {} > SRAM_CPA1,   palign(8)
    .TI.ramfunc : {} > SRAM_CPA1,   palign(8)

    .data       : {} > SRAM_CDA2_11
    .bss        : {} > SRAM_CDA2_11
    .stack      : {} > SRAM_CDA2_11
    .sysmem     : {} > SRAM_CDA2_11
}