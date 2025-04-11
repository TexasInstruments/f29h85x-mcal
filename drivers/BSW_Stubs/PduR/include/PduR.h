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
 *  File:       PduR.h
 *  Project:    F29x MCAL
 *  Module:     Can Interface
 *  Generator:  None
 *
 *  Description:  This file contains interface header for PduR callback functions.
 *                                                                     
 *********************************************************************************************************************/
#ifndef PDUR_H
#define PDUR_H
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "ComStack_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief Defines for symbolic names for the PduR Handle Id's */

#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_0        0U	  /*~ASR~*/
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_1        1U	  /*~ASR~*/
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_2        2U    /*~ASR~*/
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_3        3U    /*~ASR~*/	
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_4        4U    /*~ASR~*/	
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_5        5U    /*~ASR~*/		
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_6        6U    /*~ASR~*/		
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_7        7U    /*~ASR~*/		
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_8        8U    /*~ASR~*/		
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_9        9U    /*~ASR~*/		
#define PduRConf_PduRSrcPdu_PduRSrcPdu_Pdu_10       10U   /*~ASR~*/		

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
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

Std_ReturnType PduR_Cdd_Sent_RxIndication( PduIdType RxPduId, const PduInfoType* PduInfoPtr );

Std_ReturnType PduR_Cdd_Ipc_RxIndication( PduIdType RxPduId, const PduInfoType* PduInfoPtr );

#endif /* PDUR_H */
/*********************************************************************************************************************
 *  End of File: PduR.h
 *********************************************************************************************************************/
