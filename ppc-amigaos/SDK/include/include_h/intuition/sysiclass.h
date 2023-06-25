#ifndef INTUITION_SYSICLASS_H
#define INTUITION_SYSICLASS_H
/*
**    $VER: sysiclass.h 54.16 (22.08.2022)
**
**    System image class definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef   INTUITION_IMAGECLASS_H
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

/****************************************************************************/

/***************************************************/
/*** Common structures for simple vector drawing ***/
/***************************************************/

struct Vector
{
   UBYTE  Operation; /* Type of rendering operation */
   UBYTE  Type;      /* Type of environment (monochrome/color) */
   UWORD  DRIPen;    /* DrawInfo pen for this rendering */
   ULONG  States;    /* States this rendering applies to */
   WORD   X, Y;      /* Offsets for rendering */
   UWORD *Data;      /* Rendering specifications */
};

struct VectorInfo
{
   ULONG          VectorID;     /* To identify the image, if needed */
   struct Vector *Vectors;      /* VO_END-terminated array of vectors */
   UWORD          DesignWidth;  /* Reference width for scaling */
   UWORD          DesignHeight; /* Reference height for scaling */
   ULONG          Flags;        /* Additional information */
   ULONG          States;       /* Supported states */
};

/* Values for Vector.Operation */

#define VO_LINE 0x00  /* Outline only */
#define VO_FILL 0x01  /* Filled, not outline */
#define VO_RECT 0x00  /* Rectangle */
#define VO_POLY 0x02  /* Polygon */
#define VO_ELPS 0x04  /* Ellipse */

#define VO_LINERECT (VO_LINE | VO_RECT)
#define VO_FILLRECT (VO_FILL | VO_RECT)
#define VO_LINEPOLY (VO_LINE | VO_POLY)
#define VO_FILLPOLY (VO_FILL | VO_POLY)
#define VO_LINEELPS (VO_LINE | VO_ELPS)
#define VO_FILLELPS (VO_FILL | VO_ELPS)

#define VO_END      0xFF  /* End marker for Vector array */

/* Values for Vector.Type */

#define VT_MONO  0x01  /* Vector is used for monochrome rendering */
#define VT_COLOR 0x02  /* Vector is used for color rendering */
#define VT_BOTH  0x03  /* Vector is used for both types of rendering */

/* Special values for Vector.DRIPen */

#define PEN_BRIGHT      0x1000  /* Bright shade of the background */
#define PEN_HALFBRIGHT  0x1001  /* Half-bright shade of the background */
#define PEN_HALFDARK    0x1003  /* Half-dark shade of the background */
#define PEN_DARK        0x1004  /* Dark shade of the background */
#define PEN_ALPHASHINE  0x2000  /* OR with 0..255 for bright alpha shading */
#define PEN_ALPHASHADOW 0x3000  /* OR with 0..255 for dark alpha shading */
#define PEN_ALPHA       0x4000  /* OR with 0..255 for alpha blending */

/* State flags. Sysiclass doesn't support INACTIVEDISABLED for now. */

#define IDSF_NORMAL           (1 << IDS_NORMAL)
#define IDSF_SELECTED         (1 << IDS_SELECTED)
#define IDSF_DISABLED         (1 << IDS_DISABLED)
#define IDSF_INACTIVENORMAL   (1 << IDS_INACTIVENORMAL)
#define IDSF_INACTIVESELECTED (1 << IDS_INACTIVESELECTED)
#define IDSF_SELECTEDDISABLED (1 << IDS_SELECTEDDISABLED)

#define IDSF_MASK             (0x10000000L) /* Use for image mask */
#define IDSF_DISABLEDMASK     (0x20000000L) /* Use for normal disabled mask */
#define IDSF_SELDISABLEDMASK  (0x40000000L) /* Use for selected disabled mask*/
#define IDSF_ERASEMASK        (0x80000000L) /* Draw mask with color zero */

/* Values for VectorInfo.Flags */

#define VIF_WMULTIPLY      0x0000000F /* Multiplier for width (VIF_REFFONT) */
#define VIF_REFFONT        0x00000010 /* Allows reference font
                                         to be specified */
#define VIF_IGNOREWIDTH    0x00000020 /* Ignore IA_Width */
#define VIF_IGNOREHEIGHT   0x00000040 /* Ignore IA_Height */
#define VIF_ROUNDEDSCALING 0x00000100 /* Needs rounded scaling */
#define VIF_KEEPASPECT     0x00000200 /* Preserve aspect ratio of
                                         reference size */
#define VIF_3DDISABLE      0x00000400 /* Uses 3D (embossed) disable effects */
#define VIF_NOBUFFER       0x00000800 /* Render without using off-screen
                                         bitmaps */
