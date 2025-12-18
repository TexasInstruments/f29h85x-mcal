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
 *  File:        Cdd_Xbar_Priv.c
 *  Generator:   None
 *
 *  Description: Private source file for CDD XBar IP related source
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Xbar.h"
#include "Cdd_Xbar_Priv.h"

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

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CDD_XBAR_START_SEC_CODE
#include "Cdd_Xbar_MemMap.h"

/*
 * Design: MCAL-25761
 */
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect,
                  P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint32, AUTOMATIC) inputxselectaddress;

    /* Offset same as (InputSelect * 4) */
    inputxselectaddress = INPUTXBAR_BASE + INPUT_XBAR_O_INPUTSELECT(*InputSelect - 1U);

    if (TRUE == Selection)
    {
        /* Write GPIO number as InputPin to Input Select */
        HWREG(inputxselectaddress) = *InputLine;
    }
    else
    {
        /* Write reset value to the Input Select*/
        HWREG(inputxselectaddress) = 0xFFFE;
    }

    return;
}

/*
 * Design: MCAL-25768
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InSelectLockStatus(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect)
{
    VAR(uint32, AUTOMATIC) inputxselectlockaddress;
    VAR(boolean, AUTOMATIC) status       = FALSE;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << ((*InputSelect - 1U) % 32U);

    if (*InputSelect <= 32U)
    {
        inputxselectlockaddress = INPUTXBAR_BASE + INPUT_XBAR_O_INPUTSELECTLOCK1;
    }
    else
    {
        inputxselectlockaddress = INPUTXBAR_BASE + INPUT_XBAR_O_INPUTSELECTLOCK2;
    }

    status = (boolean)(HWREG(inputxselectlockaddress) & selectionmask);

    return status;
}

/*
 * Design: MCAL-25767
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InSelectLock(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect)
{
    VAR(uint32, AUTOMATIC) inputxselectlockaddress;
    VAR(uint32, AUTOMATIC) selectionmask;

    /* Check if crossbar isn't already locked before attempting a lock */
    if (FALSE == Cdd_Xbar_InSelectLockStatus(InputSelect))
    {
        selectionmask = (uint32)1U << ((*InputSelect - 1U) % 32U);
        if (*InputSelect <= 32U)
        {
            inputxselectlockaddress = INPUTXBAR_BASE + INPUT_XBAR_O_INPUTSELECTLOCK1;
        }
        else
        {
            inputxselectlockaddress = INPUTXBAR_BASE + INPUT_XBAR_O_INPUTSELECTLOCK2;
        }
        HWREG(inputxselectlockaddress) |= selectionmask;
    }

    return;
}
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

/*
 * Design: MCAL-25769
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLockStatus(void)
{
    VAR(uint32, AUTOMATIC) outputxlockaddress = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBARLOCK;
    VAR(boolean, AUTOMATIC) status            = FALSE;

    /* Check whether 0th Lock Bit is set or not */
    if ((HWREG(outputxlockaddress) & CDD_XBAR_LOCK_BIT) == CDD_XBAR_LOCK_BIT)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-25770
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_OutLock(void)
{
    VAR(uint32, AUTOMATIC) outputxlockaddress = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBARLOCK;
    VAR(uint32, AUTOMATIC) key                = (uint32)CDD_XBAR_LOCK_KEY << CDD_XBAR_LOCK_KEY_SHIFT;

    if (FALSE == Cdd_Xbar_OutLockStatus())
    {
        /* Write Key to Bits 16-31 to enable lock setting and set lock bit with it */
        HWREG(outputxlockaddress) = key | CDD_XBAR_LOCK_BIT;
    }

    return;
}

