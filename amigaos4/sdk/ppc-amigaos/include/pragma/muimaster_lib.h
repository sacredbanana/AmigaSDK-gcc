#ifndef _INCLUDE_PRAGMA_MUIMASTER_LIB_H
#define _INCLUDE_PRAGMA_MUIMASTER_LIB_H

#ifndef  CLIB_MUIMASTER_PROTOS_H
#include <clib/muimaster_protos.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma amicall(MUIMasterBase,0x1e,MUI_NewObjectA(a0,a1))
#pragma tagcall(MUIMasterBase,0x1e,MUI_NewObject(a0,a1))
#pragma amicall(MUIMasterBase,0x24,MUI_DisposeObject(a0))
#pragma amicall(MUIMasterBase,0x2a,MUI_RequestA(d0,d1,d2,a0,a1,a2,a3))
#pragma tagcall(MUIMasterBase,0x2a,MUI_Request(d0,d1,d2,a0,a1,a2,a3))
#pragma amicall(MUIMasterBase,0x30,MUI_AllocAslRequest(d0,a0))
#pragma tagcall(MUIMasterBase,0x30,MUI_AllocAslRequestTags(d0,a0))
#pragma amicall(MUIMasterBase,0x36,MUI_AslRequest(a0,a1))
#pragma tagcall(MUIMasterBase,0x36,MUI_AslRequestTags(a0,a1))
#pragma amicall(MUIMasterBase,0x3c,MUI_FreeAslRequest(a0))
#pragma amicall(MUIMasterBase,0x42,MUI_Error())
#pragma amicall(MUIMasterBase,0x48,MUI_SetError(d0))
#pragma amicall(MUIMasterBase,0x4e,MUI_GetClass(a0))
#pragma amicall(MUIMasterBase,0x54,MUI_FreeClass(a0))
#pragma amicall(MUIMasterBase,0x5a,MUI_RequestIDCMP(a0,d0))
#pragma amicall(MUIMasterBase,0x60,MUI_RejectIDCMP(a0,d0))
#pragma amicall(MUIMasterBase,0x66,MUI_Redraw(a0,d0))
#pragma amicall(MUIMasterBase,0x6c,MUI_CreateCustomClass(a0,a1,a2,d0,a3))
#pragma amicall(MUIMasterBase,0x72,MUI_DeleteCustomClass(a0))
#pragma amicall(MUIMasterBase,0x78,MUI_MakeObjectA(d0,a0))
#pragma tagcall(MUIMasterBase,0x78,MUI_MakeObject(d0,a0))
#pragma amicall(MUIMasterBase,0x7e,MUI_Layout(a0,d0,d1,d2,d3,d4))
#pragma amicall(MUIMasterBase,0x9c,MUI_ObtainPen(a0,a1,d0))
#pragma amicall(MUIMasterBase,0xa2,MUI_ReleasePen(a0,d0))
#pragma amicall(MUIMasterBase,0xa8,MUI_AddClipping(a0,d0,d1,d2,d3))
#pragma amicall(MUIMasterBase,0xae,MUI_RemoveClipping(a0,a1))
#pragma amicall(MUIMasterBase,0xb4,MUI_AddClipRegion(a0,a1))
#pragma amicall(MUIMasterBase,0xba,MUI_RemoveClipRegion(a0,a1))
#pragma amicall(MUIMasterBase,0xc0,MUI_BeginRefresh(a0,d0))
#pragma amicall(MUIMasterBase,0xc6,MUI_EndRefresh(a0,d0))
#pragma amicall(MUIMasterBase,0xd8,MUI_Show(a0))
#pragma amicall(MUIMasterBase,0xde,MUI_Hide(a0))
#pragma amicall(MUIMasterBase,0xe4,MUI_LayoutObj(a0,d0,d1,d2,d3,d4))
#pragma amicall(MUIMasterBase,0xea,MUI_Offset(a0,d0,d1))

#ifdef __cplusplus
}
#endif

#endif
