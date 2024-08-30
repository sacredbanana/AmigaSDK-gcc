/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PNG_H
#define _PPCINLINE_PNG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PNG_BASE_NAME
#define PNG_BASE_NAME PNGBase
#endif /* !PNG_BASE_NAME */

#define png_access_version_number() \
	(((png_uint_32 (*)(void))*(void**)((long)(PNG_BASE_NAME) - 1000))())

#define png_set_sig_bytes(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 820))(__p0, __p1))

#define png_sig_cmp(__p0, __p1, __p2) \
	(((int (*)(png_bytep , png_size_t , png_size_t ))*(void**)((long)(PNG_BASE_NAME) - 910))(__p0, __p1, __p2))

#define png_check_sig(__p0, __p1) \
	(((int (*)(png_bytep , int ))*(void**)((long)(PNG_BASE_NAME) - 34))(__p0, __p1))

#define png_create_read_struct(__p0, __p1, __p2, __p3) \
	(((png_structp (*)(png_const_charp , png_voidp , png_error_ptr , png_error_ptr ))*(void**)((long)(PNG_BASE_NAME) - 70))(__p0, __p1, __p2, __p3))

#define png_create_write_struct(__p0, __p1, __p2, __p3) \
	(((png_structp (*)(png_const_charp , png_voidp , png_error_ptr , png_error_ptr ))*(void**)((long)(PNG_BASE_NAME) - 76))(__p0, __p1, __p2, __p3))

