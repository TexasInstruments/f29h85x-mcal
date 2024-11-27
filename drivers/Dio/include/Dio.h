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
 *  File:       Dio.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Dio Driver functions
 *
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H
/**
 * \defgroup DIO Dio API GUIDE Header file
 * @{
 */
/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Below are the global requirements which are met by this DIO driver which
 * can't be mapped to a particular source ID.
 *
 * Design:  MCAL-22530, MCAL-22531, MCAL-22436, MCAL-22442, MCAL-22443, MCAL-22444, MCAL-22500, MCAL-22512,
 * Design:  MCAL-22533, MCAL-22534, MCAL-22553
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-22532, MCAL-22437 */
#include "Std_Types.h"
#include "Dio_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*
 * Defines for DIO Driver version used for compatibility checks.
 */
/** \brief Driver Implementation Major Version. */
#define DIO_SW_MAJOR_VERSION     (1U)
/** \brief Driver Implementation Minor Version. */ 
#define DIO_SW_MINOR_VERSION     (0U)
/** \brief Driver Implementation Patch Version. */ 
#define DIO_SW_PATCH_VERSION     (0U)

/*********************************************************************************************************************
 * Defines for DIO Driver AUTOSAR version used for compatibility checks.
 *********************************************************************************************************************/
/** \brief AUTOSAR Major version specification implemented by DIO Driver. */
#define DIO_AR_RELEASE_MAJOR_VERSION    (4U)

/** \brief AUTOSAR Minor version specification implemented by DIO Driver. */
#define DIO_AR_RELEASE_MINOR_VERSION    (3U)

/** \brief AUTOSAR Patch version specification implemented by DIO Driver. */
#define DIO_AR_RELEASE_REVISION_VERSION (1U)

/** \brief Texas Instruments Vendor ID. */
#define DIO_VENDOR_ID   ((uint16) 44U)
/** \brief DIO Driver Module ID. */ 
#define DIO_MODULE_ID   ((uint16) 120U) 
/** \brief DIO Driver Instance ID. */
#define DIO_INSTANCE_ID ((uint8) 0U)   

/* DIO Error Codes returned by Driver functions. */
/* Design: MCAL-22460, MCAL-22461, MCAL-22462, MCAL-22463 */
/** \brief API service called with invalid channel ID. */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  (0x0AU)
/** \brief API service called with invalid port ID. */
#define DIO_E_PARAM_INVALID_PORT_ID     (0x14U)
/** \brief API service called with invalid channel group ID. */
#define DIO_E_PARAM_INVALID_GROUP       (0x1FU)
/** \brief Dio_GetVersionInfo() called with NULL_PTR as parameter. */
#define DIO_E_PARAM_POINTER             (0x20U)

/*
 * Dio Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 */
/** \brief Dio_ReadChannel() */
#define DIO_SID_READ_CHANNEL           (0x0U)
/** \brief Dio_WriteChannel() */
#define DIO_SID_WRITE_CHANNEL          (0x1U)
/** \brief Dio_ReadPort() */
#define DIO_SID_READ_PORT              (0x2U)
/** \brief Dio_WritePort() */
#define DIO_SID_WRITE_PORT             (0x3U)
/** \brief Dio_ReadChannelGroup() */
#define DIO_SID_READ_CHANNEL_GROUP     (0x4U)
/** \brief Dio_WriteChannelGroup() */
#define DIO_SID_WRITE_CHANNEL_GROUP    (0x5U)
/** \brief Dio_FlipChannel() */
#define DIO_SID_FLIP_CHANNEL           (0x11U)
/** \brief Dio_GetVersionInfo() */
#define DIO_SID_GET_VERSION_INFO       (0x12U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Numeric ID of a DIO channel. */
/* Design: MCAL-22469 */
typedef uint32 Dio_ChannelType;

/** \brief Numeric ID of a DIO port. */
/* Design: MCAL-22472 */
typedef uint32 Dio_PortType;

/** \brief These are the possible levels a DIO channel can have (input or output). */
/* Design: MCAL-22477 */
typedef uint8 Dio_LevelType;

/** \brief If the uC owns ports of different port widths Dio_PortLevelType
 * inherits the size of the largest port. */
/* Design: MCAL-22478 */
typedef uint32 Dio_PortLevelType;

/** \brief Type definition for identifying channel groups (meaning a set of
 * pins in one port). */
