/**
 * @file
 * @brief bbTree defines a structure where each member has a parent and a list of daughter nodes.
 * the first element of the member should start with :
 *
 *	bbNode p_Node
 *
 *	Any such structure can be referred to as bbNode
 *
 *	bbPool_data p_Pool is the first element of bbNode
 *  bbNode p_Node is the first element of bbTest_Node
 *  bbTestNode is an example of the kind of object to be stored in a bbTree
 *
 *  as such bbTestNode can be cast as bbNode and bbNode can be cast as bbPool
 */

#ifndef BBTREE_H
#define BBTREE_H

#include <inttypes.h>
#include "headers/bbPool.h"

typedef struct {
	// Integer address (location in pool) of parent node
	int32_t Parent;
	// Start of list of daughter nodes
	int32_t Head;
	// End of list of daughter nodes
	int32_t Tail;
	// Previous in list of daughter nodes
	int32_t Prev;
	// Next in list of daughter nodes
	int32_t Next;

} bbTree_data;

typedef struct {
	bbPool_data p_Pool;
	bbTree_data p_Tree;
} bbNode;

typedef struct {
	bbNode p_Node;
	char* string;
	int32_t integer;
} bbTestNode;

typedef int32_t bbTreeFunction (void* reference, void* node);

/// add a new node (with no daughter nodes) as a daughter node to parent;
int32_t bbNode_setParent(void* node, void* parent, bbPool* pool);
///recursively search through nodes until myFunc(node); returns f_Break
int32_t descending_search(void* reference, void* root, bbTreeFunction* myFunc, bbPool* pool);
///recursively search through nodes until myFunc(node); returns f_Break
int32_t ascending_search(void* reference, void* root, bbTreeFunction* myFunc, bbPool* pool);

#endif // BBTREE_H;