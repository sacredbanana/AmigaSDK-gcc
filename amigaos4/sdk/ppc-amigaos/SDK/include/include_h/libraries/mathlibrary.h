#ifndef LIBRARIES_MATHLIBRARY_H
#define LIBRARIES_MATHLIBRARY_H
/*
**    $VER: mathlibrary.h 54.16 (22.08.2022)
**
**    Data structure returned by OpenLibrary of:
**    mathieeedoubbas.library,mathieeedoubtrans.library
**    mathieeesingbas.library,mathieeesingtrans.library
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifdef __amigaos4__
#error mathieeedoubbas.library, mathieeedoubtrans.library, \
       mathieeesingbas.library, mathieeesingtrans.library not supported on OS4
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
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

struct MathIEEEBase
{
    struct Library   MathIEEEBase_LibNode;
    unsigned char    MathIEEEBase_reserved[18];
    int            (*MathIEEEBase_TaskOpenLib)();
    int            (*MathIEEEBase_TaskCloseLib)();

    /* This structure may be extended in the future */
};

/*
* Math resources may need to know when a program opens or closes this
* library. The functions TaskOpenLib and TaskCloseLib are called when
* a task opens or closes this library. They are initialized to point to
* local initialization pertaining to 68881 stuff if 68881 resources
* are found. To override the default the vendor must provide appropriate
* hooks in the MathIEEEResource. If specified, these will be called
* when the library initializes.
*/

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

#endif /* LIBRARIES_MATHLIBRARY_H */
