#ifndef INLINE4_LZMA_H
#define INLINE4_LZMA_H

/*
** This file was auto generated by idltool 53.1.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
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
#include <interfaces/lzma.h>

/* Inline macros for Interface "main" */
#define lzma_code(strm, action) ILZMA->lzma_code((strm), (action))
#define lzma_end(strm) ILZMA->lzma_end((strm))
#define lzma_memusage(strm) ILZMA->lzma_memusage((strm))
#define lzma_memlimit_get(strm) ILZMA->lzma_memlimit_get((strm))
#define lzma_memlimit_set(strm, memlimit) ILZMA->lzma_memlimit_set((strm), (memlimit))
#define lzma_block_header_size(block) ILZMA->lzma_block_header_size((block))
#define lzma_block_header_encode(block, out) ILZMA->lzma_block_header_encode((block), (out))
#define lzma_block_header_decode(block, allocator, in) ILZMA->lzma_block_header_decode((block), (allocator), (in))
#define lzma_block_compressed_size(block, unpadded_size) ILZMA->lzma_block_compressed_size((block), (unpadded_size))
#define lzma_block_unpadded_size(block) ILZMA->lzma_block_unpadded_size((block))
#define lzma_block_total_size(block) ILZMA->lzma_block_total_size((block))
#define lzma_block_encoder(strm, block) ILZMA->lzma_block_encoder((strm), (block))
#define lzma_block_decoder(strm, block) ILZMA->lzma_block_decoder((strm), (block))
#define lzma_block_buffer_bound(uncompressed_size) ILZMA->lzma_block_buffer_bound((uncompressed_size))
#define lzma_block_buffer_encode(block, allocator, in, in_size, out, out_pos, out_size) ILZMA->lzma_block_buffer_encode((block), (allocator), (in), (in_size), (out), (out_pos), (out_size))
#define lzma_block_buffer_decode(block, allocator, in, in_pos, in_size, out, out_pos, out_size) ILZMA->lzma_block_buffer_decode((block), (allocator), (in), (in_pos), (in_size), (out), (out_pos), (out_size))
#define lzma_check_is_supported(check) ILZMA->lzma_check_is_supported((check))
#define lzma_check_size(check) ILZMA->lzma_check_size((check))
#define lzma_crc32(buf, size, crc) ILZMA->lzma_crc32((buf), (size), (crc))
#define lzma_crc64(buf, size, crc) ILZMA->lzma_crc64((buf), (size), (crc))
#define lzma_get_check(strm) ILZMA->lzma_get_check((strm))
#define lzma_easy_encoder_memusage(preset) ILZMA->lzma_easy_encoder_memusage((preset))
#define lzma_easy_decoder_memusage(preset) ILZMA->lzma_easy_decoder_memusage((preset))
#define lzma_easy_encoder(strm, preset, check) ILZMA->lzma_easy_encoder((strm), (preset), (check))
#define lzma_easy_buffer_encode(preset, check, allocator, in, in_size, out, out_pos, out_size) ILZMA->lzma_easy_buffer_encode((preset), (check), (allocator), (in), (in_size), (out), (out_pos), (out_size))
#define lzma_stream_encoder(strm, filters, check) ILZMA->lzma_stream_encoder((strm), (filters), (check))
#define lzma_alone_encoder(strm, options) ILZMA->lzma_alone_encoder((strm), (options))
#define lzma_stream_buffer_bound(uncompressed_size) ILZMA->lzma_stream_buffer_bound((uncompressed_size))
#define lzma_stream_buffer_encode(filters, check, allocator, in, in_size, out, out_pos, out_size) ILZMA->lzma_stream_buffer_encode((filters), (check), (allocator), (in), (in_size), (out), (out_pos), (out_size))
#define lzma_stream_decoder(strm, memlimit, flags) ILZMA->lzma_stream_decoder((strm), (memlimit), (flags))
#define lzma_auto_decoder(strm, memlimit, flags) ILZMA->lzma_auto_decoder((strm), (memlimit), (flags))
#define lzma_alone_decoder(strm, memlimit) ILZMA->lzma_alone_decoder((strm), (memlimit))
#define lzma_stream_buffer_decode(memlimit, flags, allocator, in, in_pos, in_size, out, out_pos, out_size) ILZMA->lzma_stream_buffer_decode((memlimit), (flags), (allocator), (in), (in_pos), (in_size), (out), (out_pos), (out_size))
#define lzma_filter_encoder_is_supported(id) ILZMA->lzma_filter_encoder_is_supported((id))
#define lzma_filter_decoder_is_supported(id) ILZMA->lzma_filter_decoder_is_supported((id))
#define lzma_filters_copy(src, dest, allocator) ILZMA->lzma_filters_copy((src), (dest), (allocator))
#define lzma_raw_encoder_memusage(filters) ILZMA->lzma_raw_encoder_memusage((filters))
#define lzma_raw_decoder_memusage(filters) ILZMA->lzma_raw_decoder_memusage((filters))
#define lzma_raw_encoder(strm, filters) ILZMA->lzma_raw_encoder((strm), (filters))
#define lzma_raw_decoder(strm, filters) ILZMA->lzma_raw_decoder((strm), (filters))
#define lzma_filters_update(strm, filters) ILZMA->lzma_filters_update((strm), (filters))
#define lzma_raw_buffer_encode(filters, allocator, in, in_size, out, out_pos, out_size) ILZMA->lzma_raw_buffer_encode((filters), (allocator), (in), (in_size), (out), (out_pos), (out_size))
#define lzma_raw_buffer_decode(filters, allocator, in, in_pos, in_size, out, out_pos, out_size) ILZMA->lzma_raw_buffer_decode((filters), (allocator), (in), (in_pos), (in_size), (out), (out_pos), (out_size))
#define lzma_properties_size(size, filter) ILZMA->lzma_properties_size((size), (filter))
#define lzma_properties_encode(filter, props) ILZMA->lzma_properties_encode((filter), (props))
#define lzma_properties_decode(filter, allocator, props, props_size) ILZMA->lzma_properties_decode((filter), (allocator), (props), (props_size))
#define lzma_filter_flags_size(size, filter) ILZMA->lzma_filter_flags_size((size), (filter))
#define lzma_filter_flags_encode(filter, out, out_pos, out_size) ILZMA->lzma_filter_flags_encode((filter), (out), (out_pos), (out_size))
#define lzma_filter_flags_decode(filter, allocator, in, in_pos, in_size) ILZMA->lzma_filter_flags_decode((filter), (allocator), (in), (in_pos), (in_size))
#define lzma_physmem() ILZMA->lzma_physmem() 
#define lzma_index_memusage(streams, blocks) ILZMA->lzma_index_memusage((streams), (blocks))
#define lzma_index_memused(i) ILZMA->lzma_index_memused((i))
#define lzma_index_init(allocator) ILZMA->lzma_index_init((allocator))
#define lzma_index_end(i, allocator) ILZMA->lzma_index_end((i), (allocator))
#define lzma_index_append(i, allocator, unpadded_size, uncompressed_size) ILZMA->lzma_index_append((i), (allocator), (unpadded_size), (uncompressed_size))
#define lzma_index_stream_flags(i, stream_flags) ILZMA->lzma_index_stream_flags((i), (stream_flags))
#define lzma_index_checks(i) ILZMA->lzma_index_checks((i))
#define lzma_index_stream_padding(i, stream_padding) ILZMA->lzma_index_stream_padding((i), (stream_padding))
#define lzma_index_stream_count(i) ILZMA->lzma_index_stream_count((i))
#define lzma_index_block_count(i) ILZMA->lzma_index_block_count((i))
#define lzma_index_size(i) ILZMA->lzma_index_size((i))
#define lzma_index_stream_size(i) ILZMA->lzma_index_stream_size((i))
#define lzma_index_total_size(i) ILZMA->lzma_index_total_size((i))
#define lzma_index_file_size(i) ILZMA->lzma_index_file_size((i))
#define lzma_index_uncompressed_size(i) ILZMA->lzma_index_uncompressed_size((i))
#define lzma_index_iter_init(iter, i) ILZMA->lzma_index_iter_init((iter), (i))
#define lzma_index_iter_rewind(iter) ILZMA->lzma_index_iter_rewind((iter))
#define lzma_index_iter_next(iter, mode) ILZMA->lzma_index_iter_next((iter), (mode))
#define lzma_index_iter_locate(iter, target) ILZMA->lzma_index_iter_locate((iter), (target))
#define lzma_index_cat(dest, src, allocator) ILZMA->lzma_index_cat((dest), (src), (allocator))
#define lzma_index_dup(i, allocator) ILZMA->lzma_index_dup((i), (allocator))
#define lzma_index_encoder(strm, i) ILZMA->lzma_index_encoder((strm), (i))
#define lzma_index_decoder(strm, i, memlimit) ILZMA->lzma_index_decoder((strm), (i), (memlimit))
#define lzma_index_buffer_encode(i, out, out_pos, out_size) ILZMA->lzma_index_buffer_encode((i), (out), (out_pos), (out_size))
#define lzma_index_buffer_decode(i, memlimit, allocator, in, in_pos, in_size) ILZMA->lzma_index_buffer_decode((i), (memlimit), (allocator), (in), (in_pos), (in_size))
#define lzma_index_hash_init(index_hash, allocator) ILZMA->lzma_index_hash_init((index_hash), (allocator))
#define lzma_index_hash_end(index_hash, allocator) ILZMA->lzma_index_hash_end((index_hash), (allocator))
#define lzma_index_hash_append(index_hash, unpadded_size, uncompressed_size) ILZMA->lzma_index_hash_append((index_hash), (unpadded_size), (uncompressed_size))
#define lzma_index_hash_decode(index_hash, in, in_pos, in_size) ILZMA->lzma_index_hash_decode((index_hash), (in), (in_pos), (in_size))
#define lzma_index_hash_size(index_hash) ILZMA->lzma_index_hash_size((index_hash))
#define lzma_mf_is_supported(match_finder) ILZMA->lzma_mf_is_supported((match_finder))
#define lzma_mode_is_supported(mode) ILZMA->lzma_mode_is_supported((mode))
#define lzma_lzma_preset(options, preset) ILZMA->lzma_lzma_preset((options), (preset))
#define lzma_stream_header_encode(options, out) ILZMA->lzma_stream_header_encode((options), (out))
#define lzma_stream_footer_encode(options, out) ILZMA->lzma_stream_footer_encode((options), (out))
#define lzma_stream_header_decode(options, in) ILZMA->lzma_stream_header_decode((options), (in))
#define lzma_stream_footer_decode(options, in) ILZMA->lzma_stream_footer_decode((options), (in))
#define lzma_stream_flags_compare(a, b) ILZMA->lzma_stream_flags_compare((a), (b))
#define lzma_version_number() ILZMA->lzma_version_number() 
#define lzma_version_string() ILZMA->lzma_version_string() 
#define lzma_vli_encode(vli, vli_pos, out, out_pos, out_size) ILZMA->lzma_vli_encode((vli), (vli_pos), (out), (out_pos), (out_size))
#define lzma_vli_decode(vli, vli_pos, in, in_pos, in_size) ILZMA->lzma_vli_decode((vli), (vli_pos), (in), (in_pos), (in_size))
#define lzma_vli_size(vli) ILZMA->lzma_vli_size((vli))
#define lzma_get_progress(strm, progress_in, progress_out) ILZMA->lzma_get_progress((strm), (progress_in), (progress_out))

#endif /* INLINE4_LZMA_H */
