#ifndef LIBRARIES_NONVOLATILE_H
#define LIBRARIES_NONVOLATILE_H

/*
	nonvolatile.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

#pragma pack(2)


struct NVInfo
{
	ULONG nvi_MaxStorage;
	ULONG nvi_FreeStorage;
};

struct NVEntry
{
	struct MinNode nve_Node;
	STRPTR         nve_Name;
	ULONG          nve_Size;
	ULONG          nve_Protection;
};


#define NVEB_DELETE   0
#define NVEB_APPNAME  31

#define NVEF_DELETE   (1<<NVEB_DELETE)
#define NVEF_APPNAME  (1<<NVEB_APPNAME)


#define NVERR_BADNAME    1
#define NVERR_WRITEPROT  2
#define NVERR_FAIL       3
#define NVERR_FATAL      4


#define SizeNVData(DataPtr)  ((((ULONG *)DataPtr)[-1]) - 4)


#pragma pack()

#endif /* LIBRARIES_NONVOLATILE_H */