#define VIF_PENSHADE       0x00001000 /* Uses pen shading, needs a map */
#define VIF_ALPHASHINE     0x00002000 /* Uses bright alpha shading,
                                         needs a map */
#define VIF_ALPHASHADOW    0x00004000 /* Uses dark alpha shading,
                                         needs a map */
#define VIF_ALPHASHADE     0x00006000 /* Uses both bright and dark
                                         alpha shading */
#define VIF_ALPHABLEND     0x00008000 /* Uses alpha blending, needs a map */
#define VIF_BORDERMASK     0x00FF0000 /* Specifications for image borders */
#define VIF_TBLEFT         0x00010000 /* Image is for left side of titlebar */
#define VIF_TBRIGHT        0x00020000 /* Image is for right side of titlebar */
#define VIF_VERTARROW      0x00040000 /* Image is for right window border */
#define VIF_HORIZARROW     0x00080000 /* Image is for bottom window border */
#define VIF_BRCORN         0x00100000 /* Image is for bottom-right
                                         window corner */
#define VIF_SCREENBAR      0x00200000 /* Image is for screen titlebar */
#define VIF_MENU           0x00400000 /* Image is for menu panel */
#define VIF_BUTTON         0x00800000 /* Image must have a button-like
                                         border */


/**********************************************/
/*** The sysiclass rendering hook interface ***/
/**********************************************/

/* Starting with Intuition V50, sysiclass supports custom rendering hooks.   */
/* The rendering hook message structure is defined in <intuition/plugins.h>; */
/* object is a struct Image * (the image instance to be drawn).              */
/* Please note that the object may be NULL, in which case the rm_Flags field */
/* will hold information on what to render (see flags defined below).        */

/* These are the different types of messages that a sysiclass rendering hook */
/* can see; more might be added in future Intuition releases.                */
/*                                                                           */
/* NOTE WELL: in a pen shade level map, you render with colors 0-4, which    */
/* correspond to the LEVEL_#? constants defined in <intuition/gui.h>.        */
/* In an alpha shading map, instead, you render with colors 0-255 which are  */
/* interpreted as alpha intensity percentages (darkest to brightest).        */
/* The former method allows to produce 3D effects consistent with the user   */
/* contrast settings for the GUI; the latter allows for fancy/artistic       */
/* 3D rendering, but can only be used on hicolor/truecolor screenmodes.      */

#define SR_DRAW           801 /* Render symbol imagery for this state        */
#define SR_DRAWMASK       802 /* Render symbol shape mask for this state     */
#define SR_DRAWDISMASK    803 /* Render outline mask for disabling, normal   */
#define SR_DRAWSELDISMASK 804 /* Render outline mask for disabling, selected */
#define SR_DRAWLEVELMAP   805 /* Render pen shade level map (if any)         */
#define SR_DRAWSHINEMAP   806 /* Render bright alpha shading map (if any)    */
#define SR_DRAWSHADOWMAP  807 /* Render dark alpha shading map (if any)      */
#define SR_DRAWALPHAMAP   808 /* Render alpha blending map (if any)          */
#define SR_DRAWIMAGEFRAME 809 /* Render frame for this image, if any         */

/* These are the sysiclass-specific values for RenderMsg.rm_Flags */

#define SRF_MONOCHROME     0x00000001 /* Render as monochrome                */
#define SRF_ISBITMAP       0x00000002 /* A bitmap will later be applied      */
#define SRF_HSCROLLERFRAME 0x00000004 /* Render frame for horizontal scroller*/
#define SRF_VSCROLLERFRAME 0x00000008 /* Render frame for vertical scroller  */


/****************************************************/
/***        The sysiclass plugin interface        ***/
/*** -------------------------------------------- ***/
/*** Warning: for style plugin implementors only! ***/
/****************************************************/

/* A sysiclass plugin can export graphic styles for system  */
/* imagery (in the form of a rendering hook and/or an array */
/* of struct VectorInfo) as well as geometry information    */
/* for system gadgets and images (in the form of a geometry */
/* hook, see below). As of V50, the style and geometry      */
/* categories known by sysiclass are the following:         */

#define SC_GLOBALSTYLE      (0)  /* Default (fallback) graphic style */
#define SC_GLOBALGEOMETRY   (1)  /* Default (fallback) geometry      */
#define SC_WINBORDERSTYLE   (2)  /* Style for window borders         */
#define SC_WINBFRAMESTYLE   (3)  /* Style for border gadget frames   */
#define SC_WINBGADSTYLE     (4)  /* Style for border gadget symbols  */
#define SC_GADGETSTYLE      (5)  /* Style for generic gadget symbols */
#define SC_ARROWGSTYLE      (6)  /* Style for arrow gadget symbols   */
#define SC_CYCLEGSTYLE      (7)  /* Style for cycle gadget symbols   */
#define SC_KHANDLESTYLE     (8)  /* Style for knob handle symbols    */
#define SC_MENUSTYLE        (9)  /* Style for menu images            */
#define SC_WINBGADGEOMETRY (10)  /* Geometry for border gadgets      */
#define SC_GADGETGEOMETRY  (11)  /* Geometry for inner gadgets       */

