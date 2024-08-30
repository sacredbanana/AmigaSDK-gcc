#ifndef SDL_PROTOS
#define SDL_PROTOS

#include <stdio.h>

#ifndef	DOS_DOS_H
#include	<dos/dos.h>
#endif

#ifndef PROTO_POWERSDL_H
#define PROTO_POWERSDL_H
#define PROTO_POWERSDL_TRICK
#endif

#ifndef	_SDL_H
#include <SDL/SDL.h>
#endif

#include <SDL/SDL_active.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_byteorder.h>
#include <SDL/SDL_cdrom.h>
#include <SDL/SDL_copying.h>
#include <SDL/SDL_cpuinfo.h>
#include <SDL/SDL_endian.h>
#include <SDL/SDL_error.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_joystick.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_loadso.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_mutex.h>
#include <SDL/SDL_name.h>
#include <SDL/SDL_quit.h>
#include <SDL/SDL_rwops.h>
#include <SDL/SDL_syswm.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_types.h>
#include <SDL/SDL_version.h>
#include <SDL/SDL_video.h>

#ifdef PROTO_POWERSDL_TRICK
#undef PROTO_POWERSDL_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* General */
int SDL_Init(Uint32 flags);
void SDL_RealQuit(void);
int SDL_InitSubSystem(Uint32 flags);
void SDL_QuitSubSystem(Uint32 flags);
Uint32 SDL_WasInit(Uint32 flags);

/* RWOps */
SDL_RWops * SDL_AMIGA_RWFromFile(const char *file, const char *mode);
SDL_RWops * SDL_RWFromFP(FILE *fp, int autoclose); /* in the libSDL.a stubs */
SDL_RWops * SDL_RWFromMem(void *mem, int size);
SDL_RWops * SDL_AllocRW(void);
void SDL_FreeRW(SDL_RWops *area);

/* Gfx */
SDL_Surface * SDL_LoadBMP_RW(SDL_RWops *src, int freesrc);
SDL_Surface * SDL_DisplayFormat(SDL_Surface *surface);
void SDL_FreeSurface(SDL_Surface *surface);
int SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color);
int SDL_UpperBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_Flip(SDL_Surface *screen);
void SDL_UpdateRects(SDL_Surface *screen, int numrects, SDL_Rect *rects);
void SDL_UpdateRect(SDL_Surface *screen, Sint32 x, Sint32 y, Uint32 w, Uint32 h);
const SDL_VideoInfo * SDL_GetVideoInfo(void);
SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);
Uint32 SDL_MapRGB(SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b);
Uint32 SDL_MapRGBA(SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

char *SDL_VideoDriverName(char *namebuf, int maxlen);
SDL_Surface * SDL_GetVideoSurface(void);
int SDL_VideoModeOK(int width, int height, int bpp, Uint32 flags);
SDL_Rect ** SDL_ListModes(SDL_PixelFormat *format, Uint32 flags);
int SDL_SetGamma(float red, float green, float blue);
int SDL_SetGammaRamp(const Uint16 *red, const Uint16 *green, const Uint16 *blue);
int SDL_GetGammaRamp(Uint16 *red, Uint16 *green, Uint16 *blue);
int SDL_SetColors(SDL_Surface *surface, SDL_Color *colors, int firstcolor, int ncolors);
int SDL_SetPalette(SDL_Surface *surface, int flags, SDL_Color *colors, int firstcolor, int ncolors);
void SDL_GetRGB(Uint32 pix, SDL_PixelFormat *fmt, Uint8 *r, Uint8 *g, Uint8 *b);
void SDL_GetRGBA(Uint32 pix, SDL_PixelFormat *fmt, Uint8 *r, Uint8 *g, Uint8 *b, Uint8 *a);
SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
int SDL_LockSurface(SDL_Surface *surface);
void SDL_UnlockSurface(SDL_Surface *surface);
int SDL_SaveBMP_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst);
int SDL_SetColorKey(SDL_Surface *surface, Uint32 flag, Uint32 key);
int SDL_SetAlpha(SDL_Surface *surface, Uint32 flag, Uint8 alpha);
SDL_bool SDL_SetClipRect(SDL_Surface *surface, const SDL_Rect *rect);
void SDL_GetClipRect(SDL_Surface *surface, SDL_Rect *rect);
SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt, Uint32 flags);
SDL_Surface * SDL_DisplayFormatAlpha(SDL_Surface *surface);

/* Overlay */
SDL_Overlay *SDL_CreateYUVOverlay(int width, int height,Uint32 format, SDL_Surface *display);
int SDL_LockYUVOverlay(SDL_Overlay *overlay);
void SDL_UnlockYUVOverlay(SDL_Overlay *overlay);
int SDL_DisplayYUVOverlay(SDL_Overlay *overlay, SDL_Rect *dstrect);
void SDL_FreeYUVOverlay(SDL_Overlay *overlay);

