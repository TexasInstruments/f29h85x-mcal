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
 *  \param[in] llobj            Link list object.
 *  \param[in] node             Node object pointer used for linking.
 *  \param[in] data             Data pointer to add to node.
 *  \param[in] params           Pointer to node params containing info like data
 *                              pointer, priority, seqId, seqInterruptible.
 *  \param[in] currSeqId        Current sequence ID in progress for the HW unit.
 *  \param[out] llobj            Link list object.
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
 *  \param[in] llobj: pointer to linklist Object
 *  \param[in] node: pointer to a node in linklist
 *  \param[out] llobj: pointer to linklist Object
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