/*
 * Design: MCAL-25762
 */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint32, AUTOMATIC) outputgroupselectaddress;
    VAR(uint8, AUTOMATIC) groupnumber = CDD_XBAR_GET_GROUP_NUMBER(*InputLine);

    /* Direct Formula for Group Select Address:
      OUTPUTXBAR_BASE + 0x100 + (GroupNumber * 4) + (OutputLine * 0x40); */
    outputgroupselectaddress =
        (uint32)(OUTPUTXBAR_BASE + (OUTPUT_XBAR_O_OUTPUTXBARG0SEL(*OutputLine - 1U)) +
                 ((groupnumber) * (OUTPUT_XBAR_O_OUTPUTXBARG1SEL(0U) - OUTPUT_XBAR_O_OUTPUTXBARG0SEL(0U))));

    if (TRUE == Selection)
    {
        /* Select the corresponding Input Line */
        HWREG(outputgroupselectaddress) |= Cdd_Xbar_Input_Selection_Mask(*InputLine);
    }
    else
    {
        /* Deselect the corresponding Input Line */
        HWREG(outputgroupselectaddress) &= ~((uint32)Cdd_Xbar_Input_Selection_Mask(*InputLine));
    }

    return;
}

/*
 * Design: MCAL-25772
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC)
    outputxoutinvertaddress              = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(outputxoutinvertaddress) |= inversionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(outputxoutinvertaddress) &= ~inversionmask;
    }

    return;
}

/*
 * Design: MCAL-25771
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion = FALSE;
    VAR(uint32, AUTOMATIC)
    outputxoutinvertaddress              = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is 1 or enabled */
    if (inversionmask == (HWREG(outputxoutinvertaddress) & inversionmask))
    {
        inversion = TRUE;
    }

    return inversion;
}

/*
 * Design: MCAL-25775
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                           P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC)
    outputxoutlatchselectaddress         = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTLATCH;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        HWREG(outputxoutlatchselectaddress) |= selectionmask;
    }
    else
    {
        HWREG(outputxoutlatchselectaddress) &= ~selectionmask;
    }

    return;
}

/*
 * Design: MCAL-25774
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchSelectSts(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) latch = FALSE;
    VAR(uint32, AUTOMATIC)
    outputxoutlatchselectaddress         = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTLATCH;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if ((HWREG(outputxoutlatchselectaddress) & selectionmask) != 0U)
    {
        latch = TRUE;
    }

    return latch;
}

/*
 * Design: MCAL-28156
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagStatus(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                               P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress)
{
    VAR(boolean, AUTOMATIC) latch = FALSE;
    VAR(uint32, AUTOMATIC)
    outputxflagaddress = (uint32)(*OutputXbarFlagBaseAddress + ((*OutputLine - 1U) * XBAR_OUTPUTXBAR_FLAGS_OFFSET) +
                                  OUTPUT_XBAR_O_OUTPUTXBARFLAG);

    if ((HWREG(outputxflagaddress) & OUTPUT_XBAR_OUTPUTXBARFLAG_FLG) != 0U)
    {
        latch = TRUE;
    }

    return latch;
}

/*
 * Design: MCAL-28157
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagForce(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                              P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress)
{
    VAR(uint32, AUTOMATIC)
    outputxflagaddress = (uint32)(*OutputXbarFlagBaseAddress + ((*OutputLine - 1U) * XBAR_OUTPUTXBAR_FLAGS_OFFSET) +
                                  OUTPUT_XBAR_O_OUTPUTXBARFLAGFORCE);

    HWREG(outputxflagaddress) = OUTPUT_XBAR_OUTPUTXBARFLAGFORCE_FLG;

    return;
}

/*
 * Design: MCAL-28158
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagClear(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                              P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress)
{
    VAR(uint32, AUTOMATIC)
    outputxflagaddress = (uint32)(*OutputXbarFlagBaseAddress + ((*OutputLine - 1U) * XBAR_OUTPUTXBAR_FLAGS_OFFSET) +
                                  OUTPUT_XBAR_O_OUTPUTXBARFLAGCLEAR);

    HWREG(outputxflagaddress) = OUTPUT_XBAR_OUTPUTXBARFLAGCLEAR_FLG;

    return;
}

/*
 * Design: MCAL-25773
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputInvLatchSts(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion = TRUE;
    VAR(uint32, AUTOMATIC)
    outputxoutinvertflagaddress          = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBARFLAGINVERT;
    VAR(uint32, AUTOMATIC) inversionmask = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is not 1 or is disabled */
    if (0U == (HWREG(outputxoutinvertflagaddress) & inversionmask))
    {
        inversion = FALSE;
    }

    return inversion;
}

