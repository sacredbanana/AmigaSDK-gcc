#ifndef CLIB_VORBISFILE_PROTOS_H
#define CLIB_VORBISFILE_PROTOS_H

#include <exec/types.h>
#include <exec/semaphores.h>
#include <dos/dos.h>

#include <libraries/vorbisfile.h>
#include <utility/hooks.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/***************************/
/* vorbisfile              */

int ov_clear(OggVorbis_File *vf);
int ov_fopen(char *path,OggVorbis_File *vf);
int ov_open(BPTR f,OggVorbis_File *vf,char *initial,long ibytes);
int ov_open_callbacks(void *datasource, OggVorbis_File *vf, char *initial, long ibytes, ov_callbacks *callbacks);
int ov_test(BPTR f,OggVorbis_File *vf,char *initial,long ibytes);
int ov_test_callbacks(void *datasource, OggVorbis_File *vf, char *initial, long ibytes, ov_callbacks *callbacks);
int ov_test_open(OggVorbis_File *vf);

long ov_bitrate(OggVorbis_File *vf,int i);
long ov_bitrate_instant(OggVorbis_File *vf);
long ov_seekable(OggVorbis_File *vf);
long ov_serialnumber(OggVorbis_File *vf,int i);

ogg_int64_t ov_raw_total(OggVorbis_File *vf,int i);
ogg_int64_t ov_pcm_total(OggVorbis_File *vf,int i);
double ov_time_total(OggVorbis_File *vf,int i);

int ov_raw_seek(OggVorbis_File *vf,ogg_int64_t pos);
int ov_pcm_seek(OggVorbis_File *vf,ogg_int64_t pos);
int ov_pcm_seek_page(OggVorbis_File *vf,ogg_int64_t pos);
int ov_time_seek(OggVorbis_File *vf,double pos);
int ov_time_seek_page(OggVorbis_File *vf, double pos);

ogg_int64_t ov_raw_tell(OggVorbis_File *vf);
ogg_int64_t ov_pcm_tell(OggVorbis_File *vf);
double ov_time_tell(OggVorbis_File *vf);

vorbis_info *ov_info(OggVorbis_File *vf,int link);
vorbis_comment *ov_comment(OggVorbis_File *vf,int link);

long ov_read(OggVorbis_File *vf,char *buffer,int length, int bigendianp,int word,int sgned,int *bitstream);
long ov_read_float(OggVorbis_File *vf,float ***pcm_channels,int length, int *bitstream);
long ov_streams(OggVorbis_File *vf);

/********************************/
/* vorbisenc                    */

int vorbis_encode_init(vorbis_info *vi, long channels, long rate, long max_bitrate, long nominal_bitrate, long min_bitrate);
int vorbis_encode_setup_managed(vorbis_info *vi, long channels, long rate, long max_bitrate, long nominal_bitrate, long min_bitrate);
int vorbis_encode_setup_vbr(vorbis_info *vi, long channels, long rate, float quality);
int vorbis_encode_init_vbr(vorbis_info *vi, long channels, long rate, float base_quality);
int vorbis_encode_setup_init(vorbis_info *vi);
int vorbis_encode_ctl(vorbis_info *vi,int number,void *arg);

/******************************/
/* required for enc too       */

void vorbis_info_init(vorbis_info *vi);
void vorbis_info_clear(vorbis_info *vi);

void vorbis_comment_init(vorbis_comment *vc);
void vorbis_comment_add_tag(vorbis_comment *vc, const char *tag, const char *contents);
void vorbis_comment_clear(vorbis_comment *vc);

int vorbis_analysis_init(vorbis_dsp_state *v,vorbis_info *vi);
int vorbis_analysis_headerout(vorbis_dsp_state *v, vorbis_comment *vc, ogg_packet *op, ogg_packet *op_comm, ogg_packet *op_code);
float **vorbis_analysis_buffer(vorbis_dsp_state *v,int vals);
int vorbis_analysis_wrote(vorbis_dsp_state *v,int vals);
int vorbis_analysis_blockout(vorbis_dsp_state *v,vorbis_block *vb);
int vorbis_analysis(vorbis_block *vb,ogg_packet *op);

