#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_ICON_H
#define _INLINE_ICON_H

#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H
#endif

#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif

#ifndef ICON_BASE_NAME
#define ICON_BASE_NAME IconBase
#endif

#define FreeFreeList(freelist) ({ \
  struct FreeList * _FreeFreeList_freelist = (freelist); \
  { \
  register struct Library * const __FreeFreeList__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct FreeList * __FreeFreeList_freelist __asm("a0") = (_FreeFreeList_freelist); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__FreeFreeList__bn), "r"(__FreeFreeList_freelist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddFreeList(freelist, mem, size) ({ \
  struct FreeList * _AddFreeList_freelist = (freelist); \
  const APTR _AddFreeList_mem = (mem); \
  ULONG _AddFreeList_size = (size); \
  BOOL _AddFreeList__re = \
  ({ \
  register struct Library * const __AddFreeList__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __AddFreeList__re __asm("d0"); \
  register struct FreeList * __AddFreeList_freelist __asm("a0") = (_AddFreeList_freelist); \
  register const APTR __AddFreeList_mem __asm("a1") = (_AddFreeList_mem); \
  register ULONG __AddFreeList_size __asm("a2") = (_AddFreeList_size); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__AddFreeList__re) \
  : "r"(__AddFreeList__bn), "r"(__AddFreeList_freelist), "r"(__AddFreeList_mem), "r"(__AddFreeList_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddFreeList__re; \
  }); \
  _AddFreeList__re; \
})

#define GetDiskObject(name) ({ \
  CONST_STRPTR _GetDiskObject_name = (name); \
  struct DiskObject * _GetDiskObject__re = \
  ({ \
  register struct Library * const __GetDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __GetDiskObject__re __asm("d0"); \
  register CONST_STRPTR __GetDiskObject_name __asm("a0") = (_GetDiskObject_name); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__GetDiskObject__re) \
  : "r"(__GetDiskObject__bn), "r"(__GetDiskObject_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDiskObject__re; \
  }); \
  _GetDiskObject__re; \
})

#define PutDiskObject(name, diskobj) ({ \
  CONST_STRPTR _PutDiskObject_name = (name); \
  const struct DiskObject * _PutDiskObject_diskobj = (diskobj); \
  BOOL _PutDiskObject__re = \
  ({ \
  register struct Library * const __PutDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __PutDiskObject__re __asm("d0"); \
  register CONST_STRPTR __PutDiskObject_name __asm("a0") = (_PutDiskObject_name); \
  register const struct DiskObject * __PutDiskObject_diskobj __asm("a1") = (_PutDiskObject_diskobj); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__PutDiskObject__re) \
  : "r"(__PutDiskObject__bn), "r"(__PutDiskObject_name), "r"(__PutDiskObject_diskobj) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PutDiskObject__re; \
  }); \
  _PutDiskObject__re; \
})

#define FreeDiskObject(diskobj) ({ \
  struct DiskObject * _FreeDiskObject_diskobj = (diskobj); \
  { \
  register struct Library * const __FreeDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __FreeDiskObject_diskobj __asm("a0") = (_FreeDiskObject_diskobj); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__FreeDiskObject__bn), "r"(__FreeDiskObject_diskobj) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindToolType(toolTypeArray, typeName) ({ \
  STRPTR * _FindToolType_toolTypeArray = (toolTypeArray); \
  CONST_STRPTR _FindToolType_typeName = (typeName); \
  STRPTR _FindToolType__re = \
  ({ \
  register struct Library * const __FindToolType__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register STRPTR __FindToolType__re __asm("d0"); \
  register STRPTR * __FindToolType_toolTypeArray __asm("a0") = (_FindToolType_toolTypeArray); \
  register CONST_STRPTR __FindToolType_typeName __asm("a1") = (_FindToolType_typeName); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__FindToolType__re) \
  : "r"(__FindToolType__bn), "r"(__FindToolType_toolTypeArray), "r"(__FindToolType_typeName) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindToolType__re; \
  }); \
  _FindToolType__re; \
})

