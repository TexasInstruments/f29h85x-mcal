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
 *  File:       Spi_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains private function definitions for Spi
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi_Priv.h"
#include "Spi_Reg_Access.h"
#include "Mcal_Lib.h"
#if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
#include "Dem.h"
#endif
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief SPI Limit to consider 8bit or 16bit buffer length */
#define SPI_8BIT_BUFFER_LIMIT ((uint8) 9U)
/** \brief SPI Maximum word length supports */
#define SPI_MAX_WORD_LENGTH   (16U)
/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
typedef uint8 Spi_Cs_Dio_LevelType;
 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
typedef Spi_ChannelObjType * Spi_ChannelObjPtrType;
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief function to Check And Set Driver State
 *
 *  function to Check And Set Driver State
 *
 * \param[in] None     
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_CheckAndSetDrvState(void);

/** \brief function to Clear All Interrupt Flags
 *
 *  function to Clear All Interrupt Flags
 *
 * \param[in] baseAddr : BaseAddress of HWUnit     
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ClearAllInterruptFlags(VAR(uint32,AUTOMATIC) baseAddr);

/** \brief function to Get Current Channel Object
 *
 *  function to Get Current Channel Object
 *
 * \param[in] chId : Channel Id   
 * \pre None
 * \post None
 * \return pointer to channel object
 * \retval Spi_ChannelObjPtrType : pointer to channel object
 *
 ********************************************************************************************************************/
FUNC(Spi_ChannelObjPtrType, SPI_CODE) Spi_GetCurrChannelObj(VAR(Spi_ChannelType,AUTOMATIC) chId);


/** \brief function to Get Queue Jobs
 *
 *  function to add jobs in linked list
 *
 * \param[in] seqObj : pointer to Sequence object  
 * \pre None
 * \post None
 * \return  returns whether command has been accepted or rejected 
 * \retval E_OK : JobObj is added to linked list
 * \retval E_NOT_OK : JobObj is not added to linked list
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE) Spi_QueueJobs(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj);

/** \brief function to Start Sequence
 *
 *  function to check whther sequence is in pending status
 *
 * \param[in] seqObj : pointer to Sequence object  
 * \pre None
 * \post None
 * \return  returns whether command has been accepted or rejected 
 * \retval E_OK : when all jobs in seqObj are not in pending
 * \retval E_NOT_OK : when any job in seqObj is in pending
 *
 ********************************************************************************************************************/
static FUNC(Std_ReturnType, SPI_CODE) Spi_StartSeqCheck(P2CONST(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj);

/** \brief function to Schedule Job
 *
 *  function to Schedule Job
 *
 * \param[in] jobObj : pointer to Job object  
 * \pre None
 * \post None
 * \return  None 
 * \retval None
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_ScheduleJob(P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj);

/** \brief function to Configure Job
 *
 *  function to Configure Job
 *
 * \param[in] jobObj : pointer to Job object
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \pre None
 * \post None
 * \return  None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ConfigJob(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                   P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj);

/** \brief function to Configure Channel
 *
 *  function to Configure Channel
 *
 * \param[in] chObj : pointer to Channel object
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \pre None
 * \post None
 * \return  None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ConfigChannel(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                       P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj);

/** \brief function to Start transmission
 *
 *  function to Start transmission
 *
 * \param[in] chObj : pointer to Channel object
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \param[in] jobObj  : pointer to Job object
 * \param[in] isIntrMode : True or False
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_Start(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj, \
               P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj, \
               P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)ChObj, \
               VAR(uint32,AUTOMATIC)isIntrMode);

/** \brief function to Start transmission of next channel
 *
 *  function to Start transmission of next channel
 *
 * \param[in] chObj : pointer to Channel object
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \param[in] jobObj  : pointer to Job object
 * \pre None
 * \post None
 * \return  None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_StartNextChannel(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
               P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj);

/** \brief function to reset HWUnit
 *
 *  function to reset HWUnit
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_HwReset(VAR(uint32,AUTOMATIC) baseAddr);

/** \brief function to Clear All Irq Status
 *
 *  function to Clear All Irq Status
 *
 * \param[in] baseAddr : BaseAddress of HWUnit
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_ClearAllIrqStatus( VAR(uint32,AUTOMATIC) baseAddr);

/** \brief function to Get DataWidth Bit Mask
 *
 *  function to Get DataWidth Bit Mask
 *
 * \param[in] dataWidth : dataWidth
 * \pre None
 * \post None
 * \return  returns datawidth bit mask value
 * \retval unsigned integer of 16 bits
 *
 ********************************************************************************************************************/
FUNC(uint16, SPI_CODE) Spi_GetDataWidthBitMask( VAR(uint8,AUTOMATIC) dataWidth);

/** \brief function to Schedule All Jobs Synchronous Transmission
 *
 *  function to Schedule All Jobs Synchronous Transmission
 *
 * \param[in] seqObj : pointer to sequence object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_ScheduleAllJobsSyncTransmit(
                                       P2VAR( Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj);

/** \brief function to Transfer Job
 *
 *  function to Transfer Job
 *
 * \param[in] seqObj : pointer to sequence object
 * \pre None
 * \post None
 * \return return Job status
 * \retval SPI_JOB_OK : The last transmission of the Job has been finished successfully 
*  \retval SPI_JOB_PENDING : The SPI Handler/Driver is performing a SPI Job.
 * \retval SPI_JOB_FAILED : The last transmission of the Job has failed 
 * \retval SPI_JOB_QUEUED : An asynchronous transmit Job has been accepted, while
 *                          actual transmission for this Job has not started yet 
 *   
 *
 ********************************************************************************************************************/
FUNC(Spi_JobResultType, SPI_CODE) Spi_TransferJob(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj, \
                                          P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj);

/** \brief function to Read from fifo
 *
 *  function to Read from fifo
 *
 * \param[in] baseAddr : Base Address of HWUnit
 * \param[in] numWordsToRead : number of words to read
 * \param[out] chObj : pointer to channel object 
 * \param[out] curRxWords : total number of words read
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *   
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_ReadFifo(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)ChObj,
                         VAR(uint32,AUTOMATIC) baseAddr,
                         VAR(uint32,AUTOMATIC)      numWordsToRead,
                         VAR(uint16,AUTOMATIC) curRxWords);

/** \brief function to Write into fifo
 *
 *  function to Write into fifo
 *
 * \param[in] baseAddr : Base Address of HWUnit
 * \param[in] numWordsToWrite : number of words to write
 * \param[in] chObj : pointer to channel object
 * \param[out] curTxWords : total number of words written
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *   
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_WriteFifo(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)ChObj,
                         VAR(uint32,AUTOMATIC)    baseAddr,
                         VAR(uint32,AUTOMATIC)    numWordsToWrite,
                         VAR(uint16,AUTOMATIC)    curTxWords);

/** \brief function to continue transmission and reception
 *
 *  function to continue transmission and reception
 *
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \param[in] chObj : pointer to Channel object
 * \param[out] jobObj : pointer to job object
 * \pre None
 * \post None
 * \return return Job status
 * \retval SPI_JOB_OK : The last transmission of the Job has been finished successfully 
 * \retval SPI_JOB_PENDING : The SPI Handler/Driver is performing a SPI Job.
 * \retval SPI_JOB_FAILED :The last transmission of the Job has failed 
 * \retval SPI_JOB_QUEUED : An asynchronous transmit Job has been accepted, while
 *                          actual transmission for this Job has not started yet 
 *   
 *
 ********************************************************************************************************************/
FUNC(Spi_JobResultType, SPI_CODE) Spi_ContinueTxRx(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,\
                            P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE) chObj);

/** \brief function to complete job
 *
 *  function to complete job
 *
 * \param[in] hwUnitObj : pointer to HWUnit object
 * \param[in] jobObj : pointer to job object
 * \param[out]  seqObj : pointer to Sequence object
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *   
 *
 ********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_ProcessJobCompletion(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)HwUnitObj,
                                     P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)JobObj);


/** \brief function to stop job
 *
 *  function to stop job
 *
 * \param[in] hwUnitObj : pointer to HWUnit object   
 * \param[out]  jobObj : pointer to job object
 * \pre None
 * \post None
 * \return None
 * \retval None 
 *   
 *
 ********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_StopJob(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                 P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
LOCAL_INLINE const uint8 *Spi_FifoWrite8(VAR(uint32,AUTOMATIC) baseAddr,\
                                      VAR(uint32,AUTOMATIC) wordSize,\
                                      P2CONST(uint8,AUTOMATIC,SPI_CODE)bufPtr,\
                                       VAR(uint32,AUTOMATIC) transferLength,\
                                       VAR(uint16,AUTOMATIC) curTxWords)
{
    uint16        txData;
    uint32        i;

        /* Write the data in TX FIFO for 8-bit transfer */
    for(i = curTxWords ; i < (curTxWords + transferLength); i++)
    {
        txData = bufPtr[i];
        Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, (txData << (SPI_MAX_WORD_LENGTH - wordSize)));
    }

    return (bufPtr);
}

LOCAL_INLINE const uint16 *Spi_FifoWrite16(VAR(uint32,AUTOMATIC) baseAddr,\
                                      VAR(uint32,AUTOMATIC) wordSize,\
                                      P2CONST(uint16,AUTOMATIC,SPI_CODE)bufPtr,\
                                       VAR(uint32,AUTOMATIC) transferLength,\
                                       VAR(uint16,AUTOMATIC) curTxWords)
{
    uint16        txData;
    uint32        i;

    /* Write the data in TX FIFO for 16-bit transfer */
    for(i = curTxWords ; i < (curTxWords + transferLength); i++)
    {
        txData = bufPtr[i];
        Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, txData << (SPI_MAX_WORD_LENGTH - wordSize));
    }

    return (bufPtr);
}


LOCAL_INLINE uint8 *Spi_FifoRead8(VAR(uint32,AUTOMATIC)baseAddr,\
                                P2VAR(uint8,AUTOMATIC,SPI_CODE)bufPtr,\
                                VAR(uint32,AUTOMATIC)numWordsToRead,\
                                VAR(uint16,AUTOMATIC)dataWidthBitMask,\
                                VAR(uint16,AUTOMATIC)curRxWords)
{
    uint16        rxData;
    uint32        i;

    
    /* Read the data from RX FIFO for 8-bit transfer */
    for(i = curRxWords; i < (curRxWords + numWordsToRead); i++)
    {
        rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
        rxData &= dataWidthBitMask;         /* Clear unused bits */
        bufPtr[i] = (uint8) rxData;
        
    }

    return (bufPtr);
}

LOCAL_INLINE uint16 *Spi_FifoRead16(VAR(uint32,AUTOMATIC)baseAddr,\
                                P2VAR(uint16,AUTOMATIC,SPI_CODE)bufPtr,\
                                VAR(uint32,AUTOMATIC)numWordsToRead,\
                                VAR(uint16,AUTOMATIC)dataWidthBitMask,\
                                VAR(uint16,AUTOMATIC)curRxWords)
{
    uint16       rxData;
    uint32       i;

    /* Read the data from RX FIFO for 16-bit transfer */
    for(i = curRxWords; i < (curRxWords + numWordsToRead); i++)
    {
        rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
        rxData &= dataWidthBitMask;         /* Clear unused bits */
        bufPtr[i] = (uint16) rxData;
    }

    return (bufPtr);
}

LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FifoWriteDefault(VAR(uint32,AUTOMATIC)baseAddr,\
                                        VAR(uint32,AUTOMATIC)wordSize,\
                                        VAR(uint16,AUTOMATIC)defaultTxData,\
                                        VAR(uint32,AUTOMATIC)transferLength)
{
    uint32        i;

    /* Write default data to TX FIFO */
    for(i = ((uint32) 0U); i < transferLength; i++)
    {
        Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, defaultTxData << (SPI_MAX_WORD_LENGTH - wordSize));
    }

    return;
}

LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FifoReadDiscard(VAR(uint32,AUTOMATIC)baseAddr,\
                                  VAR(uint32,AUTOMATIC)transferLength)
{
    uint32            i;
    volatile uint16   rxData;

    /* Read the data from RX FIFO and discard it */
    for(i = ((uint32) 0U); i < transferLength; i++)
    {
        rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
        (void) rxData;
    }

    return;
}
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_ClearPIPEINTFlag(VAR(uint32,AUTOMATIC) intNum)
{
    HWREGB(PIPE_BASE + PIPE_O_INT_CTL_H(intNum)) = PIPE_INT_CTL_H_FLAG_CLR;
    return;
}
/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/


FUNC(void, SPI_CODE) Spi_ResetDrvObj(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj)
{
        uint32 index;
#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == \
                                                          SPI_IB_EB))
    uint32 ibIndex;
#endif
    for (index = ((uint32) 0U); index < SPI_MAX_CHANNELS; index++)
    {
        drvObj->channelObj[index].txBufPtr = NULL_PTR;
        drvObj->channelObj[index].rxBufPtr = NULL_PTR;
        drvObj->channelObj[index].numWordsTxRx = ((uint16) 0U);
        drvObj->channelObj[index].effTxFifoDepth = ((uint16) 0U);

        drvObj->channelObj[index].curTxBufPtr  = NULL_PTR;
        drvObj->channelObj[index].curRxBufPtr = NULL_PTR;
        drvObj->channelObj[index].curTxWords     = ((Spi_NumberOfDataType) 0U);
        drvObj->channelObj[index].curRxWords     = ((Spi_NumberOfDataType) 0U);
        drvObj->channelObj[index].bufWidth       = ((uint8) SPI_8BIT_BUFFER);
        drvObj->channelObj[index].dataWidthBitMask = ((uint16) 0xFFFFU);
#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == \
                                                          SPI_IB_EB))
        for(ibIndex = ((uint32) 0U); ibIndex < SPI_IB_MAX_LENGTH; ibIndex++)
        {
            drvObj->channelObj[index].txIb[ibIndex] = ((uint8)0U);
            drvObj->channelObj[index].rxIb[ibIndex] = ((uint8)0U);
        }
#endif
    }
    for (index = ((uint32) 0U); index < SPI_MAX_JOBS; index++)
    {
        drvObj->jobObj[index].jobResult     = SPI_JOB_OK;
        drvObj->jobObj[index].seqObj        = NULL_PTR;
        drvObj->jobObj[index].curChIdx      = ((uint32)0U);
        drvObj->jobObj[index].txFifoTrigLvl = ((uint32)0U);
        drvObj->jobObj[index].rxFifoTrigLvl = ((uint32)0U);
        Spi_UtilsInitNodeObject(&(drvObj->jobObj[index].nodeObj));
        drvObj->jobObj[index].extDevCfg =
            NULL_PTR;
    }
    for (index = ((uint32) 0U); index < SPI_MAX_SEQ; index++)
    {
        drvObj->seqObj[index].seqResult      = SPI_SEQ_OK;
        drvObj->seqObj[index].numJobsPending = ((uint32)0U);
    }
    for (index = ((uint32) 0U); index < SPI_MAX_HW_UNIT; index++)
    {
        drvObj->hwUnitObj[index].hwUnitResult = SPI_HW_UNIT_OK;
        drvObj->hwUnitObj[index].curJobObj    = NULL_PTR;
        /* Init current job to invalid job id */
        drvObj->hwUnitObj[index].curConfiguredJobId = SPI_MAX_JOBS;
        drvObj->hwUnitObj[index].hwUnitDemState = E_OK;
    }
    drvObj->isAsyncInProgress = (uint32) FALSE;
    drvObj->maxChannels      = ((uint8)0U);
    drvObj->maxJobs          = ((uint8)0U);
    drvObj->maxSeq           = ((uint8)0U);
    drvObj->maxHwUnit        = ((uint8)0U);
#if ((SPI_SCALABILITY == SPI_LEVEL_0) || \
    (SPI_SCALABILITY ==  SPI_LEVEL_2))
    drvObj->asyncMode        = SPI_POLLING_MODE;
#endif
#if (SPI_SCALABILITY == SPI_LEVEL_1)
    drvObj->asyncMode        = SPI_POLLING_MODE;
#endif
    return;
}

FUNC(void, SPI_CODE) Spi_CopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj,
    P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    drvObj->maxChannels  = cfgPtr->maxChannels;
    drvObj->maxJobs      = cfgPtr->maxJobs;
    drvObj->maxSeq       = cfgPtr->maxSeq;
    drvObj->maxHwUnit    = cfgPtr->maxHwUnit;
    drvObj->maxExtDevCfg = cfgPtr->maxExtDevCfg;

    Spi_PrivHWUnitCopyConfig(drvObj,cfgPtr);
    Spi_PrivExtDevCopyConfig(drvObj,cfgPtr);
    Spi_PrivJobCopyConfig(drvObj,cfgPtr);
    Spi_PrivSeqCopyConfig(drvObj,cfgPtr);
    Spi_PrivChannelCopyConfig(drvObj,cfgPtr);
    
    return;
}

FUNC(uint32, SPI_CODE) Spi_GetHwUnitBaseAddr(VAR(Spi_HWUnitType,AUTOMATIC)hwUnitId)
{
    return (Spi_HwUnitBaseAddr[hwUnitId]);
}

/*
 * Design : MCAL-24886, MCAL-24894, MCAL-24916,    
 */

static FUNC(void, SPI_CODE) Spi_CheckAndSetDrvState(void)
{
    uint32 hwUnitIdx, isSomeHwBusy;

    /* Since check is done across HW unit, all interrupts
     * are disabled */
    isSomeHwBusy = (uint32) FALSE;
    for (hwUnitIdx = ((uint32) 0U); hwUnitIdx < Spi_DrvObj.maxHwUnit;
	                                                      hwUnitIdx++)
    {
        if (Spi_DrvObj.hwUnitObj[hwUnitIdx].hwUnitResult ==
            SPI_HW_UNIT_PENDING)
        {
            isSomeHwBusy = (uint32) TRUE;
            break;
        }
    }

    if ((((uint32) FALSE)) == isSomeHwBusy)
    {
        Spi_DrvObj.isAsyncInProgress = (uint32) FALSE;
        Spi_DrvStatus = SPI_IDLE;
    }

    return;
}

FUNC(void, SPI_CODE) Spi_HwUnitInit(P2VAR(Spi_HwUnitObjType,AUTOMATIC,SPI_CODE)hwUnitObj)
{
    hwUnitObj->baseAddr   = Spi_GetHwUnitBaseAddr
	                                  (hwUnitObj->hwUnitCfg->hwUnitId);

    Spi_UtilsInitLinkList(&hwUnitObj->jobList);
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);
    
    /*Reset HW unit*/ 
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_SPIRST);

    /* set HW in controller mode as per AUTOSAR*/ 
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CTL,
                            SPI_CTL_CONTROLLER_PERIPHERAL);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CTL, SPI_CTL_TALK);
    /*Enable/Disable HS mode*/ 
    if(TRUE == hwUnitObj->hwUnitCfg->hsModeEnable){
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_HS_MODE);
    } else {
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_HS_MODE);
    }
    /* Enable/Disable FIFO Enhancements mode */
    if(TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable)
    {
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_SPIFFENA);
    } else
    {
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_SPIFFENA);
    }

    /* Enable/Disable LoopBack mode */
    if(TRUE == hwUnitObj->hwUnitCfg->loopBackEnable){
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_SPILBK);
    } else
    {
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_SPILBK);
    }

    /* Disable Tx Fifo interrupt. */
    Spi_RegWriteRaw16((hwUnitObj->baseAddr + SPI_O_FFTX),
                        (Spi_RegReadRaw16(hwUnitObj->baseAddr + SPI_O_FFTX) & (uint16)(~(SPI_FFTX_TXFFIENA))));
    if(SPI_POLLING_MODE == Spi_DrvObj.asyncMode){
        Spi_DisableInterrupt(hwUnitObj->baseAddr, hwUnitObj->hwUnitCfg->fifoModeEnable);
    } else
    {
        Spi_EnableInterrupt(hwUnitObj->baseAddr, hwUnitObj->hwUnitCfg->fifoModeEnable);
    }
    hwUnitObj->hwUnitDemState = E_OK;

    return;
}

