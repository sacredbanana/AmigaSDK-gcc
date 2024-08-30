#ifndef LIBRARIES_JFIF_H
#define LIBRARIES_JFIF_H

/*

	MorphOS Shared JPEGLib
	
	jfif.library include
	
	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.

*/

#include <sys/types.h>


/* jconfig.h/jmorecfg.h mimic */


#define BITS_IN_JSAMPLE	8
#define MAX_COMPONENTS	10

typedef unsigned char JSAMPLE;
typedef short JCOEF;
typedef unsigned char JOCTET;
typedef unsigned int JDIMENSION;

typedef unsigned char UINT8;
typedef unsigned short UINT16;

typedef int boolean;


#define GETJSAMPLE(value)	((int) (value))
#define GETJOCTET(value)	(value)

#define MAXJSAMPLE	255
#define CENTERJSAMPLE	128

#define JPEG_MAX_DIMENSION	65500L


#define METHODDEF(type)	static type
#define JMETHOD(type,methodname,arglist)	type (*methodname) arglist

#ifndef FAR
#define FAR
#endif


/* jpeglib.h mimic */


#define JPEG_LIB_VERSION	62

#define DCTSIZE	8
#define DCTSIZE2	64
#define NUM_QUANT_TBLS	4
#define NUM_HUFF_TBLS	4
#define NUM_ARITH_TBLS	16
#define MAX_COMPS_IN_SCAN	4
#define MAX_SAMP_FACTOR	4
#define C_MAX_BLOCKS_IN_MCU	10
#define D_MAX_BLOCKS_IN_MCU	10


typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;

typedef JCOEF JBLOCK[DCTSIZE2];
typedef JBLOCK *JBLOCKROW;
typedef JBLOCKROW *JBLOCKARRAY;
typedef JBLOCKARRAY *JBLOCKIMAGE;

typedef JCOEF *JCOEFPTR;


/* DCT coefficient quantization tables. */
typedef struct {
	UINT16 quantval[DCTSIZE2];
	boolean sent_table;
} JQUANT_TBL;


/* Huffman coding tables. */
typedef struct {
	UINT8 bits[17];
	UINT8 huffval[256];
	boolean sent_table;
} JHUFF_TBL;


/* Basic info about one component (color channel). */
typedef struct {
	int component_id;
	int component_index;
	int h_samp_factor;
	int v_samp_factor;
	int quant_tbl_no;
	int dc_tbl_no;
	int ac_tbl_no;
	JDIMENSION width_in_blocks;
	JDIMENSION height_in_blocks;
	int DCT_scaled_size;
	JDIMENSION downsampled_width;
	JDIMENSION downsampled_height;
	boolean component_needed;
	int MCU_width;
	int MCU_height;
	int MCU_blocks;
	int MCU_sample_width;
	int last_col_width;
	int last_row_height;
	JQUANT_TBL * quant_table;
	void * dct_table;
} jpeg_component_info;


/* The script for encoding a multiple-scan file is an array of these: */
typedef struct {
	int comps_in_scan;
	int component_index[MAX_COMPS_IN_SCAN];
	int Ss, Se;
	int Ah, Al;
} jpeg_scan_info;


/* The decompressor can save APPn and COM markers in a list of these: */
typedef struct jpeg_marker_struct * jpeg_saved_marker_ptr;

struct jpeg_marker_struct {
	jpeg_saved_marker_ptr next;
	UINT8 marker;
	unsigned int original_length;
	unsigned int data_length;
	JOCTET * data;
};

/* Known color spaces. */
typedef enum {
	JCS_UNKNOWN,
	JCS_GRAYSCALE,
	JCS_RGB,
	JCS_YCbCr,
	JCS_CMYK,
	JCS_YCCK
} J_COLOR_SPACE;

/* DCT/IDCT algorithm options. */
typedef enum {
	JDCT_ISLOW,
	JDCT_IFAST,
	JDCT_FLOAT
} J_DCT_METHOD;

#define JDCT_DEFAULT  JDCT_ISLOW
#define JDCT_FASTEST  JDCT_IFAST

