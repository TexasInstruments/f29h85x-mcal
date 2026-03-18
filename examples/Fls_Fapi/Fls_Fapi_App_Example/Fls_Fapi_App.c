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
 *  File:         Fls_Fapi_App.c
 *  Generator:    None
 *
 *  Description:  This example demonstrates integration of the standalone Flash API library with MCAL, with FLS
 *  chosen to illustrate the integration. The example performs Flash API library operations followed by FLS
 *  operations, followed once again by Flash API library operations on F29H85x.
 *  Integration of the Flash API library with MCAL involves 2 steps:
 *      1. Include the Flash API library (e.g. F29H85x_NWFlashAPI_v21.00.01.lib) in the project
 *      2. Include the header file FlashTech_F29H85x_C29x.h in the source file
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls_Fapi_App.h"
#include "AppUtils.h"
#include "SchM_Fls.h"
#include "Fls_Ac.h"
#include "DeviceSupport.h"
#include "Std_Types.h"

//
// Include Flash API include file
//
#include "FlashTech_F29H85x_C29x.h"

//
// Include Flash API example header file
//
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define APP_NAME       "FLS_FAPI_APP"
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

/*
 * Flash API configuration variables used by FlsApp_FapiFlashOperations()
 */
static Fapi_FlashBankType BankType           = C29Bank;
static Fapi_FOTAStatus    FOTAStatus         = Active_Bank;
uint32_t                  u32UserFlashConfig = 0U;

/* Length (in bytes) of data buffer used for Flash API program operations */
#define WORDS_IN_FLASH_BUFFER 0x200U

/* Data buffers used for program operation using the Flash API program function */
static uint8_t   Buffer[WORDS_IN_FLASH_BUFFER];
static uint32_t *Buffer32;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static void    FlsApp_PlatformInit(void);
Std_ReturnType FlsFapiApp(void);

Std_ReturnType FlsApp_main_handling(void);

/* Flash API example functions (ported from flash_mode0_128_program.c) */
static void Example_Error(Fapi_StatusType status);
static void FMSTAT_Fail(void);
static void ClearFSMStatus(uint32_t u32StartAddress, uint32_t u32UserFlashConfig);
static void Example_EraseBanks(void);
static void Example_EraseSector(void);
static void Example_ProgramUsingC29AutoECC(void);
static void Example_ProgramUsingDataAndECC(void);
static void Example_ProgramUsingDataOnlyECCOnly(void);
static void Example_ProgramDataFlashUsingC29AutoECC(void);
static void Example_CallFlashAPI(void);

static Std_ReturnType FlsApp_FapiFlashOperations(void);

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
    (void)FlsFapiApp();

    return (0);
}

/*********************************************************************************************************************
 *  Example_Error
 *
 *  Halts execution on a fatal Flash API error. Error code is in the status parameter.
 *********************************************************************************************************************/
static void Example_Error(Fapi_StatusType status)
{
    //
    // Error code will be in the status parameter
    //
    (void)status;
    asm(" EMUSTOP0");
    for (;;)
        ;
}

/*********************************************************************************************************************
 *  FMSTAT_Fail
 *
 *  Halts execution on an FMSTAT failure.
 *********************************************************************************************************************/
static void FMSTAT_Fail(void)
{
    asm(" EMUSTOP0");
    for (;;)
        ;
}

