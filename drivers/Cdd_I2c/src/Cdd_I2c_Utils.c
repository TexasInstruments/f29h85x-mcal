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
 *  File:       Cdd_I2c_Utils.c
 *  Generator:  None
 *
 *  Description:  Utility functions implementation file.
 *                This file defines the helper functions like create, add and remove nodes
 *
 *********************************************************************************************************************/

/**
 *  \file Cdd_I2c_Utils.c
 *
 *  \brief Utility functions implementation file.
 *  This file defines the helper functions like create, add and remove nodes
 *
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c_Utils.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

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

static void Cdd_I2c_UtilsLinkDoublePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node,
                                       const Cdd_I2c_UtilsParams *params, uint8 currSeqId);
static void Cdd_I2c_UtilsUnLinkDoublePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

void Cdd_I2c_UtilsInitLinkList(Cdd_I2c_UtilsLinkListObj *llobj)
{
    /* Initialize the variables */
    llobj->headNode = (Cdd_I2c_UtilsNode *)NULL_PTR;
    llobj->tailNode = (Cdd_I2c_UtilsNode *)NULL_PTR;

    return;
}

void Cdd_I2c_UtilsDeInitLinkList(Cdd_I2c_UtilsLinkListObj *llobj)
{
    llobj->headNode = (Cdd_I2c_UtilsNode *)NULL_PTR;
    llobj->tailNode = (Cdd_I2c_UtilsNode *)NULL_PTR;

    return;
}

void Cdd_I2c_UtilsLinkNodePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node,
                              const Cdd_I2c_UtilsParams *params, uint8 currSeqId)
{
    Cdd_I2c_UtilsLinkDoublePri(llobj, node, params, currSeqId);

    return;
}

void Cdd_I2c_UtilsUnLinkNodePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node)
{
    Cdd_I2c_UtilsUnLinkDoublePri(llobj, node);

    return;
}

void Cdd_I2c_UtilsInitNodeObject(Cdd_I2c_UtilsNode *node)
{
    node->next                    = (Cdd_I2c_UtilsNode *)NULL_PTR;
    node->prev                    = (Cdd_I2c_UtilsNode *)NULL_PTR;
    node->params.data             = NULL_PTR;
    node->params.priority         = 0U;
    node->params.seqId            = 0U;
    node->params.seqInterruptible = (uint8)FALSE;

    return;
}

Cdd_I2c_UtilsNode *Cdd_I2c_UtilsGetHeadNode(const Cdd_I2c_UtilsLinkListObj *llobj)
{
    return (llobj->headNode);
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/**
 *  Cdd_I2c_UtilsLinkDoublePri
 *  \brief Links a node to a double link list based on priority.
 *  For nodes with same priority, the new node will be added to the
 *  last.
 */
static void Cdd_I2c_UtilsLinkDoublePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node,
                                       const Cdd_I2c_UtilsParams *params, uint8 currSeqId)
{
    uint32             interruptible = 0U;
    Cdd_I2c_UtilsNode *curNode       = (Cdd_I2c_UtilsNode *)NULL_PTR;
    Cdd_I2c_UtilsNode *prevNode      = (Cdd_I2c_UtilsNode *)NULL_PTR;

    prevNode                      = (Cdd_I2c_UtilsNode *)NULL_PTR;
    node->params.data             = params->data;
    node->params.priority         = params->priority;
    node->params.seqId            = params->seqId;
    node->params.seqInterruptible = params->seqInterruptible;

    /* Add to the list based on priority */
    curNode = llobj->headNode;
    while (NULL_PTR != curNode)
    {
        /* Check if we can insert the ch after current ch */
        interruptible = (uint32)TRUE;
        if ((((uint8)FALSE) == curNode->params.seqInterruptible) && (currSeqId == curNode->params.seqId))
        {
            interruptible = (uint32)FALSE;
        }

        /* Nodes with the same priority are always added to the bottom
         * of the existing nodes with same priority. So break only if
         * priority is high */
        if ((params->priority > curNode->params.priority) && (((uint32)TRUE) == interruptible))
        {
            break;
        }

        /* Move to next node */
        prevNode = curNode;
        curNode  = curNode->next;
    }

    /* Add the node between current and previous nodes */
    node->next = curNode;
    node->prev = prevNode;
    if (NULL_PTR != prevNode)
    {
        prevNode->next = node;
    }
    else
    {
        /* Adding to the top of the list */
        llobj->headNode = node;
    }

    if (NULL_PTR != curNode)
    {
        curNode->prev = node;
    }
    else
    {
        llobj->tailNode = node;
    }

    return;
}

/**
 *  Cdd_I2c_UtilsUnLinkDoublePri
 *  \brief Unlinks a node from a double link list.
 */
static void Cdd_I2c_UtilsUnLinkDoublePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node)
{
    if (NULL_PTR == node->prev)
    {
        /* Removing head node */
        llobj->headNode = node->next;
    }
    else
    {
        /* Removing non-head node */
        node->prev->next = node->next;
    }

    if (NULL_PTR != node->next)
    {
        node->next->prev = node->prev;
    }
    else
    {
        llobj->tailNode = (Cdd_I2c_UtilsNode *)NULL_PTR;
    }

    /* Reset node memory */
    node->next = (Cdd_I2c_UtilsNode *)NULL_PTR;
    node->prev = (Cdd_I2c_UtilsNode *)NULL_PTR;

    return;
}

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Utils.c
 *********************************************************************************************************************/
