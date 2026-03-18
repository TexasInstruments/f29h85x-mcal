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
 *  File:       Cdd_I2c_Cfg.h
 *  Generator:  None
 *
 *  Description:  Cdd_I2c configuration header file
 *********************************************************************************************************************/
/**
 *  \addtogroup CDD_I2C
 *
 *  This files defines I2C configuration structures
 *  @{
 */

#ifndef CDD_I2C_CFG_H_
#define CDD_I2C_CFG_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief This type defines the addresss size */
typedef uint16 Cdd_I2c_AddressType;

/** \brief This type defines the direction of operation - write or read */
typedef uint8 Cdd_I2c_DirectionType;

/** \brief This type defines the data to be transmitted using the CDD_I2C Driver */
typedef uint8 Cdd_I2c_DataType;

/** \brief Definition for the pointer type for general buffer handling */
typedef uint8* Cdd_I2c_DataPtrType;

/** \brief Definition for the pointer type for TX buffer handling */
typedef const uint8* Cdd_I2c_DataConstPtrType;

/** \brief Specifies the identification (ID) for a CDD_I2C Hardware unit */
typedef uint8 Cdd_I2c_HwUnitType;

/** \brief This is the type for a sequence identifier */
typedef uint8 Cdd_I2c_SequenceType;

/** \brief This is the type for a Ch identifier */
typedef uint8 Cdd_I2c_ChannelType;

/** \brief Type to define the number of data elements to be sent and/or received
 *  during a transmission */
typedef uint16 Cdd_I2c_DataLengthType;

/**
 *  \name I2C Driver Configuration SW Version Info
 *
 *  Defines for I2C Driver configuration version
 *  @{
 */
/** \brief I2C configuration Major Version */
#define CDD_I2C_CFG_MAJOR_VERSION       (1U)
/** \brief I2C configuration Minor Version */
#define CDD_I2C_CFG_MINOR_VERSION       (2U)
/** \brief I2C configuration Patch Version */
#define CDD_I2C_CFG_PATCH_VERSION       (0U)
/** @} */

/**
 *  \brief I2C Build Variant.
 *   Build variants.(i.e Pre Compile and Post Build)
 */
#define CDD_I2C_PRE_COMPILE_VARIANT     (STD_ON)
/** \brief Precompile variant macro */
#define CDD_I2C_CONFIG_PC               Cdd_I2c_Config


/** \brief STD_ON if any HW unit uses polling */
#define CDD_I2C_POLLING_MODE        (STD_ON)
/** \brief STD_ON if any HW unit uses interrupts */
#define CDD_I2C_INTERRUPT_MODE      (STD_OFF)

/** \brief STD_ON if any HW unit is in controller mode */
#define CDD_I2C_CONTROLLER_ACTIVE   (STD_ON)
/** \brief STD_ON if any HW unit is in target mode */
#define CDD_I2C_TARGET_ACTIVE       (STD_OFF)

/** \brief Enable/Disable I2C dev detect error */
#define CDD_I2C_DEV_ERROR_DETECT        (STD_ON)

/** \brief Version info API macro */
#define CDD_I2C_VERSION_INFO_API        (STD_ON)

/** \brief Check to enable cancel API */
#define CDD_I2C_CANCEL_API              (STD_ON)

/** \brief Check to enable get driver status API */
#define CDD_I2C_GET_STATUS_API          (STD_ON)

/**
 *  \name I2C HW Unit ID
 *
 *  Specifies the HW identification (ID) for I2C
 *  @{
 */
/** \brief HW unit 0 */
#define CDD_I2C_HW_UNIT_I2CA            ((Cdd_I2c_HwUnitType)0U)
/** \brief HW unit 1 */
#define CDD_I2C_HW_UNIT_I2CB            ((Cdd_I2c_HwUnitType)1U)
/** @} */
/** \brief Maximum supported HW units for the SOC */
#define CDD_I2C_HW_UNIT_MAX             (2U)

/*
 * All below macros are used for static memory allocation and can be changed to
 * match the usecase requirements.
 */
/** \brief Maximum channels allowed per sequence */
#define CDD_I2C_MAX_CH_PER_SEQ          (2U)

/** \brief Maximum channels across all sequence/hwunit */
#define CDD_I2C_MAX_CH                  (12U)

/** \brief Maximum sequence across all hwunit */
#define CDD_I2C_MAX_SEQ                 (8U)

/** \brief Maximum HW unit */
#define CDD_I2C_MAX_HW_UNIT             (2U)

/*
 * All below macros are used for enabling a particular hardware.
 */
#define CDD_I2C_HW_UNIT_I2CA_ACTIVE
#define CDD_I2C_HW_UNIT_I2CB_ACTIVE


