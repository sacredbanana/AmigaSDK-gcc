VERSION		EQU	0
REVISION	EQU	1
DATE	MACRO
		dc.b	'08.06.06'
	ENDM
VERS	MACRO
		dc.b	'skeletonnix.library 0.1'
	ENDM
VSTRING	MACRO
		dc.b	'skeletonnix.library 0.1 (08.06.06) � 2002-2006 by Sigbj�rn Skj�ret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbj�rn Skj�ret',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeletonnix.library 0.1 (08.06.06) � 2002-2006 by Sigbj�rn Skj�ret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbj�rn Skj�ret',0
	ENDM