/*
 * Design: MCAL-28155
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputInvLatch(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                        P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC)
    outputxflaginvertaddress             = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBARFLAGINVERT;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(outputxflaginvertaddress) |= selectionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(outputxflaginvertaddress) &= ~selectionmask;
    }

    return;
}

/*
 * Design: MCAL-25776
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchPulse(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                            P2CONST(Cdd_Xbar_TickStretchType, AUTOMATIC, CDD_XBAR_CONST) Ticks)
{
    VAR(uint32, AUTOMATIC)
    outputxoutstretchaddress = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTSTRETCH;
    VAR(uint32, AUTOMATIC)
    outputxoutlenaddress                 = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTLENGTH;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if (CDD_XBAR_SYSTICKS_STRETCH_OFF == *Ticks)
    {
        /* Clear the selection bit */
        HWREG(outputxoutstretchaddress) &= ~selectionmask;
    }
    else
    {
        /* Stretched Pulse selection */
        HWREG(outputxoutstretchaddress) |= selectionmask;
        if (CDD_XBAR_SYSTICKS_16 == *Ticks)
        {
            /* Set 0 for length 16 SYS Ticks */
            HWREG(outputxoutlenaddress) &= ~selectionmask;
        }
        else
        {
            /* Set 1 for length 32 SYS Ticks */
            HWREG(outputxoutlenaddress) |= selectionmask;
        }
    }

    return;
}

/*
 * Design: MCAL-25777
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchOrNot(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) stretch = FALSE;
    VAR(uint32, AUTOMATIC)
    outputxoutstretchaddress             = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTSTRETCH;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if ((HWREG(outputxoutstretchaddress) & selectionmask) != 0U)
    {
        stretch = TRUE;
    }

    return stretch;
}

/*
 * Design: MCAL-25778
 */
FUNC(Cdd_Xbar_TickStretchType, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchGet(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) stretch = CDD_XBAR_SYSTICKS_STRETCH_OFF;
    VAR(uint32, AUTOMATIC)
    outputxoutlenaddress                 = OUTPUTXBAR_BASE + OUTPUT_XBAR_O_OUTPUTXBAROUTLENGTH;
    VAR(uint32, AUTOMATIC) selectionmask = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == Cdd_Xbar_OutputStretchOrNot(OutputLine))
    {
        if ((HWREG(outputxoutlenaddress) & selectionmask) == 0U)
        {
            stretch = CDD_XBAR_SYSTICKS_16;
        }
        else
        {
            stretch = CDD_XBAR_SYSTICKS_32;
        }
    }

    return stretch;
}

/*
 * Design: MCAL-25779
 */
FUNC(Cdd_Xbar_OutputlevelType, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputState(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                        P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress)
{
    VAR(Cdd_Xbar_OutputlevelType, AUTOMATIC) output = ((Cdd_Xbar_OutputlevelType)STD_LOW);
    VAR(uint32, AUTOMATIC)
    outputxoutstatusaddress =
        (uint32)(*OutputXbarFlagBaseAddress + (((*OutputLine) - 1U) * (XBAR_OUTPUTXBAR_FLAGS_OFFSET)) +
                 OUTPUT_XBAR_O_OUTPUTXBARSTATUS);

    /* Check Output status bit for enablement */
    if ((HWREG(outputxoutstatusaddress) & ((uint32)OUTPUT_XBAR_OUTPUTXBARSTATUS_STS)) != 0U)
    {
        output = STD_HIGH;
    }

    return output;
}
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

/*
 * Design: MCAL-25784
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbLockStatus(void)
{
    VAR(uint32, AUTOMATIC) clbxlockaddress = CLBXBAR_BASE + CLB_XBAR_O_CLBXBARLOCK;
    VAR(boolean, AUTOMATIC) status         = FALSE;

    /* Check whether 0th Lock Bit is set or not */
    if ((HWREG(clbxlockaddress) & CDD_XBAR_LOCK_BIT) == CDD_XBAR_LOCK_BIT)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-25785
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_ClbLock(void)
{
    VAR(uint32, AUTOMATIC) clbxlockaddress = CLBXBAR_BASE + CLB_XBAR_O_CLBXBARLOCK;
    VAR(uint32, AUTOMATIC) key             = (uint32)CDD_XBAR_LOCK_KEY << CDD_XBAR_LOCK_KEY_SHIFT;
    ;

    if (FALSE == Cdd_Xbar_ClbLockStatus())
    {
        /* Write Key to Bits 16-31 to enable lock setting and set lock bit with it */
        HWREG(clbxlockaddress) = key | CDD_XBAR_LOCK_BIT;
    }

    return;
}

/*
 * Design: MCAL-25764
 */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_ClbSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint8, AUTOMATIC) groupnumber = CDD_XBAR_GET_GROUP_NUMBER(*InputLine);
    VAR(uint32, AUTOMATIC) clbxgroupselectaddress;

    clbxgroupselectaddress = (uint32)(CLBXBAR_BASE + (CLB_XBAR_O_CLBXBARG0SEL(*OutputLine - 1U)) +
                                      ((groupnumber) * (CLB_XBAR_O_CLBXBARG1SEL(0U) - CLB_XBAR_O_CLBXBARG0SEL(0U))));

    if (TRUE == Selection)
    {
        /* Select the corresponding Input Line */
        HWREG(clbxgroupselectaddress) |= Cdd_Xbar_Input_Selection_Mask(*InputLine);
    }
    else
    {
        /* Deselect the corresponding Input Line */
        HWREG(clbxgroupselectaddress) &= ~((uint32)Cdd_Xbar_Input_Selection_Mask(*InputLine));
    }

    return;
}

