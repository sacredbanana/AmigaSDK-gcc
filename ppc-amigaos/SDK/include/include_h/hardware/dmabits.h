#ifndef HARDWARE_DMABITS_H
#define HARDWARE_DMABITS_H
/*
**    $VER: dmabits.h 54.16 (22.08.2022)
**
**    include file for defining dma control stuff
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

/* write definitions for dmaconw */
#define DMAF_SETCLR   0x8000
#define DMAF_AUDIO    0x000F   /* 4 bit mask */
#define DMAF_AUD0     0x0001
#define DMAF_AUD1     0x0002
#define DMAF_AUD2     0x0004
#define DMAF_AUD3     0x0008
#define DMAF_DISK     0x0010
#define DMAF_SPRITE   0x0020
#define DMAF_BLITTER  0x0040
#define DMAF_COPPER   0x0080
#define DMAF_RASTER   0x0100
#define DMAF_MASTER   0x0200
#define DMAF_BLITHOG  0x0400
#define DMAF_ALL      0x01FF   /* all dma channels */

/* read definitions for dmaconr */
/* bits 0-8 correspnd to dmaconw definitions */
#define DMAF_BLTDONE  0x4000
#define DMAF_BLTNZERO 0x2000

#define DMAB_SETCLR   15
#define DMAB_AUD0      0
#define DMAB_AUD1      1
#define DMAB_AUD2      2
#define DMAB_AUD3      3
#define DMAB_DISK      4
#define DMAB_SPRITE    5
#define DMAB_BLITTER   6
#define DMAB_COPPER    7
#define DMAB_RASTER    8
#define DMAB_MASTER    9
#define DMAB_BLITHOG  10
#define DMAB_BLTDONE  14
#define DMAB_BLTNZERO 13

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

#endif /* HARDWARE_DMABITS_H */