/*********************************************************************************************************************
 *  ClearFSMStatus
 *
 *  Clears the status (STATCMD) of the previous flash operation and waits until
 *  the FSM is ready. Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void ClearFSMStatus(uint32_t u32StartAddress,
                                                                   uint32_t u32UserFlashConfig)
{
    Fapi_FlashStatusType oFlashStatus;
    Fapi_StatusType      oReturnCheck;

    //
    // Wait until FSM is done with the previous flash operation
    //
    while (Fapi_checkFsmForReady(u32StartAddress, u32UserFlashConfig) != Fapi_Status_FsmReady)
        ;

    oFlashStatus = Fapi_getFsmStatus(u32StartAddress, u32UserFlashConfig);

    //
    // If the status register is nonzero, then clear it
    //
    if (oFlashStatus != 0)
    {
        //
        // Clear the status register
        //
        oReturnCheck = Fapi_issueAsyncCommand(u32StartAddress, u32UserFlashConfig, Fapi_ClearStatus);

        //
        // Wait until status is cleared
        //
        while (Fapi_getFsmStatus(u32StartAddress, u32UserFlashConfig) != 0)
        {
        }

        if (oReturnCheck != Fapi_Status_Success)
        {
            Example_Error(oReturnCheck);
        }
    }
}

/*********************************************************************************************************************
 *  Example_EraseBanks
 *
 *  Erases all Mode 0 interleaved banks (FR1RP1-FR1RP3) and the data flash bank (FR4RP0),
 *  then performs a blank check on each. Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_EraseBanks(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue Bank erase command
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR1RP1STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR1RP3ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        //
        // Loop for erasing 1 interleaved bank
        //
        for (uint32_t u8Iterator = 1; u8Iterator <= 2; u8Iterator++)
        {
            ClearFSMStatus(u32CurrentAddress, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)(u32CurrentAddress), u32UserFlashConfig,
                                       FLASH_NOWRAPPER_O_CMDWEPROTA, 0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)(u32CurrentAddress), u32UserFlashConfig,
                                       FLASH_NOWRAPPER_O_CMDWEPROTB, 0x00000000);

            //
            // Issue bank erase command
            //
            oReturnCheck = Fapi_issueBankEraseCommand((uint32_t *)(u32CurrentAddress), u8Iterator, u32UserFlashConfig);

            //
            // Wait until FSM is done with erase operation
            //
            while (Fapi_checkFsmForReady(u32CurrentAddress, u32UserFlashConfig) != Fapi_Status_FsmReady)
            {
            }

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // erase command to see if there are any erase operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32CurrentAddress, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }
        }

        //
        // Perform a blank check to ensure all sectors are erased
        //
        oReturnCheck = Fapi_doBlankCheck((uint32_t *)u32CurrentAddress, (256 * MainBankSector4KB_u32length),
                                         &oFlashStatusWord, 0, u32UserFlashConfig);

        if (oReturnCheck != Fapi_Status_Success)
        {
            Example_Error(oReturnCheck);
        }
    }

    //
    // Issue Bank erase command for Data Flash
    // No for loop here because data flash is not interleaved
    //
    ClearFSMStatus(C29FLASHBANKFR4RP0STARTADDRESS, u32UserFlashConfig);

    //
    // Set program/erase protection
    //
    Fapi_setupBankSectorEnable((uint32_t *)(C29FLASHBANKFR4RP0STARTADDRESS), u32UserFlashConfig,
                               FLASH_NOWRAPPER_O_CMDWEPROTA, 0x00000000);
    Fapi_setupBankSectorEnable((uint32_t *)(C29FLASHBANKFR4RP0STARTADDRESS), u32UserFlashConfig,
                               FLASH_NOWRAPPER_O_CMDWEPROTB, 0x00000000);

    //
    // Issue bank erase command
    //
    oReturnCheck = Fapi_issueBankEraseCommand((uint32_t *)(C29FLASHBANKFR4RP0STARTADDRESS), 0, u32UserFlashConfig);

    //
    // Wait until FSM is done with erase operation
    //
    while (Fapi_checkFsmForReady(C29FLASHBANKFR4RP0STARTADDRESS, u32UserFlashConfig) != Fapi_Status_FsmReady)
    {
    }

    if (oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }

    //
    // Read FMSTAT register contents to know the status of FSM after
    // erase command to see if there are any erase operation related errors
    //
    oFlashStatus = Fapi_getFsmStatus(C29FLASHBANKFR4RP0STARTADDRESS, u32UserFlashConfig);
    if (oFlashStatus != 3)
    {
        FMSTAT_Fail();
    }

    //
    // Perform a blank check to ensure all sectors are erased
    //
    oReturnCheck = Fapi_doBlankCheck((uint32_t *)C29FLASHBANKFR4RP0STARTADDRESS, (128 * DataBankSector2KB_u32length),
                                     &oFlashStatusWord, 0, u32UserFlashConfig);

    if (oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }
}

/*********************************************************************************************************************
 *  Example_EraseSector
 *
 *  Erases the first sector of FR1RP1 and verifies with a blank check. Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_EraseSector(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue sector erase command
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR1RP1STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR1RP1ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        for (uint8_t u8Iterator = 1; u8Iterator <= 2; u8Iterator++)
        {
            ClearFSMStatus(u32CurrentAddress, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)(u32CurrentAddress), u32UserFlashConfig,
                                       FLASH_NOWRAPPER_O_CMDWEPROTA, 0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)(u32CurrentAddress), u32UserFlashConfig,
                                       FLASH_NOWRAPPER_O_CMDWEPROTB, 0x00000000);

            //
            // Erase Sector
            //
            oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector, (uint32_t *)(u32CurrentAddress),
                                                             u8Iterator, u32UserFlashConfig);

            //
            // Wait until FSM is done with erase sector operation
            //
            while (Fapi_checkFsmForReady(u32CurrentAddress, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // erase command to see if there are any erase operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32CurrentAddress, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }
        }

        //
        // Verify the Sector is erased
        //
        oReturnCheck = Fapi_doBlankCheck((uint32_t *)(u32CurrentAddress), MainBankSector4KB_u32length,
                                         &oFlashStatusWord, 0, u32UserFlashConfig);

        if (oReturnCheck != Fapi_Status_Success)
        {
            Example_Error(oReturnCheck);
        }
    }
}

/*********************************************************************************************************************
 *  Example_ProgramUsingC29AutoECC
 *
 *  Programs 0x200 bytes to FR1RP1 using AutoEccGeneration option and verifies.
 *  Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_ProgramUsingC29AutoECC(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue program command for Mode 0 Main array interleaved bank FR1RP1
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR1RP1STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR1RP1ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        //
        // Program 0x200 words to given bank
        //
        for (uint32_t i = 0, u32Index = u32CurrentAddress; u32Index < (u32CurrentAddress + WORDS_IN_FLASH_BUFFER);
             i += 16, u32Index += 16)
        {
            ClearFSMStatus(u32Index, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTA,
                                       0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTB,
                                       0x00000000);

            oReturnCheck = Fapi_issueProgrammingCommand((uint32_t *)u32Index, Buffer + i, 16, 0, 0,
                                                        Fapi_AutoEccGeneration, u32UserFlashConfig);

            //
            // Wait until the Flash program operation is over
            //
            while (Fapi_checkFsmForReady(u32Index, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // program command to see if there are any program operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32Index, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }

            //
            // Verify the programmed values. Check for any ECC errors.
            //
            oReturnCheck = Fapi_doVerify((uint32_t *)u32Index, 4, (uint32_t *)(Buffer + i), &oFlashStatusWord, 0,
                                         u32UserFlashConfig);

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }
        }
    }
}

/*********************************************************************************************************************
 *  Example_ProgramUsingDataAndECC
 *
 *  Programs 0x200 bytes to FR1RP2 using DataAndEcc option and verifies.
 *  Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_ProgramUsingDataAndECC(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue program command for Mode 0 Main array interleaved bank FR1RP2
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR1RP2STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR1RP2ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        //
        // Program 0x200 words to given bank
        //
        for (uint32_t i = 0, u32Index = u32CurrentAddress; u32Index < (u32CurrentAddress + WORDS_IN_FLASH_BUFFER);
             i += 16, u32Index += 16)
        {
            ClearFSMStatus(u32Index, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTA,
                                       0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTB,
                                       0x00000000);

            //
            // Point LData to the lower 64 bit data
            // and   HData to the higher 64 bit data
            //
            uint64_t *LData = (uint64_t *)(Buffer32 + i / 4);
            uint64_t *HData = (uint64_t *)(Buffer32 + i / 4 + 2);

            //
            // Calculate ECC for lower 64 bit and higher 64 bit data
            //
            uint32_t ECC_LB = Fapi_calculateEcc((uint32_t *)u32Index, LData, 0);
            uint32_t ECC_HB = Fapi_calculateEcc((uint32_t *)(u32Index + 8), HData, 0);
            uint32_t ECC_B  = ((ECC_HB << 8) | ECC_LB);

            oReturnCheck = Fapi_issueProgrammingCommand((uint32_t *)u32Index, Buffer + i, 16, (uint8_t *)&ECC_B, 2,
                                                        Fapi_DataAndEcc, u32UserFlashConfig);

            //
            // Wait until the Flash program operation is over
            //
            while (Fapi_checkFsmForReady(u32Index, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // program command to see if there are any program operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32Index, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }

            //
            // Verify the programmed values. Check for any ECC errors.
            //
            oReturnCheck = Fapi_doVerify((uint32_t *)u32Index, 4, (uint32_t *)(Buffer + i), &oFlashStatusWord, 0,
                                         u32UserFlashConfig);

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }
        }
    }
}

/*********************************************************************************************************************
 *  Example_ProgramUsingDataOnlyECCOnly
 *
 *  Programs 0x200 bytes to FR1RP3 using DataOnly option then writes ECC separately
 *  using EccOnly option, and verifies. Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_ProgramUsingDataOnlyECCOnly(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue program command for Mode 0 Main array interleaved bank FR1RP3
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR1RP3STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR1RP3ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        //
        // Program 0x200 words to given bank
        //
        for (uint32_t i = 0, u32Index = u32CurrentAddress; u32Index < (u32CurrentAddress + WORDS_IN_FLASH_BUFFER);
             i += 16, u32Index += 16)
        {
            ClearFSMStatus(u32Index, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTA,
                                       0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTB,
                                       0x00000000);

            //
            // Point LData to the lower 64 bit data
            // and   HData to the higher 64 bit data
            //
            uint64_t *LData = (uint64_t *)(Buffer32 + i / 4);
            uint64_t *HData = (uint64_t *)(Buffer32 + i / 4 + 2);

            //
            // Calculate ECC for lower 64 bit and higher 64 bit data
            //
            uint32_t ECC_LB = Fapi_calculateEcc((uint32_t *)u32Index, LData, 0);
            uint32_t ECC_HB = Fapi_calculateEcc((uint32_t *)(u32Index + 8), HData, 0);
            uint32_t ECC_B  = ((ECC_HB << 8) | ECC_LB);

            oReturnCheck = Fapi_issueProgrammingCommand((uint32_t *)u32Index, Buffer + i, 16, 0, 0, Fapi_DataOnly,
                                                        u32UserFlashConfig);

            //
            // Wait until the Flash program operation is over
            //
            while (Fapi_checkFsmForReady(u32Index, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // program command to see if there are any program operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32Index, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTA,
                                       0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTB,
                                       0x00000000);

            oReturnCheck = Fapi_issueProgrammingCommand((uint32_t *)u32Index, 0, 0, (uint8_t *)&ECC_B, 2, Fapi_EccOnly,
                                                        u32UserFlashConfig);

            //
            // Wait until the Flash program operation is over
            //
            while (Fapi_checkFsmForReady(u32Index, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // program command to see if there are any program operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32Index, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }

            //
            // Verify the programmed values. Check for any ECC errors.
            //
            oReturnCheck = Fapi_doVerify((uint32_t *)u32Index, 4, (uint32_t *)(Buffer + i), &oFlashStatusWord, 0,
                                         u32UserFlashConfig);

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }
        }
    }
}

/*********************************************************************************************************************
 *  Example_ProgramDataFlashUsingC29AutoECC
 *
 *  Programs 0x200 bytes to the data flash bank FR4RP0 using AutoEccGeneration option
 *  and verifies byte-by-byte. Executed from RAM.
 *********************************************************************************************************************/
