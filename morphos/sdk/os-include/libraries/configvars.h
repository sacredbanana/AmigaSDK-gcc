#ifndef LIBRARIES_CONFIGVARS_H
#define LIBRARIES_CONFIGVARS_H

/*
	AutoConfig(TM) structures

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef LIBRARIES_CONFIGREGS_H
# include <libraries/configregs.h>
#endif

#pragma pack(2)


struct ConfigDev
{
	struct Node          cd_Node;
	UBYTE                cd_Flags;
	UBYTE                cd_Pad;
	struct ExpansionRom  cd_Rom;
	APTR                 cd_BoardAddr;
	ULONG                cd_BoardSize;
	UWORD                cd_SlotAddr;
	UWORD                cd_SlotSize;
	APTR                 cd_Driver;
	struct ConfigDev    *cd_NextCD;
	ULONG                cd_Unused[4];
};


#define CDB_SHUTUP      0
#define CDB_CONFIGME    1
#define CDB_BADMEMORY   2
#define CDB_PROCESSED   3

#define CDF_SHUTUP      (1<<CDB_SHUTUP)
#define CDF_CONFIGME    (1<<CDB_CONFIGME)
#define CDF_BADMEMORY   (1<<CDB_BADMEMORY)
#define CDF_PROCESSED   (1<<CDB_PROCESSED)


struct CurrentBinding
{
	struct ConfigDev  *cb_ConfigDev;
	UBYTE             *cb_FileName;
	UBYTE             *cb_ProductString;
	UBYTE            **cb_ToolTypes;
};


#pragma pack()

#endif /* LIBRARIES_CONFIGVARS_H */
