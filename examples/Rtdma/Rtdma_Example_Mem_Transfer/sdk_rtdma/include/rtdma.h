// ###########################################################################
//
//  FILE:   rtdma.h
//
//  TITLE:  C29x RTDMA driver
//
// ###########################################################################
//  $Copyright:  $
// ###########################################################################

#ifndef RTDMA_H
#define RTDMA_H

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
//! \addtogroup rtdma_api RTDMA
//! \brief This module is used for RTDMA configurations.
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include "sdk_mcal_integration.h"
#include "hw_rtdma.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"
#include "hw_types.h"

#define DMA_TOTAL_MPU 16U  // 16 MPU regions
#define DMA_TOTAL_CH  10U  // 10 channels in each DMA instance

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as part of the config
//! parameter to configure the Oneshot mode.
//
//*****************************************************************************
//! Only one burst transfer performed per trigger.
#define DMA_CFG_ONESHOT_DISABLE 0U
//! Burst transfers occur without additional event triggers after the first.
#define DMA_CFG_ONESHOT_ENABLE RTDMA_MODE_ONESHOT

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as part of the config
//! parameter to configure the continuous mode of transfer.
//
//*****************************************************************************
//! DMA channel will be disabled at the end of a transfer.
#define DMA_CFG_CONTINUOUS_DISABLE 0U
//! DMA reinitializes when the transfer count is zero and waits for a trigger.
#define DMA_CFG_CONTINUOUS_ENABLE RTDMA_MODE_CONTINUOUS

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as part of the config
//! parameter to configure the DMA transfer read data size.
//
//*****************************************************************************
#define DMA_CFG_READ_SIZE_8BIT  0x0U      // DMA reads 8 bits at a time.
#define DMA_CFG_READ_SIZE_16BIT 0x20000U  // DMA reads 16 bits at a time.
#define DMA_CFG_READ_SIZE_32BIT 0x40000U  // DMA reads 32 bits at a time.
#define DMA_CFG_READ_SIZE_64BIT 0x60000U  // DMA reads 64 bits at a time.

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as part of the config
//! parameter to configure the DMA write data size.
//
//*****************************************************************************
#define DMA_CFG_WRT_SIZE_8BIT  0x0U       // DMA writes 8 bits at a time.
#define DMA_CFG_WRT_SIZE_16BIT 0x100000U  // DMA writes 16 bits at a time.
#define DMA_CFG_WRT_SIZE_32BIT 0x200000U  // DMA writes 32 bits at a time.
#define DMA_CFG_WRT_SIZE_64BIT 0x300000U  // DMA writes 64 bits at a time.

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as part of the config
//! parameter to configure both the DMA read data size and write data size.
//
//*****************************************************************************
#define DMA_CFG_SIZE_8BIT  (DMA_CFG_READ_SIZE_8BIT | DMA_CFG_WRT_SIZE_8BIT)
#define DMA_CFG_SIZE_16BIT (DMA_CFG_READ_SIZE_16BIT | DMA_CFG_WRT_SIZE_16BIT)
#define DMA_CFG_SIZE_32BIT (DMA_CFG_READ_SIZE_32BIT | DMA_CFG_WRT_SIZE_32BIT)
#define DMA_CFG_SIZE_64BIT (DMA_CFG_READ_SIZE_64BIT | DMA_CFG_WRT_SIZE_64BIT)

//*****************************************************************************
//
//! Values that can be passed to DMA_configMPURegion() as the channel mask to
//! the DMA_MPUConfigParams structure.
//
//*****************************************************************************
#define DMA_MPU_CH1_ENABLE  0x0001U  // Enable DMA Channel 1 for the MPU region.
#define DMA_MPU_CH2_ENABLE  0x0002U  // Enable DMA Channel 2 for the MPU region.
#define DMA_MPU_CH3_ENABLE  0x0004U  // Enable DMA Channel 3 for the MPU region.
#define DMA_MPU_CH4_ENABLE  0x0008U  // Enable DMA Channel 4 for the MPU region.
#define DMA_MPU_CH5_ENABLE  0x0010U  // Enable DMA Channel 5 for the MPU region.
#define DMA_MPU_CH6_ENABLE  0x0020U  // Enable DMA Channel 6 for the MPU region.
#define DMA_MPU_CH7_ENABLE  0x0040U  // Enable DMA Channel 7 for the MPU region.
#define DMA_MPU_CH8_ENABLE  0x0080U  // Enable DMA Channel 8 for the MPU region.
#define DMA_MPU_CH9_ENABLE  0x0100U  // Enable DMA Channel 9 for the MPU region.
#define DMA_MPU_CH10_ENABLE 0x0200U  // Enable DMA Channel 10 for the MPU region.

