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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
static FUNC(boolean, FLS_CODE) Fls_Fapi_isAddressValid(uint32 u32StartAddress, uint32 u32Length);
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value);
static FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_regReadback(uint32 reg_offset, uint32 readback_value);

/* Flash C API functions*/
static FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueFsmCommand(Fls_FlashStateCmdType oCommand);
static FUNC(boolean, FLS_CODE) Fls_Fapi_isMainArrayAddressValid(uint32 u32StartAddress);
static FUNC(boolean, FLS_CODE) Fls_Fapi_isNonMainArrayAddressValid(uint32 u32StartAddress);

static FUNC(uint32, FLS_CODE) Fls_Fapi_flushPipeline(void);

/* Device Family Dependent FSM commands */
static FUNC(boolean, FLS_CODE) Fls_Fapi_isAddressEcc(uint32 u32Address);

static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_loopRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue);

static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_loopRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32Length,
                                      Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                      Fls_FapiRegionValueType oRegionValue);

static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_checkRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                 uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue);

static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_checkRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32Length,
                                       Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                       Fls_FapiRegionValueType oRegionValue);

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
FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_initializeAPI(uint32 u32HclkFrequency)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn   = FLS_FAPI_STATUS_SUCCESS;
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn_1 = FLS_FAPI_STATUS_SUCCESS;

    /* the waitstates is updated in Fls_Init(), checking waitstate here is not needed */

    /* Configure KDIV and CFGCMD.WAITSTATE based on the input SYSCLK frequency
     * Return error if the input SYSCLK is not in valid range
     */
    /* Add 200Mhz clock range for final code, 100Mhz is for QT setup */
    if ((u32HclkFrequency <= 200U) && (u32HclkFrequency > 100U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 4U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 100U) && (u32HclkFrequency > 90U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 2U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 90U) && (u32HclkFrequency > 80U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 2U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 80U) && (u32HclkFrequency > 60U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 1U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 60U) && (u32HclkFrequency > 40U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 1U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 40U) && (u32HclkFrequency > 30U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 2U);
    }
    else if ((u32HclkFrequency <= 30U) && (u32HclkFrequency > 20U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 1U);
    }
    else if ((u32HclkFrequency <= 15U) && (u32HclkFrequency > 10U))
    {
        oErrorReturn   = Fls_Write_32(FLS_FLASH_READINTERFACE_BASE, FLS_FLASH_O_FLCLKCTL, FLS_FLASH_FLCLKCTL_KDIV_M,
                                      FLS_FLASH_FLCLKCTL_KDIV_S, 0U);
        oErrorReturn_1 = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CFGCMD,
                                      FLS_FLASH_NW_CFGCMD_WAITSTATE_M, FLS_FLASH_NW_CFGCMD_WAITSTATE_S, 0U);
    }
    else
    {
        oErrorReturn = FLS_FAPI_ERROR_INVALIDHCLKVALUE;
    }

    if ((oErrorReturn_1 != FLS_FAPI_STATUS_SUCCESS))
    {
        oErrorReturn = oErrorReturn_1;
    }
    /* Delay for more than 8 cycles after the flash wait-state configuration */
    /*for(i =0U; i<8U; i++) {};*/
    McalLib_Delay((uint32)1U);

    return (oErrorReturn);
}

/*
 *   Used to setup and issue a programming command to the Flash State Machine.
 */
