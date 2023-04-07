	IFND	DOS_DATETIME_I
DOS_DATETIME_I SET 1

**
**	$VER: datetime.i 47.27 (2.12.2021)
**
**	Date and time conversion for AmigaDOS
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND DOS_DOS_I
	INCLUDE "dos/dos.i"
	ENDC

* Data structures and constants used by the AmigaDOS functions
* StrtoDate() and DatetoStr(), first available in dos.library
* V36 (V1.4)

* String/Date & Time conversion
    STRUCTURE	DateTime,0
	STRUCT	dat_Stamp,ds_SIZEOF	; DOS DateStamp
	UBYTE	dat_Format		; controls appearance of dat_StrDate
	UBYTE	dat_Flags		; see flags below
	CPTR	dat_StrDay		; day of the week string (see LEN_DATSTRING below)
	CPTR	dat_StrDate		; date string (see LEN_DATSTRING below)
	CPTR	dat_StrTime		; time string (see LEN_DATSTRING below)
	LABEL	dat_SIZEOF

* The DateTime.dat_StrDay/dat_StrDate/dat_StrTime members must
* never point to string buffers shorter than this:
LEN_DATSTRING	EQU	16

*	Flags for dat_Flags
*
	BITDEF	DT,SUBST,0		; substitute Today, Tomorrow, etc.
	BITDEF	DT,FUTURE,1		; day of the week is in future
*
*	date format values
*
FORMAT_DOS	equ	0		; dd-mmm-yy
FORMAT_INT	equ	1		; yy-mm-dd
FORMAT_USA	equ	2		; mm-dd-yy
FORMAT_CDN	equ	3		; dd-mm-yy
FORMAT_DEF	equ	4		; default format for locale

* NOTE: dos.library supports only four built-in formats for
*       date and time conversion (FORMAT_DOS, FORMAT_INT, FORMAT_USA
*       and FORMAT_CDN). This is why FORMAT_MAX is set to FORMAT_CDN.
*       The use of FORMAT_DEF requires locale.library to be active,
*       otherwise dos.library will fall back onto using FORMAT_DOS
*       instead.
FORMAT_MAX	equ	FORMAT_CDN

	ENDC	; DOS_DATETIME_I
