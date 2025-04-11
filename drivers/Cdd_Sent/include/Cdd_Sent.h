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
 * Design:  MCAL-xxxxx
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-xxxx */
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
#define CDD_SENT_SW_MAJOR_VERSION     (1U)
/** \brief Driver Implementation Minor Version. */
#define CDD_SENT_SW_MINOR_VERSION     (0U)
/** \brief Driver Implementation Patch Version. */
#define CDD_SENT_SW_PATCH_VERSION     (0U)

/** \brief AUTOSAR major version specification implemented by CDD_SENT Driver. */
#define CDD_SENT_AR_RELEASE_MAJOR_VERSION    (4U)
/** \brief AUTOSAR minor version specification implemented by CDD_SENT Driver. */
#define CDD_SENT_AR_RELEASE_MINOR_VERSION    (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_SENT Driver. */
#define CDD_SENT_AR_RELEASE_REVISION_VERSION (1U)

/** \brief Texas Instruments Vendor ID. */
#define CDD_SENT_VENDOR_ID   ((uint16) 44U)
/** \brief CDD_SENT Driver Module ID. */
#define CDD_SENT_MODULE_ID   ((uint16) 255U)
/** \brief  CDD_SENT Driver Instance ID. */
#define CDD_SENT_INSTANCE_ID ((uint8) 0U)
                                                
/** \brief API parameter checking: invalid pointer. */
#ifndef CDD_SENT_E_PARAM_POINTER
#define CDD_SENT_E_PARAM_POINTER             (0x20U)
#endif

/** \brief API parameter checking: invalid value. */
#ifndef CDD_SENT_E_PARAM_CHANNEL
#define CDD_SENT_E_PARAM_CHANNEL             (0x21U)
#endif

/** \brief API service for initialization called when already  initialized. */
#ifndef CDD_SENT_E_ALREADY_INITIALIZED
#define CDD_SENT_E_ALREADY_INITIALIZED       (0x22U)
#endif

/** \brief  API service called without module initialization. */
#ifndef CDD_SENT_E_UNINIT
#define CDD_SENT_E_UNINIT                    (0x23U)
#endif

/** \brief Cdd_Sent_GetVersionInfo(). */
#define CDD_SENT_SID_GET_VERSION_INFO       (0x0U)
/** \brief Cdd_Sent_Init(). */
#define CDD_SENT_SID_INIT                   (0x1U)
/** \brief Cdd_Sent_Deinit(). */
#define CDD_SENT_SID_DEINIT                 (0x2U)
/** \brief Cdd_Sent_TriggerPulse(). */
#define CDD_SENT_SID_TRANSMIT               (0x3U) 
/** \brief TIMESTAMP MEMDATA */
#define TIMESTAMP_MEMDATA                   ((uint16) 0x3U)
/** \brief DATA0 MEMDATA */
#define DATA0_MEMDATA                       ((uint16) 0x1U)

/** \brief Data offsent for data1 and data 0 */
#define SENT_DATAXMAP_STEP       (SENT_O_DATA1_MAP - SENT_O_DATA0_MAP)
/** \brief software trigger step */
#define SENT_MTP_SWTR_STEP      (SENT_O_S1_MTP_SWTR - SENT_O_BC_MTP_SWTR)

/** \brief SENSOR 1 ERROR INTERRUPTS */
#define SENSOR_1_ERROR_INTERRUPTS      (0x381100U)
/** \brief SENSOR 2 ERROR INTERRUPTS */
#define SENSOR_2_ERROR_INTERRUPTS      (0x382200U)
/** \brief SENSOR 3 ERROR INTERRUPTS */
#define SENSOR_3_ERROR_INTERRUPTS      (0x384400U)
/** \brief SENSOR 4 ERROR INTERRUPTS */
#define SENSOR_4_ERROR_INTERRUPTS      (0x388800U)
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Type for Cdd_SENT Instance */
/*
 *Design: MCAL-xxxx
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
typedef enum
{
    /** \brief Receiver Data 0 */
    CDD_SENT_RECEIVER_DATA0 = 0x0U,   
    /** \brief Receiver Data 1 */
    CDD_SENT_RECEIVER_DATA1 = 0x1U
} Cdd_Sent_DataNumber;

