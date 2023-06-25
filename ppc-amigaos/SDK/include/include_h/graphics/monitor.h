#ifndef GRAPHICS_MONITOR_H
#define GRAPHICS_MONITOR_H
/*
**    $VER: monitor.h 54.16 (22.08.2022)
**
**    graphics monitor definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010, 2014 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#ifndef   GRAPHICS_GFXNODES_H
#include <graphics/gfxnodes.h>
#endif

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
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

/* define structure names in this scope */
struct View;
struct GfxBase;
struct GraphicsIFace;

struct MonitorSpec
{
    struct ExtendedNode    ms_Node;
    UWORD                  ms_Flags;
    LONG                   ratioh;
    LONG                   ratiov;
    UWORD                  total_rows;
    UWORD                  total_colorclocks;
    UWORD                  DeniseMaxDisplayColumn;
    UWORD                  BeamCon0;
    UWORD                  min_row;
    struct SpecialMonitor *ms_Special;
    UWORD                  ms_OpenCount;
    VOID                 (*ms_transform)(struct MonitorSpec *mspc,
                                         Point              *src,
                                         UWORD               type,
                                         Point              *dst);
    VOID                 (*ms_translate)(struct MonitorSpec *mspc,
                                         Point              *src,
                                         UWORD               type,
                                         Point              *dst);
    VOID                 (*ms_scale)    (struct MonitorSpec *mspc,
                                         Point              *src,
                                         UWORD               type,
                                         Point              *dst);
    UWORD                  ms_xoffset;
    UWORD                  ms_yoffset;
    struct Rectangle       ms_LegalView;
    LONG                 (*ms_maxoscan) /* maximum legal overscan */
                                       (struct GraphicsIFace *,
                                        struct MonitorSpec *mspc,
                                        struct Rectangle   *rect,
                                        UWORD               mode);
    LONG                 (*ms_videoscan) /* video display overscan */
                                        (struct GraphicsIFace *,
                                         struct MonitorSpec *mspc,
                                         struct Rectangle   *rect,
                                         UWORD               mode);
    UWORD                  DeniseMinDisplayColumn;
    ULONG                  DisplayCompatible;
    struct List            DisplayInfoDataBase;
    struct SignalSemaphore DisplayInfoDataBaseSemaphore;
    ULONG                (*ms_MrgCop)  (struct GraphicsIFace *, struct View *);
    VOID                 (*ms_LoadView)(struct GraphicsIFace *, struct View *);
    VOID                 (*ms_KillView)(struct GraphicsIFace *,
                                        struct MonitorSpec *);
};

#define TO_MONITOR          0
#define FROM_MONITOR        1
#define STANDARD_XOFFSET    9
#define STANDARD_YOFFSET    0

#define MSB_REQUEST_NTSC    0
#define MSB_REQUEST_PAL     1
#define MSB_REQUEST_SPECIAL 2
#define MSB_REQUEST_A2024   3
#define MSB_DOUBLE_SPRITES  4
#define MSF_REQUEST_NTSC    (1 << MSB_REQUEST_NTSC)
#define MSF_REQUEST_PAL     (1 << MSB_REQUEST_PAL)
#define MSF_REQUEST_SPECIAL (1 << MSB_REQUEST_SPECIAL)
#define MSF_REQUEST_A2024   (1 << MSB_REQUEST_A2024)
#define MSF_DOUBLE_SPRITES  (1 << MSB_DOUBLE_SPRITES)


/* obsolete, v37 compatible definitions follow */
#define REQUEST_NTSC        (1 << MSB_REQUEST_NTSC)
#define REQUEST_PAL         (1 << MSB_REQUEST_PAL)
#define REQUEST_SPECIAL     (1 << MSB_REQUEST_SPECIAL)
#define REQUEST_A2024       (1 << MSB_REQUEST_A2024)

#define DEFAULT_MONITOR_NAME  "default.monitor"
#define NTSC_MONITOR_NAME     "ntsc.monitor"
#define PAL_MONITOR_NAME      "pal.monitor"
#define STANDARD_MONITOR_MASK ( REQUEST_NTSC | REQUEST_PAL )

#define STANDARD_NTSC_ROWS    262
#define STANDARD_PAL_ROWS     312
#define STANDARD_COLORCLOCKS  226
#define STANDARD_DENISE_MAX   455
#define STANDARD_DENISE_MIN   93
#define STANDARD_NTSC_BEAMCON ( 0x0000 )
#define STANDARD_PAL_BEAMCON  ( 0x0020 )

#define SPECIAL_BEAMCON \
    ( VARVBLANK | LOLDIS | VARVSYNC | VARHSYNC | VARBEAM | CSBLANK | VSYNCTRUE)

