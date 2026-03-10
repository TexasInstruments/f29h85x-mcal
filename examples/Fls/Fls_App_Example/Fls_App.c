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
 *  File:         Fls_App.c
 *  Generator:    None
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls_App.h"
#include "AppUtils.h"
#include "SchM_Fls.h"
#include "Fls_Ac.h"
#include "DeviceSupport.h"
#include "Std_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define APP_NAME       "FLS_APP"
#define DATA_SIZE_TEST 4096U
#define Debug_AppPrint
// #undef Debug_AppPrint
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
uint32 loopCount = 0; /**for debug*/
uint32 i         = 0;
/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
volatile uint32 Fls_JobDoneSuccess; /** success */
volatile uint32 Fls_JobDoneError;   /** failed flag */
uint32          Fls_errCnt  = 0x0U; /** error count */
uint32          Fls_passCnt = 0x0U; /** pass count */

/* Buffer containing the known data that needs to be written to flash */
uint8 txBuf_test[DATA_SIZE_TEST] = {0};

/* Buffer containing the received data */
uint8 rxBuf_test[DATA_SIZE_TEST] = {0};

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static void    FlsApp_PlatformInit(void);
Std_ReturnType FlsApp(void);

Std_ReturnType FlsApp_main_handling(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
static void FlsApp_PlatformInit(void)
{
    DeviceSupport_Init();
    Mcu_Init(&Mcu_Config_Mcu_ModuleConfiguration_0);

#if (STD_ON == MCU_CFG_INIT_CLOCK_API)
    /*Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_Osc2);*/
    (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_Osc2);

    while (MCU_PLL_LOCKED != Mcu_GetPllStatus()) /* Get PLL status and check */
    {
        /* Wait until all enabled PLLs are locked */
    }

#if (STD_OFF == MCU_CFG_NO_PLL)
    (void)Mcu_DistributePllClock();
#endif
#endif

    Os_StartOS(); /* Initializes Os stub */
    return;
}
/** main function */
int main(void)
{
    (void)FlsApp_PlatformInit();
    (void)FlsApp();

    return (0);
}

Std_ReturnType FlsApp(void)
{
    /* use if sector erase is to be selected*/
    uint32         Total_datasize;
    uint32         testSize   = DATA_SIZE_TEST; /* 4096 bytes*/
    uint32         testAddr   = 0x10C00000 - FLS_BASE_ADDRESS;
    uint32         testLength = DATA_SIZE_TEST;
    uint32         numOfSectorsOrBlocks;
    uint32         CfgSectorOrBlockSize;
    uint32         numofseccfg;
    Std_ReturnType job_accepted = E_OK;
    Std_ReturnType status;

    uint32          sectorStartAddr;
    uint32          offset;
    volatile uint32 idx;

#if (STD_ON == FLS_VERSION_INFO_API)
    Std_VersionInfoType VersionInfo;
#endif

#if (STD_ON == FLS_GET_JOB_RESULT_API)
    MemIf_JobResultType Result_type;
#endif
#if defined(Debug_AppPrint)
    Port_Init(&Port_Config);
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("FLS Example: Sample Application - STARTS !!!\n");
#endif
#if (STD_ON == FLS_PRE_COMPILE_VARIANT)
#if defined(Debug_AppPrint)
    AppUtils_Printf("APP_NAME : Variant - Pre Compile being used !!!\n\r");
#endif
    Fls_Init((const Fls_ConfigType *)NULL_PTR);
#else
#if defined(Debug_AppPrint)
    AppUtils_Printf("APP_NAME : Variant - Post Build being used !!!\n\r");
#endif
    Fls_Init(&Fls_Config);
#endif /* #if (STD_ON == FLS_PRE_COMPILE_VARIANT) */

#if (STD_ON == FLS_VERSION_INFO_API)
    (void)Fls_GetVersionInfo(&VersionInfo);
#if defined(Debug_AppPrint)
    AppUtils_Printf("FLS MCAL version info:%d.%d.%d\n\r", VersionInfo.sw_major_version, VersionInfo.sw_minor_version,
                    VersionInfo.sw_patch_version);
    AppUtils_Printf("FLS MCAL Module/Driver:%d.%d \n\r", VersionInfo.moduleID, VersionInfo.vendorID);
#endif
#endif /* #if (STD_ON == FLS_VERSION_INFO_API) */

/* FLS driver should be free now - check */
#if (STD_ON == FLS_GET_STATUS_API)
    MemIf_StatusType memStatus;
    memStatus = Fls_GetStatus();
    if (memStatus != MEMIF_IDLE)
    {
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": FLS driver is not IDLE!!\n\r");
#endif
    }
#endif /* #if ( STD_ON == FLS_GET_STATUS_API) */

    /********************************************************************************************************************************/
    /* Configuring writePtr with 0xBB and 0xAA alternatively and readPtr with zeroes */
    for (idx = 0U; idx < (testSize); idx += 2)
    {
        txBuf_test[idx]     = 0xAA;
        txBuf_test[idx + 1] = 0xBB;
        rxBuf_test[idx]     = 0x0;
        rxBuf_test[idx + 1] = 0x00;
    }
    /********************************************************************************************************************************/

    /********************************************************************************************************************************/

    for (loopCount = 0; loopCount < 500; loopCount++)
    {
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Configured operation on flash is from 0x%x address offset till %d bytes!!\n\r",
                        testAddr, testSize);
        AppUtils_Printf(APP_NAME ": Perform ERASE, WRITE, READ, BLANKCHECK, CANCEL, COMPARE, etc\n\r");
#endif

        /** The error count (Fls_errCnt) should be = loopCount. The error is intentionally injected
         */
        testAddr = testAddr + i * 4096; /** erase, write, read at differnt location*/
        i        = 1;
#ifdef BUILD_DEVICE_F29P32X
        if (testAddr > 0x1FFFF)
        {
            testAddr = 0;
            i        = 0;
        }
#else
        if (testAddr > 0x3FFFF)
        {
            testAddr = 0;
            i        = 0;
        }
#endif

        (void)Fls_SetEraseType(FLS_SECTOR_ERASE);

#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Sector Erasing \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Erase(testAddr, testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

/********************************************************************************************************************************/
#if (STD_ON == FLS_GET_JOB_RESULT_API)
        Result_type = Fls_GetJobResult();
        if (Result_type != MEMIF_JOB_OK)
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Get Job Result Failed, check done through Fls_GetJobResult API()\n\r");
#endif
        }
        else
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Get Job Result Passed, check done through Fls_GetJobResult API()\n\r");
#endif
        }
