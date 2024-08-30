/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_AHI_H
#define _PPCINLINE_AHI_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef AHI_BASE_NAME
#define AHI_BASE_NAME AHIBase
#endif /* !AHI_BASE_NAME */

#define AHI_FreeAudio(__p0) \
	LP1NR(48, AHI_FreeAudio, \
		struct AHIAudioCtrl *, __p0, a2, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_ControlAudioA(__p0, __p1) \
	LP2(60, ULONG , AHI_ControlAudioA, \
		struct AHIAudioCtrl *, __p0, a2, \
		struct TagItem *, __p1, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_SetSound(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(78, AHI_SetSound, \
		UWORD , __p0, d0, \
		UWORD , __p1, d1, \
		ULONG , __p2, d2, \
		LONG , __p3, d3, \
		struct AHIAudioCtrl *, __p4, a2, \
		ULONG , __p5, d4, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_PlayA(__p0, __p1) \
	LP2NR(138, AHI_PlayA, \
		struct AHIAudioCtrl *, __p0, a2, \
		struct TagItem *, __p1, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_SetEffect(__p0, __p1) \
	LP2(84, ULONG , AHI_SetEffect, \
		APTR , __p0, a0, \
		struct AHIAudioCtrl *, __p1, a2, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_SetFreq(__p0, __p1, __p2, __p3) \
	LP4NR(72, AHI_SetFreq, \
		UWORD , __p0, d0, \
		ULONG , __p1, d1, \
		struct AHIAudioCtrl *, __p2, a2, \
		ULONG , __p3, d2, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_AudioRequestA(__p0, __p1) \
	LP2(126, BOOL , AHI_AudioRequestA, \
		struct AHIAudioModeRequester *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_SetVol(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(66, AHI_SetVol, \
		UWORD , __p0, d0, \
		Fixed , __p1, d1, \
		sposition , __p2, d2, \
		struct AHIAudioCtrl *, __p3, a2, \
		ULONG , __p4, d3, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_FreeAudioRequest(__p0) \
	LP1NR(132, AHI_FreeAudioRequest, \
		struct AHIAudioModeRequester *, __p0, a0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_KillAudio() \
	LP0NR(54, AHI_KillAudio, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_AllocAudioA(__p0) \
	LP1(42, struct AHIAudioCtrl *, AHI_AllocAudioA, \
		struct TagItem *, __p0, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_NextAudioID(__p0) \
	LP1(102, ULONG , AHI_NextAudioID, \
		ULONG , __p0, d0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_AddAudioMode(__p0) \
	LP1(150, ULONG , AHI_AddAudioMode, \
		struct TagItem *, __p0, a0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_GetAudioAttrsA(__p0, __p1, __p2) \
	LP3(108, BOOL , AHI_GetAudioAttrsA, \
		ULONG , __p0, d0, \
		struct AHIAudioCtrl *, __p1, a2, \
		struct TagItem *, __p2, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_RemoveAudioMode(__p0) \
	LP1(156, ULONG , AHI_RemoveAudioMode, \
		ULONG , __p0, d0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_LoadModeFile(__p0) \
	LP1(162, ULONG , AHI_LoadModeFile, \
		STRPTR , __p0, a0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_AllocAudioRequestA(__p0) \
	LP1(120, struct AHIAudioModeRequester *, AHI_AllocAudioRequestA, \
		struct TagItem *, __p0, a0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_SampleFrameSize(__p0) \
	LP1(144, ULONG , AHI_SampleFrameSize, \
		ULONG , __p0, d0, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_LoadSound(__p0, __p1, __p2, __p3) \
	LP4(90, ULONG , AHI_LoadSound, \
		UWORD , __p0, d0, \
		ULONG , __p1, d1, \
		APTR , __p2, a0, \
		struct AHIAudioCtrl *, __p3, a2, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_UnloadSound(__p0, __p1) \
	LP2NR(96, AHI_UnloadSound, \
		UWORD , __p0, d0, \
		struct AHIAudioCtrl *, __p1, a2, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHI_BestAudioIDA(__p0) \
	LP1(114, ULONG , AHI_BestAudioIDA, \
		struct TagItem *, __p0, a1, \
		, AHI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AHI_ControlAudio(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_ControlAudioA(__p0, (struct TagItem *)_tags);})

#define AHI_Play(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_PlayA(__p0, (struct TagItem *)_tags);})

#define AHI_AudioRequest(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_AudioRequestA(__p0, (struct TagItem *)_tags);})

#define AHI_AllocAudio(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_AllocAudioA((struct TagItem *)_tags);})

#define AHI_GetAudioAttrs(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_GetAudioAttrsA(__p0, __p1, (struct TagItem *)_tags);})

#define AHI_AllocAudioRequest(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_AllocAudioRequestA((struct TagItem *)_tags);})

#define AHI_BestAudioID(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AHI_BestAudioIDA((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_AHI_H */
