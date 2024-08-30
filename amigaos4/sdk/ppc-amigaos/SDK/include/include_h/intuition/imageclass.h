#ifndef INTUITION_IMAGECLASS_H
#define INTUITION_IMAGECLASS_H
/*
**    $VER: imageclass.h 54.16 (22.08.2022)
**
**    definitions for the system image classes
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/******************************************************/

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
 * NOTE:  <intuition/iobsolete.h> is included at the END of this file!
 */

#define CUSTOMIMAGEDEPTH (-1)
/* if image.Depth is this, it's a new Image class object */

/* some convenient macros and casts */
#define GADGET_BOX( g ) ( (struct IBox *) &((struct Gadget *)(g))->LeftEdge )
#define IM_BOX( im )    ( (struct IBox *) &((struct Image *)(im))->LeftEdge )
#define IM_FGPEN( im )  ( (im)->PlanePick )
#define IM_BGPEN( im )  ( (im)->PlaneOnOff )

/******************************************************/
#define IA_Dummy            (TAG_USER + 0x20000)
#define IA_Left             (IA_Dummy + 0x01)
#define IA_Top              (IA_Dummy + 0x02)
#define IA_Width            (IA_Dummy + 0x03)
#define IA_Height           (IA_Dummy + 0x04)
#define IA_FGPen            (IA_Dummy + 0x05)
            /* IA_FGPen also means "PlanePick" */
#define IA_BGPen            (IA_Dummy + 0x06)
            /* IA_BGPen also means "PlaneOnOff" */
#define IA_Data             (IA_Dummy + 0x07)
            /* bitplanes, for classic image,
             * other image classes may use it for other things
             */
#define IA_LineWidth        (IA_Dummy + 0x08)
#define IA_Pens             (IA_Dummy + 0x0E)
            /* pointer to UWORD pens[],
             * ala DrawInfo.Pens, MUST be
             * terminated by ~0.  Some classes can
             * choose to have this, or SYSIA_DrawInfo,
             * or both.
             */
#define IA_Resolution       (IA_Dummy + 0x0F)
            /* packed uwords for x/y resolution into a longword
             * ala DrawInfo.Resolution
             */

/**** see class documentation to learn which *****/
/**** classes recognize these                *****/
#define IA_APattern         (IA_Dummy + 0x10)
#define IA_APatSize         (IA_Dummy + 0x11)
#define IA_Mode             (IA_Dummy + 0x12)
#define IA_Font             (IA_Dummy + 0x13)
#define IA_Outline          (IA_Dummy + 0x14)
#define IA_Recessed         (IA_Dummy + 0x15)
#define IA_DoubleEmboss     (IA_Dummy + 0x16)
#define IA_EdgesOnly        (IA_Dummy + 0x17)

/**** "sysiclass" attributes                 *****/
#define SYSIA_Size          (IA_Dummy + 0x0B)
            /* #define's below */
#define SYSIA_Depth         (IA_Dummy + 0x0C)
            /* this is unused by Intuition.  SYSIA_DrawInfo
             * is used instead for V36
             */
#define SYSIA_Which         (IA_Dummy + 0x0D)
            /* see #define's below */
#define SYSIA_DrawInfo      (IA_Dummy + 0x18)
            /* pass to sysiclass, please */

/***** obsolete: don't use these, use IA_Pens *****/
#define SYSIA_Pens          IA_Pens
#define IA_ShadowPen        (IA_Dummy + 0x09)
#define IA_HighlightPen     (IA_Dummy + 0x0A)

/* New for V39: */
#define SYSIA_ReferenceFont (IA_Dummy + 0x19)
            /* Font to use as reference for scaling
             * certain sysiclass images
             */
#define IA_SupportsDisable  (IA_Dummy + 0x1a)
            /* By default, Intuition ghosts gadgets itself,
             * instead of relying on IDS_DISABLED or
             * IDS_SELECTEDDISABLED.  An imageclass that
             * supports these states should return this attribute
             * as TRUE.  You cannot set or clear this attribute,
             * however.
             */

#define IA_FrameType        (IA_Dummy + 0x1b)
            /* Starting with V39, FrameIClass recognizes
             * several standard types of frame.  Use one
             * of the FRAME_ specifiers below.    Defaults
             * to FRAME_DEFAULT.
             */

#define IA_Underscore       (IA_Dummy + 0x1c)
            /* V44, Indicate underscore keyboard shortcut for image labels.
             * (UBYTE) Defaults to '_'
             */