/** \brief Type for Receiver Data Nibble Number */
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
typedef enum
{
    /** \brief No Nibble Selected */
    CDD_SENT_NO_NIBBLE      = 0x0U,
    /** \brief Data Nibble 1 */   
    CDD_SENT_DATA_NIBBLE1   = 0x1U,   
    /** \brief Data Nibble 2 */   
    CDD_SENT_DATA_NIBBLE2   = 0x2U,   
    /** \brief Data Nibble 3 */   
    CDD_SENT_DATA_NIBBLE3   = 0x3U,   
    /** \brief Data Nibble 4 */   
    CDD_SENT_DATA_NIBBLE4   = 0x4U,   
    /** \brief Data Nibble 5 */   
    CDD_SENT_DATA_NIBBLE5   = 0x5U,   
    /** \brief Data Nibble 6 */   
    CDD_SENT_DATA_NIBBLE6   = 0x6U,   
    /** \brief Data Nibble 7 */   
    CDD_SENT_DATA_NIBBLE7   = 0x7U,   
    /** \brief Data Nibble 8 */   
    CDD_SENT_DATA_NIBBLE8   = 0x8U,   
    /** \brief Crc Nibble 1 */   
    CDD_SENT_CRC_NIBBLE1    = 0xAU,   
    /** \brief Crc Nibble 2 */   
    CDD_SENT_CRC_NIBBLE2    = 0xBU,   
    /** \brief status Nibble */   
    CDD_SENT_STATUS_NIBBLE  = 0xFU 
} Cdd_SentNibble;

/** \brief Type for SENT CRC Type */
/*
 *Design: MCAL-xxxx
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
 *Design: MCAL-xxxx
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
typedef enum
{
    /** \brief Direct Mapping Mode */
    SENT_DIRECT_MEMMAPPED = 0U,
    /** \brief Fifo  Mode */
    CDD_SENT_FIFOMODE_FIFO = 1U

} Cdd_SentFIFOMode;

/** \brief Type for Trigger Level */
typedef enum
{
    /** \brief Trigger disable */
    CDD_SENT_TRIGDISABLE    = 0U,
    /** \brief Trigger level 1 */
    CDD_SENT_TRIGLEV1       = 1U,       
    /** \brief Trigger level 2 */
    CDD_SENT_TRIGLEV2       = 2U,      
    /** \brief Trigger level 3 */
    CDD_SENT_TRIGLEV3       = 3U,    
    /** \brief Trigger level 4 */
    CDD_SENT_TRIGLEV4       = 4U,       
    /** \brief Trigger level 5 */
    CDD_SENT_TRIGLEV5       = 5U,       
    /** \brief Trigger level 6 */
    CDD_SENT_TRIGLEV6       = 6U,       
    /** \brief Trigger level 7 */
    CDD_SENT_TRIGLEV7       = 7U,       
    /** \brief Trigger level 8 */
    CDD_SENT_TRIGLEV8       = 8U,       
    /** \brief Trigger level 9 */
    CDD_SENT_TRIGLEV9       = 9U,       
    /** \brief Trigger level 10 */
    CDD_SENT_TRIGLEV10      = 10,       
    /** \brief Trigger level 11 */
    CDD_SENT_TRIGLEV11      = 11U,      
    /** \brief Trigger level 12 */
    CDD_SENT_TRIGLEV12      = 12U,      
    /** \brief Trigger level 13 */
    CDD_SENT_TRIGLEV13      = 13U,      
    /** \brief Trigger level 14 */
    CDD_SENT_TRIGLEV14      = 14U,      
    /** \brief Trigger level 15 */
    CDD_SENT_TRIGLEV15      = 15U,     
    /** \brief Trigger level 16 */
    CDD_SENT_TRIGLEV16      = 16U       
} Cdd_SentTriggerLevel;

/** \brief Type for SENT CRC includes status or not */
/*
 *Design: MCAL-xxxx
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
 *Design: MCAL-xxxx
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
 *Design: MCAL-xxxx
 */
typedef enum
{
    /** \brief sensor trigger 1 */
    CDD_SENT_CHANNEL_SENSOR_1,
    /** \brief sensor trigger 2 */
    CDD_SENT_CHANNEL_SENSOR_2,
    /** \brief sensor trigger 3 */
    CDD_SENT_CHANNEL_SENSOR_3,
    /** \brief sensor trigger 4 */
    CDD_SENT_CHANNEL_SENSOR_4,
    /** \brief Broadcast sensor trigger*/
    CDD_SENT_CHANNEL_BROADCAST,
}Cdd_SentSensorType;


/*
 *Design: MCAL-xxxx
 */
/** \brief  Sent Channel Type. */
typedef enum
{
    /** \brief Fast channel */
    FAST_CHANNEL,
    /** \brief Short serial slow channel */
    SHORT_SERIAL_SLOW_CHANNEL,
    /** \brief Enhanced serial 12 bit slow channel */
    ENHANCED_SERIAL_12BIT_SLOW_CHANNEL,
    /** \brief enhanced serial 16 bit slowc channel */
    ENHANCED_SERIAL_16BIT_SLOW_CHANNEL
}Cdd_SentChannelType;

