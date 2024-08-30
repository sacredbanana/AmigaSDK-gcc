/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POWERSDL_H
#define _PPCINLINE_POWERSDL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POWERSDL_BASE_NAME
#define POWERSDL_BASE_NAME PowerSDLBase
#endif /* !POWERSDL_BASE_NAME */

#define SDL_JoystickNumHats(__p0) \
	(((int (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 526))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetMouseState(__p0, __p1) \
	(((Uint8 (*)(void *, int *, int *))*(void**)((long)(POWERSDL_BASE_NAME) - 616))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_HasAltiVec() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1096))((void*)(POWERSDL_BASE_NAME)))

#define SDL_JoystickGetAxis(__p0, __p1) \
	(((Sint16 (*)(void *, SDL_Joystick *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 550))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GetThreadID(__p0) \
	(((Uint32 (*)(void *, SDL_Thread *))*(void**)((long)(POWERSDL_BASE_NAME) - 784))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetClipRect(__p0, __p1) \
	(((void (*)(void *, SDL_Surface *, SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 274))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_OpenPrefs() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1156))((void*)(POWERSDL_BASE_NAME)))

#define SDL_SetClipRect(__p0, __p1) \
	(((SDL_bool (*)(void *, SDL_Surface *, const SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 268))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_CDNumDrives() \
	(((int (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 832))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CDStop(__p0) \
	(((int (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 874))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SetCursor(__p0) \
	(((void (*)(void *, SDL_Cursor *))*(void**)((long)(POWERSDL_BASE_NAME) - 640))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_LowerBlit(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 1144))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_ShowCursor(__p0) \
	(((int (*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 658))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_RemoveTimer(__p0) \
	(((SDL_bool (*)(void *, SDL_TimerID ))*(void**)((long)(POWERSDL_BASE_NAME) - 430))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_HasMMXExt() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1126))((void*)(POWERSDL_BASE_NAME)))

#define SDL_SetGamma(__p0, __p1, __p2) \
	(((int (*)(void *, float , float , float ))*(void**)((long)(POWERSDL_BASE_NAME) - 184))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_CDOpen(__p0) \
	(((SDL_CD *(*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 844))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetRelativeMouseState(__p0, __p1) \
	(((Uint8 (*)(void *, int *, int *))*(void**)((long)(POWERSDL_BASE_NAME) - 622))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GL_UpdateRects(__p0, __p1) \
	(((void (*)(void *, int , SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 352))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_UpdateRects(__p0, __p1, __p2) \
	(((void (*)(void *, SDL_Surface *, int , SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 124))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_VideoDriverName(__p0, __p1) \
	(((char *(*)(void *, char *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 160))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_LockSurface(__p0) \
	(((int (*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 238))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CopyAndSwap32(__p0, __p1, __p2) \
	(((void (*)(ULONG *, ULONG *, ULONG , void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1174))(__p0, __p1, __p2, (void*)(POWERSDL_BASE_NAME)))

#define SDL_CreateCond() \
	(((SDL_cond *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 964))((void*)(POWERSDL_BASE_NAME)))

#define SDL_PushEvent(__p0) \
	(((int (*)(void *, SDL_Event *))*(void**)((long)(POWERSDL_BASE_NAME) - 460))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_DisplayFormat(__p0) \
	(((SDL_Surface *(*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 94))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CondBroadcast(__p0) \
	(((int (*)(void *, SDL_cond *))*(void**)((long)(POWERSDL_BASE_NAME) - 982))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CDPause(__p0) \
	(((int (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 862))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_PauseAudio(__p0) \
	(((void (*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 718))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_EventState(__p0, __p1) \
	(((Uint8 (*)(void *, Uint8 , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 478))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_LockAudio() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 754))((void*)(POWERSDL_BASE_NAME)))

#define SDL_SetColorKey(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_Surface *, Uint32 , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 256))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_AddTimer(__p0, __p1, __p2) \
	(((SDL_TimerID (*)(void *, Uint32 , SDL_NewTimerCallback , void *))*(void**)((long)(POWERSDL_BASE_NAME) - 424))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_LoadWAV_RW(__p0, __p1, __p2, __p3, __p4) \
	(((SDL_AudioSpec *(*)(void *, SDL_RWops *, int , SDL_AudioSpec *, Uint8 **, Uint32 *))*(void**)((long)(POWERSDL_BASE_NAME) - 724))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SDL_Flip(__p0) \
	(((int (*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 118))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetRGBA(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(void *, Uint32 , SDL_PixelFormat *, Uint8 *, Uint8 *, Uint8 *, Uint8 *))*(void**)((long)(POWERSDL_BASE_NAME) - 220))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5))

#define SDL_GetRGB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(void *, Uint32 , SDL_PixelFormat *, Uint8 *, Uint8 *, Uint8 *))*(void**)((long)(POWERSDL_BASE_NAME) - 214))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SDL_AMIGA_RWFromFile(__p0, __p1) \
	(((SDL_RWops *(*)(void *, const char *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 820))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_HasMMX() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1108))((void*)(POWERSDL_BASE_NAME)))

#define SDL_QuitSubSystem(__p0) \
	(((void (*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 46))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GL_Unlock() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 364))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CondSignal(__p0) \
	(((int (*)(void *, SDL_cond *))*(void**)((long)(POWERSDL_BASE_NAME) - 976))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_FreeRW(__p0) \
	(((void (*)(void *, SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 82))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_Linked_Version() \
	(((const SDL_version *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 802))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CloseAudio() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 766))((void*)(POWERSDL_BASE_NAME)))

#define SDL_AMIGA_RWFromFP(__p0, __p1) \
	(((SDL_RWops *(*)(void *, BPTR , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 826))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_ReadBE32(__p0) \
	(((Uint32 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1024))(__p0))

#define SDL_SetVideoMode(__p0, __p1, __p2, __p3) \
	(((SDL_Surface *(*)(void *, int , int , int , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 142))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_HasSSE() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1120))((void*)(POWERSDL_BASE_NAME)))

#define SDL_GL_GetAttribute(__p0, __p1) \
	(((int (*)(void *, SDL_GLattr , int *))*(void**)((long)(POWERSDL_BASE_NAME) - 340))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GetKeyName(__p0) \
	(((char *(*)(void *, SDLKey ))*(void**)((long)(POWERSDL_BASE_NAME) - 610))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_Init(__p0) \
	(((int (*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 28))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickGetBall(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Joystick *, int , int *, int *))*(void**)((long)(POWERSDL_BASE_NAME) - 562))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_WM_GrabInput(__p0) \
	(((SDL_GrabMode (*)(void *, SDL_GrabMode ))*(void**)((long)(POWERSDL_BASE_NAME) - 400))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_HasRDTSC() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1102))((void*)(POWERSDL_BASE_NAME)))

#define SDL_UnlockSurface(__p0) \
	(((void (*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 244))((void*)(POWERSDL_BASE_NAME), __p0))

#ifdef SYSTEM_PRIVATE
#define SDLP_malloc(__p0) \
	(((void *(*)(void *, size_t ))*(void**)((long)(POWERSDL_BASE_NAME) - 1078))((void*)(POWERSDL_BASE_NAME), __p0))
#endif /* SYSTEM_PRIVATE */

#define SDL_SetPalette(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(void *, SDL_Surface *, int , SDL_Color *, int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 208))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#ifdef SYSTEM_PRIVATE
#define SDLP_RWFromFPhack(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((SDL_RWops *(*)(void *, void *, int , int (*)(struct SDL_RWops *, int, int), int (*)(struct SDL_RWops *, void *, int, int), int (*)(struct SDL_RWops *, const void *, int, int), int (*)(struct SDL_RWops *)))*(void**)((long)(POWERSDL_BASE_NAME) - 1162))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5))
#endif /* SYSTEM_PRIVATE */

#define SDL_PumpEvents() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 436))((void*)(POWERSDL_BASE_NAME)))

#define SDL_WriteBE64(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint64 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1072))(__p0, __p1))

#define SDL_ReadLE64(__p0) \
	(((Uint64 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1030))(__p0))

#define SDL_DestroyCond(__p0) \
	(((void (*)(void *, SDL_cond *))*(void**)((long)(POWERSDL_BASE_NAME) - 970))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_WriteLE16(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint16 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1042))(__p0, __p1))

#define SDL_CreateCursor(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((SDL_Cursor *(*)(void *, Uint8 *, Uint8 *, int , int , int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 634))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5))

#define SDL_OpenAudio(__p0, __p1) \
	(((int (*)(void *, SDL_AudioSpec *, SDL_AudioSpec *))*(void**)((long)(POWERSDL_BASE_NAME) - 706))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_JoystickGetButton(__p0, __p1) \
	(((Uint8 (*)(void *, SDL_Joystick *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 568))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_WaitThread(__p0, __p1) \
	(((void (*)(void *, SDL_Thread *, int *))*(void**)((long)(POWERSDL_BASE_NAME) - 790))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_JoystickClose(__p0) \
	(((void (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 574))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetTicks() \
	(((Uint32 (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 406))((void*)(POWERSDL_BASE_NAME)))

#define SDL_DisplayFormatAlpha(__p0) \
	(((SDL_Surface *(*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 286))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetGammaRamp(__p0, __p1, __p2) \
	(((int (*)(void *, Uint16 *, Uint16 *, Uint16 *))*(void**)((long)(POWERSDL_BASE_NAME) - 196))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_WasInit(__p0) \
	(((Uint32 (*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 52))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_Delay(__p0) \
	(((void (*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 412))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickUpdate() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 538))((void*)(POWERSDL_BASE_NAME)))

#define SDL_JoystickEventState(__p0) \
	(((int (*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 544))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickName(__p0) \
	(((const char *(*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 490))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_Has3DNowExt() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1132))((void*)(POWERSDL_BASE_NAME)))

#define SDL_InitTGL(__p0, __p1) \
	(((void (*)(void *, void **, void **))*(void**)((long)(POWERSDL_BASE_NAME) - 1000))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_WarpMouse(__p0, __p1) \
	(((void (*)(void *, Uint16 , Uint16 ))*(void**)((long)(POWERSDL_BASE_NAME) - 628))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_SemWait(__p0) \
	(((int (*)(void *, SDL_sem *))*(void**)((long)(POWERSDL_BASE_NAME) - 940))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_UnlockAudio() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 760))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CondWaitTimeout(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_cond *, SDL_mutex *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 988))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_CDStatus(__p0) \
	(((CDstatus (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 850))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GetEventFilter() \
	(((SDL_EventFilter (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 472))((void*)(POWERSDL_BASE_NAME)))

#define SDL_SetAlpha(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_Surface *, Uint32 , Uint8 ))*(void**)((long)(POWERSDL_BASE_NAME) - 262))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_JoystickIndex(__p0) \
	(((int (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 508))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_MapRGBA(__p0, __p1, __p2, __p3, __p4) \
	(((Uint32 (*)(void *, SDL_PixelFormat *, Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)((long)(POWERSDL_BASE_NAME) - 154))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SDL_MapRGB(__p0, __p1, __p2, __p3) \
	(((Uint32 (*)(void *, SDL_PixelFormat *, Uint8 , Uint8 , Uint8 ))*(void**)((long)(POWERSDL_BASE_NAME) - 148))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_VideoModeOK(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, int , int , int , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 172))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_EnableKeyRepeat(__p0, __p1) \
	(((int (*)(void *, int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 586))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_CreateRGBSurfaceFrom(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((SDL_Surface *(*)(void *, void *, int , int , int , int , Uint32 , Uint32 , Uint32 , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 232))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define SDL_CreateYUVOverlay(__p0, __p1, __p2, __p3) \
	(((SDL_Overlay *(*)(void *, int , int , Uint32 , SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 292))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_PeepEvents(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Event *, int , SDL_eventaction , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 454))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_DestroySemaphore(__p0) \
	(((void (*)(void *, SDL_sem *))*(void**)((long)(POWERSDL_BASE_NAME) - 922))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SemTryWait(__p0) \
	(((int (*)(void *, SDL_sem *))*(void**)((long)(POWERSDL_BASE_NAME) - 928))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_GL_Lock() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 358))((void*)(POWERSDL_BASE_NAME)))

#define SDL_GetError() \
	(((char *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 676))((void*)(POWERSDL_BASE_NAME)))

#define SDL_FreeSurface(__p0) \
	(((void (*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 100))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CDResume(__p0) \
	(((int (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 868))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_ThreadID() \
	(((Uint32 (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 778))((void*)(POWERSDL_BASE_NAME)))

#define SDL_GetVideoInfo() \
	(((const SDL_VideoInfo *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 136))((void*)(POWERSDL_BASE_NAME)))

#define SDL_WaitEvent(__p0) \
	(((int (*)(void *, SDL_Event *))*(void**)((long)(POWERSDL_BASE_NAME) - 448))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_Has3DNow() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1114))((void*)(POWERSDL_BASE_NAME)))

#define SDL_WriteLE32(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1054))(__p0, __p1))

#define SDL_UnlockYUVOverlay(__p0) \
	(((void (*)(void *, SDL_Overlay *))*(void**)((long)(POWERSDL_BASE_NAME) - 304))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickNumAxes(__p0) \
	(((int (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 514))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_EnableUNICODE(__p0) \
	(((int (*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 580))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_mutexP(__p0) \
	(((int (*)(void *, SDL_mutex *))*(void**)((long)(POWERSDL_BASE_NAME) - 904))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SemValue(__p0) \
	(((Uint32 (*)(void *, SDL_sem *))*(void**)((long)(POWERSDL_BASE_NAME) - 946))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SetEventFilter(__p0) \
	(((void (*)(void *, SDL_EventFilter ))*(void**)((long)(POWERSDL_BASE_NAME) - 466))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_BuildAudioCVT(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((int (*)(void *, SDL_AudioCVT *, Uint16 , Uint8 , int , Uint16 , Uint8 , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 736))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define SDL_GetVideoSurface() \
	(((SDL_Surface *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 166))((void*)(POWERSDL_BASE_NAME)))

#define SDL_mutexV(__p0) \
	(((int (*)(void *, SDL_mutex *))*(void**)((long)(POWERSDL_BASE_NAME) - 910))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CDName(__p0) \
	(((const char *(*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 838))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_ListModes(__p0, __p1) \
	(((SDL_Rect **(*)(void *, SDL_PixelFormat *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 178))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_AudioDriverName(__p0, __p1) \
	(((char *(*)(void *, char *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 700))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_WriteBE16(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint16 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1048))(__p0, __p1))

#define SDL_ReadBE64(__p0) \
	(((Uint64 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1036))(__p0))

#define SDL_ReadLE16(__p0) \
	(((Uint16 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1006))(__p0))

#define SDL_ConvertSurface(__p0, __p1, __p2) \
	(((SDL_Surface *(*)(void *, SDL_Surface *, SDL_PixelFormat *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 280))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_SoftStretch(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 808))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_FreeYUVOverlay(__p0) \
	(((void (*)(void *, SDL_Overlay *))*(void**)((long)(POWERSDL_BASE_NAME) - 316))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_RWFromFile(__p0, __p1) \
	(((SDL_RWops *(*)(void *, const char *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 58))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_CreateRGBSurface(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((SDL_Surface *(*)(void *, Uint32 , int , int , int , Uint32 , Uint32 , Uint32 , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 226))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define SDL_AllocRW() \
	(((SDL_RWops *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 76))((void*)(POWERSDL_BASE_NAME)))

#define SDL_GetCursor() \
	(((SDL_Cursor *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 646))((void*)(POWERSDL_BASE_NAME)))

#define SDL_GetModState() \
	(((SDLMod (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 598))((void*)(POWERSDL_BASE_NAME)))

#define SDL_SetModState(__p0) \
	(((void (*)(void *, SDLMod ))*(void**)((long)(POWERSDL_BASE_NAME) - 604))((void*)(POWERSDL_BASE_NAME), __p0))

#ifdef SYSTEM_PRIVATE
#define SDLP_free(__p0) \
	(((void (*)(void *, void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1084))((void*)(POWERSDL_BASE_NAME), __p0))
#endif /* SYSTEM_PRIVATE */

#define SDL_CDPlayTracks(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(void *, SDL_CD *, int , int , int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 1150))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SDL_UNIX2AMIGA(__p0) \
	(((const char *(*)(void *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 814))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_DestroyMutex(__p0) \
	(((void (*)(void *, SDL_mutex *))*(void**)((long)(POWERSDL_BASE_NAME) - 898))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_InitSubSystem(__p0) \
	(((int (*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 40))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_HasSSE2() \
	(((SDL_bool (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1138))((void*)(POWERSDL_BASE_NAME)))

#define SDL_UpdateRect(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(void *, SDL_Surface *, Sint32 , Sint32 , Uint32 , Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 130))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define SDL_SetColors(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Surface *, SDL_Color *, int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 202))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_GL_SwapBuffers() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 346))((void*)(POWERSDL_BASE_NAME)))

#define SDL_WM_IconifyWindow() \
	(((int (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 388))((void*)(POWERSDL_BASE_NAME)))

#define SDL_Error(__p0) \
	(((void (*)(void *, SDL_errorcode ))*(void**)((long)(POWERSDL_BASE_NAME) - 958))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CreateThread(__p0, __p1) \
	(((SDL_Thread *(*)(void *, int (*)(void *), void *))*(void**)((long)(POWERSDL_BASE_NAME) - 772))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GetAppState() \
	(((Uint8 (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 664))((void*)(POWERSDL_BASE_NAME)))

#define SDL_LockYUVOverlay(__p0) \
	(((int (*)(void *, SDL_Overlay *))*(void**)((long)(POWERSDL_BASE_NAME) - 298))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_AudioQuit() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 694))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CDClose(__p0) \
	(((void (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 886))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SetTimer(__p0, __p1) \
	(((int (*)(void *, Uint32 , SDL_TimerCallback ))*(void**)((long)(POWERSDL_BASE_NAME) - 418))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_FreeCursor(__p0) \
	(((void (*)(void *, SDL_Cursor *))*(void**)((long)(POWERSDL_BASE_NAME) - 652))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickOpened(__p0) \
	(((int (*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 502))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_FillRect(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_Surface *, SDL_Rect *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 106))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_SemPost(__p0) \
	(((int (*)(void *, SDL_sem *))*(void**)((long)(POWERSDL_BASE_NAME) - 952))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_WM_ToggleFullScreen(__p0) \
	(((int (*)(void *, SDL_Surface *))*(void**)((long)(POWERSDL_BASE_NAME) - 394))((void*)(POWERSDL_BASE_NAME), __p0))

#ifdef SYSTEM_PRIVATE
#define SDLP_realloc(__p0, __p1) \
	(((void *(*)(void *, void *, size_t ))*(void**)((long)(POWERSDL_BASE_NAME) - 1090))((void*)(POWERSDL_BASE_NAME), __p0, __p1))
#endif /* SYSTEM_PRIVATE */

#define SDL_GL_SetAttribute(__p0, __p1) \
	(((int (*)(void *, SDL_GLattr , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 334))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_JoystickNumButtons(__p0) \
	(((int (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 532))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CondWait(__p0, __p1) \
	(((int (*)(void *, SDL_cond *, SDL_mutex *))*(void**)((long)(POWERSDL_BASE_NAME) - 994))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_CDEject(__p0) \
	(((int (*)(void *, SDL_CD *))*(void**)((long)(POWERSDL_BASE_NAME) - 880))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_RWFromMem(__p0, __p1) \
	(((SDL_RWops *(*)(void *, void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 70))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_ClearError() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 682))((void*)(POWERSDL_BASE_NAME)))

#define SDL_FreeWAV(__p0) \
	(((void (*)(void *, Uint8 *))*(void**)((long)(POWERSDL_BASE_NAME) - 730))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CDPlay(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_CD *, int , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 856))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#if !defined(__STRICT_ANSI__)
#define SDL_SetError(...) \
	(((void (*)(void *, const char *, ...))*(void**)((long)(POWERSDL_BASE_NAME) - 670))((void*)(POWERSDL_BASE_NAME), __VA_ARGS__))
#endif

#define SDL_UpperBlit(__p0, __p1, __p2, __p3) \
	(((int (*)(void *, SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 112))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_MixAudio(__p0, __p1, __p2, __p3) \
	(((void (*)(void *, Uint8 *, const Uint8 *, Uint32 , int ))*(void**)((long)(POWERSDL_BASE_NAME) - 748))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2, __p3))

#define SDL_RealQuit() \
	(((void (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 34))((void*)(POWERSDL_BASE_NAME)))

#define SDL_ReadLE32(__p0) \
	(((Uint32 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1018))(__p0))

#define SDL_WriteBE32(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1060))(__p0, __p1))

#define SDL_SetGammaRamp(__p0, __p1, __p2) \
	(((int (*)(void *, const Uint16 *, const Uint16 *, const Uint16 *))*(void**)((long)(POWERSDL_BASE_NAME) - 190))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_WM_SetCaption(__p0, __p1) \
	(((void (*)(void *, const char *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 370))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_SemWaitTimeout(__p0, __p1) \
	(((int (*)(void *, SDL_sem *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 934))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_CopyAndSwap16(__p0, __p1, __p2) \
	(((void (*)(UWORD *, UWORD *, ULONG , void *))*(void**)((long)(POWERSDL_BASE_NAME) - 1168))(__p0, __p1, __p2, (void*)(POWERSDL_BASE_NAME)))

#define SDL_JoystickNumBalls(__p0) \
	(((int (*)(void *, SDL_Joystick *))*(void**)((long)(POWERSDL_BASE_NAME) - 520))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_CreateSemaphore(__p0) \
	(((SDL_sem *(*)(void *, Uint32 ))*(void**)((long)(POWERSDL_BASE_NAME) - 916))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_JoystickOpen(__p0) \
	(((SDL_Joystick *(*)(void *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 496))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_SaveBMP_RW(__p0, __p1, __p2) \
	(((int (*)(void *, SDL_Surface *, SDL_RWops *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 250))((void*)(POWERSDL_BASE_NAME), __p0, __p1, __p2))

#define SDL_AudioInit(__p0) \
	(((int (*)(void *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 688))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_WM_GetCaption(__p0, __p1) \
	(((void (*)(void *, char **, char **))*(void**)((long)(POWERSDL_BASE_NAME) - 376))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_JoystickGetHat(__p0, __p1) \
	(((Uint8 (*)(void *, SDL_Joystick *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 556))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GL_GetProcAddress(__p0) \
	(((void *(*)(void *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 328))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_LoadBMP_RW(__p0, __p1) \
	(((SDL_Surface *(*)(void *, SDL_RWops *, int ))*(void**)((long)(POWERSDL_BASE_NAME) - 88))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_DisplayYUVOverlay(__p0, __p1) \
	(((int (*)(void *, SDL_Overlay *, SDL_Rect *))*(void**)((long)(POWERSDL_BASE_NAME) - 310))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#define SDL_GL_LoadLibrary(__p0) \
	(((int (*)(void *, const char *))*(void**)((long)(POWERSDL_BASE_NAME) - 322))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_WriteLE64(__p0, __p1) \
	(((int (*)(SDL_RWops *, Uint64 ))*(void**)((long)(POWERSDL_BASE_NAME) - 1066))(__p0, __p1))

#define SDL_GetKeyState(__p0) \
	(((Uint8 *(*)(void *, int *))*(void**)((long)(POWERSDL_BASE_NAME) - 592))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_ConvertAudio(__p0) \
	(((int (*)(void *, SDL_AudioCVT *))*(void**)((long)(POWERSDL_BASE_NAME) - 742))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_NumJoysticks() \
	(((int (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 484))((void*)(POWERSDL_BASE_NAME)))

#define SDL_ReadBE16(__p0) \
	(((Uint16 (*)(SDL_RWops *))*(void**)((long)(POWERSDL_BASE_NAME) - 1012))(__p0))

#define SDL_GetAudioStatus() \
	(((SDL_audiostatus (*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 712))((void*)(POWERSDL_BASE_NAME)))

#define SDL_CreateMutex() \
	(((SDL_mutex *(*)(void *))*(void**)((long)(POWERSDL_BASE_NAME) - 892))((void*)(POWERSDL_BASE_NAME)))

#define SDL_PollEvent(__p0) \
	(((int (*)(void *, SDL_Event *))*(void**)((long)(POWERSDL_BASE_NAME) - 442))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_KillThread(__p0) \
	(((void (*)(void *, SDL_Thread *))*(void**)((long)(POWERSDL_BASE_NAME) - 796))((void*)(POWERSDL_BASE_NAME), __p0))

#define SDL_WM_SetIcon(__p0, __p1) \
	(((void (*)(void *, SDL_Surface *, Uint8 *))*(void**)((long)(POWERSDL_BASE_NAME) - 382))((void*)(POWERSDL_BASE_NAME), __p0, __p1))

#endif /* !_PPCINLINE_POWERSDL_H */
