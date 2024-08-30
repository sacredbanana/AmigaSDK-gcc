
#ifdef __amigaos4__
  #error Include <proto/> header files, not <inline/> header files in OS4.
#endif 


#ifndef _INLINE_DOS_H
#define _INLINE_DOS_H

#ifndef CLIB_DOS_PROTOS_H
#define CLIB_DOS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef  DOS_RECORD_H
#include <dos/record.h>
#endif
#ifndef  DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef  DOS_DOSASL_H
#include <dos/dosasl.h>
#endif
#ifndef  DOS_VAR_H
#include <dos/var.h>
#endif
#ifndef  DOS_NOTIFY_H
#include <dos/notify.h>
#endif
#ifndef  DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef  DOS_EXALL_H
#include <dos/exall.h>
#endif
#ifndef  DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif
#ifndef  DOS_DOSTAGS_H
#include <dos/dostags.h>
#endif
#ifndef  DOS_MOUNT_H
#include <dos/mount.h>
#endif
#ifndef  DOS_DOSHUNKS_H
#include <dos/doshunks.h>
#endif
#ifndef  DOS_PATH_H
#include <dos/path.h>
#endif
#ifndef  DOS_ANCHORPATH_H
#include <dos/anchorpath.h>
#endif
#ifndef  DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef  DOS_ERRORS_H
#include <dos/errors.h>
#endif

#ifndef DOS_BASE_NAME
#define DOS_BASE_NAME DOSBase
#endif

