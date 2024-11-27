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
#if ((DIO_AR_RELEASE_MAJOR_VERSION    != (0x04U)) || \
     (DIO_AR_RELEASE_MINOR_VERSION    != (0x03U)) || \
     (DIO_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version Numbers of Dio are different"
#endif

#if ((DIO_SW_MAJOR_VERSION != (1U)) || (DIO_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Dio.c and Dio.h are inconsistent!"
#endif

#if ((DIO_CFG_MAJOR_VERSION != (1U)) || (DIO_CFG_MINOR_VERSION != (0U)))
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
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "DIO_E_PARAM_POINTER" error */
    if (NULL_PTR == Versioninfo)
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_GET_VERSION_INFO,
                        DIO_E_PARAM_POINTER);
    }
    else
#endif
    {
        Versioninfo->vendorID         = (uint16) DIO_VENDOR_ID;
        Versioninfo->moduleID         = (uint16) DIO_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)  DIO_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)  DIO_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)  DIO_SW_PATCH_VERSION;
    }
}
#endif

/* Design: MCAL-22536,MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22455,MCAL-22458,MCAL-22454,MCAL-22464,MCAL-22467,
 * Design: MCAL-22441,MCAL-22552,MCAL-22460,MCAL-22479 */
FUNC(Dio_LevelType, DIO_CODE)
Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    VAR(Dio_LevelType, AUTOMATIC) Level = ((Dio_LevelType) STD_LOW);

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType) E_OK) != Dio_IsChannelValid(ChannelId))
    {

        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_READ_CHANNEL,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        /* Read the level of the channel and return the value. */
        Level = Dio_PinReadPriv(ChannelId);
    }

    return (Level);
}

/* Design: MCAL-22536, MCAL-22439, MCAL-22440, MCAL-22445, MCAL-22446, MCAL-22447, MCAL-22480, MCAL-22481,MCAL-22482,
 * Design: MCAL-22449, MCAL-22441, MCAL-22448, MCAL-22464, MCAL-22467, MCAL-22552, MCAL-22460 */
FUNC(void, DIO_CODE)
Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType) E_OK) != Dio_IsChannelValid(ChannelId))
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_WRITE_CHANNEL,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        /*  Write to pin */
        Dio_PinWritePriv(ChannelId, Level);
    }
}

/* Design: MCAL-22536,MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22456,MCAL-22483,MCAL-22484,MCAL-22454,
*  Design: MCAL-22465,MCAL-22552,MCAL-22461,MCAL-22441,MCAL-22514 */
FUNC(Dio_PortLevelType, DIO_CODE)
Dio_ReadPort(Dio_PortType PortId)
{
    /* return portValue as 0 when there is a DET error */
    VAR(Dio_PortLevelType, AUTOMATIC) portVal = ((Dio_PortLevelType) 0x0000U);

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /*  Check if the port configuration is enable else return a DET error. */
    if (0U == (DIO_CFG_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_READ_PORT,
                        DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        /* Read the Port Data and return the Port Value. */
        Dio_ReadPortDataPriv(PortId, &portVal);
    }

    return (portVal);
}

/* Design: MCAL-22485,MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22451,MCAL-22486,
 * Design: MCAL-22487,MCAL-22488,MCAL-22536,MCAL-22450,MCAL-22448,MCAL-22465,MCAL-22552,MCAL-22461,MCAL-22514 */
FUNC(void, DIO_CODE)
Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    
#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /*  Check if the port configuration is enable else return a DET error. */
    if (0U == (DIO_CFG_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_WRITE_PORT,
                        DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        /* Write the Port Data. */
        Dio_WritePortDataPriv(PortId, Level);
    }
}

/* Design: MCAL-22439,MCAL-22440,MCAL-22453,MCAL-22457,MCAL-22489,MCAL-22535,MCAL-22536,MCAL-22454,MCAL-22441,
 * Design: MCAL-22466,MCAL-22463,MCAL-22552,MCAL-22462,MCAL-22490,MCAL-22491  */
FUNC(Dio_PortLevelType, DIO_CODE)
Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr)
{
    VAR(Dio_PortLevelType, AUTOMATIC) portLevelVal = (Dio_PortLevelType) STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /*
     * Check if the Group Channel Id Pointer is not null otherwise return a
     * DET error.
     */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_READ_CHANNEL_GROUP,
                        DIO_E_PARAM_POINTER);
    }
    else if(((Std_ReturnType) E_OK) != Dio_IsChannelGroupValid(ChannelGroupIdPtr))
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_READ_CHANNEL_GROUP,
                        DIO_E_PARAM_INVALID_GROUP);
    }
    else
#endif
    {
        Dio_ReadPortDataPriv(ChannelGroupIdPtr->port, &portLevelVal);
        portLevelVal &= ChannelGroupIdPtr->mask;
        portLevelVal = portLevelVal >> ChannelGroupIdPtr->offset;
    }

    return (portLevelVal);
}

/* Design: MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22492,MCAL-22493,MCAL-22535,MCAL-22536,
 * Design: MCAL-22495,MCAL-22494,MCAL-22452,MCAL-22462,MCAL-22463,MCAL-22552,MCAL-22448,MCAL-22466 */
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
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_WRITE_CHANNEL_GROUP,
                        DIO_E_PARAM_POINTER);
    }
    else if(((Std_ReturnType) E_OK) != Dio_IsChannelGroupValid(ChannelGroupIdPtr))
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_WRITE_CHANNEL_GROUP,
                        DIO_E_PARAM_INVALID_GROUP);
    }
    else
#endif
    {
        Dio_WriteChannelGroupPriv(ChannelGroupIdPtr, Level);
    }
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/* Design: MCAL-22439,MCAL-22440,MCAL-22445,MCAL-22446,MCAL-22447,MCAL-22497,MCAL-22498,MCAL-22499,MCAL-22536,
 * Design: MCAL-22441,MCAL-22454,MCAL-22448,MCAL-22464,MCAL-22467,MCAL-22460,MCAL-22552 */
FUNC(Dio_LevelType, DIO_CODE)
Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    VAR(Dio_LevelType, AUTOMATIC) currentVal = (Dio_LevelType) STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)

    /* Check if channel is valid and report a DET error if invalid. */
    if (((Std_ReturnType) E_OK) != Dio_IsChannelValid(ChannelId))
    {
        (void)Det_ReportError(
                        DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        DIO_SID_FLIP_CHANNEL,
                        DIO_E_PARAM_INVALID_CHANNEL_ID);
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
