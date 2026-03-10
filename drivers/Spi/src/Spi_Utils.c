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
 *  File:       Spi_Utils.c
 *  Generator:  None
 *
 *  Description:  Utility functions implementation file.
 *  This file defines the helper functions like create, add and remove nodes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi_Utils.h"

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
/**
 *  \brief Links a node to the linked list.
 *  The memory to the node object should be allocated by the caller. This
 *  is used for link list with priority.
 *
 *  \param[inout] llobj            Link list object.
 *  \param[in] node             Node object pointer used for linking.
 *  \param[in] params           Pointer to node params containing info like data
 *                              pointer, priority, seqId, seqInterruptible.
 *  \param[in] currSeqId        Current sequence ID in progress for the HW unit.
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
static void Spi_UtilsLinkDoublePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node, const Spi_UtilsParams *params,
                                   uint8 currSeqId);

/**
 *  \brief Unlinks the node from the list. Used for the priority link lists.
 *
 *  \param[inout] llobj: pointer to linklist Object
 *  \param[in] node: pointer to a node in linklist
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
static void Spi_UtilsUnLinkDoublePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

void Spi_UtilsInitLinkList(Spi_UtilsLinkListObj *llobj)
{
    /* Initialize the variables */
    llobj->headNode = NULL_PTR;
    llobj->tailNode = NULL_PTR;

    return;
}

void Spi_UtilsDeInitLinkList(Spi_UtilsLinkListObj *llobj)
{
    llobj->headNode = NULL_PTR;
    llobj->tailNode = NULL_PTR;

    return;
}

void Spi_UtilsLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node, const Spi_UtilsParams *params,
                          uint8 currSeqId)
{
    Spi_UtilsLinkDoublePri(llobj, node, params, currSeqId);

    return;
}

void Spi_UtilsUnLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node)
{
    Spi_UtilsUnLinkDoublePri(llobj, node);

    return;
}

void Spi_UtilsInitNodeObject(Spi_UtilsNode *node)
{
    node->next                    = NULL_PTR;
    node->prev                    = NULL_PTR;
    node->params.data             = NULL_PTR;
    node->params.priority         = ((uint32)0U);
    node->params.seqId            = ((uint8)0U);
    node->params.seqInterruptible = (uint8)FALSE;

    return;
}

Spi_UtilsNode *Spi_UtilsGetHeadNode(const Spi_UtilsLinkListObj *llobj)
{
    return (llobj->headNode);
}

/**
 *  Spi_UtilsLinkDoublePri
 *  \brief Links a node to a double link list based on priority.
 *  For nodes with same priority, the new node will be added to the last.
 */
static void Spi_UtilsLinkDoublePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node, const Spi_UtilsParams *params,
                                   uint8 currSeqId)
{
    VAR(uint32, AUTOMATIC) interruptible;
    P2VAR(Spi_UtilsNode, AUTOMATIC, SPI_CODE) curNode;
    P2VAR(Spi_UtilsNode, AUTOMATIC, SPI_CODE) prevNode;

    prevNode                      = NULL_PTR;
    node->params.data             = params->data;
    node->params.priority         = params->priority;
    node->params.seqId            = params->seqId;
    node->params.seqInterruptible = params->seqInterruptible;

    /* Add to the list based on priority */
    curNode = llobj->headNode;
    while (NULL_PTR != curNode)
    {
        /* Check if we can insert the job after current job */
        if (currSeqId == curNode->params.seqId)
        {
            interruptible = (uint32)TRUE;
        }
        else
        {
            interruptible = (uint32)curNode->params.seqInterruptible;
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
 *  Spi_UtilsUnLinkDoublePri
 *  \brief Unlinks a node from a double link list.
 */
static void Spi_UtilsUnLinkDoublePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node)
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
        llobj->tailNode = NULL_PTR;
    }

    /* Reset node memory */
    node->next = NULL_PTR;
    node->prev = NULL_PTR;

    return;
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Spi_Utils.c
 *********************************************************************************************************************/
