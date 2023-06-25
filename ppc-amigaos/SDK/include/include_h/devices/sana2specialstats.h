#ifndef DEVICES_SANA2SPECIALSTATS_H
#define DEVICES_SANA2SPECIALSTATS_H 1
/*
**    $VER: sana2specialstats.h 54.16 (22.08.2022)
**
**    Defined IDs for SANA-II special statistics.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   DEVICES_SANA2_H
#include <devices/sana2.h>
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

/*
** The SANA-II special statistic identifier is an unsigned 32 number.
** The upper 16 bits identify the type of network wire type to which
** the statistic applies and the lower 16 bits identify the particular
** statistic.
**
** If you desire to add a new statistic identifier, contacts CATS.
*/



/*
** defined ethernet special statistics
*/

#define S2SS_ETHERNET_BADMULTICAST \
                      ((((S2WireType_Ethernet)&0xffff)<<16)|0x0000)
/*
** This count will record the number of times a received packet tripped
** the hardware's multicast filtering mechanism but was not actually in
** the current multicast table.
*/

#define S2SS_ETHERNET_RETRIES \
                      ((((S2WireType_Ethernet)&0xffff)<<16)|0x0001)
/*
** This count records the total number of retries which have resulted
** from transmissions on this board.
*/


#define S2SS_ETHERNET_FIFO_UNDERRUNS \
                      ((((S2WireType_Ethernet)&0xffff)<<16)|0x0002)
/*
** This count records an error condition which indoicates that the host
** computer did not feed the network interface card at a high enough rate.
*/

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

#endif /* DEVICES_SANA2SPECIALSTATS_H */
