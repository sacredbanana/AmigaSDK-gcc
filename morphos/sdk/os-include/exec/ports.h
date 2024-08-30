#ifndef EXEC_PORTS_H
#define EXEC_PORTS_H

/*
	exec port definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#pragma pack(2)


struct MsgPort
{
	struct Node  mp_Node;
	UBYTE        mp_Flags;
	UBYTE        mp_SigBit;
	void        *mp_SigTask;
	struct List  mp_MsgList;
};

#define mp_SoftInt  mp_SigTask

#define PF_ACTION   3
#define PA_SIGNAL   0
#define PA_SOFTINT  1
#define PA_IGNORE   2


struct Message
{
	struct Node     mn_Node;
	struct MsgPort *mn_ReplyPort;
	UWORD           mn_Length;
};


#pragma pack()

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#endif
