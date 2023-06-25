#ifndef RESOURCES_MATHRESOURCE_H
#define RESOURCES_MATHRESOURCE_H
/*
**    $VER: mathresource.h 54.16 (22.08.2022)
**
**    Data structure returned by OpenResource of:
**    "MathIEEE.resource"
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifdef __amigaos4__
#error MathIEEE.resource is not supported on AmigaOS4
#endif

#ifndef   EXEC_NODES_H
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

/*
*    The 'Init' entries are only used if the corresponding
*    bit is set in the Flags field.
*
*    So if you are just a 68881, you do not need the Init stuff
*    just make sure you have cleared the Flags field.
*
*    This should allow us to add Extended Precision later.
*
*    For Init users, if you need to be called whenever a task
*    opens this library for use, you need to change the appropriate
*    entries in MathIEEELibrary.
*/

struct MathIEEEResource
{
    struct Node       MathIEEEResource_Node;
    unsigned short    MathIEEEResource_Flags;
    unsigned short *  MathIEEEResource_BaseAddr; /* ptr to 881 if exists */
    void            (*MathIEEEResource_DblBasInit)();
    void            (*MathIEEEResource_DblTransInit)();
    void            (*MathIEEEResource_SglBasInit)();
    void            (*MathIEEEResource_SglTransInit)();
    void            (*MathIEEEResource_ExtBasInit)();
    void            (*MathIEEEResource_ExtTransInit)();
};

/* definations for MathIEEEResource_FLAGS */
#define MATHIEEERESOURCEF_DBLBAS    (1<<0)
#define MATHIEEERESOURCEF_DBLTRANS  (1<<1)
#define MATHIEEERESOURCEF_SGLBAS    (1<<2)
#define MATHIEEERESOURCEF_SGLTRANS  (1<<3)
#define MATHIEEERESOURCEF_EXTBAS    (1<<4)
#define MATHIEEERESOURCEF_EXTTRANS  (1<<5)

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

#endif /* RESOURCES_MATHRESOURCE_H */
