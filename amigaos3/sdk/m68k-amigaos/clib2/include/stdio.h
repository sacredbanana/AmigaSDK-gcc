/*
 * $Id: stdio.h,v 1.24 2010-10-20 13:12:59 obarthel Exp $
 *
 * :ts=4
 *
 * Portable ISO 'C' (1994) runtime library for the Amiga computer
 * Copyright (c) 2002-2015 by Olaf Barthel <obarthel (at) gmx.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Neither the name of Olaf Barthel nor the names of contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************
 *
 * Documentation and source code for this library, and the most recent library
 * build are available from <http://sourceforge.net/projects/clib2>.
 *
 *****************************************************************************
 */

#ifndef _STDIO_H
#define _STDIO_H

/****************************************************************************/

#ifndef _STDDEF_H
#include <stddef.h>
#endif /* _STDDEF_H */

#ifndef _STDARG_H
#include <stdarg.h>
#endif /* _STDARG_H */

#ifndef _LIMITS_H
#include <limits.h>
#endif /* _LIMITS_H */

#ifndef _SYS_TYPES_H
#include <sys/types.h>
#endif /* _SYS_TYPES_H */

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

/* 'End of file' indicator returned by, for example, fgetc() */
#define EOF (-1)

/****************************************************************************/

/*
 * Maximum number of files that can be open at a time. This number does not
 * correspond to a real limitation for this 'C' runtime library and is
 * included solely for ISO 'C' (1994) compliance.
 */
#define FOPEN_MAX 64

/****************************************************************************/

/* Maximum size of a file/path name. */
#define FILENAME_MAX 256

/****************************************************************************/

/* Default size for all standard I/O file buffers. */
#define BUFSIZ 8192

/****************************************************************************/

/* File buffering modes for use with setvbuf() */

#define _IOFBF 0	/* Full buffering (flush when buffer is full) */

#define _IOLBF 1	/* Line buffering (flush when buffer is full or when
					   a line feed character is written) */

#define _IONBF 2	/* Perform no buffering at all */

/****************************************************************************/

/* Positioning modes for use with fseek() */

#define SEEK_SET 0	/* New position is absolute */
#define SEEK_CUR 1	/* New position is relative to current file position */
#define SEEK_END 2	/* New position is relative to end of file */

/****************************************************************************/

/* Used by fgetpos() and fsetpos() */

#if defined(__GNUC__)
typedef long long fpos_t;
#else
typedef long fpos_t;
#endif /* __GNUC__ */

/****************************************************************************/

/*
 * This is part of the internal 'FILE' structure; this is guaranteed not to
 * change in future library releases. However, the private portion of this
 * data structure may change.
 */
typedef struct __FILE
{
	long			position;			/* Current buffer position, which is
										   usually a number between 0 and
										   size-1 */
	long			num_read_bytes;		/* How many bytes can be read from
										   the buffer; this can be 0! */
	long			num_write_bytes;	/* How many bytes have been copied
										   to the buffer which have not been
										   written back yet; this can be 0! */
	unsigned short	flags;				/* See below for some of the public
										   flag bits defined; this is by no
										   means a complete list, though! */
	short _file;
	unsigned char *	buffer;				/* Points to the first byte of the
										   buffer; this could be NULL! */
	long			size;				/* How many bytes will fit into the
										   buffer; this could be 0! */

	/* Private fields follow... */
} FILE;

/****************************************************************************/

/* Field and flag definitions for the getc/putc macros below. */
#define __FILE_BUFFER_MASK	3		/* Masks off the buffering mode */
#define __FILE_EOF			0x20	/* (1<<2)	/ * EOF reached */
#define __FILE_READABLE		0x04	/* (1<<3)	/ * File is readable */
#define __FILE_WRITABLE		0x08	/* (1<<4)	/ * File is writable */
#define __FILE_IN_USE		0x800	/* (1<<5)	/ * File is in use */
#define __FILE_ERROR		0x40	/* (1<<6)	/ * Error detected */

/****************************************************************************/

/*
 * Maximum file name buffer size for use with tmpfile() and tmpnam();
 * note that the maximum file name length is shorter by one character
 */
#define L_tmpnam 10

/* Maximum number of unique file names tmpnam() can generate */
#define TMP_MAX 0x40000

/****************************************************************************/

/* Anchor for the buffered standard I/O streams */
extern struct iob ** __iob;

/****************************************************************************/

/* The three standard I/O streams */
#define stdin	((FILE *)__iob[0])
#define stdout	((FILE *)__iob[1])
#define stderr	((FILE *)__iob[2])

/****************************************************************************/

extern __stdargs void perror(const char * s);

/****************************************************************************/