//*****************************************************************************
//
//! Values that can be passed to DMA_configMode() as the \e trigger parameter
//
//*****************************************************************************
typedef enum
{
    DMA_TRIGGER_SOFTWARE                   = 0,    //! TRIGGER SOFTWARE
    DMA_TRIGGER_ADCA1                      = 1,    //! TRIGGER ADCA1
    DMA_TRIGGER_ADCA2                      = 2,    //! TRIGGER ADCA2
    DMA_TRIGGER_ADCA3                      = 3,    //! TRIGGER ADCA3
    DMA_TRIGGER_ADCA4                      = 4,    //! TRIGGER ADCA4
    DMA_TRIGGER_ADCAEVT                    = 5,    //! TRIGGER ADCAEVT
    DMA_TRIGGER_ADCB1                      = 6,    //! TRIGGER ADCB1
    DMA_TRIGGER_ADCB2                      = 7,    //! TRIGGER ADCB2
    DMA_TRIGGER_ADCB3                      = 8,    //! TRIGGER ADCB3
    DMA_TRIGGER_ADCB4                      = 9,    //! TRIGGER ADCB4
    DMA_TRIGGER_ADCBEVT                    = 10,   //! TRIGGER ADCBEVT
    DMA_TRIGGER_ADCC1                      = 11,   //! TRIGGER ADCC1
    DMA_TRIGGER_ADCC2                      = 12,   //! TRIGGER ADCC2
    DMA_TRIGGER_ADCC3                      = 13,   //! TRIGGER ADCC3
    DMA_TRIGGER_ADCC4                      = 14,   //! TRIGGER ADCC4
    DMA_TRIGGER_ADCCEVT                    = 15,   //! TRIGGER ADCCEVT
    DMA_TRIGGER_ADCD1                      = 16,   //! TRIGGER ADCD1
    DMA_TRIGGER_ADCD2                      = 17,   //! TRIGGER ADCD2
    DMA_TRIGGER_ADCD3                      = 18,   //! TRIGGER ADCD3
    DMA_TRIGGER_ADCD4                      = 19,   //! TRIGGER ADCD4
    DMA_TRIGGER_ADCDEVT                    = 20,   //! TRIGGER ADCDEVT
    DMA_TRIGGER_ADCE1                      = 21,   //! TRIGGER ADCE1
    DMA_TRIGGER_ADCE2                      = 22,   //! TRIGGER ADCE2
    DMA_TRIGGER_ADCE3                      = 23,   //! TRIGGER ADCE3
    DMA_TRIGGER_ADCE4                      = 24,   //! TRIGGER ADCE4
    DMA_TRIGGER_ADCEEVT                    = 25,   //! TRIGGER ADCEEVT
    DMA_TRIGGER_CPU1_XINT1                 = 31,   //! TRIGGER CPU1 XINT1
    DMA_TRIGGER_CPU1_XINT2                 = 32,   //! TRIGGER CPU1 XINT2
    DMA_TRIGGER_CPU1_XINT3                 = 33,   //! TRIGGER CPU1 XINT3
    DMA_TRIGGER_CPU1_XINT4                 = 34,   //! TRIGGER CPU1 XINT4
    DMA_TRIGGER_CPU1_XINT5                 = 35,   //! TRIGGER CPU1 XINT5
    DMA_TRIGGER_CPU2_XINT1                 = 36,   //! TRIGGER CPU2 XINT1
    DMA_TRIGGER_CPU2_XINT2                 = 37,   //! TRIGGER CPU2 XINT2
    DMA_TRIGGER_CPU2_XINT3                 = 38,   //! TRIGGER CPU2 XINT3
    DMA_TRIGGER_CPU2_XINT4                 = 39,   //! TRIGGER CPU2 XINT4
    DMA_TRIGGER_CPU2_XINT5                 = 40,   //! TRIGGER CPU2 XINT5
    DMA_TRIGGER_CPU3_XINT1                 = 41,   //! TRIGGER CPU3 XINT1
    DMA_TRIGGER_CPU3_XINT2                 = 42,   //! TRIGGER CPU3 XINT2
    DMA_TRIGGER_CPU3_XINT3                 = 43,   //! TRIGGER CPU3 XINT3
    DMA_TRIGGER_CPU3_XINT4                 = 44,   //! TRIGGER CPU3 XINT4
    DMA_TRIGGER_CPU3_XINT5                 = 45,   //! TRIGGER CPU3 XINT5
    DMA_TRIGGER_EPWM1SOCA                  = 46,   //! TRIGGER EPWM1SOCA
    DMA_TRIGGER_EPWM1SOCB                  = 47,   //! TRIGGER EPWM1SOCB
    DMA_TRIGGER_EPWM2SOCA                  = 48,   //! TRIGGER EPWM2SOCA
    DMA_TRIGGER_EPWM2SOCB                  = 49,   //! TRIGGER EPWM2SOCB
    DMA_TRIGGER_EPWM3SOCA                  = 50,   //! TRIGGER EPWM3SOCA
    DMA_TRIGGER_EPWM3SOCB                  = 51,   //! TRIGGER EPWM3SOCB
    DMA_TRIGGER_EPWM4SOCA                  = 52,   //! TRIGGER EPWM4SOCA
    DMA_TRIGGER_EPWM4SOCB                  = 53,   //! TRIGGER EPWM4SOCB
    DMA_TRIGGER_EPWM5SOCA                  = 54,   //! TRIGGER EPWM5SOCA
    DMA_TRIGGER_EPWM5SOCB                  = 55,   //! TRIGGER EPWM5SOCB
    DMA_TRIGGER_EPWM6SOCA                  = 56,   //! TRIGGER EPWM6SOCA
    DMA_TRIGGER_EPWM6SOCB                  = 57,   //! TRIGGER EPWM6SOCB
    DMA_TRIGGER_EPWM7SOCA                  = 58,   //! TRIGGER EPWM7SOCA
    DMA_TRIGGER_EPWM7SOCB                  = 59,   //! TRIGGER EPWM7SOCB
    DMA_TRIGGER_EPWM8SOCA                  = 60,   //! TRIGGER EPWM8SOCA
    DMA_TRIGGER_EPWM8SOCB                  = 61,   //! TRIGGER EPWM8SOCB
    DMA_TRIGGER_EPWM9SOCA                  = 62,   //! TRIGGER EPWM9SOCA
    DMA_TRIGGER_EPWM9SOCB                  = 63,   //! TRIGGER EPWM9SOCB
    DMA_TRIGGER_EPWM10SOCA                 = 64,   //! TRIGGER EPWM10SOCA
    DMA_TRIGGER_EPWM10SOCB                 = 65,   //! TRIGGER EPWM10SOCB
    DMA_TRIGGER_EPWM11SOCA                 = 66,   //! TRIGGER EPWM11SOCA
    DMA_TRIGGER_EPWM11SOCB                 = 67,   //! TRIGGER EPWM11SOCB
    DMA_TRIGGER_EPWM12SOCA                 = 68,   //! TRIGGER EPWM12SOCA
    DMA_TRIGGER_EPWM12SOCB                 = 69,   //! TRIGGER EPWM12SOCB
    DMA_TRIGGER_EPWM13SOCA                 = 70,   //! TRIGGER EPWM13SOCA
    DMA_TRIGGER_EPWM13SOCB                 = 71,   //! TRIGGER EPWM13SOCB
    DMA_TRIGGER_EPWM14SOCA                 = 72,   //! TRIGGER EPWM14SOCA
    DMA_TRIGGER_EPWM14SOCB                 = 73,   //! TRIGGER EPWM14SOCB
    DMA_TRIGGER_EPWM15SOCA                 = 74,   //! TRIGGER EPWM15SOCA
    DMA_TRIGGER_EPWM15SOCB                 = 75,   //! TRIGGER EPWM15SOCB
    DMA_TRIGGER_EPWM16SOCA                 = 76,   //! TRIGGER EPWM16SOCA
    DMA_TRIGGER_EPWM16SOCB                 = 77,   //! TRIGGER EPWM16SOCB
    DMA_TRIGGER_EPWM17SOCA                 = 78,   //! TRIGGER EPWM17SOCA
    DMA_TRIGGER_EPWM17SOCB                 = 79,   //! TRIGGER EPWM17SOCB
    DMA_TRIGGER_EPWM18SOCA                 = 80,   //! TRIGGER EPWM18SOCA
    DMA_TRIGGER_EPWM18SOCB                 = 81,   //! TRIGGER EPWM18SOCB
    DMA_TRIGGER_TINT0                      = 94,   //! TRIGGER CPU1 TINT0
    DMA_TRIGGER_TINT1                      = 95,   //! TRIGGER CPU1 TINT1
    DMA_TRIGGER_TINT2                      = 96,   //! TRIGGER CPU1 TINT2
    DMA_TRIGGER_CPU2_TINT0                 = 97,   //! TRIGGER CPU2 TINT0
    DMA_TRIGGER_CPU2_TINT1                 = 98,   //! TRIGGER CPU2 TINT1
    DMA_TRIGGER_CPU2_TINT2                 = 99,   //! TRIGGER CPU2 TINT2
    DMA_TRIGGER_CPU3_TINT0                 = 100,  //! TRIGGER CPU3 TINT0
    DMA_TRIGGER_CPU3_TINT1                 = 101,  //! TRIGGER CPU3 TINT1
    DMA_TRIGGER_CPU3_TINT2                 = 102,  //! TRIGGER CPU3 TINT2
    DMA_TRIGGER_ECAP1                      = 112,  //! TRIGGER ECAP1
    DMA_TRIGGER_ECAP2                      = 113,  //! TRIGGER ECAP2
    DMA_TRIGGER_ECAP3                      = 114,  //! TRIGGER ECAP3
    DMA_TRIGGER_ECAP4                      = 115,  //! TRIGGER ECAP4
    DMA_TRIGGER_ECAP5                      = 116,  //! TRIGGER ECAP5
    DMA_TRIGGER_ECAP6                      = 117,  //! TRIGGER ECAP6
    DMA_TRIGGER_LINATX                     = 120,  //! TRIGGER LINATX
    DMA_TRIGGER_LINARX                     = 121,  //! TRIGGER LINARX
    DMA_TRIGGER_LINBTX                     = 122,  //! TRIGGER LINBTX
    DMA_TRIGGER_LINBRX                     = 123,  //! TRIGGER LINBRX
    DMA_TRIGGER_SYNC                       = 124,  //! TRIGGER SYNC
    DMA_TRIGGER_SPIATX                     = 125,  //! TRIGGER SPIATX
    DMA_TRIGGER_SPIARX                     = 126,  //! TRIGGER SPIARX
    DMA_TRIGGER_SPIBTX                     = 127,  //! TRIGGER SPIBTX
    DMA_TRIGGER_SPIBRX                     = 128,  //! TRIGGER SPIBRX
    DMA_TRIGGER_SPICTX                     = 129,  //! TRIGGER SPICTX
    DMA_TRIGGER_SPICRX                     = 130,  //! TRIGGER SPICRX
    DMA_TRIGGER_SPIDTX                     = 131,  //! TRIGGER SPIDTX
    DMA_TRIGGER_SPIDRX                     = 132,  //! TRIGGER SPIDRX
    DMA_TRIGGER_SPIETX                     = 133,  //! TRIGGER SPIETX
    DMA_TRIGGER_SPIERX                     = 134,  //! TRIGGER SPIERX
    DMA_TRIGGER_CLB1INT                    = 135,  //! TRIGGER CLB1INT
    DMA_TRIGGER_CLB2INT                    = 136,  //! TRIGGER CLB2INT
    DMA_TRIGGER_CLB3INT                    = 137,  //! TRIGGER CLB3INT
    DMA_TRIGGER_CLB4INT                    = 138,  //! TRIGGER CLB4INT
    DMA_TRIGGER_CLB5INT                    = 139,  //! TRIGGER CLB5INT
    DMA_TRIGGER_CLB6INT                    = 140,  //! TRIGGER CLB6INT
    DMA_TRIGGER_FSITXA                     = 143,  //! TRIGGER FSITXA
    DMA_TRIGGER_FSIRXA                     = 144,  //! TRIGGER FSIRXA
    DMA_TRIGGER_FSIA_DATA_TAG_MATCH        = 145,  //! TRIGGER FSIA DATA TAG MATCH
    DMA_TRIGGER_FSIA_PING_TAG_MATCH        = 146,  //! TRIGGER FSIA PING TAG MATCH
    DMA_TRIGGER_FSIRXB                     = 148,  //! TRIGGER FSIRXB
    DMA_TRIGGER_FSITXB                     = 147,  //! TRIGGER FSITXB
    DMA_TRIGGER_FSIB_DATA_TAG_MATCH        = 149,  //! TRIGGER FSIB DATA TAG MATCH
    DMA_TRIGGER_FSIB_PING_TAG_MATCH        = 150,  //! TRIGGER FSIB PING TAG MATCH
    DMA_TRIGGER_FSIRXC                     = 152,  //! TRIGGER FSIRXC
    DMA_TRIGGER_FSITXC                     = 151,  //! TRIGGER FSITXC
    DMA_TRIGGER_FSIC_DATA_TAG_MATCH        = 153,  //! TRIGGER FSIC DATA TAG MATCH
    DMA_TRIGGER_FSIC_PING_TAG_MATCH        = 154,  //! TRIGGER FSIC PING TAG MATCH
    DMA_TRIGGER_FSITXD                     = 155,  //! TRIGGER FSITXD
    DMA_TRIGGER_FSIRXD                     = 156,  //! TRIGGER FSIRXD
    DMA_TRIGGER_FSID_DATA_TAG_MATCH        = 157,  //! TRIGGER FSID DATA TAG MATCH
    DMA_TRIGGER_FSID_PING_TAG_MATCH        = 158,  //! TRIGGER FSID PING TAG MATCH
    DMA_TRIGGER_CPU1_DLT                   = 161,  //! TRIGGER CPU1 DLT
    DMA_TRIGGER_CPU3_DLT                   = 163,  //! TRIGGER CPU3 DLT
    DMA_TRIGGER_CPU2_DLT                   = 162,  //! TRIGGER CPU2 DLT
    DMA_TRIGGER_UARTARX                    = 167,  //! TRIGGER UARTARX
    DMA_TRIGGER_UARTATX                    = 168,  //! TRIGGER UARTATX
    DMA_TRIGGER_UARTBTX                    = 169,  //! TRIGGER UARTBTX
    DMA_TRIGGER_UARTBRX                    = 170,  //! TRIGGER UARTBRX
    DMA_TRIGGER_UARTCTX                    = 171,  //! TRIGGER UARTCTX
    DMA_TRIGGER_UARTCRX                    = 172,  //! TRIGGER UARTCRX
    DMA_TRIGGER_UARTDTX                    = 173,  //! TRIGGER UARTDTX
    DMA_TRIGGER_UARTDRX                    = 174,  //! TRIGGER UARTDRX
    DMA_TRIGGER_UARTETX                    = 175,  //! TRIGGER UARTETX
    DMA_TRIGGER_UARTERX                    = 176,  //! TRIGGER UARTERX
    DMA_TRIGGER_UARTFTX                    = 177,  //! TRIGGER UARTFTX
    DMA_TRIGGER_UARTFRX                    = 178,  //! TRIGGER UARTFRX
    DMA_TRIGGER_DTHE_SHA_DMA_S_CTXIN_REQ   = 179,  //! TRIGGER DTHE SHA DMA S CTXIN REQ
    DMA_TRIGGER_DTHE_SHA_DMA_S_DATAIN_REQ  = 180,  //! TRIGGER DTHE SHA DMA S DATAIN REQ
    DMA_TRIGGER_DTHE_SHA_DMA_S_CTXOUT_REQ  = 181,  //! TRIGGER DTHE SHA DMA S CTXOUT REQ
    DMA_TRIGGER_DTHE_SHA_DMA_P_CTXIN_REQ   = 182,  //! TRIGGER DTHE SHA DMA P CTXIN REQ
    DMA_TRIGGER_DTHE_SHA_DMA_P_DATAIN_REQ  = 183,  //! TRIGGER DTHE SHA DMA P DATAIN REQ
    DMA_TRIGGER_DTHE_SHA_DMA_P_CTXOUT_REQ  = 184,  //! TRIGGER DTHE SHA DMA P CTXOUT REQ
    DMA_TRIGGER_DTHE_AES_DMA_S_CTXIN_REQ   = 185,  //! TRIGGER DTHE AES DMA S CTXIN REQ
    DMA_TRIGGER_DTHE_AES_DMA_S_DATAIN_REQ  = 186,  //! TRIGGER DTHE AES DMA S DATAIN REQ
    DMA_TRIGGER_DTHE_AES_DMA_S_DATAOUT_REQ = 187,  //! TRIGGER DTHE AES DMA S DATAOUT REQ
    DMA_TRIGGER_DTHE_AES_DMA_S_CTXOUT_REQ  = 188,  //! TRIGGER DTHE AES DMA S CTXOUT REQ
    DMA_TRIGGER_DTHE_AES_DMA_P_CTXIN_REQ   = 189,  //! TRIGGER DTHE AES DMA P CTXIN REQ
    DMA_TRIGGER_DTHE_AES_DMA_P_DATAIN_REQ  = 190,  //! TRIGGER DTHE AES DMA P DATAIN REQ
    DMA_TRIGGER_DTHE_AES_DMA_P_DATAOUT_REQ = 191,  //! TRIGGER DTHE AES DMA P DATAOUT REQ
    DMA_TRIGGER_DTHE_AES_DMA_P_CTXOUT_REQ  = 192,  //! TRIGGER DTHE AES DMA P CTXOUT REQ
    DMA_TRIGGER_DTHE_SM3_CTXIN_REQ         = 193,  //! TRIGGER DTHE SM3 CTXIN REQ
    DMA_TRIGGER_DTHE_SM3_DATAIN_REQ        = 194,  //! TRIGGER DTHE SM3 DATAIN REQ
    DMA_TRIGGER_DTHE_SM3_CTXOUT_REQ        = 195,  //! TRIGGER DTHE SM3 CTXOUT REQ
    DMA_TRIGGER_DTHE_SM4_CTXIN_REQ         = 196,  //! TRIGGER DTHE SM4 CTXIN REQ
    DMA_TRIGGER_DTHE_SM4_DATAIN_REQ        = 197,  //! TRIGGER DTHE SM4 DATAIN REQ
    DMA_TRIGGER_DTHE_SM4_DATAOUT_REQ       = 198,  //! TRIGGER DTHE SM4 DATAOUT REQ
    DMA_TRIGGER_DTHE_SM4_CTXOUT_REQ        = 199,  //! TRIGGER DTHE SM4 CTXOUT REQ
    DMA_TRIGGER_EPG                        = 200,  //! TRIGGER EPG
    DMA_TRIGGER_SDFM1FLT1                  = 201,  //! TRIGGER SDFM1FLT1
    DMA_TRIGGER_SDFM1FLT2                  = 202,  //! TRIGGER SDFM1FLT2
    DMA_TRIGGER_SDFM1FLT3                  = 203,  //! TRIGGER SDFM1FLT3
    DMA_TRIGGER_SDFM1FLT4                  = 204,  //! TRIGGER SDFM1FLT4
    DMA_TRIGGER_SDFM2FLT1                  = 205,  //! TRIGGER SDFM2FLT1
    DMA_TRIGGER_SDFM2FLT2                  = 206,  //! TRIGGER SDFM2FLT2
    DMA_TRIGGER_SDFM2FLT3                  = 207,  //! TRIGGER SDFM2FLT3
    DMA_TRIGGER_SDFM2FLT4                  = 208,  //! TRIGGER SDFM2FLT4
    DMA_TRIGGER_SDFM3FLT1                  = 209,  //! TRIGGER SDFM3FLT1
    DMA_TRIGGER_SDFM3FLT2                  = 210,  //! TRIGGER SDFM3FLT2
    DMA_TRIGGER_SDFM3FLT3                  = 211,  //! TRIGGER SDFM3FLT3
    DMA_TRIGGER_SDFM3FLT4                  = 212,  //! TRIGGER SDFM3FLT4
    DMA_TRIGGER_SDFM4FLT1                  = 213,  //! TRIGGER SDFM4FLT1
    DMA_TRIGGER_SDFM4FLT2                  = 214,  //! TRIGGER SDFM4FLT2
    DMA_TRIGGER_SDFM4FLT3                  = 215,  //! TRIGGER SDFM4FLT3
    DMA_TRIGGER_SDFM4FLT4                  = 216,  //! TRIGGER SDFM4FLT4
    DMA_TRIGGER_SENT1                      = 217,  //! TRIGGER SENT1
    DMA_TRIGGER_SENT2                      = 218,  //! TRIGGER SENT2
    DMA_TRIGGER_SENT3                      = 219,  //! TRIGGER SENT3
    DMA_TRIGGER_SENT4                      = 220,  //! TRIGGER SENT4
    DMA_TRIGGER_SENT5                      = 221,  //! TRIGGER SENT5
    DMA_TRIGGER_SENT6                      = 222,  //! TRIGGER SENT6
    DMA_TRIGGER_WADI1                      = 223,  //! TRIGGER WADI1
    DMA_TRIGGER_WADI2                      = 224,  //! TRIGGER WADI2
    DMA_TRIGGER_RTDMA_CH1INT               = 240,  //! TRIGGER RTDMA CH1INT
    DMA_TRIGGER_RTDMA_CH2INT               = 241,  //! TRIGGER RTDMA CH2INT
    DMA_TRIGGER_RTDMA_CH3INT               = 242,  //! TRIGGER RTDMA CH3INT
    DMA_TRIGGER_RTDMA_CH4INT               = 243,  //! TRIGGER RTDMA CH4INT
    DMA_TRIGGER_RTDMA_CH5INT               = 244,  //! TRIGGER RTDMA CH5INT
    DMA_TRIGGER_RTDMA_CH6INT               = 245,  //! TRIGGER RTDMA CH6INT
    DMA_TRIGGER_RTDMA_CH7INT               = 246,  //! TRIGGER RTDMA CH7INT
    DMA_TRIGGER_RTDMA_CH8INT               = 247,  //! TRIGGER RTDMA CH8INT
    DMA_TRIGGER_RTDMA_CH9INT               = 248,  //! TRIGGER RTDMA CH9INT
    DMA_TRIGGER_RTDMA_CH10INT              = 249   //! TRIGGER RTDMA CH10INT
} DMA_Trigger;

