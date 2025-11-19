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
 *  File:       File name
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  Description of file's purpose                                                           
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "hw_memmap.h"
#include "Std_Types.h"
#ifdef __cplusplus

extern "C" {
#endif

[!AUTOSPACING!]

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
  #if ((CDD_ECAP_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||(CDD_ECAP_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap.h are inconsistent!"
#endif

 #if ((CDD_ECAP_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||(CDD_ECAP_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_BASEADDR_STEP             (ECAP2_BASE - ECAP1_BASE)
#define CDD_ECAP_HR_BASEADDR_STEP          (HRCAP6_BASE - HRCAP5_BASE)
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Ecap Driver configuration */

#define CDD_ECAP_START_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

[!SELECT "as:modconf('Cdd_Ecap/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Ecap/Cdd']"!]
[!VAR "NumChannels" = "num:i(count(CddEcapConfigSet/CddEcapChannel/*))"!]

[!AUTOSPACING!]

[!VAR "Index" = "0"!]
[!VAR "Index1" = "0"!]
[!VAR "Ticks" = "0"!]
[!VAR "DeviceName" = "node:value(node:ref('ASPathDataOfSchema:/TI_F29H85x/ResourceAllocator/ResourceAllocatorGeneral/Device'))"!]

[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile')"!]
[!VAR "Index" = "0"!]
[!VAR "Index1" = "0"!]
[!VAR "Ticks" = "0"!]

/* Cdd_Ecap Channel Configuration parameters */
 CONST(struct Cdd_Ecap_ConfigTag, CDD_ECAP_CONFIG_DATA)
    Cdd_Ecap_Config =
{
    .chCfg =
    {
    [!LOOP "CddEcapConfigSet/CddEcapChannel/*"!][!/*Channel Loop */!]
        [[!"num:i($Index1)"!]] =
        {
            .channelId = CDD_ECAP_CHANNEL[!"num:i(CddEcapChannelId)"!], /* Channel ID */
            .emulationMode = [!"CddEcapEmulationMode"!], /* Emulation Mode */
            .defaultStartEdge = [!"CddEcapDefaultStartEdge"!],/* Default start edge*/
            .inputSelect = [!"CddEcapInputSelect"!],/* Input source select */
            .measurementMode = [!"CddEcapMeasurementMode"!],/* Measurement Mode*/
            [!IF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_SIGNAL_MEASUREMENT'"!]
            .signalMeasurementProperty = [!"CddEcapSignalMeasurement/CddEcapSignalMeasurementProperty"!],
              [!IF "node:empty(CddEcapSignalMeasurement/CddEcapSignalMeasurementProperty) = 'true'"!][!ERROR "Signal Measurement Property is not configured"!][!ENDIF!][!//
            [!ELSEIF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_TIMESTAMP'"!]
            [!IF "node:exists(CddEcapTimestampMeasurement/CddEcapTimestampNotification)"!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)[!IF "node:empty(CddEcapTimestampMeasurement/CddEcapTimestampNotification)"!] NULL_PTR [!ELSE!] [!"CddEcapTimestampMeasurement/CddEcapTimestampNotification"!] [!ENDIF!],
            [!ELSE!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)NULL_PTR,
            [!ENDIF!]
            .bufferType =  [!"CddEcapTimestampMeasurement/CddEcapTimestampMeasurementProperty"!],
            [!IF "node:empty(CddEcapTimestampMeasurement/CddEcapTimestampMeasurementProperty) = 'true'"!][!ERROR "Buffer Type is not configured"!][!ENDIF!][!//
            [!ELSEIF "CddEcapMeasurementMode = 'CDD_ECAP_MODE_SIGNAL_EDGE_DETECT'"!]
            [!IF "node:exists(CddEcapSignalEdgeDetection/CddEcapSignalNotification)"!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)[!IF "node:empty(CddEcapSignalEdgeDetection/CddEcapSignalNotification)"!] NULL_PTR [!ELSE!] [!"CddEcapSignalEdgeDetection/CddEcapSignalNotification"!] [!ENDIF!],
            [!ELSE!]
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)NULL_PTR,
            [!ENDIF!]
            [!ENDIF!]
            .instanceClkMHz = [!"num:i(num:div(num:i(CddEcapClkFrequency), 1000000))"!]U,
            .prescaler = (uint8)[!"num:i(num:div(substring-after(CddEcapPrescaler,'CDD_ECAP_PRESCALAR_'), 2))"!]U, /* prescale */
            .base_addr = (uint32)[!"node:value(node:ref(CddEcapChannelRef)/BaseAddr)"!], /* Base address of the channel */
            [!IF "CddEcapHREnable = 'true'"!]
            [!IF "ecu:get('ResourceAllocator_F29H85x.Cdd_Ecap_HrEnable') = 'FALSE'"!][!ERROR "HR mode is not enabled for this device."!]
            [!ELSEIF "not(text:contains(concat(',', ecu:get('ResourceAllocator_F29H85x.Cdd_Ecap_HrSupportId'), ','), concat(',', CddEcapChannelId, ',')))"!][!ERROR!]HR mode is not supported for ECAP [!"num:i(CddEcapChannelId + 1)"!][!ENDERROR!]
            [!ELSE!]
            .hr_enable = (boolean)TRUE,
            [!VAR "baseAddr" = "node:value(node:ref(CddEcapChannelRef)/BaseAddr)"!]
            .hr_base_addr = (uint32)[!"concat('HR', substring-after($baseAddr, 'E'))"!] /* Base address of the high resolution channel */
            [!ENDIF!]
            [!ENDIF!]
        }[!VAR "Index1" = "$Index1+1"!][!IF "not(node:islast())"!],[!ENDIF!][!CR!][!ENDLOOP!]
    }[!IF "not(node:islast())"!],[!ENDIF!][!CR!]
};
[!VAR "Index" = "$Index+1"!][!/*End of CddEcapConfigSet */!]
[!ENDIF!][!//

[!/*
    Duplicate channel ID check
*/!]
[!LOOP "CddEcapConfigSet/CddEcapChannel/*"!]
[!VAR "chanId" = "CddEcapChannelId"!]
[!VAR "chName" = "@name"!]
[!VAR "Repeated" = "0"!]
[!LOOP "CddEcapConfigSet/CddEcapChannel/*"!]
[!IF "CddEcapChannelId = num:i($chanId)"!]
    [!IF "'1' = num:i($Repeated)"!]
        [!ERROR!] Cdd_Ecap ChannelId should be unique!!!. Please check channel [!"$chName"!] and [!"@name"!], both have same channel ID as [!"num:i($chanId)"!]." [!ENDERROR!]
    [!ELSE!]
        [!VAR "Repeated" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
#ifdef __cplusplus
}
#endif

/*</CDD_ECAP_CONFIGURATION>*/
#define CDD_ECAP_STOP_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

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
 *  External Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Cfg.c
 *********************************************************************************************************************/