extern __stdargs FILE *fopen(const char *filename, const char *mode);
extern __stdargs int fclose(FILE *stream);
extern __stdargs int fflush(FILE *stream);
extern __stdargs FILE *freopen(const char *filename, const char *mode, FILE *stream);
extern __stdargs int setvbuf(FILE *stream,char *buf,int bufmode,size_t size);
extern __stdargs void setbuf(FILE *stream, char *buf);

/****************************************************************************/

extern __stdargs int fseek(FILE *stream, long int offset, int wherefrom);
extern __stdargs long int ftell(FILE *stream);
extern __stdargs void rewind(FILE *stream);
extern __stdargs int fgetpos(FILE *stream, fpos_t *pos);
extern __stdargs int fsetpos(FILE *stream, fpos_t *pos);

/****************************************************************************/

extern __stdargs int fgetc(FILE *stream);
extern __stdargs int getc(FILE *stream);
extern __stdargs int getchar(void);
extern __stdargs int ungetc(int c,FILE *stream);

/****************************************************************************/

extern __stdargs int fputc(int c,FILE *stream);
extern __stdargs int putc(int c,FILE *stream);
extern __stdargs int putchar(int c);

/****************************************************************************/

extern __stdargs char *fgets(char *s,int n,FILE *stream);
extern __stdargs char *gets(char *s);

/****************************************************************************/

extern __stdargs int fscanf(FILE *stream, const char *format, ...);
extern __stdargs int scanf(const char *format, ...);
extern __stdargs int sscanf(const char *s,const char *format, ...);

/****************************************************************************/

extern __stdargs int fputs(const char *s, FILE *stream);
extern __stdargs int puts(const char *s);

/****************************************************************************/

extern __stdargs int fprintf(FILE *stream,const char *format,...);
extern __stdargs int printf(const char *format, ...);
extern __stdargs int sprintf(char *s, const char *format, ...);

/****************************************************************************/

extern __stdargs int vfprintf(FILE *stream,const char *format,va_list arg);
extern __stdargs int vprintf(const char *format,va_list arg);
extern __stdargs int vsprintf(char *s, const char *format,va_list arg);

/****************************************************************************/

extern __stdargs size_t fread(void *ptr,size_t element_size,size_t count,FILE *stream);
extern __stdargs size_t fwrite(const void *ptr,size_t element_size,size_t count,FILE *stream);

/****************************************************************************/

extern __stdargs int feof(FILE *stream);
extern __stdargs int ferror(FILE *stream);
extern __stdargs void clearerr(FILE *stream);

/****************************************************************************/

extern __stdargs int rename(const char *oldname,const char *newname);
extern __stdargs int remove(const char *filename);

/****************************************************************************/

extern __stdargs FILE *tmpfile(void);
extern __stdargs char *tmpnam(char *buf);

/****************************************************************************/

/*
 * fgetc() implemented as a "simple" macro; note that fgetc() does much more than
 * can be conveniently expressed as a macro!
 */
#define __getc_unlocked(f) \
	(((((FILE *)(f))->flags & (__FILE_IN_USE|__FILE_READABLE|__FILE_EOF)) == (__FILE_IN_USE|__FILE_READABLE) && \
	 (((FILE *)(f))->flags & __FILE_BUFFER_MASK) != _IONBF && \
	 ((FILE *)(f))->position < ((FILE *)(f))->num_read_bytes) ? \
	    ((FILE *)(f))->buffer[((FILE *)(f))->position++] : \
	    fgetc(f))

/****************************************************************************/

/*
 * fputc() implemented as a "simple" macro; note that fputc() does much more than
 * can be conveniently expressed as a macro!
 */
#define __putc_unlocked(c,f) \
	(((((FILE *)(f))->flags & (__FILE_IN_USE|__FILE_WRITABLE)) == (__FILE_IN_USE|__FILE_WRITABLE) && \
	 (((FILE *)(f))->flags & __FILE_BUFFER_MASK) != _IONBF && \
	 (((FILE *)(f))->num_write_bytes < ((FILE *)(f))->size)) ? \
	  (((FILE *)(f))->buffer[((FILE *)(f))->num_write_bytes] = (c), \
	  (((((FILE *)(f))->flags & __FILE_BUFFER_MASK) == _IOLBF && \
	  ((FILE *)(f))->buffer[((FILE *)(f))->num_write_bytes] == '\n') ? \
	   ((FILE *)(f))->num_write_bytes++, __flush(f) : \
	   ((FILE *)(f))->buffer[((FILE *)(f))->num_write_bytes++])) : \
	   fputc((c),(f)))

/****************************************************************************/

#if defined(__THREAD_SAFE)

