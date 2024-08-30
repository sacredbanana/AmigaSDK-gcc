#ifndef PRAGMAS_EXPANSION_PRAGMAS_H
#define PRAGMAS_EXPANSION_PRAGMAS_H

/*
**	$VER: expansion_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_EXPANSION_PROTOS_H
#include <clib/expansion_protos.h>
#endif /* CLIB_EXPANSION_PROTOS_H */

/* "expansion.library" */
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma libcall ExpansionBase AddConfigDev 1e 801
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall ExpansionBase AddBootNode 24 981004
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma libcall ExpansionBase AllocBoardMem 2a 001
#pragma libcall ExpansionBase AllocConfigDev 30 00
#pragma libcall ExpansionBase AllocExpansionMem 36 1002
#pragma libcall ExpansionBase ConfigBoard 3c 9802
#pragma libcall ExpansionBase ConfigChain 42 801
#pragma libcall ExpansionBase FindConfigDev 48 10803
#pragma libcall ExpansionBase FreeBoardMem 4e 1002
#pragma libcall ExpansionBase FreeConfigDev 54 801
#pragma libcall ExpansionBase FreeExpansionMem 5a 1002
#pragma libcall ExpansionBase ReadExpansionByte 60 0802
#pragma libcall ExpansionBase ReadExpansionRom 66 9802
#pragma libcall ExpansionBase RemConfigDev 6c 801
#pragma libcall ExpansionBase WriteExpansionByte 72 10803
#pragma libcall ExpansionBase ObtainConfigBinding 78 00
#pragma libcall ExpansionBase ReleaseConfigBinding 7e 00
#pragma libcall ExpansionBase SetCurrentBinding 84 0802
#pragma libcall ExpansionBase GetCurrentBinding 8a 0802
#pragma libcall ExpansionBase MakeDosNode 90 801
#pragma libcall ExpansionBase AddDosNode 96 81003
/*--- functions in V36 or higher (Release 2.0) ---*/

#endif /* PRAGMAS_EXPANSION_PRAGMAS_H */
