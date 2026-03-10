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
 *  \file       Fls_Priv.c
 *
 *  \brief Description:  This file contains FLS MCAL driver internal functions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls.h"
#include "Fls_Priv.h"
#include "Det.h"
#include "SchM_Fls.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

VAR(uint32, AUTOMATIC) Fls_U32FlsWrite_PostFapiFsmReady         = (uint32)0U; /* FSM ready flag*/
VAR(uint32, AUTOMATIC) Fls_SectorBankErase_PostFapiFsmReadyDone = (uint32)0U; /* erase done flag*/

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

VAR(uint32, FLS_VAR_INIT_32) Fls_CMD_WE_Protection_A_Mask = 0x00000000; /* protect reg A */
VAR(uint32, FLS_VAR_INIT_32) Fls_CMD_WE_Protection_B_Mask = 0x00000000; /* Register B */

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
VAR(StatusType, AUTOMATIC) counterStatus = E_NOT_OK;
#endif

volatile VAR(uint8, FLS_VAR_INIT_32) Fls_U8SectorEraseStage = FLS_S_EDEFAULT; /* sector Erase stage*/
volatile VAR(uint8, FLS_VAR_INIT_32) Fls_U8BankEraseStage   = FLS_S_EDEFAULT; /* bank erase stage*/
volatile VAR(uint8, FLS_VAR_INIT_32) Fls_U8FlashWriteStage  = FLS_S_WDEFAULT; /* flash program stage*/

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static FUNC(void, FLS_CODE) Fls_PostProcessAndReportError(uint8 ApiId, uint8 processFailureType);
static FUNC(void, FLS_CODE) Fls_PostProcessAndInitiateNextJob(Fls_JobType processJobCheck, uint32 processChunkSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncWrite_sub(uint32 actualSize);
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncWrite(uint32 actualSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_Callf29Erase(uint32 actualChunkSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncSectorErase(uint32 actualChunkSize);
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncSectorErase_sub(uint32 actualChunkSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncBankErase(uint32 actualChunkSize);
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncBankErase_sub(uint32 actualChunkSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29Read(uint32 actualChunkSize);
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29Compare(uint32 actualChunkSize);
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29BlankCheck(uint32 actualChunkSize);

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
static FUNC(Std_ReturnType, FLS_CODE) Fls_TimeoutVerification(McalLib_TickType startCount);
#endif

/* This checking function might be used in the future release */
/* static FUNC(Std_ReturnType, FLS_CODE) Fls_FindSectorConfig(Fls_AddressType addr);*/

static FUNC(void, FLS_CODE) Fls_Process_JobErase(uint32 chunkSize);
static FUNC(void, FLS_CODE) Fls_Process_JobWrite(uint32 chunkSize);
static FUNC(void, FLS_CODE) Fls_Process_JobRead(uint32 chunkSize);
static FUNC(void, FLS_CODE) Fls_Process_JobCompare(uint32 chunkSize);
static FUNC(void, FLS_CODE) Fls_Process_JobBlankCheck(uint32 chunkSize);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
static FUNC(Std_ReturnType, FLS_CODE) Fls_TimeoutVerification(McalLib_TickType startCount)
{
    VAR(McalLib_TickType, AUTOMATIC) tempCount    = (McalLib_TickType)0U;
    VAR(McalLib_TickType, AUTOMATIC) elapsedCount = (McalLib_TickType)0U;
    VAR(Std_ReturnType, AUTOMATIC) timeoutCheck   = E_OK;

    VAR(McalLib_TickType, AUTOMATIC) time1 = (McalLib_TickType)0U;

    tempCount = startCount;
    (void)McalLib_GetElapsedValue(&tempCount, &elapsedCount);

    if (Fls_DrvObj.jobType == FLS_JOB_ERASE)
    {
        if (Fls_DrvObj.typeoferase == FLS_SECTOR_ERASE)
        {
            /* We have max sector erase time, so we are multiplying it with CPU clock and also
                with number of sectors in one bank to get max number of cycles in order to
                compare with run time cycles FLS_MAX_ERASE_TIME: sector erase time in us time1:
                clock cycles of sector erase
            */
            time1 = FLS_MAX_ERASE_TIME * (FLS_CPU_CLOCK_FREQ / FLS_CONV_TO_MHZ);
        }
        else
        {
            /* Based on F28H5x device datasheet, the bank erase takes 40% more than sector
                erase: 1003ms vs 1410ms
            */
            time1 = (FLS_MAX_ERASE_TIME * 2U) * (FLS_CPU_CLOCK_FREQ / FLS_CONV_TO_MHZ);
        }
    }
    else
    {
        time1 = FLS_MAX_WRITE_TIME * (FLS_CPU_CLOCK_FREQ / FLS_CONV_TO_MHZ);
    }

    if (elapsedCount > time1)
    {
        timeoutCheck = E_NOT_OK;
    }

    return timeoutCheck;
}
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

/* API for post processing which checks whether the job has competed or initiate global variables
    for next chunk of operation
*/
static FUNC(void, FLS_CODE) Fls_PostProcessAndInitiateNextJob(Fls_JobType processJobCheck, uint32 processChunkSize)
{
    if (processJobCheck != FLS_JOB_NONE)
    {
        if (Fls_DrvObj.status != MEMIF_BUSY_INTERNAL)
        {
            Fls_DrvObj.ramAddr    = &Fls_DrvObj.ramAddr[processChunkSize];
            Fls_DrvObj.flashAddr += processChunkSize;
            Fls_DrvObj.length    -= processChunkSize;
        }
        if (Fls_DrvObj.status == MEMIF_BUSY_INTERNAL) /* MEMIF_BUSY_INTERNAL: 03*/
        {
            Fls_DrvObj.status = MEMIF_BUSY; /* MEMIF_BUSY: 02*/
        }

        if (0U == Fls_DrvObj.length)
        {
            Fls_DrvObj.jobResultType = MEMIF_JOB_OK; /* The job has been finished successfully */
            Fls_DrvObj.status        = MEMIF_IDLE;
            Fls_DrvObj.jobType       = FLS_JOB_NONE;
            if (Fls_DrvObj.Fls_JobEndNotification != NULL_PTR)
            {
                Fls_DrvObj.Fls_JobEndNotification();
            }
        }
    }
}

/* API used to post process and report errors
 * Design: MCAL-30899,
 */
static FUNC(void, FLS_CODE) Fls_PostProcessAndReportError(uint8 ApiId, uint8 processFailureType)
{
    Fls_DrvObj.status  = MEMIF_IDLE;
    Fls_DrvObj.jobType = FLS_JOB_NONE;
    if ((processFailureType == FLS_E_VERIFY_WRITE_FAILED) || (processFailureType == FLS_E_COMPARE_FAILED))
    {
        Fls_DrvObj.jobResultType = MEMIF_BLOCK_INCONSISTENT;
    }
    else
    {
        Fls_DrvObj.jobResultType = MEMIF_JOB_FAILED;
    }

    if ((processFailureType == FLS_E_VERIFY_WRITE_FAILED) || (processFailureType == FLS_E_COMPARE_FAILED) ||
        (processFailureType == FLS_E_TIMEOUT))
    {
        (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, ApiId, processFailureType);
    }
    else
    {
        (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, ApiId, processFailureType);
    }

    if (Fls_DrvObj.Fls_JobErrorNotification != NULL_PTR)
    {
        Fls_DrvObj.Fls_JobErrorNotification();
    }
}

/*
 *  Function Name: Fls_processJobs
 *
 *  This function invoke Fls_F29Compare,Fls_F29BankErase,Fls_F29SectorErase,Fls_F29ChipErase,
 *  Fls_F29Read,Fls_F29Write and Fls_F29BlankCheck function. it will perform any one
 *  function based on jobtype
 */
FUNC(void, FLS_CODE) Fls_processJobs(Fls_JobType job)
{
    VAR(uint32, AUTOMATIC) chunkSize = (uint32)0U;

    /* Get the MIN of two*/
    if (Fls_DrvObj.length < Fls_DrvObj.jobChunkSize)
    {
        chunkSize = Fls_DrvObj.length;
    }
    else
    {
        chunkSize = Fls_DrvObj.jobChunkSize;
    }
    switch (job)
    {
        case FLS_JOB_COMPARE:
            Fls_Process_JobCompare(chunkSize);
            break;
        case FLS_JOB_ERASE:
            Fls_Process_JobErase(chunkSize);
            break;
        case FLS_JOB_READ:
            Fls_Process_JobRead(chunkSize);
            break;
        case FLS_JOB_WRITE:
            Fls_Process_JobWrite(chunkSize);
            break;
        case FLS_JOB_BLANKCHECK:
            Fls_Process_JobBlankCheck(chunkSize);
            break;
        default:
            break;
    }
}

static FUNC(void, FLS_CODE) Fls_Process_JobBlankCheck(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    retVal = Fls_F29BlankCheck(chunkSize);

    if (retVal == E_OK)
    {
        Fls_PostProcessAndInitiateNextJob(FLS_JOB_BLANKCHECK, chunkSize);
    }
    else
    {
        failureType = FLS_E_BLANK_CHECK_FAILED; /* FLS_E_BLANK_CHECK_FAILED =0xB*/
        Fls_PostProcessAndReportError((uint8)FLS_SID_BLANK_CHECK, failureType);
    }
}

/*
 * Design: MCAL-30909,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobCompare(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    retVal = Fls_F29Compare(chunkSize);

    if (retVal == E_OK)
    {
        Fls_PostProcessAndInitiateNextJob(FLS_JOB_COMPARE, chunkSize);
    }
    else
    {
        failureType = FLS_E_COMPARE_FAILED; /* FLS_E_COMPARE_FAILED = 0x04*/
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
}

/*
 * Design: MCAL-30908,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobRead(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    retVal = Fls_F29Read(chunkSize);
    /* Post process and initiating next job or error flagging is done
        only for read memory here
    */
    if (retVal == E_OK)
    {
        Fls_PostProcessAndInitiateNextJob(FLS_JOB_READ, chunkSize);
    }
    else
    {
        failureType = FLS_E_READ_FAILED;
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
}

/*
 * Design: MCAL-30903, MCAL-30905, MCAL-30906,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobErase(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    /* To claim the flash semaphore */
    Fls_SSU_claimFlashSemaphore();

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    VAR(McalLib_TickType, AUTOMATIC) CurrentCount = 0U;
    (void)McalLib_GetCounterValue(&CurrentCount);
#endif

    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();
    retVal = Fls_Callf29Erase(chunkSize);
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();

    if (retVal == E_NOT_OK)
    {
        /* To release the Flash semaphore if erase operation failed*/
        Fls_SSU_releaseFlashSemaphore();
        failureType = FLS_E_ERASE_FAILED; /* FLS_E_ERASE_FAILED=0x1*/
    }
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    else
    {
        /*  Below API can change start time, so use temp variable */
        if (Fls_TimeoutVerification(CurrentCount) == E_NOT_OK)
        {
            retVal      = E_NOT_OK;
            failureType = FLS_E_TIMEOUT; /* FLS_E_TIMEOUT = 0x9*/
        }
    }
#endif

    /* After execution of an erase job, the flash driver shall verify that the addressed
        block has been erased completely.
        This feature shall be statically configurable (on/off).
    */
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)
    if (retVal == E_OK)
    {
        /* Erase chunk size would be one sector (2048 bytes) but blank check chunk size
         *  would be 8 bytes, so running blank check command for (2048/8) times
         */
        if (Fls_SectorBankErase_PostFapiFsmReadyDone == 0x1U)
        {
            /* To release the Flash semaphore after the sector/bank is erased correctly*/
            Fls_SSU_releaseFlashSemaphore();
            retVal = Fls_F29BlankCheck(chunkSize);
            if (retVal != E_OK)
            {
                failureType = FLS_E_VERIFY_ERASE_FAILED; /** FLS_E_VERIFY_ERASE_FAILED=0x7*/
            }
        }
    }
#endif
    if (retVal == E_OK)
    {
        Fls_PostProcessAndInitiateNextJob(FLS_JOB_ERASE, chunkSize);
    }
    else
    {
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
}

/*
 * Design: MCAL-30904, MCAL-30905, MCAL-30907,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobWrite(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    /* To claim the flash semaphore */
    Fls_SSU_claimFlashSemaphore();

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    VAR(McalLib_TickType, AUTOMATIC) CurrentCount = 0U;
#endif

    /* Before writing data to flash memory, the flash driver shall verify if the addressed
     *  memory area has been erased.
     *  If the memory is not erased, the processing of the write function shall be
     *  aborted with an error notification.
     *  This feature shall be statically configurable (on/off)
     *
     *  SRS_Fls_12158
     */
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)
    /* When postFapiFsmReady=1, the data has been programmed to flash, but FSM is still busy*/
    if (Fls_U32FlsWrite_PostFapiFsmReady != 0x1U)
    {
        retVal = Fls_F29BlankCheck(chunkSize);
        if (retVal != E_OK)
        {
            failureType = FLS_E_VERIFY_ERASE_FAILED; /* FLS_E_VERIFY_ERASE_FAILED=0x7*/
        }
    }
#endif

    /* Get the current counter value and store it into global variable */
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    (void)McalLib_GetCounterValue(&CurrentCount);
#endif

    if (retVal == E_OK)
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();
        retVal = Fls_F29AsyncWrite(chunkSize);
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();
    }
    if (retVal == E_NOT_OK)
    {
        failureType = FLS_E_WRITE_FAILED; /* FLS_E_WRITE_FAILED=0x2*/
    }
    else
    {
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        if (Fls_TimeoutVerification(CurrentCount) == E_NOT_OK)
        {
            retVal      = E_NOT_OK;
            failureType = FLS_E_TIMEOUT; /* FLS_E_TIMEOUT = 0x9*/
        }
#endif
    }
    /* The flash driver shall verify written data by reading back from flash and
     *  comparing with the source data after each write access.
     *  Differences shall be notified as error.
     *  The checking shall be done within the processing of the write function.
     *
     *  This feature shall be statically configurable (on/off).
     *
     *  SRS_Fls_12141
     */
#if (STD_ON == FLS_WRITE_VERIFICATION_ENABLED)
    if (retVal == E_OK)
    {
        retVal = Fls_F29Compare(chunkSize);
    }
    if (retVal == E_COMPARE_MISMATCH)
    {
        failureType = FLS_E_VERIFY_WRITE_FAILED; /* FLS_E_VERIFY_WRITE_FAILED =0x8*/
    }
#endif

    if ((retVal == E_OK) && (Fls_DrvObj.length <= chunkSize))
    {
        /* To release the Flash semaphore*/
        Fls_SSU_releaseFlashSemaphore();
    }

    if (retVal == E_OK)
    {
        Fls_PostProcessAndInitiateNextJob(FLS_JOB_WRITE, chunkSize);
    }
    else
    {
        /* To release the Flash semaphore if erase operation failed*/
        Fls_SSU_releaseFlashSemaphore();
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
}
/*
 *  Function Name: Fls_F29Compare
 *  This function Compares flash memory, if any mismatch return E_NOT_OK
 *  Design: MCAL-30897,
 *  SRS_Fls_13301
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29Compare(uint32 actualChunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) oReturnCheck;
    VAR(Fls_FlashStatusWordType, AUTOMATIC) oFlashStatusWord;

    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;

    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CheckValueBuffer = Fls_DrvObj.ramAddr;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32StartAddress   = (uint32 *)Fls_DrvObj.flashAddr;

    /*  compare data. since the minimum number of byte to program is 8 bytes. I change to 4
     *   bytes compare: Fls_Fapi_doVerify()
     *   VAR(uint32, AUTOMATIC)u32Length  = actualChunkSize;
     *   P2CONST(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CheckValueBuffer = (uint8 *)
     * *Fls_DrvObj.ramAddr; P2CONST(uint8, AUTOMATIC, FLS_APPL_DATA) pu8StartAddress  = (uint8 *)
     * Fls_DrvObj.flashAddr; oReturnCheck = Fls_Fapi_doVerifyByByte((uint8 *)pu8StartAddress,
     * u32Length, (uint8 *)pu8CheckValueBuffer, &oFlashStatusWord);
     */

    oReturnCheck = Fls_Fapi_doVerifyByByte((uint8 *)pu32StartAddress, actualChunkSize, (uint8 *)pu8CheckValueBuffer,
                                           &oFlashStatusWord);

    if (oReturnCheck != E_OK)
    {
        retVal = E_COMPARE_MISMATCH; /*E_NOT_OK;*/
    }
    else
    {
        retVal = E_OK;
    }
    return retVal;
}