#define IA_Scalable         (IA_Dummy + 0x1d)
            /* V44, Attribute indicates this image is allowed
             * to/can scale its rendering.
             * (BOOL) Defaults to FALSE.
             */

#define IA_ActivateKey      (IA_Dummy + 0x1e)
            /* (STRPTR) Get the image shortcut key(s).
             * Defaults to NULL. (V44)
             */

#define IA_Screen           (IA_Dummy + 0x1f)
            /* V44 Screen pointer, may be useful/required by certain classes.
             * (struct Screen *)
             */

#define IA_Precision        (IA_Dummy + 0x20)
            /* V44 Precision value, typically pen precision but may be
             * used for similar custom purposes.
             * (ULONG)
             */

/* New for V50: */
#define SYSIA_FullFrame     (IA_Dummy + 0x21)
            /* Specifies whether the sysiclass image must have an
             * inner frame, if the current style normally has one.
             * This is useful only with TBFRAMEIMAGE images.
             * Set this to FALSE to get an image suitable as
             * background for text, or TRUE if you want a normal
             * titlebar gadget image which you can add graphic
             * contents to. Defaults to FALSE. (V50)
             */
#define SYSIA_ContentsBox   (IA_Dummy + 0x22)
            /* Read-only attribute: pass a (struct IBox *) to
             * inquire about the position and size of the inner
             * area of a TBFRAMEIMAGE image, in order to bound
             * your custom imagery inside that area and avoid
             * overwriting the image's borders. (V50)
             */
#define IA_Orientation      (IA_Dummy + 0x23)
            /* Defines orientation, for images needing this kind
             * of information, such as the PROPKNOB frameiclass
             * type or gaugeiclass. As of V50, the values can be
             * 0 (horizontal) or 1 (vertical). Defaults to 0. (V50)
             */
#define IA_Simple           (IA_Dummy + 0x24)
            /* This boolean attribute indicates whether the image
             * should be drawn with the most plain graphic
             * appearance it supports. For frameiclass, this means
             * to drop fancy styles like XEN or rounded corners.
             * Defaults to FALSE (user-selected style). (V50)
             */
#define SYSIA_VectorInfo    (IA_Dummy + 0x25)
            /* Custom vector definition for a sysiclass image. (V50)
             */
#define SYSIA_RenderHook    (IA_Dummy + 0x26)
            /* Custom rendering hook for a sysiclass image. (V50)
             */
#define SYSIA_BitMapCache   (IA_Dummy + 0x27)
            /* Level of bitmap caching for sysiclass images (0 = none,
             * 1 = deferred, 2 = immediate). Defaults to 2. (V50)
             */
#define IA_Label            (IA_Dummy + 0x28)
#define SYSIA_Label         IA_Label
            /* Pointer to a string to be used as the image's text
             * label, if it supports one. (V50)
             */
#define IA_BackFill         (IA_Dummy + 0x29)
#define IA_SelectedBackFill (IA_Dummy + 0x2A)
#define IA_DisabledBackFill (IA_Dummy + 0x2B)
#define IA_InactiveBackFill (IA_Dummy + 0x2C)
            /* Pointer to a backfill hook the image can use to fill
             * its background, if it supports this attribute. (V50)
             */
#define IA_EraseBackground  (IA_Dummy + 0x2D)
            /* Erase the background before rendering the image?
             * Defaults to TRUE for images having a non-rectangular
             * or anti-aliased shape, FALSE otherwise. (V51)
             */
#define IA_InBorder         (IA_Dummy + 0x2E)
            /* Is this image to be drawn inside a window border?
             * Defaults to FALSE. (V51)
             */
/**** "gaugeiclass" attributes               *****/
#define GAUGEIA_Min         (IA_Dummy + 0x2F)
            /* Minimum level of a gaugeiclass image. (V51)
             */
#define GAUGEIA_Max         (IA_Dummy + 0x30)
            /* Maximum level of a gaugeiclass image. (V51)
             */
#define GAUGEIA_Level       (IA_Dummy + 0x31)
            /* Current level of a gaugeiclass image. (V51)
             */
#define GAUGEIA_Ticks       (IA_Dummy + 0x32)
            /* Number of tick marks to be drawn for a gaugeiclass
             * image. Defaults to 0 (no tick marks). (V51)
             */
