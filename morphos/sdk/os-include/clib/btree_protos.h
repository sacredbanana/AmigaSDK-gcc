#ifndef CLIB_BTREE_PROTOS_H
#define CLIB_BTREE_PROTOS_H

/*
	btree C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_BTREE_H
# include <libraries/btree.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR CreateTree(ULONG Type, const struct BTArgArray *argArray);
void DeleteTree(APTR Tree);
APTR InsertTreeNode(APTR Tree, const APTR Key, const APTR Data);
void DeleteTreeNode(APTR Tree, APTR Node);
APTR GetTreeNodeKey(const APTR Tree, const APTR Node);
APTR GetTreeNodeData(const APTR Tree, const APTR Node);
APTR SuccTreeNode(const APTR Tree, const APTR Node);
APTR PredTreeNode(const APTR Tree, const APTR Node);
APTR MinTreeNode(const APTR Tree);
APTR MaxTreeNode(const APTR Tree);
APTR FindTreeNodeByKey(const APTR Tree, const APTR Key);
APTR FindTreeNodeByData(const APTR Tree, const APTR Data);
ULONG ForTreeNodes(const APTR Tree,
                   void (*nodeFunc)(APTR userData, const APTR Node), const APTR userData);
ULONG EnumTreeNodes(const APTR Tree, const APTR lowKey, const APTR highKey,
                    LONG (*nodeFunc)(APTR userData, const APTR Node), const APTR userData);
ULONG GetTreeSize(const APTR Tree);
ULONG GetTreeHeight(const APTR Tree);
void FlushTree(APTR Tree);
APTR SetTreeNodeData(const APTR Tree, APTR Node, const APTR NewData);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BTREE_PROTOS_H */
