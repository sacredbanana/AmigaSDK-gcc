#ifndef DEVICES_CD_H
#define DEVICES_CD_H

/*
	cd.device include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#pragma pack(2)


/* CD commands */

#define CD_RESET         (CMD_RESET)
#define CD_READ          (CMD_READ)
#define CD_WRITE         (CMD_WRITE)
#define CD_UPDATE        (CMD_UPDATE)
#define CD_CLEAR         (CMD_CLEAR)
#define CD_STOP          (CMD_STOP)
#define CD_START         (CMD_START)
#define CD_FLUSH         (CMD_FLUSH)

#define CD_MOTOR         (CMD_NONSTD + 0)
#define CD_SEEK          (CMD_NONSTD + 1)
#define CD_FORMAT        (CMD_NONSTD + 2)
#define CD_REMOVE        (CMD_NONSTD + 3)
#define CD_CHANGENUM     (CMD_NONSTD + 4)
#define CD_CHANGESTATE   (CMD_NONSTD + 5)
#define CD_PROTSTATUS    (CMD_NONSTD + 6)

#define CD_GETDRIVETYPE  (CMD_NONSTD + 9)
#define CD_GETNUMTRACKS  (CMD_NONSTD + 10)
#define CD_ADDCHANGEINT  (CMD_NONSTD + 11)
#define CD_REMCHANGEINT  (CMD_NONSTD + 12)
#define CD_GETGEOMETRY   (CMD_NONSTD + 13)
#define CD_EJECT         (CMD_NONSTD + 14)

#define CD_INFO          (CMD_NONSTD + 23)
#define CD_CONFIG        (CMD_NONSTD + 24)
#define CD_TOCMSF        (CMD_NONSTD + 25)
#define CD_TOCLSN        (CMD_NONSTD + 26)

#define CD_READXL        (CMD_NONSTD + 27)

#define CD_PLAYTRACK     (CMD_NONSTD + 28)
#define CD_PLAYMSF       (CMD_NONSTD + 29)
#define CD_PLAYLSN       (CMD_NONSTD + 30)
#define CD_PAUSE         (CMD_NONSTD + 31)
#define CD_SEARCH        (CMD_NONSTD + 32)

#define CD_QCODEMSF      (CMD_NONSTD + 33)
#define CD_QCODELSN      (CMD_NONSTD + 34)
#define CD_ATTENUATE     (CMD_NONSTD + 35)

#define CD_ADDFRAMEINT   (CMD_NONSTD + 36)
#define CD_REMFRAMEINT   (CMD_NONSTD + 37)


/* CD errors */

#define CDERR_OPENFAIL        (-1)
#define CDERR_ABORTED         (-2)
#define CDERR_NOCMD           (-3)
#define CDERR_BADLENGTH       (-4)
#define CDERR_BADADDRESS      (-5)
#define CDERR_UNITBUSY        (-6)
#define CDERR_SELFTEST        (-7)

#define CDERR_NotSpecified    20
#define CDERR_NoSecHdr        21
#define CDERR_BadSecPreamble  22
#define CDERR_BadSecID        23
#define CDERR_BadHdrSum       24
#define CDERR_BadSecSum       25
#define CDERR_TooFewSecs      26
#define CDERR_BadSecHdr       27
#define CDERR_WriteProt       28
#define CDERR_NoDisk          29
#define CDERR_SeekError       30
#define CDERR_NoMem           31
#define CDERR_BadUnitNum      32
#define CDERR_BadDriveType    33
#define CDERR_DriveInUse      34
#define CDERR_PostReset       35
#define CDERR_BadDataType     36
#define CDERR_InvalidState    37

#define CDERR_Phase           42
#define CDERR_NoBoard         50


/* CD config */

#define TAGCD_PLAYSPEED    0x0001
#define TAGCD_READSPEED    0x0002
#define TAGCD_READXLSPEED  0x0003
#define TAGCD_SECTORSIZE   0x0004
#define TAGCD_XLECC        0x0005
#define TAGCD_EJECTRESET   0x0006


struct CDInfo
{
	UWORD PlaySpeed;
	UWORD ReadSpeed;
	UWORD ReadXLSpeed;
	UWORD SectorSize;
	UWORD XLECC;
	UWORD EjectReset;
	UWORD Reserved1[4];

	UWORD MaxSpeed;
	UWORD AudioPrecision;
	UWORD Status;
	UWORD Reserved2[4];
};


/* CD status-flags */

#define CDSTSB_CLOSED     0
#define CDSTSB_DISK       1
#define CDSTSB_SPIN       2
#define CDSTSB_TOC        3
#define CDSTSB_CDROM      4
#define CDSTSB_PLAYING    5
#define CDSTSB_PAUSED     6
#define CDSTSB_SEARCH     7
#define CDSTSB_DIRECTION  8

#define CDSTSF_CLOSED     0x0001
#define CDSTSF_DISK       0x0002
#define CDSTSF_SPIN       0x0004
#define CDSTSF_TOC        0x0008
#define CDSTSF_CDROM      0x0010
#define CDSTSF_PLAYING    0x0020
#define CDSTSF_PAUSED     0x0040
#define CDSTSF_SEARCH     0x0080
#define CDSTSF_DIRECTION  0x0100


/* CD_SEARCH modes */

#define CDMODE_NORMAL  0
#define CDMODE_FFWD    1
#define CDMODE_FREV    2


struct RMSF
{
	UBYTE Reserved;
	UBYTE Minute;
	UBYTE Second;
	UBYTE Frame;
};

union LSNMSF
{
	struct RMSF MSF;
	ULONG       LSN;
};


struct CDXL
{
	struct MinNode   Node;
	char            *Buffer;
	LONG             Length;
	LONG             Actual;
	APTR             IntData;
	VOID           (*IntCode)(VOID);
};


struct TOCSummary
{
	UBYTE        FirstTrack;
	UBYTE        LastTrack;
	union LSNMSF LeadOut;
};


struct TOCEntry
{
	UBYTE        CtlAdr;
	UBYTE        Track;
	union LSNMSF Position;
};


union CDTOC
{
	struct TOCSummary Summary;
	struct TOCEntry   Entry;
};


struct QCode
{
	UBYTE        CtlAdr;
	UBYTE        Track;
	UBYTE        Index;
	UBYTE        Zero;
	union LSNMSF TrackPosition;
	union LSNMSF DiskPosition;
};


#define CTLADR_CTLMASK  0xF0

#define CTL_CTLMASK     0xD0

#define CTL_2AUD        0x00
#define CTL_2AUDEMPH    0x10
#define CTL_4AUD        0x80
#define CTL_4AUDEMPH    0x90
#define CTL_DATA        0x40

#define CTL_COPYMASK    0x20

#define CTL_COPY        0x20

#define CTLADR_ADRMASK  0x0F

#define ADR_POSITION    0x01
#define ADR_UPC         0x02
#define ADR_ISRC        0x03
#define ADR_HYBRID      0x05


#pragma pack()

#endif
