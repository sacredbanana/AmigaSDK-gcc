/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MPEGA_H
#define _PPCINLINE_MPEGA_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MPEGA_BASE_NAME
#define MPEGA_BASE_NAME MPEGABase
#endif /* !MPEGA_BASE_NAME */

#define MPEGA_decode_frame(__p0, __p1) \
	LP2(42, LONG , MPEGA_decode_frame, \
		MPEGA_STREAM *, __p0, a0, \
		WORD **, __p1, a1, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_time(__p0, __p1) \
	LP2(54, LONG , MPEGA_time, \
		MPEGA_STREAM *, __p0, a0, \
		ULONG *, __p1, a1, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_close(__p0) \
	LP1NR(36, MPEGA_close, \
		MPEGA_STREAM *, __p0, a0, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_open(__p0, __p1) \
	LP2(30, MPEGA_STREAM *, MPEGA_open, \
		char *, __p0, a0, \
		MPEGA_CTRL *, __p1, a1, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_find_sync(__p0, __p1) \
	LP2(60, LONG , MPEGA_find_sync, \
		BYTE *, __p0, a0, \
		LONG , __p1, d0, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_scale(__p0, __p1) \
	LP2(66, LONG , MPEGA_scale, \
		MPEGA_STREAM *, __p0, a0, \
		LONG , __p1, d0, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MPEGA_seek(__p0, __p1) \
	LP2(48, LONG , MPEGA_seek, \
		MPEGA_STREAM *, __p0, a0, \
		ULONG , __p1, d0, \
		, MPEGA_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_MPEGA_H */
