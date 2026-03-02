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
 *  File:       Dio_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains private function definitions for DIO
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Dio_Priv.h"

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
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/* Design: MCAL-22525,MCAL-22513 */
#if (STD_ON == DIO_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, DIO_CODE)
Dio_IsChannelValid(Dio_ChannelType channelId)
{
    VAR(Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_NOT_OK;

    VAR(uint32, AUTOMATIC) port_num = (uint32)(channelId / DIO_PORT_WIDTH);

    /*  Check if the port configuration is enable else return E_NOT_OK. */
    if (0U != (DIO_CFG_ENABLED_PORT_MASK & ((uint32)1U << port_num)))
    {
        status = (Std_ReturnType)E_OK;
    }

    return (status);
}
#endif

/* Design: MCAL-22683 */
#if (STD_ON == DIO_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, DIO_CODE)
Dio_IsChannelGroupValid(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_NOT_OK;

    /*  Check if the channel group configuration is valid else return E_NOT_OK. */
    for (uint32 i = 0U; i < (uint32)DIO_MAX_NO_OF_CHANNEL_GROUPS; i++)
    {
        if (Dio_ChannelGroupRef[i] == ChannelGroupIdPtr)
        {
            status = (Std_ReturnType)E_OK;
            break;
        }
    }

    return (status);
}
#endif

/* Design:  MCAL-22520,MCAL-22516 */
FUNC(Dio_LevelType, DIO_CODE)
Dio_PinReadPriv(Dio_ChannelType channelId)
{
    VAR(uint32, AUTOMATIC) reg_val;
    VAR(Dio_LevelType, AUTOMATIC) status;
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpio_data_reg;

    gpio_data_reg = (uint32 *)((uint32 *)GPIODATA_BASE + ((channelId / DIO_PORT_WIDTH) * DIO_DATA_REGS_STEP));

    reg_val = ((gpio_data_reg[DIO_DATA_INDEX] >> (channelId % DIO_PORT_WIDTH)) & (uint32)0x1U);

    status = ((uint32)0U != reg_val) ? (Dio_LevelType)STD_HIGH : (Dio_LevelType)STD_LOW;

    return (status);
}

/* Design:  MCAL-22521,MCAL-22517,MCAL-22518,MCAL-22519 */
FUNC(void, DIO_CODE)
Dio_PinWritePriv(Dio_ChannelType channelId, Dio_LevelType channelVal)
{
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpio_data_reg;
    VAR(uint32, AUTOMATIC) pin_mask_val;

    gpio_data_reg = (uint32 *)((uint32 *)GPIODATA_BASE + ((channelId / DIO_PORT_WIDTH) * DIO_DATA_REGS_STEP));
    pin_mask_val  = (uint32)1U << (channelId % DIO_PORT_WIDTH);

    /*  Writing 0 to either SET or CLEAR register has no effect */
    if (((Dio_LevelType)STD_LOW) == channelVal)
    {
        gpio_data_reg[DIO_CLEAR_INDEX] = pin_mask_val;
    }
    else
    {
        gpio_data_reg[DIO_SET_INDEX] = pin_mask_val;
    }
}

/* Design:  MCAL-22523,MCAL-22517,MCAL-22518,MCAL-22519 */
FUNC(void, DIO_CODE)
Dio_WritePortDataPriv(Dio_PortType portId, Dio_PortLevelType portValue)
{
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpio_data_reg;
    VAR(uint32, AUTOMATIC) set_bits;
    VAR(uint32, AUTOMATIC) clear_bits;

    set_bits   = portValue;
    clear_bits = ~portValue;

    /* Get the starting address of the port's registers and write to DATA. */
    gpio_data_reg = (uint32 *)((uint32 *)GPIODATA_BASE + ((uint32)portId * DIO_DATA_REGS_STEP));
    /* Writing 1 will clear the bit and Writing 0 has no effect. */
    gpio_data_reg[DIO_CLEAR_INDEX] = clear_bits;

    /* Writing 1 will set the bit and Writing 0 has no effect. */
    gpio_data_reg[DIO_SET_INDEX] = set_bits;
}

/* Design: MCAL-22682,MCAL-22517,MCAL-22518,MCAL-22519 */
FUNC(void, DIO_CODE)
Dio_WriteChannelGroupPriv(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr,
                          Dio_PortLevelType level)
{
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpio_data_reg;
    VAR(uint32, AUTOMATIC) set_bits;
    VAR(uint32, AUTOMATIC) clear_bits;

    set_bits   = ((level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
    clear_bits = ((~level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);

    /* Get the starting address of the port's registers and write to DATA. */
    gpio_data_reg = (uint32 *)((uint32 *)GPIODATA_BASE + ((uint32)ChannelGroupIdPtr->port * DIO_DATA_REGS_STEP));

    /* Writing 1 will clear the bit and Writing 0 has no effect. */
    gpio_data_reg[DIO_CLEAR_INDEX] = clear_bits;

    /* Writing 1 will set the bit and Writing 0 has no effect. */
    gpio_data_reg[DIO_SET_INDEX] = set_bits;
}

/* Design: MCAL-22524,MCAL-22515 */
FUNC(void, DIO_CODE)
Dio_PinFlipVal(Dio_ChannelType ChannelId)
{
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpioDataReg;
    VAR(uint32, AUTOMATIC) pinMaskVal;

    gpioDataReg = (uint32 *)((uint32 *)GPIODATA_BASE + ((ChannelId / DIO_PORT_WIDTH) * DIO_DATA_REGS_STEP));

    pinMaskVal = (uint32)1U << (ChannelId % DIO_PORT_WIDTH);

    gpioDataReg[DIO_TOGGLE_INDEX] = pinMaskVal;
}

/* Design: MCAL-22522,MCAL-22516 */
FUNC(void, DIO_CODE)
Dio_ReadPortDataPriv(Dio_PortType PortId, Dio_PortLevelType *PortValue)
{
    P2VAR(volatile uint32, AUTOMATIC, REGSPACE) gpioDataReg;
    /* Get the starting address of the registers. */
    gpioDataReg = (uint32 *)((uint32 *)GPIODATA_BASE + ((uint32)PortId * DIO_DATA_REGS_STEP));

    /* Return the data of the port. */
    *PortValue = gpioDataReg[DIO_DATA_INDEX];
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Dio_Priv.c
 *********************************************************************************************************************/
