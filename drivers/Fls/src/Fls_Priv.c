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

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static FUNC(void, FLS_CODE) Fls_PostProcessAndReportError(uint8 ApiId, uint8 processFailureType);
static FUNC(void, FLS_CODE) Fls_PostProcessAndInitiateNextJob(Fls_JobType processJobCheck, uint32 processChunkSize);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncWrite(void);

static FUNC(Std_ReturnType, FLS_CODE) Fls_Callf29Erase(void);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncSectorErase(void);

static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncBankErase(void);

static FUNC(void, FLS_CODE) Fls_F29Read(uint32 actualChunkSize);
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
/*
 *   Function Name: Fls_TimeoutVerification
 *   Checks whether elapsed time for the current job exceeds the configured maximum.
 *   Design: MCAL-30905, MCAL-31032, MCAL-31033, MCAL-31034, MCAL-31035,
 */
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

    /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] Hardware fault: elapsedCount exceeds
     * time1 (timeout occurred). In test hardware the flash FSM always completes within the
     * configured deadline, so the timeout branch is never taken. */
    if (elapsedCount > time1)
    {
        timeoutCheck = E_NOT_OK;
    }
    /* TI_COVERAGE_GAP_STOP */

    return timeoutCheck;
}
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

/* API for post processing which checks whether the job has competed or initiate global variables
    for next chunk of operation
 * Design: MCAL-31026, MCAL-31027, MCAL-31040, MCAL-31041, MCAL-31042,
*/
static FUNC(void, FLS_CODE) Fls_PostProcessAndInitiateNextJob(Fls_JobType processJobCheck, uint32 processChunkSize)
{
    /* TI_COVERAGE_GAP_START [Branch Coverage] Defensive coding: Fls_PostProcessAndInitiateNextJob()
     * is always called with a valid job type (FLS_JOB_WRITE, FLS_JOB_ERASE, FLS_JOB_BLANKCHECK,
     * or FLS_JOB_COMPARE). Passing FLS_JOB_NONE is a misuse of the internal API. */
    if (processJobCheck != FLS_JOB_NONE)
    /* TI_COVERAGE_GAP_STOP */
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
    /* TI_COVERAGE_GAP_START [MC/DC Coverage] Hardware fault: FLS_E_VERIFY_WRITE_FAILED is the
     * first operand of the || expression. For it to independently determine the outcome (True
     * while FLS_E_COMPARE_FAILED is False), a write-verify mismatch must occur without a compare
     * failure. This independent effect is not coverable by the existing test suite. */
    if ((processFailureType == FLS_E_VERIFY_WRITE_FAILED) || (processFailureType == FLS_E_COMPARE_FAILED))
    /* TI_COVERAGE_GAP_STOP */
    {
        Fls_DrvObj.jobResultType = MEMIF_BLOCK_INCONSISTENT;
    }
    else
    {
        Fls_DrvObj.jobResultType = MEMIF_JOB_FAILED;
    }

    /* TI_COVERAGE_GAP_START [MC/DC Coverage] Hardware fault: FLS_E_VERIFY_WRITE_FAILED is the
     * first operand of the || expression (with FLS_E_COMPARE_FAILED and FLS_E_TIMEOUT as
     * subsequent operands). For it to independently determine the outcome, a write-verify
     * mismatch without a compare failure or timeout must be injected. Not coverable. */
    if ((processFailureType == FLS_E_VERIFY_WRITE_FAILED) || (processFailureType == FLS_E_COMPARE_FAILED) ||
        (processFailureType == FLS_E_TIMEOUT))
    /* TI_COVERAGE_GAP_STOP */
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
 *  Function Name: Fls_processJob
 *
 *  This function invoke Fls_F29Compare,Fls_F29BankErase,Fls_F29SectorErase,Fls_F29ChipErase,
 *  Fls_F29Read,Fls_F29Write and Fls_F29BlankCheck function. it will perform any one
 *  function based on jobtype
 *  Design: MCAL-31013, MCAL-31015, MCAL-31031,
 */
FUNC(void, FLS_CODE) Fls_processJob(Fls_JobType job)
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
        /* TI_COVERAGE_GAP_START [Branch Coverage] Default case in the job-dispatch switch
         * inside Fls_DispatchAsyncOp(). The switch covers all valid AUTOSAR job types
         * (FLS_JOB_WRITE, FLS_JOB_ERASE, FLS_JOB_BLANKCHECK). Reaching default requires an
         * invalid jobType value, which cannot occur through the defined Fls API. */
        default:
            /* TI_COVERAGE_GAP_STOP */
            break;
    }
}

