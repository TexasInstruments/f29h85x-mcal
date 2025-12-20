// ###########################################################################
//
//  FILE:   asysctl.h
//
//  TITLE:  C29x driver for Analog System Control.
//
// ###########################################################################
//  //
//	Copyright: Copyright (C) Texas Instruments Incorporated
//	All rights reserved not granted herein.
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
//   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

// ###########################################################################

#ifndef ASYSCTL_H
#define ASYSCTL_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//
//! \addtogroup asysctl_api ASysCtl
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include "sdk_mcal_integration.h"
#include "hw_asysctl.h"
#include "hw_memmap.h"
#include "hw_types.h"

//
// These values can be used as the parameter \e config in the function
// ASysCtl_setAGPIOFilter functions
//
#define ASYSCTL_AGPIOFILTER_BYPASS  0U  // Filter bypass (min ACQPS = 90ns)
#define ASYSCTL_AGPIOFILTER_333OHM  1U  // 333Ohm filter (min ACQPS = 125ns)
#define ASYSCTL_AGPIOFILTER_500OHM  2U  // 500 Ohm filter (min ACQPS = 160ns)
#define ASYSCTL_AGPIOFILTER_1000OHM 3U  // 1KOhm filter  (min ACQPS = 230ns)

//*****************************************************************************
//
//! Defines for VREF configurations
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_VREFHIAB  = 0,
    ASYSCTL_VREFHICDE = 1
} ASysCtl_Vref;

//*****************************************************************************
//
//! Defines for VREF configurations
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_VREF_EXTERNAL       = 0x001,
    ASYSCTL_VREF_INTERNAL_3_3_V = 0x000,
    ASYSCTL_VREF_INTERNAL_2_5_V = 0x100
} ASysCtl_VrefMode;

//*****************************************************************************
//
//! Defines for IO Buffer configurations
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_IOBUFF_GPIO10 = 0,
    ASYSCTL_IOBUFF_GPIO15 = 1,
    ASYSCTL_IOBUFF_GPIO18 = 2,
    ASYSCTL_IOBUFF_GPIO22 = 3,
    ASYSCTL_IOBUFF_GPIO23 = 4,
    ASYSCTL_IOBUFF_GPIO29 = 5,
} ASysCtl_IOBuffer;

//*****************************************************************************
//
//! Defines for IO Buffer configurations
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_IOBUFF_DRIVE_4_MA  = 0,  //! IO will have 4ma drive
    ASYSCTL_IOBUFF_DRIVE_20_MA = 1,  //! IO will support 20ma drive for PMBUS
} ASysCtl_IOBufferDrive;

//*****************************************************************************
//
//! Defines for IO Buffer configurations
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_IOBUFF_MODE_3_3_V  = 0,  //! IO is set to operate at 3.3v
    ASYSCTL_IOBUFF_MODE_1_35_V = 1,  //! IO is set to operate at 1.35v for PMBUS
} ASysCtl_IOBufferMode;