__attribute__((section(".TI.ramfunc"))) static void Example_ProgramDataFlashUsingC29AutoECC(void)
{
    Fapi_StatusType          oReturnCheck;
    Fapi_FlashStatusType     oFlashStatus;
    Fapi_FlashStatusWordType oFlashStatusWord;

    //
    // Issue program command for Mode 0 main array data bank FR4RP0
    //
    for (uint32_t u32CurrentAddress                                                = C29FLASHBANKFR4RP0STARTADDRESS;
         u32CurrentAddress < C29FLASHBANKFR4RP0ENDADDRESSPLUS1; u32CurrentAddress += FlashC29BankSize)
    {
        //
        // Program 0x200 words to given bank
        //
        for (uint32_t i = 0, u32Index = u32CurrentAddress; u32Index < (u32CurrentAddress + WORDS_IN_FLASH_BUFFER);
             i += 16, u32Index += 16)
        {
            ClearFSMStatus(u32Index, u32UserFlashConfig);

            //
            // Set program/erase protection
            //
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTA,
                                       0x00000000);
            Fapi_setupBankSectorEnable((uint32_t *)u32Index, u32UserFlashConfig, FLASH_NOWRAPPER_O_CMDWEPROTB,
                                       0x00000000);

            oReturnCheck = Fapi_issueProgrammingCommand((uint32_t *)u32Index, Buffer + i, 16, 0, 0,
                                                        Fapi_AutoEccGeneration, u32UserFlashConfig);

            //
            // Wait until the Flash program operation is over
            //
            while (Fapi_checkFsmForReady(u32Index, u32UserFlashConfig) == Fapi_Status_FsmBusy)
                ;

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }

            //
            // Read FMSTAT register contents to know the status of FSM after
            // program command to see if there are any program operation related errors
            //
            oFlashStatus = Fapi_getFsmStatus(u32Index, u32UserFlashConfig);
            if (oFlashStatus != 3)
            {
                FMSTAT_Fail();
            }

            //
            // Verify the programmed values. Check for any ECC errors.
            //
            oReturnCheck = Fapi_doVerifyByByte((uint8_t *)u32Index, 16, (uint8_t *)(Buffer + i), &oFlashStatusWord, 0,
                                               u32UserFlashConfig);

            if (oReturnCheck != Fapi_Status_Success)
            {
                Example_Error(oReturnCheck);
            }
        }
    }
}

