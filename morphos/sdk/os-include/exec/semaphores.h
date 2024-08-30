#ifndef EXEC_SEMAPHORES_H
#define EXEC_SEMAPHORES_H

/*
	exec semaphore definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


/*
 * Shouldn't be available public..
 */
struct SemaphoreRequest
{
	struct MinNode  sr_Link;
	struct Task    *sr_Waiter;
};

struct SignalSemaphore
{
	struct Node              ss_Link;
	WORD                     ss_NestCount;
	struct MinList           ss_WaitQueue;
	struct SemaphoreRequest  ss_MultipleLink;
	struct Task             *ss_Owner;
	WORD                     ss_QueueCount;
};

struct SemaphoreMessage
{
	struct Message          ssm_Message;
	struct SignalSemaphore *ssm_Semaphore;
};

#define SM_SHARED     (1)
#define SM_EXCLUSIVE  (0)

#ifdef EXEC_OBSOLETE
struct Semaphore
{
	struct MsgPort sm_MsgPort;
	WORD           sm_Bids;
};
#define sm_LockMsg  mp_SigTask
#endif


#pragma pack()

#endif