/* Design: MCAL-22475, MCAL-22510, MCAL-22511 */
typedef struct Dio_ChannelGroupType_s
{
    /** \brief Port ID of a channel group. */
    Dio_PortType      port; 
    /** \brief Bitmask where a '1' represents a pin handled by this channel group. */  
    Dio_PortLevelType mask;
    /** \brief Shifts channel group values, so it is always "right" aligned. */   
    uint8             offset; 
} Dio_ChannelGroupType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == DIO_VERSION_INFO_API)
/** \brief Service to get the version information of the module.
 *
 * This service writes the version information of this module into the data
 * structure referenced by the parameter. If this parameter references
 * NULL_PTR, a development error is reported to Det. This service is only
 * available if the pre-compile configuration parameter DIO_VERSION_INFO_API
 * is enabled.
 * 
 * \param[in] Versioninfo
 * \param[out] Versioninfo structure that contains the version information parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE) \
Dio_GetVersionInfo(P2VAR (Std_VersionInfoType, AUTOMATIC,DIO_APPL_DATA) \
                   Versioninfo);
#endif

/** \brief Returns the value of the specified DIO channel.
 *
 * This service is to read from a specified DIO channel. If the channel
 * specified is not valid, a development error is reported to Det. The value
 * for the DIO channel is read and returned.
 * 
 * \param[in] ChannelId specifies the ID of the general-purpose digital
 *     input/output pin.
 * \pre None
 * \post None
 * \return Returns the logic level(value) on a specified DIO pin of type Dio_LevelType.
 * \retval STD_HIGH: logic level 1
 * \retval STD_LOW: logic level 0
 *
 *********************************************************************************************************************/
FUNC(Dio_LevelType, DIO_CODE) \
Dio_ReadChannel(Dio_ChannelType ChannelId);

/** \brief Service to set a level of a channel.
 *
 * This service is to set a specified level of a particular DIO channel. If
 * the channel specified is not valid, a development error is reported to Det.
 * The value is written to the specified DIO channel.
 * 
 * \param[in] ChannelId specifies the ID of the general-purpose digital
 * input/output pin.
 * \param[in] Level specifies the value to be written to the channel. Value can
 * be STD_HIGH or STD_LOW.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE) \
Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/** \brief Returns the level of all channels of that port.
 * 
 * This service reads the value of a DIO port. If the port is not
 * enabled, a development error is reported to Det. The value of the port of
 * which the ID is specified is read and returned.
 *
 * \param[in] PortId specifies the ID of the grouped Input/Output channels.
 * \pre None
 * \post None
 * \return level of all the channels of the specified port
 * \retval Value of type Dio_PortLevelType
 *
 *********************************************************************************************************************/
FUNC(Dio_PortLevelType, DIO_CODE) \
Dio_ReadPort(Dio_PortType PortId);

/** \brief Service to set a value of the port.
 *
 * This service sets a specified value of a DIO port. If the port is not
 * enabled, a development error is reported to Det. The value is written
 * to the specified DIO port.
 *
 * \param[in] PortId specifies the ID of the grouped Input/Output channels.
 * \param[in] Level Value consisting of level of all the channels of the
 * specified port.
 * \pre None
 * \post None
 * \return None
 * \retval None
 * 
 *********************************************************************************************************************/
FUNC(void, DIO_CODE) \
Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/** \brief This Service reads a subset of the adjoining bits of a port.
 *
 * This service reads the value of the subset of the bits of a port. If this
 * parameter references NULL_PTR, a development error is reported to Det. The
 * value of the level of the channel group is read and returned.
 * 
 * \param[in] ChannelGroupIdPtr for referencing channel group structures.
 * \pre None
 * \post None
 * \return levels of the specified channel group.
 * \retval value of type Dio_PortLevelType
 * 
 *********************************************************************************************************************/
FUNC(Dio_PortLevelType, DIO_CODE) \
Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr);

/** \brief Service to set a subset of the adjoining bits of a port to a
 * specified level.
 * 
 * This service writes the specified value to a subset of the bits of a port.
 * If this parameter references NULL_PTR, a development error is reported to
 * Det. The information of the channel group is in the referenced channel
 * group structure.The data is then written to the port.
 * 
 * \param[in] ChannelGroupIdPtr for referencing channel group structures.
 * \param[in] Level Value consisting of levels of the specified channel group.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE) \
Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr, \
                      Dio_PortLevelType Level);

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/** \brief Service to flip the value of a DIO channel.
 *
 * This service is to change the value of the corresponding DIO channel.If
 * the channel specified is not valid, a development error is reported to Det.
 * The value of the specified channel is flipped.This service is only
 * available if the pre-compile configuration parameter DIO_FLIP_CHANNEL_API
 * is enabled.
 * 
 * \param[in] ChannelId specifies the ID of the general-purpose digital input/output pin.
 * \pre None
 * \post None
 * \return Value consisting of level of the specified channel after flip of type Dio_LevelType.
 * \retval STD_HIGH: logic level 1
 *         STD_LOW: logic level 0
 *
 *********************************************************************************************************************/
FUNC(Dio_LevelType, DIO_CODE) \
Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* Mark the end of the C bindings section for C++ compilers. */
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* DIO_H */
/*********************************************************************************************************************
 *  End of File: Dio.h
 *********************************************************************************************************************/
