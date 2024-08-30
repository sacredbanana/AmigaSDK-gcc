#include "libdata.h"

struct BTDInfo *QueryMyBlanker(void);
APTR            InitMyBlanker(struct TagItem *);
void            EndMyBlanker(APTR);
void            AnimMyBlanker(APTR);

struct BTDInfo *LIB_QueryBlanker(void)
{
	return(QueryMyBlanker());
}

APTR LIB_InitBlanker(void)
{
	struct TagItem *MyTags=(struct TagItem*) REG_A0;
	return(InitMyBlanker(MyTags));
}

void LIB_EndBlanker(void)
{
	APTR Ptr=(APTR)REG_A0;
	EndMyBlanker(Ptr);
}

void LIB_AnimBlanker(void)
{
	APTR Ptr=(APTR)REG_A0;
	AnimMyBlanker(Ptr);
}

