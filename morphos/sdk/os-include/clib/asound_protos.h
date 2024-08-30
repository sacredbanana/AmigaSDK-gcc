#ifndef AMBIENT_SOUND_PROTOS_H
#define AMBIENT_SOUND_PROTOS_H
/*
 * ambient_sound.library C prototypes
 * ----------------------------------
 * © 2001-2004 by David Gerber <zapek@morphos.net>
 * All Rights Reserved
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR ASound_Create(ULONG mode, struct TagItem *tags);
#if !defined(USE_INLINE_STDARG)
APTR ASound_CreateTags(ULONG mode, ULONG tag1, ...);
#endif
void ASound_Delete(APTR ctx);

ULONG ASound_PlaySync(APTR ctx, APTR buf, ULONG len);
ULONG ASound_PlayAsync(APTR ctx, APTR buf, ULONG len);

ULONG ASound_Wait(APTR ctx);
void ASound_Abort(APTR ctx);

APTR ASound_GetAttr(APTR ctx, ULONG attr);

#ifdef __cplusplus
}
#endif

#endif /* AMBIENT_SOUND_PROTOS_H */