//*****************************************************************************
//
//! Defines which internal node is selected to come out on the INTERNALTEST node
//! connected to ADC
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_TEST_NODE_NO_CONN            = 0U,   //!< No Internal Connection
    ASYSCTL_TEST_NODE_VDDCORE            = 1U,   //!< Core VDD (1.2V) voltage
    ASYSCTL_TEST_NODE_VDDA               = 2U,   //!< VDDA voltage
    ASYSCTL_TEST_NODE_VSSA               = 3U,   //!< VSSA - Analog ground pin
    ASYSCTL_TEST_NODE_VREFLOAB           = 4U,   //!< VREFLOA pin voltage
    ASYSCTL_TEST_NODE_CDAC1H             = 5U,   //!< CMPSS1 High DAC output
    ASYSCTL_TEST_NODE_CDAC1L             = 6U,   //!< CMPSS1 Low DAC output
    ASYSCTL_TEST_NODE_CDAC2H             = 7U,   //!< CMPSS2 High DAC output
    ASYSCTL_TEST_NODE_CDAC2L             = 8U,   //!< CMPSS2 Low DAC output
    ASYSCTL_TEST_NODE_CDAC3H             = 9U,   //!< CMPSS3 High DAC output
    ASYSCTL_TEST_NODE_CDAC3L             = 10U,  //!< CMPSS3 Low DAC output
    ASYSCTL_TEST_NODE_CDAC4H             = 11U,  //!< CMPSS4 High DAC output
    ASYSCTL_TEST_NODE_CDAC4L             = 12U,  //!< CMPSS4 Low DAC output
    ASYSCTL_TEST_NODE_CDAC5H             = 13U,  //!< CMPSS5 High DAC output
    ASYSCTL_TEST_NODE_CDAC5L             = 14U,  //!< CMPSS5 Low DAC output
    ASYSCTL_TEST_NODE_CDAC6H             = 15U,  //!< CMPSS6 High DAC output
    ASYSCTL_TEST_NODE_CDAC6L             = 16U,  //!< CMPSS6 Low DAC output
    ASYSCTL_TEST_NODE_CDAC7H             = 17U,  //!< CMPSS7 High DAC output
    ASYSCTL_TEST_NODE_CDAC7L             = 18U,  //!< CMPSS7 Low DAC output
    ASYSCTL_TEST_NODE_CDAC8H             = 19U,  //!< CMPSS8 High DAC output
    ASYSCTL_TEST_NODE_CDAC8L             = 20U,  //!< CMPSS8 Low DAC output
    ASYSCTL_TEST_NODE_CDAC9H             = 21U,  //!< CMPSS9 High DAC output
    ASYSCTL_TEST_NODE_CDAC9L             = 22U,  //!< CMPSS9 Low DAC output
    ASYSCTL_TEST_NODE_CDAC10H            = 23U,  //!< CMPSS10 High DAC output
    ASYSCTL_TEST_NODE_CDAC10L            = 24U,  //!< CMPSS10 Low DAC output
    ASYSCTL_TEST_NODE_CDAC11H            = 25U,  //!< CMPSS11 High DAC output
    ASYSCTL_TEST_NODE_CDAC11L            = 26U,  //!< CMPSS11 Low DAC output
    ASYSCTL_TEST_NODE_CDAC12H            = 27U,  //!< CMPSS12 High DAC output
    ASYSCTL_TEST_NODE_CDAC12L            = 28U,  //!< CMPSS12 Low DAC output
    ASYSCTL_TEST_NODE_ENZ_CALIB_GAIN_3P3 = 29U,  //!< All ADCs are placed in gain
                                                 //!< calibration mode
    ASYSCTL_TEST_NODE_VREFLOCDE = 49U            //!< VREFLOCDE pin voltage
} ASysCtl_InternalTestNode;

//*****************************************************************************
//
//! Defines which CMP to select.
//
//*****************************************************************************

