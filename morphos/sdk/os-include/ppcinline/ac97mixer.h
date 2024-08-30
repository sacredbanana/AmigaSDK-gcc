/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_AC97MIXER_H
#define _PPCINLINE_AC97MIXER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef AC97MIXER_BASE_NAME
#define AC97MIXER_BASE_NAME AC97MixerBase
#endif /* !AC97MIXER_BASE_NAME */

#define AC97AddCodecTagList(__p0, __p1) \
	LP2(156, void * , AC97AddCodecTagList, \
		struct AC97Mixer_CodecObject *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97SetInputAttr(__p0, __p1, __p2, __p3) \
	LP4(114, LONG , AC97SetInputAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		LONG , __p3, d2, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define AC97RemCodecByID(__p0) \
	LP1NR(162, AC97RemCodecByID, \
		LONG , __p0, d0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97RestoreState(__p0, __p1) \
	LP2(90, LONG , AC97RestoreState, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97AddMixerNotify(__p0, __p1, __p2) \
	LP3(132, LONG , AC97AddMixerNotify, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		struct Hook *, __p2, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97ReadIndex(__p0, __p1) \
	LP2(72, LONG , AC97ReadIndex, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97StoreState(__p0, __p1) \
	LP2(84, LONG , AC97StoreState, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97SetMixerAttr(__p0, __p1, __p2) \
	LP3(102, LONG , AC97SetMixerAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		LONG , __p2, d1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97FindMixer(__p0, __p1, __p2) \
	LP3(66, void *, AC97FindMixer, \
		void *, __p0, a0, \
		LONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97RemMixerNotify(__p0, __p1) \
	LP2(138, LONG , AC97RemMixerNotify, \
		void *, __p0, a0, \
		struct Hook *, __p1, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97WriteIndex(__p0, __p1, __p2) \
	LP3(78, LONG , AC97WriteIndex, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97GetInputAttr(__p0, __p1, __p2, __p3) \
	LP4(108, LONG , AC97GetInputAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		void *, __p3, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97AddCodec(__p0) \
	LP1(144, LONG , AC97AddCodec, \
		struct AC97Mixer_CodecObject *, __p0, a0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97SetOutputAttr(__p0, __p1, __p2, __p3) \
	LP4(126, LONG , AC97SetOutputAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		LONG , __p3, d2, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97RemCodec(__p0) \
	LP1NR(150, AC97RemCodec, \
		struct AC97Mixer_CodecObject *, __p0, a0, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97GetMixerAttr(__p0, __p1, __p2) \
	LP3(96, LONG , AC97GetMixerAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		void *, __p2, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AC97GetOutputAttr(__p0, __p1, __p2, __p3) \
	LP4(120, LONG , AC97GetOutputAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		void *, __p3, a1, \
		, AC97MIXER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AC97AddCodecTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AC97AddCodecTagList(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_AC97MIXER_H */
