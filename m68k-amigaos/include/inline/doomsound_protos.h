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

VOID __Sfx_SetVol(__reg("a6") struct Library * , __reg("d0") LONG vol ) = "\tjsr\t-30(a6)";
#define Sfx_SetVol(vol) __Sfx_SetVol(DoomSndBase, (vol))

VOID __Sfx_Start(__reg("a6") struct Library * , __reg("a0") BYTE * wave , __reg("d0") LONG cnum , __reg("d1") LONG step , __reg("d2") LONG vol , __reg("d3") LONG sep , __reg("d4") LONG length ) = "\tjsr\t-36(a6)";
#define Sfx_Start(wave, cnum, step, vol, sep, length) __Sfx_Start(DoomSndBase, (wave), (cnum), (step), (vol), (sep), (length))

VOID __Sfx_Update(__reg("a6") struct Library * , __reg("d0") LONG cnum , __reg("d1") LONG step , __reg("d2") LONG vol , __reg("d3") LONG sep ) = "\tjsr\t-42(a6)";
#define Sfx_Update(cnum, step, vol, sep) __Sfx_Update(DoomSndBase, (cnum), (step), (vol), (sep))

VOID __Sfx_Stop(__reg("a6") struct Library * , __reg("d0") LONG cnum ) = "\tjsr\t-48(a6)";
#define Sfx_Stop(cnum) __Sfx_Stop(DoomSndBase, (cnum))

LONG __Sfx_Done(__reg("a6") struct Library * , __reg("d0") LONG cnum ) = "\tjsr\t-54(a6)";
#define Sfx_Done(cnum) __Sfx_Done(DoomSndBase, (cnum))

VOID __Mus_SetVol(__reg("a6") struct Library * , __reg("d0") LONG vol ) = "\tjsr\t-60(a6)";
#define Mus_SetVol(vol) __Mus_SetVol(DoomSndBase, (vol))

LONG __Mus_Register(__reg("a6") struct Library * , __reg("a0") APTR musdata ) = "\tjsr\t-66(a6)";
#define Mus_Register(musdata) __Mus_Register(DoomSndBase, (musdata))

VOID __Mus_Unregister(__reg("a6") struct Library * , __reg("d0") LONG handle ) = "\tjsr\t-72(a6)";
#define Mus_Unregister(handle) __Mus_Unregister(DoomSndBase, (handle))

VOID __Mus_Play(__reg("a6") struct Library * , __reg("d0") LONG handle , __reg("d1") LONG looping ) = "\tjsr\t-78(a6)";
#define Mus_Play(handle, looping) __Mus_Play(DoomSndBase, (handle), (looping))

VOID __Mus_Stop(__reg("a6") struct Library * , __reg("d0") LONG handle ) = "\tjsr\t-84(a6)";
#define Mus_Stop(handle) __Mus_Stop(DoomSndBase, (handle))

VOID __Mus_Pause(__reg("a6") struct Library * , __reg("d0") LONG handle ) = "\tjsr\t-90(a6)";
#define Mus_Pause(handle) __Mus_Pause(DoomSndBase, (handle))

VOID __Mus_Resume(__reg("a6") struct Library * , __reg("d0") LONG handle ) = "\tjsr\t-96(a6)";
#define Mus_Resume(handle) __Mus_Resume(DoomSndBase, (handle))

LONG __Mus_Done(__reg("a6") struct Library * , __reg("d0") LONG handle ) = "\tjsr\t-102(a6)";
#define Mus_Done(handle) __Mus_Done(DoomSndBase, (handle))

VOID __Sfx_StartLoop(__reg("a6") struct Library * , __reg("a0") BYTE * wave , __reg("d0") LONG cnum , __reg("d1") LONG step , __reg("d2") LONG vol , __reg("d3") LONG sep , __reg("d4") LONG length , __reg("d5") LONG loop ) = "\tjsr\t-108(a6)";
#define Sfx_StartLoop(wave, cnum, step, vol, sep, length, loop) __Sfx_StartLoop(DoomSndBase, (wave), (cnum), (step), (vol), (sep), (length), (loop))

VOID __Sfx_UpdatePitch(__reg("a6") struct Library * , __reg("d0") LONG cnum , __reg("d1") LONG step ) = "\tjsr\t-114(a6)";
#define Sfx_UpdatePitch(cnum, step) __Sfx_UpdatePitch(DoomSndBase, (cnum), (step))

VOID __Sfx_UpdateVol(__reg("a6") struct Library * , __reg("d0") LONG cnum , __reg("d2") LONG vol , __reg("d3") LONG sep ) = "\tjsr\t-120(a6)";
#define Sfx_UpdateVol(cnum, vol, sep) __Sfx_UpdateVol(DoomSndBase, (cnum), (vol), (sep))

#endif /* !_INLINE_DOOMSOUND_H */
