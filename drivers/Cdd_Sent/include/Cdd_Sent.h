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
 *  File:       Cdd_Sent.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Cdd_Sent Driver functions
 *
 *********************************************************************************************************************/
#ifndef CDD_SENT_H
#define CDD_SENT_H
/**
 * \defgroup CDD_SENT Cdd_Sent API GUIDE Header file
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Below are the global requirements which are met by this Cdd_SENT driver which
 * can't be mapped to a particular source ID.
 *
 * Design:  MCAL-28615
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-28632, MCAL-28611, MCAL-28612, MCAL-28613, MCAL-28614, MCAL-28623,  MCAL-28681
 */
#include "Std_Types.h"
#include "Cdd_Sent_Cfg.h"
#include "ComStack_Types.h"
#include "PduR.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief Driver Implementation Major Version. */
#define CDD_SENT_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version. */
#define CDD_SENT_SW_MINOR_VERSION (1U)
/** \brief Driver Implementation Patch Version. */
#define CDD_SENT_SW_PATCH_VERSION (0U)

/** \brief AUTOSAR major version specification implemented by Cdd_Sent Driver. */
#define CDD_SENT_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR minor version specification implemented by Cdd_Sent Driver. */
#define CDD_SENT_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by Cdd_Sent Driver. */
#define CDD_SENT_AR_RELEASE_REVISION_VERSION (1U)

/** \brief Texas Instruments Vendor ID. */
#define CDD_SENT_VENDOR_ID ((uint16)44U)
/** \brief Cdd_Sent Driver Module ID. */
#define CDD_SENT_MODULE_ID ((uint16)255U)
/** \brief  Cdd_Sent Driver Instance ID. */
#define CDD_SENT_INSTANCE_ID ((uint8)0U)

/*
 * Design: MCAL-28630
 */
/** \brief API parameter checking: invalid pointer. */
#ifndef CDD_SENT_E_PARAM_POINTER
#define CDD_SENT_E_PARAM_POINTER (0x20U)
#endif

/*
 * Design: MCAL-28629
 */
/** \brief API parameter checking: invalid value. */
#ifndef CDD_SENT_E_PARAM_CHANNEL
#define CDD_SENT_E_PARAM_CHANNEL (0x21U)
#endif

/*
 * Design: MCAL-28631
 */
/** \brief API service for initialization called when already  initialized. */
#ifndef CDD_SENT_E_ALREADY_INITIALIZED
#define CDD_SENT_E_ALREADY_INITIALIZED (0x22U)
#endif

/*
 * Design: MCAL-28628
 */
/** \brief  API service called without module initialization. */
#ifndef CDD_SENT_E_UNINIT
#define CDD_SENT_E_UNINIT (0x23U)
#endif

/*
 * Design: MCAL-28627
 */
/*********************************************************************************************************************
 * CDD SENT Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 *********************************************************************************************************************/
/** \brief Cdd_Sent_GetVersionInfo(). */
#define CDD_SENT_SID_GET_VERSION_INFO (0x0U)
/** \brief Cdd_Sent_Init(). */
#define CDD_SENT_SID_INIT (0x1U)
/** \brief Cdd_Sent_Deinit(). */
#define CDD_SENT_SID_DEINIT (0x2U)
/** \brief Cdd_Sent_Transmit(). */
#define CDD_SENT_SID_TRANSMIT (0x3U)
/** \brief Cdd_Sent_Enable_Interrupts(). */
#define CDD_SENT_SID_ENABLE_INTERRUPT (0x4U)
/** \brief Cdd_Sent_Disable_Interrupts(). */
#define CDD_SENT_SID_DISABLE_INTERRUPT (0x5U)

/** \brief TIMESTAMP MEMDATA */
#define TIMESTAMP_MEMDATA ((uint16)0x3U)
/** \brief DATA0 MEMDATA */
#define DATA0_MEMDATA ((uint16)0x1U)

