#ifndef CLIB_JFIF_PROTOS_H
#define CLIB_JFIF_PROTOS_H

/*
	jfif.library C prototypes

	Copyright � 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_JFIF_H
# include <libraries/jfif.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

void jpeg_CreateCompress(j_compress_ptr cinfo,int version, size_t structsize);
void jpeg_CreateDecompress(j_decompress_ptr cinfo,int version, size_t structsize);

#define jpeg_create_compress(cinfo)	jpeg_CreateCompress((cinfo), JPEG_LIB_VERSION, (size_t) sizeof(struct jpeg_compress_struct))
#define jpeg_create_decompress(cinfo)	jpeg_CreateDecompress((cinfo), JPEG_LIB_VERSION, (size_t) sizeof(struct jpeg_decompress_struct))

void jpeg_destroy_compress(j_compress_ptr cinfo);
void jpeg_destroy_decompress(j_decompress_ptr cinfo);
void jpeg_set_defaults(j_compress_ptr cinfo);
void jpeg_set_colorspace(j_compress_ptr cinfo, J_COLOR_SPACE colorspace);
void jpeg_default_colorspace(j_compress_ptr cinfo);
void jpeg_set_quality(j_compress_ptr cinfo, int quality, boolean force_baseline);
void jpeg_set_linear_quality(j_compress_ptr cinfo, int scale_factor, boolean force_baseline);
void jpeg_add_quant_table(j_compress_ptr cinfo, int which_tbl, const unsigned int *basic_table, int scale_factor, boolean force_baseline);
int jpeg_quality_scaling(int quality);
void jpeg_simple_progression(j_compress_ptr cinfo);
void jpeg_suppress_tables(j_compress_ptr cinfo, boolean suppress);
JQUANT_TBL * jpeg_alloc_quant_table(j_common_ptr cinfo);
JHUFF_TBL * jpeg_alloc_huff_table(j_common_ptr cinfo);
void jpeg_start_compress(j_compress_ptr cinfo, boolean write_all_tables);
JDIMENSION jpeg_write_scanlines(j_compress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION num_lines);
void jpeg_finish_compress(j_compress_ptr cinfo);
JDIMENSION jpeg_write_raw_data(j_compress_ptr cinfo, JSAMPIMAGE data, JDIMENSION num_lines);
void jpeg_write_marker(j_compress_ptr cinfo, int marker, const JOCTET * dataptr, unsigned int datalen);
void jpeg_write_m_header(j_compress_ptr cinfo, int marker, unsigned int datalen);
void jpeg_write_m_byte(j_compress_ptr cinfo, int val);
void jpeg_write_tables(j_compress_ptr cinfo);
int jpeg_read_header(j_decompress_ptr cinfo, boolean require_image);
boolean jpeg_start_decompress(j_decompress_ptr cinfo);
JDIMENSION jpeg_read_scanlines(j_decompress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION max_lines);
boolean jpeg_finish_decompress(j_decompress_ptr cinfo);
JDIMENSION jpeg_read_raw_data(j_decompress_ptr cinfo, JSAMPIMAGE data, JDIMENSION max_lines);
boolean jpeg_has_multiple_scans(j_decompress_ptr cinfo);
boolean jpeg_start_output(j_decompress_ptr cinfo, int scan_number);
boolean jpeg_finish_output(j_decompress_ptr cinfo);
boolean jpeg_input_complete(j_decompress_ptr cinfo);
void jpeg_new_colormap(j_decompress_ptr cinfo);
int jpeg_consume_input(j_decompress_ptr cinfo);
void jpeg_calc_output_dimensions(j_decompress_ptr cinfo);
void jpeg_save_markers(j_decompress_ptr cinfo, int marker_code, unsigned int length_limit);
void jpeg_set_marker_processor(j_decompress_ptr cinfo, int marker_code, jpeg_marker_parser_method routine);
jvirt_barray_ptr * jpeg_read_coefficients(j_decompress_ptr cinfo);
void jpeg_write_coefficients(j_compress_ptr cinfo, jvirt_barray_ptr * coef_arrays);
void jpeg_copy_critical_parameters(j_decompress_ptr srcinfo, j_compress_ptr dstinfo);
void jpeg_abort_compress(j_compress_ptr cinfo);
void jpeg_abort_decompress(j_decompress_ptr cinfo);
void jpeg_abort(j_common_ptr cinfo);
void jpeg_destroy(j_common_ptr cinfo);
boolean jpeg_resync_to_restart(j_decompress_ptr cinfo, int desired);

/* for the benefit of the link library */
struct jpeg_error_mgr *jpeg_std_error(struct jpeg_error_mgr * err);

#include <stdio.h>

void jpeg_stdio_dest(j_compress_ptr cinfo, FILE * outfile);
void jpeg_stdio_src(j_decompress_ptr cinfo, FILE * infile);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_JFIF_PROTOS_H */
