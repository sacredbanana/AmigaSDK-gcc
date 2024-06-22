#ifndef CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#define CLIB_MATHIEEEDOUBTRANS_PROTOS_H

/*
**	$VER: mathieeedoubtrans_protos.h 47.1 (30.11.2021)
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
DOUBLE  __stdargs IEEEDPAtan( DOUBLE parm );
DOUBLE  __stdargs IEEEDPSin( DOUBLE parm );
DOUBLE  __stdargs IEEEDPCos( DOUBLE parm );
DOUBLE  __stdargs IEEEDPTan( DOUBLE parm );
DOUBLE  __stdargs IEEEDPSincos( DOUBLE *pf2, DOUBLE parm );
DOUBLE  __stdargs IEEEDPSinh( DOUBLE parm );
DOUBLE  __stdargs IEEEDPCosh( DOUBLE parm );
DOUBLE  __stdargs IEEEDPTanh( DOUBLE parm );
DOUBLE  __stdargs IEEEDPExp( DOUBLE parm );
DOUBLE  __stdargs IEEEDPLog( DOUBLE parm );
DOUBLE  __stdargs IEEEDPPow( DOUBLE exp, DOUBLE arg );
DOUBLE  __stdargs IEEEDPSqrt( DOUBLE parm );
FLOAT  __stdargs IEEEDPTieee( DOUBLE parm );
DOUBLE  __stdargs IEEEDPFieee( FLOAT single );
DOUBLE  __stdargs IEEEDPAsin( DOUBLE parm );
DOUBLE  __stdargs IEEEDPAcos( DOUBLE parm );
DOUBLE  __stdargs IEEEDPLog10( DOUBLE parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MATHIEEEDOUBTRANS_PROTOS_H */
