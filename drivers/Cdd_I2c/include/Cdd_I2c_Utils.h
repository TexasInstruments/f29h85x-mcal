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
 *  File:       Cdd_I2c_Utils.h
 *  Generator:  None
 *
 *  Description:  I2C utility functions header file
 *                This file declares the functions required to create, add and remove nodes.
 *********************************************************************************************************************/

#ifndef CDD_I2C_UTILS_H_
#define CDD_I2C_UTILS_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Std_Types.h"

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

/**< \brief Typedef for Node structure. */
typedef struct Cdd_I2c_UtilsNode_t Cdd_I2c_UtilsNode;

/**
 *  struct Cdd_I2c_UtilsParams
 *  \brief Structure for storing node info.
 */
typedef struct
{
    void  *data;
    /**< Node data pointer pointer */
    uint32 priority;
    /**< Priority of the node. Used for priority based linked list.
     *   Priority is in ascending order of the value. So 0 is the
     *   lowest priority and is added to the bottom of the node.Nodes
     *   with the same priority are always added to the bottom of the
     *   existing nodes with same priority. for non-priority based
     *   modes, this parameter is ignored and could be set
     *   to 0. */
    uint8  seqId;
    /**< Sequence ID to which the ch belongs. */
    uint8  seqInterruptible;
    /**< Flag indicating whether the sequence to which this ch
     *   belongs is interruptible or not. */
} Cdd_I2c_UtilsParams;

/**
 *  struct Cdd_I2c_UtilsNode_t
 *  \brief Self referential structure for double link list.
 */
struct Cdd_I2c_UtilsNode_t
{
    Cdd_I2c_UtilsNode  *next;
    /**< Pointer to the next node. */
    Cdd_I2c_UtilsNode  *prev;
    /**< Pointer to the previous node. */
    Cdd_I2c_UtilsParams params;
    /**< Node info structure. */
};

/**
 *  struct Cdd_I2c_UtilsLinkListObj
 *  \brief Structure to the link list object information.
 */
typedef struct
{
    Cdd_I2c_UtilsNode *headNode;
    /**< Head node reference pointer */
    Cdd_I2c_UtilsNode *tailNode;
    /**< Tail node reference pointer */
} Cdd_I2c_UtilsLinkListObj;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/**
 *  \brief Init a link list object.
 *
 *  \param llobj            Link list object.
 */
void Cdd_I2c_UtilsInitLinkList(Cdd_I2c_UtilsLinkListObj *llobj);

/**
 *  \brief De-init a link list object.
 *
 *  \param llobj            Link list object.
 */
void Cdd_I2c_UtilsDeInitLinkList(Cdd_I2c_UtilsLinkListObj *llobj);

/**
 *  \brief Links a node to the linked list.
 *  The memory to the node object should be allocated by the caller.
 *  This is used for link list with priority.
 *
 *  \param llobj           Link list object.
 *  \param node            Node object pointer used for linking.
 *  \param params          Pointer to node params containing info
 *                         like data
 *                         pointer, priority, seqId, seqInterruptible.
 *  \param currSeqId       Current sequence ID in progress for the HW
 *                         unit.
 */
void Cdd_I2c_UtilsLinkNodePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node,
                              const Cdd_I2c_UtilsParams *params, uint8 currSeqId);

/**
 *  \brief Unlinks the node from the list. Used for the priority link
    lists.
 *
 *  \param llobj            Link list object.
 *  \param node             Node pointer to be unlinked from the list.
 */
void Cdd_I2c_UtilsUnLinkNodePri(Cdd_I2c_UtilsLinkListObj *llobj, Cdd_I2c_UtilsNode *node);

/**
 *  \brief Initialize the node object with default value.
 *
 *  \param node             Node pointer to initialize.
 */
void Cdd_I2c_UtilsInitNodeObject(Cdd_I2c_UtilsNode *node);

/**
 *  \brief Returns the reference to the head node.
 *         This does not remove the node from the head.
 *
 *  \param llobj            Link list object.
 */
Cdd_I2c_UtilsNode *Cdd_I2c_UtilsGetHeadNode(const Cdd_I2c_UtilsLinkListObj *llobj);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef I2C_UTILS_H_ */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Utils.h
 *********************************************************************************************************************/
