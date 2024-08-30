#ifndef DEVICES_PRTGFX_H
#define DEVICES_PRTGFX_H

/*
	printer graphics driver definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef GRAPHICS_RASTPORT_H
# include <graphics/rastport.h>
#endif

#pragma pack(2)


#define PCMYELLOW   0
#define PCMMAGENTA  1
#define PCMCYAN     2
#define PCMBLACK    3
#define PCMBLUE     PCMYELLOW
#define PCMGREEN    PCMMAGENTA
#define PCMRED      PCMCYAN
#define PCMWHITE    PCMBLACK


union colorEntry
{
	ULONG colorLong;
	UBYTE colorByte[4];
	BYTE  colorSByte[4];
};


struct PrtInfo
{
	LONG             (*pi_render)(VOID);
	struct RastPort   *pi_rp;
	struct RastPort   *pi_temprp;
	UWORD             *pi_RowBuf;
	UWORD             *pi_HamBuf;
	union colorEntry  *pi_ColorMap;
	union colorEntry  *pi_ColorInt;
	union colorEntry  *pi_HamInt;
	union colorEntry  *pi_Dest1Int;
	union colorEntry  *pi_Dest2Int;
	UWORD             *pi_ScaleX;
	UWORD             *pi_ScaleXAlt;
	UBYTE             *pi_dmatrix;
	UWORD             *pi_TopBuf;
	UWORD             *pi_BotBuf;

	UWORD              pi_RowBufSize;
	UWORD              pi_HamBufSize;
	UWORD              pi_ColorMapSize;
	UWORD              pi_ColorIntSize;
	UWORD              pi_HamIntSize;
	UWORD              pi_Dest1IntSize;
	UWORD              pi_Dest2IntSize;
	UWORD              pi_ScaleXSize;
	UWORD              pi_ScaleXAltSize;

	UWORD              pi_PrefsFlags;
	ULONG              pi_special;
	UWORD              pi_xstart;
	UWORD              pi_ystart;
	UWORD              pi_width;
	UWORD              pi_height;
	ULONG              pi_pc;
	ULONG              pi_pr;
	UWORD              pi_ymult;
	UWORD              pi_ymod;
	WORD               pi_ety;
	UWORD              pi_xpos;
	UWORD              pi_threshold;
	UWORD              pi_tempwidth;
	UWORD              pi_flags;

	/*** V44 ***/

	UWORD             *pi_ReduceBuf;
	UWORD              pi_ReduceBufSize;
	struct Hook       *pi_SourceHook;
	ULONG             *pi_InvertHookBuf;
};


#pragma pack()

#endif /* DEVICES_PRTGFX_H */
