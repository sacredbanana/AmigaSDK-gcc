#ifndef DATATYPES_PICTURECLASS_H
#define DATATYPES_PICTURECLASS_H
/*
**    $VER: pictureclass.h 54.16 (22.08.2022)
**
**    Interface definitions for DataType picture objects.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
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

#define PICTUREDTCLASS "picture.datatype"

/*****************************************************************************/

/* Picture attributes */

/* Mode ID of the picture (ULONG). */
#define PDTA_ModeID           (DTA_Dummy + 200)

/* Bitmap header information (struct BitMapHeader *). */
#define PDTA_BitMapHeader     (DTA_Dummy + 201)

/* Pointer to a subclass-allocated bitmap, that will end up
 * being freed by the picture class when DisposeDTObject()
 * is called (struct BitMap *).
 */
#define PDTA_BitMap           (DTA_Dummy + 202)

/* Picture color table (struct ColorRegister *). */
#define PDTA_ColorRegisters   (DTA_Dummy + 203)

/* Color table to use with SetRGB32CM() (ULONG *). */
#define PDTA_CRegs            (DTA_Dummy + 204)

/* Color table; this table is initialized during the layout
 * process and will contain the colours the picture will use
 * after remapping. If no remapping takes place, these colours
 * will match those in the PDTA_CRegs table (ULONG *).
 */
#define PDTA_GRegs            (DTA_Dummy + 205)

/* Shared pen table; this table is initialized during the layout
 * process while the picture is being remapped (UBYTE *).
 */
#define PDTA_ColorTable       (DTA_Dummy + 206)

/* Shared pen table; in most places this table will be identical to
 * the PDTA_ColorTable table. Some of the colours in this table might
 * match the original colour palette a little better than the colours
 * picked for the other table. The picture.datatype uses the two tables
 * during remapping, alternating for each pixel (UBYTE *).
 */
#define PDTA_ColorTable2      (DTA_Dummy + 207)

/* OBSOLETE; DO NOT USE */
#define PDTA_Allocated        (DTA_Dummy + 208)

/* Number of colors used by the picture (UWORD). */
#define PDTA_NumColors        (DTA_Dummy + 209)

/* Number of colors allocated by the picture (UWORD). */
#define PDTA_NumAlloc         (DTA_Dummy + 210)

/* Remap the picture (BOOL); defaults to TRUE. */
#define PDTA_Remap            (DTA_Dummy + 211)

/* Screen to remap to (struct Screen *). */
#define PDTA_Screen           (DTA_Dummy + 212)

/* Free the source bitmap after remapping (BOOL). */
#define PDTA_FreeSourceBitMap (DTA_Dummy + 213)

/* Grab point of the picture (Point *). */
#define PDTA_Grab             (DTA_Dummy + 214)

/* Pointer to the destination (remapped) bitmap (struct BitMap *). */
#define PDTA_DestBitMap       (DTA_Dummy + 215)

/* Pointer to a subclass-allocated bitmap, that will end up
 * being freed by the subclass after DisposeDTObject()
 * is called (struct BitMap *).
 */
#define PDTA_ClassBitMap      (DTA_Dummy + 216)

/* Number of colors used for sparse remapping (UWORD). */
#define PDTA_NumSparse        (DTA_Dummy + 217)

/* Pointer to a table of pen numbers indicating
 * which colors should be used when remapping the image.
 * This array must contain as many entries as there
 * are colors specified with PDTA_NumSparse (UBYTE *).
 */
#define PDTA_SparseTable      (DTA_Dummy + 218)

/* Index number of the picture to load (ULONG). (V44) */
#define PDTA_WhichPicture     (DTA_Dummy + 219)

/* Get the number of pictures stored in the file (ULONG *). (V44) */
#define PDTA_GetNumPictures   (DTA_Dummy + 220)

/* Maximum number of colours to use for dithering (ULONG). (V44) */
#define PDTA_MaxDitherPens    (DTA_Dummy + 221)

/* Quality of the dithering algorithm to be used during colour
 * quantization (ULONG). (V44)
 */
#define PDTA_DitherQuality    (DTA_Dummy + 222)

/* Pointer to the allocated pen table (UBYTE *). (V44) */
#define PDTA_AllocatedPens    (DTA_Dummy + 223)

/* Quality for scaling (ULONG). (V45) */
#define PDTA_ScaleQuality     (DTA_Dummy + 224)

/* If a CLUT (8-bit) picture with a transparent color needs to be
 * "promoted" to truecolor format for layout or scaling purposes,
 * setting this to TRUE allows the picture's transparency mask to
 * be converted as well and carried over to the truecolor data as
 * valid alpha information (BOOL). (V53)
 */
#define PDTA_PromoteMask      (DTA_Dummy + 225)

/*****************************************************************************/

/* When querying the number of pictures stored in a file, the
 * following value denotes "the number of pictures is unknown".
 */
#define PDTANUMPICTURES_Unknown (0)

/*****************************************************************************/

/* V43 extensions (attributes) */

/* Set the sub datatype interface mode (LONG); see "Interface modes" below. */
#define PDTA_SourceMode       (DTA_Dummy + 250)

/* Set the app datatype interface mode (LONG); see "Interface modes" below. */
#define PDTA_DestMode         (DTA_Dummy + 251)

/* Allocates the resulting bitmap as a friend bitmap (BOOL). */
#define PDTA_UseFriendBitMap  (DTA_Dummy + 255)

/* Returns TRUE if the bitmap has a valid alpha channel (BOOL). */
#define PDTA_AlphaChannel     (DTA_Dummy + 256)

/* NULL or mask plane for use with BltMaskBitMapRastPort() (PLANEPTR). */
#define PDTA_MaskPlane        (DTA_Dummy + 258)

