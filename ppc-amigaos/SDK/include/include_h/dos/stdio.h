#ifndef DOS_STDIO_H
#define DOS_STDIO_H
/*
**    $VER: stdio.h  54.102 (28.09.2021)
**
**    ANSI-like stdio defines for dos buffered I/O
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

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
/* Pseudonyms for DOS functions. */

#define ReadChar()             FGetC(Input())
#define WriteChar(c)           FPutC(Output(),(c))
#define UnReadChar(c)          UnGetC(Input(),(c))

/* next one is inefficient */
#define ReadChars(buf,num)     FRead(Input(),(buf),1,(num))
#define ReadLn(buf,len)        FGets(Input(),(buf),(len))
#define WriteStr(s)            FPuts(Output(),(s))

/****************************************************************************/
/* Types for SetVBuf() and SetFileHandleAttr() */

#define BUF_LINE    0    /* flush on \n, etc.  (DEFAULT) */
#define BUF_FULL    1    /* never flush except when needed */
#define BUF_NONE    2    /* no buffering */

/****************************************************************************/

/* EOF return value */
#define ENDSTREAMCH      (-1)

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

#endif    /* DOS_STDIO_H */
