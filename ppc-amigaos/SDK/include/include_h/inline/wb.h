#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_WB_H
#define _INLINE_WB_H

#ifndef CLIB_WB_PROTOS_H
#define CLIB_WB_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef WB_BASE_NAME
#define WB_BASE_NAME WorkbenchBase
#endif

#define UpdateWorkbench(name, lock, action) ({ \
  CONST_STRPTR _UpdateWorkbench_name = (name); \
  ULONG _UpdateWorkbench_lock = (lock); \
  LONG _UpdateWorkbench_action = (action); \
  { \
  register struct Library * const __UpdateWorkbench__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register CONST_STRPTR __UpdateWorkbench_name __asm("a0") = (_UpdateWorkbench_name); \
  register ULONG __UpdateWorkbench_lock __asm("a1") = (_UpdateWorkbench_lock); \
  register LONG __UpdateWorkbench_action __asm("d0") = (_UpdateWorkbench_action); \
  __asm volatile ("jsr a6@(-30:W)" \
  : \
  : "r"(__UpdateWorkbench__bn), "r"(__UpdateWorkbench_name), "r"(__UpdateWorkbench_lock), "r"(__UpdateWorkbench_action) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddAppWindowA(id, userdata, window, msgport, taglist) ({ \
  ULONG _AddAppWindowA_id = (id); \
  ULONG _AddAppWindowA_userdata = (userdata); \
  struct Window * _AddAppWindowA_window = (window); \
  struct MsgPort * _AddAppWindowA_msgport = (msgport); \
  struct TagItem * _AddAppWindowA_taglist = (taglist); \
  struct AppWindow * _AddAppWindowA__re = \
  ({ \
  register struct Library * const __AddAppWindowA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register struct AppWindow * __AddAppWindowA__re __asm("d0"); \
  register ULONG __AddAppWindowA_id __asm("d0") = (_AddAppWindowA_id); \
  register ULONG __AddAppWindowA_userdata __asm("d1") = (_AddAppWindowA_userdata); \
  register struct Window * __AddAppWindowA_window __asm("a0") = (_AddAppWindowA_window); \
  register struct MsgPort * __AddAppWindowA_msgport __asm("a1") = (_AddAppWindowA_msgport); \
  register struct TagItem * __AddAppWindowA_taglist __asm("a2") = (_AddAppWindowA_taglist); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__AddAppWindowA__re) \
  : "r"(__AddAppWindowA__bn), "r"(__AddAppWindowA_id), "r"(__AddAppWindowA_userdata), "r"(__AddAppWindowA_window), "r"(__AddAppWindowA_msgport), "r"(__AddAppWindowA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddAppWindowA__re; \
  }); \
  _AddAppWindowA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct AppWindow * ___AddAppWindow(struct Library * WorkbenchBase, ULONG id, ULONG userdata, struct Window * window, struct MsgPort * msgport, Tag taglist, ...)
{
  return AddAppWindowA(id, userdata, window, msgport, (struct TagItem *) &taglist);
}

#define AddAppWindow(id, userdata, window, msgport...) ___AddAppWindow(WB_BASE_NAME, id, userdata, window, msgport)
#endif

#define RemoveAppWindow(appWindow) ({ \
  struct AppWindow * _RemoveAppWindow_appWindow = (appWindow); \
  BOOL _RemoveAppWindow__re = \
  ({ \
  register struct Library * const __RemoveAppWindow__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __RemoveAppWindow__re __asm("d0"); \
  register struct AppWindow * __RemoveAppWindow_appWindow __asm("a0") = (_RemoveAppWindow_appWindow); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__RemoveAppWindow__re) \
  : "r"(__RemoveAppWindow__bn), "r"(__RemoveAppWindow_appWindow) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveAppWindow__re; \
  }); \
  _RemoveAppWindow__re; \
})

#define AddAppIconA(id, userdata, text, msgport, lock, diskobj, taglist) ({ \
  ULONG _AddAppIconA_id = (id); \
  ULONG _AddAppIconA_userdata = (userdata); \
  CONST_STRPTR _AddAppIconA_text = (text); \
  struct MsgPort * _AddAppIconA_msgport = (msgport); \
  BPTR _AddAppIconA_lock = (lock); \
  struct DiskObject * _AddAppIconA_diskobj = (diskobj); \
  struct TagItem * _AddAppIconA_taglist = (taglist); \
  struct AppIcon * _AddAppIconA__re = \
  ({ \
  register struct Library * const __AddAppIconA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register struct AppIcon * __AddAppIconA__re __asm("d0"); \
  register ULONG __AddAppIconA_id __asm("d0") = (_AddAppIconA_id); \
  register ULONG __AddAppIconA_userdata __asm("d1") = (_AddAppIconA_userdata); \
  register CONST_STRPTR __AddAppIconA_text __asm("a0") = (_AddAppIconA_text); \
  register struct MsgPort * __AddAppIconA_msgport __asm("a1") = (_AddAppIconA_msgport); \
  register BPTR __AddAppIconA_lock __asm("a2") = (_AddAppIconA_lock); \
  register struct DiskObject * __AddAppIconA_diskobj __asm("a3") = (_AddAppIconA_diskobj); \
  register struct TagItem * __AddAppIconA_taglist __asm("d2") = (_AddAppIconA_taglist); \
  __asm volatile ("exg a4,d2\n\tjsr a6@(-60:W)\n\texg a4,d2" \
  : "=r"(__AddAppIconA__re) \
  : "r"(__AddAppIconA__bn), "r"(__AddAppIconA_id), "r"(__AddAppIconA_userdata), "r"(__AddAppIconA_text), "r"(__AddAppIconA_msgport), "r"(__AddAppIconA_lock), "r"(__AddAppIconA_diskobj), "r"(__AddAppIconA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddAppIconA__re; \
  }); \
  _AddAppIconA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct AppIcon * ___AddAppIcon(struct Library * WorkbenchBase, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, BPTR lock, struct DiskObject * diskobj, Tag taglist, ...)
{
  return AddAppIconA(id, userdata, text, msgport, lock, diskobj, (struct TagItem *) &taglist);
}

#define AddAppIcon(id, userdata, text, msgport, lock, diskobj...) ___AddAppIcon(WB_BASE_NAME, id, userdata, text, msgport, lock, diskobj)
#endif

#define RemoveAppIcon(appIcon) ({ \
  struct AppIcon * _RemoveAppIcon_appIcon = (appIcon); \
  BOOL _RemoveAppIcon__re = \
  ({ \
  register struct Library * const __RemoveAppIcon__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __RemoveAppIcon__re __asm("d0"); \
  register struct AppIcon * __RemoveAppIcon_appIcon __asm("a0") = (_RemoveAppIcon_appIcon); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__RemoveAppIcon__re) \
  : "r"(__RemoveAppIcon__bn), "r"(__RemoveAppIcon_appIcon) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveAppIcon__re; \
  }); \
  _RemoveAppIcon__re; \
})