/** \brief Symbolic Name for I2c Sequence 0 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_0    (0U)
/** \brief Symbolic Name for I2c Sequence 1 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_1    (1U)
/** \brief Symbolic Name for I2c Sequence 2 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_2    (2U)
/** \brief Symbolic Name for I2c Sequence 3 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_3    (3U)
/** \brief Symbolic Name for I2c Sequence 4 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_4    (4U)
/** \brief Symbolic Name for I2c Sequence 5 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_5    (5U)
/** \brief Symbolic Name for I2c Sequence 6 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_6    (6U)
/** \brief Symbolic Name for I2c Sequence 7 */
#define CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_7    (7U)

/** \brief Symbolic Name for I2c Channel 0 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_0      (0U)
/** \brief Symbolic Name for I2c Channel 1 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_1      (1U)
/** \brief Symbolic Name for I2c Channel 2 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_2      (2U)
/** \brief Symbolic Name for I2c Channel 3 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_3      (3U)
/** \brief Symbolic Name for I2c Channel 4 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_4      (4U)
/** \brief Symbolic Name for I2c Channel 5 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_5      (5U)
/** \brief Symbolic Name for I2c Channel 6 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_6      (6U)
/** \brief Symbolic Name for I2c Channel 7 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_7      (7U)
/** \brief Symbolic Name for I2c Channel 8 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_8      (8U)
/** \brief Symbolic Name for I2c Channel 9 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_9      (9U)
/** \brief Symbolic Name for I2c Channel 10 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_10      (10U)
/** \brief Symbolic Name for I2c Channel 11 */
#define CddI2cConf_CddI2cChConfig_CddI2cChConfig_11      (11U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/**
 * \brief This is an enum containing the possible restart modes.
 * The default mode is CDD_I2C_RESTART_MODE_NOSTOP
 */
typedef enum
{
    /** \brief CDD_I2C restart mode with stop at end of each transaction/channel write/read */
    CDD_I2C_RESTART_MODE_STOP,
    /** \brief CDD_I2C restart mode with no stop at end of each transaction/channel write/read,
     * by default there is start at begining of each transaction */
    CDD_I2C_RESTART_MODE_NOSTOP
} Cdd_I2c_RestartModeType;

/*
 * Controller mode callbacks (used per Sequence in Cdd_I2c_SequenceConfigType)
 */
/**
 * \brief Callback routine provided by the user for each Sequence to notify the
 * caller that a Sequence has been finished.
 */
typedef void (*Cdd_I2c_SequenceEndNotification)(void);

/**
 * \brief Callback routine provided by the user for each Sequence to notify the
 * caller that a Sequence has been finished with an error.
 *
 * \param[out] errorCode Sequence error code
 */
typedef void (*Cdd_I2c_SequenceErrorNotification)(uint8 errorCode);

/*
 * Target mode callbacks (used per HW unit in Cdd_I2c_HwUnitConfigType)
 */
/**
 * \brief Target RX start notification callback - called on start condition
 *
 * \param[in] hwUnitId I2C instance
 */
typedef void (*Cdd_I2c_TargetRxStartNotificationType)(Cdd_I2c_HwUnitType hwUnitId);

/**
 * \brief Target TX start notification callback - called on start condition
 *
 * \param[in] hwUnitId I2C instance
 */
typedef void (*Cdd_I2c_TargetTxStartNotificationType)(Cdd_I2c_HwUnitType hwUnitId);
/**
 * \brief Target RX complete notification callback - called on stop condition or the buffer is fully filled.
 *
 * \param[in] hwUnitId I2C instance
 * \param[in] pRxBuffer Pointer to RX data buffer given at time of submit
 * \param[in] rxCount Number of bytes actually received
 * \param[in] event CDD_I2C_TARGET_EVENT_TRANSFER_COMPLETE or CDD_I2C_TARGET_EVENT_STOP
 */
typedef void (*Cdd_I2c_TargetRxCompleteNotificationType)(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataPtrType pRxBuffer,
                                                         Cdd_I2c_DataLengthType rxCount, uint8 event);

/**
 * \brief Target TX complete notification callback - called on stop condition or the buffer is fully transferred.
 *
 * \param[in] hwUnitId I2C instance
 * \param[in] pTxBuffer Pointer to TX data buffer
 * \param[in] txCount Number of bytes actually transmitted
 * \param[in] event CDD_I2C_TARGET_EVENT_TRANSFER_COMPLETE or CDD_I2C_TARGET_EVENT_STOP
 */
typedef void (*Cdd_I2c_TargetTxCompleteNotificationType)(Cdd_I2c_HwUnitType       hwUnitId,
                                                         Cdd_I2c_DataConstPtrType pTxBuffer,
                                                         Cdd_I2c_DataLengthType txCount, uint8 event);

/**
 * \brief Target error notification callback - called on bus error conditions
 *
 * \param[in] hwUnitId I2C instance
 * \param[in] errorEvent Error Events: CDD_I2C_TARGET_EVENT_NO_BUFFER, CDD_I2C_TARGET_EVENT_TX_UNDERFLOW,
 *                                CDD_I2C_TARGET_EVENT_RX_OVERFLOW, CDD_I2C_TARGET_EVENT_NACK
 *
 */
