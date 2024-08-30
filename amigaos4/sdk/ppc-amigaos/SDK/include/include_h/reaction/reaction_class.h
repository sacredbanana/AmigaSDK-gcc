#ifndef REACTION_REACTION_CLASS_H
#define REACTION_REACTION_CLASS_H
/*
**    $VER: reaction_class.h 54.16 (22.08.2022)
**
**    reaction class author definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   INTUITION_CGHOOKS_H
#include <intuition/cghooks.h>
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

/****************************************************************************/

/*
 * PRIVATE!
 */
struct SpecialPens
{
    WORD sp_Version;  /* Currently 0 */
    LONG sp_DarkPen;  /* XEN/Thick extended locked pen */
    LONG sp_LightPen; /* XEN/Thick extended locked pen */
    /* NOTE: This structure may grow! */
};

/*****************************************************************************
 * Custom method defined and supported by some Reaction Gadgets
 * When this method is supported by more (all?) Reaction Gadgets
 * this structure may move to intuition/gadgetclass.h
 */
#ifndef GM_CLIPRECT
#define GM_CLIPRECT (0x550001L)

/* The GM_CLIPRECT method is used to pass a gadget a cliprect
 * it should install before rendering to ObtainGIRPort() rastports
 * to support proper usage within virtual groups.
 */

struct gpClipRect
{
    ULONG              MethodID;     /* GM_CLIPRECT          */
    struct GadgetInfo *gpc_GInfo;    /* GadgetInfo           */
    struct Rectangle  *gpc_ClipRect; /* Rectangle To Clip To */
    ULONG              gpc_Flags;    /* Flags                */
};

/* Possible return values from GM_CLIPRECT
 */
#define GMC_VISIBLE   2
#define GMC_PARTIAL   1
#define GMC_INVISIBLE 0
#endif

/**************************************************************************/

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

#endif /* REACTION_REACTION_CLASS_H */
