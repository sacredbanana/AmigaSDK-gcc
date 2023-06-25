#ifndef CLIB_MATHIEEESINGBAS_PROTOS_H
#define CLIB_MATHIEEESINGBAS_PROTOS_H

/*
**    $Id: mathieeesingbas_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

LONG IEEESPFix( FLOAT parm );
FLOAT IEEESPFlt( LONG integer );
LONG IEEESPCmp( FLOAT leftParm, FLOAT rightParm );
LONG IEEESPTst( FLOAT parm );
FLOAT IEEESPAbs( FLOAT parm );
FLOAT IEEESPNeg( FLOAT parm );
FLOAT IEEESPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT IEEESPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT IEEESPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT IEEESPDiv( FLOAT dividend, FLOAT divisor );
FLOAT IEEESPFloor( FLOAT parm );
FLOAT IEEESPCeil( FLOAT parm );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_MATHIEEESINGBAS_PROTOS_H */
