#ifndef HARDWARE_BLIT_H
#define HARDWARE_BLIT_H

/*
	blitter defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#pragma pack(2)


#define HSIZEBITS  6
#define VSIZEBITS  (16 - HSIZEBITS)
#define HSIZEMASK  0x3f
#define VSIZEMASK  0x3FF


#ifndef NO_BIG_BLITS
# define MINBYTESPERROW  128
# define MAXBYTESPERROW  4096
#else
# define MAXBYTESPERROW  128
#endif


#define ABC     0x80
#define ABNC    0x40
#define ANBC    0x20
#define ANBNC   0x10
#define NABC    0x8
#define NABNC   0x4
#define NANBC   0x2
#define NANBNC  0x1

#define A_OR_B   (ABC|ANBC|NABC|ABNC|ANBNC|NABNC)
#define A_OR_C   (ABC|NABC|ABNC|ANBC|NANBC|ANBNC)
#define A_XOR_C  (NABC|ABNC|NANBC|ANBNC)
#define A_TO_D   (ABC|ANBC|ABNC|ANBNC)

#define BC0B_DEST  8
#define BC0B_SRCC  9
#define BC0B_SRCB  10
#define BC0B_SRCA  11
#define BC0F_DEST  (1<<BC0B_DEST)
#define BC0F_SRCC  (1<<BC0B_SRCC)
#define BC0F_SRCB  (1<<BC0B_SRCB)
#define BC0F_SRCA  (1<<BC0B_SRCA)

#define BC1F_DESC  2

#define DEST  BC0F_DEST
#define SRCC  BC0F_SRCC
#define SRCB  BC0F_SRCB
#define SRCA  BC0F_SRCA

#define ASHIFTSHIFT  12
#define BSHIFTSHIFT  12


#define LINEMODE      0x1
#define FILL_OR       0x8
#define FILL_XOR      0x10
#define FILL_CARRYIN  0x4
#define ONEDOT        0x2
#define OVFLAG        0x20
#define SIGNFLAG      0x40
#define BLITREVERSE   0x2

#define SUD  0x10
#define SUL  0x8
#define AUL  0x4

#define OCTANT8  24
#define OCTANT7  4
#define OCTANT6  12
#define OCTANT5  28
#define OCTANT4  20
#define OCTANT3  8
#define OCTANT2  0
#define OCTANT1  16


struct bltnode
{
	struct bltnode  *n;
	int            (*function)(void);
	char             stat;
	short            blitsize;
	short            beamsync;
	int            (*cleanup)(void);
};


#define CLEANUP  0x40
#define CLEANME  CLEANUP


#pragma pack()

#endif /* HARDWARE_BLIT_H */
