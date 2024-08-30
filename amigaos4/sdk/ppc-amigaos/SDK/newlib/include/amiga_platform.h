#ifndef _AMIGA_PLATFORM_H_
#define _AMIGA_PLATFORM_H_

#include <sys/unistd.h>
#include <sys/reent.h>

/*
 * Define and set to 1 (or rather just link with -lunix) to enable translation
 * of Unix path names to Amiga path names in the clib file i/o functions. If
 * you don't define this or link with -lunix the default is 0 (disabled).
 */
extern const int __unix_path_semantics;

/* A data structures used by the path translation routines below. */
struct NameTranslationInfo
{
	char	nti_Substitute[MAXPATHLEN];
	char *	nti_OriginalName;
	int		nti_IsRoot;
};

extern void __restore_path_name (char const **,struct NameTranslationInfo *);
extern int __translate_amiga_to_unix_path_name (char const **,struct NameTranslationInfo *);
extern int __translate_unix_to_amiga_path_name (char const **,struct NameTranslationInfo *);
extern int __translate_amiga_to_unix_path_name_r (struct _reent *,char const **,struct NameTranslationInfo *);
extern int __translate_unix_to_amiga_path_name_r (struct _reent *,char const **,struct NameTranslationInfo *);

#endif

