#ifndef HARDWARE_CIA_H
#define HARDWARE_CIA_H

/*
	cia registers and bits

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct CIA
{
	VOLATILE UBYTE ciapra;
	VOLATILE UBYTE            pad0[0xff];
	VOLATILE UBYTE ciaprb;
	VOLATILE UBYTE            pad1[0xff];
	VOLATILE UBYTE ciaddra;
	VOLATILE UBYTE            pad2[0xff];
	VOLATILE UBYTE ciaddrb;
	VOLATILE UBYTE            pad3[0xff];
	VOLATILE UBYTE ciatalo;
	VOLATILE UBYTE            pad4[0xff];
	VOLATILE UBYTE ciatahi;
	VOLATILE UBYTE            pad5[0xff];
	VOLATILE UBYTE ciatblo;
	VOLATILE UBYTE            pad6[0xff];
	VOLATILE UBYTE ciatbhi;
	VOLATILE UBYTE            pad7[0xff];
	VOLATILE UBYTE ciatodlow;
	VOLATILE UBYTE            pad8[0xff];
	VOLATILE UBYTE ciatodmid;
	VOLATILE UBYTE            pad9[0xff];
	VOLATILE UBYTE ciatodhi;
	VOLATILE UBYTE            pad10[0xff];
	VOLATILE UBYTE unusedreg;
	VOLATILE UBYTE            pad11[0xff];
	VOLATILE UBYTE ciasdr;
	VOLATILE UBYTE            pad12[0xff];
	VOLATILE UBYTE ciaicr;
	VOLATILE UBYTE            pad13[0xff];
	VOLATILE UBYTE ciacra;
	VOLATILE UBYTE            pad14[0xff];
	VOLATILE UBYTE ciacrb;
};


#define CIAICRB_TA      0
#define CIAICRB_TB      1
#define CIAICRB_ALRM    2
#define CIAICRB_SP      3
#define CIAICRB_FLG     4
#define CIAICRB_IR      7
#define CIAICRB_SETCLR  7

#define CIAICRF_TA      (1<<CIAICRB_TA)
#define CIAICRF_TB      (1<<CIAICRB_TB)
#define CIAICRF_ALRM    (1<<CIAICRB_ALRM)
#define CIAICRF_SP      (1<<CIAICRB_SP)
#define CIAICRF_FLG     (1<<CIAICRB_FLG)
#define CIAICRF_IR      (1<<CIAICRB_IR)
#define CIAICRF_SETCLR  (1<<CIAICRB_SETCLR)


#define CIACRAB_START    0
#define CIACRAB_PBON     1
#define CIACRAB_OUTMODE  2
#define CIACRAB_RUNMODE  3
#define CIACRAB_LOAD     4
#define CIACRAB_INMODE   5
#define CIACRAB_SPMODE   6
#define CIACRAB_TODIN    7

#define CIACRAF_START    (1<<CIACRAB_START)
#define CIACRAF_PBON     (1<<CIACRAB_PBON)
#define CIACRAF_OUTMODE  (1<<CIACRAB_OUTMODE)
#define CIACRAF_RUNMODE  (1<<CIACRAB_RUNMODE)
#define CIACRAF_LOAD     (1<<CIACRAB_LOAD)
#define CIACRAF_INMODE   (1<<CIACRAB_INMODE)
#define CIACRAF_SPMODE   (1<<CIACRAB_SPMODE)
#define CIACRAF_TODIN    (1<<CIACRAB_TODIN)


#define CIACRBB_START    0
#define CIACRBB_PBON     1
#define CIACRBB_OUTMODE  2
#define CIACRBB_RUNMODE  3
#define CIACRBB_LOAD     4
#define CIACRBB_INMODE0  5
#define CIACRBB_INMODE1  6
#define CIACRBB_ALARM    7

#define CIACRBF_START    (1<<CIACRBB_START)
#define CIACRBF_PBON     (1<<CIACRBB_PBON)
#define CIACRBF_OUTMODE  (1<<CIACRBB_OUTMODE)
#define CIACRBF_RUNMODE  (1<<CIACRBB_RUNMODE)
#define CIACRBF_LOAD     (1<<CIACRBB_LOAD)
#define CIACRBF_INMODE0  (1<<CIACRBB_INMODE0)
#define CIACRBF_INMODE1  (1<<CIACRBB_INMODE1)
#define CIACRBF_ALARM    (1<<CIACRBB_ALARM)


#define CIACRBF_IN_PHI2    0
#define CIACRBF_IN_CNT     (CIACRBF_INMODE0)
#define CIACRBF_IN_TA      (CIACRBF_INMODE1)
#define CIACRBF_IN_CNT_TA  (CIACRBF_INMODE0|CIACRBF_INMODE1)


#define CIAB_GAMEPORT1  (7)
#define CIAB_GAMEPORT0  (6)
#define CIAB_DSKRDY     (5)
#define CIAB_DSKTRACK0  (4)
#define CIAB_DSKPROT    (3)
#define CIAB_DSKCHANGE  (2)
#define CIAB_LED        (1)
#define CIAB_OVERLAY    (0)

#define CIAF_GAMEPORT1  (1<<CIAB_GAMEPORT1)
#define CIAF_GAMEPORT0  (1<<CIAB_GAMEPORT0)
#define CIAF_DSKRDY     (1<<CIAB_DSKRDY)
#define CIAF_DSKTRACK0  (1<<CIAB_DSKTRACK0)
#define CIAF_DSKPROT    (1<<CIAB_DSKPROT)
#define CIAF_DSKCHANGE  (1<<CIAB_DSKCHANGE)
#define CIAF_LED        (1<<CIAB_LED)
#define CIAF_OVERLAY    (1<<CIAB_OVERLAY)


#define CIAB_COMDTR     (7)
#define CIAB_COMRTS     (6)
#define CIAB_COMCD      (5)
#define CIAB_COMCTS     (4)
#define CIAB_COMDSR     (3)
#define CIAB_PRTRSEL    (2)
#define CIAB_PRTRPOUT   (1)
#define CIAB_PRTRBUSY   (0)

#define CIAF_COMDTR     (1<<CIAB_COMDTR)
#define CIAF_COMRTS     (1<<CIAB_COMRTS)
#define CIAF_COMCD      (1<<CIAB_COMCD)
#define CIAF_COMCTS     (1<<CIAB_COMCTS)
#define CIAF_COMDSR     (1<<CIAB_COMDSR)
#define CIAF_PRTRSEL    (1<<CIAB_PRTRSEL)
#define CIAF_PRTRPOUT   (1<<CIAB_PRTRPOUT)
#define CIAF_PRTRBUSY   (1<<CIAB_PRTRBUSY)


#define CIAB_DSKMOTOR   (7)
#define CIAB_DSKSEL3    (6)
#define CIAB_DSKSEL2    (5)
#define CIAB_DSKSEL1    (4)
#define CIAB_DSKSEL0    (3)
#define CIAB_DSKSIDE    (2)
#define CIAB_DSKDIREC   (1)
#define CIAB_DSKSTEP    (0)

#define CIAF_DSKMOTOR   (1<<CIAB_DSKMOTOR)
#define CIAF_DSKSEL3    (1<<CIAB_DSKSEL3)
#define CIAF_DSKSEL2    (1<<CIAB_DSKSEL2)
#define CIAF_DSKSEL1    (1<<CIAB_DSKSEL1)
#define CIAF_DSKSEL0    (1<<CIAB_DSKSEL0)
#define CIAF_DSKSIDE    (1<<CIAB_DSKSIDE)
#define CIAF_DSKDIREC   (1<<CIAB_DSKDIREC)
#define CIAF_DSKSTEP    (1<<CIAB_DSKSTEP)


#pragma pack()

#endif /* HARDWARE_CIA_H */
