#ifndef BOOTMOUSE_CLASS_H
#define BOOTMOUSE_CLASS_H

/*
 *----------------------------------------------------------------------------
 *                         Includes for Bootmouse class
 *----------------------------------------------------------------------------
 *                   By Chris Hodges <hodges@in.tum.de>
 *
 * History
 *
 *  11-03-2002  - Initial
 *
 */

#include <devices/newmouse.h>
#include <exec/types.h>
#include <exec/lists.h>
#include <exec/alerts.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <exec/interrupts.h>
#include <exec/semaphores.h>
#include <exec/execbase.h>
#include <exec/devices.h>
#include <exec/io.h>
#include <exec/ports.h>
#include <exec/errors.h>
#include <exec/resident.h>
#include <exec/initializers.h>

#include <devices/timer.h>
#include <devices/input.h>
#include <utility/utility.h>
#include <dos/dos.h>
#include <intuition/intuition.h>
#include <libraries/mui.h>
#include <libraries/gadtools.h>
#include <libraries/asl.h>

#include <devices/usb.h>
#include <devices/usbhardware.h>
#include <devices/usb_hid.h>
#include <libraries/usbclass.h>

#include <clib/alib_protos.h>

#include <string.h>
#include <stddef.h>
#include <stdio.h>

#if defined(__GNUC__) && !defined(__aligned)
#define __aligned __attribute__((__aligned__(4)))
#endif
#define inline __inline

#include "declgate.h"
#include "bootmouse.h"

/* Protos
*/

struct NepClassHid * nAllocHid(void);
void nFreeHid(struct NepClassHid *nch);

LONG nOpenBindingCfgWindow(struct NepHidBase *nh, struct NepClassHid *nch);

void nGUITaskCleanup(struct NepClassHid *nch);

void DECLFUNC_0(nHidTask);
void DECLFUNC_0(nGUITask);

#ifndef __GNUC__

#include <pragmas/dos_pragmas.h>
#include <pragmas/icon_pragmas.h>
#include <pragmas/graphics_pragmas.h>
#include <pragmas/datatypes_pragmas.h>
#include <pragmas/commodities_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/gadtools_pragmas.h>
#include <pragmas/utility_pragmas.h>
#include <pragmas/asl_pragmas.h>
//#include <pragma/muimaster_lib.h>
#include <pragmas/muimaster_pragmas.h>

#endif

#endif /* BOOTMOUSE_CLASS_H */
