#ifndef GRAPHICS_GFXBASE_H
#define GRAPHICS_GFXBASE_H
/*
**    $VER: gfxbase.h 54.16 (22.08.2022)
**
**    graphics base definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef   GRAPHICS_MONITOR_H
#include <graphics/monitor.h>
#endif

/****************************************************************************/

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

struct GfxBase
{
    struct Library LibNode;
    struct View *ActiView;
    struct copinit *copinit;      /* ptr to copper start up list */
    LONG  *cia;                   /* for 8520 resource use */
    LONG  *blitter;               /* for future blitter resource use */
    UWORD *LOFlist;
    UWORD *SHFlist;
    struct bltnode *blthd,*blttl;
    struct bltnode *bsblthd,*bsblttl;
    struct Interrupt vbsrv,timsrv,bltsrv;
    struct List     TextFonts;
    struct TextFont *DefaultFont;
    UWORD  Modes;                 /* copy of current first bplcon0 */
    BYTE   VBlank;
    BYTE   Debug;
    WORD   BeamSync;
    WORD   system_bplcon0;        /* it is ored into each bplcon0 for display */
    UBYTE  SpriteReserved;
    UBYTE  bytereserved;
    UWORD  Flags;
    WORD   BlitLock;
    WORD   BlitNest;

    struct List BlitWaitQ;
    struct Task *BlitOwner;
    struct List TOF_WaitQ;
    UWORD  DisplayFlags;          /* NTSC PAL GENLOC etc*/
                                  /* flags initialized at power on */
    struct SimpleSprite **SimpleSprites;
    UWORD  MaxDisplayRow;         /* hardware stuff, do not use */
    UWORD  MaxDisplayColumn;      /* hardware stuff, do not use */
    UWORD  NormalDisplayRows;
    UWORD  NormalDisplayColumns;
    /* the following are for standard non interlace, 1/2 wb width */
    UWORD  NormalDPMX;            /* Dots per meter on display */
    UWORD  NormalDPMY;            /* Dots per meter on display */
    struct SignalSemaphore *LastChanceMemory;
    UWORD *LCMptr;
    UWORD  MicrosPerLine;         /* 256 time usec/line */
    UWORD  MinDisplayColumn;
    UBYTE  ChipRevBits0;
    UBYTE  MemType;
    UBYTE  crb_reserved[4];
    UWORD  monitor_id;
    ULONG  hedley[8];
    ULONG  hedley_sprites[8];     /* sprite ptrs for intuition mouse */
    ULONG  hedley_sprites1[8];    /* sprite ptrs for intuition mouse */
    WORD   hedley_count;
    UWORD  hedley_flags;
    WORD   hedley_tmp;
    LONG  *hash_table;
    UWORD  current_tot_rows;
    UWORD  current_tot_cclks;
    UBYTE  hedley_hint;
    UBYTE  hedley_hint2;
    ULONG  nreserved[4];
    LONG  *a2024_sync_raster;
    UWORD  control_delta_pal;
    UWORD  control_delta_ntsc;
    struct MonitorSpec *current_monitor;
    struct List MonitorList;
    struct MonitorSpec *default_monitor;
    struct SignalSemaphore *MonitorListSemaphore;
    VOID  *DisplayInfoDataBase;
    UWORD  TopLine;
    struct SignalSemaphore *ActiViewCprSemaphore;
    ULONG *UtilBase;              /* for hook and tag utilities */
    ULONG *ExecBase;              /* to link with rom.lib       */
    UBYTE *bwshifts;
    UWORD *StrtFetchMasks;
    UWORD *StopFetchMasks;
    UWORD *Overrun;
    WORD  *RealStops;
    UWORD  SpriteWidth;           /* current width (in words) of sprites */
    UWORD  SpriteFMode;           /* current sprite fmode bits           */
    BYTE   SoftSprites;           /* bit mask of size change             */
                                  /* knowledgeable sprites               */
    BYTE   arraywidth;
    UWORD  DefaultSpriteWidth;    /* what width intuition wants */
    BYTE   SprMoveDisable;
    UBYTE  WantChips;
    UBYTE  BoardMemType;
    UBYTE  Bugs;
    ULONG *gb_LayersBase;
    ULONG  ColorMask;
    APTR   IVector;
    APTR   IData;
    ULONG  SpecialCounter;        /* special for double buffering */
    APTR   DBList;
    UWORD  MonitorFlags;
    UBYTE  ScanDoubledSprites;
    UBYTE  BP3Bits;
    struct AnalogSignalInterval MonitorVBlank;
    struct MonitorSpec *natural_monitor;
    APTR   ProgData;
    UBYTE  ExtSprites;
    UBYTE  ClassicAmiga;          /* Private - dont use */
    UWORD  GfxFlags;
    ULONG  VBCounter;
    struct SignalSemaphore *HashTableSemaphore;
    ULONG *HWEmul[9];
    /* Added in V46 */
    ULONG  DefaultCharSet;        /* Private - for diskfont.library */
    APTR   RegionPool;            /* Private */
    struct SignalSemaphore *RegionPoolSemaphore; /* Private */
    /* Added in V47 */
    struct Library *DiskfontBase; /* Private - for diskfont.library */
    /* Added in V48 */
    ULONG  Antialiasing;          /* Private - for diskfont.library */
    // There are more fields beyond here and they are all private.
};