/*********************************************************************************************************************
 *  Example_CallFlashAPI
 *
 *  Fills the data buffer, then runs the full sequence of erase/program operations
 *  across all banks in Mode 0: bank erase, program with AutoECC, sector erase,
 *  program with DataAndECC, program with DataOnly+EccOnly, data flash program,
 *  and a final bank erase for clean exit.
 *********************************************************************************************************************/
static void Example_CallFlashAPI(void)
{
    //
    // Fill a buffer with data to program into the flash.
    //
    uint32_t i;
    for (i = 0; i < WORDS_IN_FLASH_BUFFER; i++)
    {
        Buffer[i] = (uint8_t)i;
    }

    //
    // Assign 32-indexed buffer for ECC computation
    //
    Buffer32 = (uint32_t *)Buffer;

    //
    // Erase banks before programming
    //
    Example_EraseBanks();

    //
    // Program first 0x200 bytes of FR1RP1 (at 0x10100000) using AutoECC option
    //
    Example_ProgramUsingC29AutoECC();

    //
    // Erase the sector
    //
    Example_EraseSector();

    //
    // Program first 0x200 bytes of FR1RP2 (at 0x10200000) using DataAndECC option
    //
    Example_ProgramUsingDataAndECC();

    //
    // Program first 0x200 bytes of FR1RP3 (at 0x10300000) using DataOnly and EccOnly options
    //
    Example_ProgramUsingDataOnlyECCOnly();

    //
    // Program first 0x200 bytes of FR4RP0 (at 0x10C00000) using AutoECC option
    //
    Example_ProgramDataFlashUsingC29AutoECC();

    //
    // Erase all Mode 0 interleaved banks for clean exit
    //
    Example_EraseBanks();
}

