#ifndef PREFS_DOS_H
#define PREFS_DOS_H
/*
**  $VER: dos.h  54.100 (07.09.2020)
**
**  File format for DOS preferences
**
**  Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**      All Rights Reserved
**
**  Copyright (c) 2010 Hyperion Entertainment CVBA.
**      All Rights Reserved.
*/
 
/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

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

/*****************************************************************************/


#define ID_DOSP MAKE_ID('D','O','S','P')


struct DOSPrefs
{
    int32 dp_FHBufferSize;       /* Size in bytes for all FileHandle buffers. */
    int32 dp_MinProcStack;       /* Minimum stack bytes for all processes */
    int32 dp_WarnWaitTime;       /* Number of seconds to wait between warnings. */
    int32 dp_WarnPostTime;       /* Number of seconds to post warning for.  */
                                 /* Note that a value of 0 means post forever. */
    int32 dp_WildStar;           /* BOOLEAN - see doscontrol  */
    int32 dp_AssignMount;        /* BOOLEAN - see errorreport()  */
    int32 dp_BootCliFontSize;    /* Set to: TOPAZ_EIGHTY or TOPAZ_SIXTY (8 or 9) */
                                 /* The define for this is in intuition/preferences.h */
    int32 dp_BootCliCloseGadget; /* BOOLEAN - see doscontrol */
    int32 dp_Reserved[6];        /* reserved for future DOS expansion.  */
};



/*****************************************************************************/
/*  These are the default definitions and values used by the DOS library
**  and also the DOS prefs tool.
*/

#define FHBufferSize_Default           0x8000       /* 32k bytes */
#define MinProcStack_Default           0x8000       /* 32k bytes */
#define WarnWaitTime_Default           2            /* 2 seconds */
#define WarnPostTime_Default           180          /* 3 mins    */
#define WildStar_Default               0            /* BOOLEAN FALSE */
#define AssignMount_Default            1            /* BOOLEAN TRUE  */
#define BootCliFontSize_Default        9            /* 9 point font (8 or 9) */
#define BootCliCloseGadget_Default     1            /* BOOLEAN TRUE  */    



/*****************************************************************************/
/*  These set the allowable ranges for the DOS prefs tool and are also used
**  inside the IDOS->DosControl() function for limit checks.
*/

/* Filehandle buffer size limits. */
#define FHB_MIN		204			/* min= 204 byte limit is for V40 compatibility */
#define FHB_MAX		0x80000   	/* max= 512k filehandle buffer bytes */

/* Process stack size limits. */
#define MPS_MIN		0x3FF8		/* min= 16k process stack (best page fit) */
#define MPS_MAX		0x80000		/* max= 512k process stack */

/* Warning wait time before reposting a requester. */
#define WWT_MIN		0			/* min= 0 seconds  */
#define WWT_MAX		600			/* max= 600 seconds (10 minutes) */

/* Warning post time before auto-closing requester - note that 0= post forever. 
** NB: Values between 1 and 5 should be avoided to prevent requesters
**     disappearing too fast for the user to be able to read them.
*/ 
#define WPT_MIN		0			/* min= 0 seconds = post forever */
#define WPT_MAX		600			/* max= 600 seconds maximum post time */




/*****************************************************************************/

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

/*****************************************************************************/

#endif /* PREFS_DOS_H */
