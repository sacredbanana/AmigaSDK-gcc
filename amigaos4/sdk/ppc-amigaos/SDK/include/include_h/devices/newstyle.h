#ifndef DEVICES_NEWSTYLE_H
#define DEVICES_NEWSTYLE_H

/*
**    $VER: newstyle.h 54.16 (22.08.2022)
**
**    New Style Device standard definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
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
 *  At the moment there is just a single new style general command:
 */

#define NSCMD_DEVICEQUERY 0x4000

/****************************************************************************/

struct NSDeviceQueryResult
{
    /*
    ** Standard information, must be reset for every query
    */
    uint32   DevQueryFormat;         /* this is type 0 */
    uint32   SizeAvailable;          /* bytes available */

    /*
    ** Common information (READ ONLY!)
    */
    uint16   DeviceType;             /* what the device does */
    uint16   DeviceSubType;          /* depends on the main type */
    uint16 * SupportedCommands;      /* 0 terminated list of cmd's */

    /* May be extended in the future! Check SizeAvailable! */
};

/****************************************************************************/

#define NSDEVTYPE_UNKNOWN    0  /* No suitable category, anything */
#define NSDEVTYPE_GAMEPORT   1  /* like gameport.device */
#define NSDEVTYPE_TIMER      2  /* like timer.device */
#define NSDEVTYPE_KEYBOARD   3  /* like keyboard.device */
#define NSDEVTYPE_INPUT      4  /* like input.device */
#define NSDEVTYPE_TRACKDISK  5  /* like trackdisk.device */
#define NSDEVTYPE_CONSOLE    6  /* like console.device */
#define NSDEVTYPE_SANA2      7  /* A >=SANA2R2 networking device */
#define NSDEVTYPE_AUDIO      8  /* like audio.device */
#define NSDEVTYPE_CLIPBOARD  9  /* like clipboard.device */
#define NSDEVTYPE_PRINTER   10  /* like printer.device */
#define NSDEVTYPE_SERIAL    11  /* like serial.device */
#define NSDEVTYPE_PARALLEL  12  /* like parallel.device */
#define NSDEVTYPE_SCANNER	13
#define NSDEVTYPE_USB		14

/****************************************************************************/

/* The following defines should really be part of device specific
 * includes. So we protect them from being redefined.
 */

#ifndef NSCMD_TD_READ64

/****************************************************************************/

/*
 *  An early new style trackdisk like device can also return this
 *  new identifier for TD_GETDRIVETYPE. This should no longer
 *  be the case though for newly written or updated NSD devices.
 *  This identifier is ***OBSOLETE***
 */

#define DRIVE_NEWSTYLE (0x4E535459L)   /* 'NSTY' */

/*
 *  At the moment, only four new style commands in the device
 *  specific range and their ETD counterparts may be implemented.
 */

#define NSCMD_TD_READ64     0xC000
#define NSCMD_TD_WRITE64    0xC001
#define NSCMD_TD_SEEK64     0xC002
#define NSCMD_TD_FORMAT64   0xC003

#define NSCMD_ETD_READ64    0xE000
#define NSCMD_ETD_WRITE64   0xE001
#define NSCMD_ETD_SEEK64    0xE002
#define NSCMD_ETD_FORMAT64  0xE003

/****************************************************************************/

#endif /* NSCMD_TD_READ64 */

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

#endif /* DEVICES_NEWSTYLE_H */