/*
 *  Function Name: Fls_F29BlankCheck
 *  Fls_F29BlankCheck shall verify, whether a given memory area has been
 *  erased
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29BlankCheck(uint32 actualChunkSize)
{
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32StartAddress = (uint32 *)Fls_DrvObj.flashAddr;
    VAR(Fls_FlashStatusWordType, AUTOMATIC) oFlashStatusWord;
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(Std_ReturnType, AUTOMATIC) oReturnCheck;

    VAR(uint32, AUTOMATIC) u32Length = actualChunkSize / 4U; /* bytes --> 32-bit words*/

    oReturnCheck = Fls_Fapi_doBlankCheck((uint32 *)pu32StartAddress, u32Length, &oFlashStatusWord);

    if (oReturnCheck != E_OK)
    {
        retVal = E_BLANKCHECK_MISMATCH; /* E_NOT_OK*/
    }

    return retVal;
}

/* This function is to check if the address is the range of sectorList. It might be used by user
static FUNC(Std_ReturnType, FLS_CODE) Fls_FindSectorConfig(Fls_AddressType addr)
{
    VAR(uint32, AUTOMATIC)i = (uint32)0U;
    VAR(Fls_AddressType, AUTOMATIC)sectorStartAddr = (Fls_AddressType)0U;
    VAR(Fls_LengthType, AUTOMATIC)sectorSize = (Fls_LengthType)0U;
    VAR(Fls_LengthType, AUTOMATIC)numOfSectors = (Fls_LengthType)0U;
    VAR(Std_ReturnType, AUTOMATIC)retVal =  E_NOT_OK;

    for (i = 0U; i < FLS_NUMBER_OF_SECTOR_CFG; i++)
    {
        sectorStartAddr = Fls_DrvObj.sectorList[i].sectorStartAddress;
        sectorSize = Fls_DrvObj.sectorList[i].sectorSize;
        numOfSectors = Fls_DrvObj.sectorList[i].numberOfSectors;

        if ((addr >= sectorStartAddr)
            && (addr < (sectorStartAddr + (numOfSectors * sectorSize))))
        {
            retVal = E_OK;
            break;
        }
    }
    return retVal;
}
*/

