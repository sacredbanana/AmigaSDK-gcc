#ifndef PRAGMAS_TIMESYNC_PRAGMAS_H
#define PRAGMAS_TIMESYNC_PRAGMAS_H

/*
**    $VER: timesync_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_TIMESYNC_PROTOS_H
#include <clib/timesync_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(TimesyncBase,0x01e,RemoteSyncA(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall TimesyncBase RemoteSyncA            01e 801
#endif
#ifdef __STORM__
#pragma tagcall(TimesyncBase,0x01e,RemoteSync(a0))
#endif
#ifdef __SASC_60
#pragma  tagcall TimesyncBase RemoteSync             01e 801
#endif

#endif /*  PRAGMAS_TIMESYNC_PRAGMAS_H */