#define GAUGEIA_TickSize    (IA_Dummy + 0x33)
            /* Length of tick marks for a gaugeiclass image, if
             * they are present. Defaults to 4. (V51)
             */
#define GAUGEIA_ShortTicks  (IA_Dummy + 0x34)
            /* Should half-length tick marks be drawn in-between
             * the normal tick marks of a gaugeiclass image?
             * Defaults to FALSE. (V51)
                     */
#define GAUGEIA_InnerTicks  (IA_Dummy + 0x35)
            /* Should tick marks be drawn inside the gauge,
             * rather than alongside it? Defaults to FALSE. (V51)
             */
#define GAUGEIA_ScaleHook   (IA_Dummy + 0x36)
            /* Custom hook for calculating the size of the filled
             * part of the gauge, relative to the container's size;
             * object is the image, message is a pointer to an
             * array of 3 uint32s. The scale hook must calculate
             * (number[0] * number[1]) / number[2] and return the
             * result, or zero if it can't perform the calculation.
             * Passing NULL means an internal scaling routine will
             * be used. Defaults to NULL. (V51)
             */
#define IA_Justification    (IA_Dummy + 0x37)
            /* Justification of the image's text label, if it
             * supports one. Use one of the IJ_ constants below.
             * Defaults to IJ_LEFT, unless otherwise specified
             * in the documentation for the image class. (V51)
             */
#define IA_LabelPen         (IA_Dummy + 0x38)
            /* Color of the image's text label, if it supports one.
             * Defaults to the TEXTPEN color. (V51)
             */
/** next attribute:         (IA_Dummy + 0x39) **/
/***********************************************/

/* data values for SYSIA_Size */
#define SYSISIZE_MEDRES (0)
#define SYSISIZE_LOWRES (1)
#define SYSISIZE_HIRES  (2)

/*
 * SYSIA_Which tag data values:
 * Specifies which system gadget you want an image for.
 * Some numbers correspond to internal Intuition #defines
 */
#define DEPTHIMAGE     (0x00L) /* Window depth gadget image */
#define ZOOMIMAGE      (0x01L) /* Window zoom gadget image */
#define SIZEIMAGE      (0x02L) /* Window sizing gadget image */
#define CLOSEIMAGE     (0x03L) /* Window close gadget image */
#define SDEPTHIMAGE    (0x05L) /* Screen depth gadget image */
#define LEFTIMAGE      (0x0AL) /* Window left-arrow gadget image */
#define UPIMAGE        (0x0BL) /* Window up-arrow gadget image */
#define RIGHTIMAGE     (0x0CL) /* Window right-arrow gadget image */
#define DOWNIMAGE      (0x0DL) /* Window down-arrow gadget image */
#define CHECKIMAGE     (0x0EL) /* GT/RA checkbox image */
#define MXIMAGE        (0x0FL) /* GT/RA mutual exclude "button" image */
#define MENUCHECK      (0x10L) /* Menu checkmark image (V39) */
#define AMIGAKEY       (0x11L) /* Menu Amiga-key image (V39) */
#define SBARLOGO       (0x12L) /* Screen titlebar logo (V50) */
#define POPUPIMAGE     (0x13L) /* Window pop-up gadget image (V50) */
#define SETTINGSIMAGE  (0x14L) /* Window settings gadget image (V50) */
#define SNAPSHOTIMAGE  (0x15L) /* Window snapshot gadget image (V50) */
#define ICONIFYIMAGE   (0x16L) /* Window iconify gadget image (V50) */
#define PADLOCKIMAGE   (0x17L) /* Window padlock gadget image (V50) */
#define TBFRAMEIMAGE   (0x18L) /* Window titlebar frame image (V50) */
#define HKHANDLEIMAGE  (0x19L) /* Window horizontal knob handle symbol (V50) */
#define VKHANDLEIMAGE  (0x1AL) /* Window vertical knob handle symbol (V50) */
#define MENUMX         (0x1BL) /* Menu mutualexclude image (V50) */
#define MENUSUB        (0x1CL) /* Menu sub-panel indicator (V50) */
#define CYCLEIMAGE     (0x1DL) /* GT/RA cycle symbol (V50) */
#define CHECKMARKIMAGE (0x1EL) /* GT/RA checkmark symbol (V50) */
#define GLEFTIMAGE     (0x1FL) /* GT/RA left-arrow symbol (V50) */
#define GUPIMAGE       (0x20L) /* GT/RA up-arrow symbol (V50) */
#define GRIGHTIMAGE    (0x21L) /* GT/RA right-arrow symbol (V50) */
#define GDOWNIMAGE     (0x22L) /* GT/RA down-arrow symbol (V50) */
#define GHKHANDLEIMAGE (0x23L) /* GT/RA horizontal knob handle symbol (V50) */
#define GVKHANDLEIMAGE (0x24L) /* GT/RA vertical knob handle symbol (V50) */
#define SCLOSEIMAGE    (0x25L) /* Screen close gadget image (V51) */
#define SCREENSIMAGE   (0x26L) /* Window screen-jump gadget image (V51) */
#define SORTASCIMAGE   (0x27L) /* Sort ascending image (V53.25) */
#define SORTDESIMAGE   (0x28L) /* Sort descending image (V53.25) */
#define TABCLOSEIMAGE  (0x29L) /* Tab close image (V54.27) */

