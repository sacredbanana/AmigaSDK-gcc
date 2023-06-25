#ifndef INTUITION_GADGETCLASS_H
#define INTUITION_GADGETCLASS_H
/*
**    $VER: gadgetclass.h 54.16 (22.08.2022)
**
**    Custom and 'boopsi' gadget class interface
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*****************************************************************************/

/* NOTE:  <intuition/iobsolete.h> is included at the END of this file! */

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

/* Gadget class attributes */
#define GA_Dummy            (TAG_USER+0x30000)

#define GA_Left             (GA_Dummy+1)
    /* (LONG) Left edge of the gadget relative to the left edge of
     * the window */

#define GA_RelRight         (GA_Dummy+2)
    /* (LONG) Left edge of the gadget relative to the right edge of
     * the window */

#define GA_Top              (GA_Dummy+3)
    /* (LONG) Top edge of the gadget relative to the top edge of
     * the window */

#define GA_RelBottom        (GA_Dummy+4)
    /* (LONG) Top edge of the gadget relative to the bottom edge
     * of the window */

#define GA_Width            (GA_Dummy+5)
    /* (LONG) Width of the gadget */

#define GA_RelWidth         (GA_Dummy+6)
    /* (LONG) Width of the gadget relative to the width of the
     * window */

#define GA_Height           (GA_Dummy+7)
    /* (LONG) Height of the gadget */

#define GA_RelHeight        (GA_Dummy+8)
    /* (LONG) Height of the gadget relative to the height of
     * the window */

#define GA_Text             (GA_Dummy+9)
    /* (STRPTR) Gadget imagry is NULL terminated string */

#define GA_Image            (GA_Dummy+10)
    /* (struct Image *) Gadget imagry is an image */

#define GA_Border           (GA_Dummy+11)
    /* (struct Border *) Gadget imagry is a border */

#define GA_SelectRender     (GA_Dummy+12)
    /* (struct Image *) Selected gadget imagry */

#define GA_Highlight        (GA_Dummy+13)
    /* (UWORD) One of GFLG_GADGHNONE, GFLG_GADGHBOX, GFLG_GADGHCOMP,
     * or GFLG_GADGHIMAGE */

#define GA_Disabled         (GA_Dummy+14)
    /* (BOOL) Indicate whether gadget is disabled or not.
     * Defaults to FALSE. */

#define GA_GZZGadget        (GA_Dummy+15)
    /* (BOOL) Indicate whether the gadget is for
     * WFLG_GIMMEZEROZERO window borders or not.  Defaults
     * to FALSE. */

#define GA_ID               (GA_Dummy+16)
    /* (UWORD) Gadget ID assigned by the application */

#define GA_UserData         (GA_Dummy+17)
    /* (APTR) Application specific data */

#define GA_SpecialInfo      (GA_Dummy+18)
    /* (APTR) Gadget specific data */

#define GA_Selected         (GA_Dummy+19)
    /* (BOOL) Indicate whether the gadget is selected or not.
     * Defaults to FALSE */

#define GA_EndGadget        (GA_Dummy+20)
    /* (BOOL) When set tells the system that when this gadget
     * is selected causes the requester that it is in to be
     * ended.  Defaults to FALSE. */

#define GA_Immediate        (GA_Dummy+21)
    /* (BOOL) When set indicates that the gadget is to
     * notify the application when it becomes active.  Defaults
     * to FALSE. */

#define GA_RelVerify        (GA_Dummy+22)
    /* (BOOL) When set indicates that the application wants to
     * verify that the pointer was still over the gadget when
     * the select button is released.  Defaults to FALSE. */

#define GA_FollowMouse      (GA_Dummy+23)
    /* (BOOL) When set indicates that the application wants to
     * be notified of mouse movements while the gadget is active.
     * It is recommmended that GA_Immediate and GA_RelVerify are
     * also used so that the active gadget can be tracked by the
     * application.  Defaults to FALSE. */

#define GA_RightBorder      (GA_Dummy+24)
    /* (BOOL) Indicate whether the gadget is in the right border
     * or not.  Defaults to FALSE. */

#define GA_LeftBorder       (GA_Dummy+25)
    /* (BOOL) Indicate whether the gadget is in the left border
     * or not.  Defaults to FALSE. */

#define GA_TopBorder        (GA_Dummy+26)
    /* (BOOL) Indicate whether the gadget is in the top border
     * or not.  Defaults to FALSE. */

#define GA_BottomBorder     (GA_Dummy+27)
    /* (BOOL) Indicate whether the gadget is in the bottom border
     * or not.  Defaults to FALSE. */

#define GA_ToggleSelect     (GA_Dummy+28)
    /* (BOOL) Indicate whether the gadget is toggle-selected
     * or not.  Defaults to FALSE. */

