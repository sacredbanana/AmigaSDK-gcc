#ifndef EXEC_LISTS_H
#define EXEC_LISTS_H

/*
	exec list definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct List
{
	struct Node *lh_Head;
	struct Node *lh_Tail;
	struct Node *lh_TailPred;
	UBYTE        lh_Type;
	UBYTE        lh_pad;
};

struct MinList
{
	struct MinNode *mlh_Head;
	struct MinNode *mlh_Tail;
	struct MinNode *mlh_TailPred;
};

#ifdef __GNUC__
#define IsListEmpty(x)     ({struct List *__tmpl = x; (APTR)__tmpl->lh_TailPred == (APTR)__tmpl;})
#define IsMsgPortEmpty(x)  ({struct List *__tmpl = &(x)->mp_MsgList; (APTR)__tmpl->lh_TailPred == (APTR)__tmpl;})
#else
#define IsListEmpty(x)     (((x)->lh_TailPred) == (struct Node *)(x))
#define IsMsgPortEmpty(x)  (((x)->mp_MsgList.lh_TailPred) == (struct Node *)(&(x)->mp_MsgList))
#endif

/*
 * Some useful macros
 */
#ifndef NO_LIST_MACROS

#ifndef NEWLIST
#define	NEWLIST(MyList)	\
do { \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	_MyList->mlh_TailPred = (struct MinNode *)_MyList; \
	_MyList->mlh_Tail = (struct MinNode *)NULL; \
	_MyList->mlh_Head = (struct MinNode *)&_MyList->mlh_Tail; \
} while (0)
#endif /* !NEWLIST */

#ifndef REMHEAD
#define	REMHEAD(MyList) \
({ \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	struct MinNode *RemovedNode; \
	struct MinNode *Result; \
	if ((RemovedNode = _MyList->mlh_Head)->mln_Succ) \
	{ \
		_MyList->mlh_Head = RemovedNode->mln_Succ; \
		_MyList->mlh_Head->mln_Pred = (struct MinNode *)&_MyList->mlh_Head; \
		Result = RemovedNode; \
	} \
	else \
	{ \
		Result = NULL; \
	} \
	(APTR)Result; \
})
#endif /* !REMHEAD */

#ifndef REMTAIL
#define	REMTAIL(MyList) \
({ \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	struct MinNode *RemovedNode; \
	struct MinNode *Result; \
	if ((RemovedNode = _MyList->mlh_TailPred)->mln_Pred) \
	{ \
		_MyList->mlh_TailPred = RemovedNode->mln_Pred; \
		_MyList->mlh_TailPred->mln_Succ = (struct MinNode *)&_MyList->mlh_Tail; \
		Result = RemovedNode; \
	} \
	else \
	{ \
		Result = NULL; \
	} \
	(APTR)Result; \
})
#endif /* !REMTAIL */

#ifndef ADDHEAD
#define	ADDHEAD(MyList,MyNode) \
do { \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	struct MinNode *_MyNode = (struct MinNode *)(MyNode); \
	struct MinNode *OldHeadNode; \
	OldHeadNode = _MyList->mlh_Head; \
	_MyNode->mln_Succ = OldHeadNode; \
	OldHeadNode->mln_Pred = _MyNode; \
	_MyNode->mln_Pred = (struct MinNode *)_MyList; \
	_MyList->mlh_Head = _MyNode; \
} while (0)
#endif /* !ADDHEAD */

#ifndef ADDTAIL
#define	ADDTAIL(MyList,MyNode) \
do { \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	struct MinNode *_MyNode = (struct MinNode *)(MyNode); \
	struct MinNode *OldPredNode; \
	OldPredNode = _MyList->mlh_TailPred; \
	_MyNode->mln_Succ = (struct MinNode *)&_MyList->mlh_Tail; \
	_MyNode->mln_Pred = OldPredNode; \
	OldPredNode->mln_Succ = _MyNode; \
	_MyList->mlh_TailPred = _MyNode; \
} while (0)
#endif /* !ADDTAIL */

#ifndef REMOVE
#define	REMOVE(MyNode) \
({ \
	struct MinNode *_MyNode = (struct MinNode *)(MyNode); \
	struct MinNode *PredNode; \
	struct MinNode *SuccNode; \
	PredNode = _MyNode->mln_Pred; \
	SuccNode = _MyNode->mln_Succ; \
	PredNode->mln_Succ = SuccNode; \
	SuccNode->mln_Pred = PredNode; \
	_MyNode; \
})
#endif /* !REMOVE */

