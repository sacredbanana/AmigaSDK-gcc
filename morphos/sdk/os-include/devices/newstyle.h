#ifndef DEVICES_NEWSTYLE_H
#define DEVICES_NEWSTYLE_H

/*
	newstyle device definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#warning "It's not recommended that you use any NSD functionality in your devices..."

#pragma pack(2)


#define NSCMD_DEVICEQUERY  0x4000


struct NSDeviceQueryResult
{
	ULONG  DevQueryFormat;
	ULONG  SizeAvailable;

	UWORD  DeviceType;
	UWORD  DeviceSubType;
	UWORD *SupportedCommands;
};


#define NSDEVTYPE_UNKNOWN      0
#define NSDEVTYPE_GAMEPORT     1
#define NSDEVTYPE_TIMER        2
#define NSDEVTYPE_KEYBOARD     3
#define NSDEVTYPE_INPUT        4
#define NSDEVTYPE_TRACKDISK    5
#define NSDEVTYPE_CONSOLE      6
#define NSDEVTYPE_SANA2        7
#define NSDEVTYPE_AUDIO        8
#define NSDEVTYPE_CLIPBOARD    9
#define NSDEVTYPE_PRINTER      10
#define NSDEVTYPE_SERIAL       11
#define NSDEVTYPE_PARALLEL     12

#define NSDEVTYPE_USBHARDWARE  NSDEVTYPE_UNKNOWN


#ifndef NSCMD_TD_READ64

#define DRIVE_NEWSTYLE  (0x4E535459L)	/* NSTY */

#define NSCMD_TD_READ64     0xC000
#define NSCMD_TD_WRITE64    0xC001
#define NSCMD_TD_SEEK64     0xC002
#define NSCMD_TD_FORMAT64   0xC003

#define NSCMD_ETD_READ64    0xE000
#define NSCMD_ETD_WRITE64   0xE001
#define NSCMD_ETD_SEEK64    0xE002
#define NSCMD_ETD_FORMAT64  0xE003

#endif /* NSCMD_TD_READ64 */


#pragma pack()

#endif /* DEVICES_NEWSTYLE_H */
