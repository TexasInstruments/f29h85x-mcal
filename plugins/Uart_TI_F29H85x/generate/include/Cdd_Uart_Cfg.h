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
#define CDD_UART_CFG_MAJOR_VERSION           ([!"substring-before($moduleSoftwareVer,'.')"!]U)
#define CDD_UART_CFG_MINOR_VERSION           ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
#define CDD_UART_CFG_PATCH_VERSION           ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
[!SELECT "as:modconf('Cdd_Uart/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Uart/Cdd']"!]
/** \brief Maximum UART HW Instances on Board */
#define CDD_UART_MAX_NUM_HWUNIT                     (uint8)([!"num:i(count(CddUartConfigSet[1]/CddUartConfig/*))"!]U)

/** \brief Enable/Disable Pre compile variant.*/
#define CDD_UART_CFG_PRE_COMPILE_VARIANT            [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Enable/Disable DEV error detection.*/
#define CDD_UART_CFG_DEV_ERROR_DETECT               [!IF "CddUartGeneral/CddUartDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Enable/Disable Cdd_Uart_GetVersionInfo().*/
#define CDD_UART_CFG_GET_VERSION_INFO_API           [!IF "CddUartGeneral/CddUartVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Pre compile pointer to configuration structure */
[!LOOP "CddUartConfigSet"!][!//
#define CDD_UART_INIT_CONFIG_PC                     Cdd_Uart_Config
[!ENDLOOP!][!//

/** \brief Defines symbolic names for the CddUart HW unit ID's (CddUartHWUnitId) */
[!LOOP "CddUartConfigSet/CddUartConfig/*"!][!//
#define CddUartConf_CddUartConfigSet_[!"@name"!] ([!"(node:value(CddUartHWUnitId))"!]U) /*~ASR~*/
[!ENDLOOP!][!//

/** \brief CddUart ConfigSet Instance interrupt definition */
[!LOOP "CddUartConfigSet/CddUartConfig/*"!][!//
#define CDD_[!"(node:ref(CddUartInstance)/InstanceName)"!]_ENABLE
[!IF "CddUartInteruptType = 'CDD_UART_ISR_CAT1_RTINT'"!][!//
#define CDD_[!"(node:ref(CddUartInstance)/InstanceName)"!]_ISR_CAT1_RTINT
[!ELSEIF "CddUartInteruptType = 'CDD_UART_ISR_CAT1_INT'"!][!//
#define CDD_[!"(node:ref(CddUartInstance)/InstanceName)"!]_ISR_CAT1_INT
[!ELSE!][!//
#define CDD_[!"(node:ref(CddUartInstance)/InstanceName)"!]_ISR_CAT2
[!ENDIF!][!//
[!ENDLOOP!][!//

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

[!LOOP "CddUartConfigSet"!][!//
extern CONST(struct Cdd_Uart_ConfigTag, CDD_UART_CONFIG_DATA) Cdd_Uart_Config;
[!ENDLOOP!][!//
[!ENDSELECT!]
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
