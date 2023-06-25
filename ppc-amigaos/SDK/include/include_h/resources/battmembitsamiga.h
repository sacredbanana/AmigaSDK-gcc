#ifndef RESOURCES_BATTMEMBITSAMIGA_H
#define RESOURCES_BATTMEMBITSAMIGA_H 1
/*
**    $VER: battmembitsamiga.h 54.16 (22.08.2022)
**
**    BattMem Amiga specific bit definitions.
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

/*
 * Amiga specific bits in the battery-backedup ram.
 *
 *     Bits 0 to 31, inclusive
 */

/*
 * AMIGA_AMNESIA
 *
 *     The battery-backedup memory has had a memory loss.
 *     This bit is used as a flag that the user should be
 *     notified that all battery-backed bit have been
 *     reset and that some attention is required. Zero
 *     indicates that a memory loss has occured.
 */

#define BATTMEM_AMIGA_AMNESIA_ADDR 0
#define BATTMEM_AMIGA_AMNESIA_LEN  1


/*
 * SCSI_TIMEOUT
 *
 *     adjusts the timeout value for SCSI device selection.  A
 *     value of 0 will produce short timeouts (128 ms) while a
 *     value of 1 produces long timeouts (2 sec).  This is used
 *     for Seagate drives (and some Maxtors apparently) that
 *     don`t respond to selection until they are fully spun up
 *     and intialised.
 */

#define BATTMEM_SCSI_TIMEOUT_ADDR  1
#define BATTMEM_SCSI_TIMEOUT_LEN   1


/*
 * SCSI_LUNS
 *
 *     Determines if the controller attempts to access logical
 *     units above 0 at any given SCSI address.  This prevents
 *     problems with drives that respond to ALL LUN addresses
 *     (instead of only 0 like they should).  Default value is
 *     0 meaning don't support LUNs.
 */

#define BATTMEM_SCSI_LUNS_ADDR     2
#define BATTMEM_SCSI_LUNS_LEN      1

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

#endif /* RESOURCES_BATTMEMBITSAMIGA_H */
