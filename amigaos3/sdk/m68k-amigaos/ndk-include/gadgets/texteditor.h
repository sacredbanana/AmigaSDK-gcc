#ifndef GADGETS_TEXTEDITOR_H
#define GADGETS_TEXTEDITOR_H
/*
**	$VER: texteditor.h 47.54 (16.8.2021)
**
**	Definitions for texteditor.gadget BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#ifndef IMAGES_BEVEL_H
#include <images/bevel.h>
#endif

/*****************************************************************************/

#define   TEXTEDITOR_Dummy                 (REACTION_Dummy + 0x26000)

#define   GA_TEXTEDITOR_Contents           (TEXTEDITOR_Dummy + 0x02) /* the text */
#define   GA_TEXTEDITOR_CursorX            (TEXTEDITOR_Dummy + 0x04) /* position in block */
#define   GA_TEXTEDITOR_CursorY            (TEXTEDITOR_Dummy + 0x05) /* block number */
#define   GA_TEXTEDITOR_DoubleClickHook    (TEXTEDITOR_Dummy + 0x06)
#define   GA_TEXTEDITOR_ExportHook         (TEXTEDITOR_Dummy + 0x08)
#define   GA_TEXTEDITOR_ExportWrap         (TEXTEDITOR_Dummy + 0x09)
#define   GA_TEXTEDITOR_FixedFont          (TEXTEDITOR_Dummy + 0x0a)
#define   GA_TEXTEDITOR_Flow               (TEXTEDITOR_Dummy + 0x0b) /* justification, see values below - but broken ! */
#define   GA_TEXTEDITOR_HasChanged         (TEXTEDITOR_Dummy + 0x0c)
#define   GA_TEXTEDITOR_ImportHook         (TEXTEDITOR_Dummy + 0x0e)
#define   GA_TEXTEDITOR_ImportWrap         (TEXTEDITOR_Dummy + 0x10)
#define   GA_TEXTEDITOR_InsertMode         (TEXTEDITOR_Dummy + 0x0f) /* not implemented always true */
#define   GA_TEXTEDITOR_KeyBindings        (TEXTEDITOR_Dummy + 0x11)
#define   GA_TEXTEDITOR_NumLock            (TEXTEDITOR_Dummy + 0x18) /* not implemented */
#define   GA_TEXTEDITOR_PopWindow_Open     (TEXTEDITOR_Dummy + 0x03) /* Private!!! */
#define   GA_TEXTEDITOR_AreaMarked         (TEXTEDITOR_Dummy + 0x14)
#define   GA_TEXTEDITOR_Prop_DeltaFactor   (TEXTEDITOR_Dummy + 0x0d) /* obsolete is always 1 */
#define   GA_TEXTEDITOR_Prop_Entries       (TEXTEDITOR_Dummy + 0x15)
#define   GA_TEXTEDITOR_Prop_First         (TEXTEDITOR_Dummy + 0x20)
#define   GA_TEXTEDITOR_Prop_Release       (TEXTEDITOR_Dummy + 0x01) /* Private!!! */
#define   GA_TEXTEDITOR_Prop_Visible       (TEXTEDITOR_Dummy + 0x16)
#define   GA_TEXTEDITOR_Quiet              (TEXTEDITOR_Dummy + 0x17)
#define   GA_TEXTEDITOR_ReadOnly           (TEXTEDITOR_Dummy + 0x19)
#define   GA_TEXTEDITOR_RedoAvailable      (TEXTEDITOR_Dummy + 0x13)
#define   GA_TEXTEDITOR_Separator          (TEXTEDITOR_Dummy + 0x2c) /* see values below - but broken ! */
#define   GA_TEXTEDITOR_HorizontalScroll   (TEXTEDITOR_Dummy + 0x2d)
#define   GA_TEXTEDITOR_Pen                (TEXTEDITOR_Dummy + 0x2e) /* not implemented */
#define   GA_TEXTEDITOR_ColorMap           (TEXTEDITOR_Dummy + 0x2f) /* not implemented */
#define   GA_TEXTEDITOR_StyleBold          (TEXTEDITOR_Dummy + 0x1c) /* not implemented */
#define   GA_TEXTEDITOR_StyleItalic        (TEXTEDITOR_Dummy + 0x1d) /* not implemented */
#define   GA_TEXTEDITOR_StyleUnderline     (TEXTEDITOR_Dummy + 0x1e) /* not implemented */
#define   GA_TEXTEDITOR_TypeAndSpell       (TEXTEDITOR_Dummy + 0x07) /* obsolete - use a highlighterhook to accomplish */
#define   GA_TEXTEDITOR_UndoAvailable      (TEXTEDITOR_Dummy + 0x12)
#define   GA_TEXTEDITOR_WrapBorder         (TEXTEDITOR_Dummy + 0x21)
#define   GA_TEXTEDITOR_HProp_DeltaFactor  (TEXTEDITOR_Dummy + 0x30) /* obsolete is always 1 */
#define   GA_TEXTEDITOR_HProp_Entries      (TEXTEDITOR_Dummy + 0x31)
#define   GA_TEXTEDITOR_HProp_First        (TEXTEDITOR_Dummy + 0x32)
#define   GA_TEXTEDITOR_HProp_Visible      (TEXTEDITOR_Dummy + 0x33)
#define   GA_TEXTEDITOR_ExitHelp           (TEXTEDITOR_Dummy + 0x34)
#define   GA_TEXTEDITOR_TabSize            (TEXTEDITOR_Dummy + 0x35)
#define   GA_TEXTEDITOR_SpacesPerTAB       GA_TEXTEDITOR_TabSize
#define   GA_TEXTEDITOR_IndentWidth        (TEXTEDITOR_Dummy + 0x36)
#define   GA_TEXTEDITOR_HighlighterHook    (TEXTEDITOR_Dummy + 0x37)
#define   GA_TEXTEDITOR_ShowLineNumbers    (TEXTEDITOR_Dummy + 0x38)
#define   GA_TEXTEDITOR_LeftBarHook        (TEXTEDITOR_Dummy + 0x39)
#define   GA_TEXTEDITOR_RectangularSelections (TEXTEDITOR_Dummy + 0x3A)
/* Please note that OS4 defines the above 5 binary values with other meaning - yes we messed up */
#define   GA_TEXTEDITOR_ErrorCode          (TEXTEDITOR_Dummy + 0x36) /* OS4ONLY */
#define   GA_TEXTEDITOR_Keymap             (TEXTEDITOR_Dummy + 0x37) /* OS4ONLY */
#define   GA_TEXTEDITOR_CursorBlinkSpeed   (TEXTEDITOR_Dummy + 0x38) /* OS4ONLY */
/*#define   GA_TEXTEDITOR_AutoIndent         (TEXTEDITOR_Dummy + 0x39)  OS4ONLY */
#define   GA_TEXTEDITOR_Length             (TEXTEDITOR_Dummy + 0x3a) /* OS4ONLY */

