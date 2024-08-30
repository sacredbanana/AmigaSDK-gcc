#ifndef GRAPHICS_GFXNODES_H
#define GRAPHICS_GFXNODES_H

/*
	graphics extended node definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct ExtendedNode
{
	struct Node  *xln_Succ;
	struct Node  *xln_Pred;
	UBYTE         xln_Type;
	BYTE          xln_Pri;
	STRPTR        xln_Name;
	UBYTE         xln_Subsystem;
	UBYTE         xln_Subtype;
	LONG          xln_Library;
	LONG        (*xln_Init)(VOID);
};


#define SS_GRAPHICS  0x02

#define VIEW_EXTRA_TYPE       1
#define VIEWPORT_EXTRA_TYPE   2
#define SPECIAL_MONITOR_TYPE  3
#define MONITOR_SPEC_TYPE     4


#pragma pack()

#endif /* GRAPHICS_GFXNODES_H */
