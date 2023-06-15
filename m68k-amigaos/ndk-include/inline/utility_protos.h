/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_UTILITY_H
#define _INLINE_UTILITY_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

struct TagItem * __FindTagItem(__reg("a6") struct Library * , __reg("d0") Tag tagVal , __reg("a0") CONST struct TagItem * tagList ) = "\tjsr\t-30(a6)";
#define FindTagItem(tagVal, tagList) __FindTagItem(UtilityBase, (tagVal), (tagList))

ULONG __GetTagData(__reg("a6") struct Library * , __reg("d0") Tag tagValue , __reg("d1") ULONG defaultVal , __reg("a0") CONST struct TagItem * tagList ) = "\tjsr\t-36(a6)";
#define GetTagData(tagValue, defaultVal, tagList) __GetTagData(UtilityBase, (tagValue), (defaultVal), (tagList))

ULONG __PackBoolTags(__reg("a6") struct Library * , __reg("d0") ULONG initialFlags , __reg("a0") CONST struct TagItem * tagList , __reg("a1") CONST struct TagItem * boolMap ) = "\tjsr\t-42(a6)";
#define PackBoolTags(initialFlags, tagList, boolMap) __PackBoolTags(UtilityBase, (initialFlags), (tagList), (boolMap))

struct TagItem * __NextTagItem(__reg("a6") struct Library * , __reg("a0") struct TagItem * *tagListPtr ) = "\tjsr\t-48(a6)";
#define NextTagItem(tagListPtr) __NextTagItem(UtilityBase, (tagListPtr))

VOID __FilterTagChanges(__reg("a6") struct Library * , __reg("a0") struct TagItem * changeList , __reg("a1") struct TagItem * originalList , __reg("d0") ULONG apply ) = "\tjsr\t-54(a6)";
#define FilterTagChanges(changeList, originalList, apply) __FilterTagChanges(UtilityBase, (changeList), (originalList), (apply))

VOID __MapTags(__reg("a6") struct Library * , __reg("a0") struct TagItem * tagList , __reg("a1") CONST struct TagItem * mapList , __reg("d0") ULONG mapType ) = "\tjsr\t-60(a6)";
#define MapTags(tagList, mapList, mapType) __MapTags(UtilityBase, (tagList), (mapList), (mapType))

struct TagItem * __AllocateTagItems(__reg("a6") struct Library * , __reg("d0") ULONG numTags ) = "\tjsr\t-66(a6)";
#define AllocateTagItems(numTags) __AllocateTagItems(UtilityBase, (numTags))

struct TagItem * __CloneTagItems(__reg("a6") struct Library * , __reg("a0") CONST struct TagItem * tagList ) = "\tjsr\t-72(a6)";
#define CloneTagItems(tagList) __CloneTagItems(UtilityBase, (tagList))

VOID __FreeTagItems(__reg("a6") struct Library * , __reg("a0") struct TagItem * tagList ) = "\tjsr\t-78(a6)";
#define FreeTagItems(tagList) __FreeTagItems(UtilityBase, (tagList))

VOID __RefreshTagItemClones(__reg("a6") struct Library * , __reg("a0") struct TagItem * clone , __reg("a1") CONST struct TagItem * original ) = "\tjsr\t-84(a6)";
#define RefreshTagItemClones(clone, original) __RefreshTagItemClones(UtilityBase, (clone), (original))

BOOL __TagInArray(__reg("a6") struct Library * , __reg("d0") Tag tagValue , __reg("a0") CONST Tag * tagArray ) = "\tjsr\t-90(a6)";
#define TagInArray(tagValue, tagArray) __TagInArray(UtilityBase, (tagValue), (tagArray))

ULONG __FilterTagItems(__reg("a6") struct Library * , __reg("a0") struct TagItem * tagList , __reg("a1") CONST Tag * filterArray , __reg("d0") ULONG logic ) = "\tjsr\t-96(a6)";
#define FilterTagItems(tagList, filterArray, logic) __FilterTagItems(UtilityBase, (tagList), (filterArray), (logic))

ULONG __CallHookPkt(__reg("a6") struct Library * , __reg("a0") struct Hook * hook , __reg("a2") APTR object , __reg("a1") APTR paramPacket ) = "\tjsr\t-102(a6)";
#define CallHookPkt(hook, object, paramPacket) __CallHookPkt(UtilityBase, (hook), (object), (paramPacket))

