#ifndef CLIB_TRANSLATOR_PROTOS_H
#define CLIB_TRANSLATOR_PROTOS_H

/*
	translator.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

LONG Translate( CONST_STRPTR inputString, LONG inputLength, STRPTR outputBuffer, LONG bufferSize );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_TRANSLATOR_PROTOS_H */
