/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Mcal_Lib_Cpu.h
 *  Generator:  None
 *
 *  Description:  Useful C29x CPU defines.
 *********************************************************************************************************************/
#ifndef MCAL_LIB_CPU_H
#define MCAL_LIB_CPU_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

#ifndef MCAL_LIB_EINT
#define MCAL_LIB_EINT __asm(" ENINT") /* Define to enable interrupts */
#endif

#ifndef MCAL_LIB_DINT
#define MCAL_LIB_DINT __asm(" DISINT") /* Define to disable interrupts */
#endif

#ifndef MCAL_LIB_EMUSTOP0
#define MCAL_LIB_EMUSTOP0 __asm(" EMUSTOP0") /* Define for emulation stop */
#endif

#ifndef MCAL_LIB_NOP
#define MCAL_LIB_NOP __asm(" NOP #1") /* Define for no operation */
#endif

#ifndef MCAL_LIB_IDLE
#define MCAL_LIB_IDLE __asm(" IDLE") /* Define for putting processor into a low-power mode */
#endif

#ifndef MCAL_LIB_INT_ISR
/* Define for declaring ISRs for INT level interrupts */
#define MCAL_LIB_INT_ISR(ISRNAME) __attribute__((interrupt("INT"))) void ISRNAME(void)
#endif

#ifndef MCAL_LIB_RTINT_ISR
/* Define for declaring ISRs for RTINT level interrupts */
#define MCAL_LIB_RTINT_ISR(ISRNAME) __attribute__((interrupt("RTINT"))) void ISRNAME(void)
#endif

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCAL_LIB_CPU_H */
/*********************************************************************************************************************
 *  End of File: Mcal_Lib_Cpu.h
 *********************************************************************************************************************/
