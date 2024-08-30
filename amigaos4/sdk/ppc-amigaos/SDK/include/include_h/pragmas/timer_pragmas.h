#ifndef PRAGMAS_TIMER_PRAGMAS_H
#define PRAGMAS_TIMER_PRAGMAS_H

/*
**    $VER: timer_pragmas.h 54.16 (22.08.2022)
**
**    Direct ROM interface (pragma) definitions.
**
**    Copyright (C) 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*
 * NOTE: These 68k platform specific #pragma header files are unlikely to see
 *       further updates with the AmigaOS4 update and following development
 *       efforts. If you can, please switch to native PowerPC development.
 */
#ifdef __amigaos4__
#error Include <proto/> header files, not <pragmas/> header files in OS4.
#endif

#ifndef CLIB_TIMER_PROTOS_H
#include <clib/timer_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(TimerBase,0x02a,AddTime(a0,a1))
#pragma amicall(TimerBase,0x030,SubTime(a0,a1))
#pragma amicall(TimerBase,0x036,CmpTime(a0,a1))
#pragma amicall(TimerBase,0x03c,ReadEClock(a0))
#pragma amicall(TimerBase,0x042,GetSysTime(a0))
#pragma amicall(TimerBase,0x048,GetUpTime(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall TimerBase AddTime    02a 9802
#pragma  libcall TimerBase SubTime    030 9802
#pragma  libcall TimerBase CmpTime    036 9802
#pragma  libcall TimerBase ReadEClock 03c 801
#pragma  libcall TimerBase GetSysTime 042 801
#pragma  libcall TimerBase GetUpTime  048 801
#endif

#endif /* PRAGMAS_TIMER_PRAGMAS_H */