/** \brief Data offsent for data1 and data 0 */
#define SENT_DATAXMAP_STEP (SENT_O_DATA1_MAP - SENT_O_DATA0_MAP)
/** \brief software trigger step */
#define SENT_MTP_SWTR_STEP (SENT_O_S1_MTP_SWTR - SENT_O_BC_MTP_SWTR)
/** \brief Mtp Timeout step */
#define SENT_MTP_TIMEOUT_STEP (SENT_O_S2_MTP_TO - SENT_O_S1_MTP_TO)
/*
 * Design: MCAL-28668
 */
/** \brief maximum number of sensors */
#define MAXIMUM_NUMBER_OF_SENSORS (4U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Type for reading and setting the channel index */
/*
 * Design: MCAL-28675
 */
typedef uint32 CddSent_ValueType;

/** \brief Type for Cdd_Sent Instance */
/*
 * Design: MCAL-28636
 */
typedef enum
{
    /** \brief SENT instance 1*/
    CDD_SENT_INSTANCE_SENT1,
    /** \brief SENT instance 2*/
    CDD_SENT_INSTANCE_SENT2,
    /** \brief SENT instance 3*/
    CDD_SENT_INSTANCE_SENT3,
    /** \brief SENT instance 4*/
    CDD_SENT_INSTANCE_SENT4,
    /** \brief SENT instance 5*/
    CDD_SENT_INSTANCE_SENT5,
    /** \brief SENT instance 6*/
    CDD_SENT_INSTANCE_SENT6,
} Cdd_SentInstance;

/** \brief Type for Receiver Data */
/*
 * Design: MCAL-28637
 */
typedef enum
{
    /** \brief Receiver Data 0 */
    CDD_SENT_RECEIVER_DATA0 = 0x0U,
    /** \brief Receiver Data 1 */
    CDD_SENT_RECEIVER_DATA1 = 0x1U
} Cdd_Sent_DataNumber;

/** \brief Type for Receiver Data Nibble Number */
/*
 * Design: MCAL-28638
 */
typedef enum
{
    /** \brief DataX Nibble Number 0 */
    CDD_SENT_DATAX_NIB0 = 0x0U,
    /** \brief DataX Nibble Number 1 */
    CDD_SENT_DATAX_NIB1 = 0x1U,
    /** \brief DataX Nibble Number 2 */
    CDD_SENT_DATAX_NIB2 = 0x2U,
    /** \brief DataX Nibble Number 3 */
    CDD_SENT_DATAX_NIB3 = 0x3U,
    /** \brief DataX Nibble Number 4 */
    CDD_SENT_DATAX_NIB4 = 0x4U,
    /** \brief DataX Nibble Number 5 */
    CDD_SENT_DATAX_NIB5 = 0x5U,
    /** \brief DataX Nibble Number 6 */
    CDD_SENT_DATAX_NIB6 = 0x6U,
    /** \brief DataX Nibble Number 7 */
    CDD_SENT_DATAX_NIB7 = 0x7U
} Cdd_SentNibbleNumber;

/** \brief Type for Receiver Data Nibble*/
/*
 * Design: MCAL-28639
 */
typedef enum
{
    /** \brief No Nibble Selected */
    CDD_SENT_NO_NIBBLE = 0x0U,
    /** \brief Data Nibble 1 */
    CDD_SENT_DATA_NIBBLE1 = 0x1U,
    /** \brief Data Nibble 2 */
    CDD_SENT_DATA_NIBBLE2 = 0x2U,
    /** \brief Data Nibble 3 */
    CDD_SENT_DATA_NIBBLE3 = 0x3U,
    /** \brief Data Nibble 4 */
    CDD_SENT_DATA_NIBBLE4 = 0x4U,
    /** \brief Data Nibble 5 */
    CDD_SENT_DATA_NIBBLE5 = 0x5U,
    /** \brief Data Nibble 6 */
    CDD_SENT_DATA_NIBBLE6 = 0x6U,
    /** \brief Data Nibble 7 */
    CDD_SENT_DATA_NIBBLE7 = 0x7U,
    /** \brief Data Nibble 8 */
    CDD_SENT_DATA_NIBBLE8 = 0x8U,
    /** \brief Crc Nibble 1 */
    CDD_SENT_CRC_NIBBLE1 = 0xAU,
    /** \brief Crc Nibble 2 */
    CDD_SENT_CRC_NIBBLE2 = 0xBU,
    /** \brief status Nibble */
    CDD_SENT_STATUS_NIBBLE = 0xFU
} Cdd_SentNibble;

