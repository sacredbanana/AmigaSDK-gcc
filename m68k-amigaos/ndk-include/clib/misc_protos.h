#ifndef CLIB_MISC_PROTOS_H
#define CLIB_MISC_PROTOS_H

/*
**	$VER: misc_protos.h 47.1 (30.11.2021)
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
UBYTE * __stdargs AllocMiscResource( ULONG unitNum, CONST_STRPTR name );
VOID  __stdargs FreeMiscResource( ULONG unitNum );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MISC_PROTOS_H */
