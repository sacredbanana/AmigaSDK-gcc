/*************************************************************************
 ** 68040.library                                                	**
 **                                                                     **
 ** CPU driver library for the 68040					**
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
 ** $VER: 40.2 (31.10.99) © THOR                       			**
 *************************************************************************/

#ifndef LIBRARIES_68040_H
#define LIBRARIES_68040_H

/* There's really nothing in this library base you need to care about */

struct MC68040Base {
        struct Library  dllib_Library;
        /* more below this point */
};

#define MC68040_NAME "68040.library"

/* Bit definitions for the FPUControl call, exception disable */

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

#endif
