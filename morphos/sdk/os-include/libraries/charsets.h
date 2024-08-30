#ifndef LIBRARIES_CHARSETS_H
#define LIBRARIES_CHARSETS_H

/*
 * charsets.library include
 *
 * Copyright ? 2009-2012 The MorphOS Development Team, All Rights Reserved.
 */

#include <utility/tagitem.h>

/* Typedefs */

#ifndef UTF16_TYPEDEF
#define UTF16_TYPEDEF
typedef unsigned short UTF16;
#endif

/* Flags for GetCharsetNumber() */

#define CSF_IANA_NAME     (1 << 0)
#define CSF_IANA_MIMENAME (1 << 1)
#define CSF_IANA_ALIAS    (1 << 2)

/* Some IANA MIBenum numbers */

#define MIBENUM_INVALID         0
#define MIBENUM_US_ASCII        3
#define MIBENUM_ISO_8859_1      4
#define MIBENUM_ISO_8859_2      5
#define MIBENUM_ISO_8859_3      6
#define MIBENUM_ISO_8859_4      7
#define MIBENUM_ISO_8859_5      8
#define MIBENUM_ISO_8859_6      9
#define MIBENUM_ISO_8859_7      10
#define MIBENUM_ISO_8859_8      11
#define MIBENUM_ISO_8859_9      12
#define MIBENUM_ISO_8859_10     13
#define MIBENUM_UTF_8           106
#define MIBENUM_ISO_8859_13     109
#define MIBENUM_ISO_8859_14     110
#define MIBENUM_ISO_8859_15     111
#define MIBENUM_ISO_8859_16     112
#define MIBENUM_ISO_10646_UCS_2 1000
#define MIBENUM_ISO_10646_UCS_4 1001
#define MIBENUM_UTF_16BE        1013
#define MIBENUM_UTF_16LE        1014
#define MIBENUM_UTF_16          1015
#define MIBENUM_UTF_32          1017
#define MIBENUM_UTF_32BE        1018
#define MIBENUM_UTF_32LE        1019
#define MIBENUM_KOI8_R          2084
#define MIBENUM_AMIGA_1251      2104
#define MIBENUM_WINDOWS_1250    2250
#define MIBENUM_WINDOWS_1251    2251
#define MIBENUM_WINDOWS_1252    2252
#define MIBENUM_TIS_620         2259


/* Nonstandard encodings (not emumerated by IANA). */

#define MIBENUM_AMIGAPL         5000


/* For ConvertTagList() use. */

#define MIBENUM_SYSTEM          0xFFFFFFFF


/* Tags for ConvertTagList() */

#define CST_GetDestBytes         (TAG_USER + 1)
#define CST_GetUnterminatedBytes (TAG_USER + 2)
#define CST_DoNotTerminate       (TAG_USER + 3)
#define CST_GetDestEncoding      (TAG_USER + 4)


/* Attributes and methods of "charsets.list" BOOPSI class. */

#define CLSM_NextCharsetName    (TAG_USER + 256)
#define CLSM_NextCharsetNumber  (TAG_USER + 257)

#define CLSA_NameTable          (TAG_USER + 272)  /* [..G], (CONST_STRPTR*) */
#define CLSA_NumberTable        (TAG_USER + 273)  /* [..G], (LONG*) */
#define CLSA_NameCount          (TAG_USER + 274)  /* [..G], (LONG) */
#define CLSA_NumberCount        (TAG_USER + 275)  /* [..G], (LONG) */
#define CLSA_Aliases            (TAG_USER + 276)  /* [I..], (BOOL) */
#define CLSA_MimePreferred      (TAG_USER + 277)  /* [I..], (BOOL) */
#define CLSA_NonStandard        (TAG_USER + 278)  /* [I..], (BOOL) */

#endif /* LIBRARIES_CHARSETS_H */
