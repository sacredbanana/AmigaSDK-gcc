/*
 * $Id: assert.h,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 * :ts=8
 *
 * Copyright © 2000-2005 by Olaf Barthel. All Rights Reserved.
 */

/****************************************************************************/

/* IMPORTANT: If DEBUG is redefined, it must happen only here. This
 *            will cause all modules to depend upon it to be rebuilt
 *            by the smakefile (that is, provided the smakefile has
 *            all the necessary dependency lines in place).
 */

/*#define DEBUG*/

/****************************************************************************/

/* Profiling support code. */
#ifdef __SASC
#include <sprof.h>
#else
#ifdef PROFILE_OFF
#undef PROFILE_OFF
#endif
#define PROFILE_OFF() {}

#ifdef PROFILE_ON
#undef PROFILE_ON
#endif
#define PROFILE_ON()  {}
#endif /* __SASC */

/****************************************************************************/

#ifdef ASSERT
#undef ASSERT
#endif	/* ASSERT */

#define PUSH_ASSERTS()	PUSHDEBUGLEVEL(0)
#define PUSH_REPORTS()	PUSHDEBUGLEVEL(1)
#define PUSH_CALLS()	PUSHDEBUGLEVEL(2)
#define PUSH_ALL()	PUSHDEBUGLEVEL(2)
#define POP()		POPDEBUGLEVEL()

#if defined(DEBUG)

 #if defined(__amigaos4__)
  #define __VAR_ARGS __attribute__((linearvarargs))
 #else
  #define __VAR_ARGS
 #endif /* __amigaos4__ */

 void _ASSERT(int x,const char *xs,const char *file,int line,const char *function);
 void _SHOWVALUE(unsigned long value,int size,const char *name,const char *file,int line);
 void _SHOWPOINTER(void *p,const char *name,const char *file,int line);
 void _SHOWSTRING(const char *string,const char *name,const char *file,int line);
 void _SHOWMSG(const char *msg,const char *file,int line);
 void _ENTER(const char *file,int line,const char *function);
 void _LEAVE(const char *file,int line,const char *function);
 void _RETURN(const char *file,int line,const char *function,unsigned long result);
 void _DPRINTF_HEADER(const char *file,int line);
 int  _SETDEBUGLEVEL(int level);
 void _PUSHDEBUGLEVEL(int level);
 void _POPDEBUGLEVEL(void);
 int  _GETDEBUGLEVEL(void);
 void _SETPROGRAMNAME(char *name);

 void __VAR_ARGS _DPRINTF(const char *format,...);
 void __VAR_ARGS _DLOG(const char *format,...);

#if defined(__SASC)
#else
#if INCLUDE_VERSION >= 44
 #ifndef __MORPHOS__
 #include <clib/debug_protos.h>
 #endif
#endif
#endif

#if !defined(__SASC)
#define __FUNC__	__FUNCTION__
#endif

 #define ASSERT(x)		do { PROFILE_OFF(); _ASSERT((int)(x),#x,__FILE__,__LINE__,__FUNC__); PROFILE_ON(); } while(0)
 #define ENTER()		do { PROFILE_OFF(); _ENTER(__FILE__,__LINE__,__FUNC__); PROFILE_ON(); } while(0)
 #define LEAVE()		do { PROFILE_OFF(); _LEAVE(__FILE__,__LINE__,__FUNC__); PROFILE_ON(); } while(0)
 #define RETURN(r)		do { PROFILE_OFF(); _RETURN(__FILE__,__LINE__,__FUNC__,(unsigned long)r); PROFILE_ON(); } while(0)
 #define SHOWVALUE(v)		do { PROFILE_OFF(); _SHOWVALUE((unsigned long)(v),sizeof(v),#v,__FILE__,__LINE__); PROFILE_ON(); } while(0)
 #define SHOWPOINTER(p)		do { PROFILE_OFF(); _SHOWPOINTER(p,#p,__FILE__,__LINE__); PROFILE_ON(); } while(0)
 #define SHOWSTRING(s)		do { PROFILE_OFF(); _SHOWSTRING(s,#s,__FILE__,__LINE__); PROFILE_ON(); } while(0)
 #define SHOWMSG(s)		do { PROFILE_OFF(); _SHOWMSG(s,__FILE__,__LINE__); PROFILE_ON(); } while(0)
 #define D(s)			do { PROFILE_OFF(); _DPRINTF_HEADER(__FILE__,__LINE__); _DPRINTF s; PROFILE_ON(); } while(0)
 #define PRINTHEADER()		do { PROFILE_OFF(); _DPRINTF_HEADER(__FILE__,__LINE__); PROFILE_ON(); PROFILE_ON(); } while(0)
 #define PRINTF(s)		do { PROFILE_OFF(); _DLOG s; PROFILE_ON(); } while(0)
 #define LOG(s)			do { PROFILE_OFF(); _DPRINTF_HEADER(__FILE__,__LINE__); _DLOG("<%s()>:",__FUNC__); _DLOG s; PROFILE_ON(); } while(0)
 #define SETDEBUGLEVEL(l)	do { PROFILE_OFF(); _SETDEBUGLEVEL(l); PROFILE_ON(); } while(0)
 #define PUSHDEBUGLEVEL(l)	do { PROFILE_OFF(); _PUSHDEBUGLEVEL(l); PROFILE_ON(); } while(0)
 #define POPDEBUGLEVEL()	do { PROFILE_OFF(); _POPDEBUGLEVEL(); PROFILE_ON(); } while(0)
 #define SETPROGRAMNAME(n)	do { PROFILE_OFF(); _SETPROGRAMNAME(n); PROFILE_ON(); } while(0)
 #define GETDEBUGLEVEL()	_GETDEBUGLEVEL()

 #undef DEBUG
 #define DEBUG 1
#else
 #define ASSERT(x)		((void)0)
 #define ENTER()		((void)0)
 #define LEAVE()		((void)0)
 #define RETURN(r)		((void)0)
 #define SHOWVALUE(v)		((void)0)
 #define SHOWPOINTER(p)		((void)0)
 #define SHOWSTRING(s)		((void)0)
 #define SHOWMSG(s)		((void)0)
 #define D(s)			((void)0)
 #define PRINTHEADER()		((void)0)
 #define PRINTF(s)		((void)0)
 #define LOG(s)			((void)0)
 #define SETDEBUGLEVEL(l)	((void)0)
 #define PUSHDEBUGLEVEL(l)	((void)0)
 #define POPDEBUGLEVEL()	((void)0)
 #define SETPROGRAMNAME(n)	((void)0)
 #define GETDEBUGLEVEL()	(0)

 #ifdef DEBUG
 #undef DEBUG
 #endif /* DEBUG */

 #define DEBUG 0
#endif /* DEBUG */

/****************************************************************************/
