#ifndef CLIB_KEYMAP_PROTOS_H
#define CLIB_KEYMAP_PROTOS_H

/*
**    $Id: keymap_protos.h,v 1.10 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef   LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
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

/*--- functions in V36 or higher (Release 2.0) ---*/
VOID SetKeyMapDefault( CONST struct KeyMap *keyMap );
struct KeyMap *AskKeyMapDefault( VOID );
WORD MapRawKey( CONST struct InputEvent *event, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
LONG MapANSI( CONST_STRPTR string, LONG count, STRPTR buffer, LONG length, CONST struct KeyMap *keyMap );
/*--- functions in V50 or higher (Release 4.0 beta) ---*/
APTR OpenKeyMapHandleA( STRPTR filename, struct TagItem *taglist );
APTR OpenKeyMapHandle( STRPTR filename, Tag tag1, ... );
VOID CloseKeyMapHandle( APTR handle );
ULONG ObtainKeyMapInfoA( APTR handle, struct TagItem *taglist );
ULONG ObtainKeyMapInfo( APTR handle, Tag tag1, ... );
VOID ReleaseKeyMapInfoA( APTR handle, struct TagItem *taglist );
VOID ReleaseKeyMapInfo( APTR handle, Tag tag1, ... );
/*--- functions in V51 or higher (Release 4.0 beta2) ---*/
VOID ObtainRawKeyInfoA( struct TagItem *taglist );
VOID ObtainRawKeyInfo( Tag tag1, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_KEYMAP_PROTOS_H */