#define   GA_TEXTEDITOR_AutoIndent         (TEXTEDITOR_Dummy + 0x3B) /* same name but different value to OS4 */
#define   GA_TEXTEDITOR_CutCopyLineWhenNoSelection (TEXTEDITOR_Dummy + 0x3C)
#define   GA_TEXTEDITOR_LineEndingImported (TEXTEDITOR_Dummy + 0x3D)
#define   GA_TEXTEDITOR_LineEndingExport   (TEXTEDITOR_Dummy + 0x3E)
#define   GA_TEXTEDITOR_TabKeyPolicy       (TEXTEDITOR_Dummy + 0x3F)
#define   GA_TEXTEDITOR_HorizScroller      (TEXTEDITOR_Dummy + 0x40) /* OS4ONLY */
#define   GA_TEXTEDITOR_VertScroller       (TEXTEDITOR_Dummy + 0x41) /* OS4ONLY */
#define   GA_TEXTEDITOR_TextAttr           (TEXTEDITOR_Dummy + 0x42) /* OS4ONLY */
#define   GA_TEXTEDITOR_TabToSpaces        (TEXTEDITOR_Dummy + 0x43) /* OS4ONLY */
#define   GA_TEXTEDITOR_Dragging           (TEXTEDITOR_Dummy + 0x44) /* OS4ONLY */
#define   GA_TEXTEDITOR_EOLMarker          (TEXTEDITOR_Dummy + 0x45) /* OS4ONLY */
#define   GA_TEXTEDITOR_LookAhead          (TEXTEDITOR_Dummy + 0x46) /* OS4ONLY */
#define   GA_TEXTEDITOR_BevelStyle         (TEXTEDITOR_Dummy + 0x47) /* OS4ONLY */
#define   GA_TEXTEDITOR_Transparent        (TEXTEDITOR_Dummy + 0x48) /* OS4ONLY */
#define   GA_TEXTEDITOR_MaxUndoLevels      (TEXTEDITOR_Dummy + 0x49) /* OS4ONLY */
#define   GA_TEXTEDITOR_MaxUndoSize        (TEXTEDITOR_Dummy + 0x4A) /* OS4ONLY */

