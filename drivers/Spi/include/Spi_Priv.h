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
 *  File:       Spi_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to Spi
 *
 *********************************************************************************************************************/
#ifndef SPI_PRIV_H
#define SPI_PRIV_H
/*********************************************************************************************************************
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi.h"
#include "SchM_Spi.h"
#include "Spi_Utils.h"
#include "hw_spi.h"
#include "hw_pipe.h"
#include "hw_ints.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Pre-declaration for HW unit object */
typedef struct Spi_HwUnitObjType_t Spi_HwUnitObjType;

/** \brief These are the possible levels a chip select */
typedef uint8 Spi_CsLevelType;
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/**
 *  \brief SPI Buffer pointer type.
 */

typedef enum
{
    /** \brief SPI 8 bit buffer */
    SPI_8BIT_BUFFER,
    /** \brief SPI 16 bit buffer */
    SPI_16BIT_BUFFER

} Spi_BufferWidthType;
/*
 * Design : MCAL-24874, MCAL-24877, MCAL-24881, MCAL-25177
 */

/**
 *  \brief SPI Channel object structure.
 */

typedef struct
{
    /** \brief SPI channel config passed during init */
    const Spi_ChannelConfigType *chCfg;
    /** \brief TX buffer pointer given by user. This should be persistent */
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) txBufPtr;
    /** \brief RX buffer pointer given by user. This should be persistent */
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) rxBufPtr;

#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
    /** \brief Internal TX buffer */
    volatile Spi_DataBufferType txIb[SPI_IB_MAX_LENGTH];
    /** \brief Internal RX buffer */
    volatile Spi_DataBufferType rxIb[SPI_IB_MAX_LENGTH];
#endif
    /** \brief Current TX buffer pointer */
    volatile const uint8 *curTxBufPtr;
    /** \brief Current RX buffer pointer */
    volatile uint8       *curRxBufPtr;
    /** \brief Number of words to transfer */
    Spi_NumberOfDataType  numWordsTxRx;
    /** \brief   Number of words transmitted. We need separate counters for
     *   TX/RX because when FIFO in enabled, TX writes happen in
     *   advance where as RX will happen on actual received data. */
    Spi_NumberOfDataType  curTxWords;
    /** \brief Number of words received */
    Spi_NumberOfDataType  curRxWords;
    /** \brief   Width of buffer in bytes-used for accessing the TX/RX buffer.
     *   When dataWidth < 9,           bufWidth = uint8 (1 bytes)
     *   When dataWidth >= 9  && < 17, bufWidth = uint16 (2 bytes)
     */
    Spi_BufferWidthType   bufWidth;
    /** \brief Effective TX FIFO depth in words - depends on dataWidth */
    uint16                effTxFifoDepth;
    /** \brief Data width mask depending on SPI word size */
    uint16                dataWidthBitMask;

} Spi_ChannelObjType;

/*
 * Design : MCAL-25178
 */

/**
 *  \brief SPI Sequence object structure.
 */
typedef struct
{
    /** \brief SPI sequence config passed during init */
    const Spi_SeqConfigType *seqCfg;
    /** \brief SPI sequence result/status */
    Spi_SeqResultType        seqResult;
    /** \brief Number of jobs still pending.Used for notifying sequence end */
    uint32                   numJobsPending;

} Spi_SeqObjType;

/*
 * Design : MCAL-25179
 */

/**
 *  \brief SPI Job object structure.
 */
typedef struct
{
    /** \brief SPI job config passed during init */
    const Spi_JobConfigType      *jobCfg;
    /** \brief SPI job config passed during init */
    Spi_ExternalDeviceConfigType *extDevCfg;
    /** \brief SPI job result/status */
    Spi_JobResultType             jobResult;
    /** \brief SPI HW unit object as ID and array index may not be same.
     * This is used for easy de-referencing */
    Spi_HwUnitObjType            *hwUnitObj;
    /** \brief SPI sequence object pointer to which the job belongs.
     * This is used for easy de-referencing */
    Spi_SeqObjType               *seqObj;
    /** \brief Node object used for node memory to be used in link list */
    Spi_UtilsNode                 nodeObj;
    /** \brief Current channel index. Used for notifying job end */
    uint32                        curChIdx;
    /** \brief TX FIFO trigger level in bytes */
    uint32                        txFifoTrigLvl;
    /** \brief RX FIFO trigger level in bytes */
    uint32                        rxFifoTrigLvl;
} Spi_JobObjType;