VOID __Amiga2Date(__reg("a6") struct Library * , __reg("d0") ULONG seconds , __reg("a0") struct ClockData * result ) = "\tjsr\t-120(a6)";
#define Amiga2Date(seconds, result) __Amiga2Date(UtilityBase, (seconds), (result))

ULONG __Date2Amiga(__reg("a6") struct Library * , __reg("a0") CONST struct ClockData * date ) = "\tjsr\t-126(a6)";
#define Date2Amiga(date) __Date2Amiga(UtilityBase, (date))

ULONG __CheckDate(__reg("a6") struct Library * , __reg("a0") CONST struct ClockData * date ) = "\tjsr\t-132(a6)";
#define CheckDate(date) __CheckDate(UtilityBase, (date))

LONG __SMult32(__reg("a6") struct Library * , __reg("d0") LONG arg1 , __reg("d1") LONG arg2 ) = "\tjsr\t-138(a6)";
#define SMult32(arg1, arg2) __SMult32(UtilityBase, (arg1), (arg2))

ULONG __UMult32(__reg("a6") struct Library * , __reg("d0") ULONG arg1 , __reg("d1") ULONG arg2 ) = "\tjsr\t-144(a6)";
#define UMult32(arg1, arg2) __UMult32(UtilityBase, (arg1), (arg2))

LONG __SDivMod32(__reg("a6") struct Library * , __reg("d0") LONG dividend , __reg("d1") LONG divisor ) = "\tjsr\t-150(a6)";
#define SDivMod32(dividend, divisor) __SDivMod32(UtilityBase, (dividend), (divisor))

ULONG __UDivMod32(__reg("a6") struct Library * , __reg("d0") ULONG dividend , __reg("d1") ULONG divisor ) = "\tjsr\t-156(a6)";
#define UDivMod32(dividend, divisor) __UDivMod32(UtilityBase, (dividend), (divisor))

LONG __Stricmp(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR string1 , __reg("a1") CONST_STRPTR string2 ) = "\tjsr\t-162(a6)";
#define Stricmp(string1, string2) __Stricmp(UtilityBase, (string1), (string2))

LONG __Strnicmp(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR string1 , __reg("a1") CONST_STRPTR string2 , __reg("d0") LONG length ) = "\tjsr\t-168(a6)";
#define Strnicmp(string1, string2, length) __Strnicmp(UtilityBase, (string1), (string2), (length))

UBYTE __ToUpper(__reg("a6") struct Library * , __reg("d0") UBYTE character ) = "\tjsr\t-174(a6)";
#define ToUpper(character) __ToUpper(UtilityBase, (character))

UBYTE __ToLower(__reg("a6") struct Library * , __reg("d0") UBYTE character ) = "\tjsr\t-180(a6)";
#define ToLower(character) __ToLower(UtilityBase, (character))

VOID __ApplyTagChanges(__reg("a6") struct Library * , __reg("a0") struct TagItem * list , __reg("a1") CONST struct TagItem * changeList ) = "\tjsr\t-186(a6)";
#define ApplyTagChanges(list, changeList) __ApplyTagChanges(UtilityBase, (list), (changeList))

LONG __SMult64(__reg("a6") struct Library * , __reg("d0") LONG arg1 , __reg("d1") LONG arg2 ) = "\tjsr\t-198(a6)";
#define SMult64(arg1, arg2) __SMult64(UtilityBase, (arg1), (arg2))

ULONG __UMult64(__reg("a6") struct Library * , __reg("d0") ULONG arg1 , __reg("d1") ULONG arg2 ) = "\tjsr\t-204(a6)";
#define UMult64(arg1, arg2) __UMult64(UtilityBase, (arg1), (arg2))

ULONG __PackStructureTags(__reg("a6") struct Library * , __reg("a0") APTR pack , __reg("a1") CONST ULONG * packTable , __reg("a2") CONST struct TagItem * tagList ) = "\tjsr\t-210(a6)";
#define PackStructureTags(pack, packTable, tagList) __PackStructureTags(UtilityBase, (pack), (packTable), (tagList))

ULONG __UnpackStructureTags(__reg("a6") struct Library * , __reg("a0") CONST_APTR pack , __reg("a1") CONST ULONG * packTable , __reg("a2") struct TagItem * tagList ) = "\tjsr\t-216(a6)";
#define UnpackStructureTags(pack, packTable, tagList) __UnpackStructureTags(UtilityBase, (pack), (packTable), (tagList))

