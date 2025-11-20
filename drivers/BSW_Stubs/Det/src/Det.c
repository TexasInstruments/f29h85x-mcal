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
 *  File:       Det.c
 *  Generator:  None
 *
 *  Description:  Development Error Tracer source file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Det.h"
#include "AppUtils.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/* AUTOSAR version information check has to match definition in header file */
#if ((DET_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
     (DET_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (DET_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "DET: AUTOSAR Version Numbers of DET are different"
#endif

/* Vendor specific version information is BCD coded */
#if ((DET_SW_MAJOR_VERSION != (1U)) || (DET_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Det.c and Det.h are inconsistent!"
#endif

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
 *  External Functions Definition
 *********************************************************************************************************************/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) ErrorId)
{
    AppUtils_Printf(" Module ID         : %u\n\r", ModuleId);
    AppUtils_Printf(" Instance ID       : %u\n\r", InstanceId);
    AppUtils_Printf(" Api Id            : %u\n\r", ApiId);
    AppUtils_Printf(" ErrorId           : %u\n\r", ErrorId);
    AppUtils_Printf(" \n\r");
    while(1);
    return E_OK;
}

FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) ErrorId)
{
    /* System Integrator may implement additional handling for this Run time Error */
    AppUtils_Printf(" Module ID         : %u\n\r", ModuleId);
    AppUtils_Printf(" Instance ID       : %u\n\r", InstanceId);
    AppUtils_Printf(" Api Id            : %u\n\r", ApiId);
    AppUtils_Printf(" ErrorId           : %u\n\r", ErrorId);
    AppUtils_Printf(" \n\r");
    return E_OK;
}

FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, DET_DATA) ModuleId, VAR(uint8, DET_DATA) InstanceId, \
VAR(uint8, DET_DATA) ApiId, VAR(uint8, DET_DATA) FaultId)
{
    /* System Integrator may implement additional handling for this Transient Fault */
    AppUtils_Printf(" Module Id         : %u\n\r", ModuleId);
    AppUtils_Printf(" Instance Id       : %u\n\r", InstanceId);
    AppUtils_Printf(" Api Id            : %u\n\r", ApiId);
    AppUtils_Printf(" Fault Id          : %u\n\r", FaultId);
    AppUtils_Printf(" \n\r");
    return (E_OK);
}

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Det.c
 *********************************************************************************************************************/
