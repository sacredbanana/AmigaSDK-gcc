/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SCREENNOTIFY_H
#define _PPCINLINE_SCREENNOTIFY_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SCREENNOTIFY_BASE_NAME
#define SCREENNOTIFY_BASE_NAME ScreenNotifyBase
#endif /* !SCREENNOTIFY_BASE_NAME */

#define RemPubScreenClient(__p0) \
	LP1(48, BOOL , RemPubScreenClient, \
		APTR , __p0, a0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemWorkbenchClient(__p0) \
	LP1(60, BOOL , RemWorkbenchClient, \
		APTR , __p0, a0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddCloseScreenClient(__p0, __p1, __p2) \
	LP3(30, APTR , AddCloseScreenClient, \
		struct Screen *, __p0, a0, \
		struct MsgPort *, __p1, a1, \
		BYTE , __p2, d0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define AddPubScreenClient(__p0, __p1) \
	LP2(42, APTR , AddPubScreenClient, \
		struct MsgPort *, __p0, a0, \
		BYTE , __p1, d0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddWorkbenchClient(__p0, __p1) \
	LP2(54, APTR , AddWorkbenchClient, \
		struct MsgPort *, __p0, a0, \
		BYTE , __p1, d0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemCloseScreenClient(__p0) \
	LP1(36, BOOL , RemCloseScreenClient, \
		APTR , __p0, a0, \
		, SCREENNOTIFY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_SCREENNOTIFY_H */
