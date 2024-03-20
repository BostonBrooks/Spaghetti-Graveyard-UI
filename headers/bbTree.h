/**
 * @file
 * @brief bbTree defines a structure where each member has a parent and a list of daughter nodes.
 * the first element of the member should start with :
 *
 *	bbPool_data p_Pool;
 *	bbTree p_Tree;
 *
 *	Any such structure can be referred to as bbNode
 *
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
	// end of list of daughter nodes
	int32_t Tail;
	// previous in list of daughter nodes
	int32_t Prev;
	// next in list of daughter nodes
	int32_t Next;

} bbTree;

typedef struct {
	bbPool_data p_Pool;
	bbTree p_Tree;
} bbEmptyNode;

/// add a new (with no daughter nodes) as a daughter node to parent;
int32_t bbNode_setParent(bbEmptyNode* node, bbEmptyNode* parent, bbPool* pool);
///recursively search through nodes until myFunc(node); returns f_Break
int32_t descending_search(bbEmptyNode* root, void* myFunc, bbPool* pool);
///recursively search through nodes until myFunc(node); returns f_Break
int32_t ascending_search(bbEmptyNode* root, void* myFunc, bbPool* pool);

#endif // BBTREE_H;