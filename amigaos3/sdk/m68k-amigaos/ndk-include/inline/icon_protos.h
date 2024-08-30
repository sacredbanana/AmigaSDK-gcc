/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_ICON_H
#define _INLINE_ICON_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __FreeFreeList(__reg("a6") struct Library * , __reg("a0") struct FreeList * freelist ) = "\tjsr\t-54(a6)";
#define FreeFreeList(freelist) __FreeFreeList(IconBase, (freelist))

BOOL __AddFreeList(__reg("a6") struct Library * , __reg("a0") struct FreeList * freelist , __reg("a1") CONST_APTR mem , __reg("a2") ULONG size ) = "\tjsr\t-72(a6)";
#define AddFreeList(freelist, mem, size) __AddFreeList(IconBase, (freelist), (mem), (size))

struct DiskObject * __GetDiskObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name ) = "\tjsr\t-78(a6)";
#define GetDiskObject(name) __GetDiskObject(IconBase, (name))

BOOL __PutDiskObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct DiskObject * diskobj ) = "\tjsr\t-84(a6)";
#define PutDiskObject(name, diskobj) __PutDiskObject(IconBase, (name), (diskobj))

VOID __FreeDiskObject(__reg("a6") struct Library * , __reg("a0") struct DiskObject * diskobj ) = "\tjsr\t-90(a6)";
#define FreeDiskObject(diskobj) __FreeDiskObject(IconBase, (diskobj))

UBYTE * __FindToolType(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR * toolTypeArray , __reg("a1") CONST_STRPTR typeName ) = "\tjsr\t-96(a6)";
#define FindToolType(toolTypeArray, typeName) __FindToolType(IconBase, (toolTypeArray), (typeName))

BOOL __MatchToolValue(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR typeString , __reg("a1") CONST_STRPTR value ) = "\tjsr\t-102(a6)";
#define MatchToolValue(typeString, value) __MatchToolValue(IconBase, (typeString), (value))

STRPTR __BumpRevision(__reg("a6") struct Library * , __reg("a0") STRPTR newname , __reg("a1") CONST_STRPTR oldname ) = "\tjsr\t-108(a6)";
#define BumpRevision(newname, oldname) __BumpRevision(IconBase, (newname), (oldname))

APTR __FreeAlloc(__reg("a6") struct Library * , __reg("a0") struct FreeList * free , __reg("a1") ULONG len , __reg("a2") ULONG type ) = "\tjsr\t-114(a6)";
#define FreeAlloc(free, len, type) __FreeAlloc(IconBase, (free), (len), (type))

struct DiskObject * __GetDefDiskObject(__reg("a6") struct Library * , __reg("d0") LONG type ) = "\tjsr\t-120(a6)";
#define GetDefDiskObject(type) __GetDefDiskObject(IconBase, (type))

BOOL __PutDefDiskObject(__reg("a6") struct Library * , __reg("a0") CONST struct DiskObject * diskObject ) = "\tjsr\t-126(a6)";
#define PutDefDiskObject(diskObject) __PutDefDiskObject(IconBase, (diskObject))

struct DiskObject * __GetDiskObjectNew(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name ) = "\tjsr\t-132(a6)";
#define GetDiskObjectNew(name) __GetDiskObjectNew(IconBase, (name))

BOOL __DeleteDiskObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name ) = "\tjsr\t-138(a6)";
#define DeleteDiskObject(name) __DeleteDiskObject(IconBase, (name))

VOID __FreeFree(__reg("a6") struct Library * , __reg("a0") struct FreeList * fl , __reg("a1") APTR address ) = "\tjsr\t-144(a6)";
#define FreeFree(fl, address) __FreeFree(IconBase, (fl), (address))

