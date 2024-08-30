/*****************************************************************************

This code serves as a basis for writing a library-based MUI custom class
(xyz.mcc) and its preferences editor (xyz.mcp).

You need to define a few things in your main source file, then include
this file and then continue with your classes methods. The order is
important, mccheader.c must be the first code-generating module.

Things to be defined before mccheader.c is included:

(1)  UserLibID     - version string for your class. must follow normal $VER: string conventions.
(2)  VERSION       - version number of the class. must match the one given in the $VER: string.
(3)  REVISION      - revision number of the class. must match the one given in the $VER: string.
(4)  CLASS         - Name of your class, ".mcc" or ".mcp" must always be appended.

(5)  SUPERCLASS    - superclass of your class.
(6)  struct Data   - instance data structure.
(7)  _Dispatcher   - your dispatcher function.

(8)  SUPERCLASSP   - Superclass of the preferences class, must be MUIC_Mccprefs or a subclass.
(9)  struct DataP  - instance data structure of preferences class.
(10) _DispatcherP  - dispatcher for the preferences class.

(11) USEDCLASSES   - Other custom classes required by this class (NULL terminated string array)
(12) USEDCLASSESP  - Preferences classes (.mcp) required by this class (NULL terminated string array)
(13) SHORTHELP     - .mcp help text for prefs program's listview.

Items (1) to (4) must always be defined. If you create a stand-alone
custom class (*.mcc) without preferences editor, also define (5), (6)
and (7). Name your class and the resulting ouptut file "Myclass.mcc".

If you create a preferences class (*.mcp) for a custom class, define
(8), (9) and (10) instead of (5), (6) and (7). Name your class and the
resulting output file "Myclass.mcp".

If you create a custom class with included preferences editor, define
all the above. Note that in this case, the name of your class and the
resulting output file is always "Myclass.mcc". MUI will automatically
recognize that there's also a "Myclass.mcp" included. Having a builtin
preferences class reduces the need for a second file but increases the
size and memory consuption of the class.

(11) If your class requires other mcc custom classes, list them in the
static array USEDCLASSES like this: 
const STRPTR USEDCLASSES[] = { "Busy.mcc", "Listtree.mcc", NULL };

(12) If your class has one (or more) preferences classes, list them in
the array USEDCLASSESP like this:
const STRPTR USEDCLASSESP[] = { "Myclass.mcp", "Popxxx.mcp", NULL };

(13) If you want MUI to display additional help text (besides name, 
version and copyright) when the mouse pointer is over your mcp entry 
in the prefs listview:
#define SHORTHELP "ANSI display for terminal programs."

If your class needs custom initialization (e.g. opening other
libraries), you can define
	ClassInit
	ClassExit
to point to custom functions. These functions need to have the prototypes
	BOOL ClassInitFunc(struct Library *base);
	VOID ClassExitFunc(struct Library *base);
and will be called right after the class has been created and right
before the class is being deleted. If your init func returns FALSE,
the custom class will be unloaded immediately.

Define the minimum version of muimaster.libray in MASTERVERSION. If you
don't define MASTERVERSION, it will default to MUIMASTER_VMIN from the
mui.h include file.

---
Items (1) to (4) must always be defined. If you create a stand-alone
custom class (*.mcc) without preferences editor, also define (5), (6)
and (7). Name your class and the resulting ouptut file "Myclass.mcc".

If you create a preferences class (*.mcp) for a custom class, define
(8), (9) and (10) instead of (5), (6) and (7). Name your class and the
resulting output file "Myclass.mcp".

If you create a custom class with included preferences editor, define
all the above. Note that in this case, the name of your class and the
resulting output file is always "Myclass.mcc". MUI will automatically
recognize that there's also a "Myclass.mcp" included. Having a builtin
preferences class reduces the need for a second file but increases the
size and memory consuption of the class.

If your class needs custom initialization (e.g. opening other
libraries), you can define
	PreClassInit
	PostClassExit
	ClassInit
	ClassExit
to point to custom functions. These functions need to have the prototypes
	BOOL ClassInitFunc(struct Library *base);
	VOID ClassExitFunc(struct Library *base);
and will be called right after the class has been created and right
before the class is being deleted. If your init func returns FALSE,
the custom class will be unloaded immediately.

	BOOL PreClassInitFunc(void);
	VOID PostClassExitFunc(void);

These functions will be called BEFORE the class is created and AFTER the
class is deleted, if something depends on it for example. MUIMasterBase
is open then.

Define the minimum version of muimaster.libray in MASTERVERSION. If you
don't define MASTERVERSION, it will default to MUIMASTER_VMIN from the
mui.h include file.

This code automatically defines and initializes the following variables:
	struct Library *MUIMasterBase;
	struct Library *SysBase;
	struct Library *UtilityBase;
	struct DosLibrary *DOSBase;
	struct GfxBase *GfxBase;
	struct IntuitionBase *IntuitionBase;
	struct Library *MUIClassBase;       // your classes library base
	struct MUI_CustomClass *ThisClass;  // your custom class
	struct MUI_CustomClass *ThisClassP; // your preferences class

Example: Myclass.c
	#define CLASS      MUIC_Myclass // name of class, e.g. "Myclass.mcc"
	#define SUPERCLASS MUIC_Area    // name of superclass
	struct Data
	{
		LONG          MyData;
		struct Foobar MyData2;
		// ...
	};
	#define UserLibID "$VER: Myclass.mcc 17.53 (11.11.96)"
	#define VERSION   17
	#define REVISION  53
	#include "mccheader.c"
	ULONG ASM SAVEDS _Dispatcher(REG(a0) struct IClass *cl GNUCREG(a0),
	                             REG(a2) Object *obj GNUCREG(a2),
	                             REG(a1) Msg msg GNUCREG(a1) )
	{
		// ...
	}

Compiling and linking with SAS-C can look like this:
	Myclass.mcc: Myclass.c
		sc $(CFLAGS) $*.c OBJNAME $*.o
		slink to $@ from $*.o lib $(LINKERLIBS) $(LINKERFLAGS)

Note well that we don't use SAS library creation feature here, it simply
sucks too much. It's not much more complicated to do the library
initialziation ourselves and we have better control over everything.

Make sure to read the whole source to get some interesting comments
and some understanding on how libraries are created!

*****************************************************************************/

