/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_DOOMSOUND_H
#define _INLINE_DOOMSOUND_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef DOOMSOUND_BASE_NAME
#define DOOMSOUND_BASE_NAME DoomSndBase
#endif /* !DOOMSOUND_BASE_NAME */

#define Sfx_SetVol(___vol) \
      LP1NR(0x1e, Sfx_SetVol , LONG, ___vol, d0,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_Start(___wave, ___cnum, ___step, ___vol, ___sep, ___length) \
      LP6NR(0x24, Sfx_Start , BYTE *, ___wave, a0, LONG, ___cnum, d0, LONG, ___step, d1, LONG, ___vol, d2, LONG, ___sep, d3, LONG, ___length, d4,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_Update(___cnum, ___step, ___vol, ___sep) \
      LP4NR(0x2a, Sfx_Update , LONG, ___cnum, d0, LONG, ___step, d1, LONG, ___vol, d2, LONG, ___sep, d3,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_Stop(___cnum) \
      LP1NR(0x30, Sfx_Stop , LONG, ___cnum, d0,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_Done(___cnum) \
      LP1(0x36, LONG, Sfx_Done , LONG, ___cnum, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_SetVol(___vol) \
      LP1NR(0x3c, Mus_SetVol , LONG, ___vol, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Register(___musdata) \
      LP1(0x42, LONG, Mus_Register , APTR, ___musdata, a0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Unregister(___handle) \
      LP1NR(0x48, Mus_Unregister , LONG, ___handle, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Play(___handle, ___looping) \
      LP2NR(0x4e, Mus_Play , LONG, ___handle, d0, LONG, ___looping, d1,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Stop(___handle) \
      LP1NR(0x54, Mus_Stop , LONG, ___handle, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Pause(___handle) \
      LP1NR(0x5a, Mus_Pause , LONG, ___handle, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Resume(___handle) \
      LP1NR(0x60, Mus_Resume , LONG, ___handle, d0,\
      , DOOMSOUND_BASE_NAME)

#define Mus_Done(___handle) \
      LP1(0x66, LONG, Mus_Done , LONG, ___handle, d0,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_StartLoop(___wave, ___cnum, ___step, ___vol, ___sep, ___length, ___loop) \
      LP7NR(0x6c, Sfx_StartLoop , BYTE *, ___wave, a0, LONG, ___cnum, d0, LONG, ___step, d1, LONG, ___vol, d2, LONG, ___sep, d3, LONG, ___length, d4, LONG, ___loop, d5,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_UpdatePitch(___cnum, ___step) \
      LP2NR(0x72, Sfx_UpdatePitch , LONG, ___cnum, d0, LONG, ___step, d1,\
      , DOOMSOUND_BASE_NAME)

#define Sfx_UpdateVol(___cnum, ___vol, ___sep) \
      LP3NR(0x78, Sfx_UpdateVol , LONG, ___cnum, d0, LONG, ___vol, d2, LONG, ___sep, d3,\
      , DOOMSOUND_BASE_NAME)

#endif /* !_INLINE_DOOMSOUND_H */
