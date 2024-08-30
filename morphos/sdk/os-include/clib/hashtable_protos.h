#ifndef CLIB_HASHTABLE_PROTOS_H
#define CLIB_HASHTABLE_PROTOS_H

/*
 * hashtable.library C prototypes
 *
 * Copyright © 2014-2015 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef _SYS_TYPES_H_
# include <sys/types.h>
#endif

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct TagItem;

APTR CreateHashTableTagList(CONST struct TagItem *taglist);
VOID DeleteHashTable(CONST_APTR hashtable);
VOID ClearHashTable(CONST_APTR hashtable);
size_t GetHashTableAttribute(CONST_APTR hashtable, size_t attr);

BOOL InsertHash(CONST_APTR hashtable, size_t key, CONST_APTR data);

BOOL RemoveHashByKey(CONST_APTR hashtable, size_t key, APTR *dataptr);
BOOL RemoveHashByData(CONST_APTR hashtable, CONST_APTR data, size_t *keyptr);

BOOL GetHashDataByKey(CONST_APTR hashtable, size_t key, APTR *dataptr);
BOOL GetHashKeyByData(CONST_APTR hashtable, CONST_APTR data, size_t *keyptr);

size_t IterateHashTable(CONST_APTR hashtable, BOOL (*iterator)(CONST_APTR, size_t, APTR, APTR), APTR userdata);
size_t ResizeHashTable(CONST_APTR hashtable);

#if !defined(USE_INLINE_STDARG)
CONST_APTR CreateHashTableTags(ULONG Tag1, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_HASHTABLE_PROTOS_H */
