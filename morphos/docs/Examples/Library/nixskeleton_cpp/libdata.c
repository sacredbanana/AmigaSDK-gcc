#include "libdata.h"


/* This function must preserve all registers except r13 */
asm(
"	.section  \".text\"\n"
"	.align 2\n"
"	.type  __restore_r13, @function\n"
"__restore_r13:\n"
"	lwz 13, 36(3)\n"   // r13 = MyLibBase->DataSeg
"	blr\n"
"__end__restore_r13:\n"
"	.size	__restore_r13, __end__restore_r13 - __restore_r13\n"
);


/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

static BOOL InitLibnix(void);
static void UnInitLibnix(void);


/* Global libbases */
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;


/* Init all your globals here */
BOOL __saveds InitData(struct LibBase *MyLibBase)
{
	SysBase = MyLibBase->SBase;

	if (!(DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 36)))
		return FALSE;

	return InitLibnix();
}

/* ..and uninit them here (will be called even if InitData() fails!) */
void __saveds UnInitData(struct LibBase *MyLibBase)
{
	UnInitLibnix();

	if (DOSBase)
		CloseLibrary((struct Library *)DOSBase);
}


/* Disable CTRL-C check */
void __chkabort(void) { }

/* We can't allow abort() or exit()! */
void abort(void) { kprintf("Something called abort()! Painful death follows...\n"); for (;;) Wait(0); }
void exit(int i) { kprintf("Something called exit()! Painful death follows...\n"); for (;;) Wait(0); }

#include <stdlib.h>

/* Required libnix startup globals */
struct WBStartup *_WBenchMsg;
char *_ProgramName = "";
void *libnix_mempool;
int ThisRequiresConstructorHandling;


/* De/constructor stuff */
struct CTDT
{
	int (*fp)(void);
	long priority;
};

extern const void (* const __ctrslist[])(void);
extern const void (* const __dtrslist[])(void);
extern const struct CTDT __ctdtlist[];
static struct CTDT *sort_ctdt(struct CTDT **last);
static struct CTDT *ctdt, *last_ctdt;

struct FuncSeg
{
	ULONG size;
	struct FuncSeg *next;
};


/* ANSI de/constructor handler */
static void CallFuncArray(const void (* const FuncArray[])(void))
{
	struct FuncSeg *seg;
	int i, num;

	seg = (struct FuncSeg *)(((IPTR)FuncArray) - sizeof(struct FuncSeg));
	num = (seg->size - sizeof(struct FuncSeg)) / sizeof(APTR);

	for (i=0; (i < num) && FuncArray[i]; i++)
	{
		if (FuncArray[i] != ((const void (* const)(void))-1))
			(*FuncArray[i])();
	}
}

static int comp_ctdt(struct CTDT *a, struct CTDT *b)
{
	if (a->priority == b->priority)
		return (0);
	if ((unsigned long)a->priority < (unsigned long) b->priority)
		return (-1);

	return (1);
}

static struct CTDT *sort_ctdt(struct CTDT **last)
{
	struct FuncSeg *seg;
	struct CTDT *last_ctdt;

	seg = (struct FuncSeg *)(((IPTR)__ctdtlist) - sizeof(struct FuncSeg));
	last_ctdt = (struct CTDT *)(((IPTR)seg) + seg->size);

	qsort((struct CTDT *)__ctdtlist, (IPTR)(last_ctdt - __ctdtlist), sizeof(*__ctdtlist), (int (*)(const void *, const void *))comp_ctdt);

	*last = last_ctdt;

	return ((struct CTDT *) __ctdtlist);
}

struct object {
	IPTR dummy[8];
};

extern const char __EH_FRAME_BEGIN__[];
extern void __register_frame_info (const void *, struct object *);
extern void *__deregister_frame_info (const void *);
struct object object;

static BOOL InitLibnix(void)
{
	/* Sort SAS/C de/constructor list */
	ctdt = sort_ctdt(&last_ctdt);

	/* Call SAS/C constructors */
	while (ctdt < last_ctdt)
	{
		if (ctdt->priority >= 0)
		{
			if(ctdt->fp() != 0)
			{
				return FALSE;
			}
		}

		ctdt++;
	}

	/* Preinit memory-system */
	malloc(0);

	__register_frame_info (__EH_FRAME_BEGIN__, &object);

	/* Call ANSI constructors */
	CallFuncArray(__ctrslist);

	return TRUE;
}

static void UnInitLibnix(void)
{
	/* Call ANSI destructors */
	if (ctdt == last_ctdt)
		CallFuncArray(__dtrslist);

	/* Call SAS/C destructors */
	ctdt = (struct CTDT *)__ctdtlist;
	while (ctdt < last_ctdt)
	{
		if (ctdt->priority < 0)
		{
			if(ctdt->fp != (int (*)(void)) -1)
			{
				ctdt->fp();
			}
		}

		ctdt++;
	}
	
	__deregister_frame_info(__EH_FRAME_BEGIN__);
}
