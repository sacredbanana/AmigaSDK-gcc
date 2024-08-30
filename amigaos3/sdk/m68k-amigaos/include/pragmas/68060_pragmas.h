#ifndef _INCLUDE_PRAGMA_68060_LIB_H
#define _INCLUDE_PRAGMA_68060_LIB_H

#ifndef CLIB_68060_PROTOS_H
#include <clib/68060_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(MC68060Base,0x0DE,FPUControl(d0,d1))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall MC68060Base FPUControl           0DE 1002
#endif

#endif	/*  _INCLUDE_PRAGMA_68060_LIB_H  */
