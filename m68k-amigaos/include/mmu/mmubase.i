        IFND MMU_MMUBASE_I
MMU_MMUBASE_I    SET 1
;*************************************************************************
;** mmu.library                                                         **
;**                                                                     **
;** a system library for arbitration and control of the MC68K MMUs      **
;**                                                                     **
;** © 1998 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** Definition of the library base                                      **
;** and of the MMU configurations                                       **
;**									**
;** $VER: 42.1 (08.04.2001)						**
;*************************************************************************

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC ; EXEC_TYPES_I

        IFND EXEC_LIBRARIES_I
        INCLUDE "exec/libraries.i"
        ENDC ; EXEC_LIBRARIES_I

;* There's really nothing in this library base you need to care about *

        STRUCTURE  MMUBase,LIB_SIZE
        LABEL   mulib_SIZE


MMUNAME         MACRO
                DC.B  'mmu.library',0
                ENDM

;* definitions of the known MMU types *


MUTYPE_NONE     equ     0
;* no MMU detected *

MUTYPE_68851    equ     '2'
;* 68020/68851 MMU *

MUTYPE_68030    equ     '3'
;* 68030 MMU *

MUTYPE_68040    equ     '4'
;* 68040 MMU *

MUTYPE_68060    equ     '6'
;* 68060 MMU *

        ENDC    ; MMU_MMUBASE_I
