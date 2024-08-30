#if !defined(CLIB_SCREENNOTIFY_PROTOS_H) && !defined(CLIB_SCREENNOTIFY_H)
#define CLIB_SCREENNOTIFY_PROTOS_H
#define CLIB_SCREENNOTIFY_H

/*
	screennotify.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef INTUITION_SCREENS_H
# include <intuition/screens.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR AddCloseScreenClient(struct Screen *, struct MsgPort *, BYTE);
APTR AddPubScreenClient(struct MsgPort *, BYTE);
APTR AddWorkbenchClient(struct MsgPort *, BYTE);
BOOL RemCloseScreenClient(APTR);
BOOL RemPubScreenClient(APTR);
BOOL RemWorkbenchClient(APTR);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_SCREENNOTIFY_PROTOS_H */