/* a few other includes... */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <exec/semaphores.h>
#include <exec/resident.h>
#include <exec/execbase.h>
#include <libraries/query.h>
#include <dos/dos.h>
#include <proto/exec.h>
#include <proto/muimaster.h>

#ifdef SAVEDS
#undef SAVEDS
#endif

#ifdef __SASC

#	define REG( r )				register __ ## r
#	define GNUCREG( r )
#	define SAVEDS				__saveds
#	define ASM					__asm
#	define REGARGS				__regargs
#	define STDARGS				__stdargs
#	define STACKARGS			__stdargs
#	define ALIGNED				__aligned
#	define FAR					__far
#	define INLINE				__inline

#else
#	ifdef __GNUC__
#    ifdef __MORPHOS__
#		define REG( r )
#		define GNUCREG( r )
#		define SAVEDS
#		define ASM
#		define REGARGS			__regargs
#		define STDARGS			__stdargs
#		define SACKARGS			__stdargs
#		define ALIGNED			__aligned
#		define FAR				__far
#		define INLINE			__inline
#		define NO_PRAGMAS
#		define USE_GLUE
#    else

#		define REG( r )
#		define GNUCREG( r )		__asm( #r )
#		define SAVEDS			__saveds
#		define ASM
#		define REGARGS			__regargs
#		define STDARGS			__stdargs
#		define STACKARGS		__stdargs
#		define ALIGNED			__aligned
#		define FAR				__far
#		define INLINE
#		define NO_PRAGMAS
#    endif

#	else /* Any other compiler. */

#		define REG( r )
#		define GNUCREG( r )
#		define SAVEDS
#		define ASM
#		define REGARGS
#		define STDARGS
#		define SACKARGS
#		define ALIGNED
#		define FAR
#		define INLINE

#	endif /* __GNUC__ */
#endif /* __SASC */

/* Dummy entry point and LibNull() function all in one */

STATIC IPTR ASM LibNull(VOID)
{
	return (IPTR)NULL;
}



/* The name of the class will also become the name of the library. */
/* We need a pointer to this string in our ROMTag (see below). */

