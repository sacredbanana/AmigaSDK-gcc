/**
 * @file mounter.h
 *
 * @copyright (c) 2004-2014 by Sebastian Bauer
 */

#ifndef LIBRARIES_MOUNTER_H
#define LIBRARIES_MOUNTER_H

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif


#define MNTA_Dummy             (TAG_USER + 0x1000)


/* Specifies a hook for MounterAnnounce() that is invoked when the initial
 * device processing has been completed. In the ideal case, all partitions
 * on the media have been mounted then. The object and message parameter
 * of the invoked hook function is currently set to NULL.
 *
 * This tag is useful in a situation in that one want to halt a certain
 * process until a first attempt to mount the partition has been
 * undertaken. E.g., devices that are added in a pre dos environment
 * may hold the boot process until the partitions has been enqueued to
 * ensure that it is possible to boot from them. Note that a time-out must
 * be implemented by the respective devices on their own. Also note that
 * once the hook have been called, it will be never called again for this
 * instance.
 */
#define MNTA_AnnounceCompletedHook     (MNTA_Dummy + 1) /* struct Hook * */

/*
 * Specifies a hint how the prefix of the dos name of mounted partitions
 * could look like. For instance, USB devices could specifies "USB" in which
 * case "USB0:" would be the dos name for unit 0.
 */
#define MNTA_DosNamePrefixHint         (MNTA_Dummy + 2) /* CONST_STRPTR */

/************************************************************************/

/* The following should be part of a device include file */

/**
 * Similar to struct DriveGeometry but using 64 bit
 * quantities where needed.
 */
struct DriveGeometry64
{
    uint32 dg_SectorSize; 					/* in bytes */
    uint64 dg_Reserved1;					/* 0 */
    uint64 dg_TotalSectors;					/* total # of sectors on drive */
    const struct TagItem *dg_BufMemTags;	/* tags describing the preferred buffer memory type more detailed than BufMemType */
    uint8 dg_DeviceType;					/* codes as defined in the SCSI-2 spec */
    uint8 dg_Flags;							/* flags, including removable */
    uint16 dg_Reserved2;					/* 0 */
};

/**
 * Gets the disk geometry table. Similar to TD_GETGEOMETRY
 * but uses struct DriveGeometry64.
 */
#define NSCMD_TD_GETGEOMETRY64 0xA004


struct ChangeUnit
{
	/**
         * Specifies the unit number under which the device or parts of it shall be made
         * addressable. A -1 will indicate that a not yet used unit shall be used.
         */
	int32 unitNumber;

	/**
         * Specifies the start block (inclusive) of the part of the media that should
         * be made available under the unitNumber. Use endBlock < startBlock if the
         * part should cover the entire media.
         */
	uint64 startBlock;

	/**
         * Specifies the end block (inclusive) of the part of the media that should
         * be made available under the unitNumber. Use endBlock < startBlock if the
         * part should cover the entire media.
         */
	uint64 endBlock;
};

/**
 * Attempts to change the unit to a new unit as specified
 * by io->io_Offset. May return IOERR_UNITBUSY if the
 * new unit is already in use. Use -1 for io->io_Offset
 * if a compeltly new unit should be chosen.
 */
#define NSCMD_TD_CHANGEUNIT 0xA005

/**
 * Associates the given unit with a callback
 * hook (io_Data). The io will be under control of
 * the device if the call succeeds. Use
 * NSCMD_TD_REMSTATCALLBACK to remove the
 * callback. The embedded MinNode of the supplied
 * Hook might get overwritten.
 */
#define NSCMD_TD_ADDSTATCALLBACK 0xA006

/**
 * Passed as the message parameter to the stat
 * callback.
 */
struct StatData
{
	uint32 Size;
	uint32 Flags;
};

#define SD_READ (1<<0)
#define SD_WRITE (1<<1)


/**
 * Removes the given stat callback from the unit.
 */
#define NSCMD_TD_REMSTATCALLBACK 0xA007


#endif