/*
 * Design: MCAL-30903, MCAL-31005, MCAL-31006,
 */
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
    /* Fls_F29Read is a direct memory copy (like memcpy) with no software-visible error return. */
    Fls_F29Read(chunkSize);
    Fls_PostProcessAndInitiateNextJob(FLS_JOB_READ, chunkSize);
}

/*
 * Design: MCAL-30903, MCAL-30905, MCAL-30906,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobErase(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    /* To claim the flash semaphore */
    retVal = Fls_SSU_claimFlashSemaphore();
    /* TI_COVERAGE_GAP_START [Branch Coverage] Semaphore claim by other CPU/LINK: Fls_SSU_claimFlashSemaphore() returns
     * E_NOT_OK only if another CPU or LINK holds the flash semaphore. This condition cannot occur in a single-CPU
     * validation environment. */
    if (retVal != E_OK)
    /* TI_COVERAGE_GAP_STOP */
    {
        failureType = FLS_E_ERASE_FAILED;
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
    else
    {
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        /* Capture the start time once per erase FSM operation. While polling POSTCHECK across multiple
         * Fls_MainFunction calls, both stage variables remain at FLS_S_ERASE_POSTCHECK so the start
         * time is preserved, giving a cumulative elapsed time for that single sector/bank erase cycle.
         */
        if ((Fls_DrvObj.sectorEraseStage != FLS_S_ERASE_POSTCHECK) &&
            (Fls_DrvObj.bankEraseStage != FLS_S_ERASE_POSTCHECK))
        {
            (void)McalLib_GetCounterValue(&Fls_DrvObj.jobStartCount);
        }
#endif

        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();
        retVal = Fls_Callf29Erase();
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();
        /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: Fls_Callf29Erase() returns E_NOT_OK, indicating the
         * sector erase command could not be issued to the flash controller. Requires a hardware fault (e.g., flash
         * controller unresponsive); not triggered in normal operation. */
        if (retVal == E_NOT_OK)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* To release the Flash semaphore if erase operation failed*/
            Fls_SSU_releaseFlashSemaphore();
            failureType = FLS_E_ERASE_FAILED; /* FLS_E_ERASE_FAILED=0x1*/
        }
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        else
        {
            /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] Hardware fault:
             * Fls_TimeoutVerification(Fls_DrvObj.jobStartCount) returns E_NOT_OK. Callf29Erase returned E_OK so the
             * early E_NOT_OK release block above was skipped. The verification block below is also skipped when retVal
             * is E_NOT_OK, so the semaphore must be released here before propagating the timeout failure. Requires a
             * hardware programming failure (e.g., over-programmed cell, ECC fault); not triggered in normal operation.
             */
            if (Fls_TimeoutVerification(Fls_DrvObj.jobStartCount) == E_NOT_OK)
            /* TI_COVERAGE_GAP_STOP */
            {
                /* Callf29Erase returned E_OK so the early E_NOT_OK release block above was skipped.
                 * The verification block below is also skipped when retVal is E_NOT_OK, so the
                 * semaphore must be released here before propagating the timeout failure.
                 */
                Fls_SSU_releaseFlashSemaphore();
                retVal      = E_NOT_OK;
                failureType = FLS_E_TIMEOUT; /* FLS_E_TIMEOUT = 0x9*/
            }
        }
#endif

        /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retVal != E_OK after Fls_Callf29Erase().
         * This occurs when the erase operation fails (FLS_E_ERASE_FAILED) or times out (FLS_E_TIMEOUT).
         * Both error conditions require hardware faults and are not triggered in normal operation. */
        if (retVal == E_OK)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* Erase chunk size would be one sector (2048 bytes) but blank check chunk size
             *  would be 8 bytes, so running blank check command for (2048/8) times
             */
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: Fls_DrvObj.erasePostFapiFsmDone != 0x1U.
             * This flag is set to 0x1U only when the FSM completes the erase operation successfully.
             * Requires a hardware programming failure; not triggered in normal operation. */
            if (Fls_DrvObj.erasePostFapiFsmDone == 0x1U)
            /* TI_COVERAGE_GAP_STOP */
            {
                /* To release the Flash semaphore after the sector/bank is erased correctly*/
                Fls_SSU_releaseFlashSemaphore();
                /* After execution of an erase job, the flash driver shall verify that the addressed
                 *  block has been erased completely.
                 *  This feature shall be statically configurable (on/off).
                 */
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)

                retVal = Fls_F29BlankCheck(chunkSize);
                /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: Fls_F29BlankCheck() returns E_NOT_OK after
                 * erase. Indicates blank-check verification failed (FLS_ERASE_VERIFICATION_ENABLED=STD_ON path).
                 * Requires a hardware erase failure; not triggered in normal operation. */
                if (retVal != E_OK)
                /* TI_COVERAGE_GAP_STOP */
                {
                    failureType = FLS_E_VERIFY_ERASE_FAILED; /** FLS_E_VERIFY_ERASE_FAILED=0x7*/
                }