typedef enum
{
    ASYSCTL_CMP1_HP_0 = 0x00000000,
    ASYSCTL_CMP1_HP_1 = 0x00000001,
    ASYSCTL_CMP1_HP_2 = 0x00000002,
    ASYSCTL_CMP1_HP_3 = 0x00000003,
    ASYSCTL_CMP1_HP_4 = 0x00000004,
    ASYSCTL_CMP1_HP_5 = 0x00000005,
    ASYSCTL_CMP1_HP_6 = 0x00000006,

    ASYSCTL_CMP2_HP_0 = 0x00000300,
    ASYSCTL_CMP2_HP_1 = 0x00000301,
    ASYSCTL_CMP2_HP_2 = 0x00000302,
    ASYSCTL_CMP2_HP_3 = 0x00000303,
    ASYSCTL_CMP2_HP_4 = 0x00000304,
    ASYSCTL_CMP2_HP_5 = 0x00000305,
    ASYSCTL_CMP2_HP_6 = 0x00000306,

    ASYSCTL_CMP3_HP_0 = 0x00000600,
    ASYSCTL_CMP3_HP_1 = 0x00000601,
    ASYSCTL_CMP3_HP_2 = 0x00000602,
    ASYSCTL_CMP3_HP_3 = 0x00000603,
    ASYSCTL_CMP3_HP_4 = 0x00000604,
    ASYSCTL_CMP3_HP_5 = 0x00000605,
    ASYSCTL_CMP3_HP_6 = 0x00000606,

    ASYSCTL_CMP4_HP_0 = 0x00000900,
    ASYSCTL_CMP4_HP_1 = 0x00000901,
    ASYSCTL_CMP4_HP_2 = 0x00000902,
    ASYSCTL_CMP4_HP_3 = 0x00000903,
    ASYSCTL_CMP4_HP_4 = 0x00000904,
    ASYSCTL_CMP4_HP_5 = 0x00000905,
    ASYSCTL_CMP4_HP_6 = 0x00000906,

    ASYSCTL_CMP5_HP_0 = 0x00000C00,
    ASYSCTL_CMP5_HP_1 = 0x00000C01,
    ASYSCTL_CMP5_HP_2 = 0x00000C02,
    ASYSCTL_CMP5_HP_3 = 0x00000C03,
    ASYSCTL_CMP5_HP_4 = 0x00000C04,
    ASYSCTL_CMP5_HP_5 = 0x00000C05,
    ASYSCTL_CMP5_HP_6 = 0x00000C06,

    ASYSCTL_CMP6_HP_0 = 0x00000F00,
    ASYSCTL_CMP6_HP_1 = 0x00000F01,
    ASYSCTL_CMP6_HP_2 = 0x00000F02,
    ASYSCTL_CMP6_HP_3 = 0x00000F03,
    ASYSCTL_CMP6_HP_4 = 0x00000F04,
    ASYSCTL_CMP6_HP_5 = 0x00000F05,
    ASYSCTL_CMP6_HP_6 = 0x00000F06,

    ASYSCTL_CMP7_HP_0 = 0x00001200,
    ASYSCTL_CMP7_HP_1 = 0x00001201,
    ASYSCTL_CMP7_HP_2 = 0x00001202,
    ASYSCTL_CMP7_HP_3 = 0x00001203,
    ASYSCTL_CMP7_HP_4 = 0x00001204,
    ASYSCTL_CMP7_HP_5 = 0x00001205,
    ASYSCTL_CMP7_HP_6 = 0x00001206,

    ASYSCTL_CMP8_HP_0 = 0x00001500,
    ASYSCTL_CMP8_HP_1 = 0x00001501,
    ASYSCTL_CMP8_HP_2 = 0x00001502,
    ASYSCTL_CMP8_HP_3 = 0x00001503,
    ASYSCTL_CMP8_HP_4 = 0x00001504,
    ASYSCTL_CMP8_HP_5 = 0x00001505,
    ASYSCTL_CMP8_HP_6 = 0x00001506,

    ASYSCTL_CMP9_HP_0 = 0x00001800,
    ASYSCTL_CMP9_HP_1 = 0x00001801,
    ASYSCTL_CMP9_HP_2 = 0x00001802,
    ASYSCTL_CMP9_HP_3 = 0x00001803,
    ASYSCTL_CMP9_HP_4 = 0x00001804,
    ASYSCTL_CMP9_HP_5 = 0x00001805,
    ASYSCTL_CMP9_HP_6 = 0x00001806,

    ASYSCTL_CMP10_HP_0 = 0x00001B00,
    ASYSCTL_CMP10_HP_1 = 0x00001B01,
    ASYSCTL_CMP10_HP_2 = 0x00001B02,
    ASYSCTL_CMP10_HP_3 = 0x00001B03,
    ASYSCTL_CMP10_HP_4 = 0x00001B04,
    ASYSCTL_CMP10_HP_5 = 0x00001B05,
    ASYSCTL_CMP10_HP_6 = 0x00001B06,

    ASYSCTL_CMP11_HP_0 = 0x00040000,
    ASYSCTL_CMP11_HP_1 = 0x00040001,
    ASYSCTL_CMP11_HP_2 = 0x00040002,
    ASYSCTL_CMP11_HP_3 = 0x00040003,
    ASYSCTL_CMP11_HP_4 = 0x00040004,
    ASYSCTL_CMP11_HP_5 = 0x00040005,
    ASYSCTL_CMP11_HP_6 = 0x00040006,

    ASYSCTL_CMP12_HP_0 = 0x00040300,
    ASYSCTL_CMP12_HP_1 = 0x00040301,
    ASYSCTL_CMP12_HP_2 = 0x00040302,
    ASYSCTL_CMP12_HP_3 = 0x00040303,
    ASYSCTL_CMP12_HP_4 = 0x00040304,
    ASYSCTL_CMP12_HP_5 = 0x00040305,
    ASYSCTL_CMP12_HP_6 = 0x00040306,

    ASYSCTL_CMP1_LP_0 = 0x00080000,
    ASYSCTL_CMP1_LP_1 = 0x00080001,
    ASYSCTL_CMP1_LP_2 = 0x00080002,
    ASYSCTL_CMP1_LP_3 = 0x00080003,
    ASYSCTL_CMP1_LP_4 = 0x00080004,
    ASYSCTL_CMP1_LP_5 = 0x00080005,
    ASYSCTL_CMP1_LP_6 = 0x00080006,

    ASYSCTL_CMP2_LP_0 = 0x00080300,
    ASYSCTL_CMP2_LP_1 = 0x00080301,
    ASYSCTL_CMP2_LP_2 = 0x00080302,
    ASYSCTL_CMP2_LP_3 = 0x00080303,
    ASYSCTL_CMP2_LP_4 = 0x00080304,
    ASYSCTL_CMP2_LP_5 = 0x00080305,
    ASYSCTL_CMP2_LP_6 = 0x00080306,

    ASYSCTL_CMP3_LP_0 = 0x00080600,
    ASYSCTL_CMP3_LP_1 = 0x00080601,
    ASYSCTL_CMP3_LP_2 = 0x00080602,
    ASYSCTL_CMP3_LP_3 = 0x00080603,
    ASYSCTL_CMP3_LP_4 = 0x00080604,
    ASYSCTL_CMP3_LP_5 = 0x00080605,
    ASYSCTL_CMP3_LP_6 = 0x00080606,

    ASYSCTL_CMP4_LP_0 = 0x00080900,
    ASYSCTL_CMP4_LP_1 = 0x00080901,
    ASYSCTL_CMP4_LP_2 = 0x00080902,
    ASYSCTL_CMP4_LP_3 = 0x00080903,
    ASYSCTL_CMP4_LP_4 = 0x00080904,
    ASYSCTL_CMP4_LP_5 = 0x00080905,
    ASYSCTL_CMP4_LP_6 = 0x00080906,

    ASYSCTL_CMP5_LP_0 = 0x00080C00,
    ASYSCTL_CMP5_LP_1 = 0x00080C01,
    ASYSCTL_CMP5_LP_2 = 0x00080C02,
    ASYSCTL_CMP5_LP_3 = 0x00080C03,
    ASYSCTL_CMP5_LP_4 = 0x00080C04,
    ASYSCTL_CMP5_LP_5 = 0x00080C05,
    ASYSCTL_CMP5_LP_6 = 0x00080C06,

    ASYSCTL_CMP6_LP_0 = 0x00080F00,
    ASYSCTL_CMP6_LP_1 = 0x00080F01,
    ASYSCTL_CMP6_LP_2 = 0x00080F02,
    ASYSCTL_CMP6_LP_3 = 0x00080F03,
    ASYSCTL_CMP6_LP_4 = 0x00080F04,
    ASYSCTL_CMP6_LP_5 = 0x00080F05,
    ASYSCTL_CMP6_LP_6 = 0x00080F06,

    ASYSCTL_CMP7_LP_0 = 0x00081200,
    ASYSCTL_CMP7_LP_1 = 0x00081201,
    ASYSCTL_CMP7_LP_2 = 0x00081202,
    ASYSCTL_CMP7_LP_3 = 0x00081203,
    ASYSCTL_CMP7_LP_4 = 0x00081204,
    ASYSCTL_CMP7_LP_5 = 0x00081205,
    ASYSCTL_CMP7_LP_6 = 0x00081206,

    ASYSCTL_CMP8_LP_0 = 0x00081500,
    ASYSCTL_CMP8_LP_1 = 0x00081501,
    ASYSCTL_CMP8_LP_2 = 0x00081502,
    ASYSCTL_CMP8_LP_3 = 0x00081503,
    ASYSCTL_CMP8_LP_4 = 0x00081504,
    ASYSCTL_CMP8_LP_5 = 0x00081505,
    ASYSCTL_CMP8_LP_6 = 0x00081506,

    ASYSCTL_CMP9_LP_0 = 0x00081800,
    ASYSCTL_CMP9_LP_1 = 0x00081801,
    ASYSCTL_CMP9_LP_2 = 0x00081802,
    ASYSCTL_CMP9_LP_3 = 0x00081803,
    ASYSCTL_CMP9_LP_4 = 0x00081804,
    ASYSCTL_CMP9_LP_5 = 0x00081805,
    ASYSCTL_CMP9_LP_6 = 0x00081806,

    ASYSCTL_CMP10_LP_0 = 0x00081B00,
    ASYSCTL_CMP10_LP_1 = 0x00081B01,
    ASYSCTL_CMP10_LP_2 = 0x00081B02,
    ASYSCTL_CMP10_LP_3 = 0x00081B03,
    ASYSCTL_CMP10_LP_4 = 0x00081B04,
    ASYSCTL_CMP10_LP_5 = 0x00081B05,
    ASYSCTL_CMP10_LP_6 = 0x00081B06,

    ASYSCTL_CMP11_LP_0 = 0x000C0000,
    ASYSCTL_CMP11_LP_1 = 0x000C0001,
    ASYSCTL_CMP11_LP_2 = 0x000C0002,
    ASYSCTL_CMP11_LP_3 = 0x000C0003,
    ASYSCTL_CMP11_LP_4 = 0x000C0004,
    ASYSCTL_CMP11_LP_5 = 0x000C0005,
    ASYSCTL_CMP11_LP_6 = 0x000C0006,

    ASYSCTL_CMP12_LP_0 = 0x000C0300,
    ASYSCTL_CMP12_LP_1 = 0x000C0301,
    ASYSCTL_CMP12_LP_2 = 0x000C0302,
    ASYSCTL_CMP12_LP_3 = 0x000C0303,
    ASYSCTL_CMP12_LP_4 = 0x000C0304,
    ASYSCTL_CMP12_LP_5 = 0x000C0305,
    ASYSCTL_CMP12_LP_6 = 0x000C0306,

    ASYSCTL_CMP1_HN_0 = 0x00100000,
    ASYSCTL_CMP1_HN_1 = 0x00100001,

    ASYSCTL_CMP2_HN_0 = 0x00100100,
    ASYSCTL_CMP2_HN_1 = 0x00100101,

    ASYSCTL_CMP3_HN_0 = 0x00100200,
    ASYSCTL_CMP3_HN_1 = 0x00100201,

    ASYSCTL_CMP4_HN_0 = 0x00100300,
    ASYSCTL_CMP4_HN_1 = 0x00100301,

    ASYSCTL_CMP5_HN_0 = 0x00100400,
    ASYSCTL_CMP5_HN_1 = 0x00100401,

    ASYSCTL_CMP6_HN_0 = 0x00100500,
    ASYSCTL_CMP6_HN_1 = 0x00100501,

    ASYSCTL_CMP7_HN_0 = 0x00100600,
    ASYSCTL_CMP7_HN_1 = 0x00100601,

    ASYSCTL_CMP8_HN_0 = 0x00100700,
    ASYSCTL_CMP8_HN_1 = 0x00100701,

    ASYSCTL_CMP9_HN_0 = 0x00100800,
    ASYSCTL_CMP9_HN_1 = 0x00100801,

    ASYSCTL_CMP10_HN_0 = 0x00100900,
    ASYSCTL_CMP10_HN_1 = 0x00100901,

    ASYSCTL_CMP11_HN_0 = 0x00100A00,
    ASYSCTL_CMP11_HN_1 = 0x00100A01,

    ASYSCTL_CMP12_HN_0 = 0x00100B00,
    ASYSCTL_CMP12_HN_1 = 0x00100B01,

    ASYSCTL_CMP1_LN_0 = 0x00140000,
    ASYSCTL_CMP1_LN_1 = 0x00140001,

    ASYSCTL_CMP2_LN_0 = 0x00140100,
    ASYSCTL_CMP2_LN_1 = 0x00140101,

    ASYSCTL_CMP3_LN_0 = 0x00140200,
    ASYSCTL_CMP3_LN_1 = 0x00140201,

    ASYSCTL_CMP4_LN_0 = 0x00140300,
    ASYSCTL_CMP4_LN_1 = 0x00140301,

    ASYSCTL_CMP5_LN_0 = 0x00140400,
    ASYSCTL_CMP5_LN_1 = 0x00140401,

    ASYSCTL_CMP6_LN_0 = 0x00140500,
    ASYSCTL_CMP6_LN_1 = 0x00140501,

    ASYSCTL_CMP7_LN_0 = 0x00140600,
    ASYSCTL_CMP7_LN_1 = 0x00140601,

    ASYSCTL_CMP8_LN_0 = 0x00140700,
    ASYSCTL_CMP8_LN_1 = 0x00140701,

    ASYSCTL_CMP9_LN_0 = 0x00140800,
    ASYSCTL_CMP9_LN_1 = 0x00140801,

    ASYSCTL_CMP10_LN_0 = 0x00140900,
    ASYSCTL_CMP10_LN_1 = 0x00140901,

    ASYSCTL_CMP11_LN_0 = 0x00140A00,
    ASYSCTL_CMP11_LN_1 = 0x00140A01,

    ASYSCTL_CMP12_LN_0 = 0x00140B00,
    ASYSCTL_CMP12_LN_1 = 0x00140B01
} AsysCtl_CMPselect;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************

