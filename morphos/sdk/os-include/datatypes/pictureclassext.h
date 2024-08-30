#ifndef DATATYPES_PICTURECLASSEXT_H
#define DATATYPES_PICTURECLASSEXT_H

/*
	datatypes picture-object definitions extension wrapper (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DATATYPES_PICTURECLASS_H
# include <datatypes/pictureclass.h>
#endif

#pragma pack(2)


#define DTM_WRITEPIXELARRAY  PDTM_WRITEPIXELARRAY
#define DTM_READPIXELARRAY   PDTM_READPIXELARRAY
#define DTM_CREATEPIXMAPDIR  PDTM_CREATEPIXMAPDIR
#define DTM_FIRSTPIXMAPDIR   PDTM_FIRSTPIXMAPDIR
#define DTM_NEXTPIXMAPDIR    PDTM_NEXTPIXMAPDIR
#define DTM_PREVPIXMAPDIR    PDTM_PREVPIXMAPDIR
#define DTM_BESTPIXMAPDIR    PDTM_BESTPIXMAPDIR


/* Identical to struct pdtBlitPixelArray, please use that instead */
struct gpBlitPixelArray
{
	ULONG  MethodID;
	UBYTE *PixelArray;
	ULONG  PixelArrayMode;
	ULONG  PixelArrayMod;
	ULONG  LeftEdge;
	ULONG  TopEdge;
	ULONG  Width;
	ULONG  Height;
};


#define MODE_V42  PMODE_V42
#define MODE_V43  PMODE_V43


#pragma pack()

#endif