#define MatchToolValue(typeString, value) ({ \
  CONST_STRPTR _MatchToolValue_typeString = (typeString); \
  CONST_STRPTR _MatchToolValue_value = (value); \
  BOOL _MatchToolValue__re = \
  ({ \
  register struct Library * const __MatchToolValue__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __MatchToolValue__re __asm("d0"); \
  register CONST_STRPTR __MatchToolValue_typeString __asm("a0") = (_MatchToolValue_typeString); \
  register CONST_STRPTR __MatchToolValue_value __asm("a1") = (_MatchToolValue_value); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__MatchToolValue__re) \
  : "r"(__MatchToolValue__bn), "r"(__MatchToolValue_typeString), "r"(__MatchToolValue_value) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MatchToolValue__re; \
  }); \
  _MatchToolValue__re; \
})

#define BumpRevision(newname, oldname) ({ \
  STRPTR _BumpRevision_newname = (newname); \
  CONST_STRPTR _BumpRevision_oldname = (oldname); \
  STRPTR _BumpRevision__re = \
  ({ \
  register struct Library * const __BumpRevision__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register STRPTR __BumpRevision__re __asm("d0"); \
  register STRPTR __BumpRevision_newname __asm("a0") = (_BumpRevision_newname); \
  register CONST_STRPTR __BumpRevision_oldname __asm("a1") = (_BumpRevision_oldname); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__BumpRevision__re) \
  : "r"(__BumpRevision__bn), "r"(__BumpRevision_newname), "r"(__BumpRevision_oldname) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BumpRevision__re; \
  }); \
  _BumpRevision__re; \
})

#define GetDefDiskObject(type) ({ \
  LONG _GetDefDiskObject_type = (type); \
  struct DiskObject * _GetDefDiskObject__re = \
  ({ \
  register struct Library * const __GetDefDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __GetDefDiskObject__re __asm("d0"); \
  register LONG __GetDefDiskObject_type __asm("d0") = (_GetDefDiskObject_type); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__GetDefDiskObject__re) \
  : "r"(__GetDefDiskObject__bn), "r"(__GetDefDiskObject_type) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDefDiskObject__re; \
  }); \
  _GetDefDiskObject__re; \
})

#define PutDefDiskObject(diskObject) ({ \
  const struct DiskObject * _PutDefDiskObject_diskObject = (diskObject); \
  BOOL _PutDefDiskObject__re = \
  ({ \
  register struct Library * const __PutDefDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __PutDefDiskObject__re __asm("d0"); \
  register const struct DiskObject * __PutDefDiskObject_diskObject __asm("a0") = (_PutDefDiskObject_diskObject); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__PutDefDiskObject__re) \
  : "r"(__PutDefDiskObject__bn), "r"(__PutDefDiskObject_diskObject) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PutDefDiskObject__re; \
  }); \
  _PutDefDiskObject__re; \
})

#define GetDiskObjectNew(name) ({ \
  CONST_STRPTR _GetDiskObjectNew_name = (name); \
  struct DiskObject * _GetDiskObjectNew__re = \
  ({ \
  register struct Library * const __GetDiskObjectNew__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __GetDiskObjectNew__re __asm("d0"); \
  register CONST_STRPTR __GetDiskObjectNew_name __asm("a0") = (_GetDiskObjectNew_name); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__GetDiskObjectNew__re) \
  : "r"(__GetDiskObjectNew__bn), "r"(__GetDiskObjectNew_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDiskObjectNew__re; \
  }); \
  _GetDiskObjectNew__re; \
})

#define DeleteDiskObject(name) ({ \
  CONST_STRPTR _DeleteDiskObject_name = (name); \
  BOOL _DeleteDiskObject__re = \
  ({ \
  register struct Library * const __DeleteDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __DeleteDiskObject__re __asm("d0"); \
  register CONST_STRPTR __DeleteDiskObject_name __asm("a0") = (_DeleteDiskObject_name); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__DeleteDiskObject__re) \
  : "r"(__DeleteDiskObject__bn), "r"(__DeleteDiskObject_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DeleteDiskObject__re; \
  }); \
  _DeleteDiskObject__re; \
})

