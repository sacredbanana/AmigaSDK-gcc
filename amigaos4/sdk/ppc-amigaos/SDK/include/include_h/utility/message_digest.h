#ifndef UTILITY_MESSAGE_DIGEST_H
#define UTILITY_MESSAGE_DIGEST_H
/*
** Message digest calculation
**
** Copyright 1989-2003 Amiga Inc.
**
** Copyright 2003-2019 Trevor Dickinson.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* Context information to be passed around between the different SHA-1
   calculation routines. When the digest has been calculated, you fill
   find it stored in the 'mdsha_Code' member (all 160 bits of it). */
struct MessageDigest_SHA
{
    UBYTE mdsha_Code[20];
    UBYTE mdsha_Reserved[328];
};

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* UTILITY_MESSAGE_DIGEST_H */
