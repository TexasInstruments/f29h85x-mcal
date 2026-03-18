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
 *  File:       AppUtils.c
 *  Generator:  None
 *
 *  Description:  AppUtils source file
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "AppUtils.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define UART_BASE (UARTA_BASE)

#define UART_BAUDRATE (115200U)
#define UART_CONFIG   (0x00000060UL)

#define UART_TX_PIN (2U)
#define UART_RX_PIN (3U)

#define UART_TX_PIN_CONFIG (0x000C0405U)
#define UART_RX_PIN_CONFIG (0x000C0605U)

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

void AppUtils_AssertFunc(uint32 Condition, char *Str, char *FileName, uint32 LineNum)
{
    if (Condition == 0U)
    {
        /* Print the statement */
        AppUtils_Printf(" Assertion @ Line: %d in file %s: condition %s : failed !!!\n", LineNum, FileName, Str);
#if defined(DEBUG)
        assert(Condition);
#else
        while (TRUE)
        {
        }
#endif /* #if defined(DEBUG) */
    }

    return;
}

void Uart_DisableModule()
{
    /* Wait for end of TX. */
    while ((HWREG(UART_BASE + UART_O_FR) & UART_FR_BUSY) == UART_FR_BUSY)
    {
    }

    /* Disable the FIFO. */
    // HWREG(UART_BASE + UART_O_LCRH) &= ~(UART_LCRH_FEN);

    /* Disable the UART. */
    HWREG(UART_BASE + UART_O_CTL) &= ~(UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);
}

void Uart_EnableModule()
{
    /* Enable the FIFO */
    // HWREG(UART_BASE + UART_O_LCRH) |= UART_LCRH_FEN;

    /* Enable RX, TX, and the UART. */
    HWREG(UART_BASE + UART_O_CTL) |= (UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);
}

sint8 Uart_ReadChar()
{
    /* Wait until a char is available. */
    while ((HWREG(UART_BASE + UART_O_FR) & UART_FR_RXFE) == UART_FR_RXFE)
    {
    }
    /* Now get the char */
    return ((sint8)HWREG(UART_BASE + UART_O_DR));
}

void Uart_WriteChar(uint8 Data)
{
    /* Wait until space is available */
    while ((HWREG(UART_BASE + UART_O_FR) & UART_FR_TXFF) == UART_FR_TXFF)
    {
    }
    /* Send the char. */
    HWREG(UART_BASE + UART_O_DR) = Data;
}

void Uart_SetConfig(uint32 UartClk, uint32 Baudrate, uint32 Config)
{
    uint32 fbrdiv;

    /* Stop the UART. */
    Uart_DisableModule();

    /* Check if the requiredn baud-rate is greater than the maximum rate supported */
    if ((Baudrate * 16U) > UartClk)
    {
        /* Enable high speed mode. */
        HWREG(UART_BASE + UART_O_CTL) |= UART_CTL_HSE;

        /* Half the supplied baud rate to compensate for enabling high speed mode */
        Baudrate /= 2U;
    }
    else
    {
        /* Disable high speed mode. */
        HWREG(UART_BASE + UART_O_CTL) &= ~(UART_CTL_HSE);
    }

    /* Compute the fractional baud rate divider. */
    fbrdiv = (((UartClk * 8U) / Baudrate) + 1U) / 2U;

    /* Set the baud rate. */
    HWREG(UART_BASE + UART_O_IBRD) = (uint16)(fbrdiv / 64U);
    HWREG(UART_BASE + UART_O_FBRD) = (uint8)(fbrdiv % 64U);

    /* Set parity, data length, and number of stop bits. */
    HWREG(UART_BASE + UART_O_LCRH) = (uint8)Config;

    /* Start the UART. */
    Uart_EnableModule();
}

void AppUtils_DeInit(void)
{
    Uart_DisableModule();
}

void AppUtils_Init(uint32 UartClk)
{
    /* Configure UART */
    Uart_SetConfig(UartClk, UART_BAUDRATE, UART_CONFIG);
}

sint8 AppUtils_GetChar(void)
{
    return Uart_ReadChar();
}

sint32 AppUtils_GetNum(void)
{
    sint32 number = 0;
    sint32 sign   = 1;
    sint8  rx_data;
    sint8  a = 48, b = 57, c = 45;

    rx_data = Uart_ReadChar();

    /* Check if the received data is a positive number or a negative number*/
    if ((a <= rx_data) && (rx_data <= b))
    {
        number = number * 10 + (rx_data - 0x30);
    }
    else if (c == rx_data)
    {
        sign = -1;
    }

    while (1)
    {
        rx_data = Uart_ReadChar();

        /* Checking if the entered character is a carriage return. Pressing the
         * 'Enter' key on the keyboard executes a carriage return on the serial console. */
        if ((sint8)'\r' == rx_data)
        {
            break;
        }
        /*  Subtracting 0x30 to convert from ASCII standard to hexadecimal */
        number = number * 10 + (rx_data - 0x30);
    }

    /* Multiply the number with the sign. */
    number = number * sign;
    return number;
}

void AppUtils_Printf(const char *Message, ...)
{
    char            buffer[1000];
    uint32          i = 0U;
    volatile sint32 string_size;

    /* This type is used to retrieve the additional arguments of a function. */
    va_list var_arg;

    /*
     * Initializes a variable argument list.
     * Initializes var_arg to retrieve the additional arguments after parameter Message.
     */
    va_start(var_arg, Message);

    /*
     * Write formatted data from variable argument list to sized buffer
     * Returns the number of characters that would have been written if the buffer had been
     * sufficiently large, not counting the terminating null character.
     */
    string_size = vsnprintf(buffer, sizeof(buffer), Message, var_arg);

    if (string_size > 0)
    {
        for (i = 0U; buffer[i] != '\0'; i++)
        {
            Uart_WriteChar((uint8)buffer[i]);
        }
    }

    va_end(var_arg);
    return;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: AppUtils.c
 *********************************************************************************************************************/
