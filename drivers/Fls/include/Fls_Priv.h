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
 *  \file       Fls_Priv.h
 *  Generator:  None
 *
 *  \brief Description:  This file contains common declarations and macros used across all the FLS
 *MCAL driver files.
 *********************************************************************************************************************/

#ifndef FLS_PRIV_H_
#define FLS_PRIV_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls_Ac.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief Job result: flash compare found a data mismatch */
#define E_COMPARE_MISMATCH (2U)
/** \brief Job result: blank check found a non-erased word */
#define E_BLANKCHECK_MISMATCH (3U)

/** \brief Erase FSM stage: default/idle, no erase job active */
#define FLS_S_EDEFAULT (0U)
/** \brief Erase FSM stage: waiting for flash FSM ready before issuing erase command */
#define FLS_S_ERASE_PRECHECK (1U)
/** \brief Erase/write FSM stage: configuring CMDWEPROTA/B sector-unlock registers */
#define FLS_DO_SECTOR_UNLOCK (2U)
/** \brief Erase FSM stage: erase command issued, waiting for FSM completion */
#define FLS_DO_ERASE_JOB (3U)
/** \brief Erase FSM stage: erase done, running post-erase blank check */
#define FLS_S_ERASE_POSTCHECK (4U)

/** \brief Erase FSM sub-state: check flash FSM is ready before issuing command */
#define FLS_ERASE_FSM_READY_CHECK (0U)
/** \brief Erase FSM sub-state: issue the erase command to the flash FSM */
#define FLS_ERASE_FSM_ISSUE_CMD (1U)
/** \brief Erase FSM sub-state: poll flash FSM status for command completion */
#define FLS_ERASE_FSM_STATUS_CHECK (2U)
/** \brief Erase FSM sub-state: clear flash FSM status register after completion */
#define FLS_STATUS_CLEAR_CHECK (3U)
/** \brief Erase FSM sub-state: verify erase command result */
#define FLS_ERASE_CMD_CHECK (4U)

/** \brief Write FSM sub-state: check flash FSM is ready before issuing command */
#define FLS_WRITE_FSM_READY_CHECK (0U)
/** \brief Write FSM sub-state: issue the programming command to the flash FSM */
#define FLS_WRITE_FSM_ISSUE_CMD (1U)
/** \brief Write FSM sub-state: poll flash FSM status for command completion */
#define FLS_WRITE_FSM_STATUS_CHECK (2U)
/** \brief Write FSM sub-state: verify programming command result */
#define FLS_WRITE_CMD_CHECK (4U)

/** \brief Write FSM stage: default/idle, no write job active */
#define FLS_S_WDEFAULT (0U)
/** \brief Write FSM stage: pre-write blank check, waiting for flash FSM ready */
#define FLS_S_WRITE_PRECHECK (1U)
/** \brief Write FSM stage: programming command issued, waiting for FSM completion */
#define FLS_DO_WRITE_JOB (3U)
/** \brief Write FSM stage: write done, running post-write verify compare */
#define FLS_S_WRITE_POSTCHECK (4U)

/** \brief Divisor to convert a frequency value in Hz to MHz */
#define FLS_CONV_TO_MHZ (1000000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief ENUM for job type names */
typedef enum
{
    FLS_JOB_NONE       = 0U, /*!< \brief  Job type none */
    FLS_JOB_COMPARE    = 1U, /*!< \brief  Job type compare */
    FLS_JOB_ERASE      = 2U, /*!< \brief  Job type erase */
    FLS_JOB_READ       = 3U, /*!< \brief  Job type read */
    FLS_JOB_WRITE      = 4U, /*!< \brief  Job type write */
    FLS_JOB_BLANKCHECK = 5U  /*!< \brief  Job type blank check */
} Fls_JobType;

/**
 * \brief FLS Driver Object, global information used by module.
 */