#define GA_SysGadget        (GA_Dummy+29)
    /* (BOOL) Reserved for system use to indicate that the
     * gadget belongs to the system.  Defaults to FALSE. */

#define GA_SysGType         (GA_Dummy+30)
    /* (UWORD) Reserved for system use to indicate the
     * gadget type. */

#define GA_Previous         (GA_Dummy+31)
    /* (struct Gadget *) Previous gadget in the linked list.
     * NOTE: This attribute CANNOT be used to link new gadgets
     * into the gadget list of an open window or requester.
     * You must use AddGList(). */

#define GA_Next             (GA_Dummy+32)
    /* (struct Gadget *) Next gadget in the linked list. */

#define GA_DrawInfo         (GA_Dummy+33)
    /* (struct DrawInfo *) Some gadgets need a DrawInfo at creation time */

/* You should use at most ONE of GA_Text, GA_IntuiText, and GA_LabelImage */
#define GA_IntuiText        (GA_Dummy+34)
    /* (struct IntuiText *) Label is an IntuiText. */

#define GA_LabelImage       (GA_Dummy+35)
    /* (Object *) Label is an image object. */

#define GA_TabCycle         (GA_Dummy+36)
    /* (BOOL) Indicate whether gadget is part of TAB/SHIFT-TAB cycle
     * activation.  Defaults to FALSE.  New for V37. */

#define GA_GadgetHelp       (GA_Dummy+37)
    /* (BOOL) Indicate whether gadget is to send IDCMP_GADGETHELP.
     * Defaults to FALSE.  New for V39. */

#define GA_Bounds           (GA_Dummy+38)
    /* (struct IBox *) Copied into the extended gadget's bounds.
     * New for V39. */

#define GA_RelSpecial       (GA_Dummy+39)
    /* (BOOL) Indicate whether gadget has special relativity.  Defaults to
     * FALSE.  New for V39. */

#define GA_TextAttr         (GA_Dummy+40)
    /* (struct TextAttr *) Indicate the font to use for the gadget.
     * New for V42. */

#define GA_ReadOnly         (GA_Dummy+41)
    /* (BOOL) Indicate that the gadget is read-only (non-selectable).
     * Defaults to FALSE. New for V42. */

#define GA_Underscore       (GA_Dummy+42)
    /* (UBYTE) Underscore/escape character for keyboard shortcuts.
     * Defaults to '_' . New for V44. */

#define GA_ActivateKey      (GA_Dummy+43)
    /* (STRPTR) Set/Get the gadgets shortcut/activation key(s)
     * Defaults to NULL. New for V44. */

#define GA_BackFill         (GA_Dummy+44)
    /* (struct Hook *) Backfill pattern hook.
     * Defaults to NULL. New for V44. */

#define GA_GadgetHelpText   (GA_Dummy+45)
    /* (STRPTR) **RESERVED/PRIVATE DO NOT USE**
     * Defaults to NULL. New for V44. */

#define GA_UserInput        (GA_Dummy+46)
    /* (BOOL) Notification tag indicates this notification is from the active
     * gadget receiving user input - an attempt to make IDCMPUPDATE more
     * efficient.
     * Defaults to FALSE. New for V44. */

#define GA_DoLayout         (GA_Dummy+51)
    /* (BOOL) Set this to TRUE if the gadget should recompute its
     * position and size when it receives a GM_LAYOUT message. For
     * gadgets which are part of a layout group this attribute
     * should be FALSE; the layout takes care of placing and sizing
     * its members and the resulting geometry must not be changed.
     * The default is usually FALSE for ReAction gadgets, while for
     * others it is defined on a class-by-class basis. New for V50. */

#define GA_NoFilterMenuKeys (GA_Dummy+52)
    /* (BOOL) Corresponds to GMORE_NOFILTERMENUKEYS. New for V50. */

#define GA_Titlebar         (GA_Dummy+53)
    /* (BOOL) Set this to TRUE if you want the gadget to be automatically
     * positioned by Intuition in the window titlebar (at the left or at
     * the right side, depending on the state of GFLG_RELRIGHT). The layout
     * is done according to the current style and geometry settings for
     * window border gadgets. Please use an appropriate sysiclass instance
     * as imagery for a titlebar gadget, such as ICONIFYIMAGE or TBFRAMEIMAGE.
     * Note: This property implies { GA_TopBorder, TRUE }. New for V50. */

#define GA_Hidden           (GA_Dummy+54)
    /* (BOOL) Corresponds to GMORE_HIDDEN. New for V50. */

#define GA_NoFilterWheel    (GA_Dummy+55)
    /* (BOOL) Corresponds to GMORE_NOFILTERWHEEL. New for V51. */