//*****************************************************************************
//
//! MPU regions
//
//*****************************************************************************
typedef enum
{
    DMA_MPUR1  = 0,
    DMA_MPUR2  = 1,
    DMA_MPUR3  = 2,
    DMA_MPUR4  = 3,
    DMA_MPUR5  = 4,
    DMA_MPUR6  = 5,
    DMA_MPUR7  = 6,
    DMA_MPUR8  = 7,
    DMA_MPUR9  = 8,
    DMA_MPUR10 = 9,
    DMA_MPUR11 = 10,
    DMA_MPUR12 = 11,
    DMA_MPUR13 = 12,
    DMA_MPUR14 = 13,
    DMA_MPUR15 = 14,
    DMA_MPUR16 = 15
} DMA_MPURegion;

//*****************************************************************************
//
//! DMA channels
//
//*****************************************************************************
typedef enum
{
    DMA_CH1  = 1,
    DMA_CH2  = 2,
    DMA_CH3  = 3,
    DMA_CH4  = 4,
    DMA_CH5  = 5,
    DMA_CH6  = 6,
    DMA_CH7  = 7,
    DMA_CH8  = 8,
    DMA_CH9  = 9,
    DMA_CH10 = 10,
} DMA_Channel;

//*****************************************************************************
//
//! DMA channel prioritites
//
//*****************************************************************************
typedef enum
{
    DMA_CHPRIORITY0,  //! DMA channel has Priority 0.
    DMA_CHPRIORITY1,  //! DMA channel has Priority 1.
    DMA_CHPRIORITY2,  //! DMA channel has Priority 2.
    DMA_CHPRIORITY3   //! DMA channel has Priority 3.
} DMA_ChannelPriority;

