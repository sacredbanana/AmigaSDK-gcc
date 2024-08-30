#ifndef GRAPHICS_DISPLAYINFO_H
#define GRAPHICS_DISPLAYINFO_H

/*
	graphics displayinfo definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#ifndef GRAPHICS_MONITOR_H
# include <graphics/monitor.h>
#endif

#ifndef GRAPHICS_MODEID_H
# include <graphics/modeid.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


typedef APTR DisplayInfoHandle;


#define DTAG_DISP  0x80000000
#define DTAG_DIMS  0x80001000
#define DTAG_MNTR  0x80002000
#define DTAG_NAME  0x80003000
#define DTAG_VEC   0x80004000


struct QueryHeader
{
	ULONG StructID;
	ULONG DisplayID;
	ULONG SkipID;
	ULONG Length;
};

struct DisplayInfo
{
	struct QueryHeader Header;
	UWORD              NotAvailable;
	ULONG              PropertyFlags;
	Point              Resolution;
	UWORD              PixelSpeed;
	UWORD              NumStdSprites;
	UWORD              PaletteRange;
	Point              SpriteResolution;
	UBYTE              pad[4];
	UBYTE              RedBits;
	UBYTE              GreenBits;
	UBYTE              BlueBits;
	UBYTE              pad2[5];
	ULONG              reserved[2];
};


#define DI_AVAIL_NOCHIPS         0x0001
#define DI_AVAIL_NOMONITOR       0x0002
#define DI_AVAIL_NOTWITHGENLOCK  0x0004


#define DIPF_IS_LACE               0x00000001
#define DIPF_IS_DUALPF             0x00000002
#define DIPF_IS_PF2PRI             0x00000004
#define DIPF_IS_HAM                0x00000008

#define DIPF_IS_ECS                0x00000010
#define DIPF_IS_AA                 0x00010000

#define DIPF_IS_PAL                0x00000020
#define DIPF_IS_SPRITES            0x00000040
#define DIPF_IS_GENLOCK            0x00000080

#define DIPF_IS_WB                 0x00000100
#define DIPF_IS_DRAGGABLE          0x00000200
#define DIPF_IS_PANELLED           0x00000400
#define DIPF_IS_BEAMSYNC           0x00000800

#define DIPF_IS_EXTRAHALFBRITE     0x00001000

#define DIPF_IS_SPRITES_ATT        0x00002000
#define DIPF_IS_SPRITES_CHNG_RES   0x00004000
#define DIPF_IS_SPRITES_BORDER     0x00008000
#define DIPF_IS_SCANDBL            0x00020000
#define DIPF_IS_SPRITES_CHNG_BASE  0x00040000
#define DIPF_IS_SPRITES_CHNG_PRI   0x00080000
#define DIPF_IS_DBUFFER            0x00100000
#define DIPF_IS_PROGBEAM           0x00200000
#define DIPF_IS_FOREIGN            0x80000000


struct DimensionInfo
{
	struct QueryHeader Header;
	UWORD              MaxDepth;
	UWORD              MinRasterWidth;
	UWORD              MinRasterHeight;
	UWORD              MaxRasterWidth;
	UWORD              MaxRasterHeight;
	struct Rectangle   Nominal;
	struct Rectangle   MaxOScan;
	struct Rectangle   VideoOScan;
	struct Rectangle   TxtOScan;
	struct Rectangle   StdOScan;
	UBYTE              pad[14];
	ULONG              reserved[2];
};

struct MonitorInfo
{
	struct QueryHeader  Header;
	struct MonitorSpec *Mspc;
	Point               ViewPosition;
	Point               ViewResolution;
	struct Rectangle    ViewPositionRange;
	UWORD               TotalRows;
	UWORD               TotalColorClocks;
	UWORD               MinRow;
	WORD                Compatibility;
	UBYTE               pad[32];
	Point               MouseTicks;
	Point               DefaultViewPosition;
	ULONG               PreferredModeID;
	ULONG               reserved[2];
};


#define MCOMPAT_MIXED    0
#define MCOMPAT_SELF     1
#define MCOMPAT_NOBODY  -1

#define DISPLAYNAMELEN  32

struct NameInfo
{
	struct QueryHeader Header;
	UBYTE              Name[DISPLAYNAMELEN];
	ULONG              reserved[2];
};


struct VecInfo
{
	struct QueryHeader Header;
	APTR               Vec;
	APTR               Data;
	UWORD              Type;
	UWORD              pad[3];
	ULONG              reserved[2];
};


#pragma pack()

#endif /* GRAPHICS_DISPLAYINFO_H */
