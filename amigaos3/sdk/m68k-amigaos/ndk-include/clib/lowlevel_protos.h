#ifndef CLIB_LOWLEVEL_PROTOS_H
#define CLIB_LOWLEVEL_PROTOS_H

/*
**	$VER: lowlevel_protos.h 47.1 (30.11.2021)
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
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  LIBRARIES_LOWLEVEL_H
#include <libraries/lowlevel.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/

/* CONTROLLER HANDLING */

ULONG  __stdargs ReadJoyPort( ULONG port );

/* LANGUAGE HANDLING */

UBYTE  __stdargs GetLanguageSelection( VOID );

/* KEYBOARD HANDLING */

ULONG  __stdargs GetKey( VOID );
VOID  __stdargs QueryKeys( struct KeyQuery *queryArray, LONG arraySize );
APTR  __stdargs AddKBInt( APTR intRoutine, APTR intData );
VOID  __stdargs RemKBInt( APTR intHandle );

/* SYSTEM HANDLING */

ULONG  __stdargs SystemControlA( CONST struct TagItem *tagList );
ULONG  __stdargs SystemControl( Tag firstTag, ... );

/* TIMER HANDLING */

APTR  __stdargs AddTimerInt( APTR intRoutine, APTR intData );
VOID  __stdargs RemTimerInt( APTR intHandle );
VOID  __stdargs StopTimerInt( APTR intHandle );
VOID  __stdargs StartTimerInt( APTR intHandle, ULONG timeInterval, LONG continuous );
ULONG  __stdargs ElapsedTime( struct EClockVal *context );

/* VBLANK HANDLING */

APTR  __stdargs AddVBlankInt( APTR intRoutine, APTR intData );
VOID  __stdargs RemVBlankInt( APTR intHandle );

/* MORE CONTROLLER HANDLING */

BOOL  __stdargs SetJoyPortAttrsA( ULONG portNumber, CONST struct TagItem *tagList );
BOOL  __stdargs SetJoyPortAttrs( ULONG portNumber, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LOWLEVEL_PROTOS_H */