static const char UserLibName[] = CLASS;


/* Here's our global data, described above. */

struct Library *MUIClassBase;
struct Library *MUIMasterBase;
struct ExecBase *SysBase;
struct Library *UtilityBase; /* sba: on my machine this is struct Library, struct UtilityBase *UtilityBase; RHP: struct Library *UtilityBase; */
struct DosLibrary *DOSBase;
struct GfxBase *GfxBase;
struct IntuitionBase *IntuitionBase;

#ifdef SUPERCLASS
struct MUI_CustomClass *ThisClass;
#endif

#ifdef SUPERCLASSP
struct MUI_CustomClass *ThisClassP;
#endif

#ifdef __SASC

#if 0
ULONG XCEXIT       = NULL; /* these symbols may be referenced by    */
ULONG _XCEXIT      = NULL; /* some functions of sc.lib, but should  */
#endif
ULONG ONBREAK      = NULL; /* never be used inside a shared library */
ULONG _ONBREAK     = NULL;
ULONG base         = NULL;
ULONG _base        = NULL;
ULONG ProgramName  = NULL;
ULONG _ProgramName = NULL;
ULONG StackPtr     = NULL;
ULONG _StackPtr    = NULL;
ULONG oserr        = NULL;
ULONG _oserr       = NULL;
ULONG OSERR        = NULL;
ULONG _OSERR       = NULL;

void __regargs __chkabort(void) {}	/* a shared library cannot be    */
void __regargs _CXBRK(void)     {}	/* CTRL-C aborted when doing I/O */

#else
 #ifdef __GNUC__
  /* these one are needed copies for libnix.a */
  struct DosLibrary *__DOSBase = NULL;
  struct Library *__UtilityBase = NULL;

  #ifndef __MORPHOS__
   #ifndef _STDLIB_H_
    void __regargs exit(void) {}
   #endif
   LONG _WBenchMsg = 0;
  #endif
 #endif /* __GNUC__ */

#endif /* __SASC */

/* Our library structure, consisting of a struct Library, a segment pointer */
/* and a semaphore. We need the semaphore to protect init/exit stuff in our */
/* open/close functions */

struct LibraryHeader
{
	struct Library         lh_Library;
	BPTR                   lh_Segment;
	struct SignalSemaphore lh_Semaphore;
	UWORD                  lh_Initialized;
#if !defined(__MORPHOS__)
	struct StackSwapStruct *lh_Stack;
#endif
};

#define STACKSWAPSIZE		8192


/* Prototypes for all library functions */

#ifdef __MORPHOS__
struct LibraryHeader * LibInit   (struct Library *lib, BPTR segment, struct ExecBase *SysBase);
BPTR                   LibExpunge(void);
struct LibraryHeader * LibOpen   (void);
BPTR                   LibClose  (void);
ULONG                  MCC_Query (void);
#else
struct LibraryHeader * ASM LibInit   (REG(a0) BPTR Segment GNUCREG(a0));
BPTR                   ASM LibExpunge(REG(a6) struct LibraryHeader *base GNUCREG(a6));
struct LibraryHeader * ASM LibOpen   (REG(a6) struct LibraryHeader *base GNUCREG(a6));
BPTR                   ASM LibClose  (REG(a6) struct LibraryHeader *base GNUCREG(a6));
ULONG           SAVEDS ASM MCC_Query (REG(d0) LONG which GNUCREG(d0));
#endif


/* Prototypes for a few sub-functions */

BPTR     MyLibExpunge(struct LibraryHeader *base);
BOOL ASM UserLibOpen   (REG(a6) struct Library *base GNUCREG(a6));
BOOL ASM UserLibClose  (REG(a6) struct Library *base GNUCREG(a6));


/* This is the librarie's jump table */

static const APTR LibVectors[] =
{
#ifdef __MORPHOS__
	(APTR)FUNCARRAY_32BIT_NATIVE,
#endif
	LibOpen,
	LibClose,
	LibExpunge,
	LibNull,
	MCC_Query,
	(APTR)-1
};


#ifdef __MORPHOS__
const unsigned long __abox__ = 1;
#endif

