#ifndef	_FNMATCH_H_
#define	_FNMATCH_H_

#define	FNM_NOMATCH	1	/* Match failed. */
#define	FNM_NOSYS	2	/* Function not supported (unused). */

#define	FNM_NOESCAPE	0x01	/* Disable backslash escaping. */
#define	FNM_PATHNAME	0x02	/* Slash must be matched by slash. */
#define	FNM_PERIOD	0x04	/* Period must be matched by period. */

// ignore the case
#define	FNM_LEADING_DIR	0x08	/* Ignore /<tail> after Imatch. */
#define	FNM_CASEFOLD	0x10	/* Case insensitive search. */
#define	FNM_IGNORECASE	FNM_CASEFOLD
#define	FNM_FILE_NAME	FNM_PATHNAME

// The following shall be declared as a function and may also be defined as a macro. A function prototype shall be provided.
__stdargs	int fnmatch(const char *, const char *, int);

#endif // _FNMATCH_H_
