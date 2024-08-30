/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_VORBISFILE_H
#define _PPCINLINE_VORBISFILE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef VORBISFILE_BASE_NAME
#define VORBISFILE_BASE_NAME VorbisFileBase
#endif /* !VORBISFILE_BASE_NAME */

#define vorbis_comment_query(__p0, __p1, __p2) \
	(((char *(*)(vorbis_comment *, const char *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 562))(__p0, __p1, __p2))

#define ov_pcm_seek_page(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 118))(__p0, __p1))

#define ogg_stream_clear(__p0) \
	(((int (*)(ogg_stream_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 418))(__p0))

#define vorbis_synthesis_read(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 334))(__p0, __p1))

#define vorbis_dsp_clear(__p0) \
	(((void (*)(vorbis_dsp_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 370))(__p0))

#define ogg_sync_reset(__p0) \
	(((int (*)(ogg_sync_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 502))(__p0))

#define ogg_stream_packetpeek(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 394))(__p0, __p1))

#define ov_info(__p0, __p1) \
	(((vorbis_info *(*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 154))(__p0, __p1))

#define ov_raw_seek(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 106))(__p0, __p1))

#define ov_fopen(__p0, __p1) \
	(((int (*)(char *, OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 634))(__p0, __p1))

#define vorbis_analysis_buffer(__p0, __p1) \
	(((float **(*)(vorbis_dsp_state *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 262))(__p0, __p1))

#define ov_time_seek_lap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, double ))*(void**)((long)(VORBISFILE_BASE_NAME) - 604))(__p0, __p1))

#define ogg_stream_eos(__p0) \
	(((int (*)(ogg_stream_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 544))(__p0))

#define vorbis_comment_clear(__p0) \
	(((void (*)(vorbis_comment *))*(void**)((long)(VORBISFILE_BASE_NAME) - 244))(__p0))

#define ov_crosslap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 616))(__p0, __p1))

#define vorbis_info_blocksize(__p0, __p1) \
	(((int (*)(vorbis_info *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 550))(__p0, __p1))

#define ogg_sync_check(__p0) \
	(((int (*)(ogg_sync_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 658))(__p0))

#define ov_time_total(__p0, __p1) \
	(((double (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 100))(__p0, __p1))

#define vorbis_info_init(__p0) \
	(((void (*)(vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 220))(__p0))

#define ov_bitrate(__p0, __p1) \
	(((long (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 64))(__p0, __p1))

#define ov_pcm_seek_lap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 592))(__p0, __p1))

#define vorbis_analysis(__p0, __p1) \
	(((int (*)(vorbis_block *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 280))(__p0, __p1))

#define vorbis_analysis_headerout(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(vorbis_dsp_state *, vorbis_comment *, ogg_packet *, ogg_packet *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 256))(__p0, __p1, __p2, __p3, __p4))

#define ov_read_float(__p0, __p1, __p2, __p3) \
	(((long (*)(OggVorbis_File *, float ***, int , int *))*(void**)((long)(VORBISFILE_BASE_NAME) - 172))(__p0, __p1, __p2, __p3))

#define vorbis_packet_blocksize(__p0, __p1) \
	(((long (*)(vorbis_info *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 340))(__p0, __p1))

#define ogg_stream_packetin(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 382))(__p0, __p1))

#define vorbis_encode_setup_init(__p0) \
	(((int (*)(vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 208))(__p0))

#define vorbis_synthesis_idheader(__p0) \
	(((int (*)(ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 640))(__p0))

#define ov_read_filter(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((long (*)(OggVorbis_File *, char *, int , int , int , int , int *, void (*)(float **pcm,long channels,long samples,void *filter_param), void *))*(void**)((long)(VORBISFILE_BASE_NAME) - 670))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define vorbis_granule_time(__p0, __p1) \
	(((double (*)(vorbis_dsp_state *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 580))(__p0, __p1))

#define ogg_stream_reset(__p0) \
	(((int (*)(ogg_stream_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 532))(__p0))

#define ov_time_seek_page(__p0, __p1) \
	(((int (*)(OggVorbis_File *, double ))*(void**)((long)(VORBISFILE_BASE_NAME) - 130))(__p0, __p1))

#define ov_clear(__p0) \
	(((int (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 28))(__p0))

#define ov_serialnumber(__p0, __p1) \
	(((long (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 82))(__p0, __p1))

#define vorbis_analysis_wrote(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 268))(__p0, __p1))

#define vorbis_synthesis_halfrate_p(__p0) \
	(((int (*)(vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 352))(__p0))

#define ogg_page_granulepos(__p0) \
	(((ogg_int64_t (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 466))(__p0))

#define ov_halfrate_p(__p0) \
	(((int (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 628))(__p0))

#define vorbis_encode_setup_vbr(__p0, __p1, __p2, __p3) \
	(((int (*)(vorbis_info *, long , long , float ))*(void**)((long)(VORBISFILE_BASE_NAME) - 196))(__p0, __p1, __p2, __p3))

#define vorbis_bitrate_addblock(__p0) \
	(((int (*)(vorbis_block *))*(void**)((long)(VORBISFILE_BASE_NAME) - 424))(__p0))

#define ogg_stream_check(__p0) \
	(((int (*)(ogg_stream_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 664))(__p0))

#define vorbis_synthesis_headerin(__p0, __p1, __p2) \
	(((int (*)(vorbis_info *, vorbis_comment *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 286))(__p0, __p1, __p2))

#define ov_streams(__p0) \
	(((long (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 178))(__p0))

#define ov_seekable(__p0) \
	(((long (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 76))(__p0))

#define vorbis_synthesis_trackonly(__p0, __p1) \
	(((int (*)(vorbis_block *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 310))(__p0, __p1))

#define vorbis_synthesis_blockin(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, vorbis_block *))*(void**)((long)(VORBISFILE_BASE_NAME) - 316))(__p0, __p1))

#define vorbis_bitrate_flushpacket(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 430))(__p0, __p1))

#define ogg_page_pageno(__p0) \
	(((long (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 478))(__p0))

#define ov_comment(__p0, __p1) \
	(((vorbis_comment *(*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 160))(__p0, __p1))

#define vorbis_synthesis_pcmout(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, float ***))*(void**)((long)(VORBISFILE_BASE_NAME) - 322))(__p0, __p1))

#define ogg_sync_wrote(__p0, __p1) \
	(((int (*)(ogg_sync_state *, long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 514))(__p0, __p1))

#define ov_test(__p0, __p1, __p2, __p3) \
	(((int (*)(BPTR , OggVorbis_File *, char *, long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 46))(__p0, __p1, __p2, __p3))

#define ogg_stream_iovecin(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(ogg_stream_state *, ogg_iovec_t *, int , long , ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 652))(__p0, __p1, __p2, __p3, __p4))

#define ov_raw_tell(__p0) \
	(((ogg_int64_t (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 136))(__p0))

#define ogg_sync_init(__p0) \
	(((int (*)(ogg_sync_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 490))(__p0))

#define ov_read(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((long (*)(OggVorbis_File *, char *, int , int , int , int , int *))*(void**)((long)(VORBISFILE_BASE_NAME) - 166))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define ov_test_open(__p0) \
	(((int (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 58))(__p0))

#define vorbis_synthesis_init(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 292))(__p0, __p1))

#define ov_pcm_seek_page_lap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 598))(__p0, __p1))

#define ogg_page_bos(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 454))(__p0))

#define vorbis_encode_init_vbr(__p0, __p1, __p2, __p3) \
	(((int (*)(vorbis_info *, long , long , float ))*(void**)((long)(VORBISFILE_BASE_NAME) - 202))(__p0, __p1, __p2, __p3))

#define ov_open(__p0, __p1, __p2, __p3) \
	(((int (*)(BPTR , OggVorbis_File *, char *, long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 34))(__p0, __p1, __p2, __p3))

#define ov_time_seek(__p0, __p1) \
	(((int (*)(OggVorbis_File *, double ))*(void**)((long)(VORBISFILE_BASE_NAME) - 124))(__p0, __p1))

#define vorbis_info_clear(__p0) \
	(((void (*)(vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 226))(__p0))

#define vorbis_block_clear(__p0) \
	(((int (*)(vorbis_block *))*(void**)((long)(VORBISFILE_BASE_NAME) - 364))(__p0))

#define vorbis_synthesis(__p0, __p1) \
	(((int (*)(vorbis_block *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 304))(__p0, __p1))

#define ov_pcm_seek(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 112))(__p0, __p1))

#define vorbis_encode_init(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(vorbis_info *, long , long , long , long , long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 184))(__p0, __p1, __p2, __p3, __p4, __p5))

#define ogg_sync_pageseek(__p0, __p1) \
	(((long (*)(ogg_sync_state *, ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 520))(__p0, __p1))

#define ogg_stream_packetout(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 388))(__p0, __p1))

#define ogg_page_continued(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 448))(__p0))

#define vorbis_analysis_init(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, vorbis_info *))*(void**)((long)(VORBISFILE_BASE_NAME) - 250))(__p0, __p1))

#define vorbis_synthesis_halfrate(__p0, __p1) \
	(((int (*)(vorbis_info *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 346))(__p0, __p1))

#define vorbis_synthesis_restart(__p0) \
	(((int (*)(vorbis_dsp_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 298))(__p0))

#define vorbis_comment_add_tag(__p0, __p1, __p2) \
	(((void (*)(vorbis_comment *, const char *, const char *))*(void**)((long)(VORBISFILE_BASE_NAME) - 238))(__p0, __p1, __p2))

#define vorbis_encode_ctl(__p0, __p1, __p2) \
	(((int (*)(vorbis_info *, int , void *))*(void**)((long)(VORBISFILE_BASE_NAME) - 214))(__p0, __p1, __p2))

#define ogg_sync_pageout(__p0, __p1) \
	(((int (*)(ogg_sync_state *, ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 526))(__p0, __p1))

#define vorbis_comment_query_count(__p0, __p1) \
	(((int (*)(vorbis_comment *, const char *))*(void**)((long)(VORBISFILE_BASE_NAME) - 568))(__p0, __p1))

#define ogg_page_packets(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 484))(__p0))

#define ov_bitrate_instant(__p0) \
	(((long (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 70))(__p0))

#define ogg_sync_buffer(__p0, __p1) \
	(((char *(*)(ogg_sync_state *, long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 508))(__p0, __p1))

#define vorbis_version_string() \
	(((const char *(*)(void))*(void**)((long)(VORBISFILE_BASE_NAME) - 646))())

#define ogg_stream_pagein(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 400))(__p0, __p1))

#define vorbis_commentheader_out(__p0, __p1) \
	(((int (*)(vorbis_comment *, ogg_packet *))*(void**)((long)(VORBISFILE_BASE_NAME) - 574))(__p0, __p1))

#define ogg_stream_flush(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 412))(__p0, __p1))

#define ogg_page_version(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 442))(__p0))

#define ov_time_seek_page_lap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, double ))*(void**)((long)(VORBISFILE_BASE_NAME) - 610))(__p0, __p1))

#define ov_halfrate(__p0, __p1) \
	(((int (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 622))(__p0, __p1))

#define vorbis_synthesis_lapout(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, float ***))*(void**)((long)(VORBISFILE_BASE_NAME) - 328))(__p0, __p1))

#define ogg_sync_clear(__p0) \
	(((int (*)(ogg_sync_state *))*(void**)((long)(VORBISFILE_BASE_NAME) - 496))(__p0))

#define vorbis_analysis_blockout(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, vorbis_block *))*(void**)((long)(VORBISFILE_BASE_NAME) - 274))(__p0, __p1))

#define vorbis_comment_add(__p0, __p1) \
	(((void (*)(vorbis_comment *, const char *))*(void**)((long)(VORBISFILE_BASE_NAME) - 556))(__p0, __p1))

#define ogg_stream_init(__p0, __p1) \
	(((int (*)(ogg_stream_state *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 376))(__p0, __p1))

#define ogg_page_eos(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 460))(__p0))

#define ov_pcm_total(__p0, __p1) \
	(((ogg_int64_t (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 94))(__p0, __p1))

#define ogg_stream_pageout(__p0, __p1) \
	(((int (*)(ogg_stream_state *, ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 406))(__p0, __p1))

#define ov_raw_total(__p0, __p1) \
	(((ogg_int64_t (*)(OggVorbis_File *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 88))(__p0, __p1))

#define vorbis_block_init(__p0, __p1) \
	(((int (*)(vorbis_dsp_state *, vorbis_block *))*(void**)((long)(VORBISFILE_BASE_NAME) - 358))(__p0, __p1))

#define ov_open_callbacks(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(void *, OggVorbis_File *, char *, long , ov_callbacks *))*(void**)((long)(VORBISFILE_BASE_NAME) - 40))(__p0, __p1, __p2, __p3, __p4))

#define vorbis_encode_setup_managed(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(vorbis_info *, long , long , long , long , long ))*(void**)((long)(VORBISFILE_BASE_NAME) - 190))(__p0, __p1, __p2, __p3, __p4, __p5))

#define vorbis_comment_init(__p0) \
	(((void (*)(vorbis_comment *))*(void**)((long)(VORBISFILE_BASE_NAME) - 232))(__p0))

#define ov_test_callbacks(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(void *, OggVorbis_File *, char *, long , ov_callbacks *))*(void**)((long)(VORBISFILE_BASE_NAME) - 52))(__p0, __p1, __p2, __p3, __p4))

#define ov_time_tell(__p0) \
	(((double (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 148))(__p0))

#define ogg_page_checksum_set(__p0) \
	(((void (*)(ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 436))(__p0))

#define ogg_page_serialno(__p0) \
	(((int (*)(const ogg_page *))*(void**)((long)(VORBISFILE_BASE_NAME) - 472))(__p0))

#define ov_raw_seek_lap(__p0, __p1) \
	(((int (*)(OggVorbis_File *, ogg_int64_t ))*(void**)((long)(VORBISFILE_BASE_NAME) - 586))(__p0, __p1))

#define ogg_stream_reset_serialno(__p0, __p1) \
	(((int (*)(ogg_stream_state *, int ))*(void**)((long)(VORBISFILE_BASE_NAME) - 538))(__p0, __p1))

#define ov_pcm_tell(__p0) \
	(((ogg_int64_t (*)(OggVorbis_File *))*(void**)((long)(VORBISFILE_BASE_NAME) - 142))(__p0))

#endif /* !_PPCINLINE_VORBISFILE_H */