/*
 * Design : MCAL-25180
 */

/**
 *  \brief SPI Hardware unit object structure.
 */
struct Spi_HwUnitObjType_t
{
    /** \brief SPI HW unit config passed during init */
    const Spi_HwUnitConfigType *hwUnitCfg;
    /** \brief SPI HW unit result/status */
    Spi_HwUnitResultType        hwUnitResult;
    /** \brief Base address of the hardware */
    uint32                      baseAddr;
    /** \brief Job link list per hardware */
    Spi_UtilsLinkListObj        jobList;
    /** \brief When hardware is busy, this points to the current job that
     * is in progress. When hardware is idle, this will be NULL */
    Spi_JobObjType             *curJobObj;
    /** \brief Currently configured job ID. Used to avoid re-configuring the
     * hardware again when the same job ID is used back to back */
    Spi_JobType                 curConfiguredJobId;
    /* current DEM status for this HW unit */
    Std_ReturnType              hwUnitDemState;
};

/*
 * Design : MCAL-25181
 */

/**
 *  \brief SPI driver object structure.
 */
typedef struct
{
    /** \brief Flag to indicate any async transfer is in progress */
    uint32                       isAsyncInProgress;
    /** \brief Async mode set by user */
    Spi_AsyncModeType            asyncMode;
    /** \brief Maximum number of channels.
     * Should not be more than SPI_MAX_CHANNELS */
    uint8                        maxChannels;
    /** \brief Maximum number of jobs
     * Should not be more than SPI_MAX_JOBS */
    uint8                        maxJobs;
    /** \brief Maximum number of sequences
     * Should not be more than SPI_MAX_SEQ */
    uint8                        maxSeq;
    /** \brief Maximum number of HW unit
     * Should not be more than SPI_MAX_HW_UNIT */
    uint8                        maxHwUnit;
    /** \brief Maximum number of external device configurations
     * Should not be more than SPI_MAX_EXT_DEV */
    uint8                        maxExtDevCfg;
    /** \brief SPI channel objects */
    Spi_ChannelObjType           channelObj[SPI_MAX_CHANNELS];
    /** \brief SPI job objects */
    Spi_JobObjType               jobObj[SPI_MAX_JOBS];
    /** \brief SPI sequence objects */
    Spi_SeqObjType               seqObj[SPI_MAX_SEQ];
    /** \brief SPI hw unit objects */
    Spi_HwUnitObjType            hwUnitObj[SPI_MAX_HW_UNIT];
    /** \brief External HW device config */
    Spi_ExternalDeviceConfigType extDevCfg[SPI_MAX_EXT_DEV];

} Spi_DriverObjType;

/*
 * Design : MCAL-25182
 */
/** \brief SPI driver status */
extern volatile Spi_StatusType Spi_DrvStatus;
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief function to reset driver object
 *
 *  function to reset driver object
 *
 * \param[in] drvObj: pointer to driver object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ResetDrvObj(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj);

