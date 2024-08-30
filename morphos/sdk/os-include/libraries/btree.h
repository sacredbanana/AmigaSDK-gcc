#ifndef LIBRARIES_BTREE_H
#define LIBRARIES_BTREE_H

/*
	btree.library include (V50)

	Copyright © 2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define BTREENAME "btree.library"

struct BTArgArray
{
	APTR (*Alloc)(APTR userdata, ULONG size);
	void (*Free)(APTR userdata, APTR mem, ULONG size);
	LONG (*Compare)(APTR userdata, const APTR keya, const APTR keyb);
	void (*DestroyKey)(APTR userdata, APTR key);
	void (*DestroyData)(APTR userdata, APTR data);
	APTR UserData;
};


/* Tree Types for CreateTree
*/
enum
{
	BT_DEFAULT,             /* The best overall routine for generic use */
	BT_AVL_TREE,            /* AVL balanced binary tree */
	BT_RED_BLACK_TREE       /* Red-Black balanced binary tree */
};


#pragma pack()

#endif /* LIBRARIES_BTREE_H */
