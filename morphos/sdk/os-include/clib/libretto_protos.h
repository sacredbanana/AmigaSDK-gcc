#ifndef CLIB_LIBRETTO_PROTOS_H
#define CLIB_LIBRETTO_PROTOS_H

/*
   libretto.library C prototypes
   Copyright © 2015 Grzegorz Kraszewski
   Generated with LibMaker 0.12.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef LIBRARIES_LIBRETTO_H
#include <libraries/libretto.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

Object* NewGlyphRunA(APTR, LONG, struct TagItem*);
Object* NewDrawTargetA(APTR, LONG, struct TagItem*);
VOID DrawGlyphRun(Object*, Object*, LONG, LONG);

#ifndef USE_INLINE_STDARG

Object* NewGlyphRun(APTR, LONG, Tag tag1, ...);
Object* NewDrawTarget(APTR, LONG, Tag tag1, ...);

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LIBRETTO_PROTOS_H */
