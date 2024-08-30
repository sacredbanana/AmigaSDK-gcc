/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TRE_H
#define _PPCINLINE_TRE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TRE_BASE_NAME
#define TRE_BASE_NAME TREBase
#endif /* !TRE_BASE_NAME */

#define tre_regwexec(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(const regex_t *, const wchar_t *, size_t , regmatch_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 58))(__p0, __p1, __p2, __p3, __p4))

#define tre_regexec(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(const regex_t *, const char *, size_t , regmatch_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 34))(__p0, __p1, __p2, __p3, __p4))

#define tre_regwncomp(__p0, __p1, __p2, __p3) \
	(((int (*)(regex_t *, const wchar_t *, size_t , int ))*(void**)((long)(TRE_BASE_NAME) - 76))(__p0, __p1, __p2, __p3))

#define tre_reganexec(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(const regex_t *, const char *, size_t , regamatch_t *, regaparams_t , int ))*(void**)((long)(TRE_BASE_NAME) - 94))(__p0, __p1, __p2, __p3, __p4, __p5))

#define tre_regwnexec(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(const regex_t *, const wchar_t *, size_t , size_t , regmatch_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 82))(__p0, __p1, __p2, __p3, __p4, __p5))

#define tre_regerror(__p0, __p1, __p2, __p3) \
	(((size_t (*)(int , const regex_t *, char *, size_t ))*(void**)((long)(TRE_BASE_NAME) - 40))(__p0, __p1, __p2, __p3))

#define tre_config(__p0, __p1) \
	(((int (*)(int , void *))*(void**)((long)(TRE_BASE_NAME) - 130))(__p0, __p1))

#define tre_regncomp(__p0, __p1, __p2, __p3) \
	(((int (*)(regex_t *, const char *, size_t , int ))*(void**)((long)(TRE_BASE_NAME) - 64))(__p0, __p1, __p2, __p3))

#define tre_have_backrefs(__p0) \
	(((int (*)(const regex_t *))*(void**)((long)(TRE_BASE_NAME) - 136))(__p0))

#define tre_regaexec(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(const regex_t *, const char *, regamatch_t *, regaparams_t , int ))*(void**)((long)(TRE_BASE_NAME) - 88))(__p0, __p1, __p2, __p3, __p4))

#define tre_regawexec(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(const regex_t *, const wchar_t *, regamatch_t *, regaparams_t , int ))*(void**)((long)(TRE_BASE_NAME) - 100))(__p0, __p1, __p2, __p3, __p4))

#define tre_regnexec(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(const regex_t *, const char *, size_t , size_t , regmatch_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 70))(__p0, __p1, __p2, __p3, __p4, __p5))

#define tre_regfree(__p0) \
	(((void (*)(regex_t *))*(void**)((long)(TRE_BASE_NAME) - 46))(__p0))

#define tre_reguexec(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(const regex_t *, const tre_str_source *, size_t , regmatch_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 118))(__p0, __p1, __p2, __p3, __p4))

#define tre_have_approx(__p0) \
	(((int (*)(const regex_t *))*(void**)((long)(TRE_BASE_NAME) - 142))(__p0))

#define tre_regawnexec(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(const regex_t *, const wchar_t *, size_t , regamatch_t *, regaparams_t , int ))*(void**)((long)(TRE_BASE_NAME) - 106))(__p0, __p1, __p2, __p3, __p4, __p5))

#define tre_regwcomp(__p0, __p1, __p2) \
	(((int (*)(regex_t *, const wchar_t *, int ))*(void**)((long)(TRE_BASE_NAME) - 52))(__p0, __p1, __p2))

#define tre_regcomp(__p0, __p1, __p2) \
	(((int (*)(regex_t *, const char *, int ))*(void**)((long)(TRE_BASE_NAME) - 28))(__p0, __p1, __p2))

#define tre_regaparams_default(__p0) \
	(((void (*)(regaparams_t *))*(void**)((long)(TRE_BASE_NAME) - 112))(__p0))

#define tre_version() \
	(((char *(*)(void))*(void**)((long)(TRE_BASE_NAME) - 124))())

#endif /* !_PPCINLINE_TRE_H */
