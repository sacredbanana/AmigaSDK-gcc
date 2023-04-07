#ifndef CLIB_MATHIEEESINGTRANS_PROTOS_H
#define CLIB_MATHIEEESINGTRANS_PROTOS_H

/*
**	$VER: mathieeesingtrans_protos.h 47.1 (30.11.2021)
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
FLOAT    __stdargs IEEESPAtan( FLOAT parm );
FLOAT    __stdargs IEEESPSin( FLOAT parm );
FLOAT    __stdargs IEEESPCos( FLOAT parm );
FLOAT    __stdargs IEEESPTan( FLOAT parm );
FLOAT    __stdargs IEEESPSincos( FLOAT *cosptr, FLOAT parm );
FLOAT    __stdargs IEEESPSinh( FLOAT parm );
FLOAT    __stdargs IEEESPCosh( FLOAT parm );
FLOAT    __stdargs IEEESPTanh( FLOAT parm );
FLOAT    __stdargs IEEESPExp( FLOAT parm );
FLOAT    __stdargs IEEESPLog( FLOAT parm );
FLOAT    __stdargs IEEESPPow( FLOAT exp, FLOAT arg );
FLOAT    __stdargs IEEESPSqrt( FLOAT parm );
FLOAT    __stdargs IEEESPTieee( FLOAT parm );
FLOAT    __stdargs IEEESPFieee( FLOAT parm );
FLOAT    __stdargs IEEESPAsin( FLOAT parm );
FLOAT    __stdargs IEEESPAcos( FLOAT parm );
FLOAT    __stdargs IEEESPLog10( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_MATHIEEESINGTRANS_PROTOS_H */
