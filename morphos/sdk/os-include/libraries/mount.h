#ifndef	LIBRARIES_MOUNT_H
#define	LIBRARIES_MOUNT_H

#ifndef	EXEC_TYPES_H
#include <exec/types.h>
#endif

#define	MOUNTATTR_Dummy			(TAG_USER +0x01010000)
/*
 * The Device ptr for the NotifyUnit
 *     Data: struct Device*
 * Function: MountCreateNotifyUnitTagList(), MountGetNotifyUnitAttr()
 */
#define	MOUNTATTR_DEVICE		(MOUNTATTR_Dummy+0)
/*
 * The Unit ptr for the NotifyUnit
 *     Data: struct Unit*
 * Function: MountCreateNotifyUnitTagList(), MountGetNotifyUnitAttr()
 */
#define	MOUNTATTR_UNIT			(MOUNTATTR_Dummy+1)
/*
 * The interrupt for a notifynode
 * Data: struct Interrupt*
 */
#define	MOUNTATTR_INTERRUPT		(MOUNTATTR_Dummy+1)
/*
 * The Task for a notifynode
 * Data: struct Task*
 */
#define	MOUNTATTR_TASK			(MOUNTATTR_Dummy+2)
/*
 * The IORequest for a notifynode
 * Data: struct IORequest*
 */
#define	MOUNTATTR_IOREQUEST		(MOUNTATTR_Dummy+3)
/*
 * The ChangeStatus
 * Data: ULONG (0 or -1)
 */
#define	MOUNTATTR_CHANGESTATE		(MOUNTATTR_Dummy+4)
/*
 * The ProtStatus
 *     Data: ULONG (0 or -1)
 * Function: MountGetNotifyUnitAttr()
 */
#define	MOUNTATTR_PROTSTATE		(MOUNTATTR_Dummy+5)
/*
 * Copies the DriveGeometry to the passed data ptr
 *     Data: struct DriveGeometry *
 * Function: MountGetNotifyUnitAttr()
 */
#define	MOUNTATTR_DRIVEGEOMETRY		(MOUNTATTR_Dummy+6)

/*
 * Refreshes the drivegeometry(totalsectors,sectorsize...) and protstatus
 * to reflect the current drive state. Only used by MountMountTagList() at
 * the moment.
 * Data: Boolean
 */
#define	MOUNTATTR_UPDATEUNITCONFIG	(MOUNTATTR_Dummy+7)

/*
 * Set the mount mode for an unit mount operation.
 * Data: Mode
 *       MOUNTMODE_AUTO 
 *       MOUNTMODE_YES
 *       MOUNTMODE_NO
 */
#define	MOUNTATTR_MOUNTMODE		(MOUNTATTR_Dummy+8)

/*
 * Get more informations why some function failed
 * Data: MOUNTERROR_?
 */
#define	MOUNTATTR_ERROR			(MOUNTATTR_Dummy+9)

/*
 * No ISO9660 mounting for cdroms
 * Data: Boolean
 */
#define	MOUNTATTR_NOISO9660		(MOUNTATTR_Dummy+10)
/*
 * No RDB mounting
 * Data: Boolean
 */
#define	MOUNTATTR_NORDB			(MOUNTATTR_Dummy+11)
/*
 * No MBR mounting
 * Data: Boolean
 */
#define	MOUNTATTR_NOMBR			(MOUNTATTR_Dummy+12)
/*
 * No FAT mounting
 * Data: Boolean
 */
#define	MOUNTATTR_NOFAT			(MOUNTATTR_Dummy+13)
/*
 * No MAC mounting
 * Data: Boolean
 */
#define	MOUNTATTR_NOMAC			(MOUNTATTR_Dummy+14)
/*
 * No GUID mounting
 * Data: Boolean
 */
#define	MOUNTATTR_NOGUID		(MOUNTATTR_Dummy+15)
/*
 * Force mounting stand-alone filesystem (without partition-table layout)
 * Data: Boolean
 */
#define	MOUNTATTR_FORCENOLAYOUT	(MOUNTATTR_Dummy+16)
#define	MOUNTATTR_FORCENOLAYUOT	MOUNTATTR_FORCENOLAYOUT
/*
 * Drive name for no partition table case
 * Data: STRPTR
 */
#define	MOUNTATTR_DRIVENAME		(MOUNTATTR_Dummy+17)
/*
 * Filesystem for no partition table case
 * Data: ULONG
 */
#define	MOUNTATTR_FILESYSTEM	(MOUNTATTR_Dummy+18)
/*
 * Number of buffers for no partition table case
 * Data: ULONG
 */
#define	MOUNTATTR_NUMBUFFERS	(MOUNTATTR_Dummy+19)
/*
 * No RAW FS autodetection and mounting
 * Data: Boolean
 */
#define MOUNTATTR_NORAWFS       (MOUNTATTR_Dummy+20)

/*****************************************************************************/

/*
 * MOUNTATTR_MOUNTMODE
 * values
 */

#define	MOUNTMODE_AUTO	0
#define	MOUNTMODE_NO	1
#define	MOUNTMODE_YES	2


/*****************************************************************************/

/*
 * MOUNTATTR_ERROR
 * values
 */
#define	MOUNTERROR_OK			0
#define	MOUNTERROR_MEMORY		1
#define	MOUNTERROR_QUERY_NOUNITNUM	2
#define	MOUNTERROR_SIGNAL		3
#define	MOUNTERROR_TIMER		4


#endif