#define ChunkyToPlanarPtr HWEmul[0]



/* Values for GfxBase->DisplayFlags */
#define NTSC        1
#define GENLOC      2
#define PAL         4
#define TODA_SAFE   8
#define REALLY_PAL 16 /* what is actual crystal frequency
                         (as opposed to what bootmenu set the agnus to)?
                         (V39) */
#define LPEN_SWAP_FRAMES 32
        /* LightPen software could set this bit if the
         * "lpen-with-interlace" fix put in for V39
         * does not work. This is true of a number of
         * Agnus chips.
         * (V40).
         */

/* bits for dalestuff, which may go away when blitter becomes a resource */
#define QBOWNERn       1 /* blitter owned by blit queuer */
#define BLITMSG_FAULTn 2

#define QBOWNER        (1 << QBOWNERn)
#define BLITMSG_FAULT  (1 << BLITMSG_FAULTn)

#define GBFLAGSB_TIMER 6
#define GBFLAGSF_TIMER (1 << GBFLAGSB_TIMER)

/* bits defs for ChipRevBits */
#define GFXB_BIG_BLITS  0
#define GFXB_HR_AGNUS   0
#define GFXB_HR_DENISE  1
#define GFXB_AA_ALICE   2
#define GFXB_AA_LISA    3
#define GFXB_AA_MLISA   4 /* internal use only. */

#define GFXF_BIG_BLITS  1
#define GFXF_HR_AGNUS   1
#define GFXF_HR_DENISE  2
#define GFXF_AA_ALICE   4
#define GFXF_AA_LISA    8
#define GFXF_AA_MLISA  16 /* internal use only */

/* Pass ONE of these to SetChipRev() */
#define SETCHIPREV_A    GFXF_HR_AGNUS
#define SETCHIPREV_ECS  (GFXF_HR_AGNUS | GFXF_HR_DENISE)
#define SETCHIPREV_AA   (GFXF_AA_ALICE | GFXF_AA_LISA | SETCHIPREV_ECS)
#define SETCHIPREV_BEST 0xffffffff

/* memory type */
#define BUS_16          0
#define NML_CAS         0
#define BUS_32          1
#define DBL_CAS         2
#define BANDWIDTH_1X    (BUS_16 | NML_CAS)
#define BANDWIDTH_2XNML BUS_32
#define BANDWIDTH_2XDBL DBL_CAS
#define BANDWIDTH_4X    (BUS_32 | DBL_CAS)

/* Values for GfxBase->GfxFlags */

#define GFXF_NEW_DATABASE  0x0001  /* New display database */
#define GFXF_HAVECOMPOSITE 0x0002  /* CompositeTagList() is available */

#define GRAPHICSNAME "graphics.library"

/****************************************************************************/

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

#endif /* GRAPHICS_GFXBASE_H */