#define GA_HintInfo         (GA_Dummy+56)
    /* (CONST_STRPTR) The default HintInfo string for this gadget.
     * See window.class documentation for more information. New for V53. */

#define GA_ContextMenu      (GA_Dummy+57)
    /* (APTR) The default context menu for this gadget. It can be either a
     * traditional menu or a BOOPSI menu tree from menuclass. New for V54. */

#define GA_Reserved1        (GA_Dummy+60)
    /* Reserved for future extension, do not use. */

#define GA_Reserved2        (GA_Dummy+61)
    /* Reserved for future extension, do not use. */

/*****************************************************************************/

/* PROPGCLASS attributes */
#define PGA_Dummy      (TAG_USER+0x31000)
#define PGA_Freedom    (PGA_Dummy+0x0001)
     /* only one of FREEVERT or FREEHORIZ */
#define PGA_Borderless (PGA_Dummy+0x0002)
#define PGA_HorizPot   (PGA_Dummy+0x0003)
#define PGA_HorizBody  (PGA_Dummy+0x0004)
#define PGA_VertPot    (PGA_Dummy+0x0005)
#define PGA_VertBody   (PGA_Dummy+0x0006)
#define PGA_Total      (PGA_Dummy+0x0007)
#define PGA_Visible    (PGA_Dummy+0x0008)
#define PGA_Top        (PGA_Dummy+0x0009)
/* New for V37: */
#define PGA_NewLook    (PGA_Dummy+0x000A)
/* New for V50: scrollergclass attributes */
#define PGA_ArrowDelta (PGA_Dummy+0x000B)
#define PGA_ArrowDown  (PGA_Dummy+0x000C)

/*****************************************************************************/

/* STRGCLASS attributes */
#define STRINGA_Dummy          (TAG_USER     +0x32000)
#define STRINGA_MaxChars       (STRINGA_Dummy+0x0001)
/* Note:  There is a minor problem with Intuition when using boopsi integer
 * gadgets (which are requested by using STRINGA_LongVal).  Such gadgets
 * must not have a STRINGA_MaxChars to be bigger than 15.  Setting
 * STRINGA_MaxChars for a boopsi integer gadget will cause a mismatched
 * FreeMem() to occur.
 */

#define STRINGA_Buffer         (STRINGA_Dummy+0x0002)
#define STRINGA_UndoBuffer     (STRINGA_Dummy+0x0003)
#define STRINGA_WorkBuffer     (STRINGA_Dummy+0x0004)
#define STRINGA_BufferPos      (STRINGA_Dummy+0x0005)
#define STRINGA_DispPos        (STRINGA_Dummy+0x0006)
#define STRINGA_AltKeyMap      (STRINGA_Dummy+0x0007)
#define STRINGA_Font           (STRINGA_Dummy+0x0008)
#define STRINGA_Pens           (STRINGA_Dummy+0x0009)
#define STRINGA_ActivePens     (STRINGA_Dummy+0x000A)
#define STRINGA_EditHook       (STRINGA_Dummy+0x000B)
#define STRINGA_EditModes      (STRINGA_Dummy+0x000C)

/* booleans */
#define STRINGA_ReplaceMode    (STRINGA_Dummy+0x000D)
#define STRINGA_FixedFieldMode (STRINGA_Dummy+0x000E)
#define STRINGA_NoFilterMode   (STRINGA_Dummy+0x000F)

#define STRINGA_Justification  (STRINGA_Dummy+0x0010)
    /* GACT_STRINGCENTER, GACT_STRINGLEFT, GACT_STRINGRIGHT */
#define STRINGA_LongVal        (STRINGA_Dummy+0x0011)
#define STRINGA_TextVal        (STRINGA_Dummy+0x0012)

#define STRINGA_ExitHelp       (STRINGA_Dummy+0x0013)
    /* STRINGA_ExitHelp is new for V37, and ignored by V36.
     * Set this if you want the gadget to exit when Help is
     * pressed.  Look for a code of 0x5F, the rawkey code for Help */

#define STRINGA_MarkedBlock    (STRINGA_Dummy+0x0014)
    /* Sets/gets the marked block of a string.gadget. The hi-word
     * contains the start position (first marked char) and the
     * lo-word the end position (last marked char).  If both are
     * -1 nothing is marked.  (V50).
     */

#define SG_DEFAULTMAXCHARS (128)

/*****************************************************************************/

/* Gadget layout related attributes */
#define LAYOUTA_Dummy          (TAG_USER+0x38000)
#define LAYOUTA_LayoutObj      (LAYOUTA_Dummy+0x0001)
#define LAYOUTA_Spacing        (LAYOUTA_Dummy+0x0002)
#define LAYOUTA_Orientation    (LAYOUTA_Dummy+0x0003)

