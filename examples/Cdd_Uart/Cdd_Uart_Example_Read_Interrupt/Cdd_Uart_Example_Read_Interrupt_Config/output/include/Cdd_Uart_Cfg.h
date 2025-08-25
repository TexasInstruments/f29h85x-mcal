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
 *  File:       Cdd_Uart_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_UART_CFG_H
#define CDD_UART_CFG_H

/** \addtogroup CDD_UART
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "hw_memmap.h"
#include "hw_uart.h"
#include "Cdd_Uart_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* CDD UART Driver Configuration SW Version Info */
#define CDD_UART_CFG_MAJOR_VERSION           (2U)
#define CDD_UART_CFG_MINOR_VERSION           (0U)
#define CDD_UART_CFG_PATCH_VERSION           (0U)

/** \brief Maximum UART HW Instances on Board */
#define CDD_UART_MAX_NUM_HWUNIT                     (uint8)(1U)

/** \brief Enable/Disable Pre compile variant.*/
#define CDD_UART_CFG_PRE_COMPILE_VARIANT            (STD_ON)

/** \brief Enable/Disable DEV error detection.*/
#define CDD_UART_CFG_DEV_ERROR_DETECT               (STD_ON)

/** \brief Enable/Disable Cdd_Uart_GetVersionInfo().*/
#define CDD_UART_CFG_GET_VERSION_INFO_API           (STD_ON)

/** \brief Pre compile pointer to configuration structure */
#define CDD_UART_INIT_CONFIG_PC                     Cdd_Uart_Config

/** \brief Defines symbolic names for the CddUart HW unit ID's (CddUartHWUnitId) */
#define CddUartConf_CddUartConfigSet_CddUartConfig_0 (0U) /*~ASR~*/

/** \brief CddUart ConfigSet Instance interrupt definition */
#define CDD_UARTD_ENABLE
#define CDD_UARTD_ISR_CAT1_INT

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern CONST(struct Cdd_Uart_ConfigTag, CDD_UART_CONFIG_DATA) Cdd_Uart_Config;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_UART_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Cfg.h
 *********************************************************************************************************************/
