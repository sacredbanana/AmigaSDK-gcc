VERSION		EQU	0
REVISION	EQU	3
DATE	MACRO
		dc.b	'13.04.06'
	ENDM
VERS	MACRO
		dc.b	'skeletonrel.library 0.3'
	ENDM
VSTRING	MACRO
		dc.b	'skeletonrel.library 0.3 (13.04.06) � 2002-2006 by Sigbj�rn Skj�ret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbj�rn Skj�ret',13,10,0
	ENDM
VERSTAG	MACRO
		dc.b	0,'$VER: skeletonrel.library 0.3 (13.04.06) � 2002-2006 by Sigbj�rn Skj�ret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbj�rn Skj�ret',0
	ENDM