#define LAYOUTA_ChildMaxWidth  (LAYOUTA_Dummy+0x0004)
    /* (BOOL) Child objects are of equal width.  Should default to TRUE for
     * gadgets with a horizontal orientation.  New for V42. */
#define LAYOUTA_ChildMaxHeight (LAYOUTA_Dummy+0x0005)
    /* (BOOL) Child objects are of equal height.  Should default to TRUE for
     * gadgets with a vertical orientation.  New for V42. */

/* orientation values */
#define LORIENT_NONE  0
#define LORIENT_HORIZ 1
#define LORIENT_VERT  2

/*****************************************************************************/

/* Gadget Method ID's */
#define GM_Dummy         (-1)
    /* Not used for anything */

#define GM_HITTEST       (0)
    /* Return GMR_GADGETHIT if you are clicked on (whether or not you
     * are disabled). */

#define GM_RENDER        (1)
    /* Draw yourself, in the appropriate state */

#define GM_GOACTIVE      (2)
    /* You are now going to be fed input */

#define GM_HANDLEINPUT   (3)
    /* Handle that input */

#define GM_GOINACTIVE    (4)
    /* Whether or not by choice, you are done */

#define GM_HELPTEST      (5)
    /* Will you send gadget help if the mouse is at the specified coordinates?
     * See below for possible GMR_ values. */

#define GM_LAYOUT        (6)
    /* Re-evaluate your size based on the GadgetInfo domain.
     * Do NOT re-render yourself yet, you will be called when it is
     * time... */

#define GM_DOMAIN        (7)
    /* Used to obtain the sizing requirements of an object.  Does not
     * require an object. */

#define GM_KEYTEST       (8)
    /* Return GMR_GADGETHIT if your activation key matches
     * (whether or not you are disabled). */

#define GM_KEYGOACTIVE   (9)
    /* You are now going to be fed raw key events. (V53) */

#define GM_KEYGOINACTIVE (10)
    /* You are done receiving raw key events. (V53) */

#define GM_PRERENDER     (11)
    /* New for V50. Private */

#define GM_POSTRENDER    (12)
    /* New for V50. Private */

#define GM_EXTENT        (13)
    /* Let Intuition know what pixels your GM_RENDER method will fill. (V51) */

#define GM_HANDLESCROLL  (14)
    /* Handle a mouse wheel event. (V52) */

#define GM_QUERY         (15)
    /* You're being queried about some special information. (V53) */

#define GM_MENUPICK      (16)
    /* The user selected an item from your context menu. (V54) */

#define GM_MENUHELP      (17)
    /* The user asked for help on an item from your context menu. (V54) */

/*****************************************************************************/

/* Parameter "Messages" passed to gadget class methods    */

/* GM_HITTEST and GM_HELPTEST send this message.
 * For GM_HITTEST, gpht_Mouse are coordinates relative to the gadget
 * select box.  For GM_HELPTEST, the coordinates are relative to
 * the gadget bounding box (which defaults to the select box).
 */
struct gpHitTest
{
    ULONG              MethodID;
    struct GadgetInfo *gpht_GInfo;
    struct
    {
        int16 X;
        int16 Y;
    }                  gpht_Mouse;
};

/* For GM_HITTEST, return GMR_GADGETHIT if you were indeed hit,
 * otherwise return zero.
 *
 * For GM_HELPTEST, return GMR_NOHELPHIT (zero) if you were not hit.
 * Typically, return GMR_HELPHIT if you were hit.
 * It is possible to pass a UWORD to the application via the Code field
 * of the IDCMP_GADGETHELP message.  Return GMR_HELPCODE or'd with
 * the UWORD-sized result you wish to return.
 *
 * GMR_HELPHIT yields a Code value of ((UWORD) ~0), which should
 * mean "nothing particular" to the application.
 */

#define GMR_GADGETHIT (0x00000004) /* GM_HITTEST hit */

#define GMR_NOHELPHIT (0x00000000) /* GM_HELPTEST didn't hit */
#define GMR_HELPHIT   (0xFFFFFFFF) /* GM_HELPTEST hit, return code = ~0 */
#define GMR_HELPCODE  (0x00010000) /* GM_HELPTEST hit,
                                         return low word as code */

/*****************************************************************************/

/* GM_RENDER */
struct gpRender
{
    ULONG              MethodID;
    struct GadgetInfo *gpr_GInfo;  /* gadget context              */
    struct RastPort   *gpr_RPort;  /* all ready for use           */
    LONG               gpr_Redraw; /* might be a "highlight pass" */
};

/* values of gpr_Redraw */
#define GREDRAW_UPDATE (2) /* incremental update, e.g. prop slider */
#define GREDRAW_REDRAW (1) /* redraw gadget                        */
#define GREDRAW_TOGGLE (0) /* toggle highlight, if applicable      */

