#ifndef LIBRARIES_THREADPOOL_H
#define LIBRARIES_THREADPOOL_H

/*
 * Copyright © 2012-2014 The MorphOS Development Team
 *
 */

#ifndef DOS_DOSTAGS_H
#include <dos/dostags.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

typedef VOID (*THREADFUNC)(APTR UserData, struct MsgPort *port);

#define THREADPOOL_MaxIdleThreads (TAG_USER + 0)
#define THREADPOOL_DataSegment    (TAG_USER + 1)    /* Small data pointer */
#define THREADPOOL_Priority        NP_Priority      /* Default is 0 */
#define THREADPOOL_Name            NP_Name

#define WORKITEM_INVALID -1
#define WORKITEM_ANY     -2

typedef enum
{
	WORKITEMSTATUS_NOT_FOUND = -1,
	WORKITEMSTATUS_EXECUTING = 0,
	WORKITEMSTATUS_PENDING   = 1,

} WORKITEMSTATUS;

#endif /* LIBRARIES_THREADPOOL_H */

