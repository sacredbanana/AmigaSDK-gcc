#ifndef CLIB_RESOURCE_PROTOS_H
#define CLIB_RESOURCE_PROTOS_H

/*
	resource.library C prototypes

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_RESOURCE_H
# include <libraries/resource.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef LIBRARIES_LOCALE_H
# include <libraries/locale.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

RESOURCEFILE RL_OpenResource( APTR resource, struct Screen *screen, struct Catalog *catalog );
VOID RL_CloseResource( RESOURCEFILE resfile );
Object *RL_NewObjectA( RESOURCEFILE resfile, RESOURCEID resid, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
Object *RL_NewObject( RESOURCEFILE resfile, RESOURCEID resid, ... );
#endif
VOID RL_DisposeObject( RESOURCEFILE resfile, Object *obj );
Object **RL_NewGroupA( RESOURCEFILE resfile, RESOURCEID id, struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
Object **RL_NewGroup( RESOURCEFILE resfile, RESOURCEID id, ... );
#endif
VOID RL_DisposeGroup( RESOURCEFILE resfile, Object **obj );
Object **RL_GetObjectArray( RESOURCEFILE resfile, Object *obj, RESOURCEID id );
BOOL RL_SetResourceScreen( RESOURCEFILE resfile, struct Screen *screen );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_RESOURCE_PROTOS_H */