#define getc(f)		(flockfile(f), __unlockfile((f),__getc_unlocked(f)))
#define putc(c,f)	(flockfile(f), __unlockfile((f),__putc_unlocked((c),(f))))

#else

#define getc(f)		__getc_unlocked(f)
#define putc(c,f)	__putc_unlocked((c),(f))

#endif /* __THREAD_SAFE */

/****************************************************************************/

#define getchar()	getc(stdin)
#define putchar(c)	putc((c),stdout)

/****************************************************************************/

/*
 * If requested, reimplement some of the file I/O routines as macros.
 */

#ifdef __C_MACROS__

/****************************************************************************/

#if defined(__THREAD_SAFE)

/****************************************************************************/

#define clearerr(file)	((void)(flockfile(file), (file)->flags &= ~(__FILE_EOF|__FILE_ERROR), funlockfile(file)))
#define feof(file)		(flockfile(file), __unlockfile((file),((file)->flags & __FILE_EOF) != 0))
#define ferror(file)	(flockfile(file), __unlockfile((file),((file)->flags & __FILE_ERROR) != 0))

/****************************************************************************/

#else

/****************************************************************************/

#define clearerr(file)	((void)((file)->flags &= ~(__FILE_EOF|__FILE_ERROR)))
#define feof(file)		(((file)->flags & __FILE_EOF) != 0)
#define ferror(file)	(((file)->flags & __FILE_ERROR) != 0)

/****************************************************************************/

#endif /* __THREAD_SAFE */

/****************************************************************************/

#endif /* __C_MACROS__ */

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

/****************************************************************************/

#define MAXPATHLEN PATH_MAX

/****************************************************************************/

#define L_ctermid 32

/****************************************************************************/

extern __stdargs char *ctermid(char *);

/****************************************************************************/

/*
 * A special buffer flush routine which returns the last character written
 * in case of success and EOF in case of failure. This is used by the
 * __putc_unlocked() macro defined above.
 */
extern __stdargs int __flush(FILE *stream);

/****************************************************************************/

/*
 * A special function which returns the input character. This is used by
 * the __getc_unlocked() macro defined above.
 */
extern __stdargs int __unlockfile(FILE *stream,int c);

/****************************************************************************/

extern __stdargs int getc_unlocked(FILE *stream);
extern __stdargs int getchar_unlocked(void);
extern __stdargs int putc_unlocked(int c,FILE *stream);
extern __stdargs int putchar_unlocked(int c);

/****************************************************************************/

#define getc_unlocked(f)	__getc_unlocked(f)
#define putc_unlocked(c,f)	__putc_unlocked((c),(f))

#define getchar_unlocked()	__getc_unlocked(stdin)
#define putchar_unlocked(c)	__putc_unlocked((c),stdout)

/****************************************************************************/

extern __stdargs FILE * fdopen(int file_descriptor, const char * type);
extern __stdargs int fileno(FILE * file);
extern __stdargs int asprintf(char **ret, const char *format, ...);
extern __stdargs int vsnprintf(char *s,size_t size,const char *format,va_list arg);
extern __stdargs int pclose(FILE *stream);
extern __stdargs FILE * popen(const char *command, const char *type);
extern __stdargs int fseeko(FILE *stream, off_t offset, int wherefrom);
extern __stdargs off_t ftello(FILE *stream);

/****************************************************************************/

#if defined(__THREAD_SAFE)

/****************************************************************************/

extern __stdargs void flockfile(FILE * file);
extern __stdargs void funlockfile(FILE * file);
extern __stdargs int ftrylockfile(FILE * file);

/****************************************************************************/

#else

/****************************************************************************/

#define flockfile(file)		((void)0)
#define funlockfile(file)	((void)0)
#define ftrylockfile(file)	(0)

/****************************************************************************/

#endif /* __THREAD_SAFE */

/****************************************************************************/

extern __stdargs int vasprintf(char **ret,const char *format,va_list arg);

#ifdef __MEM_DEBUG
extern __stdargs int __vasprintf(const char *file,int line,char **ret,const char *format,va_list arg);

#define vasprintf(ret,format,arg) __vasprintf(__FILE__,__LINE__,(ret),(format),(arg))
#endif /* __MEM_DEBUG */

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard, but it should
   be part of ISO/IEC 9899:1999, also known as "C99". */

/****************************************************************************/

extern __stdargs int vfscanf(FILE *stream, const char *format, va_list arg);
extern __stdargs int vsscanf(const char *s, const char *format, va_list arg);
extern __stdargs int vscanf(const char *format,va_list arg);
extern __stdargs int snprintf(char *s,size_t size,const char *format,...);

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _STDIO_H */
