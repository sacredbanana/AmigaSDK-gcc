#ifndef DEVICES_BOOTBLOCK_H
#define DEVICES_BOOTBLOCK_H

/*
	bootblock include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct BootBlock
{
	UBYTE bb_id[4];
	LONG  bb_chksum;
	LONG  bb_dosblock;
};


#define BOOTSECTS  2

#define BBID_DOS   {'D','O','S','\0'}
#define BBID_KICK  {'K','I','C','K'}

#define BBNAME_DOS   0x444F5300
#define BBNAME_KICK  0x4B49434B


#pragma pack()

#endif /* DEVICES_BOOTBLOCK_H */
