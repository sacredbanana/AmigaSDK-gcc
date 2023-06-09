/*
 * $Id: assert.h,v 1.1 2008-09-15 13:25:04 sarcher Exp $
 *
 * :ts=8
 *
 * Copyright � 2001-2005 by Olaf Barthel. All Rights Reserved.
 */

/****************************************************************************/

/* IMPORTANT: If DEBUG is redefined, it must happen only here. This
 *            will cause all modules to depend upon it to be rebuilt
 *            by the smakefile (that is, provided the smakefile has
 *            all the necessary dependency lines in place).
 */

/*#define DEBUG*/

/****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/****************************************************************************/

#ifdef ASSERT
#undef ASSERT
#endif	/* ASSERT */

/****************************************************************************/

#define PUSH_ASSERTS()	PUSHDEBUGLEVEL(0)
#define PUSH_REPORTS()	PUSHDEBUGLEVEL(1)
#define PUSH_CALLS()	PUSHDEBUGLEVEL(2)
#define PUSH_ALL()	PUSHDEBUGLEVEL(2)
#define POP()		POPDEBUGLEVEL()

/****************************************************************************/

#if defined(DEBUG) && defined(__SASC)
 void _ASSERT(int x,const char *xs,const char *file,int line,const char *function);
 void _SHOWVALUE(unsigned long value,int size,const char *name,const char *file,int line);
 void _SHOWPOINTER(void *p,const char *name,const char *file,int line);
 void _SHOWSTRING(const char *string,const char *name,const char *file,int line);
 void _SHOWMSG(const char *msg,const char *file,int line);
 void _ENTER(const char *file,int line,const char *function);
 void _LEAVE(const char *file,int line,const char *function);
 void _RETURN(const char *file,int line,const char *function,unsigned long result);
 void _DPRINTF_HEADER(const char *file,int line);
 void VARARGS68K _DPRINTF(const char *format,...);
 void VARARGS68K _DLOG(const char *format,...);
 int  _SETDEBUGLEVEL(int level);
 void _PUSHDEBUGLEVEL(int level);
 void _POPDEBUGLEVEL(void);
 int  _GETDEBUGLEVEL(void);
 void _SETPROGRAMNAME(char *name);

 #define ASSERT(x)		_ASSERT((int)(x),#x,__FILE__,__LINE__,__FUNC__)
 #define ENTER()		_ENTER(__FILE__,__LINE__,__FUNC__)
 #define LEAVE()		_LEAVE(__FILE__,__LINE__,__FUNC__)
 #define RETURN(r)		_RETURN(__FILE__,__LINE__,__FUNC__,(unsigned long)r)
 #define SHOWVALUE(v)		_SHOWVALUE(v,sizeof(v),#v,__FILE__,__LINE__)
 #define SHOWPOINTER(p)		_SHOWPOINTER(p,#p,__FILE__,__LINE__)
 #define SHOWSTRING(s)		_SHOWSTRING(s,#s,__FILE__,__LINE__)
 #define SHOWMSG(s)		_SHOWMSG(s,__FILE__,__LINE__)
 #define D(s)			do { _DPRINTF_HEADER(__FILE__,__LINE__); _DPRINTF s; } while(0)
 #define PRINTHEADER()		_DPRINTF_HEADER(__FILE__,__LINE__)
 #define PRINTF(s)		_DLOG s
 #define LOG(s)			do { _DPRINTF_HEADER(__FILE__,__LINE__); _DLOG("<%s()>:",__FUNC__); _DLOG s; } while(0)
 #define SETDEBUGLEVEL(l)	_SETDEBUGLEVEL(l)
 #define PUSHDEBUGLEVEL(l)	_PUSHDEBUGLEVEL(l)
 #define POPDEBUGLEVEL()	_POPDEBUGLEVEL()
 #define SETPROGRAMNAME(n)	_SETPROGRAMNAME(n)
 #define GETDEBUGLEVEL()	_GETDEBUGLEVEL()

 #undef DEBUG
 #define DEBUG 1
#elif (defined(DEBUG) && defined(__GNUC__))
 void _ASSERT(int x,const char *xs,const char *file,int line,const char *function);
 void _SHOWVALUE(unsigned long value,int size,const char *name,const char *file,int line);
 void _SHOWPOINTER(void *p,const char *name,const char *file,int line);
 void _SHOWSTRING(const char *string,const char *name,const char *file,int line);
 void _SHOWMSG(const char *msg,const char *file,int line);
 void _ENTER(const char *file,int line,const char *function);
 void _LEAVE(const char *file,int line,const char *function);
 void _RETURN(const char *file,int line,const char *function,unsigned long result);
 void _DPRINTF_HEADER(const char *file,int line);
#if defined(__amigaos4__)
 void VARARGS68K _DPRINTF(const char *format,...);
 void VARARGS68K _DLOG(const char *format,...);
#else
 void _DPRINTF(const char *format,...);
 void _DLOG(const char *format,...);
#endif /* __amigaos4__ */
 int  _SETDEBUGLEVEL(int level);
 void _PUSHDEBUGLEVEL(int level);
 void _POPDEBUGLEVEL(void);
 int  _GETDEBUGLEVEL(void);
 void _SETPROGRAMNAME(char *name);

 #define ASSERT(x)		_ASSERT((int)(x),#x,__FILE__,__LINE__,__PRETTY_FUNCTION__)
 #define ENTER()		_ENTER(__FILE__,__LINE__,__PRETTY_FUNCTION__)
 #define LEAVE()		_LEAVE(__FILE__,__LINE__,__PRETTY_FUNCTION__)
 #define RETURN(r)		_RETURN(__FILE__,__LINE__,__PRETTY_FUNCTION__,(unsigned long)r)
 #define SHOWVALUE(v)		_SHOWVALUE(v,sizeof(v),#v,__FILE__,__LINE__)
 #define SHOWPOINTER(p)		_SHOWPOINTER(p,#p,__FILE__,__LINE__)
 #define SHOWSTRING(s)		_SHOWSTRING(s,#s,__FILE__,__LINE__)
 #define SHOWMSG(s)		_SHOWMSG(s,__FILE__,__LINE__)
 #define D(s)			do { _DPRINTF_HEADER(__FILE__,__LINE__); _DPRINTF s; } while(0)
 #define PRINTHEADER()		_DPRINTF_HEADER(__FILE__,__LINE__)
 #define PRINTF(s)		_DLOG s
 #define LOG(s)			do { _DPRINTF_HEADER(__FILE__,__LINE__); _DLOG("<%s()>:",__PRETTY_FUNCTION__); _DLOG s; } while(0)
 #define SETDEBUGLEVEL(l)	_SETDEBUGLEVEL(l)
 #define PUSHDEBUGLEVEL(l)	_PUSHDEBUGLEVEL(l)
 #define POPDEBUGLEVEL()	_POPDEBUGLEVEL()
 #define SETPROGRAMNAME(n)	_SETPROGRAMNAME(n)
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
