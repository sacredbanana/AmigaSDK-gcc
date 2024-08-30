/*
  Reggae definitions for FLAC format.

  Reggae FLAC decoder and encoder give access to many format details and internals.
  This file contains definitions for FLAC specific attributes and methods.
*/

#ifndef CLASSES_MULTIMEDIA_FLAC_H
#define CLASSES_MULTIMEDIA_FLAC_H

#include <classes/multimedia/multimedia.h>


/* methods (to override) */

#define MMM_Flac_AcceptBlock           (MMA_Dummy + 1100)

struct mmopFlacAcceptBlock
{
	ULONG MethodID;
	struct TagItem *BlockInfo;
};


/* Attributes provided as a taglist sent to MMM_Flac_AcceptBlock(). */

#define MMA_Flac_BlockData             (MMA_Dummy + 1110)   /* UBYTE*, pointer to FLAC data */
#define MMA_Flac_BlockLength           (MMA_Dummy + 1111)   /* LONG, block length in bytes */
#define MMA_Flac_HeaderLength          (MMA_Dummy + 1112)   /* LONG, block header length in bytes */
#define MMA_Flac_HeaderChecksum        (MMA_Dummy + 1113)   /* UBYTE, CRC-8 checksum of header */
#define MMA_Flac_ChecksumLoaded        (MMA_Dummy + 1114)   /* UWORD, CRC-16 of block as read from stream */
#define MMA_Flac_ChecksumComputed      (MMA_Dummy + 1115)   /* UWORD, CRC-16 of block as calculated from data */
#define MMA_Flac_StreamPosition        (MMA_Dummy + 1116)   /* QUAD*, block position in (headerless) stream */
#define MMA_Flac_AudioFrames           (MMA_Dummy + 1117)   /* LONG, number of audio frames in block */
#define MMA_Flac_VariableBlock         (MMA_Dummy + 1118)   /* BOOL, TRUE if blocking mode flag set for the block */
#define MMA_Flac_SampleRate            (MMA_Dummy + 1119)   /* LONG, sample rate of block in Hz */
#define MMA_Flac_Channels              (MMA_Dummy + 1120)   /* LONG, number of audio channels in block */
#define MMA_Flac_StereoMode            (MMA_Dummy + 1121)   /* LONG, stereo decorrelation mode (see values below) */
#define MMA_Flac_BitsPerSample         (MMA_Dummy + 1122)   /* LONG, bits per sample (already taken from demuxer if needed) */
#define MMA_Flac_FirstAudioFrame       (MMA_Dummy + 1123)   /* QUAD*, first audio frame of block */

/* Stereo decorrelation modes. */

#define MMV_Flac_StereoMode_None       0                    /* block is not stereo */
#define MMV_Flac_StereoMode_LR         1                    /* channel 0: left, channel 1: right */
#define MMV_Flac_StereoMode_LS         2                    /* channel 0: left, channel 1: side */
#define MMV_Flac_StereoMode_SR         3                    /* channel 0: side, channel 1: right */
#define MMV_Flac_StereoMode_MS         4                    /* channel 0: middle, channel 1: side */

/* Subblock types. */

#define MMV_Flac_SubType_Undefined     0
#define MMV_Flac_SubType_Constant      1
#define MMV_Flac_SubType_Verbatim      2
#define MMV_Flac_SubType_Fixed         3
#define MMV_Flac_SubType_LPC           4


#endif /* CLASSES_MULTIMEDIA_FLAC_H */
