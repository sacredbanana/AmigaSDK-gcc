/* 
$VER: video.h 51.8 (16.9.2007)
*/

/* video objects methods and attributes */

#ifndef CLASSES_MULTIMEDIA_VIDEO_H
#define CLASSES_MULTIMEDIA_VIDEO_H

#include <classes/multimedia/multimedia.h>

/* formats */

#define MMF_VIDEO_BMP            (MMF_VIDEOMASK + 1)
#define MMF_VIDEO_PNG            (MMF_VIDEOMASK + 2)   /* PNG zlib stream */
#define MMF_VIDEO_BITPLANES      (MMF_VIDEOMASK + 3)   /* bitplanes */
#define MMF_VIDEO_GRAY8          (MMF_VIDEOMASK + 4)   /* raw 8-bit grayscale */
#define MMF_VIDEO_GRAY16BE       (MMF_VIDEOMASK + 5)   /* raw 16-bit grayscale, big endian */
#define MMF_VIDEO_RGB24          (MMF_VIDEOMASK + 6)   /* raw RGB, 8 bits per gun */
#define MMF_VIDEO_RGB48BE        (MMF_VIDEOMASK + 7)   /* raw RGB, 16 bits per gun, big endian */
#define MMF_VIDEO_GIF            (MMF_VIDEOMASK + 8)   /* GIF compressed stream */
#define MMF_VIDEO_LUT8           (MMF_VIDEOMASK + 9)   /* raw, palette based, 256 colors */
#define MMF_VIDEO_IFFDEEP        (MMF_VIDEOMASK + 10)  /* IFF DEEP */
#define MMF_VIDEO_IFFILBM        (MMF_VIDEOMASK + 11)  /* IFF ILBM */
#define MMF_VIDEO_PCX            (MMF_VIDEOMASK + 12)
#define MMF_VIDEO_JPEG           (MMF_VIDEOMASK + 13)
#define MMF_VIDEO_ZXSPECTRUM     (MMF_VIDEOMASK + 14)  /* ZX Spectrum screen dump */
#define MMF_VIDEO_TARGA          (MMF_VIDEOMASK + 15)  /* Targa */
#define MMF_VIDEO_IFFANIM5       (MMF_VIDEOMASK + 16)
#define MMF_VIDEO_IFFANIM7       (MMF_VIDEOMASK + 17)
#define MMF_VIDEO_SUNRASTER      (MMF_VIDEOMASK + 18)
#define MMF_VIDEO_AMIGAICON      (MMF_VIDEOMASK + 19)
#define MMF_VIDEO_RGBA32         (MMF_VIDEOMASK + 20)  /* raw RGBA, 8 bits per gun */
#define MMF_VIDEO_DEGAS          (MMF_VIDEOMASK + 21)  /* Atari Degas */
#define MMF_VIDEO_BGR24          (MMF_VIDEOMASK + 22)  /* raw data, 8 bits per gun */
#define MMF_VIDEO_ABGR32         (MMF_VIDEOMASK + 23)  /* raw data, 8 bits per gun */
#define MMF_VIDEO_ARGB32         (MMF_VIDEOMASK + 24)  /* raw data, 8 bits per gun */
#define MMF_VIDEO_TIFF           (MMF_VIDEOMASK + 25)
#define MMF_VIDEO_BGRA32         (MMF_VIDEOMASK + 26)  /* raw data, 8 bits per gun */


/* methods */

/* attributes */