/* Each plugin can export one or more sub-styles for each   */
/* of the above style categories. It informs clients about  */
/* this by initializing its SubStyles field: it must point  */
/* to an array of struct SubStyle, each of which represents */
/* a specific sub-style for a given category, and gives its */
/* name and unique ID number (uniqueness only needs to be   */
/* relative to the plugin and category). The array must be  */
/* terminated by way of a NULL Name field.                  */
/* Specialized categories should contain at least all the   */
/* sub-styles of their parent category. The style category  */
/* hierarchy (as of V50) is as follows:                     */
/*                                                          */
/* +--SC_GLOBALSTYLE                                        */
/* |  |                                                     */
/* |  +--SC_WINBORDERSTYLE                                  */
/* |  +--SC_WINBFRAMESTYLE                                  */
/* |  +--SC_WINBGADSTYLE                                    */
/* |  +--SC_MENUSTYLE                                       */
/* |  +--SC_GADGETSTYLE                                     */
/* |     |                                                  */
/* |     +--SC_ARROWGSTYLE                                  */
/* |     +--SC_CYCLEGSTYLE                                  */
/* |     +--SC_KHANDLESTYLE                                 */
/* |                                                        */
/* +--SC_GLOBALGEOMETRY                                     */
/*    |                                                     */
/*    +--SC_WINBGADGEOMETRY                                 */
/*    +--SC_GADGETGEOMETRY                                  */
/*                                                          */

struct SubStyle
{
   CONST_STRPTR Name;      /* Name of the sub-style           */
   UWORD        Category;  /* Category it belongs to          */
   UWORD        ID;        /* Unique style ID for this plugin */
};

/* The main structure exported by a style plugin library: */
/* it is a generic GUIPlugin structure followed by fields */
/* specific to sysiclass.                                 */
/* Note: the (sparse) VectorInfo array, if present, needs */
/* to be terminated by an element with VectorID == ~0L.   */

struct SysIPlugin
{
   struct Node        Node;          /* Reserved, don't use                  */
   ULONG              Version;       /* Version of the plugin                */
   ULONG              Type;          /* PLUGIN_SYSI                          */
   ULONG              Attrs;         /* Type-specific attributes (see below) */
   ULONG              Flags;         /* Additional information               */
   struct TagItem    *AttrList;      /* Optional list of GUI attributes      */
   ULONG              Reserved[4];   /* For future expansion                 */
   struct Hook       *RenderHook;    /* Optional rendering hook              */
   struct VectorInfo *VIArray;       /* Optional array of struct VectorInfo  */
   UWORD              Reserved1;     /* For future expansion                 */
   struct Hook       *GeometryHook;  /* Optional geometry hook (see below)   */
   struct SubStyle   *SubStyles;     /* Table of available sub-styles        */
   ULONG              Reserved2[4];  /* For future expansion                 */
};

/* Plugin type */

#define PLUGIN_SYSI 1  /* Identifies a system imagery plugin */

/* Plugin attributes (flags) */

#define SPA_WINBORDERSTYLE  0x00000004  /* NOT SUPPORTED YET */
#define SPA_WINBFRAMESTYLE  0x00000008  /* Plugin exports style for
                                         * border gadget frames
                                         */
#define SPA_WINBGADSTYLE    0x00000010  /* Plugin exports style for
                                         * border gadget symbols
                                         */
#define SPA_GADGETSTYLE     0x00000020  /* Plugin exports style for
                                         * normal gadget symbols
                                         */
#define SPA_MENUSTYLE       0x00000200  /* Plugin exports style for
                                         * menu symbols
                                         */
#define SPA_WINBGADGEOMETRY 0x00000400  /* Plugin exports geometry for
                                         * border gadgets
                                         */
#define SPA_GADGETGEOMETRY  0x00000800  /* Plugin exports geometry for
                                         * normal gadgets
                                         */


/***********************************/
/*** The geometry hook interface ***/
/***********************************/

/* The different types of messages that a geometry hook can see */

#define SG_IMAGEBOX  901  /* Compute box for this (sysiclass) image */
#define SG_GADGETBOX 902  /* Compute box for this gadget            */

/* Possible return values from a geometry hook */

#define GCB_OK      0  /* Hook understands this message type    */
#define GCB_UNKNOWN 1  /* Hook does not understand this message */