#ifdef QUERYINFOATTR_NAME
static struct TagItem	QueryTags[]=
{
	{QUERYINFOATTR_NAME, (ULONG) CLASS},
	{QUERYINFOATTR_IDSTRING, (ULONG) (LIBQUERYID)},
	{QUERYINFOATTR_DESCRIPTION, (ULONG) LIBQUERYDESCRIPTION},
	{QUERYINFOATTR_VERSION, (ULONG) VERSION},
	{QUERYINFOATTR_REVISION, REVISION},
	{QUERYINFOATTR_CODETYPE, MACHINE_PPC},
	{QUERYINFOATTR_TYPE, QUERYTYPE_LIBRARY},
	{QUERYINFOATTR_SUBTYPE, QUERYSUBTYPE_MUICLASS},
	#ifdef LIBQUERYCLASS
	{QUERYINFOATTR_CLASS, LIBQUERYCLASS},
	#endif
	#ifdef LIBQUERYSUBCLASS
	{QUERYINFOATTR_SUBCLASS, LIBQUERYSUBCLASS},
	#endif
	#ifdef LIBQUERYSUBCLASSPRI
	{QUERYINFOATTR_PRI, LIBQUERYSUBCLASSPRI},
	#endif
	#ifdef LIBQUERYCUSTOMENTRIES
	LIBQUERYCUSTOMENTRIES ,
	#endif
	{TAG_DONE,0}
};
#endif

/* Here's what makes us a library. */

struct Resident ROMTag =
{
	RTC_MATCHWORD,
	(struct Resident *)&ROMTag,
	(struct Resident *)(&ROMTag + 1),
#ifdef __MORPHOS__
	RTF_PPC | RTF_EXTENDED,
#else
	0,
#endif
	VERSION,
	NT_LIBRARY,
	0,
	(void *)UserLibName,
	(char *)UserLibID,
	LibInit

#ifdef __MORPHOS__
	/* RTF_EXTENDED Fields */
	,REVISION,
#ifdef QUERYINFOATTR_NAME
	QueryTags
#else
	NULL
#endif
#endif /* __MORPHOS__ */
};



/******************************************************************************/
/* Standard Library Functions, all of them are called in Forbid() state.      */
/******************************************************************************/

#ifdef __MORPHOS__
struct LibraryHeader *LibInit( struct Library *dummylib __attribute__((__unused__)), BPTR Segment, struct ExecBase *sb )
{
#else
struct LibraryHeader * ASM SAVEDS LibInit( REG(a0) BPTR Segment GNUCREG(a0) )
{
	struct ExecBase *sb = *((struct ExecBase **)4);
#endif

	struct LibraryHeader *base;
#if !defined(__MORPHOS__)
	static struct StackSwapStruct *stack = NULL;
#endif

	SysBase = sb;

	D(bug( "%s: Start...\n",__func__ ) );

	#ifdef __SASC
	#ifdef _M68040
	if (!(((struct ExecBase *)SysBase)->AttnFlags & AFF_68040))
		return NULL;
	#endif
	#ifdef _M68030
	if (!(((struct ExecBase *)SysBase)->AttnFlags & AFF_68030))
		return NULL;
	#endif
	#ifdef _M68020
	if (!(((struct ExecBase *)SysBase)->AttnFlags & AFF_68020))
		return NULL;
	#endif
	#endif

#if defined( CLASS_STACKSWAP ) && !defined( __MORPHOS__ )
	stack = AllocMem(sizeof(struct StackSwapStruct) + STACKSWAPSIZE, MEMF_PUBLIC);
	if (!stack)
		return NULL;

	stack->stk_Lower	= (APTR)((ULONG)stack + sizeof(struct StackSwapStruct));
	stack->stk_Upper	= (ULONG)((ULONG)stack->stk_Lower + STACKSWAPSIZE);
	stack->stk_Pointer	= (APTR)stack->stk_Upper;

	D(bug( "%s: Before StackSwap()\n",__func__) );
	StackSwap(stack);
#endif