#define MMA_Video_Width               (MMA_Dummy + 400)
#define MMA_Video_Height              (MMA_Dummy + 401)
#define MMA_Video_BitsPerPixel        (MMA_Dummy + 402)
#define MMA_Video_FrameCount          (MMA_Dummy + 403)
#define MMA_Video_SrcOffsetX          (MMA_Dummy + 404)
#define MMA_Video_SrcOffsetY          (MMA_Dummy + 405)
#define MMA_Video_RastPort            (MMA_Dummy + 406)
#define MMA_Video_DestOffsetX         (MMA_Dummy + 407)
#define MMA_Video_DestOffsetY         (MMA_Dummy + 408)
#define MMA_Video_UseAlpha            (MMA_Dummy + 409)
#define MMA_Video_GlobalAlpha         (MMA_Dummy + 410)
#define MMA_Video_Progressive         (MMA_Dummy + 411)
#define MMA_Video_FinalTouch          (MMA_Dummy + 412)
#define MMA_Video_Palette             (MMA_Dummy + 413)
#define MMA_Video_GammaCorrection     (MMA_Dummy + 414)
#define MMA_Video_SourceWidth         (MMA_Dummy + 415)
#define MMA_Video_SourceHeight        (MMA_Dummy + 416)
#define MMA_Video_FpsNumerator        (MMA_Dummy + 417)
#define MMA_Video_BgColor             (MMA_Dummy + 418)
#define MMA_Video_FpsDenominator      (MMA_Dummy + 419)
#define MMA_Video_SyncSignal          (MMA_Dummy + 420)
#define MMA_Video_SyncTask            (MMA_Dummy + 421)
#define MMA_Video_SyncPort            (MMA_Dummy + 422)
#define MMA_Video_Unbuffered          (MMA_Dummy + 423)
#define MMA_Video_ToGray              (MMA_Dummy + 424)
#define MMA_Video_PaletteLength       (MMA_Dummy + 425)
#define MMA_Video_LinePadding         (MMA_Dummy + 426)  /* videopcm.encoder, in bytes, 1, 2 or 4 */

/* Mask data right after image (used by bmp.decoder) */

#define MMA_Video_MaskAfterImage      (MMA_Dummy + 499)

/* Bytes per line (modulo) used by bitplane.decoder. */

#define MMA_Video_BytesPerLine        (MMA_Dummy + 498)

/* Color to gray conversion types. */

#define MMV_Video_ToGray_Mean          1
#define MMV_Video_ToGray_Luma          2
#define MMV_Video_ToGray_Min           3
#define MMV_Video_ToGray_Max           4

/* Video metaformat */

#define MMMF_PIXMAP                  1
#define MMMF_RECTFILL                2
#define MMMF_WAIT                    3
#define MMMF_SAVE                    4
#define MMMF_RESTORE                 5
#define MMMF_END                     6

struct MFHeader
{
	ULONG Type;    /* one of MMMF_XXXXX above */
	ULONG Length;  /* in LONG-s */
};

/*============================================================================*/
/* MMMF_RECTFILL draws a filled rectangle.                                    */
/*============================================================================*/

struct MFRectFill    /* 0 pixels follow */
{
	ULONG Left;
	ULONG Top;
	ULONG Width;
	ULONG Height;
	ULONG Color;
};

/*============================================================================*/
/* MMMF_PIXMAP draws a rectangular pixmap, ARGB32 pixmap data directly        */
/* follows this structure in the metastream. There are exactly Width * Height */
/* longwords.                                                                 */
/*============================================================================*/

struct MFPixMap      /* mfpm_Width * mfpm_Height pixels follow */
{
	ULONG Left;
	ULONG Top;
	ULONG Width;
	ULONG Height;
	ULONG Transparent;
};

/*============================================================================*/
/* MMMF_WAIT directs player to wait to the specified timepoint of stream.     */
/*============================================================================*/

struct MFWait
{
	ULONG MicrosHigh;
	ULONG MicrosLow;
};

/*============================================================================*/
/* MMMF_SAVE instructs player to save a rectangular output area to a buffer   */
/* identified by 'Id' for later use.                                          */
/*============================================================================*/

struct MFSave
{
	ULONG Left;
	ULONG Top;
	ULONG Width;
	ULONG Height;
	ULONG Id;
};

/*============================================================================*/
/* MMMF_RESTORE requests restoring rectangular pixmap from a buffer identi-   */
/* fied by 'Id' and place it at specified coordinates.                        */
/*============================================================================*/

struct MFRestore
{
	ULONG Left;
	ULONG Top;
	ULONG Id;
};

#endif /* CLASSES_MULTIMEDIA_PICTURE_H */