//*****************************************************************************
//
//! Values that can be passed to DMA_setInterruptMode() as the \e mode
//! parameter.
//
//*****************************************************************************
typedef enum
{
    //! DMA interrupt is generated at the beginning of a transfer
    DMA_INT_AT_BEGINNING,
    //! DMA interrupt is generated at the end of a transfer
    DMA_INT_AT_END
} DMA_InterruptMode;

//*****************************************************************************
//
//! Values that can be passed to DMA_setEmulationMode() as the \e mode
//! parameter.
//
//*****************************************************************************
typedef enum
{
    //! Transmission stops after current read-write access is completed
    DMA_EMULATION_STOP,
    //! Continue DMA operation regardless of emulation suspend
    DMA_EMULATION_FREE_RUN
} DMA_EmulationMode;

//*****************************************************************************
//
//! Values that can be passed to DMA_setPriorityMode() as the \e mode
//! parameter.
//
//*****************************************************************************
typedef enum
{
    //! Transmission stops after current read-write access is completed
    DMA_PRIORITY_ROUND_ROBIN,
    //! Continue DMA operation regardless of emulation suspend
    DMA_PRIORITY_SOFTWARE_CONFIG
} DMA_PriorityMode;

//*****************************************************************************
//
//! Values that can be passed to DMA_setBurstMode() as the \e mode
//! parameter.
//
//*****************************************************************************
typedef enum
{
    //! Burst signaling disabled. Last=First=1 though the burst (FIFOs)
    DMA_BURST_SIGNALING_DISABLE = 0U,
    //! Burst signaling enabled and can't be interrupted (can use with EMIF)
    DMA_BURST_SIGNALING_ENABLE_NO_INT = 2U,
} DMA_BurstSignalingMode;

//*****************************************************************************
//
//! Values that can be used to define the type of access allowed in a
//! particular MPU region
//
//*****************************************************************************
typedef enum
{
    //! DMA has no access to the MPU region.
    DMA_MPU_NO_ACCESS,
    //! DMA has only read access to the MPU region.
    DMA_MPU_READ_ACCESS,
    //! DMA has both read and write access to the MPU region.
    DMA_MPU_READ_WRITE_ACCESS
} DMA_MPUAccessPermission;

//*****************************************************************************
//
//! Values that can be passed to DMA_configChannel() as the
//! configure parameter.
//
//*****************************************************************************
typedef struct
{
    DMA_Trigger       transferTrigger;  // DMA transfer triggers
    DMA_InterruptMode interruptMode;    // Channel interrupt mode
    bool              enableInterrupt;  // Enable/Disable interrupt mode
    uint32_t          configSize;       // Data bus width (16 or 32 bits)
    uint32_t          wrtDatasize;      // Size of write accesses
    uint32_t          transferMode;     // Burst transfer mode
    uint32_t          reinitMode;       // DMA reinitialization mode
    uint32_t          channelPriority;  // Priority of the DMA channel
    uint32_t          burstSize;        // Number of words transferred per burst
    uint32_t          transferSize;     // Number of bursts per transfer
    //! Number of bursts to be transferred before a wrap of the source address
    //! occurs.
    uint32_t          srcWrapSize;
    //! Number of bursts to be transferred before a wrap of the destination
    //! address occurs.
    uint32_t          destWrapSize;
    uint32_t          destAddr;  // destination address
    uint32_t          srcAddr;   // source address
    //! Amount to inc or dec the source address after each word of a burst
    int16_t           srcBurstStep;
    //! Amount to inc or dec the destination address after each word of a burst
    int16_t           destBurstStep;
    //! Amount to inc or dec the source address after each burst of a transfer
    int16_t           srcTransferStep;
    //! Amount to inc or dec the destination address after each burst of a
    //! transfer
    int16_t           destTransferStep;
    //! Amount to inc or dec the source address when the wrap occurs
    int16_t           srcWrapStep;
    //! Amount to inc or dec the destination address when the wrap occurs
    int16_t           destWrapStep;

} DMA_ConfigParams;

//*****************************************************************************
//
//! Values that can be passed to DMA_configMPURegion() as the configure
//! parameter.
//! The startAddr is the beginning address of the 4KB granular block, whose
//! least 12 bits are 0's.
//! The endAddr denotes the end of the granular region and the least 12 bits
//! are 1's (0xFFF)
//
//*****************************************************************************
typedef struct
{
    //! MPU region start address (granularity of 4KB)
    uint32_t                startAddr;
    //! MPU region end address (end of the 4KB granular region)
    uint32_t                endAddr;
    //! Enable/ disable specific channel accesses using channel mask bits. It
    //! can be OR of the DMA_MPU_CH(#)_ENABLE macros
    uint16_t                channelMask;
    //! Region access permissions
    DMA_MPUAccessPermission accessPermission;
} DMA_MPUConfigParams;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! \internal
//! Checks an DMA channel base address.
//!
//! \param base specifies the DMA channel base address.
//!
//! This function determines if a DMA channel base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
__attribute__((always_inline)) static inline bool DMA_isBaseValid(uint32_t base)
{
    //
    // Check if the base address of the 2 RTDMA instance is valid
    //
    return ((base == RTDMA1_BASE) || (base == RTDMA2_BASE));
}

__attribute__((always_inline)) static inline bool DMA_MPU_isBaseValid(uint32_t base)
{
    //
    // Check if the base address of the MPU registers is valid
    //
    return ((base == RTDMA1_MPU_BASE) || (base == RTDMA2_MPU_BASE));
}

__attribute__((always_inline)) static inline bool DMA_CH_isBaseValid(uint32_t base)
{
    //
    // Check if the base address of the DMA channel control registers is valid
    //
    return (((base & BASE_ADDR_MASK) == RTDMA1CH1_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH2_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH3_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH4_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH5_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH6_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH7_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH8_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH9_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA1CH10_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH1_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH2_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH3_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH4_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH5_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH6_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH7_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH8_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH9_BASE_FRAME(0U)) ||
            ((base & BASE_ADDR_MASK) == RTDMA2CH10_BASE_FRAME(0U)));
}
#endif