	base = (struct LibraryHeader *) MakeLibrary((APTR)LibVectors, NULL, NULL, sizeof(struct LibraryHeader), 0);
	if (base)
	{
		D(bug( "%s: After MakeLibrary()\n",__func__ ) );

		base->lh_Library.lib_Node.ln_Type = NT_LIBRARY;
		base->lh_Library.lib_Node.ln_Name = (char *)UserLibName;
		base->lh_Library.lib_Flags        = LIBF_CHANGED | LIBF_SUMUSED;
		base->lh_Library.lib_Version      = VERSION;
		base->lh_Library.lib_Revision     = REVISION;
		base->lh_Library.lib_IdString     = (char *)UserLibID;

		base->lh_Segment	= Segment;
#if !defined(__MORPHOS__)
		base->lh_Stack		= stack;
#endif

		InitSemaphore(&base->lh_Semaphore);

		D(bug( "%s: AddLibrary()\n",__func__) );
		AddLibrary((struct Library *)base);
	}
	else
	{
		D(bug("%s: MakeLibrary() failed\n",__func__) );
	}

#if defined( CLASS_STACKSWAP ) && !defined( __MORPHOS__ )
	StackSwap(stack);
	FreeMem(stack, sizeof(struct StackSwapStruct) + STACKSWAPSIZE);
	D(bug( "%s: After second StackSwap()\n",__func__ ) );
#endif