/*
 *   Function Name: Fls_F29Read
 *   This function read flash memory
 *   SRS_Fls_12134
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29Read(uint32 actualChunkSize)
{
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA)
    src = (uint8 *)Fls_DrvObj.flashAddr; /* if read 32-bit word, use uint32* */
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA)
    dest                                         = (uint8 *)Fls_DrvObj.ramAddr; /* if read 32-bit word, use uint32* */
    VAR(uint32, AUTOMATIC) length                = (uint32)0U;
    VAR(Std_ReturnType, AUTOMATIC) retVal        = E_OK;
    VAR(volatile uint32, AUTOMATIC) u32DummyRead = 0U;

    /* Checking if the address is located in the sectors defined in sector list is not in FLS spec*/
    /*Addr_Valid = Fls_FindSectorConfig(Fls_DrvObj.flashAddr);*/

    length = actualChunkSize; /* if read by 32-bit word, length should be / 4 */

    /* FRI-4 flush pipeline, dummy read */
    u32DummyRead = *((volatile uint32 *)0x10C00000U);
    u32DummyRead = *((volatile uint32 *)0x10C00200U);
    u32DummyRead = *((volatile uint32 *)0x10C00400U);
    u32DummyRead = 0U;

    while (length > 0U)
    {
        *dest = *src; /* read by byte*/
        src++;
        dest++;
        length = length - 1U;
    }
    retVal = (Std_ReturnType)u32DummyRead;
    return (retVal);
}