FUNC(Fls_FapiStatusType, FLS_CODE)
Fls_Fapi_issueProgrammingCommand(uint32 *pu32StartAddress, uint8 *pu8DataBuffer, uint8 u8DataBufferSizeInBytes)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;
    /*VAR(Fls_Fapi_FlashProgrammingCommandsType, AUTOMATIC) oCurrentMode =
     * FLS_Fapi_AutoEccGeneration;*/
    VAR(uint32, AUTOMATIC) u8BankWidth       = 16U;
    VAR(uint32, AUTOMATIC) u32StartCondition = 0U;
    VAR(uint32, AUTOMATIC) u32StopCondition  = 0U;
    VAR(uint32, AUTOMATIC) u32Index          = 0U;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA)
    pu32DataBuffer = (uint32 *)pu8DataBuffer; /**QJ, problem */

    /* Check if FSM is busy with another operation */
    if (Fls_Fapi_checkFsmForReady() == FLS_FAPI_STATUS_FSMBUSY)
    {
        oErrorReturn = FLS_FAPI_STATUS_FSMBUSY;
    }
    /* Configure Flash wrapper for the active bank based on given address */
    /* Return an error if the address provided is not valid */
    if (!(((uint32)pu32StartAddress >= FLS_C29FLASHBANKFR4RP0STARTADDRESS) &&
          ((uint32)pu32StartAddress < FLS_C29FLASHBANKFR4RP0ENDADDRESSPLUS1)))
    {
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
    }
    if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
    {
        /* Setup the start position within the register */
        /*LDRA_INSPECTED 439 S MR:R.11.2,R.11.4,R.11.6,R.11.7 "Reason - Cast from pointer to
         * integral type required"*/
        u32StartCondition = ((uint32)pu32StartAddress) & (uint32)((uint32)u8BankWidth - (uint32)1U);

        /* Check to see if there is more data in the buffer than the register width */
        /* only if it is not ECC Only mode */
        if ((u8DataBufferSizeInBytes == 0U) || ((u32StartCondition + u8DataBufferSizeInBytes) > u8BankWidth))
        {
            oErrorReturn = FLS_FAPI_ERROR_ASYNCWRONGDBUFLEN;
        }
    }
    /* Proceed to setting up address and data registers for program operation */
    if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
    {
        /* Enable AUTOCALC_EN for AutoEccGeneration feature */
        (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_ECCGENOVR,
                           FLS_FLASH_NW_CMDCTL_ECCGENOVR_S, 0U);

        /* Enable DATAVEREN to catch 0->1 program request */
        (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_DATAVEREN,
                           FLS_FLASH_NW_CMDCTL_DATAVEREN_S, 1U);

        /* Configure for 1x128 word program: Command is program (1), Size is ONEWORD (0) */
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDTYPE) = FLS_FLASH_NW_CMDTYPE_PROG_ONEWD;

        /* Read back for FLS_FLASH_NW_O_CMDTYPE register */
        oErrorReturn = Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDTYPE, (uint32)FLS_FLASH_NW_CMDTYPE_PROG_ONEWD);

        if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
        {
            /* Configure the address for program */
            HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDADDR) =
                (uint32)((uint32)pu32StartAddress & (uint32)0xFFFFFFF0U);

            /* Read back and Issue an error if address is not configured correctly */
            oErrorReturn = Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDADDR, (uint32)pu32StartAddress);
        }

        /* Configure data index */
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDDATAINDEX) =
            (((uint32)pu32StartAddress >> 4U) & 0x3U); /* 256KB Bank(Data Flash) */

        if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
        {
            /* If not  ECC only mode, load data into the data registers */
            /* Setup the stop position within the register */
            /* Changed to words instead of bytes */
            u32StopCondition = u32StartCondition + (uint32)((uint32)(u8DataBufferSizeInBytes) - (uint32)1U);

            /* Write each byte to the FWPWrite registers */
            HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDBYTEN) = 0U;

            for (u32Index = u32StartCondition; u32Index <= u32StopCondition; u32Index++)
            {
                if ((u32Index % 4U) == 0U)
                {
                    if (((u32Index == 0U) || (u32Index == 4U)))
                    {
                        (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDBYTEN,
                                           FLS_FLASH_NW_CMDBYTEN_ECC0VAL_M, FLS_FLASH_NW_CMDBYTEN_ECC0VAL_S, 1U);
                    }
                    else
                    {
                        (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDBYTEN,
                                           FLS_FLASH_NW_CMDBYTEN_ECC1VAL_M, FLS_FLASH_NW_CMDBYTEN_ECC1VAL_S, 1U);
                    }

                    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDDATA0 + (u32Index)) = *pu32DataBuffer;

                    pu32DataBuffer++;

                    HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDBYTEN) |= (((uint32)0xF) << (u32Index));
                }
            }
            /* Issue the Program command to the FSM */
            (void)Fls_Fapi_issueFsmCommand(FLS_FAPI_PROGRAMDATA);
        }
        /* Disable AUTOCALC */
        (void)Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDCTL, FLS_FLASH_NW_CMDCTL_ECCGENOVR,
                           FLS_FLASH_NW_CMDCTL_ECCGENOVR_S, 1U);
    }
    /* Return the function status */
    return (oErrorReturn);
}

/*
 *   Issues a command to the Flash State Machine for operations that require
 *   a valid address to operate to correctly.
 */
