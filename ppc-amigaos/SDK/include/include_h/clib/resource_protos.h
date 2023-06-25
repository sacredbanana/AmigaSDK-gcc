#ifndef CLIB_RESOURCE_PROTOS_H
#define CLIB_RESOURCE_PROTOS_H

/*
**    $Id: resource_protos.h,v 1.7 2010-01-31 01:29:03 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   LIBRARIES_RESOURCE_H
#include <libraries/resource.h>
#endif
#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

RESOURCEFILE RL_OpenResource( APTR resource, struct Screen *screen, struct Catalog *catalog );
VOID RL_CloseResource( RESOURCEFILE resfile );
Object *RL_NewObjectA( RESOURCEFILE resfile, RESOURCEID resid, struct TagItem *tags );
Object *RL_NewObject( RESOURCEFILE resfile, RESOURCEID resid, ... );
VOID RL_DisposeObject( RESOURCEFILE resfile, Object *obj );
Object **RL_NewGroupA( RESOURCEFILE resfile, RESOURCEID id, struct TagItem *taglist );
Object **RL_NewGroup( RESOURCEFILE resfile, RESOURCEID id, ... );
VOID RL_DisposeGroup( RESOURCEFILE resfile, Object **obj );
Object **RL_GetObjectArray( RESOURCEFILE resfile, Object *obj, RESOURCEID id );
BOOL RL_SetResourceScreen( RESOURCEFILE resfile, struct Screen *screen );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_RESOURCE_PROTOS_H */
