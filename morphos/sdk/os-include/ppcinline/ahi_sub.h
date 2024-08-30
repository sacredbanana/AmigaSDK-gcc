/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_AHI_SUB_H
#define _PPCINLINE_AHI_SUB_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef AHI_SUB_BASE_NAME
#define AHI_SUB_BASE_NAME AHIsubBase
#endif /* !AHI_SUB_BASE_NAME */

#define AHIsub_Stop(__p0, __p1) \
	LP2(66, ULONG , AHIsub_Stop, \
		ULONG , __p0, d0, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_Enable(__p0) \
	LP1NR(48, AHIsub_Enable, \
		struct AHIAudioCtrlDrv *, __p0, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_LoadSound(__p0, __p1, __p2, __p3) \
	LP4(96, ULONG , AHIsub_LoadSound, \
		UWORD , __p0, d0, \
		ULONG , __p1, d1, \
		APTR , __p2, a0, \
		struct AHIAudioCtrlDrv *, __p3, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_UnloadSound(__p0, __p1) \
	LP2(102, ULONG , AHIsub_UnloadSound, \
		UWORD , __p0, d0, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_Start(__p0, __p1) \
	LP2(54, ULONG , AHIsub_Start, \
		ULONG , __p0, d0, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_HardwareControl(__p0, __p1, __p2) \
	LP3(114, LONG , AHIsub_HardwareControl, \
		ULONG , __p0, d0, \
		LONG , __p1, d1, \
		struct AHIAudioCtrlDrv *, __p2, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_FreeAudio(__p0) \
	LP1NR(36, AHIsub_FreeAudio, \
		struct AHIAudioCtrlDrv *, __p0, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_Disable(__p0) \
	LP1NR(42, AHIsub_Disable, \
		struct AHIAudioCtrlDrv *, __p0, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_SetSound(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(84, ULONG , AHIsub_SetSound, \
		UWORD , __p0, d0, \
		UWORD , __p1, d1, \
		ULONG , __p2, d2, \
		LONG , __p3, d3, \
		struct AHIAudioCtrlDrv *, __p4, a2, \
		ULONG , __p5, d4, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_SetEffect(__p0, __p1) \
	LP2(90, ULONG , AHIsub_SetEffect, \
		APTR , __p0, a0, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_SetFreq(__p0, __p1, __p2, __p3) \
	LP4(78, ULONG , AHIsub_SetFreq, \
		UWORD , __p0, d0, \
		ULONG , __p1, d1, \
		struct AHIAudioCtrlDrv *, __p2, a2, \
		ULONG , __p3, d2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_GetAttr(__p0, __p1, __p2, __p3, __p4) \
	LP5(108, LONG , AHIsub_GetAttr, \
		ULONG , __p0, d0, \
		LONG , __p1, d1, \
		LONG , __p2, d2, \
		struct TagItem *, __p3, a1, \
		struct AHIAudioCtrlDrv *, __p4, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_AllocAudio(__p0, __p1) \
	LP2(30, ULONG , AHIsub_AllocAudio, \
		struct TagItem *, __p0, a1, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_SetVol(__p0, __p1, __p2, __p3, __p4) \
	LP5(72, ULONG , AHIsub_SetVol, \
		UWORD , __p0, d0, \
		Fixed , __p1, d1, \
		sposition , __p2, d2, \
		struct AHIAudioCtrlDrv *, __p3, a2, \
		ULONG , __p4, d3, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AHIsub_Update(__p0, __p1) \
	LP2(60, ULONG , AHIsub_Update, \
		ULONG , __p0, d0, \
		struct AHIAudioCtrlDrv *, __p1, a2, \
		, AHI_SUB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_AHI_SUB_H */
