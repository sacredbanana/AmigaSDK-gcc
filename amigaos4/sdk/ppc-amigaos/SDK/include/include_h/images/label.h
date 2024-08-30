#ifndef IMAGES_LABEL_H
#define IMAGES_LABEL_H
/*
**    $VER: label.h 54.16 (22.08.2022)
**
**    Definitions for the Label BOOPSI class
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

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/imageclass.h>
#endif


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

/*****************************************************************************/

/* Justification modes.
 */
#define LJ_LEFT   0
#define LJ_CENTRE 1
#define LJ_CENTER 1
#define LJ_RIGHT  2

/* Obsolete, DON'T USE THESE!
 */
#define LABEL_LEFT   LJ_LEFT
#define LABEL_CENTRE LJ_CENTRE
#define LABEL_CENTER LJ_CENTRE
#define LABEL_RIGHT  LJ_RIGHT

/* Vertical alignment types.
 */
#define LVALIGN_BOTTOM   0
#define LVALIGN_BASELINE 1

/*****************************************************************************/

/* Additional attributes defined by the Label class
 */
#define LABEL_Dummy           (REACTION_Dummy+0x0006000)

#define LABEL_DrawInfo        SYSIA_DrawInfo

#define LABEL_Text            (LABEL_Dummy+1)
    /* (CONST_STRPTR) Text to print in the label. */

#define LABEL_Image           (LABEL_Dummy+2)
    /* (struct Image *) Image to print in the label. */

#define LABEL_Mapping         (LABEL_Dummy+3)
    /* (uint16 *) Mapping array for the next image. */

#define LABEL_Justification   (LABEL_Dummy+4)
    /* (uint16) Justification modes (see above) */

#define LABEL_Key             (LABEL_Dummy+5)
    /* (uint16) Returns the underscored key (if any) */

#define LABEL_Underscore      (LABEL_Dummy+6)
    /* (uint8) Defaults to '_'. */

#define LABEL_DisposeImage    (LABEL_Dummy+7)
    /* (BOOL) Defaults to FALSE. */

#define LABEL_SoftStyle       (LABEL_Dummy+8)
    /* (uint8) Defaults to none. */

#define LABEL_VerticalSpacing (LABEL_Dummy+9)
    /* (uint16) Vertical spacing between text/image nodes/lines.
       Defaults to 0. */

#define LABEL_VerticalAlignment (LABEL_Dummy+10)
    /* (uint16) Vertical alignment for subsequent text/images.
       Defaults to LVALIGN_BOTTOM. */

#define LABEL_WordWrap          (LABEL_Dummy+11)
    /* (uint16) Specifies the width for each LABEL_Text before
       breaking the line. Defaults to 0 (no wrap) */

#define LABEL_MenuMode          (LABEL_Dummy+12)
    /* (BOOL) Use highlighting that fits in better visually in a
       menu. Defaults to FALSE. */

/*****************************************************************************/

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

#endif /* IMAGES_LABEL_H */
