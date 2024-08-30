#ifndef HARDWARE_DMABITS_H
#define HARDWARE_DMABITS_H

/*
	dma bits

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


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
#define DMAB_BLITHOG   10
#define DMAB_BLTNZERO  13
#define DMAB_BLTDONE   14
#define DMAB_SETCLR    15

#define DMAF_AUD0      (1<<DMAB_AUD0)
#define DMAF_AUD1      (1<<DMAB_AUD1)
#define DMAF_AUD2      (1<<DMAB_AUD2)
#define DMAF_AUD3      (1<<DMAB_AUD3)
#define DMAF_DISK      (1<<DMAB_DISK)
#define DMAF_SPRITE    (1<<DMAB_SPRITE)
#define DMAF_BLITTER   (1<<DMAB_BLITTER)
#define DMAF_COPPER    (1<<DMAB_COPPER)
#define DMAF_RASTER    (1<<DMAB_RASTER)
#define DMAF_MASTER    (1<<DMAB_MASTER)
#define DMAF_BLITHOG   (1<<DMAB_BLITHOG)
#define DMAF_BLTNZERO  (1<<DMAB_BLTNZERO)
#define DMAF_BLTDONE   (1<<DMAB_BLTDONE)
#define DMAF_SETCLR    (1<<DMAB_SETCLR)


#define DMAF_AUDIO     (DMAF_AUD0|DMAF_AUD1|DMAF_AUD2|DMAF_AUD3)
#define DMAF_ALL       (DMAF_AUD0|DMAF_AUD1|DMAF_AUD2|DMAF_AUD3|DMAF_DISK|DMAF_SPRITE|DMAF_BLITTER|DMAF_COPPER|DMAF_RASTER)


#endif /* HARDWARE_DMABITS_H */
