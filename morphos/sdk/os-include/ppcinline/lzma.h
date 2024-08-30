/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LZMA_H
#define _PPCINLINE_LZMA_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LZMA_BASE_NAME
#define LZMA_BASE_NAME LZMABase
#endif /* !LZMA_BASE_NAME */

#define lzma_get_progress(__p0, __p1, __p2) \
	(((void (*)(lzma_stream *, uint64_t *, uint64_t *))*(void**)((long)(LZMA_BASE_NAME) - 604))(__p0, __p1, __p2))

#define lzma_stream_decoder(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_stream *, uint64_t , uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 280))(__p0, __p1, __p2))

#define lzma_stream_encoder_mt_memusage(__p0) \
	(((uint64_t (*)(const lzma_mt *))*(void**)((long)(LZMA_BASE_NAME) - 616))(__p0))

#define lzma_index_memused(__p0) \
	(((uint64_t (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 406))(__p0))

#define lzma_filter_flags_decode(__p0, __p1, __p2, __p3, __p4) \
	(((lzma_ret (*)(lzma_filter *, const lzma_allocator *, const uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 208))(__p0, __p1, __p2, __p3, __p4))

#define lzma_memlimit_set(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, uint64_t ))*(void**)((long)(LZMA_BASE_NAME) - 64))(__p0, __p1))

#define lzma_index_buffer_encode(__p0, __p1, __p2, __p3) \
	(((lzma_ret (*)(const lzma_index *, uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 538))(__p0, __p1, __p2, __p3))

#define lzma_end(__p0) \
	(((void (*)(lzma_stream *))*(void**)((long)(LZMA_BASE_NAME) - 46))(__p0))

#define lzma_properties_size(__p0, __p1) \
	(((lzma_ret (*)(uint32_t *, const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 178))(__p0, __p1))

#define lzma_index_decoder(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_stream *, lzma_index **, uint64_t ))*(void**)((long)(LZMA_BASE_NAME) - 532))(__p0, __p1, __p2))

#define lzma_EasyDecode(__p0, __p1, __p2, __p3, __p4) \
	(((lzma_ret (*)(void *, void *, size_t *, const void *, size_t , const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 598))((void*)(LZMA_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define lzma_raw_buffer_encode(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((lzma_ret (*)(const lzma_filter *, const lzma_allocator *, const uint8_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 166))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define lzma_stream_encoder(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_stream *, const lzma_filter *, lzma_check ))*(void**)((long)(LZMA_BASE_NAME) - 256))(__p0, __p1, __p2))

#define lzma_mf_is_supported(__p0) \
	(((lzma_bool (*)(lzma_match_finder ))*(void**)((long)(LZMA_BASE_NAME) - 214))(__p0))

#define lzma_crc64(__p0, __p1, __p2) \
	(((uint64_t (*)(const uint8_t *, size_t , uint64_t ))*(void**)((long)(LZMA_BASE_NAME) - 106))(__p0, __p1, __p2))

#define lzma_index_size(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 460))(__p0))

#define lzma_block_buffer_decode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((lzma_ret (*)(lzma_block *, const lzma_allocator *, const uint8_t *, size_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 394))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define lzma_check_size(__p0) \
	(((uint32_t (*)(lzma_check ))*(void**)((long)(LZMA_BASE_NAME) - 94))(__p0))

#define lzma_vli_decode(__p0, __p1, __p2, __p3, __p4) \
	(((lzma_ret (*)(lzma_vli *, size_t *, const uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 76))(__p0, __p1, __p2, __p3, __p4))

#define lzma_block_header_decode(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_block *, const lzma_allocator *, const uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 346))(__p0, __p1, __p2))

#define lzma_index_iter_rewind(__p0) \
	(((void (*)(lzma_index_iter *))*(void**)((long)(LZMA_BASE_NAME) - 496))(__p0))

#define lzma_index_dup(__p0, __p1) \
	(((lzma_index *(*)(const lzma_index *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 520))(__p0, __p1))

#define lzma_index_append(__p0, __p1, __p2, __p3) \
	(((lzma_ret (*)(lzma_index *, const lzma_allocator *, lzma_vli , lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 424))(__p0, __p1, __p2, __p3))

#define lzma_filters_copy(__p0, __p1, __p2) \
	(((lzma_ret (*)(const lzma_filter *, lzma_filter *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 130))(__p0, __p1, __p2))

#define lzma_index_end(__p0, __p1) \
	(((void (*)(lzma_index *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 418))(__p0, __p1))

#define lzma_index_cat(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_index *, lzma_index *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 514))(__p0, __p1, __p2))

#define lzma_stream_buffer_decode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((lzma_ret (*)(uint64_t *, uint32_t , const lzma_allocator *, const uint8_t *, size_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 298))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define lzma_stream_header_encode(__p0, __p1) \
	(((lzma_ret (*)(const lzma_stream_flags *, uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 304))(__p0, __p1))

#define lzma_easy_encoder_memusage(__p0) \
	(((uint64_t (*)(uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 232))(__p0))

#define lzma_filter_decoder_is_supported(__p0) \
	(((lzma_bool (*)(lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 124))(__p0))

#define lzma_vli_encode(__p0, __p1, __p2, __p3, __p4) \
	(((lzma_ret (*)(lzma_vli , size_t *, uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 70))(__p0, __p1, __p2, __p3, __p4))

#define lzma_version_string() \
	(((const char *(*)(void))*(void**)((long)(LZMA_BASE_NAME) - 34))())

#define lzma_block_decoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, lzma_block *))*(void**)((long)(LZMA_BASE_NAME) - 376))(__p0, __p1))

#define lzma_raw_buffer_decode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((lzma_ret (*)(const lzma_filter *, const lzma_allocator *, const uint8_t *, size_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 172))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define lzma_block_buffer_encode(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((lzma_ret (*)(lzma_block *, const lzma_allocator *, const uint8_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 388))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define lzma_check_is_supported(__p0) \
	(((lzma_bool (*)(lzma_check ))*(void**)((long)(LZMA_BASE_NAME) - 88))(__p0))

#define lzma_stream_buffer_encode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((lzma_ret (*)(lzma_filter *, lzma_check , const lzma_allocator *, const uint8_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 274))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define lzma_block_compressed_size(__p0, __p1) \
	(((lzma_ret (*)(lzma_block *, lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 352))(__p0, __p1))

#define lzma_block_header_size(__p0) \
	(((lzma_ret (*)(lzma_block *))*(void**)((long)(LZMA_BASE_NAME) - 334))(__p0))

#define lzma_stream_header_decode(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream_flags *, const uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 316))(__p0, __p1))

#define lzma_stream_encoder_mt(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_mt *))*(void**)((long)(LZMA_BASE_NAME) - 622))(__p0, __p1))

#define lzma_index_stream_flags(__p0, __p1) \
	(((lzma_ret (*)(lzma_index *, const lzma_stream_flags *))*(void**)((long)(LZMA_BASE_NAME) - 430))(__p0, __p1))

#define lzma_vli_size(__p0) \
	(((uint32_t (*)(lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 82))(__p0))

#define lzma_easy_buffer_encode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((lzma_ret (*)(uint32_t , lzma_check , const lzma_allocator *, const uint8_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 250))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))


#define lzma_index_hash_decode(__p0, __p1, __p2, __p3) \
	(((lzma_ret (*)(lzma_index_hash *, const uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 568))(__p0, __p1, __p2, __p3))

#define lzma_block_uncomp_encode(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((lzma_ret (*)(lzma_block *, const uint8_t *, size_t , uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 610))(__p0, __p1, __p2, __p3, __p4, __p5))

#define lzma_properties_decode(__p0, __p1, __p2, __p3) \
	(((lzma_ret (*)(lzma_filter *, const lzma_allocator *, const uint8_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 190))(__p0, __p1, __p2, __p3))

#define lzma_index_iter_locate(__p0, __p1) \
	(((lzma_bool (*)(lzma_index_iter *, lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 508))(__p0, __p1))

#define lzma_filter_flags_encode(__p0, __p1, __p2, __p3) \
	(((lzma_ret (*)(const lzma_filter *, uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 202))(__p0, __p1, __p2, __p3))

#define lzma_index_file_size(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 478))(__p0))

#define lzma_index_memusage(__p0, __p1) \
	(((uint64_t (*)(lzma_vli , lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 400))(__p0, __p1))

#define lzma_index_stream_padding(__p0, __p1) \
	(((lzma_ret (*)(lzma_index *, lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 442))(__p0, __p1))

#define lzma_alone_decoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, uint64_t ))*(void**)((long)(LZMA_BASE_NAME) - 292))(__p0, __p1))

#define lzma_lzma_preset(__p0, __p1) \
	(((lzma_bool (*)(lzma_options_lzma *, uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 226))(__p0, __p1))

#define lzma_index_hash_size(__p0) \
	(((lzma_vli (*)(const lzma_index_hash *))*(void**)((long)(LZMA_BASE_NAME) - 574))(__p0))

#define lzma_index_init(__p0) \
	(((lzma_index *(*)(const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 412))(__p0))

#define lzma_memusage(__p0) \
	(((uint64_t (*)(const lzma_stream *))*(void**)((long)(LZMA_BASE_NAME) - 52))(__p0))

#define lzma_index_encoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 526))(__p0, __p1))

#define lzma_raw_decoder_memusage(__p0) \
	(((uint64_t (*)(const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 142))(__p0))

#define lzma_block_encoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, lzma_block *))*(void**)((long)(LZMA_BASE_NAME) - 370))(__p0, __p1))

#define lzma_stream_footer_encode(__p0, __p1) \
	(((lzma_ret (*)(const lzma_stream_flags *, uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 310))(__p0, __p1))

#define lzma_index_hash_init(__p0, __p1) \
	(((lzma_index_hash *(*)(lzma_index_hash *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 550))(__p0, __p1))

#define lzma_raw_encoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 148))(__p0, __p1))

#define lzma_physmem() \
	(((uint64_t (*)(void))*(void**)((long)(LZMA_BASE_NAME) - 580))())

#define lzma_block_total_size(__p0) \
	(((lzma_vli (*)(const lzma_block *))*(void**)((long)(LZMA_BASE_NAME) - 364))(__p0))

#define lzma_easy_encoder(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_stream *, uint32_t , lzma_check ))*(void**)((long)(LZMA_BASE_NAME) - 244))(__p0, __p1, __p2))

#define lzma_stream_flags_compare(__p0, __p1) \
	(((lzma_ret (*)(const lzma_stream_flags *, const lzma_stream_flags *))*(void**)((long)(LZMA_BASE_NAME) - 328))(__p0, __p1))

#define lzma_stream_footer_decode(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream_flags *, const uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 322))(__p0, __p1))

#define lzma_index_hash_end(__p0, __p1) \
	(((void (*)(lzma_index_hash *, const lzma_allocator *))*(void**)((long)(LZMA_BASE_NAME) - 556))(__p0, __p1))

#define lzma_EasyGetSize(__p0, __p1, __p2) \
	(((lzma_ret (*)(void *, const void *, size_t , int64_t *))*(void**)((long)(LZMA_BASE_NAME) - 592))((void*)(LZMA_BASE_NAME), __p0, __p1, __p2))

#define lzma_index_hash_append(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_index_hash *, lzma_vli , lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 562))(__p0, __p1, __p2))

#define lzma_filter_encoder_is_supported(__p0) \
	(((lzma_bool (*)(lzma_vli ))*(void**)((long)(LZMA_BASE_NAME) - 118))(__p0))

#define lzma_index_stream_count(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 448))(__p0))

#define lzma_index_total_size(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 472))(__p0))

#define lzma_cputhreads() \
	(((uint32_t (*)(void))*(void**)((long)(LZMA_BASE_NAME) - 628))())

#define lzma_easy_decoder_memusage(__p0) \
	(((uint64_t (*)(uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 238))(__p0))

#define lzma_stream_buffer_bound(__p0) \
	(((size_t (*)(size_t ))*(void**)((long)(LZMA_BASE_NAME) - 268))(__p0))

#define lzma_index_iter_next(__p0, __p1) \
	(((lzma_bool (*)(lzma_index_iter *, lzma_index_iter_mode ))*(void**)((long)(LZMA_BASE_NAME) - 502))(__p0, __p1))

#define lzma_auto_decoder(__p0, __p1, __p2) \
	(((lzma_ret (*)(lzma_stream *, uint64_t , uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 286))(__p0, __p1, __p2))

#define lzma_filters_update(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 160))(__p0, __p1))

#define lzma_raw_encoder_memusage(__p0) \
	(((uint64_t (*)(const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 136))(__p0))

#define lzma_block_unpadded_size(__p0) \
	(((lzma_vli (*)(const lzma_block *))*(void**)((long)(LZMA_BASE_NAME) - 358))(__p0))

#define lzma_mode_is_supported(__p0) \
	(((lzma_bool (*)(lzma_mode ))*(void**)((long)(LZMA_BASE_NAME) - 220))(__p0))

#define lzma_index_checks(__p0) \
	(((uint32_t (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 436))(__p0))

#define lzma_block_buffer_bound(__p0) \
	(((size_t (*)(size_t ))*(void**)((long)(LZMA_BASE_NAME) - 382))(__p0))

#define lzma_index_uncompressed_size(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 484))(__p0))

#define lzma_index_buffer_decode(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((lzma_ret (*)(lzma_index **, uint64_t *, const lzma_allocator *, const uint8_t *, size_t *, size_t ))*(void**)((long)(LZMA_BASE_NAME) - 544))(__p0, __p1, __p2, __p3, __p4, __p5))

#define lzma_index_iter_init(__p0, __p1) \
	(((void (*)(lzma_index_iter *, const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 490))(__p0, __p1))

#define lzma_raw_decoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 154))(__p0, __p1))

#define lzma_version_number() \
	(((uint32_t (*)(void))*(void**)((long)(LZMA_BASE_NAME) - 28))())

#define lzma_index_stream_size(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 466))(__p0))

#define lzma_filter_flags_size(__p0, __p1) \
	(((lzma_ret (*)(uint32_t *, const lzma_filter *))*(void**)((long)(LZMA_BASE_NAME) - 196))(__p0, __p1))

#define lzma_properties_encode(__p0, __p1) \
	(((lzma_ret (*)(const lzma_filter *, uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 184))(__p0, __p1))

#define lzma_alone_encoder(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, const lzma_options_lzma *))*(void**)((long)(LZMA_BASE_NAME) - 262))(__p0, __p1))

#define lzma_code(__p0, __p1) \
	(((lzma_ret (*)(lzma_stream *, lzma_action ))*(void**)((long)(LZMA_BASE_NAME) - 40))(__p0, __p1))

#define lzma_crc32(__p0, __p1, __p2) \
	(((uint32_t (*)(const uint8_t *, size_t , uint32_t ))*(void**)((long)(LZMA_BASE_NAME) - 100))(__p0, __p1, __p2))

#define lzma_index_block_count(__p0) \
	(((lzma_vli (*)(const lzma_index *))*(void**)((long)(LZMA_BASE_NAME) - 454))(__p0))

#define lzma_memlimit_get(__p0) \
	(((uint64_t (*)(const lzma_stream *))*(void**)((long)(LZMA_BASE_NAME) - 58))(__p0))

#define lzma_block_header_encode(__p0, __p1) \
	(((lzma_ret (*)(const lzma_block *, uint8_t *))*(void**)((long)(LZMA_BASE_NAME) - 340))(__p0, __p1))

#define lzma_get_check(__p0) \
	(((lzma_check (*)(const lzma_stream *))*(void**)((long)(LZMA_BASE_NAME) - 112))(__p0))

#endif /* !_PPCINLINE_LZMA_H */
