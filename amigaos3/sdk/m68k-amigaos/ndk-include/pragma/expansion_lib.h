#ifndef PRAGMA_EXPANSION_LIB_H
#define PRAGMA_EXPANSION_LIB_H

/*
**	$VER: expansion_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_EXPANSION_PROTOS_H
#include <clib/expansion_protos.h>
#endif /* CLIB_EXPANSION_PROTOS_H */

/* "expansion.library" */
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma amicall(ExpansionBase, 0x1e, AddConfigDev(a0))
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(ExpansionBase, 0x24, AddBootNode(d0,d1,a0,a1))
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma amicall(ExpansionBase, 0x2a, AllocBoardMem(d0))
#pragma amicall(ExpansionBase, 0x30, AllocConfigDev())
#pragma amicall(ExpansionBase, 0x36, AllocExpansionMem(d0,d1))
#pragma amicall(ExpansionBase, 0x3c, ConfigBoard(a0,a1))
#pragma amicall(ExpansionBase, 0x42, ConfigChain(a0))
#pragma amicall(ExpansionBase, 0x48, FindConfigDev(a0,d0,d1))
#pragma amicall(ExpansionBase, 0x4e, FreeBoardMem(d0,d1))
#pragma amicall(ExpansionBase, 0x54, FreeConfigDev(a0))
#pragma amicall(ExpansionBase, 0x5a, FreeExpansionMem(d0,d1))
#pragma amicall(ExpansionBase, 0x60, ReadExpansionByte(a0,d0))
#pragma amicall(ExpansionBase, 0x66, ReadExpansionRom(a0,a1))
#pragma amicall(ExpansionBase, 0x6c, RemConfigDev(a0))
#pragma amicall(ExpansionBase, 0x72, WriteExpansionByte(a0,d0,d1))
#pragma amicall(ExpansionBase, 0x78, ObtainConfigBinding())
#pragma amicall(ExpansionBase, 0x7e, ReleaseConfigBinding())
#pragma amicall(ExpansionBase, 0x84, SetCurrentBinding(a0,d0))
#pragma amicall(ExpansionBase, 0x8a, GetCurrentBinding(a0,d0))
#pragma amicall(ExpansionBase, 0x90, MakeDosNode(a0))
#pragma amicall(ExpansionBase, 0x96, AddDosNode(d0,d1,a0))
/*--- functions in V36 or higher (Release 2.0) ---*/

#endif /* PRAGMA_EXPANSION_LIB_H */