/** \brief Type for SENT CRC Type */
/*
 * Design: MCAL-28640
 */
typedef enum
{
    /** \brief legacy CRC 2007 */
    CDD_SENT_CRC_LEGACY_2007 = 0x800U,
    /** \brief Recommended CRC 2010 */
    CDD_SENT_CRC_RECOMENDED_2010 = 0x000U,
    /** \brief CRC Disable */
    CDD_SENT_CRC_NONE = 0xFFFU,
} Cdd_SentCRCType;

/** \brief Type for SENT CRC Width */
/*
 * Design: MCAL-28641
 */
typedef enum
{
    /** \brief 4 Bit CRC*/
    CDD_SENT_CRC_4_BIT = 0,
    /** \brief 6 Bit CRC*/
    CDD_SENT_CRC_6_BIT = 1,
    /** \brief 8 Bit CRC*/
    CDD_SENT_CRC_8_BIT = 2,
} Cdd_SentCRCWidth;

/** \brief Sent Data mode type */
/*
 * Design: MCAL-28642
 */
typedef enum
{
    /** \brief Direct Mapping Mode */
    SENT_DIRECT_MEMMAPPED = 0U,
    /** \brief Fifo  Mode */
    CDD_SENT_FIFOMODE_FIFO = 1U

} Cdd_SentFIFOMode;

/** \brief Type for Trigger Level */
/*
 * Design: MCAL-28643
 */
typedef enum
{
    /** \brief Trigger disable */
    CDD_SENT_TRIGDISABLE = 0U,
    /** \brief Trigger level 3 */
    CDD_SENT_TRIGLEV3 = 3U,
    /** \brief Trigger level 4 */
    CDD_SENT_TRIGLEV4 = 4U,
    /** \brief Trigger level 5 */
    CDD_SENT_TRIGLEV5 = 5U,
    /** \brief Trigger level 6 */
    CDD_SENT_TRIGLEV6 = 6U,
    /** \brief Trigger level 7 */
    CDD_SENT_TRIGLEV7 = 7U,
    /** \brief Trigger level 8 */
    CDD_SENT_TRIGLEV8 = 8U,
    /** \brief Trigger level 9 */
    CDD_SENT_TRIGLEV9 = 9U,
    /** \brief Trigger level 10 */
    CDD_SENT_TRIGLEV10 = 10,
    /** \brief Trigger level 11 */
    CDD_SENT_TRIGLEV11 = 11U,
    /** \brief Trigger level 12 */
    CDD_SENT_TRIGLEV12 = 12U,
    /** \brief Trigger level 13 */
    CDD_SENT_TRIGLEV13 = 13U,
    /** \brief Trigger level 14 */
    CDD_SENT_TRIGLEV14 = 14U,
    /** \brief Trigger level 15 */
    CDD_SENT_TRIGLEV15 = 15U,
    /** \brief Trigger level 16 */
    CDD_SENT_TRIGLEV16 = 16U
} Cdd_SentTriggerLevel;

/** \brief Type for SENT CRC includes status or not */
/*
 * Design: MCAL-28644
 */
typedef enum
{
    /** \brief Calculation of CRC includes Status nibble*/
    CDD_SENT_CRC_WITH_STATUS = 0x400,
    /** \brief Calculation of CRC excludes Status nibble*/
    CDD_SENT_CRC_WITHOUT_STATUS = 0x000,
} Cdd_SentCRCWithStatus;

/** \brief Type for SENT number of data nibbles count */
/*
 * Design: MCAL-28645
 */
typedef enum
{
    /** \brief 1 data nibble per-frame */
    CDD_SENT_1_DATA_NIBBLES = 1,
    /** \brief 2 data nibble per-frame */
    CDD_SENT_2_DATA_NIBBLES = 2,
    /** \brief 3 data nibble per-frame */
    CDD_SENT_3_DATA_NIBBLES = 3,
    /** \brief 4 data nibble per-frame */
    CDD_SENT_4_DATA_NIBBLES = 4,
    /** \brief 5 data nibble per-frame */
    CDD_SENT_5_DATA_NIBBLES = 5,
    /** \brief 6 data nibble per-frame */
    CDD_SENT_6_DATA_NIBBLES = 6,
    /** \brief 7 data nibble per-frame */
    CDD_SENT_7_DATA_NIBBLES = 7,
    /** \brief 8 data nibble per-frame */
    CDD_SENT_8_DATA_NIBBLES = 8,
} Cdd_SentDataNibblesCount;

