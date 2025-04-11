--entry_point="code_start"
--retain="reset_vector"


/* Specify the system memory map */

MEMORY
{
    SRAM_CDA2_11    : o=0x20128000, l=0x28000
    SRAM_CPA1       : o=0x20118000, l=0x8000

    FLASH_RP0       : o=0x10400000, l=0x100000
}


/* Specify the sections allocation into memory */

SECTIONS
{
    resetvector   : {} > 0x10400000,      palign(8)
    codestart     : {} > FLASH_RP0,       palign(8)
    .text         : {} > FLASH_RP0,       palign(8)
    .binit        : {} > FLASH_RP0,       palign(8)
    .cinit        : {} > FLASH_RP0,       palign(8)
    .const        : {} > FLASH_RP0,       palign(8)
    .rodata       : {} > FLASH_RP0,       palign(8)
    .init_array   : {} > FLASH_RP0,       palign(8)

    .TI.ramfunc   : {} LOAD=FLASH_RP0, RUN=SRAM_CPA1, table(BINIT),     palign(8)

    .data         : {} > SRAM_CDA2_11
    .bss          : {} > SRAM_CDA2_11
    .stack        : {} > SRAM_CDA2_11
    .sysmem       : {} > SRAM_CDA2_11
    .cio          : {} > SRAM_CDA2_11
}