/* Dithering options for decompression. */
typedef enum {
	JDITHER_NONE,
	JDITHER_ORDERED,
	JDITHER_FS
} J_DITHER_MODE;




#define jpeg_common_fields \
	struct jpeg_error_mgr * err; \
	struct jpeg_memory_mgr * mem; \
	struct jpeg_progress_mgr * progress; \
	void * client_data; \
	boolean is_decompressor; \
	int global_state
  
typedef
struct jpeg_common_struct {
	jpeg_common_fields;
} *j_common_ptr;


typedef
struct jpeg_compress_struct {
	jpeg_common_fields;

	struct jpeg_destination_mgr * dest;

	JDIMENSION image_width;	/* input image width */
	JDIMENSION image_height;	/* input image height */
	int input_components;	/* # of color components in input image */
	J_COLOR_SPACE in_color_space;	/* colorspace of input image */

	double input_gamma;	/* image gamma of input image */

	int data_precision;	/* bits of precision in image data */

	int num_components;	/* # of color components in JPEG image */
	J_COLOR_SPACE jpeg_color_space; /* colorspace of JPEG image */

	jpeg_component_info * comp_info;

	JQUANT_TBL * quant_tbl_ptrs[NUM_QUANT_TBLS];

	JHUFF_TBL * dc_huff_tbl_ptrs[NUM_HUFF_TBLS];
	JHUFF_TBL * ac_huff_tbl_ptrs[NUM_HUFF_TBLS];

	UINT8 arith_dc_L[NUM_ARITH_TBLS]; /* L values for DC arith-coding tables */
	UINT8 arith_dc_U[NUM_ARITH_TBLS]; /* U values for DC arith-coding tables */
	UINT8 arith_ac_K[NUM_ARITH_TBLS]; /* Kx values for AC arith-coding tables */

	int num_scans;	/* # of entries in scan_info array */
	const jpeg_scan_info * scan_info; /* script for multi-scan file, or NULL */

	boolean raw_data_in;	/* TRUE=caller supplies downsampled data */
	boolean arith_code;	/* TRUE=arithmetic coding, FALSE=Huffman */
	boolean optimize_coding;	/* TRUE=optimize entropy encoding parms */
	boolean CCIR601_sampling;	/* TRUE=first samples are cosited */
	int smoothing_factor;	/* 1..100, or 0 for no input smoothing */
	J_DCT_METHOD dct_method;	/* DCT algorithm selector */

	unsigned int restart_interval; /* MCUs per restart, or 0 for no restart */
	int restart_in_rows;	/* if > 0, MCU rows per restart interval */

	boolean write_JFIF_header;	/* should a JFIF marker be written? */
	UINT8 JFIF_major_version;	/* What to write for the JFIF version number */
	UINT8 JFIF_minor_version;

	UINT8 density_unit;	/* JFIF code for pixel size units */
	UINT16 X_density;	/* Horizontal pixel density */
	UINT16 Y_density;	/* Vertical pixel density */
	boolean write_Adobe_marker;	/* should an Adobe marker be written? */

	JDIMENSION next_scanline;	/* 0 .. image_height-1  */

	boolean progressive_mode;	/* TRUE if scan script uses progressive mode */
	int max_h_samp_factor;	/* largest h_samp_factor */
	int max_v_samp_factor;	/* largest v_samp_factor */

	JDIMENSION total_iMCU_rows;	/* # of iMCU rows to be input to coef ctlr */

	int comps_in_scan;	/* # of JPEG components in this scan */
	jpeg_component_info * cur_comp_info[MAX_COMPS_IN_SCAN];
	/* *cur_comp_info[i] describes component that appears i'th in SOS */

	JDIMENSION MCUs_per_row;	/* # of MCUs across the image */
	JDIMENSION MCU_rows_in_scan;	/* # of MCU rows in the image */

	int blocks_in_MCU;	/* # of DCT blocks per MCU */
	int MCU_membership[C_MAX_BLOCKS_IN_MCU];