FUNC(void, SPI_CODE) Spi_HwUnitDeInit(P2VAR(Spi_HwUnitObjType,AUTOMATIC,SPI_CODE)hwUnitObj)
{
    /* Reset HW instance*/
    Spi_HwReset(hwUnitObj->baseAddr);

    Spi_UtilsDeInitLinkList(&hwUnitObj->jobList);
    return;
}

FUNC(void, SPI_CODE) Spi_HwReset(VAR(uint32,AUTOMATIC)baseAddr)
{

    Spi_RegBitClear16(baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);
    Spi_RegBitSet16(baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);
    return;
}

FUNC(void, SPI_CODE) Spi_DisableInterrupt(VAR(uint32,AUTOMATIC)baseAddr,VAR(boolean,AUTOMATIC)isFifoEnabled){

    if((boolean) TRUE == isFifoEnabled){
        Spi_RegWriteRaw16((baseAddr + SPI_O_FFRX),
                        (Spi_RegReadRaw16(baseAddr + SPI_O_FFRX) & (uint16)(~(SPI_FFRX_RXFFIENA))));
    } else
    {
        /* Disable the specified non-FIFO interrupts. */
        Spi_RegWriteRaw16((baseAddr + SPI_O_CTL),
                        (Spi_RegReadRaw16(baseAddr + SPI_O_CTL) & (uint16)(~(SPI_CTL_SPIINTENA))));
        Spi_RegWriteRaw16((baseAddr + SPI_O_CTL),
                        (Spi_RegReadRaw16(baseAddr + SPI_O_CTL) & (uint16)(~(SPI_CTL_OVERRUNINTENA))));
    }

    return;
}

FUNC(void, SPI_CODE) Spi_EnableInterrupt(VAR(uint32,AUTOMATIC)baseAddr,VAR(boolean,AUTOMATIC)isFifoEnabled){

    /* Enable the specified non-FIFO interrupts. */
    if((boolean) TRUE == isFifoEnabled){
        /* Enable the specified FIFO-mode interrupts. */
        Spi_RegWriteRaw16((baseAddr + SPI_O_FFRX),
                        (Spi_RegReadRaw16(baseAddr + SPI_O_FFRX) | (uint16)(SPI_FFRX_RXFFIENA)));
    } else
    {
        Spi_RegWriteRaw16((baseAddr + SPI_O_CTL),
                     (Spi_RegReadRaw16(baseAddr + SPI_O_CTL) | (uint16)(SPI_CTL_SPIINTENA)));
        Spi_RegWriteRaw16((baseAddr + SPI_O_CTL),
                        (Spi_RegReadRaw16(baseAddr + SPI_O_CTL) | (uint16)(SPI_CTL_OVERRUNINTENA)));
    }
    return;
};

FUNC(void, SPI_CODE) Spi_ClearAllInterruptFlags(VAR(uint32,AUTOMATIC)baseAddr)
{
    /* Non-FIFO interrupts flags */
    Spi_RegBitClear16(baseAddr + SPI_O_STS, SPI_STS_INT_FLAG);
    Spi_RegBitClear16(baseAddr + SPI_O_STS, SPI_STS_OVERRUN_FLAG);

    /* FIFO interrupts flags */
    Spi_RegBitSet16(baseAddr + SPI_O_FFTX, SPI_FFTX_TXFFINTCLR);
    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFINTCLR);
    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFOVFCLR);
};

FUNC(uint16, SPI_CODE) Spi_GetDataWidthBitMask(VAR(uint8,AUTOMATIC)dataWidth)
{
    uint16 i, fifoBitMask = 0x0U;
    uint16 tmpVar = 0U;

    for (i = ((uint16) 0U); i < dataWidth; i++)
    {
        tmpVar = ((uint16)1U << i);
        fifoBitMask |= tmpVar;
    }

    return fifoBitMask;
};

Spi_HwUnitObjType *Spi_GetHwUnitObj(VAR(Spi_HWUnitType,AUTOMATIC)HWUnit)
{
    uint32 hwUnitIdx          = ((uint32) 0U);
    uint32 hwUnitCfgFound     = (uint32) FALSE;
    Spi_DriverObjType *drvObj = &Spi_DrvObj;
    Spi_HwUnitObjType *hwUnitObj = NULL_PTR;
    /* HW unit ID may not be the index, so search for matching HW unit */
    for (hwUnitIdx = ((uint32) 0U); hwUnitIdx < drvObj->maxHwUnit; hwUnitIdx++)
    {
        if (drvObj->hwUnitObj[hwUnitIdx].hwUnitCfg->hwUnitId == HWUnit)
        {
            hwUnitCfgFound = (uint32) TRUE;
            break; /* Match found */
        }
    }

    if (hwUnitCfgFound != ((uint32) TRUE))
    {
#if (STD_ON == SPI_DEV_ERROR_DETECT)
       (void) Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_UNIT);
#endif
    }
    else
    {
        hwUnitObj = &drvObj->hwUnitObj[hwUnitIdx];
    }

    return hwUnitObj;
}

FUNC(Spi_ChannelObjPtrType, SPI_CODE) Spi_GetCurrChannelObj(VAR(Spi_ChannelType,AUTOMATIC) chId)
{
    return (&Spi_DrvObj.channelObj[chId]);
}
/*
 * Design : MCAL-24897,     
 */
