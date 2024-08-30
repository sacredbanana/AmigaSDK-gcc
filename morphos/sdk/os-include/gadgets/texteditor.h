#ifndef GADGETS_TEXTEDITOR_H
#define GADGETS_TEXTEDITOR_H

/*
	texteditor.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#ifndef IMAGES_BEVEL_H
# include <images/bevel.h>
#endif

#pragma pack(2)


/* Attributes defined by texteditor.gadget */

#define TEXTEDITOR_Dummy                (REACTION_Dummy + 0x26000)

#define GA_TEXTEDITOR_AreaMarked        (TEXTEDITOR_Dummy + 0x14)
#define GA_TEXTEDITOR_ColorMap          (TEXTEDITOR_Dummy + 0x2F)
#define GA_TEXTEDITOR_Contents          (TEXTEDITOR_Dummy + 0x02)
#define GA_TEXTEDITOR_CursorX           (TEXTEDITOR_Dummy + 0x04)
#define GA_TEXTEDITOR_CursorY           (TEXTEDITOR_Dummy + 0x05)
#define GA_TEXTEDITOR_DoubleClickHook   (TEXTEDITOR_Dummy + 0x06)
#define GA_TEXTEDITOR_ExportHook        (TEXTEDITOR_Dummy + 0x08)
#define GA_TEXTEDITOR_ExportWrap        (TEXTEDITOR_Dummy + 0x09)
#define GA_TEXTEDITOR_FixedFont         (TEXTEDITOR_Dummy + 0x0A)
#define GA_TEXTEDITOR_Flow              (TEXTEDITOR_Dummy + 0x0B)
#define GA_TEXTEDITOR_HasChanged        (TEXTEDITOR_Dummy + 0x0C)
#define GA_TEXTEDITOR_HorizontalScroll  (TEXTEDITOR_Dummy + 0x2D)
#define GA_TEXTEDITOR_ImportHook        (TEXTEDITOR_Dummy + 0x0E)
#define GA_TEXTEDITOR_ImportWrap        (TEXTEDITOR_Dummy + 0x10)
#define GA_TEXTEDITOR_InsertMode        (TEXTEDITOR_Dummy + 0x0F)
#define GA_TEXTEDITOR_KeyBindings       (TEXTEDITOR_Dummy + 0x11)
#define GA_TEXTEDITOR_NumLock           (TEXTEDITOR_Dummy + 0x18)
#define GA_TEXTEDITOR_Pen               (TEXTEDITOR_Dummy + 0x2E)
#define GA_TEXTEDITOR_PopWindow_Open    (TEXTEDITOR_Dummy + 0x03)
#define GA_TEXTEDITOR_Prop_DeltaFactor  (TEXTEDITOR_Dummy + 0x0D)
#define GA_TEXTEDITOR_Prop_Entries      (TEXTEDITOR_Dummy + 0x15)
#define GA_TEXTEDITOR_Prop_First        (TEXTEDITOR_Dummy + 0x20)
#define GA_TEXTEDITOR_Prop_Release      (TEXTEDITOR_Dummy + 0x01)
#define GA_TEXTEDITOR_Prop_Visible      (TEXTEDITOR_Dummy + 0x16)
#define GA_TEXTEDITOR_Quiet             (TEXTEDITOR_Dummy + 0x17)
#define GA_TEXTEDITOR_ReadOnly          (TEXTEDITOR_Dummy + 0x19)
#define GA_TEXTEDITOR_RedoAvailable     (TEXTEDITOR_Dummy + 0x13)
#define GA_TEXTEDITOR_Separator         (TEXTEDITOR_Dummy + 0x2C)
#define GA_TEXTEDITOR_StyleBold         (TEXTEDITOR_Dummy + 0x1C)
#define GA_TEXTEDITOR_StyleItalic       (TEXTEDITOR_Dummy + 0x1D)
#define GA_TEXTEDITOR_StyleUnderline    (TEXTEDITOR_Dummy + 0x1E)
#define GA_TEXTEDITOR_TypeAndSpell      (TEXTEDITOR_Dummy + 0x07)
#define GA_TEXTEDITOR_UndoAvailable     (TEXTEDITOR_Dummy + 0x12)
#define GA_TEXTEDITOR_WrapBorder        (TEXTEDITOR_Dummy + 0x21)


#undef TEXTEDITOR_Dummy
#define TEXTEDITOR_Dummy                (0x45000)

