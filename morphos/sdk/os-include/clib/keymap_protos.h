#ifndef CLIB_KEYMAP_PROTOS_H
#define CLIB_KEYMAP_PROTOS_H

/*
	keymap.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DEVICES_INPUTEVENT_H
# include <devices/inputevent.h>
#endif

#ifndef DEVICES_KEYMAP_H
# include <devices/keymap.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID SetKeyMapDefault( CONST struct KeyMap *keyMap );
struct KeyMap *AskKeyMapDefault( VOID );
WORD MapRawKey( CONST struct InputEvent *event, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
LONG MapANSI( CONST_STRPTR string, LONG count, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
WORD MapRawKeyUCS4( CONST struct InputEvent *event, WSTRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
LONG MapUCS4( CONST_WSTRPTR string, LONG count, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
char ToANSI( WCHAR ucs4char, CONST struct KeyMap *keyMap );
WCHAR ToUCS4( char asciichar, CONST struct KeyMap *keyMap );
CONST_STRPTR GetKeyMapCodepage( CONST struct KeyMap *keyMap );
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_KEYMAP_PROTOS_H */