/*********************************************************************************************************************
 *  FlsApp_FapiFlashOperations
 *
 *  Groups the Flash API operations from flash_mode0_128_program.c (lines 127-198):
 *    - Claim the flash semaphore
 *    - Retrieve the FOTA user configuration
 *    - Set the Flash API CPU configuration (Mode 0)
 *    - Initialize the Flash API
 *    - Execute direct Flash API operations via Example_CallFlashAPI()
 *    - Release the flash semaphore
 *
 *  Returns E_OK on success, E_NOT_OK on any failure.
 *********************************************************************************************************************/
static Std_ReturnType FlsApp_FapiFlashOperations(void)
{
    Fapi_StatusType oReturnCheck;

    //
    // Request semaphore for CPU1
    //
    Fls_SSU_claimFlashSemaphore();

    //
    // Get the current FOTA configuration. This variable is passed as a parameter
    // to most functions and, if in Mode 1 or 3, determines whether or not the
    // update region will be written to.
    //
    u32UserFlashConfig = Fapi_getUserConfiguration(BankType, FOTAStatus);

    //
    // Set Flash API Bank Mode configuration. These address mappings will be used
    // for program and erase operations. Outside of specific use cases, this should
    // match the device's currently programmed bank mode.
    //
    oReturnCheck = Fapi_SetFlashCPUConfiguration(Mode0);
    if (oReturnCheck != Fapi_Status_Success)
    {
        (void)Fls_SSU_releaseFlashSemaphore();
        return E_NOT_OK;
    }

    //
    // Initialize the Flash API by providing the Flash register base address
    // and operating frequency (in MHz). This function is required to initialize
    // the Flash API based on System frequency before any other Flash API operation
    // can be performed. This function must also be called whenever System frequency
    // or RWAIT is changed.
    //
    oReturnCheck = Fapi_initializeAPI((Fapi_FmcRegistersType *)FLASHCONTROLLER1_BASE, 200);
    if (oReturnCheck != Fapi_Status_Success)
    {
        (void)Fls_SSU_releaseFlashSemaphore();
        return E_NOT_OK;
    }

    //
    // Flash API functions should not be executed from the same bank on which
    // erase/program operations are in progress. Also, note that there should not
    // be any access to the Flash bank on which erase/program operations are
    // in progress.
    //
    Example_CallFlashAPI();

    //
    // Release the flash semaphore
    //
    Fls_SSU_releaseFlashSemaphore();

    return E_OK;
}

Std_ReturnType FlsFapiApp(void)
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
    /* Perform direct Flash API operations (semaphore claim, FAPI init, flash operations, semaphore release) */
    status = FlsApp_FapiFlashOperations();
#if defined(Debug_AppPrint)
    if (status == E_OK)
    {
        AppUtils_Printf("Flash API based Flash operations completed successfully.\n\r");
    }
    else
    {
        AppUtils_Printf("Flash API based Flash operations failed.\n\r");
    }
#endif
    /********************************************************************************************************************************/

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

    /********************************************************************************************************************************/
    /* Perform direct Flash API operations (semaphore claim, FAPI init, flash operations, semaphore release) */
    status = FlsApp_FapiFlashOperations();
#if defined(Debug_AppPrint)
    if (status == E_OK)
    {
        AppUtils_Printf("Flash API based Flash operations completed successfully.\n\r");
    }
    else
    {
        AppUtils_Printf("Flash API based Flash operations failed.\n\r");
    }
#endif
    /********************************************************************************************************************************/

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
 *  End of File: Fls_Fapi_App.c
 *********************************************************************************************************************/
