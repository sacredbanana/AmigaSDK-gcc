#ifndef CLIB_EXTRAS_PROTOS_H
#define CLIB_EXTRAS_PROTOS_H

/*
   extras.library C prototypes
   Copyright © 2015 MorphOS Team
   Generated with LibMaker 0.12.
*/

#include <graphics/gfx.h>
#include <utility/tagitem.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct BitMap* LoadImageToBitMapA(CONST_STRPTR, struct TagItem*);
APTR LoadFileA(CONST_STRPTR, struct TagItem*);
APTR LoadImageToArrayA(CONST_STRPTR, struct TagItem*);

#ifndef USE_INLINE_STDARG

struct BitMap* LoadImageToBitMap(CONST_STRPTR, Tag tag1, ...);
APTR LoadFile(CONST_STRPTR, Tag tag1, ...);
APTR LoadImageToArray(CONST_STRPTR, Tag tag1, ...);

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_EXTRAS_PROTOS_H */