#define Open(name, accessMode) ({ \
  CONST_STRPTR _Open_name = (name); \
  LONG _Open_accessMode = (accessMode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Open__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __Open__re __asm("d0"); \
  register CONST_STRPTR __Open_name __asm("d1") = (_Open_name); \
  register LONG __Open_accessMode __asm("d2") = (_Open_accessMode); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__Open__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Open__bn), "rf"(__Open_name), "rf"(__Open_accessMode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Close(file) ({ \
  BPTR _Close_file = (file); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Close__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Close__re __asm("d0"); \
  register BPTR __Close_file __asm("d1") = (_Close_file); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__Close__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Close__bn), "rf"(__Close_file) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Read(file, buffer, length) ({ \
  BPTR _Read_file = (file); \
  APTR _Read_buffer = (buffer); \
  LONG _Read_length = (length); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Read__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Read__re __asm("d0"); \
  register BPTR __Read_file __asm("d1") = (_Read_file); \
  register APTR __Read_buffer __asm("d2") = (_Read_buffer); \
  register LONG __Read_length __asm("d3") = (_Read_length); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__Read__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Read__bn), "rf"(__Read_file), "rf"(__Read_buffer), "rf"(__Read_length) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Write(file, buffer, length) ({ \
  BPTR _Write_file = (file); \
  CONST APTR _Write_buffer = (buffer); \
  LONG _Write_length = (length); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Write__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Write__re __asm("d0"); \
  register BPTR __Write_file __asm("d1") = (_Write_file); \
  register CONST APTR __Write_buffer __asm("d2") = (_Write_buffer); \
  register LONG __Write_length __asm("d3") = (_Write_length); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__Write__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Write__bn), "rf"(__Write_file), "rf"(__Write_buffer), "rf"(__Write_length) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Input() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Input__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __Input__re __asm("d0"); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__Input__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Input__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Output() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Output__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __Output__re __asm("d0"); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__Output__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Output__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETESeek(file, position, offset) ({ \
  BPTR _OBSOLETESeek_file = (file); \
  LONG _OBSOLETESeek_position = (position); \
  LONG _OBSOLETESeek_offset = (offset); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETESeek__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETESeek__re __asm("d0"); \
  register BPTR __OBSOLETESeek_file __asm("d1") = (_OBSOLETESeek_file); \
  register LONG __OBSOLETESeek_position __asm("d2") = (_OBSOLETESeek_position); \
  register LONG __OBSOLETESeek_offset __asm("d3") = (_OBSOLETESeek_offset); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__OBSOLETESeek__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETESeek__bn), "rf"(__OBSOLETESeek_file), "rf"(__OBSOLETESeek_position), "rf"(__OBSOLETESeek_offset) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Delete(name) ({ \
  CONST_STRPTR _Delete_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Delete__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Delete__re __asm("d0"); \
  register CONST_STRPTR __Delete_name __asm("d1") = (_Delete_name); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__Delete__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Delete__bn), "rf"(__Delete_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Rename(oldName, newName) ({ \
  CONST_STRPTR _Rename_oldName = (oldName); \
  CONST_STRPTR _Rename_newName = (newName); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Rename__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Rename__re __asm("d0"); \
  register CONST_STRPTR __Rename_oldName __asm("d1") = (_Rename_oldName); \
  register CONST_STRPTR __Rename_newName __asm("d2") = (_Rename_newName); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__Rename__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Rename__bn), "rf"(__Rename_oldName), "rf"(__Rename_newName) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Lock(name, type) ({ \
  CONST_STRPTR _Lock_name = (name); \
  LONG _Lock_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Lock__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __Lock__re __asm("d0"); \
  register CONST_STRPTR __Lock_name __asm("d1") = (_Lock_name); \
  register LONG __Lock_type __asm("d2") = (_Lock_type); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__Lock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Lock__bn), "rf"(__Lock_name), "rf"(__Lock_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnLock(lock) ({ \
  BPTR _UnLock_lock = (lock); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnLock__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __UnLock_lock __asm("d1") = (_UnLock_lock); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnLock__bn), "rf"(__UnLock_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DupLock(lock) ({ \
  BPTR _DupLock_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DupLock__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __DupLock__re __asm("d0"); \
  register BPTR __DupLock_lock __asm("d1") = (_DupLock_lock); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__DupLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DupLock__bn), "rf"(__DupLock_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExamine(lock, fileInfoBlock) ({ \
  BPTR _OBSOLETEExamine_lock = (lock); \
  struct FileInfoBlock * _OBSOLETEExamine_fileInfoBlock = (fileInfoBlock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExamine__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETEExamine__re __asm("d0"); \
  register BPTR __OBSOLETEExamine_lock __asm("d1") = (_OBSOLETEExamine_lock); \
  register struct FileInfoBlock * __OBSOLETEExamine_fileInfoBlock __asm("d2") = (_OBSOLETEExamine_fileInfoBlock); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__OBSOLETEExamine__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExamine__bn), "rf"(__OBSOLETEExamine_lock), "rf"(__OBSOLETEExamine_fileInfoBlock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExNext(lock, fileInfoBlock) ({ \
  BPTR _OBSOLETEExNext_lock = (lock); \
  struct FileInfoBlock * _OBSOLETEExNext_fileInfoBlock = (fileInfoBlock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExNext__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETEExNext__re __asm("d0"); \
  register BPTR __OBSOLETEExNext_lock __asm("d1") = (_OBSOLETEExNext_lock); \
  register struct FileInfoBlock * __OBSOLETEExNext_fileInfoBlock __asm("d2") = (_OBSOLETEExNext_fileInfoBlock); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__OBSOLETEExNext__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExNext__bn), "rf"(__OBSOLETEExNext_lock), "rf"(__OBSOLETEExNext_fileInfoBlock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Info(lock, parameterBlock) ({ \
  BPTR _Info_lock = (lock); \
  struct InfoData * _Info_parameterBlock = (parameterBlock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Info__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Info__re __asm("d0"); \
  register BPTR __Info_lock __asm("d1") = (_Info_lock); \
  register struct InfoData * __Info_parameterBlock __asm("d2") = (_Info_parameterBlock); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__Info__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Info__bn), "rf"(__Info_lock), "rf"(__Info_parameterBlock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CreateDir(name) ({ \
  CONST_STRPTR _CreateDir_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CreateDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __CreateDir__re __asm("d0"); \
  register CONST_STRPTR __CreateDir_name __asm("d1") = (_CreateDir_name); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__CreateDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CreateDir__bn), "rf"(__CreateDir_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetCurrentDir(lock) ({ \
  BPTR _SetCurrentDir_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetCurrentDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __SetCurrentDir__re __asm("d0"); \
  register BPTR __SetCurrentDir_lock __asm("d1") = (_SetCurrentDir_lock); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__SetCurrentDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetCurrentDir__bn), "rf"(__SetCurrentDir_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define IoErr() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __IoErr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __IoErr__re __asm("d0"); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__IoErr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__IoErr__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETECreateProc(name, pri, segList, stackSize) ({ \
  CONST_STRPTR _OBSOLETECreateProc_name = (name); \
  LONG _OBSOLETECreateProc_pri = (pri); \
  BPTR _OBSOLETECreateProc_segList = (segList); \
  LONG _OBSOLETECreateProc_stackSize = (stackSize); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETECreateProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __OBSOLETECreateProc__re __asm("d0"); \
  register CONST_STRPTR __OBSOLETECreateProc_name __asm("d1") = (_OBSOLETECreateProc_name); \
  register LONG __OBSOLETECreateProc_pri __asm("d2") = (_OBSOLETECreateProc_pri); \
  register BPTR __OBSOLETECreateProc_segList __asm("d3") = (_OBSOLETECreateProc_segList); \
  register LONG __OBSOLETECreateProc_stackSize __asm("d4") = (_OBSOLETECreateProc_stackSize); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__OBSOLETECreateProc__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETECreateProc__bn), "rf"(__OBSOLETECreateProc_name), "rf"(__OBSOLETECreateProc_pri), "rf"(__OBSOLETECreateProc_segList), "rf"(__OBSOLETECreateProc_stackSize) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define LoadSegOVL(name, hunktab, scb) ({ \
  CONST_STRPTR _LoadSegOVL_name = (name); \
  BPTR _LoadSegOVL_hunktab = (hunktab); \
  BPTR _LoadSegOVL_scb = (scb); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LoadSegOVL__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __LoadSegOVL__re __asm("d0"); \
  register CONST_STRPTR __LoadSegOVL_name __asm("d1") = (_LoadSegOVL_name); \
  register BPTR __LoadSegOVL_hunktab __asm("d2") = (_LoadSegOVL_hunktab); \
  register BPTR __LoadSegOVL_scb __asm("d3") = (_LoadSegOVL_scb); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__LoadSegOVL__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LoadSegOVL__bn), "rf"(__LoadSegOVL_name), "rf"(__LoadSegOVL_hunktab), "rf"(__LoadSegOVL_scb) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnLoadSeg(seglist) ({ \
  BPTR _UnLoadSeg_seglist = (seglist); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnLoadSeg__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __UnLoadSeg_seglist __asm("d1") = (_UnLoadSeg_seglist); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnLoadSeg__bn), "rf"(__UnLoadSeg_seglist) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LoadSeg(name) ({ \
  CONST_STRPTR _LoadSeg_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LoadSeg__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __LoadSeg__re __asm("d0"); \
  register CONST_STRPTR __LoadSeg_name __asm("d1") = (_LoadSeg_name); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__LoadSeg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LoadSeg__bn), "rf"(__LoadSeg_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEDeviceProc(name) ({ \
  CONST_STRPTR _OBSOLETEDeviceProc_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEDeviceProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __OBSOLETEDeviceProc__re __asm("d0"); \
  register CONST_STRPTR __OBSOLETEDeviceProc_name __asm("d1") = (_OBSOLETEDeviceProc_name); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__OBSOLETEDeviceProc__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEDeviceProc__bn), "rf"(__OBSOLETEDeviceProc_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetComment(name, comment) ({ \
  CONST_STRPTR _SetComment_name = (name); \
  CONST_STRPTR _SetComment_comment = (comment); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetComment__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetComment__re __asm("d0"); \
  register CONST_STRPTR __SetComment_name __asm("d1") = (_SetComment_name); \
  register CONST_STRPTR __SetComment_comment __asm("d2") = (_SetComment_comment); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__SetComment__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetComment__bn), "rf"(__SetComment_name), "rf"(__SetComment_comment) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetProtection(name, protect) ({ \
  CONST_STRPTR _SetProtection_name = (name); \
  ULONG _SetProtection_protect = (protect); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetProtection__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetProtection__re __asm("d0"); \
  register CONST_STRPTR __SetProtection_name __asm("d1") = (_SetProtection_name); \
  register ULONG __SetProtection_protect __asm("d2") = (_SetProtection_protect); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__SetProtection__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetProtection__bn), "rf"(__SetProtection_name), "rf"(__SetProtection_protect) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DateStamp(date) ({ \
  struct DateStamp * _DateStamp_date = (date); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DateStamp__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DateStamp * __DateStamp__re __asm("d0"); \
  register struct DateStamp * __DateStamp_date __asm("d1") = (_DateStamp_date); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__DateStamp__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DateStamp__bn), "rf"(__DateStamp_date) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Delay(timeout) ({ \
  ULONG _Delay_timeout = (timeout); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Delay__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __Delay_timeout __asm("d1") = (_Delay_timeout); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Delay__bn), "rf"(__Delay_timeout) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WaitForChar(file, timeout) ({ \
  BPTR _WaitForChar_file = (file); \
  LONG _WaitForChar_timeout = (timeout); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WaitForChar__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __WaitForChar__re __asm("d0"); \
  register BPTR __WaitForChar_file __asm("d1") = (_WaitForChar_file); \
  register LONG __WaitForChar_timeout __asm("d2") = (_WaitForChar_timeout); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__WaitForChar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WaitForChar__bn), "rf"(__WaitForChar_file), "rf"(__WaitForChar_timeout) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ParentDir(lock) ({ \
  BPTR _ParentDir_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ParentDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __ParentDir__re __asm("d0"); \
  register BPTR __ParentDir_lock __asm("d1") = (_ParentDir_lock); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__ParentDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ParentDir__bn), "rf"(__ParentDir_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define IsInteractive(file) ({ \
  BPTR _IsInteractive_file = (file); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __IsInteractive__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __IsInteractive__re __asm("d0"); \
  register BPTR __IsInteractive_file __asm("d1") = (_IsInteractive_file); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__IsInteractive__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__IsInteractive__bn), "rf"(__IsInteractive_file) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExecute(string, file, file2) ({ \
  CONST_STRPTR _OBSOLETEExecute_string = (string); \
  BPTR _OBSOLETEExecute_file = (file); \
  BPTR _OBSOLETEExecute_file2 = (file2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExecute__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETEExecute__re __asm("d0"); \
  register CONST_STRPTR __OBSOLETEExecute_string __asm("d1") = (_OBSOLETEExecute_string); \
  register BPTR __OBSOLETEExecute_file __asm("d2") = (_OBSOLETEExecute_file); \
  register BPTR __OBSOLETEExecute_file2 __asm("d3") = (_OBSOLETEExecute_file2); \
  __asm volatile ("jsr a6@(-222:W)" \
  : "=r"(__OBSOLETEExecute__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExecute__bn), "rf"(__OBSOLETEExecute_string), "rf"(__OBSOLETEExecute_file), "rf"(__OBSOLETEExecute_file2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AllocDosObject(type, tags) ({ \
  ULONG _AllocDosObject_type = (type); \
  const struct TagItem * _AllocDosObject_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AllocDosObject__bn __asm("a6") = DOS_BASE_NAME;\
  register APTR __AllocDosObject__re __asm("d0"); \
  register ULONG __AllocDosObject_type __asm("d1") = (_AllocDosObject_type); \
  register const struct TagItem * __AllocDosObject_tags __asm("d2") = (_AllocDosObject_tags); \
  __asm volatile ("jsr a6@(-228:W)" \
  : "=r"(__AllocDosObject__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AllocDosObject__bn), "rf"(__AllocDosObject_type), "rf"(__AllocDosObject_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AllocDosObjectTagList(type, tags) AllocDosObject((type), (tags))

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___AllocDosObjectTags(struct Library * DOSBase, ULONG type, ULONG tags, ...)
{
  return AllocDosObject(type, (const struct TagItem *) &tags);
}

#define AllocDosObjectTags(type...) ___AllocDosObjectTags(DOS_BASE_NAME, type)
#endif

#define FreeDosObject(type, ptr) ({ \
  ULONG _FreeDosObject_type = (type); \
  APTR _FreeDosObject_ptr = (ptr); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeDosObject__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __FreeDosObject_type __asm("d1") = (_FreeDosObject_type); \
  register APTR __FreeDosObject_ptr __asm("d2") = (_FreeDosObject_ptr); \
  __asm volatile ("jsr a6@(-234:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeDosObject__bn), "rf"(__FreeDosObject_type), "rf"(__FreeDosObject_ptr) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DoPkt(port, action, arg1, arg2, arg3, arg4, arg5) ({ \
  struct MsgPort * _DoPkt_port = (port); \
  LONG _DoPkt_action = (action); \
  LONG _DoPkt_arg1 = (arg1); \
  LONG _DoPkt_arg2 = (arg2); \
  LONG _DoPkt_arg3 = (arg3); \
  LONG _DoPkt_arg4 = (arg4); \
  LONG _DoPkt_arg5 = (arg5); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt__re __asm("d0"); \
  register struct MsgPort * __DoPkt_port __asm("d1") = (_DoPkt_port); \
  register LONG __DoPkt_action __asm("d2") = (_DoPkt_action); \
  register LONG __DoPkt_arg1 __asm("d3") = (_DoPkt_arg1); \
  register LONG __DoPkt_arg2 __asm("d4") = (_DoPkt_arg2); \
  register LONG __DoPkt_arg3 __asm("d5") = (_DoPkt_arg3); \
  register LONG __DoPkt_arg4 __asm("d6") = (_DoPkt_arg4); \
  register LONG __DoPkt_arg5 __asm("d7") = (_DoPkt_arg5); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt__bn), "rf"(__DoPkt_port), "rf"(__DoPkt_action), "rf"(__DoPkt_arg1), "rf"(__DoPkt_arg2), "rf"(__DoPkt_arg3), "rf"(__DoPkt_arg4), "rf"(__DoPkt_arg5) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DoPkt0(port, action) ({ \
  struct MsgPort * _DoPkt0_port = (port); \
  LONG _DoPkt0_action = (action); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt0__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt0__re __asm("d0"); \
  register struct MsgPort * __DoPkt0_port __asm("d1") = (_DoPkt0_port); \
  register LONG __DoPkt0_action __asm("d2") = (_DoPkt0_action); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt0__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt0__bn), "rf"(__DoPkt0_port), "rf"(__DoPkt0_action) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DoPkt1(port, action, arg1) ({ \
  struct MsgPort * _DoPkt1_port = (port); \
  LONG _DoPkt1_action = (action); \
  LONG _DoPkt1_arg1 = (arg1); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt1__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt1__re __asm("d0"); \
  register struct MsgPort * __DoPkt1_port __asm("d1") = (_DoPkt1_port); \
  register LONG __DoPkt1_action __asm("d2") = (_DoPkt1_action); \
  register LONG __DoPkt1_arg1 __asm("d3") = (_DoPkt1_arg1); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt1__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt1__bn), "rf"(__DoPkt1_port), "rf"(__DoPkt1_action), "rf"(__DoPkt1_arg1) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DoPkt2(port, action, arg1, arg2) ({ \
  struct MsgPort * _DoPkt2_port = (port); \
  LONG _DoPkt2_action = (action); \
  LONG _DoPkt2_arg1 = (arg1); \
  LONG _DoPkt2_arg2 = (arg2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt2__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt2__re __asm("d0"); \
  register struct MsgPort * __DoPkt2_port __asm("d1") = (_DoPkt2_port); \
  register LONG __DoPkt2_action __asm("d2") = (_DoPkt2_action); \
  register LONG __DoPkt2_arg1 __asm("d3") = (_DoPkt2_arg1); \
  register LONG __DoPkt2_arg2 __asm("d4") = (_DoPkt2_arg2); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt2__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt2__bn), "rf"(__DoPkt2_port), "rf"(__DoPkt2_action), "rf"(__DoPkt2_arg1), "rf"(__DoPkt2_arg2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DoPkt3(port, action, arg1, arg2, arg3) ({ \
  struct MsgPort * _DoPkt3_port = (port); \
  LONG _DoPkt3_action = (action); \
  LONG _DoPkt3_arg1 = (arg1); \
  LONG _DoPkt3_arg2 = (arg2); \
  LONG _DoPkt3_arg3 = (arg3); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt3__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt3__re __asm("d0"); \
  register struct MsgPort * __DoPkt3_port __asm("d1") = (_DoPkt3_port); \
  register LONG __DoPkt3_action __asm("d2") = (_DoPkt3_action); \
  register LONG __DoPkt3_arg1 __asm("d3") = (_DoPkt3_arg1); \
  register LONG __DoPkt3_arg2 __asm("d4") = (_DoPkt3_arg2); \
  register LONG __DoPkt3_arg3 __asm("d5") = (_DoPkt3_arg3); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt3__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt3__bn), "rf"(__DoPkt3_port), "rf"(__DoPkt3_action), "rf"(__DoPkt3_arg1), "rf"(__DoPkt3_arg2), "rf"(__DoPkt3_arg3) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DoPkt4(port, action, arg1, arg2, arg3, arg4) ({ \
  struct MsgPort * _DoPkt4_port = (port); \
  LONG _DoPkt4_action = (action); \
  LONG _DoPkt4_arg1 = (arg1); \
  LONG _DoPkt4_arg2 = (arg2); \
  LONG _DoPkt4_arg3 = (arg3); \
  LONG _DoPkt4_arg4 = (arg4); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DoPkt4__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DoPkt4__re __asm("d0"); \
  register struct MsgPort * __DoPkt4_port __asm("d1") = (_DoPkt4_port); \
  register LONG __DoPkt4_action __asm("d2") = (_DoPkt4_action); \
  register LONG __DoPkt4_arg1 __asm("d3") = (_DoPkt4_arg1); \
  register LONG __DoPkt4_arg2 __asm("d4") = (_DoPkt4_arg2); \
  register LONG __DoPkt4_arg3 __asm("d5") = (_DoPkt4_arg3); \
  register LONG __DoPkt4_arg4 __asm("d6") = (_DoPkt4_arg4); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__DoPkt4__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DoPkt4__bn), "rf"(__DoPkt4_port), "rf"(__DoPkt4_action), "rf"(__DoPkt4_arg1), "rf"(__DoPkt4_arg2), "rf"(__DoPkt4_arg3), "rf"(__DoPkt4_arg4) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SendPkt(dp, port, replyport) ({ \
  struct DosPacket * _SendPkt_dp = (dp); \
  struct MsgPort * _SendPkt_port = (port); \
  struct MsgPort * _SendPkt_replyport = (replyport); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SendPkt__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosPacket * __SendPkt_dp __asm("d1") = (_SendPkt_dp); \
  register struct MsgPort * __SendPkt_port __asm("d2") = (_SendPkt_port); \
  register struct MsgPort * __SendPkt_replyport __asm("d3") = (_SendPkt_replyport); \
  __asm volatile ("jsr a6@(-246:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SendPkt__bn), "rf"(__SendPkt_dp), "rf"(__SendPkt_port), "rf"(__SendPkt_replyport) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WaitPkt(task_replyport) ({ \
  struct MsgPort * _WaitPkt_task_replyport = (task_replyport); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WaitPkt__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosPacket * __WaitPkt__re __asm("d0"); \
  register struct MsgPort * __WaitPkt_task_replyport __asm("d1") = (_WaitPkt_task_replyport); \
  __asm volatile ("jsr a6@(-252:W)" \
  : "=r"(__WaitPkt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WaitPkt__bn), "rf"(__WaitPkt_task_replyport) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReplyPkt(dp, res1, res2) ({ \
  struct DosPacket * _ReplyPkt_dp = (dp); \
  LONG _ReplyPkt_res1 = (res1); \
  LONG _ReplyPkt_res2 = (res2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReplyPkt__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ReplyPkt__re __asm("d0"); \
  register struct DosPacket * __ReplyPkt_dp __asm("d1") = (_ReplyPkt_dp); \
  register LONG __ReplyPkt_res1 __asm("d2") = (_ReplyPkt_res1); \
  register LONG __ReplyPkt_res2 __asm("d3") = (_ReplyPkt_res2); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__ReplyPkt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReplyPkt__bn), "rf"(__ReplyPkt_dp), "rf"(__ReplyPkt_res1), "rf"(__ReplyPkt_res2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define LockRecord(fh, offset, length, mode, timeout) ({ \
  BPTR _LockRecord_fh = (fh); \
  ULONG _LockRecord_offset = (offset); \
  ULONG _LockRecord_length = (length); \
  ULONG _LockRecord_mode = (mode); \
  ULONG _LockRecord_timeout = (timeout); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LockRecord__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __LockRecord__re __asm("d0"); \
  register BPTR __LockRecord_fh __asm("d1") = (_LockRecord_fh); \
  register ULONG __LockRecord_offset __asm("d2") = (_LockRecord_offset); \
  register ULONG __LockRecord_length __asm("d3") = (_LockRecord_length); \
  register ULONG __LockRecord_mode __asm("d4") = (_LockRecord_mode); \
  register ULONG __LockRecord_timeout __asm("d5") = (_LockRecord_timeout); \
  __asm volatile ("jsr a6@(-270:W)" \
  : "=r"(__LockRecord__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LockRecord__bn), "rf"(__LockRecord_fh), "rf"(__LockRecord_offset), "rf"(__LockRecord_length), "rf"(__LockRecord_mode), "rf"(__LockRecord_timeout) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define LockRecords(recArray, timeout) ({ \
  struct RecordLock * _LockRecords_recArray = (recArray); \
  ULONG _LockRecords_timeout = (timeout); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LockRecords__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __LockRecords__re __asm("d0"); \
  register struct RecordLock * __LockRecords_recArray __asm("d1") = (_LockRecords_recArray); \
  register ULONG __LockRecords_timeout __asm("d2") = (_LockRecords_timeout); \
  __asm volatile ("jsr a6@(-276:W)" \
  : "=r"(__LockRecords__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LockRecords__bn), "rf"(__LockRecords_recArray), "rf"(__LockRecords_timeout) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnLockRecord(fh, offset, length) ({ \
  BPTR _UnLockRecord_fh = (fh); \
  ULONG _UnLockRecord_offset = (offset); \
  ULONG _UnLockRecord_length = (length); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnLockRecord__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __UnLockRecord__re __asm("d0"); \
  register BPTR __UnLockRecord_fh __asm("d1") = (_UnLockRecord_fh); \
  register ULONG __UnLockRecord_offset __asm("d2") = (_UnLockRecord_offset); \
  register ULONG __UnLockRecord_length __asm("d3") = (_UnLockRecord_length); \
  __asm volatile ("jsr a6@(-282:W)" \
  : "=r"(__UnLockRecord__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnLockRecord__bn), "rf"(__UnLockRecord_fh), "rf"(__UnLockRecord_offset), "rf"(__UnLockRecord_length) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnLockRecords(recArray) ({ \
  struct RecordLock * _UnLockRecords_recArray = (recArray); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnLockRecords__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __UnLockRecords__re __asm("d0"); \
  register struct RecordLock * __UnLockRecords_recArray __asm("d1") = (_UnLockRecords_recArray); \
  __asm volatile ("jsr a6@(-288:W)" \
  : "=r"(__UnLockRecords__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnLockRecords__bn), "rf"(__UnLockRecords_recArray) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SelectInput(fh) ({ \
  BPTR _SelectInput_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SelectInput__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __SelectInput__re __asm("d0"); \
  register BPTR __SelectInput_fh __asm("d1") = (_SelectInput_fh); \
  __asm volatile ("jsr a6@(-294:W)" \
  : "=r"(__SelectInput__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SelectInput__bn), "rf"(__SelectInput_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SelectOutput(fh) ({ \
  BPTR _SelectOutput_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SelectOutput__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __SelectOutput__re __asm("d0"); \
  register BPTR __SelectOutput_fh __asm("d1") = (_SelectOutput_fh); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__SelectOutput__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SelectOutput__bn), "rf"(__SelectOutput_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FGetC(fh) ({ \
  BPTR _FGetC_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FGetC__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FGetC__re __asm("d0"); \
  register BPTR __FGetC_fh __asm("d1") = (_FGetC_fh); \
  __asm volatile ("jsr a6@(-306:W)" \
  : "=r"(__FGetC__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FGetC__bn), "rf"(__FGetC_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FPutC(fh, ch) ({ \
  BPTR _FPutC_fh = (fh); \
  LONG _FPutC_ch = (ch); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FPutC__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FPutC__re __asm("d0"); \
  register BPTR __FPutC_fh __asm("d1") = (_FPutC_fh); \
  register LONG __FPutC_ch __asm("d2") = (_FPutC_ch); \
  __asm volatile ("jsr a6@(-312:W)" \
  : "=r"(__FPutC__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FPutC__bn), "rf"(__FPutC_fh), "rf"(__FPutC_ch) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FUnGetC(fh, character) ({ \
  BPTR _FUnGetC_fh = (fh); \
  LONG _FUnGetC_character = (character); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FUnGetC__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FUnGetC__re __asm("d0"); \
  register BPTR __FUnGetC_fh __asm("d1") = (_FUnGetC_fh); \
  register LONG __FUnGetC_character __asm("d2") = (_FUnGetC_character); \
  __asm volatile ("jsr a6@(-318:W)" \
  : "=r"(__FUnGetC__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FUnGetC__bn), "rf"(__FUnGetC_fh), "rf"(__FUnGetC_character) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FRead(fh, block, blocklen, number) ({ \
  BPTR _FRead_fh = (fh); \
  APTR _FRead_block = (block); \
  ULONG _FRead_blocklen = (blocklen); \
  ULONG _FRead_number = (number); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FRead__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __FRead__re __asm("d0"); \
  register BPTR __FRead_fh __asm("d1") = (_FRead_fh); \
  register APTR __FRead_block __asm("d2") = (_FRead_block); \
  register ULONG __FRead_blocklen __asm("d3") = (_FRead_blocklen); \
  register ULONG __FRead_number __asm("d4") = (_FRead_number); \
  __asm volatile ("jsr a6@(-324:W)" \
  : "=r"(__FRead__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FRead__bn), "rf"(__FRead_fh), "rf"(__FRead_block), "rf"(__FRead_blocklen), "rf"(__FRead_number) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FWrite(fh, block, blocklen, number) ({ \
  BPTR _FWrite_fh = (fh); \
  const APTR _FWrite_block = (block); \
  ULONG _FWrite_blocklen = (blocklen); \
  ULONG _FWrite_number = (number); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FWrite__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __FWrite__re __asm("d0"); \
  register BPTR __FWrite_fh __asm("d1") = (_FWrite_fh); \
  register const APTR __FWrite_block __asm("d2") = (_FWrite_block); \
  register ULONG __FWrite_blocklen __asm("d3") = (_FWrite_blocklen); \
  register ULONG __FWrite_number __asm("d4") = (_FWrite_number); \
  __asm volatile ("jsr a6@(-330:W)" \
  : "=r"(__FWrite__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FWrite__bn), "rf"(__FWrite_fh), "rf"(__FWrite_block), "rf"(__FWrite_blocklen), "rf"(__FWrite_number) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FGets(fh, buf, buflen) ({ \
  BPTR _FGets_fh = (fh); \
  STRPTR _FGets_buf = (buf); \
  ULONG _FGets_buflen = (buflen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FGets__bn __asm("a6") = DOS_BASE_NAME;\
  register STRPTR __FGets__re __asm("d0"); \
  register BPTR __FGets_fh __asm("d1") = (_FGets_fh); \
  register STRPTR __FGets_buf __asm("d2") = (_FGets_buf); \
  register ULONG __FGets_buflen __asm("d3") = (_FGets_buflen); \
  __asm volatile ("jsr a6@(-336:W)" \
  : "=r"(__FGets__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FGets__bn), "rf"(__FGets_fh), "rf"(__FGets_buf), "rf"(__FGets_buflen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FPuts(fh, str) ({ \
  BPTR _FPuts_fh = (fh); \
  CONST_STRPTR _FPuts_str = (str); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FPuts__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FPuts__re __asm("d0"); \
  register BPTR __FPuts_fh __asm("d1") = (_FPuts_fh); \
  register CONST_STRPTR __FPuts_str __asm("d2") = (_FPuts_str); \
  __asm volatile ("jsr a6@(-342:W)" \
  : "=r"(__FPuts__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FPuts__bn), "rf"(__FPuts_fh), "rf"(__FPuts_str) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define VFPrintf(fh, format, argarray) ({ \
  BPTR _VFPrintf_fh = (fh); \
  CONST_STRPTR _VFPrintf_format = (format); \
  CONST APTR _VFPrintf_argarray = (argarray); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __VFPrintf__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __VFPrintf__re __asm("d0"); \
  register BPTR __VFPrintf_fh __asm("d1") = (_VFPrintf_fh); \
  register CONST_STRPTR __VFPrintf_format __asm("d2") = (_VFPrintf_format); \
  register CONST APTR __VFPrintf_argarray __asm("d3") = (_VFPrintf_argarray); \
  __asm volatile ("jsr a6@(-354:W)" \
  : "=r"(__VFPrintf__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__VFPrintf__bn), "rf"(__VFPrintf_fh), "rf"(__VFPrintf_format), "rf"(__VFPrintf_argarray) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___FPrintf(struct Library * DOSBase, BPTR fh, CONST_STRPTR format, ULONG argarray, ...)
{
  return VFPrintf(fh, format, (CONST APTR) &argarray);
}

#define FPrintf(fh, format...) ___FPrintf(DOS_BASE_NAME, fh, format)
#endif

#define FFlush(fh) ({ \
  BPTR _FFlush_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FFlush__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FFlush__re __asm("d0"); \
  register BPTR __FFlush_fh __asm("d1") = (_FFlush_fh); \
  __asm volatile ("jsr a6@(-360:W)" \
  : "=r"(__FFlush__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FFlush__bn), "rf"(__FFlush_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETESetVBuf(fh, buff, type, size) ({ \
  BPTR _OBSOLETESetVBuf_fh = (fh); \
  STRPTR _OBSOLETESetVBuf_buff = (buff); \
  LONG _OBSOLETESetVBuf_type = (type); \
  LONG _OBSOLETESetVBuf_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETESetVBuf__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETESetVBuf__re __asm("d0"); \
  register BPTR __OBSOLETESetVBuf_fh __asm("d1") = (_OBSOLETESetVBuf_fh); \
  register STRPTR __OBSOLETESetVBuf_buff __asm("d2") = (_OBSOLETESetVBuf_buff); \
  register LONG __OBSOLETESetVBuf_type __asm("d3") = (_OBSOLETESetVBuf_type); \
  register LONG __OBSOLETESetVBuf_size __asm("d4") = (_OBSOLETESetVBuf_size); \
  __asm volatile ("jsr a6@(-366:W)" \
  : "=r"(__OBSOLETESetVBuf__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETESetVBuf__bn), "rf"(__OBSOLETESetVBuf_fh), "rf"(__OBSOLETESetVBuf_buff), "rf"(__OBSOLETESetVBuf_type), "rf"(__OBSOLETESetVBuf_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DupLockFromFH(fh) ({ \
  BPTR _DupLockFromFH_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DupLockFromFH__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __DupLockFromFH__re __asm("d0"); \
  register BPTR __DupLockFromFH_fh __asm("d1") = (_DupLockFromFH_fh); \
  __asm volatile ("jsr a6@(-372:W)" \
  : "=r"(__DupLockFromFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DupLockFromFH__bn), "rf"(__DupLockFromFH_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OpenFromLock(lock) ({ \
  BPTR _OpenFromLock_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OpenFromLock__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __OpenFromLock__re __asm("d0"); \
  register BPTR __OpenFromLock_lock __asm("d1") = (_OpenFromLock_lock); \
  __asm volatile ("jsr a6@(-378:W)" \
  : "=r"(__OpenFromLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OpenFromLock__bn), "rf"(__OpenFromLock_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ParentOfFH(fh) ({ \
  BPTR _ParentOfFH_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ParentOfFH__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __ParentOfFH__re __asm("d0"); \
  register BPTR __ParentOfFH_fh __asm("d1") = (_ParentOfFH_fh); \
  __asm volatile ("jsr a6@(-384:W)" \
  : "=r"(__ParentOfFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ParentOfFH__bn), "rf"(__ParentOfFH_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExamineFH(fh, fib) ({ \
  BPTR _OBSOLETEExamineFH_fh = (fh); \
  struct FileInfoBlock * _OBSOLETEExamineFH_fib = (fib); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExamineFH__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETEExamineFH__re __asm("d0"); \
  register BPTR __OBSOLETEExamineFH_fh __asm("d1") = (_OBSOLETEExamineFH_fh); \
  register struct FileInfoBlock * __OBSOLETEExamineFH_fib __asm("d2") = (_OBSOLETEExamineFH_fib); \
  __asm volatile ("jsr a6@(-390:W)" \
  : "=r"(__OBSOLETEExamineFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExamineFH__bn), "rf"(__OBSOLETEExamineFH_fh), "rf"(__OBSOLETEExamineFH_fib) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetDate(name, date) ({ \
  CONST_STRPTR _SetDate_name = (name); \
  const struct DateStamp * _SetDate_date = (date); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetDate__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetDate__re __asm("d0"); \
  register CONST_STRPTR __SetDate_name __asm("d1") = (_SetDate_name); \
  register const struct DateStamp * __SetDate_date __asm("d2") = (_SetDate_date); \
  __asm volatile ("jsr a6@(-396:W)" \
  : "=r"(__SetDate__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetDate__bn), "rf"(__SetDate_name), "rf"(__SetDate_date) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NameFromLock(lock, buffer, len) ({ \
  BPTR _NameFromLock_lock = (lock); \
  STRPTR _NameFromLock_buffer = (buffer); \
  LONG _NameFromLock_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NameFromLock__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NameFromLock__re __asm("d0"); \
  register BPTR __NameFromLock_lock __asm("d1") = (_NameFromLock_lock); \
  register STRPTR __NameFromLock_buffer __asm("d2") = (_NameFromLock_buffer); \
  register LONG __NameFromLock_len __asm("d3") = (_NameFromLock_len); \
  __asm volatile ("jsr a6@(-402:W)" \
  : "=r"(__NameFromLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NameFromLock__bn), "rf"(__NameFromLock_lock), "rf"(__NameFromLock_buffer), "rf"(__NameFromLock_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NameFromFH(fh, buffer, len) ({ \
  BPTR _NameFromFH_fh = (fh); \
  STRPTR _NameFromFH_buffer = (buffer); \
  LONG _NameFromFH_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NameFromFH__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NameFromFH__re __asm("d0"); \
  register BPTR __NameFromFH_fh __asm("d1") = (_NameFromFH_fh); \
  register STRPTR __NameFromFH_buffer __asm("d2") = (_NameFromFH_buffer); \
  register LONG __NameFromFH_len __asm("d3") = (_NameFromFH_len); \
  __asm volatile ("jsr a6@(-408:W)" \
  : "=r"(__NameFromFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NameFromFH__bn), "rf"(__NameFromFH_fh), "rf"(__NameFromFH_buffer), "rf"(__NameFromFH_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SplitName(name, seperator, buf, oldpos, size) ({ \
  CONST_STRPTR _SplitName_name = (name); \
  ULONG _SplitName_seperator = (seperator); \
  STRPTR _SplitName_buf = (buf); \
  LONG _SplitName_oldpos = (oldpos); \
  LONG _SplitName_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SplitName__bn __asm("a6") = DOS_BASE_NAME;\
  register WORD __SplitName__re __asm("d0"); \
  register CONST_STRPTR __SplitName_name __asm("d1") = (_SplitName_name); \
  register ULONG __SplitName_seperator __asm("d2") = (_SplitName_seperator); \
  register STRPTR __SplitName_buf __asm("d3") = (_SplitName_buf); \
  register LONG __SplitName_oldpos __asm("d4") = (_SplitName_oldpos); \
  register LONG __SplitName_size __asm("d5") = (_SplitName_size); \
  __asm volatile ("jsr a6@(-414:W)" \
  : "=r"(__SplitName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SplitName__bn), "rf"(__SplitName_name), "rf"(__SplitName_seperator), "rf"(__SplitName_buf), "rf"(__SplitName_oldpos), "rf"(__SplitName_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SameLock(lock1, lock2) ({ \
  BPTR _SameLock_lock1 = (lock1); \
  BPTR _SameLock_lock2 = (lock2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SameLock__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SameLock__re __asm("d0"); \
  register BPTR __SameLock_lock1 __asm("d1") = (_SameLock_lock1); \
  register BPTR __SameLock_lock2 __asm("d2") = (_SameLock_lock2); \
  __asm volatile ("jsr a6@(-420:W)" \
  : "=r"(__SameLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SameLock__bn), "rf"(__SameLock_lock1), "rf"(__SameLock_lock2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetMode(fh, mode) ({ \
  BPTR _SetMode_fh = (fh); \
  LONG _SetMode_mode = (mode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetMode__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetMode__re __asm("d0"); \
  register BPTR __SetMode_fh __asm("d1") = (_SetMode_fh); \
  register LONG __SetMode_mode __asm("d2") = (_SetMode_mode); \
  __asm volatile ("jsr a6@(-426:W)" \
  : "=r"(__SetMode__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetMode__bn), "rf"(__SetMode_fh), "rf"(__SetMode_mode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExAll(lock, buffer, size, data, control) ({ \
  BPTR _OBSOLETEExAll_lock = (lock); \
  struct ExAllData * _OBSOLETEExAll_buffer = (buffer); \
  LONG _OBSOLETEExAll_size = (size); \
  LONG _OBSOLETEExAll_data = (data); \
  struct ExAllControl * _OBSOLETEExAll_control = (control); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExAll__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETEExAll__re __asm("d0"); \
  register BPTR __OBSOLETEExAll_lock __asm("d1") = (_OBSOLETEExAll_lock); \
  register struct ExAllData * __OBSOLETEExAll_buffer __asm("d2") = (_OBSOLETEExAll_buffer); \
  register LONG __OBSOLETEExAll_size __asm("d3") = (_OBSOLETEExAll_size); \
  register LONG __OBSOLETEExAll_data __asm("d4") = (_OBSOLETEExAll_data); \
  register struct ExAllControl * __OBSOLETEExAll_control __asm("d5") = (_OBSOLETEExAll_control); \
  __asm volatile ("jsr a6@(-432:W)" \
  : "=r"(__OBSOLETEExAll__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExAll__bn), "rf"(__OBSOLETEExAll_lock), "rf"(__OBSOLETEExAll_buffer), "rf"(__OBSOLETEExAll_size), "rf"(__OBSOLETEExAll_data), "rf"(__OBSOLETEExAll_control) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReadSoftLink(port, lock, path, buffer, size) ({ \
  struct MsgPort * _ReadSoftLink_port = (port); \
  BPTR _ReadSoftLink_lock = (lock); \
  CONST_STRPTR _ReadSoftLink_path = (path); \
  STRPTR _ReadSoftLink_buffer = (buffer); \
  ULONG _ReadSoftLink_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReadSoftLink__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ReadSoftLink__re __asm("d0"); \
  register struct MsgPort * __ReadSoftLink_port __asm("d1") = (_ReadSoftLink_port); \
  register BPTR __ReadSoftLink_lock __asm("d2") = (_ReadSoftLink_lock); \
  register CONST_STRPTR __ReadSoftLink_path __asm("d3") = (_ReadSoftLink_path); \
  register STRPTR __ReadSoftLink_buffer __asm("d4") = (_ReadSoftLink_buffer); \
  register ULONG __ReadSoftLink_size __asm("d5") = (_ReadSoftLink_size); \
  __asm volatile ("jsr a6@(-438:W)" \
  : "=r"(__ReadSoftLink__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReadSoftLink__bn), "rf"(__ReadSoftLink_port), "rf"(__ReadSoftLink_lock), "rf"(__ReadSoftLink_path), "rf"(__ReadSoftLink_buffer), "rf"(__ReadSoftLink_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MakeLink(name, dest, soft) ({ \
  CONST_STRPTR _MakeLink_name = (name); \
  APTR _MakeLink_dest = (dest); \
  LONG _MakeLink_soft = (soft); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MakeLink__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MakeLink__re __asm("d0"); \
  register CONST_STRPTR __MakeLink_name __asm("d1") = (_MakeLink_name); \
  register APTR __MakeLink_dest __asm("d2") = (_MakeLink_dest); \
  register LONG __MakeLink_soft __asm("d3") = (_MakeLink_soft); \
  __asm volatile ("jsr a6@(-444:W)" \
  : "=r"(__MakeLink__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MakeLink__bn), "rf"(__MakeLink_name), "rf"(__MakeLink_dest), "rf"(__MakeLink_soft) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ChangeMode(type, fh, newmode) ({ \
  LONG _ChangeMode_type = (type); \
  BPTR _ChangeMode_fh = (fh); \
  LONG _ChangeMode_newmode = (newmode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ChangeMode__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ChangeMode__re __asm("d0"); \
  register LONG __ChangeMode_type __asm("d1") = (_ChangeMode_type); \
  register BPTR __ChangeMode_fh __asm("d2") = (_ChangeMode_fh); \
  register LONG __ChangeMode_newmode __asm("d3") = (_ChangeMode_newmode); \
  __asm volatile ("jsr a6@(-450:W)" \
  : "=r"(__ChangeMode__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ChangeMode__bn), "rf"(__ChangeMode_type), "rf"(__ChangeMode_fh), "rf"(__ChangeMode_newmode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETESetFileSize(fh, pos, mode) ({ \
  BPTR _OBSOLETESetFileSize_fh = (fh); \
  LONG _OBSOLETESetFileSize_pos = (pos); \
  LONG _OBSOLETESetFileSize_mode = (mode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETESetFileSize__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETESetFileSize__re __asm("d0"); \
  register BPTR __OBSOLETESetFileSize_fh __asm("d1") = (_OBSOLETESetFileSize_fh); \
  register LONG __OBSOLETESetFileSize_pos __asm("d2") = (_OBSOLETESetFileSize_pos); \
  register LONG __OBSOLETESetFileSize_mode __asm("d3") = (_OBSOLETESetFileSize_mode); \
  __asm volatile ("jsr a6@(-456:W)" \
  : "=r"(__OBSOLETESetFileSize__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETESetFileSize__bn), "rf"(__OBSOLETESetFileSize_fh), "rf"(__OBSOLETESetFileSize_pos), "rf"(__OBSOLETESetFileSize_mode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetIoErr(result) ({ \
  LONG _SetIoErr_result = (result); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetIoErr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetIoErr__re __asm("d0"); \
  register LONG __SetIoErr_result __asm("d1") = (_SetIoErr_result); \
  __asm volatile ("jsr a6@(-462:W)" \
  : "=r"(__SetIoErr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetIoErr__bn), "rf"(__SetIoErr_result) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Fault(code, header, buffer, len) ({ \
  LONG _Fault_code = (code); \
  CONST_STRPTR _Fault_header = (header); \
  STRPTR _Fault_buffer = (buffer); \
  LONG _Fault_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Fault__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Fault__re __asm("d0"); \
  register LONG __Fault_code __asm("d1") = (_Fault_code); \
  register CONST_STRPTR __Fault_header __asm("d2") = (_Fault_header); \
  register STRPTR __Fault_buffer __asm("d3") = (_Fault_buffer); \
  register LONG __Fault_len __asm("d4") = (_Fault_len); \
  __asm volatile ("jsr a6@(-468:W)" \
  : "=r"(__Fault__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Fault__bn), "rf"(__Fault_code), "rf"(__Fault_header), "rf"(__Fault_buffer), "rf"(__Fault_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define PrintFault(code, header) ({ \
  LONG _PrintFault_code = (code); \
  CONST_STRPTR _PrintFault_header = (header); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __PrintFault__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __PrintFault__re __asm("d0"); \
  register LONG __PrintFault_code __asm("d1") = (_PrintFault_code); \
  register CONST_STRPTR __PrintFault_header __asm("d2") = (_PrintFault_header); \
  __asm volatile ("jsr a6@(-474:W)" \
  : "=r"(__PrintFault__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__PrintFault__bn), "rf"(__PrintFault_code), "rf"(__PrintFault_header) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ErrorReport(code, type, arg1, device) ({ \
  LONG _ErrorReport_code = (code); \
  LONG _ErrorReport_type = (type); \
  ULONG _ErrorReport_arg1 = (arg1); \
  struct MsgPort * _ErrorReport_device = (device); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ErrorReport__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ErrorReport__re __asm("d0"); \
  register LONG __ErrorReport_code __asm("d1") = (_ErrorReport_code); \
  register LONG __ErrorReport_type __asm("d2") = (_ErrorReport_type); \
  register ULONG __ErrorReport_arg1 __asm("d3") = (_ErrorReport_arg1); \
  register struct MsgPort * __ErrorReport_device __asm("d4") = (_ErrorReport_device); \
  __asm volatile ("jsr a6@(-480:W)" \
  : "=r"(__ErrorReport__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ErrorReport__bn), "rf"(__ErrorReport_code), "rf"(__ErrorReport_type), "rf"(__ErrorReport_arg1), "rf"(__ErrorReport_device) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Cli() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Cli__bn __asm("a6") = DOS_BASE_NAME;\
  register struct CommandLineInterface * __Cli__re __asm("d0"); \
  __asm volatile ("jsr a6@(-492:W)" \
  : "=r"(__Cli__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Cli__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CreateNewProc(tags) ({ \
  const struct TagItem * _CreateNewProc_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CreateNewProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct Process * __CreateNewProc__re __asm("d0"); \
  register const struct TagItem * __CreateNewProc_tags __asm("d1") = (_CreateNewProc_tags); \
  __asm volatile ("jsr a6@(-498:W)" \
  : "=r"(__CreateNewProc__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CreateNewProc__bn), "rf"(__CreateNewProc_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CreateNewProcTagList(tags) CreateNewProc((tags))

#ifndef NO_INLINE_STDARG
static __inline__ struct Process * ___CreateNewProcTags(struct Library * DOSBase, ULONG tags, ...)
{
  return CreateNewProc((const struct TagItem *) &tags);
}

#define CreateNewProcTags(tags...) ___CreateNewProcTags(DOS_BASE_NAME, tags)
#endif

#define RunCommand(seg, stack, paramptr, paramlen) ({ \
  BPTR _RunCommand_seg = (seg); \
  ULONG _RunCommand_stack = (stack); \
  CONST_STRPTR _RunCommand_paramptr = (paramptr); \
  LONG _RunCommand_paramlen = (paramlen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RunCommand__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __RunCommand__re __asm("d0"); \
  register BPTR __RunCommand_seg __asm("d1") = (_RunCommand_seg); \
  register ULONG __RunCommand_stack __asm("d2") = (_RunCommand_stack); \
  register CONST_STRPTR __RunCommand_paramptr __asm("d3") = (_RunCommand_paramptr); \
  register LONG __RunCommand_paramlen __asm("d4") = (_RunCommand_paramlen); \
  __asm volatile ("jsr a6@(-504:W)" \
  : "=r"(__RunCommand__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RunCommand__bn), "rf"(__RunCommand_seg), "rf"(__RunCommand_stack), "rf"(__RunCommand_paramptr), "rf"(__RunCommand_paramlen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetConsolePort() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetConsolePort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __GetConsolePort__re __asm("d0"); \
  __asm volatile ("jsr a6@(-510:W)" \
  : "=r"(__GetConsolePort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetConsolePort__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetConsolePort(port) ({ \
  const struct MsgPort * _SetConsolePort_port = (port); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetConsolePort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __SetConsolePort__re __asm("d0"); \
  register const struct MsgPort * __SetConsolePort_port __asm("d1") = (_SetConsolePort_port); \
  __asm volatile ("jsr a6@(-516:W)" \
  : "=r"(__SetConsolePort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetConsolePort__bn), "rf"(__SetConsolePort_port) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetFileSysPort() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetFileSysPort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __GetFileSysPort__re __asm("d0"); \
  __asm volatile ("jsr a6@(-522:W)" \
  : "=r"(__GetFileSysPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetFileSysPort__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetFileSysPort(port) ({ \
  const struct MsgPort * _SetFileSysPort_port = (port); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetFileSysPort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __SetFileSysPort__re __asm("d0"); \
  register const struct MsgPort * __SetFileSysPort_port __asm("d1") = (_SetFileSysPort_port); \
  __asm volatile ("jsr a6@(-528:W)" \
  : "=r"(__SetFileSysPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetFileSysPort__bn), "rf"(__SetFileSysPort_port) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetArgStr() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetArgStr__bn __asm("a6") = DOS_BASE_NAME;\
  register STRPTR __GetArgStr__re __asm("d0"); \
  __asm volatile ("jsr a6@(-534:W)" \
  : "=r"(__GetArgStr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetArgStr__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetArgStr(string) ({ \
  CONST_STRPTR _SetArgStr_string = (string); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetArgStr__bn __asm("a6") = DOS_BASE_NAME;\
  register STRPTR __SetArgStr__re __asm("d0"); \
  register CONST_STRPTR __SetArgStr_string __asm("d1") = (_SetArgStr_string); \
  __asm volatile ("jsr a6@(-540:W)" \
  : "=r"(__SetArgStr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetArgStr__bn), "rf"(__SetArgStr_string) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindCliProc(num) ({ \
  ULONG _FindCliProc_num = (num); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindCliProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct Process * __FindCliProc__re __asm("d0"); \
  register ULONG __FindCliProc_num __asm("d1") = (_FindCliProc_num); \
  __asm volatile ("jsr a6@(-546:W)" \
  : "=r"(__FindCliProc__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindCliProc__bn), "rf"(__FindCliProc_num) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MaxCli() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MaxCli__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __MaxCli__re __asm("d0"); \
  __asm volatile ("jsr a6@(-552:W)" \
  : "=r"(__MaxCli__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MaxCli__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetCliCurrentDirName(name) ({ \
  CONST_STRPTR _SetCliCurrentDirName_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetCliCurrentDirName__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetCliCurrentDirName__re __asm("d0"); \
  register CONST_STRPTR __SetCliCurrentDirName_name __asm("d1") = (_SetCliCurrentDirName_name); \
  __asm volatile ("jsr a6@(-558:W)" \
  : "=r"(__SetCliCurrentDirName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetCliCurrentDirName__bn), "rf"(__SetCliCurrentDirName_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetCliCurrentDirName(buf, len) ({ \
  STRPTR _GetCliCurrentDirName_buf = (buf); \
  LONG _GetCliCurrentDirName_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetCliCurrentDirName__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetCliCurrentDirName__re __asm("d0"); \
  register STRPTR __GetCliCurrentDirName_buf __asm("d1") = (_GetCliCurrentDirName_buf); \
  register LONG __GetCliCurrentDirName_len __asm("d2") = (_GetCliCurrentDirName_len); \
  __asm volatile ("jsr a6@(-564:W)" \
  : "=r"(__GetCliCurrentDirName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetCliCurrentDirName__bn), "rf"(__GetCliCurrentDirName_buf), "rf"(__GetCliCurrentDirName_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetCliProgramName(name) ({ \
  CONST_STRPTR _SetCliProgramName_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetCliProgramName__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetCliProgramName__re __asm("d0"); \
  register CONST_STRPTR __SetCliProgramName_name __asm("d1") = (_SetCliProgramName_name); \
  __asm volatile ("jsr a6@(-570:W)" \
  : "=r"(__SetCliProgramName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetCliProgramName__bn), "rf"(__SetCliProgramName_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetCliProgramName(buf, len) ({ \
  STRPTR _GetCliProgramName_buf = (buf); \
  LONG _GetCliProgramName_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetCliProgramName__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetCliProgramName__re __asm("d0"); \
  register STRPTR __GetCliProgramName_buf __asm("d1") = (_GetCliProgramName_buf); \
  register LONG __GetCliProgramName_len __asm("d2") = (_GetCliProgramName_len); \
  __asm volatile ("jsr a6@(-576:W)" \
  : "=r"(__GetCliProgramName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetCliProgramName__bn), "rf"(__GetCliProgramName_buf), "rf"(__GetCliProgramName_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetCliPrompt(name) ({ \
  CONST_STRPTR _SetCliPrompt_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetCliPrompt__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetCliPrompt__re __asm("d0"); \
  register CONST_STRPTR __SetCliPrompt_name __asm("d1") = (_SetCliPrompt_name); \
  __asm volatile ("jsr a6@(-582:W)" \
  : "=r"(__SetCliPrompt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetCliPrompt__bn), "rf"(__SetCliPrompt_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetCliPrompt(buf, len) ({ \
  STRPTR _GetCliPrompt_buf = (buf); \
  LONG _GetCliPrompt_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetCliPrompt__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetCliPrompt__re __asm("d0"); \
  register STRPTR __GetCliPrompt_buf __asm("d1") = (_GetCliPrompt_buf); \
  register LONG __GetCliPrompt_len __asm("d2") = (_GetCliPrompt_len); \
  __asm volatile ("jsr a6@(-588:W)" \
  : "=r"(__GetCliPrompt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetCliPrompt__bn), "rf"(__GetCliPrompt_buf), "rf"(__GetCliPrompt_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetProgramDir(lock) ({ \
  BPTR _SetProgramDir_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetProgramDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __SetProgramDir__re __asm("d0"); \
  register BPTR __SetProgramDir_lock __asm("d1") = (_SetProgramDir_lock); \
  __asm volatile ("jsr a6@(-594:W)" \
  : "=r"(__SetProgramDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetProgramDir__bn), "rf"(__SetProgramDir_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetProgramDir() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetProgramDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __GetProgramDir__re __asm("d0"); \
  __asm volatile ("jsr a6@(-600:W)" \
  : "=r"(__GetProgramDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetProgramDir__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SystemTagList(command, tags) ({ \
  CONST_STRPTR _SystemTagList_command = (command); \
  const struct TagItem * _SystemTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SystemTagList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SystemTagList__re __asm("d0"); \
  register CONST_STRPTR __SystemTagList_command __asm("d1") = (_SystemTagList_command); \
  register const struct TagItem * __SystemTagList_tags __asm("d2") = (_SystemTagList_tags); \
  __asm volatile ("jsr a6@(-606:W)" \
  : "=r"(__SystemTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SystemTagList__bn), "rf"(__SystemTagList_command), "rf"(__SystemTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define System(command, tags) SystemTagList((command), (tags))

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SystemTags(struct Library * DOSBase, CONST_STRPTR command, ULONG tags, ...)
{
  return SystemTagList(command, (const struct TagItem *) &tags);
}

#define SystemTags(command...) ___SystemTags(DOS_BASE_NAME, command)
#endif

#define AssignLock(name, lock) ({ \
  CONST_STRPTR _AssignLock_name = (name); \
  BPTR _AssignLock_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AssignLock__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AssignLock__re __asm("d0"); \
  register CONST_STRPTR __AssignLock_name __asm("d1") = (_AssignLock_name); \
  register BPTR __AssignLock_lock __asm("d2") = (_AssignLock_lock); \
  __asm volatile ("jsr a6@(-612:W)" \
  : "=r"(__AssignLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AssignLock__bn), "rf"(__AssignLock_name), "rf"(__AssignLock_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AssignLate(name, path) ({ \
  CONST_STRPTR _AssignLate_name = (name); \
  CONST_STRPTR _AssignLate_path = (path); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AssignLate__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AssignLate__re __asm("d0"); \
  register CONST_STRPTR __AssignLate_name __asm("d1") = (_AssignLate_name); \
  register CONST_STRPTR __AssignLate_path __asm("d2") = (_AssignLate_path); \
  __asm volatile ("jsr a6@(-618:W)" \
  : "=r"(__AssignLate__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AssignLate__bn), "rf"(__AssignLate_name), "rf"(__AssignLate_path) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AssignPath(name, path) ({ \
  CONST_STRPTR _AssignPath_name = (name); \
  CONST_STRPTR _AssignPath_path = (path); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AssignPath__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AssignPath__re __asm("d0"); \
  register CONST_STRPTR __AssignPath_name __asm("d1") = (_AssignPath_name); \
  register CONST_STRPTR __AssignPath_path __asm("d2") = (_AssignPath_path); \
  __asm volatile ("jsr a6@(-624:W)" \
  : "=r"(__AssignPath__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AssignPath__bn), "rf"(__AssignPath_name), "rf"(__AssignPath_path) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AssignAdd(name, lock) ({ \
  CONST_STRPTR _AssignAdd_name = (name); \
  BPTR _AssignAdd_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AssignAdd__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AssignAdd__re __asm("d0"); \
  register CONST_STRPTR __AssignAdd_name __asm("d1") = (_AssignAdd_name); \
  register BPTR __AssignAdd_lock __asm("d2") = (_AssignAdd_lock); \
  __asm volatile ("jsr a6@(-630:W)" \
  : "=r"(__AssignAdd__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AssignAdd__bn), "rf"(__AssignAdd_name), "rf"(__AssignAdd_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define RemAssignList(name, lock) ({ \
  CONST_STRPTR _RemAssignList_name = (name); \
  BPTR _RemAssignList_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemAssignList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __RemAssignList__re __asm("d0"); \
  register CONST_STRPTR __RemAssignList_name __asm("d1") = (_RemAssignList_name); \
  register BPTR __RemAssignList_lock __asm("d2") = (_RemAssignList_lock); \
  __asm volatile ("jsr a6@(-636:W)" \
  : "=r"(__RemAssignList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemAssignList__bn), "rf"(__RemAssignList_name), "rf"(__RemAssignList_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetDeviceProc(name, dp) ({ \
  CONST_STRPTR _GetDeviceProc_name = (name); \
  struct DevProc * _GetDeviceProc_dp = (dp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetDeviceProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DevProc * __GetDeviceProc__re __asm("d0"); \
  register CONST_STRPTR __GetDeviceProc_name __asm("d1") = (_GetDeviceProc_name); \
  register struct DevProc * __GetDeviceProc_dp __asm("d2") = (_GetDeviceProc_dp); \
  __asm volatile ("jsr a6@(-642:W)" \
  : "=r"(__GetDeviceProc__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetDeviceProc__bn), "rf"(__GetDeviceProc_name), "rf"(__GetDeviceProc_dp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FreeDeviceProc(dp) ({ \
  struct DevProc * _FreeDeviceProc_dp = (dp); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeDeviceProc__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DevProc * __FreeDeviceProc_dp __asm("d1") = (_FreeDeviceProc_dp); \
  __asm volatile ("jsr a6@(-648:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeDeviceProc__bn), "rf"(__FreeDeviceProc_dp) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LockDosList(flags) ({ \
  ULONG _LockDosList_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LockDosList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __LockDosList__re __asm("d0"); \
  register ULONG __LockDosList_flags __asm("d1") = (_LockDosList_flags); \
  __asm volatile ("jsr a6@(-654:W)" \
  : "=r"(__LockDosList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LockDosList__bn), "rf"(__LockDosList_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnLockDosList(flags) ({ \
  ULONG _UnLockDosList_flags = (flags); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnLockDosList__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __UnLockDosList_flags __asm("d1") = (_UnLockDosList_flags); \
  __asm volatile ("jsr a6@(-660:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnLockDosList__bn), "rf"(__UnLockDosList_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AttemptLockDosList(flags) ({ \
  ULONG _AttemptLockDosList_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AttemptLockDosList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __AttemptLockDosList__re __asm("d0"); \
  register ULONG __AttemptLockDosList_flags __asm("d1") = (_AttemptLockDosList_flags); \
  __asm volatile ("jsr a6@(-666:W)" \
  : "=r"(__AttemptLockDosList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AttemptLockDosList__bn), "rf"(__AttemptLockDosList_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define RemDosEntry(dlist) ({ \
  struct DosList * _RemDosEntry_dlist = (dlist); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __RemDosEntry__re __asm("d0"); \
  register struct DosList * __RemDosEntry_dlist __asm("d1") = (_RemDosEntry_dlist); \
  __asm volatile ("jsr a6@(-672:W)" \
  : "=r"(__RemDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemDosEntry__bn), "rf"(__RemDosEntry_dlist) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddDosEntry(dlist) ({ \
  struct DosList * _AddDosEntry_dlist = (dlist); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddDosEntry__re __asm("d0"); \
  register struct DosList * __AddDosEntry_dlist __asm("d1") = (_AddDosEntry_dlist); \
  __asm volatile ("jsr a6@(-678:W)" \
  : "=r"(__AddDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddDosEntry__bn), "rf"(__AddDosEntry_dlist) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindDosEntry(dlist, name, flags) ({ \
  const struct DosList * _FindDosEntry_dlist = (dlist); \
  CONST_STRPTR _FindDosEntry_name = (name); \
  ULONG _FindDosEntry_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __FindDosEntry__re __asm("d0"); \
  register const struct DosList * __FindDosEntry_dlist __asm("d1") = (_FindDosEntry_dlist); \
  register CONST_STRPTR __FindDosEntry_name __asm("d2") = (_FindDosEntry_name); \
  register ULONG __FindDosEntry_flags __asm("d3") = (_FindDosEntry_flags); \
  __asm volatile ("jsr a6@(-684:W)" \
  : "=r"(__FindDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindDosEntry__bn), "rf"(__FindDosEntry_dlist), "rf"(__FindDosEntry_name), "rf"(__FindDosEntry_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NextDosEntry(dlist, flags) ({ \
  const struct DosList * _NextDosEntry_dlist = (dlist); \
  ULONG _NextDosEntry_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NextDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __NextDosEntry__re __asm("d0"); \
  register const struct DosList * __NextDosEntry_dlist __asm("d1") = (_NextDosEntry_dlist); \
  register ULONG __NextDosEntry_flags __asm("d2") = (_NextDosEntry_flags); \
  __asm volatile ("jsr a6@(-690:W)" \
  : "=r"(__NextDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NextDosEntry__bn), "rf"(__NextDosEntry_dlist), "rf"(__NextDosEntry_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MakeDosEntry(name, type) ({ \
  CONST_STRPTR _MakeDosEntry_name = (name); \
  LONG _MakeDosEntry_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MakeDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __MakeDosEntry__re __asm("d0"); \
  register CONST_STRPTR __MakeDosEntry_name __asm("d1") = (_MakeDosEntry_name); \
  register LONG __MakeDosEntry_type __asm("d2") = (_MakeDosEntry_type); \
  __asm volatile ("jsr a6@(-696:W)" \
  : "=r"(__MakeDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MakeDosEntry__bn), "rf"(__MakeDosEntry_name), "rf"(__MakeDosEntry_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FreeDosEntry(dlist) ({ \
  struct DosList * _FreeDosEntry_dlist = (dlist); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosList * __FreeDosEntry_dlist __asm("d1") = (_FreeDosEntry_dlist); \
  __asm volatile ("jsr a6@(-702:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeDosEntry__bn), "rf"(__FreeDosEntry_dlist) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define IsFileSystem(name) ({ \
  CONST_STRPTR _IsFileSystem_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __IsFileSystem__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __IsFileSystem__re __asm("d0"); \
  register CONST_STRPTR __IsFileSystem_name __asm("d1") = (_IsFileSystem_name); \
  __asm volatile ("jsr a6@(-708:W)" \
  : "=r"(__IsFileSystem__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__IsFileSystem__bn), "rf"(__IsFileSystem_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Format(filesystem, volumename, dostype, flags) ({ \
  CONST_STRPTR _Format_filesystem = (filesystem); \
  CONST_STRPTR _Format_volumename = (volumename); \
  ULONG _Format_dostype = (dostype); \
  ULONG _Format_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Format__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Format__re __asm("d0"); \
  register CONST_STRPTR __Format_filesystem __asm("d1") = (_Format_filesystem); \
  register CONST_STRPTR __Format_volumename __asm("d2") = (_Format_volumename); \
  register ULONG __Format_dostype __asm("d3") = (_Format_dostype); \
  register ULONG __Format_flags __asm("d4") = (_Format_flags); \
  __asm volatile ("jsr a6@(-714:W)" \
  : "=r"(__Format__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Format__bn), "rf"(__Format_filesystem), "rf"(__Format_volumename), "rf"(__Format_dostype), "rf"(__Format_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Relabel(drive, newname) ({ \
  CONST_STRPTR _Relabel_drive = (drive); \
  CONST_STRPTR _Relabel_newname = (newname); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Relabel__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Relabel__re __asm("d0"); \
  register CONST_STRPTR __Relabel_drive __asm("d1") = (_Relabel_drive); \
  register CONST_STRPTR __Relabel_newname __asm("d2") = (_Relabel_newname); \
  __asm volatile ("jsr a6@(-720:W)" \
  : "=r"(__Relabel__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Relabel__bn), "rf"(__Relabel_drive), "rf"(__Relabel_newname) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Inhibit(name, onoff) ({ \
  CONST_STRPTR _Inhibit_name = (name); \
  LONG _Inhibit_onoff = (onoff); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Inhibit__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Inhibit__re __asm("d0"); \
  register CONST_STRPTR __Inhibit_name __asm("d1") = (_Inhibit_name); \
  register LONG __Inhibit_onoff __asm("d2") = (_Inhibit_onoff); \
  __asm volatile ("jsr a6@(-726:W)" \
  : "=r"(__Inhibit__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Inhibit__bn), "rf"(__Inhibit_name), "rf"(__Inhibit_onoff) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddBuffers(name, number) ({ \
  CONST_STRPTR _AddBuffers_name = (name); \
  LONG _AddBuffers_number = (number); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddBuffers__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddBuffers__re __asm("d0"); \
  register CONST_STRPTR __AddBuffers_name __asm("d1") = (_AddBuffers_name); \
  register LONG __AddBuffers_number __asm("d2") = (_AddBuffers_number); \
  __asm volatile ("jsr a6@(-732:W)" \
  : "=r"(__AddBuffers__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddBuffers__bn), "rf"(__AddBuffers_name), "rf"(__AddBuffers_number) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CompareDates(date1, date2) ({ \
  const struct DateStamp * _CompareDates_date1 = (date1); \
  const struct DateStamp * _CompareDates_date2 = (date2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CompareDates__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __CompareDates__re __asm("d0"); \
  register const struct DateStamp * __CompareDates_date1 __asm("d1") = (_CompareDates_date1); \
  register const struct DateStamp * __CompareDates_date2 __asm("d2") = (_CompareDates_date2); \
  __asm volatile ("jsr a6@(-738:W)" \
  : "=r"(__CompareDates__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CompareDates__bn), "rf"(__CompareDates_date1), "rf"(__CompareDates_date2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DateToStr(datetime) ({ \
  struct DateTime * _DateToStr_datetime = (datetime); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DateToStr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DateToStr__re __asm("d0"); \
  register struct DateTime * __DateToStr_datetime __asm("d1") = (_DateToStr_datetime); \
  __asm volatile ("jsr a6@(-744:W)" \
  : "=r"(__DateToStr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DateToStr__bn), "rf"(__DateToStr_datetime) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define StrToDate(datetime) ({ \
  struct DateTime * _StrToDate_datetime = (datetime); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __StrToDate__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __StrToDate__re __asm("d0"); \
  register struct DateTime * __StrToDate_datetime __asm("d1") = (_StrToDate_datetime); \
  __asm volatile ("jsr a6@(-750:W)" \
  : "=r"(__StrToDate__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__StrToDate__bn), "rf"(__StrToDate_datetime) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define InternalLoadSeg(fh, table, funcarray) ({ \
  BPTR _InternalLoadSeg_fh = (fh); \
  BPTR _InternalLoadSeg_table = (table); \
  const LONG * _InternalLoadSeg_funcarray = (funcarray); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __InternalLoadSeg__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __InternalLoadSeg__re __asm("d0"); \
  register BPTR __InternalLoadSeg_fh __asm("d0") = (_InternalLoadSeg_fh); \
  register BPTR __InternalLoadSeg_table __asm("a0") = (_InternalLoadSeg_table); \
  register const LONG * __InternalLoadSeg_funcarray __asm("a1") = (_InternalLoadSeg_funcarray); \
  __asm volatile ("jsr a6@(-756:W)" \
  : "=r"(__InternalLoadSeg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__InternalLoadSeg__bn), "rf"(__InternalLoadSeg_fh), "rf"(__InternalLoadSeg_table), "rf"(__InternalLoadSeg_funcarray) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define InternalUnLoadSeg(seglist, freefunc) ({ \
  BPTR _InternalUnLoadSeg_seglist = (seglist); \
  VOID (*_InternalUnLoadSeg_freefunc)() = (freefunc); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __InternalUnLoadSeg__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __InternalUnLoadSeg__re __asm("d0"); \
  register BPTR __InternalUnLoadSeg_seglist __asm("d1") = (_InternalUnLoadSeg_seglist); \
  register VOID (*__InternalUnLoadSeg_freefunc)() __asm("a1") = (_InternalUnLoadSeg_freefunc); \
  __asm volatile ("jsr a6@(-762:W)" \
  : "=r"(__InternalUnLoadSeg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__InternalUnLoadSeg__bn), "rf"(__InternalUnLoadSeg_seglist), "rf"(__InternalUnLoadSeg_freefunc) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NewLoadSeg(file, tags) ({ \
  CONST_STRPTR _NewLoadSeg_file = (file); \
  const struct TagItem * _NewLoadSeg_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NewLoadSeg__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __NewLoadSeg__re __asm("d0"); \
  register CONST_STRPTR __NewLoadSeg_file __asm("d1") = (_NewLoadSeg_file); \
  register const struct TagItem * __NewLoadSeg_tags __asm("d2") = (_NewLoadSeg_tags); \
  __asm volatile ("jsr a6@(-768:W)" \
  : "=r"(__NewLoadSeg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NewLoadSeg__bn), "rf"(__NewLoadSeg_file), "rf"(__NewLoadSeg_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NewLoadSegTagList(file, tags) NewLoadSeg((file), (tags))

#ifndef NO_INLINE_STDARG
static __inline__ BPTR ___NewLoadSegTags(struct Library * DOSBase, CONST_STRPTR file, ULONG tags, ...)
{
  return NewLoadSeg(file, (const struct TagItem *) &tags);
}

#define NewLoadSegTags(file...) ___NewLoadSegTags(DOS_BASE_NAME, file)
#endif

#define AddSegment(name, seg, type) ({ \
  CONST_STRPTR _AddSegment_name = (name); \
  BPTR _AddSegment_seg = (seg); \
  LONG _AddSegment_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddSegment__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddSegment__re __asm("d0"); \
  register CONST_STRPTR __AddSegment_name __asm("d1") = (_AddSegment_name); \
  register BPTR __AddSegment_seg __asm("d2") = (_AddSegment_seg); \
  register LONG __AddSegment_type __asm("d3") = (_AddSegment_type); \
  __asm volatile ("jsr a6@(-774:W)" \
  : "=r"(__AddSegment__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddSegment__bn), "rf"(__AddSegment_name), "rf"(__AddSegment_seg), "rf"(__AddSegment_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindSegment(name, seg, type) ({ \
  CONST_STRPTR _FindSegment_name = (name); \
  const struct DosResidentSeg * _FindSegment_seg = (seg); \
  LONG _FindSegment_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindSegment__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DosResidentSeg * __FindSegment__re __asm("d0"); \
  register CONST_STRPTR __FindSegment_name __asm("d1") = (_FindSegment_name); \
  register const struct DosResidentSeg * __FindSegment_seg __asm("d2") = (_FindSegment_seg); \
  register LONG __FindSegment_type __asm("d3") = (_FindSegment_type); \
  __asm volatile ("jsr a6@(-780:W)" \
  : "=r"(__FindSegment__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindSegment__bn), "rf"(__FindSegment_name), "rf"(__FindSegment_seg), "rf"(__FindSegment_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define RemSegment(seg) ({ \
  struct DosResidentSeg * _RemSegment_seg = (seg); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemSegment__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __RemSegment__re __asm("d0"); \
  register struct DosResidentSeg * __RemSegment_seg __asm("d1") = (_RemSegment_seg); \
  __asm volatile ("jsr a6@(-786:W)" \
  : "=r"(__RemSegment__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemSegment__bn), "rf"(__RemSegment_seg) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CheckSignal(mask) ({ \
  ULONG _CheckSignal_mask = (mask); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CheckSignal__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __CheckSignal__re __asm("d0"); \
  register ULONG __CheckSignal_mask __asm("d1") = (_CheckSignal_mask); \
  __asm volatile ("jsr a6@(-792:W)" \
  : "=r"(__CheckSignal__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CheckSignal__bn), "rf"(__CheckSignal_mask) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReadArgs(arg_template, array, args) ({ \
  CONST_STRPTR _ReadArgs_arg_template = (arg_template); \
  LONG * _ReadArgs_array = (array); \
  struct RDArgs * _ReadArgs_args = (args); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReadArgs__bn __asm("a6") = DOS_BASE_NAME;\
  register struct RDArgs * __ReadArgs__re __asm("d0"); \
  register CONST_STRPTR __ReadArgs_arg_template __asm("d1") = (_ReadArgs_arg_template); \
  register LONG * __ReadArgs_array __asm("d2") = (_ReadArgs_array); \
  register struct RDArgs * __ReadArgs_args __asm("d3") = (_ReadArgs_args); \
  __asm volatile ("jsr a6@(-798:W)" \
  : "=r"(__ReadArgs__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReadArgs__bn), "rf"(__ReadArgs_arg_template), "rf"(__ReadArgs_array), "rf"(__ReadArgs_args) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindArg(arg_template, keyword) ({ \
  CONST_STRPTR _FindArg_arg_template = (arg_template); \
  CONST_STRPTR _FindArg_keyword = (keyword); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindArg__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FindArg__re __asm("d0"); \
  register CONST_STRPTR __FindArg_arg_template __asm("d1") = (_FindArg_arg_template); \
  register CONST_STRPTR __FindArg_keyword __asm("d2") = (_FindArg_keyword); \
  __asm volatile ("jsr a6@(-804:W)" \
  : "=r"(__FindArg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindArg__bn), "rf"(__FindArg_arg_template), "rf"(__FindArg_keyword) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReadItem(buffer, maxchars, cSource) ({ \
  STRPTR _ReadItem_buffer = (buffer); \
  LONG _ReadItem_maxchars = (maxchars); \
  struct CSource * _ReadItem_cSource = (cSource); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReadItem__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ReadItem__re __asm("d0"); \
  register STRPTR __ReadItem_buffer __asm("d1") = (_ReadItem_buffer); \
  register LONG __ReadItem_maxchars __asm("d2") = (_ReadItem_maxchars); \
  register struct CSource * __ReadItem_cSource __asm("d3") = (_ReadItem_cSource); \
  __asm volatile ("jsr a6@(-810:W)" \
  : "=r"(__ReadItem__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReadItem__bn), "rf"(__ReadItem_buffer), "rf"(__ReadItem_maxchars), "rf"(__ReadItem_cSource) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define StrToLong(string, value) ({ \
  CONST_STRPTR _StrToLong_string = (string); \
  LONG * _StrToLong_value = (value); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __StrToLong__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __StrToLong__re __asm("d0"); \
  register CONST_STRPTR __StrToLong_string __asm("d1") = (_StrToLong_string); \
  register LONG * __StrToLong_value __asm("d2") = (_StrToLong_value); \
  __asm volatile ("jsr a6@(-816:W)" \
  : "=r"(__StrToLong__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__StrToLong__bn), "rf"(__StrToLong_string), "rf"(__StrToLong_value) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MatchFirst(pat, anchor) ({ \
  CONST_STRPTR _MatchFirst_pat = (pat); \
  struct AnchorPath * _MatchFirst_anchor = (anchor); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MatchFirst__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MatchFirst__re __asm("d0"); \
  register CONST_STRPTR __MatchFirst_pat __asm("d1") = (_MatchFirst_pat); \
  register struct AnchorPath * __MatchFirst_anchor __asm("d2") = (_MatchFirst_anchor); \
  __asm volatile ("jsr a6@(-822:W)" \
  : "=r"(__MatchFirst__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MatchFirst__bn), "rf"(__MatchFirst_pat), "rf"(__MatchFirst_anchor) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MatchNext(anchor) ({ \
  struct AnchorPath * _MatchNext_anchor = (anchor); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MatchNext__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MatchNext__re __asm("d0"); \
  register struct AnchorPath * __MatchNext_anchor __asm("d1") = (_MatchNext_anchor); \
  __asm volatile ("jsr a6@(-828:W)" \
  : "=r"(__MatchNext__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MatchNext__bn), "rf"(__MatchNext_anchor) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MatchEnd(anchor) ({ \
  struct AnchorPath * _MatchEnd_anchor = (anchor); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MatchEnd__bn __asm("a6") = DOS_BASE_NAME;\
  register struct AnchorPath * __MatchEnd_anchor __asm("d1") = (_MatchEnd_anchor); \
  __asm volatile ("jsr a6@(-834:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MatchEnd__bn), "rf"(__MatchEnd_anchor) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ParsePattern(pat, buf, buflen) ({ \
  CONST_STRPTR _ParsePattern_pat = (pat); \
  STRPTR _ParsePattern_buf = (buf); \
  LONG _ParsePattern_buflen = (buflen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ParsePattern__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ParsePattern__re __asm("d0"); \
  register CONST_STRPTR __ParsePattern_pat __asm("d1") = (_ParsePattern_pat); \
  register STRPTR __ParsePattern_buf __asm("d2") = (_ParsePattern_buf); \
  register LONG __ParsePattern_buflen __asm("d3") = (_ParsePattern_buflen); \
  __asm volatile ("jsr a6@(-840:W)" \
  : "=r"(__ParsePattern__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ParsePattern__bn), "rf"(__ParsePattern_pat), "rf"(__ParsePattern_buf), "rf"(__ParsePattern_buflen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MatchPattern(pat, str) ({ \
  CONST_STRPTR _MatchPattern_pat = (pat); \
  CONST_STRPTR _MatchPattern_str = (str); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MatchPattern__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MatchPattern__re __asm("d0"); \
  register CONST_STRPTR __MatchPattern_pat __asm("d1") = (_MatchPattern_pat); \
  register CONST_STRPTR __MatchPattern_str __asm("d2") = (_MatchPattern_str); \
  __asm volatile ("jsr a6@(-846:W)" \
  : "=r"(__MatchPattern__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MatchPattern__bn), "rf"(__MatchPattern_pat), "rf"(__MatchPattern_str) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FreeArgs(args) ({ \
  struct RDArgs * _FreeArgs_args = (args); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeArgs__bn __asm("a6") = DOS_BASE_NAME;\
  register struct RDArgs * __FreeArgs_args __asm("d1") = (_FreeArgs_args); \
  __asm volatile ("jsr a6@(-858:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeArgs__bn), "rf"(__FreeArgs_args) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define StartPart(path) ({ \
  CONST_STRPTR _StartPart_path = (path); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __StartPart__bn __asm("a6") = DOS_BASE_NAME;\
  register STRPTR __StartPart__re __asm("d0"); \
  register CONST_STRPTR __StartPart_path __asm("d1") = (_StartPart_path); \
  __asm volatile ("jsr a6@(-864:W)" \
  : "=r"(__StartPart__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__StartPart__bn), "rf"(__StartPart_path) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FilePart(path) ({ \
  CONST_STRPTR _FilePart_path = (path); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FilePart__bn __asm("a6") = DOS_BASE_NAME;\
  register CONST_STRPTR __FilePart__re __asm("d0"); \
  register CONST_STRPTR __FilePart_path __asm("d1") = (_FilePart_path); \
  __asm volatile ("jsr a6@(-870:W)" \
  : "=r"(__FilePart__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FilePart__bn), "rf"(__FilePart_path) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define PathPart(path) ({ \
  CONST_STRPTR _PathPart_path = (path); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __PathPart__bn __asm("a6") = DOS_BASE_NAME;\
  register STRPTR __PathPart__re __asm("d0"); \
  register CONST_STRPTR __PathPart_path __asm("d1") = (_PathPart_path); \
  __asm volatile ("jsr a6@(-876:W)" \
  : "=r"(__PathPart__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__PathPart__bn), "rf"(__PathPart_path) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddPart(dest_dirname, filename, size) ({ \
  STRPTR _AddPart_dest_dirname = (dest_dirname); \
  CONST_STRPTR _AddPart_filename = (filename); \
  ULONG _AddPart_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddPart__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddPart__re __asm("d0"); \
  register STRPTR __AddPart_dest_dirname __asm("d1") = (_AddPart_dest_dirname); \
  register CONST_STRPTR __AddPart_filename __asm("d2") = (_AddPart_filename); \
  register ULONG __AddPart_size __asm("d3") = (_AddPart_size); \
  __asm volatile ("jsr a6@(-882:W)" \
  : "=r"(__AddPart__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddPart__bn), "rf"(__AddPart_dest_dirname), "rf"(__AddPart_filename), "rf"(__AddPart_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define StartNotify(notify) ({ \
  struct NotifyRequest * _StartNotify_notify = (notify); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __StartNotify__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __StartNotify__re __asm("d0"); \
  register struct NotifyRequest * __StartNotify_notify __asm("d1") = (_StartNotify_notify); \
  __asm volatile ("jsr a6@(-888:W)" \
  : "=r"(__StartNotify__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__StartNotify__bn), "rf"(__StartNotify_notify) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define EndNotify(notify) ({ \
  struct NotifyRequest * _EndNotify_notify = (notify); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __EndNotify__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __EndNotify__re __asm("d0"); \
  register struct NotifyRequest * __EndNotify_notify __asm("d1") = (_EndNotify_notify); \
  __asm volatile ("jsr a6@(-894:W)" \
  : "=r"(__EndNotify__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__EndNotify__bn), "rf"(__EndNotify_notify) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetVar(name, buffer, size, flags) ({ \
  CONST_STRPTR _SetVar_name = (name); \
  CONST_STRPTR _SetVar_buffer = (buffer); \
  LONG _SetVar_size = (size); \
  ULONG _SetVar_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetVar__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetVar__re __asm("d0"); \
  register CONST_STRPTR __SetVar_name __asm("d1") = (_SetVar_name); \
  register CONST_STRPTR __SetVar_buffer __asm("d2") = (_SetVar_buffer); \
  register LONG __SetVar_size __asm("d3") = (_SetVar_size); \
  register ULONG __SetVar_flags __asm("d4") = (_SetVar_flags); \
  __asm volatile ("jsr a6@(-900:W)" \
  : "=r"(__SetVar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetVar__bn), "rf"(__SetVar_name), "rf"(__SetVar_buffer), "rf"(__SetVar_size), "rf"(__SetVar_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetVar(name, buffer, size, flags) ({ \
  CONST_STRPTR _GetVar_name = (name); \
  STRPTR _GetVar_buffer = (buffer); \
  LONG _GetVar_size = (size); \
  ULONG _GetVar_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetVar__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetVar__re __asm("d0"); \
  register CONST_STRPTR __GetVar_name __asm("d1") = (_GetVar_name); \
  register STRPTR __GetVar_buffer __asm("d2") = (_GetVar_buffer); \
  register LONG __GetVar_size __asm("d3") = (_GetVar_size); \
  register ULONG __GetVar_flags __asm("d4") = (_GetVar_flags); \
  __asm volatile ("jsr a6@(-906:W)" \
  : "=r"(__GetVar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetVar__bn), "rf"(__GetVar_name), "rf"(__GetVar_buffer), "rf"(__GetVar_size), "rf"(__GetVar_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DeleteVar(name, flags) ({ \
  CONST_STRPTR _DeleteVar_name = (name); \
  ULONG _DeleteVar_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DeleteVar__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DeleteVar__re __asm("d0"); \
  register CONST_STRPTR __DeleteVar_name __asm("d1") = (_DeleteVar_name); \
  register ULONG __DeleteVar_flags __asm("d2") = (_DeleteVar_flags); \
  __asm volatile ("jsr a6@(-912:W)" \
  : "=r"(__DeleteVar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DeleteVar__bn), "rf"(__DeleteVar_name), "rf"(__DeleteVar_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindVar(name, type) ({ \
  CONST_STRPTR _FindVar_name = (name); \
  ULONG _FindVar_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindVar__bn __asm("a6") = DOS_BASE_NAME;\
  register struct LocalVar * __FindVar__re __asm("d0"); \
  register CONST_STRPTR __FindVar_name __asm("d1") = (_FindVar_name); \
  register ULONG __FindVar_type __asm("d2") = (_FindVar_type); \
  __asm volatile ("jsr a6@(-918:W)" \
  : "=r"(__FindVar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindVar__bn), "rf"(__FindVar_name), "rf"(__FindVar_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CliInitNewcli(dp) ({ \
  struct DosPacket * _CliInitNewcli_dp = (dp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CliInitNewcli__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __CliInitNewcli__re __asm("d0"); \
  register struct DosPacket * __CliInitNewcli_dp __asm("a0") = (_CliInitNewcli_dp); \
  __asm volatile ("jsr a6@(-930:W)" \
  : "=r"(__CliInitNewcli__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CliInitNewcli__bn), "rf"(__CliInitNewcli_dp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CliInitRun(dp) ({ \
  struct DosPacket * _CliInitRun_dp = (dp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CliInitRun__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __CliInitRun__re __asm("d0"); \
  register struct DosPacket * __CliInitRun_dp __asm("a0") = (_CliInitRun_dp); \
  __asm volatile ("jsr a6@(-936:W)" \
  : "=r"(__CliInitRun__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CliInitRun__bn), "rf"(__CliInitRun_dp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define WriteChars(buf, buflen) ({ \
  CONST_STRPTR _WriteChars_buf = (buf); \
  ULONG _WriteChars_buflen = (buflen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WriteChars__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __WriteChars__re __asm("d0"); \
  register CONST_STRPTR __WriteChars_buf __asm("d1") = (_WriteChars_buf); \
  register ULONG __WriteChars_buflen __asm("d2") = (_WriteChars_buflen); \
  __asm volatile ("jsr a6@(-942:W)" \
  : "=r"(__WriteChars__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WriteChars__bn), "rf"(__WriteChars_buf), "rf"(__WriteChars_buflen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define PutStr(str) ({ \
  CONST_STRPTR _PutStr_str = (str); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __PutStr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __PutStr__re __asm("d0"); \
  register CONST_STRPTR __PutStr_str __asm("d1") = (_PutStr_str); \
  __asm volatile ("jsr a6@(-948:W)" \
  : "=r"(__PutStr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__PutStr__bn), "rf"(__PutStr_str) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define VPrintf(format, argarray) ({ \
  CONST_STRPTR _VPrintf_format = (format); \
  CONST APTR _VPrintf_argarray = (argarray); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __VPrintf__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __VPrintf__re __asm("d0"); \
  register CONST_STRPTR __VPrintf_format __asm("d1") = (_VPrintf_format); \
  register CONST APTR __VPrintf_argarray __asm("d2") = (_VPrintf_argarray); \
  __asm volatile ("jsr a6@(-954:W)" \
  : "=r"(__VPrintf__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__VPrintf__bn), "rf"(__VPrintf_format), "rf"(__VPrintf_argarray) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___Printf(struct Library * DOSBase, CONST_STRPTR format, ULONG argarray, ...)
{
  return VPrintf(format, (CONST APTR) &argarray);
}

#define Printf(format...) ___Printf(DOS_BASE_NAME, format)
#endif

#define ParsePatternNoCase(pat, buf, buflen) ({ \
  CONST_STRPTR _ParsePatternNoCase_pat = (pat); \
  STRPTR _ParsePatternNoCase_buf = (buf); \
  LONG _ParsePatternNoCase_buflen = (buflen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ParsePatternNoCase__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ParsePatternNoCase__re __asm("d0"); \
  register CONST_STRPTR __ParsePatternNoCase_pat __asm("d1") = (_ParsePatternNoCase_pat); \
  register STRPTR __ParsePatternNoCase_buf __asm("d2") = (_ParsePatternNoCase_buf); \
  register LONG __ParsePatternNoCase_buflen __asm("d3") = (_ParsePatternNoCase_buflen); \
  __asm volatile ("jsr a6@(-966:W)" \
  : "=r"(__ParsePatternNoCase__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ParsePatternNoCase__bn), "rf"(__ParsePatternNoCase_pat), "rf"(__ParsePatternNoCase_buf), "rf"(__ParsePatternNoCase_buflen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MatchPatternNoCase(pat, str) ({ \
  CONST_STRPTR _MatchPatternNoCase_pat = (pat); \
  CONST_STRPTR _MatchPatternNoCase_str = (str); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MatchPatternNoCase__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MatchPatternNoCase__re __asm("d0"); \
  register CONST_STRPTR __MatchPatternNoCase_pat __asm("d1") = (_MatchPatternNoCase_pat); \
  register CONST_STRPTR __MatchPatternNoCase_str __asm("d2") = (_MatchPatternNoCase_str); \
  __asm volatile ("jsr a6@(-972:W)" \
  : "=r"(__MatchPatternNoCase__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MatchPatternNoCase__bn), "rf"(__MatchPatternNoCase_pat), "rf"(__MatchPatternNoCase_str) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SameDevice(lock1, lock2) ({ \
  BPTR _SameDevice_lock1 = (lock1); \
  BPTR _SameDevice_lock2 = (lock2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SameDevice__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SameDevice__re __asm("d0"); \
  register BPTR __SameDevice_lock1 __asm("d1") = (_SameDevice_lock1); \
  register BPTR __SameDevice_lock2 __asm("d2") = (_SameDevice_lock2); \
  __asm volatile ("jsr a6@(-984:W)" \
  : "=r"(__SameDevice__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SameDevice__bn), "rf"(__SameDevice_lock1), "rf"(__SameDevice_lock2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define OBSOLETEExAllEnd(lock, buffer, size, data, control) ({ \
  BPTR _OBSOLETEExAllEnd_lock = (lock); \
  struct ExAllData * _OBSOLETEExAllEnd_buffer = (buffer); \
  LONG _OBSOLETEExAllEnd_size = (size); \
  LONG _OBSOLETEExAllEnd_data = (data); \
  struct ExAllControl * _OBSOLETEExAllEnd_control = (control); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETEExAllEnd__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __OBSOLETEExAllEnd_lock __asm("d1") = (_OBSOLETEExAllEnd_lock); \
  register struct ExAllData * __OBSOLETEExAllEnd_buffer __asm("d2") = (_OBSOLETEExAllEnd_buffer); \
  register LONG __OBSOLETEExAllEnd_size __asm("d3") = (_OBSOLETEExAllEnd_size); \
  register LONG __OBSOLETEExAllEnd_data __asm("d4") = (_OBSOLETEExAllEnd_data); \
  register struct ExAllControl * __OBSOLETEExAllEnd_control __asm("d5") = (_OBSOLETEExAllEnd_control); \
  __asm volatile ("jsr a6@(-990:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETEExAllEnd__bn), "rf"(__OBSOLETEExAllEnd_lock), "rf"(__OBSOLETEExAllEnd_buffer), "rf"(__OBSOLETEExAllEnd_size), "rf"(__OBSOLETEExAllEnd_data), "rf"(__OBSOLETEExAllEnd_control) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OBSOLETESetOwner(name, owner_info) ({ \
  CONST_STRPTR _OBSOLETESetOwner_name = (name); \
  ULONG _OBSOLETESetOwner_owner_info = (owner_info); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __OBSOLETESetOwner__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __OBSOLETESetOwner__re __asm("d0"); \
  register CONST_STRPTR __OBSOLETESetOwner_name __asm("d1") = (_OBSOLETESetOwner_name); \
  register ULONG __OBSOLETESetOwner_owner_info __asm("d2") = (_OBSOLETESetOwner_owner_info); \
  __asm volatile ("jsr a6@(-996:W)" \
  : "=r"(__OBSOLETESetOwner__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__OBSOLETESetOwner__bn), "rf"(__OBSOLETESetOwner_name), "rf"(__OBSOLETESetOwner_owner_info) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetEntryData() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetEntryData__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetEntryData__re __asm("d0"); \
  __asm volatile ("jsr a6@(-1002:W)" \
  : "=r"(__GetEntryData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetEntryData__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReadLineItem(buffer, maxchars, tags) ({ \
  STRPTR _ReadLineItem_buffer = (buffer); \
  LONG _ReadLineItem_maxchars = (maxchars); \
  const struct TagItem * _ReadLineItem_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReadLineItem__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ReadLineItem__re __asm("d0"); \
  register STRPTR __ReadLineItem_buffer __asm("d1") = (_ReadLineItem_buffer); \
  register LONG __ReadLineItem_maxchars __asm("d2") = (_ReadLineItem_maxchars); \
  register const struct TagItem * __ReadLineItem_tags __asm("d3") = (_ReadLineItem_tags); \
  __asm volatile ("jsr a6@(-1008:W)" \
  : "=r"(__ReadLineItem__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReadLineItem__bn), "rf"(__ReadLineItem_buffer), "rf"(__ReadLineItem_maxchars), "rf"(__ReadLineItem_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___ReadLineItemTags(struct Library * DOSBase, STRPTR buffer, LONG maxchars, ULONG tags, ...)
{
  return ReadLineItem(buffer, maxchars, (const struct TagItem *) &tags);
}

#define ReadLineItemTags(buffer, maxchars...) ___ReadLineItemTags(DOS_BASE_NAME, buffer, maxchars)
#endif

#define GetCurrentDir() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetCurrentDir__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __GetCurrentDir__re __asm("d0"); \
  __asm volatile ("jsr a6@(-1026:W)" \
  : "=r"(__GetCurrentDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetCurrentDir__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NonBlockingModifyDosEntry(dl, mode, arg1, arg2) ({ \
  struct DosList * _NonBlockingModifyDosEntry_dl = (dl); \
  LONG _NonBlockingModifyDosEntry_mode = (mode); \
  APTR _NonBlockingModifyDosEntry_arg1 = (arg1); \
  APTR _NonBlockingModifyDosEntry_arg2 = (arg2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NonBlockingModifyDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NonBlockingModifyDosEntry__re __asm("d0"); \
  register struct DosList * __NonBlockingModifyDosEntry_dl __asm("d1") = (_NonBlockingModifyDosEntry_dl); \
  register LONG __NonBlockingModifyDosEntry_mode __asm("d2") = (_NonBlockingModifyDosEntry_mode); \
  register APTR __NonBlockingModifyDosEntry_arg1 __asm("d3") = (_NonBlockingModifyDosEntry_arg1); \
  register APTR __NonBlockingModifyDosEntry_arg2 __asm("d4") = (_NonBlockingModifyDosEntry_arg2); \
  __asm volatile ("jsr a6@(-1032:W)" \
  : "=r"(__NonBlockingModifyDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NonBlockingModifyDosEntry__bn), "rf"(__NonBlockingModifyDosEntry_dl), "rf"(__NonBlockingModifyDosEntry_mode), "rf"(__NonBlockingModifyDosEntry_arg1), "rf"(__NonBlockingModifyDosEntry_arg2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SecondsToDateStamp(seconds, ds) ({ \
  ULONG _SecondsToDateStamp_seconds = (seconds); \
  struct DateStamp * _SecondsToDateStamp_ds = (ds); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SecondsToDateStamp__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DateStamp * __SecondsToDateStamp__re __asm("d0"); \
  register ULONG __SecondsToDateStamp_seconds __asm("d1") = (_SecondsToDateStamp_seconds); \
  register struct DateStamp * __SecondsToDateStamp_ds __asm("d2") = (_SecondsToDateStamp_ds); \
  __asm volatile ("jsr a6@(-1038:W)" \
  : "=r"(__SecondsToDateStamp__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SecondsToDateStamp__bn), "rf"(__SecondsToDateStamp_seconds), "rf"(__SecondsToDateStamp_ds) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DateStampToSeconds(ds) ({ \
  const struct DateStamp * _DateStampToSeconds_ds = (ds); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DateStampToSeconds__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __DateStampToSeconds__re __asm("d0"); \
  register const struct DateStamp * __DateStampToSeconds_ds __asm("d1") = (_DateStampToSeconds_ds); \
  __asm volatile ("jsr a6@(-1044:W)" \
  : "=r"(__DateStampToSeconds__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DateStampToSeconds__bn), "rf"(__DateStampToSeconds_ds) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FixDateStamp(ds) ({ \
  struct DateStamp * _FixDateStamp_ds = (ds); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FixDateStamp__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FixDateStamp__re __asm("d0"); \
  register struct DateStamp * __FixDateStamp_ds __asm("a0") = (_FixDateStamp_ds); \
  __asm volatile ("jsr a6@(-1050:W)" \
  : "=r"(__FixDateStamp__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FixDateStamp__bn), "rf"(__FixDateStamp_ds) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddDates(to, from) ({ \
  struct DateStamp * _AddDates_to = (to); \
  CONST struct DateStamp * _AddDates_from = (from); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddDates__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddDates__re __asm("d0"); \
  register struct DateStamp * __AddDates_to __asm("a0") = (_AddDates_to); \
  register CONST struct DateStamp * __AddDates_from __asm("a1") = (_AddDates_from); \
  __asm volatile ("jsr a6@(-1056:W)" \
  : "=r"(__AddDates__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddDates__bn), "rf"(__AddDates_to), "rf"(__AddDates_from) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SubtractDates(to, from) ({ \
  struct DateStamp * _SubtractDates_to = (to); \
  CONST struct DateStamp * _SubtractDates_from = (from); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SubtractDates__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SubtractDates__re __asm("d0"); \
  register struct DateStamp * __SubtractDates_to __asm("a0") = (_SubtractDates_to); \
  register CONST struct DateStamp * __SubtractDates_from __asm("a1") = (_SubtractDates_from); \
  __asm volatile ("jsr a6@(-1062:W)" \
  : "=r"(__SubtractDates__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SubtractDates__bn), "rf"(__SubtractDates_to), "rf"(__SubtractDates_from) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddSegmentTagList(name, type, tags) ({ \
  CONST_STRPTR _AddSegmentTagList_name = (name); \
  LONG _AddSegmentTagList_type = (type); \
  const struct TagItem * _AddSegmentTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddSegmentTagList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddSegmentTagList__re __asm("d0"); \
  register CONST_STRPTR __AddSegmentTagList_name __asm("d1") = (_AddSegmentTagList_name); \
  register LONG __AddSegmentTagList_type __asm("d2") = (_AddSegmentTagList_type); \
  register const struct TagItem * __AddSegmentTagList_tags __asm("d3") = (_AddSegmentTagList_tags); \
  __asm volatile ("jsr a6@(-1068:W)" \
  : "=r"(__AddSegmentTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddSegmentTagList__bn), "rf"(__AddSegmentTagList_name), "rf"(__AddSegmentTagList_type), "rf"(__AddSegmentTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ParseCapturePattern(pat, dst, length, casesen) ({ \
  CONST_STRPTR _ParseCapturePattern_pat = (pat); \
  STRPTR _ParseCapturePattern_dst = (dst); \
  LONG _ParseCapturePattern_length = (length); \
  LONG _ParseCapturePattern_casesen = (casesen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ParseCapturePattern__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ParseCapturePattern__re __asm("d0"); \
  register CONST_STRPTR __ParseCapturePattern_pat __asm("a0") = (_ParseCapturePattern_pat); \
  register STRPTR __ParseCapturePattern_dst __asm("a1") = (_ParseCapturePattern_dst); \
  register LONG __ParseCapturePattern_length __asm("d0") = (_ParseCapturePattern_length); \
  register LONG __ParseCapturePattern_casesen __asm("d1") = (_ParseCapturePattern_casesen); \
  __asm volatile ("jsr a6@(-1074:W)" \
  : "=r"(__ParseCapturePattern__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ParseCapturePattern__bn), "rf"(__ParseCapturePattern_pat), "rf"(__ParseCapturePattern_dst), "rf"(__ParseCapturePattern_length), "rf"(__ParseCapturePattern_casesen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CapturePattern(pat, str, casesen, cap) ({ \
  CONST_STRPTR _CapturePattern_pat = (pat); \
  CONST_STRPTR _CapturePattern_str = (str); \
  LONG _CapturePattern_casesen = (casesen); \
  struct CapturedExpression ** _CapturePattern_cap = (cap); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CapturePattern__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __CapturePattern__re __asm("d0"); \
  register CONST_STRPTR __CapturePattern_pat __asm("a0") = (_CapturePattern_pat); \
  register CONST_STRPTR __CapturePattern_str __asm("a1") = (_CapturePattern_str); \
  register LONG __CapturePattern_casesen __asm("d0") = (_CapturePattern_casesen); \
  register struct CapturedExpression ** __CapturePattern_cap __asm("a2") = (_CapturePattern_cap); \
  __asm volatile ("jsr a6@(-1080:W)" \
  : "=r"(__CapturePattern__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CapturePattern__bn), "rf"(__CapturePattern_pat), "rf"(__CapturePattern_str), "rf"(__CapturePattern_casesen), "rf"(__CapturePattern_cap) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReleaseCapturedExpressions(first) ({ \
  struct CapturedExpression * _ReleaseCapturedExpressions_first = (first); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseCapturedExpressions__bn __asm("a6") = DOS_BASE_NAME;\
  register struct CapturedExpression * __ReleaseCapturedExpressions_first __asm("a0") = (_ReleaseCapturedExpressions_first); \
  __asm volatile ("jsr a6@(-1086:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseCapturedExpressions__bn), "rf"(__ReleaseCapturedExpressions_first) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindTrackedAddress(address, hook) ({ \
  CONST APTR _FindTrackedAddress_address = (address); \
  struct Hook * _FindTrackedAddress_hook = (hook); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindTrackedAddress__bn __asm("a6") = DOS_BASE_NAME;\
  register CONST APTR __FindTrackedAddress_address __asm("a0") = (_FindTrackedAddress_address); \
  register struct Hook * __FindTrackedAddress_hook __asm("a1") = (_FindTrackedAddress_hook); \
  __asm volatile ("jsr a6@(-1092:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindTrackedAddress__bn), "rf"(__FindTrackedAddress_address), "rf"(__FindTrackedAddress_hook) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define TrackAddressList(name, segment, extra_info, extra_info_size, aas, num_pairs) ({ \
  CONST_STRPTR _TrackAddressList_name = (name); \
  BPTR _TrackAddressList_segment = (segment); \
  CONST APTR _TrackAddressList_extra_info = (extra_info); \
  LONG _TrackAddressList_extra_info_size = (extra_info_size); \
  const struct AddressAndSize * _TrackAddressList_aas = (aas); \
  LONG _TrackAddressList_num_pairs = (num_pairs); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __TrackAddressList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __TrackAddressList__re __asm("d0"); \
  register CONST_STRPTR __TrackAddressList_name __asm("a0") = (_TrackAddressList_name); \
  register BPTR __TrackAddressList_segment __asm("d0") = (_TrackAddressList_segment); \
  register CONST APTR __TrackAddressList_extra_info __asm("a1") = (_TrackAddressList_extra_info); \
  register LONG __TrackAddressList_extra_info_size __asm("d1") = (_TrackAddressList_extra_info_size); \
  register const struct AddressAndSize * __TrackAddressList_aas __asm("a2") = (_TrackAddressList_aas); \
  register LONG __TrackAddressList_num_pairs __asm("d2") = (_TrackAddressList_num_pairs); \
  __asm volatile ("jsr a6@(-1098:W)" \
  : "=r"(__TrackAddressList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__TrackAddressList__bn), "rf"(__TrackAddressList_name), "rf"(__TrackAddressList_segment), "rf"(__TrackAddressList_extra_info), "rf"(__TrackAddressList_extra_info_size), "rf"(__TrackAddressList_aas), "rf"(__TrackAddressList_num_pairs) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define TrackSegmentList(name, segment, extra_info, extra_info_size) ({ \
  CONST_STRPTR _TrackSegmentList_name = (name); \
  BPTR _TrackSegmentList_segment = (segment); \
  CONST APTR _TrackSegmentList_extra_info = (extra_info); \
  LONG _TrackSegmentList_extra_info_size = (extra_info_size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __TrackSegmentList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __TrackSegmentList__re __asm("d0"); \
  register CONST_STRPTR __TrackSegmentList_name __asm("a0") = (_TrackSegmentList_name); \
  register BPTR __TrackSegmentList_segment __asm("d0") = (_TrackSegmentList_segment); \
  register CONST APTR __TrackSegmentList_extra_info __asm("a1") = (_TrackSegmentList_extra_info); \
  register LONG __TrackSegmentList_extra_info_size __asm("d1") = (_TrackSegmentList_extra_info_size); \
  __asm volatile ("jsr a6@(-1104:W)" \
  : "=r"(__TrackSegmentList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__TrackSegmentList__bn), "rf"(__TrackSegmentList_name), "rf"(__TrackSegmentList_segment), "rf"(__TrackSegmentList_extra_info), "rf"(__TrackSegmentList_extra_info_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define UnTrackAddress(address) ({ \
  APTR _UnTrackAddress_address = (address); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnTrackAddress__bn __asm("a6") = DOS_BASE_NAME;\
  register APTR __UnTrackAddress_address __asm("a0") = (_UnTrackAddress_address); \
  __asm volatile ("jsr a6@(-1110:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnTrackAddress__bn), "rf"(__UnTrackAddress_address) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define UnTrackSegmentList(segment) ({ \
  BPTR _UnTrackSegmentList_segment = (segment); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __UnTrackSegmentList__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __UnTrackSegmentList_segment __asm("d0") = (_UnTrackSegmentList_segment); \
  __asm volatile ("jsr a6@(-1116:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__UnTrackSegmentList__bn), "rf"(__UnTrackSegmentList_segment) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetExitData() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetExitData__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetExitData__re __asm("d0"); \
  __asm volatile ("jsr a6@(-1122:W)" \
  : "=r"(__GetExitData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetExitData__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define PutErrStr(str) ({ \
  CONST_STRPTR _PutErrStr_str = (str); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __PutErrStr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __PutErrStr__re __asm("d0"); \
  register CONST_STRPTR __PutErrStr_str __asm("d1") = (_PutErrStr_str); \
  __asm volatile ("jsr a6@(-1128:W)" \
  : "=r"(__PutErrStr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__PutErrStr__bn), "rf"(__PutErrStr_str) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ErrorOutput() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ErrorOutput__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __ErrorOutput__re __asm("d0"); \
  __asm volatile ("jsr a6@(-1134:W)" \
  : "=r"(__ErrorOutput__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ErrorOutput__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SelectErrorOutput(fh) ({ \
  BPTR _SelectErrorOutput_fh = (fh); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SelectErrorOutput__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __SelectErrorOutput__re __asm("d0"); \
  register BPTR __SelectErrorOutput_fh __asm("d1") = (_SelectErrorOutput_fh); \
  __asm volatile ("jsr a6@(-1140:W)" \
  : "=r"(__SelectErrorOutput__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SelectErrorOutput__bn), "rf"(__SelectErrorOutput_fh) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define MountDevice(name, type, tags) ({ \
  CONST_STRPTR _MountDevice_name = (name); \
  LONG _MountDevice_type = (type); \
  const struct TagItem * _MountDevice_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __MountDevice__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __MountDevice__re __asm("d0"); \
  register CONST_STRPTR __MountDevice_name __asm("a0") = (_MountDevice_name); \
  register LONG __MountDevice_type __asm("a1") = (_MountDevice_type); \
  register const struct TagItem * __MountDevice_tags __asm("a2") = (_MountDevice_tags); \
  __asm volatile ("jsr a6@(-1146:W)" \
  : "=r"(__MountDevice__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__MountDevice__bn), "rf"(__MountDevice_name), "rf"(__MountDevice_type), "rf"(__MountDevice_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___MountDeviceTags(struct Library * DOSBase, CONST_STRPTR name, LONG type, ULONG tags, ...)
{
  return MountDevice(name, type, (const struct TagItem *) &tags);
}

#define MountDeviceTags(name, type...) ___MountDeviceTags(DOS_BASE_NAME, name, type)
#endif

#define SetProcWindow(win) ({ \
  CONST APTR _SetProcWindow_win = (win); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetProcWindow__bn __asm("a6") = DOS_BASE_NAME;\
  register APTR __SetProcWindow__re __asm("d0"); \
  register CONST APTR __SetProcWindow_win __asm("a0") = (_SetProcWindow_win); \
  __asm volatile ("jsr a6@(-1152:W)" \
  : "=r"(__SetProcWindow__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetProcWindow__bn), "rf"(__SetProcWindow_win) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FindSegmentStackSize(segment) ({ \
  BPTR _FindSegmentStackSize_segment = (segment); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FindSegmentStackSize__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __FindSegmentStackSize__re __asm("d0"); \
  register BPTR __FindSegmentStackSize_segment __asm("d0") = (_FindSegmentStackSize_segment); \
  __asm volatile ("jsr a6@(-1158:W)" \
  : "=r"(__FindSegmentStackSize__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FindSegmentStackSize__bn), "rf"(__FindSegmentStackSize_segment) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CalculateSegmentChecksum(segment) ({ \
  BPTR _CalculateSegmentChecksum_segment = (segment); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CalculateSegmentChecksum__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __CalculateSegmentChecksum__re __asm("d0"); \
  register BPTR __CalculateSegmentChecksum_segment __asm("d0") = (_CalculateSegmentChecksum_segment); \
  __asm volatile ("jsr a6@(-1164:W)" \
  : "=r"(__CalculateSegmentChecksum__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CalculateSegmentChecksum__bn), "rf"(__CalculateSegmentChecksum_segment) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AllocSegList(entry, data, datalen, identkey) ({ \
  CONST APTR _AllocSegList_entry = (entry); \
  CONST APTR _AllocSegList_data = (data); \
  ULONG _AllocSegList_datalen = (datalen); \
  ULONG _AllocSegList_identkey = (identkey); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AllocSegList__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __AllocSegList__re __asm("d0"); \
  register CONST APTR __AllocSegList_entry __asm("a0") = (_AllocSegList_entry); \
  register CONST APTR __AllocSegList_data __asm("a1") = (_AllocSegList_data); \
  register ULONG __AllocSegList_datalen __asm("d0") = (_AllocSegList_datalen); \
  register ULONG __AllocSegList_identkey __asm("d1") = (_AllocSegList_identkey); \
  __asm volatile ("jsr a6@(-1170:W)" \
  : "=r"(__AllocSegList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AllocSegList__bn), "rf"(__AllocSegList_entry), "rf"(__AllocSegList_data), "rf"(__AllocSegList_datalen), "rf"(__AllocSegList_identkey) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetSegListInfo(seglist, tags) ({ \
  BPTR _GetSegListInfo_seglist = (seglist); \
  const struct TagItem * _GetSegListInfo_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetSegListInfo__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetSegListInfo__re __asm("d0"); \
  register BPTR __GetSegListInfo_seglist __asm("d0") = (_GetSegListInfo_seglist); \
  register const struct TagItem * __GetSegListInfo_tags __asm("a0") = (_GetSegListInfo_tags); \
  __asm volatile ("jsr a6@(-1176:W)" \
  : "=r"(__GetSegListInfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetSegListInfo__bn), "rf"(__GetSegListInfo_seglist), "rf"(__GetSegListInfo_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetSegListInfoTags(struct Library * DOSBase, BPTR seglist, ULONG tags, ...)
{
  return GetSegListInfo(seglist, (const struct TagItem *) &tags);
}

#define GetSegListInfoTags(seglist...) ___GetSegListInfoTags(DOS_BASE_NAME, seglist)
#endif

#define AddSegListTail(bseglist_head, bseg_new) ({ \
  BPTR _AddSegListTail_bseglist_head = (bseglist_head); \
  BPTR _AddSegListTail_bseg_new = (bseg_new); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddSegListTail__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AddSegListTail__re __asm("d0"); \
  register BPTR __AddSegListTail_bseglist_head __asm("a0") = (_AddSegListTail_bseglist_head); \
  register BPTR __AddSegListTail_bseg_new __asm("a1") = (_AddSegListTail_bseg_new); \
  __asm volatile ("jsr a6@(-1182:W)" \
  : "=r"(__AddSegListTail__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddSegListTail__bn), "rf"(__AddSegListTail_bseglist_head), "rf"(__AddSegListTail_bseg_new) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DevNameFromLock(lock, buffer, buflen, mode) ({ \
  BPTR _DevNameFromLock_lock = (lock); \
  STRPTR _DevNameFromLock_buffer = (buffer); \
  LONG _DevNameFromLock_buflen = (buflen); \
  LONG _DevNameFromLock_mode = (mode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DevNameFromLock__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DevNameFromLock__re __asm("d0"); \
  register BPTR __DevNameFromLock_lock __asm("d1") = (_DevNameFromLock_lock); \
  register STRPTR __DevNameFromLock_buffer __asm("d2") = (_DevNameFromLock_buffer); \
  register LONG __DevNameFromLock_buflen __asm("d3") = (_DevNameFromLock_buflen); \
  register LONG __DevNameFromLock_mode __asm("d4") = (_DevNameFromLock_mode); \
  __asm volatile ("jsr a6@(-1188:W)" \
  : "=r"(__DevNameFromLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DevNameFromLock__bn), "rf"(__DevNameFromLock_lock), "rf"(__DevNameFromLock_buffer), "rf"(__DevNameFromLock_buflen), "rf"(__DevNameFromLock_mode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetProcMsgPort(proc) ({ \
  const struct Process * _GetProcMsgPort_proc = (proc); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetProcMsgPort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct MsgPort * __GetProcMsgPort__re __asm("d0"); \
  register const struct Process * __GetProcMsgPort_proc __asm("a0") = (_GetProcMsgPort_proc); \
  __asm volatile ("jsr a6@(-1194:W)" \
  : "=r"(__GetProcMsgPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetProcMsgPort__bn), "rf"(__GetProcMsgPort_proc) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define WaitForData(stream, data_direction, timeout) ({ \
  BPTR _WaitForData_stream = (stream); \
  LONG _WaitForData_data_direction = (data_direction); \
  LONG _WaitForData_timeout = (timeout); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WaitForData__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __WaitForData__re __asm("d0"); \
  register BPTR __WaitForData_stream __asm("d0") = (_WaitForData_stream); \
  register LONG __WaitForData_data_direction __asm("d1") = (_WaitForData_data_direction); \
  register LONG __WaitForData_timeout __asm("d2") = (_WaitForData_timeout); \
  __asm volatile ("jsr a6@(-1200:W)" \
  : "=r"(__WaitForData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WaitForData__bn), "rf"(__WaitForData_stream), "rf"(__WaitForData_data_direction), "rf"(__WaitForData_timeout) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetBlockingMode(stream, new_blocking_mode) ({ \
  BPTR _SetBlockingMode_stream = (stream); \
  LONG _SetBlockingMode_new_blocking_mode = (new_blocking_mode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetBlockingMode__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetBlockingMode__re __asm("d0"); \
  register BPTR __SetBlockingMode_stream __asm("d0") = (_SetBlockingMode_stream); \
  register LONG __SetBlockingMode_new_blocking_mode __asm("d1") = (_SetBlockingMode_new_blocking_mode); \
  __asm volatile ("jsr a6@(-1206:W)" \
  : "=r"(__SetBlockingMode__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetBlockingMode__bn), "rf"(__SetBlockingMode_stream), "rf"(__SetBlockingMode_new_blocking_mode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetCurrentCmdPathList(pn) ({ \
  struct PathNode * _SetCurrentCmdPathList_pn = (pn); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetCurrentCmdPathList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __SetCurrentCmdPathList__re __asm("d0"); \
  register struct PathNode * __SetCurrentCmdPathList_pn __asm("a0") = (_SetCurrentCmdPathList_pn); \
  __asm volatile ("jsr a6@(-1212:W)" \
  : "=r"(__SetCurrentCmdPathList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetCurrentCmdPathList__bn), "rf"(__SetCurrentCmdPathList_pn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AllocateCmdPathList(first_lock) ({ \
  BPTR _AllocateCmdPathList_first_lock = (first_lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AllocateCmdPathList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __AllocateCmdPathList__re __asm("d0"); \
  register BPTR __AllocateCmdPathList_first_lock __asm("d0") = (_AllocateCmdPathList_first_lock); \
  __asm volatile ("jsr a6@(-1218:W)" \
  : "=r"(__AllocateCmdPathList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AllocateCmdPathList__bn), "rf"(__AllocateCmdPathList_first_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FreeCmdPathList(pn) ({ \
  struct PathNode * _FreeCmdPathList_pn = (pn); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeCmdPathList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __FreeCmdPathList_pn __asm("a0") = (_FreeCmdPathList_pn); \
  __asm volatile ("jsr a6@(-1224:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeCmdPathList__bn), "rf"(__FreeCmdPathList_pn) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemoveCmdPathNode(pn, lock) ({ \
  struct PathNode * _RemoveCmdPathNode_pn = (pn); \
  BPTR _RemoveCmdPathNode_lock = (lock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemoveCmdPathNode__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __RemoveCmdPathNode__re __asm("d0"); \
  register struct PathNode * __RemoveCmdPathNode_pn __asm("a0") = (_RemoveCmdPathNode_pn); \
  register BPTR __RemoveCmdPathNode_lock __asm("d0") = (_RemoveCmdPathNode_lock); \
  __asm volatile ("jsr a6@(-1230:W)" \
  : "=r"(__RemoveCmdPathNode__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemoveCmdPathNode__bn), "rf"(__RemoveCmdPathNode_pn), "rf"(__RemoveCmdPathNode_lock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddCmdPathNode(pn, lock, where) ({ \
  struct PathNode * _AddCmdPathNode_pn = (pn); \
  BPTR _AddCmdPathNode_lock = (lock); \
  LONG _AddCmdPathNode_where = (where); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddCmdPathNode__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __AddCmdPathNode__re __asm("d0"); \
  register struct PathNode * __AddCmdPathNode_pn __asm("a0") = (_AddCmdPathNode_pn); \
  register BPTR __AddCmdPathNode_lock __asm("d0") = (_AddCmdPathNode_lock); \
  register LONG __AddCmdPathNode_where __asm("d1") = (_AddCmdPathNode_where); \
  __asm volatile ("jsr a6@(-1236:W)" \
  : "=r"(__AddCmdPathNode__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddCmdPathNode__bn), "rf"(__AddCmdPathNode_pn), "rf"(__AddCmdPathNode_lock), "rf"(__AddCmdPathNode_where) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SearchCmdPathList(pn, h, name, tags) ({ \
  const struct PathNode * _SearchCmdPathList_pn = (pn); \
  const struct Hook * _SearchCmdPathList_h = (h); \
  CONST_STRPTR _SearchCmdPathList_name = (name); \
  const struct TagItem * _SearchCmdPathList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SearchCmdPathList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SearchCmdPathList__re __asm("d0"); \
  register const struct PathNode * __SearchCmdPathList_pn __asm("a0") = (_SearchCmdPathList_pn); \
  register const struct Hook * __SearchCmdPathList_h __asm("a1") = (_SearchCmdPathList_h); \
  register CONST_STRPTR __SearchCmdPathList_name __asm("a2") = (_SearchCmdPathList_name); \
  register const struct TagItem * __SearchCmdPathList_tags __asm("a3") = (_SearchCmdPathList_tags); \
  __asm volatile ("jsr a6@(-1242:W)" \
  : "=r"(__SearchCmdPathList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SearchCmdPathList__bn), "rf"(__SearchCmdPathList_pn), "rf"(__SearchCmdPathList_h), "rf"(__SearchCmdPathList_name), "rf"(__SearchCmdPathList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SearchCmdPathListTags(struct Library * DOSBase, const struct PathNode * pn, const struct Hook * h, CONST_STRPTR name, ULONG tags, ...)
{
  return SearchCmdPathList(pn, h, name, (const struct TagItem *) &tags);
}

#define SearchCmdPathListTags(pn, h, name...) ___SearchCmdPathListTags(DOS_BASE_NAME, pn, h, name)
#endif

#define ScanVars(hook, flags, userdata) ({ \
  const struct Hook * _ScanVars_hook = (hook); \
  ULONG _ScanVars_flags = (flags); \
  CONST APTR _ScanVars_userdata = (userdata); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ScanVars__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ScanVars__re __asm("d0"); \
  register const struct Hook * __ScanVars_hook __asm("d1") = (_ScanVars_hook); \
  register ULONG __ScanVars_flags __asm("d2") = (_ScanVars_flags); \
  register CONST APTR __ScanVars_userdata __asm("d3") = (_ScanVars_userdata); \
  __asm volatile ("jsr a6@(-1248:W)" \
  : "=r"(__ScanVars__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ScanVars__bn), "rf"(__ScanVars_hook), "rf"(__ScanVars_flags), "rf"(__ScanVars_userdata) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetProcSegList(proc, flags) ({ \
  const struct Process * _GetProcSegList_proc = (proc); \
  ULONG _GetProcSegList_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetProcSegList__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __GetProcSegList__re __asm("d0"); \
  register const struct Process * __GetProcSegList_proc __asm("a0") = (_GetProcSegList_proc); \
  register ULONG __GetProcSegList_flags __asm("d0") = (_GetProcSegList_flags); \
  __asm volatile ("jsr a6@(-1254:W)" \
  : "=r"(__GetProcSegList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetProcSegList__bn), "rf"(__GetProcSegList_proc), "rf"(__GetProcSegList_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define HexToLong(string, value_ptr) ({ \
  CONST_STRPTR _HexToLong_string = (string); \
  ULONG * _HexToLong_value_ptr = (value_ptr); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __HexToLong__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __HexToLong__re __asm("d0"); \
  register CONST_STRPTR __HexToLong_string __asm("d1") = (_HexToLong_string); \
  register ULONG * __HexToLong_value_ptr __asm("d2") = (_HexToLong_value_ptr); \
  __asm volatile ("jsr a6@(-1260:W)" \
  : "=r"(__HexToLong__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__HexToLong__bn), "rf"(__HexToLong_string), "rf"(__HexToLong_value_ptr) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetDeviceProcFlags(name, odp, flags) ({ \
  CONST_STRPTR _GetDeviceProcFlags_name = (name); \
  struct DevProc * _GetDeviceProcFlags_odp = (odp); \
  ULONG _GetDeviceProcFlags_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetDeviceProcFlags__bn __asm("a6") = DOS_BASE_NAME;\
  register struct DevProc * __GetDeviceProcFlags__re __asm("d0"); \
  register CONST_STRPTR __GetDeviceProcFlags_name __asm("d1") = (_GetDeviceProcFlags_name); \
  register struct DevProc * __GetDeviceProcFlags_odp __asm("d2") = (_GetDeviceProcFlags_odp); \
  register ULONG __GetDeviceProcFlags_flags __asm("d3") = (_GetDeviceProcFlags_flags); \
  __asm volatile ("jsr a6@(-1266:W)" \
  : "=r"(__GetDeviceProcFlags__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetDeviceProcFlags__bn), "rf"(__GetDeviceProcFlags_name), "rf"(__GetDeviceProcFlags_odp), "rf"(__GetDeviceProcFlags_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DosControl(tags) ({ \
  const struct TagItem * _DosControl_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DosControl__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DosControl__re __asm("d0"); \
  register const struct TagItem * __DosControl_tags __asm("a0") = (_DosControl_tags); \
  __asm volatile ("jsr a6@(-1272:W)" \
  : "=r"(__DosControl__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DosControl__bn), "rf"(__DosControl_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___DosControlTags(struct Library * DOSBase, ULONG tags, ...)
{
  return DosControl((const struct TagItem *) &tags);
}

#define DosControlTags(tags...) ___DosControlTags(DOS_BASE_NAME, tags)
#endif

#define CreateDirTree(tree) ({ \
  CONST_STRPTR _CreateDirTree_tree = (tree); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CreateDirTree__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __CreateDirTree__re __asm("d0"); \
  register CONST_STRPTR __CreateDirTree_tree __asm("a0") = (_CreateDirTree_tree); \
  __asm volatile ("jsr a6@(-1278:W)" \
  : "=r"(__CreateDirTree__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CreateDirTree__bn), "rf"(__CreateDirTree_tree) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NotifyVar(name, hook, flags, userdata) ({ \
  CONST_STRPTR _NotifyVar_name = (name); \
  const struct Hook * _NotifyVar_hook = (hook); \
  LONG _NotifyVar_flags = (flags); \
  CONST APTR _NotifyVar_userdata = (userdata); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NotifyVar__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NotifyVar__re __asm("d0"); \
  register CONST_STRPTR __NotifyVar_name __asm("d1") = (_NotifyVar_name); \
  register const struct Hook * __NotifyVar_hook __asm("d2") = (_NotifyVar_hook); \
  register LONG __NotifyVar_flags __asm("d3") = (_NotifyVar_flags); \
  register CONST APTR __NotifyVar_userdata __asm("d4") = (_NotifyVar_userdata); \
  __asm volatile ("jsr a6@(-1284:W)" \
  : "=r"(__NotifyVar__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NotifyVar__bn), "rf"(__NotifyVar_name), "rf"(__NotifyVar_hook), "rf"(__NotifyVar_flags), "rf"(__NotifyVar_userdata) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetDiskFileSystemData(name) ({ \
  CONST_STRPTR _GetDiskFileSystemData_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetDiskFileSystemData__bn __asm("a6") = DOS_BASE_NAME;\
  register struct FileSystemData * __GetDiskFileSystemData__re __asm("d0"); \
  register CONST_STRPTR __GetDiskFileSystemData_name __asm("a0") = (_GetDiskFileSystemData_name); \
  __asm volatile ("jsr a6@(-1290:W)" \
  : "=r"(__GetDiskFileSystemData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetDiskFileSystemData__bn), "rf"(__GetDiskFileSystemData_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FreeDiskFileSystemData(fsd) ({ \
  struct FileSystemData * _FreeDiskFileSystemData_fsd = (fsd); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeDiskFileSystemData__bn __asm("a6") = DOS_BASE_NAME;\
  register struct FileSystemData * __FreeDiskFileSystemData_fsd __asm("a0") = (_FreeDiskFileSystemData_fsd); \
  __asm volatile ("jsr a6@(-1296:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeDiskFileSystemData__bn), "rf"(__FreeDiskFileSystemData_fsd) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FOpen(name, mode, bufsize) ({ \
  CONST_STRPTR _FOpen_name = (name); \
  LONG _FOpen_mode = (mode); \
  LONG _FOpen_bufsize = (bufsize); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FOpen__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __FOpen__re __asm("d0"); \
  register CONST_STRPTR __FOpen_name __asm("d1") = (_FOpen_name); \
  register LONG __FOpen_mode __asm("d2") = (_FOpen_mode); \
  register LONG __FOpen_bufsize __asm("d3") = (_FOpen_bufsize); \
  __asm volatile ("jsr a6@(-1302:W)" \
  : "=r"(__FOpen__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FOpen__bn), "rf"(__FOpen_name), "rf"(__FOpen_mode), "rf"(__FOpen_bufsize) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FClose(scb) ({ \
  BPTR _FClose_scb = (scb); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FClose__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FClose__re __asm("d0"); \
  register BPTR __FClose_scb __asm("d1") = (_FClose_scb); \
  __asm volatile ("jsr a6@(-1308:W)" \
  : "=r"(__FClose__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FClose__bn), "rf"(__FClose_scb) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FOpenFromLock(lock, bufsize) ({ \
  BPTR _FOpenFromLock_lock = (lock); \
  LONG _FOpenFromLock_bufsize = (bufsize); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FOpenFromLock__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __FOpenFromLock__re __asm("d0"); \
  register BPTR __FOpenFromLock_lock __asm("d1") = (_FOpenFromLock_lock); \
  register LONG __FOpenFromLock_bufsize __asm("d2") = (_FOpenFromLock_bufsize); \
  __asm volatile ("jsr a6@(-1314:W)" \
  : "=r"(__FOpenFromLock__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FOpenFromLock__bn), "rf"(__FOpenFromLock_lock), "rf"(__FOpenFromLock_bufsize) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DupCmdPathList(source) ({ \
  const struct PathNode * _DupCmdPathList_source = (source); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DupCmdPathList__bn __asm("a6") = DOS_BASE_NAME;\
  register struct PathNode * __DupCmdPathList__re __asm("d0"); \
  register const struct PathNode * __DupCmdPathList_source __asm("a0") = (_DupCmdPathList_source); \
  __asm volatile ("jsr a6@(-1320:W)" \
  : "=r"(__DupCmdPathList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DupCmdPathList__bn), "rf"(__DupCmdPathList_source) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define TimedDosRequester(tags) ({ \
  const struct TagItem * _TimedDosRequester_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __TimedDosRequester__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __TimedDosRequester__re __asm("d0"); \
  register const struct TagItem * __TimedDosRequester_tags __asm("a0") = (_TimedDosRequester_tags); \
  __asm volatile ("jsr a6@(-1326:W)" \
  : "=r"(__TimedDosRequester__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__TimedDosRequester__bn), "rf"(__TimedDosRequester_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___TimedDosRequesterTags(struct Library * DOSBase, ULONG tags, ...)
{
  return TimedDosRequester((const struct TagItem *) &tags);
}

#define TimedDosRequesterTags(tags...) ___TimedDosRequesterTags(DOS_BASE_NAME, tags)
#endif

#define RenameDosEntry(dlist, newname) ({ \
  struct DosList * _RenameDosEntry_dlist = (dlist); \
  CONST_STRPTR _RenameDosEntry_newname = (newname); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RenameDosEntry__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __RenameDosEntry__re __asm("d0"); \
  register struct DosList * __RenameDosEntry_dlist __asm("d1") = (_RenameDosEntry_dlist); \
  register CONST_STRPTR __RenameDosEntry_newname __asm("d2") = (_RenameDosEntry_newname); \
  __asm volatile ("jsr a6@(-1332:W)" \
  : "=r"(__RenameDosEntry__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RenameDosEntry__bn), "rf"(__RenameDosEntry_dlist), "rf"(__RenameDosEntry_newname) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DismountDevice(name, flags, reserved) ({ \
  CONST_STRPTR _DismountDevice_name = (name); \
  ULONG _DismountDevice_flags = (flags); \
  APTR _DismountDevice_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DismountDevice__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DismountDevice__re __asm("d0"); \
  register CONST_STRPTR __DismountDevice_name __asm("a0") = (_DismountDevice_name); \
  register ULONG __DismountDevice_flags __asm("a1") = (_DismountDevice_flags); \
  register APTR __DismountDevice_reserved __asm("a2") = (_DismountDevice_reserved); \
  __asm volatile ("jsr a6@(-1338:W)" \
  : "=r"(__DismountDevice__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DismountDevice__bn), "rf"(__DismountDevice_name), "rf"(__DismountDevice_flags), "rf"(__DismountDevice_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DupFileHandle(scb) ({ \
  BPTR _DupFileHandle_scb = (scb); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DupFileHandle__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __DupFileHandle__re __asm("d0"); \
  register BPTR __DupFileHandle_scb __asm("d1") = (_DupFileHandle_scb); \
  __asm volatile ("jsr a6@(-1344:W)" \
  : "=r"(__DupFileHandle__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DupFileHandle__bn), "rf"(__DupFileHandle_scb) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DevNameFromFH(scb, buffer, buflen, mode) ({ \
  BPTR _DevNameFromFH_scb = (scb); \
  STRPTR _DevNameFromFH_buffer = (buffer); \
  LONG _DevNameFromFH_buflen = (buflen); \
  LONG _DevNameFromFH_mode = (mode); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DevNameFromFH__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DevNameFromFH__re __asm("d0"); \
  register BPTR __DevNameFromFH_scb __asm("d1") = (_DevNameFromFH_scb); \
  register STRPTR __DevNameFromFH_buffer __asm("d2") = (_DevNameFromFH_buffer); \
  register LONG __DevNameFromFH_buflen __asm("d3") = (_DevNameFromFH_buflen); \
  register LONG __DevNameFromFH_mode __asm("d4") = (_DevNameFromFH_mode); \
  __asm volatile ("jsr a6@(-1350:W)" \
  : "=r"(__DevNameFromFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DevNameFromFH__bn), "rf"(__DevNameFromFH_scb), "rf"(__DevNameFromFH_buffer), "rf"(__DevNameFromFH_buflen), "rf"(__DevNameFromFH_mode) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AssignAddToList(name, lock, endpos) ({ \
  CONST_STRPTR _AssignAddToList_name = (name); \
  BPTR _AssignAddToList_lock = (lock); \
  LONG _AssignAddToList_endpos = (endpos); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AssignAddToList__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __AssignAddToList__re __asm("d0"); \
  register CONST_STRPTR __AssignAddToList_name __asm("d1") = (_AssignAddToList_name); \
  register BPTR __AssignAddToList_lock __asm("d2") = (_AssignAddToList_lock); \
  register LONG __AssignAddToList_endpos __asm("d3") = (_AssignAddToList_endpos); \
  __asm volatile ("jsr a6@(-1356:W)" \
  : "=r"(__AssignAddToList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AssignAddToList__bn), "rf"(__AssignAddToList_name), "rf"(__AssignAddToList_lock), "rf"(__AssignAddToList_endpos) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetFileHandleAttr(fh, tags) ({ \
  BPTR _SetFileHandleAttr_fh = (fh); \
  const struct TagItem * _SetFileHandleAttr_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetFileHandleAttr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetFileHandleAttr__re __asm("d0"); \
  register BPTR __SetFileHandleAttr_fh __asm("d0") = (_SetFileHandleAttr_fh); \
  register const struct TagItem * __SetFileHandleAttr_tags __asm("a0") = (_SetFileHandleAttr_tags); \
  __asm volatile ("jsr a6@(-1362:W)" \
  : "=r"(__SetFileHandleAttr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetFileHandleAttr__bn), "rf"(__SetFileHandleAttr_fh), "rf"(__SetFileHandleAttr_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetFileHandleAttrTags(struct Library * DOSBase, BPTR fh, ULONG tags, ...)
{
  return SetFileHandleAttr(fh, (const struct TagItem *) &tags);
}

#define SetFileHandleAttrTags(fh...) ___SetFileHandleAttrTags(DOS_BASE_NAME, fh)
#endif

#define FileSystemAttr(tags) ({ \
  const struct TagItem * _FileSystemAttr_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FileSystemAttr__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FileSystemAttr__re __asm("d0"); \
  register const struct TagItem * __FileSystemAttr_tags __asm("a0") = (_FileSystemAttr_tags); \
  __asm volatile ("jsr a6@(-1368:W)" \
  : "=r"(__FileSystemAttr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FileSystemAttr__bn), "rf"(__FileSystemAttr_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___FileSystemAttrTags(struct Library * DOSBase, ULONG tags, ...)
{
  return FileSystemAttr((const struct TagItem *) &tags);
}

#define FileSystemAttrTags(tags...) ___FileSystemAttrTags(DOS_BASE_NAME, tags)
#endif

#define FReadLine(fh, frld) ({ \
  BPTR _FReadLine_fh = (fh); \
  struct FReadLineData * _FReadLine_frld = (frld); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FReadLine__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FReadLine__re __asm("d0"); \
  register BPTR __FReadLine_fh __asm("d1") = (_FReadLine_fh); \
  register struct FReadLineData * __FReadLine_frld __asm("d2") = (_FReadLine_frld); \
  __asm volatile ("jsr a6@(-1374:W)" \
  : "=r"(__FReadLine__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FReadLine__bn), "rf"(__FReadLine_fh), "rf"(__FReadLine_frld) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CopyStringBSTRToC(bsrc, dst, siz) ({ \
  BSTR _CopyStringBSTRToC_bsrc = (bsrc); \
  STRPTR _CopyStringBSTRToC_dst = (dst); \
  ULONG _CopyStringBSTRToC_siz = (siz); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CopyStringBSTRToC__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __CopyStringBSTRToC__re __asm("d0"); \
  register BSTR __CopyStringBSTRToC_bsrc __asm("d1") = (_CopyStringBSTRToC_bsrc); \
  register STRPTR __CopyStringBSTRToC_dst __asm("d2") = (_CopyStringBSTRToC_dst); \
  register ULONG __CopyStringBSTRToC_siz __asm("d3") = (_CopyStringBSTRToC_siz); \
  __asm volatile ("jsr a6@(-1380:W)" \
  : "=r"(__CopyStringBSTRToC__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CopyStringBSTRToC__bn), "rf"(__CopyStringBSTRToC_bsrc), "rf"(__CopyStringBSTRToC_dst), "rf"(__CopyStringBSTRToC_siz) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CopyStringCToBSTR(src, bdest, siz) ({ \
  CONST_STRPTR _CopyStringCToBSTR_src = (src); \
  BSTR _CopyStringCToBSTR_bdest = (bdest); \
  ULONG _CopyStringCToBSTR_siz = (siz); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CopyStringCToBSTR__bn __asm("a6") = DOS_BASE_NAME;\
  register ULONG __CopyStringCToBSTR__re __asm("d0"); \
  register CONST_STRPTR __CopyStringCToBSTR_src __asm("d1") = (_CopyStringCToBSTR_src); \
  register BSTR __CopyStringCToBSTR_bdest __asm("d2") = (_CopyStringCToBSTR_bdest); \
  register ULONG __CopyStringCToBSTR_siz __asm("d3") = (_CopyStringCToBSTR_siz); \
  __asm volatile ("jsr a6@(-1386:W)" \
  : "=r"(__CopyStringCToBSTR__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CopyStringCToBSTR__bn), "rf"(__CopyStringCToBSTR_src), "rf"(__CopyStringCToBSTR_bdest), "rf"(__CopyStringCToBSTR_siz) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ProcessScan(hook, userdata, reserved) ({ \
  const struct Hook * _ProcessScan_hook = (hook); \
  CONST APTR _ProcessScan_userdata = (userdata); \
  ULONG _ProcessScan_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ProcessScan__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __ProcessScan__re __asm("d0"); \
  register const struct Hook * __ProcessScan_hook __asm("d1") = (_ProcessScan_hook); \
  register CONST APTR __ProcessScan_userdata __asm("d2") = (_ProcessScan_userdata); \
  register ULONG __ProcessScan_reserved __asm("d3") = (_ProcessScan_reserved); \
  __asm volatile ("jsr a6@(-1446:W)" \
  : "=r"(__ProcessScan__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ProcessScan__bn), "rf"(__ProcessScan_hook), "rf"(__ProcessScan_userdata), "rf"(__ProcessScan_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NotifyDosListChange(process, signalnum, reserved) ({ \
  struct Process * _NotifyDosListChange_process = (process); \
  ULONG _NotifyDosListChange_signalnum = (signalnum); \
  ULONG _NotifyDosListChange_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NotifyDosListChange__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NotifyDosListChange__re __asm("d0"); \
  register struct Process * __NotifyDosListChange_process __asm("d1") = (_NotifyDosListChange_process); \
  register ULONG __NotifyDosListChange_signalnum __asm("d2") = (_NotifyDosListChange_signalnum); \
  register ULONG __NotifyDosListChange_reserved __asm("d3") = (_NotifyDosListChange_reserved); \
  __asm volatile ("jsr a6@(-1452:W)" \
  : "=r"(__NotifyDosListChange__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NotifyDosListChange__bn), "rf"(__NotifyDosListChange_process), "rf"(__NotifyDosListChange_signalnum), "rf"(__NotifyDosListChange_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NotifyProcListChange(process, signalnum, reserved) ({ \
  struct Process * _NotifyProcListChange_process = (process); \
  ULONG _NotifyProcListChange_signalnum = (signalnum); \
  ULONG _NotifyProcListChange_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NotifyProcListChange__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NotifyProcListChange__re __asm("d0"); \
  register struct Process * __NotifyProcListChange_process __asm("d1") = (_NotifyProcListChange_process); \
  register ULONG __NotifyProcListChange_signalnum __asm("d2") = (_NotifyProcListChange_signalnum); \
  register ULONG __NotifyProcListChange_reserved __asm("d3") = (_NotifyProcListChange_reserved); \
  __asm volatile ("jsr a6@(-1458:W)" \
  : "=r"(__NotifyProcListChange__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NotifyProcListChange__bn), "rf"(__NotifyProcListChange_process), "rf"(__NotifyProcListChange_signalnum), "rf"(__NotifyProcListChange_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetDiskInfo(tags) ({ \
  const struct TagItem * _GetDiskInfo_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetDiskInfo__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetDiskInfo__re __asm("d0"); \
  register const struct TagItem * __GetDiskInfo_tags __asm("a0") = (_GetDiskInfo_tags); \
  __asm volatile ("jsr a6@(-1464:W)" \
  : "=r"(__GetDiskInfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetDiskInfo__bn), "rf"(__GetDiskInfo_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetDiskInfoTags(struct Library * DOSBase, ULONG tags, ...)
{
  return GetDiskInfo((const struct TagItem *) &tags);
}

#define GetDiskInfoTags(tags...) ___GetDiskInfoTags(DOS_BASE_NAME, tags)
#endif

#define WriteProtectVolume(name, on_off, passkey, reserved) ({ \
  CONST_STRPTR _WriteProtectVolume_name = (name); \
  LONG _WriteProtectVolume_on_off = (on_off); \
  ULONG _WriteProtectVolume_passkey = (passkey); \
  LONG _WriteProtectVolume_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WriteProtectVolume__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __WriteProtectVolume__re __asm("d0"); \
  register CONST_STRPTR __WriteProtectVolume_name __asm("d1") = (_WriteProtectVolume_name); \
  register LONG __WriteProtectVolume_on_off __asm("d2") = (_WriteProtectVolume_on_off); \
  register ULONG __WriteProtectVolume_passkey __asm("d3") = (_WriteProtectVolume_passkey); \
  register LONG __WriteProtectVolume_reserved __asm("d4") = (_WriteProtectVolume_reserved); \
  __asm volatile ("jsr a6@(-1470:W)" \
  : "=r"(__WriteProtectVolume__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WriteProtectVolume__bn), "rf"(__WriteProtectVolume_name), "rf"(__WriteProtectVolume_on_off), "rf"(__WriteProtectVolume_passkey), "rf"(__WriteProtectVolume_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ExamineObject(ctags) ({ \
  const struct TagItem * _ExamineObject_ctags = (ctags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ExamineObject__bn __asm("a6") = DOS_BASE_NAME;\
  register struct ExamineData * __ExamineObject__re __asm("d0"); \
  register const struct TagItem * __ExamineObject_ctags __asm("a0") = (_ExamineObject_ctags); \
  __asm volatile ("jsr a6@(-1476:W)" \
  : "=r"(__ExamineObject__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ExamineObject__bn), "rf"(__ExamineObject_ctags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct ExamineData * ___ExamineObjectTags(struct Library * DOSBase, ULONG ctags, ...)
{
  return ExamineObject((const struct TagItem *) &ctags);
}

#define ExamineObjectTags(tags...) ___ExamineObjectTags(DOS_BASE_NAME, tags)
#endif

#define ExamineDir(context) ({ \
  APTR _ExamineDir_context = (context); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ExamineDir__bn __asm("a6") = DOS_BASE_NAME;\
  register struct ExamineData * __ExamineDir__re __asm("d0"); \
  register APTR __ExamineDir_context __asm("a0") = (_ExamineDir_context); \
  __asm volatile ("jsr a6@(-1482:W)" \
  : "=r"(__ExamineDir__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ExamineDir__bn), "rf"(__ExamineDir_context) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ObtainDirContext(ctags) ({ \
  const struct TagItem * _ObtainDirContext_ctags = (ctags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainDirContext__bn __asm("a6") = DOS_BASE_NAME;\
  register APTR __ObtainDirContext__re __asm("d0"); \
  register const struct TagItem * __ObtainDirContext_ctags __asm("a0") = (_ObtainDirContext_ctags); \
  __asm volatile ("jsr a6@(-1488:W)" \
  : "=r"(__ObtainDirContext__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainDirContext__bn), "rf"(__ObtainDirContext_ctags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___ObtainDirContextTags(struct Library * DOSBase, ULONG ctags, ...)
{
  return ObtainDirContext((const struct TagItem *) &ctags);
}

#define ObtainDirContextTags(tags...) ___ObtainDirContextTags(DOS_BASE_NAME, tags)
#endif

#define ReleaseDirContext(contx) ({ \
  APTR _ReleaseDirContext_contx = (contx); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseDirContext__bn __asm("a6") = DOS_BASE_NAME;\
  register APTR __ReleaseDirContext_contx __asm("a0") = (_ReleaseDirContext_contx); \
  __asm volatile ("jsr a6@(-1494:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseDirContext__bn), "rf"(__ReleaseDirContext_contx) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetOwnerInfo(tags) ({ \
  const struct TagItem * _GetOwnerInfo_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetOwnerInfo__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetOwnerInfo__re __asm("d0"); \
  register const struct TagItem * __GetOwnerInfo_tags __asm("a0") = (_GetOwnerInfo_tags); \
  __asm volatile ("jsr a6@(-1500:W)" \
  : "=r"(__GetOwnerInfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetOwnerInfo__bn), "rf"(__GetOwnerInfo_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetOwnerInfoTags(struct Library * DOSBase, ULONG tags, ...)
{
  return GetOwnerInfo((const struct TagItem *) &tags);
}

#define GetOwnerInfoTags(tags...) ___GetOwnerInfoTags(DOS_BASE_NAME, tags)
#endif

#define SetOwnerInfo(tags) ({ \
  const struct TagItem * _SetOwnerInfo_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetOwnerInfo__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SetOwnerInfo__re __asm("d0"); \
  register const struct TagItem * __SetOwnerInfo_tags __asm("a0") = (_SetOwnerInfo_tags); \
  __asm volatile ("jsr a6@(-1506:W)" \
  : "=r"(__SetOwnerInfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetOwnerInfo__bn), "rf"(__SetOwnerInfo_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetOwnerInfoTags(struct Library * DOSBase, ULONG tags, ...)
{
  return SetOwnerInfo((const struct TagItem *) &tags);
}

#define SetOwnerInfoTags(tags...) ___SetOwnerInfoTags(DOS_BASE_NAME, tags)
#endif

#define LockTagList(tags) ({ \
  const struct TagItem * _LockTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __LockTagList__bn __asm("a6") = DOS_BASE_NAME;\
  register BPTR __LockTagList__re __asm("d0"); \
  register const struct TagItem * __LockTagList_tags __asm("a0") = (_LockTagList_tags); \
  __asm volatile ("jsr a6@(-1512:W)" \
  : "=r"(__LockTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__LockTagList__bn), "rf"(__LockTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ BPTR ___LockTags(struct Library * DOSBase, ULONG tags, ...)
{
  return LockTagList((const struct TagItem *) &tags);
}

#define LockTags(tags...) ___LockTags(DOS_BASE_NAME, tags)
#endif

#define GetPID(proc, which) ({ \
  struct Process * _GetPID_proc = (proc); \
  LONG _GetPID_which = (which); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetPID__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __GetPID__re __asm("d0"); \
  register struct Process * __GetPID_proc __asm("a0") = (_GetPID_proc); \
  register LONG __GetPID_which __asm("d0") = (_GetPID_which); \
  __asm volatile ("jsr a6@(-1518:W)" \
  : "=r"(__GetPID__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetPID__bn), "rf"(__GetPID_proc), "rf"(__GetPID_which) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FlushVolume(name) ({ \
  CONST_STRPTR _FlushVolume_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FlushVolume__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FlushVolume__re __asm("d0"); \
  register CONST_STRPTR __FlushVolume_name __asm("a0") = (_FlushVolume_name); \
  __asm volatile ("jsr a6@(-1524:W)" \
  : "=r"(__FlushVolume__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FlushVolume__bn), "rf"(__FlushVolume_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ObtainConsoleData(tags) ({ \
  const struct TagItem * _ObtainConsoleData_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainConsoleData__bn __asm("a6") = DOS_BASE_NAME;\
  register struct ConsoleWindowData * __ObtainConsoleData__re __asm("d0"); \
  register const struct TagItem * __ObtainConsoleData_tags __asm("a0") = (_ObtainConsoleData_tags); \
  __asm volatile ("jsr a6@(-1530:W)" \
  : "=r"(__ObtainConsoleData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainConsoleData__bn), "rf"(__ObtainConsoleData_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct ConsoleWindowData * ___ObtainConsoleDataTags(struct Library * DOSBase, ULONG tags, ...)
{
  return ObtainConsoleData((const struct TagItem *) &tags);
}

#define ObtainConsoleDataTags(tags...) ___ObtainConsoleDataTags(DOS_BASE_NAME, tags)
#endif

#define ReleaseConsoleData(data) ({ \
  struct ConsoleWindowData * _ReleaseConsoleData_data = (data); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseConsoleData__bn __asm("a6") = DOS_BASE_NAME;\
  register struct ConsoleWindowData * __ReleaseConsoleData_data __asm("a0") = (_ReleaseConsoleData_data); \
  __asm volatile ("jsr a6@(-1536:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseConsoleData__bn), "rf"(__ReleaseConsoleData_data) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Serialize(name) ({ \
  CONST_STRPTR _Serialize_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Serialize__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __Serialize__re __asm("d0"); \
  register CONST_STRPTR __Serialize_name __asm("a0") = (_Serialize_name); \
  __asm volatile ("jsr a6@(-1542:W)" \
  : "=r"(__Serialize__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Serialize__bn), "rf"(__Serialize_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define NameFromPort(p, buffer, buflen, add_colon) ({ \
  struct MsgPort * _NameFromPort_p = (p); \
  STRPTR _NameFromPort_buffer = (buffer); \
  LONG _NameFromPort_buflen = (buflen); \
  LONG _NameFromPort_add_colon = (add_colon); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __NameFromPort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __NameFromPort__re __asm("d0"); \
  register struct MsgPort * __NameFromPort_p __asm("a0") = (_NameFromPort_p); \
  register STRPTR __NameFromPort_buffer __asm("a1") = (_NameFromPort_buffer); \
  register LONG __NameFromPort_buflen __asm("d0") = (_NameFromPort_buflen); \
  register LONG __NameFromPort_add_colon __asm("d1") = (_NameFromPort_add_colon); \
  __asm volatile ("jsr a6@(-1548:W)" \
  : "=r"(__NameFromPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__NameFromPort__bn), "rf"(__NameFromPort_p), "rf"(__NameFromPort_buffer), "rf"(__NameFromPort_buflen), "rf"(__NameFromPort_add_colon) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define DevNameFromPort(p, buffer, buflen, add_colon) ({ \
  struct MsgPort * _DevNameFromPort_p = (p); \
  STRPTR _DevNameFromPort_buffer = (buffer); \
  LONG _DevNameFromPort_buflen = (buflen); \
  LONG _DevNameFromPort_add_colon = (add_colon); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DevNameFromPort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __DevNameFromPort__re __asm("d0"); \
  register struct MsgPort * __DevNameFromPort_p __asm("a0") = (_DevNameFromPort_p); \
  register STRPTR __DevNameFromPort_buffer __asm("a1") = (_DevNameFromPort_buffer); \
  register LONG __DevNameFromPort_buflen __asm("d0") = (_DevNameFromPort_buflen); \
  register LONG __DevNameFromPort_add_colon __asm("d1") = (_DevNameFromPort_add_colon); \
  __asm volatile ("jsr a6@(-1554:W)" \
  : "=r"(__DevNameFromPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DevNameFromPort__bn), "rf"(__DevNameFromPort_p), "rf"(__DevNameFromPort_buffer), "rf"(__DevNameFromPort_buflen), "rf"(__DevNameFromPort_add_colon) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SameFH(scb1, scb2) ({ \
  BPTR _SameFH_scb1 = (scb1); \
  BPTR _SameFH_scb2 = (scb2); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SameFH__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SameFH__re __asm("d0"); \
  register BPTR __SameFH_scb1 __asm("d1") = (_SameFH_scb1); \
  register BPTR __SameFH_scb2 __asm("d2") = (_SameFH_scb2); \
  __asm volatile ("jsr a6@(-1560:W)" \
  : "=r"(__SameFH__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SameFH__bn), "rf"(__SameFH_scb1), "rf"(__SameFH_scb2) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define IsFileSystemPort(port) ({ \
  struct MsgPort * _IsFileSystemPort_port = (port); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __IsFileSystemPort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __IsFileSystemPort__re __asm("d0"); \
  register struct MsgPort * __IsFileSystemPort_port __asm("a0") = (_IsFileSystemPort_port); \
  __asm volatile ("jsr a6@(-1566:W)" \
  : "=r"(__IsFileSystemPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__IsFileSystemPort__bn), "rf"(__IsFileSystemPort_port) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define InhibitPort(port, state) ({ \
  struct MsgPort * _InhibitPort_port = (port); \
  int32 _InhibitPort_state = (state); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __InhibitPort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __InhibitPort__re __asm("d0"); \
  register struct MsgPort * __InhibitPort_port __asm("a0") = (_InhibitPort_port); \
  register int32 __InhibitPort_state __asm("d0") = (_InhibitPort_state); \
  __asm volatile ("jsr a6@(-1572:W)" \
  : "=r"(__InhibitPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__InhibitPort__bn), "rf"(__InhibitPort_port), "rf"(__InhibitPort_state) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FormatPort(port, volname, dostype, flags) ({ \
  struct MsgPort * _FormatPort_port = (port); \
  STRPTR _FormatPort_volname = (volname); \
  ULONG _FormatPort_dostype = (dostype); \
  ULONG _FormatPort_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FormatPort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FormatPort__re __asm("d0"); \
  register struct MsgPort * __FormatPort_port __asm("a0") = (_FormatPort_port); \
  register STRPTR __FormatPort_volname __asm("a1") = (_FormatPort_volname); \
  register ULONG __FormatPort_dostype __asm("d0") = (_FormatPort_dostype); \
  register ULONG __FormatPort_flags __asm("d1") = (_FormatPort_flags); \
  __asm volatile ("jsr a6@(-1578:W)" \
  : "=r"(__FormatPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FormatPort__bn), "rf"(__FormatPort_port), "rf"(__FormatPort_volname), "rf"(__FormatPort_dostype), "rf"(__FormatPort_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SerializePort(port) ({ \
  struct MsgPort * _SerializePort_port = (port); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SerializePort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __SerializePort__re __asm("d0"); \
  register struct MsgPort * __SerializePort_port __asm("a0") = (_SerializePort_port); \
  __asm volatile ("jsr a6@(-1584:W)" \
  : "=r"(__SerializePort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SerializePort__bn), "rf"(__SerializePort_port) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FlushVolumePort(port) ({ \
  struct MsgPort * _FlushVolumePort_port = (port); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FlushVolumePort__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FlushVolumePort__re __asm("d0"); \
  register struct MsgPort * __FlushVolumePort_port __asm("a0") = (_FlushVolumePort_port); \
  __asm volatile ("jsr a6@(-1590:W)" \
  : "=r"(__FlushVolumePort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FlushVolumePort__bn), "rf"(__FlushVolumePort_port) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define FileHandleScan(hook, userdata, reserved) ({ \
  const struct Hook * _FileHandleScan_hook = (hook); \
  CONST APTR _FileHandleScan_userdata = (userdata); \
  ULONG _FileHandleScan_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FileHandleScan__bn __asm("a6") = DOS_BASE_NAME;\
  register LONG __FileHandleScan__re __asm("d0"); \
  register const struct Hook * __FileHandleScan_hook __asm("d1") = (_FileHandleScan_hook); \
  register CONST APTR __FileHandleScan_userdata __asm("d2") = (_FileHandleScan_userdata); \
  register ULONG __FileHandleScan_reserved __asm("d3") = (_FileHandleScan_reserved); \
  __asm volatile ("jsr a6@(-1596:W)" \
  : "=r"(__FileHandleScan__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FileHandleScan__bn), "rf"(__FileHandleScan_hook), "rf"(__FileHandleScan_userdata), "rf"(__FileHandleScan_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetFileSystemVectorPort(port, min_version) ({ \
  struct MsgPort * _GetFileSystemVectorPort_port = (port); \
  uint32 _GetFileSystemVectorPort_min_version = (min_version); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetFileSystemVectorPort__bn __asm("a6") = DOS_BASE_NAME;\
  register struct FileSystemVectorPort * __GetFileSystemVectorPort__re __asm("d0"); \
  register struct MsgPort * __GetFileSystemVectorPort_port __asm("a0") = (_GetFileSystemVectorPort_port); \
  register uint32 __GetFileSystemVectorPort_min_version __asm("d0") = (_GetFileSystemVectorPort_min_version); \
  __asm volatile ("jsr a6@(-1602:W)" \
  : "=r"(__GetFileSystemVectorPort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetFileSystemVectorPort__bn), "rf"(__GetFileSystemVectorPort_port), "rf"(__GetFileSystemVectorPort_min_version) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ResolvePath(port, path, inlock, outbuf, outbufsize, outdir, sl) ({ \
  struct MsgPort * _ResolvePath_port = (port); \
  CONST_STRPTR _ResolvePath_path = (path); \
  BPTR _ResolvePath_inlock = (inlock); \
  STRPTR _ResolvePath_outbuf = (outbuf); \
  uint32 _ResolvePath_outbufsize = (outbufsize); \
  BPTR * _ResolvePath_outdir = (outdir); \
  uint32 * _ResolvePath_sl = (sl); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ResolvePath__bn __asm("a6") = DOS_BASE_NAME;\
  register int32 __ResolvePath__re __asm("d0"); \
  register struct MsgPort * __ResolvePath_port __asm("a0") = (_ResolvePath_port); \
  register CONST_STRPTR __ResolvePath_path __asm("a1") = (_ResolvePath_path); \
  register BPTR __ResolvePath_inlock __asm("d1") = (_ResolvePath_inlock); \
  register STRPTR __ResolvePath_outbuf __asm("a2") = (_ResolvePath_outbuf); \
  register uint32 __ResolvePath_outbufsize __asm("d2") = (_ResolvePath_outbufsize); \
  register BPTR * __ResolvePath_outdir __asm("a3") = (_ResolvePath_outdir); \
  register uint32 * __ResolvePath_sl __asm("d3") = (_ResolvePath_sl); \
  __asm volatile ("jsr a6@(-1608:W)" \
  : "=r"(__ResolvePath__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ResolvePath__bn), "rf"(__ResolvePath_port), "rf"(__ResolvePath_path), "rf"(__ResolvePath_inlock), "rf"(__ResolvePath_outbuf), "rf"(__ResolvePath_outbufsize), "rf"(__ResolvePath_outdir), "rf"(__ResolvePath_sl) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define WriteProtectVolumePort(port, on_off, passkey, reserved) ({ \
  struct MsgPort * _WriteProtectVolumePort_port = (port); \
  int32 _WriteProtectVolumePort_on_off = (on_off); \
  uint32 _WriteProtectVolumePort_passkey = (passkey); \
  int32 _WriteProtectVolumePort_reserved = (reserved); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WriteProtectVolumePort__bn __asm("a6") = DOS_BASE_NAME;\
  register int32 __WriteProtectVolumePort__re __asm("d0"); \
  register struct MsgPort * __WriteProtectVolumePort_port __asm("d1") = (_WriteProtectVolumePort_port); \
  register int32 __WriteProtectVolumePort_on_off __asm("d2") = (_WriteProtectVolumePort_on_off); \
  register uint32 __WriteProtectVolumePort_passkey __asm("d3") = (_WriteProtectVolumePort_passkey); \
  register int32 __WriteProtectVolumePort_reserved __asm("d4") = (_WriteProtectVolumePort_reserved); \
  __asm volatile ("jsr a6@(-1614:W)" \
  : "=r"(__WriteProtectVolumePort__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WriteProtectVolumePort__bn), "rf"(__WriteProtectVolumePort_port), "rf"(__WriteProtectVolumePort_on_off), "rf"(__WriteProtectVolumePort_passkey), "rf"(__WriteProtectVolumePort_reserved) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AsyncIO(tags) ({ \
  const struct TagItem * _AsyncIO_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AsyncIO__bn __asm("a6") = DOS_BASE_NAME;\
  register int32 __AsyncIO__re __asm("d0"); \
  register const struct TagItem * __AsyncIO_tags __asm("a0") = (_AsyncIO_tags); \
  __asm volatile ("jsr a6@(-1620:W)" \
  : "=r"(__AsyncIO__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AsyncIO__bn), "rf"(__AsyncIO_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ int32 ___AsyncIOTags(struct Library * DOSBase, uint32 tags, ...)
{
  return AsyncIO((const struct TagItem *) &tags);
}

#define AsyncIOTags(tags...) ___AsyncIOTags(DOS_BASE_NAME, tags)
#endif

#define WaitForChildExit(pid) ({ \
  uint32 _WaitForChildExit_pid = (pid); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WaitForChildExit__bn __asm("a6") = DOS_BASE_NAME;\
  register int32 __WaitForChildExit__re __asm("d0"); \
  register uint32 __WaitForChildExit_pid __asm("d1") = (_WaitForChildExit_pid); \
  __asm volatile ("jsr a6@(-1626:W)" \
  : "=r"(__WaitForChildExit__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WaitForChildExit__bn), "rf"(__WaitForChildExit_pid) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CheckForChildExit(pid) ({ \
  uint32 _CheckForChildExit_pid = (pid); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CheckForChildExit__bn __asm("a6") = DOS_BASE_NAME;\
  register int32 __CheckForChildExit__re __asm("d0"); \
  register uint32 __CheckForChildExit_pid __asm("d1") = (_CheckForChildExit_pid); \
  __asm volatile ("jsr a6@(-1632:W)" \
  : "=r"(__CheckForChildExit__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CheckForChildExit__bn), "rf"(__CheckForChildExit_pid) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#endif /*  _INLINE_DOS_H  */
