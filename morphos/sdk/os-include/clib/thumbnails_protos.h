#ifndef CLIB_THUMBNAILS_H
#define CLIB_THUMBNAILS_H

#include <exec/types.h>
#include <utility/tagitem.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR ThbGenerateThumbnailA(CONST_STRPTR path, struct TagItem *tags);
VOID ThbDeleteThumbnail(APTR thumbnail);
ULONG ThbGetAttrsA(APTR thumbnail, struct TagItem *tags);
ULONG ThbNextFrame(APTR thumbnail);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif

