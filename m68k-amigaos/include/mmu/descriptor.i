        IFND MMU_DESCRIPTOR_I
MMU_DESCRIPTOR_I   SET     1
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
;** Definition of the abstract data descriptor				**
;**									**
;** $VER: 42.1 (08.04.2001)						**
;*************************************************************************

	IFND EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC ; EXEC_TYPES_I

;**
;** This structure describes a MMU descriptor abstractly. This structure
;** must be passed to GetIndirect, and will be filled in by the library
;** there is currently no other use for this structure.
;** Especially, do not interpret undocumented fields.
;**

	STRUCTURE AbstractDescriptor,0
		ULONG		atd_Pointer		;* logical address *
		ULONG		atd_Properties		;* MMU properties *

;** 
;** The next fields are filled in, but currently intentionally undocumented.
;** However, they MUST be allocated.
;**

		UWORD		atd_LowerLimit
		UWORD		atd_UpperLimit
		UBYTE		atd_ThisType
		UBYTE		atd_NextType
		UWORD		atd_reserved
	LABEL atd_SIZE

;**
;** About the properties: Only a minor subset is supported here.
;** Check the documenation mmu.doc for details what you may expect here
;** and what not.
;**

;**
;** This is returned if BuildIndirect() failed:
;**

BAD_DESCRIPTOR	EQU	3

	ENDC		;MMU_DESCRIPTOR_I
