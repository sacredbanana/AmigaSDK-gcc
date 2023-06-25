#ifndef RESOURCES_BOOTSD_H
#define RESOURCES_BOOTSD_H
/*
**    $VER: bootsd.h 54.16 (22.08.2022)
**
**    Unit number definitions for "qoriq.resource"
**
**    Copyright (c) 2012 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
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

/***************************************************************************/

#define BOOTSDNAME "bootsd.resource"

/***************************************************************************/

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

#endif /* RESOURCES_BOOTSD_H */
