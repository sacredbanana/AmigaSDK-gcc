#ifndef PREFS_SOUND_H
#define PREFS_SOUND_H
/*
**    $VER: sound.h 54.16 (22.08.2022)
**
**    File format for sound preferences
**
**    Copyright (C) 1985-2008 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define ID_SOND MAKE_ID('S','O','N','D')

struct SoundPrefs
{
    int32	sop_Reserved[3];        /* System reserved              */
    uint16	sop_PlayBootSound;      /* Play boot sound: 0=no, 1=yes (V52) */
									/* V52.5 - split the 1x32bit field into 2x16 */
    uint16	sop_BootSoundAudioVolume; /* Volume of Boot sound, 0..64 (V52.5) */
    BOOL	sop_DisplayQueue;       /* Flash the display?           */
    BOOL	sop_AudioQueue;         /* Make some sound?             */
    uint16	sop_AudioType;          /* Type of sound, see below     */
    uint16	sop_AudioVolume;        /* Volume of sound, 0..64       */
    uint16	sop_AudioPeriod;        /* Period of sound, 127..2500   */
    uint16	sop_AudioDuration;      /* Length of simple beep        */
    TEXT  sop_AudioFileName[256]; /* Filename of 8SVX file        */
	/* Fields added in V52 */
    TEXT  sop_BootSoundFileName[256]; /* Filename of audio file   */
};

/* constants for SoundPrefs.sop_AudioType */
#define SPTYPE_BEEP   0 /* simple beep sound */
#define SPTYPE_SAMPLE 1 /* sampled sound     */

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* PREFS_SOUND_H */
