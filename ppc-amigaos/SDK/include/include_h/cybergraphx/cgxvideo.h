#include <exec/types.h>

#ifndef  RTG_BASE_H
#include <rtgBase.h>
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

struct VLayerHandle
{
	struct ExtraData	Extra;
	ULONG	leftIndent;
	ULONG	rightIndent;
	ULONG	topIndent;
	ULONG	bottomIndent;
	LONG	Pen;
	ULONG	Color;
	ULONG	useBackFill;
	struct Window		*Window;
	struct ColorMap	*ColorMap;
	struct Hook			Hook, *oldHook;
	struct SignalSemaphore	NestCountLock;
	UWORD	NestCount;
	struct p96SemaphoreHandle	Lock;
	struct BitMap *SourceBitMap;
	struct RastPort	RastPort;
	struct GraphicsIFace *IGraphics;
};

#define VOA_LeftIndent    0x88000001
#define VOA_RightIndent   0x88000002
#define VOA_TopIndent     0x88000003
#define VOA_BottomIndent  0x88000004

#define VOA_SrcType     0x88000005
#define VOA_SrcWidth    0x88000006
#define VOA_SrcHeight   0x88000007

#define VOA_Error       0x88000008

#define VOA_UseColorKey	0x88000009

#define VOA_UseBackfill 0x8800000a

#define VOA_BaseAddress 0x88000030
#define VOA_ColorKeyPen 0x88000031
#define VOA_ColorKey    0x88000032

/* v42 additions */
#define VOA_Modulo 		0x88000038

/* possible errors returned with VOA_Error tag */

#define VOERR_OK                0       /* No error */
#define VOERR_INVSCRMODE        1       /* video overlay not possible for that mode */
#define VOERR_NOOVLMEMORY       2       /* No memory for video overlay */
#define VOERR_INVSRCFMT         3       /* Source format not supported */
#define VOERR_NOMEMORY          4       /* Not enough memory */

/* Src types */

#define SRCFMT_YUV16    0
#define SRCFMT_YCbCr16  1
#define SRCFMT_RGB15    2
#define SRCFMT_RGB16    3

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif
