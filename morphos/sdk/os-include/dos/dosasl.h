#ifndef DOS_DOSASL_H
#define DOS_DOSASL_H

/*
	dos asl definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


struct AnchorPath
{
	struct AChain        *ap_Base;
#	define                ap_First ap_Base

	struct AChain        *ap_Last;
#	define                ap_Current ap_Last

	LONG                  ap_BreakBits;
	LONG                  ap_FoundBreak;

	BYTE                  ap_Flags;
#	define                ap_Length ap_Flags

	BYTE                  ap_Extended;
#	define                ap_Reserved ap_Extended

	WORD                  ap_Strlen;
	struct FileInfoBlock  ap_Info;
	UBYTE                 ap_Buf[2];
	/* ap_Buf continues */
};


#define APB_DOWILD        0
#define APF_DOWILD        (1<<APB_DOWILD)

#define APB_ITSWILD       1
#define APF_ITSWILD       (1<<APB_ITSWILD)

#define APB_DODIR         2
#define APF_DODIR         (1<<APB_DODIR)

#define APB_DIDDIR        3
#define APF_DIDDIR        (1<<APB_DIDDIR)

#define APB_NOMEMERR      4
#define APF_NOMEMERR      (1<<APB_NOMEMERR)

#define APB_DODOT         5
#define APF_DODOT         (1<<APB_DODOT)

#define APB_DirChanged    6
#define APF_DirChanged    (1<<APB_DirChanged)

#define APB_FollowHLinks  7
#define APF_FollowHLinks  (1<<APB_FollowHLinks)


#define APSB_EXTENDED         15
#define APSF_EXTENDED         (1<<APSB_EXTENDED)

/* Following are ap_Extended flags, only enabled when ap_StrLen has
   APSF_EXTENDED set. Added in dos.library 50.67. */

/* Return literal softlink names instead of the link destination */
#define APEB_LiteralSLinks    1
#define APEF_LiteralSLinks    (1<<APEB_LiteralSLinks)

/* Don't follow softlink directories, implies APEF_LiteralSLinks */
#define APEB_DontFollowSLinks 2
#define APEF_DontFollowSLinks (1<<APEB_DontFollowSLinks)

#define APEB_FutureExtension  7
#define APEF_FutureExtension  (1<<APEB_FutureExtension)


struct AChain
{
	struct AChain        *an_Child;
	struct AChain        *an_Parent;
	BPTR                  an_Lock;
	struct FileInfoBlock  an_Info;
	BYTE                  an_Flags;
	UBYTE                 an_String[1];
	/* an_String continues */
};


#define DDB_PatternBit   0
#define DDF_PatternBit   (1<<DDB_PatternBit)

#define DDB_ExaminedBit  1
#define DDF_ExaminedBit  (1<<DDB_ExaminedBit)

#define DDB_Completed    2
#define DDF_Completed    (1<<DDB_Completed)

#define DDB_AllBit       3
#define DDF_AllBit       (1<<DDB_AllBit)

#define DDB_Single       4
#define DDF_Single       (1<<DDB_Single)


#define P_ANY       0x80
#define P_SINGLE    0x81
#define P_ORSTART   0x82
#define P_ORNEXT    0x83
#define P_OREND     0x84
#define P_NOT       0x85
#define P_NOTEND    0x86
#define P_NOTCLASS  0x87
#define P_CLASS     0x88
#define P_REPBEG    0x89
#define P_REPEND    0x8A
#define P_STOP      0x8B


#define COMPLEX_BIT  1
#define EXAMINE_BIT  2


#define ERROR_BUFFER_OVERFLOW  303
#define ERROR_BREAK            304
#define ERROR_NOT_EXECUTABLE   305


#pragma pack()

#endif /* DOS_DOSASL_H */