/* GL */
int SDL_GL_LoadLibrary(const char *path);
void *SDL_GL_GetProcAddress(const char* proc);
int SDL_GL_SetAttribute(SDL_GLattr attr, int value);
int SDL_GL_GetAttribute(SDL_GLattr attr, int* value);
void SDL_GL_SwapBuffers(void);
void SDL_GL_UpdateRects(int numrects, SDL_Rect* rects);
void SDL_GL_Lock(void);
void SDL_GL_Unlock(void);

/* WM */
void SDL_WM_SetCaption(const char *title, const char *icon);
void SDL_WM_GetCaption(char **title, char **icon);
void SDL_WM_SetIcon(SDL_Surface *icon, Uint8 *mask);
int SDL_WM_IconifyWindow(void);
int SDL_WM_ToggleFullScreen(SDL_Surface *surface);
SDL_GrabMode SDL_WM_GrabInput(SDL_GrabMode mode);

/* timer */

Uint32 SDL_GetTicks(void);
void SDL_Delay(Uint32 ms);
int SDL_SetTimer(Uint32 interval, SDL_TimerCallback callback);
SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_NewTimerCallback callback, void *param);
SDL_bool SDL_RemoveTimer(SDL_TimerID t);

/* events */
void SDL_PumpEvents(void);
int SDL_PollEvent(SDL_Event *event);
int SDL_WaitEvent(SDL_Event *event);
int SDL_PeepEvents(SDL_Event *events, int numevents,SDL_eventaction action, Uint32 mask);
int SDL_PushEvent(SDL_Event *event);
void SDL_SetEventFilter(SDL_EventFilter filter);
SDL_EventFilter SDL_GetEventFilter(void);
Uint8 SDL_EventState(Uint8 type, int state);

/* joystick */
int SDL_NumJoysticks(void);
const char *SDL_JoystickName(int device_index);
SDL_Joystick *SDL_JoystickOpen(int device_index);
int SDL_JoystickOpened(int device_index);
int SDL_JoystickIndex(SDL_Joystick *joystick);
int SDL_JoystickNumAxes(SDL_Joystick *joystick);
int SDL_JoystickNumBalls(SDL_Joystick *joystick);
int SDL_JoystickNumHats(SDL_Joystick *joystick);
int SDL_JoystickNumButtons(SDL_Joystick *joystick);
void SDL_JoystickUpdate(void);
int SDL_JoystickEventState(int state);
Sint16 SDL_JoystickGetAxis(SDL_Joystick *joystick, int axis);
Uint8 SDL_JoystickGetHat(SDL_Joystick *joystick, int hat);
int SDL_JoystickGetBall(SDL_Joystick *joystick, int ball, int *dx, int *dy);
Uint8 SDL_JoystickGetButton(SDL_Joystick *joystick, int button);
void SDL_JoystickClose(SDL_Joystick *joystick);

/* keyboard */
int SDL_EnableUNICODE(int enable);
int SDL_EnableKeyRepeat(int delay, int interval);
Uint8 * SDL_GetKeyState(int *numkeys);
SDLMod SDL_GetModState(void);
void SDL_SetModState(SDLMod modstate);
char * SDL_GetKeyName(SDLKey key);

/* mouse */
Uint8 SDL_GetMouseState(int *x, int *y);
Uint8 SDL_GetRelativeMouseState(int *x, int *y);
void SDL_WarpMouse(Uint16 x, Uint16 y);
SDL_Cursor *SDL_CreateCursor(Uint8 *data, Uint8 *mask, int w, int h, int hot_x, int hot_y);
void SDL_SetCursor(SDL_Cursor *cursor);
SDL_Cursor * SDL_GetCursor(void);
void SDL_FreeCursor(SDL_Cursor *cursor);
int SDL_ShowCursor(int toggle);

/* application */
Uint8 SDL_GetAppState(void);

/* error */
void SDL_SetError(const char *fmt, ... );								// FIXME
//void SDL_SetErrorA(const char *fmt, unsigned long *arglist);	// FIXME
char *SDL_GetError(void);													// FIXME
void SDL_ClearError(void);

/* audio */
int SDL_AudioInit(const char *driver_name);
void SDL_AudioQuit(void);
char *SDL_AudioDriverName(char *namebuf, int maxlen);
int SDL_OpenAudio(SDL_AudioSpec *desired, SDL_AudioSpec *obtained);
SDL_audiostatus SDL_GetAudioStatus(void);
void SDL_PauseAudio(int pause_on);
SDL_AudioSpec *SDL_LoadWAV_RW(SDL_RWops *src, int freesrc,SDL_AudioSpec *spec, Uint8 **audio_buf, Uint32 *audio_len);
void SDL_FreeWAV(Uint8 *audio_buf);
int SDL_BuildAudioCVT(SDL_AudioCVT *cvt,Uint16 src_format, Uint8 src_channels, int src_rate,Uint16 dst_format, Uint8 dst_channels, int dst_rate);
int SDL_ConvertAudio(SDL_AudioCVT *cvt);
void SDL_MixAudio(Uint8 *dst, const Uint8 *src, Uint32 len, int volume);
void SDL_LockAudio(void);
void SDL_UnlockAudio(void);
void SDL_CloseAudio(void);

