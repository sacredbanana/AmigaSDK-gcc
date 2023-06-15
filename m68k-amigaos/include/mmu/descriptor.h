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
 ** Definition of the abstract data descriptor				**
 **									**
 ** $VER: 42.1 (08.04.2001)						**
 *************************************************************************/

#ifndef MMU_DESCRIPTOR_H
#define MMU_DESCRIPTOR_H

/**
 ** This structure describes a MMU descriptor abstractly. This structure
 ** must be passed to GetIndirect, and will be filled in by the library
 ** there is currently no other use for this structure.
 ** Especially, do not interpret undocumented fields.
 **/

struct AbstractDescriptor {
	ULONG		atd_Pointer;		/* logical address */
	ULONG		atd_Properties;		/* MMU properties */

/** 
 ** The next fields are filled in, but currently intentionally undocumented.
 ** However, they MUST be allocated.
 **/

	UWORD		atd_LowerLimit;
	UWORD		atd_UpperLimit;
	UBYTE		atd_ThisType;
	UBYTE		atd_NextType;
	UWORD		atd_reserved;
};

/** 
 ** About the properties: Only a minor subset is supported here.
 ** Check the documenation mmu.doc for details what you may expect here
 ** and what not.
 **/

/**
 ** This is returned if BuildIndirect() failed:
 **/

#define BAD_DESCRIPTOR	3

#endif