/** \brief  Sent Data Buffer. */
typedef struct
{
    #if ENABLE_TIMESTAMP
        /** \brief Timestamp */
        uint32 Timestamp[1];
    #endif
    /** \brief Data Buffer */
    uint32 Data_Buffer[1];
}Cdd_Sent_Data_Buffer;


/** \brief  Notification callback function pointer. */
typedef void (*Cdd_Sent_NotifyType)(PduIdType id, const PduInfoType *PduInfoPtr);

/** \brief  Configuration per HW unit */
/*
 *Design: MCAL-xxxx
 */
typedef struct Cdd_Sent_ChannelConfigType_s
{
    /** \brief CDD_SENT sensor type */
    Cdd_SentSensorType Cdd_SentSensorType;
    /** \brief CDD_SENT channel */
    Cdd_SentChannelType Cdd_SentChannelType;
    /** \brief CDD_SENT Enable Timestamp */
    boolean                EnableTimeStamp;
    /** \brief CDD_SENT ChannelID */  
    uint32                 Cdd_Sent_channelID;
    /** \brief CDD_SENT SensorID*/
    uint32                  Cdd_Sent_MessageID;
    /** \brief CDD_SENT Data buffer */
    Cdd_Sent_Data_Buffer             Cdd_Sent_Buffer_Data;
} Cdd_Sent_ChannelConfigType;

/** \brief  Configuration per HW unit */
/*
 *Design: MCAL-xxxx
 */
typedef struct Cdd_Sent_HWUnitType_s
{
    /** \brief CDD_SENT HW unit ID */
    uint8               Cdd_SentHWUnitId;
    /** \brief CDD_SENT HW unit Instance */ 
    Cdd_SentInstance   Cdd_SentInstance;
    /** \brief CDD_SENT Enable Fast Interrupt */
    uint32             Enable_Fast_Interrupt;
    /** \brief CDD_SENT Enable Slow Interrupt */
    uint32             Enable_Slow_Interrupt;
    /** \brief CDD_SENT HW unit Base Address */
    uint32              Cdd_SentBaseAddress;
    /** \brief Clock tick time for the CDD_SENT data range 3usec -10 usec*/
    uint32               Cdd_SentClockTick;
    /** \brief CDD_SENT CRC type */
    Cdd_SentCRCType    Cdd_SentCRCType;
    /** \brief CDD_SENT CRC Width */
    Cdd_SentCRCWidth   Cdd_SentCRCWidth;
    /** \brief CDD_SENT CRC status */
    Cdd_SentCRCWithStatus  Cdd_SentCRCWithStatus;
    /** \brief CDD_SENT Data Nibbles Count */
    Cdd_SentDataNibblesCount    Cdd_SentDataNibblesCount;
    /** \brief CDD_SENT FIFO trigger level */
    Cdd_SentTriggerLevel  FIFOTriggerLevel;
    /** \brief CDD_SENT Sync Timeout */
    uint32              SyncTimeout;
    /** \brief Accept Error Data */
    boolean                AcceptErrorData;
    /** \brief Glitch filter */
    uint8                  GlitchFilter;
    /** \brief CDD_SENT Pause Pulse */
    boolean                Cdd_SentPausePulse;
    /** \brief CDD_SENT Channel Count */
    uint8               Cdd_SentChannelCount;
    /** \brief CDD_SENT CONFIG List */
    Cdd_Sent_ChannelConfigType**    Cdd_SentChannelConfigList;
    /** \brief User call back function */
    Cdd_Sent_NotifyType         Cdd_SentUserCallbackFunction;
} Cdd_Sent_HWUnitType;

/** \brief  Configuration per HW unit */
/*
 *Design: MCAL-xxxx
 */

typedef struct Cdd_Sent_DriverObjType_s
{
    /* SENT HW unit ID */
    Cdd_Sent_HWUnitType *Cdd_Sent_HWUnit[6];  /* [SENT_MAX_HW_UNITS]*/

} Cdd_Sent_ConfigType;

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
FUNC(void, CDD_SENT_CODE) \
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
FUNC(void, CDD_SENT_CODE) Cdd_Sent_Init(P2CONST(Cdd_Sent_ConfigType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

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

/** \brief Cdd_Sent_TriggerPulse : Triggers the MTP.
 *
 * This service will trigger the MTP in case of MTP enabled.
 *
 * \param[in] PduInfoPtr Pointer to PDU Information.
 * \param[in] TxPduId ID of the Tx PDU
 * \pre Cdd_Sent_Init should be called first before calling this service.
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SENT_CODE) \
Cdd_Sent_TriggerPulse(P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr, \
                    PduIdType TxPduId);


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
