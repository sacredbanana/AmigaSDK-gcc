#ifndef MIDI_MIDIPREFS_H
#define MIDI_MIDIPREFS_H
/*
** $VER: midiprefs.h 54.16 (22.08.2022)
** 
** C. A. M. D. (Commodore Amiga MIDI Driver)
**
** midiprefs.h - CAMD MIDI preferences
**
** Design & Development  - Roger B. Dannenberg
**                       - Jean-Christophe Dhellemmes
**                       - Bill Barton
**                       - Darius Taghavy
**
** Copyright 1990 by Commodore Business Machines
**
** Copyright (c) 2013 Hyperion Entertainment CVBA.
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif


/***************************************************************
*
*   MidiUnitDef
*
***************************************************************/

#define MaxMidiDevName		32
#define MaxMidiInOutName	32
#define MaxMidiComment		34

struct MidiUnitDef 
{
    uint8 MidiDeviceName[32];	/* Name of MIDI device driver for this Unit (ignored for MUDF_Internal) */
    uint8 MidiClusterInName[32];/* Name of Cluster for input from MIDI device driver */
    uint8 MidiClusterOutName[32];/* Name of Cluster for output to MIDI device driver */
    uint8 MidiDeviceComment[34]; /* Comment field */
    uint8 MidiDevicePort;	/* MIDI device driver port number for this Unit */
    uint8 Flags;
    uint32 XmitQueueSize;
    uint32 RecvQueueSize;
    uint32 Reserved[4];
};

    /* flags */
#define MUDF_Internal	 (1<<0)	/* Use Amiga's internal serial port.
				   Ignore MidiDeviceName/Port when set.
				   Only one Unit can legally have this bit set. */
#define MUDF_Ignore	 (1<<1) /* Ignore this entry. */

/* !!! maybe additional flags:	running status enable, thru */

    /* minimum queue sizes */

#define MinXmitQueueSize 512L	/* minimum send queue size (bytes) */
#define MinRecvQueueSize 2048L	/* minimum recv queue size (words) */


/***************************************************************
*
*   MidiPrefs
*
***************************************************************/


#define ID_MIDI MAKE_ID('M','I','D','I')

struct MidiPrefs 
{
    uint8 NUnits;
    uint8 pad0[3];
    struct MidiUnitDef UnitDef[1];
};

#define MidiPrefsName  "midi.prefs"

#endif
