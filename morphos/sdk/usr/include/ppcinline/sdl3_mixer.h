/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SDL3_MIXER_H
#define _PPCINLINE_SDL3_MIXER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SDL3_MIXER_BASE_NAME
#define SDL3_MIXER_BASE_NAME SDL3MixerBase
#endif /* !SDL3_MIXER_BASE_NAME */

#ifndef MIX_Init
#define MIX_Init() \
	({ \
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 52))());\
	})
#endif

#ifndef MIX_Quit
#define MIX_Quit() \
	({ \
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 58))());\
	})
#endif

#ifndef MIX_Version
#define MIX_Version() \
	({ \
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 64))());\
	})
#endif

#ifndef MIX_CreateMixer
#define MIX_CreateMixer(__p0) \
	({ \
		const SDL_AudioSpec * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Mixer *(*)(const SDL_AudioSpec *))*(void**)(__base - 70))(__t__p0));\
	})
#endif

#ifndef MIX_CreateMixerDevice
#define MIX_CreateMixerDevice(__p0, __p1) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		const SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Mixer *(*)(SDL_AudioDeviceID , const SDL_AudioSpec *))*(void**)(__base - 76))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_DestroyMixer
#define MIX_DestroyMixer(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Mixer *))*(void**)(__base - 82))(__t__p0));\
	})
#endif

#ifndef MIX_GetNumAudioDecoders
#define MIX_GetNumAudioDecoders() \
	({ \
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 88))());\
	})
#endif

#ifndef MIX_GetAudioDecoder
#define MIX_GetAudioDecoder(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 94))(__t__p0));\
	})
#endif

#ifndef MIX_GetMixerFormat
#define MIX_GetMixerFormat(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, SDL_AudioSpec *))*(void**)(__base - 100))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_LoadAudio_IO
#define MIX_LoadAudio_IO(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, SDL_IOStream *, bool , bool ))*(void**)(__base - 106))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_LoadAudio
#define MIX_LoadAudio(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, const char *, bool ))*(void**)(__base - 112))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_LoadAudioWithProperties
#define MIX_LoadAudioWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(SDL_PropertiesID ))*(void**)(__base - 118))(__t__p0));\
	})
#endif

#ifndef MIX_LoadRawAudio_IO
#define MIX_LoadRawAudio_IO(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		const SDL_AudioSpec * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, SDL_IOStream *, const SDL_AudioSpec *, bool ))*(void**)(__base - 124))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_LoadRawAudio
#define MIX_LoadRawAudio(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		const SDL_AudioSpec * __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, const void *, size_t , const SDL_AudioSpec *))*(void**)(__base - 130))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_LoadRawAudioNoCopy
#define MIX_LoadRawAudioNoCopy(__p0, __p1, __p2, __p3, __p4) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		const SDL_AudioSpec * __t__p3 = __p3;\
		bool  __t__p4 = __p4;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, const void *, size_t , const SDL_AudioSpec *, bool ))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef MIX_CreateSineWaveAudio
#define MIX_CreateSineWaveAudio(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		Sint64  __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, int , float , Sint64 ))*(void**)(__base - 142))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_GetAudioProperties
#define MIX_GetAudioProperties(__p0) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(MIX_Audio *))*(void**)(__base - 148))(__t__p0));\
	})
#endif

#ifndef MIX_DestroyAudio
#define MIX_DestroyAudio(__p0) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Audio *))*(void**)(__base - 154))(__t__p0));\
	})
#endif

#ifndef MIX_CreateTrack
#define MIX_CreateTrack(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Track *(*)(MIX_Mixer *))*(void**)(__base - 160))(__t__p0));\
	})
#endif

