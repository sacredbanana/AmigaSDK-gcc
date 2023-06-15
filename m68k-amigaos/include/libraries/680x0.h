/*************************************************************************
 ** 680x0.library                                                	**
 **                                                                     **
 ** CPU driver library base library					**
 **                                                                     **
 ** © 1999 THOR-Software, Thomas Richter                                **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** Definition of the library, and structures                           **
 **									**
 ** $VER: 40.2 (28.8.1999) © THOR                       		**
 *************************************************************************/

#ifndef LIBRARIES_680X0_H
#define LIBRARIES_680X0_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef MMU_MMUBASE_H
#include <mmu/mmubase.h>
#endif

/* There's really nothing in this library base you need to care about */

struct MC680X0Base {
        struct Library  dllib_Library;
        /* more below this point */
};

#define MC680X0_NAME "680x0.library"

/* Bit definitions for the SetFPUExceptions call, exception disable */

#define FPUCtrlB_BSUN	0L	/* disable branch or set on unordered */
#define FPUCtrlB_INEX	1L	/* disable inexact result exception */
#define FPUCtrlB_DIVZ	2L	/* disable divide by zero exception */
#define FPUCtrlB_UNFL	3L	/* disable underflow exception */
#define FPUCtrlB_OVFL	4L	/* disable overflow exception */
#define FPUCtrlB_SNAN	5L	/* disable signalling NAN exception */
#define FPUCtrlB_OPERR	6L	/* disable operand error exception */

#define FPUCtrlF_BSUN	(1L<<0L)
#define FPUCtrlF_INEX	(1L<<1L)
#define FPUCtrlF_DIVZ	(1L<<2L)
#define FPUCtrlF_UNFL	(1L<<3L)
#define FPUCtrlF_OVFL	(1L<<4L)
#define FPUCtrlF_SNAN	(1L<<5L)
#define FPUCtrlF_OPERR	(1L<<6L)

/* CPU and FPU definitions. */

#define	CPUTYPE_68000	'0'	/* a plain 68000*/
#define	CPUTYPE_68010	'1'	/* a 68010	*/
#define	CPUTYPE_68020	'2'	/* a 68020	*/
#define	CPUTYPE_68030	'3'	/* a 68030	*/
#define	CPUTYPE_68040	'4'	/* a 68040	*/
#define	CPUTYPE_68060	'6'	/* a 68060	*/

#define FPUTYPE_NONE	0	/* no FPU available */
#define	FPUTYPE_68881	'1'	/* the 68881 external FPU 	*/
#define	FPUTYPE_68882	'2'	/* the advanced edition of this chip */
#define	FPUTYPE_68040	'4'	/* the 68040 buildin FPU	*/
#define	FPUTYPE_68060	'6'	/* the 68060 buildin FPU	*/

#endif
