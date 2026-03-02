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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Dio.Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to DIO
 *
 *********************************************************************************************************************/
#ifndef DIO_PRIV_H
#define DIO_PRIV_H
/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Dio.h"
#include "hw_memmap.h"
#include "hw_gpio.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/* Design: MCAL-23533 */

/** \brief Index of GPIO_DATA register for a port registers set */

#define DIO_DATA_INDEX (GPIO_O_GPADAT / 4U)

/* Design: MCAL-23536 */

/** \brief Index of GPIO_TOGGLE register for a port registers set */

#define DIO_TOGGLE_INDEX (GPIO_O_GPATOGGLE / 4U)

/* Design: MCAL-23535 */

/** \brief Index of GPIO_CLEAR register for a port registers set */

#define DIO_CLEAR_INDEX (GPIO_O_GPACLEAR / 4U)

/* Design: MCAL-23534 */

/** \brief Index of GPIO_SET register for a port registers set */

#define DIO_SET_INDEX (GPIO_O_GPASET / 4U)

/* Design: MCAL-23537 */

/** \brief Port Data register step size */

#define DIO_DATA_REGS_STEP ((GPIO_O_GPBDAT - GPIO_O_GPADAT) / 4U)

/* Design: MCAL-22468 */
/** \brief Width of GPIO register in this platform. */
#define DIO_PORT_WIDTH (32U)

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Checks if the channel ID is valid.
 *
 * Checks if the channel_id passed to the API is valid or not by
 * calculating the Port of the Channel and checking if the port is enabled.
 *
 * \param[in] ChannelId specifies the ID of the general-purpose digital
 * \pre None
 * \post None
 * \return This function returns Std_ReturnType
 * \retval value E_OK: ChannelId is valid.
 *               E_NOT_OK: ChannelId is Invalid.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DIO_CODE)
Dio_IsChannelValid(Dio_ChannelType ChannelId);

/** \brief Checks if the channel group is valid.
 *
 * Checks if the channelgroup_id_ptr passed to the API is valid or not by
 * comparing it with the structure pointers of the current configuration.
 *
 * \param[in] ChannelGroupIdPtr for referencing channel group structures.
 * \pre None
 * \post None
 * \return This function returns Std_ReturnType
 * \retval E_OK: ChannelGroupIdPtr is valid.
 *         E_NOT_OK: ChannelGroupIdPtr is Invalid.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DIO_CODE)
Dio_IsChannelGroupValid(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr);

/** \brief Reads the value present on the specified pin.
 *
 * The value at the specified channel is read, as specified by \e channelId
 * and returned
 *
 * \param[in] channelId is the identifying number of the pin.
 * \pre None
 * \post None
 * \return Returns the logic level(value) on a specified DIO pin of type Dio_LevelType.
 * \retval STD_HIGH: logic level 1
 *         STD_LOW: logic level 0
 *
 *********************************************************************************************************************/
FUNC(Dio_LevelType, DIO_CODE)
Dio_PinReadPriv(Dio_ChannelType channelId);

/** \brief Writes a value to the specified pin.
 *
 * Writes the corresponding bit values to the pin specified by
 * \e channelId. Writing to a channel configured as an input pin has no
 * effect.
 *
 * \param[in] channelId is the identifying number of the pin.
 * \param[in] channelVal is the value to write to the channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE)
Dio_PinWritePriv(Dio_ChannelType channelId, Dio_LevelType channelVal);

/** \brief Writes a value to the specified port.
 *
 * This function writes the value \e port_value to the port specified by the
 * \e portId parameter.
 *
 * \param[in] portId is the DIO port being accessed.
 * \param[in] portValue is the value to write to the port.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE)
Dio_WritePortDataPriv(Dio_PortType portId, Dio_PortLevelType portValue);

/** \brief Writes  a subset of the adjoining bits of a port to a specified level.
 *
 *  This function compute the port value based on the received level, group mask and offset.
 *  Then write the computed port value to the specified port based on the portId received in
 *channelGroupPtr.
 *
 * \param[in] ChannelGroupIdPtr for referencing channel group structures.
 * \param[in] PortValue is the value to write to the port.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE)
Dio_WriteChannelGroupPriv(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr,
                          Dio_PortLevelType PortValue);

/** \brief Reads the data on the specified port.
 *
 * The value at the specified port is read, as specified by \e PortId
 * and writes into the \e PortValue parameter.
 *
 * \param[in] PortId is the DIO port being accessed.
 * \param[out] PortValue stores the value of the corresponding port being referred.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE)
Dio_ReadPortDataPriv(Dio_PortType PortId, Dio_PortLevelType *PortValue);

/** \brief Toggles the present value of the specified channel.
 *
 * Toggles the corresponding bit values to the pin specified by \e ChannelId.
 *
 * \param[in] ChannelId is the identifying number of the pin.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, DIO_CODE)
Dio_PinFlipVal(Dio_ChannelType ChannelId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *
 *  Mark the end of the C bindings section for C++ compilers.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
#endif /* DIO_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Dio_Priv.h
 *********************************************************************************************************************/