//*****************************************************************************
//
//! Initializes the DMA controller to a known state.
//!
//! \param base specifies the base address DMA configuration registers.
//!
//! This function does a hard reset of the DMA controller in order to put it
//! into a known state. The function also sets the DMA to run free during
//! an emulation suspend (see the field DEBUGCTRL.FREE for more info).
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_initController"))) __attribute__((always_inline)) static inline void
DMA_initController(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set the hard reset bit. One NOP is required after HARDRESET.
    //
    HWREGB(base + RTDMA_O_DMACTRL) = RTDMA_DMACTRL_HARDRESET;
    NOP;
}

//*****************************************************************************
//
//! Channel Soft Reset
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function does a soft reset to place the channel into its default state
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_triggerSoftReset(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set the soft reset bit. One NOP is required after SOFTRESET
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_SOFTRESET;  // HWREGH
    NOP;
}

//*****************************************************************************
//
//! Sets DMA emulation mode.
//!
//! \param base specifies the base address of the DMA configuration registers.
//! \param mode is the emulation mode to be selected.
//!
//! This function sets the behavior of the DMA operation when an emulation
//! suspend occurs. The \e mode parameter can be one of the following:
//!
//! - \b DMA_EMULATION_STOP - DMA runs until the current read-write access
//!   is completed.
//! - \b DMA_EMULATION_FREE_RUN - DMA operation continues regardless of a
//!   the suspend.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_setEmulationMode"))) __attribute__((always_inline)) static inline void
DMA_setEmulationMode(uint32_t base, DMA_EmulationMode mode)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set Emulation mode
    //
    if (mode == DMA_EMULATION_STOP)
    {
        HWREGH(base + RTDMA_O_DEBUGCTRL) &= ~(uint16_t)RTDMA_DEBUGCTRL_FREE;
    }
    else
    {
        HWREGH(base + RTDMA_O_DEBUGCTRL) |= (uint16_t)RTDMA_DEBUGCTRL_FREE;
    }
}

//*****************************************************************************
//
//! Sets the DMA channel priority mode.
//!
//! \param base specifies the base address of the DMA configuration registers.
//! \param priorityMode is the channel priority mode to be selected.
//!
//! This function sets the channel priority mode. The \e priorityMode
//! parameter can be one of the following:
//!
//! - \b DMA_PRIORITY_ROUND_ROBIN - DMA channels are serviced in round-robin
//! mode. This is the default behavior.
//! - \b DMA_PRIORITY_SOFTWARE_CONFIG - Priority for channels are software
//! configurable. The priority of the channels is set in the SWPRI registers.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_setPriorityMode"))) __attribute__((always_inline)) static inline void
DMA_setPriorityMode(uint32_t base, DMA_PriorityMode priorityMode)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set Priority mode
    //
    if (priorityMode == DMA_PRIORITY_SOFTWARE_CONFIG)
    {
        HWREG(base + RTDMA_O_DMACTRL) |= RTDMA_DMACTRL_PRIORITYSEL;
    }
    else
    {
        HWREG(base + RTDMA_O_DMACTRL) &= ~RTDMA_DMACTRL_PRIORITYSEL;
    }
}

//*****************************************************************************
//
//! Sets the DMA channel priority
//!
//! \param base is the base address of the DMA configuration registers.
//! \param channel is the corresponding DMA channel number.
//! \param chPriority is the priority to be assigned to the channel.
//!
//! This function sets the priority of the DMA channel. Priority can be set to
//! any value of 0x0 to 0x3. Default value is 1 and value of 0 is treated as a
//! special condition during arbitration.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_setChannelPriority"))) __attribute__((always_inline)) static inline void
DMA_setChannelPriority(uint32_t base, DMA_Channel channel, DMA_ChannelPriority chPriority)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));
    if ((uint8_t)channel < 9U)
    {
        HWREG(base + RTDMA_O_SWPRI1) = (HWREG(base + RTDMA_O_SWPRI1) & ~(0xFU << (4U * ((uint32_t)channel - 1U)))) |
                                       ((uint32_t)chPriority << (4U * ((uint32_t)channel - 1U)));
    }
    else
    {
        HWREG(base + RTDMA_O_SWPRI2) = (HWREG(base + RTDMA_O_SWPRI2) & ~(0xFU << (4U * ((uint32_t)channel - 9U)))) |
                                       ((uint32_t)chPriority << (4U * ((uint32_t)channel - 9U)));
    }
}

//*****************************************************************************
//
//! Resets the DMA channel priority.
//!
//! \param base specifies the base address of the DMA configuration registers.
//!
//! If PRIORITYSEL==0: The priority reset bit resets the round-robin state
//! machine when a 1 is written. Service starts from the first enabled
//! channel. Writes of 0 are ignored and this bit always reads back a 0.
//!
//! If PRIORITYSEL==1: The SWPRI register is reset to it's reset value when a
//! 1 is written. All channels will be of priority "1". Writes of 0 are
//! ignored and this bit always reads back a 0.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_resetPriority"))) __attribute__((always_inline)) static inline void
DMA_resetPriority(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set the Priority reset bit
    //
    HWREGB(base + RTDMA_O_DMACTRL) = RTDMA_DMACTRL_PRIORITYRESET;
}

//*****************************************************************************
//
//! Enables peripherals to trigger a DMA transfer.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function enables the selected peripheral trigger to start a DMA
//! transfer on the specified channel.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_enableTrigger(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set the peripheral interrupt trigger enable bit.
    //
    HWREGH(base + RTDMA_O_MODE) |= RTDMA_MODE_PERINTE;
}

//*****************************************************************************
//
//! Disables peripherals from triggering a DMA transfer.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function disables the selected peripheral trigger from starting a DMA
//! transfer on the specified channel. This also disables the use of the
//! software force using the DMA_forceTrigger() API.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_disableTrigger(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Clear the peripheral interrupt trigger enable bit.
    //
    HWREGH(base + RTDMA_O_MODE) &= ~RTDMA_MODE_PERINTE;
}

//*****************************************************************************
//
//! Force a peripheral trigger to a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function sets the peripheral trigger flag and if triggering a DMA
//! burst is enabled (see DMA_enableTrigger()), a DMA burst transfer will be
//! forced.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_forceTrigger(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set the peripheral interrupt trigger force bit.
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_PERINTFRC;
}

