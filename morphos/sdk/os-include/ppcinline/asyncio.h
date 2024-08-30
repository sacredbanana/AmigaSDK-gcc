/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_ASYNCIO_H
#define _PPCINLINE_ASYNCIO_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef ASYNCIO_BASE_NAME
#define ASYNCIO_BASE_NAME AsyncIOBase
#endif /* !ASYNCIO_BASE_NAME */

#define ReadLineAsync(__p0, __p1, __p2) \
	LP3(78, LONG , ReadLineAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteLineAsync(__p0, __p1) \
	LP2(84, LONG , WriteLineAsync, \
		AsyncFile *, __p0, a0, \
		STRPTR , __p1, a1, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadAsyncPkt(__p0, __p1, __p2) \
	LP3(198, LONG , ReadAsyncPkt, \
		AsyncFile *, __p0, a0, \
		struct Hook *, __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PeekAsync(__p0, __p1, __p2) \
	LP3(102, LONG , PeekAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenAsync(__p0, __p1, __p2) \
	LP3(30, AsyncFile *, OpenAsync, \
		const STRPTR , __p0, a0, \
		OpenModes , __p1, d0, \
		LONG , __p2, d1, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FGetsLenAsync(__p0, __p1, __p2, __p3) \
	LP4(96, APTR , FGetsLenAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		LONG *, __p3, a2, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteAsync(__p0, __p1, __p2) \
	LP3(60, LONG , WriteAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadCharAsync(__p0) \
	LP1(66, LONG , ReadCharAsync, \
		AsyncFile *, __p0, a0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FGetsAsync(__p0, __p1, __p2) \
	LP3(90, APTR , FGetsAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenAsyncFromFH(__p0, __p1, __p2) \
	LP3(36, AsyncFile *, OpenAsyncFromFH, \
		BPTR , __p0, a0, \
		OpenModes , __p1, d0, \
		LONG , __p2, d1, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteCharAsync(__p0, __p1) \
	LP2(72, LONG , WriteCharAsync, \
		AsyncFile *, __p0, a0, \
		UBYTE , __p1, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SeekAsync64(__p0, __p1, __p2) \
	(((QUAD (*)(void *, AsyncFile *, QUAD , SeekModes ))*(void**)((long)(ASYNCIO_BASE_NAME) - 202))((void*)(ASYNCIO_BASE_NAME), __p0, __p1, __p2))

#define ReadAsync(__p0, __p1, __p2) \
	LP3(54, LONG , ReadAsync, \
		AsyncFile *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseAsync(__p0) \
	LP1(42, LONG , CloseAsync, \
		AsyncFile *, __p0, a0, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SeekAsync(__p0, __p1, __p2) \
	LP3(48, LONG , SeekAsync, \
		AsyncFile *, __p0, a0, \
		LONG , __p1, d0, \
		SeekModes , __p2, d1, \
		, ASYNCIO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_ASYNCIO_H */
