#ifndef CLIB_MATHIEEEDOUBBAS_PROTOS_H
#define CLIB_MATHIEEEDOUBBAS_PROTOS_H

/*
**	$VER: mathieeedoubbas_protos.h 47.1 (30.11.2021)
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
LONG  __stdargs IEEEDPFix( DOUBLE parm );
DOUBLE  __stdargs IEEEDPFlt( LONG integer );
LONG  __stdargs IEEEDPCmp( DOUBLE leftParm, DOUBLE rightParm );
LONG  __stdargs IEEEDPTst( DOUBLE parm );
DOUBLE  __stdargs IEEEDPAbs( DOUBLE parm );
DOUBLE  __stdargs IEEEDPNeg( DOUBLE parm );
DOUBLE  __stdargs IEEEDPAdd( DOUBLE leftParm, DOUBLE rightParm );
DOUBLE  __stdargs IEEEDPSub( DOUBLE leftParm, DOUBLE rightParm );
DOUBLE  __stdargs IEEEDPMul( DOUBLE factor1, DOUBLE factor2 );
DOUBLE  __stdargs IEEEDPDiv( DOUBLE dividend, DOUBLE divisor );
/*--- functions in V33 or higher (Release 1.2) ---*/
DOUBLE  __stdargs IEEEDPFloor( DOUBLE parm );
DOUBLE  __stdargs IEEEDPCeil( DOUBLE parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MATHIEEEDOUBBAS_PROTOS_H */
