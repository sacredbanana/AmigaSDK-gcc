#ifndef CLIB_MATHFFP_PROTOS_H
#define CLIB_MATHFFP_PROTOS_H

/*
**    $Id: mathffp_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
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

LONG SPFix( FLOAT parm );
FLOAT SPFlt( LONG integer );
LONG SPCmp( FLOAT leftParm, FLOAT rightParm );
LONG SPTst( FLOAT parm );
FLOAT SPAbs( FLOAT parm );
FLOAT SPNeg( FLOAT parm );
FLOAT SPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT SPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT SPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT SPDiv( FLOAT leftParm, FLOAT rightParm );
/*--- functions in V33 or higher (Release 1.2) ---*/
FLOAT SPFloor( FLOAT parm );
FLOAT SPCeil( FLOAT parm );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_MATHFFP_PROTOS_H */
