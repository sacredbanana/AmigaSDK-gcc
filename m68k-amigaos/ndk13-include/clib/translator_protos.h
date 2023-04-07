#ifndef CLIB_TRANSLATOR_PROTOS_H
#define CLIB_TRANSLATOR_PROTOS_H

/*
**	$VER: translator_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
LONG    __stdargs Translate( CONST_STRPTR inputString, LONG inputLength, STRPTR outputBuffer, LONG bufferSize );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_TRANSLATOR_PROTOS_H */
