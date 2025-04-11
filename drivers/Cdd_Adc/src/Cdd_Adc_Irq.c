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
 *  File:         Cdd_Adc_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Adc Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc_Priv.h"
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
#define CDD_ADC_START_SEC_ISR_CODE
#include "Cdd_Adc_MemMap.h"

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT1_ENABLE)
#if defined(CDD_ADCA_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int1Isr)
#elif defined(CDD_ADCA_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int1Isr)
#elif defined(CDD_ADCA_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int1Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1,CDD_ADCA);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCA_INT2_ENABLE)
#if defined(CDD_ADCA_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int2Isr)
#elif defined(CDD_ADCA_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int2Isr)
#elif defined(CDD_ADCA_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int2Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2,CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT3_ENABLE)
#if defined(CDD_ADCA_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int3Isr)
#elif defined(CDD_ADCA_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int3Isr)
#elif defined(CDD_ADCA_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int3Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3,CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCA_INT4_ENABLE)
#if defined(CDD_ADCA_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_Int4Isr)
#elif defined(CDD_ADCA_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_Int4Isr)
#elif defined(CDD_ADCA_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_Int4Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4,CDD_ADCA);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT1_ENABLE)
#if defined(CDD_ADCB_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int1Isr)
#elif defined(CDD_ADCB_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int1Isr)
#elif defined(CDD_ADCB_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int1Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1,CDD_ADCB);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCB_INT2_ENABLE)
#if defined(CDD_ADCB_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int2Isr)
#elif defined(CDD_ADCB_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int2Isr)
#elif defined(CDD_ADCB_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int2Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2,CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT3_ENABLE)
#if defined(CDD_ADCB_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int3Isr)
#elif defined(CDD_ADCB_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int3Isr)
#elif defined(CDD_ADCB_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int3Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3,CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCB_INT4_ENABLE)
#if defined(CDD_ADCB_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_Int4Isr)
#elif defined(CDD_ADCB_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_Int4Isr)
#elif defined(CDD_ADCB_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_Int4Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4,CDD_ADCB);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT1_ENABLE)
#if defined(CDD_ADCC_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int1Isr)
#elif defined(CDD_ADCC_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int1Isr)
#elif defined(CDD_ADCC_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int1Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1,CDD_ADCC);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCC_INT2_ENABLE)
#if defined(CDD_ADCC_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int2Isr)
#elif defined(CDD_ADCC_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int2Isr)
#elif defined(CDD_ADCC_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int2Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2,CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT3_ENABLE)
#if defined(CDD_ADCC_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int3Isr)
#elif defined(CDD_ADCC_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int3Isr)
#elif defined(CDD_ADCC_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int3Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3,CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCC_INT4_ENABLE)
#if defined(CDD_ADCC_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_Int4Isr)
#elif defined(CDD_ADCC_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_Int4Isr)
#elif defined(CDD_ADCC_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_Int4Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4,CDD_ADCC);
}
#endif

/*
 *Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT1_ENABLE)
#if defined(CDD_ADCD_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int1Isr)
#elif defined(CDD_ADCD_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int1Isr)
#elif defined(CDD_ADCD_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int1Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1,CDD_ADCD);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCD_INT2_ENABLE)
#if defined(CDD_ADCD_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int2Isr)
#elif defined(CDD_ADCD_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int2Isr)
#elif defined(CDD_ADCD_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int2Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2,CDD_ADCD);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT3_ENABLE)
#if defined(CDD_ADCD_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int3Isr)
#elif defined(CDD_ADCD_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int3Isr)
#elif defined(CDD_ADCD_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int3Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3,CDD_ADCD);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCD_INT4_ENABLE)
#if defined(CDD_ADCD_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_Int4Isr)
#elif defined(CDD_ADCD_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_Int4Isr)
#elif defined(CDD_ADCD_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_Int4Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4,CDD_ADCD);
}
#endif

/*
 * Design: MCAL-
 */

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT1_ENABLE)
#if defined(CDD_ADCE_INT1_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int1Isr)
#elif defined(CDD_ADCE_INT1_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int1Isr)
#elif defined(CDD_ADCE_INT1_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int1Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT1,CDD_ADCE);
}
#endif

/*
 *Design: MCAL
 */
#if defined(CDD_ADCE_INT2_ENABLE)
#if defined(CDD_ADCE_INT2_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int2Isr)
#elif defined(CDD_ADCE_INT2_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int2Isr)
#elif defined(CDD_ADCE_INT2_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int2Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT2,CDD_ADCE);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT3_ENABLE)
#if defined(CDD_ADCE_INT3_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int3Isr)
#elif defined(CDD_ADCE_INT3_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int3Isr)
#elif defined(CDD_ADCE_INT3_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int3Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT3,CDD_ADCE);
}
#endif

/*
 *Design: MCAL-
 */
#if defined(CDD_ADCE_INT4_ENABLE)
#if defined(CDD_ADCE_INT4_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_Int4Isr)
#elif defined(CDD_ADCE_INT4_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_Int4Isr)
#elif defined(CDD_ADCE_INT4_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_Int4Isr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_ProcessIsr(CDD_ADC_INT4,CDD_ADCE);
}
#endif


#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Enable the ISR functions only if Limit check API is enabled */

#if defined(CDD_ADCA_EVTINT_ENABLE)
#if defined(CDD_ADCA_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#elif defined(CDD_ADCA_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#elif defined(CDD_ADCA_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCA_PpbEvtIntIsr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCA);
}
#endif

#if defined(CDD_ADCB_EVTINT_ENABLE)
#if defined(CDD_ADCB_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#elif defined(CDD_ADCB_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#elif defined(CDD_ADCB_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCB_PpbEvtIntIsr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCB);
}
#endif

#if defined(CDD_ADCC_EVTINT_ENABLE)
#if defined(CDD_ADCC_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#elif defined(CDD_ADCC_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#elif defined(CDD_ADCC_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCC_PpbEvtIntIsr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCC);
}
#endif

#if defined(CDD_ADCD_EVTINT_ENABLE)
#if defined(CDD_ADCD_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#elif defined(CDD_ADCD_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#elif defined(CDD_ADCD_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCD_PpbEvtIntIsr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCD);
}
#endif

#if defined(CDD_ADCE_EVTINT_ENABLE)
#if defined(CDD_ADCE_EVTINT_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#elif defined(CDD_ADCE_EVTINT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#elif defined(CDD_ADCE_EVTINT_ISR_CAT2_INT)
ISR(Cdd_Adc_ADCE_PpbEvtIntIsr)
#else
    #error "Invalid Adc interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Cdd_Adc_PpbEvtIsr(CDD_ADCE);
}
#endif

#endif

#define CDD_ADC_STOP_SEC_ISR_CODE
#include "Cdd_Adc_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Irq.c
 *********************************************************************************************************************/
