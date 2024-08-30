	IFND	DEVICES_TRACKDISK_I
DEVICES_TRACKDISK_I	SET	1

**
**	$VER: trackdisk.i 47.3 (24.8.2020)
**
**	trackdisk device structure and value definitions
**
**	Copyright (C) 2019-2020 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_IO_I
	INCLUDE	"exec/io.i"
	ENDC	!EXEC_IO_I

	IFND	EXEC_DEVICES_I
	INCLUDE	"exec/devices.i"
	ENDC	!EXEC_DEVICES_I

*--------------------------------------------------------------------
*
* Physical drive constants
*
*--------------------------------------------------------------------

NUMSECS		EQU	11
NUMUNITS	EQU	4

*--------------------------------------------------------------------
*
* Useful constants
*
*--------------------------------------------------------------------

*-- sizes before mfm encoding
TD_SECTOR	EQU	512
TD_SECSHIFT	EQU	9			; log TD_SECTOR

*--------------------------------------------------------------------
*
* Driver Specific Commands
*
*--------------------------------------------------------------------

*-- TD_NAME is a generic macro to get the name of the driver.  This
*-- way if the name is ever changed you will pick up the change
*-- automatically.
*--
*-- Normal usage would be:
*--
*-- internalName:	TD_NAME
*--

TD_NAME:	MACRO
		DC.B	'trackdisk.device',0
		DS.W	0
		ENDM

	BITDEF	TD,EXTCOM,15

	DEVINIT
	DEVCMD	TD_MOTOR		; control the disk's motor
	DEVCMD	TD_SEEK			; explicit seek (for testing)
	DEVCMD	TD_FORMAT		; format disk
	DEVCMD	TD_REMOVE		; notify when disk changes
	DEVCMD	TD_CHANGENUM		; number of disk changes
	DEVCMD	TD_CHANGESTATE		; is there a disk in the drive?
	DEVCMD	TD_PROTSTATUS		; is the disk write protected?
	DEVCMD	TD_RAWREAD		; read raw bits from the disk
	DEVCMD	TD_RAWWRITE		; write raw bits to the disk
	DEVCMD	TD_GETDRIVETYPE		; get the type of the disk drive
	DEVCMD	TD_GETNUMTRACKS		; get the # of tracks on this disk
	DEVCMD	TD_ADDCHANGEINT		; TD_REMOVE done right
	DEVCMD	TD_REMCHANGEINT		; removes softint set by ADDCHANGEINT
	DEVCMD	TD_GETGEOMETRY		; gets the disk geometry table
	DEVCMD	TD_EJECT		; for those drives that support it
	DEVCMD	TD_LASTCOMM		; dummy placeholder for end of list

*
* Some devices also support 64-bit wide commands. The higher 32 bit are then
* in io_Actual. The trackdisk itself does not support these commands
* for obvious reasons...
TD_READ64     EQU	24
TD_WRITE64    EQU	25
TD_SEEK64     EQU	26
TD_FORMAT64   EQU	27

*
*
* The disk driver has an "extended command" facility.  These commands
* take a superset of the normal IO Request block.
*
ETD_WRITE	EQU	(CMD_WRITE!TDF_EXTCOM)
ETD_READ	EQU	(CMD_READ!TDF_EXTCOM)
ETD_MOTOR	EQU	(TD_MOTOR!TDF_EXTCOM)
ETD_SEEK	EQU	(TD_SEEK!TDF_EXTCOM)
ETD_FORMAT	EQU	(TD_FORMAT!TDF_EXTCOM)
ETD_UPDATE	EQU	(CMD_UPDATE!TDF_EXTCOM)
ETD_CLEAR	EQU	(CMD_CLEAR!TDF_EXTCOM)
ETD_RAWREAD	EQU	(TD_RAWREAD!TDF_EXTCOM)
ETD_RAWWRITE	EQU	(TD_RAWWRITE!TDF_EXTCOM)

*
* extended IO has a larger than normal io request block.
*

 STRUCTURE IOEXTTD,IOSTD_SIZE
	ULONG	IOTD_COUNT	; removal/insertion count
	APTR	IOTD_SECLABEL	; sector label data region
	LABEL	IOTD_SIZE

*
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
*

 STRUCTURE DriveGeometry,0
	ULONG	dg_SectorSize		; in bytes 
	ULONG	dg_TotalSectors		; total # of sectors on drive 
	ULONG	dg_Cylinders		; number of cylinders 
	ULONG	dg_CylSectors		; number of sectors/cylinder 
	ULONG	dg_Heads		; number of surfaces 
	ULONG	dg_TrackSectors		; number of sectors/track 
	ULONG	dg_BufMemType		; preferred buffer memory type 
					; (usually MEMF_PUBLIC)
	UBYTE	dg_DeviceType		; codes as defined in the SCSI-2 spec
	UBYTE	dg_Flags		; flags, including removable 
	UWORD	dg_Reserved
 LABEL dg_SIZEOF

