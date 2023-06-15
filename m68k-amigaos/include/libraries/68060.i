;*************************************************************************
;** 68060.library                                                	**
;**                                                                     **
;** the CPU driver for the 68060            				**
;**                                                                     **
;** © 2001 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** Definition of the library, and structures                           **
;**									**
;** $VER: 40.1 (23.03.2001) © THOR                       		**
;*************************************************************************

        IFND LIBRARIES_68060_I

LIBRARIES_68060_I SET 1

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC ; EXEC_TYPES_I

        IFND EXEC_LIBRARIES_I
        INCLUDE "exec/libraries.i"
        ENDC ; EXEC_LIBRARIES_I

        ;* There's really nothing in this library base you need to care about *

        STRUCTURE	MC68060Base,LIB_SIZE
        LABEL		dllib_SIZE


MC68060NAME        	MACRO
                        DC.B '68060.library',0
                        ENDM


;* Bit definitions for the FPUControl call, exception disable

	BITDEF FPUCtrl,BSUN,0L		;* disable branch or set on unordered
	BITDEF FPUCtrl,INEX,1L		;* disable inexact result exception
	BITDEF FPUCtrl,DIVZ,2L		;* disable divide by zero exception
	BITDEF FPUCtrl,UNFL,3L		;* disable underflow exception
	BITDEF FPUCtrl,OVFL,4L		;* disable overflow exception
	BITDEF FPUCtrl,SNAN,5L		;* disable signalling NAN exception
	BITDEF FPUCtrl,OPERR,6L		;* disable operand error exception

        ENDC    ;LIBRARIES_68060_I
