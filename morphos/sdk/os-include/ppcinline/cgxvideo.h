/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CGXVIDEO_H
#define _PPCINLINE_CGXVIDEO_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CGXVIDEO_BASE_NAME
#define CGXVIDEO_BASE_NAME CGXVideoBase
#endif /* !CGXVIDEO_BASE_NAME */

#define AttachVLayerTagList(__p0, __p1, __p2) \
	LP3(42, ULONG , AttachVLayerTagList, \
		struct VLayerHandle *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SwapVLayerBuffer(__p0) \
	LP1NR(96, SwapVLayerBuffer, \
		struct VLayerHandle *, __p0, a0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define QueryVLayerAttr(__p0, __p1) \
	LP2(108, ULONG , QueryVLayerAttr, \
		struct Screen *, __p0, a0, \
		ULONG , __p1, d0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteSPLine(__p0, __p1, __p2, __p3, __p4) \
	LP5(102, ULONG , WriteSPLine, \
		struct VLayerHandle *, __p0, a0, \
		unsigned char *, __p1, a1, \
		int , __p2, d0, \
		int , __p3, d1, \
		int , __p4, d2, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DetachVLayer(__p0) \
	LP1(48, ULONG , DetachVLayer, \
		struct VLayerHandle *, __p0, a0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockVLayer(__p0) \
	LP1(66, ULONG , UnlockVLayer, \
		struct VLayerHandle *, __p0, a0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteVLayerHandle(__p0) \
	LP1(36, ULONG , DeleteVLayerHandle, \
		struct VLayerHandle *, __p0, a0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetVLayerAttr(__p0, __p1) \
	LP2(54, ULONG , GetVLayerAttr, \
		struct VLayerHandle *, __p0, a0, \
		ULONG , __p1, d0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockVLayer(__p0) \
	LP1(60, ULONG , LockVLayer, \
		struct VLayerHandle *, __p0, a0, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetVLayerAttrTagList(__p0, __p1) \
	LP2NR(72, SetVLayerAttrTagList, \
		struct VLayerHandle *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateVLayerHandleTagList(__p0, __p1) \
	LP2(30, struct VLayerHandle *, CreateVLayerHandleTagList, \
		struct Screen *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CGXVIDEO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetVLayerAttrTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetVLayerAttrTagList(__p0, (struct TagItem *)_tags);})

#define CreateVLayerHandleTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateVLayerHandleTagList(__p0, (struct TagItem *)_tags);})

#define AttachVLayerTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AttachVLayerTagList(__p0, __p1, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CGXVIDEO_H */
