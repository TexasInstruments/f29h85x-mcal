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
 *  \file       Fls_Ac.c
 *
 *  \brief Description:  This file contains the driver APIs for FLASH controller.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-30912, MCAL-30913, MCAL-30914,
 */
#include "Fls_Ac.h"

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

static FUNC(void, FLS_CODE) Fls_Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value);

/* Flash C API functions*/
static FUNC(void, FLS_CODE) Fls_Fapi_issueFsmCommand(void);

static FUNC(uint32, FLS_CODE) Fls_Fapi_flushPipeline(void);

/* Device Family Dependent FSM commands */

static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_loopRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue);

static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_checkRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                 uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue);

static FUNC(void, FLS_CODE) Fls_F29WriteTrims(uint32 reg_offset, uint32 mask, uint32 shift, uint32 value);
static FUNC(void, FLS_CODE) Fls_F29SetWaitstates(uint16 waitstates);
static FUNC(void, FLS_CODE) Fls_F29ConfigFRI(Fls_FlashFRIType friID, uint32 configFlags);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define FLS_START_SEC_CODE /* Definition of start symbol for FLS memory section */
#include "Fls_MemMap.h"    /* Include of the memory mapping header file */

/*
 *   This is the primary function to initialize the API for first use or when the user changes
 * active Flash Wrappers or System Frequency
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_initializeAPI(uint32 u32HclkFrequency)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn = E_OK;

    /* the waitstates is updated in Fls_Init(), checking waitstate here is not needed */

    /* Configure KDIV and CFGCMD.WAITSTATE based on the input SYSCLK frequency
     * Return error if the input SYSCLK is not in valid range
     */
    /* Add 200Mhz clock range for final code, 100Mhz is for QT setup */
    if ((u32HclkFrequency <= 200U) && (u32HclkFrequency > 100U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 4U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 100U) && (u32HclkFrequency > 90U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 2U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 90U) && (u32HclkFrequency > 80U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 2U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 80U) && (u32HclkFrequency > 60U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 1U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 60U) && (u32HclkFrequency > 40U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 1U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 40U) && (u32HclkFrequency > 30U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 30U) && (u32HclkFrequency > 20U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 15U) && (u32HclkFrequency > 10U))
    {
        Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                     FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD, FLS_FLASH_NW_CFGCMD_WAITSTATE_M,
                     FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 0U);
    }
    else
    {
        oErrorReturn = E_NOT_OK;
    }

    /* Delay for more than 8 cycles after the flash wait-state configuration */
    McalLib_Delay((uint32)1U);

    return (oErrorReturn);
}

/*
 *   Used to setup and issue a programming command to the Flash State Machine.
 *  Design: MCAL-30891, MCAL-30892, MCAL-30893, MCAL-30897,
 */