/* Not supported in AmigaOS */
#define PDTA_Reserved1        (DTA_Dummy + 259)

/* OS 3.2 compatibility - use PDTM_OBTAINPIXELARRAY instead (V54) */
#define PDTA_ObtainPixelBuffer (DTA_Dummy + 260)

/*****************************************************************************/

/* Interface modes */
#define PMODE_V42 (0)    /* Compatibility mode */
#define PMODE_V43 (1)    /* Extended mode */

/*****************************************************************************/

/* V43 extensions (methods) */

#define PDTM_Dummy           (DTM_Dummy + 0x60)

/* Transfer pixel data to the picture object in the specified format */
#define PDTM_WRITEPIXELARRAY (PDTM_Dummy + 0)

/* Transfer pixel data from the picture object in the specified format */
#define PDTM_READPIXELARRAY  (PDTM_Dummy + 1)

/* PIXMAPDIR methods not supported in AmigaOS */
#define PDTM_RESERVED1       (PDTM_Dummy + 2)
#define PDTM_RESERVED2       (PDTM_Dummy + 3)
#define PDTM_RESERVED3       (PDTM_Dummy + 4)
#define PDTM_RESERVED4       (PDTM_Dummy + 5)
#define PDTM_RESERVED5       (PDTM_Dummy + 6)

/* PDTM_WRITEPIXELARRAY, PDTM_READPIXELARRAY */
struct pdtBlitPixelArray
{
    ULONG MethodID;
    APTR  pbpa_PixelData;     /* The pixel data to transfer to/from */
    ULONG pbpa_PixelFormat;   /* Format of the pixel data (see "Pixel formats" below) */
    ULONG pbpa_PixelArrayMod; /* Number of bytes per row */
    ULONG pbpa_Left;          /* Left edge of the rectangle to transfer pixels to/from */
    ULONG pbpa_Top;           /* Top edge of the rectangle to transfer pixels to/from */
    ULONG pbpa_Width;         /* Width of the rectangle to transfer pixels to/from */
    ULONG pbpa_Height;        /* Height of the rectangle to transfer pixels to/from */
};

/* Pixel formats */
#define PBPAFMT_RGB   0 /* 3 bytes per pixel (red, green, blue) */
#define PBPAFMT_RGBA  1 /* 4 bytes per pixel (red, green, blue, alpha channel) */
#define PBPAFMT_ARGB  2 /* 4 bytes per pixel (alpha channel, red, green, blue) */
#define PBPAFMT_LUT8  3 /* 1 byte per pixel (using a separate colour map) */
#define PBPAFMT_GREY8 4 /* 1 byte per pixel (0==black, 255==white) */

/*****************************************************************************/

/* V45 extensions (methods) */

/* Scale pixel data to the specified size */
#define PDTM_SCALE           (PDTM_Dummy + 2)

/* PDTM_SCALE */
struct pdtScale
{
    ULONG MethodID;
    ULONG ps_NewWidth;  /* The new width the pixel data should have */
    ULONG ps_NewHeight; /* The new height the pixel data should have */
    ULONG ps_Flags;     /* Should be 0 for now */
};

/*****************************************************************************/

/* V54 extensions (methods) */

/* Obtain direct access to the internal pixel data */
#define PDTM_OBTAINPIXELARRAY (PDTM_Dummy + 7)

/* PDTM_OBTAINPIXELARRAY */
struct pdtObtainPixelArray
{
    ULONG MethodID;
    struct pdtBlitPixelArray *popa_PixelArray; /* Get pixel data buffer details */
    ULONG popa_Flags;
};

/* If array is 8-bit, request it be set for PBPAFMT_GREY8 writes */
#define POPAF_WRITEGREY8	(1L << 0)

/*****************************************************************************/

/* Masking techniques */
#define mskNone                0
#define mskHasMask             1
#define mskHasTransparentColor 2
#define mskLasso               3
#define mskHasAlpha            4

/* Compression techniques */
#define cmpNone     0
#define cmpByteRun1 1
#define cmpByteRun2 2 /* NOTE: unused (V44) */

/* Bitmap header (BMHD) structure */
struct BitMapHeader
{
    UWORD bmh_Width;       /* Width in pixels */
    UWORD bmh_Height;      /* Height in pixels */
    WORD  bmh_Left;        /* Left position */
    WORD  bmh_Top;         /* Top position */
    UBYTE bmh_Depth;       /* Number of planes */
    UBYTE bmh_Masking;     /* Masking type */
    UBYTE bmh_Compression; /* Compression type */
    UBYTE bmh_Pad;
    UWORD bmh_Transparent; /* Transparent color */
    UBYTE bmh_XAspect;
    UBYTE bmh_YAspect;
    WORD  bmh_PageWidth;
    WORD  bmh_PageHeight;
};

/*****************************************************************************/

/* Color register structure */
struct ColorRegister
{
    UBYTE red, green, blue;
};

/*****************************************************************************/

/* IFF types that may be in pictures */
#define ID_ILBM MAKE_ID('I','L','B','M')
#define ID_BMHD MAKE_ID('B','M','H','D')
#define ID_CMAP MAKE_ID('C','M','A','P')
#define ID_CRNG MAKE_ID('C','R','N','G')
#define ID_GRAB MAKE_ID('G','R','A','B')
#define ID_SPRT MAKE_ID('S','P','R','T')
#define ID_DEST MAKE_ID('D','E','S','T')
#define ID_CAMG MAKE_ID('C','A','M','G')

#ifndef ID_BODY
#define ID_BODY MAKE_ID('B','O','D','Y')
#endif /* ID_BODY */

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

#endif /* DATATYPES_PICTURECLASS_H */
