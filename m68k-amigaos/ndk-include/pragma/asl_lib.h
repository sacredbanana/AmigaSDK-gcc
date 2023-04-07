#ifndef PRAGMA_ASL_LIB_H
#define PRAGMA_ASL_LIB_H

/*
**	$VER: asl_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_ASL_PROTOS_H
#include <clib/asl_protos.h>
#endif /* CLIB_ASL_PROTOS_H */

/* "asl.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/* OBSOLETE -- Please use the generic requester functions instead */

#pragma amicall(AslBase, 0x1e, AllocFileRequest())
#pragma amicall(AslBase, 0x24, FreeFileRequest(a0))
#pragma amicall(AslBase, 0x2a, RequestFile(a0))
#pragma amicall(AslBase, 0x30, AllocAslRequest(d0,a0))
#if defined(__STORM__)
#pragma tagcall(AslBase, 0x30, AllocAslRequestTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(AslBase, 0x36, FreeAslRequest(a0))
#pragma amicall(AslBase, 0x3c, AslRequest(a0,a1))
#if defined(__STORM__)
#pragma tagcall(AslBase, 0x3c, AslRequestTags(a0,a1))
#endif /* __STORM__ */
#pragma amicall(AslBase, 0x4e, AbortAslRequest(a0))
#pragma amicall(AslBase, 0x54, ActivateAslRequest(a0))

#endif /* PRAGMA_ASL_LIB_H */
