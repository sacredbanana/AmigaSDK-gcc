#ifndef DATATYPES_SOUNDCLASS_H
#define DATATYPES_SOUNDCLASS_H

/*
	datatypes sound-object definitions (V50)

	$VER: soundclass.h 50.14 (19.8.2003)

	Copyright © 2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DATATYPES_DATATYPESCLASS_H
# include <datatypes/datatypesclass.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#pragma pack(2)

/*****************************************************************************/

#define SOUNDDTCLASS    "sound.datatype"


/*****************************************************************************/
/* Sound streaming methods */

#define SDTM_Dummy            (DTM_Dummy + 0x200)

#define SDTM_FETCH            (SDTM_Dummy + 1)
#define SDTM_APPEND           (SDTM_Dummy + 2)
#define SDTM_REWIND           (SDTM_Dummy + 3)


/* message structure for streaming methods */

struct sdtFetch
{
	ULONG MethodID;             /* SDTM_FETCH */
	APTR  sdtf_Buffer;          /* pointer to application provided buffer */
	ULONG sdtf_Length;          /* length of the buffer in bytes*/
	ULONG sdtf_Actual;          /* actual length of fetched data in bytes */
	ULONG sdtf_EndOfStream;     /* true for end of stream */
};

struct sdtAppend
{
	ULONG MethodID;             /* SDTM_APPEND */
	BPTR  sdta_Handle;          /* DOS file handle data will be written to */
	APTR  sdta_Buffer;          /* pointer to data provided by application */
	ULONG sdta_Length;          /* length of the data in bytes*/
	ULONG sdta_EndOfStream;     /* set to true for end of stream */
};


/*****************************************************************************/
/* Sound attributes */

#define SDTA_Dummy            (DTA_Dummy + 500)

#define SDTA_VoiceHeader      (SDTA_Dummy + 1)	/* OBSOLETE! */
#define SDTA_Sample           (SDTA_Dummy + 2)
#define SDTA_SampleLength     (SDTA_Dummy + 3)
#define SDTA_Period           (SDTA_Dummy + 4)	/* OBSOLETE! */
#define SDTA_Volume           (SDTA_Dummy + 5)
#define SDTA_Cycles           (SDTA_Dummy + 6)  /* not supported yet  */
#define SDTA_SignalTask       (SDTA_Dummy + 7)

/*         NOTE: Due to a bug in sound.datatype V40 SDTA_SignalBit
 *               was actually implemented as a signal mask as opposed
 *               to a bit number. The documentation now reflects
 *               this. If you intend to use a signal bit number
 *               instead of the mask, use the new V44 tag
 *               SDTA_SignalBitNumber below.
 */

#define SDTA_SignalBit        (SDTA_Dummy + 8)
#define SDTA_SignalBitMask     SDTA_SignalBit
#define SDTA_Continuous       (SDTA_Dummy + 9)
#define SDTA_SignalBitNumber  (SDTA_Dummy + 10)

/* #define SDTA_ReplayPeriod     (SDTA_Dummy + 12)  not supported yet */
/* #define SDTA_SyncSampleChange (SDTA_Dummy + 17)  not supported yet */

#define SDTA_Panning          (SDTA_Dummy + 31)
#define SDTA_Frequency        (SDTA_Dummy + 32)
#define SDTA_Mode             (SDTA_Dummy + 33)
#define SDTA_PreciseVolume    (SDTA_Dummy + 34)
#define SDTA_Duration         (SDTA_Dummy + 35)
#define SDTA_SampleType       (SDTA_Dummy + 36)
#define SDTA_Codec            (SDTA_Dummy + 37)

/*****************************************************************************/
/* SDTA_Mode sound.datatype API modes */

#define SDTA_Mode_Compatible    0
#define SDTA_Mode_Extended      1


/*****************************************************************************/
/* definitions for SDTA_SampleType (all types are signed) */

#define SDTST_M8S   0x00010001   /* 8bit mono sample (default) */
#define SDTST_S8S   0x00020001   /* 8bit stereo sample (samplewise left/right) */
#define SDTST_M16S  0x00010002   /* same as SDTST_M8S but 16bit */
#define SDTST_S16S  0x00020002   /* same as SDTST_S8S but 16bit */

/* How to construct SDTA_SampleValue for any number of channels and sample   */
/* size? The high word of sample type contains number of channels. The low   */
/* word contains size of single sample (not frame) in bytes.                 */
/* example: 5-channel 48-bit sound sample has sample type of 0x00050006.     */
/* Some common types are defined above.                                      */


/****************************************************************************/
/* some handy macros */

#define SDTM_CHANNELS(SampleType)        (SampleType >> 16)
#define SDTM_BYTESPERSAMPLE(SampleType)  (SampleType & 0xFFFF)
#define SDTM_BYTESPERPOINT(SampleType)   (SDTM_CHANNELS(SampleType) * SDTM_BYTESPERSAMPLE(SampleType))


/*****************************************************************************/
/* Data compression methods for 8SVX / 16SV */

#define CMP_NONE      0
#define CMP_FIBDELTA  1
#define CMP_EXPDELTA  2

/*****************************************************************************/
/* Supported data compression methods for WAVE */

#define CMP_WAVE_PCM               1
#define CMP_WAVE_MICROSOFT_ADPCM   2
#define CMP_WAVE_FLOAT32           3
#define CMP_WAVE_ALAW              6
#define CMP_WAVE_ULAW              7

/*****************************************************************************/
/* Unity = Fixed 1.0 = maximum volume */

#define Unity  0x10000UL


/*****************************************************************************/

struct VoiceHeader
{
	ULONG vh_OneShotHiSamples;  /* # samples in the high octave 1-shot part */
	ULONG vh_RepeatHiSamples;   /* # samples in the high octave repeat part */
	ULONG vh_SamplesPerHiCycle; /* # samples/cycle in high octave, else 0 */
	UWORD vh_SamplesPerSec;     /* data sampling rate */
	UBYTE vh_Octaves;           /* # of octaves of waveforms */
	UBYTE vh_Compression;       /* data compression technique used */
	ULONG vh_Volume;            /* playback nominal volume from 0 to Unity
	                             * (full volume). Map this value into
	                             * the output hardware's dynamic range.
	                             */
};


/*****************************************************************************/
/* IFF types */

#define ID_8SVX  MAKE_ID('8','S','V','X')
#define ID_16SV  MAKE_ID('1','6','S','V')
#define ID_VHDR  MAKE_ID('V','H','D','R')
#define ID_CHAN  MAKE_ID('C','H','A','N')
#define ID_BODY  MAKE_ID('B','O','D','Y')
#define ID_NAME  MAKE_ID('N','A','M','E')
#define ID_AUTH  MAKE_ID('A','U','T','H')
#define ID_ANNO  MAKE_ID('A','N','N','O')
#define ID_COPY  MAKE_ID('(','c',')',' ')


/*****************************************************************************/
/* IFF 8SVX sample types ('CHAN' property) */

#define SVX_LEFT    (2L)
#define SVX_RIGHT   (4L)
#define SVX_STEREO  (6L)


/*****************************************************************************/




#pragma pack()

#endif  /* DATATYPES_SOUNDCLASS_H */
