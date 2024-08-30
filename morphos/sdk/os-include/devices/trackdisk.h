#ifndef DEVICES_TRACKDISK_H
#define DEVICES_TRACKDISK_H

/*
	trackdisk.device include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#ifndef EXEC_DEVICES_H
# include <exec/devices.h>
#endif

#pragma pack(2)


#define NUMSECS   11
#define NUMUNITS  4

#define TD_SECTOR    512
#define TD_SECSHIFT  9


#define TD_NAME  "trackdisk.device"

#define TDF_EXTCOM  (1<<15)


#define TD_MOTOR         (CMD_NONSTD + 0)
#define TD_SEEK          (CMD_NONSTD + 1)
#define TD_FORMAT        (CMD_NONSTD + 2)
#define TD_REMOVE        (CMD_NONSTD + 3)
#define TD_CHANGENUM     (CMD_NONSTD + 4)
#define TD_CHANGESTATE   (CMD_NONSTD + 5)
#define TD_PROTSTATUS    (CMD_NONSTD + 6)
#define TD_RAWREAD       (CMD_NONSTD + 7)
#define TD_RAWWRITE      (CMD_NONSTD + 8)
#define TD_GETDRIVETYPE  (CMD_NONSTD + 9)
#define TD_GETNUMTRACKS  (CMD_NONSTD + 10)
#define TD_ADDCHANGEINT  (CMD_NONSTD + 11)
#define TD_REMCHANGEINT  (CMD_NONSTD + 12)
#define TD_GETGEOMETRY   (CMD_NONSTD + 13)
#define TD_EJECT         (CMD_NONSTD + 14)
#define TD_LASTCOMM      (CMD_NONSTD + 15)

/* TD64 */
#define TD_READ64        (CMD_NONSTD + 15)
#define TD_WRITE64       (CMD_NONSTD + 16)
#define TD_SEEK64        (CMD_NONSTD + 17)
#define TD_FORMAT64      (CMD_NONSTD + 18)

/* TDGETGEOMETRY64 */
/* (CMD_NONSTD+19 reserved for SCSIDirect cmd */
/* (CMD_NONSTD+20 reserved for IDEDirect cmd */
#define TD_GETGEOMETRY64 (CMD_NONSTD + 21)

#define ETD_WRITE        (CMD_WRITE|TDF_EXTCOM)
#define ETD_READ         (CMD_READ|TDF_EXTCOM)
#define ETD_MOTOR        (TD_MOTOR|TDF_EXTCOM)
#define ETD_SEEK         (TD_SEEK|TDF_EXTCOM)
#define ETD_FORMAT       (TD_FORMAT|TDF_EXTCOM)
#define ETD_UPDATE       (CMD_UPDATE|TDF_EXTCOM)
#define ETD_CLEAR        (CMD_CLEAR|TDF_EXTCOM)
#define ETD_RAWREAD      (TD_RAWREAD|TDF_EXTCOM)
#define ETD_RAWWRITE     (TD_RAWWRITE|TDF_EXTCOM)

#define io_HighOffset io_Actual /* TD64 */
#define io_LowOffset io_Offset  /* TD64 */

struct IOExtTD
{
	struct IOStdReq iotd_Req;
	ULONG           iotd_Count;
	ULONG           iotd_SecLabel;
};

struct DriveGeometry
{
	ULONG dg_SectorSize;
	/*
	 * Only valid up to 2TB, if the medium has more
	 * it should return INT_MAX
	 */
	ULONG dg_TotalSectors;
	/*
	 * As modern storage media aren't layouted
	 * in Cylinder/Heads/Sectors, the value is
	 * *usually* calculated from the dg_TotalSectors
	 * value.
	 * Only valid up to 2TB, the usage is deprecated.
	 */
	ULONG dg_Cylinders;
	/*
	 * As modern storage media aren't layouted
	 * in Cylinder/Heads/Sectors, the value is
	 * *usually* calculated from the dg_TotalSectors
	 * value.
	 * Only valid up to 2TB, the usage is deprecated.
	 */
	ULONG dg_CylSectors;
	/*
	 * As modern storage media aren't layouted
	 * in Cylinder/Heads/Sectors, the value is
	 * *usually* calculated from the dg_TotalSectors
	 * value.
	 * Only valid up to 2TB, the usage is deprecated.
	 */
	ULONG dg_Heads;
	/*
	 * As modern storage media aren't layouted
	 * in Cylinder/Heads/Sectors, the value is
	 * *usually* calculated from the dg_TotalSectors
	 * value.
	 * Only valid up to 2TB, the usage is deprecated.
	 */
	ULONG dg_TrackSectors;
	ULONG dg_BufMemType;
	UBYTE dg_DeviceType;
	UBYTE dg_Flags;
	UWORD dg_Reserved;
};

