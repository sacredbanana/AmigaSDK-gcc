/* Automatically generated header (sfdc 1.11e)! Do not edit! */

#ifndef _INLINE_DOS_H
#define _INLINE_DOS_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef DOS_BASE_NAME
#define DOS_BASE_NAME DOSBase
#endif /* !DOS_BASE_NAME */

#define Open(___name, ___accessMode) \
      LP2(0x1e, BPTR, Open , CONST_STRPTR, ___name, d1, LONG, ___accessMode, d2,\
      , DOS_BASE_NAME)

#define Close(___file) \
      LP1(0x24, LONG, Close , BPTR, ___file, d1,\
      , DOS_BASE_NAME)

#define Read(___file, ___buffer, ___length) \
      LP3(0x2a, LONG, Read , BPTR, ___file, d1, APTR, ___buffer, d2, LONG, ___length, d3,\
      , DOS_BASE_NAME)

#define Write(___file, ___buffer, ___length) \
      LP3(0x30, LONG, Write , BPTR, ___file, d1, CONST_APTR, ___buffer, d2, LONG, ___length, d3,\
      , DOS_BASE_NAME)

#define Input() \
      LP0(0x36, BPTR, Input ,\
      , DOS_BASE_NAME)

#define Output() \
      LP0(0x3c, BPTR, Output ,\
      , DOS_BASE_NAME)

#define Seek(___file, ___position, ___offset) \
      LP3(0x42, LONG, Seek , BPTR, ___file, d1, LONG, ___position, d2, LONG, ___offset, d3,\
      , DOS_BASE_NAME)

#define DeleteFile(___name) \
      LP1(0x48, LONG, DeleteFile , CONST_STRPTR, ___name, d1,\
      , DOS_BASE_NAME)

#define Rename(___oldName, ___newName) \
      LP2(0x4e, LONG, Rename , CONST_STRPTR, ___oldName, d1, CONST_STRPTR, ___newName, d2,\
      , DOS_BASE_NAME)

#define Lock(___name, ___type) \
      LP2(0x54, BPTR, Lock , CONST_STRPTR, ___name, d1, LONG, ___type, d2,\
      , DOS_BASE_NAME)

#define UnLock(___lock) \
      LP1NR(0x5a, UnLock , BPTR, ___lock, d1,\
      , DOS_BASE_NAME)

#define DupLock(___lock) \
      LP1(0x60, BPTR, DupLock , BPTR, ___lock, d1,\
      , DOS_BASE_NAME)

#define Examine(___lock, ___fileInfoBlock) \
      LP2(0x66, LONG, Examine , BPTR, ___lock, d1, struct FileInfoBlock *, ___fileInfoBlock, d2,\
      , DOS_BASE_NAME)

#define ExNext(___lock, ___fileInfoBlock) \
      LP2(0x6c, LONG, ExNext , BPTR, ___lock, d1, struct FileInfoBlock *, ___fileInfoBlock, d2,\
      , DOS_BASE_NAME)

#define Info(___lock, ___parameterBlock) \
      LP2(0x72, LONG, Info , BPTR, ___lock, d1, struct InfoData *, ___parameterBlock, d2,\
      , DOS_BASE_NAME)

#define CreateDir(___name) \
      LP1(0x78, BPTR, CreateDir , CONST_STRPTR, ___name, d1,\
      , DOS_BASE_NAME)

#define CurrentDir(___lock) \
      LP1(0x7e, BPTR, CurrentDir , BPTR, ___lock, d1,\
      , DOS_BASE_NAME)

#define IoErr() \
      LP0(0x84, LONG, IoErr ,\
      , DOS_BASE_NAME)

#define CreateProc(___name, ___pri, ___segList, ___stackSize) \
      LP4(0x8a, struct MsgPort *, CreateProc , CONST_STRPTR, ___name, d1, LONG, ___pri, d2, BPTR, ___segList, d3, LONG, ___stackSize, d4,\
      , DOS_BASE_NAME)

#define Exit(___returnCode) \
      LP1NR(0x90, Exit , LONG, ___returnCode, d1,\
      , DOS_BASE_NAME)

#define LoadSeg(___name) \
      LP1(0x96, BPTR, LoadSeg , CONST_STRPTR, ___name, d1,\
      , DOS_BASE_NAME)

#define UnLoadSeg(___seglist) \
      LP1NR(0x9c, UnLoadSeg , BPTR, ___seglist, d1,\
      , DOS_BASE_NAME)

#define DeviceProc(___name) \
      LP1(0xae, struct MsgPort *, DeviceProc , CONST_STRPTR, ___name, d1,\
      , DOS_BASE_NAME)

#define SetComment(___name, ___comment) \
      LP2(0xb4, LONG, SetComment , CONST_STRPTR, ___name, d1, CONST_STRPTR, ___comment, d2,\
      , DOS_BASE_NAME)

#define SetProtection(___name, ___protect) \
      LP2(0xba, LONG, SetProtection , CONST_STRPTR, ___name, d1, LONG, ___protect, d2,\
      , DOS_BASE_NAME)

#define DateStamp(___date) \
      LP1(0xc0, struct DateStamp *, DateStamp , struct DateStamp *, ___date, d1,\
      , DOS_BASE_NAME)

#define Delay(___timeout) \
      LP1NR(0xc6, Delay , LONG, ___timeout, d1,\
      , DOS_BASE_NAME)

#define WaitForChar(___file, ___timeout) \
      LP2(0xcc, LONG, WaitForChar , BPTR, ___file, d1, LONG, ___timeout, d2,\
      , DOS_BASE_NAME)

#define ParentDir(___lock) \
      LP1(0xd2, BPTR, ParentDir , BPTR, ___lock, d1,\
      , DOS_BASE_NAME)

#define IsInteractive(___file) \
      LP1(0xd8, LONG, IsInteractive , BPTR, ___file, d1,\
      , DOS_BASE_NAME)

#define Execute(___string, ___file, ___file2) \
      LP3(0xde, LONG, Execute , CONST_STRPTR, ___string, d1, BPTR, ___file, d2, BPTR, ___file2, d3,\
      , DOS_BASE_NAME)

#endif /* !_INLINE_DOS_H */