FUNC(void, FLS_CODE)
Fls_Fapi_issueProgrammingCommand(uint32 *pu32StartAddress, uint8 *pu8DataBuffer, uint8 u8DataBufferSizeInBytes)
{
    VAR(uint32, AUTOMATIC) u8BankWidth       = 16U;
    VAR(uint32, AUTOMATIC) u32StartCondition = 0U;
    VAR(uint32, AUTOMATIC) u32StopCondition  = 0U;
    VAR(uint32, AUTOMATIC) u32Index          = 0U;
    VAR(uint32, AUTOMATIC) u32CopyDataBuffer = 0U;

    u32StartCondition = ((uint32)pu32StartAddress) & (uint32)((uint32)u8BankWidth - (uint32)1U);
    /* Proceed to setting up address and data registers for program operation */

    /* Enable AUTOCALC_EN for AutoEccGeneration feature */
    (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_ECCGENOVR,
                       FLS_FLASH_NW_CMDCTL_ECCGENOVR_S, 0U);

    /* Enable DATAVEREN to catch 0->1 program request */
    (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_DATAVEREN,
                       FLS_FLASH_NW_CMDCTL_DATAVEREN_S, 1U);

    /* Configure for 1x128 word program: Command is program (1), Size is ONEWORD (0) */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDTYPE) = FLS_FLASH_NW_CMDTYPE_PROG_ONEWD;

    /* Configure the address for program */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDADDR) =
        (uint32)((uint32)pu32StartAddress & (uint32)0xFFFFFFF0U);

    /* Configure data index */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDDATAINDEX) =
        (((uint32)pu32StartAddress >> 4U) & 0x3U); /* 256KB Bank(Data Flash) */

    /* If not  ECC only mode, load data into the data registers */
    /* Setup the stop position within the register */
    /* Changed to words instead of bytes */
    u32StopCondition = u32StartCondition + (uint32)((uint32)(u8DataBufferSizeInBytes) - (uint32)1U);

    /* Write each byte to the FWPWrite registers */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDBYTEN) = 0U;

    for (u32Index = u32StartCondition; u32Index <= u32StopCondition; u32Index = u32Index + 4U)
    {
        u32CopyDataBuffer  = 0U;
        u32CopyDataBuffer |= (((uint32) * (pu8DataBuffer + u32Index)));
        u32CopyDataBuffer |= (((uint32) * (pu8DataBuffer + u32Index + 1U)) << 8U);
        u32CopyDataBuffer |= (((uint32) * (pu8DataBuffer + u32Index + 2U)) << 16U);
        u32CopyDataBuffer |= ((uint32) * (pu8DataBuffer + u32Index + 3U) << 24U);

        if (((u32Index == 0U) || (u32Index == 4U)))
        {
            /*enable Ecc data byte for programming data 0 to 7 bytes (0-63 bits)*/
            (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDBYTEN,
                               FLS_FLASH_NW_CMDBYTEN_ECC0VAL_M, FLS_FLASH_NW_CMDBYTEN_ECC0VAL_S, 1U);
        }
        else
        {
            /*enable Ecc data byte for programming data 8 -15 byte (64-127 bits)*/
            (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDBYTEN,
                               FLS_FLASH_NW_CMDBYTEN_ECC1VAL_M, FLS_FLASH_NW_CMDBYTEN_ECC1VAL_S, 1U);
        }

        /* Copy data buffer to  CMDATA0 - CMDDATA3 (128-bits) */
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDDATA0 + (u32Index)) = u32CopyDataBuffer;

        /*enable 32-bits for programming data sequentially(1 bit corresponds to 1 byte)*/
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDBYTEN) |= (((uint32)0xF) << (u32Index));
    }
    /* Issue the Program command to the FSM */
    Fls_Fapi_issueFsmCommand();

    /* Disable AUTOCALC */
    (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_ECCGENOVR,
                       FLS_FLASH_NW_CMDCTL_ECCGENOVR_S, 1U);
}
/*
 *   Issues a command to the Flash State Machine for operations that require
 *   a valid address to operate to correctly.
 */
FUNC(void, FLS_CODE)
Fls_Fapi_issueAsyncCommandWithAddress(uint32 *pu32StartAddress)
{
    /*  Configure for sector erase: Command is erase (2), Size is sector (4) */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDTYPE) = FLS_FLASH_NW_CMDTYPE_SECTOR_ERASE;

    /* Configure the address for sector erase */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDADDR) = (uint32)pu32StartAddress;

    /* Issue the specified command to the FSM */
    Fls_Fapi_issueFsmCommand();
}

/*
 *   Issues bank erase command to the Flash State Machine for the given bank address
 */
FUNC(void, FLS_CODE) Fls_Fapi_issueBankEraseCommand(uint32 *pu32StartAddress)
{
    /* Bit field: | 4   3  |  2   1   0| */
    /* Bit field:   FLCID      BankID    */
    HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_BANK)  = (4U << FLS_SSU_BEPROT_BANK_BANKID_S);
    HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_BANK) |= (0U << FLS_SSU_BEPROT_BANK_FLCID_S);

    /* Configure for sector erase: Command is erase (2), Size is Bank (5)*/

    Fls_Write_32((uint32)FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDTYPE, FLS_FLASH_NW_CMDTYPE_VAL_M,
                 FLS_FLASH_NW_CMDTYPE_VAL_S, (uint32)FLS_FLASH_NW_CMDTYPE_BANK_ERASE);

    Fls_Write_32((uint32)FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDADDR, FLS_FLASH_NW_CMDADDR_VAL_M,
                 FLS_FLASH_NW_CMDADDR_VAL_S, (uint32)pu32StartAddress);
    /* configure CMDWEPROTNM register to protect non-main region sectors 0 from erase
     *  and do the read back for register
     */
    Fls_Write_32((uint32)FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDWEPROTNM, FLS_FLASH_NW_CMDWEPROTNM_VAL_M,
                 FLS_FLASH_NW_CMDWEPROTNM_VAL_S, 1U);

    /* Issue the specified command to the FSM */
    Fls_Fapi_issueFsmCommand();
}