#ifndef MIX_DestroyTrack
#define MIX_DestroyTrack(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Track *))*(void**)(__base - 166))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrackAudio
#define MIX_SetTrackAudio(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_Audio * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_Audio *))*(void**)(__base - 172))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_SetTrackAudioStream
#define MIX_SetTrackAudioStream(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		SDL_AudioStream * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, SDL_AudioStream *))*(void**)(__base - 178))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_SetTrackIOStream
#define MIX_SetTrackIOStream(__p0, __p1, __p2) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, SDL_IOStream *, bool ))*(void**)(__base - 184))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetTrackRawIOStream
#define MIX_SetTrackRawIOStream(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		const SDL_AudioSpec * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, SDL_IOStream *, const SDL_AudioSpec *, bool ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_TagTrack
#define MIX_TagTrack(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, const char *))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_UntagTrack
#define MIX_UntagTrack(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Track *, const char *))*(void**)(__base - 202))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_SetTrackPlaybackPosition
#define MIX_SetTrackPlaybackPosition(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, Sint64 ))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTrackPlaybackPosition
#define MIX_GetTrackPlaybackPosition(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Track *))*(void**)(__base - 214))(__t__p0));\
	})
#endif

#ifndef MIX_TrackMSToFrames
#define MIX_TrackMSToFrames(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Track *, Sint64 ))*(void**)(__base - 220))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_TrackFramesToMS
#define MIX_TrackFramesToMS(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Track *, Sint64 ))*(void**)(__base - 226))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_AudioMSToFrames
#define MIX_AudioMSToFrames(__p0, __p1) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Audio *, Sint64 ))*(void**)(__base - 232))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_AudioFramesToMS
#define MIX_AudioFramesToMS(__p0, __p1) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Audio *, Sint64 ))*(void**)(__base - 238))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_MSToFrames
#define MIX_MSToFrames(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(int , Sint64 ))*(void**)(__base - 244))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_FramesToMS
#define MIX_FramesToMS(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(int , Sint64 ))*(void**)(__base - 250))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_PlayTrack
#define MIX_PlayTrack(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, SDL_PropertiesID ))*(void**)(__base - 256))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_PlayTag
#define MIX_PlayTag(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_PropertiesID  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, const char *, SDL_PropertiesID ))*(void**)(__base - 262))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_PlayAudio
#define MIX_PlayAudio(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		MIX_Audio * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, MIX_Audio *))*(void**)(__base - 268))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_StopTrack
#define MIX_StopTrack(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, Sint64 ))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_StopAllTracks
#define MIX_StopAllTracks(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, Sint64 ))*(void**)(__base - 280))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_StopTag
#define MIX_StopTag(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Sint64  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, const char *, Sint64 ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_PauseTrack
#define MIX_PauseTrack(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *))*(void**)(__base - 292))(__t__p0));\
	})
#endif

#ifndef MIX_PauseAllTracks
#define MIX_PauseAllTracks(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *))*(void**)(__base - 298))(__t__p0));\
	})
#endif

#ifndef MIX_PauseTag
#define MIX_PauseTag(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, const char *))*(void**)(__base - 304))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_ResumeTrack
#define MIX_ResumeTrack(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *))*(void**)(__base - 310))(__t__p0));\
	})
#endif

#ifndef MIX_ResumeAllTracks
#define MIX_ResumeAllTracks(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *))*(void**)(__base - 316))(__t__p0));\
	})
#endif

#ifndef MIX_ResumeTag
#define MIX_ResumeTag(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, const char *))*(void**)(__base - 322))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_TrackPlaying
#define MIX_TrackPlaying(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *))*(void**)(__base - 328))(__t__p0));\
	})
#endif

#ifndef MIX_TrackPaused
#define MIX_TrackPaused(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *))*(void**)(__base - 334))(__t__p0));\
	})
#endif

#ifndef MIX_SetMixerGain
#define MIX_SetMixerGain(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, float ))*(void**)(__base - 340))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetMixerGain
#define MIX_GetMixerGain(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(MIX_Mixer *))*(void**)(__base - 346))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrackGain
#define MIX_SetTrackGain(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, float ))*(void**)(__base - 352))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTrackGain
#define MIX_GetTrackGain(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(MIX_Track *))*(void**)(__base - 358))(__t__p0));\
	})