FUNC(Fls_FapiStatusType, FLS_CODE)
Fls_Fapi_issueAsyncCommandWithAddress(Fls_FlashStateCmdType oCommand, uint32 *pu32StartAddress)
{
    VAR(Fls_FapiStatusType, AOYOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;

    /* Check the given command and issue an error if it is OTP Erase or if it is not sector erase */
    if (FLS_FAPI_ERASESECTOR != oCommand)
    {
        oErrorReturn = FLS_FAPI_ERROR_FEATURENOTAVAILABLE;
    }

    /* Check if FSM is busy with another operation */
    if (Fls_Fapi_checkFsmForReady() == FLS_FAPI_STATUS_FSMBUSY)
    {
        oErrorReturn = FLS_FAPI_STATUS_FSMBUSY;
    }

    /* Return an error if the address provided is not valid */
    if ((Fls_Fapi_isMainArrayAddressValid((uint32)pu32StartAddress) == (boolean)TRUE) &&
        (Fls_Fapi_isNonMainArrayAddressValid((uint32)pu32StartAddress) == (boolean)TRUE))
    {
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
    }

    if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
    {
        /*  Configure for sector erase: Command is erase (2), Size is sector (4) */
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDTYPE) = FLS_FLASH_NW_CMDTYPE_SECTOR_ERASE;
        /* Readback FLS_FLASH_O_CMDTYPE register */
        if (Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDTYPE, (uint32)FLS_FLASH_NW_CMDTYPE_SECTOR_ERASE) ==
            FLS_FAPI_STATUS_SUCCESS)
        {
            /* Configure the address for sector erase */
            HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDADDR) = (uint32)pu32StartAddress;
            /* Issue an error if address is not configured correctly */
            oErrorReturn = Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDADDR, (uint32)pu32StartAddress);
        }

        if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
        {
            /* Issue the specified command to the FSM */
            oErrorReturn = Fls_Fapi_issueFsmCommand(FLS_FAPI_ERASESECTOR);
        }
    }
    return (oErrorReturn);
}

/*
 *   Issues bank erase command to the Flash State Machine for the given bank address
 */
FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueBankEraseCommand(uint32 *pu32StartAddress)
{
    VAR(Fls_FapiStatusType, AOYOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS; /*0x0*/
    /*VAR(volatile uint32, AOYOMATIC) u32DummyRead = 0U;*/

    /* Check if FSM is busy with another operation */
    if (Fls_Fapi_checkFsmForReady() == FLS_FAPI_STATUS_FSMBUSY)
    {
        oErrorReturn = FLS_FAPI_STATUS_FSMBUSY;
    }

    /* Return an error if the address provided is not valid */
    if (Fls_Fapi_isMainArrayAddressValid((uint32)pu32StartAddress) == (boolean)TRUE) /*QJ, should be FALSE*/
    {
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
    }

    if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
    {
        /* Bit field: | 4   3  |  2   1   0| */
        /* Bit field:   FLCID      BankID    */
        HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_BANK)  = (4U << FLS_SSU_BEPROT_BANK_BANKID_S);
        HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_BANK) |= (0U << FLS_SSU_BEPROT_BANK_FLCID_S);

        /*u32DummyRead = HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_BANK) & 0x1F;*/

        /*while ((HWREG(FLS_SSUGEN_BASE + FLS_SSU_O_BEPROT_STAT) & 0x1U) != 0x1U) {}*/

        /* Configure for sector erase: Command is erase (2), Size is Bank (5)*/
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDTYPE) = FLS_FLASH_NW_CMDTYPE_BANK_ERASE;
        /* Readback FLS_FLASH_O_CMDTYPE register */
        if (Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDTYPE, (uint32)FLS_FLASH_NW_CMDTYPE_BANK_ERASE) ==
            FLS_FAPI_STATUS_SUCCESS)
        {
            /* Configure the address for bank erase */
            HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDADDR) = (uint32)pu32StartAddress;

            /* Issue an error if address is not configured correctly */
            oErrorReturn = Fls_Fapi_regReadback((uint32)FLS_FLASH_NW_O_CMDADDR, (uint32)pu32StartAddress);
        }
        if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
        {
            /* configure CMDWEPROTNM register to protect non-main region sectors 0 from erase
             *  and do the read back for register
             */
            oErrorReturn = Fls_Write_32((uint32)FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDWEPROTNM,
                                        FLS_FLASH_NW_CMDWEPROTNM_VAL_M, FLS_FLASH_NW_CMDWEPROTNM_VAL_S, 1U);

            if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
            {
                /* Issue the specified command to the FSM */
                oErrorReturn = Fls_Fapi_issueFsmCommand(FLS_FAPI_ERASEBANK);
            }
        }
    }
    return (oErrorReturn);
}