	int Ss, Se, Ah, Al;	/* progressive JPEG parameters for scan */

	struct jpeg_comp_master * master;
	struct jpeg_c_main_controller * main;
	struct jpeg_c_prep_controller * prep;
	struct jpeg_c_coef_controller * coef;
	struct jpeg_marker_writer * marker;
	struct jpeg_color_converter * cconvert;
	struct jpeg_downsampler * downsample;
	struct jpeg_forward_dct * fdct;
	struct jpeg_entropy_encoder * entropy;
	jpeg_scan_info * script_space; /* workspace for jpeg_simple_progression */
	int script_space_size;
} *j_compress_ptr;


/* Master record for a decompression instance */
typedef
struct jpeg_decompress_struct {
	jpeg_common_fields;	/* Fields shared with jpeg_compress_struct */

	/* Source of compressed data */
	struct jpeg_source_mgr * src;

	/* Basic description of image --- filled in by jpeg_read_header(). */
	/* Application may inspect these values to decide how to process image. */

	JDIMENSION image_width;	/* nominal image width (from SOF marker) */
	JDIMENSION image_height;	/* nominal image height */
	int num_components;	/* # of color components in JPEG image */
	J_COLOR_SPACE jpeg_color_space; /* colorspace of JPEG image */

	/* Decompression processing parameters --- these fields must be set before
	 * calling jpeg_start_decompress().  Note that jpeg_read_header() initializes
	 * them to default values.
	 */

	J_COLOR_SPACE out_color_space; /* colorspace for output */

	unsigned int scale_num, scale_denom; /* fraction by which to scale image */

	double output_gamma;	/* image gamma wanted in output */

	boolean buffered_image;	/* TRUE=multiple output passes */
	boolean raw_data_out;	/* TRUE=downsampled data wanted */

	J_DCT_METHOD dct_method;	/* IDCT algorithm selector */
	boolean do_fancy_upsampling;	/* TRUE=apply fancy upsampling */
	boolean do_block_smoothing;	/* TRUE=apply interblock smoothing */

	boolean quantize_colors;	/* TRUE=colormapped output wanted */
	/* the following are ignored if not quantize_colors: */
	J_DITHER_MODE dither_mode;	/* type of color dithering to use */
	boolean two_pass_quantize;	/* TRUE=use two-pass color quantization */
	int desired_number_of_colors;	/* max # colors to use in created colormap */
	/* these are significant only in buffered-image mode: */
	boolean enable_1pass_quant;	/* enable future use of 1-pass quantizer */
	boolean enable_external_quant;/* enable future use of external colormap */
	boolean enable_2pass_quant;	/* enable future use of 2-pass quantizer */

	/* Description of actual output image that will be returned to application.
	 * These fields are computed by jpeg_start_decompress().
	 * You can also use jpeg_calc_output_dimensions() to determine these values
	 * in advance of calling jpeg_start_decompress().
	 */

	JDIMENSION output_width;	/* scaled image width */
	JDIMENSION output_height;	/* scaled image height */
	int out_color_components;	/* # of color components in out_color_space */
	int output_components;	/* # of color components returned */
	/* output_components is 1 (a colormap index) when quantizing colors;
	 * otherwise it equals out_color_components.
	 */
	int rec_outbuf_height;	/* min recommended height of scanline buffer */
	/* If the buffer passed to jpeg_read_scanlines() is less than this many rows
	 * high, space and time will be wasted due to unnecessary data copying.
	 * Usually rec_outbuf_height will be 1 or 2, at most 4.
	 */

	/* When quantizing colors, the output colormap is described by these fields.
	 * The application can supply a colormap by setting colormap non-NULL before
	 * calling jpeg_start_decompress; otherwise a colormap is created during
	 * jpeg_start_decompress or jpeg_start_output.
	 * The map has out_color_components rows and actual_number_of_colors columns.
	 */
	int actual_number_of_colors;	/* number of entries in use */
	JSAMPARRAY colormap;	/* The color map as a 2-D pixel array */

	/* State variables: these variables indicate the progress of decompression.
	 * The application may examine these but must not modify them.
	 */

