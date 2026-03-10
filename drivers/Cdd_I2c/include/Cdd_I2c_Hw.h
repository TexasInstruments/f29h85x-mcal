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
 *  File:       Cdd_I2c_Hw.h
 *  Generator:  None
 *
 *  Description:  This file contains the private implementation of I2C HW functions.
 *********************************************************************************************************************/

#ifndef CDD_I2C_HW_H_
#define CDD_I2C_HW_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c_Priv.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/* ISRC INTCODE values for target-relevant interrupt sources */
#define CDD_I2C_ISRC_INTCODE_NONE            ((uint16)0x0000U)
#define CDD_I2C_ISRC_INTCODE_ARBL            ((uint16)0x0001U)
#define CDD_I2C_ISRC_INTCODE_NACK            ((uint16)0x0002U)
#define CDD_I2C_ISRC_INTCODE_ARDY            ((uint16)0x0003U)
#define CDD_I2C_ISRC_INTCODE_RRDY            ((uint16)0x0004U)
#define CDD_I2C_ISRC_INTCODE_XRDY            ((uint16)0x0005U)
#define CDD_I2C_ISRC_INTCODE_SCD             ((uint16)0x0006U)
#define CDD_I2C_ISRC_INTCODE_AAT             ((uint16)0x0007U)
#define CDD_I2C_ISRC_INTCODE_EXT_CLK_STRETCH ((uint16)0x0008U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

void Cdd_I2c_HwInit(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk,
                    Cdd_I2c_AddressType ownAddress, uint8 mode);
void Cdd_I2c_HwDeInit(uint32 baseAddr);

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPolling(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPollingContinue(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPolling(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPollingContinue(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxIntr(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxIntr(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxRxIntrContinue(Cdd_I2c_ChObjType *chObj);

void Cdd_I2c_HwEnableIntr(uint32 baseAddr, uint16 mask);
void Cdd_I2c_HwDisableIntr(uint32 baseAddr, uint16 mask);

void Cdd_I2c_HwDisableAllIntr(uint32 baseAddr);
void Cdd_I2c_HwClearAllStatus(uint32 baseAddr);

void   Cdd_I2c_HwSetMode(uint32 baseAddr, uint16 ctrlMask, uint16 ctrlCmds);
void   Cdd_I2c_HwSetDataCount(uint32 baseAddr, uint16 length);
void   Cdd_I2c_SetExtCompatibilityMode(uint32 baseAddr, uint8 extCompMode);
void   Cdd_I2c_DisableFifo(uint32 baseAddr);
uint16 Cdd_I2c_HwGetIntCode(uint32 baseAddr);

void  Cdd_I2c_HwWriteData(uint32 baseAddr, uint8 data);
uint8 Cdd_I2c_HwReadData(uint32 baseAddr);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CDD_I2C_HW_H_ */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Hw.h
 *********************************************************************************************************************/