#endif /*( STD_ON == FLS_GET_JOB_RESULT_API)*/

        /********************************************************************************************************************************/

#if (STD_ON == FLS_BLANK_CHECK_API)
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Blank Checking \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_BlankCheck(testAddr, testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif /*STD_ON == FLS_BLANK_CHECK_API*/
/********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Writing 8-bytes, 16 bytes, 32 bytes, ... \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr, &txBuf_test[0], 8);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr, &txBuf_test[0], 8);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr + 0x20, &txBuf_test[0], 8);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr + 0x20, &txBuf_test[0], 8);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr + 0x40, &txBuf_test[0], 16);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr + 0x40, &txBuf_test[0], 16);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr + 0x80, &txBuf_test[0], 16);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr + 0x80, &txBuf_test[0], 16);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr + 0x100, &txBuf_test[0], 32);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr + 0x100, &txBuf_test[0], 32);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr + 0x140, &txBuf_test[0], 32);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if (STD_ON == FLS_COMPARE_API)
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr + 0x140, &txBuf_test[0], 32);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif

        /********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": erase 2 sectors\n\r");
#endif

        while (1U)
        {
            job_accepted = Fls_Erase(testAddr, testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Writing 2 sectors\n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr, &txBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Reading \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Read(testAddr, &rxBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

        /********************************************************************************************************************************/

#if (STD_ON == FLS_COMPARE_API)
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Write Compare \n\r");
#endif
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr, &txBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Read Compare \n\r");
#endif
        while (1U)
        {
            /*
            Check if the read operation was successful by comparing readBuf_test (previously read)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr, &rxBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif /*STD_ON == FLS_COMPARE_API*/

/********************************************************************************************************************************/

/********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Perform FLS_BANK_ERASE \n\r");
#endif
        (void)Fls_SetEraseType(FLS_BANK_ERASE);
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Bank Erasing \n\r");
#endif

        while (1U)
        {
            job_accepted = Fls_Erase(testAddr, FLS_SECTOR_SIZE);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

/********************************************************************************************************************************/
#if (STD_ON == FLS_GET_JOB_RESULT_API)
        Result_type = Fls_GetJobResult();
        if (Result_type != MEMIF_JOB_OK)
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Get Job Result Failed, check done through Fls_GetJobResult API()\n\r");
#endif
        }
        else
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Get Job Result Passed, check done through Fls_GetJobResult API()\n\r");
#endif
        }