//*****************************************************************************
//
//! Clears a DMA channel's peripheral trigger flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function clears the peripheral trigger flag. Normally, you would use
//! this function when initializing the DMA for the first time. The flag is
//! cleared automatically when the DMA starts the first burst of a transfer.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_clearTriggerFlag(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Write a one to the clear bit to clear the peripheral trigger flag.
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_PERINTCLR;
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's Transfer Status Flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if the Transfer Status Flag is set, which
//! means a DMA transfer has begun.
//! This flag is cleared when TRANSFER_COUNT reaches zero, or when the
//! HARDRESET or SOFTRESET bit is set.
//!
//! \return Returns \b true if the Transfer Status Flag is set. Returns
//! \b false otherwise.
//
//*****************************************************************************
__attribute__((always_inline)) static inline bool DMA_getTransferStatusFlag(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Read the Transfer Status Flag and return appropriately.
    //
    return ((HWREGH(base + RTDMA_O_CONTROL) & RTDMA_CONTROL_TRANSFERSTS) != 0U);
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's Burst Status Flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if the Burst Status Flag is set, which
//! means a DMA burst has begun.
//! This flag is cleared when BURST_COUNT reaches zero, or when the
//! HARDRESET or SOFTRESET bit is set.
//!
//! \return Returns \b true if the Burst Status Flag is set. Returns \b false
//! otherwise.
//
//*****************************************************************************
__attribute__((always_inline)) static inline bool DMA_getBurstStatusFlag(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Read the Burst Status Flag and return appropriately.
    //
    return ((HWREGH(base + RTDMA_O_CONTROL) & RTDMA_CONTROL_BURSTSTS) != 0U);
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's Run Status Flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if the Run Status Flag is set, which
//! means the DMA channel is enabled.
//! This flag is cleared when a transfer completes (TRANSFER_COUNT = 0) and
//! continuous mode is disabled, or when the HARDRESET, SOFTRESET, or HALT bit
//! is set.
//!
//! \return Returns \b true if the channel is enabled. Returns \b false
//! otherwise.
//
//*****************************************************************************
__attribute__((always_inline)) static inline bool DMA_getRunStatusFlag(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Read the Run Status Flag and return appropriately.
    //
    return ((HWREGH(base + RTDMA_O_CONTROL) & RTDMA_CONTROL_RUNSTS) != 0U);
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's Overflow Flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if the Overflow Flag is set, which
//! means peripheral event trigger was received while Peripheral Event Trigger
//! Flag was already set.
//! This flag can be cleared by writing to ERRCLR bit, using the function
//! DMA_clearErrorFlag().
//!
//! \return Returns \b true if the channel is enabled. Returns \b false
//! otherwise.
//
//*****************************************************************************
__attribute__((always_inline)) static inline bool DMA_getOverflowFlag(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Read the Overflow Flag and return appropriately.
    //
    return ((HWREGH(base + RTDMA_O_CONTROL) & RTDMA_CONTROL_OVRFLG) != 0U);
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's peripheral trigger flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if a peripheral trigger event has occurred
//! The flag is automatically cleared when the first burst transfer begins, but
//! if needed, it can be cleared using DMA_clearTriggerFlag().
//!
//! \return Returns \b true if a peripheral trigger event has occurred and its
//! flag is set. Returns \b false otherwise.
//
//*****************************************************************************
__attribute__((always_inline)) static inline bool DMA_getTriggerFlagStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Read the peripheral trigger flag and return appropriately.
    //
    return ((HWREGH(base + RTDMA_O_CONTROL) & RTDMA_CONTROL_PERINTFLG) != 0U);
}

//*****************************************************************************
//
//! Starts a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function starts the DMA running, typically after you have configured
//! it. It will wait for the first trigger event to start operation. To halt
//! the channel use DMA_stopChannel().
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_startChannel(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set the run bit.
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_RUN;
}

//*****************************************************************************
//
//! Halts a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function halts the DMA at its current state and any current read-write
//! access is completed. To start the channel again use DMA_startChannel().
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_stopChannel(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set the halt bit.
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_HALT;
}

//*****************************************************************************
//
//! Sets the interrupt generation mode of a DMA channel interrupt.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param mode is a flag to indicate the channel interrupt mode.
//!
//! This function sets the channel interrupt mode. When the \e mode parameter
//! is
//! - \b DMA_INT_AT_END, the DMA channel interrupt will be generated at the
//! end of the transfer.
//! - \b DMA_INT_AT_BEGINNING, the interrupt will be generated at the
//! beginning of a new transfer. Generating at the beginning of a new
//! transfer is the default behavior.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_setInterruptMode(uint32_t base, DMA_InterruptMode mode)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Write the selected interrupt generation mode to the register.
    //
    if (mode == DMA_INT_AT_END)
    {
        HWREG(base + RTDMA_O_MODE) |= RTDMA_MODE_CHINTMODE;
    }
    else
    {
        HWREG(base + RTDMA_O_MODE) &= ~RTDMA_MODE_CHINTMODE;
    }
}

//*****************************************************************************
//
//! Enables a DMA channel interrupt source.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function enables the indicated DMA channel;s CPU interrupt.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_enableInterrupt(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Enable the specified DMA channel interrupt.
    //
    HWREG(base + RTDMA_O_MODE) |= RTDMA_MODE_CHINTE;
}

//*****************************************************************************
//
//! Disables a DMA channel interrupt source.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function disables the indicated DMA channel's CPU interrupt.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_disableInterrupt(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Disable the specified DMA channel interrupt.
    //
    HWREG(base + RTDMA_O_MODE) &= ~RTDMA_MODE_CHINTE;
}

//*****************************************************************************
//
//! Locks the DMA configuration registers
//!
//! \param base is the base address of the DMA configuration registers.
//!
//! The configuration registers in the RTDMA_REGS apeture DMACTRL, DEBUGCTRL,
//! SWPRI1/2 are locked (writes will have no effect on them).
//! This can only be done if DMACFG_COMMIT.COMMIT is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_lockDMAConfig"))) __attribute__((always_inline)) static inline void
DMA_lockDMAConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Lock DMA configuration
    //
    HWREGB(base + RTDMA_O_DMACFG_LOCK) = RTDMA_DMACFG_LOCK_LOCK;
}

//*****************************************************************************
//
//! Unlocks DMA configuration registers
//!
//! \param base is the base address of the DMA configuration registers.
//!
//! The configuration registers in the RTDMA_REGS apeture DMACTRL, DEBUGCTRL,
//! SWPRI1/2 are unlocked and can be modified.
//! This can only be done if DMACFG_COMMIT.COMMIT is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_unlockDMAConfig"))) __attribute__((always_inline)) static inline void
DMA_unlockDMAConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Unlock DMA configuration, if not committed
    //
    HWREGB(base + RTDMA_O_DMACFG_LOCK) = 0U;
}

//*****************************************************************************
//
//! Commits the DMA configuration registers
//!
//! \param base is the base address of the DMA configuration registers.
//!
//! This function commits the lock on the DMA configuration registers.
//! Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_commitDMAConfig"))) __attribute__((always_inline)) static inline void
DMA_commitDMAConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Commit the lock on the DMA configuration registers
    //
    HWREGB(base + RTDMA_O_DMACFG_COMMIT) = RTDMA_DMACFG_COMMIT_COMMIT;
}

//*****************************************************************************
//
//! Enables the DMA channel overrun interrupt.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function enables the indicated DMA channel's ability to generate an
//! interrupt upon the detection of an overrun. An overrun is when a peripheral
//! event trigger is received by the DMA before a previous trigger on that
//! channel had been serviced and its flag had been cleared.
//!
//! Note that this is the same interrupt signal as the interrupt that gets
//! generated at the beginning/end of a transfer. That interrupt must first be
//! enabled using DMA_enableInterrupt() in order for the overrun interrupt to
//! be generated.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_enableOverrunInterrupt(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Enable the specified DMA channel interrupt.
    //
    HWREGH(base + RTDMA_O_MODE) |= RTDMA_MODE_OVRINTE;
}

//*****************************************************************************
//
//! Disables the DMA channel overrun interrupt.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function disables the indicated DMA channel's ability to generate an
//! interrupt upon the detection of an overrun.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_disableOverrunInterrupt(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Disable the specified DMA channel interrupt.
    //
    HWREGH(base + RTDMA_O_MODE) &= ~(uint16_t)RTDMA_MODE_OVRINTE;
}

//*****************************************************************************
//
//! Clears the DMA channel error flags.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function clears both the DMA channel's sync error flag and its
//! overrun error flag.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_clearErrorFlag(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Write to the error clear bit
    //
    HWREGB(base + RTDMA_O_CONTROL) = RTDMA_CONTROL_ERRCLR;
}

//*****************************************************************************
//
//! Configures the source address for the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *srcAddr is a source address.
//!
//! This function configures the source address of a DMA channel.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_configSourceAddress(uint32_t base, const void *srcAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set up SOURCE address.
    //
    HWREG(base + RTDMA_O_SRC_BEG_ADDR_SHADOW) = (uint32_t)srcAddr;
    HWREG(base + RTDMA_O_SRC_ADDR_SHADOW)     = (uint32_t)srcAddr;
}

//*****************************************************************************
//
//! Configures the destination address for the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *destAddr is the destination address.
//!
//! This function configures the destinaton address of a DMA channel.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_configDestAddress(uint32_t base, const void *destAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Set up DESTINATION address.
    //
    HWREG(base + RTDMA_O_DST_BEG_ADDR_SHADOW) = (uint32_t)destAddr;
    HWREG(base + RTDMA_O_DST_ADDR_SHADOW)     = (uint32_t)destAddr;
}

//*****************************************************************************
//
//! Configures the modes supported during burst operation
//!
//! \param base is the base address of the DMA channel control registers.
//! \param mode is the mode
//!
//! This function configures the modes supported during burst operation. The
//! Burst signaling can be enabled/ disabled. If enabled, it can be configured
//! to be interrupted or not be interrupted.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_setBurstSignalingMode(uint32_t base, DMA_BurstSignalingMode mode)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Configure the Burst mode operation
    //
    HWREGB(base + RTDMA_O_BURST_INTF_CTRL) = (uint8_t)mode;
}

//*****************************************************************************
//
//! Locks the channel configuration registers of all DMA channels
//!
//! \param base is the base address of the first DMA channel control registers.
//!
//! The configuration registers of all the channels are locked
//! (writes will have no effect on them).
//! This can only be done if the corresponding CHCFG_COMMIT.COMMIT is cleared.
//!
//! This function locks the configuration registers of all the DMA channels
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_lockAllChannelConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    uint8_t  i;
    uint32_t base_ch;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_CH; i++)
    {
        base_ch = base + (0x1000U * i);

        //
        // Lock the DMA channel configuration.
        //
        HWREGB(base_ch + RTDMA_O_CHCFG_LOCK) = RTDMA_CHCFG_LOCK_LOCK;
    }
}