//*****************************************************************************
//
//! Enable temperature sensor.
//!
//! This function enables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_enableTemperatureSensor"))) static inline void
ASysCtl_enableTemperatureSensor(void)
{
    //
    // Set the temperature sensor enable bit.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) |= ASYSCTL_TSNSCTL_ENABLE;
}

//*****************************************************************************
//
//! Disable temperature sensor.
//!
//! This function disables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_disableTemperatureSensor"))) static inline void
ASysCtl_disableTemperatureSensor(void)
{
    //
    // Clear the temperature sensor enable bit.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) &= ~(ASYSCTL_TSNSCTL_ENABLE);
}

//*****************************************************************************
//
//! Locks the temperature sensor control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockTemperatureSensor"))) static inline void ASysCtl_lockTemperatureSensor(
    void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_TSNSCTL;
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to external / internal.
//!
//! \param vref is VREFHI signal to be configured
//!             -   ASYSCTL_VREFHIAB
//!             -   ASYSCTL_VREFHICDE
//! \param mode is one of the following:
//!             -   ASYSCTL_VREF_EXTERNAL
//!             -   ASYSCTL_VREF_INTERNAL_3_3_V
//!             -   ASYSCTL_VREF_INTERNAL_2_5_V
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_setVREF"))) static inline void ASysCtl_setVREF(ASysCtl_Vref     vref,
                                                                                           ASysCtl_VrefMode mode)
{
    uint16_t mask = ~(0x101U << (uint16_t)vref);

    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) =
        (HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) & mask) | (uint16_t)mode << (uint16_t)vref;
}

