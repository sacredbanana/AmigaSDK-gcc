#ifndef CLIB_KEYMAP_PROTOS_H
#define CLIB_KEYMAP_PROTOS_H

/*
**	$VER: keymap_protos.h 47.1 (30.11.2021)
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
#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif
/*--- functions in V36 or higher (Release 2.0) ---*/
VOID  __stdargs SetKeyMapDefault( struct KeyMap *keyMap );
struct KeyMap * __stdargs AskKeyMapDefault( VOID );
WORD  __stdargs MapRawKey( CONST struct InputEvent *event, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
LONG  __stdargs MapANSI( CONST_STRPTR string, LONG count, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_KEYMAP_PROTOS_H */
