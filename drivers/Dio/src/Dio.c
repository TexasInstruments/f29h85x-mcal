/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Dio.c
 *  Generator:  None
 *
 *  Description:  This file contains DIO MCAL driver API function definitions
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-22532 */
#include "Dio.h"
#include "Dio_Priv.h"

/* Design: MCAL-22438 */
#if (STD_ON == DIO_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (DIO_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (DIO_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version Numbers of Dio are different"
#endif

#if ((DIO_SW_MAJOR_VERSION != (1U)) || (DIO_SW_MINOR_VERSION != (1U)))
#error "Version numbers of Dio.c and Dio.h are inconsistent!"
#endif

#if ((DIO_CFG_MAJOR_VERSION != (1U)) || (DIO_CFG_MINOR_VERSION != (1U)))
#error "Version numbers of Dio.c and Dio_Cfg.h are inconsistent!"
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
 *  Local Inline Function Definitions and Function-Like Macros
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
 *  External Functions Definition
 *********************************************************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VERSION_INFO_API)

/* Design: MCAL-22467, MCAL-22496, MCAL-22552, MCAL-22463 */
FUNC(void, DIO_CODE)
Dio_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) Versioninfo)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "DIO_E_PARAM_POINTER"
     * error */
    if (NULL_PTR == Versioninfo)
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_GET_VERSION_INFO, DIO_E_PARAM_POINTER);
    }
    else
#endif
    {
        Versioninfo->vendorID         = (uint16)DIO_VENDOR_ID;
        Versioninfo->moduleID         = (uint16)DIO_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
    }
}
#endif

// clang-format off
/* Design:
 * MCAL-22536,MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22455,MCAL-22458,MCAL-22454,MCAL-22464,MCAL-22467,
 * Design: MCAL-22441,MCAL-22552,MCAL-22460,MCAL-22479 */
// clang-format on
FUNC(Dio_LevelType, DIO_CODE)
Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    VAR(Dio_LevelType, AUTOMATIC) Level = ((Dio_LevelType)STD_LOW);

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType)E_OK) != Dio_IsChannelValid(ChannelId))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_READ_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        /* Read the level of the channel and return the value. */
        Level = Dio_PinReadPriv(ChannelId);
    }

    return (Level);
}

// clang-format off
/* Design: MCAL-22536, MCAL-22439, MCAL-22440, MCAL-22445, MCAL-22446, MCAL-22447, MCAL-22480,
 * Design: MCAL-22481,MCAL-22482, MCAL-22449, MCAL-22441, MCAL-22448, MCAL-22464, MCAL-22467,
 * Design: MCAL-22552, MCAL-22460 */
// clang-format on
FUNC(void, DIO_CODE)
Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType)E_OK) != Dio_IsChannelValid(ChannelId))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_WRITE_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        /*  Write to pin */
        Dio_PinWritePriv(ChannelId, Level);
    }
}

// clang-format off
/* Design: MCAL-22536,MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22456,MCAL-22483,MCAL-22484,MCAL-22454,
 * Design: MCAL-22465,MCAL-22552,MCAL-22461,MCAL-22441,MCAL-22514 */
// clang-format on
FUNC(Dio_PortLevelType, DIO_CODE)
Dio_ReadPort(Dio_PortType PortId)
{
    /* return portValue as 0 when there is a DET error */
    VAR(Dio_PortLevelType, AUTOMATIC) portVal = ((Dio_PortLevelType)0x0000U);

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /*  Check if the port configuration is enable else return a DET error. */
    if (0U == (DIO_CFG_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_READ_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        /* Read the Port Data and return the Port Value. */
        Dio_ReadPortDataPriv(PortId, &portVal);
    }

    return (portVal);
}

// clang-format off
/* Design: MCAL-22485,MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22451,MCAL-22486,
 * Design: MCAL-22487,MCAL-22488,MCAL-22536,MCAL-22450,MCAL-22448,MCAL-22465,MCAL-22552,MCAL-22461,MCAL-22514 */
// clang-format on
FUNC(void, DIO_CODE)
Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /*  Check if the port configuration is enable else return a DET error. */
    if (0U == (DIO_CFG_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_WRITE_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        /* Write the Port Data. */
        Dio_WritePortDataPriv(PortId, Level);
    }
}

// clang-format off
/* Design:
 * MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22457,MCAL-22489,MCAL-22535,MCAL-22536,MCAL-22454,MCAL-22441,
 * Design: MCAL-22466,MCAL-22463,MCAL-22552,MCAL-22462,MCAL-22490,MCAL-22491 */
// clang-format on
FUNC(Dio_PortLevelType, DIO_CODE)
Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr)
{
    VAR(Dio_PortLevelType, AUTOMATIC) portLevelVal = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /*
     * Check if the Group Channel Id Pointer is not null otherwise return a
     * DET error.
     */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_READ_CHANNEL_GROUP, DIO_E_PARAM_POINTER);
    }
    else if (((Std_ReturnType)E_OK) != Dio_IsChannelGroupValid(ChannelGroupIdPtr))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_READ_CHANNEL_GROUP, DIO_E_PARAM_INVALID_GROUP);
    }
    else
#endif
    {
        Dio_ReadPortDataPriv(ChannelGroupIdPtr->port, &portLevelVal);
        portLevelVal &= ChannelGroupIdPtr->mask;
        portLevelVal  = portLevelVal >> ChannelGroupIdPtr->offset;
    }

    return (portLevelVal);
}

// clang-format off
/* Design:
 * MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22492,MCAL-22493,MCAL-22535,MCAL-22536,
 * Design: MCAL-22495,MCAL-22494,MCAL-22452,MCAL-22462,MCAL-22463,MCAL-22552,MCAL-22448,MCAL-22466 */
// clang-format on
FUNC(void, DIO_CODE)
Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr,
                      Dio_PortLevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /*
     * Check if the Group Channel Id Pointer is not null otherwise return a
     * DET error.
     */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_WRITE_CHANNEL_GROUP, DIO_E_PARAM_POINTER);
    }
    else if (((Std_ReturnType)E_OK) != Dio_IsChannelGroupValid(ChannelGroupIdPtr))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_WRITE_CHANNEL_GROUP, DIO_E_PARAM_INVALID_GROUP);
    }
    else
#endif
    {
        Dio_WriteChannelGroupPriv(ChannelGroupIdPtr, Level);
    }
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
// clang-format off
/* Design:
 * MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22497,MCAL-22498,MCAL-22499,MCAL-22536,
 * Design: MCAL-22441,MCAL-22454,MCAL-22448,MCAL-22464,MCAL-22467,MCAL-22460,MCAL-22552 */
// clang-format on
FUNC(Dio_LevelType, DIO_CODE)
Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    VAR(Dio_LevelType, AUTOMATIC) currentVal = (Dio_LevelType)STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType)E_OK) != Dio_IsChannelValid(ChannelId))
    {
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_FLIP_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        Dio_PinFlipVal(ChannelId);
        currentVal = Dio_PinReadPriv(ChannelId);
    }

    return (currentVal);
}
#endif
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Dio.c
 *********************************************************************************************************************/