#endif

#ifndef MIX_SetTagGain
#define MIX_SetTagGain(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, const char *, float ))*(void**)(__base - 364))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetTrackFrequencyRatio
#define MIX_SetTrackFrequencyRatio(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, float ))*(void**)(__base - 370))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTrackFrequencyRatio
#define MIX_GetTrackFrequencyRatio(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(MIX_Track *))*(void**)(__base - 376))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrackOutputChannelMap
#define MIX_SetTrackOutputChannelMap(__p0, __p1, __p2) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		const int * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, const int *, int ))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetTrackStoppedCallback
#define MIX_SetTrackStoppedCallback(__p0, __p1, __p2) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_TrackStoppedCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_TrackStoppedCallback , void *))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_CreateGroup
#define MIX_CreateGroup(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Group *(*)(MIX_Mixer *))*(void**)(__base - 394))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrackGroup
#define MIX_SetTrackGroup(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_Group * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_Group *))*(void**)(__base - 400))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_DestroyGroup
#define MIX_DestroyGroup(__p0) \
	({ \
		MIX_Group * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Group *))*(void**)(__base - 406))(__t__p0));\
	})
#endif

#ifndef MIX_GetGroupMixer
#define MIX_GetGroupMixer(__p0) \
	({ \
		MIX_Group * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Mixer *(*)(MIX_Group *))*(void**)(__base - 412))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackMixer
#define MIX_GetTrackMixer(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Mixer *(*)(MIX_Track *))*(void**)(__base - 418))(__t__p0));\
	})
#endif

#ifndef MIX_SetPostMixCallback
#define MIX_SetPostMixCallback(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		MIX_PostMixCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, MIX_PostMixCallback , void *))*(void**)(__base - 424))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetGroupPostMixCallback
#define MIX_SetGroupPostMixCallback(__p0, __p1, __p2) \
	({ \
		MIX_Group * __t__p0 = __p0;\
		MIX_GroupMixCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Group *, MIX_GroupMixCallback , void *))*(void**)(__base - 430))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetTrackRawCallback
#define MIX_SetTrackRawCallback(__p0, __p1, __p2) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_TrackMixCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_TrackMixCallback , void *))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetTrackCookedCallback
#define MIX_SetTrackCookedCallback(__p0, __p1, __p2) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_TrackMixCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_TrackMixCallback , void *))*(void**)(__base - 442))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_Generate
#define MIX_Generate(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(MIX_Mixer *, void *, int ))*(void**)(__base - 448))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_GetAudioDuration
#define MIX_GetAudioDuration(__p0) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Audio *))*(void**)(__base - 454))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackLoops
#define MIX_GetTrackLoops(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(MIX_Track *))*(void**)(__base - 460))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackAudio
#define MIX_GetTrackAudio(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Track *))*(void**)(__base - 466))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackAudioStream
#define MIX_GetTrackAudioStream(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioStream *(*)(MIX_Track *))*(void**)(__base - 472))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackRemaining
#define MIX_GetTrackRemaining(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Track *))*(void**)(__base - 478))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrack3DPosition
#define MIX_SetTrack3DPosition(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		const MIX_Point3D * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, const MIX_Point3D *))*(void**)(__base - 484))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTrack3DPosition
#define MIX_GetTrack3DPosition(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		MIX_Point3D * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, MIX_Point3D *))*(void**)(__base - 490))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetAudioFormat
#define MIX_GetAudioFormat(__p0, __p1) \
	({ \
		MIX_Audio * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Audio *, SDL_AudioSpec *))*(void**)(__base - 496))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetMixerProperties
#define MIX_GetMixerProperties(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(MIX_Mixer *))*(void**)(__base - 502))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackProperties
#define MIX_GetTrackProperties(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(MIX_Track *))*(void**)(__base - 508))(__t__p0));\
	})
