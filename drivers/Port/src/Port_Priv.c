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
 *  File:       Port_Priv.c
 *
 *  Description:  This file contains controller dependent local functions and private functions to
 *be used in Port.c
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Port.h"
#include "Port_Priv.h"

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

/** \brief  Sets the pull configuration for the specified pin.
 *
 * This function Sets the pull configuration for the specified pin.
 * The parameter
 * \e pinType can be the following values:
 *
 * - \b PORT_PIN_TYPE_STD specifies a push-pull output or a floating input
 * - \b PORT_PIN_TYPE_PULLUP specifies the pull-up is enabled for an input
 * - \b PORT_PIN_TYPE_OPEN_DRAIN specifies an open-drain output pin
 *
 * \param[in] PinNumber is the identifying number of the pin.
 * \param[in] PinProperty specifies the pin type.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, PORT_CODE) Port_SetPadConfig(Port_PinType PinNumber, Port_PinPadConfigType PinProperty);

/** \brief  Sets the qualification mode for the specified pin.
 *
 * This function sets the qualification mode for the specified pin. The
 * parameter \e qualification can be one of the following values:
 * - \b PORT_QUAL_SYNC
 * - \b PORT_QUAL_3SAMPLE
 * - \b PORT_QUAL_6SAMPLE
 * - \b PORT_QUAL_ASYNC
 *
 * \param[in] PinNumber is the identifying number of the pin.
 * \param[in] Qualification specifies the qualification mode of the pin.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, PORT_CODE) Port_SetQualificationMode(Port_PinType PinNumber, Port_PinQualificationMode Qualification);

/** \brief  Sets the qualification period for a set of pins
 *
 * This function sets the qualification period for a set of \b 8 \b pins,
 * specified by the \e pin parameter. For instance, passing in 3 as the value
 * of \e pin will set the qualification period for GPIO0 through GPIO7, and a
 * value of 98 will set the qualification period for GPIO96 through GPIO103.
 * This is because the register field that configures the divider is shared.
 *
 * \param[in] PinNumber is the identifying GPIO number of the pin.
 * \param[in] QualificationPeriod specifies the Qualification period.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, PORT_CODE) Port_SetQualificationPeriod(Port_PinType PinNumber, uint32 QualificationPeriod);

/** \brief  Selects the master core of a specified pin.
 *
 * This function configures which core owns the specified pin's data registers
 * (DATA, SET, CLEAR, and TOGGLE). The \e core parameter is an enumerated data
 * type that specifies the core, such as \b PORT_CORE_CPU1_CLA1 to make CPU1's
 * CLA1 master of the pin.
 * One pin can be accessed by only one pin at a time. Hence same pin cannot be
 * assigned multiple cores.
 *
 * The pin is specified by its numerical value. For example, GPIO34 is
 * specified by passing 34 as \e pin.
 *
 * \param[in] PinNumber is the identifying number of the pin.
 * \param[in] Core is the core that is master of the specified pin.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, PORT_CODE) Port_SetMasterCore(Port_PinType PinNumber, Port_PinCoreSelect Core);

/** \brief  Sets the analog mode of the specified pin.
 *
 * This function configures the specified pin for either analog or digital
 * mode. Not all GPIO pins have the ability to be switched to analog mode,
 * so refer to the technical reference manual for details. This setting should
 * be thought of as another level of muxing.
 *
 * The parameter \e mode is an enumerated data type that can be one of the
 * following values:
 *
 * - \b PORT_ANALOG_DISABLED - Pin is in digital mode
 * - \b PORT_ANALOG_ENABLED - Pin is in analog mode
 *
 * The pin is specified by its numerical value. For example, GPIO34 is
 * specified by passing 34 as \e pin.
 *
 * \param[in] PinNumber is the identifying number of the pin.
 * \param[in] Mode is the selected analog mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, PORT_CODE) Port_SetAnalogMode(Port_PinType PinNumber, Port_AnalogModeType Mode);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/*
 *Design: MCAL-22382,MCAL-22316,MCAL-22409,MCAL-22390,MCAL-22404
 */
