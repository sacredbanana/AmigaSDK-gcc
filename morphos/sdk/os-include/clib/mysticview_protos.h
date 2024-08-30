#ifndef CLIB_MYSTICVIEW_H
#define CLIB_MYSTICVIEW_H
/*
**	$VER: mysticview_protos.h v4.2 (31.5.99)
**
**	C prototype definitions
**
**	© TEK neoscientists
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR MV_Create(struct Screen *screen, struct RastPort *rastport, ...);
APTR MV_CreateA(struct Screen *screen, struct RastPort *rastport, struct TagItem *tags);

void MV_Delete(APTR mview);

void MV_SetAttrs(APTR mview, ...);
void MV_SetAttrsA(APTR mview, struct TagItem *tags);

void MV_SetPicture(APTR mview, APTR picture);

BOOL MV_DrawOn(APTR mview);
void MV_DrawOff(APTR mview);

void MV_Refresh(APTR mview);

void MV_GetAttrs(APTR mview, ...);
void MV_GetAttrsA(APTR mview, struct TagItem *tags);

void MV_SetViewStart(APTR mview, LONG x, LONG y);
void MV_SetViewRelative(APTR mview, LONG x, LONG y);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
