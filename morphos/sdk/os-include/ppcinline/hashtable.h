/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_HASHTABLE_H
#define _PPCINLINE_HASHTABLE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef HASHTABLE_BASE_NAME
#define HASHTABLE_BASE_NAME HashTableBase
#endif /* !HASHTABLE_BASE_NAME */

#define CreateHashTableTagList(__p0) \
	(((APTR (*)(CONST struct TagItem *))*(void**)((long)(HASHTABLE_BASE_NAME) - 28))(__p0))

#define RemoveHashByData(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_APTR , CONST_APTR , size_t *, void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 64))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define GetHashTableAttribute(__p0, __p1) \
	(((size_t (*)(CONST_APTR , size_t , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 46))(__p0, __p1, (void*)(HASHTABLE_BASE_NAME)))

#define InsertHash(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_APTR , size_t , CONST_APTR , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 76))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define DeleteHashTable(__p0) \
	(((VOID (*)(CONST_APTR , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 34))(__p0, (void*)(HASHTABLE_BASE_NAME)))

#define ResizeHashTable(__p0) \
	(((size_t (*)(CONST_APTR , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 88))(__p0, (void*)(HASHTABLE_BASE_NAME)))

#define GetHashKeyByData(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_APTR , CONST_APTR , size_t *, void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 52))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define IterateHashTable(__p0, __p1, __p2) \
	(((size_t (*)(CONST_APTR , BOOL (*)(CONST_APTR, size_t, APTR, APTR), APTR , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 82))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define GetHashDataByKey(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_APTR , size_t , APTR *, void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 58))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define RemoveHashByKey(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_APTR , size_t , APTR *, void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 70))(__p0, __p1, __p2, (void*)(HASHTABLE_BASE_NAME)))

#define ClearHashTable(__p0) \
	(((VOID (*)(CONST_APTR , void *))*(void**)((long)(HASHTABLE_BASE_NAME) - 40))(__p0, (void*)(HASHTABLE_BASE_NAME)))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define CreateHashTableTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateHashTableTagList((CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_HASHTABLE_H */
