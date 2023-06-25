#ifndef RESOURCES_MISC_H
#define RESOURCES_MISC_H
/*
**    $VER: misc.h 54.16 (22.08.2022)
**
**    Unit number definitions for "misc.resource"
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
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

/****************************************************************************/

/*
 * Unit number definitions.  Ownership of a resource grants low-level
 * bit access to the hardware registers.  You are still obligated to follow
 * the rules for shared access of the interrupt system (see
 * exec.library/SetIntVector or cia.resource as appropriate).
 */
#define MR_SERIALPORT   0 /* Amiga custom chip serial port registers
                             (SERDAT,SERDATR,SERPER,ADKCON, and interrupts) */
#define MR_SERIALBITS   1 /* Serial control bits (DTR,CTS, etc.) */
#define MR_PARALLELPORT 2 /* The 8 bit parallel data port
                             (CIAAPRA & CIAADDRA only!) */
#define MR_PARALLELBITS 3 /* All other parallel bits & interrupts
                             (BUSY,ACK,etc.) */

/*
 * Library vector offset definitions
 */
#define MR_ALLOCMISCRESOURCE (LIB_BASE)              /* - 6 */
#define MR_FREEMISCRESOURCE  (LIB_BASE-LIB_VECTSIZE) /* -12 */

#define MISCNAME "misc.resource"

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

#endif /* RESOURCES_MISC_H */
