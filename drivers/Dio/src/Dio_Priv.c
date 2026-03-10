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
Dio_IsChannelValid(Dio_ChannelType ChannelId)
{
    VAR(Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_NOT_OK;

    VAR(uint32, AUTOMATIC) port_num = (uint32)(ChannelId / DIO_PORT_WIDTH);

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
