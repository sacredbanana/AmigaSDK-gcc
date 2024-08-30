#ifndef GRAPHICS_RPATTR_H
#define GRAPHICS_RPATTR_H
/*
**    $VER: rpattr.h 54.16 (22.08.2022)
**
**    tag definitions for GetRPAttr, SetRPAttr
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
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

#define RPTAG_Font            0x80000000 /* get/set font */
#define RPTAG_APen            0x80000002 /* get/set apen */
#define RPTAG_BPen            0x80000003 /* get/set bpen */
#define RPTAG_DrMd            0x80000004 /* get/set draw mode */
#define RPTAG_OutLinePen      0x80000005 /* get/set outline pen */
#define RPTAG_OutlinePen      0x80000005 /* get/set outline pen. corrected case. */
#define RPTAG_OPen            0x80000005 /* get/set outline pen. short alias. */
#define RPTAG_WriteMask       0x80000006 /* get/set WriteMask */
#define RPTAG_MaxPen          0x80000007 /* get/set maxpen */

#define RPTAG_DrawBounds      0x80000008 /* get only rastport draw bounds. pass &rect */

/* V51 extensions */
#define RPTAG_APenColor       0x80000009 /* get/set apen color 0xaarrggbb */
#define RPTAG_BPenColor       0x8000000A /* get/set bpen color 0xaarrggbb */
#define RPTAG_OPenColor       0x8000000B /* get/set open color 0xaarrggbb */
#define RPTAG_OutlinePenColor 0x8000000B /* get/set open color 0xaarrggbb. alias. */
#define RPTAG_RemapColorFonts 0x8000000C /* get/set */
#define RPTAG_BitMap          0x8000000D /* get/set bitmap of rastport */

/* V54 extensions */
#define RPTAG_XPos            0x8000000E /* get/set x position */
#define RPTAG_YPos            0x8000000F /* get/set y position */

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

#endif /* GRAPHICS_RPATTR_H */