#define GM_TEXTEDITOR_AddKeyBindings    (TEXTEDITOR_Dummy + 0x22)
#define GM_TEXTEDITOR_ARexxCmd          (TEXTEDITOR_Dummy + 0x23)
#define GM_TEXTEDITOR_BlockInfo         (TEXTEDITOR_Dummy + 0x30)
#define GM_TEXTEDITOR_ClearText         (TEXTEDITOR_Dummy + 0x24)
#define GM_TEXTEDITOR_ExportText        (TEXTEDITOR_Dummy + 0x25)
#define GM_TEXTEDITOR_HandleError       (TEXTEDITOR_Dummy + 0x1F)
#define GM_TEXTEDITOR_InsertText        (TEXTEDITOR_Dummy + 0x26)
#define GM_TEXTEDITOR_MacroBegin        (TEXTEDITOR_Dummy + 0x27)
#define GM_TEXTEDITOR_MacroEnd          (TEXTEDITOR_Dummy + 0x28)
#define GM_TEXTEDITOR_MacroExecute      (TEXTEDITOR_Dummy + 0x29)
#define GM_TEXTEDITOR_MarkText          (TEXTEDITOR_Dummy + 0x2C)
#define GM_TEXTEDITOR_Replace           (TEXTEDITOR_Dummy + 0x2A)
#define GM_TEXTEDITOR_Search            (TEXTEDITOR_Dummy + 0x2B)


struct GP_TEXTEDITOR_ARexxCmd
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	STRPTR             command;
};

struct GP_TEXTEDITOR_BlockInfo
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	ULONG             *startx;
	ULONG             *starty;
	ULONG             *stopx;
	ULONG             *stopy;
};

struct GP_TEXTEDITOR_ClearText
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
};

struct GP_TEXTEDITOR_ExportText
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
};

struct GP_TEXTEDITOR_HandleError
{
	ULONG MethodID;
	ULONG errorcode;
};

struct GP_TEXTEDITOR_InsertText
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	STRPTR             text;
	LONG               pos;
};

struct GP_TEXTEDITOR_MarkText
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	ULONG              start_crsr_x;
	ULONG              start_crsr_y;
	ULONG              stop_crsr_x;
	ULONG              stop_crsr_y;
};

struct GP_TEXTEDITOR_Replace
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	STRPTR             newstring;
	ULONG              flags;
};

struct GP_TEXTEDITOR_Search
{
	ULONG              MethodID;
	struct GadgetInfo *GInfo;
	STRPTR             string;
	ULONG              flags;
};


#define GV_TEXTEDITOR_ExportHook_Plain       0x00000000
#define GV_TEXTEDITOR_ExportHook_EMail       0x00000001

#define GV_TEXTEDITOR_Flow_Left              0x00000000
#define GV_TEXTEDITOR_Flow_Center            0x00000001
#define GV_TEXTEDITOR_Flow_Right             0x00000002
#define GV_TEXTEDITOR_Flow_Justified         0x00000003

#define GV_TEXTEDITOR_ImportHook_Plain       0x00000000
#define GV_TEXTEDITOR_ImportHook_EMail       0x00000002
#define GV_TEXTEDITOR_ImportHook_MIME        0x00000003
#define GV_TEXTEDITOR_ImportHook_MIMEQuoted  0x00000004

#define GV_TEXTEDITOR_InsertText_Cursor      0x00000000
#define GV_TEXTEDITOR_InsertText_Top         0x00000001
#define GV_TEXTEDITOR_InsertText_Bottom      0x00000002

#define GV_TEXTEDITOR_LengthHook_Plain       0x00000000
#define GV_TEXTEDITOR_LengthHook_ANSI        0x00000001
#define GV_TEXTEDITOR_LengthHook_HTML        0x00000002
#define GV_TEXTEDITOR_LengthHook_MAIL        0x00000003


#define GF_TEXTEDITOR_Search_FromTop        (1<<0)
#define GF_TEXTEDITOR_Search_Next           (1<<1)
#define GF_TEXTEDITOR_Search_CaseSensitive  (1<<2)
#define GF_TEXTEDITOR_Search_DOSPattern     (1<<3)
#define GF_TEXTEDITOR_Search_Backwards      (1<<4)


/* GM_TEXTEDITOR_HandleError values */

#define Error_ClipboardIsEmpty        0x01
#define Error_ClipboardIsNotFTXT      0x02
#define Error_MacroBufferIsFull       0x03
#define Error_MemoryAllocationFailed  0x04
#define Error_NoAreaMarked            0x05
#define Error_NoMacroDefined          0x06
#define Error_NothingToRedo           0x07
#define Error_NothingToUndo           0x08
#define Error_NotEnoughUndoMem        0x09
#define Error_StringNotFound          0x0A
#define Error_NoBookmarkInstalled     0x0B
#define Error_BookmarkHasBeenLost     0x0C


struct ClickMessage
{
	STRPTR LineContents;
	ULONG  ClickPosition;
};


/* Separator type */

#define LNSB_Top         0
#define LNSB_Middle      1
#define LNSB_Bottom      2
#define LNSB_StrikeThru  3
#define LNSB_Thick       4

#define LNSF_Top         (1<<LNSB_Top)
#define LNSF_Middle      (1<<LNSB_Middle)
#define LNSF_Bottom      (1<<LNSB_Bottom)
#define LNSF_StrikeThru  (1<<LNSB_StrikeThru)
#define LNSF_Thick       (1<<LNSB_Thick)


#pragma pack()

#endif /* GADGETS_TEXTEDITOR_H */
