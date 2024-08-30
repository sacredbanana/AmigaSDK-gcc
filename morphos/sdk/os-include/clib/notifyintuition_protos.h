#ifndef CLIB_NOTIFYINTUITION_PROTOS_H
#define CLIB_NOTIFYINTUITION_PROTOS_H

/*
	notifyintuition.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef LIBRARIES_NOTIFYINTUITION_H
# include <libraries/notifyintuition.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct IntNotifyRequest *NotIStartNotify(struct IntNotifyRequest *);
struct IntNotifyRequest *NotIEndNotify(struct IntNotifyRequest *);
struct Task *NotIFindUniqueTask(ULONG);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_NOTIFYINTUITION_PROTOS_H */
