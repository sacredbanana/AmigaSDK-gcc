#ifndef GRAPHICS_VIEW_H
#define GRAPHICS_VIEW_H

/*
	graphics viewport definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#define ECS_SPECIFIC

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#ifndef GRAPHICS_COPPER_H
# include <graphics/copper.h>
#endif

#ifndef GRAPHICS_GFXNODES_H
# include <graphics/gfxnodes.h>
#endif

#ifndef GRAPHICS_MONITOR_H
# include <graphics/monitor.h>
#endif

#ifndef GRAPHICS_DISPLAYINFO_H
# include <graphics/displayinfo.h>
#endif

#ifndef HARDWARE_CUSTOM_H
# include <hardware/custom.h>
#endif

#pragma pack(2)


struct ViewPort
{
	struct ViewPort *Next;
	struct ColorMap *ColorMap;
	struct CopList  *DspIns;
	struct CopList  *SprIns;
	struct CopList  *ClrIns;
	struct UCopList *UCopIns;
	WORD             DWidth, DHeight;
	WORD             DxOffset, DyOffset;
	UWORD            Modes;
	UBYTE            SpritePriorities;
	UBYTE            ExtendedModes;
	struct RasInfo  *RasInfo;
};

struct View
{
	struct ViewPort *ViewPort;
	struct cprlist  *LOFCprList;
	struct cprlist  *SHFCprList;
	WORD             DyOffset, DxOffset;
	UWORD            Modes;
};

struct ViewExtra
{
	struct ExtendedNode  n;
	struct View         *View;
	struct MonitorSpec  *Monitor;
	UWORD                TopLine;
};

struct ViewPortExtra
{
	struct ExtendedNode  n;
	struct ViewPort     *ViewPort;
	struct Rectangle     DisplayClip;

	APTR                 VecTable;
	APTR                 DriverData[2];
	UWORD                Flags;
	Point                Origin[2];
	ULONG                cop1ptr;
	ULONG                cop2ptr;
};

#define VPXB_FREE_ME        0
#define VPXF_FREE_ME        (1<<VPXB_FREE_ME)
#define VPXB_LAST           1
#define VPXF_LAST           (1<<VPXB_LAST)
#define VPXB_STRADDLES_256  4
#define VPXF_STRADDLES_256  (1<<VPXB_STRADDLES_256)
#define VPXB_STRADDLES_512  5
#define VPXF_STRADDLES_512  (1<<VPXB_STRADDLES_512)


#define EXTEND_VSTRUCT  0x1000

#define VPF_A2024  0x40
#define VPF_TENHZ  0x20
#define VPB_A2024  6
#define VPB_TENHZ  4


#define GENLOCK_VIDEO    0x0002
#define LACE             0x0004
#define DOUBLESCAN       0x0008
#define SUPERHIRES       0x0020
#define PFBA             0x0040
#define EXTRA_HALFBRITE  0x0080
#define GENLOCK_AUDIO    0x0100
#define DUALPF           0x0400
#define HAM              0x0800
#define EXTENDED_MODE    0x1000
#define VP_HIDE          0x2000
#define SPRITES          0x4000
#define HIRES            0x8000

struct RasInfo
{
	struct RasInfo *Next;
	struct BitMap  *BitMap;
	WORD            RxOffset, RyOffset;
};

struct ColorMap
{
	UBYTE                 Flags;
	UBYTE                 Type;
	UWORD                 Count;
	APTR                  ColorTable;
	struct ViewPortExtra *cm_vpe;
	APTR                  LowColorBits;
	UBYTE                 TransparencyPlane;
	UBYTE                 SpriteResolution;
	UBYTE                 SpriteResDefault;
	UBYTE                 AuxFlags;
	struct ViewPort      *cm_vp;
	APTR                  NormalDisplayInfo;
	APTR                  CoerceDisplayInfo;
	struct TagItem       *cm_batch_items;
	ULONG                 VPModeID;
	struct PaletteExtra  *PalExtra;
	UWORD                 SpriteBase_Even;
	UWORD                 SpriteBase_Odd;
	UWORD                 Bp_0_base;
	UWORD                 Bp_1_base;
};


#define COLORMAP_TYPE_V1_2  0x00
#define COLORMAP_TYPE_V1_4  0x01
#define COLORMAP_TYPE_V36   COLORMAP_TYPE_V1_4
#define COLORMAP_TYPE_V39   0x02

#define COLORMAP_TRANSPARENCY    0x01
#define COLORPLANE_TRANSPARENCY  0x02
#define BORDER_BLANKING          0x04
#define BORDER_NOTRANSPARENCY    0x08
#define VIDEOCONTROL_BATCH       0x10
#define USER_COPPER_CLIP         0x20
#define BORDERSPRITES            0x40

#define CMF_CMTRANS   0
#define CMF_CPTRANS   1
#define CMF_BRDRBLNK  2
#define CMF_BRDNTRAN  3
#define CMF_BRDRSPRT  6

#define SPRITERESN_ECS       0
#define SPRITERESN_140NS     1
#define SPRITERESN_70NS      2
#define SPRITERESN_35NS      3
#define SPRITERESN_DEFAULT  -1

#define CMAB_FULLPALETTE         0
#define CMAF_FULLPALETTE         (1<<CMAB_FULLPALETTE)
#define CMAB_NO_INTERMED_UPDATE  1
#define CMAF_NO_INTERMED_UPDATE  (1<<CMAB_NO_INTERMED_UPDATE)
#define CMAB_NO_COLOR_LOAD       2
#define CMAF_NO_COLOR_LOAD       (1<<CMAB_NO_COLOR_LOAD)
#define CMAB_DUALPF_DISABLE      3
#define CMAF_DUALPF_DISABLE      (1<<CMAB_DUALPF_DISABLE)


struct PaletteExtra
{
	struct SignalSemaphore  pe_Semaphore;
	UWORD                   pe_FirstFree;
	UWORD                   pe_NFree;
	UWORD                   pe_FirstShared;
	UWORD                   pe_NShared;
	UBYTE                  *pe_RefCnt;
	UBYTE                  *pe_AllocList;
	struct ViewPort        *pe_ViewPort;
	UWORD                   pe_SharableColors;
};


#define PENB_EXCLUSIVE    0
#define PENB_NO_SETCOLOR  1

#define PENF_EXCLUSIVE    (1<<PENB_EXCLUSIVE)
#define PENF_NO_SETCOLOR  (1<<PENB_NO_SETCOLOR)

#define PEN_EXCLUSIVE    PENF_EXCLUSIVE
#define PEN_NO_SETCOLOR  PENF_NO_SETCOLOR


#define PRECISION_EXACT  -1
#define PRECISION_IMAGE   0
#define PRECISION_ICON    16
#define PRECISION_GUI     32


#define OBP_Precision  0x84000000
#define OBP_FailIfBad  0x84000001


#define MVP_OK          0
#define MVP_NO_MEM      1
#define MVP_NO_VPE      2
#define MVP_NO_DSPINS   3
#define MVP_NO_DISPLAY  4
#define MVP_OFF_BOTTOM  5


#define MCOP_OK      0
#define MCOP_NO_MEM  1
#define MCOP_NOP     2


struct DBufInfo
{
	APTR           dbi_Link1;
	ULONG          dbi_Count1;
	struct Message dbi_SafeMessage;
	APTR           dbi_UserData1;

	APTR           dbi_Link2;
	ULONG          dbi_Count2;
	struct Message dbi_DispMessage;
	APTR           dbi_UserData2;
	ULONG          dbi_MatchLong;
	APTR           dbi_CopPtr1;
	APTR           dbi_CopPtr2;
	APTR           dbi_CopPtr3;
	UWORD          dbi_BeamPos1;
	UWORD          dbi_BeamPos2;
};


#pragma pack()

#endif /* GRAPHICS_VIEW_H */