/*****************************************************************************/

/* GM_GOACTIVE, GM_HANDLEINPUT, GM_HANDLESCROLL */
struct gpInput
{
    ULONG              MethodID;
    struct GadgetInfo *gpi_GInfo;
    struct InputEvent *gpi_IEvent;
    LONG              *gpi_Termination;
    struct
    {
        int16 X;
        int16 Y;
    }                  gpi_Mouse;

    /* (V39) Pointer to TabletData structure, if this event originated
     * from a tablet which sends IESUBCLASS_NEWTABLET events, or NULL if
     * not.
     *
     * DO NOT ATTEMPT TO READ THIS FIELD UNDER INTUITION PRIOR TO V39!
     * IT WILL BE INVALID!
     */
    struct TabletData *gpi_TabletData;
};

/* GM_GOACTIVE, GM_HANDLEINPUT and GM_HANDLESCROLL return code flags */
/* return GMR_MEACTIVE (0) alone if you want more input.
 * Otherwise, return ONE of GMR_NOREUSE and GMR_REUSE, and optionally
 * GMR_VERIFY.
 */
#define GMR_MEACTIVE   (0)
#define GMR_NOREUSE    (1 << 1)
#define GMR_REUSE      (1 << 2)
#define GMR_VERIFY     (1 << 3) /* you MUST set gpi_Termination */

/* New for V37:
 * You can end activation with one of GMR_NEXTACTIVE and GMR_PREVACTIVE,
 * which instructs Intuition to activate the next or previous gadget
 * that has GFLG_TABCYCLE set.
 */
#define GMR_NEXTACTIVE (1 << 4)
#define GMR_PREVACTIVE (1 << 5)

/*****************************************************************************/

/* GM_GOINACTIVE */
struct gpGoInactive
{
    ULONG              MethodID;
    struct GadgetInfo *gpgi_GInfo;

    /* V37 field only!  DO NOT attempt to read under V36! */
    ULONG              gpgi_Abort; /* gpgi_Abort=1 if gadget was aborted
                                    * by Intuition and 0 if gadget went
                                    * inactive at its own request
                                    */
};

/*****************************************************************************/

/* New for V39: Intuition sends GM_LAYOUT to any GREL_ gadget when
 * the gadget is added to the window (or when the window opens, if
 * the gadget was part of the NewWindow.FirstGadget or the WA_Gadgets
 * list), or when the window is resized.  Your gadget can set the
 * GA_RelSpecial property to get GM_LAYOUT events without Intuition
 * changing the interpretation of your gadget select box.  This
 * allows for completely arbitrary resizing/repositioning based on
 * window size.
 */
/* GM_LAYOUT */
struct gpLayout
{
    ULONG              MethodID;
    struct GadgetInfo *gpl_GInfo;
    ULONG              gpl_Initial; /* non-zero if this method was invoked
                                     * during AddGList() or OpenWindow()
                                     * time.  zero if this method was invoked
                                     * during window resizing.
                                     */
};

/*****************************************************************************/

/* The GM_DOMAIN method is used to obtain the sizing requirements of an
 * object for a class before ever creating an object. */

/* GM_DOMAIN */
struct gpDomain
{
    ULONG              MethodID;
    struct GadgetInfo *gpd_GInfo;
    struct RastPort   *gpd_RPort;  /* RastPort to layout for */
    LONG               gpd_Which;
    struct IBox        gpd_Domain; /* Resulting domain */
    struct TagItem    *gpd_Attrs;  /* Additional attributes */
};

#define GDOMAIN_MINIMUM (0) /* Minimum size */
#define GDOMAIN_NOMINAL (1) /* Nominal size */
#define GDOMAIN_MAXIMUM (2) /* Maximum size */


/*****************************************************************************/

/* The GM_KEYTEST method is used to determine if a key press matches an
 * object's activation key(s). The default method will search keys
 * set via GA_ActivateKey.
 */

/* GM_KEYTEST */
struct gpKeyTest
{
    uint32               MethodID;
    struct GadgetInfo   *gpkt_GInfo;
    struct IntuiMessage *gpkt_IMsg;
    uint32               gpkt_VanillaKey;
};

/*****************************************************************************/

/* The GM_KEYGOACTIVE method is called to simulate a gadget going down.
 * A gadget should render itself in a selected state when receiving
 * this message. If the class supports this method it must return
 * GMR_KEYACTIVE.
 *
 * If a gadget returns GMR_KEYACTIVATE (zero) for this method, it will
 * subsequently be activated via ActivateGadget() with a NULL IEvent.
 */

