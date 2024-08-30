#ifndef RESOURCES_MATHRESOURCE_H
#define RESOURCES_MATHRESOURCE_H

/*
	MathIEEE.resource include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct MathIEEEResource
{
	struct Node      MathIEEEResource_Node;
	UWORD            MathIEEEResource_Flags;
	UWORD           *MathIEEEResource_BaseAddr;
	VOID           (*MathIEEEResource_DblBasInit)(VOID);
	VOID           (*MathIEEEResource_DblTransInit)(VOID);
	VOID           (*MathIEEEResource_SglBasInit)(VOID);
	VOID           (*MathIEEEResource_SglTransInit)(VOID);
	VOID           (*MathIEEEResource_ExtBasInit)(VOID);
	VOID           (*MathIEEEResource_ExtTransInit)(VOID);
};

#define MATHIEEERESOURCEF_DBLBAS    (1<<0)
#define MATHIEEERESOURCEF_DBLTRANS  (1<<1)
#define MATHIEEERESOURCEF_SGLBAS    (1<<2)
#define MATHIEEERESOURCEF_SGLTRANS  (1<<3)
#define MATHIEEERESOURCEF_EXTBAS    (1<<4)
#define MATHIEEERESOURCEF_EXTTRANS  (1<<5)


#pragma pack()

#endif /* RESOURCES_MATHRESOURCE_H */
