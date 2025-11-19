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
                    Cdd_I2c_AddressType ownAddress);
void Cdd_I2c_HwDeInit(uint32 baseAddr);

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPolling(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPollingContinue(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPolling(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPollingContinue(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxIntr(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwRxIntr(Cdd_I2c_ChObjType *chObj);
Cdd_I2c_ChannelResultType Cdd_I2c_HwTxRxIntrContinue(Cdd_I2c_ChObjType *chObj);

void Cdd_I2c_HwCancelPolling(Cdd_I2c_ChObjType *chObj);
void Cdd_I2c_HwCancelIntr(Cdd_I2c_ChObjType *chObj);

void Cdd_I2c_HwDisableAllIntr(uint32 baseAddr);
void Cdd_I2c_HwClearAllStatus(uint32 baseAddr);

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
