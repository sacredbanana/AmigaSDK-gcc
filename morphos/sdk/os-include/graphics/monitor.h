#ifndef GRAPHICS_MONITOR_H
#define GRAPHICS_MONITOR_H

/*
	graphics monitorspec definitions

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef GRAPHICS_GFXNODES_H
# include <graphics/gfxnodes.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#pragma pack(2)


struct MonitorSpec
{
	struct ExtendedNode      ms_Node;
	UWORD                    ms_Flags;
	LONG                     ratioh;
	LONG                     ratiov;
	UWORD                    total_rows;
	UWORD                    total_colorclocks;
	UWORD                    DeniseMaxDisplayColumn;
	UWORD                    BeamCon0;
	UWORD                    min_row;
	struct SpecialMonitor   *ms_Special;
	UWORD                    ms_OpenCount;
	LONG                   (*ms_transform)(VOID);
	LONG                   (*ms_translate)(VOID);
	LONG                   (*ms_scale)(VOID);
	UWORD                    ms_xoffset;
	UWORD                    ms_yoffset;
	struct Rectangle         ms_LegalView;
	LONG                   (*ms_maxoscan)(VOID);
	LONG                   (*ms_videoscan)(VOID);
	UWORD                    DeniseMinDisplayColumn;
	ULONG                    DisplayCompatible;
	struct List              DisplayInfoDataBase;
	struct SignalSemaphore   DisplayInfoDataBaseSemaphore;
	LONG                   (*ms_MrgCop)(VOID);
	LONG                   (*ms_LoadView)(VOID);
	LONG                   (*ms_KillView)(VOID);
};

#define TO_MONITOR          0
#define FROM_MONITOR        1
#define STANDARD_XOFFSET    9
#define STANDARD_YOFFSET    0

#define MSB_REQUEST_NTSC     0
#define MSB_REQUEST_PAL      1
#define MSB_REQUEST_SPECIAL  2
#define MSB_REQUEST_A2024    3
#define MSB_DOUBLE_SPRITES   4
#define MSF_REQUEST_NTSC     (1<<MSB_REQUEST_NTSC)
#define MSF_REQUEST_PAL      (1<<MSB_REQUEST_PAL)
#define MSF_REQUEST_SPECIAL  (1<<MSB_REQUEST_SPECIAL)
#define MSF_REQUEST_A2024    (1<<MSB_REQUEST_A2024)
#define MSF_DOUBLE_SPRITES   (1<<MSB_DOUBLE_SPRITES)


#define REQUEST_NTSC     (1<<MSB_REQUEST_NTSC)
#define REQUEST_PAL      (1<<MSB_REQUEST_PAL)
#define REQUEST_SPECIAL  (1<<MSB_REQUEST_SPECIAL)
#define REQUEST_A2024    (1<<MSB_REQUEST_A2024)

#define DEFAULT_MONITOR_NAME   "default.monitor"
#define NTSC_MONITOR_NAME      "ntsc.monitor"
#define PAL_MONITOR_NAME       "pal.monitor"
#define VGA_MONITOR_NAME       "vga.monitor"
#define VGA70_MONITOR_NAME     "vga70.monitor"
#define STANDARD_MONITOR_MASK  (REQUEST_NTSC | REQUEST_PAL)

#define STANDARD_NTSC_ROWS     262
#define STANDARD_PAL_ROWS      312
#define STANDARD_COLORCLOCKS   226
#define STANDARD_DENISE_MAX    455
#define STANDARD_DENISE_MIN    93
#define STANDARD_NTSC_BEAMCON  (0x0000)
#define STANDARD_PAL_BEAMCON   (DISPLAYPAL)

#define SPECIAL_BEAMCON  (VARVBLANK | LOLDIS | VARVSYNC | VARHSYNC | VARBEAM | CSBLANK | VSYNCTRUE)

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

#define VGA_COLORCLOCKS  (STANDARD_COLORCLOCKS/2)
#define VGA_TOTAL_ROWS   (STANDARD_NTSC_ROWS*2)
#define VGA_DENISE_MIN   59
#define MIN_VGA_ROW      29
#define VGA_HBSTRT       0x08
#define VGA_HSSTRT       0x0E
#define VGA_HSSTOP       0x1C
#define VGA_HBSTOP       0x1E
#define VGA_VBSTRT       0x0000
#define VGA_VSSTRT       0x0153
#define VGA_VSSTOP       0x0235
#define VGA_VBSTOP       0x0CCD


#define VGA70_COLORCLOCKS  (STANDARD_COLORCLOCKS/2)
#define VGA70_TOTAL_ROWS   449
#define VGA70_DENISE_MIN   59
#define MIN_VGA70_ROW      35
#define VGA70_HBSTRT       0x08
#define VGA70_HSSTRT       0x0E
#define VGA70_HSSTOP       0x1C
#define VGA70_HBSTOP       0x1E
#define VGA70_VBSTRT       0x0000
#define VGA70_VSSTRT       0x02A6
#define VGA70_VSSTOP       0x0388
#define VGA70_VBSTOP       0x0F73

#define VGA70_BEAMCON      (SPECIAL_BEAMCON ^ VSYNCTRUE)

#define BROADCAST_HBSTRT   0x01
#define BROADCAST_HSSTRT   0x06
#define BROADCAST_HSSTOP   0x17
#define BROADCAST_HBSTOP   0x27
#define BROADCAST_VBSTRT   0x0000
#define BROADCAST_VSSTRT   0x02A6
#define BROADCAST_VSSTOP   0x054C
#define BROADCAST_VBSTOP   0x1C40
#define BROADCAST_BEAMCON  (LOLDIS | CSBLANK)

#define RATIO_FIXEDPART  4
#define RATIO_UNITY      (1<<RATIO_FIXEDPART)

struct AnalogSignalInterval
{
	UWORD asi_Start;
	UWORD asi_Stop;
};

struct SpecialMonitor
{
	struct ExtendedNode           spm_Node;
	UWORD                         spm_Flags;
	LONG                        (*do_monitor)(VOID);
	LONG                        (*reserved1)(VOID);
	LONG                        (*reserved2)(VOID);
	LONG                        (*reserved3)(VOID);
	struct AnalogSignalInterval   hblank;
	struct AnalogSignalInterval   vblank;
	struct AnalogSignalInterval   hsync;
	struct AnalogSignalInterval   vsync;
};


#pragma pack()

#endif /* GRAPHICS_MONITOR_H */