#undef    TEXTEDITOR_Dummy
#define   TEXTEDITOR_Dummy   (0x45000)

#define   GM_TEXTEDITOR_HandleError        (TEXTEDITOR_Dummy + 0x1f)
#define   GM_TEXTEDITOR_AddKeyBindings     (TEXTEDITOR_Dummy + 0x22)
#define   GM_TEXTEDITOR_ARexxCmd           (TEXTEDITOR_Dummy + 0x23)
#define   GM_TEXTEDITOR_ClearText          (TEXTEDITOR_Dummy + 0x24)
#define   GM_TEXTEDITOR_ExportText         (TEXTEDITOR_Dummy + 0x25)
#define   GM_TEXTEDITOR_InsertText         (TEXTEDITOR_Dummy + 0x26)
#define   GM_TEXTEDITOR_MacroBegin         (TEXTEDITOR_Dummy + 0x27)
#define   GM_TEXTEDITOR_MacroEnd           (TEXTEDITOR_Dummy + 0x28)
#define   GM_TEXTEDITOR_MacroExecute       (TEXTEDITOR_Dummy + 0x29)
#define   GM_TEXTEDITOR_Replace            (TEXTEDITOR_Dummy + 0x2a)
#define   GM_TEXTEDITOR_Search             (TEXTEDITOR_Dummy + 0x2b)
#define   GM_TEXTEDITOR_MarkText           (TEXTEDITOR_Dummy + 0x2c)
#define   GM_TEXTEDITOR_BlockInfo          (TEXTEDITOR_Dummy + 0x30)
#define   GM_TEXTEDITOR_AddChangeListener  (TEXTEDITOR_Dummy + 0x31)
#define   GM_TEXTEDITOR_ExportBlock        (TEXTEDITOR_Dummy + 0x44) /* OS4ONLY */
#define   GM_TEXTEDITOR_ReplaceAll         (TEXTEDITOR_Dummy + 0x4B) /* OS4ONLY */

/* Register an instance of this to listen to changes
 * You must keep the structure and members valid as long as it is registered
 * You may add your own data following the structure.
 * It is safe to set function pointers to NULL
 */
struct ChangeListener
{
    void (*onCharsInserted)(struct ChangeListener *listener, ULONG startBlockNun, ULONG startPosInBlock,
                             ULONG endBlockNum, ULONG endPosInBlock);
    void (*onCharsDeleted)(struct ChangeListener *listener, ULONG startBlockNum, ULONG startPosInBlock,
                             ULONG endBlockNum, ULONG endPosInBlock);
    void (*onCharEntered)(struct ChangeListener *listener, ULONG character);
    ULONG Reserved1;
	ULONG Reserved2; /* all ReservedX members of this struct must be NULL */
	ULONG Reserved3;
    ULONG Reserved4;
    ULONG Reserved5;
};


