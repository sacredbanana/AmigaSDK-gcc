#ifndef CLIB_BATTCLOCK_PROTOS_H
#define CLIB_BATTCLOCK_PROTOS_H

/*
**	$VER: battclock_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
VOID  __stdargs ResetBattClock( VOID );
ULONG  __stdargs ReadBattClock( VOID );
VOID  __stdargs WriteBattClock( ULONG time );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_BATTCLOCK_PROTOS_H */
