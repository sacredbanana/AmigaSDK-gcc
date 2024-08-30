#ifndef INTUITION_EXTENSIONS_H
#define INTUITION_EXTENSIONS_H

/*
	intuition v50 definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_DIATTR_H
#include <intuition/diattr.h>
#endif

#ifndef INTUITION_SCREENS_H
#include <intuition/screens.h>
#endif

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef INTUITION_POINTERCLASS_H
#include <intuition/pointerclass.h>
#endif

#pragma pack(2)


/* new SYSIA_Which values (added some padding there) */

#define ICONIFYIMAGE    (0x12L)
#define LOCKIMAGE       (0x13L)
#define MUIIMAGE        (0x14L)
#define POPUPIMAGE      (0x15L)
#define SNAPSHOTIMAGE   (0x16L)
#define JUMPIMAGE       (0x17L)
#define MENUTOGGLEIMAGE (0x19L)
#define SUBMENUIMAGE    (0x1AL)


/* Flags for ExtraTitlebarGadgets!!! */
#define ETG_ICONIFY             (0x1L)  /* MUI iconify gadget */
#define ETG_LOCK                (0x2L)  /* lock gadget from Magellan */
#define ETG_MUI                 (0x4L)  /* MUI prefs gadget */
#define ETG_POPUP               (0x8L)  /* popup menu gadget */
#define ETG_SNAPSHOT            (0x10L) /* MUI snapshot gadget */
#define ETG_JUMP                (0x20L) /* MUI screen jump gadget */

/* Extra gadget ID's */
#define ETI_Dummy               (0xFFD0)/* you can change this base with WA_ExtraGadgetsStartID! */
#define ETI_Iconify             (ETI_Dummy)
#define ETI_Lock                (ETI_Dummy + 1)
#define ETI_MUI                 (ETI_Dummy + 2)
#define ETI_PopUp               (ETI_Dummy + 3)
#define ETI_Snapshot            (ETI_Dummy + 4)
#define ETI_Jump                (ETI_Dummy + 5)

/* for use with custom ETI_Dummy base... */
#define ETD_Iconify             0
#define ETD_Lock                1
#define ETD_MUI                 2
#define ETD_PopUp               3
#define ETD_Snapshot            4
#define ETD_Jump                5

/* GetSkinInfo defines */

#define SI_Dummy                (0x8000000)

/* Window border size */
#define SI_BorderTop            (SI_Dummy + 1)
#define SI_BorderTopTitle       (SI_Dummy + 2) /* when you want a window with title/titlebar gadgets */
#define SI_BorderLeft           (SI_Dummy + 3)
#define SI_BorderRight          (SI_Dummy + 4) /* std size of window border */
#define SI_BorderRightSize      (SI_Dummy + 5) /* border with size gadgets */
#define SI_BorderBottom         (SI_Dummy + 6)
#define SI_BorderBottomSize     (SI_Dummy + 7)
#define SI_ScreenTitlebarHeight (SI_Dummy + 8) /* real height of screen titlebar (no need to add 1 pixel there!)
											   ** please use this instead of reading from struct Screen
											   ** do note that this returns 0 for invisible or disappearing
											   ** titlebars so it may not be what you need */

/* Titlebar gadgets positions/sizes */
#define SI_RightPropWidth       (SI_Dummy + 10)
#define SI_BottomPropHeight     (SI_Dummy + 11)
#define SI_RightArrowBox        (SI_Dummy + 12) /* space used by arrows on right titlebar */
#define SI_BottomArrowBox       (SI_Dummy + 13)

/* Other Information */
#define SI_Shadows              (SI_Dummy + 14) /* returns TRUE if the skin supports window shadows */



/* window action methods, see the autodoc for detailed descriptions */

#define WAC_DUMMY                       (0x0001)
#define WAC_HIDEWINDOW                  (WAC_DUMMY)
#define WAC_SHOWWINDOW                  (WAC_DUMMY + 1)
#define WAC_SENDIDCMPCLOSE              (WAC_DUMMY + 2)
#define WAC_MOVEWINDOW                  (WAC_DUMMY + 3)
#define WAC_SIZEWINDOW                  (WAC_DUMMY + 4)
#define WAC_CHANGEWINDOWBOX             (WAC_DUMMY + 5)
#define WAC_WINDOWTOFRONT               (WAC_DUMMY + 6)
#define WAC_WINDOWTOBACK                (WAC_DUMMY + 7)
#define WAC_ZIPWINDOW                   (WAC_DUMMY + 8)
#define WAC_MOVEWINDOWINFRONTOF         (WAC_DUMMY + 9)
#define WAC_ACTIVATEWINDOW              (WAC_DUMMY + 10)
/* V51 */
#define WAC_MAXIMIZEWINDOW              (WAC_DUMMY + 11)
#define WAC_MINIMIZEWINDOW              (WAC_DUMMY + 12)
#define WAC_RESTOREINITIALSIZEPOS       (WAC_DUMMY + 13)
#define WAC_OPENMENU                    (WAC_DUMMY + 14)
#define WAC_FAMILYTOFRONT               (WAC_DUMMY + 15)
#define WAC_FAMILYTOBACK                (WAC_DUMMY + 16)

