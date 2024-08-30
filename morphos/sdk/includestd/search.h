#ifndef _SEARCH_H
#define _SEARCH_H

/* search.h -- declarations for POSIX/SVID-compatible search functions */

/* HSEARCH(3C) */
typedef struct entry { char *key, *data; } ENTRY;
typedef enum { FIND, ENTER } ACTION;

/* TSEARCH(3C) */
typedef enum { preorder, postorder, endorder, leaf } VISIT;

#include <sys/types.h>
#include <sys/cdefs.h>

__BEGIN_DECLS
void *lfind __P((const void *, const void *, size_t *, size_t, int (*comp)(const void *, const void *)));
void *lsearch __P((const void *, void *, size_t *, size_t, int (*comp)(const void *, const void *)));
__END_DECLS

#endif /* _SEARCH_H */
