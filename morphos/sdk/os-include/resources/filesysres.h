#ifndef RESOURCES_FILESYSRES_H
#define RESOURCES_FILESYSRES_H

/*
	FileSystem.resource include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


#define FSRNAME  "FileSystem.resource"


struct FileSysResource
{
	struct Node  fsr_Node;
	char        *fsr_Creator;
	struct List  fsr_FileSysEntries;
};

struct FileSysEntry
{
	struct Node fse_Node;
	ULONG       fse_DosType;
	ULONG       fse_Version;
	ULONG       fse_PatchFlags;
	ULONG       fse_Type;
	CPTR        fse_Task;
	BPTR        fse_Lock;
	BSTR        fse_Handler;
	ULONG       fse_StackSize;
	LONG        fse_Priority;
	BPTR        fse_Startup;
	BPTR        fse_SegList;
	BPTR        fse_GlobalVec;
};


#pragma pack()

#endif /* RESOURCES_FILESYSRES_H */
