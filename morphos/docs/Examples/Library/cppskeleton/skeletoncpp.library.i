VERSION		EQU	0
REVISION	EQU	1
DATE	MACRO
		dc.b	'26.01.05'
	ENDM
VERS	MACRO
		dc.b	'skeletoncpp.library 0.1'
	ENDM
VSTRING	MACRO
		dc.b	'skeletoncpp.library 0.1 (26.01.05) � 2005 by Sigbj�rn Skj�ret, written by Ralph Schmidt and Sigbj�rn Skj�ret',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeletoncpp.library 0.1 (26.01.05) � 2005 by Sigbj�rn Skj�ret, written by Ralph Schmidt and Sigbj�rn Skj�ret',0
	ENDM
