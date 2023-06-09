#ifndef LZMA_INTERFACE_DEF_H
#define LZMA_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.1.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LZMA_H
#include <lzma.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct LZMAIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct LZMAIFace *Self);
	uint32 APICALL (*Release)(struct LZMAIFace *Self);
	void APICALL (*Expunge)(struct LZMAIFace *Self);
	struct Interface * APICALL (*Clone)(struct LZMAIFace *Self);
	lzma_ret (*lzma_code)(lzma_stream *strm, lzma_action action);
	void (*lzma_end)(lzma_stream *strm);
	uint64_t (*lzma_memusage)(const lzma_stream *strm);
	uint64_t (*lzma_memlimit_get)(const lzma_stream *strm);
	lzma_ret (*lzma_memlimit_set)(lzma_stream *strm, uint64_t memlimit);
	lzma_ret (*lzma_block_header_size)(lzma_block *block);
	lzma_ret (*lzma_block_header_encode)(const lzma_block *block, uint8_t *out);
	lzma_ret (*lzma_block_header_decode)(lzma_block *block, lzma_allocator *allocator, const uint8_t *in);
	lzma_ret (*lzma_block_compressed_size)(lzma_block *block, lzma_vli unpadded_size);
	lzma_vli (*lzma_block_unpadded_size)(const lzma_block *block);
	lzma_vli (*lzma_block_total_size)(const lzma_block *block);
	lzma_ret (*lzma_block_encoder)(lzma_stream *strm, lzma_block *block);
	lzma_ret (*lzma_block_decoder)(lzma_stream *strm, lzma_block *block);
	size_t (*lzma_block_buffer_bound)(size_t uncompressed_size);
	lzma_ret (*lzma_block_buffer_encode)(lzma_block *block, lzma_allocator *allocator, const uint8_t *in, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_block_buffer_decode)(lzma_block *block, lzma_allocator *allocator, const uint8_t *in, size_t *in_pos, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_bool (*lzma_check_is_supported)(lzma_check check);
	uint32_t (*lzma_check_size)(lzma_check check);
	uint32_t (*lzma_crc32)(const uint8_t *buf, size_t size, uint32_t crc);
	uint64_t (*lzma_crc64)(const uint8_t *buf, size_t size, uint64_t crc);
	lzma_check (*lzma_get_check)(const lzma_stream *strm);
	uint64_t (*lzma_easy_encoder_memusage)(uint32_t preset);
	uint64_t (*lzma_easy_decoder_memusage)(uint32_t preset);
	lzma_ret (*lzma_easy_encoder)(lzma_stream *strm, uint32_t preset, lzma_check check);
	lzma_ret (*lzma_easy_buffer_encode)(uint32_t preset, lzma_check check, lzma_allocator *allocator, const uint8_t *in, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_stream_encoder)(lzma_stream *strm, const lzma_filter *filters, lzma_check check);
	lzma_ret (*lzma_alone_encoder)(lzma_stream *strm, const lzma_options_lzma *options);
	size_t (*lzma_stream_buffer_bound)(size_t uncompressed_size);
	lzma_ret (*lzma_stream_buffer_encode)(lzma_filter *filters, lzma_check check, lzma_allocator *allocator, const uint8_t *in, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_stream_decoder)(lzma_stream *strm, uint64_t memlimit, uint32_t flags);
	lzma_ret (*lzma_auto_decoder)(lzma_stream *strm, uint64_t memlimit, uint32_t flags);
	lzma_ret (*lzma_alone_decoder)(lzma_stream *strm, uint64_t memlimit);
	lzma_ret (*lzma_stream_buffer_decode)(uint64_t *memlimit, uint32_t flags, lzma_allocator *allocator, const uint8_t *in, size_t *in_pos, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_bool (*lzma_filter_encoder_is_supported)(lzma_vli id);
	lzma_bool (*lzma_filter_decoder_is_supported)(lzma_vli id);
	lzma_ret (*lzma_filters_copy)(const lzma_filter *src, lzma_filter *dest, lzma_allocator *allocator);
	uint64_t (*lzma_raw_encoder_memusage)(const lzma_filter *filters);
	uint64_t (*lzma_raw_decoder_memusage)(const lzma_filter *filters);
	lzma_ret (*lzma_raw_encoder)(lzma_stream *strm, const lzma_filter *filters);
	lzma_ret (*lzma_raw_decoder)(lzma_stream *strm, const lzma_filter *filters);
	lzma_ret (*lzma_filters_update)(lzma_stream *strm, const lzma_filter *filters);
	lzma_ret (*lzma_raw_buffer_encode)(const lzma_filter *filters, lzma_allocator *allocator, const uint8_t *in, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_raw_buffer_decode)(const lzma_filter *filters, lzma_allocator *allocator, const uint8_t *in, size_t *in_pos, size_t in_size, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_properties_size)(uint32_t *size, const lzma_filter *filter);
	lzma_ret (*lzma_properties_encode)(const lzma_filter *filter, uint8_t *props);
	lzma_ret (*lzma_properties_decode)(lzma_filter *filter, lzma_allocator *allocator, const uint8_t *props, size_t props_size);
	lzma_ret (*lzma_filter_flags_size)(uint32_t *size, const lzma_filter *filter);
	lzma_ret (*lzma_filter_flags_encode)(const lzma_filter *filter, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_filter_flags_decode)(lzma_filter *filter, lzma_allocator *allocator, const uint8_t *in, size_t *in_pos, size_t in_size);
	uint64_t (*lzma_physmem)(void);
	uint64_t (*lzma_index_memusage)(lzma_vli streams, lzma_vli blocks);
	uint64_t (*lzma_index_memused)(const lzma_index *i);
	lzma_index * (*lzma_index_init)(lzma_allocator *allocator);
	void (*lzma_index_end)(lzma_index *i, lzma_allocator *allocator);
	lzma_ret (*lzma_index_append)(lzma_index *i, lzma_allocator *allocator, lzma_vli unpadded_size, lzma_vli uncompressed_size);
	lzma_ret (*lzma_index_stream_flags)(lzma_index *i, const lzma_stream_flags *stream_flags);
	uint32_t (*lzma_index_checks)(const lzma_index *i);
	lzma_ret (*lzma_index_stream_padding)(lzma_index *i, lzma_vli stream_padding);
	lzma_vli (*lzma_index_stream_count)(const lzma_index *i);
	lzma_vli (*lzma_index_block_count)(const lzma_index *i);
	lzma_vli (*lzma_index_size)(const lzma_index *i);
	lzma_vli (*lzma_index_stream_size)(const lzma_index *i);
	lzma_vli (*lzma_index_total_size)(const lzma_index *i);
	lzma_vli (*lzma_index_file_size)(const lzma_index *i);
	lzma_vli (*lzma_index_uncompressed_size)(const lzma_index *i);
	void (*lzma_index_iter_init)(lzma_index_iter *iter, const lzma_index *i);
	void (*lzma_index_iter_rewind)(lzma_index_iter *iter);
	lzma_bool (*lzma_index_iter_next)(lzma_index_iter *iter, lzma_index_iter_mode mode);
	lzma_bool (*lzma_index_iter_locate)(lzma_index_iter *iter, lzma_vli target);
	lzma_ret (*lzma_index_cat)(lzma_index *dest, lzma_index *src, lzma_allocator *allocator);
	lzma_index *(*lzma_index_dup)(const lzma_index *i, lzma_allocator *allocator);
	lzma_ret (*lzma_index_encoder)(lzma_stream *strm, const lzma_index *i);
	lzma_ret (*lzma_index_decoder)(lzma_stream *strm, lzma_index **i, uint64_t memlimit);
	lzma_ret (*lzma_index_buffer_encode)(const lzma_index *i, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_index_buffer_decode)(lzma_index **i, uint64_t *memlimit, lzma_allocator *allocator, const uint8_t *in, size_t *in_pos, size_t in_size);
	lzma_index_hash * (*lzma_index_hash_init)(lzma_index_hash *index_hash, lzma_allocator *allocator);
	void (*lzma_index_hash_end)(lzma_index_hash *index_hash, lzma_allocator *allocator);
	lzma_ret (*lzma_index_hash_append)(lzma_index_hash *index_hash, lzma_vli unpadded_size, lzma_vli uncompressed_size);
	lzma_ret (*lzma_index_hash_decode)(lzma_index_hash *index_hash, const uint8_t *in, size_t *in_pos, size_t in_size);
	lzma_vli (*lzma_index_hash_size)(const lzma_index_hash *index_hash);
	lzma_bool (*lzma_mf_is_supported)(lzma_match_finder match_finder);
	lzma_bool (*lzma_mode_is_supported)(lzma_mode mode);
	lzma_bool (*lzma_lzma_preset)(lzma_options_lzma *options, uint32_t preset);
	lzma_ret (*lzma_stream_header_encode)(const lzma_stream_flags *options, uint8_t *out);
	lzma_ret (*lzma_stream_footer_encode)(const lzma_stream_flags *options, uint8_t *out);
	lzma_ret (*lzma_stream_header_decode)(lzma_stream_flags *options, const uint8_t *in);
	lzma_ret (*lzma_stream_footer_decode)(lzma_stream_flags *options, const uint8_t *in);
	lzma_ret (*lzma_stream_flags_compare)(const lzma_stream_flags *a, const lzma_stream_flags *b);
	uint32_t (*lzma_version_number)(void);
	const char *(*lzma_version_string)(void);
	lzma_ret (*lzma_vli_encode)(lzma_vli vli, size_t *vli_pos, uint8_t *out, size_t *out_pos, size_t out_size);
	lzma_ret (*lzma_vli_decode)(lzma_vli *vli, size_t *vli_pos, const uint8_t *in, size_t *in_pos, size_t in_size);
	uint32_t (*lzma_vli_size)(lzma_vli vli);
	void (*lzma_get_progress)(lzma_stream *strm, uint64_t *progress_in, uint64_t *progress_out);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* LZMA_INTERFACE_DEF_H */