/*
 * Design: MCAL-25787
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_ClbOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC) clbxoutinvertaddress = CLBXBAR_BASE + CLB_XBAR_O_CLBXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(clbxoutinvertaddress) |= inversionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(clbxoutinvertaddress) &= ~inversionmask;
    }

    return;
}

/*
 * Design: MCAL-25786
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_ClbOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion           = FALSE;
    VAR(uint32, AUTOMATIC) clbxoutinvertaddress = CLBXBAR_BASE + CLB_XBAR_O_CLBXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is 1 or enabled */
    if (inversionmask == (HWREG(clbxoutinvertaddress) & inversionmask))
    {
        inversion = TRUE;
    }

    return inversion;
}
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

/*
 * Design: MCAL-25780
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmLockStatus(void)
{
    VAR(uint32, AUTOMATIC) epwmxlockaddress = EPWMXBAR_BASE + EPWM_XBAR_O_PWMXBARLOCK;
    VAR(boolean, AUTOMATIC) status          = FALSE;

    /* Check whether 0th Lock Bit is set or not */
    if ((HWREG(epwmxlockaddress) & CDD_XBAR_LOCK_BIT) == CDD_XBAR_LOCK_BIT)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-25781
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_EpwmLock(void)
{
    VAR(uint32, AUTOMATIC) epwmxlockaddress = EPWMXBAR_BASE + EPWM_XBAR_O_PWMXBARLOCK;
    VAR(uint32, AUTOMATIC) key              = (uint32)CDD_XBAR_LOCK_KEY << CDD_XBAR_LOCK_KEY_SHIFT;

    if (FALSE == Cdd_Xbar_EpwmLockStatus())
    {
        /* Write Key to Bits 16-31 to enable lock setting and set lock bit with it */
        HWREG(epwmxlockaddress) = key | CDD_XBAR_LOCK_BIT;
    }

    return;
}

/*
 * Design: MCAL-25763
 */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_EpwmSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                    P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint32, AUTOMATIC) epwmxgroupselectaddress;
    VAR(uint8, AUTOMATIC) groupnumber = CDD_XBAR_GET_GROUP_NUMBER(*InputLine);

    epwmxgroupselectaddress = (uint32)(EPWMXBAR_BASE + (EPWM_XBAR_O_PWMXBARG0SEL(*OutputLine - 1U)) +
                                       ((groupnumber) * (EPWM_XBAR_O_PWMXBARG1SEL(0U) - EPWM_XBAR_O_PWMXBARG0SEL(0U))));

    if (TRUE == Selection)
    {
        /* Select the corresponding Input Line */
        HWREG(epwmxgroupselectaddress) |= Cdd_Xbar_Input_Selection_Mask(*InputLine);
    }
    else
    {
        /* Deselect the corresponding Input Line */
        HWREG(epwmxgroupselectaddress) &= ~((uint32)Cdd_Xbar_Input_Selection_Mask(*InputLine));
    }

    return;
}

