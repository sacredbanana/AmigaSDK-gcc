	IFND DOS_STDIO_I
DOS_STDIO_I	EQU	1
**
**	$VER: stdio.i 47.1 (29.7.2019)
**
**	ANSI-like stdio defines for dos buffered I/O
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**


* types for SetVBuf()
BUF_LINE	EQU	0	; flush on \n, etc
BUF_FULL	EQU	1	; never flush except when needed
BUF_NONE	EQU	2	; no buffering

* EOF return value
ENDSTREAMCH	EQU	-1

	ENDC	; DOS_STDIO_I