#define AddAppMenuItemA(id, userdata, text, msgport, taglist) ({ \
  ULONG _AddAppMenuItemA_id = (id); \
  ULONG _AddAppMenuItemA_userdata = (userdata); \
  CONST_STRPTR _AddAppMenuItemA_text = (text); \
  struct MsgPort * _AddAppMenuItemA_msgport = (msgport); \
  struct TagItem * _AddAppMenuItemA_taglist = (taglist); \
  struct AppMenuItem * _AddAppMenuItemA__re = \
  ({ \
  register struct Library * const __AddAppMenuItemA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register struct AppMenuItem * __AddAppMenuItemA__re __asm("d0"); \
  register ULONG __AddAppMenuItemA_id __asm("d0") = (_AddAppMenuItemA_id); \
  register ULONG __AddAppMenuItemA_userdata __asm("d1") = (_AddAppMenuItemA_userdata); \
  register CONST_STRPTR __AddAppMenuItemA_text __asm("a0") = (_AddAppMenuItemA_text); \
  register struct MsgPort * __AddAppMenuItemA_msgport __asm("a1") = (_AddAppMenuItemA_msgport); \
  register struct TagItem * __AddAppMenuItemA_taglist __asm("a2") = (_AddAppMenuItemA_taglist); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__AddAppMenuItemA__re) \
  : "r"(__AddAppMenuItemA__bn), "r"(__AddAppMenuItemA_id), "r"(__AddAppMenuItemA_userdata), "r"(__AddAppMenuItemA_text), "r"(__AddAppMenuItemA_msgport), "r"(__AddAppMenuItemA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddAppMenuItemA__re; \
  }); \
  _AddAppMenuItemA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct AppMenuItem * ___AddAppMenuItem(struct Library * WorkbenchBase, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, Tag taglist, ...)
{
  return AddAppMenuItemA(id, userdata, text, msgport, (struct TagItem *) &taglist);
}

#define AddAppMenuItem(id, userdata, text, msgport...) ___AddAppMenuItem(WB_BASE_NAME, id, userdata, text, msgport)
#endif