/** \brief Type for SENT Sensor type */
/*
 * Design: MCAL-28646
 */
typedef enum
{
    /** \brief Broadcast sensor trigger*/
    CDD_SENT_CHANNEL_BROADCAST,
    /** \brief sensor trigger 1 */
    CDD_SENT_CHANNEL_SENSOR_1,
    /** \brief sensor trigger 2 */
    CDD_SENT_CHANNEL_SENSOR_2,
    /** \brief sensor trigger 3 */
    CDD_SENT_CHANNEL_SENSOR_3,
    /** \brief sensor trigger 4 */
    CDD_SENT_CHANNEL_SENSOR_4,
    /** \brief Standard sensor trigger  */
    CDD_SENT_CHANNEL_STANDARD_SENSOR,
} Cdd_SentSensorType;

/*
 * Design: MCAL-28647
 */
/** \brief  Sent Channel Type. */
typedef enum
{
    /** \brief Fast channel for Stanadard sensor */
    CDD_SENT_CHANNEL_STANDARD_SENSOR_FAST_CHANNEL,
    /** \brief Fast channel for sensor 1 */
    CDD_SENT_CHANNEL_SENSOR_1_FAST_CHANNEL,
    /** \brief Fast channel for sensor 2 */
    CDD_SENT_CHANNEL_SENSOR_2_FAST_CHANNEL,
    /** \brief Fast channel for sensor 3 */
    CDD_SENT_CHANNEL_SENSOR_3_FAST_CHANNEL,
    /** \brief Fast channel for sensor 4 */
    CDD_SENT_CHANNEL_SENSOR_4_FAST_CHANNEL,
    /** \brief Short serial and Enhanced serial 12  slow channel */
    SHORT_SERIAL_ENHANCED_SERIAL_12BIT_SLOW_CHANNEL,
    /** \brief enhanced serial 16 bit slowc channel */
    ENHANCED_SERIAL_16BIT_SLOW_CHANNEL
} Cdd_SentChannelType;

/** \brief  Sent Data Buffer. */
/*
 * Design: MCAL-28648
 */
typedef struct
{
    /** \brief Timestamp */
    uint32 Timestamp[1];
    /** \brief Data Buffer */
    uint32 Data_Buffer[2];
} Cdd_Sent_Data_Buffer;

/*
 * Design: MCAL-28664
 */
/** \brief  Notification callback function pointer. */
typedef void (*Cdd_Sent_NotifyType)(PduIdType id, const PduInfoType *PduInfoPtr);

/*
 * Design: MCAL-28665
 */
/** \brief  Error Notification callback function pointer. */
typedef void (*Cdd_Sent_ErrorNotifyType)(void);

/** \brief  Configuration per HW unit */
/*
 * Design: MCAL-28674
 */