/*
 *   Function Name: Fls_F29AsyncWrite
 *   Function to perform write to flash
 *   RS_Fls_12135
 */
static Std_ReturnType Fls_F29AsyncWrite(uint32 actualChunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;

    /* Check if the address is in the range of sectorList defined in Fls_Cfg.c
     * Fls_FindSectorConfig() always returns E_OK since checking sectorList is not
     * required
     */

    if (Fls_U8FlashWriteStage == FLS_S_WDEFAULT)
    {
        Fls_U8FlashWriteStage = FLS_S_WRITE_PRECHECK; /*  FLS_S_WRITE_PRECHECK=0x1 */
    }

    retVal = Fls_F29AsyncWrite_sub(actualChunkSize);

    return retVal;
}

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncWrite_sub(uint32 actualSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;

    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus = MEMIF_BUSY;

    VAR(uint32, AUTOMATIC) u32StartAddress     = Fls_DrvObj.flashAddr;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) buf = Fls_DrvObj.ramAddr;

    /* Fls_DrvObj.FlsMaxWriteNormalMode should be 8 or 16*/
    VAR(uint8, AUTOMATIC) DataBufSizeInBytes = Fls_DrvObj.FlsMaxWriteNormalMode;

    static uint16 pre_write_check    = FLS_WRITE_FSM_READY_CHECK;
    static uint16 post_write_check   = FLS_WRITE_FSM_READY_CHECK;
    Fls_U32FlsWrite_PostFapiFsmReady = 0U;

    if (Fls_U8FlashWriteStage == FLS_S_WRITE_PRECHECK)
    {
        if (pre_write_check == FLS_WRITE_FSM_READY_CHECK)
        {
            if (Fls_Fapi_checkFsmForReady() == E_OK)
            {
                pre_write_check = FLS_WRITE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Flash driver is busy with Internal management
                                                    operations*/
            }
        }
        if (pre_write_check == FLS_WRITE_FSM_ISSUE_CMD)
        {
            pre_write_check = FLS_WRITE_FSM_STATUS_CHECK;
            Fls_Fapi_issueAsyncCommand();
        }
        if (pre_write_check == FLS_WRITE_FSM_STATUS_CHECK)
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            if (oFlashStatus == 0x0U) /* FLS_FAPI_STATUS_SUCCESS*/
            {
                Fls_U8FlashWriteStage = FLS_DO_SECTOR_UNLOCK;
                pre_write_check       = FLS_WRITE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_U8FlashWriteStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_CMD_WE_Protection_A_Mask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_CMD_WE_Protection_B_Mask);
        Fls_U8FlashWriteStage = FLS_DO_WRITE_JOB;
    }
    if (Fls_U8FlashWriteStage == FLS_DO_WRITE_JOB)
    {
        /* DataBufSizeInBytes can be 8 or 16. ALl other values are not allowed */
        Fls_Fapi_issueProgrammingCommand((uint32 *)u32StartAddress, (uint8 *)buf, (uint8)DataBufSizeInBytes);

        Fls_U8FlashWriteStage = FLS_S_WRITE_POSTCHECK;
        post_write_check      = FLS_WRITE_FSM_READY_CHECK;
    }
    if (Fls_U8FlashWriteStage == FLS_S_WRITE_POSTCHECK)
    {
        if (post_write_check == FLS_WRITE_FSM_READY_CHECK)
        {
            retVal = Fls_Fapi_checkFsmForReady();
            if (retVal != E_NOT_OK)
            {
                post_write_check = FLS_WRITE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do noting or wait for a while*/
                fsmStatus                        = MEMIF_BUSY_INTERNAL;
                Fls_U32FlsWrite_PostFapiFsmReady = 0x1U;
                retVal                           = E_OK;
            }
        }
        if (post_write_check == FLS_WRITE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            if (retFsmStatus != 0x3U)
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                = E_OK;
                Fls_U8FlashWriteStage = FLS_S_WRITE_PRECHECK;
            }
        }
    }
    if (fsmStatus == MEMIF_BUSY_INTERNAL)
    {
        Fls_DrvObj.status = MEMIF_BUSY_INTERNAL;
    }
    return retVal;
}

