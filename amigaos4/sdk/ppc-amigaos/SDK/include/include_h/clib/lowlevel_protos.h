#ifndef CLIB_LOWLEVEL_PROTOS_H
#define CLIB_LOWLEVEL_PROTOS_H

/*
**    $Id: lowlevel_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
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
#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef   LIBRARIES_LOWLEVEL_H
#include <libraries/lowlevel.h>
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

/*--- functions in V40 or higher (Release 3.1) ---*/

/* CONTROLLER HANDLING */

ULONG ReadJoyPort( ULONG port );

/* LANGUAGE HANDLING */

UBYTE GetLanguageSelection( VOID );

/* KEYBOARD HANDLING */

ULONG GetKey( VOID );
VOID QueryKeys( struct KeyQuery *queryArray, ULONG arraySize );
APTR AddKBInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemKBInt( APTR intHandle );

/* SYSTEM HANDLING */

ULONG SystemControlA( CONST struct TagItem *tagList );
ULONG SystemControl( Tag firstTag, ... );

/* TIMER HANDLING */

APTR AddTimerInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemTimerInt( APTR intHandle );
VOID StopTimerInt( APTR intHandle );
VOID StartTimerInt( APTR intHandle, ULONG timeInterval, LONG continuous );
ULONG ElapsedTime( struct EClockVal *context );

/* VBLANK HANDLING */

APTR AddVBlankInt( CONST APTR intRoutine, CONST APTR intData );
VOID RemVBlankInt( APTR intHandle );

/* MORE CONTROLLER HANDLING */

BOOL SetJoyPortAttrsA( ULONG portNumber, CONST struct TagItem *tagList );
BOOL SetJoyPortAttrs( ULONG portNumber, Tag firstTag, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_LOWLEVEL_PROTOS_H */