FUNC(Std_ReturnType, SPI_CODE) Spi_StartSeqAsync(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    uint32             index;
    Std_ReturnType     retVal = (Std_ReturnType) E_NOT_OK;
    Spi_UtilsNode     *headNodeObj;
    Spi_JobObjType    *jobObj;
    Spi_HwUnitObjType *hwUnitObj;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
    /* Queue the jobs in this sequence */
    retVal = Spi_QueueJobs(seqObj);
    if (((Std_ReturnType) E_OK) == retVal)
    {
        /* Check all the hardware queue and consume any pending job if
		 * the hardware is free */
        for (index = ((uint32) 0U); index < Spi_DrvObj.maxHwUnit; index++)
        {
            hwUnitObj = &Spi_DrvObj.hwUnitObj[index];
            if ((SPI_HW_UNIT_OK == hwUnitObj->hwUnitResult) && (hwUnitObj->jobList.headNode != NULL_PTR))
            {
                /* Check if we have any job pending in the queue */
                headNodeObj = Spi_UtilsGetHeadNode(
				                                 &hwUnitObj->jobList);
                /* Some job pending - schedule it */
                jobObj = (Spi_JobObjType *)
                                            headNodeObj->params.data;
                Spi_UtilsUnLinkNodePri((&(hwUnitObj->jobList)),
                                                        headNodeObj);
                hwUnitObj->curJobObj    = jobObj;
                hwUnitObj->hwUnitResult = SPI_HW_UNIT_PENDING;
                Spi_ScheduleJob(jobObj);
            }
        }
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    return retVal;
}
/*
 * Design : MCAL-24912,    
 */
static FUNC(Std_ReturnType, SPI_CODE) Spi_QueueJobs(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    uint32             index;
    uint8              currSeqId;
    Std_ReturnType     retVal = E_NOT_OK;
    Spi_JobType        jobId;
    Spi_JobObjType    *jobObj;
    Spi_HwUnitObjType *hwUnitObj;
    Spi_UtilsParams    utilsParams;
    /* Check for start sequence error */
    retVal = Spi_StartSeqCheck(seqObj);
    if (((Std_ReturnType) E_OK) == retVal)
    {
        /* Queue all the jobs to the respective hardware queue */
        for (index = ((uint32) 0U); index < seqObj->seqCfg->jobPerSeq; index++)
        {
            jobId  = seqObj->seqCfg->jobList[index];
            jobObj = &Spi_DrvObj.jobObj[jobId];

            hwUnitObj = jobObj->hwUnitObj;
            /* Get current sequence ID which is in progress for this HW unit */

            if (hwUnitObj->curJobObj == NULL_PTR)
            {
                /* No sequence in progress. Give invalid ID */
                currSeqId = SPI_MAX_SEQ;
            }
            else
            {
                currSeqId =
				        hwUnitObj->curJobObj->seqObj->seqCfg->seqId;
            }

            /* Queue the job to the hardware queue */
            jobObj->seqObj               = seqObj;
            jobObj->jobResult            = SPI_JOB_QUEUED;
            utilsParams.data             = jobObj;
            utilsParams.priority         =
			                      (uint32) jobObj->jobCfg->jobPriority;
            utilsParams.seqId            = seqObj->seqCfg->seqId;
            utilsParams.seqInterruptible =
			                          seqObj->seqCfg->seqInterruptible;
            Spi_UtilsLinkNodePri(
                &hwUnitObj->jobList,
                &jobObj->nodeObj,
                &utilsParams,
                currSeqId);
        }
        /* Set the states */
        seqObj->seqResult           = SPI_SEQ_PENDING;
        seqObj->numJobsPending      = seqObj->seqCfg->jobPerSeq;
        Spi_DrvObj.isAsyncInProgress = (uint32) TRUE;
        Spi_DrvStatus = SPI_BUSY;
    }

    return (retVal);
}
/*
 * Design : MCAL-24898,     
 */

static FUNC(Std_ReturnType, SPI_CODE) Spi_StartSeqCheck(
    P2CONST(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    uint32          index;
    Std_ReturnType  retVal = (Std_ReturnType) E_OK;
    Spi_JobObjType *jobObj;
    Spi_JobType     jobId;

    /* check all jobs if they are allowed to be queued */
    for (index = ((uint32) 0U); index < seqObj->seqCfg->jobPerSeq; index++)
    {
        jobId  = seqObj->seqCfg->jobList[index];
        jobObj = &Spi_DrvObj.jobObj[jobId];
        if ((SPI_JOB_PENDING == jobObj->jobResult) || (SPI_JOB_QUEUED == jobObj->jobResult))
        {
            /* the sequence is rejected due to common used jobs */
            retVal = (Std_ReturnType) E_NOT_OK;
            break;
        }
    }

    return (retVal);
}


static FUNC(void, SPI_CODE) Spi_ScheduleJob(P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj)
{
    uint32              isIntrMode;
    Spi_ChannelType     chId;
    Spi_ChannelObjType  *chObj;
    Spi_HwUnitObjType   *hwUnitObj;

    hwUnitObj = jobObj->hwUnitObj;

    if (SPI_POLLING_MODE == Spi_DrvObj.asyncMode)
    {
        isIntrMode = (uint32) FALSE;
    }
    else
    {
        isIntrMode = (uint32) TRUE;
    }
    /* Set the states */
    jobObj->jobResult = SPI_JOB_PENDING;
    jobObj->curChIdx  = ((uint32) 0U);

    /* Configure the hardware if previously configured job ID is
	 * different */
    if (hwUnitObj->curConfiguredJobId != jobObj->jobCfg->jobId)
    {
        Spi_ConfigJob(hwUnitObj, jobObj);
        hwUnitObj->curConfiguredJobId = jobObj->jobCfg->jobId;
    }

    /* Start the first channel */
    chId  = jobObj->jobCfg->channelList[jobObj->curChIdx];
    chObj = (Spi_ChannelObjType  *) Spi_GetCurrChannelObj(chId);
    Spi_ConfigChannel(hwUnitObj, chObj);

    /*Start Spi transfer*/ 
    Spi_Start(hwUnitObj, jobObj, chObj, isIntrMode);
    return;
}

/*
 * Design : MCAL-24864
 */
FUNC(void, SPI_CODE) Spi_ConfigJob(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                   P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj)
{


    Spi_ExternalDeviceConfigType *extDevCfg;
    extDevCfg = jobObj->extDevCfg;

    /*Update Baud rate as per external device configured*/ 
    Spi_RegMFWriteRaw16(hwUnitObj->baseAddr + SPI_O_BRR, SPI_BRR_SPI_BIT_RATE_M,
                                                        SPI_BRR_SPI_BIT_RATE_S, extDevCfg->clkDivider);




    /*configure clocking schemes*/ 
    if(SPI_CLK_MODE_0 == extDevCfg->clkMode)
    {
        /*set clock phase and clock polarity to 0*/
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CTL, SPI_CTL_CLK_PHASE);
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_CLKPOLARITY);

    }else if(SPI_CLK_MODE_1 == extDevCfg->clkMode)
    {
        /*set clock phase to 1 and clock polarity to 0*/
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CTL, SPI_CTL_CLK_PHASE);
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_CLKPOLARITY);
    } else if(SPI_CLK_MODE_2 == extDevCfg->clkMode)
    {
         /*set clock phase to 0 and clock polarity to 1*/
        Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_CTL, SPI_CTL_CLK_PHASE);
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_CLKPOLARITY);
    } else
    {
        /*set clock phase to 1and clock polarity to 1*/
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CTL, SPI_CTL_CLK_PHASE);
        Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_CLKPOLARITY);
    }

    /*add word delay if configured*/ 
    if((TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable) && (extDevCfg->wordDelay > ((Spi_DataDelayType) 0U)))
    {
        Spi_RegMFWriteRaw16(hwUnitObj->baseAddr + SPI_O_FFCT, SPI_FFCT_TXDLY_M,
                                                        SPI_FFCT_TXDLY_S, (uint16)extDevCfg->wordDelay);
    }

    return;
}


FUNC(void, SPI_CODE) Spi_ConfigChannel(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                       P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj)
{
    uint32 baseAddr;
    baseAddr = hwUnitObj->baseAddr;

#if ((SPI_CHANNEL_BUFFERS == SPI_EB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
    if (((uint8) SPI_EB) == chObj->chCfg->channelBufType)
    {
        chObj->curTxBufPtr = chObj->txBufPtr;
        chObj->curRxBufPtr = chObj->rxBufPtr;
    }
#endif
#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
    if (((uint8) SPI_IB) == chObj->chCfg->channelBufType)
    {
        chObj->curTxBufPtr = (const uint8 *) &chObj->txIb[0U];
        chObj->curRxBufPtr = (uint8 *) &chObj->rxIb[0U];
    }
#endif
    /* Reset Transmit and receive words to Zero */
    chObj->curTxWords  = ((Spi_NumberOfDataType) 0U);
    chObj->curRxWords  = ((Spi_NumberOfDataType) 0U);

    /* Set word-length in bits */
    Spi_RegMFWriteRaw16(baseAddr + SPI_O_CCR, SPI_CCR_SPICHAR_M, SPI_CCR_SPICHAR_S, (uint16)chObj->chCfg->dataWidth - 1U);
    
    return;
}


FUNC(void, SPI_CODE) Spi_Start(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj, \
               P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj, \
               P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj, \
                VAR(uint32,AUTOMATIC)isIntrMode)
{

    uint32 baseAddr;
    uint16 txIntrStatus;

    baseAddr  = hwUnitObj->baseAddr;

    /*clear all interrupt flags*/ 
    Spi_ClearAllInterruptFlags(baseAddr);

    /*Reset HW unit*/ 
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_SPIRST);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_SPIRST);

    /*Reset TxFIFO*/ 
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_TXFIFO);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_TXFIFO);

    /*Reset RxFIFO*/ 
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFRX, SPI_FFRX_RXFIFORESET);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFRX, SPI_FFRX_RXFIFORESET);

    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);

    if((chObj->numWordsTxRx > chObj->curTxWords)){
        #if(STD_ON == SPI_CS_VIA_GPIO)
        /* Enable chip select if it is GPIO*/
        if(CS_VIA_GPIO == jobObj->jobCfg->csSelect){
            /*Set Chip select*/
            Spi_ConfigGpioChipSelect(jobObj, TRUE);
        }
        #endif
        if(((uint32) FALSE) == isIntrMode)
        {
            /*Disable interrupts */ 
            Spi_DisableInterrupt(baseAddr, hwUnitObj->hwUnitCfg->fifoModeEnable);
            
        }
        else
        {
            Spi_EnableInterrupt(baseAddr, hwUnitObj->hwUnitCfg->fifoModeEnable);
        }

        if((boolean)TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable){
            txIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFTX);
            if(chObj->numWordsTxRx <= SPI_FIFO_RX_INTERRUPT_LEVEL){
                Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, SPI_FFRX_RXFFIL_S, chObj->numWordsTxRx);
            } else{
                Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, SPI_FFRX_RXFFIL_S, SPI_FIFO_RX_INTERRUPT_LEVEL);
            }
            /* Transmit next words */
            Spi_PrivProcessTxEvent(baseAddr, chObj, txIntrStatus);
        } else{
            Spi_WriteTxBufferNonFifo(chObj,baseAddr);
        }
    }
    return;
}
FUNC(void, SPI_CODE) Spi_StartNextChannel(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
               P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj)
{
    uint32 baseAddr;
    uint16 txIntrStatus;
    baseAddr  = hwUnitObj->baseAddr;

    /*clear all interrupt flags*/ 
    Spi_ClearAllInterruptFlags(baseAddr);

    /*Reset TxFIFO*/ 
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_TXFIFO);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFTX, SPI_FFTX_TXFIFO);

    /* Reset RxFIFO*/
    Spi_RegBitClear16(hwUnitObj->baseAddr + SPI_O_FFRX, SPI_FFRX_RXFIFORESET);
    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_FFRX, SPI_FFRX_RXFIFORESET);

    Spi_RegBitSet16(hwUnitObj->baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);

    if((boolean)TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable){
        if(chObj->numWordsTxRx > chObj->curTxWords){
            if(chObj->numWordsTxRx <= SPI_FIFO_RX_INTERRUPT_LEVEL){
                Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, SPI_FFRX_RXFFIL_S, chObj->numWordsTxRx);
            } else{
                Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, SPI_FFRX_RXFFIL_S, SPI_FIFO_RX_INTERRUPT_LEVEL);
            }

            /*Enable FIFO Interrupt if configured */
            if(SPI_INTERRUPT_MODE == Spi_DrvObj.asyncMode){
                Spi_RegBitSet16(baseAddr + SPI_O_FFTX, SPI_FFTX_TXFFIENA);
            }

            txIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFTX);
            Spi_PrivProcessTxEvent(baseAddr, chObj, txIntrStatus);
            
        }
    }else
    {
        if(chObj->numWordsTxRx > chObj->curTxWords)
        {
                Spi_WriteTxBufferNonFifo(chObj,baseAddr);
        }
    }
    return;
}