/*
 *   Function Name: Fls_Callf29Erase
 *   This function Erase a sector from flash
 *   SRS_Fls_12136
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_Callf29Erase(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_NOT_OK;

    if (Fls_U8SectorEraseStage == FLS_S_EDEFAULT)
    {
        Fls_U8SectorEraseStage = FLS_S_ERASE_PRECHECK;
    }
    else
    {
        Fls_U8SectorEraseStage = Fls_U8SectorEraseStage;
    }
    if (Fls_U8BankEraseStage == FLS_S_EDEFAULT)
    {
        Fls_U8BankEraseStage = FLS_S_ERASE_PRECHECK;
    }
    else
    {
        Fls_U8BankEraseStage = Fls_U8BankEraseStage;
    }

    if (Fls_DrvObj.typeoferase == FLS_SECTOR_ERASE)
    {
        retVal = Fls_F29AsyncSectorErase(chunkSize);
    }
    else
    {
        retVal = Fls_F29AsyncBankErase(chunkSize);
    }

    return retVal;
}

/*
 *   Function Name: Fls_F29AsyncSectorErase
 *   Function to perform sector erase in the flash
 */
static Std_ReturnType Fls_F29AsyncSectorErase(uint32 actualChunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;

    if (actualChunkSize == 0U)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        retVal = Fls_F29AsyncSectorErase_sub(actualChunkSize);
    }
    return retVal;
}

