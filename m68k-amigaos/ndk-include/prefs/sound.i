	IFND	PREFS_SOUND_I
PREFS_SOUND_I	SET	1
**
**	$VER: sound.i 47.1 (2.8.2019)
**
**	File format for sound preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

;---------------------------------------------------------------------------

ID_SOND equ "SOND"


   STRUCTURE SoundPrefs,0
	STRUCT sop_Reserved,4*4		; System reserved
	BOOL   sop_DisplayQueue         ; Flash the display?
	BOOL   sop_AudioQueue           ; Make some sound?
	UWORD  sop_AudioType            ; Type of sound, see below
	UWORD  sop_AudioVolume          ; Volume of sound, 0..64
	UWORD  sop_AudioPeriod          ; Period of sound, 127..2500
	UWORD  sop_AudioDuration	; Length of simple beep
	STRUCT sop_AudioFileName,256    ; Filename of 8SVX file
    LABEL SoundPrefs_SIZEOF


; constants for SoundPrefs.sop_AudioType
SPTYPE_BEEP	equ 0	; simple beep sound
SPTYPE_SAMPLE	equ 1	; sampled sound

;---------------------------------------------------------------------------

	ENDC	; PREFS_SOUND_I
