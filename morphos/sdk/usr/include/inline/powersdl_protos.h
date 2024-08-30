/* Automatically generated header! Do not edit! */

#ifndef _VBCCINLINE_POWERSDL_H
#define _VBCCINLINE_POWERSDL_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

int  __SDL_JoystickNumHats(void *, SDL_Joystick *) =
	"\tlwz\t0,-526(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickNumHats(__p0) __SDL_JoystickNumHats(PowerSDLBase, (__p0))

Uint8  __SDL_GetMouseState(void *, int *, int *) =
	"\tlwz\t0,-616(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetMouseState(__p0, __p1) __SDL_GetMouseState(PowerSDLBase, (__p0), (__p1))

SDL_bool  __SDL_HasAltiVec(void *) =
	"\tlwz\t0,-1096(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasAltiVec() __SDL_HasAltiVec(PowerSDLBase)

Sint16  __SDL_JoystickGetAxis(void *, SDL_Joystick *, int ) =
	"\tlwz\t0,-550(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickGetAxis(__p0, __p1) __SDL_JoystickGetAxis(PowerSDLBase, (__p0), (__p1))

Uint32  __SDL_GetThreadID(void *, SDL_Thread *) =
	"\tlwz\t0,-784(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetThreadID(__p0) __SDL_GetThreadID(PowerSDLBase, (__p0))

void  __SDL_GetClipRect(void *, SDL_Surface *, SDL_Rect *) =
	"\tlwz\t0,-274(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetClipRect(__p0, __p1) __SDL_GetClipRect(PowerSDLBase, (__p0), (__p1))

void  __SDL_OpenPrefs(void *) =
	"\tlwz\t0,-1156(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_OpenPrefs() __SDL_OpenPrefs(PowerSDLBase)

SDL_bool  __SDL_SetClipRect(void *, SDL_Surface *, const SDL_Rect *) =
	"\tlwz\t0,-268(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetClipRect(__p0, __p1) __SDL_SetClipRect(PowerSDLBase, (__p0), (__p1))

int  __SDL_CDNumDrives(void *) =
	"\tlwz\t0,-832(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDNumDrives() __SDL_CDNumDrives(PowerSDLBase)

int  __SDL_CDStop(void *, SDL_CD *) =
	"\tlwz\t0,-874(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDStop(__p0) __SDL_CDStop(PowerSDLBase, (__p0))

void  __SDL_SetCursor(void *, SDL_Cursor *) =
	"\tlwz\t0,-640(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetCursor(__p0) __SDL_SetCursor(PowerSDLBase, (__p0))

int  __SDL_LowerBlit(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *) =
	"\tlwz\t0,-1144(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LowerBlit(__p0, __p1, __p2, __p3) __SDL_LowerBlit(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

int  __SDL_ShowCursor(void *, int ) =
	"\tlwz\t0,-658(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ShowCursor(__p0) __SDL_ShowCursor(PowerSDLBase, (__p0))

SDL_bool  __SDL_RemoveTimer(void *, SDL_TimerID ) =
	"\tlwz\t0,-430(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_RemoveTimer(__p0) __SDL_RemoveTimer(PowerSDLBase, (__p0))

SDL_bool  __SDL_HasMMXExt(void *) =
	"\tlwz\t0,-1126(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasMMXExt() __SDL_HasMMXExt(PowerSDLBase)

int  __SDL_SetGamma(void *, float , float , float ) =
	"\tlwz\t0,-184(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetGamma(__p0, __p1, __p2) __SDL_SetGamma(PowerSDLBase, (__p0), (__p1), (__p2))

SDL_CD * __SDL_CDOpen(void *, int ) =
	"\tlwz\t0,-844(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDOpen(__p0) __SDL_CDOpen(PowerSDLBase, (__p0))

Uint8  __SDL_GetRelativeMouseState(void *, int *, int *) =
	"\tlwz\t0,-622(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetRelativeMouseState(__p0, __p1) __SDL_GetRelativeMouseState(PowerSDLBase, (__p0), (__p1))

void  __SDL_GL_UpdateRects(void *, int , SDL_Rect *) =
	"\tlwz\t0,-352(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_UpdateRects(__p0, __p1) __SDL_GL_UpdateRects(PowerSDLBase, (__p0), (__p1))

void  __SDL_UpdateRects(void *, SDL_Surface *, int , SDL_Rect *) =
	"\tlwz\t0,-124(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UpdateRects(__p0, __p1, __p2) __SDL_UpdateRects(PowerSDLBase, (__p0), (__p1), (__p2))

char * __SDL_VideoDriverName(void *, char *, int ) =
	"\tlwz\t0,-160(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_VideoDriverName(__p0, __p1) __SDL_VideoDriverName(PowerSDLBase, (__p0), (__p1))

int  __SDL_LockSurface(void *, SDL_Surface *) =
	"\tlwz\t0,-238(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LockSurface(__p0) __SDL_LockSurface(PowerSDLBase, (__p0))

