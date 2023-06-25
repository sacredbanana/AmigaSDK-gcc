#ifndef LIBRARIES_TRANSLATOR_H
#define LIBRARIES_TRANSLATOR_H

/*
**    $VER: translator.h 54.16 (22.08.2022)
**
**    Useful definitions for translator.library
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        Joseph Katz/Mark Barton.  All rights reserved.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

/*    Translator error return codes    */

#define TR_NotUsed  -1  /* This is an oft used system rc */
#define TR_NoMem    -2  /* Can't allocate memory         */
#define TR_MakeBad  -4  /* Error in MakeLibrary call     */

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

#endif /* LIBRARIES_TRANSLATOR_H */
