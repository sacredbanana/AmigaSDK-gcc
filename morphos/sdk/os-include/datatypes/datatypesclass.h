#ifndef DATATYPES_DATATYPESCLASS_H
#define DATATYPES_DATATYPESCLASS_H

/*
	datatypes object definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DATATYPES_DATATYPES_H
# include <datatypes/datatypes.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef DEVICES_PRINTER_H
# include <devices/printer.h>
#endif

#ifndef DEVICES_PRTBASE_H
# include <devices/prtbase.h>
#endif

#pragma pack(2)


#define DATATYPESCLASS  "datatypesclass"


/* Generic attributes */

#define DTA_Dummy           (TAG_USER + 0x1000)
#define DTA_TextAttr        (DTA_Dummy + 10)
#define DTA_TopVert         (DTA_Dummy + 11)
#define DTA_VisibleVert     (DTA_Dummy + 12)
#define DTA_TotalVert       (DTA_Dummy + 13)
#define DTA_VertUnit        (DTA_Dummy + 14)
#define DTA_TopHoriz        (DTA_Dummy + 15)
#define DTA_VisibleHoriz    (DTA_Dummy + 16)
#define DTA_TotalHoriz      (DTA_Dummy + 17)
#define DTA_HorizUnit       (DTA_Dummy + 18)
#define DTA_NodeName        (DTA_Dummy + 19)
#define DTA_Title           (DTA_Dummy + 20)
#define DTA_TriggerMethods  (DTA_Dummy + 21)
#define DTA_Data            (DTA_Dummy + 22)
#define DTA_TextFont        (DTA_Dummy + 23)
#define DTA_Methods         (DTA_Dummy + 24)
#define DTA_PrinterStatus   (DTA_Dummy + 25)
#define DTA_PrinterProc     (DTA_Dummy + 26)
#define DTA_LayoutProc      (DTA_Dummy + 27)
#define DTA_Busy            (DTA_Dummy + 28)
#define DTA_Sync            (DTA_Dummy + 29)
#define DTA_BaseName        (DTA_Dummy + 30)
#define DTA_GroupID         (DTA_Dummy + 31)
#define DTA_ErrorLevel      (DTA_Dummy + 32)
#define DTA_ErrorNumber     (DTA_Dummy + 33)
#define DTA_ErrorString     (DTA_Dummy + 34)
#define DTA_Conductor       (DTA_Dummy + 35)
#define DTA_ControlPanel    (DTA_Dummy + 36)
#define DTA_Immediate       (DTA_Dummy + 37)
#define DTA_Repeat          (DTA_Dummy + 38)

/*** V44 ***/

#define DTA_SourceAddress   (DTA_Dummy + 39)
#define DTA_SourceSize      (DTA_Dummy + 40)
#define DTA_Reserved        (DTA_Dummy + 41)

/*** V45 ***/

#define DTA_Progressive     (DTA_Dummy + 60)
#define DTA_CurrentLevel    (DTA_Dummy + 61)
#define DTA_Class           (DTA_Dummy + 62)


/* DTObject attributes */

#define DTA_Name            (DTA_Dummy + 100)
#define DTA_SourceType      (DTA_Dummy + 101)
#define DTA_Handle          (DTA_Dummy + 102)
#define DTA_DataType        (DTA_Dummy + 103)
#define DTA_Domain          (DTA_Dummy + 104)

/*** DO NOT USE ***/
#define DTA_Left            (DTA_Dummy + 105)
#define DTA_Top             (DTA_Dummy + 106)
#define DTA_Width           (DTA_Dummy + 107)
#define DTA_Height          (DTA_Dummy + 108)

#define DTA_ObjName         (DTA_Dummy + 109)
#define DTA_ObjAuthor       (DTA_Dummy + 110)
#define DTA_ObjAnnotation   (DTA_Dummy + 111)
#define DTA_ObjCopyright    (DTA_Dummy + 112)
#define DTA_ObjVersion      (DTA_Dummy + 113)
#define DTA_ObjectID        (DTA_Dummy + 114)
#define DTA_UserData        (DTA_Dummy + 115)
#define DTA_FrameInfo       (DTA_Dummy + 116)

/*** DO NOT USE ***/
#define DTA_RelRight        (DTA_Dummy + 117)
#define DTA_RelBottom       (DTA_Dummy + 118)
#define DTA_RelWidth        (DTA_Dummy + 119)
#define DTA_RelHeight       (DTA_Dummy + 120)

#define DTA_SelectDomain    (DTA_Dummy + 121)
#define DTA_TotalPVert      (DTA_Dummy + 122)
#define DTA_TotalPHoriz     (DTA_Dummy + 123)
#define DTA_NominalVert     (DTA_Dummy + 124)
#define DTA_NominalHoriz    (DTA_Dummy + 125)


/* Printing attributes */

#define DTA_DestCols        (DTA_Dummy + 400)
#define DTA_DestRows        (DTA_Dummy + 401)
#define DTA_Special         (DTA_Dummy + 402)
#define DTA_RastPort        (DTA_Dummy + 403)
#define DTA_ARexxPortName   (DTA_Dummy + 404)


#define DTST_RAM        1
#define DTST_FILE       2
#define DTST_CLIPBOARD  3
#define DTST_HOTLINK    4

/*** V44 ***/

#define DTST_MEMORY     5


struct DTSpecialInfo
{
	struct SignalSemaphore  si_Lock;
	ULONG                   si_Flags;

	LONG                    si_TopVert;
	LONG                    si_VisVert;
	LONG                    si_TotVert;
	LONG                    si_OTopVert;
	LONG                    si_VertUnit;

	LONG                    si_TopHoriz;
	LONG                    si_VisHoriz;
	LONG                    si_TotHoriz;
	LONG                    si_OTopHoriz;
	LONG                    si_HorizUnit;
};


#define DTSIF_LAYOUT      (1<<0)
#define DTSIF_NEWSIZE     (1<<1)
#define DTSIF_DRAGGING    (1<<2)
#define DTSIF_DRAGSELECT  (1<<3)
#define DTSIF_HIGHLIGHT   (1<<4)
#define DTSIF_PRINTING    (1<<5)
#define DTSIF_LAYOUTPROC  (1<<6)


struct DTMethod
{
	STRPTR dtm_Label;
	STRPTR dtm_Command;
	ULONG  dtm_Method;
};


#define DTM_Dummy           (0x600)
#define DTM_FRAMEBOX        (DTM_Dummy + 1)
#define DTM_PROCLAYOUT      (DTM_Dummy + 2)
#define DTM_ASYNCLAYOUT     (DTM_Dummy + 3)
#define DTM_REMOVEDTOBJECT  (DTM_Dummy + 4)
#define DTM_SELECT          (DTM_Dummy + 5)
#define DTM_CLEARSELECTED   (DTM_Dummy + 6)
#define DTM_COPY            (DTM_Dummy + 7)
#define DTM_PRINT           (DTM_Dummy + 8)
#define DTM_ABORTPRINT      (DTM_Dummy + 9)

#define DTM_NEWMEMBER       (DTM_Dummy + 16)
#define DTM_DISPOSEMEMBER   (DTM_Dummy + 17)

#define DTM_GOTO            (DTM_Dummy + 48)
#define DTM_TRIGGER         (DTM_Dummy + 49)

#define DTM_OBTAINDRAWINFO  (DTM_Dummy + 64)
#define DTM_DRAW            (DTM_Dummy + 65)
#define DTM_RELEASEDRAWINFO (DTM_Dummy + 66)

#define DTM_WRITE           (DTM_Dummy + 80)


struct FrameInfo
{
	ULONG            fri_PropertyFlags;
	Point            fri_Resolution;

	UBYTE            fri_RedBits;
	UBYTE            fri_GreenBits;
	UBYTE            fri_BlueBits;

