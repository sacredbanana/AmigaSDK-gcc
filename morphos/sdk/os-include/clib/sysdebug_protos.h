#ifndef CLIB_SYSDEBUG_PROTOS_H
#define CLIB_SYSDEBUG_PROTOS_H

/*
	sysdebug C prototypes

	Copyright © 2019 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

STRPTR SysDebugFindSeg(ULONG Address, ULONG *SegNum, ULONG *Offset);
/* V52 */
LONG SysDebugFindSegTagList(struct TagItem *taglist);
#if !defined(USE_INLINE_STDARG)
LONG SysDebugFindSegTags(ULONG tag1, ...);
#endif
void SysDebugFreeArray(APTR array);
void SysDebugLock(void);
void SysDebugUnLock(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_SYSDEBUG_PROTOS_H */