FUNC(Std_ReturnType, PORT_CODE)
Port_SetCntSpConfig(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfigPtr)
{
    P2CONST(Port_ControllerSpecificType, AUTOMATIC, PORT_APPL_DATA)
    controllerSpecificPtr                          = &PinConfigPtr->Port_ControllerSpecific;
    VAR(Std_ReturnType, AUTOMATIC) returnValue     = (Std_ReturnType)E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC) PortPinNumValid = (Std_ReturnType)E_NOT_OK;

    PortPinNumValid = Port_IsPinNumberValid(PinConfigPtr->Port_PinId);

    if (PortPinNumValid != (Std_ReturnType)E_NOT_OK)
    {
        if (TRUE == PORT_IS_ANALOG_MODE_SUPPORTED(controllerSpecificPtr))
        {
            Port_SetAnalogMode(PinConfigPtr->Port_PinId, controllerSpecificPtr->Port_AnalogMode);
        }
        else
        {
            /*
             * Do Nothing
             */
        }
        if ((FALSE == PORT_IS_ANALOG_MODE_SUPPORTED(controllerSpecificPtr)) ||
            (PORT_ANALOG_DISABLED == controllerSpecificPtr->Port_AnalogMode))
        {
            Port_SetPadConfig(PinConfigPtr->Port_PinId, controllerSpecificPtr->Port_PinPadConfig);

            Port_SetQualificationMode(PinConfigPtr->Port_PinId, controllerSpecificPtr->Port_PinQualification);

            Port_SetQualificationPeriod(PinConfigPtr->Port_PinId, controllerSpecificPtr->Port_PinQualificationPeriod);

            Port_SetMasterCore(PinConfigPtr->Port_PinId, controllerSpecificPtr->Port_CoreSelect);

            Port_SetPinModeConfig(controllerSpecificPtr->Port_InitialMuxMode);
        }
        else
        {
            /*
             * Do Nothing
             */
        }
        returnValue = (Std_ReturnType)E_OK;
    }
    else
    {
        /*
         * Do Nothing
         */
    }
    return (returnValue);
}

/*
 *Design: MCAL-22411,MCAL-22703
 */
FUNC(Std_ReturnType, PORT_CODE)
Port_EnableLPMWakeUpPin(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfig)
{
    VAR(Port_PinType, AUTOMATIC) gpio31        = 31U;
    VAR(Port_PinType, AUTOMATIC) gpio63        = 63U;
    VAR(Port_PinType, AUTOMATIC) PinNumber     = PinConfig->Port_PinId;
    VAR(uint32, AUTOMATIC) pinMask             = 0U;
    VAR(Std_ReturnType, AUTOMATIC) returnValue = (Std_ReturnType)E_OK;

    P2CONST(Port_ControllerSpecificType, AUTOMATIC, PORT_CONFIG_DATA)
    controllerSpecificPtr = NULL_PTR;
    controllerSpecificPtr = &PinConfig->Port_ControllerSpecific;

    /*Bit position of the pin Number/GPIO number*/
    pinMask = (uint32)ONE_BIT_MASK << (PinNumber % PORT_WIDTH);

    /* Enable LPM Wakeup Pin if configured for the current pin*/
    if ((boolean)TRUE == controllerSpecificPtr->Port_EnableWakeupPinLPM)
    {
        /*If pin number is less than equal to 31 ( GPIO31 )*/
        if (gpio31 >= PinNumber)
        {
            HWREG((CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL0)) |= (pinMask);
        }
        else if (gpio63 >= PinNumber) /*If pin number is less than equal to 63 ( GPIO63 )*/
        {
            HWREG((CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL1)) |= (pinMask);
        }
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /*
         * Do Nothing
         */
    }
    return (returnValue);
}

/*
 *Design: MCAL-22383,MCAL-22404
 */