/*
 * Design: MCAL-25783
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_EpwmOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                          P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC) epwmxoutinvertaddress = EPWMXBAR_BASE + EPWM_XBAR_O_PWMXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask         = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(epwmxoutinvertaddress) |= inversionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(epwmxoutinvertaddress) &= ~inversionmask;
    }

    return;
}

/*
 * Design: MCAL-25782
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_EpwmOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion            = FALSE;
    VAR(uint32, AUTOMATIC) epwmxoutinvertaddress = EPWMXBAR_BASE + EPWM_XBAR_O_PWMXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask         = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is 1 or enabled */
    if (inversionmask == (HWREG(epwmxoutinvertaddress) & inversionmask))
    {
        inversion = TRUE;
    }

    return inversion;
}
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

/*
 * Design: MCAL-25788
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlLockStatus(void)
{
    VAR(uint32, AUTOMATIC) mdlxlockaddress = MDLXBAR_BASE + MDL_XBAR_O_MDLXBARLOCK;
    VAR(boolean, AUTOMATIC) status         = FALSE;

    /* Check whether 0th Lock Bit is set or not */
    if ((HWREG(mdlxlockaddress) & CDD_XBAR_LOCK_BIT) == CDD_XBAR_LOCK_BIT)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-25789
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_MdlLock(void)
{
    VAR(uint32, AUTOMATIC) mdlxlockaddress = MDLXBAR_BASE + MDL_XBAR_O_MDLXBARLOCK;
    VAR(uint32, AUTOMATIC) key             = (uint32)CDD_XBAR_LOCK_KEY << CDD_XBAR_LOCK_KEY_SHIFT;

    if (FALSE == Cdd_Xbar_MdlLockStatus())
    {
        /* Write Key to Bits 16-31 to enable lock setting and set lock bit with it */
        HWREG(mdlxlockaddress) = key | CDD_XBAR_LOCK_BIT;
    }

    return;
}

/*
 * Design: MCAL-25765
 */
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_MdlSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint8, AUTOMATIC) groupnumber = CDD_XBAR_GET_GROUP_NUMBER(*InputLine);
    VAR(uint32, AUTOMATIC) mdlxgroupselectaddress;

    mdlxgroupselectaddress = (uint32)(MDLXBAR_BASE + (MDL_XBAR_O_MDLXBARG0SEL(*OutputLine - 1U)) +
                                      ((groupnumber) * (MDL_XBAR_O_MDLXBARG1SEL(0U) - MDL_XBAR_O_MDLXBARG0SEL(0U))));

    if (TRUE == Selection)
    {
        /* Select the corresponding Input Line */
        HWREG(mdlxgroupselectaddress) |= Cdd_Xbar_Input_Selection_Mask(*InputLine);
    }
    else
    {
        /* Deselect the corresponding Input Line */
        HWREG(mdlxgroupselectaddress) &= ~((uint32)Cdd_Xbar_Input_Selection_Mask(*InputLine));
    }

    return;
}

/*
 * Design: MCAL-25791
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_MdlOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC) mdlxoutinvertaddress = MDLXBAR_BASE + MDL_XBAR_O_MDLXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(mdlxoutinvertaddress) |= inversionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(mdlxoutinvertaddress) &= ~inversionmask;
    }

    return;
}

/*
 * Design: MCAL-25790
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_MdlOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion           = FALSE;
    VAR(uint32, AUTOMATIC) mdlxoutinvertaddress = MDLXBAR_BASE + MDL_XBAR_O_MDLXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is 1 or enabled */
    if (inversionmask == (HWREG(mdlxoutinvertaddress) & inversionmask))
    {
        inversion = TRUE;
    }

    return inversion;
}
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

/*
 * Design: MCAL-25792
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_IclLockStatus(void)
{
    VAR(uint32, AUTOMATIC) iclxlockaddress = ICLXBAR_BASE + ICL_XBAR_O_ICLXBARLOCK;
    VAR(boolean, AUTOMATIC) status         = FALSE;

    /* Check whether 0th Lock Bit is set or not */
    if ((HWREG(iclxlockaddress) & CDD_XBAR_LOCK_BIT) == CDD_XBAR_LOCK_BIT)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-25793
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_IclLock(void)
{
    VAR(uint32, AUTOMATIC) iclxlockaddress = ICLXBAR_BASE + ICL_XBAR_O_ICLXBARLOCK;
    VAR(uint32, AUTOMATIC) key             = (uint32)CDD_XBAR_LOCK_KEY << CDD_XBAR_LOCK_KEY_SHIFT;

    if (FALSE == Cdd_Xbar_IclLockStatus())
    {
        /* Write Key to Bits 16-31 to enable lock setting and set lock bit with it */
        HWREG(iclxlockaddress) = key | CDD_XBAR_LOCK_BIT;
    }

    return;
}

