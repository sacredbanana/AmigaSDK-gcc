#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H

/*
	printer.device include (V45)

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_DEVICES_H
# include <exec/devices.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define PRD_RAWWRITE        (CMD_NONSTD + 0)
#define PRD_PRTCOMMAND      (CMD_NONSTD + 1)
#define PRD_DUMPRPORT       (CMD_NONSTD + 2)
#define PRD_QUERY           (CMD_NONSTD + 3)

/*** V44 ***/

#define PRD_RESETPREFS      (CMD_NONSTD + 4)
#define PRD_LOADPREFS       (CMD_NONSTD + 5)
#define PRD_USEPREFS        (CMD_NONSTD + 6)
#define PRD_SAVEPREFS       (CMD_NONSTD + 7)
#define PRD_READPREFS       (CMD_NONSTD + 8)
#define PRD_WRITEPREFS      (CMD_NONSTD + 9)
#define PRD_EDITPREFS       (CMD_NONSTD + 10)
#define PRD_SETERRHOOK      (CMD_NONSTD + 11)
#define PRD_DUMPRPORTTAGS   (CMD_NONSTD + 12)


#define aRIS     0
#define aRIN     1
#define aIND     2
#define aNEL     3
#define aRI      4

#define aSGR0    5
#define aSGR3    6
#define aSGR23   7
#define aSGR4    8
#define aSGR24   9
#define aSGR1    10
#define aSGR22   11
#define aSFC     12
#define aSBC     13

#define aSHORP0  14
#define aSHORP2  15
#define aSHORP1  16
#define aSHORP4  17
#define aSHORP3  18
#define aSHORP6  19
#define aSHORP5  20

#define aDEN6    21
#define aDEN5    22
#define aDEN4    23
#define aDEN3    24
#define aDEN2    25
#define aDEN1    26

#define aSUS2    27
#define aSUS1    28
#define aSUS4    29
#define aSUS3    30
#define aSUS0    31
#define aPLU     32
#define aPLD     33

#define aFNT0    34
#define aFNT1    35
#define aFNT2    36
#define aFNT3    37
#define aFNT4    38
#define aFNT5    39
#define aFNT6    40
#define aFNT7    41
#define aFNT8    42
#define aFNT9    43
#define aFNT10   44

#define aPROP2   45
#define aPROP1   46
#define aPROP0   47
#define aTSS     48
#define aJFY5    49
#define aJFY7    50
#define aJFY6    51
#define aJFY0    52
#define aJFY3    53
#define aJFY1    54

#define aVERP0   55
#define aVERP1   56
#define aSLPP    57
#define aPERF    58
#define aPERF0   59

#define aLMS     60
#define aRMS     61
#define aTMS     62
#define aBMS     63
#define aSTBM    64
#define aSLRM    65
#define aCAM     66

#define aHTS     67
#define aVTS     68
#define aTBC0    69
#define aTBC3    70
#define aTBC1    71
#define aTBC4    72
#define aTBCALL  73
#define aTBSALL  74
#define aEXTEND  75

#define aRAW     76


struct IOPrtCmdReq
{
	struct Message  io_Message;
	struct Device  *io_Device;
	struct Unit    *io_Unit;
	UWORD           io_Command;
	UBYTE           io_Flags;
	BYTE            io_Error;
	UWORD           io_PrtCommand;
	UBYTE           io_Parm0;
	UBYTE           io_Parm1;
	UBYTE           io_Parm2;
	UBYTE           io_Parm3;
};


struct IODRPReq
{
	struct Message   io_Message;
	struct Device   *io_Device;
	struct Unit     *io_Unit;
	UWORD            io_Command;
	UBYTE            io_Flags;
	BYTE             io_Error;
	struct RastPort *io_RastPort;
	struct ColorMap *io_ColorMap;
	ULONG            io_Modes;
	UWORD            io_SrcX;
	UWORD            io_SrcY;
	UWORD            io_SrcWidth;
	UWORD            io_SrcHeight;
	LONG             io_DestCols;
	LONG             io_DestRows;
	UWORD            io_Special;
};


/*** V44 ***/

struct IODRPTagsReq
{
	struct Message   io_Message;
	struct Device   *io_Device;
	struct Unit     *io_Unit;
	UWORD            io_Command;
	UBYTE            io_Flags;
	BYTE             io_Error;
	struct RastPort *io_RastPort;
	struct ColorMap *io_ColorMap;
	ULONG            io_Modes;
	UWORD            io_SrcX;
	UWORD            io_SrcY;
	UWORD            io_SrcWidth;
	UWORD            io_SrcHeight;
	LONG             io_DestCols;
	LONG             io_DestRows;
	UWORD            io_Special;
	struct TagItem  *io_TagList;
};


