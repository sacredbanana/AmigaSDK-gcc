#ifndef MIDI_CAMDDEVICES_H
#define MIDI_CAMDDEVICES_H
/*
** $VER: camddevices.h 54.16 (22.08.2022)
** 
** C. A. M. D. (Commodore Amiga MIDI Driver)
**
** camddevices.h - MIDI device driver include file
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


struct MidiPortData 
{
    void (*ActivateXmit)(); /* function to activate transmitter interrupt when idle */
};

struct MidiDeviceData 
{
    uint32 Magic;	    /* MDD_Magic */
    char  *Name; 	    /* driver name */
    char  *IDString;
    uint16 Version;
    uint16 Revision;

    BOOL (*Init)(void);     /* called after LoadSeg() */
    void (*Expunge)(void);  /* called before UnLoadSeg() */
    struct MidiPortData *(*OpenPort)();
    void (*ClosePort)();

    uint8 NPorts;	    /* number of ports */
    uint8 Flags;	    /* currently none */

    struct Library          *CamdDriverBase;
    struct CamdDriverIFace  *ICamdDriver;
};

#define MDD_SegOffset	8   /* offset to structure in segment (past NextSeg and MOVEQ/RTS) */
#define MDD_Magic	((uint32)'M' << 24 | (ULONG)'D' << 16 | 'E' << 8 | 'V')


#endif