//*****************************************************************************
//
//! Unlocks the channel configuration registers of all DMA channels.
//!
//! \param base is the base address of the first DMA channel control registers.
//!
//! The configuration registers of the specified channel are unlocked and
//! can be modified.
//! This can only be done if CHCFG_COMMIT.COMMIT is cleared.
//!
//! This function unlocks the DMA configuration registers.
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_unlockAllChannelConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT((base == RTDMA1CH1_BASE) || (base == RTDMA2CH1_BASE));

    uint8_t  i;
    uint32_t base_ch;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_CH; i++)
    {
        base_ch = base + (0x1000U * i);
        ASSERT(DMA_CH_isBaseValid(base_ch));

        //
        // Unlock the DMA channel configuration.
        //
        HWREGB(base_ch + RTDMA_O_CHCFG_LOCK) = 0U;
    }
}

//*****************************************************************************
//
//! Commits the channel configuration registers of all DMA channels
//!
//! \param base is the base address of the first DMA channel control registers.
//!
//! This function commits the lock on the corresponding DMA channel
//! configuration registers.
//! Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_commitAllChannelConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    uint32_t i;
    uint32_t base_ch;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_CH; i++)
    {
        base_ch = base + (0x1000U * i);
        ASSERT(DMA_CH_isBaseValid(base_ch));

        //
        // Commit the DMA channel configuration.
        //
        HWREGB(base_ch + RTDMA_O_CHCFG_COMMIT) = RTDMA_CHCFG_COMMIT_COMMIT;
    }
}

//*****************************************************************************
//
//! Locks the DMA channel configuration registers
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! The configuration registers of the specified channel are locked
//! (writes will have no effect on them).
//! This will only be done if CHCFG_COMMIT.COMMIT is cleared.
//!
//! This function locks the DMA channel configuration registers
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_lockChannelConfig(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Lock the DMA channel configuration.
    //
    HWREGB(base + RTDMA_O_CHCFG_LOCK) = RTDMA_CHCFG_LOCK_LOCK;
}

//*****************************************************************************
//
//! Unlocks the DMA channel configuration registers.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! The configuration registers of the specified channel are unlocked and
//! can be modified.
//! This can only be done if CHCFG_COMMIT.COMMIT is cleared.
//!
//! This function unlocks the DMA configuration registers.
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_unlockChannelConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Unlock DMA channel configuration
    //
    HWREGB(base + RTDMA_O_CHCFG_LOCK) = 0U;
}

//*****************************************************************************
//
//! Commits the DMA channel configuration registers
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function commits the lock on the corresponding DMA channel
//! configuration registers. Once committed, cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((always_inline)) static inline void DMA_commitChannelConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_CH_isBaseValid(base));

    //
    // Commit the lock on the DMA channel configuration registers
    //
    HWREGB(base + RTDMA_O_CHCFG_COMMIT) = RTDMA_CHCFG_COMMIT_COMMIT;
}

//*****************************************************************************
//
//! Enables the MPU function
//!
//! \param base is the base address of the MPU registers.
//!
//! This function enables the MPU function. It can be executed by SROOT only.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_enableMPU"))) __attribute__((always_inline)) static inline void DMA_enableMPU(
    uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Set the MPU function enable bit.
    //
    HWREGB(base + RTDMA_O_MPUCTRL) |= RTDMA_MPUCTRL_MPUEN;
}

//*****************************************************************************
//
//! Disables the MPU function
//!
//! \param base is the base address of the MPU registers.
//!
//! This function disables the MPU function. It can be executed by SROOT only.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_disableMPU"))) __attribute__((always_inline)) static inline void DMA_disableMPU(
    uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Set the MPU function enable bit.
    //
    HWREGB(base + RTDMA_O_MPUCTRL) &= ~RTDMA_MPUCTRL_MPUEN;
}

//*****************************************************************************
//
//! Locks the MPU configuration register
//!
//! \param base is the base address of the MPU registers.
//!
//! The MPU configuration register MPUCTRL is locked (writes will have no
//! effect on them). This is only done if MPUCFG_COMMIT.COMMIT is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_lockMPUConfig"))) __attribute__((always_inline)) static inline void
DMA_lockMPUConfig(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Lock the MPU region configuration.
    //
    HWREGB(base + RTDMA_O_MPUCFG_LOCK) = RTDMA_MPUCFG_LOCK_LOCK;
}

//*****************************************************************************
//
//! Unlocks the MPU configuration register
//!
//! \param base is the base address of the MPU registers.
//!
//! The MPU configuration register MPUCTRL is unlocked.
//! This can only be done if MPUCFG_COMMIT.COMMIT is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_unlockMPUConfig"))) __attribute__((always_inline)) static inline void
DMA_unlockMPUConfig(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Unlock the MPU configuration
    //
    HWREGB(base + RTDMA_O_MPUCFG_LOCK) = 0U;
}

//*****************************************************************************
//
//! Commits the MPU configuration register.
//!
//! \param base is the base address of the MPU registers.
//!
//! This function commits the lock on the corresponding MPU configuration
//! register. Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_commitMPUConfig"))) __attribute__((always_inline)) static inline void
DMA_commitMPUConfig(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Commit the lock on the MPU configuration.
    //
    HWREGB(base + RTDMA_O_MPUCFG_COMMIT) = RTDMA_MPUCFG_COMMIT_COMMIT;
}

//*****************************************************************************
//
//! Locks the registers of all MPU regions
//!
//! \param base is the base address of the MPU registers.
//!
//! The configuration registers of all the MPU regions are locked
//! (writes will have no effect on them).
//! This can only be done if the corresponding COMMIT bit is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_lockAllMPURegion"))) __attribute__((always_inline)) static inline void
DMA_lockAllMPURegion(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    uint8_t i;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_MPU; i++)
    {
        //
        // Lock the MPU configuration
        //
        HWREGB(base + RTDMA_O_MPUR_LOCK(i)) = 1U;
    }
}

//*****************************************************************************
//
//! Unlocks the registers of all MPU regions
//!
//! \param base is the base address of the MPU registers.
//!
//! The configuration registers of all the MPU regions are unlocked
//! This can only be done if the corresponding COMMIT bit is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_unlockAllMPURegion"))) __attribute__((always_inline)) static inline void
DMA_unlockAllMPURegion(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_MPU_isBaseValid(base));
    uint8_t i;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_MPU; i++)
    {
        //
        // Unlock the MPU configuration
        //
        HWREGB(base + RTDMA_O_MPUR_LOCK(i)) = 0U;
    }
}

//*****************************************************************************
//
//! Commits the registers of all MPU regions.
//!
//! \param base is the base address of the MPU registers.
//!
//! This function commits the lock on the corresponding MPU region
//! configuration registers.
//! Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_commitAllMPURegion"))) __attribute__((always_inline)) static inline void
DMA_commitAllMPURegion(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    uint8_t i;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_MPU; i++)
    {
        //
        // Commit the lock on the MPU registers.
        //
        HWREGB(base + RTDMA_O_MPUR_COMMIT(i)) = 1U;
    }
}

//*****************************************************************************
//
//! Locks the registers of an MPU region.
//!
//! \param base is the base address of the MPU registers.
//! \param MPURegion is the MPU region number.
//!
//! The configuration registers of the specific MPU region is locked
//! (writes will have no effect on them).
//! This can only be done if the corresponding COMMIT bit is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_lockMPURegion"))) __attribute__((always_inline)) static inline void
DMA_lockMPURegion(uint32_t base, DMA_MPURegion MPURegion)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Lock the MPU region registers.
    //
    HWREGB(base + RTDMA_O_MPUR_LOCK((uint32_t)MPURegion)) = 1U;
}

//*****************************************************************************
//
//! Unocks the registers of an MPU region.
//!
//! \param base is the base address of the MPU registers.
//! \param MPURegion is the MPU region number.
//!
//! The configuration registers of the specific MPU region is unlocked
//! This can only be done if the corresponding COMMIT bit is cleared.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_unlockMPURegion"))) __attribute__((always_inline)) static inline void
DMA_unlockMPURegion(uint32_t base, DMA_MPURegion MPURegion)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Unlock the MPU region registers.
    //
    HWREGB(base + RTDMA_O_MPUR_LOCK((uint32_t)MPURegion)) = 0U;
}

//*****************************************************************************
//
//! Commits the MPU region configuration registers
//!
//! \param base is the base address of the MPU registers.
//! \param MPURegion is the MPU region number.
//!
//! This function commits the lock on the corresponding MPU registers.
//! Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_commitMPURegion"))) __attribute__((always_inline)) static inline void
DMA_commitMPURegion(uint32_t base, DMA_MPURegion MPURegion)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_MPU_isBaseValid(base));

    //
    // Commit the lock on MPU registers.
    //
    HWREGB(base + RTDMA_O_MPUR_COMMIT((uint32_t)MPURegion)) = 1U;
}