/* Additional system image types recognized by DrawSysImageA()
 */
#define SI_HPROPBACKGROUND 0x1001 /* Background of horizontal scroller (V50) */
#define SI_VPROPBACKGROUND 0x1002 /* Background of vertical scroller (V50) */

/* Data values for IA_FrameType (recognized by FrameIClass)
 *
 * FRAME_DEFAULT:  The standard V37-type frame, which has
 *    thin edges.
 * FRAME_BUTTON:  Standard button gadget frames, having thicker
 *    sides and nicely edged corners.
 * FRAME_RIDGE:  A ridge such as used by standard string gadgets.
 *    You can recess the ridge to get a groove image.
 * FRAME_ICONDROPBOX: A broad ridge which is the standard imagery
 *    for areas in AppWindows where icons may be dropped.
 * FRAME_PROPBORDER: A frame suitable for use as border of a
 *    proportional gadget container. (V50)
 * FRAME_PROPKNOB: A frame suitable for use as knob of a
 *    proportional gadget. (V50)
 * FRAME_DISPLAY: A recessed frame for display elements, such as
 *    read-only text or number gadgets. (V50)
 */

#define FRAME_DEFAULT     0
#define FRAME_BUTTON      1
#define FRAME_RIDGE       2
#define FRAME_ICONDROPBOX 3
#define FRAME_PROPBORDER  4
#define FRAME_PROPKNOB    5
#define FRAME_DISPLAY     6

/* IA_Justification tag data values */

#define IJ_LEFT   0
#define IJ_CENTER 1
#define IJ_RIGHT  2


/* image message id's */
#define IM_DRAW        0x202L /* draw yourself, with "state" */
#define IM_HITTEST     0x203L /* return TRUE if click hits image */
#define IM_ERASE       0x204L /* erase yourself */
#define IM_MOVE        0x205L /* draw new and erase old, smoothly */

#define IM_DRAWFRAME   0x206L /* draw with specified dimensions */
#define IM_FRAMEBOX    0x207L /* get recommended frame around some box */
#define IM_HITFRAME    0x208L /* hittest with dimensions */
#define IM_ERASEFRAME  0x209L /* erase with dimensions */

#define IM_DOMAINFRAME 0x20AL /* query image for its domain info (V44) */

#define IM_EXTENT      0x20BL /* inquire about rendering extent (V51) */
#define IM_EXTENTFRAME 0x20CL /* as IM_EXTENT, with dimensions (V51) */

/* image draw states or styles, for IM_DRAW */
/* Note that they have no bitwise meanings (unfortunately) */
#define IDS_NORMAL           (0L)
#define IDS_SELECTED         (1L) /* for selected gadgets */
#define IDS_DISABLED         (2L) /* for disabled gadgets */
#define IDS_BUSY             (3L) /* for future functionality */
#define IDS_INDETERMINATE    (4L) /* for future functionality */
#define IDS_INACTIVENORMAL   (5L) /* normal, in inactive window border */
#define IDS_INACTIVESELECTED (6L) /* selected, in inactive border */
#define IDS_INACTIVEDISABLED (7L) /* disabled, in inactive border */
#define IDS_SELECTEDDISABLED (8L) /* disabled and selected */

/* oops, please forgive spelling error by jimm */
#define IDS_INDETERMINANT IDS_INDETERMINATE

/* IM_FRAMEBOX    */
struct impFrameBox
{
    ULONG            MethodID;
    struct IBox     *imp_ContentsBox; /* input: relative box of contents */
    struct IBox     *imp_FrameBox;    /* output: rel. box of encl frame  */
    struct DrawInfo *imp_DrInfo;      /* NB: May be NULL */
    ULONG            imp_FrameFlags;
};