static FUNC(void, SPI_CODE) Spi_ScheduleAllJobsSyncTransmit(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    uint32               index;
    Spi_JobObjType      *jobObj;
    Spi_HwUnitObjType   *hwUnitObj;
    Spi_JobType          jobId;
    Spi_JobResultType    jobResult;

    /* Set state of all jobs in sequence to queued */
    for (index = ((uint32) 0U); index < seqObj->seqCfg->jobPerSeq; index++)
    {
        jobId  = seqObj->seqCfg->jobList[index];
        jobObj = &Spi_DrvObj.jobObj[jobId];
        /* Queue the job to the hardware queue */
        jobObj->seqObj = seqObj;
        /* Set the states */
        jobObj->jobResult = SPI_JOB_QUEUED;
    }

    for (index = ((uint32) 0U); index < seqObj->seqCfg->jobPerSeq; index++)
    {
        jobId  = seqObj->seqCfg->jobList[index];
        jobObj = &Spi_DrvObj.jobObj[jobId];
        /* Queue the job to the hardware queue */
        jobObj->seqObj = seqObj;
        if(seqObj->numJobsPending > 0U){
            if(SPI_SEQ_FAILED != seqObj->seqResult){
                /* Set the states */
                jobObj->jobResult = SPI_JOB_PENDING;
                jobObj->curChIdx  = ((uint32) 0U);
                hwUnitObj         = jobObj->hwUnitObj;

                hwUnitObj->curJobObj    = jobObj;
                hwUnitObj->hwUnitResult = SPI_HW_UNIT_PENDING;
                
                /* Configure the hardware if previously configured job ID is
                * different */
                if (hwUnitObj->curConfiguredJobId != jobObj->jobCfg->jobId)
                {
                    Spi_ConfigJob(hwUnitObj, jobObj);
                    hwUnitObj->curConfiguredJobId = jobObj->jobCfg->jobId;
                }
                jobResult = Spi_TransferJob
                                ((Spi_HwUnitObjType *) hwUnitObj,
                                                                    jobObj);
                #if(STD_ON == SPI_CS_VIA_GPIO)
                if(CS_VIA_GPIO == jobObj->jobCfg->csSelect){
                    /*Set Chip select*/
                    Spi_ConfigGpioChipSelect(jobObj, FALSE);
                }
                #endif
                hwUnitObj->curJobObj    = NULL_PTR;
                hwUnitObj->hwUnitResult = SPI_HW_UNIT_OK;

                seqObj->numJobsPending--;
                jobObj->jobResult  = jobResult;

                /* Fail the sequence if job fails */
                if (SPI_JOB_FAILED == jobResult)
                {
                    seqObj->seqResult = SPI_SEQ_FAILED;
                }
            }else{
                /* If one of the Job is failed, Mark remaining jobs as failed */
                jobObj->jobResult = SPI_JOB_FAILED;
                seqObj->numJobsPending--;
            }           
        }
        
    }

    return;
}

FUNC(Spi_JobResultType, SPI_CODE) Spi_TransferJob(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj, \
                                 P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj)
{
    uint32              index;
    Spi_ChannelType     chId;
    Spi_ChannelObjType *chObj;
    Spi_JobResultType   jobResult = SPI_JOB_PENDING;

    /* Transfer all the channels */
    for (index = ((uint32) 0U); index < jobObj->jobCfg->channelPerJob; index++)
    {
        chId  = jobObj->jobCfg->channelList[jobObj->curChIdx];
        chObj = (Spi_ChannelObjType  *) Spi_GetCurrChannelObj(chId);

        /* Configure and start the channel */
        Spi_ConfigChannel(hwUnitObj, chObj);

        Spi_Start(hwUnitObj, jobObj, chObj, (uint32) FALSE);
        /* Busy loop till channel transfer is completed */
        do
        {
            jobResult = Spi_ContinueTxRx(hwUnitObj,chObj);
        }
        while (SPI_JOB_PENDING == jobResult);
        /* check the job status and continue to next channel */
        if(SPI_JOB_FAILED == jobResult){
            break;
        }else{
            /* Move to next channel */
            jobObj->curChIdx++;
        }
    }

    return (jobResult);
}

static FUNC(void, SPI_CODE) Spi_ReadFifo(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj,
                         VAR(uint32,AUTOMATIC) baseAddr,
                         VAR(uint32,AUTOMATIC)      numWordsToRead,
                         VAR(uint16,AUTOMATIC) curRxWords)
{
    if(NULL_PTR != chObj->curRxBufPtr)
    {
        if(SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            chObj->curRxBufPtr = Spi_FifoRead8(
                                     baseAddr,
                                     chObj->curRxBufPtr,
                                     numWordsToRead,
                                     chObj->dataWidthBitMask,
                                     curRxWords);
        }
        else
        {
            chObj->curRxBufPtr = (uint8 *) Spi_FifoRead16(
                                     baseAddr,
                                     (uint16 *) chObj->curRxBufPtr,
                                     numWordsToRead,
                                     chObj->dataWidthBitMask,
                                     curRxWords);
        }
    }
    else
    {
        /* NULL RX pointer provided. Read and discard data */
        Spi_FifoReadDiscard(baseAddr, numWordsToRead);
    }
    chObj->curRxWords += (Spi_NumberOfDataType) numWordsToRead;

    return;
}
/*
 * Design : MCAL-24871, MCAL-24872, MCAL-24873
 */

static FUNC(void, SPI_CODE) Spi_WriteFifo(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj,
                         VAR(uint32,AUTOMATIC) baseAddr,
                         VAR(uint32,AUTOMATIC)      numWordsToWrite,
                         VAR(uint16,AUTOMATIC) curTxWords)
{
    if(NULL_PTR != chObj->curTxBufPtr)
    {
        if(SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            chObj->curTxBufPtr = Spi_FifoWrite8(
                                     baseAddr,
                                     (uint32) chObj->chCfg->dataWidth,
                                     chObj->curTxBufPtr,
                                     numWordsToWrite,
                                     curTxWords);
        }
        else
        {
            chObj->curTxBufPtr = (const uint8 *) Spi_FifoWrite16(
                                     baseAddr,
                                     (uint32) chObj->chCfg->dataWidth,
                                     (const uint16 *) chObj->curTxBufPtr,
                                     numWordsToWrite,
                                     curTxWords);
        }
    }
    else
    {
        /* NULL TX pointer provided. Use default data */
        Spi_FifoWriteDefault(baseAddr, (uint32) chObj->chCfg->dataWidth,
                            chObj->chCfg->defaultTxData, numWordsToWrite);
    }
    chObj->curTxWords += (Spi_NumberOfDataType) numWordsToWrite;

    return;
}

LOCAL_INLINE FUNC(void, SPI_CODE) Spi_ReadRxBufferNonFifo(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE)chObj,\
                               VAR(uint32,AUTOMATIC)baseAddr)
{
    uint8 * rxBufferPtr8;
    uint16 * rxBufferPtr16;
    uint16 rxData;
    if(NULL_PTR != chObj->curTxBufPtr)
    {
        if(SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            rxBufferPtr8 = (uint8 *) chObj->curRxBufPtr;
            rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
            rxData &= chObj->dataWidthBitMask;         /* Clear unused bits */
            rxBufferPtr8[chObj->curRxWords] = (uint8) rxData;
        }
        else
        {
            rxBufferPtr16 = (uint16 *) chObj->curRxBufPtr;
            rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
            rxData &= chObj->dataWidthBitMask;         /* Clear unused bits */
            rxBufferPtr16[chObj->curRxWords] = (uint16) rxData;
        }
    }
    else
    {
        /* Read the data from RX Buffer and discard it */
        rxData = Spi_RegReadRaw16(baseAddr + SPI_O_RXBUF);
        (void) rxData;
    }
    chObj->curRxWords++;
    return;
}

LOCAL_INLINE FUNC(void, SPI_CODE) Spi_WriteTxBufferNonFifo(P2VAR(Spi_ChannelObjType, AUTOMATIC, SPI_CODE)chObj,\
                               VAR(uint32,AUTOMATIC)baseAddr)
{
    const uint8 * txBufferPtr8;
    const uint16 * txBufferPtr16;
    uint16 txData;
    if(NULL_PTR != chObj->curTxBufPtr)
    {
        if(SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            txBufferPtr8 = (const uint8 *) chObj->curTxBufPtr;
            txData = txBufferPtr8[chObj->curTxWords];
            Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, (txData << (SPI_MAX_WORD_LENGTH - chObj->chCfg->dataWidth)));
        }
        else
        {
            txBufferPtr16 = (const uint16 *) chObj->curTxBufPtr;
            txData = txBufferPtr16[chObj->curTxWords];
            Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, (txData << (SPI_MAX_WORD_LENGTH - chObj->chCfg->dataWidth)));
        }
    }
    else
    {
        /* NULL TX pointer provided. Use default data */
        Spi_RegWriteRaw16(baseAddr + SPI_O_TXBUF, \
        chObj->chCfg->defaultTxData << (SPI_MAX_WORD_LENGTH - chObj->chCfg->dataWidth));
    }
    chObj->curTxWords++;
    return;
}
/*
 * Design : MCAL-24890 
 */
