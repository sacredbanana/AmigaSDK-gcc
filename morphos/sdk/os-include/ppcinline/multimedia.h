/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MULTIMEDIA_H
#define _PPCINLINE_MULTIMEDIA_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MULTIMEDIA_BASE_NAME
#define MULTIMEDIA_BASE_NAME MultimediaBase
#endif /* !MULTIMEDIA_BASE_NAME */

#define MediaFindClassTagList(__p0, __p1) \
	(((STRPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 52))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1))

#define MediaGetGuiTagList(__p0) \
	(((Boopsiobject *(*)(void *, struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 94))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#define MediaConnectTagList(__p0, __p1, __p2, __p3, __p4) \
	(((BOOL (*)(void *, Boopsiobject *, ULONG , Boopsiobject *, ULONG , struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 40))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define MediaAllocVec(__p0) \
	(((APTR (*)(void *, ULONG ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 64))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#define MediaGetClassAttr(__p0, __p1, __p2) \
	(((BOOL (*)(void *, STRPTR , ULONG , ULONG *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 58))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1, __p2))

#define MediaFreeVec(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 70))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#define MediaBuildFromArgsTagList(__p0, __p1, __p2, __p3) \
	(((Boopsiobject *(*)(void *, STRPTR , Boopsiobject *, LONG , struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 112))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1, __p2, __p3))

#define MediaTimeToAudioFrame(__p0, __p1) \
	(((QUAD (*)(void *, QUAD , LONG ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 88))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1))

#define MediaNewObjectTagList(__p0) \
	(((Boopsiobject *(*)(void *, struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 46))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#define MediaGetArgsFromGui(__p0) \
	(((STRPTR (*)(void *, Boopsiobject *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 118))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#if !defined(__STRICT_ANSI__)
#define MediaLog(__p0, __p1, __p2, ...) \
	(((void (*)(void *, ULONG , STRPTR , STRPTR , STRPTR , ...))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 34))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1, __p2, __VA_ARGS__))
#endif

#define MediaAudioFrameToTime(__p0, __p1) \
	(((QUAD (*)(void *, QUAD , LONG ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 82))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1))

#define MediaSetLogLevel(__p0) \
	(((ULONG (*)(void *, ULONG ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 76))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#define MediaBuildFromGuiTagList(__p0, __p1, __p2, __p3) \
	(((Boopsiobject *(*)(void *, Boopsiobject *, Boopsiobject *, LONG , struct TagItem *))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 100))((void*)(MULTIMEDIA_BASE_NAME), __p0, __p1, __p2, __p3))

#define MediaFault(__p0) \
	(((CONST_STRPTR (*)(void *, LONG ))*(void**)((long)(MULTIMEDIA_BASE_NAME) - 106))((void*)(MULTIMEDIA_BASE_NAME), __p0))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define MediaGetGuiTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaGetGuiTagList((struct TagItem *)_tags);})

#define MediaBuildFromArgsTags(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaBuildFromArgsTagList(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define MediaFindClassTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaFindClassTagList(__p0, (struct TagItem *)_tags);})

#define MediaBuildFromGuiTags(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaBuildFromGuiTagList(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define MediaConnectTags(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaConnectTagList(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define MediaNewObjectTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MediaNewObjectTagList((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_MULTIMEDIA_H */