/*
 * Design: MCAL-25766
 */
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_IclSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(uint8, AUTOMATIC) groupnumber = CDD_XBAR_GET_GROUP_NUMBER(*InputLine);
    VAR(uint32, AUTOMATIC) iclxgroupselectaddress;

    iclxgroupselectaddress = (uint32)(ICLXBAR_BASE + (ICL_XBAR_O_ICLXBARG0SEL(*OutputLine - 1U)) +
                                      ((groupnumber) * (ICL_XBAR_O_ICLXBARG1SEL(0U) - ICL_XBAR_O_ICLXBARG0SEL(0U))));

    if (TRUE == Selection)
    {
        /* Select the corresponding Input Line */
        HWREG(iclxgroupselectaddress) |= Cdd_Xbar_Input_Selection_Mask(*InputLine);
    }
    else
    {
        /* Deselect the corresponding Input Line */
        HWREG(iclxgroupselectaddress) &= ~((uint32)Cdd_Xbar_Input_Selection_Mask(*InputLine));
    }
    return;
}

/*
 * Design: MCAL-25795
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_IclOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection)
{
    VAR(uint32, AUTOMATIC) iclxoutinvertaddress = ICLXBAR_BASE + ICL_XBAR_O_ICLXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    if (TRUE == *Selection)
    {
        /* Set Invert bit to ON (1) */
        HWREG(iclxoutinvertaddress) |= inversionmask;
    }
    else
    {
        /* Reset Invert bit to OFF (0) */
        HWREG(iclxoutinvertaddress) &= ~inversionmask;
    }

    return;
}

/*
 * Design: MCAL-25794
 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_IclOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine)
{
    VAR(boolean, AUTOMATIC) inversion           = FALSE;
    VAR(uint32, AUTOMATIC) iclxoutinvertaddress = ICLXBAR_BASE + ICL_XBAR_O_ICLXBAROUTINVERT;
    VAR(uint32, AUTOMATIC) inversionmask        = (uint32)1U << (*OutputLine - 1U);

    /* Read if inversion bit is 1 or enabled */
    if (inversionmask == (HWREG(iclxoutinvertaddress) & inversionmask))
    {
        inversion = TRUE;
    }

    return inversion;
}
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (STD_ON == CDD_XBAR_INPUT_FLAG_API)
/* Design: MCAL-28159 */
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InFlagStatus(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag,
                      P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) InputFlagBaseAddress)
{
    VAR(boolean, AUTOMATIC) status = FALSE;
    VAR(uint32, AUTOMATIC)
    xbarflagaddress = (uint32)(*InputFlagBaseAddress + (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag))-1U) * 4U));
    VAR(uint32, AUTOMATIC) inversionmask = (uint32)1U << (CDD_XBAR_INPUT_FLAG_BIT(InputFlag));

    if (inversionmask == (HWREG(xbarflagaddress) & inversionmask))
    {
        status = TRUE;
    }

    return status;
}

/* Design: MCAL-28160 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InFlagClear(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag,
                     P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) InputFlagBaseAddress)
{
    VAR(uint32, AUTOMATIC)
    xbarflagaddress =
        (uint32)(*InputFlagBaseAddress + XBAR_O_CLR1 + (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag))-1U) * 4U));
    VAR(uint32, AUTOMATIC) inversionmask = (uint32)1U << (CDD_XBAR_INPUT_FLAG_BIT(InputFlag));

    /* Set flag clear bit to 1 */
    HWREG(xbarflagaddress) |= inversionmask;

    return;
}
#endif /* STD_ON == CDD_XBAR_INPUT_FLAG_API */

#define CDD_XBAR_STOP_SEC_CODE
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Priv.c
 *********************************************************************************************************************/