struct DriveGeometry64
{
	/*
	 * Placeholder for old-style DriveGeometry entry.
	 * Only valid up to 2TB, the direct usage is deprecated, please
	 * use dg64_* defines.
	 */
	struct DriveGeometry dg64_Geometry;
	/*
	 * As modern storage media aren't layouted
	 * in Cylinder/Heads/Sectors, the drive size value is
	 * calculated from the dg_TotalSectors64 value.
	 * Valid also for drives which size is over 2TB.
	 */
	UQUAD dg64_TotalSectors64;
};

#define dg64_SectorSize     dg64_Geometry.dg_SectorSize
#define dg64_TotalSectors   dg64_Geometry.dg_TotalSectors
#define dg64_Cylinders      dg64_Geometry.dg_Cylinders
#define dg64_CylSectors     dg64_Geometry.dg_CylSectors
#define dg64_Heads          dg64_Geometry.dg_Heads
#define dg64_TrackSectors   dg64_Geometry.dg_TrackSectors
#define dg64_BufMemType     dg64_Geometry.dg_BufMemType
#define dg64_DeviceType     dg64_Geometry.dg_DeviceType
#define dg64_Flags          dg64_Geometry.dg_Flags
#define dg64_Reserved       dg64_Geometry.dg_Reserved

#define DG_DIRECT_ACCESS      0
#define DG_SEQUENTIAL_ACCESS  1
#define DG_PRINTER            2
#define DG_PROCESSOR          3
#define DG_WORM               4
#define DG_CDROM              5
#define DG_SCANNER            6
#define DG_OPTICAL_DISK       7
#define DG_MEDIUM_CHANGER     8
#define DG_COMMUNICATION      9
#define DG_GRAPHICS           10
#define DG_RAM_DISK           20
#define DG_UNKNOWN            31

#define DGB_REMOVABLE  0
#define DGF_REMOVABLE  (1<<DGB_REMOVABLE)


#define IOTDB_INDEXSYNC  4
#define IOTDF_INDEXSYNC  (1<<IOTDB_INDEXSYNC)
#define IOTDB_WORDSYNC   5
#define IOTDF_WORDSYNC   (1<<IOTDB_WORDSYNC)


#define TD_LABELSIZE  16


#define TDB_ALLOW_NON_3_5  0
#define TDF_ALLOW_NON_3_5  (1<<TDB_ALLOW_NON_3_5)

#define DRIVE3_5         1
#define DRIVE5_25        2
#define DRIVE3_5_150RPM  3


#define TDERR_NotSpecified    20
#define TDERR_NoSecHdr        21
#define TDERR_BadSecPreamble  22
#define TDERR_BadSecID        23
#define TDERR_BadHdrSum       24
#define TDERR_BadSecSum       25
#define TDERR_TooFewSecs      26
#define TDERR_BadSecHdr       27
#define TDERR_WriteProt       28
#define TDERR_DiskChanged     29
#define TDERR_SeekError       30
#define TDERR_NoMem           31
#define TDERR_BadUnitNum      32
#define TDERR_BadDriveType    33
#define TDERR_DriveInUse      34
#define TDERR_PostReset       35


struct TDU_PublicUnit
{
	struct Unit tdu_Unit;
	UWORD       tdu_Comp01Track;
	UWORD       tdu_Comp10Track;
	UWORD       tdu_Comp11Track;
	ULONG       tdu_StepDelay;
	ULONG       tdu_SettleDelay;
	UBYTE       tdu_RetryCnt;
	UBYTE       tdu_PubFlags;
	UWORD       tdu_CurrTrk;
	ULONG       tdu_CalibrateDelay;
	ULONG       tdu_Counter;
};

#define TDPB_NOCLICK  0
#define TDPF_NOCLICK  (1<<TDPB_NOCLICK)


#pragma pack()

#endif /* DEVICES_TRACKDISK_H */
