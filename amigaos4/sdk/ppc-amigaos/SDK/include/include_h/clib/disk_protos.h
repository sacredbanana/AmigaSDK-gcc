#ifndef CLIB_DISK_PROTOS_H
#define CLIB_DISK_PROTOS_H

/*
**    $Id: disk_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   RESOURCES_DISK_H
#include <resources/disk.h>
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

BOOL AllocUnit( LONG unitNum );
VOID FreeUnit( LONG unitNum );
struct DiscResourceUnit *GetUnit( struct DiscResourceUnit *unitPointer );
VOID GiveUnit( VOID );
LONG GetUnitID( LONG unitNum );
/*------ new for V37 ------*/
LONG ReadUnitID( LONG unitNum );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_DISK_PROTOS_H */