typedef struct
{
    Fls_JobEndNotifyType   Fls_JobEndNotification;
    /** \brief Mapped to the job end notification routine provided by some upper layer
     *      module, typically the Fee module. */
    Fls_JobErrorNotifyType Fls_JobErrorNotification;
    /** \brief Mapped to the job error notification routine provided by some upper layer
     *      module, typically the Fee module. */
    uint32                 FlsMaxReadFastMode;
    /** \brief The maximum number of bytes to read or compare in one cycle of the
     *      flash driver's job processing function in Fast mode. */
    uint32                 FlsMaxWriteFastMode;
    /** \brief The maximum number of bytes to write in one cycle of the
     *      flash driver's job processing function in Fast mode. */
    uint32                 FlsMaxReadNormalMode;
    /** \brief The maximum number of bytes to read or compare in one cycle of the
     *      flash driver's job processing function in normal mode. */
    uint32                 FlsMaxWriteNormalMode;
    /** \brief The maximum number of bytes to write in one cycle of the
     *      flash driver's job processing function in normal mode. */
    Fls_SectorType         sectorList[FLS_NUMBER_OF_SECTOR_CFG];
    /** \brief Array of sector configuration entries describing the flash layout. */
    MemIf_StatusType       status;
    /** \brief Current Module Status update variable */
    MemIf_JobResultType    jobResultType;
    /** \brief Current Job Result update variable */
    Fls_JobType            jobType;
    /** \brief Current running job type */
    Fls_AddressType        flashAddr;
    /** \brief Flash Address for the current job */
    uint8                 *ramAddr;
    /** \brief Ram Address pointer for the current job */
    Fls_LengthType         length;
    /** \brief Data transfer length for the current job */
    MemIf_ModeType         mode;
    /** \brief Module mode setup for current job - SLOW for now */
    uint32                 jobChunkSize;
    /** \brief Length of Data to be transfer in current call cycle */
    Fls_EraseType          typeoferase;
    /** \brief To select the type of erase (sector erase/ block erase/ bulk erase) */
    uint32                 writePostFapiFsmBusy;
    /** \brief Set to 1 while the write FSM is in POSTCHECK and the FSM is still busy (not yet done);
     *         0 otherwise. Reset to 0 when a new write job is accepted. */
    uint32                 writeChunkComplete;
    /** \brief Set to 1 when POSTCHECK STATUS_CHECK confirms the programming command completed
     *         successfully for the current chunk; gates the write-verify compare in
     *         Fls_Process_JobWrite. Reset to 0 at the start of each Fls_F29AsyncWrite call
     *         and when a new write job is accepted. */
    uint32                 erasePostFapiFsmDone;
    /** \brief Set to 1 once the erase FSM status check confirms the sector/bank erase completed
     *         successfully; gates the post-erase blank check. Reset to 0 at the start of each
     *         erase sub-function call and when a new erase job is accepted. */
    volatile uint8         sectorEraseStage;
    /** \brief Sector erase FSM stage variable. Reset to FLS_S_EDEFAULT when a new erase job is
     *         accepted; sectorErasePreCheck and sectorErasePostCheck are reset directly in
     *         Fls_Erase() rather than via the EDEFAULT detection in Fls_F29AsyncSectorErase. */
    volatile uint16        sectorErasePreCheck;
    /** \brief Sector erase pre-check sub-state FSM counter. Reset to FLS_ERASE_FSM_READY_CHECK
     *         when a new erase job is accepted. */
    volatile uint16        sectorErasePostCheck;
    /** \brief Sector erase post-check sub-state FSM counter. Reset to FLS_ERASE_FSM_READY_CHECK
     *         when a new erase job is accepted. */
    volatile uint8         bankEraseStage;
    /** \brief Bank erase FSM stage variable. Reset to FLS_S_EDEFAULT when a new erase job is
     *         accepted; bankErasePreCheck and bankErasePostCheck are reset directly in
     *         Fls_Erase() rather than via the EDEFAULT detection in Fls_F29AsyncBankErase. */
    volatile uint16        bankErasePreCheck;
    /** \brief Bank erase pre-check sub-state FSM counter. Reset to FLS_ERASE_FSM_READY_CHECK
     *         when a new erase job is accepted. */
    volatile uint16        bankErasePostCheck;
    /** \brief Bank erase post-check sub-state FSM counter. Reset to FLS_ERASE_FSM_READY_CHECK
     *         when a new erase job is accepted. */
    volatile uint8         flashWriteStage;
    /** \brief Write FSM stage variable. Reset to FLS_S_WDEFAULT when a new write job is accepted;
     *         writePreCheck and writePostCheck are reset directly in Fls_Write() rather than
     *         via the WDEFAULT detection in Fls_F29AsyncWrite. */
    volatile uint16        writePreCheck;
    /** \brief Write pre-check sub-state FSM counter. Reset to FLS_WRITE_FSM_READY_CHECK
     *         when a new write job is accepted. */
    volatile uint16        writePostCheck;
    /** \brief Write post-check sub-state FSM counter. Reset to FLS_WRITE_FSM_READY_CHECK
     *         when a new write job is accepted. */
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    McalLib_TickType jobStartCount;
    /** \brief Counter value captured when the job was accepted, for cumulative timeout tracking */
#endif
    uint32 cmdWeProtAMask;
    /** \brief Write/erase protection mask for flash sectors 0-31 (CMDWEPROTA), captured at init */
    uint32 cmdWeProtBMask;
    /** \brief Write/erase protection mask for flash sectors 32-255 (CMDWEPROTB), captured at init */
} Fls_DriverObjType;

/** \brief ENUM for Internal State type names */
typedef enum
{
    FLS_INTERNAL_JOB_WAIT  = 0U, /*!< \brief  Job state wait */
    FLS_INTERNAL_JOB_FAIL  = 1U, /*!< \brief  Job state fail */
    FLS_INTERNAL_JOB_DONE  = 2U, /*!< \brief  Job state done */
    FLS_INTERNAL_JOB_READY = 3U, /*!< \brief  Job state ready */
    FLS_INTERNAL_JOB_BUSY  = 4U  /*!< \brief  Job state busy */
} Fls_InternalStateType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/**
 * \brief FLS Driver Object instance
 */
extern Fls_DriverObjType Fls_DrvObj;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief This function invoke Fls_F29Compare,Fls_F29BankErase,Fls_F29SectorErase,Fls_F29ChipErase,
 *  Fls_F29Read,Fls_F29Write and Fls_F29BlankCheck function. it will perform any one
 *  function based on job type
 * \param[in] job job type to perform operation
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_processJob(Fls_JobType job);

/** \brief Reset driver parameters during initialize time
 * \param[in] drvObj Input configuration parameters
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_resetDrvObj(Fls_DriverObjType *drvObj);

/** \brief Configuration parameters are copied to drvObj,this function included with Fls_init
 * \param[in] drvObj configuration parameters are copied to this object
 * \param[in] cfgPtr Input configuration parameters
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_copyConfig(Fls_DriverObjType *drvObj, const Fls_ConfigType *cfgPtr);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /** #ifndef FLS_PRIV_H_ */

/*********************************************************************************************************************
 *  End of File: Fls_Priv.h
 *********************************************************************************************************************/
