#ifndef GADGETS_DIFFVIEW_H
#define GADGETS_DIFFVIEW_H
/*
**    $VER: diffview.h 54.16 (22.08.2022)
**
**    Definitions for the diffviewgclass and linecmpgclass BOOPSI classes
**
**    Copyright (c) 2011 Hyperion Entertainment CVBA.
**    All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/*****************************************************************************/

// Tags for the gadget
#define DIFFVIEW_Dummy          (TAG_USER+0x04000000)

#define DIFFVIEW_DiffObject     (DIFFVIEW_Dummy+1)    // Allocated with CreateDiffObject
#define DIFFVIEW_Screen         (DIFFVIEW_Dummy+2)    // (struct Screen *)
#define DIFFVIEW_Font           (DIFFVIEW_Dummy+3)    // (struct TextFont *)
#define DIFFVIEW_VertScroller   (DIFFVIEW_Dummy+4)    // (Object *)
#define DIFFVIEW_ViewOffsetTop  (DIFFVIEW_Dummy+5)    // int32
#define DIFFVIEW_TabSize        (DIFFVIEW_Dummy+6)    // uint32 
#define DIFFVIEW_HorizScroller  (DIFFVIEW_Dummy+7)    // (Object *)
#define DIFFVIEW_ViewOffsetLeft (DIFFVIEW_Dummy+8)    // int32
#define DIFFVIEW_CurrentLine    (DIFFVIEW_Dummy+9)    // int32 (1..n)
#define DIFFVIEW_LineCmp        (DIFFVIEW_Dummy+10)   // (Object *)

#define DIFFVIEW_BackCol          (DIFFVIEW_Dummy+100)  // Text background (rgb)
#define DIFFVIEW_TextCol          (DIFFVIEW_Dummy+101)  // Normal Text (rgb)
#define DIFFVIEW_OldCol           (DIFFVIEW_Dummy+102)  // Old file diff background (rgb)
#define DIFFVIEW_NewCol           (DIFFVIEW_Dummy+103)  // New file diff background (rgb)
#define DIFFVIEW_BlankCol         (DIFFVIEW_Dummy+104)  // Grey pattern for blank lines (rgb)
#define DIFFVIEW_LineNoBackCol    (DIFFVIEW_Dummy+105)  // Line number column background (rgb)
#define DIFFVIEW_LineNoTextCol    (DIFFVIEW_Dummy+106)  // Line number column text (rgb)
#define DIFFVIEW_GeneralBackCol   (DIFFVIEW_Dummy+107)  // General background (rgb)
#define DIFFVIEW_GeneralShineCol  (DIFFVIEW_Dummy+108)  // General shine (rgb)
#define DIFFVIEW_GeneralShadowCol (DIFFVIEW_Dummy+109)  // General shadow (rgb)
#define DIFFVIEW_OverviewOldCol   (DIFFVIEW_Dummy+110)  // Diff overview old file (rgb)
#define DIFFVIEW_OverviewNewCol   (DIFFVIEW_Dummy+111)  // Diff overview new file (rgb)
#define DIFFVIEW_WsDifferenceCol  (DIFFVIEW_Dummy+112)  // Whitespace difference (rgb)
#define DIFFVIEW_OverviewWsCol    (DIFFVIEW_Dummy+113)  // Diff overview whitespace difference (rgb)

/*****************************************************************************/

// Tags to CreateDiffObject
// Some of which may be obtainable via GetDiffObjectAttr in the future
#define DIFFOBJECT_Dummy         (TAG_USER+0x05000000)

#define DIFFOBJECT_OldFile       (DIFFOBJECT_Dummy+1)  // STRPTR
#define DIFFOBJECT_OldFileLen    (DIFFOBJECT_Dummy+2)  // uint32
#define DIFFOBJECT_NewFile       (DIFFOBJECT_Dummy+3)  // STRPTR
#define DIFFOBJECT_NewFileLen    (DIFFOBJECT_Dummy+4)  // uint32
#define DIFFOBJECT_Diffs         (DIFFOBJECT_Dummy+5)  // STRPTR
#define DIFFOBJECT_DiffsLen      (DIFFOBJECT_Dummy+6)  // uint32
#define DIFFOBJECT_ErrorStr      (DIFFOBJECT_Dummy+7)  // STRPTR *
#define DIFFOBJECT_ErrorNum      (DIFFOBJECT_Dummy+8)  // uint32 *
#define DIFFOBJECT_OldFileName   (DIFFOBJECT_Dummy+9)  // STRPTR
#define DIFFOBJECT_NewFileName   (DIFFOBJECT_Dummy+10) // STRPTR
#define DIFFOBJECT_WsUnimportant (DIFFOBJECT_Dummy+11) // BOOL
#define DIFFOBJECT_ProgressCB    (DIFFOBJECT_Dummy+12) // DIFFOBJPROGCB
#define DIFFOBJECT_ProgCBData    (DIFFOBJECT_Dummy+13) // APTR

// Attributes specific to GetDiffObjectAttr
#define DIFFOBJECT_DiffPositions (DIFFOBJECT_Dummy+10000) // struct DiffPositions

/*****************************************************************************/

// Tags for the linecmp gadget
#define LINECMP_Dummy            (TAG_USER+0x06000000)

#define LINECMP_Screen           (LINECMP_Dummy+2)    // (struct Screen *)
#define LINECMP_Font             (LINECMP_Dummy+3)    // (struct TextFont *)
#define LINECMP_TabSize          (LINECMP_Dummy+6)    // uint32 
#define LINECMP_HorizScroller    (LINECMP_Dummy+7)    // (Object *)
#define LINECMP_ViewOffsetLeft   (LINECMP_Dummy+8)    // int32
#define LINECMP_OldLine          (LINECMP_Dummy+9)    // STRPTR
#define LINECMP_NewLine          (LINECMP_Dummy+10)   // STRPTR

#define LINECMP_OldBackCol       (LINECMP_Dummy+100)  // Text background for old line (rgb)
#define LINECMP_OldTextCol       (LINECMP_Dummy+101)  // Text colour for old line (rgb)
#define LINECMP_NewBackCol       (LINECMP_Dummy+102)  // Text background for new line (rgb)
#define LINECMP_NewTextCol       (LINECMP_Dummy+103)  // Text colour for new line (rgb)
#define LINECMP_BlankCol         (LINECMP_Dummy+104)  // Grey pattern for blank lines

/*****************************************************************************/

// Error codes returned from CreateDiffObject
enum
{
	DOERR_NONE = 0,
	DOERR_OUT_OF_MEMORY,
	DOERR_UNKNOWN_DIFF_FORMAT,
	DOERR_DIFF_MISMATCH
};

/*****************************************************************************/

// Diff object creation progress callback
typedef BOOL (*DIFFOBJPROGCB)(int32 progress, APTR userdata);

/*****************************************************************************/

// List of differences returned by GetDiffObjectAttr(DiffObject, DIFFOBJECT_DiffList, AttrPtr)
struct DiffPositions
{
	uint32 dp_NumDiffs;
	uint32 dp_Positions[];
};

/*****************************************************************************/

// Codes for IDCMP_GADGETUP messages from a diffview gadget
enum
{
	DVAREA_NONE = 0,
	DVAREA_OLDTITLE,
	DVAREA_OLDTEXT,
	DVAREA_NEWTITLE,
	DVAREA_NEWTEXT,
	DVAREA_OVERVIEW
};

/*****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif //GADGETS_DIFFVIEW_H

