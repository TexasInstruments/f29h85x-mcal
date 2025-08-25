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
 *  File:       Port_Priv.h
 *
 *  Description:  Definations of internal Private functions, MACROs and Structures
 *********************************************************************************************************************/

#ifndef PORT_PRIV_H
#define PORT_PRIV_H

/**
 * \addtogroup PORT
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_gpio.h"
#include "hw_asysctl.h"
#include "hw_sysctl.h"
#include "Mcal_Lib_Cpu.h"
#include "Port.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*
 *Design: MCAL-23521, MCAL-22409, MCAL-23523, MCAL-22412, MCAL-22413,MCAL-23521
 */
/** \brief Pin configuration check */
#define PORT_IS_PIN_CONFIGURABLE(x) ((boolean)(((x->Port_ControllerSpecific.Port_PinConfigFlags)) & ((uint8)0x1U)))
/** \brief Pin Analog Support check */
#define PORT_IS_ANALOG_MODE_SUPPORTED(x) ((boolean)(((x->Port_PinConfigFlags) >> (uint8)1U) & (0x1U)))
/** \brief AGPIO Pin check */
#define PORT_IS_PIN_AGPIO(x) ((boolean)(((x->Port_PinConfigFlags) >> 2U) & (0x1U)))
/** \brief AIO Pin check */
#define PORT_IS_PIN_AIO(x) ((boolean)(((x->Port_PinConfigFlags) >> 3U) & (0x1U)))
/** \brief GPIO Pin check */
#define PORT_IS_PIN_GPIO(x) ((boolean)(((x->Port_PinConfigFlags) >> 4U) & (0x1U)))
/** \brief Port Width : 32 */
#define PORT_WIDTH (32U)
/** \brief Half of Port Width */
#define PORT_WIDTH_HALF (16U)
/** \brief Quarter of Port Width */
#define PORT_WIDTH_QUARTER (8U)
/** \brief One bit mask value */
#define ONE_BIT_MASK (1U)
/** \brief Two bit mask value */
#define TWO_BIT_MASK (0x3U)
/** \brief AGPIO Pin start Value */
#define AGPIO_PINS_START_VALUE (224U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * Useful defines used within the driver functions to access gpio registers.
 * Not intended for use by application code.
 *
 * Divide by 4 is for C29x which has word access. (temporary macro declared)
 *
 *****************************************************************************/
/*
 *Design: MCAL-23519,MCAL-23520
 */
/** \brief Port Control register step size */
#define PORT_CTRL_REGS_STEP ((GPIO_O_GPBCTRL - GPIO_O_GPACTRL) / 4U)
/** \brief Port Data register step size */
#define PORT_DATA_REGS_STEP ((GPIO_O_GPBDAT - GPIO_O_GPADAT) / 4U)
/** \brief Port Data read register step size */
#define PORT_DATA_READ_REGS_STEP ((GPIO_O_GPBDAT_R - GPIO_O_GPADAT_R) / 4U)

/** \brief Port Control register Index value */
#define PORT_CTRL_REGS_INDEX (GPIO_O_GPACTRL / 4U) /* 0U */
/** \brief Port Q-Select register Index value */
#define PORT_QSEL_REGS_INDEX (GPIO_O_GPAQSEL1 / 4U) /* 1U */
/** \brief Port MUX register Index value */
#define PORT_MUX_REGS_INDEX (GPIO_O_GPAMUX1 / 4U) /* 3U */
/** \brief Port Pull up disable register Index value */
#define PORT_PUD_REGS_INDEX (GPIO_O_GPAPUD / 4U) /* 6U */
/** \brief Port Invert polarity register Index value */
#define PORT_INV_REGS_INDEX (GPIO_O_GPAINV / 4U) /* 8U */
/** \brief Port Open drain register Index value */
#define PORT_ODR_REGS_INDEX (GPIO_O_GPAODR / 4U) /* 9U */
/** \brief Port AM Select register Index value */
#define PORT_AMSEL_REGS_INDEX (10U) /* 10U */
/** \brief Port GMUX register Index value */
#define PORT_GMUX_REGS_INDEX (GPIO_O_GPAGMUX1 / 4U) /* 16U */
/** \brief Port Core Select register Index value */
#define PORT_CSEL_REGS_INDEX (GPIO_O_GPACSEL1 / 4U) /* 20U */
/** \brief Port Lock configuration register Index value */
#define PORT_LOCK_REGS_INDEX (GPIO_O_GPALOCK / 4U) /* 30U */
/** \brief Port lock commit register Index value */
#define PORT_CR_REGS_INDEX (GPIO_O_GPACR / 4U) /* 31U */

/** \brief Port Data register Index value */
#define PORT_DAT_REGS_INDEX (GPIO_O_GPADAT / 4U) /* 0U */
/** \brief Port Data Set register Index value */
#define PORT_SET_REGS_INDEX (GPIO_O_GPASET / 4U) /* 1U */
/** \brief Port Data Clear register Index value */
#define PORT_CLEAR_REGS_INDEX (GPIO_O_GPACLEAR / 4U) /* 2U */
/** \brief Port Data Toggle register Index value */
#define PORT_TOGGLE_REGS_INDEX (GPIO_O_GPATOGGLE / 4U) /* 3U */
/** \brief Port Data Direction Set register Index value */
#define PORT_DIR_REGS_INDEX (GPIO_O_GPADIR / 4U) /* 4U */

