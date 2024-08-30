#ifndef MIDI_CAMDBASE_H
#define MIDI_CAMDBASE_H
/*
** $VER: camdbase.h 54.16 (22.08.2022)
** 
** C. A. M. D. (Commodore Amiga MIDI Driver)
**
** camdbase.h - CAMD library base structure
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

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif


struct CamdBase 
{
    struct Library Lib;
    uint16 pad0;
	/* private stuff below here */
};

#endif