#define DupDiskObjectA(diskObject, tags) ({ \
  const struct DiskObject * _DupDiskObjectA_diskObject = (diskObject); \
  const struct TagItem * _DupDiskObjectA_tags = (tags); \
  struct DiskObject * _DupDiskObjectA__re = \
  ({ \
  register struct Library * const __DupDiskObjectA__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __DupDiskObjectA__re __asm("d0"); \
  register const struct DiskObject * __DupDiskObjectA_diskObject __asm("a0") = (_DupDiskObjectA_diskObject); \
  register const struct TagItem * __DupDiskObjectA_tags __asm("a1") = (_DupDiskObjectA_tags); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__DupDiskObjectA__re) \
  : "r"(__DupDiskObjectA__bn), "r"(__DupDiskObjectA_diskObject), "r"(__DupDiskObjectA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DupDiskObjectA__re; \
  }); \
  _DupDiskObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct DiskObject * ___DupDiskObject(struct Library * IconBase, const struct DiskObject * diskObject, ...)
{
  return DupDiskObjectA(diskObject, (const struct TagItem *) ((ULONG) &diskObject + sizeof(const struct DiskObject *)));
}

#define DupDiskObject(diskObject...) ___DupDiskObject(ICON_BASE_NAME, diskObject)
#endif

#define IconControlA(icon, tags) ({ \
  struct DiskObject * _IconControlA_icon = (icon); \
  const struct TagItem * _IconControlA_tags = (tags); \
  ULONG _IconControlA__re = \
  ({ \
  register struct Library * const __IconControlA__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register ULONG __IconControlA__re __asm("d0"); \
  register struct DiskObject * __IconControlA_icon __asm("a0") = (_IconControlA_icon); \
  register const struct TagItem * __IconControlA_tags __asm("a1") = (_IconControlA_tags); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__IconControlA__re) \
  : "r"(__IconControlA__bn), "r"(__IconControlA_icon), "r"(__IconControlA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IconControlA__re; \
  }); \
  _IconControlA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___IconControl(struct Library * IconBase, struct DiskObject * icon, ...)
{
  return IconControlA(icon, (const struct TagItem *) ((ULONG) &icon + sizeof(struct DiskObject *)));
}

#define IconControl(icon...) ___IconControl(ICON_BASE_NAME, icon)
#endif