	return base;
}


#ifdef __MORPHOS__
BPTR LibExpunge( void )
{
	struct LibraryHeader *base = (void *)REG_A6;
#else
BPTR ASM SAVEDS LibExpunge(REG(a6) struct LibraryHeader *base GNUCREG(a6))
{
	struct Library *SysBase = *((struct Library **)4);
#endif
	return(MyLibExpunge(base));
}


BPTR MyLibExpunge(struct LibraryHeader *base)
{
	struct Library *SysBase = *((struct Library **)4);
	BPTR rc;

	D(bug( "%s: base = 0x%lx <%s>\n",__func__, base, base->lh_Library.lib_Node.ln_Name ) );
	D(bug( "%s: OpenCount = %ld\n",__func__, base->lh_Library.lib_OpenCnt ) );

	if (base->lh_Library.lib_OpenCnt)
	{
		base->lh_Library.lib_Flags |= LIBF_DELEXP;
		D(bug("%s: Setting LIBF_DELEXP\n",__func__) );
		return 0;
	}

	REMOVE((struct Node *)base);

	rc = base->lh_Segment;
	FreeMem((BYTE *)base - base->lh_Library.lib_NegSize,base->lh_Library.lib_NegSize + base->lh_Library.lib_PosSize);

	return rc;
}


#ifdef __MORPHOS__
struct LibraryHeader *LibOpen( void )
{
	struct LibraryHeader *base = (void *)REG_A6;
#else
struct LibraryHeader * ASM SAVEDS LibOpen( REG(a6) struct LibraryHeader *base GNUCREG(a6) )
{
	struct Library *SysBase = *((struct Library **)4);
#endif

	struct LibraryHeader *rc;

	D(bug( "%s: base = 0x%lx <%s>\n",__func__, base, base->lh_Library.lib_Node.ln_Name ) );

	base->lh_Library.lib_OpenCnt++;
	base->lh_Library.lib_Flags &= ~LIBF_DELEXP;

	ObtainSemaphore(&base->lh_Semaphore);

	D(bug( "%s: OpenCount = %ld\n",__func__, base->lh_Library.lib_OpenCnt ) );

	if (base->lh_Initialized == FALSE)
	{
		base->lh_Initialized = UserLibOpen((struct Library *)base);
	}

	if (base->lh_Initialized)
	{
		#ifdef CLASS_VERSIONFAKE
		base->lh_Library.lib_Version	= (UWORD)MUIMasterBase->lib_Version;
		base->lh_Library.lib_Revision	= (UWORD)MUIMasterBase->lib_Revision;
		#endif

		rc = base;
	}
	else
	{
		rc = NULL;
		base->lh_Library.lib_OpenCnt--;
		D(bug("%s: UserLibOpen() failed\n",__func__) );
	}

	ReleaseSemaphore(&base->lh_Semaphore);

	return rc;
}


#ifdef __MORPHOS__
BPTR LibClose( void )
{
	struct LibraryHeader *base = (struct LibraryHeader *)REG_A6;
#else
BPTR ASM SAVEDS LibClose(REG(a6) struct LibraryHeader *base GNUCREG(a6))
{
	struct Library *SysBase = *((struct Library **)4);
#endif
	BPTR rc = 0;

	D(bug( "%s: base = 0x%lx <%s>\n",__func__, base, base->lh_Library.lib_Node.ln_Name ) );
	base->lh_Library.lib_OpenCnt--;

	ObtainSemaphore(&base->lh_Semaphore);

	D(bug( "%s: OpenCount = %ld %s\n",__func__, base->lh_Library.lib_OpenCnt, base->lh_Library.lib_OpenCnt == 0 ? "\7ERROR" : "" ) );

	if (base->lh_Library.lib_OpenCnt == 0 && base->lh_Initialized)
	{
		base->lh_Initialized = FALSE;
		UserLibClose((struct Library *)base);
	}

	ReleaseSemaphore(&base->lh_Semaphore);

	/* If OpenCnt is still zero we can quit */
	if (base->lh_Library.lib_OpenCnt == 0)
	{
#ifndef EXPUNGE_AT_LAST_CLOSE
		if (base->lh_Library.lib_Flags & LIBF_DELEXP)
#endif
		{
			rc = MyLibExpunge(base);
		}
	}

	return rc;
}


#ifdef __MORPHOS__

#ifdef SUPERCLASS
ULONG _Dispatcher(void);
struct EmulLibEntry _Dispatcher_gate = { TRAP_LIB, 0, (void (*)(void)) _Dispatcher };
#endif

#ifdef SUPERCLASSP
ULONG _DispatcherP(void);
struct EmulLibEntry _DispatcherP_gate = { TRAP_LIB, 0, (void (*)(void)) _DispatcherP };
#endif

#endif

BOOL ASM SAVEDS UserLibOpen(REG(a6) struct Library *base GNUCREG(a6))
{
#ifndef __MORPHOS__
	#ifdef SUPERCLASS
#ifdef __GNUC__
	ULONG ASM _Dispatcher(void);
#else
	ULONG ASM SAVEDS _Dispatcher( REG(a0) struct IClass *cl GNUCREG(a0), REG(a2) Object *obj GNUCREG(a2), REG(a1) Msg msg GNUCREG(a1) );
#endif
	#endif

	#ifdef SUPERCLASSP
#ifdef __GNUC__
	ULONG ASM _DispatcherP(void);
#else
	ULONG ASM SAVEDS _DispatcherP( REG(a0) struct IClass *cl GNUCREG(a0), REG(a2) Object *obj GNUCREG(a2), REG(a1) Msg msg GNUCREG(a1) );
#endif
	#endif

#endif

	BOOL PreClassInitFunc(void);
	BOOL ClassInitFunc(struct Library *base);

	D(bug( "%s: base 0x%lx <%s>\n", __func__, base, base->lib_Node.ln_Name ) );
	D(bug( "%s: OpenCount = %ld\n", __func__, base->lib_OpenCnt ) );

	#ifndef MASTERVERSION
	#define MASTERVERSION MUIMASTER_VMIN
	#endif

	if ((MUIMasterBase = OpenLibrary("muimaster.library",MASTERVERSION)))
	{
		#ifdef PreClassInit
		if(PreClassInitFunc())
		#endif
		{

		#ifdef SUPERCLASS
#ifdef __MORPHOS__
		ThisClass = MUI_CreateCustomClass(base,SUPERCLASS,NULL,sizeof(struct Data),&_Dispatcher_gate);
#else
		ThisClass = MUI_CreateCustomClass(base,SUPERCLASS,NULL,sizeof(struct Data),_Dispatcher);
#endif

		D(bug( "%s: Class = %lx\n", __func__, ThisClass ) );

		if ( ThisClass )
		#endif
		{
			#ifdef SUPERCLASSP
#ifdef __MORPHOS__
			if ((ThisClassP = MUI_CreateCustomClass(base,SUPERCLASSP,NULL,sizeof(struct DataP),&_DispatcherP_gate)))
#else
			if (ThisClassP = MUI_CreateCustomClass(base,SUPERCLASSP,NULL,sizeof(struct DataP),_DispatcherP))
#endif

			D(bug( "%s: ClassP = %lx\n", __func__, ThisClassP ) );

			#endif
			{
				#ifdef SUPERCLASS
				#define THISCLASS ThisClass
				#else
				#define THISCLASS ThisClassP
				#endif

				D(bug( "%s: open libs\n", __func__) );
				UtilityBase   = (struct Library *)THISCLASS->mcc_UtilityBase; /* RHP: UtilityBase   = (struct Library *)THISCLASS->mcc_UtilityBase; */
				DOSBase       = (struct DosLibrary *)THISCLASS->mcc_DOSBase;
				GfxBase       = (struct GfxBase *)THISCLASS->mcc_GfxBase;
				IntuitionBase = (struct IntuitionBase *)THISCLASS->mcc_IntuitionBase;

				#ifdef __GNUC__
				__DOSBase		= DOSBase;
				__UtilityBase	= UtilityBase;
				#endif /* __GNUC__ */

				#ifndef ClassInit
				D(bug( "%s: no ClassInit, done\n", __func__));

				return TRUE;
				#else
				if (ClassInitFunc(base))
				{
					D(bug( "%s: ClassInit, done\n", __func__));
					return TRUE;
				}

				D(bug( "%s: failed, close\n", __func__));
				#ifdef SUPERCLASSP
				MUI_DeleteCustomClass(ThisClassP);
				ThisClassP = NULL;
				#endif

				#endif
			}
			#ifdef SUPERCLASSP
			#ifdef SUPERCLASS
			MUI_DeleteCustomClass(ThisClass);
			ThisClass = NULL;
			#endif
			#endif
		}
		}
		CloseLibrary(MUIMasterBase);
		MUIMasterBase = NULL;
	}

	D(bug("%s: fail. %08lx <%s>\n",__func__,base,base->lib_Node.ln_Name) );

	return FALSE;
}


BOOL ASM SAVEDS UserLibClose(REG(a6) struct Library *base GNUCREG(a6))
{
	VOID PostClassExitFunc(void);
	VOID ClassExitFunc(struct Library *base);

	D(bug( "%s: OpenCount = %ld\n", __func__, base->lib_OpenCnt ) );

	{
		D(bug( "%s: Close Class\n", __func__));
		#ifdef ClassExit
		ClassExitFunc(base);
		#endif

		#ifdef SUPERCLASSP
		if (ThisClassP)
		{
			MUI_DeleteCustomClass(ThisClassP);
			ThisClassP = NULL;
		}
		#endif

		#ifdef SUPERCLASS
		if (ThisClass)
		{
			MUI_DeleteCustomClass(ThisClass);
			ThisClass = NULL;
		}
		#endif

		#ifdef PostClassExit
		PostClassExitFunc();
		#endif

		if (MUIMasterBase)
		{
			CloseLibrary(MUIMasterBase);
			MUIMasterBase = NULL;
		}
	}

	D(bug( "%s: done\n", __func__));
	return TRUE;
}


#ifdef __MORPHOS__
IPTR MCC_Query( void )
{
	LONG which = (LONG)REG_D0;
#else
ULONG SAVEDS ASM MCC_Query( REG(d0) LONG which GNUCREG(d0) )
{
#endif

	switch (which)
	{
		#ifdef SUPERCLASS
		case 0: return (ULONG)ThisClass;
		#endif

		#ifdef SUPERCLASSP
		case 1: return (ULONG)ThisClassP;
		#endif

		#ifdef PREFSIMAGEOBJECT
		case 2:
		{
			Object *obj = PREFSIMAGEOBJECT;
			return (ULONG)obj;
		}
		#endif

		#ifdef ONLYGLOBAL
		case 3:
		{
			return TRUE;
		}
		#endif

		#ifdef INFOCLASS
		case 4:
		{
			return TRUE;
		}
		#endif

		#ifdef USEDCLASSES
		case 5:
		{
			return (ULONG)USEDCLASSES;
		}
		#endif

		#ifdef USEDCLASSESP
		case 6:
		{
			return (ULONG)USEDCLASSESP;
		}
		#endif

		#ifdef SHORTHELP
		case 7:
		{
			return (ULONG)SHORTHELP;
		}
		#endif
	}

	return 0;
}
