#ifndef CLIB_RAMDRIVE_PROTOS_H
#define CLIB_RAMDRIVE_PROTOS_H

/*
**	$VER: ramdrive_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_DEVICES_H
#include <exec/devices.h>
#endif
/*--- functions in V34 or higher (Release 1.3) ---*/
STRPTR  __stdargs KillRAD0( VOID );
/*--- functions in V36 or higher (Release 2.0) ---*/
STRPTR  __stdargs KillRAD( ULONG unit );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_RAMDRIVE_PROTOS_H */
