/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_KEYFRAME_H
#define _PPCINLINE_KEYFRAME_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef KEYFRAME_BASE_NAME
#define KEYFRAME_BASE_NAME KeyFrameBase
#endif /* !KEYFRAME_BASE_NAME */

#define CreateKeyFrame(__p0, __p1, __p2) \
	(((APTR (*)(void *, APTR , ULONG , LONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 28))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2))

#define DeleteKeyFrame(__p0, __p1) \
	(((BOOL (*)(void *, APTR , APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 34))((void*)(KEYFRAME_BASE_NAME), __p0, __p1))

#define DeleteKeyFrameHandle(__p0) \
	(((BOOL (*)(void *, APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 58))((void*)(KEYFRAME_BASE_NAME), __p0))

#define CreateKeyFrameHandle(__p0, __p1, __p2, __p3, __p4) \
	(((APTR (*)(void *, ULONG , ULONG , LONG , LONG , LONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 52))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SetKeyFrameHandleAttribute(__p0, __p1, __p2) \
	(((BOOL (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 64))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2))

#define SetKeyFrameAttribute(__p0, __p1, __p2) \
	(((BOOL (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 40))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2))

#define GetKeyFrameAttribute(__p0, __p1, __p2) \
	(((BOOL (*)(void *, APTR , ULONG , ULONG *))*(void**)((long)(KEYFRAME_BASE_NAME) - 46))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2))

#define GetKeyFrameHandleAttribute(__p0, __p1, __p2) \
	(((BOOL (*)(void *, APTR , ULONG , ULONG *))*(void**)((long)(KEYFRAME_BASE_NAME) - 70))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2))

#define GetNextKeyFrame(__p0, __p1) \
	(((APTR (*)(APTR , APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 106))(__p0, __p1))

#define GetPrevKeyFrame(__p0, __p1) \
	(((APTR (*)(APTR , APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 112))(__p0, __p1))

#define Interpolate(__p0, __p1) \
	(((LONG (*)(void *, APTR , ULONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 88))((void*)(KEYFRAME_BASE_NAME), __p0, __p1))

#define LockKeyFrameHandle(__p0) \
	(((VOID (*)(void *, APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 76))((void*)(KEYFRAME_BASE_NAME), __p0))

#define UnLockKeyFrameHandle(__p0) \
	(((VOID (*)(void *, APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 82))((void*)(KEYFRAME_BASE_NAME), __p0))

#define StartKeyFrameNotification(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, APTR , struct Task *, UBYTE , ULONG ))*(void**)((long)(KEYFRAME_BASE_NAME) - 94))((void*)(KEYFRAME_BASE_NAME), __p0, __p1, __p2, __p3))

#define EndKeyFrameNotification(__p0) \
	(((VOID (*)(void *, APTR ))*(void**)((long)(KEYFRAME_BASE_NAME) - 100))((void*)(KEYFRAME_BASE_NAME), __p0))

#endif /* !_PPCINLINE_KEYFRAME_H */