struct    GP_TEXTEDITOR_ARexxCmd          { ULONG MethodID; struct GadgetInfo *GInfo; STRPTR command; };
struct    GP_TEXTEDITOR_BlockInfo         { ULONG MethodID; struct GadgetInfo *GInfo; ULONG *startx; ULONG *starty; ULONG *stopx; ULONG *stopy; };
struct    GP_TEXTEDITOR_ClearText         { ULONG MethodID; struct GadgetInfo *GInfo; };
struct    GP_TEXTEDITOR_ExportText        { ULONG MethodID; struct GadgetInfo *GInfo; };
struct    GP_TEXTEDITOR_HandleError       { ULONG MethodID; ULONG errorcode; }; /* See below for error codes */
struct    GP_TEXTEDITOR_InsertText        { ULONG MethodID; struct GadgetInfo *GInfo; STRPTR text; LONG pos; }; /* See below for positions */
struct    GP_TEXTEDITOR_MarkText          { ULONG MethodID; struct GadgetInfo *GInfo; ULONG start_crsr_x; ULONG start_crsr_y; ULONG stop_crsr_x; ULONG stop_crsr_y; };
struct    GP_TEXTEDITOR_Replace           { ULONG MethodID; struct GadgetInfo *GInfo; STRPTR newstring; ULONG flags; };
struct    GP_TEXTEDITOR_Search            { ULONG MethodID; struct GadgetInfo *GInfo; STRPTR string; ULONG flags; }; /* See below for flags */
struct    GP_TEXTEDITOR_AddChangeListener { ULONG MethodID; struct ChangeListener *listener; };
struct    GP_TEXTEDITOR_ReplaceAll        { ULONG MethodID; struct GadgetInfo *GInfo; STRPTR string; STRPTR newstring; ULONG flags; }; /* OS4ONLY */

#define   GV_TEXTEDITOR_ExportHook_Plain       0x00000000
#define   GV_TEXTEDITOR_ExportHook_EMail       0x00000001

#define   GV_TEXTEDITOR_Flow_Left              0x00000000
#define   GV_TEXTEDITOR_Flow_Center            0x00000001
#define   GV_TEXTEDITOR_Flow_Right             0x00000002
#define   GV_TEXTEDITOR_Flow_Justified         0x00000003

#define   GV_TEXTEDITOR_ImportHook_Plain       0x00000000
#define   GV_TEXTEDITOR_ImportHook_EMail       0x00000002
#define   GV_TEXTEDITOR_ImportHook_MIME        0x00000003
#define   GV_TEXTEDITOR_ImportHook_MIMEQuoted  0x00000004

#define   GV_TEXTEDITOR_InsertText_Cursor      0x00000000
#define   GV_TEXTEDITOR_InsertText_Top         0x00000001
#define   GV_TEXTEDITOR_InsertText_Bottom      0x00000002

#define   GV_TEXTEDITOR_LengthHook_Plain       0x00000000 /* OS4ONLY */
#define   GV_TEXTEDITOR_LengthHook_ANSI        0x00000001 /* OS4ONLY */
#define   GV_TEXTEDITOR_LengthHook_HTML        0x00000002 /* OS4ONLY */
#define   GV_TEXTEDITOR_LengthHook_MAIL        0x00000003 /* OS4ONLY */

#define   GV_TEXTEDITOR_TabKey_IndentsLine     0
#define   GV_TEXTEDITOR_TabKey_IndentsAfter    1

#define   GF_TEXTEDITOR_Search_FromTop         0x0001
#define   GF_TEXTEDITOR_Search_Next            0x0002
#define   GF_TEXTEDITOR_Search_Incremental     0x0003
#define   GF_TEXTEDITOR_Search_Backwards       0x0010
#define   GF_TEXTEDITOR_Highlight_All          0x0013
#define   GF_TEXTEDITOR_SearchType_Mask        0x0013 /* masks out the above 5 destinct values */
#define   GF_TEXTEDITOR_Search_CaseSensitive (1 << 2)
#define   GF_TEXTEDITOR_Search_DOSPattern    (1 << 3)
#define   GF_TEXTEDITOR_Search_Wildstar      (1 << 5)
#define   GF_TEXTEDITOR_Search_Word          (1 << 6)
#define   GF_TEXTEDITOR_Search_WholeWord     GF_TEXTEDITOR_Search_Word
#define   GF_TEXTEDITOR_Search_Cyclic        (1 << 7)

