;*************************************************************************
;** 680x0.library                                                	**
;**                                                                     **
;** CPU driver base library	            				**
;**                                                                     **
;** © 1999 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** Definition of the library, and structures                           **
;**									**
;** $VER: 40.2 (31.10.99) © THOR                       			**
;*************************************************************************

        IFND LIBRARIES_680X0_I

LIBRARIES_680X0_I SET 1

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC ; EXEC_TYPES_I

        IFND EXEC_LIBRARIES_I
        INCLUDE "exec/libraries.i"
        ENDC ; EXEC_LIBRARIES_I

	IFND MMU_MMUBASE_I
	INCLUDE "mmu/mmubase.i"
	ENDC ; MMU_MMUBASE_I

        ;* There's really nothing in this library base you need to care about *

        STRUCTURE	MC680X0Base,LIB_SIZE
        LABEL		dllib_SIZE


MC680X0NAME        	MACRO
                        DC.B '680x0.library',0
                        ENDM


;* Bit definitions for the SetFPUExceptions call, exception disable

	BITDEF FPUCtrl,BSUN,0L		;* disable branch or set on unordered
	BITDEF FPUCtrl,INEX,1L		;* disable inexact result exception
	BITDEF FPUCtrl,DIVZ,2L		;* disable divide by zero exception
	BITDEF FPUCtrl,UNFL,3L		;* disable underflow exception
	BITDEF FPUCtrl,OVFL,4L		;* disable overflow exception
	BITDEF FPUCtrl,SNAN,5L		;* disable signalling NAN exception
	BITDEF FPUCtrl,OPERR,6L		;* disable operand error exception

	CPUTYPE_68000	equ     '0'	;* a plain 68000
	CPUTYPE_68010	equ	'1'	;* a 68010
	CPUTYPE_68020	equ	'2'	;* a 68020
	CPUTYPE_68030	equ	'3'	;* a 68030
	CPUTYPE_68040	equ	'4'	;* a 68040
	CPUTYPE_68060	equ	'6'	;* a 68060

	FPUTYPE_NONE	equ	0	;* no FPU available
	FPUTYPE_68881	equ	'1'	;* the 68881 external FPU 
	FPUTYPE_68882	equ	'2'	;* the advanced edition of this chip
	FPUTYPE_68040	equ	'4'	;* the 68040 buildin FPU
	FPUTYPE_68060	equ	'6'	;* the 68060 buildin FPU	

        ENDC    ;LIBRARIES_680X0_I