/*
 *   Issues a command to the Flash State Machine for operations that do not
 *   require a valid address to operate to correctly.
 */
FUNC(void, FLS_CODE) Fls_Fapi_issueAsyncCommand(void)
{
    /* Issue the command only if the command is valid    */

    /* Configure for CLEAR STATUS and read back FLS_FLASH_O_CMDTYPE*/
    Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDTYPE, FLS_FLASH_NW_CMDTYPE_CMD_M,
                 FLS_FLASH_NW_CMDTYPE_CMD_S, 0x5U);
    // /* Issue the specified command to the FSM */

    /* Issue the specified command to the FSM */
    Fls_Fapi_issueFsmCommand();
}

/*
 *  Function to flush the pipeline
 */
static FUNC(uint32, FLS_CODE) Fls_Fapi_flushPipeline(void)
{
    VAR(volatile uint32, AUTOMATIC) u32DummyRead = 0U;

    /* FRI-4 flush pipeline */
    u32DummyRead = *((volatile uint32 *)0x10C00000U);
    u32DummyRead = *((volatile uint32 *)0x10C00200U);
    u32DummyRead = *((volatile uint32 *)0x10C00400U);

    return u32DummyRead;
}

/*
 *   Loops the specified region for the looking for the specified check value.
 */
static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_loopRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue)
{
    VAR(volatile Std_ReturnType, AUTOMATIC) oErrorReturn       = E_OK;
    VAR(uint32, AUTOMATIC) u32CurrentLength                    = u32Length;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32CurrentAddress = pu32StartAddress;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32CurrentCheckValue;
    VAR(uint32, AUTOMATIC) index = (uint32)0U;

    pu32CurrentCheckValue = pu32CheckValue;

    /* step through each flash location */
    /* while( u32CurrentLength-- > 0U) */ /* Misra C overflow */
    for (index = 0; index < u32CurrentLength; index++)
    {
        if (*pu32CurrentAddress != *pu32CurrentCheckValue)
        {
            /* save address of first failure */
            poFlashStatusWord->au32StatusWord[0] = (uint32)(pu32CurrentAddress);
            /* save actual data */
            poFlashStatusWord->au32StatusWord[1] = *pu32CurrentAddress;
            /* save expected data */
            poFlashStatusWord->au32StatusWord[2] = *pu32CurrentCheckValue;

            oErrorReturn = E_NOT_OK;
            break;
        }

        /* Increment the check buffer if not checking for a single value */
        if (oRegionValue != FLS_FAPI_SINGLEVALUE)
        {
            pu32CurrentCheckValue++;
        }
        /* increment address */
        pu32CurrentAddress++;
    }

    return (oErrorReturn);
}

/*
 *   Loops the specified region looking for the specified check value
 */
static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_checkRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                 uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn = E_OK;

    (void)Fls_Fapi_flushPipeline();
    if (Fls_Fapi_loopRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, pu32CheckValue, oRegionValue) !=
        E_OK)
    {
        /* save read mode */
        poFlashStatusWord->au32StatusWord[3] = 0U;
        oErrorReturn                         = E_NOT_OK;
    }
    return (oErrorReturn);
}

/*
 *   Loops the specified region for the looking for the specified check value.
 */
static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_loopRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32ByteCount,
                                      Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                      Fls_FapiRegionValueType oRegionValue)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn                 = E_OK;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CurrentCheckValue = pu8CheckValue;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CurrentAddress    = (uint8 *)(pu8StartAddress);
    VAR(uint32, AUTOMATIC) index                                = (uint32)0U;

    for (index = 0; index < u32ByteCount; index++)
    {
        if (*pu8CurrentAddress != *pu8CurrentCheckValue)
        {
            /* save address of first failure */
            poFlashStatusWord->au32StatusWord[0] = (uint32)(pu8CurrentAddress);
            /* save actual data */
            poFlashStatusWord->au32StatusWord[1] = *pu8CurrentAddress;
            /* save expected data */
            poFlashStatusWord->au32StatusWord[2] = (uint8)*pu8CurrentCheckValue;

            oErrorReturn = E_NOT_OK;
            break;
        }
        /* Increment the check buffer if not checking for a single value */
        if (oRegionValue != FLS_FAPI_SINGLEVALUE)
        {
            pu8CurrentCheckValue++;
        }

        /* increment address */
        pu8CurrentAddress++;
    }
    return (oErrorReturn);
}

