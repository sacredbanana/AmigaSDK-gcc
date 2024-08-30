#ifndef CLIB_Z_PROTOS_H
#define CLIB_Z_PROTOS_H

/*
	z.library C prototypes

	Copyright © 2003-2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_Z_H
# include <libraries/z.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

const char *zlibVersion(void);

int deflate(z_streamp strm, int flush);
int deflateEnd(z_streamp strm);

int inflate(z_streamp strm, int flush);
int inflateEnd(z_streamp strm);

int deflateSetDictionary(z_streamp strm, const Bytef *dictionary, uInt  dictLength);
int deflateCopy(z_streamp dest, z_streamp source);
int deflateReset(z_streamp strm);
int deflateParams(z_streamp strm,int level,int strategy);
int deflateTune(z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain);
int deflateSetHeader(z_streamp strm, gz_headerp head);

int inflateSetDictionary(z_streamp strm, const Bytef *dictionary, uInt  dictLength);
int inflateGetDictionary(z_streamp strm, Bytef *dictionary, uInt  *dictLength);
int inflateSync(z_streamp strm);
int inflateReset(z_streamp strm);
int inflateReset2(z_streamp strm, int windowBits);
int inflatePrime(z_streamp strm, int bits, int value);
long inflateMark (z_streamp strm);
int inflateGetHeader(z_streamp strm, gz_headerp head);

int compress(Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen);
int compress2(Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen, int level);
int uncompress(Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen);

int deflateInit_(z_streamp strm, int level,  const char *version, int stream_size);
int inflateInit_(z_streamp strm, const char *version, int stream_size);
int deflateInit2_(z_streamp strm, int level, int method, int windowBits, int memLevel, int strategy, const char *version, int stream_size);
int inflateInit2_(z_streamp strm, int windowBits, const char *version, int stream_size);

#define deflateInit(strm, level)	deflateInit_((strm),(level),ZLIB_VERSION,sizeof(z_stream))
#define inflateInit(strm)	inflateInit_((strm),ZLIB_VERSION,sizeof(z_stream))
#define deflateInit2(strm,level,method,windowBits,memLevel,strategy)	deflateInit2_((strm),(level),(method),(windowBits),(memLevel),(strategy),ZLIB_VERSION,sizeof(z_stream))
#define inflateInit2(strm,windowBits)	inflateInit2_((strm),(windowBits),ZLIB_VERSION,sizeof(z_stream))

uLong adler32(uLong adler, const Bytef *buf, uInt len);
uLong adler32_combine(uLong adler1, uLong adler2, z_off_t len2);
uLong crc32(uLong crc, const Bytef *buf, uInt len);
uLong crc32_combine(uLong crc1, uLong crc2, z_off_t len2);
gzFile gzopen64(const char *path, const char *mode);
z_off64_t gzseek64(gzFile file, z_off64_t offset, int whence);
z_off64_t gztell64(gzFile file);
z_off64_t gzoffset64(gzFile file);
uLong adler32_combine64(uLong adler1, uLong adler2, z_off64_t len2);
uLong crc32_combine64(uLong crc1, uLong crc2, z_off64_t len2);

const char *zError(int err);
int inflateSyncPoint(z_streamp strm);
const z_crc_t *get_crc_table(void);
int inflateUndermine(z_streamp strm, int subvert);
int inflateResetKeep(z_streamp strm);
int deflateResetKeep(z_streamp strm);
unsigned long gzflags(void);
uLong zlibCompileFlags(void);

int inflateCopy(z_streamp dest, z_streamp source);

int inflateBackInit_(z_streamp strm, int windowBits, unsigned char *window, const char *version, int stream_size);
int inflateBack(z_streamp strm, in_func in, void *in_desc, out_func out, void *out_desc);
int inflateBackEnd(z_streamp strm);

#define inflateBackInit(strm,windowBits,window)	inflateBackInit_((strm),(windowBits),(window),ZLIB_VERSION,sizeof(z_stream))

uLong compressBound(uLong sourceLen);
uLong deflateBound(z_streamp strm, uLong sourceLen);
int deflatePrime(z_streamp strm,int bits,int value);
int deflatePending(z_streamp strm, unsigned *pending, int *bits);

gzFile gzopen(const char *path, const char *mode);
gzFile gzdopen(int fd, const char *mode);
int gzbuffer(gzFile file, unsigned size);
int gzsetparams(gzFile file, int level, int strategy);
int gzread (gzFile file, voidp buf, unsigned len);
int gzwrite(gzFile file, const voidp buf, unsigned len);
int gzprintf(gzFile file, const char *format, ...);
int gzputs(gzFile file, const char *s);
char * gzgets(gzFile file, char *buf, int len);
int gzputc(gzFile file, int c);
int gzgetc(gzFile file);
int gzflush(gzFile file, int flush);
z_off_t gzseek(gzFile file, z_off_t offset, int whence);
int gzrewind(gzFile file);
z_off_t gztell(gzFile file);
z_off_t gzoffset(gzFile file);
int gzeof(gzFile file);
int gzclose(gzFile file);
int gzclose_r(gzFile file);
int gzclose_w(gzFile file);
const char * gzerror(gzFile file, int *errnum);
int gzdirect(gzFile file);


int blast(blast_in infun, void *inhow, blast_out outfun, void *outhow);

int inflateBack9(z_streamp strm,in_func in, void *in_desc, out_func out, void *out_desc);
int inflateBack9End(z_streamp strm);
int inflateBack9Init_(z_streamp strm, unsigned char *window, const char *version, int stream_size);

#define inflateBack9Init(strm, window)	inflateBack9Init_((strm), (window), ZLIB_VERSION, sizeof(z_stream))


int deflateGetDictionary(z_streamp strm, Bytef *dictionary, uInt  *dictLength);
int uncompress2(Bytef *dest, uLongf *destLen, const Bytef *source, uLong *sourceLen);
#define adler32_z(a,b,l) adler32(a,b,(uInt)(l))
#define crc32_z(a,b,l) crc32(a,b,(uInt)(l))
int inflateValidate(z_streamp strm, int check);
unsigned long inflateCodesUsed(z_streamp strm);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_Z_PROTOS_H */