/* GM_KEYGOACTIVE */
struct gpKeyInput
{
    uint32             MethodID;
    struct GadgetInfo *gpk_GInfo;
    struct InputEvent *gpk_IEvent;
    int32             *gpk_Termination;  /* Used with GMR_KEYVERIFY */
};

#define GMR_KEYACTIVATE (0x00000000) /* Throw away event and call
                                        ActivateGadget() (default) */
#define GMR_KEYACTIVE   (0x00000010) /* Method supported and send more
                                        key events */
#define GMR_KEYVERIFY   (0x00000020) /* Stop sending key events.
                                        You MUST set gpk_Termination. */

/* The GM_KEYGOINACTIVE method is called to simulate the gadget release.
 * Upon receiving this message the gadget should do everything a
 * normal gadget release would do. Must always return zero.
 */

/* GM_KEYGOINACTIVE */
struct gpKeyGoInactive
{
    uint32             MethodID;   /* GM_KEYGOINACTIVE */
    struct GadgetInfo *gpki_GInfo;
    uint32             gpki_Abort; /* TRUE if input was aborted */
};

/****************************************************************************/

/* New for V51: Intuition may send GM_EXTENT to a gadget to ask it what
 * pixels (at least) it will fully redraw when its GM_RENDER method is
 * invoked in the same context.
 * (By "fully redraw", we mean changing the pixel's color in a way that
 * is totally unrelated to its previous value -- so this doesn't apply
 * to alpha-blended pixels, for example.)
 *
 * Intuition uses that information for optimization purposes: during GUI
 * refreshes, it will skip filling or erasing those pixels that the gadget
 * would then completely re-render anyway.
 * Supporting this method in your gadgets will help Intuition improve the
 * smoothness of user interface refresh, by preventing redundant graphic
 * calls and minimizing "flicker" effects caused by background clearing,
 * especially during window resizes.
 *
 * The easiest way to support it is to make sure your gadget always fills
 * every pixel within its hit box or bounding box, and just return the
 * relevant (GMR_FULLHBOX or GMR_FULLBBOX) result value. In this case, you
 * may safely ignore the actual message contents (and the following text).
 *
 * If the above solution is not feasible (for instance because the gadget
 * has an irregular or not fully connected shape), then you should check
 * the gpe_Region and gpe_RPort message fields: if any of them is non-NULL
 * you may decide to employ a more detailed way to tell Intuition exactly
 * what pixels your GM_RENDER method does fill.
 *
 * If gpe_Region is non-NULL, you can compose in it your gadget's shape,
 * by using graphics.library's XxxxRectRegion() functions. Remember to
 * look at the gpe_Action field to determine what function to use: for
 * instance, if gpe_Action is GEXTENT_ADD, you should use OrRectRegion().
 * Note: you must NOT pre-clear or alter the initial region's contents
 * in any way, other than to compose your own gadget's shape!
 * Once finished composing your gadget's shape in the region, return
 * GMR_CLIPDONE to let Intuition know you updated the region's contents.
 *
 * If gpe_RPort is non-NULL, you can draw your gadget's shape into it,
 * just like you would do for a GM_RENDER message -- however, you're only
 * allowed to use colors 0 or 1, because you're actually drawing into a
 * single-bitplane mask. Again, check the gpe_Action field to find out
 * whether you should actually set, clear, or invert the pixels making up
 * your gadget's shape in the mask. Similarly to the previous case, you
 * are NOT allowed to alter any pixels other than those belonging to your
 * gadget's shape, nor to clear the mask's background before rendering.
 * Once finished drawing your gadget's shape in the mask plane, return
 * GMR_MASKDONE to let Intuition know you updated the mask's contents.
 *
 * (If both gpe_Region and gpe_RPort are non-NULL, you may simply choose
 * the method which is most suited for your purposes; you don't have to
 * support both for the same message! If you do, however, you can let
 * Intuition know by ORing together the appropriate return values.)
 *
 * It goes without saying that the region solution is best suited for
 * gadgets made up of a few rectangular parts, whereas the mask method
 * is better in the case of more complex gadget shapes.
 *
 * (Note: as of Intuition V51, the mask method is not yet implemented.)
 *
 * If all or part of your gadget's rendering is performed by some BOOPSI
 * image, you could also try asking the image for its extent information
 * by way of an IM_EXTENT or IM_EXTENTFRAME message (see imageclass.h).
 *
 * If for whatever reasons your GM_EXTENT method finds itself unable to
 * support any of the described solutions, it should return GMR_INVALID:
 * this particular return value will tell Intuition not to clip away the
 * gadget's shape at all. While this is usually slower and more prone to
 * flickering, it will still produce correct graphic results. This is of
 * course the same fallback applied for any gadgets not recognizing the
 * GM_EXTENT method.
 *
 * NOTE WELL:
 * Since it is very important that a gadget's GM_RENDER and GM_EXTENT
 * methods remain always synchronized, the default behavior of a gadget
 * class should be to only handle GM_EXTENT if it is the "true class"
 * of the object the method is invoked on, and just return GMR_INVALID
 * otherwise. This is because a subclass might override the behavior
 * of GM_RENDER in such a way that your class' GM_EXTENT results are
 * no longer correct. If a gadget subclass needs (and knows it's ok) to
 * let its superclass handle GM_EXTENT, it must set the GPEF_ALLOWSUPER
 * flag in gpe_Flags before calling IDoSuperMethodA() (and clear it as
 * soon as the call returns). If GPEF_ALLOWSUPER is set in gpe_Flags,
 * your gadget should accept and handle GM_EXTENT regardless of whether
 * it is the true class or not.
 */