/*
 *   Issues a command to the Flash State Machine for operations that do not
 *   require a valid address to operate to correctly.
 */
FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueAsyncCommand(Fls_FlashStateCmdType oCommand)
{
    VAR(Fls_FapiStatusType, AOYOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;

    /* Check if FSM is busy with another operation */
    if (Fls_Fapi_checkFsmForReady() == FLS_FAPI_STATUS_FSMBUSY)
    {
        oErrorReturn = FLS_FAPI_STATUS_FSMBUSY;
    }

    if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
    {
        /* Issue the command only if the command is valid    */
        if (FLS_FAPI_CLEARSTATUS == oCommand)
        {
            /* Configure for CLEAR STATUS and read back FLS_FLASH_O_CMDTYPE*/
            oErrorReturn = Fls_Write_32(FLS_FLASH_FAPI_FLASHNW_FC1_BASE, FLS_FLASH_NW_O_CMDTYPE,
                                        FLS_FLASH_NW_CMDTYPE_CMD_M, FLS_FLASH_NW_CMDTYPE_CMD_S, 0x5U);
            /* Issue the specified command to the FSM */
            if (oErrorReturn == FLS_FAPI_STATUS_SUCCESS)
            {
                /* Issue the specified command to the FSM */
                oErrorReturn = Fls_Fapi_issueFsmCommand(oCommand);
            }
        }
        else
        {
            oErrorReturn = FLS_FAPI_ERROR_FEATURENOTAVAILABLE;
        }
    }
    return (oErrorReturn);
}

/*
 *  Function to flush the pipeline
 */
static FUNC(uint32, FLS_CODE) Fls_Fapi_flushPipeline(void)
{
    VAR(volatile uint32, AOYOMATIC) u32DummyRead = 0U;

    /* FRI-4 flush pipeline */
    u32DummyRead = *((volatile uint32 *)0x10C00000U);
    u32DummyRead = *((volatile uint32 *)0x10C00200U);
    u32DummyRead = *((volatile uint32 *)0x10C00400U);

    return u32DummyRead;
}

/*
 *   Loops the specified region for the looking for the specified check value.
 */
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_loopRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn            = FLS_FAPI_STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) u32CurrentLength                    = u32Length;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32CurrentAddress = pu32StartAddress;
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pu32CurrentCheckValue;
    VAR(uint32, AUTOMATIC) index = (uint32)0U;

    if (Fls_Fapi_isAddressEcc((uint32)pu32StartAddress) == (boolean)FALSE) /* See if address is an ECC location */
    {
        pu32CurrentCheckValue = pu32CheckValue;

        /* step through each flash location */
        /* while( u32CurrentLength-- > 0U) */ /* Misra C overflow */
        for (index = 0; index < u32CurrentLength; index++)
        {
            if (*pu32CurrentAddress != *pu32CurrentCheckValue)
            {
                /* save last address read */
                poFlashStatusWord->au32StatusWord[0] = (uint32)(pu32CurrentAddress);
                /* save actual data */
                poFlashStatusWord->au32StatusWord[1] = *pu32CurrentAddress;
                /* save expected data */
                poFlashStatusWord->au32StatusWord[2] = *pu32CurrentCheckValue;

                oErrorReturn = FLS_FAPI_ERROR_FAIL;
            }

            /* Increment the check buffer if not checking for a single value */
            if (oRegionValue != FLS_FAPI_SINGLEVALUE)
            {
                pu32CurrentCheckValue++;
            }
            /* increment address */
            pu32CurrentAddress++;
        }
    }
    else
    {
        oErrorReturn = FLS_FAPI_ERROR_FEATURENOTAVAILABLE;
    }
    return (oErrorReturn);
}

