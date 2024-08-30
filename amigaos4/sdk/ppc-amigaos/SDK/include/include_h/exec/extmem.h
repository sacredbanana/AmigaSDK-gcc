#ifndef EXEC_EXTMEM_H
#define EXEC_EXTMEM_H
/*
**    $VER: extmem.h 53.29 (10.8.2015)
**
**    Definitions for the Extended Memory System (ExtMem)
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2014 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

struct ExtMemIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ExtMemIFace *Self);
	uint32 APICALL (*Release)(struct ExtMemIFace *Self);
	void   APICALL (*Expunge)(struct ExtMemIFace *Self);
	struct Interface * APICALL (*Clone)(struct ExtMemIFace *Self);

	APTR APICALL (*Map)(struct ExtMemIFace *Self, APTR baseAddress, uint32 length, uint64 offset, uint32 flags);
	void APICALL (*Unmap)(struct ExtMemIFace *Self, APTR baseAddress, uint32 length);
};

enum ExtMemFlags {
	EXTMEMF_READONLY= 0x02,		// Make the area read only
	EXTMEMF_PRIVATE = 0x04,		// Make the area only available in the creators
								// address space


	EXTMEMF_FAIL_UNAVAIL	= 0x10,
								// Fail if the memory range is not available
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* EXEC_EXTMEM_H */