#define SPECIAL_MILCOLS     0x0001
#define SPECIAL_MILROWS     0x0002
#define SPECIAL_FULLCOLS    0x0004
#define SPECIAL_FULLROWS    0x0008
#define SPECIAL_FRACCOLS    0x0010
#define SPECIAL_FRACROWS    0x0020
#define SPECIAL_CENTER      0x0040
#define SPECIAL_ASPECT      0x0080
#define SPECIAL_DENSITY1    0x0100
#define SPECIAL_DENSITY2    0x0200
#define SPECIAL_DENSITY3    0x0300
#define SPECIAL_DENSITY4    0x0400
#define SPECIAL_DENSITY5    0x0500
#define SPECIAL_DENSITY6    0x0600
#define SPECIAL_DENSITY7    0x0700
#define SPECIAL_NOFORMFEED  0x0800
#define SPECIAL_TRUSTME     0x1000

#define SPECIAL_NOPRINT     0x2000


#define PDERR_NOERR            0
#define PDERR_CANCEL           1
#define PDERR_NOTGRAPHICS      2
#define PDERR_INVERTHAM        3
#define PDERR_BADDIMENSION     4
#define PDERR_DIMENSIONOVFLOW  5
#define PDERR_INTERNALMEMORY   6
#define PDERR_BUFFERMEMORY     7
#define PDERR_TOOKCONTROL      8

/*** V44 ***/

#define PDERR_BADPREFERENCES   9
#define PDERR_LASTSTANDARD     31
#define PDERR_FIRSTCUSTOM      32
#define PDERR_LASTCUSTOM       126


#define SPECIAL_DENSITYMASK     0x0700
#define SPECIAL_DIMENSIONSMASK (SPECIAL_MILCOLS|SPECIAL_MILROWS|SPECIAL_FULLCOLS|SPECIAL_FULLROWS|SPECIAL_FRACCOLS|SPECIAL_FRACROWS|SPECIAL_ASPECT)


/*** V44 ***/


#define DRPA_Dummy         (TAG_USER + 0x60000)
#define DRPA_ICCProfile    (DRPA_Dummy + 1)
#define DRPA_ICCName       (DRPA_Dummy + 2)
#define DRPA_NoColCorrect  (DRPA_Dummy + 3)
#define DRPA_SourceHook    (DRPA_Dummy + 4)
#define DRPA_AspectX       (DRPA_Dummy + 5)
#define DRPA_AspectY       (DRPA_Dummy + 6)

struct DRPSourceMsg
{
	LONG   x;
	LONG   y;
	LONG   width;
	LONG   height;
	ULONG *buf;
};

#define PPRA_Dummy      (TAG_USER + 0x70000)
#define PPRA_Window     (PPRA_Dummy + 1)
#define PPRA_Screen     (PPRA_Dummy + 2)
#define PPRA_PubScreen  (PPRA_Dummy + 3)

struct IOPrtPrefsReq
{
	struct Message  io_Message;
	struct Device  *io_Device;
	struct Unit    *io_Unit;
	UWORD           io_Command;
	UBYTE           io_Flags;
	BYTE            io_Error;
	struct TagItem *io_TagList;
};

#define PDHOOK_NONE  ((struct Hook *) NULL)
#define PDHOOK_STD   ((struct Hook *) 1)

struct IOPrtErrReq
{
	struct Message  io_Message;
	struct Device  *io_Device;
	struct Unit    *io_Unit;
	UWORD           io_Command;
	UBYTE           io_Flags;
	BYTE            io_Error;
	struct Hook    *io_Hook;
};

struct PrtErrMsg
{
	ULONG              pe_Version;
	ULONG              pe_ErrorLevel;
	struct Window     *pe_Window;
	struct EasyStruct *pe_ES;
	ULONG             *pe_IDCMP;
	APTR               pe_ArgList;
};

#define PDHOOK_VERSION  1

struct IOPrefsReq
{
	struct Message                 io_Message;
	struct Device                 *io_Device;
	struct Unit                   *io_Unit;
	UWORD                          io_Command;
	UBYTE                          io_Flags;
	BYTE                           io_Error;
	struct PrinterTxtPrefs        *io_TxtPrefs;
	struct PrinterUnitPrefs       *io_UnitPrefs;
	struct PrinterDeviceUnitPrefs *io_DevUnitPrefs;
	struct PrinterGfxPrefs        *io_GfxPrefs;
};


#pragma pack()

#endif /* DEVICES_PRINTER_H */
