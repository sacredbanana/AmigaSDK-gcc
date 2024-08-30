VERSION		EQU	0
REVISION	EQU	1
DATE	MACRO
		dc.b	'08.06.06'
	ENDM
VERS	MACRO
		dc.b	'skeletonnix.library 0.1'
	ENDM
VSTRING	MACRO
		dc.b	'skeletonnix.library 0.1 (08.06.06) © 2002-2006 by Sigbjørn Skjæret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbjørn Skjæret',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeletonnix.library 0.1 (08.06.06) © 2002-2006 by Sigbjørn Skjæret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbjørn Skjæret',0
	ENDM