/** \brief function to copy configuration into driver obj
 *
 *  function to copy driver object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_CopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
               P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/** \brief function to initialize SPI hardware unit
 *
 *  function to initialize SPI hardware unit
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] hwUnitObj: pointer to hardware unit object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_HwUnitInit(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
               P2VAR(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj);

/** \brief function to de-initialize SPI hardware unit
 *
 *  function to de-initialize SPI hardware unit
 *
 * \param[in] hwUnitObj: pointer to hardware unit object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_HwUnitDeInit(P2VAR(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj);

/** \brief function to get hardware unit object based on HW unit ID
 *
 *  function to get hardware unit object based on HW unit ID
 *
 * \param[in] HWUnit: Hw unit ID
 * \param[in] drvObj: pointer to driver object
 * \pre None
 * \post None
 * \return return found hardware unit object based on HW unit ID
 * \retval Spi_HwUnitObjType: pointer to HW unit object
 *
 ********************************************************************************************************************/
Spi_HwUnitObjType *Spi_GetHwUnitObj(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
                                    P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj);

/** \brief function to disable all the interrupts
 *
 *  function to disable all the interrupts
 *
 * \param[in] baseAddr: HW unit base address
 * \param[in] isFifoEnabled: FIFO enhancement mode enabled or disabled
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_DisableInterrupt(VAR(uint32, AUTOMATIC) baseAddr, VAR(boolean, AUTOMATIC) isFifoEnabled);

/** \brief function to enable interrupts
 *
 *  function to enable interrupts
 *
 * \param[in] baseAddr: HW unit base address
 * \param[in] isFifoEnabled: FIFO enhancement mode enabled or disabled
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_EnableInterrupt(VAR(uint32, AUTOMATIC) baseAddr, VAR(boolean, AUTOMATIC) isFifoEnabled);

/** \brief private function to start Asynchronous transmission
 *
 *  private function to start Asynchronous transmission
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] seqObj: pointer to sequence object
 * \pre None
 * \post None
 * \return returns the status of the async transfer start
 * \retval E_OK: sequence transfer start in async mode is success
 * \retval E_NOT_OK: sequence transfer start in async mode failed
 *
 ********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE)
Spi_StartSeqAsync(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                  P2VAR(Spi_SeqObjType, AUTOMATIC, SPI_CODE) seqObj);

/** \brief private function to start synchronous transmission
 *
 *  private function to start synchronous transmission
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] seqObj: pointer to sequence object
 * \pre None
 * \post None
 * \return returns the status of the async transfer start
 * \retval E_OK: sequence transfer start in sync mode is success
 * \retval E_NOT_OK: sequence transfer start in sync mode failed
 *
 ********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE)
Spi_StartSeqSync(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                 P2VAR(Spi_SeqObjType, AUTOMATIC, SPI_CODE) seqObj);

/** \brief process receive interrupt(RXINT/INT)
 *
 *  function to process receive interrupt
 *
 * \param[in] hwUnitId: Id of Hardware Unit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ProcessRxEvent(VAR(Spi_HWUnitType, AUTOMATIC) hwUnitId);

/** \brief process channel completion
 *
 *  function to process operations after channel transfer is done
 *
 * \param[in] hwUnitObj: pointer to HW unit object
 * \param[in] jobResult: result of channel completion
 * \param[in] drvObj: pointer to driver object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_ProcessChCompletion(P2VAR(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj,
                        VAR(Spi_JobResultType, AUTOMATIC) jobResult,
                        P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj);
#if (STD_ON == SPI_CS_VIA_GPIO)
/** \brief function to Enable or Disable chip-select when it is a GPIO
 *
 *  function to Enable or disable chip-select what it is a GPIO
 *
 * \param[in] jobObj: pointer to Job object
 * \param[in] enable: enable or disable flag
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_ConfigGpioChipSelect(P2CONST(Spi_JobObjType, AUTOMATIC, SPI_CODE) jobObj, VAR(boolean, AUTOMATIC) enable);
#endif

/** \brief function to cancel ongoing sequence
 *
 *  function to cancel ongoing sequence
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] seqObj: pointer to Sequence object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_CancelSequence(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                   P2VAR(Spi_SeqObjType, AUTOMATIC, SPI_CODE) seqObj);
#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
/** \brief function to write into internal buffer in 8 bits
 *
 *  function to write  into internal buffer
 *
 * \param[in] DataBufferPtr: pointer to Data Buffer
 * \param[out] ChObj: pointer to Channel object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivIntlBufWrite8(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) ChObj,
                      P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_CODE) DataBufferPtr);

/** \brief function to write  into internal buffer in 16 bits
 *
 *  function to write  into internal buffer
 *
 * \param[in] DataBufferPtr: pointer to Data Buffer
 * \param[out] ChObj: pointer to Channel object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivIntlBufWrite16(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) ChObj,
                       P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_CODE) DataBufferPtr);

/** \brief function to read  from internal buffer
 *
 *  function to read  from internal buffer
 *
 * \param[in] chObj: pointer to Channel object
 * \param[out] DataBufferPointer: pointer to Data Buffer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivReadIB(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj,
               P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_CODE) DataBufferPointer);
#endif
/** \brief function to get HW Status
 *
 *  function to get HW unit Status
 *
 * \param[in] hwUnitObj: pointer to HWUnit object
 * \pre None
 * \post None
 * \return Status of HWUnit
 * \retval  SPI_UNINIT : The SPI Handler/Driver is not initialized or not usable
 * \retval  SPI_IDLE : The SPI Handler/Driver is not currently transmitting any Job
 * \retval  SPI_BUSY : The SPI Handler/Driver is performing a SPI Job (transmit)
 *
 ********************************************************************************************************************/
