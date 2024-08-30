#ifndef GRAPHICS_SCALE_H
#define GRAPHICS_SCALE_H

/*
	graphics BitMapScale definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct BitScaleArgs
{
	UWORD          bsa_SrcX, bsa_SrcY;
	UWORD          bsa_SrcWidth, bsa_SrcHeight;
	UWORD          bsa_XSrcFactor, bsa_YSrcFactor;
	UWORD          bsa_DestX, bsa_DestY;
	UWORD          bsa_DestWidth, bsa_DestHeight;
	UWORD          bsa_XDestFactor, bsa_YDestFactor;
	struct BitMap *bsa_SrcBitMap;
	struct BitMap *bsa_DestBitMap;
	ULONG          bsa_Flags;
	UWORD          bsa_XDDA, bsa_YDDA;
	LONG           bsa_Reserved1;
	LONG           bsa_Reserved2;
};


#pragma pack()

#endif /* GRAPHICS_SCALE_H */