#endif

#ifndef MIX_GetGroupProperties
#define MIX_GetGroupProperties(__p0) \
	({ \
		MIX_Group * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(MIX_Group *))*(void**)(__base - 514))(__t__p0));\
	})
#endif

#ifndef MIX_SetTrackStereo
#define MIX_SetTrackStereo(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		const MIX_StereoGains * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, const MIX_StereoGains *))*(void**)(__base - 520))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_CreateAudioDecoder
#define MIX_CreateAudioDecoder(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_AudioDecoder *(*)(const char *, SDL_PropertiesID ))*(void**)(__base - 526))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_CreateAudioDecoder_IO
#define MIX_CreateAudioDecoder_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		SDL_PropertiesID  __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_AudioDecoder *(*)(SDL_IOStream *, bool , SDL_PropertiesID ))*(void**)(__base - 532))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_DestroyAudioDecoder
#define MIX_DestroyAudioDecoder(__p0) \
	({ \
		MIX_AudioDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_AudioDecoder *))*(void**)(__base - 538))(__t__p0));\
	})
#endif

#ifndef MIX_GetAudioDecoderProperties
#define MIX_GetAudioDecoderProperties(__p0) \
	({ \
		MIX_AudioDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(MIX_AudioDecoder *))*(void**)(__base - 544))(__t__p0));\
	})
#endif

#ifndef MIX_DecodeAudio
#define MIX_DecodeAudio(__p0, __p1, __p2, __p3) \
	({ \
		MIX_AudioDecoder * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		const SDL_AudioSpec * __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(MIX_AudioDecoder *, void *, int , const SDL_AudioSpec *))*(void**)(__base - 550))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_GetAudioDecoderFormat
#define MIX_GetAudioDecoderFormat(__p0, __p1) \
	({ \
		MIX_AudioDecoder * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_AudioDecoder *, SDL_AudioSpec *))*(void**)(__base - 556))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_SetTrackLoops
#define MIX_SetTrackLoops(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Track *, int ))*(void**)(__base - 562))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTrackFadeFrames
#define MIX_GetTrackFadeFrames(__p0) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(MIX_Track *))*(void**)(__base - 568))(__t__p0));\
	})
#endif

#ifndef MIX_GetTrackTags
#define MIX_GetTrackTags(__p0, __p1) \
	({ \
		MIX_Track * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(MIX_Track *, int *))*(void**)(__base - 574))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetTaggedTracks
#define MIX_GetTaggedTracks(__p0, __p1, __p2) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Track **(*)(MIX_Mixer *, const char *, int *))*(void**)(__base - 580))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef MIX_SetMixerFrequencyRatio
#define MIX_SetMixerFrequencyRatio(__p0, __p1) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(MIX_Mixer *, float ))*(void**)(__base - 586))(__t__p0, __t__p1));\
	})
#endif

#ifndef MIX_GetMixerFrequencyRatio
#define MIX_GetMixerFrequencyRatio(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(MIX_Mixer *))*(void**)(__base - 592))(__t__p0));\
	})
#endif

#ifndef MIX_LoadAudioNoCopy
#define MIX_LoadAudioNoCopy(__p0, __p1, __p2, __p3) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((MIX_Audio *(*)(MIX_Mixer *, const void *, size_t , bool ))*(void**)(__base - 598))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef MIX_LockMixer
#define MIX_LockMixer(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Mixer *))*(void**)(__base - 604))(__t__p0));\
	})
#endif

#ifndef MIX_UnlockMixer
#define MIX_UnlockMixer(__p0) \
	({ \
		MIX_Mixer * __t__p0 = __p0;\
		long __base = (long)(SDL3_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(MIX_Mixer *))*(void**)(__base - 610))(__t__p0));\
	})
#endif

#endif /* !_PPCINLINE_SDL3_MIXER_H */
