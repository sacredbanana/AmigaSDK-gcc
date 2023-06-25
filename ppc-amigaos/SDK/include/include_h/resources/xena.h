#ifndef RESOURCES_XENA_H
#define RESOURCES_XENA_H
/*
**    $VER: xena.h 54.16 (22.08.2022)
**
**    Unit number definitions for "xena.resource"
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

/****************************************************************************/

/*
 * Unit number definitions. Ownership of a resource grants low-level
 * bit access to the hardware registers. You are still obligated to follow
 * the rules for shared access of the interrupt system.
 * (see exec.library/SetIntVector)
 */
#define XR_XTAGPORT  0 /* XMOS JTAG interface, including
                             RESET, TRST, and DEBUG lines */
#define XR_DATABUS   1 /* High speed xena port P16A to CPU localbus,
									including LB_ALE, LB_OE# LB_WE# and LB_CS2# */
#define XR_INTERRUPT 2 /* From XCore1 P1F to CPU GPIO4/IRQ */
#define XR_LONELYBIT 3 /* The unassigned "extra" from XCore0 P1L to PLD XSPARE */


#define XENANAME "xena.resource"

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

#endif /* RESOURCES_XENA_H */
