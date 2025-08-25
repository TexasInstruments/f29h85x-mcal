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
 *  File:       Spi_Utils.h
 *  Generator:  None
 *
 *  Description:  SPI utility functions header file
 *  This file declares the functions required to create, add and remove nodes.
 *
 *********************************************************************************************************************/
#ifndef SPI_UTILS_H_
#define SPI_UTILS_H_
/** \addtogroup SPI
 *  @{
 */
/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"

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
typedef struct Spi_UtilsNode_t Spi_UtilsNode;

/**
 *  struct Spi_UtilsParams
 *  \brief Structure for storing node info.
 */
typedef struct
{
    void  *data;
    /**< Node data pointer pointer */
    uint32 priority;
    /**< Priority of the node. Used for priority based linked list. Priority is
     *   in ascending order of the value. So 0 is the lowest priority and is
     *   added to the bottom of the node.Nodes with the same priority are always
     *   added to the bottom of the existing nodes with same priority. for
     *   non-priority based modes, this parameter is ignored and could be set
     *   to 0. */
    uint8  seqId;
    /**< Sequence ID to which the job belongs. */
    uint8  seqInterruptible;
    /**< Flag indicating whether the sequence to which this job belongs is
     *   interruptible or not. */
} Spi_UtilsParams;

/**
 *  struct Spi_UtilsNode_t
 *  \brief Self referential structure for double link list.
 */
struct Spi_UtilsNode_t
{
    Spi_UtilsNode  *next;
    /**< Pointer to the next node. */
    Spi_UtilsNode  *prev;
    /**< Pointer to the previous node. */
    Spi_UtilsParams params;
    /**< Node info structure. */
};

/**
 *  struct Spi_UtilsLinkListObj
 *  \brief Structure to the link list object information.
 */
typedef struct
{
    Spi_UtilsNode *headNode;
    /**< Head node reference pointer */
    Spi_UtilsNode *tailNode;
    /**< Tail node reference pointer */
} Spi_UtilsLinkListObj;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief function to Initialize linked list
 *
 *  function to Initialize linked list
 *
 * \param[inout] llobj: pointer to linklist Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
void Spi_UtilsInitLinkList(Spi_UtilsLinkListObj *llobj);

/** \brief function to De-Initialize linked list
 *
 *  function to De-Initialize linked list
 *
 * \param[inout] llobj: pointer to linklist Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
void Spi_UtilsDeInitLinkList(Spi_UtilsLinkListObj *llobj);

/**
 *  \brief Links a node to the linked list.
 *  The memory to the node object should be allocated by the caller. This
 *  is used for link list with priority.
 *
 *  \param[in] llobj            Link list object.
 *  \param[in] node             Node object pointer used for linking.
 *  \param[in] params           Pointer to node params containing info like data
 *                              pointer, priority, seqId, seqInterruptible.
 *  \param[in] currSeqId        Current sequence ID in progress for the HW unit.
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node, const Spi_UtilsParams *params,
                          uint8 currSeqId);

/**
 *  \brief Unlinks the node from the list. Used for the priority link lists.
 *
 *  \param[in] llobj: pointer to linklist Object
 *  \param[in]  node: pointer to a node in linklist
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsUnLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node);

/**
 *  \brief Initialize the node object with default value.
 *
 *  \param[in] node: pointer to a node in linklist
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsInitNodeObject(Spi_UtilsNode *node);

/**
 *  \brief                  Returns the reference to the head node. This does
 *                          not remove the node from the head.
 *
 *  \param[inout] llobj            Link list object.
 *  \pre None
 *  \post None
 *  \return  Returns the reference to the head node
 *  \retval pointer to a node in linklist
 ********************************************************************************************************************/
Spi_UtilsNode *Spi_UtilsGetHeadNode(const Spi_UtilsLinkListObj *llobj);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Mark the end of the C bindings section for C++ compilers.
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* #ifndef SPI_UTILS_H_ */
/*********************************************************************************************************************
 *  End of File: Spi_Utils.h
 *********************************************************************************************************************/
