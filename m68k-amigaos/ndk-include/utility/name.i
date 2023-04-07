	IFND UTILITY_NAME_I
UTILITY_NAME_I	EQU	1
**
**	$VER: name.i 47.1 (3.8.2019)
**
**	Namespace definitions
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC

;---------------------------------------------------------------------------

* The named object structure */
*
   STRUCTURE NamedObject,0
	APTR	no_Object	; Your pointer, for whatever you want
   LABEL NamedObject_End

ANO_NameSpace	equ	4000	; Tag to define namespace
ANO_UserSpace	equ	4001	; tag to define userspace
ANO_Priority	equ	4002	; tag to define priority
ANO_Flags	equ	4003	; tag to define flags

* flags for tag ANO_Flags

	BITDEF	NS,NODUPS,0	; defaults to allowing duplicates
	BITDEF	NS,CASE,1	; so it defaults to caseless

;---------------------------------------------------------------------------

	ENDC	; UTILITY_NAME_I