//*****************************************************************************
//
//! Locks the analog reference control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockANAREF"))) static inline void ASysCtl_lockANAREF(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_ANAREFCTL;
}

//*****************************************************************************
//
//! Enable VMON function mask on a TRIM load
//!
//! \note This function masks the generation of POR/BOR for a fixed duration
//! whenever TRIM bits are changed.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_enableVMONMask"))) static inline void ASysCtl_enableVMONMask(void)
{
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_VREGCTL) |= ASYSCTL_VREGCTL_ENMASK;
}

//*****************************************************************************
//
//! Power down internal voltage regulator
//!
//! \note On devices, in which VREGENZ is not bonded out, this bit
//! should be used to disable internal VREG.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_powerDownVREG"))) static inline void ASysCtl_powerDownVREG(void)
{
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_VREGCTL) |= ASYSCTL_VREGCTL_PWRDNVREG;
}

//*****************************************************************************
//
//! Locks the VREG control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockVREG"))) static inline void ASysCtl_lockVREG(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_VREGCTL;
}

//*****************************************************************************
//
//! Enable BORL on VDDIO
//!
//! \note BOR circuit will be triggered if VDDIO goes lower than the lower BOR
//! threshold of VDDIO
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_enableBORL"))) static inline void ASysCtl_enableBORL(void)
{
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_VMONCTL) &= ~ASYSCTL_VMONCTL_BORLVMONDIS;
}

