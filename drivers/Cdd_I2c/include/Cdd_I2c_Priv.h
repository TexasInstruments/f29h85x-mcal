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
 *  File:       Cdd_I2c_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains the common declarations and macros used across
 *                all the I2C MCAL driver files.
 *********************************************************************************************************************/

#ifndef CDD_I2C_PRIV_H_
#define CDD_I2C_PRIV_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_I2c.h"
#include "SchM_Cdd_I2c.h"
#include "Cdd_I2c_Utils.h"
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief Maximum possible 10 bit address */
#define CDD_I2C_ADDRESS_10_BIT_MAX (1023U)
/** \brief Maximum possible 7 bit address */
#define CDD_I2C_ADDRESS_7_BIT_MAX (127U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*
 * \brief I2C driver transfer stages - used in polling mode
 */
typedef enum
{
    CDD_I2C_STATE_INIT,
    CDD_I2C_STATE_WAIT_FOR_BUS_FREE,
    CDD_I2C_STATE_SETUP,
    CDD_I2C_STATE_WAIT_FOR_BUS_BUSY,
    CDD_I2C_STATE_DATA_TRANSFER,
    CDD_I2C_STATE_WAIT_FOR_ACCESS_READY,
    CDD_I2C_STATE_WAIT_FOR_STOP,
    CDD_I2C_STATE_COMPLETE
} Cdd_I2c_StateType;

/**
 * \brief Target mode state machine states
 */
typedef enum
{
    /** \brief Waiting for address match */
    CDD_I2C_TARGET_STATE_IDLE,
    /** \brief Receiving data (controller write) */
    CDD_I2C_TARGET_STATE_RX,
    /** \brief Transmitting data (controller read) */
    CDD_I2C_TARGET_STATE_TX
} Cdd_I2c_TargetStateType;

/** \brief Pre-declaration for HW unit object */
typedef struct Cdd_I2c_HwUnitObjType_t Cdd_I2c_HwUnitObjType;

/**
 *  \brief I2C Sequence object structure.
 */
typedef struct
{
    const Cdd_I2c_SequenceConfigType *seqCfg;
    /**< I2C sequence config passed during init */
    Cdd_I2c_SequenceType              sequenceId;
    /**< I2C sequence ID. This is used for easy de-referencing */
    Cdd_I2c_HwUnitObjType            *hwUnitObj;
    /**< I2C HW unit object as ID and array index may not be same.
     *   This is used for easy de-referencing */
    Cdd_I2c_SequenceResultType        seqResult;
    /**< I2C sequence result/status */
    uint8                             seqErrorCode;
    /**< I2C sequence error code */
    uint32                            numChsPending;
    /**< Number of chs still pending. Used for notifying sequence end */
    boolean                           isCancelInProgress;
    /**< Set to TRUE when user cancels a sequence */
} Cdd_I2c_SeqObjType;

/**
 *  \brief I2C Channel object structure.
 */
typedef struct
{
    const Cdd_I2c_ChConfigType *chCfg;
    /**< I2C ch config passed during init */
    Cdd_I2c_ChannelType         chId;
    /**< I2C channel ID. This is used for easy de-referencing */
    Cdd_I2c_SeqObjType         *seqObj;
    /**< I2C sequence object pointer to which the ch belongs.
     *   This is used for easy de-referencing */
    Cdd_I2c_HwUnitObjType      *hwUnitObj;
    /**< I2C HW unit object as ID and array index may not be same.
     *   This is used for easy de-referencing */
    Cdd_I2c_UtilsNode           nodeObj;
    /**< Node object used for node memory to be used in link list */
    Cdd_I2c_DataConstPtrType    txBufPtr;
    /**< TX buffer pointer given by user. This should be persistent */
    Cdd_I2c_DataPtrType         rxBufPtr;
    /**< RX buffer pointer given by user. This should be persistent */
    Cdd_I2c_DataLengthType      length;
    /** \brief The address of a target device which is accessed by the Controller */
    Cdd_I2c_AddressType         deviceAddress;
    /** \brief 7-bit or 10-bit addressing */
    uint8                       addressScheme;
    /**< Number of words to transfer given by user */
    Cdd_I2c_ChannelResultType   chResult;
    /**< I2C channel result/status */
    Cdd_I2c_ChannelResultType   chErrorCode;
    /**< I2C channel error - temp variable to store intermediate errors and
     *   passed to channel result at channel completion */
    Cdd_I2c_DataConstPtrType    curTxBufPtr;
    /**< Current TX buffer pointer */
    Cdd_I2c_DataPtrType         curRxBufPtr;
    /**< Current RX buffer pointer */
    Cdd_I2c_DataLengthType      curLength;
    /**< Number of words transferred */
    boolean                     isStopRequired;
    /**< Flag to indicate whether to perform stop at end of channel transfer */
    boolean                     doBusyCheck;
    /**< Flag to indicate whether to perform bus busy check at start of channel transfer */
    Cdd_I2c_StateType           state;
    /**< Flag to indicate the current stage of data transfer */
    boolean                     isCancelInProgress;
    /**< Set to TRUE when user cancels a sequence - this is set for all channels in a sequence */
} Cdd_I2c_ChObjType;

