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
uint16_t TxData[64] = {0x0100, 0x0302, 0x0504, 0x0706, 0x0908, 0x0B0A, 0x0D0C, 0x0F0E, 0x1110, 0x1312, 0x1514,
                       0x1716, 0x1918, 0x1B1A, 0x1D1C, 0x1F1E, 0x2120, 0x2322, 0x2524, 0x2726, 0x2928, 0x2B2A,
                       0x2D2C, 0x2F2E, 0x3130, 0x3332, 0x3534, 0x3736, 0x3938, 0x3B3A, 0x3D3C, 0x3F3E, 0x4140,
                       0x4342, 0x4544, 0x4746, 0x4948, 0x4B4A, 0x4D4C, 0x4F4E, 0x5150, 0x5352, 0x5554, 0x5756,
                       0x5958, 0x5B5A, 0x5D5C, 0x5F5E, 0x6160, 0x6362, 0x6564, 0x6766, 0x6968, 0x6B6A, 0x6D6C,
                       0x6F6E, 0x7170, 0x7372, 0x7574, 0x7776, 0x7978, 0x7B7A, 0x7D7C, 0x7F7E};
uint16_t RxData[64];

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

    for (uint8_t i = 0; i < 64; i++)
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
