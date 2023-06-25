#ifndef GRAPHICS_DISPLAYINFO_H
#define GRAPHICS_DISPLAYINFO_H
/*
**    $VER: displayinfo.h 54.16 (22.08.2022)
**
**    include define file for displayinfo database
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010-2016 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#ifndef   GRAPHICS_MONITOR_H
#include <graphics/monitor.h>
#endif

#ifndef   GRAPHICS_MODEID_H
#include <graphics/modeid.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/* the "public" handle to a DisplayInfoRecord */

typedef APTR DisplayInfoHandle;

/* datachunk type identifiers */

#define DTAG_DISP 0x80000000
#define DTAG_DIMS 0x80001000
#define DTAG_MNTR 0x80002000
#define DTAG_NAME 0x80003000
#define DTAG_VEC  0x80004000 /* internal use only */

struct QueryHeader
{
    uint32 StructID;  /* datachunk type identifier */
    uint32 DisplayID; /* copy of display record key    */
    uint32 SkipID;    /* TAG_SKIP -- see tagitems.h */
    uint32 Length;    /* length of local data in double-longwords */
};

// WARNING
//
// struct DisplayInfo must always be a multiple of 8 bytes or the
// display database will fail.

struct DisplayInfo
{
    struct QueryHeader Header;
    uint16 NotAvailable;    // if NULL available, else see defines
    uint32 PropertyFlags;   // Properties of this mode see defines
    Point Resolution;       // ticks-per-pixel X/Y
    uint16 PixelSpeed;      // aproximation in nanoseconds
    uint16 NumStdSprites;   // number of standard amiga sprites
    uint16 PaletteRange;    // OBSOLETE - use Red/Green/Blue bits instead
    Point SpriteResolution; // std sprite ticks-per-pixel X/Y
    uint8 pad[4];           // used internally
    uint8 RedBits;          // number of Red bits display supports (V39)
    uint8 GreenBits;        // number of Green bits display supports (V39)
    uint8 BlueBits;         // number of Blue bits display supports (V39)
    uint8 pad2[4];          // find some use for this.
    uint8 RTGBoardNum;      // RTG board number this mode belongs to (V53)
    uint32 PixelFormat;     // Pixel format (enPixelFormat) (V54)
    uint8 pad3[4];          // find some use for this, too. (V54)
    uint32 reserved[2];     // terminator
};

/* availability */

#define DI_AVAIL_NOCHIPS        0x0001 // No custom chips
#define DI_AVAIL_NOMONITOR      0x0002 // No suitable monitor
#define DI_AVAIL_NOTWITHGENLOCK 0x0004 // Not allowed with genlock
#define DI_AVAIL_INVALID        0x1000 // Mode is invalid (V54)
#define DI_AVAIL_MONITOOL       0x2000 // Reserved; do not use (V54)

/* mode properties */

#define DIPF_IS_LACE              0x00000001
#define DIPF_IS_DUALPF            0x00000002
#define DIPF_IS_PF2PRI            0x00000004
#define DIPF_IS_HAM               0x00000008

#define DIPF_IS_ECS               0x00000010 /* ECS modes (SHIRES, VGA, and
                                              * PRODUCTIVITY) do not support
                                              * attached sprites.
                                              */
#define DIPF_IS_AA                0x00010000 /* AA modes - may only be
                                              * available if machine has
                                              * correct memory type to support
                                              * required bandwidth - check
                                              * availability. (V39)
                                              */
#define DIPF_IS_PAL               0x00000020
#define DIPF_IS_SPRITES           0x00000040
#define DIPF_IS_GENLOCK           0x00000080

#define DIPF_IS_WB                0x00000100
#define DIPF_IS_DRAGGABLE         0x00000200
#define DIPF_IS_PANELLED          0x00000400
#define DIPF_IS_BEAMSYNC          0x00000800

#define DIPF_IS_EXTRAHALFBRITE    0x00001000

