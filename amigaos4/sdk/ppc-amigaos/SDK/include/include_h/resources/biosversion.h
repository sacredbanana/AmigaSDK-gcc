#ifndef RESOURCES_BIOSVERSION_H
#define RESOURCES_BIOSVERSION_H 1
/*
**    $VER: biosversion.h 54.16 (22.08.2022)
**
**    biosversion.resource include file
**
**    Copyright (C) 2006 Andrea Vallinotto.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

#define BIOSVER_NAME "biosversion.resource"

struct BIOSVersionResource
{
	struct Node	bvr_Node;           /* on resource list */
	TEXT		bvr_Version[90];    /* Full version string, READ_ONLY. */
	uint32		bvr_DecodedMajor;	/* Decoded version, major */
	uint32		bvr_DecodedMinor;	/* Decoded version, minor */
	uint32		bvr_DecodedPLevel;	/* Decoded version, patchlevel or otherwise third value */
						/* Something like "U-Boot 1.1.4" would become 
						bvr_DecodedMajor = 1, bvr_DecodedMinor = 1, bvr_DecodedPLevel = 4 */
	struct DateStamp bvr_BuildDate; /* As the name says. */
	struct ExecIFace * bvr_IExec;
	BOOL (* bvr_Refresh)(struct BIOSVersionResource * base);
};

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif
