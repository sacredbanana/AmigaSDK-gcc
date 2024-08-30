/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_NEWICON_H
#define _PPCINLINE_NEWICON_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef NEWICON_BASE_NAME
#define NEWICON_BASE_NAME NewIconBase
#endif /* !NEWICON_BASE_NAME */

#define FreeRemappedImage(__p0, __p1) \
	LP2NR(72, FreeRemappedImage, \
		struct Image *, __p0, a0, \
		struct Screen *, __p1, a1, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PutNewDiskObject(__p0, __p1) \
	LP2(36, BOOL , PutNewDiskObject, \
		UBYTE *, __p0, a0, \
		struct NewDiskObject *, __p1, a1, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetNewDiskObject(__p0) \
	LP1(30, struct NewDiskObject *, GetNewDiskObject, \
		UBYTE *, __p0, a0, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDefNewDiskObject(__p0) \
	LP1(78, struct NewDiskObject *, GetDefNewDiskObject, \
		LONG , __p0, d0, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemapChunkyImage(__p0, __p1) \
	LP2(66, struct Image *, RemapChunkyImage, \
		struct ChunkyImage *, __p0, a0, \
		struct Screen *, __p1, a1, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeNewDiskObject(__p0) \
	LP1NR(42, FreeNewDiskObject, \
		struct NewDiskObject *, __p0, a0, \
		, NEWICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_NEWICON_H */
