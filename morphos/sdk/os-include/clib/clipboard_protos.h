#ifndef CLIB_CLIPBOARD_PROTOS_H
#define CLIB_CLIPBOARD_PROTOS_H

/*
   clipboard.library C prototypes
   Copyright © 2014-2016 Grzegorz Kraszewski, Michal Zukowski
   Generated with LibMaker 0.9.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_CLIPBOARD_H
#include <libraries/clipboard.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR ReadClipTextA(struct TagItem *taglist);
LONG WriteClipTextA(CONST_APTR text, struct TagItem *taglist);
VOID FreeClipText(CONST_APTR text);
LONG GetClipType(ULONG unit);
APTR ReadClipImageA(struct TagItem *taglist);
LONG WriteClipImageA(struct TagItem *taglist);

#if !defined(USE_INLINE_STDARG)
APTR ReadClipText(ULONG tag1, ...);
APTR ReadClipImage(ULONG tag1, ...);
LONG WriteClipText(CONST_APTR text, ULONG tag1, ...);
LONG WriteClipImage(ULONG tag1, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_CLIPBOARD_PROTOS_H */
