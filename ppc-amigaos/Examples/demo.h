/*************************************************************/
/* Includes and other common stuff for the MUI demo programs */
/*************************************************************/

/* MUI */
#if defined(MUI_INTERNAL)
#include <mui.h>
#else
#include <libraries/mui.h>
#endif

/* Prototypes */
#include <clib/alib_protos.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/icon.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <proto/utility.h>
#include <proto/asl.h>
#include <proto/muimaster.h>

/* System */
#include <dos/dos.h>
#if defined(__amigaos4__)
#include <dos/obsolete.h>
#endif
#include <exec/types.h>
#include <graphics/gfxmacros.h>
#include <workbench/workbench.h>

/* ANSI C */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Compiler specific stuff */

#ifdef _DCC

#define REG(x) __ ## x
#define ASM
#define SAVEDS __geta4

#else

#include "amiga_compiler.h"

#if defined(__amigaos4__)
extern struct Library *SysBase;
extern struct Library *IntuitionBase;
extern struct Library *UtilityBase;
extern struct Library *GfxBase;
extern struct Library *DOSBase;
extern struct Library *IconBase;
#else
struct IntuitionBase *IntuitionBase;
struct UtilityBase *UtilityBase;
struct GfxBase *GfxBase;
extern struct DosLibrary *DOSBase;
struct Library *IconBase;
#endif
struct Library *MUIMasterBase;
#if defined(__amigaos4__)
struct MUIMasterIFace *IMUIMaster;
#endif

#endif /* ifdef _DCC */

/*************************/
/* Init & Fail Functions */
/*************************/

static VOID fail(APTR app,const char *str)
{
        if (app)
                MUI_DisposeObject(app);

#ifndef _DCC
		#if defined(__amigaos4__)
		if (IMUIMaster)
				DropInterface((struct Interface *)IMUIMaster);
		#endif
        if (MUIMasterBase)
                CloseLibrary(MUIMasterBase);
#endif
#if !defined(__amigaos4__) && !defined(__MORPHOS__)
	if(IntuitionBase)
		CloseLibrary((struct Library *)IntuitionBase);
	if(UtilityBase)
		CloseLibrary((struct Library *)UtilityBase);
	if(GfxBase)
		CloseLibrary((struct Library *)GfxBase);
	if(IconBase)
		CloseLibrary((struct Library *)IconBase);
#endif
        if (str)
        {
                puts(str);
                exit(20);
        }
        exit(0);
}


#ifdef _DCC

int brkfunc(void) { return 0; }

int wbmain(struct WBStartup *wb_startup)
{
        extern int main(int argc, char *argv[]);
        return (main(0, (char **)wb_startup));
}

#endif


#ifdef __SASC
int CXBRK(void) { return 0; }
int _CXBRK(void) { return 0; }
void chkabort(void) {}
#endif


static VOID init(VOID)
{
#ifdef _DCC
        onbreak(brkfunc);
#endif

#ifndef _DCC
        if (!(MUIMasterBase = OpenLibrary(MUIMASTER_NAME,MUIMASTER_VMIN)))
                fail(NULL,"Failed to open "MUIMASTER_NAME".");
		#if defined(__amigaos4__)
		if (!(IMUIMaster = (struct MUIMasterIFace *)GetInterface(MUIMasterBase, "main", 1, NULL)))
				fail(NULL,"Failed to open "MUIMASTER_NAME".");
		#endif
#endif


#if !defined(__amigaos4__) && !defined(__MORPHOS__)
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 37);
	UtilityBase = (struct UtilityBase *)OpenLibrary("utility.library", 37);
	GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 37);
	IconBase = OpenLibrary("icon.library", 37);
#endif
}


#ifndef MAKE_ID
#define MAKE_ID(a,b,c,d) ((ULONG) (a)<<24 | (ULONG) (b)<<16 | (ULONG) (c)<<8 | (ULONG) (d))
#endif

#if !defined(__amigaos4__) && !defined(__MORPHOS__)
ULONG SetAttrs( APTR object, ULONG tag1, ... )
{ return SetAttrsA(object, (struct TagItem *)&tag1); }
APTR NewObject( struct IClass *classPtr, CONST_STRPTR classID, ULONG tag1, ... )
{ return NewObjectA(classPtr, classID, (const struct TagItem *)&tag1); }
struct Process *CreateNewProcTags( ULONG tag1, ... )
{ return CreateNewProc((struct TagItem *)&tag1); }
#endif

#define STR(x)  STR2(x)
#define STR2(x) #x

#define STACK_SIZE	65536

#if defined(__GNUC__) && !defined(__MORPHOS__)
#ifdef __amigaos4__
static USED_VAR CONST_STRPTR Stack = "$STACK:" STR(STACK_SIZE) "\n";
#endif // __amigaos4__
LONG __stack_size = STACK_SIZE;
#endif // __GNUC__ && !__MORPHOS__

#define inittags(msg) (((struct opSet *)msg)->ops_AttrList)

#include <SDI_stdarg.h>
#include <SDI_hook.h>

Object * STDARGS VARARGS68K DoSuperNew(struct IClass *cl, Object * obj, ...)
{
	Object *rc;
	VA_LIST args;
	struct opSet msg;

	VA_START(args, obj);
	msg.MethodID = OM_NEW;
	msg.ops_AttrList = VA_ARG(args, struct TagItem *);
	msg.ops_GInfo = NULL;
	rc = (Object *)DoSuperMethodA(cl, obj, (Msg)&msg);
	VA_END(args);

	return rc;
}