#define RemoveAppMenuItem(appMenuItem) ({ \
  struct AppMenuItem * _RemoveAppMenuItem_appMenuItem = (appMenuItem); \
  BOOL _RemoveAppMenuItem__re = \
  ({ \
  register struct Library * const __RemoveAppMenuItem__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __RemoveAppMenuItem__re __asm("d0"); \
  register struct AppMenuItem * __RemoveAppMenuItem_appMenuItem __asm("a0") = (_RemoveAppMenuItem_appMenuItem); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__RemoveAppMenuItem__re) \
  : "r"(__RemoveAppMenuItem__bn), "r"(__RemoveAppMenuItem_appMenuItem) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveAppMenuItem__re; \
  }); \
  _RemoveAppMenuItem__re; \
})

#define WBInfo(lock, name, screen) ({ \
  BPTR _WBInfo_lock = (lock); \
  STRPTR _WBInfo_name = (name); \
  struct Screen * _WBInfo_screen = (screen); \
  ULONG _WBInfo__re = \
  ({ \
  register struct Library * const __WBInfo__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register ULONG __WBInfo__re __asm("d0"); \
  register BPTR __WBInfo_lock __asm("a0") = (_WBInfo_lock); \
  register STRPTR __WBInfo_name __asm("a1") = (_WBInfo_name); \
  register struct Screen * __WBInfo_screen __asm("a2") = (_WBInfo_screen); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__WBInfo__re) \
  : "r"(__WBInfo__bn), "r"(__WBInfo_lock), "r"(__WBInfo_name), "r"(__WBInfo_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WBInfo__re; \
  }); \
  _WBInfo__re; \
})

#define OpenWorkbenchObjectA(name, tags) ({ \
  STRPTR _OpenWorkbenchObjectA_name = (name); \
  struct TagItem * _OpenWorkbenchObjectA_tags = (tags); \
  BOOL _OpenWorkbenchObjectA__re = \
  ({ \
  register struct Library * const __OpenWorkbenchObjectA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __OpenWorkbenchObjectA__re __asm("d0"); \
  register STRPTR __OpenWorkbenchObjectA_name __asm("a0") = (_OpenWorkbenchObjectA_name); \
  register struct TagItem * __OpenWorkbenchObjectA_tags __asm("a1") = (_OpenWorkbenchObjectA_tags); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__OpenWorkbenchObjectA__re) \
  : "r"(__OpenWorkbenchObjectA__bn), "r"(__OpenWorkbenchObjectA_name), "r"(__OpenWorkbenchObjectA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenWorkbenchObjectA__re; \
  }); \
  _OpenWorkbenchObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___OpenWorkbenchObject(struct Library * WorkbenchBase, STRPTR name, Tag tags, ...)
{
  return OpenWorkbenchObjectA(name, (struct TagItem *) &tags);
}

#define OpenWorkbenchObject(name...) ___OpenWorkbenchObject(WB_BASE_NAME, name)
#endif

#define CloseWorkbenchObjectA(name, tags) ({ \
  STRPTR _CloseWorkbenchObjectA_name = (name); \
  struct TagItem * _CloseWorkbenchObjectA_tags = (tags); \
  BOOL _CloseWorkbenchObjectA__re = \
  ({ \
  register struct Library * const __CloseWorkbenchObjectA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __CloseWorkbenchObjectA__re __asm("d0"); \
  register STRPTR __CloseWorkbenchObjectA_name __asm("a0") = (_CloseWorkbenchObjectA_name); \
  register struct TagItem * __CloseWorkbenchObjectA_tags __asm("a1") = (_CloseWorkbenchObjectA_tags); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__CloseWorkbenchObjectA__re) \
  : "r"(__CloseWorkbenchObjectA__bn), "r"(__CloseWorkbenchObjectA_name), "r"(__CloseWorkbenchObjectA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CloseWorkbenchObjectA__re; \
  }); \
  _CloseWorkbenchObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___CloseWorkbenchObject(struct Library * WorkbenchBase, STRPTR name, Tag tags, ...)
{
  return CloseWorkbenchObjectA(name, (struct TagItem *) &tags);
}

#define CloseWorkbenchObject(name...) ___CloseWorkbenchObject(WB_BASE_NAME, name)
#endif

