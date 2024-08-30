/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BTREE_H
#define _PPCINLINE_BTREE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BTREE_BASE_NAME
#define BTREE_BASE_NAME BTreeBase
#endif /* !BTREE_BASE_NAME */

#define DeleteTreeNode(__p0, __p1) \
	(((void (*)(void *, APTR , APTR ))*(void**)((long)(BTREE_BASE_NAME) - 46))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define FindTreeNodeByData(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 94))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define PredTreeNode(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 70))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define GetTreeNodeKey(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 52))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define InsertTreeNode(__p0, __p1, __p2) \
	(((APTR (*)(void *, APTR , const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 40))((void*)(BTREE_BASE_NAME), __p0, __p1, __p2))

#define EnumTreeNodes(__p0, __p1, __p2, __p3, __p4) \
	(((ULONG (*)(void *, const APTR , const APTR , const APTR , LONG (*)(APTR userData, const APTR Node), const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 106))((void*)(BTREE_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define GetTreeSize(__p0) \
	(((ULONG (*)(void *, const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 112))((void*)(BTREE_BASE_NAME), __p0))

#define MinTreeNode(__p0) \
	(((APTR (*)(void *, const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 76))((void*)(BTREE_BASE_NAME), __p0))

#define SetTreeNodeData(__p0, __p1, __p2) \
	(((APTR (*)(void *, const APTR , APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 130))((void*)(BTREE_BASE_NAME), __p0, __p1, __p2))

#define SuccTreeNode(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 64))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define FlushTree(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(BTREE_BASE_NAME) - 124))((void*)(BTREE_BASE_NAME), __p0))

#define CreateTree(__p0, __p1) \
	(((APTR (*)(void *, ULONG , const struct BTArgArray *))*(void**)((long)(BTREE_BASE_NAME) - 28))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define GetTreeHeight(__p0) \
	(((ULONG (*)(void *, const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 118))((void*)(BTREE_BASE_NAME), __p0))

#define ForTreeNodes(__p0, __p1, __p2) \
	(((ULONG (*)(void *, const APTR , void (*)(APTR userData, const APTR Node), const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 100))((void*)(BTREE_BASE_NAME), __p0, __p1, __p2))

#define MaxTreeNode(__p0) \
	(((APTR (*)(void *, const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 82))((void*)(BTREE_BASE_NAME), __p0))

#define FindTreeNodeByKey(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 88))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define GetTreeNodeData(__p0, __p1) \
	(((APTR (*)(void *, const APTR , const APTR ))*(void**)((long)(BTREE_BASE_NAME) - 58))((void*)(BTREE_BASE_NAME), __p0, __p1))

#define DeleteTree(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(BTREE_BASE_NAME) - 34))((void*)(BTREE_BASE_NAME), __p0))

#endif /* !_PPCINLINE_BTREE_H */
