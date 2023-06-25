#ifndef DEVICES_A1FLOPPY_H
#define DEVICES_A1FLOPPY_H
/*
**
**    $VER: a1floppy.h 54.16 (22.08.2022)
**
**    trackdisk device structure and value definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

#ifndef   EXEC_DEVICES_H
#include <exec/devices.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
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

/*--------------------------------------------------------------------
 *
 * Driver Specific Commands
 *
 *--------------------------------------------------------------------
 */

/*
 *-- TD_NAME is a generic macro to get the name of the driver.    This
 *-- way if the name is ever changed you will pick up the change
 *-- automatically.
 *--
 *-- Normal usage would be:
 *--
 *-- char internalName[] = TD_NAME;
 *--
 */

#define TD_NAME "a1floppy.device"

#define TD_MOTOR        (CMD_NONSTD+0)  /* control the disk's motor */
#define TD_SEEK         (CMD_NONSTD+1)  /* explicit seek (for testing) */
#define TD_FORMAT       (CMD_NONSTD+2)  /* format disk */
#define TD_REMOVE       (CMD_NONSTD+3)  /* notify when disk changes */
#define TD_CHANGENUM    (CMD_NONSTD+4)  /* number of disk changes */
#define TD_CHANGESTATE  (CMD_NONSTD+5)  /* is there a disk in the drive? */
#define TD_PROTSTATUS   (CMD_NONSTD+6)  /* is the disk write protected? */
#define TD_RAWREAD      (CMD_NONSTD+7)  /* read raw bits from the disk */
#define TD_RAWWRITE     (CMD_NONSTD+8)  /* write raw bits to the disk */
#define TD_GETDRIVETYPE (CMD_NONSTD+9)  /* get the type of the disk drive */
#define TD_GETNUMTRACKS (CMD_NONSTD+10) /* # of tracks for this type drive */
#define TD_ADDCHANGEINT (CMD_NONSTD+11) /* TD_REMOVE done right */
#define TD_REMCHANGEINT (CMD_NONSTD+12) /* remove softint set by ADDCHANGEINT */
#define TD_GETGEOMETRY  (CMD_NONSTD+13) /* gets the disk geometry table */
#define TD_EJECT        (CMD_NONSTD+14) /* for those drives that support it */
#define TD_LASTCOMM     (CMD_NONSTD+15)

/*
 *  This is the structure returned by TD_DRIVEGEOMETRY
 *  Note that the layout can be defined three ways:
 *
 *  1. TotalSectors
 *  2. Cylinders and CylSectors
 *  3. Cylinders, Heads, and TrackSectors.
 *
 *  #1 is most accurate, #2 is less so, and #3 is least accurate.  All
 *  are usable, though #2 and #3 may waste some portion of the available
 *  space on some drives.
 */
struct DriveGeometry
{
    ULONG dg_SectorSize;   /* in bytes */
    ULONG dg_TotalSectors; /* total # of sectors on drive */
    ULONG dg_Cylinders;    /* number of cylinders */
    ULONG dg_CylSectors;   /* number of sectors/cylinder */
    ULONG dg_Heads;        /* number of surfaces */
    ULONG dg_TrackSectors; /* number of sectors/track */
    ULONG dg_BufMemType;   /* preferred buffer memory type */
                           /* (usually MEMF_PUBLIC) */
    UBYTE dg_DeviceType;   /* codes as defined in the SCSI-2 spec*/
    UBYTE dg_Flags;        /* flags, including removable */
    UWORD dg_Reserved;
};

/* device types */
#define DG_DIRECT_ACCESS      0
#define DG_SEQUENTIAL_ACCESS  1
#define DG_PRINTER            2
#define DG_PROCESSOR          3
#define DG_WORM               4
#define DG_CDROM              5
#define DG_SCANNER            6
#define DG_OPTICAL_DISK       7
#define DG_MEDIUM_CHANGER     8
#define DG_COMMUNICATION      9
#define DG_UNKNOWN           31

/* flags */
#define DGB_REMOVABLE 0
#define DGF_REMOVABLE 1

/*
** This is a bit in the FLAGS field of OpenDevice.  If it is set, then
** the driver will allow you to open all the disks that the trackdisk
** driver understands.    Otherwise only 3.5" disks will succeed.
*/
#define TDB_ALLOW_NON_3_5 0
#define TDF_ALLOW_NON_3_5 (1<<0)

/*
**  If you set the TDB_ALLOW_NON_3_5 bit in OpenDevice, then you don't
**  know what type of disk you really got.  These defines are for the
**  TD_GETDRIVETYPE command.  In addition, you can find out how many
**  tracks are supported via the TD_GETNUMTRACKS command.
*/
#define DRIVE3_5        1
#define DRIVE5_25       2
#define DRIVE3_5_150RPM 3

/*
 *--------------------------------------------------------------------
 *
 * Driver error defines
 *
 *--------------------------------------------------------------------
 */

#define TDERR_NotSpecified   20 /* general catchall */
#define TDERR_NoSecHdr       21 /* couldn't even find a sector */
#define TDERR_BadSecPreamble 22 /* sector looked wrong */
#define TDERR_BadSecID       23 /* ditto */
#define TDERR_BadHdrSum      24 /* header had incorrect checksum */
#define TDERR_BadSecSum      25 /* data had incorrect checksum */
#define TDERR_TooFewSecs     26 /* couldn't find enough sectors */
#define TDERR_BadSecHdr      27 /* another "sector looked wrong" */
#define TDERR_WriteProt      28 /* can't write to a protected disk */
#define TDERR_DiskChanged    29 /* no disk in the drive */
#define TDERR_SeekError      30 /* couldn't find track 0 */
#define TDERR_NoMem          31 /* ran out of memory */
#define TDERR_BadUnitNum     32 /* asked for a unit > NUMUNITS */
#define TDERR_BadDriveType   33 /* not a drive that trackdisk groks */
#define TDERR_DriveInUse     34 /* someone else allocated the drive */
#define TDERR_PostReset      35 /* user hit reset; awaiting doom */
#define	TDERR_Timeout        36 /* data timeout - internal error */
#define	TDERR_DataLoss       37 /* data lost - internal error */
#define	TDERR_InternalFault  38 /* an internal software fault */
#define	TDERR_HardError      39 /* too many unsuccessful retries */

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
#endif

/****************************************************************************/

#endif /* DEVICES_A1FLOPPY_H */
