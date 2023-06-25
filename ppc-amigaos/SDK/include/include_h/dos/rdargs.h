#ifndef DOS_RDARGS_H
#define DOS_RDARGS_H
/*
**    $VER: rdargs.h  54.100 (07.09.2020)
**
**    ReadArgs() structure definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
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

/**********************************************************************
 *
 * The CSource data structure defines the input source for "ReadItem()"
 * ReadLineItem() as well as the ReadArgs() call.  
 * It is a publicly defined structure which may be used by applications
 * which use code that follows the conventions defined for access.
 *
 * When passed to the dos.library functions, the value passed as
 * struct *CSource is defined as follows:
 *    if ( CSource == 0)    Use buffered IO "ReadChar()" as data source
 *    else            Use CSource for input character stream
 *
 * The following two pseudo-code routines roughly define how the CSource
 * structure is used:
 *
 * int32 CS_ReadChar( struct CSource *CSource )
 * {
 *    if ( CSource == 0 )     return ReadChar();
 *    if ( CSource->CurChr >= CSource->Length )  return ENDSTREAMCH;
 *    return CSource->Buffer[ CSource->CurChr++ ];
 * }
 *
 * int32 CS_UnReadChar( struct CSource *CSource )
 * {
 *    if ( CSource == 0 )     return UnReadChar();
 *    if ( CSource->CurChr <= 0 )     return FALSE;
 *    CSource->CurChr--;
 *    return TRUE;
 * }
 *
 * To initialize a struct CSource, you set CSource->CS_Buffer to
 * a string which is used as the data source, and set CS_Length to
 * the number of characters in the string, as returned by strlen().
 * Normally CS_CurChr should be initialized to ZERO, or left as it was 
 * from prior use as a CSource.
 *
 **********************************************************************/

struct CSource
{
    CONST_STRPTR   CS_Buffer;
    int32          CS_Length;
    int32          CS_CurChr;
};

/**********************************************************************
 *
 * The RDArgs data structure is the input parameter passed to the DOS
 * ReadArgs() function call.
 *
 * The RDA_Source structure is a CSource as defined above;
 * if RDA_Source.CS_Buffer is non-null, RDA_Source is used as the input
 * character stream to parse, else the input comes from the buffered STDIN
 * calls ReadChar/UnReadChar.
 *
 * RDA_DAList is a private address which is used internally to track
 * allocations which are freed by FreeArgs().  This MUST be initialized
 * to NULL prior to the first call to ReadArgs().
 *
 * The RDA_Buffer and RDA_BufSiz fields allow the application to supply
 * a fixed-size buffer in which to store the parsed data.  This allows
 * the application to pre-allocate a buffer rather than requiring buffer
 * space to be allocated.  If either RDA_Buffer or RDA_BufSiz is NULL,
 * the application has not supplied a buffer.
 *
 * RDA_ExtHelp is a text string which will be displayed instead of the
 * template string, if the user is prompted for input.
 *
 * RDA_Flags bits control how ReadArgs() works.  The flag bits are
 * defined below.  Defaults are initialized to ZERO.
 *
 **********************************************************************/

struct RDArgs
{
    struct CSource RDA_Source;      /* Select input source */
    APTR           RDA_DAList;      /* PRIVATE. */
    STRPTR         RDA_Buffer;      /* Optional string parsing space. */
    int32          RDA_BufSiz;      /* Size of RDA_Buffer (0..n) */
    STRPTR         RDA_ExtHelp;     /* Optional extended help */
    int32          RDA_Flags;       /* Flags for any required control */
};

#define RDAB_STDIN      0    /* Use "STDIN" rather than "COMMAND LINE" */
#define RDAB_NOALLOC    1    /* If set, do not allocate extra string space.*/
#define RDAB_NOPROMPT   2    /* Disable reprompting for string input. */

#define RDAF_STDIN      (1L<<RDAB_STDIN)
#define RDAF_NOALLOC    (1L<<RDAB_NOALLOC)
#define RDAF_NOPROMPT   (1L<<RDAB_NOPROMPT)



/****************************************************************************/

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

#endif /* DOS_RDARGS_H */
