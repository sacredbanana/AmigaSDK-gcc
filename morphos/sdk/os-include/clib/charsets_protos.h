#ifndef CLIB_CHARSETS_PROTOS_H
#define CLIB_CHARSETS_PROTOS_H

/*
 * charsets.library C prototypes
 *
 * Copyright © 2009-2014 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_CHARSETS_H
# include <libraries/charsets.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CONST_STRPTR GetCharsetName(ULONG mibenum, CONST_STRPTR *mimename, CONST CONST_STRPTR **aliases);
ULONG GetCharsetNumber(CONST_STRPTR name, ULONG match);

#if !defined(USE_INLINE_STDARG)
LONG ConvertTags(CONST_APTR src, LONG srcbytes, APTR dst, LONG dstbytes, ULONG srcmib, ULONG dstmib, ULONG tag1, ...);
#endif
LONG ConvertTagList(CONST_APTR src, LONG srcbytes, APTR dst, LONG dstbytes, ULONG srcmib, ULONG dstmib, CONST struct TagItem *taglist);

WCHAR UTF16_ToCodePoint(UTF16 ch1, UTF16 ch2);
LONG GetSystemCharset(STRPTR buffer, ULONG buflen);
WCHAR GetUTF16BE(UTF16 *Buffer, ULONG CodeUnits);
WCHAR GetUTF16LE(UTF16 *Buffer, ULONG CodeUnits);
LONG GetLength(APTR str, LONG bytes, ULONG mib);
LONG GetByteSize(APTR str, LONG bytes, ULONG srcmib, ULONG dstmib);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_CHARSETS_PROTOS_H */