#define WorkbenchControlA(name, tags) ({ \
  STRPTR _WorkbenchControlA_name = (name); \
  struct TagItem * _WorkbenchControlA_tags = (tags); \
  BOOL _WorkbenchControlA__re = \
  ({ \
  register struct Library * const __WorkbenchControlA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __WorkbenchControlA__re __asm("d0"); \
  register STRPTR __WorkbenchControlA_name __asm("a0") = (_WorkbenchControlA_name); \
  register struct TagItem * __WorkbenchControlA_tags __asm("a1") = (_WorkbenchControlA_tags); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__WorkbenchControlA__re) \
  : "r"(__WorkbenchControlA__bn), "r"(__WorkbenchControlA_name), "r"(__WorkbenchControlA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WorkbenchControlA__re; \
  }); \
  _WorkbenchControlA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___WorkbenchControl(struct Library * WorkbenchBase, STRPTR name, Tag tags, ...)
{
  return WorkbenchControlA(name, (struct TagItem *) &tags);
}

#define WorkbenchControl(name...) ___WorkbenchControl(WB_BASE_NAME, name)
#endif

#define AddAppWindowDropZoneA(aw, id, userdata, tags) ({ \
  struct AppWindow * _AddAppWindowDropZoneA_aw = (aw); \
  ULONG _AddAppWindowDropZoneA_id = (id); \
  ULONG _AddAppWindowDropZoneA_userdata = (userdata); \
  struct TagItem * _AddAppWindowDropZoneA_tags = (tags); \
  struct AppWindowDropZone * _AddAppWindowDropZoneA__re = \
  ({ \
  register struct Library * const __AddAppWindowDropZoneA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register struct AppWindowDropZone * __AddAppWindowDropZoneA__re __asm("d0"); \
  register struct AppWindow * __AddAppWindowDropZoneA_aw __asm("a0") = (_AddAppWindowDropZoneA_aw); \
  register ULONG __AddAppWindowDropZoneA_id __asm("d0") = (_AddAppWindowDropZoneA_id); \
  register ULONG __AddAppWindowDropZoneA_userdata __asm("d1") = (_AddAppWindowDropZoneA_userdata); \
  register struct TagItem * __AddAppWindowDropZoneA_tags __asm("a1") = (_AddAppWindowDropZoneA_tags); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__AddAppWindowDropZoneA__re) \
  : "r"(__AddAppWindowDropZoneA__bn), "r"(__AddAppWindowDropZoneA_aw), "r"(__AddAppWindowDropZoneA_id), "r"(__AddAppWindowDropZoneA_userdata), "r"(__AddAppWindowDropZoneA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddAppWindowDropZoneA__re; \
  }); \
  _AddAppWindowDropZoneA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct AppWindowDropZone * ___AddAppWindowDropZone(struct Library * WorkbenchBase, struct AppWindow * aw, ULONG id, ULONG userdata, Tag tags, ...)
{
  return AddAppWindowDropZoneA(aw, id, userdata, (struct TagItem *) &tags);
}

#define AddAppWindowDropZone(aw, id, userdata...) ___AddAppWindowDropZone(WB_BASE_NAME, aw, id, userdata)
#endif

#define RemoveAppWindowDropZone(aw, dropZone) ({ \
  struct AppWindow * _RemoveAppWindowDropZone_aw = (aw); \
  struct AppWindowDropZone * _RemoveAppWindowDropZone_dropZone = (dropZone); \
  BOOL _RemoveAppWindowDropZone__re = \
  ({ \
  register struct Library * const __RemoveAppWindowDropZone__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __RemoveAppWindowDropZone__re __asm("d0"); \
  register struct AppWindow * __RemoveAppWindowDropZone_aw __asm("a0") = (_RemoveAppWindowDropZone_aw); \
  register struct AppWindowDropZone * __RemoveAppWindowDropZone_dropZone __asm("a1") = (_RemoveAppWindowDropZone_dropZone); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__RemoveAppWindowDropZone__re) \
  : "r"(__RemoveAppWindowDropZone__bn), "r"(__RemoveAppWindowDropZone_aw), "r"(__RemoveAppWindowDropZone_dropZone) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveAppWindowDropZone__re; \
  }); \
  _RemoveAppWindowDropZone__re; \
})

