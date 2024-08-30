#ifndef HARDWARE_ADKBITS_H
#define HARDWARE_ADKBITS_H

/*
	adkcon bit defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define ADKB_SETCLR    15
#define ADKB_PRECOMP1  14
#define ADKB_PRECOMP0  13
#define ADKB_MFMPREC   12
#define ADKB_UARTBRK   11
#define ADKB_WORDSYNC  10
#define ADKB_MSBSYNC   9
#define ADKB_FAST      8
#define ADKB_USE3PN    7
#define ADKB_USE2P3    6
#define ADKB_USE1P2    5
#define ADKB_USE0P1    4
#define ADKB_USE3VN    3
#define ADKB_USE2V3    2
#define ADKB_USE1V2    1
#define ADKB_USE0V1    0

#define ADKF_SETCLR    (1<<ADKB_SETCLR)
#define ADKF_PRECOMP1  (1<<ADKB_PRECOMP1)
#define ADKF_PRECOMP0  (1<<ADKB_PRECOMP0)
#define ADKF_MFMPREC   (1<<ADKB_MFMPREC)
#define ADKF_UARTBRK   (1<<ADKB_UARTBRK)
#define ADKF_WORDSYNC  (1<<ADKB_WORDSYNC)
#define ADKF_MSBSYNC   (1<<ADKB_MSBSYNC)
#define ADKF_FAST      (1<<ADKB_FAST)
#define ADKF_USE3PN    (1<<ADKB_USE3PN)
#define ADKF_USE2P3    (1<<ADKB_USE2P3)
#define ADKF_USE1P2    (1<<ADKB_USE1P2)
#define ADKF_USE0P1    (1<<ADKB_USE0P1)
#define ADKF_USE3VN    (1<<ADKB_USE3VN)
#define ADKF_USE2V3    (1<<ADKB_USE2V3)
#define ADKF_USE1V2    (1<<ADKB_USE1V2)
#define ADKF_USE0V1    (1<<ADKB_USE0V1)


#define ADKF_PRE000NS  0
#define ADKF_PRE140NS  (ADKF_PRECOMP0)
#define ADKF_PRE280NS  (ADKF_PRECOMP1)
#define ADKF_PRE560NS  (ADKF_PRECOMP0 | ADKF_PRECOMP1)


#endif /* HARDWARE_ADKBITS_H */
