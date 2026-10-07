#ifndef LIBRARIES_BTREE_H
#define LIBRARIES_BTREE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef __GNUC__
  #ifdef __PPC__
    #pragma pack(2)
  #endif
#elif defined(__VBCC__)
  #pragma amiga-align
#endif

#define BTREENAME "btree.library"

struct BTArgArray
{
  APTR (*Alloc)(APTR userdata, ULONG size);
  void (*Free)(APTR userdata, APTR mem, ULONG size);
  LONG (*Compare)(APTR userdata, CONST_APTR keya, CONST_APTR keyb);
  void (*DestroyKey)(APTR userdata, APTR key);
  void (*DestroyData)(APTR userdata, APTR data);
  APTR UserData;
};


// Tree types for CreateTree
enum
{
  BT_DEFAULT,             // the best (in average) tree type for most use cases
  BT_AVL_TREE,            // AVL balanced binary tree
  BT_RED_BLACK_TREE       // red/black balanced binary tree
};

#ifdef __GNUC__
  #ifdef __PPC__
    #pragma pack()
  #endif
#elif defined(__VBCC__)
  #pragma default-align
#endif

#endif /* LIBRARIES_BTREE_H */