/*
 *   Function Name: Fls_F29AsyncBankErase
 *   Function to perform bank erase in the flash
 */
static Std_ReturnType Fls_F29AsyncBankErase(uint32 actualChunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;

    if (actualChunkSize == 0U)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        retVal = Fls_F29AsyncBankErase_sub(actualChunkSize);
    }
    return retVal;
}

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncSectorErase_sub(uint32 actualSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus       = MEMIF_BUSY;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;

    VAR(uint32, AUTOMATIC) u32StartAddress   = Fls_DrvObj.flashAddr;
    Fls_SectorBankErase_PostFapiFsmReadyDone = 0U;

    static uint16 pre_check_sub_function  = FLS_ERASE_FSM_READY_CHECK;
    static uint16 post_check_sub_function = FLS_ERASE_FSM_READY_CHECK;

    if (Fls_U8SectorEraseStage == FLS_S_ERASE_PRECHECK) /* FLS_S_ERASE_PRECHECK=1*/
    {
        if (pre_check_sub_function == FLS_ERASE_FSM_READY_CHECK)
        {
            /* FSM is ready to accept new command*/
            retVal = Fls_Fapi_checkFsmForReady();

            if (retVal == E_OK)
            {
                pre_check_sub_function = FLS_ERASE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Next step is to return to mainFunction()*/
                retVal    = E_OK;
            }
        }
        if (pre_check_sub_function == FLS_ERASE_FSM_ISSUE_CMD)
        {
            Fls_Fapi_issueAsyncCommand();
            pre_check_sub_function = FLS_ERASE_FSM_STATUS_CHECK; /**  next is FSM status checking*/
        }
        if (pre_check_sub_function == FLS_ERASE_FSM_STATUS_CHECK)
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            if (oFlashStatus == 0x0U)
            {
                Fls_U8SectorEraseStage = FLS_DO_SECTOR_UNLOCK;
                pre_check_sub_function = FLS_ERASE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_U8SectorEraseStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_CMD_WE_Protection_A_Mask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_CMD_WE_Protection_B_Mask);

        Fls_U8SectorEraseStage = FLS_DO_ERASE_JOB;
    }
    if (Fls_U8SectorEraseStage == FLS_DO_ERASE_JOB)
    {
        Fls_Fapi_issueAsyncCommandWithAddress((uint32 *)u32StartAddress);
        Fls_U8SectorEraseStage  = FLS_S_ERASE_POSTCHECK;
        post_check_sub_function = FLS_ERASE_FSM_READY_CHECK;
    }
    if (Fls_U8SectorEraseStage == FLS_S_ERASE_POSTCHECK)
    {
        if (post_check_sub_function == FLS_ERASE_FSM_READY_CHECK)
        {
            retVal = Fls_Fapi_checkFsmForReady();
            if (retVal == E_OK)
            {
                post_check_sub_function = FLS_ERASE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do noting or wait for a while*/
                fsmStatus = MEMIF_BUSY_INTERNAL;
                retVal    = E_OK;
            }
        }
        if (post_check_sub_function == FLS_ERASE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            if (retFsmStatus != 0x3U)
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                                   = E_OK;
                Fls_U8SectorEraseStage                   = FLS_S_ERASE_PRECHECK;
                Fls_SectorBankErase_PostFapiFsmReadyDone = 0x1U;
            }
        }
    }
    if (fsmStatus == MEMIF_BUSY_INTERNAL)
    {
        Fls_DrvObj.status = MEMIF_BUSY_INTERNAL;
    }
    return retVal;
}

