#ifndef CLIB_MATHIEEESINGBAS_PROTOS_H
#define CLIB_MATHIEEESINGBAS_PROTOS_H

/*
**	$VER: mathieeesingbas_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  LIBRARIES_MATHLIBRARY_H
#include <libraries/mathlibrary.h>
#endif
LONG  __stdargs IEEESPFix( FLOAT parm );
FLOAT  __stdargs IEEESPFlt( LONG integer );
LONG  __stdargs IEEESPCmp( FLOAT leftParm, FLOAT rightParm );
LONG  __stdargs IEEESPTst( FLOAT parm );
FLOAT  __stdargs IEEESPAbs( FLOAT parm );
FLOAT  __stdargs IEEESPNeg( FLOAT parm );
FLOAT  __stdargs IEEESPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT  __stdargs IEEESPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT  __stdargs IEEESPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT  __stdargs IEEESPDiv( FLOAT dividend, FLOAT divisor );
FLOAT  __stdargs IEEESPFloor( FLOAT parm );
FLOAT  __stdargs IEEESPCeil( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MATHIEEESINGBAS_PROTOS_H */