/* Structure of SG_ messages for geometry hooks: object is a      */
/* struct Image * or a struct Gadget * according to message type. */
/* The hook must calculate position and size for the specified    */
/* object and store them into the appropriate IBox structures in  */
/* the message body. Do NOT change the object directly!           */
/* For images, igm_ImageBox represents the extent of the whole    */
/* image while igm_RenderBox is the area where actual rendering   */
/* will occur (useful for inner button imagery, for instance).    */
/* For gadgets, ggm_HitBox and ggm_BoundingBox are (as you might  */
/* have guessed) the hit box and the bounding box.                */

struct ImageGeometryMsg
{
    ULONG            igm_MethodID;   /* One of the SG_ definitions above  */
    struct RastPort *igm_RastPort;   /* Reference RastPort (for the font) */
    struct DrawInfo *igm_DrawInfo;   /* Context information               */
    struct IBox      igm_ImageBox;   /* (Output) Box computed by the hook */
    struct IBox      igm_RenderBox;  /* (Output) Box computed by the hook */
    ULONG            igm_Reserved;   /* Reserved for future use           */
    ULONG            igm_Flags;      /* More information                  */
};

/* Values for igm_Flags */

#define IGF_WBARLEFT   0x00000001 /* Image for left side of window titlebar  */
#define IGF_WBARRIGHT  0x00000002 /* Image for right side of window titlebar */
#define IGF_SBARLEFT   0x00000004 /* Image for left side of screen titlebar  */
#define IGF_SBARRIGHT  0x00000008 /* Image for right side of screen titlebar */
#define IGF_VERTARROW  0x00000010 /* Image for right window border           */
#define IGF_HORIZARROW 0x00000020 /* Image for bottom window border          */
#define IGF_BRCORN     0x00000040 /* Image for bottom-right window corner    */
#define IGF_KEEPLEFT   0x00001000 /* Use the supplied igm_ImageBox.Left      */
#define IGF_KEEPTOP    0x00002000 /* Use the supplied igm_ImageBox.Top       */
#define IGF_KEEPWIDTH  0x00004000 /* Use the supplied igm_ImageBox.Width     */
#define IGF_KEEPHEIGHT 0x00008000 /* Use the supplied igm_ImageBox.Height    */

struct GadgetGeometryMsg
{
    ULONG            ggm_MethodID;     /* One of the SG_ definitions above  */
    struct Window   *ggm_Window;       /* Reference window (may be NULL)    */
    struct DrawInfo *ggm_DrawInfo;     /* Context information               */
    struct IBox      ggm_BoundingBox;  /* (Output) Box computed by the hook */
    struct IBox      ggm_HitBox;       /* (Output) Box computed by the hook */
    APTR             ggm_IAddress;     /* Gadget-specific data (see below)  */
    ULONG            ggm_Flags;        /* More information                  */
};

/* Values for ggm_Flags */

#define GGF_INITIAL       0x00000001 /* We are at OpenWindow() time */
#define GGF_CALCHSCROLLER 0x00000002 /* Compute scroller hit box from
                                      * bounding box
                                      */
#define GGF_CALCVSCROLLER 0x00000004 /* Compute scroller hit box from
                                      * bounding box
                                      */
#define GGF_CALCHSOVERLAP 0x00000008 /* Compute scroller/button overlap
                                      * (in borders)
                                      */
#define GGF_CALCVSOVERLAP 0x00000010 /* Compute scroller/button overlap
                                      * (in borders)
                                      */
#define GGF_BOUNDED       0x00000020 /* Container size is passed in
                                      * ggm_BoundingBox
                                      */

/* Specific data for GTYP_TBARGADGET gadgets (pointed to by ggm_IAddress) */
/*                                                                        */
/* The geometry hook will use this information to determine the correct   */
/* position of the gadget passed as object. Both the gadgets already in   */
/* the window (or screen) and those in the separate list (which always    */
/* contains at least the object itself) contribute to the calculation.    */
/* For this kind of gadgets the geometry hook shouldn't depend on the     */
/* ggm_Window address, since it could be invoked in situations where no   */
/* window information is available and therefore the address is NULL.     */
/* New for V51: if GGF_BOUNDED is set in ggm_Flags, your hook can read a  */
/* "nominal" window size (or screen titlebar size, for GTYP_SCRGADGET     */
/* gadgets) from ggm_BoundingBox. Note that the hook is still expected to */
/* initialize ggm_BoundingBox after having read that initial information! */

struct TBGadgetData
{
   struct Gadget *DomainGadgetList;  /* Gadgets already attached to
                                      * window/screen
                                      * Note: this may be NULL
                                      */
   struct Gadget *GadgetGadgetList;  /* The gadget list containing the gadget
                                      * we receive as object
                                      * (this cannot be NULL)
                                      */
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

#endif /* INTUITION_SYSICLASS_H */
