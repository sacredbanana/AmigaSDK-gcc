#ifndef PRAGMAS_IFFPARSE_PRAGMAS_H
#define PRAGMAS_IFFPARSE_PRAGMAS_H

/*
**	$VER: iffparse_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_IFFPARSE_PROTOS_H
#include <clib/iffparse_protos.h>
#endif /* CLIB_IFFPARSE_PROTOS_H */

/* "iffparse.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/* Basic functions */

#pragma libcall IFFParseBase AllocIFF 1e 00
#pragma libcall IFFParseBase OpenIFF 24 0802
#pragma libcall IFFParseBase ParseIFF 2a 0802
#pragma libcall IFFParseBase CloseIFF 30 801
#pragma libcall IFFParseBase FreeIFF 36 801

/* Read/Write functions */

#pragma libcall IFFParseBase ReadChunkBytes 3c 09803
#pragma libcall IFFParseBase WriteChunkBytes 42 09803
#pragma libcall IFFParseBase ReadChunkRecords 48 109804
#pragma libcall IFFParseBase WriteChunkRecords 4e 109804

/* Context entry/exit */

#pragma libcall IFFParseBase PushChunk 54 210804
#pragma libcall IFFParseBase PopChunk 5a 801
/*--- (1 function slot reserved here) ---*/

/* Low-level handler installation */

#pragma libcall IFFParseBase EntryHandler 66 A9210806
#pragma libcall IFFParseBase ExitHandler 6c A9210806

/* Built-in chunk/property handlers */

#pragma libcall IFFParseBase PropChunk 72 10803
#pragma libcall IFFParseBase PropChunks 78 09803
#pragma libcall IFFParseBase StopChunk 7e 10803
#pragma libcall IFFParseBase StopChunks 84 09803
#pragma libcall IFFParseBase CollectionChunk 8a 10803
#pragma libcall IFFParseBase CollectionChunks 90 09803
#pragma libcall IFFParseBase StopOnExit 96 10803

/* Context utilities */

#pragma libcall IFFParseBase FindProp 9c 10803
#pragma libcall IFFParseBase FindCollection a2 10803
#pragma libcall IFFParseBase FindPropContext a8 801
#pragma libcall IFFParseBase CurrentChunk ae 801
#pragma libcall IFFParseBase ParentChunk b4 801

/* LocalContextItem support functions */

#pragma libcall IFFParseBase AllocLocalItem ba 321004
#pragma libcall IFFParseBase LocalItemData c0 801
#pragma libcall IFFParseBase SetLocalItemPurge c6 9802
#pragma libcall IFFParseBase FreeLocalItem cc 801
#pragma libcall IFFParseBase FindLocalItem d2 210804
#pragma libcall IFFParseBase StoreLocalItem d8 09803
#pragma libcall IFFParseBase StoreItemInContext de A9803

/* IFFHandle initialization */

#pragma libcall IFFParseBase InitIFF e4 90803
#pragma libcall IFFParseBase InitIFFasDOS ea 801
#pragma libcall IFFParseBase InitIFFasClip f0 801

/* Internal clipboard support */

#pragma libcall IFFParseBase OpenClipboard f6 001
#pragma libcall IFFParseBase CloseClipboard fc 801

/* Miscellaneous */

#pragma libcall IFFParseBase GoodID 102 001
#pragma libcall IFFParseBase GoodType 108 001
#pragma libcall IFFParseBase IDtoStr 10e 8002

#endif /* PRAGMAS_IFFPARSE_PRAGMAS_H */
