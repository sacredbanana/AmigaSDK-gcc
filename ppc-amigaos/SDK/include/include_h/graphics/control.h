#ifndef GRAPHICS_CONTROL_H
#define GRAPHICS_CONTROL_H
/*
**    $VER: control.h 54.16 (22.08.2022)
**
**    Graphics control include file
**
**    Copyright (c) 2014 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

// Tags for GraphicsControlTagList()

#define GCTRL_GetForceSWComposite    (TAG_USER + 1)
#define GCTRL_SetForceSWComposite    (TAG_USER + 2)
#define GCTRL_GetUseDMA              (TAG_USER + 3)
#define GCTRL_SetUseDMA              (TAG_USER + 4)
#define GCTRL_GetUseAltiVec          (TAG_USER + 5)
#define GCTRL_SetUseAltiVec          (TAG_USER + 6)
#define GCTRL_GetDisableAmigaBlitter (TAG_USER + 7)
#define GCTRL_SetDisableAmigaBlitter (TAG_USER + 8)
#define GCTRL_GetPlanesToFast        (TAG_USER + 9)
#define GCTRL_SetPlanesToFast        (TAG_USER + 10)
#define GCTRL_Get31KHzScanRate       (TAG_USER + 11)
#define GCTRL_Set31KHzScanRate       (TAG_USER + 12)

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* GRAPHICS_MINTERM_H */