typedef struct Cdd_Sent_MTPConfigType_s
{
    /** \brief Cdd_Sent channel type*/
    Cdd_SentSensorType    CddSentMTPSensorType;
    /** \brief interrupt source*/
    Cdd_SentTriggerSource CddSentTriggerSource;
    /** \brief Cdd_Sent MTP enable or not */
    boolean               CddSentMTPSensorEnable;
    /** \brief Cdd_Sent sensor Timeout */
    uint32                CddSentMTPSensorTimeout;
    /** \brief Cdd_Sent MTP Channel Period */
    uint16                CddSentMTPSensorPeriod;
    /** \brief Cdd_Sent MTP Channel Compare 1 */
    uint16                CddSentMTPSensorCompare1;
    /** \brief Cdd_Sent MTP Channel Compare 2 */
    uint16                CddSentMTPSensorCompare2;
    /** \brief Cdd_Sent MTP Channel Compare 3 */
    uint16                CddSentMTPSensorCompare3;
    /** \brief Cdd_Sent MTP Channel Compare 4 */
    uint16                CddSentMTPSensorCompare4;
    /** \brief Cdd_Sent MTP Channel Compare 5 */
    uint16                CddSentMTPSensorCompare5;
    /** \brief Cdd_Sent MTP Channel Compare 6 */
    uint16                CddSentMTPSensorCompare6;
    /** \brief Cdd_Sent MTP Channel Compare 7 */
    uint16                CddSentMTPSensorCompare7;
    /** \brief Cdd_Sent MTP Channel Compare 8 */
    uint16                CddSentMTPSensorCompare8;
    /** \brief Cdd_Sent MTP Channel Compare 9 */
    uint16                CddSentMTPSensorCompare9;
    /** \brief Cdd_Sent MTP Channel Compare 10 */
    uint16                CddSentMTPSensorCompare10;
    /** \brief Cdd_Sent Sensor PduId*/
    uint16                CddSentMTPSensorPduID;

} Cdd_Sent_MTPConfigType;

/** \brief  Configuration per HW unit */
/*
 * Design: MCAL-28672
 */
typedef struct Cdd_Sent_ChannelConfigType_s
{
    /** \brief Cdd_Sent sensor type */
    Cdd_SentSensorType  CddSentSensorType;
    /** \brief Cdd_Sent channel */
    Cdd_SentChannelType CddSentChannelType;
    /** \brief Cdd_Sent PduID */
    uint32              CddSentPduID;
    /** \brief Cdd_Sent SensorID*/
    uint32              CddSentMessageID;
} Cdd_Sent_ChannelConfigType;

/** \brief  Configuration per HW unit */
/*
 * Design: MCAL-28672
 */
typedef struct Cdd_Sent_HWUnitType_s
{
    /** \brief Cdd_Sent HW unit ID */
    uint8                        CddSentHWUnitId;
    /** \brief Cdd_Sent HW unit Instance */
    Cdd_SentInstance             CddSentInstance;
    /** \brief Cdd_Sent HW unit Base Address */
    uint32                       CddSentBaseAddress;
    /** \brief Clock tick time for the Cdd_Sent data range 3usec -10 usec*/
    uint32                       CddSentClockTick;
    /** \brief Cdd_Sent CRC type */
    Cdd_SentCRCType              CddSentCRCType;
    /** \brief Cdd_Sent CRC Width */
    Cdd_SentCRCWidth             CddSentCRCWidth;
    /** \brief Cdd_Sent CRC status */
    Cdd_SentCRCWithStatus        CddSentCRCWithStatus;
    /** \brief Cdd_Sent Data Nibbles Count */
    Cdd_SentDataNibblesCount     CddSentDataNibblesCount;
    /** \brief Cdd_Sent FIFO trigger level */
    Cdd_SentTriggerLevel         CddSentFIFOTriggerLevel;
    /** \brief Cdd_Sent Sync Timeout */
    uint32                       CddSentSyncTimeout;
    /** \brief Accept Error Data */
    boolean                      CddSentAcceptErrorData;
    /** \brief Cdd_Sent Enable Timestamp */
    boolean                      CddSentEnableTimeStamp;
    /** \brief Glitch filter */
    uint8                        CddSentGlitchFilter;
    /** \brief Cdd_Sent Channel Count */
    uint8                        CddSentChannelCount;
    /** \brief Cdd_Sent CONFIG List */
    Cdd_Sent_ChannelConfigType **CddSentChannelConfigList;
    /** \brief Cdd_Sent MTP */
    boolean                      CddSentMTP;
    /** \brief Cdd_Sent MTP Channel Count */
    uint8                        CddSentMTPChannelCount;
    /** \brief Cdd_Sent MTP CONFIG List */
    Cdd_Sent_MTPConfigType     **CddSentMTPConfigList;
    /** \brief Global wait time */
    uint16                       CddSentGlobalWaitTime;
    /** \brief User call back function */
    Cdd_Sent_NotifyType          CddSentUserCallbackFunction;
    /** \brief User call back function for Errors */
    Cdd_Sent_ErrorNotifyType     CddSentUserErrorCallbackFunction;
    /** \brief Cdd_Sent Data buffer */
    Cdd_Sent_Data_Buffer         CddSent_Buffer_Data;
} Cdd_Sent_HWUnitType;

