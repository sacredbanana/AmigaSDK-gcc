#ifndef CLIB_CONSOLE_PROTOS_H
#define CLIB_CONSOLE_PROTOS_H

/*
	console.device C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef DEVICES_INPUTEVENT_H
# include <devices/inputevent.h>
#endif

#ifndef DEVICES_KEYMAP_H
# include <devices/keymap.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct InputEvent *CDInputHandler( CONST struct InputEvent *events, struct Library *consoleDevice );
LONG RawKeyConvert( CONST struct InputEvent *events, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_CONSOLE_PROTOS_H */
