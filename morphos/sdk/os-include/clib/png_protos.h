#ifndef CLIB_PNG_PROTOS_H
#define CLIB_PNG_PROTOS_H

/*
	png.library C prototypes

	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_PNG_H
# include <libraries/png.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

png_uint_32 png_access_version_number(void);
void png_set_sig_bytes(png_structp png_ptr, int num_bytes);
int png_sig_cmp(png_bytep sig, png_size_t start, png_size_t num_to_check);
int png_check_sig(png_bytep sig, int num);
png_structp png_create_read_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
png_structp png_create_write_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
png_uint_32 png_get_compression_buffer_size(png_structp png_ptr);
void png_set_compression_buffer_size(png_structp png_ptr, png_uint_32 size);
int png_reset_zstream(png_structp png_ptr);
void png_write_chunk(png_structp png_ptr, png_bytep chunk_name, png_bytep data, png_size_t length);
void png_write_chunk_start(png_structp png_ptr, png_bytep chunk_name, png_uint_32 length);
void png_write_chunk_data(png_structp png_ptr, png_bytep data, png_size_t length);
void png_write_chunk_end(png_structp png_ptr);
png_infop png_create_info_struct(png_structp png_ptr);
void png_write_info_before_PLTE(png_structp png_ptr, png_infop info_ptr);
void png_write_info(png_structp png_ptr, png_infop info_ptr);
void png_read_info(png_structp png_ptr, png_infop info_ptr);

png_charp png_convert_to_rfc1123(png_structp png_ptr, png_timep ptime);
void png_convert_from_struct_tm(png_timep ptime, struct tm FAR * ttime);
void png_convert_from_time_t(png_timep ptime, time_t ttime);
void png_set_expand(png_structp png_ptr);
void png_set_gray_1_2_4_to_8(png_structp png_ptr);
void png_set_expand_gray_1_2_4_to_8(png_structp png_ptr);
void png_set_palette_to_rgb(png_structp png_ptr);
void png_set_tRNS_to_alpha(png_structp png_ptr);
void png_set_bgr(png_structp png_ptr);
void png_set_gray_to_rgb(png_structp png_ptr);
void png_set_rgb_to_gray(png_structp png_ptr, int error_action, double red, double green );

void png_set_rgb_to_gray_fixed(png_structp png_ptr, int error_action, png_fixed_point red, png_fixed_point green );
png_byte png_get_rgb_to_gray_status(png_structp png_ptr);

void png_build_grayscale_palette(int bit_depth, png_colorp palette);
void png_set_strip_alpha(png_structp png_ptr);
void png_set_swap_alpha(png_structp png_ptr);
void png_set_invert_alpha(png_structp png_ptr);
void png_set_filler(png_structp png_ptr, png_uint_32 filler, int flags);
void png_set_add_alpha(png_structp png_ptr, png_uint_32 filler, int filler_loc);
void png_set_swap(png_structp png_ptr);
void png_set_packing(png_structp png_ptr);
void png_set_packswap(png_structp png_ptr);
void png_set_shift(png_structp png_ptr, png_color_8p true_bits);
int png_set_interlace_handling(png_structp png_ptr);
void png_set_invert_mono(png_structp png_ptr);

void png_set_background(png_structp png_ptr, png_color_16p background_color, int background_gamma_code, int need_expand, double background_gamma);
void png_set_strip_16(png_structp png_ptr);
void png_set_dither(png_structp png_ptr, png_colorp palette, int num_palette, int maximum_colors, png_uint_16p histogram, int full_dither);

void png_set_gamma(png_structp png_ptr, double screen_gamma, double default_file_gamma);

void png_set_flush(png_structp png_ptr, int nrows);
void png_write_flush(png_structp png_ptr);


void png_start_read_image(png_structp png_ptr);
void png_read_update_info(png_structp png_ptr, png_infop info_ptr);
void png_read_rows(png_structp png_ptr, png_bytepp row, png_bytepp display_row, png_uint_32 num_rows);
void png_read_row(png_structp png_ptr, png_bytep row, png_bytep display_row);
void png_read_image(png_structp png_ptr, png_bytepp image);
void png_read_end(png_structp png_ptr, png_infop info_ptr);


void png_write_row(png_structp png_ptr, png_bytep row);
void png_write_rows(png_structp png_ptr, png_bytepp row, png_uint_32 num_rows);
void png_write_image(png_structp png_ptr, png_bytepp image);
void png_write_end(png_structp png_ptr, png_infop info_ptr);


void png_destroy_info_struct(png_structp png_ptr, png_infopp info_ptr_ptr);
void png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr);
void png_destroy_write_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr);

void png_set_crc_action(png_structp png_ptr, int crit_action, int ancil_action);
void png_set_filter(png_structp png_ptr, int method, int filters);
void png_set_filter_heuristics(png_structp png_ptr, int heuristic_method, int num_weights, png_doublep filter_weights, png_doublep filter_costs);

void png_set_compression_level(png_structp png_ptr, int level);
void png_set_compression_mem_level (png_structp png_ptr, int mem_level);
void png_set_compression_strategy (png_structp png_ptr, int strategy);
void png_set_compression_window_bits(png_structp png_ptr, int window_bits);
void png_set_compression_method(png_structp png_ptr, int method);

void png_set_error_fn(png_structp png_ptr, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn);
png_voidp png_get_error_ptr(png_structp png_ptr);

void png_set_write_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn);
void png_set_read_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);

png_voidp png_get_io_ptr(png_structp png_ptr);

void png_set_read_status_fn(png_structp png_ptr, png_read_status_ptr read_row_fn);
void png_set_write_status_fn(png_structp png_ptr, png_write_status_ptr write_row_fn);

void png_set_read_user_transform_fn(png_structp png_ptr, png_user_transform_ptr read_user_transform_fn);
void png_set_write_user_transform_fn(png_structp png_ptr, png_user_transform_ptr write_user_transform_fn);
void png_set_user_transform_info(png_structp png_ptr, png_voidp user_transform_ptr, int user_transform_depth, int user_transform_channels);
png_voidp png_get_user_transform_ptr(png_structp png_ptr);

void png_set_read_user_chunk_fn(png_structp png_ptr,png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn);
png_voidp png_get_user_chunk_ptr(png_structp  png_ptr);


void png_set_progressive_read_fn(png_structp png_ptr, png_voidp progressive_ptr, png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn);
png_voidp png_get_progressive_ptr(png_structp png_ptr);
void png_process_data(png_structp png_ptr, png_infop info_ptr, png_bytep buffer, png_size_t buffer_size);
void png_progressive_combine_row(png_structp png_ptr, png_bytep old_row, png_bytep new_row);


png_voidp png_malloc(png_structp png_ptr, png_uint_32 size);
png_voidp png_malloc_warn(png_structp png_ptr, png_uint_32 size);
void png_free(png_structp png_ptr, png_voidp ptr);
void png_free_data(png_structp png_ptr, png_infop info_ptr, png_uint_32 free_me, int num);
void png_data_freer(png_structp png_ptr, png_infop info_ptr, int freer, png_uint_32 mask);


png_voidp png_memcpy_check(png_structp png_ptr, png_voidp s1, png_voidp s2, png_uint_32 size);
png_voidp png_memset_check(png_structp png_ptr, png_voidp s1, int value, png_uint_32 size);

void png_error(png_structp png_ptr, png_const_charp error_message);
void png_chunk_error(png_structp png_ptr, png_const_charp error_message);

void png_warning(png_structp png_ptr, png_const_charp warning_message);
void png_chunk_warning(png_structp png_ptr, png_const_charp warning_message);

png_uint_32 png_get_valid(png_structp png_ptr,png_infop info_ptr, png_uint_32 flag);
png_uint_32 png_get_rowbytes(png_structp png_ptr,png_infop info_ptr);

png_bytepp png_get_rows(png_structp png_ptr,png_infop info_ptr);
void png_set_rows(png_structp png_ptr, png_infop info_ptr, png_bytepp row_pointers);

png_byte png_get_channels(png_structp png_ptr, png_infop info_ptr);

png_uint_32 png_get_image_width(png_structp png_ptr, png_infop info_ptr);
png_uint_32 png_get_image_height(png_structp png_ptr, png_infop info_ptr);
png_byte png_get_bit_depth(png_structp png_ptr, png_infop info_ptr);
png_byte png_get_color_type(png_structp png_ptr, png_infop info_ptr);
png_byte png_get_filter_type(png_structp png_ptr, png_infop info_ptr);
png_byte png_get_interlace_type(png_structp png_ptr, png_infop info_ptr);
png_byte png_get_compression_type(png_structp png_ptr, png_infop info_ptr);

png_uint_32 png_get_pixels_per_meter(png_structp png_ptr, png_infop info_ptr);
png_uint_32 png_get_x_pixels_per_meter(png_structp png_ptr, png_infop info_ptr);
png_uint_32 png_get_y_pixels_per_meter(png_structp png_ptr, png_infop info_ptr);

float png_get_pixel_aspect_ratio(png_structp png_ptr, png_infop info_ptr);

png_int_32 png_get_x_offset_pixels(png_structp png_ptr, png_infop info_ptr);
png_int_32 png_get_y_offset_pixels(png_structp png_ptr, png_infop info_ptr);
png_int_32 png_get_x_offset_microns(png_structp png_ptr, png_infop info_ptr);
png_int_32 png_get_y_offset_microns(png_structp png_ptr, png_infop info_ptr);


png_bytep png_get_signature(png_structp png_ptr, png_infop info_ptr);

png_uint_32 png_get_bKGD(png_structp png_ptr, png_infop info_ptr, png_color_16p *background);

void png_set_bKGD(png_structp png_ptr, png_infop info_ptr, png_color_16p background);

png_uint_32 png_get_cHRM(png_structp png_ptr, png_infop info_ptr, double *white_x, double *white_y, double *red_x, double *red_y, double *green_x, double *green_y, double *blue_x, double *blue_y);
png_uint_32 png_get_cHRM_fixed(png_structp png_ptr, png_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y, png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point *int_blue_x, png_fixed_point *int_blue_y);

void png_set_cHRM(png_structp png_ptr, png_infop info_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y);
void png_set_cHRM_fixed(png_structp png_ptr, png_infop info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y);

png_uint_32 png_get_gAMA(png_structp png_ptr, png_infop info_ptr, double *file_gamma);
png_uint_32 png_get_gAMA_fixed(png_structp png_ptr, png_infop info_ptr, png_fixed_point *int_file_gamma);

void png_set_gAMA(png_structp png_ptr, png_infop info_ptr, double file_gamma);
void png_set_gAMA_fixed(png_structp png_ptr, png_infop info_ptr, png_fixed_point int_file_gamma);


png_uint_32 png_get_hIST(png_structp png_ptr, png_infop info_ptr, png_uint_16p *hist);
void png_set_hIST(png_structp png_ptr, png_infop info_ptr, png_uint_16p hist);


png_uint_32 png_get_IHDR(png_structp png_ptr, png_infop info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);
void png_set_IHDR(png_structp png_ptr, png_infop info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth, int color_type, int interlace_method, int compression_method, int filter_method);

png_uint_32 png_get_oFFs(png_structp png_ptr, png_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y, int *unit_type);
void png_set_oFFs(png_structp png_ptr, png_infop info_ptr, png_int_32 offset_x, png_int_32 offset_y, int unit_type);


png_uint_32 png_get_pCAL(png_structp png_ptr, png_infop info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1, int *type, int *nparams, png_charp *units, png_charpp *params);
void png_set_pCAL(png_structp png_ptr, png_infop info_ptr, png_charp purpose, png_int_32 X0, png_int_32 X1, int type, int nparams, png_charp units, png_charpp params);

png_uint_32 png_get_pHYs(png_structp png_ptr, png_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);
void png_set_pHYs(png_structp png_ptr, png_infop info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type);


png_uint_32 png_get_PLTE(png_structp png_ptr, png_infop info_ptr, png_colorp *palette, int *num_palette);
void png_set_PLTE(png_structp png_ptr, png_infop info_ptr, png_colorp palette, int num_palette);


png_uint_32 png_get_sBIT(png_structp png_ptr, png_infop info_ptr, png_color_8p *sig_bit);
void png_set_sBIT(png_structp png_ptr, png_infop info_ptr, png_color_8p sig_bit);


png_uint_32 png_get_sRGB(png_structp png_ptr, png_infop info_ptr, int *intent);
void png_set_sRGB(png_structp png_ptr, png_infop info_ptr, int intent);
void png_set_sRGB_gAMA_and_cHRM(png_structp png_ptr, png_infop info_ptr, int intent);


png_uint_32 png_get_iCCP(png_structp png_ptr, png_infop info_ptr, png_charpp name, int *compression_type, png_charpp profile, png_uint_32 *proflen);
void png_set_iCCP(png_structp png_ptr, png_infop info_ptr, png_charp name, int compression_type, png_charp profile, png_uint_32 proflen);


png_uint_32 png_get_sPLT(png_structp png_ptr, png_infop info_ptr, png_sPLT_tpp entries);
void png_set_sPLT(png_structp png_ptr, png_infop info_ptr, png_sPLT_tp entries, int nentries);


png_uint_32 png_get_text(png_structp png_ptr, png_infop info_ptr, png_textp *text_ptr, int *num_text);
void png_set_text(png_structp png_ptr, png_infop info_ptr, png_textp text_ptr, int num_text);


png_uint_32 png_get_tIME(png_structp png_ptr, png_infop info_ptr, png_timep *mod_time);
void png_set_tIME(png_structp png_ptr, png_infop info_ptr, png_timep mod_time);


png_uint_32 png_get_tRNS(png_structp png_ptr, png_infop info_ptr, png_bytep *trans, int *num_trans, png_color_16p *trans_values);
void png_set_tRNS(png_structp png_ptr, png_infop info_ptr, png_bytep trans, int num_trans, png_color_16p trans_values);

png_uint_32 png_get_sCAL(png_structp png_ptr, png_infop info_ptr, int *unit, double *width, double *height);
void png_set_sCAL(png_structp png_ptr, png_infop info_ptr, int unit, double width, double height);


void png_set_keep_unknown_chunks(png_structp png_ptr, int keep, png_bytep chunk_list, int num_chunks);
void png_set_unknown_chunks(png_structp png_ptr, png_infop info_ptr, png_unknown_chunkp unknowns, int num_unknowns);
void png_set_unknown_chunk_location(png_structp png_ptr, png_infop info_ptr, int chunk, int location);
png_uint_32 png_get_unknown_chunks(png_structp png_ptr, png_infop info_ptr, png_unknown_chunkpp entries);


int png_handle_as_unknown(png_structp png_ptr, png_bytep chunk_name);
void png_set_invalid(png_structp png_ptr, png_infop info_ptr, int mask);

void png_read_png(png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);
void png_write_png(png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);


/*png_bytep png_sig_bytes(void);*/

png_charp png_get_copyright(png_structp png_ptr);
png_charp png_get_header_ver(png_structp png_ptr);
png_charp png_get_header_version(png_structp png_ptr);
png_charp png_get_libpng_ver(png_structp png_ptr);

png_uint_32 png_permit_mng_features(png_structp png_ptr, png_uint_32 mng_features_permitted);

int png_mmx_support(void);

void png_set_strip_error_numbers(png_structp png_ptr, png_uint_32 strip_mode);

void png_set_mem_fn(png_structp png_ptr, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
png_voidp png_get_mem_ptr(png_structp png_ptr);

png_structp png_create_read_struct_2(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
png_structp png_create_write_struct_2(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);

png_voidp png_malloc_default(png_structp png_ptr, png_uint_32 size);
void png_free_default(png_structp png_ptr, png_voidp ptr);

void png_set_user_limits(png_structp png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max);
png_uint_32 png_get_user_width_max(png_structp png_ptr);
png_uint_32 png_get_user_height_max(png_structp png_ptr);


/* this is in libpng.a */

void png_init_io(png_structp png_ptr, png_FILE_p fp);


#ifdef __cplusplus
}
#endif

#endif /* CLIB_PNG_PROTOS_H */