FUNC(Std_ReturnType, PORT_CODE)
Port_SetPinLevel(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfig, Port_PinLevelValueType PinLevel)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioDataReg;
    VAR(uint32, AUTOMATIC) pinMask;
    VAR(Port_PinType, AUTOMATIC) pinNumber         = PinConfig->Port_PinId;
    VAR(Std_ReturnType, AUTOMATIC) returnValue     = (Std_ReturnType)E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC) PortPinNumValid = (Std_ReturnType)E_NOT_OK;

    PortPinNumValid = Port_IsPinNumberValid(pinNumber);

    if ((PortPinNumValid != (Std_ReturnType)E_NOT_OK) &&
        ((PORT_PIN_OUT == PinConfig->Port_PinDirection) || (PORT_PIN_NA == PinConfig->Port_PinDirection)))
    {
        gpioDataReg = (uint32 *)((uint32 *)GPIODATA_BASE + ((pinNumber / PORT_WIDTH) * PORT_DATA_REGS_STEP));
        pinMask     = (uint32)ONE_BIT_MASK << (pinNumber % PORT_WIDTH);

        if (PORT_PIN_LEVEL_LOW == PinLevel)
        {
            gpioDataReg[PORT_CLEAR_REGS_INDEX] |= pinMask;
        }
        else if (PORT_PIN_LEVEL_HIGH == PinLevel)
        {
            gpioDataReg[PORT_SET_REGS_INDEX] |= pinMask;
        }
        else
        {
            /* DO Nothing for PORT_PIN_LEVEL_NA */
        }
        returnValue = E_OK;
    }
    else
    {
        if ((PortPinNumValid != (Std_ReturnType)E_NOT_OK) && (PORT_PIN_IN == PinConfig->Port_PinDirection))
        {
            /* Level change not required for INPUT Pins */
            returnValue = E_OK;
        }
        else
        {
            /*
             * Do Nothing
             */
        }
    }
    return (returnValue);
}

/*
 *Design: MCAL-22384,MCAL-22404
 */
FUNC(Std_ReturnType, PORT_CODE)
Port_SetDirectionMode(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfig,
                      Port_PinDirectionType PinDirection)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) pinMask;
    VAR(Port_PinType, AUTOMATIC) pinNumber         = PinConfig->Port_PinId;
    VAR(Std_ReturnType, AUTOMATIC) returnValue     = (Std_ReturnType)E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC) PortPinNumValid = (Std_ReturnType)E_NOT_OK;

    PortPinNumValid = Port_IsPinNumberValid(pinNumber);

    if (PortPinNumValid != (Std_ReturnType)E_NOT_OK)
    {
        gpioBaseAddr = (uint32 *)((uint32 *)GPIODATA_BASE + ((pinNumber / PORT_WIDTH) * PORT_DATA_REGS_STEP));
        pinMask      = (uint32)ONE_BIT_MASK << (pinNumber % PORT_WIDTH);

        /* Set the data direction */
        if (PORT_PIN_OUT == PinDirection)
        {
            /* Output */
            gpioBaseAddr[PORT_DIR_REGS_INDEX] |= pinMask;
        }
        else
        {
            /* Input */
            gpioBaseAddr[PORT_DIR_REGS_INDEX] &= ~pinMask;
        }

        returnValue = (Std_ReturnType)E_OK;
    }
    else
    {
        /*
         * Do Nothing
         */
    }

    return (returnValue);
}

/*
 * Design: MCAL-22388,MCAL-22404
 */
