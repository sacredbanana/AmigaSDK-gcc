#ifndef DOS_DOSHUNKS_H
#define DOS_DOSHUNKS_H

/*
	dos hunk definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define HUNK_UNIT          999
#define HUNK_NAME          1000
#define HUNK_CODE          1001
#define HUNK_DATA          1002
#define HUNK_BSS           1003

#define HUNK_RELOC32       1004
#define HUNK_ABSRELOC32    HUNK_RELOC32

#define HUNK_RELOC16       1005
#define HUNK_RELRELOC16    HUNK_RELOC16

#define HUNK_RELOC8        1006
#define HUNK_RELRELOC8     HUNK_RELOC8

#define HUNK_EXT           1007
#define HUNK_SYMBOL        1008
#define HUNK_DEBUG         1009
#define HUNK_END           1010
#define HUNK_HEADER        1011

#define HUNK_OVERLAY       1013
#define HUNK_BREAK         1014

#define HUNK_DREL32        1015
#define HUNK_DREL16        1016
#define HUNK_DREL8         1017

#define HUNK_LIB           1018
#define HUNK_INDEX         1019

#define HUNK_RELOC32SHORT  1020

#define HUNK_RELRELOC32    1021
#define HUNK_ABSRELOC16    1022


#define HUNKB_ADVISORY  29
#define HUNKB_CHIP      30
#define HUNKB_FAST      31

#define HUNKF_ADVISORY  (1<<HUNKB_ADVISORY)
#define HUNKF_CHIP      (1<<HUNKB_CHIP)
#define HUNKF_FAST      (1<<HUNKB_FAST)


#define EXT_SYMB       0
#define EXT_DEF        1
#define EXT_ABS        2
#define EXT_RES        3

#define EXT_REF32      129
#define EXT_ABSREF32   EXT_REF32

#define EXT_COMMON     130
#define EXT_ABSCOMMON  EXT_COMMON

#define EXT_REF16      131
#define EXT_RELREF16   EXT_REF16

#define EXT_REF8       132
#define EXT_RELREF8    EXT_REF8

#define EXT_DEXT32     133
#define EXT_DEXT16     134
#define EXT_DEXT8      135

#define EXT_RELREF32   136
#define EXT_RELCOMMON  137

#define EXT_ABSREF16   138

#define EXT_ABSREF8    139


#endif /* DOS_DOSHUNKS_H */
