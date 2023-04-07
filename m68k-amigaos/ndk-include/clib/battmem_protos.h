#ifndef CLIB_BATTMEM_PROTOS_H
#define CLIB_BATTMEM_PROTOS_H

/*
**	$VER: battmem_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
VOID  __stdargs ObtainBattSemaphore( VOID );
VOID  __stdargs ReleaseBattSemaphore( VOID );
ULONG  __stdargs ReadBattMem( APTR buffer, ULONG offset, ULONG length );
ULONG  __stdargs WriteBattMem( CONST_APTR buffer, ULONG offset, ULONG length );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_BATTMEM_PROTOS_H */
