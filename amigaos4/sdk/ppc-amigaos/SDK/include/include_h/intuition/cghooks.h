#ifndef INTUITION_CGHOOKS_H
#define INTUITION_CGHOOKS_H 1
/*
**    $VER: cghooks.h 54.16 (22.08.2022)
**
**    Custom Gadget processing
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
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
 * Package of information passed to custom and 'boopsi'
 * gadget "hook" functions.  This structure is READ ONLY.
 */
struct GadgetInfo
{

    struct Screen    *gi_Screen;
    struct Window    *gi_Window;    /* null for screen gadgets */
    struct Requester *gi_Requester; /* null if not GTYP_REQGADGET */

    /* rendering information:
     * don't use these without cloning/locking.
     * Official way is to call ObtainRPort()
     */
    struct RastPort  *gi_RastPort;
    struct Layer     *gi_Layer;

    /* copy of dimensions of screen/window/g00/req(/group)
     * that gadget resides in.    Left/Top of this box is
     * offset from window mouse coordinates to gadget coordinates
     *    screen gadgets:                0,0 (from screen coords)
     *    window gadgets (no g00):       0,0
     *    GTYP_GZZGADGETs (borderlayer): 0,0
     *    GZZ innerlayer gadget:         borderleft, bordertop
     *    Requester gadgets:             reqleft, reqtop
     */
    struct IBox       gi_Domain;

    /* these are the pens for the window or screen    */
    struct
    {
        UBYTE DetailPen;
        UBYTE BlockPen;
    }                 gi_Pens;

    /* the Detail and Block pens in gi_DrInfo->dri_Pens[] are
     * for the screen.    Use the above for window-sensitive
     * colors.
     */
    struct DrawInfo  *gi_DrInfo;

    /* gadget backpointer. New for V50. */
    struct Gadget    *gi_Gadget;

    /* reserved space: this structure is extensible
     * anyway, but using these saves some recompilation
     */
    ULONG             gi_Reserved[5];
};

/*** system private data structure for now ***/
/* prop gadget extra info    */
struct PGX
{
    struct IBox pgx_Container;
    struct IBox pgx_NewKnob;
};

/* this casts MutualExclude for easy assignment of a hook
 * pointer to the unused MutualExclude field of a custom gadget
 */
#define CUSTOM_HOOK( gadget ) ( (struct Hook *) (gadget)->MutualExclude)

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

#endif