/** \brief  Configuration per HW unit */
/*
 * Design: MCAL-28673
 */

typedef struct Cdd_Sent_ConfigType_s
{
    /** \brief  SENT HW unit ID */
    Cdd_Sent_HWUnitType *Cdd_Sent_HWUnit[SENT_MAX_HW_UNITS];

} Cdd_Sent_ConfigType;

/** \brief  Cdd_Sent driver object type structure */
/*
 * Design: MCAL-28679, MCAL-28633, MCAL-28634, MCAL-28635
 */
typedef struct Cdd_Sent_DriverObjType_s
{
    /** \brief Cdd Sent driver configuration pointer.*/
    const Cdd_Sent_ConfigType *CddSent_CfgPtr;
    /** \brief Lookup Table for Channel-Index  Ex:CddSent_Lut_Channel_Index[Ch] = index */
    CddSent_ValueType          CddSent_Lut_Channel_Index[SENT_MAX_HW_UNITS];
    /** \brief Array to store fast channel PDU id's */
    PduIdType                  CddSent_Fast_Channel_PduID[SENT_MAX_HW_UNITS][MAXIMUM_NUMBER_OF_SENSORS];

} Cdd_Sent_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Cdd_Sent_GetVersionInfo : Returns the Cdd sent Version Info.
 *
 * This service returns the version information of this module.
 *
 * \param[in] VersionInfoPtr
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
#if (STD_ON == CDD_SENT_CFG_GET_VERSION_INFO_API)
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_SENT_APPL_DATA) VersionInfoPtr);
#endif /* CDD_SENT_CFG_GET_VERSION_INFO_API */

/** \brief Cdd_Sent_Init : Initializes the CDD_SENT module.
 *
 * This service initializes the configured HW units.
 *
 * \param[in] ConfigPtr Pointer to CDD_SENT driver configuration set
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Init(P2CONST(Cdd_Sent_ConfigType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief Cdd_Sent_Deinit : De-initializes the CDD_SENT module.
 *
 * This service deinitialize the CDD_SENT driver
 *
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_SENT_CODE) Cdd_Sent_Deinit(void);

#if (STD_ON == CDD_SENT_ENABLE_MTP_MODE)
/** \brief Cdd_Sent_Transmit : Triggers the MTP.
 *
 *
 * \param[in] PduInfoPtr Pointer to PDU Information.
 *                       If PduInfoPtr->SduDataPtr[0] is 0, Will disbale HW trigger
 *                       If PduInfoPtr->SduDataPtr[0] is 1, Will configure HW trigger to
 *configuration value If PduInfoPtr->SduDataPtr[0] is 2, Will trigger SW trigger
 * \param[in] TxPduId  : When Cdd Sent is integrated with Autosar Com stack, this TxPduId parameter
 * is a Pdu identifier used  to address the respective sensor.
 * When Cdd Sent is not integrated with Autosar Com stack, this TxPduId parameter
 * is a device identifier used  to address the respective sensor.
 *
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_SENT_CODE)
Cdd_Sent_Transmit(P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr, PduIdType TxPduId);
#endif /* CDD_SENT_ENABLE_MTP_MODE */

/** \brief Cdd_Sent_Enable_Interrupts : Enable Interrupts.
 *
 * This service will enable interrupts.
 *
 * \param[in] SentInstance id of Sent HW unit.
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/

FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Enable_Interrupts(Cdd_SentInstance SentInstance);

/** \brief Cdd_Sent_Disable_Interrupts : Disable Interrupts.
 *
 * This service will Disable interrupts and ignore any received data as there
 * is no polling API for Cdd_Sent.
 *
 * \param[in] SentInstance id of Sent HW unit.
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/

FUNC(void, CDD_SENT_CODE)
Cdd_Sent_Disable_Interrupts(Cdd_SentInstance SentInstance);

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
#endif /* CDD_SENT_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Sent.h
 *********************************************************************************************************************/
