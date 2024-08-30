#ifndef DOS_FILEHANDLER_H
#define DOS_FILEHANDLER_H

/*
	dos filehandler definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


struct DosEnvec
{
	ULONG de_TableSize;
	ULONG de_SizeBlock;
	ULONG de_SecOrg;
	ULONG de_Surfaces;
	ULONG de_SectorPerBlock;
	ULONG de_BlocksPerTrack;
	ULONG de_Reserved;
	ULONG de_PreAlloc;
	ULONG de_Interleave;
	ULONG de_LowCyl;
	ULONG de_HighCyl;
	ULONG de_NumBuffers;
	ULONG de_BufMemType;
	ULONG de_MaxTransfer;
	ULONG de_Mask;
	LONG  de_BootPri;
	ULONG de_DosType;
	ULONG de_Baud;
	ULONG de_Control;
	ULONG de_BootBlocks;
};


#define DE_TABLESIZE     0
#define DE_SIZEBLOCK     1
#define DE_SECORG        2
#define DE_NUMHEADS      3
#define DE_SECSPERBLK    4
#define DE_BLKSPERTRACK  5
#define DE_RESERVEDBLKS  6
#define DE_PREFAC        7
#define DE_INTERLEAVE    8
#define DE_LOWCYL        9
#define DE_UPPERCYL      10
#define DE_NUMBUFFERS    11
#define DE_MEMBUFTYPE    12
#define DE_BUFMEMTYPE    12
#define DE_MAXTRANSFER   13
#define DE_MASK          14
#define DE_BOOTPRI       15
#define DE_DOSTYPE       16
#define DE_BAUD          17
#define DE_CONTROL       18
#define DE_BOOTBLOCKS    19


struct FileSysStartupMsg
{
	ULONG fssm_Unit;
	BSTR  fssm_Device;
	BPTR  fssm_Environ;
	ULONG fssm_Flags;
};


struct DeviceNode
{
	BPTR            dn_Next;
	ULONG           dn_Type;
	struct MsgPort *dn_Task;
	BPTR            dn_Lock;
	BSTR            dn_Handler;
	ULONG           dn_StackSize;
	LONG            dn_Priority;
	BPTR            dn_Startup;
	BPTR            dn_SegList;
	BPTR            dn_GlobalVec;
	BSTR            dn_Name;
};


#pragma pack()

#endif /* DOS_FILEHANDLER_H */
