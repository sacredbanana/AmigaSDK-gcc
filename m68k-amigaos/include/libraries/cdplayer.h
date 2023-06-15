#ifndef CDPLAYER_H
#define CDPLAYER_H

/*
	Definitionen f�r die cdplayer.library  � 1995 by Patrick Hess

	$VER: cdplayer_protos.h 1.0 (29.05.1995)
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define CDPLAYERNAME		"cdplayer.library"
#define CDPLAYERVERSION		37L

/* Macros f�r die Umrechnung der Adressen in Minuten und Sekunden */

#define BASE2MIN(val)	((val)/75/60)
#define BASE2SEC(val)	(((val)/75)%60)

/* Tabel Of Contents - Inhaltsverzeichniss der CD */

struct CD_TOC
{
	UBYTE cdc_NumTracks;	/* Anzahl der Tracks auf CD */
	UBYTE cdc_ActTitle;	/* aktueller Titel, nur nach TOC-Lesen aktuell */
	UBYTE cdc_Flags[100];	/* Pro Track: 0 = Musik, 1 = Daten */
	ULONG cdc_Addr[100];	/* Pro Track: Start-Adressen */
};

/* aktuelle Position auf der CD, alles Adresse die mit dem Macros BASE2(MIN|SEC)
   in Minuten/Sekunden umgerechnet werden m�ssen */

struct CD_Time
{
	ULONG	cdt_TrackCurBase;	/* Adr: aktuelle Position Track */
	ULONG	cdt_TrackRemainBase;	/* Adr: Restspielzeit Track */
	ULONG	cdt_TrackCompleteBase;	/* Adr: Gesammspielzeit Track */
	ULONG	cdt_AllCurBase;		/* Adr: aktuelle Position CD */
	ULONG	cdt_AllRemainBase;	/* Adr: Restspielzeit CD */
	ULONG	cdt_AllCompleteBase;	/* Adr: Gesammtspielzeit CD */
};

/* Ausgangslaust�rke des CD-Roms, bei Audio i.d.R. nur Kanal 0 und 1 be-
   nutzt, Werte von 0-255 m�glich */

struct CD_Volume
{
	UBYTE	cdv_Chan0;	/* Lautst�rke Kanal 0 (0-255) */
	UBYTE	cdv_Chan1;	/* Lautst�rke Kanal 1 (0-255) */
	UBYTE	cdv_Chan2;	/* Lautst�rke Kanal 2 (0-255) */
	UBYTE	cdv_Chan3;	/* Lautst�rke Kanal 3 (0-255) */
};

/* diverse Infos �ber Laufwerk */

struct CD_Info
{
	BYTE  cdi_DeviceType;		/* Ger�tetyp */
	BOOL  cdi_RemovableMedium;	/* kann Medium entnommen werden? */
	BYTE  cdi_ANSIVersion;		/* SCSI-Version (0, 1, 2) */
	UBYTE cdi_VendorID[9];		/* Herstellername */
	UBYTE cdi_ProductID[17];	/* Product-ID */
	UBYTE cdi_ProductRev[5];	/* Product-Revision */
	UBYTE cdi_VendorSpec[21];	/* Vendor-Specification */
};

/* m�gliche Werte der CD_Info Struktur */

/* Device-Type */

#define DIRECT_ACCESS_DEVICE	0	/* z.B. Festplatte */
#define SEQ_ACCESS_DEVICE	1	/*      Streamer */
#define PRINTER_DEVICE		2	/*      Drucker */
#define PROCESSOR_DEVICE	3
#define WRITE_ONCE_DEVICE	4
#define CDROM_DEVICE		5	/*      CDRom */
#define SCANNER_DEVICE		6	/*      Scanner */
#define OPTICAL_MEMORY_DEVICE	7
#define MEDIUM_CHANGER_DEVICE	8
#define COMMUNICATION_DEVICE	9

/* andere Werte sind undefiniert */

/* ANSI/SCSI-Version */

#define UNKNOWN		0
#define SCSI_1		1
#define SCSI_2		2

#endif	/* Ende */

