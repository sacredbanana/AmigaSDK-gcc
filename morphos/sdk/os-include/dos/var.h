#ifndef DOS_VAR_H
#define DOS_VAR_H

/*
	dos env-var definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct LocalVar
{
	struct Node  lv_Node;
	UWORD        lv_Flags;
	UBYTE       *lv_Value;
	ULONG        lv_Len;
};


#define LV_VAR    0
#define LV_ALIAS  1


#define LVB_IGNORE          7
#define LVF_IGNORE          (1<<LVB_IGNORE)

#define GVB_GLOBAL_ONLY     8
#define GVF_GLOBAL_ONLY     (1<<GVB_GLOBAL_ONLY)

#define GVB_LOCAL_ONLY      9
#define GVF_LOCAL_ONLY      (1<<GVB_LOCAL_ONLY)

#define GVB_BINARY_VAR      10
#define GVF_BINARY_VAR      (1<<GVB_BINARY_VAR)

#define GVB_DONT_NULL_TERM  11
#define GVF_DONT_NULL_TERM  (1<<GVB_DONT_NULL_TERM)

#define GVB_SAVE_VAR        12
#define GVF_SAVE_VAR        (1<<GVB_SAVE_VAR)


#pragma pack()

#endif /* DOS_VAR_H */
