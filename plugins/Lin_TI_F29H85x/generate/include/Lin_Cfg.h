/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Lin_Cfg.h
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-25544,MCAL-25545,MCAL-25546
 */
#ifndef LIN_CFG_H
#define LIN_CFG_H
/**
 * \addtogroup LIN
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif
 
 #ifndef DOXYGEN_SHOULD_SKIP_THIS 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_memmap.h"
#include "EcuM_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * \brief Lin Driver Configuration SW Version Info.
 *
 *****************************************************************************/
/** \brief Lin configuration Major Version. */
#define LIN_CFG_MAJOR_VERSION    ([!"substring-before($moduleSoftwareVer,'.')"!]U)
/** \brief Lin configuration Minor Version. */
#define LIN_CFG_MINOR_VERSION    ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief Lin configuration Patch Version. */
#define LIN_CFG_PATCH_VERSION    ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)

[!SELECT "as:modconf('Lin')[as:path(node:dtos(.))='/TI_F29H85x/Lin']"!]
/*****************************************************************************
 *
 * \brief LIN Build Variant. 
 *  Build variants.(i.e Pre-compile,Post-build or Link time)
 * 
 *****************************************************************************/
#define LIN_PRE_COMPILE_VARIANT          [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*****************************************************************************
 *
 * \brief Pointer to Lin Config Set to be used during Pre-Compile
 *
 *****************************************************************************/
#define LIN_INIT_CONFIG_PC                   Lin_Config
[!ENDIF!]

/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
/*
 * Design: MCAL-25661, MCAL-25662
 */
#define LIN_DEM_ENABLE    [!IF "node:refexists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "node:refexists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!]
/*
 * Design: MCAL-25586, MCAL-25588, MCAL-25589
 */
/** \brief LIN DEM Event Configuration: LIN Timeout */
#define LIN_E_TIMEOUT  					(DemConf_DemEventParameter_[!"node:name(node:ref(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!])

[!ENDIF!]

/** \brief LIN DEM Event Configuration: LIN Timeout Duration*/
#define LIN_TIMEOUT_DURATION            [!"LinGeneral/LinTimeoutDuration"!]U

/** \brief LIN ID used to transmit a header instead of a wakeup signal. 
 *   The hardware enters an undefined state when a standard wakeup signal is transmitted. 
 *   To mitigate this limitation, a header frame is utilized as the wakeup signal, which conforms to the LIN2.1 specification*/
#define LIN_WAKEUP_ID            0x[!"text:toupper(substring-after(num:inttohex(LinGeneral/LinWakeupId),'0x'))"!]U

[!VAR "SysClock"="num:i(node:ref(LinGeneral/LinSysClockRef)/McuClockReferencePointFrequency)"!][!//
[!VAR "SysClock"="num:i(num:div((num:div(1,65535)), num:div(15,$SysClock)))"!][!//
/** \brief LIN Delay to Mcal Lib */
#define LIN_MCAL_LIB_DELAY              [!"num:i($SysClock)"!]U

/*****************************************************************************
 *
 * \brief Enable/Disable development error detection.
 *
 *****************************************************************************/
#define LIN_DEV_ERROR_DETECT             [!IF "LinGeneral/LinDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Enable/Disable Lin_GetVersionInfo().
 *
 *****************************************************************************/
#define LIN_GET_VERSION_INFO_API         [!IF "LinGeneral/LinVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*****************************************************************************
 *
 * \brief Lin Instance to Channel ID mapping.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25663
 */
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define LIN_INSTANCE_[!"(node:ref(LinInstance)/InstanceName)"!]                    [!"LinChannelId"!]
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel Symbolic Names.
 *
 *****************************************************************************/
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define LinConf_LinChannel_[!"@name"!]       [!"LinChannelId"!]      /*~ASR~*/
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel Interrupt Line Selection.
 *
 *****************************************************************************/
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define LIN_INSTANCE_[!"(node:ref(LinInstance)/InstanceName)"!]_[!"substring-after(LinInterruptLineSelect, 'LIN_INTERRUPT_')"!]                  
[!ENDLOOP!][!//

/*****************************************************************************
 *
 * \brief Lin Channel ISR Type Selection.
 *
 *****************************************************************************/
/*
 * Design: MCAL-25665
 */
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
#define LIN_INSTANCE_[!"(node:ref(LinInstance)/InstanceName)"!]_ISR_TYPE           [!"LinISRType"!]
[!ENDLOOP!][!//


/*****************************************************************************
 *
 * \brief Max number of channels defined
 *
 *****************************************************************************/
#define LIN_MAX_CHANNEL                      ([!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Enum of Lin Interrupt line number, 0 or 1. */
/* 
*Design: MCAL-25666, MCAL-25691  
*/
typedef enum
{
   /** \brief Use Interrupt Line 0 */
   LIN_INTERRUPT_LINE_NUM_0 = 0x0U,
   /** \brief Use Interrupt Line 1 */
   LIN_INTERRUPT_LINE_NUM_1 = 0x1U
} Lin_InterruptLineNum;

/** \brief Enum of Lin Loopbackmode, Internal/External/Disabled Type selection. */
/* 
*Design: MCAL-25692, MCAL-25664
*/
typedef enum Lin_LoopbackModeTag
{
   /** \brief Loopback disabled */
   LIN_LOOPBACK_DISABLED,
   /** \brief Loopback internal */
   LIN_LOOPBACK_INTERNAL,
   /** \brief Loopback external */
   LIN_LOOPBACK_EXTERNAL
} Lin_LoopbackModeType;

/** \brief Lin Controller Configuration structure.*/
/* 
 *Design: MCAL-25693   
 */
typedef struct Lin_ControllerTag
{
   /** \brief Pointer to LinReg structure */
   uint32 CntrAddr;

   /** \brief Loopback Mode for this controller */
   Lin_LoopbackModeType LoopbackMode;

   /** \brief Interrupt Line to be selected */
   Lin_InterruptLineNum IntrLineNum;
   
} Lin_ControllerType;


/** \brief Lin Controller BaudRate Configuration.*/
/* 
 *Design: MCAL-25659,MCAL-25667,MCAL-25668,MCAL-25694
 */
typedef struct Lin_BaudrateConfigTag
{ 
   /** \brief Baud rate value */
   uint32 BaudRate;

   /** \brief Prescalar value */
   uint32 Prescalar;

   /** \brief Fractional Divider value */
   uint32 FractionalDivider;
} Lin_BaudRateConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief LIN Configuration struct declaration */
/* 
 *Design: MCAL-25660
 */
extern const struct Lin_ConfigTag Lin_Config;
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
#endif /* LIN_CFG_H */
/*********************************************************************************************************************
 *  End of File: Lin_Cfg.h
 *********************************************************************************************************************/
