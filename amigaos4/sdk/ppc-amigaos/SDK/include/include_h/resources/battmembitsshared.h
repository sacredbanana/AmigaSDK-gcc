#ifndef RESOURCES_BATTMEMBITSSHARED_H
#define RESOURCES_BATTMEMBITSSHARED_H 1
/*
**    $VER: battmembitsshared.h 54.16 (22.08.2022)
**
**    BattMem shared specific bit definitions.
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
 * Shared bits in the battery-backedup ram.
 *
 *     Bits 64 and above
 */

/*
 * SHARED_AMNESIA
 *
 *     The battery-backedup memory has had a memory loss.
 *     This bit is used as a flag that the user should be
 *     notified that all battery-backed bit have been
 *     reset and that some attention is required. Zero
 *     indicates that a memory loss has occured.
 */

#define BATTMEM_SHARED_AMNESIA_ADDR  64
#define BATTMEM_SHARED_AMNESIA_LEN    1


/*
 * SCSI_HOST_ID
 *
 *     a 3 bit field (0-7) that is stored in complemented form
 *     (this is so that default value of 0 really means 7)
 *     It's used to set the A3000 controllers SCSI ID (on reset)
 */

#define BATTMEM_SCSI_HOST_ID_ADDR    65
#define BATTMEM_SCSI_HOST_ID_LEN      3


/*
 * SCSI_SYNC_XFER
 *
 *     determines if the driver should initiate synchronous
 *     transfer requests or leave it to the drive to send the
 *     first request.    This supports drives that crash or
 *     otherwise get confused when presented with a sync xfer
 *     message.  Default=0=sync xfer not initiated.
 */

#define BATTMEM_SCSI_SYNC_XFER_ADDR  68
#define BATTMEM_SCSI_SYNC_XFER_LEN    1

/*
 * SCSI_FAST_SYNC
 *
 *     determines if the driver should initiate fast synchronous
 *     transfer requests (>5MB/s) instead of older <=5MB/s requests.
 *     Note that this has no effect if synchronous transfers are not
 *     negotiated by either side.
 *     Default=0=fast sync xfer used.
 */

#define BATTMEM_SCSI_FAST_SYNC_ADDR  69
#define BATTMEM_SCSI_FAST_SYNC_LEN    1

/*
 * SCSI_TAG_QUEUES
 *
 *     determines if the driver should use SCSI-2 tagged queuing
 *     which allows the drive to accept and reorder multiple read
 *     and write requests.
 *     Default=0=tagged queuing NOT enabled
 */

#define BATTMEM_SCSI_TAG_QUEUES_ADDR 70
#define BATTMEM_SCSI_TAG_QUEUES_LEN   1

/*
 * IDE_EXTRA_WAIT
 *
 *     Makes the system wait an additional number of seconds on
 *     every boot before accessing the IDE drives.  Currently
 *     in V40 the number is 8 seconds.  Equivalent to the SCSI
 *     TIMEOUT bit.
 *     Default=0=no extra wait
 */

#define BATTMEM_IDE_EXTRA_WAIT_ADDR  71
#define BATTMEM_IDE_EXTRA_WAIT_LEN    1

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

#endif /* RESOURCES_BATTMEMBITSSHARED_H */
