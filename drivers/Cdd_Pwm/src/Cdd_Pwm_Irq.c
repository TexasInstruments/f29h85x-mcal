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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:         Cdd_Pwm_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Pwm Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Priv.h"
#include "Mcal_Lib_Cpu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
#define CDD_PWM_START_SEC_ISR_CODE
#include "Cdd_Pwm_MemMap.h"

#if defined(CDD_PWM1_INT_ENABLE)
#if defined(CDD_PWM1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm1_IntIsr)
#elif defined(CDD_PWM1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm1_IntIsr)
#elif defined(CDD_PWM1_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm1_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(1U);
}
#endif

#if defined(CDD_PWM2_INT_ENABLE)
#if defined(CDD_PWM2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm2_IntIsr)
#elif defined(CDD_PWM2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm2_IntIsr)
#elif defined(CDD_PWM2_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm2_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(2U);
}
#endif

#if defined(CDD_PWM3_INT_ENABLE)
#if defined(CDD_PWM3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm3_IntIsr)
#elif defined(CDD_PWM3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm3_IntIsr)
#elif defined(CDD_PWM3_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm3_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(3U);
}
#endif

#if defined(CDD_PWM4_INT_ENABLE)
#if defined(CDD_PWM4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm4_IntIsr)
#elif defined(CDD_PWM4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm4_IntIsr)
#elif defined(CDD_PWM4_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm4_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(4U);
}
#endif

#if defined(CDD_PWM5_INT_ENABLE)
#if defined(CDD_PWM5_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm5_IntIsr)
#elif defined(CDD_PWM5_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm5_IntIsr)
#elif defined(CDD_PWM5_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm5_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(5U);
}
#endif

#if defined(CDD_PWM6_INT_ENABLE)
#if defined(CDD_PWM6_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm6_IntIsr)
#elif defined(CDD_PWM6_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm6_IntIsr)
#elif defined(CDD_PWM6_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm6_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(6U);
}
#endif

#if defined(CDD_PWM7_INT_ENABLE)
#if defined(CDD_PWM7_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm7_IntIsr)
#elif defined(CDD_PWM7_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm7_IntIsr)
#elif defined(CDD_PWM7_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm7_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(7U);
}
#endif

#if defined(CDD_PWM8_INT_ENABLE)
#if defined(CDD_PWM8_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm8_IntIsr)
#elif defined(CDD_PWM8_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm8_IntIsr)
#elif defined(CDD_PWM8_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm8_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(8U);
}
#endif

#if defined(CDD_PWM9_INT_ENABLE)
#if defined(CDD_PWM9_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm9_IntIsr)
#elif defined(CDD_PWM9_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm9_IntIsr)
#elif defined(CDD_PWM9_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm9_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(9U);
}
#endif

#if defined(CDD_PWM10_INT_ENABLE)
#if defined(CDD_PWM10_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm10_IntIsr)
#elif defined(CDD_PWM10_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm10_IntIsr)
#elif defined(CDD_PWM10_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm10_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(10U);
}
#endif

#if defined(CDD_PWM11_INT_ENABLE)
#if defined(CDD_PWM11_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm11_IntIsr)
#elif defined(CDD_PWM11_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm11_IntIsr)
#elif defined(CDD_PWM11_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm11_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(11U);
}
#endif

#if defined(CDD_PWM12_INT_ENABLE)
#if defined(CDD_PWM12_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm12_IntIsr)
#elif defined(CDD_PWM12_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm12_IntIsr)
#elif defined(CDD_PWM12_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm12_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(12U);
}
#endif

#if defined(CDD_PWM13_INT_ENABLE)
#if defined(CDD_PWM13_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm13_IntIsr)
#elif defined(CDD_PWM13_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm13_IntIsr)
#elif defined(CDD_PWM13_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm13_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(13U);
}
#endif

#if defined(CDD_PWM14_INT_ENABLE)
#if defined(CDD_PWM14_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm14_IntIsr)
#elif defined(CDD_PWM14_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm14_IntIsr)
#elif defined(CDD_PWM14_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm14_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(14U);
}
#endif

#if defined(CDD_PWM15_INT_ENABLE)
#if defined(CDD_PWM15_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm15_IntIsr)
#elif defined(CDD_PWM15_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm15_IntIsr)
#elif defined(CDD_PWM15_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm15_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(15U);
}
#endif

#if defined(CDD_PWM16_INT_ENABLE)
#if defined(CDD_PWM16_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm16_IntIsr)
#elif defined(CDD_PWM16_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm16_IntIsr)
#elif defined(CDD_PWM16_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm16_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(16U);
}
#endif

#if defined(CDD_PWM17_INT_ENABLE)
#if defined(CDD_PWM17_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm17_IntIsr)
#elif defined(CDD_PWM17_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm17_IntIsr)
#elif defined(CDD_PWM17_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm17_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(17U);
}
#endif

#if defined(CDD_PWM18_INT_ENABLE)
#if defined(CDD_PWM18_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Pwm_Epwm18_IntIsr)
#elif defined(CDD_PWM18_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Pwm_Epwm18_IntIsr)
#elif defined(CDD_PWM18_ISR_CAT2_INT)
ISR(Cdd_Pwm_Epwm18_IntIsr)
#else
#error "Invalid Pwm interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Pwm_ProcessIsr(18U);
}
#endif

#define CDD_PWM_STOP_SEC_ISR_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Epwm_Irq.c
 *********************************************************************************************************************/
