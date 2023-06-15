/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_PCCARD_H
#define _INLINE_PCCARD_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

const struct TagItem * __PCCard_GetTupleInfo(__reg("a6") struct Library * , __reg("a0") const UBYTE * tuple ) = "\tjsr\t-30(a6)";
#define PCCard_GetTupleInfo(tuple) __PCCard_GetTupleInfo(PCCardBase, (tuple))

VOID __PCCard_FreeTupleInfo(__reg("a6") struct Library * , __reg("a0") const struct TagItem * tagList ) = "\tjsr\t-36(a6)";
#define PCCard_FreeTupleInfo(tagList) __PCCard_FreeTupleInfo(PCCardBase, (tagList))

const struct TagItem * __PCCard_GetFuncETupleInfo(__reg("a6") struct Library * , __reg("a0") const UBYTE * tuple , __reg("d0") const UBYTE funcID ) = "\tjsr\t-42(a6)";
#define PCCard_GetFuncETupleInfo(tuple, funcID) __PCCard_GetFuncETupleInfo(PCCardBase, (tuple), (funcID))

#endif /* !_INLINE_PCCARD_H */