/*
 *   Loops the specified region for the looking for the specified check value.
 */
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_loopRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32Length,
                                      Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                      Fls_FapiRegionValueType oRegionValue)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn             = FLS_FAPI_STATUS_SUCCESS;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CurrentCheckValue = pu8CheckValue;
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pu8CurrentAddress    = (uint8 *)(pu8StartAddress);
    VAR(uint32, AUTOMATIC) u32Len                               = (uint32)u32Length;
    VAR(uint32, AUTOMATIC) index                                = (uint32)0U;

    if (Fls_Fapi_isAddressEcc((uint32)pu8StartAddress) == (boolean)FALSE) /* See if address is an ECC location */
    {
        /*    while( u32Len-- > 0U) */ /* false positive */
        for (index = 0; index < u32Len; index++)
        {
            if (*pu8CurrentAddress != *pu8CurrentCheckValue)
            {
                /* save last address read */
                poFlashStatusWord->au32StatusWord[0] = (uint32)(pu8CurrentAddress);
                /* save actual data */
                poFlashStatusWord->au32StatusWord[1] = *pu8CurrentAddress;
                /* save expected data */
                poFlashStatusWord->au32StatusWord[2] = (uint8)*pu8CurrentCheckValue;

                oErrorReturn = FLS_FAPI_ERROR_FAIL;
            }
            /* Increment the check buffer if not checking for a single value */
            if (oRegionValue != FLS_FAPI_SINGLEVALUE)
            {
                pu8CurrentCheckValue++;
            }

            /* increment address */
            pu8CurrentAddress++;
        }
    }
    return (oErrorReturn);
}

/*
 *   Loops the specified region looking for the specified check value
 */
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_checkRegionForValue(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord,
                                 uint32 *pu32CheckValue, Fls_FapiRegionValueType oRegionValue)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;

    /* Verify only if the address is valid */
    if (Fls_Fapi_isAddressValid((uint32)pu32StartAddress, u32Length) == (boolean)TRUE)
    {
        /*LDRA_INSPECTED 488 S MR:R.10.3,R.10.4 "Reason - LDRA tool issue. Value is within the
         * range"*/
        (void)Fls_Fapi_flushPipeline();
        if (Fls_Fapi_loopRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, pu32CheckValue, oRegionValue) !=
            FLS_FAPI_STATUS_SUCCESS)
        {
            /* save read mode */
            poFlashStatusWord->au32StatusWord[3] = 0U;
            oErrorReturn                         = FLS_FAPI_ERROR_FAIL;
        }
    }
    else
    {
        /* Return an error if the address provided is not valid */
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
    }
    return (oErrorReturn);
}

/*
 *   Loops the specified region for the looking for the specified check value by byte.
 */
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Fapi_checkRegionForValueByByte(uint8 *pu8StartAddress, uint32 u32Length,
                                       Fls_FlashStatusWordType *poFlashStatusWord, uint8 *pu8CheckValue,
                                       Fls_FapiRegionValueType oRegionValue)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;

    /* Verify only if the address is valid */
    /*LDRA_INSPECTED 439 S MR:R.11.2,R.11.4,R.11.6,R.11.7 "Reason - Cast from pointer to integral
     * type required"*/
    if (Fls_Fapi_isAddressValid((uint32)pu8StartAddress, u32Length / 4U) == (boolean)TRUE)
    {
        /*LDRA_INSPECTED 488 S MR:R.10.3,R.10.4 "Reason - LDRA tool issue. Value is within the
         * range"*/
        (void)Fls_Fapi_flushPipeline();
        if (Fls_Fapi_loopRegionForValueByByte(pu8StartAddress, u32Length, poFlashStatusWord, pu8CheckValue,
                                              oRegionValue) != FLS_FAPI_STATUS_SUCCESS)
        {
            /* save read mode */
            poFlashStatusWord->au32StatusWord[3] = 0U;
            oErrorReturn                         = FLS_FAPI_ERROR_FAIL;
        }
    }
    else
    {
        /* Return an error if the address provided is not valid */
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
    }
    return (oErrorReturn);
}

/**
 *   This is the function to do a data verify on flash memory
 */
FUNC(Fls_FapiStatusType, FLS_CODE)
Fls_Fapi_doVerify(uint32 *pu32StartAddress, uint32 u32Length, uint32 *pu32CheckValueBuffer,
                  Fls_FlashStatusWordType *poFlashStatusWord)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;
    oErrorReturn = Fls_Fapi_checkRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, pu32CheckValueBuffer,
                                                FLS_FAPI_MULTIPLEVALUEECC);
    return (oErrorReturn);
}

