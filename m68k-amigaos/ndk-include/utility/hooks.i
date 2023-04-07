	IFND UTILITY_HOOKS_I
UTILITY_HOOKS_I SET 1
**
**	$VER: hooks.i 47.1 (3.8.2019)
**
**	Callback hooks
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND EXEC_NODES_I
    INCLUDE "exec/nodes.i"
    ENDC

;---------------------------------------------------------------------------

; Hook conventions
;	A0 - pointer to hook itself
;	A1 - pointer to parameter packet ("message")
;	A2 - Hook specific address data ("object," e.g, gadget )

   STRUCTURE HOOK,MLN_SIZE
	APTR h_Entry		; assembler entry point
	APTR h_SubEntry		; optional HLL entry point
	APTR h_Data		; owner specific
   LABEL h_SIZEOF


;---------------------------------------------------------------------------

	ENDC	; UTILITY_HOOKS_I