//*****************************************************************************
//
//! Disable BORL on VDDIO
//!
//! \note BOR circuit will not be triggered if VDDIO goes lower than the lower
//! BOR threshold of VDDIO.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_disableBORL"))) static inline void ASysCtl_disableBORL(void)
{
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_VMONCTL) |= ASYSCTL_VMONCTL_BORLVMONDIS;
}

//*****************************************************************************
//
//! Locks the voltage monitor control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockVMON"))) static inline void ASysCtl_lockVMON(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_VMONCTL;
}

//*****************************************************************************
//
//! Selecting the required CMP mux.
//!
//! This function is common for CMPHP, CMPHN, CMPLP and CMPLN.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_configCMPMux"))) static inline void ASysCtl_configCMPMux(
    AsysCtl_CMPselect selectMux)
{
    uint32_t value, offset, shift;
    uint32_t mask = 0x000000FF;
    uint32_t temp = selectMux;
    uint32_t bitMask;

    value  = temp & mask;
    shift  = (temp >> 8U) & mask;
    offset = (temp >> 16U) & mask;

    if (selectMux < ASYSCTL_CMP1_HN_0)
    {
        bitMask = (uint32_t)0x7U << shift;
    }
    else
    {
        bitMask = (uint32_t)0x1U << shift;
    }

    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHPMXSEL + offset) =
        (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHPMXSEL + offset) & ~bitMask) | (value << shift);
}

