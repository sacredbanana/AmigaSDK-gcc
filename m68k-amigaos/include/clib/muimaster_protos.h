#ifndef  CLIB_MUIMASTER_PROTOS_H
#define  CLIB_MUIMASTER_PROTOS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/****************************************/
/* functions to be used in applications */
/****************************************/

__stdargs Object *MUI_NewObjectA(CONST_STRPTR classname, struct TagItem *tags);
__stdargs Object *MUI_NewObject(CONST_STRPTR classname, Tag tag1, ...);
__stdargs Object *MUI_MakeObjectA(LONG type, ULONG *params);
__stdargs Object *MUI_MakeObject(LONG type, ...);
__stdargs VOID    MUI_DisposeObject(Object *obj);
__stdargs LONG    MUI_RequestA(Object *app, Object *win, ULONG flags, CONST_STRPTR title, CONST_STRPTR gadgets, CONST_STRPTR format, APTR params);
__stdargs LONG    MUI_Request(Object *app, Object *win, ULONG flags, CONST_STRPTR title, CONST_STRPTR gadgets, CONST_STRPTR format, ...);
__stdargs LONG    MUI_Error(VOID);
__stdargs APTR    MUI_AllocAslRequest(ULONG reqType, struct TagItem *tagList);
__stdargs APTR    MUI_AllocAslRequestTags(ULONG reqType, Tag Tag1, ...);
__stdargs VOID    MUI_FreeAslRequest(APTR requester);
__stdargs BOOL    MUI_AslRequest(APTR requester, struct TagItem *tagList);
__stdargs BOOL    MUI_AslRequestTags(APTR requester, Tag Tag1, ...);

/******************************************/
/* functions to be used in custom classes */
/******************************************/

__stdargs LONG                    MUI_SetError(LONG num);
__stdargs struct IClass *         MUI_GetClass(CONST_STRPTR classname);
__stdargs VOID                    MUI_FreeClass(struct IClass *classptr);
__stdargs VOID                    MUI_RequestIDCMP(Object *obj, ULONG flags);
__stdargs VOID                    MUI_RejectIDCMP(Object *obj, ULONG flags);
__stdargs VOID                    MUI_Redraw(Object *obj, ULONG flags);
__stdargs APTR                    MUI_AddClipping(struct MUI_RenderInfo *mri, WORD left, WORD top, WORD width, WORD height);
__stdargs VOID                    MUI_RemoveClipping(struct MUI_RenderInfo *mri, APTR handle);
__stdargs APTR                    MUI_AddClipRegion(struct MUI_RenderInfo *mri, struct Region *r);
__stdargs VOID                    MUI_RemoveClipRegion(struct MUI_RenderInfo *mri, APTR handle);
__stdargs BOOL                    MUI_BeginRefresh(struct MUI_RenderInfo *mri, ULONG flags);
__stdargs VOID                    MUI_EndRefresh(struct MUI_RenderInfo *mri, ULONG flags);
__stdargs struct MUI_CustomClass *MUI_CreateCustomClass(struct Library *base, CONST_STRPTR supername, struct MUI_CustomClass *supermcc, ULONG datasize, APTR dispatcher);
__stdargs BOOL                    MUI_DeleteCustomClass(struct MUI_CustomClass *mcc);
__stdargs LONG                    MUI_ObtainPen(struct MUI_RenderInfo *mri, const struct MUI_PenSpec *spec, ULONG flags);
__stdargs VOID                    MUI_ReleasePen(struct MUI_RenderInfo *mri, LONG pen);

/*************************************************************/
/* layout function, use only in custom layout callback hook! */
/*************************************************************/

__stdargs BOOL MUI_Layout(Object *obj, LONG left, LONG top, LONG width, LONG height, ULONG flags);
__stdargs BOOL MUI_LayoutObj(Object *obj, LONG left, LONG top, LONG width, LONG height, ULONG flags);

__stdargs ULONG MUI_Show(Object *obj);
__stdargs ULONG MUI_Hide(Object *obj);
__stdargs VOID MUI_Offset(Object *obj, LONG addx, LONG addy);

#ifdef __cplusplus
}
#endif
#endif /* CLIB_MUIMASTER_PROTOS_H */