/* thread */
SDL_Thread * SDL_CreateThread(int (*fn)(void *), void *data);
Uint32 SDL_ThreadID(void);
Uint32 SDL_GetThreadID(SDL_Thread *thread);
void SDL_WaitThread(SDL_Thread *thread, int *status);
void SDL_KillThread(SDL_Thread *thread);

/* version */
const SDL_version * SDL_Linked_Version(void);

/* extensions */
int SDL_SoftStretch(SDL_Surface *, SDL_Rect *, SDL_Surface *, SDL_Rect *);

const char      *SDL_UNIX2AMIGA(const char *file);
SDL_RWops		*SDL_RWFromFile(const char *file, const char *mode);
SDL_RWops		*SDL_AMIGA_RWFromFP(BPTR fp, int autoclose);

/* cdrom */

int SDL_CDNumDrives(void);
const char *SDL_CDName(int drive);
SDL_CD *SDL_CDOpen(int drive);
CDstatus SDL_CDStatus(SDL_CD *cdrom);
int SDL_CDPlay(SDL_CD *cdrom, int sframe, int length);
int SDL_CDPause(SDL_CD *cdrom);
int SDL_CDResume(SDL_CD *cdrom);
int SDL_CDStop(SDL_CD *cdrom);
int SDL_CDEject(SDL_CD *cdrom);
void SDL_CDClose(SDL_CD *cdrom);

/* mutex */

SDL_mutex *SDL_CreateMutex(void);
void SDL_DestroyMutex(SDL_mutex *mutex);
int SDL_mutexP(SDL_mutex *mutex);
int SDL_mutexV(SDL_mutex *mutex);

/* semaphores */

SDL_sem *  SDL_CreateSemaphore(Uint32 initial_value);
void		SDL_DestroySemaphore(SDL_sem *sem);
int		SDL_SemTryWait(SDL_sem *sem);
int		SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout);
int		SDL_SemWait(SDL_sem *sem);
Uint32	SDL_SemValue(SDL_sem *sem);
int		SDL_SemPost(SDL_sem *sem);

void		SDL_Error(SDL_errorcode code);

/* conds */

SDL_cond * SDL_CreateCond(void);
void SDL_DestroyCond(SDL_cond *cond);
int SDL_CondSignal(SDL_cond *cond);
int SDL_CondBroadcast(SDL_cond *cond);
int SDL_CondWaitTimeout(SDL_cond *cond, SDL_mutex *mutex, Uint32 ms);
int SDL_CondWait(SDL_cond *cond, SDL_mutex *mutex);

/* TinyGL */

void SDL_InitTGL(void **glc, void **tgl);

/* Endian */

Uint16 SDL_ReadLE16(SDL_RWops *src);
Uint16 SDL_ReadBE16(SDL_RWops *src);
Uint32 SDL_ReadLE32(SDL_RWops *src);
Uint32 SDL_ReadBE32(SDL_RWops *src);
Uint64 SDL_ReadLE64(SDL_RWops *src);
Uint64 SDL_ReadBE64(SDL_RWops *src);
int SDL_WriteLE16(SDL_RWops *dst, Uint16 value);
int SDL_WriteBE16(SDL_RWops *dst, Uint16 value);
int SDL_WriteLE32(SDL_RWops *dst, Uint32 value);
int SDL_WriteBE32(SDL_RWops *dst, Uint32 value);
int SDL_WriteLE64(SDL_RWops *dst, Uint64 value);
int SDL_WriteBE64(SDL_RWops *dst, Uint64 value);

#ifdef SYSTEM_PRIVATE

/* Private, for sublibraries to access mainlib mempool */

void *SDLP_malloc(size_t size);
void SDLP_free(void *ptr);
void *SDLP_realloc(void *old, size_t newsize);

#endif /* SYSTEM_PRIVATE */

/* cpuinfo */
SDL_bool SDL_HasAltiVec(void);
SDL_bool SDL_HasRDTSC(void);
SDL_bool SDL_HasMMX(void);
SDL_bool SDL_Has3DNow(void);
SDL_bool SDL_HasSSE(void);
SDL_bool SDL_HasMMXExt(void);
SDL_bool SDL_Has3DNowExt(void);
SDL_bool SDL_HasSSE2(void);

/* addendum */

int SDL_LowerBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_CDPlayTracks(SDL_CD *cdrom, int strack, int sframe, int ntracks, int nframes);
void SDL_OpenPrefs(void);

#ifdef SYSTEM_PRIVATE

/* Private, for the SDL_RWFromFP() hack into libSDL.a */

SDL_RWops *SDLP_RWFromFPhack(void *fp, int autoclose, int (*seek)(struct SDL_RWops *, int, int), int (*read)(struct SDL_RWops *, void *, int, int), int (*write)(struct SDL_RWops *, const void *, int, int), int (*close)(struct SDL_RWops *));

#endif /* SYSTEM_PRIVATE */

void SDL_CopyAndSwap16(UWORD *src, UWORD *dst, ULONG items);
void SDL_CopyAndSwap32(ULONG *src, ULONG *dst, ULONG items);

#ifdef __cplusplus
}
#endif

#endif
