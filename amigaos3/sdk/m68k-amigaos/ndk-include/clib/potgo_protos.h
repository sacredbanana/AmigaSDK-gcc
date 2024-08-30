#ifndef CLIB_POTGO_PROTOS_H
#define CLIB_POTGO_PROTOS_H

/*
**	$VER: potgo_protos.h 47.1 (30.11.2021)
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
UWORD  __stdargs AllocPotBits( ULONG bits );
VOID  __stdargs FreePotBits( ULONG bits );
VOID  __stdargs WritePotgo( ULONG word, ULONG mask );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_POTGO_PROTOS_H */