FUNC(Fls_FapiStatusType, FLS_CODE)
Fls_Fapi_doVerifyByByte(uint8 *pu8StartAddress, uint32 u32Length, uint8 *pu8CheckValueBuffer,
                        Fls_FlashStatusWordType *poFlashStatusWord)
{
    return (Fls_Fapi_checkRegionForValueByByte(pu8StartAddress, u32Length, poFlashStatusWord, pu8CheckValueBuffer,
                                               FLS_FAPI_MULTIPLEVALUEECC));
}

/*
 *   This is the function to do a blank check on flash addresses
 */
FUNC(Fls_FapiStatusType, FLS_CODE)
Fls_Fapi_doBlankCheck(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) u32CheckValue            = (uint32)0xFFFFFFFFU;

    /* Do blank check if the address is valid */
    if (Fls_Fapi_isAddressValid((uint32)pu32StartAddress, u32Length) == (boolean)TRUE)
    {
        (void)Fls_Fapi_flushPipeline();
        if (Fls_Fapi_loopRegionForValue(pu32StartAddress, u32Length, poFlashStatusWord, &u32CheckValue,
                                        FLS_FAPI_SINGLEVALUE) != FLS_FAPI_STATUS_SUCCESS)
        {
            /* save read mode */
            poFlashStatusWord->au32StatusWord[3] = 0U; /*Normal read mode*/
            oErrorReturn                         = FLS_FAPI_ERROR_FAIL;
        }
    }
    else
    {
        /* Return an error if the address provided is not valid */
        oErrorReturn = FLS_FAPI_ERROR_INVALIDADDRESS;
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
static FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueFsmCommand(Fls_FlashStateCmdType oCommand)
{
    /* Issue the command only if the command is valid */
    if ((FLS_FAPI_CLEARSTATUS == oCommand) || (FLS_FAPI_PROGRAMDATA == oCommand) || (FLS_FAPI_ERASEBANK == oCommand) ||
        (FLS_FAPI_ERASESECTOR == oCommand))
    {
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_CMDEXEC) = 0x1U;
    }

    return (FLS_FAPI_STATUS_SUCCESS);
}

/*
 *   Used to enable sector access during erase and program operations.
 */
FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oStatusReturn = FLS_FAPI_STATUS_SUCCESS;

    if ((reg_address == (FLS_FLASH_NW_O_CMDWEPROTA)) || (reg_address == (FLS_FLASH_NW_O_CMDWEPROTB)) ||
        (reg_address == (FLS_FLASH_NW_O_CMDWEPROTNM)))
    {
        HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + reg_address) = value;
        /* read back WEPROTx register */
        if (HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + reg_address) != value)
        {
            oStatusReturn = FLS_FAPI_ERROR_FLASHREGSNOTWRITABLE;
        }
    }
    else
    {
        oStatusReturn = FLS_FAPI_ERROR_FEATURENOTAVAILABLE;
    }

    return (oStatusReturn);
}

/*
 *   Used to check if an address is located in the ECC region
 */
static FUNC(boolean, FLS_CODE) Fls_Fapi_isAddressEcc(uint32 u32Address)
{
    VAR(boolean, AUTOMATIC) isAddressEccResult = FALSE;

    if (((u32Address >= FLS_C29FLASHBANKFR4RP0ECCSTARTADDRESS) &&
         (u32Address < FLS_C29FLASHBANKFR4RP0ECCENDADDRESSPLUS1)) ||
        ((u32Address >= FLS_C29FLASHBANKFR4RP0BANKMGMTECCSTARTADDRESS) &&
         (u32Address < FLS_C29FLASHBANKFR4RP0BANKMGMTECCENDADDRESSPLUS1)))
    {
        isAddressEccResult = TRUE;
    }

    return isAddressEccResult;
}

/*
 *   Used to check if an address is located in the main region
 */
static FUNC(boolean, FLS_CODE) Fls_Fapi_isMainArrayAddressValid(uint32 u32StartAddress)
{
    VAR(boolean, AUTOMATIC) isMainArrayAddressValid = FALSE;

    if (!((u32StartAddress >= FLS_C29FLASHBANKFR4RP0STARTADDRESS) &&
          (u32StartAddress < FLS_C29FLASHBANKFR4RP0ENDADDRESSPLUS1)))
    {
        isMainArrayAddressValid = TRUE;
    }
    return isMainArrayAddressValid;
}

/*
 *   Used to check if an address is located in the  non Main Array region
 */
