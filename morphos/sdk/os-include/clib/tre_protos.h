#ifndef	CLIB_TRE_PROTOS_H
#define	CLIB_TRE_PROTOS_H
#include <libraries/tre.h>

extern int
tre_regcomp(regex_t *preg, const char *regex, int cflags);

extern int
tre_regexec(const regex_t *preg, const char *string, size_t nmatch,
	regmatch_t pmatch[], int eflags);

extern size_t
tre_regerror(int errcode, const regex_t *preg, char *errbuf,
	 size_t errbuf_size);

extern void
tre_regfree(regex_t *preg);

extern int
tre_regwcomp(regex_t *preg, const wchar_t *regex, int cflags);

extern int
tre_regwexec(const regex_t *preg, const wchar_t *string,
	 size_t nmatch, regmatch_t pmatch[], int eflags);

extern int
tre_regncomp(regex_t *preg, const char *regex, size_t len, int cflags);

extern int
tre_regnexec(const regex_t *preg, const char *string, size_t len,
	 size_t nmatch, regmatch_t pmatch[], int eflags);

extern int
tre_regwncomp(regex_t *preg, const wchar_t *regex, size_t len, int cflags);

extern int
tre_regwnexec(const regex_t *preg, const wchar_t *string, size_t len,
	  size_t nmatch, regmatch_t pmatch[], int eflags);

extern int
tre_regaexec(const regex_t *preg, const char *string,
	 regamatch_t *match, regaparams_t params, int eflags);

extern int
tre_reganexec(const regex_t *preg, const char *string, size_t len,
	  regamatch_t *match, regaparams_t params, int eflags);

extern int
tre_regawexec(const regex_t *preg, const wchar_t *string,
	  regamatch_t *match, regaparams_t params, int eflags);

extern int
tre_regawnexec(const regex_t *preg, const wchar_t *string, size_t len,
	   regamatch_t *match, regaparams_t params, int eflags);

extern void
tre_regaparams_default(regaparams_t *params);

extern int
tre_reguexec(const regex_t *preg, const tre_str_source *string,
	 size_t nmatch, regmatch_t pmatch[], int eflags);


extern int
tre_reguexec(const regex_t *preg, const tre_str_source *string,
	 size_t nmatch, regmatch_t pmatch[], int eflags);

extern char *
tre_version(void);

extern int
tre_config(int query, void *result);

extern int
tre_have_backrefs(const regex_t *preg);

extern int
tre_have_approx(const regex_t *preg);

#endif /* CLIB_TRE_PROTOS_H */