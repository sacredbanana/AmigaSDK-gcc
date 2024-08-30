/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_JFIF_H
#define _PPCINLINE_JFIF_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef JFIF_BASE_NAME
#define JFIF_BASE_NAME JFIFBase
#endif /* !JFIF_BASE_NAME */

#define jpeg_start_decompress(__p0) \
	(((boolean (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 172))(__p0))

#define jpeg_finish_decompress(__p0) \
	(((boolean (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 184))(__p0))

#define jpeg_read_scanlines(__p0, __p1, __p2) \
	(((JDIMENSION (*)(j_decompress_ptr , JSAMPARRAY , JDIMENSION ))*(void**)((long)(JFIF_BASE_NAME) - 178))(__p0, __p1, __p2))

#define jpeg_set_marker_processor(__p0, __p1, __p2) \
	(((void (*)(j_decompress_ptr , int , jpeg_marker_parser_method ))*(void**)((long)(JFIF_BASE_NAME) - 244))(__p0, __p1, __p2))

#define jpeg_write_raw_data(__p0, __p1, __p2) \
	(((JDIMENSION (*)(j_compress_ptr , JSAMPIMAGE , JDIMENSION ))*(void**)((long)(JFIF_BASE_NAME) - 136))(__p0, __p1, __p2))

#define jpeg_suppress_tables(__p0, __p1) \
	(((void (*)(j_compress_ptr , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 100))(__p0, __p1))

#define jpeg_has_multiple_scans(__p0) \
	(((boolean (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 196))(__p0))

#define jpeg_set_quality(__p0, __p1, __p2) \
	(((void (*)(j_compress_ptr , int , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 70))(__p0, __p1, __p2))

#define jpeg_write_tables(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 160))(__p0))

#define jpeg_destroy_decompress(__p0) \
	(((void (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 46))(__p0))

#define jpeg_simple_progression(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 94))(__p0))

#define jpeg_consume_input(__p0) \
	(((int (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 226))(__p0))

#define jpeg_new_colormap(__p0) \
	(((void (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 220))(__p0))

#define jpeg_copy_critical_parameters(__p0, __p1) \
	(((void (*)(j_decompress_ptr , j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 262))(__p0, __p1))

#define jpeg_abort_decompress(__p0) \
	(((void (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 274))(__p0))

#define jpeg_abort(__p0) \
	(((void (*)(j_common_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 280))(__p0))

#define jpeg_set_defaults(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 52))(__p0))

#define jpeg_finish_compress(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 130))(__p0))

#define jpeg_finish_output(__p0) \
	(((boolean (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 208))(__p0))

#define jpeg_read_coefficients(__p0) \
	(((jvirt_barray_ptr *(*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 250))(__p0))

#define jpeg_add_quant_table(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(j_compress_ptr , int , const unsigned int *, int , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 82))(__p0, __p1, __p2, __p3, __p4))

#define jpeg_start_compress(__p0, __p1) \
	(((void (*)(j_compress_ptr , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 118))(__p0, __p1))

#define jpeg_abort_compress(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 268))(__p0))

#define jpeg_write_marker(__p0, __p1, __p2, __p3) \
	(((void (*)(j_compress_ptr , int , const JOCTET *, unsigned int ))*(void**)((long)(JFIF_BASE_NAME) - 142))(__p0, __p1, __p2, __p3))

#define jpeg_resync_to_restart(__p0, __p1) \
	(((boolean (*)(j_decompress_ptr , int ))*(void**)((long)(JFIF_BASE_NAME) - 292))(__p0, __p1))

#define jpeg_write_m_header(__p0, __p1, __p2) \
	(((void (*)(j_compress_ptr , int , unsigned int ))*(void**)((long)(JFIF_BASE_NAME) - 148))(__p0, __p1, __p2))

#define jpeg_write_scanlines(__p0, __p1, __p2) \
	(((JDIMENSION (*)(j_compress_ptr , JSAMPARRAY , JDIMENSION ))*(void**)((long)(JFIF_BASE_NAME) - 124))(__p0, __p1, __p2))

#define jpeg_read_header(__p0, __p1) \
	(((int (*)(j_decompress_ptr , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 166))(__p0, __p1))

#define jpeg_set_colorspace(__p0, __p1) \
	(((void (*)(j_compress_ptr , J_COLOR_SPACE ))*(void**)((long)(JFIF_BASE_NAME) - 58))(__p0, __p1))

#define jpeg_start_output(__p0, __p1) \
	(((boolean (*)(j_decompress_ptr , int ))*(void**)((long)(JFIF_BASE_NAME) - 202))(__p0, __p1))

#define jpeg_quality_scaling(__p0) \
	(((int (*)(int ))*(void**)((long)(JFIF_BASE_NAME) - 88))(__p0))

#define jpeg_calc_output_dimensions(__p0) \
	(((void (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 232))(__p0))

#define jpeg_default_colorspace(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 64))(__p0))

#define jpeg_destroy(__p0) \
	(((void (*)(j_common_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 286))(__p0))

#define jpeg_CreateCompress(__p0, __p1, __p2) \
	(((void (*)(j_compress_ptr , int , size_t ))*(void**)((long)(JFIF_BASE_NAME) - 28))(__p0, __p1, __p2))

#define jpeg_read_raw_data(__p0, __p1, __p2) \
	(((JDIMENSION (*)(j_decompress_ptr , JSAMPIMAGE , JDIMENSION ))*(void**)((long)(JFIF_BASE_NAME) - 190))(__p0, __p1, __p2))

#define jpeg_write_coefficients(__p0, __p1) \
	(((void (*)(j_compress_ptr , jvirt_barray_ptr *))*(void**)((long)(JFIF_BASE_NAME) - 256))(__p0, __p1))

#define jpeg_alloc_quant_table(__p0) \
	(((JQUANT_TBL *(*)(j_common_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 106))(__p0))

#define jpeg_alloc_huff_table(__p0) \
	(((JHUFF_TBL *(*)(j_common_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 112))(__p0))

#define jpeg_set_linear_quality(__p0, __p1, __p2) \
	(((void (*)(j_compress_ptr , int , boolean ))*(void**)((long)(JFIF_BASE_NAME) - 76))(__p0, __p1, __p2))

#define jpeg_input_complete(__p0) \
	(((boolean (*)(j_decompress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 214))(__p0))

#define jpeg_destroy_compress(__p0) \
	(((void (*)(j_compress_ptr ))*(void**)((long)(JFIF_BASE_NAME) - 40))(__p0))

#define jpeg_CreateDecompress(__p0, __p1, __p2) \
	(((void (*)(j_decompress_ptr , int , size_t ))*(void**)((long)(JFIF_BASE_NAME) - 34))(__p0, __p1, __p2))

#define jpeg_save_markers(__p0, __p1, __p2) \
	(((void (*)(j_decompress_ptr , int , unsigned int ))*(void**)((long)(JFIF_BASE_NAME) - 238))(__p0, __p1, __p2))

#endif /* !_PPCINLINE_JFIF_H */
