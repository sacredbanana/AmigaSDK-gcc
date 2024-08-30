VERSION		EQU	0
REVISION	EQU	1
DATE	MACRO
		dc.b	'10.4.02'
	ENDM
VERS	MACRO
		dc.b	'skeleton.library 0.1'
	ENDM
VSTRING	MACRO
		dc.b	'skeleton.library 0.1 (10.4.02) © 2000 by Ralph Schmidt, written by Ralph Schmidt',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeleton.library 0.1 (10.4.02) © 2000 by Ralph Schmidt, written by Ralph Schmidt',0
	ENDM
