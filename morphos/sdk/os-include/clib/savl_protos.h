#ifndef CLIB_SAVL_PROTOS_H
#define CLIB_SAVL_PROTOS_H

/*
 * Adelson-Velskii-Landis balanced binary tree routines with
 * AmigaOS 3.9 (V45) compatible API. This stuff does not belong
 * to exec.
 *
 * Copyright © 2005 Harry Sintonen <sintonen@iki.fi>.
 */

#ifndef EXEC_AVL_H
#include <exec/avl.h>
#endif /* EXEC_AVL_H */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct AVLNode *AVL_AddNode(struct AVLNode **root, struct AVLNode *node, APTR func);
struct AVLNode *AVL_RemNodeByAddress(struct AVLNode **root, struct AVLNode *node);
struct AVLNode *AVL_RemNodeByKey(struct AVLNode **root, AVLKey key, APTR func);
struct AVLNode *AVL_FindNode(const struct AVLNode *root, AVLKey key, APTR func);
struct AVLNode *AVL_FindPrevNodeByAddress(const struct AVLNode *node);
struct AVLNode *AVL_FindPrevNodeByKey(const struct AVLNode *root, AVLKey key, APTR func);
struct AVLNode *AVL_FindNextNodeByAddress(const struct AVLNode *node);
struct AVLNode *AVL_FindNextNodeByKey(const struct AVLNode *root, AVLKey key, APTR func);
struct AVLNode *AVL_FindFirstNode(const struct AVLNode *root);
struct AVLNode *AVL_FindLastNode(const struct AVLNode *root);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_SAVL_PROTOS_H */
