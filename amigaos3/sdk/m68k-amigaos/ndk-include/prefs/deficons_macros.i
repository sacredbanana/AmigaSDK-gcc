	IFND DEFICONS_MACROS_I
DEFICONS_MACROS_I	SET	1
**
**      $VER: deficons_macros.i 47.1 (3.1.2020)
**
**      Macros for creating binary deficons
**	preferences
**
**      Copyright (C) 2020 Hyperion Entertainment CVBA.
**          Developed under license.
**


	; end a type definition,
	; also used to end a binary preference
	; file
ENDDEF			MACRO
			dc.b	0
			ENDM

	; create children and thus subtypes
	; of the recently created type created
DOWNLEVEL		MACRO
			dc.b	1
			ENDM

	; end the current list of children
	; and continue on the previous (higher)
	; level of the tree
ENDLEVEL		MACRO
			dc.b	2
			ENDM

	; define a name for the type. The icon
	; will then be taken from ENV:sys/def_XXXX.info
	; where XXXX is the name defined here.
NAME			MACRO
			dc.b	\1
			dc.b	0
			ENDM

	; the name is given by the icon associated to
	; this binary file.
NONAME			MACRO
			dc.b	'.'
			ENDM

	; checks against a template given by argument #3, of
	; length given by argument #2, at an offset
	; given by the first argument. The match
	; will be case-sensitive.
MATCH			MACRO
			dc.b	1
			dc.b	\1>>8
			dc.b	\1&$ff
			dc.b	\2
			dc.b	\3
			ENDM
			
	; same as above, but the match is case
	; insensitive.
MATCH_NOCASE		MACRO
			dc.b	1
			dc.b	(-\1)>>8
			dc.b	(-\1)&$ff
			dc.b	\2
			dc.b	\3
			ENDM

	; search a file for a template whose length is
	; given as first argument, and the pattern which
	; will be given as second argument. The search
	; will be case-sensitive.
SEARCH			MACRO
			dc.b	2
			dc.b	\1
			dc.b	\2
			ENDM

	; same as above, scans the file for a template,
	; but the match is case-insensitive.
SEARCH_NOCASE		MACRO
			dc.b	2
			dc.b	-\1
			dc.b	\2
			ENDM

	; scans the file for a template, but ignores spaces
	; or blanks when matching the template. The match
	; will be case-sensitive.
SEARCH_SKIPSPACES	MACRO
			dc.b	3
			dc.b	\1
			dc.b	\2
			ENDM

	; same as above, but the match will be case
	; sensitive.
SEARCH_SKIPSPACES_NOCASE	MACRO
			dc.b	3
			dc.b	-\1
			dc.b	\2
			ENDM

	; matches only if the file matches the given
	; file size. The file size is given as first
	; and only argument.
FILESIZE		MACRO
			dc.b	4
			dc.b	(\1>>24)&$ff
			dc.b	(\1>>16)&$ff
			dc.b	(\1>>8)&$ff
			dc.b	(\1>>0)&$ff
			ENDM

	; matches the file size against an AmigaDos
	; name pattern that will be processed through
	; ParsePatternNoCase(). All AmigaDos wildcards
	; are supported. The match is case-insensitive.
NAMEPATTERN		MACRO
			dc.b	5
			dc.b	\1,0
			ENDM

	; matches if the file protection attributes
	; match the file. The first argument is a mask
	; which contains 0 bits for all flags that shall
	; be ignored when performing the match. The
	; second argument are the protection bits itself.
	; Note that the 4 lowest order bits are inverted,
	; i.e. rwed bits are ACTIVE if they are ZERO.
PROTECTION		MACRO
			dc.b	6
			dc.b	(\1>>24)&$ff
			dc.b	(\1>>16)&$ff
			dc.b	(\1>>8)&$ff
			dc.b	(\1>>0)&$ff
			dc.b	(\2>>24)&$ff
			dc.b	(\2>>16)&$ff
			dc.b	(\2>>8)&$ff
			dc.b	(\2>>0)&$ff
			ENDM

	; defines an alternative, matches if either all
	; matching rules above, or all matching rules below
	; match.
ALTERNATIVELY		MACRO
			dc.b	7
			ENDM

	; matches if the file contains (presumingly) ISO-Latin-1
	; characters and no control characters. This is a quick
	; test and not an exhaustive scan of the entire file.
ISASCII			MACRO
			dc.b	8
			ENDM

	; Does not define an icon by itself, but only a rule
	; that is part of a higher-level tree that is used as
	; parts of other match rules.
MACROCLASS		MACRO
			dc.b	20
			ENDM

		ENDC