#define FRAMEF_SPECIFY (1<<0) /* Make do with the dimensions of FrameBox
                               * provided.
                               */

/* IM_DRAW, IM_DRAWFRAME */
struct impDraw
{
    ULONG            MethodID;
    struct RastPort *imp_RPort;
    struct
    {
        WORD X;
        WORD Y;
    }                imp_Offset;

    ULONG            imp_State;
    struct DrawInfo *imp_DrInfo; /* NB: May be NULL */

    /* these parameters only valid for IM_DRAWFRAME */
    struct
    {
        WORD Width;
        WORD Height;
    }                imp_Dimensions;
};

/* IM_ERASE, IM_ERASEFRAME */
/* NOTE: This is a subset of impDraw */
struct impErase
{
    ULONG            MethodID;
    struct RastPort *imp_RPort;
    struct
    {
        WORD X;
        WORD Y;
    }                imp_Offset;

    /* these parameters only valid for IM_ERASEFRAME */
    struct
    {
        WORD Width;
        WORD Height;
    }                imp_Dimensions;
};

/* IM_HITTEST, IM_HITFRAME */
struct impHitTest
{
    ULONG MethodID;
    struct
    {
        WORD X;
        WORD Y;
    }     imp_Point;

    /* these parameters only valid for IM_HITFRAME */
    struct
    {
        WORD Width;
        WORD Height;
    }     imp_Dimensions;
};


/* The IM_DOMAINFRAME method is used to obtain the sizing
 * requirements of an image object within a layout group.
 */

/* IM_DOMAINFRAME */
struct impDomainFrame
{
    ULONG            MethodID;
    struct DrawInfo *imp_DrInfo; /* DrawInfo */
    struct RastPort *imp_RPort;  /* RastPort to layout for */
    LONG             imp_Which;  /* what size - min/nominal/max */
    struct IBox      imp_Domain; /* Resulting domain */
    struct TagItem  *imp_Attrs;  /* Additional attributes */
};

/* Accepted vales for imp_Which.
 */
#ifndef IDOMAIN_MINIMUM
#define IDOMAIN_MINIMUM (0)
#define IDOMAIN_NOMINAL (1)
#define IDOMAIN_MAXIMUM (2)
#endif


/* The IM_EXTENT/IM_EXTENTFRAME method is used to ask the
 * image what pixels or areas (at least) it will fully
 * overwrite in its IM_DRAW/IM_DRAWFRAME method.
 *
 * See the description of gadgetclass/GM_EXTENT for more
 * detailed information about this topic.
 */

/* IM_EXTENT, IM_EXTENTFRAME */
struct impExtent
{
    ULONG            MethodID;
    struct DrawInfo *imp_DrInfo; /* May be NULL */
    struct RastPort *imp_RPort;  /* NULL if masking not supported */
    struct Region   *imp_Region; /* NULL if clipping not supported */
    ULONG            imp_Action; /* Requested operation */
    ULONG            imp_Flags;  /* Control flags, see below */
    struct TagItem  *imp_Attrs;  /* Additional attributes */
    ULONG            imp_State;  /* Rendering state */
    struct IBox      imp_Frame;  /* Sizes only valid for IM_EXTENTFRAME */
};

/* Possible operations requested by IM_EXTENT/IM_EXTENTFRAME
 */
#define IEXTENT_REMOVE (0) /* You should CLEAR shapes from region/mask */
#define IEXTENT_ADD    (1) /* You should OR shapes into region/mask */
#define IEXTENT_INVERT (2) /* You should XOR shapes into region/mask */
#define IEXTENT_SECT   (3) /* You should AND shapes into region/mask */

/* Control flags defined for IM_EXTENT/IM_EXTENTFRAME
 */
#define IMPF_ALLOWSUPER (0x01) /* Allow superclass to handle the method */

/* Possible return codes for IM_EXTENT/IM_EXTENTFRAME
 */
#define IMR_INVALID  (0x00) /* Couldn't provide any information */
#define IMR_CLIPDONE (0x40) /* Added to the region all areas I fully cover */
#define IMR_MASKDONE (0x80) /* Wrote into the mask all pixels I fully cover */

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

/* Include obsolete identifiers: */
#ifndef   INTUITION_IOBSOLETE_H
#include <intuition/iobsolete.h>
#endif

#endif
