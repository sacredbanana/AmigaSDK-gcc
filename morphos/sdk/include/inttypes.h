#ifndef _INTTYPES_H_
#define _INTTYPES_H_

#include <stdint.h>
#include <sys/cdefs.h>


#if !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

#define __PRI_8_LENGTH_MODIFIER__ "hh"
#define __PRI_16_LENGTH_MODIFIER__ "h"
#define __PRI_32_LENGTH_MODIFIER__ ""
#define __PRI_64_LENGTH_MODIFIER__ "ll"

#define PRId8 __PRI_8_LENGTH_MODIFIER__ "d"
#define PRIi8 __PRI_8_LENGTH_MODIFIER__ "i"
#define PRIo8 __PRI_8_LENGTH_MODIFIER__ "o"
#define PRIu8 __PRI_8_LENGTH_MODIFIER__ "u"
#define PRIx8 __PRI_8_LENGTH_MODIFIER__ "x"
#define PRIX8 __PRI_8_LENGTH_MODIFIER__ "X"

#define PRId16 __PRI_16_LENGTH_MODIFIER__ "d"
#define PRIi16 __PRI_16_LENGTH_MODIFIER__ "i"
#define PRIo16 __PRI_16_LENGTH_MODIFIER__ "o"
#define PRIu16 __PRI_16_LENGTH_MODIFIER__ "u"
#define PRIx16 __PRI_16_LENGTH_MODIFIER__ "x"
#define PRIX16 __PRI_16_LENGTH_MODIFIER__ "X"

#define PRId32 __PRI_32_LENGTH_MODIFIER__ "d"
#define PRIi32 __PRI_32_LENGTH_MODIFIER__ "i"
#define PRIo32 __PRI_32_LENGTH_MODIFIER__ "o"
#define PRIu32 __PRI_32_LENGTH_MODIFIER__ "u"
#define PRIx32 __PRI_32_LENGTH_MODIFIER__ "x"
#define PRIX32 __PRI_32_LENGTH_MODIFIER__ "X"

#define PRId64 __PRI_64_LENGTH_MODIFIER__ "d"
#define PRIi64 __PRI_64_LENGTH_MODIFIER__ "i"
#define PRIo64 __PRI_64_LENGTH_MODIFIER__ "o"
#define PRIu64 __PRI_64_LENGTH_MODIFIER__ "u"
#define PRIx64 __PRI_64_LENGTH_MODIFIER__ "x"
#define PRIX64 __PRI_64_LENGTH_MODIFIER__ "X"

#define PRIdLEAST8 PRId8
#define PRIiLEAST8 PRIi8
#define PRIoLEAST8 PRIo8
#define PRIuLEAST8 PRIu8
#define PRIxLEAST8 PRIx8
#define PRIXLEAST8 PRIX8

#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIoLEAST16 PRIo16
#define PRIuLEAST16 PRIu16
#define PRIxLEAST16 PRIx16
#define PRIXLEAST16 PRIX16

#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIoLEAST32 PRIo32
#define PRIuLEAST32 PRIu32
#define PRIxLEAST32 PRIx32
#define PRIXLEAST32 PRIX32

#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64
#define PRIoLEAST64 PRIo64
#define PRIuLEAST64 PRIu64
#define PRIxLEAST64 PRIx64
#define PRIXLEAST64 PRIX64

#define PRIdFAST8 PRId8
#define PRIiFAST8 PRIi8
#define PRIoFAST8 PRIo8
#define PRIuFAST8 PRIu8
#define PRIxFAST8 PRIx8
#define PRIXFAST8 PRIX8

#define PRIdFAST16 PRId16
#define PRIiFAST16 PRIi16
#define PRIoFAST16 PRIo16
#define PRIuFAST16 PRIu16
#define PRIxFAST16 PRIx16
#define PRIXFAST16 PRIX16

#define PRIdFAST32 PRId32
#define PRIiFAST32 PRIi32
#define PRIoFAST32 PRIo32
#define PRIuFAST32 PRIu32
#define PRIxFAST32 PRIx32
#define PRIXFAST32 PRIX32

#define PRIdFAST64 PRId64
#define PRIiFAST64 PRIi64
#define PRIoFAST64 PRIo64
#define PRIuFAST64 PRIu64
#define PRIxFAST64 PRIx64
#define PRIXFAST64 PRIX64

#define PRIdPTR PRId32
#define PRIiPTR PRIi32
#define PRIoPTR PRIo32
#define PRIuPTR PRIu32
#define PRIxPTR PRIx32
#define PRIXPTR PRIX32