FUNC(Spi_JobResultType, SPI_CODE) Spi_ContinueTxRx(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                                   P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj)
{
    uint32 baseAddr,numWordsToRead = 0;
    uint16 intrStatus, rxIntrStatus, txIntrStatus;
    Spi_JobResultType                  jobResult = SPI_JOB_PENDING;
    uint16 numWordsNextToRead = 0;

    baseAddr    = hwUnitObj->baseAddr;

    if((boolean)TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable)
    {
        /* Handle RX events */
        /* Get interrupt status */
        txIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFTX);
        rxIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFRX);
        if((rxIntrStatus & SPI_FFRX_RXFFOVF) == SPI_FFRX_RXFFOVF){
            /* since there is an overrun in the trasmission 
                mark the job as Failed */
            jobResult = SPI_JOB_FAILED;
            #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
            /* Report HW error to DEM */
            hwUnitObj->hwUnitDemState = (Std_ReturnType) E_NOT_OK;
            Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
            #endif
            /* clear Rx FF over flow */
            Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFOVFCLR);
        }
        if ((rxIntrStatus & SPI_FFRX_RXFFINT) == SPI_FFRX_RXFFINT)
        {
            #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
            /* Report HW error passed to DEM */
            if(hwUnitObj->hwUnitDemState == (Std_ReturnType) E_NOT_OK){
                hwUnitObj->hwUnitDemState = (Std_ReturnType) E_OK;
                Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
            }
            #endif
            numWordsToRead = (uint32) Spi_RegMFReadRaw16(baseAddr + SPI_O_FFRX, 
                                    SPI_FFRX_RXFFST_M, SPI_FFRX_RXFFST_S);
            Spi_ReadFifo(chObj, baseAddr, numWordsToRead,chObj->curRxWords);
            if(chObj->numWordsTxRx > chObj->curRxWords){
                numWordsNextToRead = ((uint32)chObj->numWordsTxRx - chObj->curRxWords);
                if((numWordsNextToRead < SPI_FIFO_RX_INTERRUPT_LEVEL) && (numWordsNextToRead != 0U)){
                    Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, \
                    SPI_FFRX_RXFFIL_S, numWordsNextToRead);
                }
            }
            // Clear Rx interrupt flag
            Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFINTCLR);

            /* Transmit next words */
            Spi_PrivProcessTxEvent(baseAddr, chObj, txIntrStatus);
        }
        else{
            /* Do nothing*/
        }
    }
    else
    {
        intrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_STS);
        if(SPI_STS_OVERRUN_FLAG == (intrStatus & SPI_STS_OVERRUN_FLAG))
        {
            /* since there is an overrun in the trasmission 
                mark the job as SPI_JOB_FAILED */
            jobResult = SPI_JOB_FAILED;
            #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
            /* Report HW error to DEM */
            hwUnitObj->hwUnitDemState = (Std_ReturnType) E_NOT_OK;
            Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
            #endif
            /* clear OVERRUN_FLAG */
            Spi_RegBitSet16(baseAddr + SPI_O_STS, SPI_STS_OVERRUN_FLAG);
        }
        else
        {
            if((intrStatus & SPI_STS_INT_FLAG) == SPI_STS_INT_FLAG)
            {
                #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
                /* Report HW error passed to DEM */
                if(hwUnitObj->hwUnitDemState == (Std_ReturnType) E_NOT_OK){
                    hwUnitObj->hwUnitDemState = (Std_ReturnType) E_OK;
                    Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
                }
                #endif
                /* Read receive buffer*/
                Spi_ReadRxBufferNonFifo(chObj, baseAddr);
                if((chObj->numWordsTxRx > chObj->curTxWords)){
                    /* Write into Tx buffer*/
                    Spi_WriteTxBufferNonFifo(chObj, baseAddr);
                }
            }
        }
    }
    if ((chObj->numWordsTxRx == chObj->curTxWords) && (chObj->numWordsTxRx == chObj->curRxWords))
    {
        jobResult = SPI_JOB_OK;
    }
    return jobResult;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_StartSeqSync(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    Std_ReturnType       retVal = ((Std_ReturnType) E_NOT_OK);
    {
        /* Set the states */
        seqObj->seqResult      = SPI_SEQ_PENDING;
        seqObj->numJobsPending = seqObj->seqCfg->jobPerSeq;
        Spi_DrvStatus          = SPI_BUSY;

        /* Schedule all the jobs one after another in case of Sync
		 *  transfer */
        Spi_ScheduleAllJobsSyncTransmit(seqObj);

        /* check if any job has previously failed or cancelled
         * and hence the sequence result is already set. So
         * don't overwrite the sequence status with OK for the
         * subsequent job */
        if (seqObj->seqResult == SPI_SEQ_PENDING)
        {
            seqObj->seqResult = SPI_SEQ_OK;
        }
    /*
         * Check if all hardware is free so that driver can be
         * put in idle state
         */
        Spi_CheckAndSetDrvState();
        retVal = (Std_ReturnType) E_OK;
    }

    return (retVal);
}

FUNC(void, SPI_CODE) Spi_ProcessRxEvent(VAR(Spi_HWUnitType,AUTOMATIC)hwUnitId)
{
    Spi_HwUnitObjType  *hwUnitObj = NULL_PTR;
    Spi_ChannelType     chId;
    Spi_ChannelObjType *chObj;
    Spi_JobObjType     *jobObj;
    uint32 baseAddr, numWordsToRead, numWordsNextToRead;
    uint16 intrStatus, rxIntrStatus, txIntrStatus;
    Spi_JobResultType   jobResult = SPI_JOB_PENDING;

    hwUnitObj = Spi_GetHwUnitObj(hwUnitId);
    if (NULL_PTR != hwUnitObj)
    {
        baseAddr = hwUnitObj->baseAddr;
        /* Get the current job/sequence */
        jobObj = hwUnitObj->curJobObj;
        if (jobObj == NULL_PTR)
        {
            Spi_ClearAllIrqStatus(baseAddr);
        }
        else
        {
            chId = jobObj->jobCfg->channelList[jobObj->curChIdx];
            /* Each port is considered as one controller */
            chObj = (Spi_ChannelObjType  *) Spi_GetCurrChannelObj(chId);

            if((boolean)TRUE == hwUnitObj->hwUnitCfg->fifoModeEnable)
            {
                txIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFTX);
                rxIntrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_FFRX);
                
                /*
                * Handle RX events
                */
                if((rxIntrStatus & SPI_FFRX_RXFFOVF) == SPI_FFRX_RXFFOVF){
                    /* since there is an overrun in the trasmission 
                        mark the job as Failed */
                    jobResult = SPI_JOB_FAILED;
                    #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
                    /* Report HW error to DEM */
                    hwUnitObj->hwUnitDemState = (Std_ReturnType) E_NOT_OK;
                    Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
                    #endif
                    /* clear Rx FF over flow */
                    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFOVFCLR);
                } 
                else if((rxIntrStatus & SPI_FFRX_RXFFINT) == SPI_FFRX_RXFFINT)
                {
                    #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
                    /* Report HW error passed to DEM */
                    if(hwUnitObj->hwUnitDemState == (Std_ReturnType) E_NOT_OK){
                        hwUnitObj->hwUnitDemState = (Std_ReturnType) E_OK;
                        Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
                    }
                    #endif
                    numWordsToRead = (uint32) Spi_RegMFReadRaw16(baseAddr + SPI_O_FFRX, 
                                            SPI_FFRX_RXFFST_M, SPI_FFRX_RXFFST_S);
                    Spi_ReadFifo(chObj, baseAddr, numWordsToRead,chObj->curRxWords);
                    if(chObj->numWordsTxRx > chObj->curRxWords){
                        numWordsNextToRead = ((uint32)chObj->numWordsTxRx - chObj->curRxWords);
                        if((numWordsNextToRead < SPI_FIFO_RX_INTERRUPT_LEVEL) && (numWordsNextToRead != 0U)){
                            Spi_RegMFWriteRaw16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFIL_M, \
                            SPI_FFRX_RXFFIL_S, numWordsNextToRead);
                        }
                    }
                    /*  Clear Rx interrupt flag */
                    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFINTCLR);
                    if(SPI_INTERRUPT_MODE == Spi_DrvObj.asyncMode){
                        /* Add delay for SPI Instance Interrupt (SPI HW erratas) */
                        McalLib_Delay(1);
                        Spi_ClearPIPEINTFlag(hwUnitObj->hwUnitCfg->RxPIPEVectorID);
                        /* Add delay to clear SPI PIPE Interrupt (SPI HW erratas) */
                        McalLib_Delay(1);
                    }
                    
                    /* Transmit next words */
                    Spi_PrivProcessTxEvent(baseAddr, chObj, txIntrStatus);
                }
                else
                {
                    /* Do nothing*/
                }
            } 
            else
            {
                intrStatus = Spi_RegReadRaw16(baseAddr + SPI_O_STS);
                if(SPI_STS_OVERRUN_FLAG == (intrStatus & SPI_STS_OVERRUN_FLAG))
                {
                    /* since there is an overrun in the trasmission 
                        mark the job as SPI_JOB_FAILED */
                    jobResult = SPI_JOB_FAILED;
                    #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
                    /* Report HW error to DEM */
                    hwUnitObj->hwUnitDemState = (Std_ReturnType) E_NOT_OK;
                    Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
                    #endif
                    /* clear OVERRUN_FLAG */
                    Spi_RegBitSet16(baseAddr + SPI_O_STS, SPI_STS_OVERRUN_FLAG);
                }
                else
                {
                    if((intrStatus & SPI_STS_INT_FLAG) == SPI_STS_INT_FLAG){
                        #if(SPI_E_HARDWARE_ERROR != SPI_DEM_NO_EVENT)
                        /* Report HW error passed to DEM */
                        if(hwUnitObj->hwUnitDemState == (Std_ReturnType) E_NOT_OK){
                            hwUnitObj->hwUnitDemState = (Std_ReturnType) E_OK;
                            Dem_SetEventStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
                        }
                        #endif
                        /* Read receive buffer*/
                        Spi_ReadRxBufferNonFifo(chObj, baseAddr);
                        if((chObj->numWordsTxRx > chObj->curTxWords)){
                            /* Write into Tx buffer*/
                            Spi_WriteTxBufferNonFifo(chObj, baseAddr);
                        }
                    }
                }
            }
            if((chObj->numWordsTxRx - chObj->curRxWords) == (uint16)0U)
            {
                jobResult = SPI_JOB_OK;
            }
            if (SPI_JOB_PENDING != jobResult)
            {
                /*
                * Channel completed or failed!!
                *
                * Caution: Since there is no channel status macro, we are
                * reusing the job status macros. Also this can be 
                * directly used to assign to job status
                */
                Spi_ProcessChCompletion(hwUnitObj, jobResult);
            }else
            {
                /* Else Job is still pending. Do nothing, wait for next 
                * interrupt */
            }
        }
    }
    return;
}


