#ifndef UTILITY_MESSAGE_DIGEST_H
#define UTILITY_MESSAGE_DIGEST_H
/*
**    $VER: message_digest.h 53.29 (10.8.2015)
**
**    Message digest calculation
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
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