	/* Row index of next scanline to be read from jpeg_read_scanlines().
	 * Application may use this to control its processing loop, e.g.,
	 * "while (output_scanline < output_height)".
	 */
	JDIMENSION output_scanline;	/* 0 .. output_height-1  */

	/* Current input scan number and number of iMCU rows completed in scan.
	 * These indicate the progress of the decompressor input side.
	 */
	int input_scan_number;	/* Number of SOS markers seen so far */
	JDIMENSION input_iMCU_row;	/* Number of iMCU rows completed */

	/* The "output scan number" is the notional scan being displayed by the
	 * output side.  The decompressor will not allow output scan/row number
	 * to get ahead of input scan/row, but it can fall arbitrarily far behind.
	 */
	int output_scan_number;	/* Nominal scan number being displayed */
	JDIMENSION output_iMCU_row;	/* Number of iMCU rows read */

	/* Current progression status.  coef_bits[c][i] indicates the precision
	 * with which component c's DCT coefficient i (in zigzag order) is known.
	 * It is -1 when no data has yet been received, otherwise it is the point
	 * transform (shift) value for the most recent scan of the coefficient
	 * (thus, 0 at completion of the progression).
	 * This pointer is NULL when reading a non-progressive file.
	 */
	int (*coef_bits)[DCTSIZE2];	/* -1 or current Al value for each coef */

	/* Internal JPEG parameters --- the application usually need not look at
	 * these fields.  Note that the decompressor output side may not use
	 * any parameters that can change between scans.
	 */

	/* Quantization and Huffman tables are carried forward across input
	 * datastreams when processing abbreviated JPEG datastreams.
	 */

	JQUANT_TBL * quant_tbl_ptrs[NUM_QUANT_TBLS];
	/* ptrs to coefficient quantization tables, or NULL if not defined */

	JHUFF_TBL * dc_huff_tbl_ptrs[NUM_HUFF_TBLS];
	JHUFF_TBL * ac_huff_tbl_ptrs[NUM_HUFF_TBLS];
	/* ptrs to Huffman coding tables, or NULL if not defined */

	/* These parameters are never carried across datastreams, since they
	 * are given in SOF/SOS markers or defined to be reset by SOI.
	 */

	int data_precision;	/* bits of precision in image data */

	jpeg_component_info * comp_info;
	/* comp_info[i] describes component that appears i'th in SOF */

	boolean progressive_mode;	/* TRUE if SOFn specifies progressive mode */
	boolean arith_code;	/* TRUE=arithmetic coding, FALSE=Huffman */

	UINT8 arith_dc_L[NUM_ARITH_TBLS]; /* L values for DC arith-coding tables */
	UINT8 arith_dc_U[NUM_ARITH_TBLS]; /* U values for DC arith-coding tables */
	UINT8 arith_ac_K[NUM_ARITH_TBLS]; /* Kx values for AC arith-coding tables */

	unsigned int restart_interval; /* MCUs per restart interval, or 0 for no restart */

	/* These fields record data obtained from optional markers recognized by
	 * the JPEG library.
	 */
	boolean saw_JFIF_marker;	/* TRUE iff a JFIF APP0 marker was found */
	/* Data copied from JFIF marker; only valid if saw_JFIF_marker is TRUE: */
	UINT8 JFIF_major_version;	/* JFIF version number */
	UINT8 JFIF_minor_version;
	UINT8 density_unit;	/* JFIF code for pixel size units */
	UINT16 X_density;	/* Horizontal pixel density */
	UINT16 Y_density;	/* Vertical pixel density */
	boolean saw_Adobe_marker;	/* TRUE iff an Adobe APP14 marker was found */
	UINT8 Adobe_transform;	/* Color transform code from Adobe marker */

	boolean CCIR601_sampling;	/* TRUE=first samples are cosited */

	/* Aside from the specific data retained from APPn markers known to the
	 * library, the uninterpreted contents of any or all APPn and COM markers
	 * can be saved in a list for examination by the application.
	 */
	jpeg_saved_marker_ptr marker_list; /* Head of list of saved markers */

