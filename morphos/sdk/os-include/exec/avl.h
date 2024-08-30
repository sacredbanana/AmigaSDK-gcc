#ifndef EXEC_AVL_H
#define EXEC_AVL_H

/*
	AVL-tree definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)

#ifndef EXEC_SILENT_BUILD
#warning exec AVL-trees are not directly supported in MorphOS, please use btree.library or libsavl instead
#endif

struct AVLNode
{
	ULONG reserved[4];
};

typedef APTR AVLKey;
typedef APTR AVLNODECOMP;
typedef APTR AVLKEYCOMP;


#pragma pack()

#endif /* EXEC_AVL_H */