/**
 *  \brief I2C Hardware unit object structure.
 */
struct Cdd_I2c_HwUnitObjType_t
{
    const Cdd_I2c_HwUnitConfigType *hwUnitCfg;
    /**< I2C HW unit config passed during init */
    uint32                          baseAddr;
    /**< Base address of the hardware */
    Cdd_I2c_UtilsLinkListObj        llobj;
    /**< Ch link list per hardware */
    Cdd_I2c_ChObjType              *curChObj;
    /**< When hardware is busy, this points to the current ch that
     *   is in progress. When hardware is idle, this will be NULL */
    Cdd_I2c_HwUnitStatusType        hwUnitStatus;
    /**< SPI HW unit result/status */

    /*
     * All below variables are used only in target mode
     */
    /** \brief Current state */
    Cdd_I2c_TargetStateType targetState;

    /** \brief Pointer to RX data buffer */
    Cdd_I2c_DataPtrType    pRxBuffer;
    /** \brief RX buffer size in bytes */
    Cdd_I2c_DataLengthType rxBufferSize;
    /** \brief RX byte count (bytes received so far) */
    Cdd_I2c_DataLengthType rxCount;
    /** \brief RX overflow status */
    boolean                rxOverflow;

    /** \brief Pointer to TX data buffer */
    Cdd_I2c_DataConstPtrType pTxBuffer;
    /** \brief TX buffer size in bytes */
    Cdd_I2c_DataLengthType   txBufferSize;
    /** \brief TX byte count (bytes sent so far) */
    Cdd_I2c_DataLengthType   txCount;
    /** \brief TX underflow status */
    boolean                  txUnderflow;
};

/**
 *  \brief I2C driver object structure.
 */
typedef struct
{
    uint8                 maxCh;
    /**< Maximum number of channels */
    uint8                 maxSeq;
    /**< Maximum number of sequences */
    uint8                 maxHwUnit;
    /**< Maximum number of HW unit */
    Cdd_I2c_ChObjType     chObj[CDD_I2C_MAX_CH];
    /**< I2C ch objects */
    Cdd_I2c_SeqObjType    seqObj[CDD_I2C_MAX_SEQ];
    /**< I2C sequence objects */
    Cdd_I2c_HwUnitObjType hwUnitObj[CDD_I2C_MAX_HW_UNIT];
    /**< I2C hw unit objects */
} Cdd_I2c_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern Cdd_I2c_ComponentStatusType Cdd_I2c_DrvState;
extern Cdd_I2c_DriverObjType       Cdd_I2c_DrvObj;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

Std_ReturnType Cdd_I2c_StartSeqAsync(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj);
Std_ReturnType Cdd_I2c_CancelSeq(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj);

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
Std_ReturnType Cdd_I2c_CheckConfig(const Cdd_I2c_ConfigType *configPtr);
#endif
void Cdd_I2c_InitDrvObj(Cdd_I2c_DriverObjType *drvObj);
void Cdd_I2c_DeInitDrvObj(Cdd_I2c_DriverObjType *drvObj);
void Cdd_I2c_CopyConfig(Cdd_I2c_DriverObjType *drvObj, const Cdd_I2c_ConfigType *configPtr);

void Cdd_I2c_ProcessIsr(Cdd_I2c_HwUnitType hwUnitId);
void Cdd_I2c_ProcessEvents(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitObjType *hwUnitObj);
void Cdd_I2c_TargetIsr(Cdd_I2c_HwUnitType hwUnitId);

uint32                 Cdd_I2c_GetHwUnitBaseAddr(Cdd_I2c_HwUnitType hwUnitId);
Cdd_I2c_HwUnitObjType *Cdd_I2c_GetHwUnitObj(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitType hwUnitId);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CDD_I2C_PRIV_H_ */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Priv.h
 *********************************************************************************************************************/
