VERSION		EQU	1
REVISION	EQU	11
DATE	MACRO
		dc.b	'3.10.02'
	ENDM
VERS	MACRO
		dc.b	'bootmouse 1.11'
	ENDM
VSTRING	MACRO
		dc.b	'bootmouse 1.11 (3.10.02) © 2002 by Chris Hodges',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: bootmouse 1.11 (3.10.02) © 2002 by Chris Hodges',0
	ENDM
