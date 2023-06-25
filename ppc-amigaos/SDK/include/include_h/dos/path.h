#ifndef DOS_PATH_H
#define DOS_PATH_H
/*
**    $VER: path.h  54.100 (07.09.2020)
**
**    Data structures and parameters for shell search path management
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/
/* A shell search path list component. Do not allocate this yourself! */

struct PathNode
{
    BPTR pn_Next;    /* Pointer to next path node */
    BPTR pn_Lock;    /* Directory lock */
};

/****************************************************************************/
/* Parameters for use with the AddCmdPathNode() function. Where to add
   the new node? */

#define ADDCMDPATHNODE_HEAD   0
#define ADDCMDPATHNODE_TAIL   1

/****************************************************************************/
/* The message passed to hook invoked by the SearchCmdPathList() function.  */

struct SearchCmdPathListMsg
{
    int32     splm_Size;
    BPTR      splm_Lock;
    STRPTR    splm_Name;
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DOS_PATH_H */