int vorbis_synthesis_idheader(ogg_packet *op);
int vorbis_synthesis_headerin(vorbis_info *vi, vorbis_comment *vc, ogg_packet *op);
int vorbis_synthesis_init(vorbis_dsp_state *v, vorbis_info *vi);
int vorbis_synthesis_restart(vorbis_dsp_state *v);
int vorbis_synthesis(vorbis_block *vb, ogg_packet *op);
int vorbis_synthesis_trackonly(vorbis_block *vb, ogg_packet *op);
int vorbis_synthesis_blockin(vorbis_dsp_state *v, vorbis_block *vb);
int vorbis_synthesis_pcmout(vorbis_dsp_state *v, float ***pcm);
int vorbis_synthesis_lapout(vorbis_dsp_state *v, float ***pcm);
int vorbis_synthesis_read(vorbis_dsp_state *v, int samples);
long vorbis_packet_blocksize(vorbis_info *vi, ogg_packet *op);
int vorbis_synthesis_halfrate(vorbis_info *v,int flag);
int vorbis_synthesis_halfrate_p(vorbis_info *v);




int vorbis_block_init(vorbis_dsp_state *v, vorbis_block *vb);
int vorbis_block_clear(vorbis_block *vb);
void vorbis_dsp_clear(vorbis_dsp_state *v);

int ogg_stream_init(ogg_stream_state *os,int serialno);
int ogg_stream_packetin(ogg_stream_state *os, ogg_packet *op);
int ogg_stream_packetout(ogg_stream_state *os,ogg_packet *op);
int ogg_stream_packetpeek(ogg_stream_state *os, ogg_packet *op);
int ogg_stream_pagein(ogg_stream_state *os, ogg_page *og);
int ogg_stream_pageout(ogg_stream_state *os, ogg_page *og);
int ogg_stream_flush(ogg_stream_state *os, ogg_page *og);
int ogg_stream_clear(ogg_stream_state *os);

int vorbis_bitrate_addblock(vorbis_block *vb);
int vorbis_bitrate_flushpacket(vorbis_dsp_state *vd, ogg_packet *op);

void ogg_page_checksum_set(ogg_page *og);
int ogg_page_version(const ogg_page *og);
int ogg_page_continued(const ogg_page *og);
int ogg_page_bos(const ogg_page *og);
int ogg_page_eos(const ogg_page *og);
ogg_int64_t ogg_page_granulepos(const ogg_page *og);
int ogg_page_serialno(const ogg_page *og);
long ogg_page_pageno(const ogg_page *og);
int ogg_page_packets(const ogg_page *og);

int ogg_sync_init(ogg_sync_state *oy);
int ogg_sync_clear(ogg_sync_state *oy);
int ogg_sync_reset(ogg_sync_state *oy);
char *ogg_sync_buffer(ogg_sync_state *oy, long size);
int ogg_sync_wrote(ogg_sync_state *oy, long bytes);
long ogg_sync_pageseek(ogg_sync_state *oy, ogg_page *og);
int ogg_sync_pageout(ogg_sync_state *oy, ogg_page *og);

int ogg_stream_reset(ogg_stream_state *os);
int ogg_stream_reset_serialno(ogg_stream_state *os, int serialno);
int ogg_stream_eos(ogg_stream_state *os);

int vorbis_info_blocksize(vorbis_info *vi, int zo);

void vorbis_comment_add(vorbis_comment *vc, const char *comment); 
char *vorbis_comment_query(vorbis_comment *vc, const char *tag, int count);
int vorbis_comment_query_count(vorbis_comment *vc, const char *tag);
int vorbis_commentheader_out(vorbis_comment *vc, ogg_packet *op);

double vorbis_granule_time(vorbis_dsp_state *v, ogg_int64_t granulepos);

int ov_raw_seek_lap(OggVorbis_File *vf, ogg_int64_t pos);
int ov_pcm_seek_lap(OggVorbis_File *vf, ogg_int64_t pos);
int ov_pcm_seek_page_lap(OggVorbis_File *vf, ogg_int64_t pos);
int ov_time_seek_lap(OggVorbis_File *vf, double pos);
int ov_time_seek_page_lap(OggVorbis_File *vf, double pos);

int ov_crosslap(OggVorbis_File *vf1, OggVorbis_File *vf2);

int ov_halfrate(OggVorbis_File *vf, int flag);
int ov_halfrate_p(OggVorbis_File *vf);


const char *vorbis_version_string(void);

int ogg_stream_iovecin(ogg_stream_state *os, ogg_iovec_t *iov, int count, long e_o_s, ogg_int64_t granulepos);
int ogg_sync_check(ogg_sync_state *oy);
int ogg_stream_check(ogg_stream_state *os);

long ov_read_filter(OggVorbis_File *vf,char *buffer,int length,int bigendianp,int word,int sgned,int *bitstream,void (*filter)(float **pcm,long channels,long samples,void *filter_param),void *filter_param);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_VORBISFILE_PROTOS_H */
