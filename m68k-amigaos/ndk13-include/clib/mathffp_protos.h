#ifndef CLIB_MATHFFP_PROTOS_H
#define CLIB_MATHFFP_PROTOS_H

/*
**	$VER: mathffp_protos.h 47.1 (30.11.2021)
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
LONG    __stdargs SPFix( FLOAT parm );
FLOAT    __stdargs SPFlt( LONG integer );
LONG    __stdargs SPCmp( FLOAT leftParm, FLOAT rightParm );
LONG    __stdargs SPTst( FLOAT parm );
FLOAT    __stdargs SPAbs( FLOAT parm );
FLOAT    __stdargs SPNeg( FLOAT parm );
FLOAT    __stdargs SPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPDiv( FLOAT leftParm, FLOAT rightParm );
/*--- functions in V33 or higher (Release 1.2) ---*/
FLOAT    __stdargs SPFloor( FLOAT parm );
FLOAT    __stdargs SPCeil( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MATHFFP_PROTOS_H */
