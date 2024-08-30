#ifndef GRAPHICS_GRAPHINT_H
#define GRAPHICS_GRAPHINT_H

/*
	graphics interrupt definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct Isrvstr
{
	struct Node      is_Node;
	struct Isrvstr  *Iptr;
	LONG           (*code)(void);
	LONG           (*ccode) __CLIB_PROTOTYPE((APTR));
	APTR             Carg;
};


#pragma pack()

#endif /* GRAPHICS_GRAPHINT_H */
