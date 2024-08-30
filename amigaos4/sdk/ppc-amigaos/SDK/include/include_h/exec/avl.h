#ifndef EXEC_AVL_H
#define EXEC_AVL_H
/*
**    $VER: avl.h 53.29 (10.8.2015)
**
**    AVL tree data structure definitions
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

/* Don't even think about the contents of this structure. Just embed it
   and reference it */
struct AVLNode
{
    uint32 reserved[4];
};

/****************************************************************************/

/* Note that this is really a totally abstract 32 bit value */
typedef void * AVLKey;

/****************************************************************************/

/* Callback functions for the AVL tree handling. They will have to return
 * strcmp like results for the given arguments (<0/0/>0).
 * You can compare to nodes or a node with a key.
 */
typedef int32 (* ASM AVLNODECOMP)(REG(a0, struct AVLNode *avlnode1),
                                 REG(a1, struct AVLNode *avlnode2));

typedef int32 (* ASM AVLKEYCOMP) (REG(a0, struct AVLNode *avlnode1),
                                 REG(a1, AVLKey avlkey));

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

#endif /* EXEC_AVL_H */
