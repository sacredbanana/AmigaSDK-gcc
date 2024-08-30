#ifndef DEVICES_SCSIDISK_H
#define DEVICES_SCSIDISK_H

/*
	scsi disk defines (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define HD_SCSICMD   28

/*** V44 ***/

#define HD_WIDESCSI  8


struct SCSICmd
{
	UWORD *scsi_Data;
	ULONG  scsi_Length;
	ULONG  scsi_Actual;
	UBYTE *scsi_Command;
	UWORD  scsi_CmdLength;
	UWORD  scsi_CmdActual;
	UBYTE  scsi_Flags;
	UBYTE  scsi_Status;
	UBYTE *scsi_SenseData;
	UWORD  scsi_SenseLength;
	UWORD  scsi_SenseActual;
};


#define SCSIF_WRITE         0
#define SCSIF_READ          1
#define SCSIB_READ_WRITE    0

#define SCSIF_NOSENSE       0
#define SCSIF_AUTOSENSE     2
#define SCSIF_OLDAUTOSENSE  6
#define SCSIB_AUTOSENSE     1
#define SCSIB_OLDAUTOSENSE  2


#define HFERR_SelfUnit      40
#define HFERR_DMA           41
#define HFERR_Phase         42
#define HFERR_Parity        43
#define HFERR_SelTimeout    44
#define HFERR_BadStatus     45

#define HFERR_NoBoard       50


#pragma pack()

#endif /* DEVICES_SCSIDISK_H */