#endif
            }
        }

        /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retVal != E_OK after blank check.
         * Occurs when blank-check verification fails (FLS_E_VERIFY_ERASE_FAILED) after a successful
         * erase operation. Requires a hardware erase failure; not triggered in normal operation. */
        if (retVal == E_OK)
        /* TI_COVERAGE_GAP_STOP */
        {
            Fls_PostProcessAndInitiateNextJob(FLS_JOB_ERASE, chunkSize);
        }
        else
        {
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: Fls_PostProcessAndInitiateNextJob()
             * not called due to job failure. This path is taken when retVal != E_OK after blank check
             * (FLS_E_VERIFY_ERASE_FAILED) or when the erase operation itself failed or timed out.
             * Requires hardware faults in erase or blank-check operations; not triggered in normal operation. */
            Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
            /* TI_COVERAGE_GAP_STOP */
        }
    } /* end else (semaphore claimed) */
}

/*
 * Design: MCAL-30904, MCAL-30905, MCAL-30907,
 */
static FUNC(void, FLS_CODE) Fls_Process_JobWrite(uint32 chunkSize)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;
    VAR(uint8, AUTOMATIC) failureType     = (uint8)0U;

    /* To claim the flash semaphore */
    retVal = Fls_SSU_claimFlashSemaphore();
    /* TI_COVERAGE_GAP_START [Branch Coverage] Semaphore claim by other CPU/LINK: Fls_SSU_claimFlashSemaphore() returns
     * E_NOT_OK only if another CPU or LINK holds the flash semaphore. This condition cannot occur in a single-CPU
     * validation environment. */
    if (retVal != E_OK)
    /* TI_COVERAGE_GAP_STOP */
    {
        failureType = FLS_E_WRITE_FAILED;
        Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
    }
    else
    {
        /* Before writing data to flash memory, the flash driver shall verify if the addressed
         *  memory area has been erased.
         *  If the memory is not erased, the processing of the write function shall be
         *  aborted with an error notification.
         *  This feature shall be statically configurable (on/off)
         *
         *  SRS_Fls_12158
         */
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        /* Capture the start time once per programming FSM operation. PostFapiFsmReady is 0 when
         * starting a new chunk and 1 while polling POSTCHECK, so the start time is preserved across
         * the polling calls, giving cumulative elapsed time for that single programming cycle.
         */
        if (Fls_DrvObj.writePostFapiFsmBusy != 0x1U)
        {
            (void)McalLib_GetCounterValue(&Fls_DrvObj.jobStartCount);
        }
#endif

#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)
        /* When writePostFapiFsmBusy=1, the data has been programmed to flash, but FSM is still busy*/
        if (Fls_DrvObj.writePostFapiFsmBusy != 0x1U)
        {
            retVal = Fls_F29BlankCheck(chunkSize);
            if (retVal != E_OK)
            {
                failureType = FLS_E_VERIFY_ERASE_FAILED; /* FLS_E_VERIFY_ERASE_FAILED=0x7*/
            }
        }
#endif

        if (retVal == E_OK)
        {
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();
            retVal = Fls_F29AsyncWrite();
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: Fls_F29AsyncWrite() returns E_NOT_OK, indicating the
         * write command could not be issued to the flash controller. Requires a hardware fault (e.g., write-protected
         * sector or flash controller error); not triggered in normal operation.*/
        if (retVal == E_NOT_OK)
        /* TI_COVERAGE_GAP_STOP */
        {
            failureType = FLS_E_WRITE_FAILED; /* FLS_E_WRITE_FAILED=0x2*/
        }
        else
        {
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            /* TI_COVERAGE_GAP_START [Line/Region/Branch Coverage] Hardware fault:
             * Fls_TimeoutVerification(Fls_DrvObj.jobStartCount) returns E_NOT_OK. */
            if (Fls_TimeoutVerification(Fls_DrvObj.jobStartCount) == E_NOT_OK)
            /* TI_COVERAGE_GAP_STOP */
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
        /* writeChunkComplete is set to 1 only when POSTCHECK STATUS_CHECK confirms the programming
         * command completed for the current chunk. Gating on this flag ensures the compare never
         * fires while the FSM is still busy (PRECHECK or POSTCHECK READY_CHECK polling), preventing
         * spurious FLS_E_VERIFY_WRITE_FAILED from reading mid-write or not-yet-written flash.
         */
        if ((retVal == E_OK) && (Fls_DrvObj.writeChunkComplete == 1U))
        {
            retVal = Fls_F29Compare(chunkSize);
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retVal == E_COMPARE_MISMATCH after write completion:
         * write-verify failure (FLS_WRITE_VERIFICATION_ENABLED=STD_ON). Not reachable in normal operation */
        if (retVal == E_COMPARE_MISMATCH)
        /* TI_COVERAGE_GAP_STOP */
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
            /* To release the Flash semaphore if write operation failed*/
            Fls_SSU_releaseFlashSemaphore();
            Fls_PostProcessAndReportError((uint8)FLS_SID_MAIN_FUNCTION, failureType);
        }
    } /* end else (semaphore claimed) */
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
 *  Design: MCAL-30903, MCAL-31000, MCAL-31006,
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
 *   Design: MCAL-30908, MCAL-30976,
 */
static FUNC(void, FLS_CODE) Fls_F29Read(uint32 actualChunkSize)
{
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA)
    src = (uint8 *)Fls_DrvObj.flashAddr;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA)
    dest                                         = (uint8 *)Fls_DrvObj.ramAddr;
    VAR(uint32, AUTOMATIC) length                = actualChunkSize;
    VAR(volatile uint32, AUTOMATIC) u32DummyRead = 0U;

    /* FRI-4 flush pipeline, dummy read */
    u32DummyRead = *((volatile uint32 *)0x10C00000U);
    u32DummyRead = *((volatile uint32 *)0x10C00200U);
    u32DummyRead = *((volatile uint32 *)0x10C00400U);
    (void)u32DummyRead; /* discard after pipeline flush, value is unused */

    while (length > 0U)
    {
        *dest = *src;
        src++;
        dest++;
        length = length - 1U;
    }
}

