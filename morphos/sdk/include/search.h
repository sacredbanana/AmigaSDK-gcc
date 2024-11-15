#ifndef _SEARCH_H_
#define _SEARCH_H_

/* search.h -- declarations for POSIX/SVID-compatible search functions */

/* HSEARCH(3C) */
typedef struct entry { char *key, *data; } ENTRY;
typedef enum { FIND, ENTER } ACTION;

/* TSEARCH(3C) */
typedef enum { preorder, postorder, endorder, leaf } VISIT;

#endif /* _SEARCH_H_ */
