#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H 1
/*
**    $VER: timer.h 54.16 (22.08.2022)
**
**    Timer device name and useful definitions.
**
**    Copyright (C) 1985-2006 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

/****************************************************************************/

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

/****************************************************************************/

/* unit defintions */
enum enTimerUnits
{
    UNIT_MICROHZ    = 0,    /* 1/1000000 second granularity */
    UNIT_VBLANK     = 1,    /* 1/60 second granularity */
    UNIT_ECLOCK     = 2,    /* system dependant number of ticks/second */
    UNIT_WAITUNTIL  = 3,    /* wait until a certain point of time */
    UNIT_WAITECLOCK = 4,    /* wait until a certain point of time
                              (in EClock ticks) */
    UNIT_ENTROPY    = 5,    /* Read entropy data */
};

/****************************************************************************/

#define TIMERNAME "timer.device"

/****************************************************************************/

/* These are the default definitions for now. If you need a different
   definition of the timeval and timerequest data structures, see below. */

struct TimeVal
{
    uint32 Seconds;
    uint32 Microseconds;
};

struct TimeRequest
{
    struct IORequest Request;
    struct TimeVal   Time;
};

/* Remember that the new data structure definitions were declared. */
#ifndef __NEW_TIMEVAL_DEFINITION_USED__
#define __NEW_TIMEVAL_DEFINITION_USED__
#endif /* __NEW_TIMEVAL_DEFINITION_USED__ */

/****************************************************************************/

/* The 'struct timeval' definition used by AmigaOS since its introduction in
   the year 1985 was similar to a data structure of the same name as used in
   the Unix domain. Similar, but not identical. This had consequences when
   porting software to the Amiga which came from a Unix/POSIX system, as it
   clashed with the Amiga definition of the 'struct timeval'. Rather than
   use compatibility workarounds, the 'struct timeval' and 'struct timerequest'
   data structures were replaced with 'struct TimeVal' and 'struct TimeRequest',
   respectively.

   If you need to compile your software with the old AmigaOS 1.x/2.x/3.x
   compatible timeval/timerequest definitions, define the preprocessor
   symbol __USE_OLD_TIMEVAL__ in your header files, makefile or source code. */

#ifdef __USE_OLD_TIMEVAL__

#ifndef __TIMEVAL_ALREADY_DEFINED
#define __TIMEVAL_ALREADY_DEFINED

struct timeval
{
    ULONG tv_secs;
    ULONG tv_micro;
};

#else

#define tv_secs  tv_sec
#define tv_micro tv_usec

#endif /* !__TIMEVAL_ALREADY_DEFINED */

struct timerequest
{
    struct IORequest tr_node;
    struct timeval   tr_time;
};

#endif /* !__USE_OLD_TIMEVAL__ */

/****************************************************************************/

/* This is really a 64 bit integer value split into two 32 bit integers. */
struct EClockVal
{
    uint32 ev_hi;
    uint32 ev_lo;
};

/****************************************************************************/

enum enTimerCmd
{
    TR_ADDREQUEST  = CMD_NONSTD,      /* Add a timer request */
    TR_GETSYSTIME  = (CMD_NONSTD+1),  /* Obtain the system time */
    TR_SETSYSTIME  = (CMD_NONSTD+2),  /* Set the system time */
    TR_READENTROPY = (CMD_NONSTD+3)
};

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
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DEVICES_TIMER_H */