//*****************************************************************************
//
//! Commits all the DMA module configurations including the DMA configuration
//! registers, all the channel configuration, MPU configuration and all MPU
//! region configuration registers.
//!
//! This function commits the lock on the corresponding configuration registers
//! Once committed, it cannot be revoked except by reset.
//!
//! \return None
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_commitAllDMASettings"))) __attribute__((always_inline)) static inline void
DMA_commitAllDMASettings(void)
{
    //
    // Commit the DMA configuration.
    //
    HWREGB(RTDMA1_BASE + RTDMA_O_DMACFG_COMMIT) = 0x1U;
    HWREGB(RTDMA2_BASE + RTDMA_O_DMACFG_COMMIT) = 0x1U;

    uint8_t  i;
    uint32_t base;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_CH; i++)
    {
        base = RTDMA1CH1_BASE + (0x1000U * i);
        ASSERT(DMA_CH_isBaseValid(base));
        //
        // Commit the RTDMA1 channel configuration.
        //
        HWREGB(base + RTDMA_O_CHCFG_COMMIT) = 0x1U;
    }

    for (i = 0U; i < (uint8_t)DMA_TOTAL_CH; i++)
    {
        base = RTDMA2CH1_BASE + (0x1000U * i);
        ASSERT(DMA_CH_isBaseValid(base));
        //
        // Commit the RTDMA2 channel configuration.
        //
        HWREGB(base + RTDMA_O_CHCFG_COMMIT) = 0x1U;
    }

    //
    // Commit the MPU configuration.
    //
    HWREGB(RTDMA1_MPU_BASE + RTDMA_O_MPUCFG_COMMIT) = 0x1U;
    HWREGB(RTDMA2_MPU_BASE + RTDMA_O_MPUCFG_COMMIT) = 0x1U;

    for (i = 0U; i < (uint8_t)DMA_TOTAL_MPU; i++)
    {
        //
        // Commit the RTDMA1 MPU regions configuration.
        //
        HWREGB(RTDMA1_MPU_BASE + RTDMA_O_MPUR_COMMIT(i)) = 0x1U;
    }

    for (i = 0U; i < (uint8_t)DMA_TOTAL_MPU; i++)
    {
        //
        // Commit the RTDMA2 MPU regions configuration.
        //
        HWREGB(RTDMA2_MPU_BASE + RTDMA_O_MPUR_COMMIT(i)) = 0x1U;
    }
}

//*****************************************************************************
//
//! Setup DMA to transfer data on the specified channel.
//!
//! \param base is Base address of the DMA channel control register
//! \param *transfParams configuration parameter
//!                      Refer struct #DMA_ConfigParams
//!
//! This function configures the DMA transfer on the specified channel.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configChannel(uint32_t base, const DMA_ConfigParams *transfParams);

//*****************************************************************************
//
//! Configures the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *destAddr is the destination address.
//! \param *srcAddr is a source address.
//!
//! This function configures the source and destination addresses of a DMA
//! channel. The parameters are pointers to the data to be transferred.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configAddresses(uint32_t base, const void *destAddr, const void *srcAddr);

//*****************************************************************************
//
//! Configures the DMA channel's burst settings.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param size is the number of words transferred per burst.
//! \param srcStep is the amount to increment or decrement the source address
//! after each word of a burst.
//! \param destStep is the amount to increment or decrement the destination
//! address after each word of a burst.
//!
//! This function configures the size of each burst and the address step size.
//!
//! The \e size parameter is the number of words that will be transferred
//! during a single burst. Possible amounts range from 1 word to 64 words.
//!
//! The \e srcStep and \e destStep parameters specify the address step that
//! should be added to the source and destination addresses after each
//! transferred word of a burst. Only signed values from -4096 to 4095 are
//! valid.
//!
//! \note Note that regardless of what data size (configured by
//! DMA_configMode()) is used, parameters are in terms of 16-bits words.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configBurst(uint32_t base, uint16_t size, int16_t srcStep, int16_t destStep);

//*****************************************************************************
//
//! Configures the DMA channel's transfer settings.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param transferSize is the number of bursts per transfer.
//! \param srcStep is the amount to increment or decrement the source address
//! after each burst of a transfer unless a wrap occurs.
//! \param destStep is the amount to increment or decrement the destination
//! address after each burst of a transfer unless a wrap occurs.
//!
//! This function configures the transfer size and the address step that is
//! made after each burst.
//!
//! The \e transferSize parameter is the number of bursts per transfer. If DMA
//! channel interrupts are enabled, they will occur after this number of bursts
//! have completed. The maximum number of bursts is 65536.
//!
//! The \e srcStep and \e destStep parameters specify the address step that
//! should be added to the source and destination addresses after each
//! transferred burst of a transfer. Only signed values from -4096 to 4095 are
//! valid. If a wrap occurs, these step values will be ignored. Wrapping is
//! configured with DMA_configWrap().
//!
//! \note Note that regardless of what data size (configured by
//! DMA_configMode()) is used, parameters are in terms of 16-bits words.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configTransfer(uint32_t base, uint32_t transferSize, int16_t srcStep, int16_t destStep);

//*****************************************************************************
//
//! Configures the DMA channel's wrap settings.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param srcWrapSize is the number of bursts to be transferred before a wrap
//! of the source address occurs.
//! \param srcStep is the amount to increment or decrement the source address
//! after each burst of a transfer unless a wrap occurs.
//! \param destWrapSize is the number of bursts to be transferred before a wrap
//! of the destination address occurs.
//! \param destStep is the amount to increment or decrement the destination
//! address after each burst of a transfer unless a wrap occurs.
//!
//! This function configures the DMA channel's wrap settings.
//!
//! The \e srcWrapSize and \e destWrapSize parameters are the number of bursts
//! that are to be transferred before their respective addresses are wrapped.
//! The maximum wrap size is 65536 bursts.
//!
//! The \e srcStep and \e destStep parameters specify the address step that
//! should be added to the source and destination addresses when the wrap
//! occurs.  Only signed values from -4096 to 4095 are valid.
//!
//! \note Note that regardless of what data size (configured by
//! DMA_configMode()) is used, parameters are in terms of 16-bits words.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configWrap(uint32_t base, uint32_t srcWrapSize, int16_t srcStep, uint32_t destWrapSize,
                           int16_t destStep);

//*****************************************************************************
//
//! Configures the DMA channel trigger and mode.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param trigger is the interrupt source that triggers a DMA transfer.
//! \param config is a bit field of several configuration selections.
//!
//! This function configures the DMA channel's trigger and mode.
//!
//! The \e trigger parameter is the interrupt source that will trigger the
//! start of a DMA transfer.
//!
//! The \e config parameter is the logical OR of the following values:
//! - \b DMA_CFG_ONESHOT_DISABLE or \b DMA_CFG_ONESHOT_ENABLE. If enabled,
//!   the subsequent burst transfers occur without additional event triggers
//!   after the first event trigger. If disabled, only one burst transfer is
//!   performed per event trigger.
//! - \b DMA_CFG_CONTINUOUS_DISABLE or \b DMA_CFG_CONTINUOUS_ENABLE. If
//!   enabled the DMA reinitializes when the transfer count is zero and
//!   waits for the next interrupt event trigger. If disabled, the DMA
//!   stops and clears the run status bit.
//! - \b DMA_CFG_READ_SIZE_8BIT , \b DMA_CFG_READ_SIZE_16BIT ,
//!   \b DMA_CFG_READ_SIZE_32BIT , \b DMA_CFG_READ_SIZE_64BIT . This setting
//!   selects whether the read data width is 8, 16, 32 or 64 bits.
//! - \b DMA_CFG_WRT_SIZE_8BIT , \b DMA_CFG_WRT_SIZE_16BIT,
//!   \b DMA_CFG_WRT_SIZE_32BIT , \b DMA_CFG_WRT_SIZE_64BIT.  This setting
//!   selects whether the write data width is 8, 16, 32 or 64 bits.
//! - To configure the read and write data size to be equal, a single macro
//!   \b DMA_CFG_SIZE_8BIT , \b DMA_CFG_SIZE_16BIT , \b DMA_CFG_SIZE_32BIT
//!   \b DMA_CFG_SIZE_64BIT can be used, instead of DMA_CFG_READ_SIZE_xBIT
//!   and DMA_CFG_WRT_SIZE_xBIT macros.
//!
//! \return None.
//
//*****************************************************************************
extern void DMA_configMode(uint32_t base, DMA_Trigger trigger, uint32_t config);

//*****************************************************************************
//
//! Setup a DMA MPU region.
//!
//! \param base is the base address of the MPU registers.
//! \param *configParams is a pointer to configuration parameter.
//!                      Refer struct #DMA_MPUConfigParams
//!
//! This function configures the DMA transfer on the specified channel.
//!
//! \return None.
//
//*****************************************************************************
__attribute__((section(".text.link2.DMA_configMPURegion"))) extern void DMA_configMPURegion(
    uint32_t base, DMA_MPURegion MPURegion, const DMA_MPUConfigParams *configParams);

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

#endif  // RTDMA_H
