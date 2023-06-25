#ifndef CLIB_DTCLASS_PROTOS_H
#define CLIB_DTCLASS_PROTOS_H
/*
**    $Id: dtclass_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
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
#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

/*--- functions in V39 or higher (distributed as Release 3.0) ---*/

Class *ObtainEngine( void );
#endif /* CLIB_DTCLASS_PROTOS_H */
