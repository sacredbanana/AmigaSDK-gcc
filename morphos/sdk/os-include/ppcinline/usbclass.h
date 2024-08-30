/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_USBCLASS_H
#define _PPCINLINE_USBCLASS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef USBCLASS_BASE_NAME
#define USBCLASS_BASE_NAME UsbClsBase
#endif /* !USBCLASS_BASE_NAME */

#define usbSetAttrsA(__p0, __p1, __p2) \
	LP3(72, LONG , usbSetAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		struct TagItem *, __p2, a1, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbAttemptDeviceBinding(__p0) \
	LP1(42, APTR , usbAttemptDeviceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbReleaseInterfaceBinding(__p0) \
	LP1NR(36, usbReleaseInterfaceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbForceInterfaceBinding(__p0) \
	LP1(54, APTR , usbForceInterfaceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbDoMethodA(__p0, __p1) \
	LP2(78, LONG , usbDoMethodA, \
		ULONG , __p0, d0, \
		APTR , __p1, a1, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbForceDeviceBinding(__p0) \
	LP1(60, APTR , usbForceDeviceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbAttemptInterfaceBinding(__p0) \
	LP1(30, APTR , usbAttemptInterfaceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbReleaseDeviceBinding(__p0) \
	LP1NR(48, usbReleaseDeviceBinding, \
		APTR , __p0, a0, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define usbGetAttrsA(__p0, __p1, __p2) \
	LP3(66, LONG , usbGetAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		struct TagItem *, __p2, a1, \
		, USBCLASS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define usbSetAttrs(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	usbSetAttrsA(__p0, __p1, (struct TagItem *)_tags);})

#define usbGetAttrs(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	usbGetAttrsA(__p0, __p1, (struct TagItem *)_tags);})

#define usbDoMethod(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	usbDoMethodA(__p0, (APTR )_tags);})

#endif

#endif /* !_PPCINLINE_USBCLASS_H */