BOOL __AddNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * nameSpace , __reg("a1") struct NamedObject * object ) = "\tjsr\t-222(a6)";
#define AddNamedObject(nameSpace, object) __AddNamedObject(UtilityBase, (nameSpace), (object))

struct NamedObject * __AllocNamedObjectA(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * tagList ) = "\tjsr\t-228(a6)";
#define AllocNamedObjectA(name, tagList) __AllocNamedObjectA(UtilityBase, (name), (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct NamedObject * __AllocNamedObject(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-228(a6)\n\tmovea.l\t(a7)+,a1";
#define AllocNamedObject(name, ...) __AllocNamedObject(UtilityBase, (name), __VA_ARGS__)
#endif

LONG __AttemptRemNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * object ) = "\tjsr\t-234(a6)";
#define AttemptRemNamedObject(object) __AttemptRemNamedObject(UtilityBase, (object))

struct NamedObject * __FindNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * nameSpace , __reg("a1") CONST_STRPTR name , __reg("a2") CONST struct NamedObject * lastObject ) = "\tjsr\t-240(a6)";
#define FindNamedObject(nameSpace, name, lastObject) __FindNamedObject(UtilityBase, (nameSpace), (name), (lastObject))

VOID __FreeNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * object ) = "\tjsr\t-246(a6)";
#define FreeNamedObject(object) __FreeNamedObject(UtilityBase, (object))

STRPTR __NamedObjectName(__reg("a6") struct Library * , __reg("a0") struct NamedObject * object ) = "\tjsr\t-252(a6)";
#define NamedObjectName(object) __NamedObjectName(UtilityBase, (object))

VOID __ReleaseNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * object ) = "\tjsr\t-258(a6)";
#define ReleaseNamedObject(object) __ReleaseNamedObject(UtilityBase, (object))

VOID __RemNamedObject(__reg("a6") struct Library * , __reg("a0") struct NamedObject * object , __reg("a1") struct Message * message ) = "\tjsr\t-264(a6)";
#define RemNamedObject(object, message) __RemNamedObject(UtilityBase, (object), (message))

ULONG __GetUniqueID(__reg("a6") struct Library * ) = "\tjsr\t-270(a6)";
#define GetUniqueID() __GetUniqueID(UtilityBase)

LONG __VSNPrintf(__reg("a6") struct Library * , __reg("a0") STRPTR buffer , __reg("d0") ULONG bufsize , __reg("a1") CONST_STRPTR fmt , __reg("a2") CONST_APTR data ) = "\tjsr\t-312(a6)";
#define VSNPrintf(buffer, bufsize, fmt, data) __VSNPrintf(UtilityBase, (buffer), (bufsize), (fmt), (data))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __SNPrintf(__reg("a6") struct Library * , __reg("a0") STRPTR buffer , __reg("d0") ULONG bufsize , CONST_STRPTR fmt , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-312(a6)\n\tmovea.l\t(a7)+,a1";
#define SNPrintf(buffer, bufsize, ...) __SNPrintf(UtilityBase, (buffer), (bufsize), __VA_ARGS__)
#endif

STRPTR __Strncpy(__reg("a6") struct Library * , __reg("a1") STRPTR dst , __reg("a0") CONST_STRPTR src , __reg("d0") ULONG size ) = "\tjsr\t-438(a6)";
#define Strncpy(dst, src, size) __Strncpy(UtilityBase, (dst), (src), (size))

STRPTR __Strncat(__reg("a6") struct Library * , __reg("a1") STRPTR dst , __reg("a0") CONST_STRPTR src , __reg("d0") ULONG size ) = "\tjsr\t-444(a6)";
#define Strncat(dst, src, size) __Strncat(UtilityBase, (dst), (src), (size))

LONG __SDivMod64(__reg("a6") struct Library * , __reg("d1") LONG hi , __reg("d0") LONG lo , __reg("d2") LONG divisor ) = "\tjsr\t-450(a6)";
#define SDivMod64(hi, lo, divisor) __SDivMod64(UtilityBase, (hi), (lo), (divisor))

ULONG __UDivMod64(__reg("a6") struct Library * , __reg("d1") ULONG hi , __reg("d0") ULONG lo , __reg("d2") ULONG divisor ) = "\tjsr\t-456(a6)";
#define UDivMod64(hi, lo, divisor) __UDivMod64(UtilityBase, (hi), (lo), (divisor))

#endif /* !_INLINE_UTILITY_H */