#define DIPF_IS_SPRITES_ATT       0x00002000 /* supports attached sprites
                                              * (V39) */
#define DIPF_IS_SPRITES_CHNG_RES  0x00004000 /* supports variable sprite
                                              * resolution (V39) */
#define DIPF_IS_SPRITES_BORDER    0x00008000 /* sprite can be displayed
                                              * in the border (V39) */
#define DIPF_IS_SCANDBL           0x00020000 /* scan doubled (V39) */
#define DIPF_IS_SPRITES_CHNG_BASE 0x00040000 /* can change the sprite
                                              * base colour (V39) */
#define DIPF_IS_SPRITES_CHNG_PRI  0x00080000 /* can change the sprite
                                              * priority with respect to
                                              * the playfield(s). (V39)
                                              */
#define DIPF_IS_DBUFFER           0x00100000 /* can support double buffering
                                              * (V39) */
#define DIPF_IS_PROGBEAM          0x00200000 /* is a programmed beam-sync
                                              * mode (V39) */

#define DIPF_IS_HWCOMPOSITE       0x00400000 /* can support hardware
                                              * compositing (V53) */
#define DIPF_IS_PREFERREDMODE     0x00800000 /* preferred/native resolution of
                                              * monitor (V53) */
#define DIPF_IS_RTG               0x80000000 /* mode is RTG and does not
                                              * use the native chip set */

// Old synonym not to be used in any new code.
#define DIPF_IS_FOREIGN DIPF_IS_RTG


struct DimensionInfo
{
    struct QueryHeader Header;
    uint16             MaxDepth;        // log2(max number of colors)
    uint16             MinRasterWidth;  // minimum width in pixels
    uint16             MinRasterHeight; // minimum height in pixels
    uint16             MaxRasterWidth;  // maximum width in pixels
    uint16             MaxRasterHeight; // maximum height in pixels
    struct Rectangle   Nominal;         // "standard" dimensions
    struct Rectangle   MaxOScan;        // fixed, hardware dependent
    struct Rectangle   VideoOScan;      // fixed, hardware dependent
    struct Rectangle   TxtOScan;        // editable via preferences
    struct Rectangle   StdOScan;        // editable via preferences
    uint8              pad[14];
    uint32             reserved[2];     // terminator
};

struct MonitorInfo
{
    struct QueryHeader  Header;
    struct MonitorSpec *Mspc;                // pointer to monitor spec.
    Point               ViewPosition;        // editable via preferences
    Point               ViewResolution;      // standard monitor
                                             // ticks-per-pixel
    struct Rectangle    ViewPositionRange;   // fixed, hardware dependent
    uint16              TotalRows;           // display height in scanlines
    uint16              TotalColorClocks;    // scanline width in 280 ns units
    uint16              MinRow;              // absolute min. active scanline
    int16               Compatibility;       // how this coexists with others
    uint8               pad[32];
    Point               MouseTicks;
    Point               DefaultViewPosition; // original, never changes
    uint32              PreferredModeID;     // for Preferences
    uint32              reserved[2];         // terminator
};

/* monitor compatibility */

#define MCOMPAT_MIXED   0 /* can share display with other MCOMPAT_MIXED */
#define MCOMPAT_SELF    1 /* can share only within same monitor */
#define MCOMPAT_NOBODY -1 /* only one viewport at a time */

#define DISPLAYNAMELEN 32

struct NameInfo
{
    struct QueryHeader Header;
    TEXT               Name[DISPLAYNAMELEN];
    uint32             reserved[2];          /* terminator */
};

/******************************************************************************/

/* The following VecInfo structure is PRIVATE, for our use only
 * Touch these, and burn! (V39)
 */

struct VecInfo
{
    struct QueryHeader Header;
    APTR               Vec;
    APTR               Data;
    uint16             Type;
    uint16             pad[3];
    uint32             reserved[2];
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

#endif /* GRAPHICS_DISPLAYINFO_H */