FUNC(void, SPI_CODE) Spi_ProcessChCompletion(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj, \
                             VAR(Spi_JobResultType,AUTOMATIC)jobResult)
{
    Spi_ChannelType     chId;
    Spi_ChannelObjType *chObj;
    Spi_SeqObjType      *seqObj;
    Spi_JobObjType     *jobObj;
    jobObj = hwUnitObj->curJobObj;
    seqObj = jobObj->seqObj;
    /*check if all the channels transfer is completed */
    jobObj->curChIdx++;
    if(SPI_JOB_FAILED == jobResult){
        jobObj->jobResult = jobResult;
        seqObj->seqResult = SPI_SEQ_FAILED;
    }
    if (jobObj->curChIdx == jobObj->jobCfg->channelPerJob)
    {
        Spi_StopJob(hwUnitObj, jobObj);
        Spi_ProcessJobCompletion(hwUnitObj,jobObj);
    }else
    {
        chId  = jobObj->jobCfg->channelList[jobObj->curChIdx];
        chObj = (Spi_ChannelObjType  *) Spi_GetCurrChannelObj(chId);
        Spi_ConfigChannel(hwUnitObj, chObj);
        Spi_StartNextChannel(hwUnitObj, chObj);
    }
    return;
}
/*
 * Design : MCAL-24893,  MCAL-24901, MCAL-24902, MCAL-24903, MCAL-24904
 * Design : MCAL-24919 , MCAL-24920 
 */
static FUNC(void, SPI_CODE) Spi_ProcessJobCompletion(P2VAR(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)HwUnitObj,
                                     P2VAR(Spi_JobObjType,AUTOMATIC, SPI_CODE)JobObj)
{
    Spi_UtilsNode       *headNodeObj;
    Spi_SeqObjType      *seqObj;
    Spi_SeqEndNotifyType seqEndNotification = NULL_PTR;
    Spi_JobEndNotifyType jobEndNotification = NULL_PTR;
    Spi_JobType jobId;
    uint32 jobIndex ,Avoid_nesting_flag = 0U;
    Spi_HwUnitObjType   *hwUnitObj;
    Spi_JobObjType      *jobObj;
    
    hwUnitObj = HwUnitObj;
    jobObj = JobObj;

    seqObj = jobObj->seqObj;

    hwUnitObj->curJobObj = NULL_PTR;
    seqObj->numJobsPending--;
    if (jobObj->jobResult == SPI_JOB_PENDING){
        jobObj->jobResult  = SPI_JOB_OK;
    }
    jobEndNotification = jobObj->jobCfg->Spi_JobEndNotification;


    /* Check if sequence is complete */
    if (0U == seqObj->numJobsPending)
    {
        /* check if any job has previously failed or cancelled
         * and hence the sequence result is already set. So
         * don't overwrite the sequence status with OK for the
         * subsequent job */
        if (seqObj->seqResult == SPI_SEQ_PENDING)
        {
            seqObj->seqResult = SPI_SEQ_OK;
        }
        seqEndNotification = 
		                   seqObj->seqCfg->Spi_SequenceEndNotification;
    }
    if (SPI_SEQ_FAILED == seqObj->seqResult)
    {
 
        /* Check all the jobs in the sequence and remove them if they are not
         * already started. If they are started allow the job to complete
         * in the normal way and do the clean-up in the ISR context */
        for (jobIndex = 0U; jobIndex < seqObj->seqCfg->jobPerSeq; jobIndex++)
        {
            jobId     = (uint32) seqObj->seqCfg->jobList[jobIndex];
            jobObj    = &Spi_DrvObj.jobObj[jobId];
            hwUnitObj = jobObj->hwUnitObj;
            Avoid_nesting_flag = 0U;
            if ((jobObj->jobResult == SPI_JOB_QUEUED) && (seqObj->numJobsPending > 0U))
            {
                /* Job is not active, remove from HW job queue */
                Spi_UtilsUnLinkNodePri(&hwUnitObj->jobList, &jobObj->nodeObj);
                seqObj->numJobsPending--;
                jobObj->jobResult = SPI_JOB_FAILED;
                Avoid_nesting_flag = 1U;
            }
            /* Notify Job end */
            if ((Avoid_nesting_flag == 1U) && (NULL_PTR != jobObj->jobCfg->Spi_JobEndNotification))
            {
                jobEndNotification = jobObj->jobCfg->Spi_JobEndNotification;
                jobEndNotification();
            }
           
        }
    }
    /* Check if any new job is pending */
    headNodeObj = Spi_UtilsGetHeadNode(&hwUnitObj->jobList);
    if (headNodeObj != NULL_PTR)
    {
        Spi_JobObjType *nextJobObj;
        /* Some job pending - schedule it */
        nextJobObj = (Spi_JobObjType *) headNodeObj->params.data;
        Spi_UtilsUnLinkNodePri((&(hwUnitObj->jobList)), headNodeObj);

        hwUnitObj->curJobObj    = nextJobObj;
        hwUnitObj->hwUnitResult = SPI_HW_UNIT_PENDING;
        Spi_ScheduleJob(nextJobObj);
    }
    else
    {
        /* No new job scheduled, hardware is free!! */
        hwUnitObj->hwUnitResult = SPI_HW_UNIT_OK;

        /*
         * Check if all hardware is free so that driver can be
         * put in idle state
         */
        Spi_CheckAndSetDrvState();
    }

    /* Notify Job end - should be done after scheduling */
    if (NULL_PTR != jobEndNotification)
    {
        jobEndNotification();
    }

    /* Notify Sequence end - should be done after scheduling */
    if (NULL_PTR != seqEndNotification)
    {
        seqEndNotification();
    }

    return;
}

FUNC(void, SPI_CODE) Spi_StopJob(P2CONST(Spi_HwUnitObjType,AUTOMATIC, SPI_CODE)hwUnitObj,
                 P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj)
{
    #if(STD_ON == SPI_CS_VIA_GPIO)
    /* UnSet chip select, if GPIO */
    if((Spi_CsSelection)CS_VIA_GPIO == jobObj->jobCfg->csSelect){
        Spi_ConfigGpioChipSelect(jobObj, FALSE);
    }
    #endif
     /* disable all interrupts */
    Spi_DisableInterrupt(hwUnitObj->baseAddr, hwUnitObj->hwUnitCfg->fifoModeEnable);

    return;
}

/*
 * Design : MCAL-24864
 */
#if(STD_ON == SPI_CS_VIA_GPIO)
FUNC(void, SPI_CODE) Spi_ConfigGpioChipSelect(P2CONST(Spi_JobObjType,AUTOMATIC, SPI_CODE)jobObj,VAR(boolean,AUTOMATIC)enable)
{
    uint32 gpioCsId = jobObj->jobCfg->csGpioId;
    
    if((Spi_CsLevelType)STD_LOW ==  (Spi_CsLevelType)jobObj->extDevCfg->csPolarity)
    {
        if(FALSE == enable){
            Dio_WriteChannel(gpioCsId, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(gpioCsId, STD_HIGH);
        }
        
    }else
    {
        if(FALSE == enable){
            Dio_WriteChannel(gpioCsId, STD_HIGH);
        }
        else
        {
            Dio_WriteChannel(gpioCsId, STD_LOW);
        }
    }
    return;
};
#endif
FUNC(void, SPI_CODE) Spi_CancelSequence(P2VAR(Spi_SeqObjType,AUTOMATIC,SPI_CODE)seqObj)
{
    uint32 jobIndex, jobId;
    Spi_JobObjType      *jobObj;
    Spi_HwUnitObjType   *hwUnitObj;
    Spi_SeqEndNotifyType seqEndNotification = NULL_PTR;
    Spi_JobEndNotifyType jobEndNotification = NULL_PTR;
    uint32 Avoid_nesting_flag = 0U;

 
    /* only a pending sequence can be cancelled */
    if (SPI_SEQ_PENDING == seqObj->seqResult)
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
        /* Cancel the sequence */
        seqObj->seqResult = SPI_SEQ_CANCELLED;
 
        /* Check all the jobs in the sequence and remove them if they are not
         * already started. If they are started allow the job to complete
         * in the normal way and do the clean-up in the ISR context */
        for (jobIndex = 0U; jobIndex < seqObj->seqCfg->jobPerSeq; jobIndex++)
        {
            jobId     = (uint32) seqObj->seqCfg->jobList[jobIndex];
            jobObj    = &Spi_DrvObj.jobObj[jobId];
            hwUnitObj = jobObj->hwUnitObj;
            Avoid_nesting_flag = 0U;
            if ((jobObj->jobResult == SPI_JOB_QUEUED) && (jobObj->seqObj->numJobsPending > 0U))
            {
                /* Job is not active, remove from HW job queue */
                Spi_UtilsUnLinkNodePri(&hwUnitObj->jobList, &jobObj->nodeObj);
                jobObj->seqObj->numJobsPending--;
                jobObj->jobResult = SPI_JOB_FAILED;
                Avoid_nesting_flag = 1U;
            }
            /* Notify Job end */
            if ((Avoid_nesting_flag == 1U) && (NULL_PTR != jobObj->jobCfg->Spi_JobEndNotification))
            {
                /*Exit exclusive area since, notification cann't be called inside exclusive area*/
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
                jobEndNotification = jobObj->jobCfg->Spi_JobEndNotification;
                jobEndNotification();
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();
            }
           
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
 
        /* If all jobs of the sequence are removed, then notify sequence end
         * callback */
        if ((0U == seqObj->numJobsPending) &&
            (NULL_PTR != seqObj->seqCfg->Spi_SequenceEndNotification))
        {
            seqEndNotification = seqObj->seqCfg->Spi_SequenceEndNotification;
            seqEndNotification();
        }
    }
 
 
    return;
}


FUNC(void, SPI_CODE) Spi_ClearAllIrqStatus( VAR(uint32,AUTOMATIC) baseAddr)
{
    /* Clear the specified non-FIFO interrupt sources. */
    Spi_RegBitClear16(baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);
    Spi_RegBitSet16(baseAddr + SPI_O_CCR, SPI_CCR_SPISWRESET);
    Spi_RegBitSet16(baseAddr + SPI_O_STS, SPI_STS_OVERRUN_FLAG);

    /* Clear the specified FIFO-mode interrupt sources. */
    Spi_RegBitSet16(baseAddr + SPI_O_FFTX, SPI_FFTX_TXFFINTCLR);
    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFINTCLR);
    Spi_RegBitSet16(baseAddr + SPI_O_FFRX, SPI_FFRX_RXFFOVFCLR);
}
#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
FUNC(void, SPI_CODE) Spi_PrivIntlBufWrite8(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)ChObj, \
                           P2CONST(Spi_DataBufferType,AUTOMATIC,SPI_CODE)DataBufferPtr)
{
    const uint8        *tempBuf8;
    uint8              *tempIbPtr8;
    uint32              index;

    tempIbPtr8 = ((uint8 *) &ChObj->txIb[0U]);
    for (index = ((uint32) 0U); index < ChObj->chCfg->maxBufLength; 
                                                        index++)
    {
        if (NULL_PTR != DataBufferPtr)
        {
            tempBuf8 = (const uint8 *) DataBufferPtr;
            tempBuf8 += index;
        }
        else
        {
            tempBuf8 = ((const uint8 *) 
                                &ChObj->chCfg->defaultTxData);
        }
        tempIbPtr8[index] = *tempBuf8;
    }
}

