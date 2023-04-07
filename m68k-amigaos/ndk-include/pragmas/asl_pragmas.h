#ifndef PRAGMAS_ASL_PRAGMAS_H
#define PRAGMAS_ASL_PRAGMAS_H

/*
**	$VER: asl_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_ASL_PROTOS_H
#include <clib/asl_protos.h>
#endif /* CLIB_ASL_PROTOS_H */

/* "asl.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/* OBSOLETE -- Please use the generic requester functions instead */

#pragma libcall AslBase AllocFileRequest 1e 00
#pragma libcall AslBase FreeFileRequest 24 801
#pragma libcall AslBase RequestFile 2a 801
#pragma libcall AslBase AllocAslRequest 30 8002
#if defined(__SASC_60)
#pragma tagcall AslBase AllocAslRequestTags 30 8002
#endif /* __SASC_60 */
#pragma libcall AslBase FreeAslRequest 36 801
#pragma libcall AslBase AslRequest 3c 9802
#if defined(__SASC_60)
#pragma tagcall AslBase AslRequestTags 3c 9802
#endif /* __SASC_60 */
#pragma libcall AslBase AbortAslRequest 4e 801
#pragma libcall AslBase ActivateAslRequest 54 801

#endif /* PRAGMAS_ASL_PRAGMAS_H */