#define MIN_NTSC_ROW     21
#define MIN_PAL_ROW      29
#define STANDARD_VIEW_X  0x81
#define STANDARD_VIEW_Y  0x2C
#define STANDARD_HBSTRT  0x06
#define STANDARD_HSSTRT  0x0B
#define STANDARD_HSSTOP  0x1C
#define STANDARD_HBSTOP  0x2C
#define STANDARD_VBSTRT  0x0122
#define STANDARD_VSSTRT  0x02A6
#define STANDARD_VSSTOP  0x03AA
#define STANDARD_VBSTOP  0x1066

#define VGA_COLORCLOCKS (STANDARD_COLORCLOCKS/2)
#define VGA_TOTAL_ROWS  (STANDARD_NTSC_ROWS*2)
#define VGA_DENISE_MIN  59
#define MIN_VGA_ROW     29
#define VGA_HBSTRT      0x08
#define VGA_HSSTRT      0x0E
#define VGA_HSSTOP      0x1C
#define VGA_HBSTOP      0x1E
#define VGA_VBSTRT      0x0000
#define VGA_VSSTRT      0x0153
#define VGA_VSSTOP      0x0235
#define VGA_VBSTOP      0x0CCD

#define VGA_MONITOR_NAME "vga.monitor"

/* NOTE: VGA70 definitions are obsolete - a VGA70 monitor has never been
 * implemented.
 */
#define VGA70_COLORCLOCKS (STANDARD_COLORCLOCKS/2)
#define VGA70_TOTAL_ROWS  449
#define VGA70_DENISE_MIN  59
#define MIN_VGA70_ROW     35
#define VGA70_HBSTRT      0x08
#define VGA70_HSSTRT      0x0E
#define VGA70_HSSTOP      0x1C
#define VGA70_HBSTOP      0x1E
#define VGA70_VBSTRT      0x0000
#define VGA70_VSSTRT      0x02A6
#define VGA70_VSSTOP      0x0388
#define VGA70_VBSTOP      0x0F73

#define VGA70_BEAMCON     (SPECIAL_BEAMCON ^ VSYNCTRUE)
#define VGA70_MONITOR_NAME "vga70.monitor"

#define BROADCAST_HBSTRT   0x01
#define BROADCAST_HSSTRT   0x06
#define BROADCAST_HSSTOP   0x17
#define BROADCAST_HBSTOP   0x27
#define BROADCAST_VBSTRT   0x0000
#define BROADCAST_VSSTRT   0x02A6
#define BROADCAST_VSSTOP   0x054C
#define BROADCAST_VBSTOP   0x1C40
#define BROADCAST_BEAMCON  ( LOLDIS | CSBLANK )
#define RATIO_FIXEDPART    4
#define RATIO_UNITY        (1 << RATIO_FIXEDPART)

struct AnalogSignalInterval
{
    UWORD asi_Start;
    UWORD asi_Stop;
};

struct SpecialMonitor
{
    struct ExtendedNode         spm_Node;
    UWORD                       spm_Flags;
    VOID                      (*do_monitor)(struct GraphicsIFace *,
                                            struct MonitorSpec *);
    LONG                      (*reserved1)();
    LONG                      (*reserved2)();
    LONG                      (*reserved3)();
    struct AnalogSignalInterval hblank;
    struct AnalogSignalInterval vblank;
    struct AnalogSignalInterval hsync;
    struct AnalogSignalInterval vsync;
};

/****************************************************************************/

#define GMD_TagBase        (TAG_USER)

#define GMD_VendorID       (GMD_TagBase+1)
#define GMD_Product        (GMD_TagBase+2)
#define GMD_ProductID      (GMD_TagBase+3)
#define GMD_HSyncMin       (GMD_TagBase+4)
#define GMD_HSyncMax       (GMD_TagBase+5)
#define GMD_VSyncMin       (GMD_TagBase+6)
#define GMD_VSyncMax       (GMD_TagBase+7)
#define GMD_DotClockMin    (GMD_TagBase+8)
#define GMD_DotClockMax    (GMD_TagBase+9)
#define GMD_DisplayWidth   (GMD_TagBase+10)
#define GMD_DisplayHeight  (GMD_TagBase+11)
#define GMD_InputType      (GMD_TagBase+12)
#define GMD_EDIDVersion    (GMD_TagBase+13)
#define GMD_EDIDRevision   (GMD_TagBase+14)
#define GMD_BasicAudio     (GMD_TagBase+15)

enum enMonitorInputType
{
    INPUTTYPE_VGA,
    INPUTTYPE_DVI
};

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

#endif /* GRAPHICS_MONITOR_H */
