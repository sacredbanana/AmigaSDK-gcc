#ifndef CLIB_DISK_PROTOS_H
#define CLIB_DISK_PROTOS_H

/*
	disk.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef RESOURCES_DISK_H
# include <resources/disk.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

BOOL AllocUnit( LONG unitNum );
VOID FreeUnit( LONG unitNum );
struct DiscResourceUnit *GetUnit( struct DiscResourceUnit *unitPointer );
VOID GiveUnit( VOID );
LONG GetUnitID( LONG unitNum );
LONG ReadUnitID( LONG unitNum );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_DISK_PROTOS_H */
