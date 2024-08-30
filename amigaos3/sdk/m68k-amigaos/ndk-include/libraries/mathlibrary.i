	IFND	LIBRARIES_MATHLIBRARY_I
LIBRARIES_MATHLIBRARY_I	SET	1
**
**	$VER: mathlibrary.i 47.1 (29.7.2019)
**
**	Data structure returned by OpenLibrary of:
**	mathieeedoubbas.library,mathieeedoubtrans.library
**	mathieeesingbas.library,mathieeesingtrans.library
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	ifnd EXEC_LIBRARIES_I
	include "exec/libraries.i"
	endc

	STRUCTURE MathIEEEBase,0
		STRUCT	MathIEEEBase_LibNode,LIB_SIZE
		STRUCT	MathIEEEBase_reserved,18
		APTR	MathIEEEBase_TaskOpenLib	; hook
		APTR	MathIEEEBase_TaskCloseLib	; hook
*	This structure may be extended in the future */
	LABEL	MathIEEEBase_SIZE

;	Math resources may need to know when a program opens or closes this
;	library. The functions TaskOpenLib and TaskCloseLib are called when
;	a task opens or closes this library.

	ENDC	; LIBRARIES_MATHLIBRARY_I