FUNC(Spi_StatusType, SPI_CODE)
Spi_PrivGetHWStatus(P2CONST(Spi_HwUnitObjType, AUTOMATIC, SPI_CODE) hwUnitObj);

/** \brief This function process transfer interrupt(TXINT)
 *
 *  function to process transfer interrupt(TXINT)
 *
 * \param[in] baseAddr: Base Address of HWUnit
 * \param[in] chObj: pointer to Channel object
 * \param[in] txIntrStatus: transfer interrupt status
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivProcessTxEvent(VAR(uint32, AUTOMATIC) baseAddr, P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj,
                       VAR(uint16, AUTOMATIC) txIntrStatus);

/** \brief function to copy configuration into Job obj
 *
 *  function to reset Job object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivJobCopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                      P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/** \brief function to copy configuration into Sequence obj
 *
 *  function to reset Sequence object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivSeqCopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                      P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/** \brief function to copy configuration into Channel obj
 *
 *  function to reset Channel object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivChannelCopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                          P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/** \brief function to copy configuration into HWUnit obj
 *
 *  function to reset HWUnit object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivHWUnitCopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                         P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/** \brief function to copy configuration into External Device obj
 *
 *  function to reset External Device object
 *
 * \param[in] drvObj: pointer to driver object
 * \param[in] cfgPtr: pointer to configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivExtDevCopyConfig(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
                         P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CODE) cfgPtr);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/** \brief function to write  into Register in 8 bits
 *
 *  function to write  into  Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] chObj : pointer to Channel object
 * \param[in] transferLength : no.of bytes to transfer
 * \param[in] curTxWords : index of transmitted words in bufPtr
 * \pre None
 * \post None
 * \return pointer to bufPtr
 * \retval pointer to bufPtr
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_FifoWrite8(VAR(uint32, AUTOMATIC) baseAddr, P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj,
                   VAR(uint32, AUTOMATIC) transferLength, VAR(uint16, AUTOMATIC) curTxWords);

/** \brief function to write  into Register in 16 bits
 *
 *  function to write  into  Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] chObj : pointer to Channel object
 * \param[in] transferLength : no.of bytes to transfer
 * \param[in] curTxWords : index of transmitted words in bufPtr
 * \post None
 * \return pointer to bufPtr
 * \retval pointer to bufPtr
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_FifoWrite16(VAR(uint32, AUTOMATIC) baseAddr, P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj,
                    VAR(uint32, AUTOMATIC) transferLength, VAR(uint16, AUTOMATIC) curTxWords);

/** \brief function to read from Register to bufPtr in 8 bits
 *
 *  function to  read from Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] numWordsToRead : no.of bytes to transfer
 * \param[in]  dataWidthBitMask : Clear unused bits
 * \param[in] curRxWords : index of received words in bufPtr
 * \param[out] bufPtr: pointer to Data Buffer
 * \pre None
 * \post None
 * \return pointer to bufPtr
 * \retval pointer to bufPtr
 *
 ********************************************************************************************************************/
