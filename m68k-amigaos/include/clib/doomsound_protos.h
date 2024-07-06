/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef CLIB_DOOMSOUND_PROTOS_H
#define CLIB_DOOMSOUND_PROTOS_H

/*
**   $VER: doomsound_protos.h $VER: doomsound_lib.sfd 38.0 (2.9.2022) $VER: doomsound_lib.sfd 38.0 (2.9.2022)
**
**   C prototypes. For use with 32 bit integers only.
**
**   Copyright (c) 2001 Amiga, Inc.
**       All Rights Reserved
*/

#include <exec/libraries.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* "doomsound.library" */
VOID Sfx_SetVol(LONG vol);
VOID Sfx_Start(BYTE * wave, LONG cnum, LONG step, LONG vol, LONG sep, LONG length);
VOID Sfx_Update(LONG cnum, LONG step, LONG vol, LONG sep);
VOID Sfx_Stop(LONG cnum);
LONG Sfx_Done(LONG cnum);
VOID Mus_SetVol(LONG vol);
LONG Mus_Register(APTR musdata);
VOID Mus_Unregister(LONG handle);
VOID Mus_Play(LONG handle, LONG looping);
VOID Mus_Stop(LONG handle);
VOID Mus_Pause(LONG handle);
VOID Mus_Resume(LONG handle);
LONG Mus_Done(LONG handle);

/*--- functions in V38 or higher ---*/
VOID Sfx_StartLoop(BYTE * wave, LONG cnum, LONG step, LONG vol, LONG sep, LONG length, LONG loop);
VOID Sfx_UpdatePitch(LONG cnum, LONG step);
VOID Sfx_UpdateVol(LONG cnum, LONG vol, LONG sep);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_DOOMSOUND_PROTOS_H */