#define   GF_TEXTEDITOR_Replace_All         0x0001 /* Replace each of the hits from GF_TEXTEDITOR_Highlight_All */

/* Error codes given as argument to GM_TEXTEDITOR_HandleError */
#define   Error_ClipboardIsEmpty         0x01
#define   Error_ClipboardIsNotFTXT       0x02
#define   Error_MacroBufferIsFull        0x03
#define   Error_MemoryAllocationFailed   0x04
#define   Error_NoAreaMarked             0x05
#define   Error_NoMacroDefined           0x06
#define   Error_NothingToRedo            0x07
#define   Error_NothingToUndo            0x08
#define   Error_NotEnoughUndoMem         0x09 /* This will cause all the stored undos to be freed */
#define   Error_StringNotFound           0x0a
#define   Error_NoBookmarkInstalled      0x0b
#define   Error_BookmarkHasBeenLost      0x0c

struct ClickMessage
{
   STRPTR  LineContents;  /* This field is ReadOnly!!! */
   ULONG   ClickPosition;
};

struct HighlightMessage{
	ULONG Version;
	STRPTR Text;
	ULONG StatusOfPrevBlock;
};

/* Definitions for Setting styles when challanged by HighlightMessage to call
 * HighlightSetFormat */
#define TBSTYLE_UNDERLINE		0x0001
#define TBSTYLE_BOLD			0x0002
#define TBSTYLE_ITALIC			0x0004
#define TBSTYLE_SETCOLOR		0x0008
#define TBSTYLE_SPELLERROR		0x0040
#define TBSTYLE_COLORMASK		0xFF00
#define TBSTYLE_STYLEMASK		0x00FF
#define TBSTYLE_NOTSET			0xFF00

struct LeftBarRenderMessage
{
	UWORD Command; /* LEFTBAR_RENDERCOMMAND */
	UWORD Version; /* For now it is 0 */
	ULONG BlockNum; /* Starting from 0 on the first block of the document */
    ULONG LineSubNum; /* Starting from 0 on the first line of the block */
    struct RastPort *RastPort; /* The rastport to render into.
								* Careful it is possible to write outside - for now
								* Font is set and position points to topleft of area.
								* You have LeftBarWidth x TxHeight to render within.
								*/
};

struct LeftBarMouseMessage
{
	UWORD Command; /* LEFTBAR_MOUSECOMMAND */
	UWORD Version; /* For now it is 0 */
	ULONG BlockNum; /* Starting from 0 on the first block of the document */
	UWORD Code; /* copied from InputEvent */
	UWORD Qualifier; /* copied from InputEvent */
	WORD X;		/* mouse position relative to upper left corner of the leftbar area for this line */
	WORD Y;
	struct timeval TimeStamp; /* copied from InputEvent */
};


/* Definitions for the various messages above */
#define LEFTBAR_RENDERCOMMAND 0
#define LEFTBAR_MOUSECOMMAND 1

/* Definitions for Separator type */

#define LNSB_Top             0 /* Mutual exclude: */
#define LNSB_Middle          1 /* Placement of    */
#define LNSB_Bottom          2 /*  the separator  */
#define LNSB_StrikeThru      3 /* Let separator go thru the textfont */
#define LNSB_Thick           4 /* Extra thick separator */

#define LNSF_Top             (1<<LNSB_Top)
#define LNSF_Middle          (1<<LNSB_Middle)
#define LNSF_Bottom          (1<<LNSB_Bottom)
#define LNSF_StrikeThru      (1<<LNSB_StrikeThru)
#define LNSF_Thick           (1<<LNSB_Thick)

/* Definitions for GA_TEXTEDITOR_LineEndingImported and GA_TEXTEDITOR_LineEndingExport */
#define LINEENDING_LF       0
#define LINEENDING_CR       1
#define LINEENDING_CRLF     2
#define LINEENDING_ASIMPORT 3 /* only meaningful for GA_TEXTEDITOR_LineEndingExport*/

#endif /* GADGETS_TEXTEDITOR_H */