/* GM_EXTENT */
struct gpExtent
{
   ULONG              MethodID;
   struct GadgetInfo *gpe_GInfo;
   struct RastPort   *gpe_RPort;  /* NULL if masking not supported */
   struct Region     *gpe_Region; /* NULL if clipping not supported */
   ULONG              gpe_Action; /* Requested operation */
   ULONG              gpe_Flags;  /* Control flags, see below */
   struct TagItem    *gpe_Attrs;  /* Additional attributes */
};

/* Possible operations requested by GM_EXTENT
 */
#define GEXTENT_REMOVE (0) /* You should CLEAR shapes from region/mask */
#define GEXTENT_ADD    (1) /* You should OR shapes into region/mask */
#define GEXTENT_INVERT (2) /* You should XOR shapes into region/mask */
#define GEXTENT_SECT   (3) /* You should AND shapes into region/mask */

/* Control flags defined for GM_EXTENT
 */
#define GPEF_ALLOWSUPER (0x00000001) /* Allow superclass to handle
                                      * the method
                                      */

/* Possible return codes for GM_EXTENT
 */
#define GMR_INVALID  (0x00000000) /* Couldn't provide any information */
#define GMR_FULLHBOX (0x00000010) /* I fill every pixel within my hit box */
#define GMR_FULLBBOX (0x00000020) /* I fill every pixel within
                                     my bounding box */
#define GMR_CLIPDONE (0x00000040) /* Added to the region all areas I fully
                                     redraw */
#define GMR_MASKDONE (0x00000080) /* Wrote into the mask all pixels I fully
                                     redraw */

/****************************************************************************/

/* The GM_QUERY method is new for V53, and is currently invoked by Intuition
 * and window.class. Gadget classes are not required to support this method,
 * but if they decide to, the currently supported queries are:
 *
 * GMQ_HINTINFO
 *   When a gadget receives this method, with gpq_Type set to this, it can
 *   return a string which will be shown as the hint info instead of the one
 *   specified by the array passed in by WINDOW_HintInfo, if any. This method
 *   is designed to be used instead of the GA_GadgetHelpText attribute, as
 *   OM_GET does not supply any positional data in order for the gadget to
 *   make the decision of which string to specify.
 *   For compatibility reasons, the target gadget must have a hintinfo defined
 *   in the array passed in from WINDOW_HintInfo at OM_NEW time. This method
 *   should be treated as a way to change the default, but if there is no
 *   default defined, it cannot be changed, and none will be displayed.
 *   SpeedBar and ClickTab gadget classes support this to allow separate
 *   hint info strings to be shown depending on the mouse pointer position
 *   within the gadget bounds. See the respective docs for further information.
 *
 * GMQ_WHICHMEMBER
 *   When a gadget receives this method, with gpq_Type set to this, it needs
 *   to handle it only if the gadget's class implements some kind of container
 *   or grouping object (e.g. layout.gadget). In this case, it should return
 *   the address of which one of its members (child gadgets) would be hit if a
 *   click were made at the specified coordinates, which are guaranteed to lie
 *   within the container's bounds.
 *   Implementation-wise, if any of the gadget's members overlaps the point
 *   specified in gpq_IEvent->ie_X/Y, the gadget should send the message to it
 *   and return whatever result it gets back. This recursive invocation allows
 *   the method to reach even child gadgets nested in sub-layouts.
 *   If the given coordinates lie outside all of the gadget's members, or if
 *   the gadget is not a container object to begin with, it should just pass
 *   back its own address, or even ignore the query by returning zero (which
 *   causes the gadget's own address to be taken as the query's result). (V54)
 *
 * GMQ_CONTEXTMENU
 *   When a gadget receives this method, with gpq_Type set to this, it can
 *   return a contextual menu which will then pop up under the mouse pointer.
 *   The context menu is essentially a menu strip which contains just one
 *   menu, having as many items and sub-items as desired. It can be either
 *   traditional or BOOPSI (built with menuclass).
 *   If no menu is returned by this method, Intuition will check if a context
 *   menu was attached to the gadget by the application via the GA_ContextMenu
 *   attribute, and use that one if this is the case. If that check fails
 *   as well, the normal window menu strip will be displayed as usual.
 *   Note that if a gadget class returns a valid menu through GM_QUERY, it
 *   should be prepared to handle menu selections by the user being fed back
 *   to it in the form of GM_MENUPICK or GM_MENUHELP messages. (V54)
 *
 * Custom gadget implementors should return GMR_NOREUSE if the method passes
 * back valid data, else zero to allow the default to be used.
 * The gpq_Data field should also be filled with the data being returned. This
 * is a general purpose data pointer in order to allow future query types to
 * use this same structure. The data pointer returned must be persistant for
 * the lifetime that it will be required, do not free the pointer until you
 * know it will no longer be referenced by the system.
 * Although this method does not invoke any rendering, the gpq_GInfo field is
 * always supplied by Intuition and gpq_IEvent supplies the positional data
 * in ie_X and ie_Y (these coordinates are relative to the upper left corner
 * of the layer the gadget lives in).
 */

