#ifndef DOS_DOSASL_H
#define DOS_DOSASL_H
/*
**    $VER: dosasl.h  54.100 (07.09.2020)
**
**    Pattern-matching structure definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/
                      
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
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

/*******************************************************************************
 * WARNING:   The V50 AnchorPath structure has moved to dos/anchorpath.h
 *
 * You MUST now allocate these with AllocDosObject() from DOS 50.76+ 
 *           MatchXXX() will simply not work if you do not heed this warning.
 ******************************************************************************/

#ifndef DOS_ANCHORPATH_H
struct AnchorPath;
#endif /* DOS_ANCHORPATH_H */

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

#endif /* DOS_DOSASL_H */
