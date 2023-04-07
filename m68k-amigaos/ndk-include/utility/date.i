	IFND UTILITY_DATE_I
UTILITY_DATE_I	SET	1
**
**	$VER: date.i 47.1 (3.8.2019)
**
**	Date conversion routines ClockData definition.
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

;---------------------------------------------------------------------------

   STRUCTURE CLOCKDATA,0
	UWORD	sec
	UWORD	min
	UWORD	hour
	UWORD	mday
	UWORD	month
	UWORD	year
	UWORD	wday
   LABEL CD_SIZE

;---------------------------------------------------------------------------

	ENDC	; UTILITY_DATE_I
