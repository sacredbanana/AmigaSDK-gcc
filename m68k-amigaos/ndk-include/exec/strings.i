	IFND	EXEC_STRINGS_I
EXEC_STRINGS_I	SET	1
**
**	$VER: strings.i 47.1 (28.6.2019)
**
**	Macros for defining old style CR/LF terminated string constants
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

*------ Terminal Control:

EOS	EQU 0
BELL	EQU 7
LF	EQU 10
CR	EQU 13
BS	EQU 8
DEL	EQU $7F
NL	EQU LF


*----------------------------------------------------------------
*
*   String Support Macros
*
*----------------------------------------------------------------

STRING	MACRO
	dc.b	\1
	dc.b	0
	CNOP	0,2
	ENDM


STRINGL MACRO
	dc.b	13,10
	dc.b	\1
	dc.b	0
	CNOP	0,2
	ENDM


STRINGR MACRO
	dc.b	\1
	dc.b	13,10,0
	CNOP	0,2
	ENDM


STRINGLR MACRO
	dc.b	13,10
	dc.b	\1
	dc.b	13,10,0
	CNOP	0,2
	ENDM

	ENDC	; EXEC_STRINGS_I