/*
 *   Loops the specified region for the looking for the specified check value by byte.
 */
static FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_checkRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32ByteCount,
                                       Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                       Fls_FapiRegionValueType oRegionValue)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn = E_OK;

    /* Verify only if the address is valid */
    (void)Fls_Fapi_flushPipeline();
    if (Fls_Fapi_loopRegionForValueByByte(pu8StartAddress, u32ByteCount, poFlashStatusWord, pu8CheckValue,
                                          oRegionValue) != E_OK)
    {
        /* save read mode */
        poFlashStatusWord->au32StatusWord[3] = 0U;
        oErrorReturn                         = E_NOT_OK;
    }

    return (oErrorReturn);
}

FUNC(Std_ReturnType, FLS_CODE)
Fls_Fapi_doVerifyByByte(uint8 *pu8StartAddress, uint32 u32ByteCount, uint8 *pu8CheckValueBuffer,
                        Fls_FlashStatusWordType *poFlashStatusWord)
{
    return (Fls_Fapi_checkRegionForValueByByte(pu8StartAddress, u32ByteCount, poFlashStatusWord, pu8CheckValueBuffer,
                                               FLS_FAPI_MULTIPLEVALUEECC));
}

/**
 *   This is the function to do a data verify on flash memory
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Fapi_doVerify(uint32 *pu32StartAddress, uint32 u32Length, uint32 *pu32CheckValueBuffer,
                  Fls_FlashStatusWordType *poFlashStatusWord)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn = E_OK;
    oErrorReturn = Fls_Fapi_checkRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, pu32CheckValueBuffer,
                                                FLS_FAPI_MULTIPLEVALUEECC);
    return (oErrorReturn);
}

/*
 *   This is the function to do a blank check on flash addresses
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Fapi_doBlankCheck(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord)
{
    VAR(Std_ReturnType, AUTOMATIC) oErrorReturn = E_OK;
    VAR(uint32, AUTOMATIC) u32CheckValue        = (uint32)0xFFFFFFFFU;

    /* Do blank check if the address is valid */
    (void)Fls_Fapi_flushPipeline();
    if (Fls_Fapi_loopRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, &u32CheckValue,
                                    FLS_FAPI_SINGLEVALUE) != E_OK)
    {
        /* save read mode */
        poFlashStatusWord->au32StatusWord[3] = 0U; /*Normal read mode*/
        oErrorReturn                         = E_NOT_OK;
    }
    return (oErrorReturn);
}

/*
 *   Used to get the status bits of the FSM.
 */
FUNC(Fls_FapiFlashStatus, FLS_CODE) Fls_Fapi_getFsmStatus(void)
{
    return (HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_STATCMD));
}

/*
 *   Issues a command to the Flash State Machine.
 */
static FUNC(void, FLS_CODE) Fls_Fapi_issueFsmCommand(void)
{
    /* Issue the command only if the command is valid */
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDEXEC) = 0x1U;
}

/*
 *   Used to enable sector access during erase and program operations.
 *   Design: MCAL-31077,
 */
FUNC(void, FLS_CODE) Fls_Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value)
{
    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + reg_address) = value;
}

/*
 *   Used to check if FSM is busy
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_checkFsmForReady(void)
{
    VAR(volatile Std_ReturnType, AUTOMATIC) oStatusReturn = E_NOT_OK;

    if ((HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_STATCMD) & FLS_FLASH_NW_STATCMD_CMDINPROGRESS) == 0U)
    {
        oStatusReturn = E_OK;
    }

    return (oStatusReturn);
}

/*
 *   Used to write 32-bit data
 */
static FUNC(void, FLS_CODE) Fls_Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{
    /* Set the requested bits to the value.*/
    HWREG(ctrlBase + reg_offset) &= ~(uint32)mask;

    HWREG(ctrlBase + reg_offset) |= ((uint32)value << shift);
}

