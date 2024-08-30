#ifndef SANA2_SANA2SPECIALSTATS_H
#define SANA2_SANA2SPECIALSTATS_H

/*
	SANA-II v3 special statistic definitions

	Copyright © 2002-2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef SANA2_SANA2DEVICE_H
# include <devices/sana2.h>
#endif


#define S2SS_ETHERNET_BADMULTICAST    ((((S2WireType_Ethernet) & 0xffff) << 16) | 0)
#define S2SS_ETHERNET_RETRIES         ((((S2WireType_Ethernet) & 0xffff) << 16) | 1)
#define S2SS_ETHERNET_FIFO_UNDERRUNS  ((((S2WireType_Ethernet) & 0xffff) << 16) | 2)


#endif /* SANA2_SANA2SPECIALSTATS_H */