/** \brief Port Data read register Index value */
#define GPIO_DAT_R_REGS_INDEX (0U)

/** \brief Port MUX to GMUX difference value */
#define PORT_MUX_TO_GMUX (GPIO_O_GPAGMUX1 - GPIO_O_GPAMUX1)

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Sets the pad/pull configuration for the specified pin.
 *
 * This function sets the controller specific parameters for the specified pin.
 * The pin is specified by its numerical value. For example, GPIO34 is
 * specified by passing 34 as \e PinNumber.
 *
 * \param[in] PinConfigPtr is the pointer to the pin config structure.
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if pad configuration is success
 * \retval E_NOT_OK if pad configuration Fails
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_CODE)
Port_SetCntSpConfig(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfigPtr);

/** \brief Writes the level value to the specified pin.
 *
 * Writes the corresponding bit values to the output pin specified by
 * \e PinNumber.  Writing to a pin configured as an input pin has no effect.
 *
 * The pin is specified by its numerical value. For example, GPIO34 is
 * specified by passing 34 as \e PinNumber.
 *
 * \param[in] PinConfigPtr is the pointer to the pin config structure.
 * \param[in] PinLevel is the value to write to the pin.
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if Level Set success
 * \retval E_NOT_OK if Level Set Fails
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_CODE)
Port_SetPinLevel(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfigPtr,
                 Port_PinLevelValueType PinLevel);

/** \brief Set pins as Low Power wakeup modes GPIO pins.
 *
 * This function Writes the corresponding bit values to the LPM registers.
 *
 * \param[in] PinConfig is the pointer to the pin config structure.
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if Wakeup Enable is success
 * \retval E_NOT_OK if Wakeup Enable is failure
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_CODE)
Port_EnableLPMWakeUpPin(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfig);

/** \brief Configures the Pin Mode function of a PORT pin.
 *
 * This function configures the pin mux that selects the peripheral function
 * associated with a particular PORT pin.  Only one peripheral function at a
 * time can be associated with a PORT pin, and each peripheral function should
 * only be associated with a single PORT pin at a time (despite the fact that
 * many of them can be associated with more than one PORT pin).
 *
 * The available mappings are supplied in Port_Pin_Map.h
 *
 * \param[in] PinMode is the pin configuration value for pin
 * \pre None
 * \post None
 * \return returnValue
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_SetPinModeConfig(uint32 PinMode);

/** \brief Sets the direction of the specified pin.
 *
 * This function configures the specified pin on the selected GPIO port as
 * either input or output.
 *
 * The parameter \e PinDirection is an enumerated data type that can be one of
 * the following values:
 *
 * - \b PORT_PIN_IN
 * - \b PORT_PIN_OUT
 *
 * where \b PORT_PIN_IN specifies that the pin is programmed as an input
 * and \b PORT_PIN_OUT specifies that the pin is programmed as an output.
 *
 * The pin is specified by its numerical value. For example, GPIO34 is
 * specified by passing 34 as \e pin.
 *
 * \param[in] PinConfigPtr is the pointer to the pin config structure.
 * \param[in] PinDirection is the pin direction mode.
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if pin direction is set successfully.
 * \retval E_NOT_OK if pin direction is Not set successfully.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_CODE)
Port_SetDirectionMode(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) PinConfigPtr,
                      Port_PinDirectionType PinDirection);

/** \brief Checks if the provided pin number is Valid or Not.
 *
 * This function Checks if the pin number provided in the configuration is valid or not.
 *
 *
 * \param[in] PinNumber is the pin num value provided in the pin configuration
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if pin number is valid.
 * \retval E_NOT_OK if pin number is not valid.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_CODE) Port_IsPinNumberValid(Port_PinType PinNumber);

/** \brief Validates the pin Mode provided.
 *
 * This function checks with the Pin mode provided for the particular pin config is valid mode or
 *not
 *
 * \param[in] Mode is the Mode passed to Pin
 * \param[in] pinConfig is the Pointer having pin config
 * \param[in] errorIdPtr is the error pointer
 * \pre None
 * \post None
 * \return retVal
 * \retval E_OK if valid mode is provided
 * \retval E_NOT_OK if mode provided is not valid
 *
 ****************************************************************************/
FUNC(Std_ReturnType, PORT_CODE)
Port_ValidateSetPinMode(Port_PinModeType Mode, P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig,
                        P2VAR(uint8, AUTOMATIC, PORT_APPL_DATA) errorIdPtr);

/** \brief Locks the Critical Configuration registers for the passed Pin.
 *
 * This function Locks the Critical Configuration registers for the passed Pin
 *
 * \param[in] pinConfig is the Pointer having pin config
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ****************************************************************************/
FUNC(void, PORT_CODE)
Port_LockConfiguration(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig);

/** \brief Unlocks the Critical Configuration registers for the passed Pin.
 *
 * This function Unlocks the Critical Configuration registers for the passed Pin
 *
 * \param[in] pinConfig is the Pointer having pin config
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ****************************************************************************/
FUNC(void, PORT_CODE)
Port_UnlockConfiguration(P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig);

/** \brief Locks and Commit the Critical Configuration registers for the passed Pin.
 *
 * This function Locks and Commit the Critical Configuration registers for the passed Pin
 *
 * \param[in] pinNumber Pin Number
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ****************************************************************************/
FUNC(void, PORT_CODE) Port_CommitConfigurationProcess(Port_PinType pinNumber);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* PORT_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Port_Priv.h
 *********************************************************************************************************************/
