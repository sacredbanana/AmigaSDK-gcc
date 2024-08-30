/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_WB_H
#define _INLINE_WB_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __UpdateWorkbench(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") BPTR lock , __reg("d0") LONG action ) = "\tjsr\t-30(a6)";
#define UpdateWorkbench(name, lock, action) __UpdateWorkbench(WorkbenchBase, (name), (lock), (action))

struct AppWindow * __AddAppWindowA(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") struct Window * window , __reg("a1") struct MsgPort * msgport , __reg("a2") CONST struct TagItem * taglist ) = "\tjsr\t-48(a6)";
#define AddAppWindowA(id, userdata, window, msgport, taglist) __AddAppWindowA(WorkbenchBase, (id), (userdata), (window), (msgport), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct AppWindow * __AddAppWindow(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") struct Window * window , __reg("a1") struct MsgPort * msgport , Tag _tag1 , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a2";
#define AddAppWindow(id, userdata, window, msgport, ...) __AddAppWindow(WorkbenchBase, (id), (userdata), (window), (msgport), __VA_ARGS__)
#endif

BOOL __RemoveAppWindow(__reg("a6") struct Library * , __reg("a0") struct AppWindow * appWindow ) = "\tjsr\t-54(a6)";
#define RemoveAppWindow(appWindow) __RemoveAppWindow(WorkbenchBase, (appWindow))

struct AppIcon * __AddAppIconA(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") CONST_STRPTR text , __reg("a1") struct MsgPort * msgport , __reg("a2") BPTR lock , __reg("a3") struct DiskObject * diskobj , __reg("a4") CONST struct TagItem * taglist ) = "\tjsr\t-60(a6)";
#define AddAppIconA(id, userdata, text, msgport, lock, diskobj, taglist) __AddAppIconA(WorkbenchBase, (id), (userdata), (text), (msgport), (lock), (diskobj), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct AppIcon * __AddAppIcon(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") CONST_STRPTR text , __reg("a1") struct MsgPort * msgport , __reg("a2") BPTR lock , __reg("a3") struct DiskObject * diskobj , Tag _tag1 , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-60(a6)\n\tmovea.l\t(a7)+,a4";
#define AddAppIcon(id, userdata, text, msgport, lock, diskobj, ...) __AddAppIcon(WorkbenchBase, (id), (userdata), (text), (msgport), (lock), (diskobj), __VA_ARGS__)
#endif

BOOL __RemoveAppIcon(__reg("a6") struct Library * , __reg("a0") struct AppIcon * appIcon ) = "\tjsr\t-66(a6)";
#define RemoveAppIcon(appIcon) __RemoveAppIcon(WorkbenchBase, (appIcon))

struct AppMenuItem * __AddAppMenuItemA(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") CONST_STRPTR text , __reg("a1") struct MsgPort * msgport , __reg("a2") CONST struct TagItem * taglist ) = "\tjsr\t-72(a6)";
#define AddAppMenuItemA(id, userdata, text, msgport, taglist) __AddAppMenuItemA(WorkbenchBase, (id), (userdata), (text), (msgport), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct AppMenuItem * __AddAppMenuItem(__reg("a6") struct Library * , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a0") CONST_STRPTR text , __reg("a1") struct MsgPort * msgport , Tag _tag1 , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-72(a6)\n\tmovea.l\t(a7)+,a2";
#define AddAppMenuItem(id, userdata, text, msgport, ...) __AddAppMenuItem(WorkbenchBase, (id), (userdata), (text), (msgport), __VA_ARGS__)
#endif

BOOL __RemoveAppMenuItem(__reg("a6") struct Library * , __reg("a0") struct AppMenuItem * appMenuItem ) = "\tjsr\t-78(a6)";
#define RemoveAppMenuItem(appMenuItem) __RemoveAppMenuItem(WorkbenchBase, (appMenuItem))

ULONG __WBInfo(__reg("a6") struct Library * , __reg("a0") BPTR lock , __reg("a1") CONST_STRPTR name , __reg("a2") struct Screen * screen ) = "\tjsr\t-90(a6)";
#define WBInfo(lock, name, screen) __WBInfo(WorkbenchBase, (lock), (name), (screen))

BOOL __OpenWorkbenchObjectA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-96(a6)";
#define OpenWorkbenchObjectA(name, tags) __OpenWorkbenchObjectA(WorkbenchBase, (name), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __OpenWorkbenchObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-96(a6)\n\tmovea.l\t(a7)+,a1";
#define OpenWorkbenchObject(name, ...) __OpenWorkbenchObject(WorkbenchBase, (name), __VA_ARGS__)
#endif

BOOL __CloseWorkbenchObjectA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-102(a6)";
#define CloseWorkbenchObjectA(name, tags) __CloseWorkbenchObjectA(WorkbenchBase, (name), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __CloseWorkbenchObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-102(a6)\n\tmovea.l\t(a7)+,a1";
#define CloseWorkbenchObject(name, ...) __CloseWorkbenchObject(WorkbenchBase, (name), __VA_ARGS__)
#endif

BOOL __WorkbenchControlA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-108(a6)";
#define WorkbenchControlA(name, tags) __WorkbenchControlA(WorkbenchBase, (name), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __WorkbenchControl(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-108(a6)\n\tmovea.l\t(a7)+,a1";
#define WorkbenchControl(name, ...) __WorkbenchControl(WorkbenchBase, (name), __VA_ARGS__)
#endif

struct AppWindowDropZone * __AddAppWindowDropZoneA(__reg("a6") struct Library * , __reg("a0") struct AppWindow * aw , __reg("d0") ULONG id , __reg("d1") ULONG userdata , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-114(a6)";
#define AddAppWindowDropZoneA(aw, id, userdata, tags) __AddAppWindowDropZoneA(WorkbenchBase, (aw), (id), (userdata), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct AppWindowDropZone * __AddAppWindowDropZone(__reg("a6") struct Library * , __reg("a0") struct AppWindow * aw , __reg("d0") ULONG id , __reg("d1") ULONG userdata , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-114(a6)\n\tmovea.l\t(a7)+,a1";
#define AddAppWindowDropZone(aw, id, userdata, ...) __AddAppWindowDropZone(WorkbenchBase, (aw), (id), (userdata), __VA_ARGS__)
#endif

BOOL __RemoveAppWindowDropZone(__reg("a6") struct Library * , __reg("a0") struct AppWindow * aw , __reg("a1") struct AppWindowDropZone * dropZone ) = "\tjsr\t-120(a6)";
#define RemoveAppWindowDropZone(aw, dropZone) __RemoveAppWindowDropZone(WorkbenchBase, (aw), (dropZone))

BOOL __ChangeWorkbenchSelectionA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") struct Hook * hook , __reg("a2") CONST struct TagItem * tags ) = "\tjsr\t-126(a6)";
#define ChangeWorkbenchSelectionA(name, hook, tags) __ChangeWorkbenchSelectionA(WorkbenchBase, (name), (hook), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __ChangeWorkbenchSelection(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") struct Hook * hook , Tag _tag1 , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-126(a6)\n\tmovea.l\t(a7)+,a2";
#define ChangeWorkbenchSelection(name, hook, ...) __ChangeWorkbenchSelection(WorkbenchBase, (name), (hook), __VA_ARGS__)
#endif

BOOL __MakeWorkbenchObjectVisibleA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-132(a6)";
#define MakeWorkbenchObjectVisibleA(name, tags) __MakeWorkbenchObjectVisibleA(WorkbenchBase, (name), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __MakeWorkbenchObjectVisible(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-132(a6)\n\tmovea.l\t(a7)+,a1";
#define MakeWorkbenchObjectVisible(name, ...) __MakeWorkbenchObjectVisible(WorkbenchBase, (name), __VA_ARGS__)
#endif

ULONG __WhichWorkbenchObjectA(__reg("a6") struct Library * , __reg("a0") struct Window * window , __reg("d0") LONG x , __reg("d1") LONG y , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-138(a6)";
#define WhichWorkbenchObjectA(window, x, y, tags) __WhichWorkbenchObjectA(WorkbenchBase, (window), (x), (y), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __WhichWorkbenchObject(__reg("a6") struct Library * , __reg("a0") struct Window * window , __reg("d0") LONG x , __reg("d1") LONG y , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-138(a6)\n\tmovea.l\t(a7)+,a1";
#define WhichWorkbenchObject(window, x, y, ...) __WhichWorkbenchObject(WorkbenchBase, (window), (x), (y), __VA_ARGS__)
#endif

#endif /* !_INLINE_WB_H */
