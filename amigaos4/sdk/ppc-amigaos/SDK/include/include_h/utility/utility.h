#ifndef UTILITY_UTILITY_H
#define UTILITY_UTILITY_H
/*
**    $VER: utility.h 53.29 (10.8.2015)
**
**    Include all other utility include files
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   UTILITY_DATA_STRUCTURES_H
#include <utility/data_structures.h>
#endif

#ifndef   UTILITY_DATE_H
#include <utility/date.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef   UTILITY_MESSAGE_DIGEST_H
#include <utility/message_digest.h>
#endif

#ifndef   UTILITY_NAME_H
#include <utility/name.h>
#endif

#ifndef   UTILITY_PACK_H
#include <utility/pack.h>
#endif

#ifndef   UTILITY_RANDOM_H
#include <utility/random.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

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

#define UTILITYNAME "utility.library"

/****************************************************************************/

struct UtilityBase
{
    struct Library ub_LibNode;
    UBYTE          ub_Language; /* Private, for lowlevel.library */
    UBYTE          ub_Reserved;
};



/*****************************************************************************/
/* Flags used by the UTF-8 functions. */

#define UTF_INVALID_SUBST_FFFD    (1<<0)
  /*  Do not abort decoding when an invalid UTF-8 sequence is encountered,
  **  instead, substitute the invalid byte sequence with the special
  **  0xFFFD character. (inverse ? on square background)
  */
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

#endif