/* window action tags */

#define WAT_DUMMY                       TAG_USER
#define WAT_MOVEWINDOWX                 (WAT_DUMMY + 1)
#define WAT_MOVEWINDOWY                 (WAT_DUMMY + 2)
#define WAT_SIZEWINDOWX                 (WAT_DUMMY + 3)
#define WAT_SIZEWINDOWY                 (WAT_DUMMY + 4)
#define WAT_WINDOWBOXLEFT               (WAT_DUMMY + 5)
#define WAT_WINDOWBOXTOP                (WAT_DUMMY + 6)
#define WAT_WINDOWBOXWIDTH              (WAT_DUMMY + 7)
#define WAT_WINDOWBOXHEIGHT             (WAT_DUMMY + 8)
#define WAT_MOVEWBEHINDWINDOW           (WAT_DUMMY + 9)

/* window transparency */

struct TransparencyMessage
{
	struct Layer          *Layer;      /* the layer you're asked to provide transparency for */
	struct Region         *Region;     /* create transparency in this region */
	struct Rectangle      *NewBounds;  /* current layer boundaries */
	struct Rectangle      *OldBounds;  /* old layer boundaries, useful after layer resize */
};

/* TransparencyControl tags and methods */
#define TRANSPCONTROLMETHOD_INSTALLREGION         0x1
/* Installs a new region, requires that you pass TRANSPCONTROL_REGION in tags. Setting this tag
** to NULL or not passing it at all removes currently installed. Passing TRANSPCONTROL_OLDREGION
** will write old region address to storagePtr passed in tag->ti_Data. Installing a region removes
** regionhook!
*/

#define TRANSPCONTROLMETHOD_INSTALLREGIONHOOK     0x2
/* Similar to TRANSPCONTROLMETHOD_INSTALLREGION */

#define TRANSPCONTROLMETHOD_UPDATETRANSPARENCY    0x3
/* Calls your transparency hook to allow you to change the transparency whenever you want.
** This has no effect with transparency region installed.
*/

#define TRANSPCONTROL_DUMMY            TAG_USER
#define TRANSPCONTROL_REGION           (TRANSPCONTROL_DUMMY + 1)
#define TRANSPCONTROL_REGIONHOOK       (TRANSPCONTROL_DUMMY + 2)
#define TRANSPCONTROL_OLDREGION        (TRANSPCONTROL_DUMMY + 3)
#define TRANSPCONTROL_OLDREGIONHOOK    (TRANSPCONTROL_DUMMY + 4)

/* requester extensions */
/* please pass this structure to EasyRequestArgs or BuildEasyRequest
** Note that the extended structure is recognised by es_StructSize field!
** You MUST set it to sizeof(struct ExtEasyStruct) in order to use the tag
** field, setting size to NULL or sizeof(struct EasyStruct) disables the use
** of this extension!
**
** please also note that no logos are displayed on CLUT screens (<=8 bitplanes)
*/

struct ExtEasyStruct
{
	ULONG  es_StructSize;
	ULONG  es_Flags;
	UBYTE *es_Title;
	UBYTE *es_TextFormat;
	UBYTE *es_GadgetFormat;
	struct TagItem *es_Tags;
};

#define EES_Dummy             TAG_USER
#define EES_ActiveButton      (EES_Dummy + 1) /* the button which will be hilighted when requester pops up, uses 1,2,..,n,0 numbering! */
#define EES_DosLogo           (EES_Dummy + 2)
#define EES_DiskBased         (EES_Dummy + 3) /* if TRUE, the requesters may use diskbased components. if FALSE, no I/O will be done when displaying the requester. defaults to TRUE */

#define DOSLOGO_DISKINSERT          1
#define DOSLOGO_DISKNOTVALIDATED    2
#define DOSLOGO_DISKPROTECTED       3
#define DOSLOGO_DISKFULL            4
#define DOSLOGO_NOTADOSDISK         5
#define DOSLOGO_NODISK              6
#define DOSLOGO_DISKBUSY            7
#define DOSLOGO_DISKERROR           8
#define LOGO_CRASH                  9

/* GetMonitorList tags */

#define GMLA_Dummy                        (TAG_USER + 0x4000)

/* ULONG, finds the monitor related to the given display ID, only the
** monitor(s) matching the provided DisplayIDs will be added to the list */
#define GMLA_DisplayID                    (GMLA_Dummy + 1)

#pragma pack()

#endif /* INTUITION_EXTENSIONS_H */
