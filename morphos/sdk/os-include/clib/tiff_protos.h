#ifndef CLIB_TIFF_PROTOS_H
#define CLIB_TIFF_PROTOS_H

/*
	tiff.library C prototypes

	Copyright © 2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_TIFF_H
# include <libraries/tiff.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif

TIFF* TIFFOpenFH(BPTR, const char*);
void TIFFPrintDirectoryFH(TIFF*, BPTR, long);

const char* TIFFGetVersion(void);

const TIFFCodec* TIFFFindCODEC(uint16);
TIFFCodec* TIFFRegisterCODEC(uint16, const char*, TIFFInitMethod);
void TIFFUnRegisterCODEC(TIFFCodec*);
int TIFFIsCODECConfigured(uint16);
TIFFCodec* TIFFGetConfiguredCODECs(void);

tdata_t _TIFFmalloc(tsize_t);
tdata_t _TIFFrealloc(tdata_t, tsize_t);
void _TIFFmemset(tdata_t, int, tsize_t);
void _TIFFmemcpy(tdata_t, const tdata_t, tsize_t);
int _TIFFmemcmp(const tdata_t, const tdata_t, tsize_t);
void _TIFFfree(tdata_t);

void TIFFClose(TIFF*);
int TIFFFlush(TIFF*);
int TIFFFlushData(TIFF*);
int TIFFGetField(TIFF*, ttag_t, ...);
int TIFFVGetField(TIFF*, ttag_t, va_list);
int TIFFGetFieldDefaulted(TIFF*, ttag_t, ...);
int TIFFVGetFieldDefaulted(TIFF*, ttag_t, va_list);
int TIFFReadDirectory(TIFF*);
int TIFFReadCustomDirectory(TIFF*, toff_t, const TIFFFieldInfo[], size_t);
int TIFFReadEXIFDirectory(TIFF*, toff_t);
tsize_t TIFFScanlineSize(TIFF*);
tsize_t TIFFRasterScanlineSize(TIFF*);
tsize_t TIFFStripSize(TIFF*);
tsize_t TIFFRawStripSize(TIFF*, tstrip_t);
tsize_t TIFFVStripSize(TIFF*, uint32);
tsize_t TIFFTileRowSize(TIFF*);
tsize_t TIFFTileSize(TIFF*);
tsize_t TIFFVTileSize(TIFF*, uint32);
uint32 TIFFDefaultStripSize(TIFF*, uint32);
void TIFFDefaultTileSize(TIFF*, uint32*, uint32*);
int TIFFFileno(TIFF*);
int TIFFGetMode(TIFF*);
int TIFFIsTiled(TIFF*);
int TIFFIsByteSwapped(TIFF*);
int TIFFIsUpSampled(TIFF*);
int TIFFIsMSB2LSB(TIFF*);
uint32 TIFFCurrentRow(TIFF*);
tdir_t TIFFCurrentDirectory(TIFF*);
tdir_t TIFFNumberOfDirectories(TIFF*);
uint32 TIFFCurrentDirOffset(TIFF*);
tstrip_t TIFFCurrentStrip(TIFF*);
ttile_t TIFFCurrentTile(TIFF*);
int TIFFReadBufferSetup(TIFF*, tdata_t, tsize_t);
int TIFFWriteBufferSetup(TIFF*, tdata_t, tsize_t);
int TIFFSetupStrips(TIFF *);
int TIFFWriteCheck(TIFF*, int, const char *);
void TIFFFreeDirectory(TIFF*);
int TIFFCreateDirectory(TIFF*);
int TIFFLastDirectory(TIFF*);
int TIFFSetDirectory(TIFF*, tdir_t);
int TIFFSetSubDirectory(TIFF*, uint32);
int TIFFUnlinkDirectory(TIFF*, tdir_t);
int TIFFSetField(TIFF*, ttag_t, ...);
int TIFFVSetField(TIFF*, ttag_t, va_list);
int TIFFWriteDirectory(TIFF *);
int TIFFCheckpointDirectory(TIFF *);
int TIFFRewriteDirectory(TIFF *);
int TIFFReassignTagToIgnore(int, int);

int TIFFReadScanline(TIFF*, tdata_t, uint32, tsample_t);
int TIFFWriteScanline(TIFF*, tdata_t, uint32, tsample_t);
int TIFFReadRGBAImage(TIFF*, uint32, uint32, uint32*, int);
int TIFFReadRGBAImageOriented(TIFF*, uint32, uint32, uint32*, int, int);
int TIFFReadRGBAStrip(TIFF*, tstrip_t, uint32 *);
int TIFFReadRGBATile(TIFF*, uint32, uint32, uint32 *);
int TIFFRGBAImageOK(TIFF*, char [1024]);
int TIFFRGBAImageBegin(TIFFRGBAImage*, TIFF*, int, char [1024]);
int TIFFRGBAImageGet(TIFFRGBAImage*, uint32*, uint32, uint32);
void TIFFRGBAImageEnd(TIFFRGBAImage*);
TIFF* TIFFOpen(const char*, const char*);
TIFF* TIFFClientOpen(const char*, const char*, thandle_t, TIFFReadWriteProc, TIFFReadWriteProc, TIFFSeekProc, TIFFCloseProc, TIFFSizeProc, TIFFMapFileProc, TIFFUnmapFileProc);
const char* TIFFFileName(TIFF*);
void TIFFError(const char*, const char*, ...);
void TIFFErrorExt(thandle_t, const char*, const char*, ...);
void TIFFWarning(const char*, const char*, ...);
void TIFFWarningExt(thandle_t, const char*, const char*, ...);
TIFFErrorHandler TIFFSetErrorHandler(TIFFErrorHandler);
TIFFErrorHandlerExt TIFFSetErrorHandlerExt(TIFFErrorHandlerExt);
TIFFErrorHandler TIFFSetWarningHandler(TIFFErrorHandler);
TIFFErrorHandlerExt TIFFSetWarningHandlerExt(TIFFErrorHandlerExt);
TIFFExtendProc TIFFSetTagExtender(TIFFExtendProc);
ttile_t TIFFComputeTile(TIFF*, uint32, uint32, uint32, tsample_t);
int TIFFCheckTile(TIFF*, uint32, uint32, uint32, tsample_t);
ttile_t TIFFNumberOfTiles(TIFF*);
tsize_t TIFFReadTile(TIFF*, tdata_t, uint32, uint32, uint32, tsample_t);
tsize_t TIFFWriteTile(TIFF*, tdata_t, uint32, uint32, uint32, tsample_t);
tstrip_t TIFFComputeStrip(TIFF*, uint32, tsample_t);
tstrip_t TIFFNumberOfStrips(TIFF*);
tsize_t TIFFReadEncodedStrip(TIFF*, tstrip_t, tdata_t, tsize_t);
tsize_t TIFFReadRawStrip(TIFF*, tstrip_t, tdata_t, tsize_t);
tsize_t TIFFReadEncodedTile(TIFF*, ttile_t, tdata_t, tsize_t);
tsize_t TIFFReadRawTile(TIFF*, ttile_t, tdata_t, tsize_t);
tsize_t TIFFWriteEncodedStrip(TIFF*, tstrip_t, tdata_t, tsize_t);
tsize_t TIFFWriteRawStrip(TIFF*, tstrip_t, tdata_t, tsize_t);
tsize_t TIFFWriteEncodedTile(TIFF*, ttile_t, tdata_t, tsize_t);
tsize_t TIFFWriteRawTile(TIFF*, ttile_t, tdata_t, tsize_t);
int TIFFDataWidth(TIFFDataType);
void TIFFSetWriteOffset(TIFF*, toff_t);
void TIFFSwabShort(uint16*);
void TIFFSwabLong(uint32*);
void TIFFSwabDouble(double*);
void TIFFSwabArrayOfShort(uint16*tp, unsigned long n);
void TIFFSwabArrayOfTriples(uint8*tp, unsigned long n);
void TIFFSwabArrayOfLong(uint32*tp, unsigned long n);
void TIFFSwabArrayOfDouble(double*tp, unsigned long n);
void TIFFReverseBits(unsigned char *tp, unsigned long n);
const unsigned char* TIFFGetBitRevTable(int);

int  TIFFGetTagListCount(TIFF *);
ttag_t TIFFGetTagListEntry(TIFF *, int tag_index);
void TIFFMergeFieldInfo(TIFF*, const TIFFFieldInfo[], int);
const TIFFFieldInfo* TIFFFindFieldInfo(TIFF*, ttag_t, TIFFDataType);
const TIFFFieldInfo* TIFFFieldWithTag(TIFF*, ttag_t);
TIFFTagMethods *TIFFAccessTagMethods(TIFF *);
void *TIFFGetClientInfo(TIFF *, const char *);
void TIFFSetClientInfo(TIFF *, void *, const char *);

int TIFFCIELabToRGBInit(TIFFCIELabToRGB*, TIFFDisplay *, float*);
void TIFFCIELabToXYZ(TIFFCIELabToRGB *, uint32, int32, int32, float *, float *, float *);
void TIFFXYZToRGB(TIFFCIELabToRGB *, float, float, float, uint32 *, uint32 *, uint32 *);
int TIFFYCbCrToRGBInit(TIFFYCbCrToRGB*, float*, float*);
void TIFFYCbCrtoRGB(TIFFYCbCrToRGB *, uint32, int32, int32, uint32 *, uint32 *, uint32 *);

void TIFFCleanup(TIFF*);
int TIFFSetFileno(TIFF*, int);
thandle_t TIFFClientdata(TIFF*);
thandle_t TIFFSetClientdata(TIFF*, thandle_t);
int TIFFSetMode(TIFF*, int);
int TIFFIsBigEndian(TIFF*);
TIFFReadWriteProc TIFFGetReadProc(TIFF*);
TIFFReadWriteProc TIFFGetWriteProc(TIFF*);
TIFFSeekProc TIFFGetSeekProc(TIFF*);
TIFFCloseProc TIFFGetCloseProc(TIFF*);
TIFFSizeProc TIFFGetSizeProc(TIFF*);
TIFFMapFileProc TIFFGetMapFileProc(TIFF*);
TIFFUnmapFileProc TIFFGetUnmapFileProc(TIFF*);
const char *TIFFSetFileName(TIFF*, const char *);
const TIFFFieldInfo *TIFFFindFieldInfoByName(TIFF* , const char *, TIFFDataType);
const TIFFFieldInfo *TIFFFieldWithName(TIFF*, const char *);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_TIFF_PROTOS_H */