#ifndef SWAPNODES
#define	SWAPNODES(MyNode1,MyNode2) \
do { \
	struct MinNode *_MyNode1 = (struct MinNode *)(MyNode1); \
	struct MinNode *_MyNode2 = (struct MinNode *)(MyNode2); \
	if (_MyNode1 != _MyNode2) \
	{ \
		struct MinNode *SuccNode2, *PredNode2; \
		SuccNode2 = _MyNode2->mln_Succ; \
		PredNode2 = _MyNode2->mln_Pred; \
		PredNode2->mln_Succ = _MyNode1; \
		SuccNode2->mln_Pred = _MyNode1; \
		_MyNode2->mln_Succ = _MyNode1->mln_Succ; \
		_MyNode2->mln_Pred = _MyNode1->mln_Pred; \
		_MyNode1->mln_Succ = SuccNode2; \
		_MyNode1->mln_Pred = PredNode2; \
		_MyNode2->mln_Pred->mln_Succ = _MyNode2; \
		_MyNode2->mln_Succ->mln_Pred = _MyNode2; \
	} \
} while (0)
#endif /* !SWAPNODES */

#ifndef INSERT
#define INSERT(MyList,MyNode,MyListNode) \
do { \
	struct MinList *_MyList = (struct MinList *)(MyList); \
	struct MinNode *_MyNode = (struct MinNode *)(MyNode); \
	struct MinNode *_MyListNode = (struct MinNode *)(MyListNode); \
	if (_MyListNode) \
	{ \
		struct MinNode *MyListNodeSucc; \
		if ((MyListNodeSucc = _MyListNode->mln_Succ)) \
		{ \
			_MyNode->mln_Succ = MyListNodeSucc; \
			_MyNode->mln_Pred = _MyListNode; \
			MyListNodeSucc->mln_Pred = _MyNode; \
			_MyListNode->mln_Succ = _MyNode; \
		} else { \
			struct MinNode *MyListNodePred; \
			_MyNode->mln_Succ = _MyListNode; \
			MyListNodePred = _MyListNode->mln_Pred; \
			_MyNode->mln_Pred = MyListNodePred; \
			_MyListNode->mln_Pred = _MyNode; \
			MyListNodePred->mln_Succ = _MyNode; \
		} \
	} else { \
		struct MinNode *OldHeadNode; \
		OldHeadNode = _MyList->mlh_Head; \
		_MyNode->mln_Succ = OldHeadNode; \
		OldHeadNode->mln_Pred = _MyNode; \
		_MyNode->mln_Pred = (struct MinNode *)_MyList; \
		_MyList->mlh_Head = _MyNode; \
	} \
} while (0)
#endif /* !INSERT */

#endif /* !NO_LIST_MACROS */

#ifdef AROS_ALMOST_COMPATIBLE

#define GetHead(_l)  \
({ struct List *l = (struct List *)(_l);  \
	l->lh_Head->ln_Succ ? l->lh_Head : (struct Node *)0;  \
})

#define GetTail(_l)  \
({ struct List *l = (struct List *)(_l);  \
	l->lh_TailPred->ln_Pred ? l->lh_TailPred : (struct Node *)0;  \
})

#define GetSucc(_n)  \
({ struct Node *n = (struct Node *)(_n);  \
	n->ln_Succ->ln_Succ ? n->ln_Succ : (struct Node *)0;  \
})

#define GetPred(_n)  \
({ struct Node *n = (struct Node *)(_n);  \
	n->ln_Pred->ln_Pred ? n->ln_Pred : (struct Node *)0;  \
})

#define ForeachNode(l,n)  \
for (  \
	n = (void *)(((struct List *)(l))->lh_Head);  \
	((struct Node *)(n))->ln_Succ;  \
	n = (void *)(((struct Node *)(n))->ln_Succ)  \
)

#define ForeachNodeSafe(l,n,n2)  \
for (  \
	n = (void *)(((struct List *)(l))->lh_Head);  \
	(n2 = (void *)((struct Node *)(n))->ln_Succ);  \
	n = (void *)n2  \
)

#define SetNodeName(node,name)  (((struct Node *)(node))->ln_Name = (char *)(name))
#define GetNodeName(node)       (((struct Node *)(node))->ln_Name)

#define ListLength(list,count)  \
do {  \
	struct Node *n;  \
	count = 0;  \
	ForeachNode(list,n) count++;  \
} while (0)

#endif /* AROS_ALMOST_COMPATIBLE */


#pragma pack()

#endif
