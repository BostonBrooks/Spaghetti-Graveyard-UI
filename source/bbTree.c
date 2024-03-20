#include "headers/bbTree.h"
#include "headers/bbFlags.h"
#include "headers/bbPrintf.h"

int32_t bbNode_setParent(bbEmptyNode* node, bbEmptyNode* parent, bbPool* pool){
	node->p_Tree.Parent = parent->p_Pool.Self;
	node->p_Tree.Head = f_None;
	node->p_Tree.Tail = f_None;
	node->p_Tree.Prev = f_None;
	node->p_Tree.Next = f_None;

	if (parent->p_Tree.Head == f_None){
		bbAssert(parent->p_Tree.Tail == f_None, "head/tail mismatch");
		parent->p_Tree.Head = node->p_Pool.Self;
		parent->p_Tree.Tail	= node->p_Pool.Self;
		return f_Success;
	}

	bbEmptyNode* tailNode;
	int32_t flag = bbPool_Lookup(&tailNode, pool, parent->p_Tree.Tail);

}