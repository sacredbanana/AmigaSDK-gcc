#ifndef PREFS_REACTION_H
#define PREFS_REACTION_H
/*
**    $VER: reaction.h 54.16 (22.08.2022)
**
**    Reaction preferences file definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef   GRAPHICS_TEXT_H
#include <graphics/text.h>
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

#define ID_RACT MAKE_ID('R','A','C','T')

#define FONTNAMESIZE (128)

struct ReactionPrefs
{
    UWORD           rp_BevelType; /* see <reaction/reaction_prefs.h> */
    UWORD           rp_GlyphType; /* see (reaction/reaction_prefs.h> */
    UWORD           rp_LayoutSpacing;
    BOOL            rp_3DProp;
    UWORD           rp_LabelPen;
    UWORD           rp_LabelPlace;
    BOOL            rp_3DLabel;
    BOOL            rp_SimpleRefresh;
    BOOL            rp_3DLook;
    struct TextAttr rp_FallbackAttr;
    struct TextAttr rp_LabelAttr;
    TEXT            rp_FallbackName[FONTNAMESIZE];
    TEXT            rp_LabelName[FONTNAMESIZE];
    TEXT            rp_Pattern[256];
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

#endif /* PREFS_REACTION_H */
