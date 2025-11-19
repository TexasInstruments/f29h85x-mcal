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