//*****************************************************************************
//
//! Locks the CMPHPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockCMPHPMux"))) static inline void ASysCtl_lockCMPHPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPHPMXSEL | ASYSCTL_LOCK_CMPHPMXSEL1;
}

//*****************************************************************************
//
//! Locks the CMPLPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockCMPLPMux"))) static inline void ASysCtl_lockCMPLPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPLPMXSEL | ASYSCTL_LOCK_CMPLPMXSEL1;
}

//*****************************************************************************
//
//! Locks the CMPHNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockCMPHNMux"))) static inline void ASysCtl_lockCMPHNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPHNMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockCMPLNMux"))) static inline void ASysCtl_lockCMPLNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPLNMXSEL;
}

//*****************************************************************************
//
//! Selects the internal node, if any, to come out on the INTERNALTEST node
//! connected to ADC.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_selectInternalTestNode"))) static inline void
ASysCtl_selectInternalTestNode(ASysCtl_InternalTestNode select)
{
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_INTERNALTESTCTL) =
        (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_INTERNALTESTCTL) & ~ASYSCTL_INTERNALTESTCTL_TESTSEL_M) |
        (0xA5A5UL << ASYSCTL_INTERNALTESTCTL_KEY_S) | ((uint32_t)select << ASYSCTL_INTERNALTESTCTL_TESTSEL_S);
}

//*****************************************************************************
//
//! Drive Select for the IO buffer:
//!
//! \param pin    is the IO buffer to be configured (ASYSCTL_IOBUFF_GPIOx)
//! \param config is the IO buffer Drive Select (ASYSCTL_IOBUFF_DRIVE_4_MA or
//!               ASYSCTL_IOBUFF_DRIVE_20_MA)
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_setIOBufferDrive"))) static inline void ASysCtl_setIOBufferDrive(
    ASysCtl_IOBuffer pin, ASysCtl_IOBufferDrive config)
{
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_IODRVSEL) =
        (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_IODRVSEL) & ~(1U << (uint32_t)pin)) | ((uint32_t)config << (uint32_t)pin);
}

