#ifndef GADGETS_TAPEDECK_H
#define GADGETS_TAPEDECK_H
/*
**    $VER: tapedeck.h 54.16 (22.08.2022)
**
**    Definitions for the tapedeck BOOPSI class
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

#define TDECK_Dummy        (TAG_USER+0x05000000)
#define TDECK_Mode         (TDECK_Dummy + 1)
#define TDECK_Paused       (TDECK_Dummy + 2)

#define TDECK_Tape         (TDECK_Dummy + 3)
    /* (BOOL) Indicate whether tapedeck or animation controls.  Defaults
       to FALSE. */

#define TDECK_Frames       (TDECK_Dummy + 11)
    /* (LONG) Number of frames in animation.  Only valid when using
       animation controls. */

#define TDECK_CurrentFrame (TDECK_Dummy + 12)
    /*  (LONG) Current frame.  Only valid when using animation controls. */

/*****************************************************************************/

/* Possible values for TDECK_Mode */
#define BUT_REWIND  0
#define BUT_PLAY    1
#define BUT_FORWARD 2
#define BUT_STOP    3
#define BUT_PAUSE   4
#define BUT_BEGIN   5
#define BUT_FRAME   6
#define BUT_END     7

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

#endif /* GADGETS_TAPEDECK_H */
