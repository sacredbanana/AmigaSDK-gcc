#ifndef CLIB_LOWLEVEL_PROTOS_H
#define CLIB_LOWLEVEL_PROTOS_H

/*
	lowlevel.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_INTERRUPTS_H
# include <exec/interrupts.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#ifndef LIBRARIES_LOWLEVEL_H
# include <libraries/lowlevel.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

ULONG ReadJoyPort( ULONG port );

UBYTE GetLanguageSelection( VOID );

ULONG GetKey( VOID );
VOID QueryKeys( struct KeyQuery *queryArray, ULONG arraySize );
APTR AddKBInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemKBInt( APTR intHandle );

ULONG SystemControlA( CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
ULONG SystemControl( Tag firstTag, ... );
#endif

APTR AddTimerInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemTimerInt( APTR intHandle );
VOID StopTimerInt( APTR intHandle );
VOID StartTimerInt( APTR intHandle, ULONG timeInterval, LONG continuous );
ULONG ElapsedTime( struct EClockVal *context );

APTR AddVBlankInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemVBlankInt( APTR intHandle );

BOOL SetJoyPortAttrsA( ULONG portNumber, CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
BOOL SetJoyPortAttrs( ULONG portNumber, Tag firstTag, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_LOWLEVEL_PROTOS_H */
