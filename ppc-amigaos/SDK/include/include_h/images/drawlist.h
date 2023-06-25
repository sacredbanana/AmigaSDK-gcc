#ifndef IMAGES_DRAWLIST_H
#define IMAGES_DRAWLIST_H
/*
**    $VER: drawlist.h 54.16 (22.08.2022)
**
**    Definitions for the drawlist.image BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

/*****************************************************************************/

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

#define DRAWLIST_Dummy      (REACTION_Dummy + 0x17000)

#define DRAWLIST_Directives (DRAWLIST_Dummy+1)
    /* (struct DrawList *) Pointer to drawlist directive array. */

#define DRAWLIST_RefHeight  (DRAWLIST_Dummy+2)
    /* (WORD) Reference height of drawlist. */

#define DRAWLIST_RefWidth   (DRAWLIST_Dummy+3)
    /* (WORD) Reference width of drawlist. */

#define DRAWLIST_DrawInfo   (DRAWLIST_Dummy+4)
    /* Obsolete!! Do not use. */

/*****************************************************************************/

/* DrawList Primitive Directives */

#define DLST_END       0

#define DLST_LINE      1
#define DLST_RECT      2
#define DLST_FILL      3
#define DLST_ELLIPSE   4
#define DLST_CIRCLE    5
#define DLST_LINEPAT   6
#define DLST_FILLPAT   7
#define DLST_AMOVE     8
#define DLST_ADRAW     9
#define DLST_AFILL    10
#define DLST_BEVELBOX 11
#define DLST_ARC      12
#define DLST_START    13
#define DLST_BOUNDS   13
#define DLST_LINESIZE 14

/*****************************************************************************/

/* Pass an array of these via DRAWLIST_Directives.
 * Last entry must be DLST_END!
 */

struct DrawList
{
    WORD dl_Directive;
    WORD dl_X1;
    WORD dl_Y1;
    WORD dl_X2;
    WORD dl_Y2;
    WORD dl_Pen;
};

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

#endif /* IMAGES_DRAWLIST_H */
