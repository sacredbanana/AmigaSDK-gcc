#ifndef CLIB_BTREE_PROTOS_H
#define CLIB_BTREE_PROTOS_H

/*
	btree C prototypes
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
APTR InsertTreeNode(APTR Tree, CONST_APTR Key, CONST_APTR Data);
void DeleteTreeNode(APTR Tree, APTR Node);
APTR GetTreeNodeKey(CONST_APTR Tree, CONST_APTR Node);
APTR GetTreeNodeData(CONST_APTR Tree, CONST_APTR Node);
APTR SuccTreeNode(CONST_APTR Tree, CONST_APTR Node);
APTR PredTreeNode(CONST_APTR Tree, CONST_APTR Node);
APTR MinTreeNode(CONST_APTR Tree);
APTR MaxTreeNode(CONST_APTR Tree);
APTR FindTreeNodeByKey(CONST_APTR Tree, CONST_APTR Key);
APTR FindTreeNodeByData(CONST_APTR Tree, CONST_APTR Data);
ULONG ForTreeNodes(CONST_APTR Tree,
                   void (*nodeFunc)(APTR userData, CONST_APTR Node), CONST_APTR userData);
ULONG EnumTreeNodes(CONST_APTR Tree, CONST_APTR lowKey, CONST_APTR highKey,
                    LONG (*nodeFunc)(APTR userData, CONST_APTR Node), CONST_APTR userData);
ULONG GetTreeSize(CONST_APTR Tree);
ULONG GetTreeHeight(CONST_APTR Tree);
void FlushTree(APTR Tree);
APTR SetTreeNodeData(CONST_APTR Tree, APTR Node, CONST_APTR NewData);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BTREE_PROTOS_H */