/* Function for Flash Bank Erase*/
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncBankErase_sub(uint32 actualSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus       = MEMIF_BUSY;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;
    Fls_SectorBankErase_PostFapiFsmReadyDone         = 0U;

    VAR(uint32, AUTOMATIC) u32StartAddress = Fls_DrvObj.flashAddr;

    static uint16 pre_bank_erase_check  = FLS_ERASE_FSM_READY_CHECK;
    static uint16 post_bank_erase_check = FLS_ERASE_FSM_READY_CHECK;

    if (Fls_U8BankEraseStage == FLS_S_ERASE_PRECHECK) /* FLS_S_ERASE_PRECHECK=1*/
    {
        if (pre_bank_erase_check == FLS_ERASE_FSM_READY_CHECK)
        {
            /* FSM is ready to accept new command*/
            retVal = Fls_Fapi_checkFsmForReady(); /* return FapiFlashStatus */

            if (retVal == E_OK)
            {
                pre_bank_erase_check = FLS_ERASE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Next step is to return to mainFunction()*/
                retVal    = E_OK;
            }
        }
        if (pre_bank_erase_check == FLS_ERASE_FSM_ISSUE_CMD)
        {
            Fls_Fapi_issueAsyncCommand();
            pre_bank_erase_check = FLS_ERASE_FSM_STATUS_CHECK; /* next is FSM status checking*/
        }
        if (pre_bank_erase_check == FLS_ERASE_FSM_STATUS_CHECK)
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            if (oFlashStatus == 0x0U)
            {
                Fls_U8BankEraseStage = FLS_DO_SECTOR_UNLOCK;
                pre_bank_erase_check = FLS_ERASE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_U8BankEraseStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_CMD_WE_Protection_A_Mask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_CMD_WE_Protection_B_Mask);

        Fls_U8BankEraseStage = FLS_DO_ERASE_JOB;
    }

    if (Fls_U8BankEraseStage == FLS_DO_ERASE_JOB)
    {
        Fls_Fapi_issueBankEraseCommand((uint32 *)(u32StartAddress));
        Fls_U8BankEraseStage  = FLS_S_ERASE_POSTCHECK;
        post_bank_erase_check = FLS_ERASE_FSM_READY_CHECK;
    }
    if (Fls_U8BankEraseStage == FLS_S_ERASE_POSTCHECK)
    {
        if (post_bank_erase_check == FLS_ERASE_FSM_READY_CHECK)
        {
            retVal = Fls_Fapi_checkFsmForReady();

            if (retVal == E_OK)
            {
                post_bank_erase_check = FLS_ERASE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do noting or wait for a while*/
                fsmStatus = MEMIF_BUSY_INTERNAL;
                retVal    = E_OK;
            }
        }
        if (post_bank_erase_check == FLS_ERASE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            if (retFsmStatus != 0x3U)
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                                   = E_OK;
                Fls_SectorBankErase_PostFapiFsmReadyDone = 0x1U;
                Fls_U8BankEraseStage                     = FLS_S_ERASE_PRECHECK;
            }
        }
    }
    if (fsmStatus == MEMIF_BUSY_INTERNAL)
    {
        Fls_DrvObj.status = MEMIF_BUSY_INTERNAL;
    }
    return retVal;
}

