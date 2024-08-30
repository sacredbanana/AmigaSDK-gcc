#ifndef  CLIB_MUIMASTER_PROTOS_H
#define  CLIB_MUIMASTER_PROTOS_H

/*
	muimaster.library C prototypes

	Copyright © 2002-2020 Stefan Stuntz & The MorphOS Development Team, All Rights Reserved.
*/

#if defined(__ixemul__) && !defined(__IXEMUL_EXEC_MIXING_ALLOWED)
# error "Mixing ixemul and native library calls is not supported. Native application should be built with -noixemul"
#endif

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/****************************************/
/* functions to be used in applications */
/****************************************/

Boopsiobject *MUI_NewObjectA         (char *classname,struct TagItem *tags);
#if !defined(USE_INLINE_STDARG)
Boopsiobject *MUI_NewObject          (char *classname,Tag tag1,...);
#endif
Boopsiobject *MUI_MakeObjectA        (LONG type,ULONG *params);
#if !defined(USE_INLINE_STDARG)
Boopsiobject *MUI_MakeObject         (LONG type,...);
#endif
VOID    MUI_DisposeObject      (Boopsiobject *obj);
LONG    MUI_RequestA           (APTR app,APTR win,LONGBITS flags,char *title,char *gadgets,char *format,APTR params);
#if !defined(USE_INLINE_STDARG)
LONG    MUI_Request            (APTR app,APTR win,LONGBITS flags,char *title,char *gadgets,char *format,...);
#endif
LONG    MUI_Error              (VOID);
APTR    MUI_AllocAslRequest    (unsigned long reqType, struct TagItem *tagList);
#if !defined(USE_INLINE_STDARG)
APTR    MUI_AllocAslRequestTags(unsigned long reqType, Tag Tag1, ...);
#endif
VOID    MUI_FreeAslRequest     (APTR requester );
BOOL    MUI_AslRequest         (APTR requester, struct TagItem *tagList);
#if !defined(USE_INLINE_STDARG)
BOOL    MUI_AslRequestTags     (APTR requester, Tag Tag1, ...);
#endif

/******************************************/
/* functions to be used in custom classes */
/******************************************/

LONG                    MUI_SetError         (LONG num);
struct IClass *         MUI_GetClass         (char *classname);
VOID                    MUI_FreeClass        (struct IClass *classptr);
VOID                    MUI_RequestIDCMP     (Boopsiobject *obj,ULONG flags);
VOID                    MUI_RejectIDCMP      (Boopsiobject *obj,ULONG flags);
VOID                    MUI_Redraw           (Boopsiobject *obj,ULONG flags);
APTR                    MUI_AddClipping      (struct MUI_RenderInfo *mri,WORD left,WORD top,WORD width,WORD height);
VOID                    MUI_RemoveClipping   (struct MUI_RenderInfo *mri,APTR handle);
APTR                    MUI_AddClipRegion    (struct MUI_RenderInfo *mri,struct Region *r);
VOID                    MUI_RemoveClipRegion (struct MUI_RenderInfo *mri,APTR handle);
BOOL                    MUI_BeginRefresh     (struct MUI_RenderInfo *mri,ULONG flags);
VOID                    MUI_EndRefresh       (struct MUI_RenderInfo *mri,ULONG flags);
struct MUI_CustomClass *MUI_CreateCustomClass(struct Library *base,char *supername,struct MUI_CustomClass *supermcc,int datasize,APTR dispatcher);
BOOL                    MUI_DeleteCustomClass(struct MUI_CustomClass *mcc);
LONG                    MUI_ObtainPen        (struct MUI_RenderInfo *mri,struct MUI_PenSpec *spec,ULONG flags);
VOID                    MUI_ReleasePen       (struct MUI_RenderInfo *mri,LONG pen);
LONG                    MUI_GetRGBColor      (const struct MUI_RenderInfo *mri, const struct MUI_PenSpec *spec, ULONG *color);

/*************************************************************/
/* layout function, use only in custom layout callback hook! */
/*************************************************************/

BOOL MUI_Layout(Boopsiobject *obj,LONG left,LONG top,LONG width,LONG height,ULONG flags);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_MUIMASTER_PROTOS_H */