static FUNC(boolean, FLS_CODE) Fls_Fapi_isNonMainArrayAddressValid(uint32 u32StartAddress)
{
    VAR(boolean, AUTOMATIC) isNonMainArrayAddressValid = FALSE;

    if ((!((u32StartAddress >= FLS_C29FLASHBANKFR4RP0BANKMGMTSTARTADDRESS) &&
           (u32StartAddress < FLS_C29FLASHBANKFR4RP0BANKMGMTENDADDRESSPLUS1))))
    {
        isNonMainArrayAddressValid = TRUE;
    }
    return isNonMainArrayAddressValid;
}

/*
 *   Used to check if FSM is busy
 */
FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_checkFsmForReady(void)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oStatusReturn = FLS_FAPI_STATUS_FSMBUSY;

    if ((HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + FLS_FLASH_NW_O_STATCMD) & FLS_FLASH_NW_STATCMD_CMDINPROGRESS) == 0U)
    {
        oStatusReturn = FLS_FAPI_STATUS_FSMREADY;
    }

    return (oStatusReturn);
}

/*
 *   Checks whether or not a given address is valid
 */
static FUNC(boolean, FLS_CODE) Fls_Fapi_isAddressValid(uint32 u32Address, uint32 u32Length)
{
    VAR(boolean, AUTOMATIC) result = (boolean)FALSE;
    ;

    if (((u32Address >= FLS_C29FLASHBANKFR4RP0STARTADDRESS) &&
         ((u32Address + (u32Length * 4U)) <= FLS_C29FLASHBANKFR4RP0ENDADDRESSPLUS1)) ||
        ((u32Address >= FLS_C29FLASHBANKFR4RP0ECCSTARTADDRESS) &&
         ((u32Address + (u32Length * 4U)) <= FLS_C29FLASHBANKFR4RP0ECCENDADDRESSPLUS1)))
    {
        result = (boolean)TRUE;
    }
    else
    {
        result = (boolean)FALSE;
    }
    return result;
}

/*
 *   Used to write 32-bit data
 */
static FUNC(Fls_FapiStatusType, FLS_CODE)
    Fls_Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{
    VAR(uint32, AUTOMATIC) readback_value = 0;

    /* Set the requested bits to the value.*/
    HWREG(ctrlBase + reg_offset) &= ~(uint32)mask;

    HWREG(ctrlBase + reg_offset) |= ((uint32)value << shift);

    readback_value = HWREG(ctrlBase + reg_offset);

    return ((readback_value == HWREG(ctrlBase + reg_offset)) ? FLS_FAPI_STATUS_SUCCESS
                                                             : FLS_FAPI_ERROR_FLASHREGSNOTWRITABLE);
}

/*
 *    Readback function for flash register
 */
static FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_regReadback(uint32 reg_offset, uint32 readback_value)
{
    VAR(Fls_FapiStatusType, AUTOMATIC) oErrorReturn = FLS_FAPI_STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) regRead_value            = 0;
    regRead_value                                   = HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + reg_offset);
    /* Issue an error if register is not configured correctly */
    if (regRead_value != HWREG(FLS_FLASH_FAPI_FLASHNW_FC1_BASE + reg_offset))
    {
        oErrorReturn = FLS_FAPI_ERROR_FLASHREGSNOTWRITABLE;
    }
    return (oErrorReturn);
}

static FUNC(void, FLS_CODE) Fls_F29SetWaitstates(uint16 waitstates)
{
    /* waitstates is 4 bits wide */
    if ((waitstates <= 0xFU) && (waitstates >= 0x1U))
    {
        /* Write flash read wait-state amount to appropriate register */
        HWREG(FLS_FRI1_CTL_BASE + FLS_FRI_O_FRDCNTL) =
            (HWREG(FLS_FRI1_CTL_BASE + FLS_FRI_O_FRDCNTL) & ~(uint32)FLS_FRI_FRDCNTL_RWAIT_M) |
            ((uint32)waitstates << FLS_FRI_FRDCNTL_RWAIT_S);
    }
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

    /* Enable data cache, code cache, prefetch, and data preread to improve
     *  performance of code executed from flash
     */
    Fls_F29ConfigFRI(FLS_FLASH_FRI4, FLS_FLASH_DATAPREREAD_ENABLE | FLS_FLASH_CODECACHE_ENABLE |
                                         FLS_FLASH_DATACACHE_ENABLE | FLS_FLASH_PREFETCH_ENABLE);

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