static FUNC(void, FLS_CODE) Fls_F29SetWaitstates(uint16 waitstates)
{
    /* waitstates is 4 bits wide */

    /* Write flash read wait-state amount to appropriate register */
    HWREG(FLS_FRI1_CTL_BASE + FLS_FRI_O_FRDCNTL) =
        (HWREG(FLS_FRI1_CTL_BASE + FLS_FRI_O_FRDCNTL) & ~(uint32)FLS_FRI_FRDCNTL_RWAIT_M) |
        ((uint32)waitstates << FLS_FRI_FRDCNTL_RWAIT_S);
}

static FUNC(void, FLS_CODE) Fls_F29WriteTrims(uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{
    /* Set the requested bits to the value.*/
    HWREG(FLS_ANALOGSUBSYS_BASE + reg_offset) &= ~(uint32)mask;

    HWREG(FLS_ANALOGSUBSYS_BASE + reg_offset) |= ((uint32)value << shift);
}

static FUNC(void, FLS_CODE) Fls_F29ConfigFRI(Fls_FlashFRIType friID, uint32 configFlags)
{
    /* Set the FRI options. */
    HWREG(FLS_FRI1_CTL_BASE + FLS_FRI_O_1_INTF_CTRL + ((uint8)friID * FLS_FRI_REG_STEP)) = configFlags; /* QJ*/
}

FUNC(void, FLS_CODE) Fls_Update_WaitStates(uint16 waitstates)
{
    /* Disable data cache, code cache, prefetch, and data preread before changing wait states*/
    Fls_F29ConfigFRI(FLS_FLASH_FRI4, FLS_FLASH_DATAPREREAD_DISABLE | FLS_FLASH_CODECACHE_DISABLE |
                                         FLS_FLASH_DATACACHE_DISABLE | FLS_FLASH_PREFETCH_DISABLE);

    /* Set waitstates according to frequency.*/
    Fls_F29SetWaitstates(waitstates);

    /* Configure TRIMCOMMITREAD and TRIMCOMMITOTHER in TRIMCOMMIT register */
    Fls_F29WriteTrims(FLS_ASYSCTL_O_FLASHTRIMCOMMIT, FLS_ASYSCTL_FLC1TRIMCOMMITREAD, 0, FLS_ASYSCTL_FLC1TRIMCOMMITREAD);
    Fls_F29WriteTrims(FLS_ASYSCTL_O_FLASHTRIMCOMMIT, FLS_ASYSCTL_FLC1TRIMCOMMITOTHER, 0,
                      FLS_ASYSCTL_FLC1TRIMCOMMITOTHER);

    /* Enable data cache, code cache and prefetch to improve
     *  performance of code executed from flash
     */
    Fls_F29ConfigFRI(FLS_FLASH_FRI4,
                     FLS_FLASH_CODECACHE_ENABLE | FLS_FLASH_DATACACHE_ENABLE | FLS_FLASH_PREFETCH_ENABLE);

    /* Force a pipeline flush to ensure that the write to the last register configured occurs before
     * returning*/
    FLS_FLASH_DELAY_CONFIG;
}

/* Claim Flash Semaphore
 * \brief return true if the semaphore is successfully assigned, false if semaphore is already
 * assigned to a different CPU or LINK .
 */
FUNC(void, FLS_CODE) Fls_SSU_claimFlashSemaphore(void)
{
    /* Check if the semaphore is already assigned */
    if ((HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_FLSEMSTAT) & FLS_SSU_FLSEMSTAT_ASSIGNED) == 0U)
    {
        /* Claim the semaphore */
        HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_FLSEMREQ) = 1U;
    }
    return;
}

/* Release Flash Semaphore
 *
 * \return true if the semaphore is successfully released, false if semaphore was not already
 * assigned to the current CPU or LINK
 *
 */
FUNC(void, FLS_CODE) Fls_SSU_releaseFlashSemaphore(void)
{
    /* Check if the semaphore is already assigned to the current CPU and LINK */
    if ((HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_FLSEMSTAT) & FLS_SSU_FLSEMSTAT_MATCH) != 0U)
    {
        /* Release the semaphore */
        HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_FLSEMCLR) = 1U;
    }
    return;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Fls_Ac.c
 *********************************************************************************************************************/