/*
 *   Function Name: Fls_copyConfig
 *   Configuration parameters are copying to drvObj,
 *   this function included with Fls_init
 */
FUNC(void, FLS_CODE) Fls_copyConfig(Fls_DriverObjType *drvObj, const Fls_ConfigType *cfgPtr)
{
    VAR(uint8, AUTOMATIC) sectorcfg_index = (uint8)0U;

    drvObj->Fls_JobEndNotification   = cfgPtr->Fls_JobEndNotification;
    drvObj->Fls_JobErrorNotification = cfgPtr->Fls_JobErrorNotification;
    drvObj->FlsMaxReadNormalMode     = cfgPtr->FlsMaxReadNormalMode;
    drvObj->FlsMaxWriteNormalMode    = cfgPtr->FlsMaxWriteNormalMode;
    while (sectorcfg_index < FLS_NUMBER_OF_SECTOR_CFG)
    {
        drvObj->sectorList[sectorcfg_index] = cfgPtr->sectorList[sectorcfg_index];
        sectorcfg_index++;
    }
}
/*
 *   Function Name: Fls_resetDrvObj
 *   All Driver parameter's reseting during initialize time.
 */
FUNC(void, FLS_CODE) Fls_resetDrvObj(Fls_DriverObjType *drvObj)
{
    drvObj->Fls_JobEndNotification   = NULL;
    drvObj->Fls_JobErrorNotification = NULL;
    drvObj->FlsMaxReadNormalMode     = 0x0;
    drvObj->FlsMaxWriteNormalMode    = 0x0;
    drvObj->status                   = MEMIF_UNINIT;
    drvObj->jobResultType            = MEMIF_JOB_OK;
    drvObj->jobType                  = FLS_JOB_NONE;
    drvObj->flashAddr                = 0x0;
    drvObj->ramAddr                  = NULL;
    drvObj->length                   = 0x0;
    drvObj->mode                     = MEMIF_MODE_SLOW;
    drvObj->jobChunkSize             = 0x0;
    drvObj->transferred              = 0x0;
    drvObj->typeoferase              = (Fls_EraseType)FLS_SECTOR_ERASE;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Fls_Priv.c
 *********************************************************************************************************************/
