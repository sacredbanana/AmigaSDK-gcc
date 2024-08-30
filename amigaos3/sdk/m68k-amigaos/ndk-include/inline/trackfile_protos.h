/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_TRACKFILE_H
#define _INLINE_TRACKFILE_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

LONG __TFStartUnitTagList(__reg("a6") struct Library * , __reg("d0") LONG which_unit , __reg("a0") CONST struct TagItem * tags ) = "\tjsr\t-42(a6)";
#define TFStartUnitTagList(which_unit, tags) __TFStartUnitTagList(TrackFileBase, (which_unit), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __TFStartUnitTags(__reg("a6") struct Library * , __reg("d0") LONG which_unit , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-42(a6)\n\tmovea.l\t(a7)+,a0";
#define TFStartUnitTags(which_unit, ...) __TFStartUnitTags(TrackFileBase, (which_unit), __VA_ARGS__)
#endif

LONG __TFStopUnitTagList(__reg("a6") struct Library * , __reg("d0") LONG which_unit , __reg("a0") CONST struct TagItem * tags ) = "\tjsr\t-48(a6)";
#define TFStopUnitTagList(which_unit, tags) __TFStopUnitTagList(TrackFileBase, (which_unit), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __TFStopUnitTags(__reg("a6") struct Library * , __reg("d0") LONG which_unit , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a0";
#define TFStopUnitTags(which_unit, ...) __TFStopUnitTags(TrackFileBase, (which_unit), __VA_ARGS__)
#endif

LONG __TFInsertMediaTagList(__reg("a6") struct Library * , __reg("d0") LONG which_unit , __reg("a0") CONST struct TagItem * tags ) = "\tjsr\t-54(a6)";
#define TFInsertMediaTagList(which_unit, tags) __TFInsertMediaTagList(TrackFileBase, (which_unit), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __TFInsertMediaTags(__reg("a6") struct Library * , __reg("d0") LONG which_unit , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a0";
#define TFInsertMediaTags(which_unit, ...) __TFInsertMediaTags(TrackFileBase, (which_unit), __VA_ARGS__)
#endif

LONG __TFEjectMediaTagList(__reg("a6") struct Library * , __reg("d0") LONG which_unit , __reg("a0") CONST struct TagItem * tags ) = "\tjsr\t-60(a6)";
#define TFEjectMediaTagList(which_unit, tags) __TFEjectMediaTagList(TrackFileBase, (which_unit), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __TFEjectMediaTags(__reg("a6") struct Library * , __reg("d0") LONG which_unit , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-60(a6)\n\tmovea.l\t(a7)+,a0";
#define TFEjectMediaTags(which_unit, ...) __TFEjectMediaTags(TrackFileBase, (which_unit), __VA_ARGS__)
#endif

struct TrackFileUnitData * __TFGetUnitData(__reg("a6") struct Library * , __reg("d0") LONG which_unit ) = "\tjsr\t-66(a6)";
#define TFGetUnitData(which_unit) __TFGetUnitData(TrackFileBase, (which_unit))

VOID __TFFreeUnitData(__reg("a6") struct Library * , __reg("a0") struct TrackFileUnitData * tfud ) = "\tjsr\t-72(a6)";
#define TFFreeUnitData(tfud) __TFFreeUnitData(TrackFileBase, (tfud))

LONG __TFChangeUnitTagList(__reg("a6") struct Library * , __reg("d0") LONG which_unit , __reg("a0") CONST struct TagItem * tags ) = "\tjsr\t-78(a6)";
#define TFChangeUnitTagList(which_unit, tags) __TFChangeUnitTagList(TrackFileBase, (which_unit), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __TFChangeUnitTags(__reg("a6") struct Library * , __reg("d0") LONG which_unit , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-78(a6)\n\tmovea.l\t(a7)+,a0";
#define TFChangeUnitTags(which_unit, ...) __TFChangeUnitTags(TrackFileBase, (which_unit), __VA_ARGS__)
#endif

LONG __TFExamineFileSize(__reg("a6") struct Library * , __reg("d0") LONG file_size ) = "\tjsr\t-84(a6)";
#define TFExamineFileSize(file_size) __TFExamineFileSize(TrackFileBase, (file_size))

#endif /* !_INLINE_TRACKFILE_H */
