/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MOUNT_H
#define _PPCINLINE_MOUNT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MOUNT_BASE_NAME
#define MOUNT_BASE_NAME MountBase
#endif /* !MOUNT_BASE_NAME */

#define MountDeleteNotifyUnit(__p0) \
	(((void (*)(void *, void *))*(void**)((long)(MOUNT_BASE_NAME) - 34))((void*)(MOUNT_BASE_NAME), __p0))

#define MountNotifyTask(__p0, __p1, __p2) \
	(((void (*)(void *, void *, struct Task *, ULONG ))*(void**)((long)(MOUNT_BASE_NAME) - 88))((void*)(MOUNT_BASE_NAME), __p0, __p1, __p2))

#define MountMountDiskHandlersTagList(__p0) \
	(((ULONG (*)(void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 100))((void*)(MOUNT_BASE_NAME), __p0))

#define MountMountTagList(__p0, __p1) \
	(((ULONG (*)(void *, void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 64))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountDeleteNotifyNode(__p0) \
	(((void (*)(void *, void *))*(void**)((long)(MOUNT_BASE_NAME) - 52))((void*)(MOUNT_BASE_NAME), __p0))

#define MountNotifySet(__p0, __p1) \
	(((void (*)(void *, void *, ULONG ))*(void**)((long)(MOUNT_BASE_NAME) - 82))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountUpdateNotifyUnitConfigTagList(__p0, __p1) \
	(((ULONG (*)(void *, void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 94))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountCreateNotifyUnitTagList(__p0) \
	(((void *(*)(void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 28))((void*)(MOUNT_BASE_NAME), __p0))

#define MountNotifyAll(__p0, __p1) \
	(((void (*)(void *, void *, ULONG ))*(void**)((long)(MOUNT_BASE_NAME) - 76))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountFindNotifyNodeTagList(__p0, __p1) \
	(((void *(*)(void *, void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 58))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountDisMountTagList(__p0, __p1) \
	(((ULONG (*)(void *, void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 70))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#define MountGetNotifyUnitAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, void *, APTR , ULONG ))*(void**)((long)(MOUNT_BASE_NAME) - 40))((void*)(MOUNT_BASE_NAME), __p0, __p1, __p2))

#define MountCreateNotifyNodeTagList(__p0, __p1) \
	(((void *(*)(void *, void *, struct TagItem *))*(void**)((long)(MOUNT_BASE_NAME) - 46))((void*)(MOUNT_BASE_NAME), __p0, __p1))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define MountMountDiskHandlersTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountMountDiskHandlersTagList((struct TagItem *)_tags);})

#define MountDisMountTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountDisMountTagList(__p0, (struct TagItem *)_tags);})

#define MountMountTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountMountTagList(__p0, (struct TagItem *)_tags);})

#define MountCreateNotifyNodeTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountCreateNotifyNodeTagList(__p0, (struct TagItem *)_tags);})

#define MountUpdateNotifyUnitConfigTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountUpdateNotifyUnitConfigTagList(__p0, (struct TagItem *)_tags);})

#define MountFindNotifyNodeTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountFindNotifyNodeTagList(__p0, (struct TagItem *)_tags);})

#define MountCreateNotifyUnitTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MountCreateNotifyUnitTagList((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_MOUNT_H */
