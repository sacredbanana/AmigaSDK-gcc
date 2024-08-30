#include "libdata.h"

/* This function must preserve all registers except r13 */
asm("\n"
"	.section  \".text\"\n"
"	.align 2\n"
"	.type  __restore_r13, @function\n"
"__restore_r13:\n"
"	lwz 13, 36(3)	# r13 = MyLibBase->DataSeg\n"
"	blr\n"
"__end__restore_r13:\n"
"	.size	__restore_r13, __end__restore_r13 - __restore_r13\n"
"\n");

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

struct ExecBase *SysBase;

/* Init all your globals here */
BOOL __saveds InitData(struct LibBase *MyLibBase)
{
	SysBase = MyLibBase->SBase;

	return TRUE;
}

/* ..and uninit them here */
void __saveds UnInitData(struct LibBase *MyLibBase)
{
}