#endif /*( STD_ON == FLS_GET_JOB_RESULT_API)*/

        /********************************************************************************************************************************/

#if (STD_ON == FLS_BLANK_CHECK_API)
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Blank Checking \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_BlankCheck(testAddr, testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif /*STD_ON == FLS_BLANK_CHECK_API*/

/********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Writing \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Write(testAddr, &txBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

/********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Reading \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Read(testAddr, &rxBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();

/********************************************************************************************************************************/
#if (STD_ON == FLS_COMPARE_API)
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Write Compare \n\r");
#endif
        while (1U)
        {
            /*
            Check if the write operation was successful by comparing writeBuf_test (hardcoded)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr, &txBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": Read Compare \n\r");
#endif
        while (1U)
        {
            /*
            Check if the read operation was successful by comparing readBuf_test (previously read)
            with the actual data in flash
            */
            job_accepted = Fls_Compare(testAddr, &rxBuf_test[0], testSize);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
        status = FlsApp_main_handling();
#endif /*STD_ON == FLS_COMPARE_API*/

        /********************************************************************************************************************************/

#if (STD_ON == FLS_CANCEL_API)
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": \n\r");
        AppUtils_Printf(APP_NAME ": Job Cancel \n\r");
        AppUtils_Printf(APP_NAME ": \t 1. Erasing \n\r");
#endif
        while (1U)
        {
            job_accepted = Fls_Erase(testAddr, testLength);
            if (E_OK == job_accepted)
            {
                break;
            }
        }
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": \t 2. Canceling \n\r");
#endif
        Fls_Cancel();
        if (Fls_JobDoneError == 1U)
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Job Canceled (SUCCESS) ! \n\r");
#endif
        }
        else
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Job completed (FAILED) !! \n\r");
#endif
        }

        Fls_JobDoneError = 0U;
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": \n\r");
#endif
#endif /*STD_ON == FLS_CANCEL_API*/

        for (numofseccfg = 0; numofseccfg < FLS_NUMBER_OF_SECTOR_CFG; numofseccfg++)
        {
            sectorStartAddr      = Fls_Config.sectorList[numofseccfg].sectorStartAddress;
            CfgSectorOrBlockSize = Fls_Config.sectorList[numofseccfg].sectorSize;
            numOfSectorsOrBlocks = Fls_Config.sectorList[numofseccfg].numberOfSectors;

            offset = sectorStartAddr - FLS_BASE_ADDRESS; /** sector start address in sector list is absolute address */

            Total_datasize = numOfSectorsOrBlocks * CfgSectorOrBlockSize;

            while (1U)
            {
                job_accepted = Fls_Read(offset, &rxBuf_test[0], Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            (void)Fls_SetEraseType(FLS_SECTOR_ERASE);
            while (1U)
            {
                job_accepted = Fls_Erase(offset, Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            while (1U)
            {
                job_accepted = Fls_BlankCheck(offset, Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            while (1U)
            {
                job_accepted = Fls_Write(offset, &txBuf_test[0], Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            (void)Fls_SetEraseType(FLS_BANK_ERASE);

            while (1U)
            {
                job_accepted = Fls_Erase(offset, Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            while (1U)
            {
                job_accepted = Fls_Write(offset, &txBuf_test[0], Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

            while (1U)
            {
                job_accepted = Fls_Read(offset, &rxBuf_test[0], Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();

#if (STD_ON == FLS_COMPARE_API)
            while (1U)
            {
                job_accepted = Fls_Compare(offset, &txBuf_test[0], Total_datasize);
                if (E_OK == job_accepted)
                {
                    break;
                }
            }
            status = FlsApp_main_handling();
#endif
        }

/********************************************************************************************************************************/
#if defined(Debug_AppPrint)
        AppUtils_Printf(APP_NAME ": \n\r");
        AppUtils_Printf(APP_NAME ": ---------- FLS Sample application Done !! ----------  \n\r");
        AppUtils_Printf(APP_NAME
                        ": Tests Passed: %d (wraps at 1000)   Tests Failed: %d (wraps at 1000, "
                        "1 expected per loop from Fls_Cancel)   Loop: %d \r\n",
                        Fls_passCnt, Fls_errCnt, loopCount);
        AppUtils_Printf(APP_NAME ": \n\r");
#endif
        /*Add breakpoint here, then check the error count in Fee_JobErrorNotification() at the end
         * of this file*/
        /*__asm(" NOP #8");*/
    }  // loop for debug use

#if defined(Debug_AppPrint)
    AppUtils_Printf(APP_NAME ": \n\r");
    AppUtils_Printf(APP_NAME ": ========== OVERALL TEST SUMMARY ==========\n\r");
    if (Fls_errCnt == loopCount)
    {
        AppUtils_Printf(APP_NAME ": OVERALL RESULT: PASS\n\r");
        AppUtils_Printf(APP_NAME ": Error count matches expected value (%d errors for %d iterations)\n\r", Fls_errCnt,
                        loopCount);
    }
    else
    {
        AppUtils_Printf(APP_NAME ": OVERALL RESULT: FAIL\n\r");
        AppUtils_Printf(APP_NAME ": Error count mismatch - Expected: %d, Actual: %d\n\r", loopCount, Fls_errCnt);
    }
    AppUtils_Printf(APP_NAME ": ===========================================\n\r");
    AppUtils_Printf(APP_NAME ": \n\r");
#endif

    return (status);
}

Std_ReturnType FlsApp_main_handling(void)
{
    Std_ReturnType retVal = E_OK;
#if defined(Debug_AppPrint)
    AppUtils_Printf(APP_NAME ": Job Processing in Progress.\n\r");
#endif
    while (1U)
    {
        Fls_MainFunction();
        if (Fls_JobDoneSuccess == 1U)
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Job Ends: SUCCESS \n\r");
#endif
            retVal = E_OK;
            break;
        }
        if (Fls_JobDoneError == 1U)
        {
#if defined(Debug_AppPrint)
            AppUtils_Printf(APP_NAME ": Job Ends: Error \n\r");
#endif
            retVal = E_NOT_OK;
            break;
        }
    }

    Fls_JobDoneSuccess = 0U;
    Fls_JobDoneError   = 0U;
    return retVal;
}

/**
void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0(void)
{
}

void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0(void)
{
}
*/

void Fee_JobEndNotification(void)
{
    Fls_JobDoneSuccess = 1U;
#if defined(Debug_AppPrint)
    AppUtils_Printf(APP_NAME ": Job Ends: SUCCESS\n\r");
#endif
    /*Fls_passCnt++;        */
    if (Fls_passCnt++ >= 1000U)
    {
        Fls_passCnt = 0;
    }
    else
    {
    }
}

void Fee_JobErrorNotification(void)
{
    Fls_JobDoneError = 1U;
#if defined(Debug_AppPrint)
    AppUtils_Printf(APP_NAME ": Job Ends: Error\n\r");
#endif
    /*Fls_errCnt++; */ /*one expected error from Fls_Cancel()*/
    if (Fls_errCnt++ >= 1000U)
    {
        Fls_errCnt = 0;
    }
    else
    {
    }
}

/*********************************************************************************************************************
 *  End of File: Fls_App.c
 *********************************************************************************************************************/