void  __SDL_CopyAndSwap32(ULONG *, ULONG *, ULONG , void *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1174(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CopyAndSwap32(__p0, __p1, __p2) __SDL_CopyAndSwap32((__p0), (__p1), (__p2), PowerSDLBase)

SDL_cond * __SDL_CreateCond(void *) =
	"\tlwz\t0,-964(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateCond() __SDL_CreateCond(PowerSDLBase)

int  __SDL_PushEvent(void *, SDL_Event *) =
	"\tlwz\t0,-460(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_PushEvent(__p0) __SDL_PushEvent(PowerSDLBase, (__p0))

SDL_Surface * __SDL_DisplayFormat(void *, SDL_Surface *) =
	"\tlwz\t0,-94(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DisplayFormat(__p0) __SDL_DisplayFormat(PowerSDLBase, (__p0))

int  __SDL_CondBroadcast(void *, SDL_cond *) =
	"\tlwz\t0,-982(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CondBroadcast(__p0) __SDL_CondBroadcast(PowerSDLBase, (__p0))

int  __SDL_CDPause(void *, SDL_CD *) =
	"\tlwz\t0,-862(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDPause(__p0) __SDL_CDPause(PowerSDLBase, (__p0))

void  __SDL_PauseAudio(void *, int ) =
	"\tlwz\t0,-718(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_PauseAudio(__p0) __SDL_PauseAudio(PowerSDLBase, (__p0))

Uint8  __SDL_EventState(void *, Uint8 , int ) =
	"\tlwz\t0,-478(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_EventState(__p0, __p1) __SDL_EventState(PowerSDLBase, (__p0), (__p1))

void  __SDL_LockAudio(void *) =
	"\tlwz\t0,-754(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LockAudio() __SDL_LockAudio(PowerSDLBase)

int  __SDL_SetColorKey(void *, SDL_Surface *, Uint32 , Uint32 ) =
	"\tlwz\t0,-256(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetColorKey(__p0, __p1, __p2) __SDL_SetColorKey(PowerSDLBase, (__p0), (__p1), (__p2))

SDL_TimerID  __SDL_AddTimer(void *, Uint32 , SDL_NewTimerCallback , void *) =
	"\tlwz\t0,-424(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AddTimer(__p0, __p1, __p2) __SDL_AddTimer(PowerSDLBase, (__p0), (__p1), (__p2))

SDL_AudioSpec * __SDL_LoadWAV_RW(void *, SDL_RWops *, int , SDL_AudioSpec *, Uint8 **, Uint32 *) =
	"\tlwz\t0,-724(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LoadWAV_RW(__p0, __p1, __p2, __p3, __p4) __SDL_LoadWAV_RW(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

int  __SDL_Flip(void *, SDL_Surface *) =
	"\tlwz\t0,-118(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Flip(__p0) __SDL_Flip(PowerSDLBase, (__p0))

void  __SDL_GetRGBA(void *, Uint32 , SDL_PixelFormat *, Uint8 *, Uint8 *, Uint8 *, Uint8 *) =
	"\tlwz\t0,-220(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetRGBA(__p0, __p1, __p2, __p3, __p4, __p5) __SDL_GetRGBA(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5))

void  __SDL_GetRGB(void *, Uint32 , SDL_PixelFormat *, Uint8 *, Uint8 *, Uint8 *) =
	"\tlwz\t0,-214(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetRGB(__p0, __p1, __p2, __p3, __p4) __SDL_GetRGB(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

SDL_RWops * __SDL_AMIGA_RWFromFile(void *, const char *, const char *) =
	"\tlwz\t0,-820(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AMIGA_RWFromFile(__p0, __p1) __SDL_AMIGA_RWFromFile(PowerSDLBase, (__p0), (__p1))

SDL_bool  __SDL_HasMMX(void *) =
	"\tlwz\t0,-1108(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasMMX() __SDL_HasMMX(PowerSDLBase)

void  __SDL_QuitSubSystem(void *, Uint32 ) =
	"\tlwz\t0,-46(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_QuitSubSystem(__p0) __SDL_QuitSubSystem(PowerSDLBase, (__p0))

void  __SDL_GL_Unlock(void *) =
	"\tlwz\t0,-364(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_Unlock() __SDL_GL_Unlock(PowerSDLBase)

int  __SDL_CondSignal(void *, SDL_cond *) =
	"\tlwz\t0,-976(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CondSignal(__p0) __SDL_CondSignal(PowerSDLBase, (__p0))

void  __SDL_FreeRW(void *, SDL_RWops *) =
	"\tlwz\t0,-82(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FreeRW(__p0) __SDL_FreeRW(PowerSDLBase, (__p0))

const SDL_version * __SDL_Linked_Version(void *) =
	"\tlwz\t0,-802(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Linked_Version() __SDL_Linked_Version(PowerSDLBase)

void  __SDL_CloseAudio(void *) =
	"\tlwz\t0,-766(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CloseAudio() __SDL_CloseAudio(PowerSDLBase)

SDL_RWops * __SDL_AMIGA_RWFromFP(void *, BPTR , int ) =
	"\tlwz\t0,-826(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AMIGA_RWFromFP(__p0, __p1) __SDL_AMIGA_RWFromFP(PowerSDLBase, (__p0), (__p1))

Uint32  __SDL_ReadBE32(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1024(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadBE32(__p0) __SDL_ReadBE32((__p0))

SDL_Surface * __SDL_SetVideoMode(void *, int , int , int , Uint32 ) =
	"\tlwz\t0,-142(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetVideoMode(__p0, __p1, __p2, __p3) __SDL_SetVideoMode(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

SDL_bool  __SDL_HasSSE(void *) =
	"\tlwz\t0,-1120(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasSSE() __SDL_HasSSE(PowerSDLBase)

int  __SDL_GL_GetAttribute(void *, SDL_GLattr , int *) =
	"\tlwz\t0,-340(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_GetAttribute(__p0, __p1) __SDL_GL_GetAttribute(PowerSDLBase, (__p0), (__p1))

char * __SDL_GetKeyName(void *, SDLKey ) =
	"\tlwz\t0,-610(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetKeyName(__p0) __SDL_GetKeyName(PowerSDLBase, (__p0))

int  __SDL_Init(void *, Uint32 ) =
	"\tlwz\t0,-28(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Init(__p0) __SDL_Init(PowerSDLBase, (__p0))

int  __SDL_JoystickGetBall(void *, SDL_Joystick *, int , int *, int *) =
	"\tlwz\t0,-562(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickGetBall(__p0, __p1, __p2, __p3) __SDL_JoystickGetBall(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

SDL_GrabMode  __SDL_WM_GrabInput(void *, SDL_GrabMode ) =
	"\tlwz\t0,-400(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_GrabInput(__p0) __SDL_WM_GrabInput(PowerSDLBase, (__p0))

SDL_bool  __SDL_HasRDTSC(void *) =
	"\tlwz\t0,-1102(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasRDTSC() __SDL_HasRDTSC(PowerSDLBase)

void  __SDL_UnlockSurface(void *, SDL_Surface *) =
	"\tlwz\t0,-244(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UnlockSurface(__p0) __SDL_UnlockSurface(PowerSDLBase, (__p0))

#ifdef SYSTEM_PRIVATE
void * __SDLP_malloc(void *, size_t ) =
	"\tlwz\t0,-1078(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDLP_malloc(__p0) __SDLP_malloc(PowerSDLBase, (__p0))
#endif /* SYSTEM_PRIVATE */

int  __SDL_SetPalette(void *, SDL_Surface *, int , SDL_Color *, int , int ) =
	"\tlwz\t0,-208(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetPalette(__p0, __p1, __p2, __p3, __p4) __SDL_SetPalette(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

#ifdef SYSTEM_PRIVATE
SDL_RWops * __SDLP_RWFromFPhack(void *, void *, int , int (*)(struct SDL_RWops *, int, int), int (*)(struct SDL_RWops *, void *, int, int), int (*)(struct SDL_RWops *, const void *, int, int), int (*)(struct SDL_RWops *)) =
	"\tlwz\t0,-1162(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDLP_RWFromFPhack(__p0, __p1, __p2, __p3, __p4, __p5) __SDLP_RWFromFPhack(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5))
#endif /* SYSTEM_PRIVATE */

void  __SDL_PumpEvents(void *) =
	"\tlwz\t0,-436(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_PumpEvents() __SDL_PumpEvents(PowerSDLBase)

int  __SDL_WriteBE64(SDL_RWops *, Uint64 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1072(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteBE64(__p0, __p1) __SDL_WriteBE64((__p0), (__p1))

Uint64  __SDL_ReadLE64(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1030(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadLE64(__p0) __SDL_ReadLE64((__p0))

void  __SDL_DestroyCond(void *, SDL_cond *) =
	"\tlwz\t0,-970(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DestroyCond(__p0) __SDL_DestroyCond(PowerSDLBase, (__p0))

int  __SDL_WriteLE16(SDL_RWops *, Uint16 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1042(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteLE16(__p0, __p1) __SDL_WriteLE16((__p0), (__p1))

SDL_Cursor * __SDL_CreateCursor(void *, Uint8 *, Uint8 *, int , int , int , int ) =
	"\tlwz\t0,-634(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateCursor(__p0, __p1, __p2, __p3, __p4, __p5) __SDL_CreateCursor(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5))

int  __SDL_OpenAudio(void *, SDL_AudioSpec *, SDL_AudioSpec *) =
	"\tlwz\t0,-706(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_OpenAudio(__p0, __p1) __SDL_OpenAudio(PowerSDLBase, (__p0), (__p1))

Uint8  __SDL_JoystickGetButton(void *, SDL_Joystick *, int ) =
	"\tlwz\t0,-568(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickGetButton(__p0, __p1) __SDL_JoystickGetButton(PowerSDLBase, (__p0), (__p1))

void  __SDL_WaitThread(void *, SDL_Thread *, int *) =
	"\tlwz\t0,-790(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WaitThread(__p0, __p1) __SDL_WaitThread(PowerSDLBase, (__p0), (__p1))

void  __SDL_JoystickClose(void *, SDL_Joystick *) =
	"\tlwz\t0,-574(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickClose(__p0) __SDL_JoystickClose(PowerSDLBase, (__p0))

Uint32  __SDL_GetTicks(void *) =
	"\tlwz\t0,-406(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetTicks() __SDL_GetTicks(PowerSDLBase)

SDL_Surface * __SDL_DisplayFormatAlpha(void *, SDL_Surface *) =
	"\tlwz\t0,-286(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DisplayFormatAlpha(__p0) __SDL_DisplayFormatAlpha(PowerSDLBase, (__p0))

int  __SDL_GetGammaRamp(void *, Uint16 *, Uint16 *, Uint16 *) =
	"\tlwz\t0,-196(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetGammaRamp(__p0, __p1, __p2) __SDL_GetGammaRamp(PowerSDLBase, (__p0), (__p1), (__p2))

Uint32  __SDL_WasInit(void *, Uint32 ) =
	"\tlwz\t0,-52(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WasInit(__p0) __SDL_WasInit(PowerSDLBase, (__p0))

void  __SDL_Delay(void *, Uint32 ) =
	"\tlwz\t0,-412(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Delay(__p0) __SDL_Delay(PowerSDLBase, (__p0))

void  __SDL_JoystickUpdate(void *) =
	"\tlwz\t0,-538(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickUpdate() __SDL_JoystickUpdate(PowerSDLBase)

int  __SDL_JoystickEventState(void *, int ) =
	"\tlwz\t0,-544(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickEventState(__p0) __SDL_JoystickEventState(PowerSDLBase, (__p0))

const char * __SDL_JoystickName(void *, int ) =
	"\tlwz\t0,-490(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickName(__p0) __SDL_JoystickName(PowerSDLBase, (__p0))

SDL_bool  __SDL_Has3DNowExt(void *) =
	"\tlwz\t0,-1132(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Has3DNowExt() __SDL_Has3DNowExt(PowerSDLBase)

void  __SDL_InitTGL(void *, void **, void **) =
	"\tlwz\t0,-1000(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_InitTGL(__p0, __p1) __SDL_InitTGL(PowerSDLBase, (__p0), (__p1))

void  __SDL_WarpMouse(void *, Uint16 , Uint16 ) =
	"\tlwz\t0,-628(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WarpMouse(__p0, __p1) __SDL_WarpMouse(PowerSDLBase, (__p0), (__p1))

int  __SDL_SemWait(void *, SDL_sem *) =
	"\tlwz\t0,-940(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SemWait(__p0) __SDL_SemWait(PowerSDLBase, (__p0))

void  __SDL_UnlockAudio(void *) =
	"\tlwz\t0,-760(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UnlockAudio() __SDL_UnlockAudio(PowerSDLBase)

int  __SDL_CondWaitTimeout(void *, SDL_cond *, SDL_mutex *, Uint32 ) =
	"\tlwz\t0,-988(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CondWaitTimeout(__p0, __p1, __p2) __SDL_CondWaitTimeout(PowerSDLBase, (__p0), (__p1), (__p2))

CDstatus  __SDL_CDStatus(void *, SDL_CD *) =
	"\tlwz\t0,-850(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDStatus(__p0) __SDL_CDStatus(PowerSDLBase, (__p0))

SDL_EventFilter  __SDL_GetEventFilter(void *) =
	"\tlwz\t0,-472(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetEventFilter() __SDL_GetEventFilter(PowerSDLBase)

int  __SDL_SetAlpha(void *, SDL_Surface *, Uint32 , Uint8 ) =
	"\tlwz\t0,-262(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetAlpha(__p0, __p1, __p2) __SDL_SetAlpha(PowerSDLBase, (__p0), (__p1), (__p2))

int  __SDL_JoystickIndex(void *, SDL_Joystick *) =
	"\tlwz\t0,-508(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickIndex(__p0) __SDL_JoystickIndex(PowerSDLBase, (__p0))

Uint32  __SDL_MapRGBA(void *, SDL_PixelFormat *, Uint8 , Uint8 , Uint8 , Uint8 ) =
	"\tlwz\t0,-154(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_MapRGBA(__p0, __p1, __p2, __p3, __p4) __SDL_MapRGBA(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

Uint32  __SDL_MapRGB(void *, SDL_PixelFormat *, Uint8 , Uint8 , Uint8 ) =
	"\tlwz\t0,-148(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_MapRGB(__p0, __p1, __p2, __p3) __SDL_MapRGB(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

int  __SDL_VideoModeOK(void *, int , int , int , Uint32 ) =
	"\tlwz\t0,-172(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_VideoModeOK(__p0, __p1, __p2, __p3) __SDL_VideoModeOK(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

int  __SDL_EnableKeyRepeat(void *, int , int ) =
	"\tlwz\t0,-586(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_EnableKeyRepeat(__p0, __p1) __SDL_EnableKeyRepeat(PowerSDLBase, (__p0), (__p1))

SDL_Surface * __SDL_CreateRGBSurfaceFrom(void *, void *, int , int , int , int , Uint32 , Uint32 , Uint32 , Uint32 ) =
	"\tlwz\t0,-232(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateRGBSurfaceFrom(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) __SDL_CreateRGBSurfaceFrom(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5), (__p6), (__p7), (__p8))

SDL_Overlay * __SDL_CreateYUVOverlay(void *, int , int , Uint32 , SDL_Surface *) =
	"\tlwz\t0,-292(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateYUVOverlay(__p0, __p1, __p2, __p3) __SDL_CreateYUVOverlay(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

int  __SDL_PeepEvents(void *, SDL_Event *, int , SDL_eventaction , Uint32 ) =
	"\tlwz\t0,-454(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_PeepEvents(__p0, __p1, __p2, __p3) __SDL_PeepEvents(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

void  __SDL_DestroySemaphore(void *, SDL_sem *) =
	"\tlwz\t0,-922(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DestroySemaphore(__p0) __SDL_DestroySemaphore(PowerSDLBase, (__p0))

int  __SDL_SemTryWait(void *, SDL_sem *) =
	"\tlwz\t0,-928(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SemTryWait(__p0) __SDL_SemTryWait(PowerSDLBase, (__p0))

void  __SDL_GL_Lock(void *) =
	"\tlwz\t0,-358(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_Lock() __SDL_GL_Lock(PowerSDLBase)

char * __SDL_GetError(void *) =
	"\tlwz\t0,-676(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetError() __SDL_GetError(PowerSDLBase)

void  __SDL_FreeSurface(void *, SDL_Surface *) =
	"\tlwz\t0,-100(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FreeSurface(__p0) __SDL_FreeSurface(PowerSDLBase, (__p0))

int  __SDL_CDResume(void *, SDL_CD *) =
	"\tlwz\t0,-868(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDResume(__p0) __SDL_CDResume(PowerSDLBase, (__p0))

Uint32  __SDL_ThreadID(void *) =
	"\tlwz\t0,-778(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ThreadID() __SDL_ThreadID(PowerSDLBase)

const SDL_VideoInfo * __SDL_GetVideoInfo(void *) =
	"\tlwz\t0,-136(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetVideoInfo() __SDL_GetVideoInfo(PowerSDLBase)

int  __SDL_WaitEvent(void *, SDL_Event *) =
	"\tlwz\t0,-448(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WaitEvent(__p0) __SDL_WaitEvent(PowerSDLBase, (__p0))

SDL_bool  __SDL_Has3DNow(void *) =
	"\tlwz\t0,-1114(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Has3DNow() __SDL_Has3DNow(PowerSDLBase)

int  __SDL_WriteLE32(SDL_RWops *, Uint32 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1054(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteLE32(__p0, __p1) __SDL_WriteLE32((__p0), (__p1))

void  __SDL_UnlockYUVOverlay(void *, SDL_Overlay *) =
	"\tlwz\t0,-304(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UnlockYUVOverlay(__p0) __SDL_UnlockYUVOverlay(PowerSDLBase, (__p0))

int  __SDL_JoystickNumAxes(void *, SDL_Joystick *) =
	"\tlwz\t0,-514(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickNumAxes(__p0) __SDL_JoystickNumAxes(PowerSDLBase, (__p0))

int  __SDL_EnableUNICODE(void *, int ) =
	"\tlwz\t0,-580(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_EnableUNICODE(__p0) __SDL_EnableUNICODE(PowerSDLBase, (__p0))

int  __SDL_mutexP(void *, SDL_mutex *) =
	"\tlwz\t0,-904(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_mutexP(__p0) __SDL_mutexP(PowerSDLBase, (__p0))

Uint32  __SDL_SemValue(void *, SDL_sem *) =
	"\tlwz\t0,-946(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SemValue(__p0) __SDL_SemValue(PowerSDLBase, (__p0))

void  __SDL_SetEventFilter(void *, SDL_EventFilter ) =
	"\tlwz\t0,-466(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetEventFilter(__p0) __SDL_SetEventFilter(PowerSDLBase, (__p0))

int  __SDL_BuildAudioCVT(void *, SDL_AudioCVT *, Uint16 , Uint8 , int , Uint16 , Uint8 , int ) =
	"\tlwz\t0,-736(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_BuildAudioCVT(__p0, __p1, __p2, __p3, __p4, __p5, __p6) __SDL_BuildAudioCVT(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5), (__p6))

SDL_Surface * __SDL_GetVideoSurface(void *) =
	"\tlwz\t0,-166(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetVideoSurface() __SDL_GetVideoSurface(PowerSDLBase)

int  __SDL_mutexV(void *, SDL_mutex *) =
	"\tlwz\t0,-910(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_mutexV(__p0) __SDL_mutexV(PowerSDLBase, (__p0))

const char * __SDL_CDName(void *, int ) =
	"\tlwz\t0,-838(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDName(__p0) __SDL_CDName(PowerSDLBase, (__p0))

SDL_Rect ** __SDL_ListModes(void *, SDL_PixelFormat *, Uint32 ) =
	"\tlwz\t0,-178(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ListModes(__p0, __p1) __SDL_ListModes(PowerSDLBase, (__p0), (__p1))

char * __SDL_AudioDriverName(void *, char *, int ) =
	"\tlwz\t0,-700(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AudioDriverName(__p0, __p1) __SDL_AudioDriverName(PowerSDLBase, (__p0), (__p1))

int  __SDL_WriteBE16(SDL_RWops *, Uint16 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1048(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteBE16(__p0, __p1) __SDL_WriteBE16((__p0), (__p1))

Uint64  __SDL_ReadBE64(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1036(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadBE64(__p0) __SDL_ReadBE64((__p0))

Uint16  __SDL_ReadLE16(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1006(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadLE16(__p0) __SDL_ReadLE16((__p0))

SDL_Surface * __SDL_ConvertSurface(void *, SDL_Surface *, SDL_PixelFormat *, Uint32 ) =
	"\tlwz\t0,-280(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ConvertSurface(__p0, __p1, __p2) __SDL_ConvertSurface(PowerSDLBase, (__p0), (__p1), (__p2))

int  __SDL_SoftStretch(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *) =
	"\tlwz\t0,-808(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SoftStretch(__p0, __p1, __p2, __p3) __SDL_SoftStretch(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

void  __SDL_FreeYUVOverlay(void *, SDL_Overlay *) =
	"\tlwz\t0,-316(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FreeYUVOverlay(__p0) __SDL_FreeYUVOverlay(PowerSDLBase, (__p0))

SDL_RWops * __SDL_RWFromFile(void *, const char *, const char *) =
	"\tlwz\t0,-58(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_RWFromFile(__p0, __p1) __SDL_RWFromFile(PowerSDLBase, (__p0), (__p1))

SDL_Surface * __SDL_CreateRGBSurface(void *, Uint32 , int , int , int , Uint32 , Uint32 , Uint32 , Uint32 ) =
	"\tlwz\t0,-226(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateRGBSurface(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) __SDL_CreateRGBSurface(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4), (__p5), (__p6), (__p7))

SDL_RWops * __SDL_AllocRW(void *) =
	"\tlwz\t0,-76(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AllocRW() __SDL_AllocRW(PowerSDLBase)

SDL_Cursor * __SDL_GetCursor(void *) =
	"\tlwz\t0,-646(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetCursor() __SDL_GetCursor(PowerSDLBase)

SDLMod  __SDL_GetModState(void *) =
	"\tlwz\t0,-598(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetModState() __SDL_GetModState(PowerSDLBase)

void  __SDL_SetModState(void *, SDLMod ) =
	"\tlwz\t0,-604(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetModState(__p0) __SDL_SetModState(PowerSDLBase, (__p0))

#ifdef SYSTEM_PRIVATE
void  __SDLP_free(void *, void *) =
	"\tlwz\t0,-1084(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDLP_free(__p0) __SDLP_free(PowerSDLBase, (__p0))
#endif /* SYSTEM_PRIVATE */

int  __SDL_CDPlayTracks(void *, SDL_CD *, int , int , int , int ) =
	"\tlwz\t0,-1150(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDPlayTracks(__p0, __p1, __p2, __p3, __p4) __SDL_CDPlayTracks(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

const char * __SDL_UNIX2AMIGA(void *, const char *) =
	"\tlwz\t0,-814(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UNIX2AMIGA(__p0) __SDL_UNIX2AMIGA(PowerSDLBase, (__p0))

void  __SDL_DestroyMutex(void *, SDL_mutex *) =
	"\tlwz\t0,-898(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DestroyMutex(__p0) __SDL_DestroyMutex(PowerSDLBase, (__p0))

int  __SDL_InitSubSystem(void *, Uint32 ) =
	"\tlwz\t0,-40(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_InitSubSystem(__p0) __SDL_InitSubSystem(PowerSDLBase, (__p0))

SDL_bool  __SDL_HasSSE2(void *) =
	"\tlwz\t0,-1138(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_HasSSE2() __SDL_HasSSE2(PowerSDLBase)

void  __SDL_UpdateRect(void *, SDL_Surface *, Sint32 , Sint32 , Uint32 , Uint32 ) =
	"\tlwz\t0,-130(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UpdateRect(__p0, __p1, __p2, __p3, __p4) __SDL_UpdateRect(PowerSDLBase, (__p0), (__p1), (__p2), (__p3), (__p4))

int  __SDL_SetColors(void *, SDL_Surface *, SDL_Color *, int , int ) =
	"\tlwz\t0,-202(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetColors(__p0, __p1, __p2, __p3) __SDL_SetColors(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

void  __SDL_GL_SwapBuffers(void *) =
	"\tlwz\t0,-346(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_SwapBuffers() __SDL_GL_SwapBuffers(PowerSDLBase)

int  __SDL_WM_IconifyWindow(void *) =
	"\tlwz\t0,-388(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_IconifyWindow() __SDL_WM_IconifyWindow(PowerSDLBase)

void  __SDL_Error(void *, SDL_errorcode ) =
	"\tlwz\t0,-958(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_Error(__p0) __SDL_Error(PowerSDLBase, (__p0))

SDL_Thread * __SDL_CreateThread(void *, int (*)(void *), void *) =
	"\tlwz\t0,-772(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateThread(__p0, __p1) __SDL_CreateThread(PowerSDLBase, (__p0), (__p1))

Uint8  __SDL_GetAppState(void *) =
	"\tlwz\t0,-664(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetAppState() __SDL_GetAppState(PowerSDLBase)

int  __SDL_LockYUVOverlay(void *, SDL_Overlay *) =
	"\tlwz\t0,-298(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LockYUVOverlay(__p0) __SDL_LockYUVOverlay(PowerSDLBase, (__p0))

void  __SDL_AudioQuit(void *) =
	"\tlwz\t0,-694(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AudioQuit() __SDL_AudioQuit(PowerSDLBase)

void  __SDL_CDClose(void *, SDL_CD *) =
	"\tlwz\t0,-886(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDClose(__p0) __SDL_CDClose(PowerSDLBase, (__p0))

int  __SDL_SetTimer(void *, Uint32 , SDL_TimerCallback ) =
	"\tlwz\t0,-418(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetTimer(__p0, __p1) __SDL_SetTimer(PowerSDLBase, (__p0), (__p1))

void  __SDL_FreeCursor(void *, SDL_Cursor *) =
	"\tlwz\t0,-652(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FreeCursor(__p0) __SDL_FreeCursor(PowerSDLBase, (__p0))

int  __SDL_JoystickOpened(void *, int ) =
	"\tlwz\t0,-502(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickOpened(__p0) __SDL_JoystickOpened(PowerSDLBase, (__p0))

int  __SDL_FillRect(void *, SDL_Surface *, SDL_Rect *, Uint32 ) =
	"\tlwz\t0,-106(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FillRect(__p0, __p1, __p2) __SDL_FillRect(PowerSDLBase, (__p0), (__p1), (__p2))

int  __SDL_SemPost(void *, SDL_sem *) =
	"\tlwz\t0,-952(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SemPost(__p0) __SDL_SemPost(PowerSDLBase, (__p0))

int  __SDL_WM_ToggleFullScreen(void *, SDL_Surface *) =
	"\tlwz\t0,-394(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_ToggleFullScreen(__p0) __SDL_WM_ToggleFullScreen(PowerSDLBase, (__p0))

#ifdef SYSTEM_PRIVATE
void * __SDLP_realloc(void *, void *, size_t ) =
	"\tlwz\t0,-1090(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDLP_realloc(__p0, __p1) __SDLP_realloc(PowerSDLBase, (__p0), (__p1))
#endif /* SYSTEM_PRIVATE */

int  __SDL_GL_SetAttribute(void *, SDL_GLattr , int ) =
	"\tlwz\t0,-334(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_SetAttribute(__p0, __p1) __SDL_GL_SetAttribute(PowerSDLBase, (__p0), (__p1))

int  __SDL_JoystickNumButtons(void *, SDL_Joystick *) =
	"\tlwz\t0,-532(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickNumButtons(__p0) __SDL_JoystickNumButtons(PowerSDLBase, (__p0))

int  __SDL_CondWait(void *, SDL_cond *, SDL_mutex *) =
	"\tlwz\t0,-994(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CondWait(__p0, __p1) __SDL_CondWait(PowerSDLBase, (__p0), (__p1))

int  __SDL_CDEject(void *, SDL_CD *) =
	"\tlwz\t0,-880(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDEject(__p0) __SDL_CDEject(PowerSDLBase, (__p0))

SDL_RWops * __SDL_RWFromMem(void *, void *, int ) =
	"\tlwz\t0,-70(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_RWFromMem(__p0, __p1) __SDL_RWFromMem(PowerSDLBase, (__p0), (__p1))

void  __SDL_ClearError(void *) =
	"\tlwz\t0,-682(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ClearError() __SDL_ClearError(PowerSDLBase)

void  __SDL_FreeWAV(void *, Uint8 *) =
	"\tlwz\t0,-730(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_FreeWAV(__p0) __SDL_FreeWAV(PowerSDLBase, (__p0))

int  __SDL_CDPlay(void *, SDL_CD *, int , int ) =
	"\tlwz\t0,-856(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CDPlay(__p0, __p1, __p2) __SDL_CDPlay(PowerSDLBase, (__p0), (__p1), (__p2))

#if defined(USE_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void  __SDL_SetError(void *, const char *, ...) =
	"\tlwz\t0,-670(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetError(...) __SDL_SetError(PowerSDLBase, __VA_ARGS__)
#endif

int  __SDL_UpperBlit(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *) =
	"\tlwz\t0,-112(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_UpperBlit(__p0, __p1, __p2, __p3) __SDL_UpperBlit(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

void  __SDL_MixAudio(void *, Uint8 *, const Uint8 *, Uint32 , int ) =
	"\tlwz\t0,-748(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_MixAudio(__p0, __p1, __p2, __p3) __SDL_MixAudio(PowerSDLBase, (__p0), (__p1), (__p2), (__p3))

void  __SDL_RealQuit(void *) =
	"\tlwz\t0,-34(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_RealQuit() __SDL_RealQuit(PowerSDLBase)

Uint32  __SDL_ReadLE32(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1018(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadLE32(__p0) __SDL_ReadLE32((__p0))

int  __SDL_WriteBE32(SDL_RWops *, Uint32 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1060(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteBE32(__p0, __p1) __SDL_WriteBE32((__p0), (__p1))

int  __SDL_SetGammaRamp(void *, const Uint16 *, const Uint16 *, const Uint16 *) =
	"\tlwz\t0,-190(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SetGammaRamp(__p0, __p1, __p2) __SDL_SetGammaRamp(PowerSDLBase, (__p0), (__p1), (__p2))

void  __SDL_WM_SetCaption(void *, const char *, const char *) =
	"\tlwz\t0,-370(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_SetCaption(__p0, __p1) __SDL_WM_SetCaption(PowerSDLBase, (__p0), (__p1))

int  __SDL_SemWaitTimeout(void *, SDL_sem *, Uint32 ) =
	"\tlwz\t0,-934(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SemWaitTimeout(__p0, __p1) __SDL_SemWaitTimeout(PowerSDLBase, (__p0), (__p1))

void  __SDL_CopyAndSwap16(UWORD *, UWORD *, ULONG , void *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1168(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CopyAndSwap16(__p0, __p1, __p2) __SDL_CopyAndSwap16((__p0), (__p1), (__p2), PowerSDLBase)

int  __SDL_JoystickNumBalls(void *, SDL_Joystick *) =
	"\tlwz\t0,-520(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickNumBalls(__p0) __SDL_JoystickNumBalls(PowerSDLBase, (__p0))

SDL_sem * __SDL_CreateSemaphore(void *, Uint32 ) =
	"\tlwz\t0,-916(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateSemaphore(__p0) __SDL_CreateSemaphore(PowerSDLBase, (__p0))

SDL_Joystick * __SDL_JoystickOpen(void *, int ) =
	"\tlwz\t0,-496(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickOpen(__p0) __SDL_JoystickOpen(PowerSDLBase, (__p0))

int  __SDL_SaveBMP_RW(void *, SDL_Surface *, SDL_RWops *, int ) =
	"\tlwz\t0,-250(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_SaveBMP_RW(__p0, __p1, __p2) __SDL_SaveBMP_RW(PowerSDLBase, (__p0), (__p1), (__p2))

int  __SDL_AudioInit(void *, const char *) =
	"\tlwz\t0,-688(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_AudioInit(__p0) __SDL_AudioInit(PowerSDLBase, (__p0))

void  __SDL_WM_GetCaption(void *, char **, char **) =
	"\tlwz\t0,-376(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_GetCaption(__p0, __p1) __SDL_WM_GetCaption(PowerSDLBase, (__p0), (__p1))

Uint8  __SDL_JoystickGetHat(void *, SDL_Joystick *, int ) =
	"\tlwz\t0,-556(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_JoystickGetHat(__p0, __p1) __SDL_JoystickGetHat(PowerSDLBase, (__p0), (__p1))

void * __SDL_GL_GetProcAddress(void *, const char *) =
	"\tlwz\t0,-328(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_GetProcAddress(__p0) __SDL_GL_GetProcAddress(PowerSDLBase, (__p0))

SDL_Surface * __SDL_LoadBMP_RW(void *, SDL_RWops *, int ) =
	"\tlwz\t0,-88(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_LoadBMP_RW(__p0, __p1) __SDL_LoadBMP_RW(PowerSDLBase, (__p0), (__p1))

int  __SDL_DisplayYUVOverlay(void *, SDL_Overlay *, SDL_Rect *) =
	"\tlwz\t0,-310(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_DisplayYUVOverlay(__p0, __p1) __SDL_DisplayYUVOverlay(PowerSDLBase, (__p0), (__p1))

int  __SDL_GL_LoadLibrary(void *, const char *) =
	"\tlwz\t0,-322(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GL_LoadLibrary(__p0) __SDL_GL_LoadLibrary(PowerSDLBase, (__p0))

int  __SDL_WriteLE64(SDL_RWops *, Uint64 ) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1066(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WriteLE64(__p0, __p1) __SDL_WriteLE64((__p0), (__p1))

Uint8 * __SDL_GetKeyState(void *, int *) =
	"\tlwz\t0,-592(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetKeyState(__p0) __SDL_GetKeyState(PowerSDLBase, (__p0))

int  __SDL_ConvertAudio(void *, SDL_AudioCVT *) =
	"\tlwz\t0,-742(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ConvertAudio(__p0) __SDL_ConvertAudio(PowerSDLBase, (__p0))

int  __SDL_NumJoysticks(void *) =
	"\tlwz\t0,-484(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_NumJoysticks() __SDL_NumJoysticks(PowerSDLBase)

Uint16  __SDL_ReadBE16(SDL_RWops *) =
	"\tlis\t11,PowerSDLBase@ha\n"
	"\tlwz\t12,PowerSDLBase@l(11)\n"
	"\tlwz\t0,-1012(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_ReadBE16(__p0) __SDL_ReadBE16((__p0))

SDL_audiostatus  __SDL_GetAudioStatus(void *) =
	"\tlwz\t0,-712(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_GetAudioStatus() __SDL_GetAudioStatus(PowerSDLBase)

SDL_mutex * __SDL_CreateMutex(void *) =
	"\tlwz\t0,-892(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_CreateMutex() __SDL_CreateMutex(PowerSDLBase)

int  __SDL_PollEvent(void *, SDL_Event *) =
	"\tlwz\t0,-442(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_PollEvent(__p0) __SDL_PollEvent(PowerSDLBase, (__p0))

void  __SDL_KillThread(void *, SDL_Thread *) =
	"\tlwz\t0,-796(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_KillThread(__p0) __SDL_KillThread(PowerSDLBase, (__p0))

void  __SDL_WM_SetIcon(void *, SDL_Surface *, Uint8 *) =
	"\tlwz\t0,-382(3)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SDL_WM_SetIcon(__p0, __p1) __SDL_WM_SetIcon(PowerSDLBase, (__p0), (__p1))

#endif /* !_VBCCINLINE_POWERSDL_H */
