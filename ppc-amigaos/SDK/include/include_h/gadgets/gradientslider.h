#ifndef GADGETS_GRADIENTSLIDER_H
#define GADGETS_GRADIENTSLIDER_H
/*
**    $VER: gradientslider.h 54.16 (22.08.2022)
**
**    Definitions for the gradientslider BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

#define GRAD_Dummy      (TAG_USER+0x05000000)
#define GRAD_MaxVal     (GRAD_Dummy+1)        /* max value of slider */
#define GRAD_CurVal     (GRAD_Dummy+2)        /* current value of slider */
#define GRAD_SkipVal    (GRAD_Dummy+3)        /* "body click" move amount */
#define GRAD_KnobPixels (GRAD_Dummy+4)        /* size of knob in pixels */
#define GRAD_PenArray   (GRAD_Dummy+5)        /* pen colors */

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

#endif /* GADGETS_GRADIENTSLIDER_H */