typedef void (*Cdd_I2c_TargetErrorNotificationType)(Cdd_I2c_HwUnitType hwUnitId, uint8 errorEvent);

/**
 * \brief CDD_I2C Hardware unit configuration structure
 */
typedef struct
{
    /** \brief CDD_I2C HW unit to use */
    Cdd_I2c_HwUnitType                       hwUnitId;
    /** \brief The baud rate of the bus in bit/s */
    uint32                                   baudRate;
    /** \brief This unit is used set the I2c HW module frequency */
    uint32                                   hwUnitFrequency;
    /** \brief This element contains the system clock frequency being used by the I2c instance */
    uint32                                   sysClk;
    /** \brief Own address. Used in both 7 and 10-bit address mode.
     *  Note that the user can program the I2C own address to any value as long as it
     *  does not conflict with other components in the system */
    Cdd_I2c_AddressType                      ownAddress;
    /** \brief 7-bit or 10-bit addressing (CDD_I2C_ADDRESS_7_BIT / CDD_I2C_ADDRESS_10_BIT).
     *         This is used at init time to program the default value. */
    uint8                                    addressScheme;
    /** \brief HW unit mode CDD_I2C_MODE_CONTROLLER or CDD_I2C_MODE_TARGET */
    uint8                                    mode;
    /** \brief TRUE if this HW unit uses interrupts, FALSE for polling */
    boolean                                  isIntrMode;
    /** \brief TX start notification callback for Target mode only [Will be assigned NULL in controller mode]*/
    Cdd_I2c_TargetTxStartNotificationType    targetTxStartNotification;
    /** \brief RX start notification callback for Target mode only [Will be assigned NULL in controller mode]*/
    Cdd_I2c_TargetRxStartNotificationType    targetRxStartNotification;
    /** \brief TX complete notification callback for Target mode only [Will be assigned NULL in controller mode]*/
    Cdd_I2c_TargetTxCompleteNotificationType targetTxCompleteNotification;
    /** \brief RX complete notification callback for Target mode only [Will be assigned NULL in controller mode]*/
    Cdd_I2c_TargetRxCompleteNotificationType targetRxCompleteNotification;
    /** \brief Error notification callback for Target mode only [Will be assigned NULL in controller mode]*/
    Cdd_I2c_TargetErrorNotificationType      targetErrorNotification;
} Cdd_I2c_HwUnitConfigType;

/**
 * \brief CDD_I2C Channel configuration structure
 */
typedef struct
{
    /** \brief CDD_I2C Direction - write or read */
    Cdd_I2c_DirectionType direction;
    /** \brief The address of a target device which is accessed by the Controller */
    Cdd_I2c_AddressType   deviceAddress;
    /** \brief 7-bit or 10-bit addressing */
    uint8                 addressScheme;
} Cdd_I2c_ChConfigType;

/**
 * \brief CDD_I2C Sequence configuration structure
 */
typedef struct
{
    /** \brief This element points to which CDD_I2C hardware instance to use */
    Cdd_I2c_HwUnitType                hwUnitId;
    /** \brief The transmission end notification to inform the user that a
     * transmission request has been serviced */
    Cdd_I2c_SequenceEndNotification   completeNotify;
    /** \brief The transmission end notification to inform the user that a
     * transmission request has been serviced but with error */
    Cdd_I2c_SequenceErrorNotification errorNotify;
    /** \brief This element indicates the restart mode */
    Cdd_I2c_RestartModeType           restartMode;
    /** \brief Number of chs for this sequence.
     *   Should not be more than CDD_I2C_MAX_CH_PER_SEQ */
    uint32                            chPerSeq;

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    /** \brief Channel index list */
    Cdd_I2c_ChannelType               chList[CDD_I2C_MAX_CH_PER_SEQ];
#endif
} Cdd_I2c_SequenceConfigType;

/**
 * \brief CDD_I2C config structure
 */
typedef struct Cdd_I2c_ConfigTag
{
    /** \brief HW Unit configurations */
    Cdd_I2c_HwUnitConfigType   hwUnitCfg[CDD_I2C_MAX_HW_UNIT];

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    /** \brief Sequence configurations */
    Cdd_I2c_SequenceConfigType seqCfg[CDD_I2C_MAX_SEQ];
    /** \brief Ch configurations */
    Cdd_I2c_ChConfigType       chCfg[CDD_I2C_MAX_CH];
#endif
} Cdd_I2c_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern CONST(struct Cdd_I2c_ConfigTag, CDD_I2C_CONFIG_DATA) Cdd_I2c_Config;
extern CONST(uint32, CDD_I2C_CONST) Cdd_I2c_HwUnitBaseAddr[CDD_I2C_HW_UNIT_MAX];

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
extern void I2c_appSeqComplete(void);
extern void I2c_appSeqFail(uint8 errorCode);


/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef I2C_CFG_H_ */

/** @} */
/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Cfg.h
 *********************************************************************************************************************/
