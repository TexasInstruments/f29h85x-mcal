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
 *  File:         Cdd_Xbar_Gpio_interrupt.c
 *  Generator:    None
 *
 *  Description:  This example application demonstrates the external interrupt feature by using it in conjunction with
 *  the input and output XBARs.
 *  The GPIO is toggled and connected to the input XBAR, while simultaneously triggering an external interrupt on the
 *  rising edge at the GPIO pin using XINT1(External Interrupt 1).
 *  The interrupt increments a counter 'count'.
 *  In addition to triggering an interrupt, the input signal is routed from the input XBAR to the output XBAR so that
 *  the output can be observed via oscilloscope or logic analyzer on a separate pin.
 *                             ___________           ________________
 *                GPIO0-------|INPUT XBAR1|---------| OUTPUT XBAR 1  |-------GPIO2
 *                            |           |         |________________|
 *                            |           |
 *                            |___________|---------triggers interrupt using XINT1
 *
 * Note : This example application uses APIs derived from F29H85X-SDK GPIO module, such as GPIO_setInterruptType and
 * GPIO_enableInterrupt. Users can use more such APIs from F29H85X-SDK GPIO APIs according to the use case.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "EcuM.h"
#include "Dio.h"
#include "hw_xint.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * Values that can be passed to GPIO_setInterruptType() and GPIO_enableInterrupt as the extIntNum parameter.
 *********************************************************************************************************************/
typedef enum
{
    GPIO_INT_XINT1 = 0,  //!< External Interrupt 1
    GPIO_INT_XINT2 = 2,  //!< External Interrupt 2
    GPIO_INT_XINT3 = 4,  //!< External Interrupt 3
    GPIO_INT_XINT4 = 6,  //!< External Interrupt 4
    GPIO_INT_XINT5 = 8   //!< External Interrupt 5
} GPIO_ExternalIntNum;

/*********************************************************************************************************************
 * Values that can be passed to GPIO_setInterruptType() as the intType parameter.
 *********************************************************************************************************************/
typedef enum
{
    GPIO_INT_TYPE_FALLING_EDGE = 0x00,  //!< Interrupt on falling edge
    GPIO_INT_TYPE_RISING_EDGE  = 0x04,  //!< Interrupt on rising edge
    GPIO_INT_TYPE_BOTH_EDGES   = 0x0C   //!< Interrupt on both edges
} GPIO_IntType;

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
Dio_LevelType          Dio_ChannelLevel;
static volatile uint32 count  = 0U;
static boolean         status = TRUE;
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Sets the interrupt type for the specified pin.
 *
 * This function sets up the various interrupt trigger mechanisms for the specified pin on the selected GPIO port.
 *
 * \param[in] extIntNum specifies the external interrupt
 * \param[in] intType specifies the type of interrupt trigger mechanism.
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
static inline void GPIO_setInterruptType(GPIO_ExternalIntNum extIntNum, GPIO_IntType intType);
/** \brief Enables the specified external interrupt.
 *
 * This function enables the indicated external interrupt sources. Only the sources that are enabled can be reflected to
 * the processor interrupt.
 *
 * \param[in] extIntNum specifies the external interrupt
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
static inline void GPIO_enableInterrupt(GPIO_ExternalIntNum extIntNum);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* Example Application */
int main(void)
{
    uint8 loop;
    DeviceSupport_Init();
    /* Configure the crossbar and init MCU */
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------"
        "\n");

    AppUtils_Printf("Setting interrupt type and enabling interrupt...\n");
    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_RISING_EDGE);
    GPIO_enableInterrupt(GPIO_INT_XINT1);

    for (loop = 0U; loop < 0xFFU; loop++)
    {
        /* Setting the GPIO0 to STD_HIGH */
        Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_HIGH);
        /* Reading the value at OUTPUTXBAR1 */
        Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
        if (STD_HIGH == Dio_ChannelLevel)
        {
            /* Setting the GPIO0 to STD_LOW */
            Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_LOW);
            /* Reading the value at OUTPUTXBAR1 */
            Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
            if (STD_LOW != Dio_ChannelLevel)
            {
                status = FALSE;
                break;
            }
        }
        else
        {
            status = FALSE;
            break;
        }
    }
    if (status == TRUE)
    {
        AppUtils_Printf("count: %d\n", count);
        AppUtils_Printf(
            "================================================================================="
            "\n");
        AppUtils_Printf("PASS: Cdd_Xbar_Gpio_interrupt Sample application passed \n");
    }
    else
    {
        AppUtils_Printf("count: %d\n", count);
        AppUtils_Printf(
            "================================================================================="
            "\n");
        AppUtils_Printf("FAIL: Cdd_Xbar_Gpio_interrupt Sample application failed \n");
    }
    return 0;
}

static inline void GPIO_setInterruptType(GPIO_ExternalIntNum extIntNum, GPIO_IntType intType)
{
    /* Write the selected polarity to the appropriate register.*/
    HWREGH(XINT_BASE + (uint16)extIntNum) =
        (HWREGH(XINT_BASE + (uint16)extIntNum) & ~XINT_1CR_POLARITY_M) | (uint16)intType;
}

static inline void GPIO_enableInterrupt(GPIO_ExternalIntNum extIntNum)
{
    /* Set the enable bit for the specified interrupt.*/
    HWREGH(XINT_BASE + (uint16)extIntNum) |= XINT_1CR_ENABLE;
}

void ISR_GPIO_XINT(void)
{
    count++;
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Gpio_interrupt.c
 *********************************************************************************************************************/
