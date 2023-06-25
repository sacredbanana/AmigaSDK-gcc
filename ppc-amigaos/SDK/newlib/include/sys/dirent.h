#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

#include <sys/types.h>

/****************************************************************************/

#define	MAXNAMLEN 255

struct dirent
{
   ino_t          d_ino;
   unsigned short d_reclen;
   unsigned char  d_type;
   unsigned char  d_namlen;
   char	          d_name[MAXNAMLEN + 1];
};
#define d_fileno d_ino

struct __dir
{
   unsigned long numentries;
   unsigned long allocatedentries;
   unsigned long currententry;
   struct dirent *entries;
};
typedef struct __dir DIR;

/*
 * File types
 */
#define	DT_UNKNOWN	 0
#define	DT_FIFO		 1
#define	DT_CHR		 2
#define	DT_DIR		 4
#define	DT_BLK		 6
#define	DT_REG		 8
#define	DT_LNK		10
#define	DT_SOCK		12
#define	DT_WHT		14

/*
 * Convert between stat structure types and directory types.
 */
#define	IFTODT(mode)	(((mode) & 0170000) >> 12)
#define	DTTOIF(dirtype)	((dirtype) << 12)

extern DIR *opendir(const char *);
extern struct dirent * readdir(DIR * directory_pointer);
extern void rewinddir(DIR *);
extern int closedir(DIR *);
extern void seekdir(DIR *, long);
extern long telldir(DIR *);

extern int scandir(const char *dirname, struct dirent ***namelist, int (*_select)(struct dirent *), int (*_compar)(const void *, const void *));
extern int alphasort(const void *d1, const void *d2);

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _SYS_DIRENT_H */
