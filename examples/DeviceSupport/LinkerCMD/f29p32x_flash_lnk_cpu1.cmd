--entry_point="code_start"


/* Specify the system memory map */

MEMORY
{
    SRAM_LDAx           : o=0x200E0000, l=0x20000
    SRAM_LPAx           : o=0x20100000, l=0x10000
    SRAM_CPA0           : o=0x20110000, l=0x8000

    CERT                : o=0x10000000, l=0x001000
    FLASH_RP0           : o=0x10001000, l=0x0FF000
    FLASH_RP1           : o=0x10100000, l=0x100000
}


/* Specify the sections allocation into memory */

SECTIONS
{
    codestart           : {} > 0x10001000,    palign(8)
    cert                : {} > CERT,          palign(8)

    CODE:
    {
        *(.*_CODE)
    } > FLASH_RP0,     palign(8)

    ISR_CODE:
    {
        *(.*_ISR_CODE)
    } > FLASH_RP0,     palign(8)

    CONFIG_DATA:
    {
        *(.*_CONFIG_DATA_*),
        *(.*_CONFIG_DATA)
    } > FLASH_RP0,     palign(8)

    CONST:
    {
        *(.*_CONST_*)
    } > FLASH_RP0,     palign(8)

    VAR_INIT:
    {
        *(.*_VAR_INIT_*)
    } > SRAM_LDAx

    VAR_FAST_INIT:
    {
        *(.*_VAR_FAST_INIT_*)
    } > SRAM_LDAx

    VAR_NO_INIT:
    {
        *(.*_VAR_NO_INIT_*)
    } > SRAM_LDAx

    GROUP : > SRAM_LDAx
    {
        __llvm_prf_cnts
        __llvm_prf_bits
    }

    .text         : {} > FLASH_RP0,     palign(8)
    .binit        : {} > FLASH_RP0,     palign(8)
    .cinit        : {} > FLASH_RP0,     palign(8)
    .const        : {} > FLASH_RP0,     palign(8)
    .rodata       : {} > FLASH_RP0,     palign(8)
    .init_array   : {} > FLASH_RP0,     palign(8)

    .TI.ramfunc   : {} LOAD=FLASH_RP0, RUN=SRAM_LPAx, table(BINIT), palign(8)

    .data         : {} > SRAM_LDAx
    .bss          : {} > SRAM_LDAx
    .stack        : {} > SRAM_LDAx
    .sysmem       : {} > SRAM_LDAx
    .cio          : {} > SRAM_LDAx
}