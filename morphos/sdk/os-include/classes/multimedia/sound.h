/*
$VER: sound.h 51.15 (25.6.2010)
*/

/* sound objects methods and attributes */

#ifndef CLASSES_MULTIMEDIA_SOUND_H
#define CLASSES_MULTIMEDIA_SOUND_H

#include <classes/multimedia/multimedia.h>

/* formats */

#define MMF_AUDIO_PCM8           (MMF_AUDIOMASK | 1)  /* 8-bit PCM integer signed */
#define MMF_AUDIO_PCM16BE        (MMF_AUDIOMASK | 2)  /* 16-bit PCM integer signed big endian */
#define MMF_AUDIO_PCM24BE        (MMF_AUDIOMASK | 3)  /* 24-bit PCM integer signed big endian */
#define MMF_AUDIO_PCM32BE        (MMF_AUDIOMASK | 4)  /* 32-bit PCM integer signed big endian */
#define MMF_AUDIO_PCM16LE        (MMF_AUDIOMASK | 5)  /* 16-bit PCM integer signed little endian */
#define MMF_AUDIO_PCM24LE        (MMF_AUDIOMASK | 6)  /* 24-bit PCM integer signed little endian */
#define MMF_AUDIO_PCM32LE        (MMF_AUDIOMASK | 7)  /* 32-bit PCM integer signed little endian */
#define MMF_AUDIO_PCM8U          (MMF_AUDIOMASK | 8)  /* 8-bit PCM integer unsigned */
#define MMF_AUDIO_MPEG           (MMF_AUDIOMASK | 9)  /* MPEG audio, norm 1, 2, 2.5, layer II, III */
#define MMF_AUDIO_PCMF32LE       (MMF_AUDIOMASK | 10) /* 32-bit PCM floating point low endian */
#define MMF_AUDIO_MULAW          (MMF_AUDIOMASK | 11) /* 8-bit nonlinear mu-law PCM */
#define MMF_AUDIO_ALAW           (MMF_AUDIOMASK | 12) /* 8-bit nonlinear A-law PCM */
#define MMF_AUDIO_IMA_ADPCM      (MMF_AUDIOMASK | 13) /* 3/4 bit IMA ADPCM */
#define MMF_AUDIO_PCMF32BE       (MMF_AUDIOMASK | 14) /* 32-bit PCM floating point big endian */
#define MMF_AUDIO_MS_ADPCM       (MMF_AUDIOMASK | 15) /* 4 bit MS ADPCM */
#define MMF_AUDIO_FIB_DPCM       (MMF_AUDIOMASK | 16) /* 4 bit Fibonacci delta PCM (IFF 8SVX) */
#define MMF_AUDIO_EXP_DPCM       (MMF_AUDIOMASK | 17) /* 4 bit exponential delta PCM (IFF 8SVX) */
#define MMF_AUDIO_PCM16UBE       (MMF_AUDIOMASK | 18) /* 16-bit PCM integer unsigned big endian */
#define MMF_AUDIO_PCM16ULE       (MMF_AUDIOMASK | 19) /* 16-bit PCM integer unsigned little endian */
#define MMF_AUDIO_FLAC           (MMF_AUDIOMASK | 20) /* encoded FLAC data stream */
#define MMF_AUDIO_PCM24UBE       (MMF_AUDIOMASK | 21) /* 24-bit PCM integer unsigned big endian */
#define MMF_AUDIO_PCM24ULE       (MMF_AUDIOMASK | 22) /* 24-bit PCM integer unsigned little endian */
#define MMF_AUDIO_PCM32UBE       (MMF_AUDIOMASK | 23) /* 32-bit PCM integer unsigned big endian */
#define MMF_AUDIO_PCM32ULE       (MMF_AUDIOMASK | 24) /* 32-bit PCM integer unsigned little endian */

/* methods */

/* backward compatibility for obsolete methods */

#define MMM_Sound_SignalAtEnd MMM_SignalAtEnd

/* attributes */

/*--------------------------------*/
/* applicability:                 */
/* I - init                       */
/* S - set on object              */
/* G - get from object            */
/* P - set on port                */
/* Q - get from port              */
/* . - not applicable             */
/* ? - class dependent            */
/* Refer to autodocs for details. */
/*--------------------------------*/


