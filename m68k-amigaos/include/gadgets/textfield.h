/*
 * textfield.h
 *
 * Copyright © 1995 Mark Thomas
 *
 * Defines for the BOOPSI textfield.gadget V3.1
 */

#ifndef TEXTFIELD_GADGET_H
#define TEXTFIELD_GADGET_H

#include <utility/tagitem.h>

#define TEXTFIELD_NAME "gadgets/textfield.gadget"
#define TEXTFIELD_VER 3

#define TEXTFIELD_TAG_BASE (TAG_USER + 0x04000000)

// V1 attributes

#define TEXTFIELD_Text           (TEXTFIELD_TAG_BASE + 1)
#define TEXTFIELD_InsertText     (TEXTFIELD_TAG_BASE + 2)
#define TEXTFIELD_TextFont       (TEXTFIELD_TAG_BASE + 3)
#define TEXTFIELD_Delimiters     (TEXTFIELD_TAG_BASE + 4)
#define TEXTFIELD_Top            (TEXTFIELD_TAG_BASE + 5)
#define TEXTFIELD_BlockCursor    (TEXTFIELD_TAG_BASE + 6)
#define TEXTFIELD_Size           (TEXTFIELD_TAG_BASE + 7)
#define TEXTFIELD_Visible        (TEXTFIELD_TAG_BASE + 8)
#define TEXTFIELD_Lines          (TEXTFIELD_TAG_BASE + 9)
#define TEXTFIELD_NoGhost        (TEXTFIELD_TAG_BASE + 10)
#define TEXTFIELD_MaxSize        (TEXTFIELD_TAG_BASE + 11)
#define TEXTFIELD_Border         (TEXTFIELD_TAG_BASE + 12)
#define TEXTFIELD_TextAttr       (TEXTFIELD_TAG_BASE + 13)
#define TEXTFIELD_FontStyle      (TEXTFIELD_TAG_BASE + 14)
#define TEXTFIELD_Up             (TEXTFIELD_TAG_BASE + 15)
#define TEXTFIELD_Down           (TEXTFIELD_TAG_BASE + 16)
#define TEXTFIELD_Alignment      (TEXTFIELD_TAG_BASE + 17)
#define TEXTFIELD_VCenter        (TEXTFIELD_TAG_BASE + 18)
#define TEXTFIELD_RuledPaper     (TEXTFIELD_TAG_BASE + 19)
#define TEXTFIELD_PaperPen       (TEXTFIELD_TAG_BASE + 20)
#define TEXTFIELD_InkPen         (TEXTFIELD_TAG_BASE + 21)
#define TEXTFIELD_LinePen        (TEXTFIELD_TAG_BASE + 22)
#define TEXTFIELD_UserAlign      (TEXTFIELD_TAG_BASE + 23)
#define TEXTFIELD_Spacing        (TEXTFIELD_TAG_BASE + 24)
#define TEXTFIELD_ClipStream     (TEXTFIELD_TAG_BASE + 25)
#define TEXTFIELD_ClipStream2    (TEXTFIELD_TAG_BASE + 26)
#define TEXTFIELD_UndoStream     (TEXTFIELD_TAG_BASE + 26)
#define TEXTFIELD_BlinkRate      (TEXTFIELD_TAG_BASE + 27)
#define TEXTFIELD_Inverted       (TEXTFIELD_TAG_BASE + 28)
#define TEXTFIELD_Partial        (TEXTFIELD_TAG_BASE + 29)
#define TEXTFIELD_CursorPos      (TEXTFIELD_TAG_BASE + 30)

// V2 attributes

#define TEXTFIELD_ReadOnly       (TEXTFIELD_TAG_BASE + 31)
#define TEXTFIELD_Modified       (TEXTFIELD_TAG_BASE + 32)
#define TEXTFIELD_AcceptChars    (TEXTFIELD_TAG_BASE + 33)
#define TEXTFIELD_RejectChars    (TEXTFIELD_TAG_BASE + 34)
#define TEXTFIELD_PassCommand    (TEXTFIELD_TAG_BASE + 35)
#define TEXTFIELD_LineLength     (TEXTFIELD_TAG_BASE + 36)
#define TEXTFIELD_MaxSizeBeep    (TEXTFIELD_TAG_BASE + 37)
#define TEXTFIELD_DeleteText     (TEXTFIELD_TAG_BASE + 38)
#define TEXTFIELD_SelectSize     (TEXTFIELD_TAG_BASE + 39)
#define TEXTFIELD_Copy           (TEXTFIELD_TAG_BASE + 40)
#define TEXTFIELD_CopyAll        (TEXTFIELD_TAG_BASE + 41)
#define TEXTFIELD_Cut            (TEXTFIELD_TAG_BASE + 42)
#define TEXTFIELD_Paste          (TEXTFIELD_TAG_BASE + 43)
#define TEXTFIELD_Erase          (TEXTFIELD_TAG_BASE + 44)
#define TEXTFIELD_Undo           (TEXTFIELD_TAG_BASE + 45)

// V3 attributes

#define TEXTFIELD_TabSpaces      (TEXTFIELD_TAG_BASE + 46)
#define TEXTFIELD_NonPrintChars  (TEXTFIELD_TAG_BASE + 47)

/*
 * TEXTFIELD_Border
 *
 * See docs for width and height sizes for these borders
 */

#define TEXTFIELD_BORDER_NONE              0
#define TEXTFIELD_BORDER_BEVEL             1
#define TEXTFIELD_BORDER_DOUBLEBEVEL       2

/*
 * TEXTFIELD_Alignment
 */

#define TEXTFIELD_ALIGN_LEFT             0
#define TEXTFIELD_ALIGN_CENTER           1
#define TEXTFIELD_ALIGN_RIGHT            2

#endif