#define ChangeWorkbenchSelectionA(name, hook, tags) ({ \
  STRPTR _ChangeWorkbenchSelectionA_name = (name); \
  struct Hook * _ChangeWorkbenchSelectionA_hook = (hook); \
  struct TagItem * _ChangeWorkbenchSelectionA_tags = (tags); \
  BOOL _ChangeWorkbenchSelectionA__re = \
  ({ \
  register struct Library * const __ChangeWorkbenchSelectionA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __ChangeWorkbenchSelectionA__re __asm("d0"); \
  register STRPTR __ChangeWorkbenchSelectionA_name __asm("a0") = (_ChangeWorkbenchSelectionA_name); \
  register struct Hook * __ChangeWorkbenchSelectionA_hook __asm("a1") = (_ChangeWorkbenchSelectionA_hook); \
  register struct TagItem * __ChangeWorkbenchSelectionA_tags __asm("a2") = (_ChangeWorkbenchSelectionA_tags); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__ChangeWorkbenchSelectionA__re) \
  : "r"(__ChangeWorkbenchSelectionA__bn), "r"(__ChangeWorkbenchSelectionA_name), "r"(__ChangeWorkbenchSelectionA_hook), "r"(__ChangeWorkbenchSelectionA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ChangeWorkbenchSelectionA__re; \
  }); \
  _ChangeWorkbenchSelectionA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___ChangeWorkbenchSelection(struct Library * WorkbenchBase, STRPTR name, struct Hook * hook, Tag tags, ...)
{
  return ChangeWorkbenchSelectionA(name, hook, (struct TagItem *) &tags);
}

#define ChangeWorkbenchSelection(name, hook...) ___ChangeWorkbenchSelection(WB_BASE_NAME, name, hook)
#endif

#define MakeWorkbenchObjectVisibleA(name, tags) ({ \
  STRPTR _MakeWorkbenchObjectVisibleA_name = (name); \
  struct TagItem * _MakeWorkbenchObjectVisibleA_tags = (tags); \
  BOOL _MakeWorkbenchObjectVisibleA__re = \
  ({ \
  register struct Library * const __MakeWorkbenchObjectVisibleA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register BOOL __MakeWorkbenchObjectVisibleA__re __asm("d0"); \
  register STRPTR __MakeWorkbenchObjectVisibleA_name __asm("a0") = (_MakeWorkbenchObjectVisibleA_name); \
  register struct TagItem * __MakeWorkbenchObjectVisibleA_tags __asm("a1") = (_MakeWorkbenchObjectVisibleA_tags); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__MakeWorkbenchObjectVisibleA__re) \
  : "r"(__MakeWorkbenchObjectVisibleA__bn), "r"(__MakeWorkbenchObjectVisibleA_name), "r"(__MakeWorkbenchObjectVisibleA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MakeWorkbenchObjectVisibleA__re; \
  }); \
  _MakeWorkbenchObjectVisibleA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___MakeWorkbenchObjectVisible(struct Library * WorkbenchBase, STRPTR name, Tag tags, ...)
{
  return MakeWorkbenchObjectVisibleA(name, (struct TagItem *) &tags);
}

#define MakeWorkbenchObjectVisible(name...) ___MakeWorkbenchObjectVisible(WB_BASE_NAME, name)
#endif

#define WhichWorkbenchObjectA(window, x, y, tags) ({ \
  struct Window * _WhichWorkbenchObjectA_window = (window); \
  LONG _WhichWorkbenchObjectA_x = (x); \
  LONG _WhichWorkbenchObjectA_y = (y); \
  struct TagItem * _WhichWorkbenchObjectA_tags = (tags); \
  ULONG _WhichWorkbenchObjectA__re = \
  ({ \
  register struct Library * const __WhichWorkbenchObjectA__bn __asm("a6") = (struct Library *) (WB_BASE_NAME);\
  register ULONG __WhichWorkbenchObjectA__re __asm("d0"); \
  register struct Window * __WhichWorkbenchObjectA_window __asm("a0") = (_WhichWorkbenchObjectA_window); \
  register LONG __WhichWorkbenchObjectA_x __asm("d0") = (_WhichWorkbenchObjectA_x); \
  register LONG __WhichWorkbenchObjectA_y __asm("d1") = (_WhichWorkbenchObjectA_y); \
  register struct TagItem * __WhichWorkbenchObjectA_tags __asm("a1") = (_WhichWorkbenchObjectA_tags); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__WhichWorkbenchObjectA__re) \
  : "r"(__WhichWorkbenchObjectA__bn), "r"(__WhichWorkbenchObjectA_window), "r"(__WhichWorkbenchObjectA_x), "r"(__WhichWorkbenchObjectA_y), "r"(__WhichWorkbenchObjectA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WhichWorkbenchObjectA__re; \
  }); \
  _WhichWorkbenchObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___WhichWorkbenchObject(struct Library * WorkbenchBase, struct Window * window, LONG x, LONG y, Tag tags, ...)
{
  return WhichWorkbenchObjectA(window, x, y, (struct TagItem *) &tags);
}

#define WhichWorkbenchObject(window, x, y...) ___WhichWorkbenchObject(WB_BASE_NAME, window, x, y)
#endif

#endif /*  _INLINE_WB_H  */