#define DrawIconStateA(rp, icon, label, leftOffset, topOffset, state, tags) ({ \
  struct RastPort * _DrawIconStateA_rp = (rp); \
  const struct DiskObject * _DrawIconStateA_icon = (icon); \
  CONST_STRPTR _DrawIconStateA_label = (label); \
  LONG _DrawIconStateA_leftOffset = (leftOffset); \
  LONG _DrawIconStateA_topOffset = (topOffset); \
  ULONG _DrawIconStateA_state = (state); \
  const struct TagItem * _DrawIconStateA_tags = (tags); \
  { \
  register struct Library * const __DrawIconStateA__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct RastPort * __DrawIconStateA_rp __asm("a0") = (_DrawIconStateA_rp); \
  register const struct DiskObject * __DrawIconStateA_icon __asm("a1") = (_DrawIconStateA_icon); \
  register CONST_STRPTR __DrawIconStateA_label __asm("a2") = (_DrawIconStateA_label); \
  register LONG __DrawIconStateA_leftOffset __asm("d0") = (_DrawIconStateA_leftOffset); \
  register LONG __DrawIconStateA_topOffset __asm("d1") = (_DrawIconStateA_topOffset); \
  register ULONG __DrawIconStateA_state __asm("d2") = (_DrawIconStateA_state); \
  register const struct TagItem * __DrawIconStateA_tags __asm("a3") = (_DrawIconStateA_tags); \
  __asm volatile ("jsr a6@(-162:W)" \
  : \
  : "r"(__DrawIconStateA__bn), "r"(__DrawIconStateA_rp), "r"(__DrawIconStateA_icon), "r"(__DrawIconStateA_label), "r"(__DrawIconStateA_leftOffset), "r"(__DrawIconStateA_topOffset), "r"(__DrawIconStateA_state), "r"(__DrawIconStateA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___DrawIconState(struct Library * IconBase, struct RastPort * rp, const struct DiskObject * icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ...)
{
  DrawIconStateA(rp, icon, label, leftOffset, topOffset, state, (const struct TagItem *) ((ULONG) &state + sizeof(ULONG)));
}

#define DrawIconState(rp, icon, label, leftOffset, topOffset, state...) ___DrawIconState(ICON_BASE_NAME, rp, icon, label, leftOffset, topOffset, state)
#endif

#define GetIconRectangleA(rp, icon, label, rect, tags) ({ \
  struct RastPort * _GetIconRectangleA_rp = (rp); \
  const struct DiskObject * _GetIconRectangleA_icon = (icon); \
  CONST_STRPTR _GetIconRectangleA_label = (label); \
  struct Rectangle * _GetIconRectangleA_rect = (rect); \
  const struct TagItem * _GetIconRectangleA_tags = (tags); \
  BOOL _GetIconRectangleA__re = \
  ({ \
  register struct Library * const __GetIconRectangleA__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __GetIconRectangleA__re __asm("d0"); \
  register struct RastPort * __GetIconRectangleA_rp __asm("a0") = (_GetIconRectangleA_rp); \
  register const struct DiskObject * __GetIconRectangleA_icon __asm("a1") = (_GetIconRectangleA_icon); \
  register CONST_STRPTR __GetIconRectangleA_label __asm("a2") = (_GetIconRectangleA_label); \
  register struct Rectangle * __GetIconRectangleA_rect __asm("a3") = (_GetIconRectangleA_rect); \
  register const struct TagItem * __GetIconRectangleA_tags __asm("d2") = (_GetIconRectangleA_tags); \
  __asm volatile ("exg a4,d2\n\tjsr a6@(-168:W)\n\texg a4,d2" \
  : "=r"(__GetIconRectangleA__re) \
  : "r"(__GetIconRectangleA__bn), "r"(__GetIconRectangleA_rp), "r"(__GetIconRectangleA_icon), "r"(__GetIconRectangleA_label), "r"(__GetIconRectangleA_rect), "r"(__GetIconRectangleA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetIconRectangleA__re; \
  }); \
  _GetIconRectangleA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___GetIconRectangle(struct Library * IconBase, struct RastPort * rp, const struct DiskObject * icon, CONST_STRPTR label, struct Rectangle * rect, ...)
{
  return GetIconRectangleA(rp, icon, label, rect, (const struct TagItem *) ((ULONG) &rect + sizeof(struct Rectangle *)));
}

#define GetIconRectangle(rp, icon, label, rect...) ___GetIconRectangle(ICON_BASE_NAME, rp, icon, label, rect)
#endif

#define NewDiskObject(type) ({ \
  LONG _NewDiskObject_type = (type); \
  struct DiskObject * _NewDiskObject__re = \
  ({ \
  register struct Library * const __NewDiskObject__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __NewDiskObject__re __asm("d0"); \
  register LONG __NewDiskObject_type __asm("d0") = (_NewDiskObject_type); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__NewDiskObject__re) \
  : "r"(__NewDiskObject__bn), "r"(__NewDiskObject_type) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NewDiskObject__re; \
  }); \
  _NewDiskObject__re; \
})

#define GetIconTagList(name, tags) ({ \
  CONST_STRPTR _GetIconTagList_name = (name); \
  const struct TagItem * _GetIconTagList_tags = (tags); \
  struct DiskObject * _GetIconTagList__re = \
  ({ \
  register struct Library * const __GetIconTagList__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct DiskObject * __GetIconTagList__re __asm("d0"); \
  register CONST_STRPTR __GetIconTagList_name __asm("a0") = (_GetIconTagList_name); \
  register const struct TagItem * __GetIconTagList_tags __asm("a1") = (_GetIconTagList_tags); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__GetIconTagList__re) \
  : "r"(__GetIconTagList__bn), "r"(__GetIconTagList_name), "r"(__GetIconTagList_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetIconTagList__re; \
  }); \
  _GetIconTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct DiskObject * ___GetIconTags(struct Library * IconBase, CONST_STRPTR name, ...)
{
  return GetIconTagList(name, (const struct TagItem *) ((ULONG) &name + sizeof(CONST_STRPTR)));
}

#define GetIconTags(name...) ___GetIconTags(ICON_BASE_NAME, name)
#endif

#define PutIconTagList(name, icon, tags) ({ \
  CONST_STRPTR _PutIconTagList_name = (name); \
  const struct DiskObject * _PutIconTagList_icon = (icon); \
  const struct TagItem * _PutIconTagList_tags = (tags); \
  BOOL _PutIconTagList__re = \
  ({ \
  register struct Library * const __PutIconTagList__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __PutIconTagList__re __asm("d0"); \
  register CONST_STRPTR __PutIconTagList_name __asm("a0") = (_PutIconTagList_name); \
  register const struct DiskObject * __PutIconTagList_icon __asm("a1") = (_PutIconTagList_icon); \
  register const struct TagItem * __PutIconTagList_tags __asm("a2") = (_PutIconTagList_tags); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__PutIconTagList__re) \
  : "r"(__PutIconTagList__bn), "r"(__PutIconTagList_name), "r"(__PutIconTagList_icon), "r"(__PutIconTagList_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PutIconTagList__re; \
  }); \
  _PutIconTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___PutIconTags(struct Library * IconBase, CONST_STRPTR name, const struct DiskObject * icon, ...)
{
  return PutIconTagList(name, icon, (const struct TagItem *) ((ULONG) &icon + sizeof(const struct DiskObject *)));
}

#define PutIconTags(name, icon...) ___PutIconTags(ICON_BASE_NAME, name, icon)
#endif

#define LayoutIconA(icon, screen, tags) ({ \
  struct DiskObject * _LayoutIconA_icon = (icon); \
  struct Screen * _LayoutIconA_screen = (screen); \
  const struct TagItem * _LayoutIconA_tags = (tags); \
  BOOL _LayoutIconA__re = \
  ({ \
  register struct Library * const __LayoutIconA__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register BOOL __LayoutIconA__re __asm("d0"); \
  register struct DiskObject * __LayoutIconA_icon __asm("a0") = (_LayoutIconA_icon); \
  register struct Screen * __LayoutIconA_screen __asm("a1") = (_LayoutIconA_screen); \
  register const struct TagItem * __LayoutIconA_tags __asm("a2") = (_LayoutIconA_tags); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__LayoutIconA__re) \
  : "r"(__LayoutIconA__bn), "r"(__LayoutIconA_icon), "r"(__LayoutIconA_screen), "r"(__LayoutIconA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LayoutIconA__re; \
  }); \
  _LayoutIconA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___LayoutIcon(struct Library * IconBase, struct DiskObject * icon, struct Screen * screen, ...)
{
  return LayoutIconA(icon, screen, (struct TagItem *) ((ULONG) &screen + sizeof(struct Screen *)));
}

#define LayoutIcon(icon, screen...) ___LayoutIcon(ICON_BASE_NAME, icon, screen)
#endif

#define ChangeToSelectedIconColor(cr) ({ \
  struct ColorRegister * _ChangeToSelectedIconColor_cr = (cr); \
  { \
  register struct Library * const __ChangeToSelectedIconColor__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register struct ColorRegister * __ChangeToSelectedIconColor_cr __asm("a0") = (_ChangeToSelectedIconColor_cr); \
  __asm volatile ("jsr a6@(-198:W)" \
  : \
  : "r"(__ChangeToSelectedIconColor__bn), "r"(__ChangeToSelectedIconColor_cr) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define BumpRevisionLength(newname, oldname, maxlength) ({ \
  STRPTR _BumpRevisionLength_newname = (newname); \
  CONST_STRPTR _BumpRevisionLength_oldname = (oldname); \
  uint32 _BumpRevisionLength_maxlength = (maxlength); \
  { \
  register struct Library * const __BumpRevisionLength__bn __asm("a6") = (struct Library *) (ICON_BASE_NAME);\
  register STRPTR __BumpRevisionLength_newname __asm("a0") = (_BumpRevisionLength_newname); \
  register CONST_STRPTR __BumpRevisionLength_oldname __asm("a1") = (_BumpRevisionLength_oldname); \
  register uint32 __BumpRevisionLength_maxlength __asm("d0") = (BumpRevisionLength_maxlength); \
  __asm volatile ("jsr a6@(-204:W)" \
  : \
  : "r"(__BumpRevisionLength__bn), "r"(__BumpRevisionLength_newname), "r"(__BumpRevisionLength_oldname), "r"(__BumpRevisionLength_maxlength) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_ICON_H  */