LOCAL_INLINE volatile uint8 *Spi_FifoRead8(VAR(uint32, AUTOMATIC) baseAddr,
                                           volatile P2VAR(uint8, AUTOMATIC, SPI_CODE) bufPtr,
                                           VAR(uint32, AUTOMATIC) numWordsToRead,
                                           VAR(uint16, AUTOMATIC) dataWidthBitMask, VAR(uint16, AUTOMATIC) curRxWords);

/** \brief function to read from Register to bufPtr in 16 bits
 *
 *  function to  read from Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] numWordsToRead : no.of bytes to transfer
 * \param[in] dataWidthBitMask : Clear unused bits
 * \param[in] curRxWords : index of received words in bufPtr
 * \param[out] bufPtr: pointer to Data Buffer
 * \pre None
 * \post None
 * \return pointer to bufPtr
 * \retval pointer to bufPtr
 *
 ********************************************************************************************************************/
LOCAL_INLINE volatile uint16 *Spi_FifoRead16(VAR(uint32, AUTOMATIC) baseAddr,
                                             volatile P2VAR(uint16, AUTOMATIC, SPI_CODE) bufPtr,
                                             VAR(uint32, AUTOMATIC) numWordsToRead,
                                             VAR(uint16, AUTOMATIC) dataWidthBitMask,
                                             VAR(uint16, AUTOMATIC) curRxWords);

/** \brief function to write Default data into Register
 *
 *  function to write default data into  Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] chObj : pointer to Channel object
 * \param[in] transferLength : no.of bytes to transfer
 * \pre None
 * \post None
 * \return pointer to bufPtr
 * \retval pointer to bufPtr
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_FifoWriteDefault(VAR(uint32, AUTOMATIC) baseAddr, VAR(uint32, AUTOMATIC) transferLength,
                         P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj);

/** \brief function to read from Register and discard
 *
 *  function to  read from Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[in] transferLength : no.of bytes to read
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_FifoReadDiscard(VAR(uint32, AUTOMATIC) baseAddr, VAR(uint32, AUTOMATIC) transferLength);

/** \brief function to read from Register to Channel Object
 *
 *  function to  read from Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[out] chObj: pointer to Channel Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_ReadRxBufferNonFifo(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj, VAR(uint32, AUTOMATIC) baseAddr);

/** \brief function to write into Register from Channel Object
 *
 *  function to  write into Register
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \param[out] chObj: pointer to Channel Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE)
    Spi_WriteTxBufferNonFifo(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE) chObj, VAR(uint32, AUTOMATIC) baseAddr);
/** \brief function to clear PIPE interrupt
 *
 *  function to  write into Register
 *
 * \param[in] intNum : Interrupt vector number
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_ClearPIPEINTFlag(VAR(uint32, AUTOMATIC) intNum);

/** \brief  Service for SPI initialization.
 *
 * This service initializes all the configured Spi channels, jobs, sequences and SPI instances This
 *will set the state of SPI driver to Initialized.
 *
 * \param[in] CfgPtr - Pointer to configuration set
 * \param[in] drvObj - Pointer to Driver Object
 * \pre CfgPtr shall be null in Pre-Compile variant, Link-Time variant and shall not be NULL in
 *Post-Build variant
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_PrivInit(P2VAR(Spi_DriverObjType, AUTOMATIC, SPI_CODE) drvObj,
             P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) CfgPtr);
/*********************************************************************************************************************
 *  Mark the end of the C bindings section for C++ compilers.
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
#endif /* SPI_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Spi_Priv.h
 *********************************************************************************************************************/