* device types
DG_DIRECT_ACCESS	EQU	0
DG_SEQUENTIAL_ACCESS	EQU	1
DG_PRINTER		EQU	2
DG_PROCESSOR		EQU	3
DG_WORM			EQU	4
DG_CDROM		EQU	5
DG_SCANNER		EQU	6
DG_OPTICAL_DISK		EQU	7
DG_MEDIUM_CHANGER	EQU	8
DG_COMMUNICATION	EQU	9
DG_UNKNOWN		EQU	31

* flags
 BITDEF DG,REMOVABLE,0

*
* raw read and write can be synced with the index pulse.  This flag
* in io request's IO_FLAGS field tells the driver that you want this.
*
	BITDEF	IOTD,INDEXSYNC,4
*
* raw read and write can be synced with a $4489 sync pattern.  This flag
* in io request's IO_FLAGS field tells the driver that you want this.
*
	BITDEF	IOTD,WORDSYNC,5

* labels are TD_LABELSIZE bytes per sector

TD_LABELSIZE	EQU	16

*
* This is a bit in the FLAGS field of OpenDevice.  If it is set, then
* the driver will allow you to open all the disks that the trackdisk
* driver understands.  Otherwise only 3.5" disks will succeed.
*
*
	BITDEF	TD,ALLOW_NON_3_5,0

*
*  If you set the TDB_ALLOW_NON_3_5 bit in OpenDevice, then you don't
*  know what type of disk you really got.  These defines are for the
*  TD_GETDRIVETYPE command.  In addition, you can find out how many
*  tracks are supported via the TD_GETNUMTRACKS command.
*
DRIVE3_5	EQU	1
DRIVE5_25	EQU	2
DRIVE3_5_150RPM	EQU	3

*--------------------------------------------------------------------
*
* Driver error defines
*
*--------------------------------------------------------------------

TDERR_NotSpecified	EQU	20	; general catchall
TDERR_NoSecHdr		EQU	21	; couldn't even find a sector
TDERR_BadSecPreamble	EQU	22	; out of bounds sector number/offset
TDERR_BadSecID		EQU	23	; incorrect sector type
TDERR_BadHdrSum		EQU	24	; header had incorrect checksum
TDERR_BadSecSum		EQU	25	; data had incorrect checksum
TDERR_TooFewSecs	EQU	26	; couldn't find enough sectors
TDERR_BadSecHdr		EQU	27	; incorrect sector track number
TDERR_WriteProt		EQU	28	; can't write to a protected disk
TDERR_DiskChanged	EQU	29	; no disk in the drive
TDERR_SeekError		EQU	30	; couldn't find track 0
TDERR_NoMem		EQU	31	; ran out of memory
TDERR_BadUnitNum	EQU	32	; asked for a unit > NUMUNITS
TDERR_BadDriveType	EQU	33	; not a drive that trackdisk groks
TDERR_DriveInUse	EQU	34	; someone else allocated the drive
TDERR_PostReset		EQU	35	; user hit reset; awaiting doom

*--------------------------------------------------------------------
*
* Public portion of unit structure
*
*--------------------------------------------------------------------

 STRUCTURE TDU_PUBLICUNIT,UNIT_SIZE
	UWORD	TDU_COMP01TRACK		; track for first precomp
	UWORD	TDU_COMP10TRACK		; track for second precomp
	UWORD	TDU_COMP11TRACK		; track for third precomp
	ULONG	TDU_STEPDELAY		; time to wait after stepping
	ULONG	TDU_SETTLEDELAY		; time to wait after seeking
	UBYTE	TDU_RETRYCNT		; # of times to retry
	UBYTE	TDU_PUBFLAGS		; public flags, see below
	UWORD	TDU_CURRTRK		; track heads are over
					;  (ONLY ACCESS WHILE UNIT IS STOPPED!)
	ULONG	TDU_CALIBRATEDELAY	; time to wait after stepping
					; for recalibrate
	ULONG	TDU_COUNTER		; counter for disk changes
					;  (ONLY ACCESS WHILE UNIT IS STOPPED!)
	ULONG   TDU_POSTWRITEDELAY	; time to wait after a write
	ULONG   TDU_SIDESELECTDELAY	; time to wait after head select

	LABEL	TDU_PUBLICUNITSIZE

*
* Flags for TDU_PUBFLAGS:
*
	BITDEF	TDP,NOCLICK,0		; set to enable noclickstart

	ENDC	; DEVICE_TRACKDISK_I