struct DiskObject * __DupDiskObjectA(__reg("a6") struct Library * , __reg("a0") CONST struct DiskObject * diskObject , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-150(a6)";
#define DupDiskObjectA(diskObject, tags) __DupDiskObjectA(IconBase, (diskObject), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct DiskObject * __DupDiskObject(__reg("a6") struct Library * , __reg("a0") CONST struct DiskObject * diskObject , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-150(a6)\n\tmovea.l\t(a7)+,a1";
#define DupDiskObject(diskObject, ...) __DupDiskObject(IconBase, (diskObject), __VA_ARGS__)
#endif

ULONG __IconControlA(__reg("a6") struct Library * , __reg("a0") struct DiskObject * icon , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-156(a6)";
#define IconControlA(icon, tags) __IconControlA(IconBase, (icon), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __IconControl(__reg("a6") struct Library * , __reg("a0") struct DiskObject * icon , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-156(a6)\n\tmovea.l\t(a7)+,a1";
#define IconControl(icon, ...) __IconControl(IconBase, (icon), __VA_ARGS__)
#endif

VOID __DrawIconStateA(__reg("a6") struct Library * , __reg("a0") struct RastPort * rp , __reg("a1") CONST struct DiskObject * icon , __reg("a2") CONST_STRPTR label , __reg("d0") LONG leftOffset , __reg("d1") LONG topOffset , __reg("d2") ULONG state , __reg("a3") CONST struct TagItem * tags ) = "\tjsr\t-162(a6)";
#define DrawIconStateA(rp, icon, label, leftOffset, topOffset, state, tags) __DrawIconStateA(IconBase, (rp), (icon), (label), (leftOffset), (topOffset), (state), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __DrawIconState(__reg("a6") struct Library * , __reg("a0") struct RastPort * rp , __reg("a1") CONST struct DiskObject * icon , __reg("a2") CONST_STRPTR label , __reg("d0") LONG leftOffset , __reg("d1") LONG topOffset , __reg("d2") ULONG state , Tag _tag1 , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-162(a6)\n\tmovea.l\t(a7)+,a3";
#define DrawIconState(rp, icon, label, leftOffset, topOffset, state, ...) __DrawIconState(IconBase, (rp), (icon), (label), (leftOffset), (topOffset), (state), __VA_ARGS__)
#endif

BOOL __GetIconRectangleA(__reg("a6") struct Library * , __reg("a0") struct RastPort * rp , __reg("a1") CONST struct DiskObject * icon , __reg("a2") CONST_STRPTR label , __reg("a3") struct Rectangle * rect , __reg("a4") CONST struct TagItem * tags ) = "\tjsr\t-168(a6)";
#define GetIconRectangleA(rp, icon, label, rect, tags) __GetIconRectangleA(IconBase, (rp), (icon), (label), (rect), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __GetIconRectangle(__reg("a6") struct Library * , __reg("a0") struct RastPort * rp , __reg("a1") CONST struct DiskObject * icon , __reg("a2") CONST_STRPTR label , __reg("a3") struct Rectangle * rect , Tag _tag1 , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-168(a6)\n\tmovea.l\t(a7)+,a4";
#define GetIconRectangle(rp, icon, label, rect, ...) __GetIconRectangle(IconBase, (rp), (icon), (label), (rect), __VA_ARGS__)
#endif

struct DiskObject * __NewDiskObject(__reg("a6") struct Library * , __reg("d0") LONG type ) = "\tjsr\t-174(a6)";
#define NewDiskObject(type) __NewDiskObject(IconBase, (type))

struct DiskObject * __GetIconTagList(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tags ) = "\tjsr\t-180(a6)";
#define GetIconTagList(name, tags) __GetIconTagList(IconBase, (name), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct DiskObject * __GetIconTags(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-180(a6)\n\tmovea.l\t(a7)+,a1";
#define GetIconTags(name, ...) __GetIconTags(IconBase, (name), __VA_ARGS__)
#endif

BOOL __PutIconTagList(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct DiskObject * icon , __reg("a2") CONST struct TagItem * tags ) = "\tjsr\t-186(a6)";
#define PutIconTagList(name, icon, tags) __PutIconTagList(IconBase, (name), (icon), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __PutIconTags(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct DiskObject * icon , Tag _tag1 , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-186(a6)\n\tmovea.l\t(a7)+,a2";
#define PutIconTags(name, icon, ...) __PutIconTags(IconBase, (name), (icon), __VA_ARGS__)
#endif

BOOL __LayoutIconA(__reg("a6") struct Library * , __reg("a0") struct DiskObject * icon , __reg("a1") struct Screen * screen , __reg("a2") struct TagItem * tags ) = "\tjsr\t-192(a6)";
#define LayoutIconA(icon, screen, tags) __LayoutIconA(IconBase, (icon), (screen), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __LayoutIcon(__reg("a6") struct Library * , __reg("a0") struct DiskObject * icon , __reg("a1") struct Screen * screen , Tag _tag1 , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-192(a6)\n\tmovea.l\t(a7)+,a2";
#define LayoutIcon(icon, screen, ...) __LayoutIcon(IconBase, (icon), (screen), __VA_ARGS__)
#endif

VOID __ChangeToSelectedIconColor(__reg("a6") struct Library * , __reg("a0") struct ColorRegister * cr ) = "\tjsr\t-198(a6)";
#define ChangeToSelectedIconColor(cr) __ChangeToSelectedIconColor(IconBase, (cr))

STRPTR __BumpRevisionLength(__reg("a6") struct Library * , __reg("a0") STRPTR newname , __reg("a1") CONST_STRPTR oldname , __reg("d0") ULONG maxLength ) = "\tjsr\t-204(a6)";
#define BumpRevisionLength(newname, oldname, maxLength) __BumpRevisionLength(IconBase, (newname), (oldname), (maxLength))

#endif /* !_INLINE_ICON_H */