#define PRIdMAX PRId64
#define PRIiMAX PRIi64
#define PRIoMAX PRIo64
#define PRIuMAX PRIu64
#define PRIxMAX PRIx64
#define PRIXMAX PRIX64


#define __SCN_8_LENGTH_MODIFIER__ "hh"
#define __SCN_16_LENGTH_MODIFIER__ "h"
#define __SCN_32_LENGTH_MODIFIER__ ""
#define __SCN_64_LENGTH_MODIFIER__ "ll"

#define SCNd8 __SCN_8_LENGTH_MODIFIER__ "d"
#define SCNi8 __SCN_8_LENGTH_MODIFIER__ "i"
#define SCNo8 __SCN_8_LENGTH_MODIFIER__ "o"
#define SCNu8 __SCN_8_LENGTH_MODIFIER__ "u"
#define SCNx8 __SCN_8_LENGTH_MODIFIER__ "x"

#define SCNd16 __SCN_16_LENGTH_MODIFIER__ "d"
#define SCNi16 __SCN_16_LENGTH_MODIFIER__ "i"
#define SCNo16 __SCN_16_LENGTH_MODIFIER__ "o"
#define SCNu16 __SCN_16_LENGTH_MODIFIER__ "u"
#define SCNx16 __SCN_16_LENGTH_MODIFIER__ "x"

#define SCNd32 __SCN_32_LENGTH_MODIFIER__ "d"
#define SCNi32 __SCN_32_LENGTH_MODIFIER__ "i"
#define SCNo32 __SCN_32_LENGTH_MODIFIER__ "o"
#define SCNu32 __SCN_32_LENGTH_MODIFIER__ "u"
#define SCNx32 __SCN_32_LENGTH_MODIFIER__ "x"

#define SCNd64 __SCN_64_LENGTH_MODIFIER__ "d"
#define SCNi64 __SCN_64_LENGTH_MODIFIER__ "i"
#define SCNo64 __SCN_64_LENGTH_MODIFIER__ "o"
#define SCNu64 __SCN_64_LENGTH_MODIFIER__ "u"
#define SCNx64 __SCN_64_LENGTH_MODIFIER__ "x"

#define SCNdLEAST8 SCNd8
#define SCNiLEAST8 SCNi8
#define SCNoLEAST8 SCNo8
#define SCNuLEAST8 SCNu8
#define SCNxLEAST8 SCNx8

#define SCNdLEAST16 SCNd16
#define SCNiLEAST16 SCNi16
#define SCNoLEAST16 SCNo16
#define SCNuLEAST16 SCNu16
#define SCNxLEAST16 SCNx16

#define SCNdLEAST32 SCNd32
#define SCNiLEAST32 SCNi32
#define SCNoLEAST32 SCNo32
#define SCNuLEAST32 SCNu32
#define SCNxLEAST32 SCNx32

#define SCNdLEAST64 SCNd64
#define SCNiLEAST64 SCNi64
#define SCNoLEAST64 SCNo64
#define SCNuLEAST64 SCNu64
#define SCNxLEAST64 SCNx64

#define SCNdFAST8 SCNd8
#define SCNiFAST8 SCNi8
#define SCNoFAST8 SCNo8
#define SCNuFAST8 SCNu8
#define SCNxFAST8 SCNx8

#define SCNdFAST16 SCNd16
#define SCNiFAST16 SCNi16
#define SCNoFAST16 SCNo16
#define SCNuFAST16 SCNu16
#define SCNxFAST16 SCNx16

#define SCNdFAST32 SCNd32
#define SCNiFAST32 SCNi32
#define SCNoFAST32 SCNo32
#define SCNuFAST32 SCNu32
#define SCNxFAST32 SCNx32

#define SCNdFAST64 SCNd64
#define SCNiFAST64 SCNi64
#define SCNoFAST64 SCNo64
#define SCNuFAST64 SCNu64
#define SCNxFAST64 SCNx64

#define SCNdPTR SCNd32
#define SCNiPTR SCNi32
#define SCNoPTR SCNo32
#define SCNuPTR SCNu32
#define SCNxPTR SCNx32

#define SCNdMAX SCNd64
#define SCNiMAX SCNi64
#define SCNoMAX SCNo64
#define SCNuMAX SCNu64
#define SCNxMAX SCNx64

#endif


__BEGIN_DECLS
typedef struct {
	intmax_t quot;  /* quotient */
	intmax_t rem;   /* remainder */
} imaxdiv_t;

intmax_t imaxabs __P((intmax_t));
imaxdiv_t imaxdiv __P((intmax_t, intmax_t));

intmax_t strtoimax __P((const char *, char **, int));
uintmax_t strtoumax __P((const char *, char **, int));
__END_DECLS


#endif /* _INTTYPES_H_ */
