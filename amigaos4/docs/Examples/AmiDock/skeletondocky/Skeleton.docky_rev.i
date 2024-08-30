VERSION		EQU	53
REVISION	EQU	1

DATE	MACRO
		dc.b '23.9.2008'
		ENDM

VERS	MACRO
		dc.b 'Skeleton.docky 53.1'
		ENDM

VSTRING	MACRO
		dc.b 'Skeleton.docky 53.1 (23.9.2008)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: Skeleton.docky 53.1 (23.9.2008)',0
		ENDM
