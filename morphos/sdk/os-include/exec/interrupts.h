#ifndef EXEC_INTERRUPTS_H
#define EXEC_INTERRUPTS_H

/*
	exec interrupt definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#pragma pack(2)


struct Interrupt
{
	struct  Node   is_Node;
	APTR           is_Data;
	VOID         (*is_Code)(VOID);
};

struct IntVector
{
	APTR          iv_Data;
	VOID        (*iv_Code)(VOID);
	struct Node  *iv_Node;
};


struct SoftIntList
{
	struct List sh_List;
	UWORD       sh_Pad;
};

#define SIH_PRIMASK  (0xf0)

#define INTB_NMI  15
#define INTF_NMI  (1<<INTB_NMI)


#pragma pack()

#endif