	/* Remaining fields are known throughout decompressor, but generally
	 * should not be touched by a surrounding application.
	 */

	/*
	 * These fields are computed during decompression startup
	 */
	int max_h_samp_factor;	/* largest h_samp_factor */
	int max_v_samp_factor;	/* largest v_samp_factor */

	int min_DCT_scaled_size;	/* smallest DCT_scaled_size of any component */

	JDIMENSION total_iMCU_rows;	/* # of iMCU rows in image */
	/* The coefficient controller's input and output progress is measured in
	 * units of "iMCU" (interleaved MCU) rows.  These are the same as MCU rows
	 * in fully interleaved JPEG scans, but are used whether the scan is
	 * interleaved or not.  We define an iMCU row as v_samp_factor DCT block
	 * rows of each component.  Therefore, the IDCT output contains
	 * v_samp_factor*DCT_scaled_size sample rows of a component per iMCU row.
	 */

	JSAMPLE * sample_range_limit; /* table for fast range-limiting */

	/*
	 * These fields are valid during any one scan.
	 * They describe the components and MCUs actually appearing in the scan.
	 * Note that the decompressor output side must not use these fields.
	 */
	int comps_in_scan;	/* # of JPEG components in this scan */
	jpeg_component_info * cur_comp_info[MAX_COMPS_IN_SCAN];
	/* *cur_comp_info[i] describes component that appears i'th in SOS */

	JDIMENSION MCUs_per_row;	/* # of MCUs across the image */
	JDIMENSION MCU_rows_in_scan;	/* # of MCU rows in the image */

	int blocks_in_MCU;	/* # of DCT blocks per MCU */
	int MCU_membership[D_MAX_BLOCKS_IN_MCU];
	/* MCU_membership[i] is index in cur_comp_info of component owning */
	/* i'th block in an MCU */

	int Ss, Se, Ah, Al;	/* progressive JPEG parameters for scan */

	/* This field is shared between entropy decoder and marker parser.
	 * It is either zero or the code of a JPEG marker that has been
	 * read from the data source, but has not yet been processed.
	 */
	int unread_marker;

	/*
	 * Links to decompression subobjects (methods, private variables of modules)
	 */
	struct jpeg_decomp_master * master;
	struct jpeg_d_main_controller * main;
	struct jpeg_d_coef_controller * coef;
	struct jpeg_d_post_controller * post;
	struct jpeg_input_controller * inputctl;
	struct jpeg_marker_reader * marker;
	struct jpeg_entropy_decoder * entropy;
	struct jpeg_inverse_dct * idct;
	struct jpeg_upsampler * upsample;
	struct jpeg_color_deconverter * cconvert;
	struct jpeg_color_quantizer * cquantize;
} *j_decompress_ptr;


/* "Object" declarations for JPEG modules that may be supplied or called
 * directly by the surrounding application.
 * As with all objects in the JPEG library, these structs only define the
 * publicly visible methods and state variables of a module.  Additional
 * private fields may exist after the public ones.
 */


