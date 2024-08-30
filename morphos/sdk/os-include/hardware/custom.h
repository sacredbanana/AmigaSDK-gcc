#ifndef HARDWARE_CUSTOM_H
#define HARDWARE_CUSTOM_H

/*
	custom-chip registers and bits

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct Custom
{
	VOLATILE UWORD bltddat;
	VOLATILE UWORD dmaconr;
	VOLATILE UWORD vposr;
	VOLATILE UWORD vhposr;
	VOLATILE UWORD dskdatr;
	VOLATILE UWORD joy0dat;
	VOLATILE UWORD joy1dat;
	VOLATILE UWORD clxdat;
	VOLATILE UWORD adkconr;
	VOLATILE UWORD pot0dat;
	VOLATILE UWORD pot1dat;
	VOLATILE UWORD potinp;
	VOLATILE UWORD serdatr;
	VOLATILE UWORD dskbytr;
	VOLATILE UWORD intenar;
	VOLATILE UWORD intreqr;
	VOLATILE APTR  dskpt;
	VOLATILE UWORD dsklen;
	VOLATILE UWORD dskdat;
	VOLATILE UWORD refptr;
	VOLATILE UWORD vposw;
	VOLATILE UWORD vhposw;
	VOLATILE UWORD copcon;
	VOLATILE UWORD serdat;
	VOLATILE UWORD serper;
	VOLATILE UWORD potgo;
	VOLATILE UWORD joytest;
	VOLATILE UWORD strequ;
	VOLATILE UWORD strvbl;
	VOLATILE UWORD strhor;
	VOLATILE UWORD strlong;
	VOLATILE UWORD bltcon0;
	VOLATILE UWORD bltcon1;
	VOLATILE UWORD bltafwm;
	VOLATILE UWORD bltalwm;
	VOLATILE APTR  bltcpt;
	VOLATILE APTR  bltbpt;
	VOLATILE APTR  bltapt;
	VOLATILE APTR  bltdpt;
	VOLATILE UWORD bltsize;
	VOLATILE UBYTE pad2d;
	VOLATILE UBYTE bltcon0l;
	VOLATILE UWORD bltsizv;
	VOLATILE UWORD bltsizh;
	VOLATILE UWORD bltcmod;
	VOLATILE UWORD bltbmod;
	VOLATILE UWORD bltamod;
	VOLATILE UWORD bltdmod;
	VOLATILE UWORD pad34[4];
	VOLATILE UWORD bltcdat;
	VOLATILE UWORD bltbdat;
	VOLATILE UWORD bltadat;
	VOLATILE UWORD pad3b[3];
	VOLATILE UWORD deniseid;
	VOLATILE UWORD dsksync;
	VOLATILE ULONG cop1lc;
	VOLATILE ULONG cop2lc;
	VOLATILE UWORD copjmp1;
	VOLATILE UWORD copjmp2;
	VOLATILE UWORD copins;
	VOLATILE UWORD diwstrt;
	VOLATILE UWORD diwstop;
	VOLATILE UWORD ddfstrt;
	VOLATILE UWORD ddfstop;
	VOLATILE UWORD dmacon;
	VOLATILE UWORD clxcon;
	VOLATILE UWORD intena;
	VOLATILE UWORD intreq;
	VOLATILE UWORD adkcon;

	struct AudChannel
	{
		VOLATILE UWORD *ac_ptr;
		VOLATILE UWORD  ac_len;
		VOLATILE UWORD  ac_per;
		VOLATILE UWORD  ac_vol;
		VOLATILE UWORD  ac_dat;
		VOLATILE UWORD  ac_pad[2];
	}     aud[4];

	VOLATILE APTR  bplpt[8];
	VOLATILE UWORD bplcon0;
	VOLATILE UWORD bplcon1;
	VOLATILE UWORD bplcon2;
	VOLATILE UWORD bplcon3;
	VOLATILE UWORD bpl1mod;
	VOLATILE UWORD bpl2mod;
	VOLATILE UWORD bplcon4;
	VOLATILE UWORD clxcon2;
	VOLATILE UWORD bpldat[8];
	VOLATILE APTR  sprpt[8];

	struct SpriteDef
	{
		VOLATILE UWORD pos;
		VOLATILE UWORD ctl;
		VOLATILE UWORD dataa;
		VOLATILE UWORD datab;
	}     spr[8];

	VOLATILE UWORD color[32];
	VOLATILE UWORD htotal;
	VOLATILE UWORD hsstop;
	VOLATILE UWORD hbstrt;
	VOLATILE UWORD hbstop;
	VOLATILE UWORD vtotal;
	VOLATILE UWORD vsstop;
	VOLATILE UWORD vbstrt;
	VOLATILE UWORD vbstop;
	VOLATILE UWORD sprhstrt;
	VOLATILE UWORD sprhstop;
	VOLATILE UWORD bplhstrt;
	VOLATILE UWORD bplhstop;
	VOLATILE UWORD hhposw;
	VOLATILE UWORD hhposr;
	VOLATILE UWORD beamcon0;
	VOLATILE UWORD hsstrt;
	VOLATILE UWORD vsstrt;
	VOLATILE UWORD hcenter;
	VOLATILE UWORD diwhigh;
	VOLATILE UWORD padf3[11];
	VOLATILE UWORD fmode;
};


#ifdef ECS_SPECIFIC

#define VARVBLANK    0x1000
#define LOLDIS       0x0800
#define CSCBLANKEN   0x0400
#define VARVSYNC     0x0200
#define VARHSYNC     0x0100
#define VARBEAM      0x0080
#define DISPLAYDUAL  0x0040
#define DISPLAYPAL   0x0020
#define VARCSYNC     0x0010
#define CSBLANK      0x0008
#define CSYNCTRUE    0x0004
#define VSYNCTRUE    0x0002
#define HSYNCTRUE    0x0001

#define USE_BPLCON3  1

#define BPLCON2_ZDCTEN     (1<<10)
#define BPLCON2_ZDBPEN     (1<<11)
#define BPLCON2_ZDBPSEL0   (1<<12)
#define BPLCON2_ZDBPSEL1   (1<<13)
#define BPLCON2_ZDBPSEL2   (1<<14)

#define BPLCON3_EXTBLNKEN  (1<<0)
#define BPLCON3_EXTBLKZD   (1<<1)
#define BPLCON3_ZDCLKEN    (1<<2)
#define BPLCON3_BRDNTRAN   (1<<4)
#define BPLCON3_BRDNBLNK   (1<<5)

#endif /* ECS_SPECIFIC */


#pragma pack()

#endif /* HARDWARE_CUSTOM_H */
