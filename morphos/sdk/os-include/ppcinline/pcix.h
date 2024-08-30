/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PCIX_H
#define _PPCINLINE_PCIX_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PCIX_BASE_NAME
#define PCIX_BASE_NAME PCIXBase
#endif /* !PCIX_BASE_NAME */

#define PCIXAllocDMA(__p0) \
	(((ULONG (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 154))((void*)(PCIX_BASE_NAME), __p0))

#define PCIXAttemptBoard(__p0) \
	(((ULONG (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 142))((void*)(PCIX_BASE_NAME), __p0))

#define PCIXCreateIntObjectTagList(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, APTR , ULONG (*)(void), APTR , struct TagItem *))*(void**)((long)(PCIX_BASE_NAME) - 52))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2, __p3))

#define PCIXDMAGetPhysical(__p0, __p1) \
	(((APTR (*)(void *, APTR , APTR ))*(void**)((long)(PCIX_BASE_NAME) - 202))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXDeleteIntObject(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 58))((void*)(PCIX_BASE_NAME), __p0))


#define PCIXFindBoardTagList(__p0, __p1) \
	(((APTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(PCIX_BASE_NAME) - 82))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXFindBridgeTagList(__p0, __p1) \
	(((APTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(PCIX_BASE_NAME) - 64))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXFreeDMA(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 160))((void*)(PCIX_BASE_NAME), __p0))

#define PCIXGetBoardAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 88))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXGetBridgeAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 70))((void*)(PCIX_BASE_NAME), __p0, __p1))





#define PCIXModifyConfigByte(__p0, __p1, __p2, __p3) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 208))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2, __p3))

#define PCIXModifyConfigLong(__p0, __p1, __p2, __p3) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 220))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2, __p3))

#define PCIXModifyConfigWord(__p0, __p1, __p2, __p3) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 214))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2, __p3))

#define PCIXObtainBoard(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 136))((void*)(PCIX_BASE_NAME), __p0))

#define PCIXReadConfigByte(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 100))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXReadConfigLong(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 112))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXReadConfigWord(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 106))((void*)(PCIX_BASE_NAME), __p0, __p1))

#define PCIXReleaseBoard(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(PCIX_BASE_NAME) - 148))((void*)(PCIX_BASE_NAME), __p0))


#define PCIXSetBoardAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 94))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2))

#define PCIXSetBridgeAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 76))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2))

#define PCIXWriteConfigByte(__p0, __p1, __p2) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 118))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2))

#define PCIXWriteConfigLong(__p0, __p1, __p2) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 130))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2))

#define PCIXWriteConfigWord(__p0, __p1, __p2) \
	(((ULONG (*)(void *, APTR , ULONG , ULONG ))*(void**)((long)(PCIX_BASE_NAME) - 124))((void*)(PCIX_BASE_NAME), __p0, __p1, __p2))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define PCIXCreateIntObjectTags(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PCIXCreateIntObjectTagList(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define PCIXFindBoardTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PCIXFindBoardTagList(__p0, (struct TagItem *)_tags);})

#define PCIXFindBridgeTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PCIXFindBridgeTagList(__p0, (struct TagItem *)_tags);})






#endif

#endif /* !_PPCINLINE_PCIX_H */