FUNC(void, PORT_CODE) Port_SetPinModeConfig(uint32 PinMode)
{
    VAR(uint32, AUTOMATIC) muxRegAddr       = 0U;
    VAR(uint32, AUTOMATIC) pinMask          = 0U;
    VAR(uint32, AUTOMATIC) shiftAmt         = 0U;
    VAR(uint32, AUTOMATIC) gmuxPinModeShift = 2U;

    muxRegAddr = (uint32)GPIOCTRL_BASE + (PinMode >> PORT_WIDTH_HALF);
    shiftAmt   = ((PinMode >> PORT_WIDTH_QUARTER) & (uint32)0xFFU);
    pinMask    = (uint32)TWO_BIT_MASK << shiftAmt;

    /* Clear fields in MUX register first to avoid glitches */
    HWREG(muxRegAddr) &= ~pinMask;

    /* Write value into GMUX register */
    HWREG(muxRegAddr + PORT_MUX_TO_GMUX) = (HWREG(muxRegAddr + PORT_MUX_TO_GMUX) & ~pinMask) |
                                           (((PinMode >> gmuxPinModeShift) & (uint32)TWO_BIT_MASK) << shiftAmt);

    /* Write value into MUX register */
    HWREG(muxRegAddr) |= ((PinMode & (uint32)TWO_BIT_MASK) << shiftAmt);
}

/*
 *Design:MCAL:22390
 */
FUNC(Std_ReturnType, PORT_CODE) Port_IsPinNumberValid(Port_PinType PinNumber)
{
    VAR(Std_ReturnType, AUTOMATIC) returnvalue = (Std_ReturnType)E_NOT_OK;

    if ((PinNumber <= (uint32)101U) || (PinNumber == (uint32)103U) || (PinNumber == (uint32)105U) ||
        (PinNumber == (uint32)127U) || ((PinNumber >= (uint32)160U) && (PinNumber <= (uint32)213U)) ||
        ((PinNumber >= (uint32)219U) && (PinNumber <= (uint32)249U)))

    {
        returnvalue = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return returnvalue;
}

/*
 * Design: MCAL-22704,MCAL-22404
 */
FUNC(Std_ReturnType, PORT_CODE)
Port_ValidateSetPinMode(Port_PinModeType Mode, P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig,
                        P2VAR(uint8, AUTOMATIC, PORT_APPL_DATA) errorIdPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) idx            = 0U;

    if (pinConfig->Port_ModeChangeable == (boolean)TRUE)
    {
        for (idx = ((uint32)0U); idx < pinConfig->Port_NumPortMuxModes; idx++)
        {
            if ((pinConfig->Port_PinMode[idx].Port_PinMuxMode == Mode))
            {
                retVal = (Std_ReturnType)E_OK;
                break;
            }
            else
            {
                *errorIdPtr = PORT_E_PARAM_INVALID_MODE;
            }
        }
    }
    else
    {
        retVal      = (Std_ReturnType)E_NOT_OK;
        *errorIdPtr = PORT_E_MODE_UNCHANGEABLE;
    }
    return (retVal);
}

/*
 *Design: MCAL-29441
 */
