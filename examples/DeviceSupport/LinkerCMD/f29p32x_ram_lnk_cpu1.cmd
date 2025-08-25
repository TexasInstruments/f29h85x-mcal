--entry_point="code_start"


/* Specify the system memory map */

MEMORY
{
    SRAM_LDAx   : o=0x200E0000, l=0x20000
    SRAM_LPAx   : o=0x20100000, l=0x10000
    SRAM_CPA0   : o=0x20110000, l=0x8000
    CPU3_CPA1   : o=0x20118000, l=0x8000

    CERT        : o=0x10000000, l=0x001000
    FLASH_RP0   : o=0x10001000, l=0x0FF000
    FLASH_RP1   : o=0x10100000, l=0x100000
}



/* Specify the sections allocation into memory */

SECTIONS
{
    cpu3_resetvector    : {} > 0x20118000, START(CPU3_RESET_VECTOR)
    codestart           : {} > 0x20100000

    CODE:
    {
        *(.*_CODE)
    } >> SRAM_LPAx | SRAM_CPA0

    ISR_CODE:
    {
        *(.*_ISR_CODE)
    } >> SRAM_LPAx | SRAM_CPA0

    CONFIG_DATA:
    {
        *(.*_CONFIG_DATA_*),
        *(.*_CONFIG_DATA)
    } >> SRAM_LDAx

    CONST:
    {
        *(.*_CONST_*)
    } >> SRAM_LDAx

    VAR_INIT:
    {
        *(.*_VAR_INIT_*)
    } >> SRAM_LDAx

    VAR_FAST_INIT:
    {
        *(.*_VAR_FAST_INIT_*)
    } >> SRAM_LDAx

    VAR_NO_INIT:
    {
        *(.*_VAR_NO_INIT_*)
    } >> SRAM_LDAx

    GROUP : > SRAM_LDAx
    {
        __llvm_prf_cnts
        __llvm_prf_bits
    }
    
    .text         : {} >> SRAM_LPAx | SRAM_CPA0
    .TI.ramfunc   : {} >  SRAM_LPAx
    .cinit        : {} >  SRAM_CPA0
    .const        : {} >> SRAM_LDAx
    .rodata       : {} >> SRAM_LDAx
    .init_array   : {} >> SRAM_LDAx

    .data         : {} >> SRAM_LDAx
    .bss          : {} >> SRAM_LDAx
    .stack        : {} >  SRAM_LDAx
    .sysmem       : {} >  SRAM_LDAx
    .cio          : {} >  SRAM_LDAx

    cpu3app       : {} > CPU3_CPA1,   palign(8)
}