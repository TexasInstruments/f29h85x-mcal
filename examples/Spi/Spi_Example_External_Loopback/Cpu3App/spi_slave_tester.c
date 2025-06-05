// #############################################################################
//
//  FILE:   spi_slave_tester.c
//
//  TITLE:  SPI SLAVE INSTANCE FOR TESTER
//
//! \addtogroup driver_example_list
//! <h1>SPI Digital External Loopback without FIFO Interrupts</h1>
//!
//! This program is used for the slave insatnce of SPI MCAL example: Spi_Example_External_Loopback
//! the SPI FIFOs and interrupts are not used in this code. SPID is configured as a peripheral.
//! This example demonstrates full duplex communication where it transmits and receives data simultaneously.
//!
//!
//! \b External \b Connections \n
//!  SPI Slave => SPI-D instance
//!  -GPIO91 - SPIPICO
//!  -GPIO92 - SPIPOCI
//!  -GPIO93 - SPICLK
//!  -GPIO94 - SPIPTE
//!
//!  SPI Master => SPI-A instance
//!  -GPIO58 - SPIPICO
//!  -GPIO59 - SPIPOCI
//!  -GPIO60 - SPICLK
//!  -GPIO61 - SPIPTE
//!
//
// #############################################################################

//
// Included Files
//
#include "board.h"

//
// RX and TX buffers
//
uint16_t TxData[30] = {0x0100, 0x0302, 0x0504, 0x0706, 0x0908, 0x0B0A, 0x0D0C, 0x0F0E, 0x1110, 0x1312,
                       0x1514, 0x1716, 0x1918, 0x1B1A, 0x1D1C, 0x1F1E, 0x2120, 0x2322, 0x2524, 0x2726,
                       0x2928, 0x2B2A, 0x2D2C, 0x2F2E, 0x3130, 0x3332, 0x3534, 0x3736, 0x3938, 0x3B3A};
uint16_t RxData[30];

//
// Main
//
int main(void)
{
    //
    // Initialize device clock, peripheral clocks and interrupts
    //

    Device_init();

    //
    // Board initialization
    //
    Board_init();
    // PERCONFIG_init_1();
    // SPI_init();

    //
    // Enable PIPE Global Interrupt (for INTs and RTINTs) and INT enable in CPU.
    //
    ENINT;
    Interrupt_enableGlobal();

    for (uint8_t i = 0; i < 30; i++)
    {
        RxData[i] = SPI_pollingNonFIFOTransaction(SPID_BASE, 16U, TxData[i]);
        if (RxData[i] != TxData[i])
        {
            ESTOP0;
        }
    }
}

//
// End of File
//
