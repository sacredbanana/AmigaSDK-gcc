#ifndef UTILITY_HOOKS_H
#define UTILITY_HOOKS_H

/*
	utility.library hook defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(2)

struct Hook
{
	struct MinNode   h_MinNode;
	ULONG          (*h_Entry)(VOID);
	ULONG          (*h_SubEntry)(VOID);
	APTR             h_Data;
};

typedef ULONG (*HOOKFUNC)(VOID);


#pragma pack()

#ifdef __cplusplus
}
#endif

#endif /* UTILITY_HOOKS_H */
