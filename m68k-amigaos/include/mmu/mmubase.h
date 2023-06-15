/*************************************************************************
 ** mmu.library                                                         **
 **                                                                     **
 ** a system library for arbitration and control of the MC68K MMUs      **
 **                                                                     **
 ** © 1998 THOR-Software, Thomas Richter                                **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** Definition of the library base                                      **
 ** and of the MMU configurations                                       **
 **									**
 ** $VER: 42.1 (08.04.2001)						**
 *************************************************************************/

#ifndef MMU_MMUBASE_H
#define MMU_MMUBASE_H

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/* There's really nothing in this library base you need to care about */

struct MMUBase {
        struct Library  mulib_Library;
        /* more below this point */
};

#define MMU_NAME "mmu.library"

/* definitions of the known MMU types */


#define MUTYPE_NONE             0       
/* no MMU detected */

#define MUTYPE_68851            '2'
/* 68020/68851 MMU */

#define MUTYPE_68030            '3'
/* 68030 MMU */

#define MUTYPE_68040            '4'
/* 68040 MMU */

#define MUTYPE_68060            '6'
/* 68060 MMU */

#endif
