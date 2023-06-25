#ifndef HARDWARE_BLIT_H
#define HARDWARE_BLIT_H
/*
**    $VER: blit.h 54.16 (22.08.2022)
**
**    Defines for direct hardware use of the blitter.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef GRAPHICS_MINTERM_H
#include <graphics/minterm.h>
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

#define HSIZEBITS 6
#define VSIZEBITS 16-HSIZEBITS
#define HSIZEMASK 0x3f         /* 2^6 -- 1 */
#define VSIZEMASK 0x3FF        /* 2^10 - 1 */

/* all agnii support horizontal blit of at least 1024 bits (128 bytes) wide */
/* some agnii support horizontal blit of up to 32768 bits (4096 bytes) wide */

#ifndef NO_BIG_BLITS
#define MINBYTESPERROW  128
#define MAXBYTESPERROW 4096
#else
#define MAXBYTESPERROW  128
#endif

#define BC0B_DEST     8
#define BC0B_SRCC     9
#define BC0B_SRCB    10
#define BC0B_SRCA    11
#define BC0F_DEST 0x100
#define BC0F_SRCC 0x200
#define BC0F_SRCB 0x400
#define BC0F_SRCA 0x800

#define BC1F_DESC 2 /* blitter descend direction */

#define DEST 0x100
#define SRCC 0x200
#define SRCB 0x400
#define SRCA 0x800

#define ASHIFTSHIFT 12 /* bits to right align ashift value */
#define BSHIFTSHIFT 12 /* bits to right align bshift value */

/* definations for blitter control register 1 */
#define LINEMODE     0x1
#define FILL_OR      0x8
#define FILL_XOR     0x10
#define FILL_CARRYIN 0x4
#define ONEDOT       0x2  /* one dot per horizontal line */
#define OVFLAG       0x20
#define SIGNFLAG     0x40
#define BLITREVERSE  0x2

#define SUD 0x10
#define SUL 0x8
#define AUL 0x4

#define OCTANT8  24
#define OCTANT7   4
#define OCTANT6  12
#define OCTANT5  28
#define OCTANT4  20
#define OCTANT3   8
#define OCTANT2   0
#define OCTANT1  16

/* stuff for blit qeuer */
struct bltnode
{
    struct bltnode *n;
    int32         (*function)();
    int8            stat;
    int16           blitsize;
    int16           beamsync;
    int32         (*cleanup)();
};

/* defined bits for bltstat */
#define CLEANUP 0x40
#define CLEANME CLEANUP

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* HARDWARE_BLIT_H */
