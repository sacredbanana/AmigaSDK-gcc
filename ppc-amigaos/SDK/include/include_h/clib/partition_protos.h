#ifndef CLIB_PARTITION_PROTOS_H
#define CLIB_PARTITION_PROTOS_H
/*
** $Id: partition_protos.h,v 1.7 2010-01-31 01:29:02 ssolie Exp $
**
** C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**     All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

Class *PARTITION_GetClass(void);
struct Node *AllocPartitionNodeA(struct TagItem *taglist);
struct Node *AllocPartitionNode(Tag tag1, ...);
void FreePartitionNode(struct Node *node);
void SetPartitionNodeAttrsA(struct Node *node, struct TagItem *taglist);
void SetPartitionNodeAttrs(struct Node *node, Tag tag1, ...);
void GetPartitionNodeAttrsA(struct Node *node, struct TagItem *taglist);
void GetPartitionNodeAttrs(struct Node *node, Tag tag1, ...);


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* CLIB_PARTITION_PROTOS_H */
