#ifndef _INLINE_BTREE_H
#define _INLINE_BTREE_H

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif

#ifndef BTREE_BASE_NAME
#define BTREE_BASE_NAME BTreeBase
#endif

#define CreateTree(Type, argArray) \
	LP2(0x1E, APTR, CreateTree, ULONG, Type, d0, const struct BTArgArray *, argArray, a0, \
	, BTREE_BASE_NAME)

#define DeleteTree(Tree) \
	LP1NR(0x24, DeleteTree, APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define InsertTreeNode(Tree, Key, Data) \
	LP3(0x2A, APTR, InsertTreeNode, APTR, Tree, a0, CONST_APTR, Key, a1, CONST_APTR, Data, a2, \
	, BTREE_BASE_NAME)

#define DeleteTreeNode(Tree, Node) \
	LP2NR(0x30, DeleteTreeNode, APTR, Tree, a0, APTR, Node, a1, \
	, BTREE_BASE_NAME)

#define GetTreeNodeKey(Tree, Node) \
	LP2(0x36, APTR, GetTreeNodeKey, CONST_APTR, Tree, a0, CONST_APTR, Node, a1, \
	, BTREE_BASE_NAME)

#define GetTreeNodeData(Tree, Node) \
	LP2(0x3C, APTR, GetTreeNodeData, CONST_APTR, Tree, a0, CONST_APTR, Node, a1, \
	, BTREE_BASE_NAME)

#define SuccTreeNode(Tree, Node) \
	LP2(0x42, APTR, SuccTreeNode, CONST_APTR, Tree, a0, CONST_APTR, Node, a1, \
	, BTREE_BASE_NAME)

#define PredTreeNode(Tree, Node) \
	LP2(0x48, APTR, PredTreeNode, CONST_APTR, Tree, a0, CONST_APTR, Node, a1, \
	, BTREE_BASE_NAME)

#define MinTreeNode(Tree) \
	LP1(0x4E, APTR, MinTreeNode, CONST_APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define MaxTreeNode(Tree) \
	LP1(0x54, APTR, MaxTreeNode, CONST_APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define FindTreeNodeByKey(Tree, Key) \
	LP2(0x5A, APTR, FindTreeNodeByKey, CONST_APTR, Tree, a0, CONST_APTR, Key, a1, \
	, BTREE_BASE_NAME)

#define FindTreeNodeByData(Tree, Data) \
	LP2(0x60, APTR, FindTreeNodeByData, CONST_APTR, Tree, a0, CONST_APTR, Data, a1, \
	, BTREE_BASE_NAME)

#define ForTreeNodes(Tree, nodeFunc, userData) \
	LP3FP(0x66, ULONG, ForTreeNodes, CONST_APTR, Tree, a0, __fpt, nodeFunc, a1, CONST_APTR, userData, a2, \
	, BTREE_BASE_NAME, void (*__fpt)(APTR userData, CONST_APTR Node))

#define EnumTreeNodes(Tree, lowKey, highKey, nodeFunc, userData) \
	LP5FP(0x6C, ULONG, EnumTreeNodes, CONST_APTR, Tree, a0, CONST_APTR, lowKey, a1, CONST_APTR, highKey, a2, __fpt, nodeFunc, a3, CONST_APTR, userData, a4, \
	, BTREE_BASE_NAME, LONG (*__fpt)(APTR userData, CONST_APTR Node))

#define GetTreeSize(Tree) \
	LP1(0x72, ULONG, GetTreeSize, CONST_APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define GetTreeHeight(Tree) \
	LP1(0x78, ULONG, GetTreeHeight, CONST_APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define FlushTree(Tree) \
	LP1NR(0x7E, FlushTree, APTR, Tree, a0, \
	, BTREE_BASE_NAME)

#define SetTreeNodeData(Tree, Node, NewData) \
	LP3(0x84, APTR, SetTreeNodeData, CONST_APTR, Tree, a0, APTR, Node, a1, CONST_APTR, NewData, a2, \
	, BTREE_BASE_NAME)

#endif /*  _INLINE_BTREE_H  */