//*****************************************************************************
//
//! Mode Select for the IO buffer:
//!
//! \param pin    is the IO buffer to be configured (ASYSCTL_IOBUFF_GPIOx)
//! \param config is the IO buffer Mode Select (ASYSCTL_IOBUFF_DRIVE_4_MA or
//!               ASYSCTL_IOBUFF_DRIVE_20_MA)
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_setIOBufferMode"))) static inline void ASysCtl_setIOBufferMode(
    ASysCtl_IOBuffer pin, ASysCtl_IOBufferMode config)
{
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_IOMODESEL) =
        (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_IOMODESEL) & ~(1U << (uint32_t)pin)) | ((uint32_t)config << (uint32_t)pin);
}

//*****************************************************************************
//
//! Configure AGPIO Filter control for Right side pins
//!
//! \param config can be bitwise OR of the following values:
//! - ASYSCTL_AGPIOFILTER_BYPASS - Filter bypass configuration(min ACQPS = 90ns)
//! - ASYSCTL_AGPIOFILTER_333OHM - 333Ohm filter setting (min ACQPS = 125ns)
//! - ASYSCTL_AGPIOFILTER_500OHM - 500 Ohm filter setting (min ACQPS = 160ns)
//! - ASYSCTL_AGPIOFILTER_1000OHM - 1KOhm filter setting (min ACQPS = 230ns)
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_setAGPIOFilter"))) static inline void ASysCtl_setAGPIOFilter(
    uint32_t config)
{
    ASSERT(config <= 3U);

    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_AGPIOFILTER) =
        (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_AGPIOFILTER) & ~ASYSCTL_AGPIOFILTER_FILTER_M) |
        (config << ASYSCTL_AGPIOFILTER_FILTER_S);
}

//*****************************************************************************
//
//! Locks the AGPIOFILTER register.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockAGPIOFilter"))) static inline void ASysCtl_lockAGPIOFilter(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_CONFIGLOCK) |= ASYSCTL_CONFIGLOCK_AGPIOFILTER;
}

//*****************************************************************************
//
//! Locks the AGPIOCTRL register.
//!
//! \note The register is used in GPIO_setAnalogMode function GPIO driver
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.ASysCtl_lockAGPIOCtrl"))) static inline void ASysCtl_lockAGPIOCtrl(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_CONFIGLOCK) |= ASYSCTL_CONFIGLOCK_AGPIOCTRL;
}

//*****************************************************************************
//
//! Configure the ADCs for Global SW Trigger
//!
//! \param adcSelect can be bitwsie OR of the following :
//! (ASYSCTL_ADCSOCFRCGBSEL_ADCA | ASYSCTL_ADCSOCFRCGBSEL_ADCB ....
//! |ASYSCTL_ADCSOCFRCGBSEL_ADCE)
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.AsysCtl_configADCGlobalSOC"))) static inline void AsysCtl_configADCGlobalSOC(
    uint32_t adcSelect)
{
    HWREG(ADCGLOBAL_BASE + ASYSCTL_O_ADCSOCFRCGBSEL) = adcSelect;
}

//*****************************************************************************
//
//! Generate Global SOC force for specified SOCs
//!
//! \param socSelect can be bitwsie OR of the following :
//! (ASYSCTL_ADCSOCFRCGB_SOC0 | ASYSCTL_ADCSOCFRCGB_SOC1 ....
//! |ASYSCTL_ADCSOCFRCGB_SOC31)
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.AsysCtl_forceADCGlobalSOC"))) static inline void AsysCtl_forceADCGlobalSOC(
    uint32_t socSelect)
{
    HWREG(ADCGLOBAL_BASE + ASYSCTL_O_ADCSOCFRCGB) = socSelect;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // ASYSCTL_H