/* GM_QUERY */
struct gpQuery
{
   ULONG              MethodID;   /* always GM_QUERY */
   struct GadgetInfo *gpq_GInfo;  /* filled in by Intuition */
   struct InputEvent *gpq_IEvent; /* positional data is here */
   ULONG              gpq_Type;   /* see below */
   LONG              *gpq_Data;   /* the data being returned */
};

/* values for gpq_Type */
#define GMQ_HINTINFO    (1)
#define GMQ_WHICHMEMBER (2)
#define GMQ_CONTEXTMENU (3)

/****************************************************************************/

/* New for V54: the GM_MENUPICK and GM_MENUHELP methods are used to let a
 * custom gadget hear context menu selections or help requests by the user.
 *
 * If the gadget supplied a valid context menu to Intuition when asked for
 * it with a GMQ_CONTEXTMENU query type in the GM_QUERY method, it must
 * then be ready to process user input from the menu via these two methods.
 *
 * Note that unlike most other input methods, GM_MENUPICK and GM_MENUHELP
 * are normally invoked on the context of the application rather than that
 * of input.device. This is because the gadget could need to carry out any
 * sort of complex actions in response to a context menu selection, even
 * involving disk I/O or high-level system calls that would be unfeasible
 * on the input.device task.
 *
 * For the same reason, these methods are never invoked under Intuition's
 * state machine (e.g. via DoGadgetMethod()), since that would make them
 * unable to call a number of Intuition functions without deadlocking.
 * A side effect of this is that GM_MENUPICK/GM_MENUHELP are always passed
 * a NULL GadgetInfo pointer, with the needed context information provided
 * instead by a pointer to the gadget's window (gpme_Window).
 * Implementors of these two methods should therefore use DoGadgetMethod()
 * themselves to invoke other gadget methods requiring a GadgetInfo.
 *
 * The address of the context menu that originated the event can be found
 * in the gpme_MenuAddress field of the message structure. The menu number
 * of the first item or sub-item that was picked by the user is stored in
 * the gpme_MenuNumber field; this number is the menu item's ID for BOOPSI
 * (menuclass) menus, and a traditional menu code for old-style menus.
 * If the method is GM_MENUPICK, there can be other items in the selection
 * chain in case the user performed multiple selection.
 *
 * For GM_MENUPICK, if the menu is BOOPSI, you can ignore gpme_MenuNumber
 * and simply read all item selections in sequence with MM_NEXTSELECT.
 *
 * GM_MENUHELP, on the other hand, is always triggered for a single menu
 * element, and there's no selection chain to follow. So, even for BOOPSI
 * menus, reading gpme_MenuNumber is the quickest way to find out which
 * item (or menu header) the user asked for help about. Alternatively, you
 * can always query the MA_MenuHelpID attribute of the context menu's root
 * object (pointed to by gpme_MenuAddress).
 *
 * The return value for these methods is currently ignored; set it to zero
 * for future compatibility.
 */

/* GM_MENUPICK, GM_MENUHELP */
struct gpMenuEvent
{
   ULONG              MethodID;
   struct GadgetInfo *gpme_GInfo;       /* Always NULL */
   APTR               gpme_MenuAddress; /* Originating context menu */
   ULONG              gpme_MenuNumber;  /* First item selected */
   struct Window     *gpme_Window;      /* The gadget's window */
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

/*****************************************************************************/

/* Include obsolete identifiers: */
#ifndef INTUITION_IOBSOLETE_H
#include <intuition/iobsolete.h>
#endif

/*****************************************************************************/

#endif