FUNC(void, SPI_CODE) Spi_PrivIntlBufWrite16(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)ChObj, \
                           P2CONST(Spi_DataBufferType,AUTOMATIC,SPI_CODE)DataBufferPtr)
{
    const uint16        *tempBuf16;
    uint16             *tempIbPtr16;
    uint32              index;

    tempIbPtr16 = ((uint16 *) &ChObj->txIb[0U]);
    for (index = ((uint32) 0U); index < ChObj->chCfg->maxBufLength; 
                                                        index++)
    {
        if (NULL_PTR != DataBufferPtr)
        {
            tempBuf16 = (const uint16 *) DataBufferPtr;
            tempBuf16 += index;
        }
        else
        {
            tempBuf16 = ((const uint16 *) 
                                &ChObj->chCfg->defaultTxData);
        }
        tempIbPtr16[index] = *tempBuf16;
    }
}

FUNC(void, SPI_CODE) Spi_PrivReadIB(P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj, \
                    P2CONST(Spi_DataBufferType,AUTOMATIC,SPI_CODE)DataBufferPointer)
{
    uint8              *tempBuf8;
    uint8              *tempIbPtr8;
    uint16             *tempBuf16;
    uint16             *tempIbPtr16;
    uint32              index;

    if (SPI_8BIT_BUFFER == chObj->bufWidth)
        {
            tempBuf8 = (uint8 *) DataBufferPointer;
            tempIbPtr8 = ((uint8 *) &chObj->rxIb[0U]);
            for (index = ((uint32) 0U); index < chObj->chCfg->maxBufLength; 
			                                                 index++)
            {
                tempBuf8[index] = tempIbPtr8[index];
            }
        }
        else
        {
            tempBuf16 = (uint16 *) DataBufferPointer;
            tempIbPtr16 = ((uint16 *) &chObj->rxIb[0U]);
            for (index = ((uint32) 0U); index < chObj->chCfg->maxBufLength; 
			                                                 index++)
            {
                tempBuf16[index] = tempIbPtr16[index];
            }
        }
}
#endif
FUNC(Spi_StatusType, SPI_CODE) Spi_PrivGetHWStatus(P2CONST(Spi_HwUnitObjType,AUTOMATIC,SPI_CODE)hwUnitObj)
{
    Spi_StatusType     hwUnitStatus = SPI_UNINIT;
    if (NULL_PTR != hwUnitObj)
    {
        if (SPI_HW_UNIT_OK == hwUnitObj->hwUnitResult)
        {
            hwUnitStatus = SPI_IDLE;
        }
        else
        {
            hwUnitStatus = SPI_BUSY;
        }
    }
    return hwUnitStatus;
}

FUNC(void, SPI_CODE) Spi_PrivProcessTxEvent(VAR(uint32,AUTOMATIC)baseAddr,P2VAR(Spi_ChannelObjType,AUTOMATIC,SPI_CODE)chObj,
             VAR(uint16,AUTOMATIC)txIntrStatus)
{
    uint32 numWordsToWrite = 0;
    uint8 txFifoStatus;
    uint16 availableTxFIFO = 0;
    if (chObj->numWordsTxRx > chObj->curTxWords)
    {
        txFifoStatus = ((txIntrStatus & SPI_FFTX_TXFFST_M) >> SPI_FFTX_TXFFST_S);
        if((SPI_FIFO_TX_FIFO_DEPTH - 1U) > txFifoStatus){
            availableTxFIFO = (uint16)(SPI_FIFO_TX_FIFO_DEPTH - 1U) - txFifoStatus;
        }
        numWordsToWrite = ((uint32)chObj->numWordsTxRx - chObj->curTxWords);
        /* If remaining no of words is greater than available FIFO, Limit words to available size */
        if (numWordsToWrite > availableTxFIFO)
        {
            /* Limit words to available size */
            numWordsToWrite = availableTxFIFO;
        }
        Spi_WriteFifo(chObj, baseAddr, numWordsToWrite,chObj->curTxWords);
    }
    return;
}

FUNC(void, SPI_CODE) Spi_PrivJobCopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj, \
                           P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    uint32              index;
    Spi_JobObjType     *jobObj;
    for (index = ((uint32) 0U); index < cfgPtr->maxJobs; index++)
    {
        jobObj = &drvObj->jobObj[index];
        jobObj->jobCfg = &cfgPtr->jobCfg[index];

        jobObj->hwUnitObj = Spi_GetHwUnitObj(jobObj->jobCfg->hwUnitId);
        jobObj->extDevCfg =
            &drvObj->extDevCfg[jobObj->jobCfg->externalDeviceCfgId];
    }
    return;
}
FUNC(void, SPI_CODE) Spi_PrivSeqCopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj, \
                           P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    uint32              index;
    for (index = ((uint32) 0U); index < cfgPtr->maxSeq; index++)
    {
        drvObj->seqObj[index].seqCfg = &cfgPtr->seqCfg[index];
    }
    return;
}
FUNC(void, SPI_CODE) Spi_PrivChannelCopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj, \
                           P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    uint32              index ;
    Spi_ChannelObjType *chObj;
    for (index = ((uint32) 0U); index < cfgPtr->maxChannels; index++)
    {
        chObj = &drvObj->channelObj[index];
        chObj->chCfg = &cfgPtr->channelCfg[index];


        if (chObj->chCfg->dataWidth < SPI_8BIT_BUFFER_LIMIT)
        {
            chObj->bufWidth = ((uint8) SPI_8BIT_BUFFER);
        }
        else
        {
            chObj->bufWidth = ((uint8) SPI_16BIT_BUFFER);
        }
        drvObj->channelObj[index].effTxFifoDepth = ((uint16) 16U);
        /* Incase of IB, the numWordsTxRx is same as maxBufLength */
        if (((uint8) SPI_IB) == chObj->chCfg->channelBufType)
        {
            chObj->numWordsTxRx = chObj->chCfg->maxBufLength;
        }
        /* Calculate data width mask depending on SPI word size */
        chObj->dataWidthBitMask = Spi_GetDataWidthBitMask(
                                        (uint8) chObj->chCfg->dataWidth);
    }
    return;
}
FUNC(void, SPI_CODE) Spi_PrivHWUnitCopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj, \
                           P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    uint32              index;
    for (index = ((uint32) 0U); index < cfgPtr->maxHwUnit; index++)
    {
        drvObj->hwUnitObj[index].hwUnitCfg = &cfgPtr->hwUnitCfg[index];
        /* Init current job to invalid job id */
        drvObj->hwUnitObj[index].curConfiguredJobId = (Spi_JobType) drvObj->maxJobs;
    }
    return;
}
FUNC(void, SPI_CODE) Spi_PrivExtDevCopyConfig(P2VAR(Spi_DriverObjType,AUTOMATIC,SPI_CODE)drvObj, \
                           P2CONST(Spi_ConfigType,AUTOMATIC,SPI_CODE)cfgPtr)
{
    uint32              index ;
    for (index = ((uint32) 0U); index < cfgPtr->maxExtDevCfg; index++)
    {
        drvObj->extDevCfg[index].externalDeviceId = cfgPtr->extDevCfg[index].externalDeviceId;
        drvObj->extDevCfg[index].csEnable = cfgPtr->extDevCfg[index].csEnable;
        drvObj->extDevCfg[index].csPolarity = cfgPtr->extDevCfg[index].csPolarity;
        drvObj->extDevCfg[index].clkDivider = cfgPtr->extDevCfg[index].clkDivider;
        drvObj->extDevCfg[index].clkMode = cfgPtr->extDevCfg[index].clkMode;
        drvObj->extDevCfg[index].wordDelay = cfgPtr->extDevCfg[index].wordDelay;  
    }
    return;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Spi_Priv.c
 *********************************************************************************************************************/