FUNC(void, PORT_CODE)
Port_LockConfiguration(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig)
{
    VAR(uint32, AUTOMATIC) pinMask                 = 0U;
    VAR(Port_PinType, AUTOMATIC) pinNumber         = pinConfig->Port_PinId;
    VAR(Std_ReturnType, AUTOMATIC) PortPinNumValid = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) regAddr                 = 0U;

    PortPinNumValid = Port_IsPinNumberValid(pinNumber);

    if (PortPinNumValid != (Std_ReturnType)E_NOT_OK)
    {
        /*Bit position of the pin Number/GPIO number*/
        pinMask = (uint32)ONE_BIT_MASK << (pinNumber % PORT_WIDTH);

        regAddr = ((uint32)GPIOCTRL_BASE + (uint32)((pinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP * 4U) +
                   (uint32)GPIO_O_GPALOCK);

        HWREG(regAddr) |= (pinMask);
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-29440
 */
FUNC(void, PORT_CODE)
Port_UnlockConfiguration(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig)
{
    VAR(uint32, AUTOMATIC) pinMask                 = 0U;
    VAR(Port_PinType, AUTOMATIC) pinNumber         = pinConfig->Port_PinId;
    VAR(Std_ReturnType, AUTOMATIC) PortPinNumValid = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) regAddr                 = 0U;

    PortPinNumValid = Port_IsPinNumberValid(pinNumber);

    if (PortPinNumValid != (Std_ReturnType)E_NOT_OK)
    {
        /*Bit position of the pin Number/GPIO number*/
        pinMask = (uint32)ONE_BIT_MASK << (pinNumber % PORT_WIDTH);

        regAddr = ((uint32)GPIOCTRL_BASE + (uint32)((pinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP * 4U) +
                   (uint32)GPIO_O_GPALOCK);

        HWREG(regAddr) &= ~pinMask;
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *Design: MCAL-29442
 */
FUNC(void, PORT_CODE) Port_CommitConfigurationProcess(Port_PinType pinNumber)
{
    VAR(uint32, AUTOMATIC) pinMask = 0U;
    VAR(uint32, AUTOMATIC) regAddr = 0U;

    /*Bit position of the pin Number/GPIO number*/
    pinMask = (uint32)ONE_BIT_MASK << (pinNumber % PORT_WIDTH);

#if (STD_OFF == PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS)
    /* Lock the Pin */
    regAddr = ((uint32)GPIOCTRL_BASE + (uint32)((pinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP * 4U) +
               (uint32)GPIO_O_GPALOCK);

    HWREG(regAddr) |= (pinMask);
#endif

    /* Commit the Pin */
    regAddr =
        ((uint32)GPIOCTRL_BASE + (uint32)((pinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP * 4U) + (uint32)GPIO_O_GPACR);

    HWREG(regAddr) |= (pinMask);
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*
 * Design: MCAL-22385
 */
static FUNC(void, PORT_CODE) Port_SetPadConfig(Port_PinType PinNumber, Port_PinPadConfigType PinProperty)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) pinMask = 0U;

    if (PORT_PIN_TYPE_NA != PinProperty)
    {
        gpioBaseAddr = (uint32 *)((uint32 *)GPIOCTRL_BASE + ((PinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP));
        pinMask      = (uint32)ONE_BIT_MASK << (PinNumber % PORT_WIDTH);

        /* Enable open drain if necessary */
        if (((uint32)PinProperty & (uint32)PORT_PIN_TYPE_OPEN_DRAIN) != 0U)
        {
            gpioBaseAddr[PORT_ODR_REGS_INDEX] |= pinMask;
        }
        else
        {
            gpioBaseAddr[PORT_ODR_REGS_INDEX] &= ~pinMask;
        }

        /* Enable pull-up if necessary */
        if (((uint32)PinProperty & (uint32)PORT_PIN_TYPE_PULLUP) != 0U)
        {
            gpioBaseAddr[PORT_PUD_REGS_INDEX] &= ~pinMask;
        }
        else
        {
            gpioBaseAddr[PORT_PUD_REGS_INDEX] |= pinMask;
        }
    }
    else
    {
        /*
         * Do Nothing
         */
    }
}

/*
 * Design: MCAL-22386
 */
static FUNC(void, PORT_CODE) Port_SetQualificationMode(Port_PinType PinNumber, Port_PinQualificationMode Qualification)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) qSelIndex;
    VAR(uint32, AUTOMATIC) shiftAmt;

    if (PORT_QUAL_NA > Qualification)
    {
        gpioBaseAddr = (uint32 *)((uint32 *)GPIOCTRL_BASE + ((PinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP));
        shiftAmt     = (uint32)(GPIO_GPAQSEL1_GPIO1_S * (PinNumber % PORT_WIDTH_HALF));
        qSelIndex    = PORT_QSEL_REGS_INDEX + ((PinNumber % PORT_WIDTH) / PORT_WIDTH_HALF);

        /*
         * Write the input qualification mode to the register.
         */
        gpioBaseAddr[qSelIndex] &= ~((uint32)GPIO_GPAQSEL1_GPIO0_M << shiftAmt);
        gpioBaseAddr[qSelIndex] |= (uint32)Qualification << shiftAmt;
    }
    else
    {
        /*
         * Do Nothing
         */
    }
}

/*
 * Design: MCAL-23161
 */
static FUNC(void, PORT_CODE) Port_SetQualificationPeriod(Port_PinType PinNumber, uint32 QualificationPeriod)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) pinMask  = 0U;
    VAR(uint32, AUTOMATIC) regVal   = 0U;
    VAR(uint32, AUTOMATIC) shiftAmt = 0U;
    VAR(uint32, AUTOMATIC) divider  = 2U;

    /*
     * Divide divider (QualificationPeriod) by two to get the value that needs to go into the field.
     * Then shift it into the right place.
     */
    if ((QualificationPeriod >= (uint32)1U) && (QualificationPeriod <= (uint32)510U))
    {
        shiftAmt = (PinNumber % PORT_WIDTH) & ~((uint32)0x7U);
        pinMask  = (uint32)0xFFU << shiftAmt;

        regVal = (QualificationPeriod / divider) << shiftAmt;

        /* Write the divider parameter into the register. */
        gpioBaseAddr = (uint32 *)((uint32 *)GPIOCTRL_BASE + ((PinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP));

        gpioBaseAddr[PORT_CTRL_REGS_INDEX] &= ~pinMask;
        gpioBaseAddr[PORT_CTRL_REGS_INDEX] |= regVal;
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 * Design: MCAL-22387
 */
static FUNC(void, PORT_CODE) Port_SetMasterCore(Port_PinType PinNumber, Port_PinCoreSelect Core)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) cSelIndex = 0U;
    VAR(uint32, AUTOMATIC) shiftAmt  = 0U;

    gpioBaseAddr = (uint32 *)((uint32 *)GPIOCTRL_BASE + ((PinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP));
    shiftAmt     = (uint32)GPIO_GPACSEL1_GPIO1_S * (PinNumber % PORT_WIDTH_QUARTER);
    cSelIndex    = PORT_CSEL_REGS_INDEX + ((PinNumber % PORT_WIDTH) / PORT_WIDTH_QUARTER);

    /* Write the core parameter into the register. */
    gpioBaseAddr[cSelIndex] &= ~((uint32)GPIO_GPACSEL1_GPIO0_M << shiftAmt);
    gpioBaseAddr[cSelIndex] |= (uint32)Core << shiftAmt;
}

/*
 *Design: MCAL-22389
 */
static FUNC(void, PORT_CODE) Port_SetAnalogMode(Port_PinType PinNumber, Port_AnalogModeType Mode)
{
    volatile P2VAR(uint32, AUTOMATIC, REGSPACE) gpioBaseAddr;
    VAR(uint32, AUTOMATIC) pinMask = 0U;

    pinMask      = (uint32)ONE_BIT_MASK << (PinNumber % PORT_WIDTH);
    gpioBaseAddr = (uint32 *)((uint32 *)GPIOCTRL_BASE + ((PinNumber / PORT_WIDTH) * PORT_CTRL_REGS_STEP));

    /* Set the analog mode selection. */
    if (PORT_ANALOG_ENABLED == Mode)
    {
        /* Enable analog mode */
        gpioBaseAddr[PORT_AMSEL_REGS_INDEX] |= pinMask;

        if ((PinNumber >= (uint32)AGPIO_PINS_START_VALUE))
        {
            /* Set AGPIOCTL */
            HWREG((ANALOGSUBSYS_BASE + ASYSCTL_O_AGPIOCTRLH)) |= (pinMask);
        }
    }
    else
    {
        /* Disable analog mode */
        gpioBaseAddr[PORT_AMSEL_REGS_INDEX] &= ~pinMask;

        if ((PinNumber >= (uint32)AGPIO_PINS_START_VALUE))
        {
            /* Clear AGPIOCTL */
            HWREG((ANALOGSUBSYS_BASE + ASYSCTL_O_AGPIOCTRLH)) &= ~(pinMask);
        }
    }
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Port_Priv.c
 *********************************************************************************************************************/