#define MMA_Sound_Channels            (MMA_Dummy + 300) /* [??G?Q] number of sound channels */
#define MMA_Sound_SampleRate          (MMA_Dummy + 301) /* [??G?Q] sampling rate */

/* SNDA_FrameCount attribute is 64-bit, it takes a pointer to QUAD. */

#define MMA_Sound_FrameCount          (MMA_Dummy + 302) /* [??G?Q] total frame count */
#define MMA_Sound_Volume              (MMA_Dummy + 303) /* [??G?Q] default sound volume (max if not specified) */
#define MMA_Sound_BitsPerSample       (MMA_Dummy + 304) /* [??G.Q] 64 max */
#define MMA_Sound_AhiUnit             (MMA_Dummy + 305) /* [I.G.Q] audio.output */
#define MMA_Sound_LoopedPlay          (MMA_Dummy + 306) /* [ISGPQ] audio.output */
#define MMA_Sound_FrameScan           (MMA_Dummy + 307) /* [I....] various demuxers/decoders */
#define MMA_Sound_FrameScanHook       (MMA_Dummy + 308) /* [I....] mpegaudio.demuxer */
#define MMA_Sound_Mute                (MMA_Dummy + 309) /* [ISGPQ] audio.output */

/*----------------------------------------------------------------------------*/
/*  fir.filter                                                                */
/*----------------------------------------------------------------------------*/

#define MMA_FirFilter_Table           (MMA_Dummy + 1000)  /* filter taps */
#define MMA_FirFilter_Taps            (MMA_Dummy + 1001)  /* number of filter taps */

/*----------------------------------------------------------------------------*/
/*  soundloop.filter                                                          */
/*----------------------------------------------------------------------------*/

#define MMA_SoundLoop_Start           (MMA_Dummy + 1002)  /* [I....] */
#define MMA_SoundLoop_End             (MMA_Dummy + 1003)  /* [I....] */
#define MMA_SoundLoop_Count           (MMA_Dummy + 1004)  /* [I....] */

/*----------------------------------------------------------------------------*/
/*  normalize.filter                                                          */
/*----------------------------------------------------------------------------*/

#define MMA_Normalize_Gain            (MMA_Dummy + 1005)  /* [..G.Q], DOUBLE*, normalizer gain */

/*----------------------------------------------------------------------------*/
/*  gapless.filter                                                            */
/*----------------------------------------------------------------------------*/

#define MMA_Gapless_ActiveInput       (MMA_Dummy + 1006)  /* [..G.Q] active input port */

/*----------------------------------------------------------------------------*/
/*  audiomixer.filter                                                         */
/*----------------------------------------------------------------------------*/

#define MMA_AudioMixer_Inputs         (MMA_Dummy + 1007)  /* [I.G.Q] number of inputs */
#define MMA_AudioMixer_Balance        (MMA_Dummy + 1008)  /* [ISGPQ] input or master balance */
#define MMA_AudioMixer_GainMatrix     (MMA_Dummy + 1008)  /* [...PQ] input gain matrix */
#define MMA_AudioMixer_StopOnSilence  (MMA_Dummy + 1009)  /* [ISGPQ] error at end of all inputs */
#define MMA_AudioMixer_Volume         (MMA_Dummy + 1010)  /* [ISGPQ] input or master volume */
#define MMA_AudioMixer_Mode           (MMA_Dummy + 1011)  /* [ISG.Q] mixing mode */


/*============================================================================*/
/* SPECIAL VALUES FOR ATTRIBUTES                                              */
/*============================================================================*/

#define MMV_Sound_FrameScan_Never                0
#define MMV_Sound_FrameScan_IfNeeded             1
#define MMV_Sound_FrameScan_Always               2


/* MMA_Sound_FrameScanHook hook message. */

struct FrameScanHookMsg
{
	QUAD BytesTotal;      // total length of the scanned stream in bytes
	QUAD BytesScanned;    // number of bytes scanned so far
	QUAD FramesFound;     // number of compressed (MPEG) frames detected
	QUAD AudioFound;      // number of so far scanned PCM audio frames (after decoding)
	LONG FrameBitrate;    // bitrate of the last scanned frame, in kilobits per second
};



#endif /* CLASSES_MULTIMEDIA_SOUND_H */
