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
 *  File:         Spi_Irq.c
 *  Generator:    None
 *
 *  Description:  This file contains SPI interrupt service routine definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi_Priv.h"
#include "Spi.h"
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
#define SPI_START_SEC_ISR_CODE
#include "Spi_MemMap.h"
/* Design : MCAL-24917 */
/* define ISR functions for SPI A */
#if defined(SPI_UNIT_SPIA_ACTIVE)
#if defined(SPI_SPIA_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Spi_A_RxISR)
#elif defined(SPI_SPIA_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Spi_A_RxISR)
#elif defined(SPI_SPIA_ISR_CAT2)
ISR(Spi_A_RxISR)
#else
#error "Invalid interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Spi_ProcessRxEvent(SPI_UNIT_SPIA);
}
#endif

/* define ISR functions for SPI B */
#if defined(SPI_UNIT_SPIB_ACTIVE)
#if defined(SPI_SPIB_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Spi_B_RxISR)
#elif defined(SPI_SPIB_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Spi_B_RxISR)
#elif defined(SPI_SPIB_ISR_CAT2)
ISR(Spi_B_RxISR)
#else
#error "Invalid interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Spi_ProcessRxEvent(SPI_UNIT_SPIB);
}
#endif

/* define ISR functions for SPI C */
#if defined(SPI_UNIT_SPIC_ACTIVE)
#if defined(SPI_SPIC_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Spi_C_RxISR)
#elif defined(SPI_SPIC_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Spi_C_RxISR)
#elif defined(SPI_SPIC_ISR_CAT2)
ISR(Spi_C_RxISR)
#else
#error "Invalid interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Spi_ProcessRxEvent(SPI_UNIT_SPIC);
}
#endif

/* define ISR functions for SPI D */
#if defined(SPI_UNIT_SPID_ACTIVE)
#if defined(SPI_SPID_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Spi_D_RxISR)
#elif defined(SPI_SPID_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Spi_D_RxISR)
#elif defined(SPI_SPID_ISR_CAT2)
ISR(Spi_D_RxISR)
#else
#error "Invalid interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Spi_ProcessRxEvent(SPI_UNIT_SPID);
}
#endif

/* define ISR functions for SPI E */
#if defined(SPI_UNIT_SPIE_ACTIVE)
#if defined(SPI_SPIE_ISR_CAT1_RTINT)
MCAL_LIB_RTINT_ISR(Spi_E_RxISR)
#elif defined(SPI_SPIE_ISR_CAT1_INT)
MCAL_LIB_INT_ISR(Spi_E_RxISR)
#elif defined(SPI_SPIE_ISR_CAT2)
ISR(Spi_E_RxISR)
#else
#error "Invalid interrupt category"
#endif
{
    /* Call the internal ISR notify function to handle interrupt */
    Spi_ProcessRxEvent(SPI_UNIT_SPIE);
}
#endif

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define SPI_STOP_SEC_ISR_CODE
#include "Spi_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Spi_Irq.c
 *********************************************************************************************************************/
