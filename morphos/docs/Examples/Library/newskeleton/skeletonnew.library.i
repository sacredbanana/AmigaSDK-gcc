VERSION		EQU	0
REVISION	EQU	3
DATE	MACRO
		dc.b	'9.2.03'
	ENDM
VERS	MACRO
		dc.b	'skeletonnew.library 0.3'
	ENDM
VSTRING	MACRO
		dc.b	'skeletonnew.library 0.3 (9.2.03) © 2002-2003 by Ralph Schmidt, written by Ralph Schmidt',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeletonnew.library 0.3 (9.2.03) © 2002-2003 by Ralph Schmidt, written by Ralph Schmidt',0
	ENDM
