#ifndef CLIB_CONSOLE_PROTOS_H
#define CLIB_CONSOLE_PROTOS_H

/*
**    $Id: console_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef   DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef   DEVICES_KEYMAP_H
#include <devices/keymap.h>
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

struct InputEvent *CDInputHandler( CONST struct InputEvent *events, struct Library *consoleDevice );
LONG RawKeyConvert( CONST struct InputEvent *events, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
/*--- functions in V36 or higher (Release 2.0) ---*/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CONSOLE_PROTOS_H */
