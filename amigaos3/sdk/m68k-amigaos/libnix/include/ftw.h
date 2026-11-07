#ifndef _FTW_H
#define _FTW_H

#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Values of the type argument passed to the callback.  */
#define FTW_F	0	/* File.  */
#define FTW_D	1	/* Directory.  */
#define FTW_DNR	2	/* Directory without read permission.  */
#define FTW_DP	3	/* Directory with subdirectories visited.  */
#define FTW_NS	4	/* stat() failed.  */
#define FTW_SL	5	/* Symbolic link.  */
#define FTW_SLN	6	/* Symbolic link that names a nonexistent file.  */

/* Flags for nftw().  */
#define FTW_PHYS	0x01	/* Do not follow symbolic links.  */
#define FTW_MOUNT	0x02	/* Do not cross a mount point.  */
#define FTW_DEPTH	0x04	/* Visit subdirectories before the directory.  */
#define FTW_CHDIR	0x08	/* Change to each directory (ignored).  */

struct FTW {
	int base;
	int level;
};

__stdargs int ftw(const char *, __stdargs int (*)(const char *, const struct stat *, int), int);
__stdargs int nftw(const char *, __stdargs int (*)(const char *, const struct stat *, int, struct FTW *), int, int);

#ifdef __cplusplus
}
#endif

#endif /* _FTW_H */
