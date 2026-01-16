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
 *  File:         Cdd_Ecap_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains Cdd Ecap Interrupt Service Routine(ISR) definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "Cdd_Ecap_Priv.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h"

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
#define CDD_ECAP_START_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

FUNC(void, CDD_ECAP_CODE) Cdd_Ecap_IntISR_Fun(Cdd_Ecap_ChannelType Cdd_Ecap_Channel)
{
#if (STD_ON == CDD_ECAP_DEV_ERROR_DETECT)
    uint32 baseAddr = Cdd_Ecap_Config.chCfg[Cdd_Ecap_Channel].base_addr;

    if (CDD_ECAP_STATUS_INIT != Cdd_Ecap_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Cdd_Ecap_intrDisable(baseAddr, CDD_ECAP_INT_ALL);
        Cdd_Ecap_intrStatusClear(baseAddr, CDD_ECAP_INT_ALL);
    }
    else
#endif
    {
        Cdd_Ecap_ChannelISR(Cdd_Ecap_Channel);
    }
}

#if defined(CDD_ECAP_CHANNEL0_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch0Notify)
#elif defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch0Notify)
#elif defined(CDD_ECAP_CHANNEL0_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch0Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL0"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL0);
}
#endif

#if defined(CDD_ECAP_CHANNEL1_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch1Notify)
#elif defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch1Notify)
#elif defined(CDD_ECAP_CHANNEL1_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch1Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL1"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL1);
}
#endif

#if defined(CDD_ECAP_CHANNEL2_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch2Notify)
#elif defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch2Notify)
#elif defined(CDD_ECAP_CHANNEL2_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch2Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL2"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL2);
}
#endif

#if defined(CDD_ECAP_CHANNEL3_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch3Notify)
#elif defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch3Notify)
#elif defined(CDD_ECAP_CHANNEL3_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch3Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL3"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL3);
}
#endif

#if defined(CDD_ECAP_CHANNEL4_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch4Notify)
#elif defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch4Notify)
#elif defined(CDD_ECAP_CHANNEL4_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch4Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL4);
}
#endif

#if defined(CDD_ECAP_CHANNEL5_INT_ENABLE)
#if defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_ch5Notify)
#elif defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_ch5Notify)
#elif defined(CDD_ECAP_CHANNEL5_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_ch5Notify)
#else
#error "Invalid interrupt category for CDD_ECAP_CHANNEL5"
#endif
{
    Cdd_Ecap_IntISR_Fun(CDD_ECAP_CHANNEL5);
}
#endif

#if defined(CDD_ECAP_HR_CHANNEL4_INT_ENABLE)
#if defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_HR_ch4Notify)
#elif defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_HR_ch4Notify)
#elif defined(CDD_ECAP_HR_CHANNEL4_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_HR_ch4Notify)
#else
#error "Invalid interrupt category for HR mode CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_HR_ISR(CDD_ECAP_CHANNEL4);
}
#endif

#if defined(CDD_ECAP_HR_CHANNEL5_INT_ENABLE)
#if defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT1_RINT)
MCAL_LIB_RTINT_ISR(Cdd_Ecap_HR_ch5Notify)
#elif defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Cdd_Ecap_HR_ch5Notify)
#elif defined(CDD_ECAP_HR_CHANNEL5_INT_ISR_CAT2_INT)
ISR(Cdd_Ecap_HR_ch5Notify)
#else
#error "Invalid interrupt category for HR mode CDD_ECAP_CHANNEL4"
#endif
{
    Cdd_Ecap_HR_ISR(CDD_ECAP_CHANNEL5);
}
#endif
#define CDD_ECAP_STOP_SEC_ISR_CODE
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Irq.c
 *********************************************************************************************************************/
