;// This reset vector section/function is applicable for CPU2/ CPU3 only

    .section   resetvector, "ax"
    .global    reset_vector

reset_vector:  
    ISR1.PROT
	|| ISR2.PROT
			
    LB.PROT @(code_start)

    .section   codestart, "ax"
    .global    code_start
    .extern    _c_int00_noargs

code_start:
    ENTRY1.PROT
    || ENTRY2.PROT

    ; Disable WD
    MV D0, 0x68
    ST.W0 @0x30208C52, D0

    LB @(_c_int00_noargs)