/*
 *   Function Name: Fls_F29AsyncWrite
 *   Function to perform write to flash
 *   SRS_Fls_12135
 *   Design: MCAL-30904, MCAL-30907,
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncWrite(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;

    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus = MEMIF_BUSY;

    VAR(uint32, AUTOMATIC) u32StartAddress     = Fls_DrvObj.flashAddr;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) buf = Fls_DrvObj.ramAddr;

    /* Fls_DrvObj.FlsMaxWriteNormalMode should be 8 or 16*/
    VAR(uint32, AUTOMATIC) DataBufSizeInBytes = Fls_DrvObj.FlsMaxWriteNormalMode;

    Fls_DrvObj.writePostFapiFsmBusy = 0U;
    Fls_DrvObj.writeChunkComplete   = 0U;

    /* Fls_Write() resets Fls_DrvObj.flashWriteStage to FLS_S_WDEFAULT when a new job is accepted
     * and directly resets writePreCheck and writePostCheck (Fls_DrvObj fields) to
     * FLS_WRITE_FSM_READY_CHECK. Detecting WDEFAULT here advances the stage to PRECHECK for
     * the new job.
     */
    if (Fls_DrvObj.flashWriteStage == FLS_S_WDEFAULT)
    {
        Fls_DrvObj.flashWriteStage = FLS_S_WRITE_PRECHECK;
    }

    if (Fls_DrvObj.flashWriteStage == FLS_S_WRITE_PRECHECK)
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: writePreCheck !=
         * FLS_WRITE_FSM_READY_CHECK when entering write PRECHECK. Only possible after a hardware FSM error in PRECHECK
         * STATUS_CHECK leaves the sub-state advanced. Flash FSM always succeeds during PRECHECK in test hardware.*/
        if (Fls_DrvObj.writePreCheck == FLS_WRITE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: Fls_Fapi_checkFsmForReady()
             * returns E_NOT_OK at write PRECHECK READY_CHECK: flash FSM is busy at the start of a new PRECHECK stage.
             * In test hardware, the flash FSM is always idle at PRECHECK entry.*/
            if (Fls_Fapi_checkFsmForReady() == E_OK)
            /* TI_COVERAGE_GAP_STOP */
            {
                Fls_DrvObj.writePreCheck = FLS_WRITE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Flash driver is busy with Internal management
                                                    operations*/
            }
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: writePreCheck !=
         * FLS_WRITE_FSM_ISSUE_CMD on sequential-if check within write PRECHECK. Not reached because the READY_CHECK
         * block always advances writePreCheck to ISSUE_CMD in the same MainFunction call.*/
        if (Fls_DrvObj.writePreCheck == FLS_WRITE_FSM_ISSUE_CMD)
        /* TI_COVERAGE_GAP_STOP */
        {
            Fls_DrvObj.writePreCheck = FLS_WRITE_FSM_STATUS_CHECK;
            Fls_Fapi_issueAsyncCommand();
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: writePreCheck !=
         * FLS_WRITE_FSM_STATUS_CHECK on sequential-if check within write PRECHECK. Not reached because the ISSUE_CMD
         * block always advances writePreCheck to STATUS_CHECK in the same MainFunction call.*/
        if (Fls_DrvObj.writePreCheck == FLS_WRITE_FSM_STATUS_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: oFlashStatus != 0x0 in write PRECHECK
             * STATUS_CHECK: flash FSM reported an error immediately after the sector-unlock command. Requires a
             * hardware fault in the flash pre-program setup sequence.*/
            if (oFlashStatus == 0x0U) /* FLS_FAPI_STATUS_SUCCESS*/
            /* TI_COVERAGE_GAP_STOP */
            {
                Fls_DrvObj.flashWriteStage = FLS_DO_SECTOR_UNLOCK;
                Fls_DrvObj.writePreCheck   = FLS_WRITE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_DrvObj.flashWriteStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_DrvObj.cmdWeProtAMask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_DrvObj.cmdWeProtBMask);
        Fls_DrvObj.flashWriteStage = FLS_DO_WRITE_JOB;
    }
    if (Fls_DrvObj.flashWriteStage == FLS_DO_WRITE_JOB)
    {
        /* DataBufSizeInBytes can be 8 or 16. ALl other values are not allowed */
        Fls_Fapi_issueProgrammingCommand((const uint32 *)u32StartAddress, (const uint8 *)buf, DataBufSizeInBytes);

        Fls_DrvObj.flashWriteStage = FLS_S_WRITE_POSTCHECK;
        Fls_DrvObj.writePostCheck  = FLS_WRITE_FSM_READY_CHECK;
    }
    /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: flashWriteStage != FLS_S_WRITE_POSTCHECK
     * when evaluated in Fls_F29AsyncWrite(). Since the flash FSM is always idle at PRECHECK entry, all PRECHECK
     * sub-states complete in one call, advancing flashWriteStage directly to POSTCHECK before this check is reached.*/
    if (Fls_DrvObj.flashWriteStage == FLS_S_WRITE_POSTCHECK)
    /* TI_COVERAGE_GAP_STOP */
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: writePostCheck !=
         * FLS_WRITE_FSM_READY_CHECK on entry to write POSTCHECK. Only occurs after a hardware FSM error at POSTCHECK
         * STATUS_CHECK leaves writePostCheck at STATUS_CHECK (see line 759).*/
        if (Fls_DrvObj.writePostCheck == FLS_WRITE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            retVal = Fls_Fapi_checkFsmForReady();
            if (retVal != E_NOT_OK)
            {
                Fls_DrvObj.writePostCheck = FLS_WRITE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do nothing or wait for a while*/
                fsmStatus                       = MEMIF_BUSY_INTERNAL;
                Fls_DrvObj.writePostFapiFsmBusy = 0x1U;
                retVal                          = E_OK;
            }
        }
        if (Fls_DrvObj.writePostCheck == FLS_WRITE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retFsmStatus != 0x3 in write POSTCHECK
             * STATUS_CHECK: flash FSM reported an error after the programming command. Requires a hardware programming
             * failure (e.g., over-programmed cell, ECC fault); not triggered in normal operation.*/
            if (retFsmStatus != 0x3U)
            /* TI_COVERAGE_GAP_STOP */
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                        = E_OK;
                Fls_DrvObj.flashWriteStage    = FLS_S_WRITE_PRECHECK;
                Fls_DrvObj.writeChunkComplete = 1U;
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
 *   This function Erase a sector or bank
 *   SRS_Fls_12136
 *   Design: MCAL-30906, MCAL-30931,
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_Callf29Erase(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_NOT_OK;
    if (Fls_DrvObj.typeoferase == FLS_SECTOR_ERASE)
    {
        retVal = Fls_F29AsyncSectorErase();
    }
    else if (Fls_DrvObj.typeoferase == FLS_BANK_ERASE)
    {
        retVal = Fls_F29AsyncBankErase();
    }
    /* Statically unreachable via normal code paths; retained as a defensive measure
     * against memory corruption or direct external writes to Fls_DrvObj.typeoferase. */
    else
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Defensive coding: typeoferase is neither FLS_SECTOR_ERASE nor
         * FLS_BANK_ERASE in Fls_Callf29Erase(). Statically unreachable: Fls_DrvObj.typeoferase is only ever set to
         * FLS_SECTOR_ERASE or FLS_BANK_ERASE by the driver. Source comment confirms it is retained as a defensive
         * measure against memory corruption.*/
        retVal = E_NOT_OK;
        /* TI_COVERAGE_GAP_STOP */
    }

    return retVal;
}

/*
 *   Function Name: Fls_F29AsyncSectorErase
 *   Issues sector erase command via FAPI and polls FSM for completion.
 *   Design: MCAL-30906, MCAL-30931,
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncSectorErase(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus       = MEMIF_BUSY;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;

    VAR(uint32, AUTOMATIC) u32StartAddress = Fls_DrvObj.flashAddr;
    Fls_DrvObj.erasePostFapiFsmDone        = 0U;

    /* Fls_Erase() resets Fls_DrvObj.sectorEraseStage to FLS_S_EDEFAULT when a new job is accepted
     * and directly resets sectorErasePreCheck and sectorErasePostCheck (Fls_DrvObj fields) to
     * FLS_ERASE_FSM_READY_CHECK. Detecting EDEFAULT here advances the stage to PRECHECK for
     * the new job.
     */
    if (Fls_DrvObj.sectorEraseStage == FLS_S_EDEFAULT)
    {
        Fls_DrvObj.sectorEraseStage = FLS_S_ERASE_PRECHECK;
    }

    if (Fls_DrvObj.sectorEraseStage == FLS_S_ERASE_PRECHECK) /* FLS_S_ERASE_PRECHECK=1*/
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: sectorErasePreCheck !=
         * FLS_ERASE_FSM_READY_CHECK when entering sector erase PRECHECK. Only possible after a hardware FSM error
         * leaves the sub-state advanced. Analogous to write PRECHECK */
        if (Fls_DrvObj.sectorErasePreCheck == FLS_ERASE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* FSM is ready to accept new command*/
            retVal = Fls_Fapi_checkFsmForReady();
            if (retVal == E_OK)
            {
                Fls_DrvObj.sectorErasePreCheck = FLS_ERASE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Next step is to return to mainFunction()*/
                retVal    = E_OK;
            }
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: sectorErasePreCheck !=
         * FLS_ERASE_FSM_ISSUE_CMD on sequential-if check within sector erase PRECHECK. READY_CHECK always advances the
         * sub-state to ISSUE_CMD in the same call.*/
        if (Fls_DrvObj.sectorErasePreCheck == FLS_ERASE_FSM_ISSUE_CMD)
        /* TI_COVERAGE_GAP_STOP */
        {
            Fls_Fapi_issueAsyncCommand();
            Fls_DrvObj.sectorErasePreCheck = FLS_ERASE_FSM_STATUS_CHECK; /**  next is FSM status checking*/
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: sectorErasePreCheck !=
         * FLS_ERASE_FSM_STATUS_CHECK on sequential-if check within sector erase PRECHECK. ISSUE_CMD always advances the
         * sub-state to STATUS_CHECK in the same call.*/
        if (Fls_DrvObj.sectorErasePreCheck == FLS_ERASE_FSM_STATUS_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: oFlashStatus != 0x0 in sector erase PRECHECK
             * STATUS_CHECK: flash FSM reported an error after the sector-unlock command. Requires a hardware fault in
             * the sector erase setup sequence.*/
            if (oFlashStatus == 0x0U)
            /* TI_COVERAGE_GAP_STOP */
            {
                Fls_DrvObj.sectorEraseStage    = FLS_DO_SECTOR_UNLOCK;
                Fls_DrvObj.sectorErasePreCheck = FLS_ERASE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_DrvObj.sectorEraseStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_DrvObj.cmdWeProtAMask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_DrvObj.cmdWeProtBMask);

        Fls_DrvObj.sectorEraseStage = FLS_DO_ERASE_JOB;
    }
    if (Fls_DrvObj.sectorEraseStage == FLS_DO_ERASE_JOB)
    {
        Fls_Fapi_issueAsyncCommandWithAddress((const uint32 *)u32StartAddress);
        Fls_DrvObj.sectorEraseStage     = FLS_S_ERASE_POSTCHECK;
        Fls_DrvObj.sectorErasePostCheck = FLS_ERASE_FSM_READY_CHECK;
    }
    /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: sectorEraseStage !=
     * FLS_S_ERASE_POSTCHECK when evaluated in Fls_F29AsyncSectorErase(). PRECHECK always completes all sub-states in
     * one call, advancing the stage directly to POSTCHECK before this check is reached.*/
    if (Fls_DrvObj.sectorEraseStage == FLS_S_ERASE_POSTCHECK)
    /* TI_COVERAGE_GAP_STOP */
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: sectorErasePostCheck !=
         * FLS_ERASE_FSM_READY_CHECK on entry to sector erase POSTCHECK. Only occurs after a hardware FSM error at
         * POSTCHECK STATUS_CHECK leaves the sub-state at STATUS_CHECK (see line 897).*/
        if (Fls_DrvObj.sectorErasePostCheck == FLS_ERASE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            retVal = Fls_Fapi_checkFsmForReady();
            if (retVal == E_OK)
            {
                Fls_DrvObj.sectorErasePostCheck = FLS_ERASE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do nothing or wait for a while*/
                fsmStatus = MEMIF_BUSY_INTERNAL;
                retVal    = E_OK;
            }
        }
        if (Fls_DrvObj.sectorErasePostCheck == FLS_ERASE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retFsmStatus != 0x3 in sector erase POSTCHECK
             * STATUS_CHECK: flash FSM reported an error after the erase command. Requires a hardware erase failure
             * (e.g., sector erase fault, ECC error); not triggered in normal operation.*/
            if (retFsmStatus != 0x3U)
            /* TI_COVERAGE_GAP_STOP */
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                          = E_OK;
                Fls_DrvObj.sectorEraseStage     = FLS_S_ERASE_PRECHECK;
                Fls_DrvObj.erasePostFapiFsmDone = 0x1U;
            }
        }
    }
    if (fsmStatus == MEMIF_BUSY_INTERNAL)
    {
        Fls_DrvObj.status = MEMIF_BUSY_INTERNAL;
    }
    return retVal;
}

/* Function for Flash Bank Erase
 * Design: MCAL-30906, MCAL-30931,
 */
static FUNC(Std_ReturnType, FLS_CODE) Fls_F29AsyncBankErase(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal            = E_OK;
    VAR(MemIf_StatusType, AUTOMATIC) fsmStatus       = MEMIF_BUSY;
    VAR(Fls_FapiFlashStatus, AUTOMATIC) oFlashStatus = 0U;
    Fls_DrvObj.erasePostFapiFsmDone                  = 0U;

    VAR(uint32, AUTOMATIC) u32StartAddress = Fls_DrvObj.flashAddr;

    /* Fls_Erase() resets Fls_DrvObj.bankEraseStage to FLS_S_EDEFAULT when a new job is accepted
     * and directly resets bankErasePreCheck and bankErasePostCheck (Fls_DrvObj fields) to
     * FLS_ERASE_FSM_READY_CHECK. Detecting EDEFAULT here advances the stage to PRECHECK for
     * the new job.
     */
    if (Fls_DrvObj.bankEraseStage == FLS_S_EDEFAULT)
    {
        Fls_DrvObj.bankEraseStage = FLS_S_ERASE_PRECHECK;
    }

    if (Fls_DrvObj.bankEraseStage == FLS_S_ERASE_PRECHECK) /* FLS_S_ERASE_PRECHECK=1*/
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: bankErasePreCheck !=
         * FLS_ERASE_FSM_READY_CHECK when entering bank erase PRECHECK. Only possible after a hardware FSM error leaves
         * the sub-state advanced. Analogous to sector erase PRECHECK (line 830).*/
        if (Fls_DrvObj.bankErasePreCheck == FLS_ERASE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* FSM is ready to accept new command*/
            retVal = Fls_Fapi_checkFsmForReady(); /* return FapiFlashStatus */
            /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: Fls_Fapi_checkFsmForReady()
             * returns E_NOT_OK at bank erase PRECHECK READY_CHECK: flash FSM is busy at PRECHECK entry. In test
             * hardware, the flash FSM is always idle at PRECHECK entry.*/
            if (retVal == E_OK)
            /* TI_COVERAGE_GAP_STOP */
            {
                Fls_DrvObj.bankErasePreCheck = FLS_ERASE_FSM_ISSUE_CMD;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL; /* Next step is to return to mainFunction()*/
                retVal    = E_OK;
            }
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: bankErasePreCheck !=
         * FLS_ERASE_FSM_ISSUE_CMD on sequential-if check within bank erase PRECHECK. READY_CHECK always advances the
         * sub-state to ISSUE_CMD in the same call.*/
        if (Fls_DrvObj.bankErasePreCheck == FLS_ERASE_FSM_ISSUE_CMD)
        /* TI_COVERAGE_GAP_STOP */
        {
            Fls_Fapi_issueAsyncCommand();
            Fls_DrvObj.bankErasePreCheck = FLS_ERASE_FSM_STATUS_CHECK; /* next is FSM status checking*/
        }
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: bankErasePreCheck !=
         * FLS_ERASE_FSM_STATUS_CHECK on sequential-if check within bank erase PRECHECK. ISSUE_CMD always advances the
         * sub-state to STATUS_CHECK in the same call.*/
        if (Fls_DrvObj.bankErasePreCheck == FLS_ERASE_FSM_STATUS_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            oFlashStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: oFlashStatus != 0x0 in bank erase PRECHECK
             * STATUS_CHECK: flash FSM reported an error after the bank-enable command. Requires a hardware fault in the
             * bank erase setup sequence.*/
            if (oFlashStatus == 0x0U)
            /* TI_COVERAGE_GAP_STOP */
            {
                Fls_DrvObj.bankEraseStage    = FLS_DO_SECTOR_UNLOCK;
                Fls_DrvObj.bankErasePreCheck = FLS_ERASE_FSM_READY_CHECK;
            }
            else
            {
                fsmStatus = MEMIF_BUSY_INTERNAL;
            }
        }
    }
    if (Fls_DrvObj.bankEraseStage == FLS_DO_SECTOR_UNLOCK)
    {
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTA, Fls_DrvObj.cmdWeProtAMask);
        Fls_Fapi_setupBankSectorEnable(FLS_FLASH_NW_O_CMDWEPROTB, Fls_DrvObj.cmdWeProtBMask);

        Fls_DrvObj.bankEraseStage = FLS_DO_ERASE_JOB;
    }

    if (Fls_DrvObj.bankEraseStage == FLS_DO_ERASE_JOB)
    {
        Fls_Fapi_issueBankEraseCommand((uint32 *)(u32StartAddress));
        Fls_DrvObj.bankEraseStage     = FLS_S_ERASE_POSTCHECK;
        Fls_DrvObj.bankErasePostCheck = FLS_ERASE_FSM_READY_CHECK;
    }
    /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: bankEraseStage != FLS_S_ERASE_POSTCHECK
     * when evaluated in Fls_F29AsyncBankErase(). PRECHECK always completes all sub-states in one call, advancing the
     * stage directly to POSTCHECK before this check is reached.*/
    if (Fls_DrvObj.bankEraseStage == FLS_S_ERASE_POSTCHECK)
    /* TI_COVERAGE_GAP_STOP */
    {
        /* TI_COVERAGE_GAP_START [Branch Coverage] Sequential state machine design: bankErasePostCheck !=
         * FLS_ERASE_FSM_READY_CHECK on entry to bank erase POSTCHECK. Only occurs after a hardware FSM error at
         * POSTCHECK STATUS_CHECK leaves the sub-state at STATUS_CHECK (see line 1007).*/
        if (Fls_DrvObj.bankErasePostCheck == FLS_ERASE_FSM_READY_CHECK)
        /* TI_COVERAGE_GAP_STOP */
        {
            retVal = Fls_Fapi_checkFsmForReady();

            if (retVal == E_OK)
            {
                Fls_DrvObj.bankErasePostCheck = FLS_ERASE_FSM_STATUS_CHECK;
            }
            else
            {
                /* Do nothing or wait for a while*/
                fsmStatus = MEMIF_BUSY_INTERNAL;
                retVal    = E_OK;
            }
        }
        if (Fls_DrvObj.bankErasePostCheck == FLS_ERASE_FSM_STATUS_CHECK)
        {
            /*  fsm status polling */
            Fls_FapiFlashStatus retFsmStatus = Fls_Fapi_getFsmStatus();
            /* TI_COVERAGE_GAP_START [Branch Coverage] Hardware fault: retFsmStatus != 0x3 in bank erase POSTCHECK
             * STATUS_CHECK: flash FSM reported an error after the bank erase command. Requires a hardware bank erase
             * failure; not triggered in normal operation.*/
            if (retFsmStatus != 0x3U)
            /* TI_COVERAGE_GAP_STOP */
            {
                retVal = E_NOT_OK;
            }
            else
            {
                retVal                          = E_OK;
                Fls_DrvObj.erasePostFapiFsmDone = 0x1U;
                Fls_DrvObj.bankEraseStage       = FLS_S_ERASE_PRECHECK;
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
 *   Design: MCAL-30923, MCAL-30924, MCAL-30925,
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
 *   Design: MCAL-30925, MCAL-30927, MCAL-30928,
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
    drvObj->typeoferase              = (Fls_EraseType)FLS_SECTOR_ERASE;
    drvObj->writePostFapiFsmBusy     = 0U;
    drvObj->writeChunkComplete       = 0U;
    drvObj->erasePostFapiFsmDone     = 0U;
    drvObj->sectorEraseStage         = (uint8)FLS_S_EDEFAULT;
    drvObj->sectorErasePreCheck      = FLS_ERASE_FSM_READY_CHECK;
    drvObj->sectorErasePostCheck     = FLS_ERASE_FSM_READY_CHECK;
    drvObj->bankEraseStage           = (uint8)FLS_S_EDEFAULT;
    drvObj->bankErasePreCheck        = FLS_ERASE_FSM_READY_CHECK;
    drvObj->bankErasePostCheck       = FLS_ERASE_FSM_READY_CHECK;
    drvObj->flashWriteStage          = (uint8)FLS_S_WDEFAULT;
    drvObj->writePreCheck            = FLS_WRITE_FSM_READY_CHECK;
    drvObj->writePostCheck           = FLS_WRITE_FSM_READY_CHECK;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Fls_Priv.c
 *********************************************************************************************************************/