	struct
	{
		ULONG Width;
		ULONG Height;
		ULONG Depth;
	}                fri_Dimensions;

	struct Screen   *fri_Screen;
	struct ColorMap *fri_ColorMap;

	ULONG            fri_Flags;
};


#define FIF_SCALABLE    0x1
#define FIF_SCROLLABLE  0x2
#define FIF_REMAPPABLE  0x4


struct dtGeneral
{
	ULONG                MethodID;
	struct GadgetInfo   *dtg_GInfo;
};

struct dtSelect
{
	ULONG                MethodID;
	struct GadgetInfo   *dts_GInfo;
	struct Rectangle     dts_Select;
};

struct dtFrameBox
{
	ULONG                MethodID;
	struct GadgetInfo   *dtf_GInfo;
	struct FrameInfo    *dtf_ContentsInfo;
	struct FrameInfo    *dtf_FrameInfo;
	ULONG                dtf_SizeFrameInfo;
	ULONG                dtf_FrameFlags;
};

#ifndef FRAMEF_SPECIFY
# define FRAMEF_SPECIFY  (1<<0)
#endif

struct dtGoto
{
	ULONG                MethodID;
	struct GadgetInfo   *dtg_GInfo;
	STRPTR               dtg_NodeName;
	struct TagItem      *dtg_AttrList;
};

struct dtTrigger
{
	ULONG                MethodID;
	struct GadgetInfo   *dtt_GInfo;
	ULONG                dtt_Function;
	APTR                 dtt_Data;
};


#define STMF_METHOD_MASK    (0x0000FFFF)
#define STMF_DATA_MASK      (0x00FF0000)
#define STMF_RESERVED_MASK  (0xFF000000)

#define STMD_VOID           (0x00010000)
#define STMD_ULONG          (0x00020000)
#define STMD_STRPTR         (0x00030000)
#define STMD_TAGLIST        (0x00040000)

#define STM_DONE            0
#define STM_END             0
#define STM_PAUSE           1
#define STM_PLAY            2
#define STM_CONTENTS        3
#define STM_INDEX           4
#define STM_RETRACE         5
#define STM_BROWSE_PREV     6
#define STM_BROWSE_NEXT     7
#define STM_NEXT_FIELD      8
#define STM_PREV_FIELD      9
#define STM_ACTIVATE_FIELD  10
#define STM_COMMAND         11
#define STM_REWIND          12
#define STM_FASTFORWARD     13
#define STM_STOP            14
#define STM_RESUME          15
#define STM_LOCATE          16

/*** V50 ***/

#define STM_HELP            17
#define STM_SEARCH          18
#define STM_SEARCH_NEXT     19
#define STM_SEARCH_PREV     20

/*** V45 ***/

#define STM_USER            100


union printerIO
{
	struct IOStdReq    ios;
	struct IODRPReq    iodrp;
	struct IOPrtCmdReq iopc;
};

struct dtPrint
{
	ULONG                MethodID;
	struct GadgetInfo   *dtp_GInfo;
	union printerIO     *dtp_PIO;
	struct TagItem      *dtp_AttrList;
};

struct dtDraw
{
	ULONG            MethodID;
	struct RastPort *dtd_RPort;
	LONG             dtd_Left;
	LONG             dtd_Top;
	LONG             dtd_Width;
	LONG             dtd_Height;
	LONG             dtd_TopHoriz;
	LONG             dtd_TopVert;
	struct TagItem  *dtd_AttrList;
};

struct dtReleaseDrawInfo
{
	ULONG MethodID;
	APTR  dtr_Handle;
};

struct dtWrite
{
	ULONG                MethodID;
	struct GadgetInfo   *dtw_GInfo;
	BPTR                 dtw_FileHandle;
	ULONG                dtw_Mode;
	struct TagItem      *dtw_AttrList;
};


#define DTWM_IFF  0
#define DTWM_RAW  1


#pragma pack()

#endif /* DATATYPES_DATATYPESCLASS_H */