#define png_get_compression_buffer_size(__p0) \
	(((png_uint_32 (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 172))(__p0))

#define png_set_compression_buffer_size(__p0, __p1) \
	(((void (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 550))(__p0, __p1))

#define png_reset_zstream(__p0) \
	(((int (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 502))(__p0))

#define png_write_chunk(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_bytep , png_bytep , png_size_t ))*(void**)((long)(PNG_BASE_NAME) - 928))(__p0, __p1, __p2, __p3))

#define png_write_chunk_start(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_bytep , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 946))(__p0, __p1, __p2))

#define png_write_chunk_data(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_bytep , png_size_t ))*(void**)((long)(PNG_BASE_NAME) - 934))(__p0, __p1, __p2))

#define png_write_chunk_end(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 940))(__p0))

#define png_create_info_struct(__p0) \
	(((png_infop (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 64))(__p0))

#define png_write_info_before_PLTE(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 976))(__p0, __p1))

#define png_write_info(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 970))(__p0, __p1))

#define png_read_info(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 472))(__p0, __p1))

#define png_convert_to_rfc1123(__p0, __p1) \
	(((png_charp (*)(png_structp , png_timep ))*(void**)((long)(PNG_BASE_NAME) - 1006))(__p0, __p1))

#define png_convert_from_struct_tm(__p0, __p1) \
	(((void (*)(png_timep , struct tm * ttime))*(void**)((long)(PNG_BASE_NAME) - 52))(__p0, __p1))

#define png_convert_from_time_t(__p0, __p1) \
	(((void (*)(png_timep , time_t ))*(void**)((long)(PNG_BASE_NAME) - 58))(__p0, __p1))

#define png_set_expand(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 604))(__p0))

#define png_set_gray_1_2_4_to_8(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 652))(__p0))

#define png_set_expand_gray_1_2_4_to_8(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 1120))(__p0))

#define png_set_palette_to_rgb(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 730))(__p0))

#define png_set_tRNS_to_alpha(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 862))(__p0))

#define png_set_bgr(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 532))(__p0))

#define png_set_gray_to_rgb(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 658))(__p0))

#define png_set_rgb_to_gray(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , int , double , double ))*(void**)((long)(PNG_BASE_NAME) - 766))(__p0, __p1, __p2, __p3))

#define png_set_rgb_to_gray_fixed(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , int , png_fixed_point , png_fixed_point ))*(void**)((long)(PNG_BASE_NAME) - 772))(__p0, __p1, __p2, __p3))

#define png_get_rgb_to_gray_status(__p0) \
	(((png_byte (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 304))(__p0))

#define png_build_grayscale_palette(__p0, __p1) \
	(((void (*)(int , png_colorp ))*(void**)((long)(PNG_BASE_NAME) - 28))(__p0, __p1))

#define png_set_strip_alpha(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 832))(__p0))

#define png_set_swap_alpha(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 844))(__p0))

#define png_set_invert_alpha(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 682))(__p0))

#define png_set_filler(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_uint_32 , int ))*(void**)((long)(PNG_BASE_NAME) - 610))(__p0, __p1, __p2))

#define png_set_add_alpha(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_uint_32 , int ))*(void**)((long)(PNG_BASE_NAME) - 1114))(__p0, __p1, __p2))

#define png_set_swap(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 838))(__p0))

#define png_set_packing(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 718))(__p0))

#define png_set_packswap(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 724))(__p0))

#define png_set_shift(__p0, __p1) \
	(((void (*)(png_structp , png_color_8p ))*(void**)((long)(PNG_BASE_NAME) - 814))(__p0, __p1))

#define png_set_interlace_handling(__p0) \
	(((int (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 676))(__p0))

#define png_set_invert_mono(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 688))(__p0))

#define png_set_background(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_color_16p , int , int , double ))*(void**)((long)(PNG_BASE_NAME) - 526))(__p0, __p1, __p2, __p3, __p4))

#define png_set_strip_16(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 826))(__p0))

#define png_set_dither(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(png_structp , png_colorp , int , int , png_uint_16p , int ))*(void**)((long)(PNG_BASE_NAME) - 592))(__p0, __p1, __p2, __p3, __p4, __p5))

#define png_set_gamma(__p0, __p1, __p2) \
	(((void (*)(png_structp , double , double ))*(void**)((long)(PNG_BASE_NAME) - 646))(__p0, __p1, __p2))

#define png_set_flush(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 628))(__p0, __p1))

#define png_write_flush(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 958))(__p0))

#define png_start_read_image(__p0) \
	(((void (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 916))(__p0))

#define png_read_update_info(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 496))(__p0, __p1))

#define png_read_rows(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_bytepp , png_bytepp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 490))(__p0, __p1, __p2, __p3))

#define png_read_row(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_bytep , png_bytep ))*(void**)((long)(PNG_BASE_NAME) - 484))(__p0, __p1, __p2))

#define png_read_image(__p0, __p1) \
	(((void (*)(png_structp , png_bytepp ))*(void**)((long)(PNG_BASE_NAME) - 466))(__p0, __p1))

#define png_read_end(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 460))(__p0, __p1))

#define png_write_row(__p0, __p1) \
	(((void (*)(png_structp , png_bytep ))*(void**)((long)(PNG_BASE_NAME) - 988))(__p0, __p1))

#define png_write_rows(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_bytepp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 994))(__p0, __p1, __p2))

#define png_write_image(__p0, __p1) \
	(((void (*)(png_structp , png_bytepp ))*(void**)((long)(PNG_BASE_NAME) - 964))(__p0, __p1))

#define png_write_end(__p0, __p1) \
	(((void (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 952))(__p0, __p1))

#define png_destroy_info_struct(__p0, __p1) \
	(((void (*)(png_structp , png_infopp ))*(void**)((long)(PNG_BASE_NAME) - 88))(__p0, __p1))

#define png_destroy_read_struct(__p0, __p1, __p2) \
	(((void (*)(png_structpp , png_infopp , png_infopp ))*(void**)((long)(PNG_BASE_NAME) - 94))(__p0, __p1, __p2))

#define png_destroy_write_struct(__p0, __p1) \
	(((void (*)(png_structpp , png_infopp ))*(void**)((long)(PNG_BASE_NAME) - 100))(__p0, __p1))

#define png_set_crc_action(__p0, __p1, __p2) \
	(((void (*)(png_structp , int , int ))*(void**)((long)(PNG_BASE_NAME) - 586))(__p0, __p1, __p2))

#define png_set_filter(__p0, __p1, __p2) \
	(((void (*)(png_structp , int , int ))*(void**)((long)(PNG_BASE_NAME) - 616))(__p0, __p1, __p2))

#define png_set_filter_heuristics(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , int , int , png_doublep , png_doublep ))*(void**)((long)(PNG_BASE_NAME) - 622))(__p0, __p1, __p2, __p3, __p4))

#define png_set_compression_level(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 556))(__p0, __p1))

#define png_set_compression_mem_level(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 562))(__p0, __p1))

#define png_set_compression_strategy(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 574))(__p0, __p1))

#define png_set_compression_window_bits(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 580))(__p0, __p1))

#define png_set_compression_method(__p0, __p1) \
	(((void (*)(png_structp , int ))*(void**)((long)(PNG_BASE_NAME) - 568))(__p0, __p1))

#define png_set_error_fn(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_voidp , png_error_ptr , png_error_ptr ))*(void**)((long)(PNG_BASE_NAME) - 598))(__p0, __p1, __p2, __p3))

#define png_get_error_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 190))(__p0))

#define png_set_write_fn(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_voidp , png_rw_ptr , png_flush_ptr ))*(void**)((long)(PNG_BASE_NAME) - 892))(__p0, __p1, __p2, __p3))

#define png_set_read_fn(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_voidp , png_rw_ptr ))*(void**)((long)(PNG_BASE_NAME) - 742))(__p0, __p1, __p2))

#define png_get_io_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 256))(__p0))

#define png_set_read_status_fn(__p0, __p1) \
	(((void (*)(png_structp , png_read_status_ptr ))*(void**)((long)(PNG_BASE_NAME) - 748))(__p0, __p1))

#define png_set_write_status_fn(__p0, __p1) \
	(((void (*)(png_structp , png_write_status_ptr ))*(void**)((long)(PNG_BASE_NAME) - 898))(__p0, __p1))

#define png_set_read_user_transform_fn(__p0, __p1) \
	(((void (*)(png_structp , png_user_transform_ptr ))*(void**)((long)(PNG_BASE_NAME) - 760))(__p0, __p1))

#define png_set_write_user_transform_fn(__p0, __p1) \
	(((void (*)(png_structp , png_user_transform_ptr ))*(void**)((long)(PNG_BASE_NAME) - 904))(__p0, __p1))

#define png_set_user_transform_info(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_voidp , int , int ))*(void**)((long)(PNG_BASE_NAME) - 886))(__p0, __p1, __p2, __p3))

#define png_get_user_transform_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 382))(__p0))

#define png_set_read_user_chunk_fn(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_voidp , png_user_chunk_ptr ))*(void**)((long)(PNG_BASE_NAME) - 754))(__p0, __p1, __p2))

#define png_get_user_chunk_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 376))(__p0))

#define png_set_progressive_read_fn(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_voidp , png_progressive_info_ptr , png_progressive_row_ptr , png_progressive_end_ptr ))*(void**)((long)(PNG_BASE_NAME) - 736))(__p0, __p1, __p2, __p3, __p4))

#define png_get_progressive_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 298))(__p0))

#define png_process_data(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_bytep , png_size_t ))*(void**)((long)(PNG_BASE_NAME) - 448))(__p0, __p1, __p2, __p3))

#define png_progressive_combine_row(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_bytep , png_bytep ))*(void**)((long)(PNG_BASE_NAME) - 454))(__p0, __p1, __p2))

#define png_malloc(__p0, __p1) \
	(((png_voidp (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 430))(__p0, __p1))

#define png_malloc_warn(__p0, __p1) \
	(((png_voidp (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 1042))(__p0, __p1))

#define png_free(__p0, __p1) \
	(((void (*)(png_structp , png_voidp ))*(void**)((long)(PNG_BASE_NAME) - 112))(__p0, __p1))

#define png_free_data(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_uint_32 , int ))*(void**)((long)(PNG_BASE_NAME) - 118))(__p0, __p1, __p2, __p3))

#define png_data_freer(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , int , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 82))(__p0, __p1, __p2, __p3))

#define png_memcpy_check(__p0, __p1, __p2, __p3) \
	(((png_voidp (*)(png_structp , png_voidp , png_voidp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 436))(__p0, __p1, __p2, __p3))

#define png_memset_check(__p0, __p1, __p2, __p3) \
	(((png_voidp (*)(png_structp , png_voidp , int , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 442))(__p0, __p1, __p2, __p3))

#define png_error(__p0, __p1) \
	(((void (*)(png_structp , png_const_charp ))*(void**)((long)(PNG_BASE_NAME) - 106))(__p0, __p1))

#define png_chunk_error(__p0, __p1) \
	(((void (*)(png_structp , png_const_charp ))*(void**)((long)(PNG_BASE_NAME) - 40))(__p0, __p1))

#define png_warning(__p0, __p1) \
	(((void (*)(png_structp , png_const_charp ))*(void**)((long)(PNG_BASE_NAME) - 922))(__p0, __p1))

#define png_chunk_warning(__p0, __p1) \
	(((void (*)(png_structp , png_const_charp ))*(void**)((long)(PNG_BASE_NAME) - 46))(__p0, __p1))

#define png_get_valid(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 388))(__p0, __p1, __p2))

#define png_get_rowbytes(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 310))(__p0, __p1))

#define png_get_rows(__p0, __p1) \
	(((png_bytepp (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 316))(__p0, __p1))

#define png_set_rows(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_bytepp ))*(void**)((long)(PNG_BASE_NAME) - 778))(__p0, __p1, __p2))

#define png_get_channels(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 160))(__p0, __p1))

#define png_get_image_width(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 244))(__p0, __p1))

#define png_get_image_height(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 238))(__p0, __p1))

#define png_get_bit_depth(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 142))(__p0, __p1))

#define png_get_color_type(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 166))(__p0, __p1))

#define png_get_filter_type(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 196))(__p0, __p1))

#define png_get_interlace_type(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 250))(__p0, __p1))

#define png_get_compression_type(__p0, __p1) \
	(((png_byte (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 178))(__p0, __p1))

#define png_get_pixels_per_meter(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 292))(__p0, __p1))

#define png_get_x_pixels_per_meter(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 406))(__p0, __p1))

#define png_get_y_pixels_per_meter(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 424))(__p0, __p1))

#define png_get_pixel_aspect_ratio(__p0, __p1) \
	(((float (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 286))(__p0, __p1))

#define png_get_x_offset_pixels(__p0, __p1) \
	(((png_int_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 400))(__p0, __p1))

#define png_get_y_offset_pixels(__p0, __p1) \
	(((png_int_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 418))(__p0, __p1))

#define png_get_x_offset_microns(__p0, __p1) \
	(((png_int_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 394))(__p0, __p1))

#define png_get_y_offset_microns(__p0, __p1) \
	(((png_int_32 (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 412))(__p0, __p1))

#define png_get_signature(__p0, __p1) \
	(((png_bytep (*)(png_structp , png_infop ))*(void**)((long)(PNG_BASE_NAME) - 346))(__p0, __p1))

#define png_get_bKGD(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_color_16p *))*(void**)((long)(PNG_BASE_NAME) - 136))(__p0, __p1, __p2))

#define png_set_bKGD(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_color_16p ))*(void**)((long)(PNG_BASE_NAME) - 520))(__p0, __p1, __p2))

#define png_get_cHRM(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((png_uint_32 (*)(png_structp , png_infop , double *, double *, double *, double *, double *, double *, double *, double *))*(void**)((long)(PNG_BASE_NAME) - 148))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define png_get_cHRM_fixed(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((png_uint_32 (*)(png_structp , png_infop , png_fixed_point *, png_fixed_point *, png_fixed_point *, png_fixed_point *, png_fixed_point *, png_fixed_point *, png_fixed_point *, png_fixed_point *))*(void**)((long)(PNG_BASE_NAME) - 154))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define png_set_cHRM(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(png_structp , png_infop , double , double , double , double , double , double , double , double ))*(void**)((long)(PNG_BASE_NAME) - 538))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define png_set_cHRM_fixed(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(png_structp , png_infop , png_fixed_point , png_fixed_point , png_fixed_point , png_fixed_point , png_fixed_point , png_fixed_point , png_fixed_point , png_fixed_point ))*(void**)((long)(PNG_BASE_NAME) - 544))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define png_get_gAMA(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , double *))*(void**)((long)(PNG_BASE_NAME) - 202))(__p0, __p1, __p2))

#define png_get_gAMA_fixed(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_fixed_point *))*(void**)((long)(PNG_BASE_NAME) - 208))(__p0, __p1, __p2))

#define png_set_gAMA(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , double ))*(void**)((long)(PNG_BASE_NAME) - 634))(__p0, __p1, __p2))

#define png_set_gAMA_fixed(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_fixed_point ))*(void**)((long)(PNG_BASE_NAME) - 640))(__p0, __p1, __p2))

#define png_get_hIST(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_uint_16p *))*(void**)((long)(PNG_BASE_NAME) - 214))(__p0, __p1, __p2))

#define png_set_hIST(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_uint_16p ))*(void**)((long)(PNG_BASE_NAME) - 664))(__p0, __p1, __p2))

#define png_get_IHDR(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((png_uint_32 (*)(png_structp , png_infop , png_uint_32 *, png_uint_32 *, int *, int *, int *, int *, int *))*(void**)((long)(PNG_BASE_NAME) - 124))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define png_set_IHDR(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(png_structp , png_infop , png_uint_32 , png_uint_32 , int , int , int , int , int ))*(void**)((long)(PNG_BASE_NAME) - 508))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define png_get_oFFs(__p0, __p1, __p2, __p3, __p4) \
	(((png_uint_32 (*)(png_structp , png_infop , png_int_32 *, png_int_32 *, int *))*(void**)((long)(PNG_BASE_NAME) - 268))(__p0, __p1, __p2, __p3, __p4))

#define png_set_oFFs(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_infop , png_int_32 , png_int_32 , int ))*(void**)((long)(PNG_BASE_NAME) - 700))(__p0, __p1, __p2, __p3, __p4))

#define png_get_pCAL(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((png_uint_32 (*)(png_structp , png_infop , png_charp *, png_int_32 *, png_int_32 *, int *, int *, png_charp *, png_charpp *))*(void**)((long)(PNG_BASE_NAME) - 274))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define png_set_pCAL(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(png_structp , png_infop , png_charp , png_int_32 , png_int_32 , int , int , png_charp , png_charpp ))*(void**)((long)(PNG_BASE_NAME) - 706))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define png_get_pHYs(__p0, __p1, __p2, __p3, __p4) \
	(((png_uint_32 (*)(png_structp , png_infop , png_uint_32 *, png_uint_32 *, int *))*(void**)((long)(PNG_BASE_NAME) - 280))(__p0, __p1, __p2, __p3, __p4))

#define png_set_pHYs(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_infop , png_uint_32 , png_uint_32 , int ))*(void**)((long)(PNG_BASE_NAME) - 712))(__p0, __p1, __p2, __p3, __p4))

#define png_get_PLTE(__p0, __p1, __p2, __p3) \
	(((png_uint_32 (*)(png_structp , png_infop , png_colorp *, int *))*(void**)((long)(PNG_BASE_NAME) - 130))(__p0, __p1, __p2, __p3))

#define png_set_PLTE(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_colorp , int ))*(void**)((long)(PNG_BASE_NAME) - 514))(__p0, __p1, __p2, __p3))

#define png_get_sBIT(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_color_8p *))*(void**)((long)(PNG_BASE_NAME) - 322))(__p0, __p1, __p2))

#define png_set_sBIT(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_color_8p ))*(void**)((long)(PNG_BASE_NAME) - 784))(__p0, __p1, __p2))

#define png_get_sRGB(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , int *))*(void**)((long)(PNG_BASE_NAME) - 340))(__p0, __p1, __p2))

#define png_set_sRGB(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , int ))*(void**)((long)(PNG_BASE_NAME) - 802))(__p0, __p1, __p2))

#define png_set_sRGB_gAMA_and_cHRM(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , int ))*(void**)((long)(PNG_BASE_NAME) - 808))(__p0, __p1, __p2))

#define png_get_iCCP(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((png_uint_32 (*)(png_structp , png_infop , png_charpp , int *, png_charpp , png_uint_32 *))*(void**)((long)(PNG_BASE_NAME) - 232))(__p0, __p1, __p2, __p3, __p4, __p5))

#define png_set_iCCP(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(png_structp , png_infop , png_charp , int , png_charp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 670))(__p0, __p1, __p2, __p3, __p4, __p5))

#define png_get_sPLT(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_sPLT_tpp ))*(void**)((long)(PNG_BASE_NAME) - 334))(__p0, __p1, __p2))

#define png_set_sPLT(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_sPLT_tp , int ))*(void**)((long)(PNG_BASE_NAME) - 796))(__p0, __p1, __p2, __p3))

#define png_get_text(__p0, __p1, __p2, __p3) \
	(((png_uint_32 (*)(png_structp , png_infop , png_textp *, int *))*(void**)((long)(PNG_BASE_NAME) - 364))(__p0, __p1, __p2, __p3))

#define png_set_text(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_textp , int ))*(void**)((long)(PNG_BASE_NAME) - 868))(__p0, __p1, __p2, __p3))

#define png_get_tIME(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_timep *))*(void**)((long)(PNG_BASE_NAME) - 352))(__p0, __p1, __p2))

#define png_set_tIME(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , png_timep ))*(void**)((long)(PNG_BASE_NAME) - 850))(__p0, __p1, __p2))

#define png_get_tRNS(__p0, __p1, __p2, __p3, __p4) \
	(((png_uint_32 (*)(png_structp , png_infop , png_bytep *, int *, png_color_16p *))*(void**)((long)(PNG_BASE_NAME) - 358))(__p0, __p1, __p2, __p3, __p4))

#define png_set_tRNS(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_infop , png_bytep , int , png_color_16p ))*(void**)((long)(PNG_BASE_NAME) - 856))(__p0, __p1, __p2, __p3, __p4))

#define png_get_sCAL(__p0, __p1, __p2, __p3, __p4) \
	(((png_uint_32 (*)(png_structp , png_infop , int *, double *, double *))*(void**)((long)(PNG_BASE_NAME) - 328))(__p0, __p1, __p2, __p3, __p4))

#define png_set_sCAL(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(png_structp , png_infop , int , double , double ))*(void**)((long)(PNG_BASE_NAME) - 790))(__p0, __p1, __p2, __p3, __p4))

#define png_set_keep_unknown_chunks(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , int , png_bytep , int ))*(void**)((long)(PNG_BASE_NAME) - 694))(__p0, __p1, __p2, __p3))

#define png_set_unknown_chunks(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , png_unknown_chunkp , int ))*(void**)((long)(PNG_BASE_NAME) - 880))(__p0, __p1, __p2, __p3))

#define png_set_unknown_chunk_location(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , int , int ))*(void**)((long)(PNG_BASE_NAME) - 874))(__p0, __p1, __p2, __p3))

#define png_get_unknown_chunks(__p0, __p1, __p2) \
	(((png_uint_32 (*)(png_structp , png_infop , png_unknown_chunkpp ))*(void**)((long)(PNG_BASE_NAME) - 370))(__p0, __p1, __p2))

#define png_handle_as_unknown(__p0, __p1) \
	(((int (*)(png_structp , png_bytep ))*(void**)((long)(PNG_BASE_NAME) - 1036))(__p0, __p1))

#define png_set_invalid(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_infop , int ))*(void**)((long)(PNG_BASE_NAME) - 1012))(__p0, __p1, __p2))

#define png_read_png(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , int , png_voidp ))*(void**)((long)(PNG_BASE_NAME) - 478))(__p0, __p1, __p2, __p3))

#define png_write_png(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_infop , int , png_voidp ))*(void**)((long)(PNG_BASE_NAME) - 982))(__p0, __p1, __p2, __p3))

#define png_get_copyright(__p0) \
	(((png_charp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 184))(__p0))

#define png_get_header_ver(__p0) \
	(((png_charp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 220))(__p0))

#define png_get_header_version(__p0) \
	(((png_charp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 226))(__p0))

#define png_get_libpng_ver(__p0) \
	(((png_charp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 262))(__p0))

#define png_permit_mng_features(__p0, __p1) \
	(((png_uint_32 (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 1018))(__p0, __p1))

#define png_mmx_support() \
	(((int (*)(void))*(void**)((long)(PNG_BASE_NAME) - 1024))())

#define png_set_strip_error_numbers(__p0, __p1) \
	(((void (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 1030))(__p0, __p1))

#define png_set_mem_fn(__p0, __p1, __p2, __p3) \
	(((void (*)(png_structp , png_voidp , png_malloc_ptr , png_free_ptr ))*(void**)((long)(PNG_BASE_NAME) - 1060))(__p0, __p1, __p2, __p3))

#define png_get_mem_ptr(__p0) \
	(((png_voidp (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 1066))(__p0))

#define png_create_read_struct_2(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((png_structp (*)(png_const_charp , png_voidp , png_error_ptr , png_error_ptr , png_voidp , png_malloc_ptr , png_free_ptr ))*(void**)((long)(PNG_BASE_NAME) - 1072))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define png_create_write_struct_2(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((png_structp (*)(png_const_charp , png_voidp , png_error_ptr , png_error_ptr , png_voidp , png_malloc_ptr , png_free_ptr ))*(void**)((long)(PNG_BASE_NAME) - 1078))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define png_malloc_default(__p0, __p1) \
	(((png_voidp (*)(png_structp , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 1084))(__p0, __p1))

#define png_free_default(__p0, __p1) \
	(((void (*)(png_structp , png_voidp ))*(void**)((long)(PNG_BASE_NAME) - 1090))(__p0, __p1))

#define png_set_user_limits(__p0, __p1, __p2) \
	(((void (*)(png_structp , png_uint_32 , png_uint_32 ))*(void**)((long)(PNG_BASE_NAME) - 1096))(__p0, __p1, __p2))

#define png_get_user_width_max(__p0) \
	(((png_uint_32 (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 1102))(__p0))

#define png_get_user_height_max(__p0) \
	(((png_uint_32 (*)(png_structp ))*(void**)((long)(PNG_BASE_NAME) - 1108))(__p0))

#endif /* !_PPCINLINE_PNG_H */
