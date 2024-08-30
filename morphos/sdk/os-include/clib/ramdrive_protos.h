#ifndef CLIB_RAMDRIVE_PROTOS_H
#define CLIB_RAMDRIVE_PROTOS_H

/*
	ramdrive.device C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

STRPTR KillRAD0( VOID );
STRPTR KillRAD( ULONG unit );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_RAMDRIVE_PROTOS_H */
