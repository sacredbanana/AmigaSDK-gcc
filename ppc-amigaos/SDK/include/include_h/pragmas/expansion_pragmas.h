#ifndef PRAGMAS_EXPANSION_PRAGMAS_H
#define PRAGMAS_EXPANSION_PRAGMAS_H

/*
**    $VER: expansion_pragmas.h 53.29 (10.8.2015)
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

#ifndef CLIB_EXPANSION_PROTOS_H
#include <clib/expansion_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(ExpansionBase,0x01e,AddConfigDev(a0))
#pragma amicall(ExpansionBase,0x024,AddBootNode(d0,d1,a0,a1))
#pragma amicall(ExpansionBase,0x02a,AllocBoardMem(d0))
#pragma amicall(ExpansionBase,0x030,AllocConfigDev())
#pragma amicall(ExpansionBase,0x036,AllocExpansionMem(d0,d1))
#pragma amicall(ExpansionBase,0x03c,ConfigBoard(a0,a1))
#pragma amicall(ExpansionBase,0x042,ConfigChain(a0))
#pragma amicall(ExpansionBase,0x048,FindConfigDev(a0,d0,d1))
#pragma amicall(ExpansionBase,0x04e,FreeBoardMem(d0,d1))
#pragma amicall(ExpansionBase,0x054,FreeConfigDev(a0))
#pragma amicall(ExpansionBase,0x05a,FreeExpansionMem(d0,d1))
#pragma amicall(ExpansionBase,0x060,ReadExpansionByte(a0,d0))
#pragma amicall(ExpansionBase,0x066,ReadExpansionRom(a0,a1))
#pragma amicall(ExpansionBase,0x06c,RemConfigDev(a0))
#pragma amicall(ExpansionBase,0x072,WriteExpansionByte(a0,d0,d1))
#pragma amicall(ExpansionBase,0x078,ObtainConfigBinding())
#pragma amicall(ExpansionBase,0x07e,ReleaseConfigBinding())
#pragma amicall(ExpansionBase,0x084,SetCurrentBinding(a0,d0))
#pragma amicall(ExpansionBase,0x08a,GetCurrentBinding(a0,d0))
#pragma amicall(ExpansionBase,0x090,MakeDosNode(a0))
#pragma amicall(ExpansionBase,0x096,AddDosNode(d0,d1,a0))
#pragma amicall(ExpansionBase,0x0a8,GetMachineInfo(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall ExpansionBase AddConfigDev           01e 801
#pragma  libcall ExpansionBase AddBootNode            024 981004
#pragma  libcall ExpansionBase AllocBoardMem          02a 001
#pragma  libcall ExpansionBase AllocConfigDev         030 00
#pragma  libcall ExpansionBase AllocExpansionMem      036 1002
#pragma  libcall ExpansionBase ConfigBoard            03c 9802
#pragma  libcall ExpansionBase ConfigChain            042 801
#pragma  libcall ExpansionBase FindConfigDev          048 10803
#pragma  libcall ExpansionBase FreeBoardMem           04e 1002
#pragma  libcall ExpansionBase FreeConfigDev          054 801
#pragma  libcall ExpansionBase FreeExpansionMem       05a 1002
#pragma  libcall ExpansionBase ReadExpansionByte      060 0802
#pragma  libcall ExpansionBase ReadExpansionRom       066 9802
#pragma  libcall ExpansionBase RemConfigDev           06c 801
#pragma  libcall ExpansionBase WriteExpansionByte     072 10803
#pragma  libcall ExpansionBase ObtainConfigBinding    078 00
#pragma  libcall ExpansionBase ReleaseConfigBinding   07e 00
#pragma  libcall ExpansionBase SetCurrentBinding      084 0802
#pragma  libcall ExpansionBase GetCurrentBinding      08a 0802
#pragma  libcall ExpansionBase MakeDosNode            090 801
#pragma  libcall ExpansionBase AddDosNode             096 81003
#pragma  libcall ExpansionBase GetMachineInfo         0a8 801
#endif
#ifdef __STORM__
#pragma tagcall(ExpansionBase,0x0a8,GetMachineInfoTags(a0))
#endif
#ifdef __SASC_60
#pragma  tagcall ExpansionBase GetMachineInfoTags     0a8 801
#endif

#endif /* PRAGMAS_EXPANSION_PRAGMAS_H */
