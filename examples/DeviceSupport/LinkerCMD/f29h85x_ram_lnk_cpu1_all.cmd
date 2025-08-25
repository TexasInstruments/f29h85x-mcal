--entry_point="code_start"


/* Specify the system memory map */

MEMORY
{
    SRAM_LDAx   : o=0x200E0000, l=0x20000
    SRAM_LPAx   : o=0x20100000, l=0x10000
    SRAM_CDA0_1 : o=0x20120000, l=0x8000
    SRAM_CPA0   : o=0x20110000, l=0x8000
    SRAM_CPA1   : o=0x20118000, l=0x8000

    CERT        : o=0x10000000, l=0x001000
    FLASH_RP0   : o=0x10001000, l=0x0FF000
    FLASH_RP1   : o=0x10100000, l=0x100000
}



/* Specify the sections allocation into memory */

SECTIONS
{
    codestart           : {} > 0x20100000

    CODE:
    {
        *(.*_CODE)
    } >> SRAM_LPAx | SRAM_CPA0 | SRAM_CPA1

    ISR_CODE:
    {
        *(.*_ISR_CODE)
    } >> SRAM_LPAx | SRAM_CPA0 | SRAM_CPA1

    CONFIG_DATA:
    {
        *(.*_CONFIG_DATA_*),
        *(.*_CONFIG_DATA)
    } >> SRAM_LDAx | SRAM_CDA0_1

    CONST:
    {
        *(.*_CONST_*)
    } >> SRAM_LDAx | SRAM_CDA0_1

    VAR_INIT:
    {
        *(.*_VAR_INIT_*)
    } >> SRAM_LDAx | SRAM_CDA0_1

    VAR_FAST_INIT:
    {
        *(.*_VAR_FAST_INIT_*)
    } >> SRAM_LDAx | SRAM_CDA0_1

    VAR_NO_INIT:
    {
        *(.*_VAR_NO_INIT_*)
    } >> SRAM_LDAx | SRAM_CDA0_1

    GROUP : > SRAM_LDAx
    {
        __llvm_prf_cnts
        __llvm_prf_bits
    }
    
    .text         : {} >> SRAM_LPAx | SRAM_CPA0 | SRAM_CPA1
    .TI.ramfunc   : {} >  SRAM_LPAx
    .cinit        : {} >  SRAM_CPA0 | SRAM_CPA1
    .const        : {} >> SRAM_LDAx | SRAM_CDA0_1
    .rodata       : {} >> SRAM_LDAx | SRAM_CDA0_1
    .init_array   : {} >> SRAM_LDAx | SRAM_CDA0_1

    .data         : {} >> SRAM_LDAx | SRAM_CDA0_1
    .bss          : {} >> SRAM_LDAx | SRAM_CDA0_1
    .stack        : {} >  SRAM_LDAx
    .sysmem       : {} >  SRAM_LDAx
    .cio          : {} >  SRAM_LDAx

}