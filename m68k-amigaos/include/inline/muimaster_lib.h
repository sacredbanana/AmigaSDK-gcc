/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MUIMASTER_H
#define _INLINE_MUIMASTER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef MUIMASTER_BASE_NAME
#define MUIMASTER_BASE_NAME MUIMasterBase
#endif /* !MUIMASTER_BASE_NAME */

#define MUI_NewObjectA(___cl, ___tags) \
      LP2(0x1e, Object *, MUI_NewObjectA , CONST_STRPTR, ___cl, a0, struct TagItem *, ___tags, a1,\
      , MUIMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MUI_NewObject(___cl, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MUI_NewObjectA((___cl), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MUI_DisposeObject(___obj) \
      LP1NR(0x24, MUI_DisposeObject , Object *, ___obj, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_RequestA(___app, ___win, ___flags, ___title, ___gadgets, ___format, ___params) \
      LP7(0x2a, LONG, MUI_RequestA , Object *, ___app, d0, Object *, ___win, d1, ULONG, ___flags, d2, CONST_STRPTR, ___title, a0, CONST_STRPTR, ___gadgets, a1, CONST_STRPTR, ___format, a2, APTR, ___params, a3,\
      , MUIMASTER_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define MUI_Request(___app, ___win, ___flags, ___title, ___gadgets, ___format, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; MUI_RequestA((___app), (___win), (___flags), (___title), (___gadgets), (___format), (APTR) _args); })
#endif /* !NO_INLINE_VARARGS */

#define MUI_AllocAslRequest(___type, ___tags) \
      LP2(0x30, APTR, MUI_AllocAslRequest , ULONG, ___type, d0, struct TagItem *, ___tags, a0,\
      , MUIMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MUI_AllocAslRequestTags(___type, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MUI_AllocAslRequest((___type), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MUI_AslRequest(___req, ___tags) \
      LP2(0x36, BOOL, MUI_AslRequest , APTR, ___req, a0, struct TagItem *, ___tags, a1,\
      , MUIMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MUI_AslRequestTags(___req, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MUI_AslRequest((___req), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MUI_FreeAslRequest(___req) \
      LP1NR(0x3c, MUI_FreeAslRequest , APTR, ___req, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_Error() \
      LP0(0x42, LONG, MUI_Error ,\
      , MUIMASTER_BASE_NAME)

#define MUI_SetError(___errnum) \
      LP1(0x48, LONG, MUI_SetError , LONG, ___errnum, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_GetClass(___name) \
      LP1(0x4e, struct IClass *, MUI_GetClass , CONST_STRPTR, ___name, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_FreeClass(___cl) \
      LP1NR(0x54, MUI_FreeClass , struct IClass *, ___cl, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_RequestIDCMP(___obj, ___flags) \
      LP2NR(0x5a, MUI_RequestIDCMP , Object *, ___obj, a0, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_RejectIDCMP(___obj, ___flags) \
      LP2NR(0x60, MUI_RejectIDCMP , Object *, ___obj, a0, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_Redraw(___obj, ___flags) \
      LP2NR(0x66, MUI_Redraw , Object *, ___obj, a0, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_CreateCustomClass(___base, ___supername, ___supermcc, ___datasize, ___dispatcher) \
      LP5(0x6c, struct MUI_CustomClass *, MUI_CreateCustomClass , struct Library *, ___base, a0, CONST_STRPTR, ___supername, a1, struct MUI_CustomClass *, ___supermcc, a2, ULONG, ___datasize, d0, APTR, ___dispatcher, a3,\
      , MUIMASTER_BASE_NAME)

#define MUI_DeleteCustomClass(___mcc) \
      LP1(0x72, BOOL, MUI_DeleteCustomClass , struct MUI_CustomClass *, ___mcc, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_MakeObjectA(___type, ___params) \
      LP2(0x78, Object *, MUI_MakeObjectA , LONG, ___type, d0, ULONG *, ___params, a0,\
      , MUIMASTER_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define MUI_MakeObject(___type, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; MUI_MakeObjectA((___type), (ULONG *) _args); })
#endif /* !NO_INLINE_VARARGS */

#define MUI_Layout(___obj, ___l, ___t, ___w, ___h, ___flags) \
      LP6(0x7e, BOOL, MUI_Layout , Object *, ___obj, a0, LONG, ___l, d0, LONG, ___t, d1, LONG, ___w, d2, LONG, ___h, d3, ULONG, ___flags, d4,\
      , MUIMASTER_BASE_NAME)

#define MUI_ObtainPen(___mri, ___spec, ___flags) \
      LP3(0x9c, LONG, MUI_ObtainPen , struct MUI_RenderInfo *, ___mri, a0, const struct MUI_PenSpec *, ___spec, a1, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_ReleasePen(___mri, ___pen) \
      LP2NR(0xa2, MUI_ReleasePen , struct MUI_RenderInfo *, ___mri, a0, LONG, ___pen, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_AddClipping(___mri, ___l, ___t, ___w, ___h) \
      LP5(0xa8, APTR, MUI_AddClipping , struct MUI_RenderInfo *, ___mri, a0, WORD, ___l, d0, WORD, ___t, d1, WORD, ___w, d2, WORD, ___h, d3,\
      , MUIMASTER_BASE_NAME)

#define MUI_RemoveClipping(___mri, ___h) \
      LP2NR(0xae, MUI_RemoveClipping , struct MUI_RenderInfo *, ___mri, a0, APTR, ___h, a1,\
      , MUIMASTER_BASE_NAME)

#define MUI_AddClipRegion(___mri, ___region) \
      LP2(0xb4, APTR, MUI_AddClipRegion , struct MUI_RenderInfo *, ___mri, a0, struct Region *, ___region, a1,\
      , MUIMASTER_BASE_NAME)

#define MUI_RemoveClipRegion(___mri, ___region) \
      LP2NR(0xba, MUI_RemoveClipRegion , struct MUI_RenderInfo *, ___mri, a0, APTR, ___region, a1,\
      , MUIMASTER_BASE_NAME)

#define MUI_BeginRefresh(___mri, ___flags) \
      LP2(0xc0, BOOL, MUI_BeginRefresh , struct MUI_RenderInfo *, ___mri, a0, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_EndRefresh(___mri, ___flags) \
      LP2NR(0xc6, MUI_EndRefresh , struct MUI_RenderInfo *, ___mri, a0, ULONG, ___flags, d0,\
      , MUIMASTER_BASE_NAME)

#define MUI_Show(___obj) \
      LP1(0xd8, ULONG, MUI_Show , Object *, ___obj, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_Hide(___obj) \
      LP1(0xde, ULONG, MUI_Hide , Object *, ___obj, a0,\
      , MUIMASTER_BASE_NAME)

#define MUI_LayoutObj(___obj, ___l, ___t, ___w, ___h, ___flags) \
      LP6(0xe4, BOOL, MUI_LayoutObj , Object *, ___obj, a0, LONG, ___l, d0, LONG, ___t, d1, LONG, ___w, d2, LONG, ___h, d3, ULONG, ___flags, d4,\
      , MUIMASTER_BASE_NAME)

#define MUI_Offset(___obj, ___x, ___y) \
      LP3NR(0xea, MUI_Offset , Object *, ___obj, a0, LONG, ___x, d0, LONG, ___y, d1,\
      , MUIMASTER_BASE_NAME)

#endif /* !_INLINE_MUIMASTER_H */
