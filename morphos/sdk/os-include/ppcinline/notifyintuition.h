/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_NOTIFYINTUITION_H
#define _PPCINLINE_NOTIFYINTUITION_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef NOTIFYINTUITION_BASE_NAME
#define NOTIFYINTUITION_BASE_NAME NotIBase
#endif /* !NOTIFYINTUITION_BASE_NAME */

#define NotIStartNotify(__p0) \
	LP1(30, struct IntNotifyRequest *, NotIStartNotify, \
		struct IntNotifyRequest *, __p0, a0, \
		, NOTIFYINTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NotIFindUniqueTask(__p0) \
	LP1(42, struct Task *, NotIFindUniqueTask, \
		ULONG , __p0, d0, \
		, NOTIFYINTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NotIEndNotify(__p0) \
	LP1(36, struct IntNotifyRequest *, NotIEndNotify, \
		struct IntNotifyRequest *, __p0, a0, \
		, NOTIFYINTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_NOTIFYINTUITION_H */