#ifdef __cplusplus
extern "C" {
#endif

/* Error handler object */

struct jpeg_error_mgr {
	/* Error exit handler: does not return to caller */
	JMETHOD(void, error_exit, (j_common_ptr cinfo));
	/* Conditionally emit a trace or warning message */
	JMETHOD(void, emit_message, (j_common_ptr cinfo, int msg_level));
	/* Routine that actually outputs a trace or error message */
	JMETHOD(void, output_message, (j_common_ptr cinfo));
	/* Format a message string for the most recent JPEG error or message */
	JMETHOD(void, format_message, (j_common_ptr cinfo, char * buffer));
#define JMSG_LENGTH_MAX  200	/* recommended size of format_message buffer */
	/* Reset error state variables at start of a new image */
	JMETHOD(void, reset_error_mgr, (j_common_ptr cinfo));

	/* The message ID code and any parameters are saved here.
	 * A message can have one string parameter or up to 8 int parameters.
	 */
	int msg_code;
#define JMSG_STR_PARM_MAX  80
	union {
		int i[8];
		char s[JMSG_STR_PARM_MAX];
	} msg_parm;

	/* Standard state variables for error facility */

	int trace_level;	/* max msg_level that will be displayed */

	/* For recoverable corrupt-data errors, we emit a warning message,
	 * but keep going unless emit_message chooses to abort.  emit_message
	 * should count warnings in num_warnings.  The surrounding application
	 * can check for bad data by seeing if num_warnings is nonzero at the
	 * end of processing.
	 */
	long num_warnings;	/* number of corrupt-data warnings */

	/* These fields point to the table(s) of error message strings.
	 * An application can change the table pointer to switch to a different
	 * message list (typically, to change the language in which errors are
	 * reported).  Some applications may wish to add additional error codes
	 * that will be handled by the JPEG library error mechanism; the second
	 * table pointer is used for this purpose.
	 *
	 * First table includes all errors generated by JPEG library itself.
	 * Error code 0 is reserved for a "no such error string" message.
	 */
	const char * const * jpeg_message_table; /* Library errors */
	int last_jpeg_message;    /* Table contains strings 0..last_jpeg_message */
	/* Second table can be added by application (see cjpeg/djpeg for example).
	 * It contains strings numbered first_addon_message..last_addon_message.
	 */
	const char * const * addon_message_table; /* Non-library errors */
	int first_addon_message;	/* code for first string in addon table */
	int last_addon_message;	/* code for last string in addon table */
};


/* Progress monitor object */

struct jpeg_progress_mgr {
	JMETHOD(void, progress_monitor, (j_common_ptr cinfo));

	long pass_counter;	/* work units completed in this pass */
	long pass_limit;	/* total number of work units in this pass */
	int completed_passes;	/* passes completed so far */
	int total_passes;	/* total number of passes expected */
};


/* Data destination object for compression */

struct jpeg_destination_mgr {
	JOCTET * next_output_byte;	/* => next byte to write in buffer */
	size_t free_in_buffer;	/* # of byte spaces remaining in buffer */

	JMETHOD(void, init_destination, (j_compress_ptr cinfo));
	JMETHOD(boolean, empty_output_buffer, (j_compress_ptr cinfo));
	JMETHOD(void, term_destination, (j_compress_ptr cinfo));
};


/* Data source object for decompression */

struct jpeg_source_mgr {
	const JOCTET * next_input_byte;	/* => next byte to read from buffer */
	size_t bytes_in_buffer;	/* # of bytes remaining in buffer */

	JMETHOD(void, init_source, (j_decompress_ptr cinfo));
	JMETHOD(boolean, fill_input_buffer, (j_decompress_ptr cinfo));
	JMETHOD(void, skip_input_data, (j_decompress_ptr cinfo, long num_bytes));
	JMETHOD(boolean, resync_to_restart, (j_decompress_ptr cinfo, int desired));
	JMETHOD(void, term_source, (j_decompress_ptr cinfo));
};


/* Memory manager object.
 * Allocates "small" objects (a few K total), "large" objects (tens of K),
 * and "really big" objects (virtual arrays with backing store if needed).
 * The memory manager does not allow individual objects to be freed; rather,
 * each created object is assigned to a pool, and whole pools can be freed
 * at once.  This is faster and more convenient than remembering exactly what
 * to free, especially where malloc()/free() are not too speedy.
 * NB: alloc routines never return NULL.  They exit to error_exit if not
 * successful.
 */

#define JPOOL_PERMANENT	0	/* lasts until master record is destroyed */
#define JPOOL_IMAGE	1	/* lasts until done with image/datastream */
#define JPOOL_NUMPOOLS	2

typedef struct jvirt_sarray_control * jvirt_sarray_ptr;
typedef struct jvirt_barray_control * jvirt_barray_ptr;


struct jpeg_memory_mgr {
	/* Method pointers */
	JMETHOD(void *, alloc_small, (j_common_ptr cinfo, int pool_id, size_t sizeofobject));
	JMETHOD(void FAR *, alloc_large, (j_common_ptr cinfo, int pool_id, size_t sizeofobject));
	JMETHOD(JSAMPARRAY, alloc_sarray, (j_common_ptr cinfo, int pool_id, JDIMENSION samplesperrow, JDIMENSION numrows));
	JMETHOD(JBLOCKARRAY, alloc_barray, (j_common_ptr cinfo, int pool_id, JDIMENSION blocksperrow, JDIMENSION numrows));
	JMETHOD(jvirt_sarray_ptr, request_virt_sarray, (j_common_ptr cinfo, int pool_id, boolean pre_zero, JDIMENSION samplesperrow, JDIMENSION numrows, JDIMENSION maxaccess));
	JMETHOD(jvirt_barray_ptr, request_virt_barray, (j_common_ptr cinfo, int pool_id, boolean pre_zero, JDIMENSION blocksperrow, JDIMENSION numrows, JDIMENSION maxaccess));
	JMETHOD(void, realize_virt_arrays, (j_common_ptr cinfo));
	JMETHOD(JSAMPARRAY, access_virt_sarray, (j_common_ptr cinfo, jvirt_sarray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, boolean writable));
	JMETHOD(JBLOCKARRAY, access_virt_barray, (j_common_ptr cinfo, jvirt_barray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, boolean writable));
	JMETHOD(void, free_pool, (j_common_ptr cinfo, int pool_id));
	JMETHOD(void, self_destruct, (j_common_ptr cinfo));

	/* Limit on memory allocation for this JPEG object.  (Note that this is
	 * merely advisory, not a guaranteed maximum; it only affects the space
	 * used for virtual-array buffers.)  May be changed by outer application
	 * after creating the JPEG object.
	 */
	long max_memory_to_use;

	/* Maximum allocation request accepted by alloc_large. */
	long max_alloc_chunk;
};


/* Routine signature for application-supplied marker processing methods.
 * Need not pass marker code since it is stored in cinfo->unread_marker.
 */
typedef JMETHOD(boolean, jpeg_marker_parser_method, (j_decompress_ptr cinfo));


/* Declarations for routines called by application.
 * The JPP macro hides prototype parameters from compilers that can't cope.
 * Note JPP requires double parentheses.
 */

#define JPP(arglist)	arglist


/* Return value (jpeg_read_header) is one of: */
#define JPEG_SUSPENDED		0 /* Suspended due to lack of input data */
#define JPEG_HEADER_OK		1 /* Found valid image datastream */
#define JPEG_HEADER_TABLES_ONLY	2 /* Found valid table-specs-only datastream */
/* If you pass require_image = TRUE (normal case), you need not check for
 * a TABLES_ONLY return code; an abbreviated file will cause an error exit.
 * JPEG_SUSPENDED is only possible if you use a data source module that can
 * give a suspension return (the stdio source module doesn't).
 */

/* Return value (jpeg_consume_input) is one of: */
/* #define JPEG_SUSPENDED	0    Suspended due to lack of input data */
#define JPEG_REACHED_SOS	1 /* Reached start of new scan */
#define JPEG_REACHED_EOI	2 /* Reached end of image */
#define JPEG_ROW_COMPLETED	3 /* Completed one iMCU row */
#define JPEG_SCAN_COMPLETED	4 /* Completed last iMCU row of a scan */


#define JPEG_RST0	0xD0
#define JPEG_EOI	0xD9
#define JPEG_APP0	0xE0
#define JPEG_COM	0xFE


/* These defintions are sometimes needed by some applications */
#ifdef JPEG_INTERNAL_OPTIONS

#define RGB_RED		0	/* Offset of Red in an RGB scanline element */
#define RGB_GREEN	1	/* Offset of Green */
#define RGB_BLUE	2	/* Offset of Blue */
#define RGB_PIXELSIZE	3	/* JSAMPLEs per RGB scanline element */

#endif /* JPEG_INTERNAL_OPTIONS */

#ifdef __cplusplus
}
#endif

#endif /* LIBRARIES_JFIF_H */
