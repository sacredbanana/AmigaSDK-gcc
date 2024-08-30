#ifndef DEVICES_HARDBLOCKS_H
#define DEVICES_HARDBLOCKS_H

/*
	hardblocks include (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

#pragma pack(2)


struct RigidDiskBlock
{
	ULONG rdb_ID;
	ULONG rdb_SummedLongs;
	LONG  rdb_ChkSum;
	ULONG rdb_HostID;
	ULONG rdb_BlockBytes;
	ULONG rdb_Flags;

	ULONG rdb_BadBlockList;
	ULONG rdb_PartitionList;
	ULONG rdb_FileSysHeaderList;
	ULONG rdb_DriveInit;
	ULONG rdb_Reserved1[6];

	ULONG rdb_Cylinders;
	ULONG rdb_Sectors;
	ULONG rdb_Heads;
	ULONG rdb_Interleave;
	ULONG rdb_Park;
	ULONG rdb_Reserved2[3];
	ULONG rdb_WritePreComp;
	ULONG rdb_ReducedWrite;
	ULONG rdb_StepRate;
	ULONG rdb_Reserved3[5];

	ULONG rdb_RDBBlocksLo;
	ULONG rdb_RDBBlocksHi;
	ULONG rdb_LoCylinder;
	ULONG rdb_HiCylinder;
	ULONG rdb_CylBlocks;
	ULONG rdb_AutoParkSeconds;
	ULONG rdb_HighRDSKBlock;
	ULONG rdb_Reserved4;

	char  rdb_DiskVendor[8];
	char  rdb_DiskProduct[16];
	char  rdb_DiskRevision[4];
	char  rdb_ControllerVendor[8];
	char  rdb_ControllerProduct[16];
	char  rdb_ControllerRevision[4];

	/*** V44 ***/

	char  rdb_DriveInitName[40];
};

#define IDNAME_RIGIDDISK  0x5244534B


#define RDB_LOCATION_LIMIT  16


#define RDBFB_LAST        0
#define RDBFF_LAST        (1<<RDBFB_LAST)
#define RDBFB_LASTLUN     1
#define RDBFF_LASTLUN     (1<<RDBFB_LASTLUN)
#define RDBFB_LASTTID     2
#define RDBFF_LASTTID     (1<<RDBFB_LASTID)
#define RDBFB_NORESELECT  3
#define RDBFF_NORESELECT  (1<<RDBFB_NORESELECT)
#define RDBFB_DISKID      4
#define RDBFF_DISKID      (1<<RDBFB_DISKID)
#define RDBFB_CTRLRID     5
#define RDBFF_CTRLRID     (1<<RDBFB_CTRLRID)
#define RDBFB_SYNCH       6
#define RDBFF_SYNCH       (1<<RDBFB_SYNCH)


struct BadBlockEntry
{
	ULONG bbe_BadBlock;
	ULONG bbe_GoodBlock;
};

struct BadBlockBlock
{
	ULONG                bbb_ID;
	ULONG                bbb_SummedLongs;
	LONG                 bbb_ChkSum;
	ULONG                bbb_HostID;
	ULONG                bbb_Next;
	ULONG                bbb_Reserved;
	struct BadBlockEntry bbb_BlockPairs[61];
};

#define IDNAME_BADBLOCK  0x42414442


struct PartitionBlock
{
	ULONG pb_ID;
	ULONG pb_SummedLongs;
	LONG  pb_ChkSum;
	ULONG pb_HostID;
	ULONG pb_Next;
	ULONG pb_Flags;
	ULONG pb_Reserved1[2];
	ULONG pb_DevFlags;
	UBYTE pb_DriveName[32];
	ULONG pb_Reserved2[15];
	ULONG pb_Environment[20];
	ULONG pb_EReserved[12];
};

#define IDNAME_PARTITION  0x50415254


#define PBFB_BOOTABLE  0
#define PBFF_BOOTABLE  (1<<PBFB_BOOTABLE)
#define PBFB_NOMOUNT   1
#define PBFF_NOMOUNT   (1<<PBFB_NOMOUNT)


struct FileSysHeaderBlock
{
	ULONG fhb_ID;
	ULONG fhb_SummedLongs;
	LONG  fhb_ChkSum;
	ULONG fhb_HostID;
	ULONG fhb_Next;
	ULONG fhb_Flags;
	ULONG fhb_Reserved1[2];
	ULONG fhb_DosType;
	ULONG fhb_Version;
	ULONG fhb_PatchFlags;
	ULONG fhb_Type;
	ULONG fhb_Task;
	ULONG fhb_Lock;
	ULONG fhb_Handler;
	ULONG fhb_StackSize;
	LONG  fhb_Priority;
	LONG  fhb_Startup;
	LONG  fhb_SegListBlocks;
	LONG  fhb_GlobalVec;
	ULONG fhb_Reserved2[23];

	/*** V44 ***/

	char  fhb_FileSysName[84];
};

#define IDNAME_FILESYSHEADER  0x46534844


struct LoadSegBlock
{
	ULONG lsb_ID;
	ULONG lsb_SummedLongs;
	LONG  lsb_ChkSum;
	ULONG lsb_HostID;
	ULONG lsb_Next;
	ULONG lsb_LoadData[123];
};

#define IDNAME_LOADSEG  0x4C534547

/*** V 50 ***/
struct NewLoadSegBlock {
	ULONG   nsb_ID;
	ULONG   nsb_SummedLongs;
	LONG    nsb_ChkSum;
	ULONG   nsb_HostID;

	ULONG   nsb_DataSize;
	ULONG   nsb_DataChkSum;
	ULONG   nsb_DataSector;

	ULONG   nsb_Pad[121];
};

#define	IDNAME_NEWLOADSEG		0x4E534547	/* 'NSEG' */


#pragma pack()

#endif /* DEVICES_HARDBLOCKS_H */
