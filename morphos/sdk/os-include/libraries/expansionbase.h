#ifndef LIBRARIES_EXPANSIONBASE_H
#define LIBRARIES_EXPANSIONBASE_H

/*
	expansion.library defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef LIBRARIES_CONFIGVARS_H
# include <libraries/configvars.h>
#endif

#pragma pack(2)


struct BootNode
{
	struct Node bn_Node;
	UWORD       bn_Flags;
	APTR        bn_DeviceNode;
};


struct ExpansionBase
{
	struct Library        LibNode;
	UBYTE                 Flags;
	UBYTE                 eb_Private01;
	ULONG                 eb_Private02;
	ULONG                 eb_Private03;
	struct CurrentBinding eb_Private04;
	struct List           eb_Private05;
	struct List           MountList;
};


#define EE_OK           0
#define EE_LASTBOARD    40
#define EE_NOEXPANSION  41
#define EE_NOMEMORY     42
#define EE_NOBOARD      43
#define EE_BADMEM       44


#define EBB_CLOGGED      0
#define EBB_SHORTMEM     1
#define EBB_BADMEM       2
#define EBB_DOSFLAG      3
#define EBB_KICKBACK33   4
#define EBB_KICKBACK36   5
#define EBB_SILENTSTART  6
#define EBB_START_CC0    7

#define EBF_CLOGGED      (1<<EBB_CLOGGED)
#define EBF_SHORTMEM     (1<<EBB_SHORTMEM)
#define EBF_BADMEM       (1<<EBB_BADMEM)
#define EBF_DOSFLAG      (1<<EBB_DOSFLAG)
#define EBF_KICKBACK33   (1<<EBB_KICKBACK33)
#define EBF_KICKBACK36   (1<<EBB_KICKBACK36)
#define EBF_SILENTSTART  (1<<EBB_SILENTSTART)
#define EBF_START_CC0    (1<<EBB_START_CC0)


#pragma pack()

#endif /* LIBRARIES_EXPANSIONBASE_H */
