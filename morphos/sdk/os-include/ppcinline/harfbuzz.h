/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_HARFBUZZ_H
#define _PPCINLINE_HARFBUZZ_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef HARFBUZZ_BASE_NAME
#define HARFBUZZ_BASE_NAME HarfbuzzBase
#endif /* !HARFBUZZ_BASE_NAME */

#define hb_tag_from_string(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_tag_t (*)(const char *, int ))*(void**)(__base - 406))(__t__p0, __t__p1));\
	})

#define hb_tag_to_string(__p0, __p1) \
	({ \
		hb_tag_t  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_tag_t , char *))*(void**)(__base - 412))(__t__p0, __t__p1));\
	})

#define hb_direction_from_string(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_direction_t (*)(const char *, int ))*(void**)(__base - 418))(__t__p0, __t__p1));\
	})

#define hb_direction_to_string(__p0) \
	({ \
		hb_direction_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(hb_direction_t ))*(void**)(__base - 424))(__t__p0));\
	})

#define hb_language_from_string(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_language_t (*)(const char *, int ))*(void**)(__base - 430))(__t__p0, __t__p1));\
	})

#define hb_language_to_string(__p0) \
	({ \
		hb_language_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(hb_language_t ))*(void**)(__base - 436))(__t__p0));\
	})

#define hb_language_get_default() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_language_t (*)(void))*(void**)(__base - 442))());\
	})

#define hb_script_from_iso15924_tag(__p0) \
	({ \
		hb_tag_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_script_t (*)(hb_tag_t ))*(void**)(__base - 448))(__t__p0));\
	})

#define hb_script_from_string(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_script_t (*)(const char *, int ))*(void**)(__base - 454))(__t__p0, __t__p1));\
	})

#define hb_script_to_iso15924_tag(__p0) \
	({ \
		hb_script_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_tag_t (*)(hb_script_t ))*(void**)(__base - 460))(__t__p0));\
	})

#define hb_script_get_horizontal_direction(__p0) \
	({ \
		hb_script_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_direction_t (*)(hb_script_t ))*(void**)(__base - 466))(__t__p0));\
	})

#define hb_feature_from_string(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		hb_feature_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const char *, int , hb_feature_t *))*(void**)(__base - 1156))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_feature_to_string(__p0, __p1, __p2) \
	({ \
		hb_feature_t * __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_feature_t *, char *, unsigned int ))*(void**)(__base - 1162))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_variation_from_string(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		hb_variation_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const char *, int , hb_variation_t *))*(void**)(__base - 1630))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_variation_to_string(__p0, __p1, __p2) \
	({ \
		hb_variation_t * __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_variation_t *, char *, unsigned int ))*(void**)(__base - 1636))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_blob_create(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const char * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		hb_memory_mode_t  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		hb_destroy_func_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(const char *, unsigned int , hb_memory_mode_t , void *, hb_destroy_func_t ))*(void**)(__base - 28))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_blob_create_sub_blob(__p0, __p1, __p2) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_blob_t *, unsigned int , unsigned int ))*(void**)(__base - 34))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_blob_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(void))*(void**)(__base - 40))());\
	})

#define hb_blob_reference(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_blob_t *))*(void**)(__base - 46))(__t__p0));\
	})

#define hb_blob_destroy(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_blob_t *))*(void**)(__base - 52))(__t__p0));\
	})

#define hb_blob_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_blob_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_blob_get_user_data(__p0, __p1) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_blob_t *, hb_user_data_key_t *))*(void**)(__base - 64))(__t__p0, __t__p1));\
	})

#define hb_blob_make_immutable(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_blob_t *))*(void**)(__base - 70))(__t__p0));\
	})

#define hb_blob_is_immutable(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_blob_t *))*(void**)(__base - 76))(__t__p0));\
	})

#define hb_blob_get_length(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_blob_t *))*(void**)(__base - 82))(__t__p0));\
	})

#define hb_blob_get_data(__p0, __p1) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(hb_blob_t *, unsigned int *))*(void**)(__base - 88))(__t__p0, __t__p1));\
	})

#define hb_blob_get_data_writable(__p0, __p1) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(hb_blob_t *, unsigned int *))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define hb_blob_copy_writable_or_fail(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_blob_t *))*(void**)(__base - 1786))(__t__p0));\
	})

#define hb_segment_properties_equal(__p0, __p1) \
	({ \
		const hb_segment_properties_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_segment_properties_t *, const hb_segment_properties_t *))*(void**)(__base - 100))(__t__p0, __t__p1));\
	})

#define hb_segment_properties_hash(__p0) \
	({ \
		const hb_segment_properties_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(const hb_segment_properties_t *))*(void**)(__base - 106))(__t__p0));\
	})

#define hb_buffer_create() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_t *(*)(void))*(void**)(__base - 112))());\
	})

#define hb_buffer_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_t *(*)(void))*(void**)(__base - 118))());\
	})

#define hb_buffer_reference(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_t *(*)(hb_buffer_t *))*(void**)(__base - 124))(__t__p0));\
	})

#define hb_buffer_destroy(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 130))(__t__p0));\
	})

#define hb_buffer_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_get_user_data(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_buffer_t *, hb_user_data_key_t *))*(void**)(__base - 142))(__t__p0, __t__p1));\
	})

#define hb_buffer_set_content_type(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_content_type_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_buffer_content_type_t ))*(void**)(__base - 148))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_content_type(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_content_type_t (*)(hb_buffer_t *))*(void**)(__base - 154))(__t__p0));\
	})

#define hb_buffer_set_unicode_funcs(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_unicode_funcs_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_unicode_funcs_t *))*(void**)(__base - 160))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_unicode_funcs(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(hb_buffer_t *))*(void**)(__base - 166))(__t__p0));\
	})

#define hb_buffer_set_direction(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_direction_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_direction_t ))*(void**)(__base - 172))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_direction(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_direction_t (*)(hb_buffer_t *))*(void**)(__base - 178))(__t__p0));\
	})

#define hb_buffer_set_script(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_script_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_script_t ))*(void**)(__base - 184))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_script(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_script_t (*)(hb_buffer_t *))*(void**)(__base - 190))(__t__p0));\
	})

#define hb_buffer_set_language(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_language_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_language_t ))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_language(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_language_t (*)(hb_buffer_t *))*(void**)(__base - 202))(__t__p0));\
	})

#define hb_buffer_set_segment_properties(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const hb_segment_properties_t *))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_segment_properties(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_segment_properties_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_segment_properties_t *))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})

#define hb_buffer_guess_segment_properties(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 220))(__t__p0));\
	})

#define hb_buffer_set_flags(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_flags_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_buffer_flags_t ))*(void**)(__base - 226))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_flags(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_flags_t (*)(hb_buffer_t *))*(void**)(__base - 232))(__t__p0));\
	})

#define hb_buffer_set_cluster_level(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_cluster_level_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_buffer_cluster_level_t ))*(void**)(__base - 238))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_cluster_level(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_cluster_level_t (*)(hb_buffer_t *))*(void**)(__base - 244))(__t__p0));\
	})

#define hb_buffer_set_replacement_codepoint(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_codepoint_t ))*(void**)(__base - 250))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_replacement_codepoint(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(hb_buffer_t *))*(void**)(__base - 256))(__t__p0));\
	})

#define hb_buffer_reset(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 262))(__t__p0));\
	})

#define hb_buffer_clear_contents(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 268))(__t__p0));\
	})

#define hb_buffer_pre_allocate(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *, unsigned int ))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})

#define hb_buffer_allocation_successful(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *))*(void**)(__base - 280))(__t__p0));\
	})

#define hb_buffer_reverse(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 286))(__t__p0));\
	})

#define hb_buffer_reverse_range(__p0, __p1, __p2) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, unsigned int , unsigned int ))*(void**)(__base - 292))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_buffer_reverse_clusters(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 298))(__t__p0));\
	})

#define hb_buffer_add(__p0, __p1, __p2) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_codepoint_t , unsigned int ))*(void**)(__base - 304))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_buffer_add_utf8(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const char *, int , unsigned int , int ))*(void**)(__base - 310))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_add_utf16(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const uint16_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const uint16_t *, int , unsigned int , int ))*(void**)(__base - 316))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_add_utf32(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const uint32_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const uint32_t *, int , unsigned int , int ))*(void**)(__base - 322))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_add_latin1(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const uint8_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const uint8_t *, int , unsigned int , int ))*(void**)(__base - 328))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_add_codepoints(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const hb_codepoint_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, const hb_codepoint_t *, int , unsigned int , int ))*(void**)(__base - 334))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_buffer_set_length(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *, unsigned int ))*(void**)(__base - 340))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_length(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_buffer_t *))*(void**)(__base - 346))(__t__p0));\
	})

#define hb_buffer_get_glyph_infos(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_glyph_info_t *(*)(hb_buffer_t *, unsigned int *))*(void**)(__base - 352))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_glyph_positions(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_glyph_position_t *(*)(hb_buffer_t *, unsigned int *))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})

#define hb_buffer_normalize_glyphs(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *))*(void**)(__base - 364))(__t__p0));\
	})

#define hb_buffer_serialize_format_from_string(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_serialize_format_t (*)(const char *, int ))*(void**)(__base - 370))(__t__p0, __t__p1));\
	})

#define hb_buffer_serialize_format_to_string(__p0) \
	({ \
		hb_buffer_serialize_format_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(hb_buffer_serialize_format_t ))*(void**)(__base - 376))(__t__p0));\
	})

#define hb_buffer_serialize_list_formats() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char **(*)(void))*(void**)(__base - 382))());\
	})

#define hb_buffer_serialize_glyphs(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		char * __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		hb_font_t * __t__p6 = __p6;\
		hb_buffer_serialize_format_t  __t__p7 = __p7;\
		hb_buffer_serialize_flags_t  __t__p8 = __p8;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_buffer_t *, unsigned int , unsigned int , char *, unsigned int , unsigned int *, hb_font_t *, hb_buffer_serialize_format_t , hb_buffer_serialize_flags_t ))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define hb_buffer_deserialize_glyphs(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		const char ** __t__p3 = __p3;\
		hb_font_t * __t__p4 = __p4;\
		hb_buffer_serialize_format_t  __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *, const char *, int , const char **, hb_font_t *, hb_buffer_serialize_format_t ))*(void**)(__base - 394))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_buffer_set_message_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_message_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_buffer_message_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 400))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_glyph_info_get_glyph_flags(__p0) \
	({ \
		const hb_glyph_info_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_glyph_flags_t (*)(const hb_glyph_info_t *))*(void**)(__base - 1792))(__t__p0));\
	})

#define hb_buffer_append(__p0, __p1, __p2, __p3) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_t * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_buffer_t *, unsigned int , unsigned int ))*(void**)(__base - 1798))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_buffer_diff(__p0, __p1, __p2, __p3) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_buffer_t * __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_diff_flags_t (*)(hb_buffer_t *, hb_buffer_t *, hb_codepoint_t , unsigned int ))*(void**)(__base - 1804))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_face_create(__p0, __p1) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(hb_blob_t *, unsigned int ))*(void**)(__base - 472))(__t__p0, __t__p1));\
	})

#define hb_face_create_for_tables(__p0, __p1, __p2) \
	({ \
		hb_reference_table_func_t  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		hb_destroy_func_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(hb_reference_table_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 478))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_face_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(void))*(void**)(__base - 484))());\
	})

#define hb_face_reference(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(hb_face_t *))*(void**)(__base - 490))(__t__p0));\
	})

#define hb_face_destroy(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *))*(void**)(__base - 496))(__t__p0));\
	})

#define hb_face_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 502))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_face_get_user_data(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_face_t *, hb_user_data_key_t *))*(void**)(__base - 508))(__t__p0, __t__p1));\
	})

#define hb_face_make_immutable(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *))*(void**)(__base - 514))(__t__p0));\
	})

#define hb_face_is_immutable(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 520))(__t__p0));\
	})

#define hb_face_reference_table(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_face_t *, hb_tag_t ))*(void**)(__base - 526))(__t__p0, __t__p1));\
	})

#define hb_face_reference_blob(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_face_t *))*(void**)(__base - 532))(__t__p0));\
	})

#define hb_face_set_index(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, unsigned int ))*(void**)(__base - 538))(__t__p0, __t__p1));\
	})

#define hb_face_get_index(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 544))(__t__p0));\
	})

#define hb_face_set_upem(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, unsigned int ))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})

#define hb_face_get_upem(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 556))(__t__p0));\
	})

#define hb_face_set_glyph_count(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, unsigned int ))*(void**)(__base - 562))(__t__p0, __t__p1));\
	})

#define hb_face_get_glyph_count(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 568))(__t__p0));\
	})

#define hb_face_get_table_tags(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_tag_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1810))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_create() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_funcs_t *(*)(void))*(void**)(__base - 574))());\
	})

#define hb_font_funcs_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_funcs_t *(*)(void))*(void**)(__base - 580))());\
	})

#define hb_font_funcs_reference(__p0) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_funcs_t *(*)(hb_font_funcs_t *))*(void**)(__base - 586))(__t__p0));\
	})

#define hb_font_funcs_destroy(__p0) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *))*(void**)(__base - 592))(__t__p0));\
	})

#define hb_font_funcs_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_funcs_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 598))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_funcs_get_user_data(__p0, __p1) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_font_funcs_t *, hb_user_data_key_t *))*(void**)(__base - 604))(__t__p0, __t__p1));\
	})

#define hb_font_funcs_make_immutable(__p0) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *))*(void**)(__base - 610))(__t__p0));\
	})

#define hb_font_funcs_is_immutable(__p0) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_funcs_t *))*(void**)(__base - 616))(__t__p0));\
	})

#define hb_font_funcs_set_font_h_extents_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_font_h_extents_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_font_h_extents_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 622))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_font_v_extents_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_font_v_extents_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_font_v_extents_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 628))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 634))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_nominal_glyph_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_nominal_glyph_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_nominal_glyph_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1606))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_variation_glyph_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_variation_glyph_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_variation_glyph_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1612))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_h_advance_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_h_advance_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_h_advance_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 640))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_v_advance_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_v_advance_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_v_advance_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_h_origin_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_h_origin_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_h_origin_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_v_origin_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_v_origin_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_v_origin_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 658))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_h_kerning_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_h_kerning_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_h_kerning_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 664))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_v_kerning_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_v_kerning_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_v_kerning_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 670))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_extents_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_extents_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_extents_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_contour_point_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_contour_point_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_contour_point_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 682))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_name_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_name_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_name_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 688))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_from_name_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_from_name_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_from_name_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 694))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_h_extents(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_font_extents_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_font_extents_t *))*(void**)(__base - 700))(__t__p0, __t__p1));\
	})

#define hb_font_get_v_extents(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_font_extents_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_font_extents_t *))*(void**)(__base - 706))(__t__p0, __t__p1));\
	})

#define hb_font_get_glyph(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t , hb_codepoint_t *))*(void**)(__base - 712))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_nominal_glyph(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t *))*(void**)(__base - 1618))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_variation_glyph(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t , hb_codepoint_t *))*(void**)(__base - 1624))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_h_advance(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t ))*(void**)(__base - 718))(__t__p0, __t__p1));\
	})

#define hb_font_get_glyph_v_advance(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t ))*(void**)(__base - 724))(__t__p0, __t__p1));\
	})

#define hb_font_get_glyph_h_origin(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_position_t * __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_position_t *, hb_position_t *))*(void**)(__base - 730))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_v_origin(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_position_t * __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_position_t *, hb_position_t *))*(void**)(__base - 736))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_h_kerning(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t ))*(void**)(__base - 742))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_glyph_v_kerning(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t ))*(void**)(__base - 748))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_glyph_extents(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_glyph_extents_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_glyph_extents_t *))*(void**)(__base - 754))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_glyph_contour_point(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , unsigned int , hb_position_t *, hb_position_t *))*(void**)(__base - 760))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_get_glyph_name(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		char * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , char *, unsigned int ))*(void**)(__base - 766))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_from_name(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, const char *, int , hb_codepoint_t *))*(void**)(__base - 772))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_extents_for_direction(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_direction_t  __t__p1 = __p1;\
		hb_font_extents_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_direction_t , hb_font_extents_t *))*(void**)(__base - 778))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_glyph_advance_for_direction(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 784))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_get_glyph_origin_for_direction(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 790))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_add_glyph_origin_for_direction(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 796))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_subtract_glyph_origin_for_direction(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_position_t * __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 802))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_get_glyph_kerning_for_direction(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		hb_direction_t  __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		hb_position_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , hb_codepoint_t , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 808))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_font_get_glyph_extents_for_origin(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_glyph_extents_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , hb_glyph_extents_t *))*(void**)(__base - 814))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_contour_point_for_origin(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		hb_direction_t  __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		hb_position_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_codepoint_t , unsigned int , hb_direction_t , hb_position_t *, hb_position_t *))*(void**)(__base - 820))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_font_glyph_to_string(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		char * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_codepoint_t , char *, unsigned int ))*(void**)(__base - 826))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_glyph_from_string(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, const char *, int , hb_codepoint_t *))*(void**)(__base - 832))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_create(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(hb_face_t *))*(void**)(__base - 838))(__t__p0));\
	})

#define hb_font_create_sub_font(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(hb_font_t *))*(void**)(__base - 844))(__t__p0));\
	})

#define hb_font_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(void))*(void**)(__base - 850))());\
	})

#define hb_font_reference(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(hb_font_t *))*(void**)(__base - 856))(__t__p0));\
	})

#define hb_font_destroy(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 862))(__t__p0));\
	})

#define hb_font_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 868))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_font_get_user_data(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_font_t *, hb_user_data_key_t *))*(void**)(__base - 874))(__t__p0, __t__p1));\
	})

#define hb_font_make_immutable(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 880))(__t__p0));\
	})

#define hb_font_is_immutable(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *))*(void**)(__base - 886))(__t__p0));\
	})

#define hb_font_set_parent(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_font_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_font_t *))*(void**)(__base - 892))(__t__p0, __t__p1));\
	})

#define hb_font_get_parent(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(hb_font_t *))*(void**)(__base - 898))(__t__p0));\
	})

#define hb_font_set_face(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_face_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_face_t *))*(void**)(__base - 1642))(__t__p0, __t__p1));\
	})

#define hb_font_get_face(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(hb_font_t *))*(void**)(__base - 904))(__t__p0));\
	})

#define hb_font_set_funcs(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_font_funcs_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_font_funcs_t *, void *, hb_destroy_func_t ))*(void**)(__base - 910))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_set_funcs_data(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		hb_destroy_func_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, void *, hb_destroy_func_t ))*(void**)(__base - 916))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_set_scale(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, int , int ))*(void**)(__base - 922))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_scale(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, int *, int *))*(void**)(__base - 928))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_set_ppem(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, unsigned int , unsigned int ))*(void**)(__base - 934))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_ppem(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, unsigned int *, unsigned int *))*(void**)(__base - 940))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_set_variations(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		const hb_variation_t * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, const hb_variation_t *, unsigned int ))*(void**)(__base - 1648))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_set_var_coords_design(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		const float * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, const float *, unsigned int ))*(void**)(__base - 1654))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_set_var_coords_normalized(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		const int * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, const int *, unsigned int ))*(void**)(__base - 1660))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_font_get_var_coords_normalized(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const int *(*)(hb_font_t *, unsigned int *))*(void**)(__base - 1666))(__t__p0, __t__p1));\
	})

#define hb_font_set_ptem(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, float ))*(void**)(__base - 1816))(__t__p0, __t__p1));\
	})

#define hb_font_get_ptem(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(hb_font_t *))*(void**)(__base - 1822))(__t__p0));\
	})

#define hb_set_create() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(void))*(void**)(__base - 946))());\
	})

#define hb_set_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(void))*(void**)(__base - 952))());\
	})

#define hb_set_reference(__p0) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(hb_set_t *))*(void**)(__base - 958))(__t__p0));\
	})

#define hb_set_destroy(__p0) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *))*(void**)(__base - 964))(__t__p0));\
	})

#define hb_set_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_set_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 970))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_set_get_user_data(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_set_t *, hb_user_data_key_t *))*(void**)(__base - 976))(__t__p0, __t__p1));\
	})

#define hb_set_allocation_successful(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *))*(void**)(__base - 982))(__t__p0));\
	})

#define hb_set_clear(__p0) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *))*(void**)(__base - 988))(__t__p0));\
	})

#define hb_set_is_empty(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *))*(void**)(__base - 994))(__t__p0));\
	})

#define hb_set_has(__p0, __p1) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, hb_codepoint_t ))*(void**)(__base - 1000))(__t__p0, __t__p1));\
	})

#define hb_set_add(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, hb_codepoint_t ))*(void**)(__base - 1006))(__t__p0, __t__p1));\
	})

#define hb_set_add_range(__p0, __p1, __p2) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, hb_codepoint_t , hb_codepoint_t ))*(void**)(__base - 1012))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_set_del(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, hb_codepoint_t ))*(void**)(__base - 1018))(__t__p0, __t__p1));\
	})

#define hb_set_del_range(__p0, __p1, __p2) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, hb_codepoint_t , hb_codepoint_t ))*(void**)(__base - 1024))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_set_is_equal(__p0, __p1) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, const hb_set_t *))*(void**)(__base - 1030))(__t__p0, __t__p1));\
	})

#define hb_set_set(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, const hb_set_t *))*(void**)(__base - 1036))(__t__p0, __t__p1));\
	})

#define hb_set_union(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, const hb_set_t *))*(void**)(__base - 1042))(__t__p0, __t__p1));\
	})

#define hb_set_intersect(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, const hb_set_t *))*(void**)(__base - 1048))(__t__p0, __t__p1));\
	})

#define hb_set_subtract(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, const hb_set_t *))*(void**)(__base - 1054))(__t__p0, __t__p1));\
	})

#define hb_set_symmetric_difference(__p0, __p1) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		const hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *, const hb_set_t *))*(void**)(__base - 1060))(__t__p0, __t__p1));\
	})

#define hb_set_invert(__p0) \
	({ \
		hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_set_t *))*(void**)(__base - 1066))(__t__p0));\
	})

#define hb_set_get_population(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(const hb_set_t *))*(void**)(__base - 1072))(__t__p0));\
	})

#define hb_set_get_min(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(const hb_set_t *))*(void**)(__base - 1078))(__t__p0));\
	})

#define hb_set_get_max(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(const hb_set_t *))*(void**)(__base - 1084))(__t__p0));\
	})

#define hb_set_next(__p0, __p1) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, hb_codepoint_t *))*(void**)(__base - 1090))(__t__p0, __t__p1));\
	})

#define hb_set_next_range(__p0, __p1, __p2) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t * __t__p1 = __p1;\
		hb_codepoint_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, hb_codepoint_t *, hb_codepoint_t *))*(void**)(__base - 1096))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_set_previous(__p0, __p1) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, hb_codepoint_t *))*(void**)(__base - 1828))(__t__p0, __t__p1));\
	})

#define hb_set_previous_range(__p0, __p1, __p2) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		hb_codepoint_t * __t__p1 = __p1;\
		hb_codepoint_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_set_t *, hb_codepoint_t *, hb_codepoint_t *))*(void**)(__base - 1834))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_shape_plan_create(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const char *const * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(hb_face_t *, const hb_segment_properties_t *, const hb_feature_t *, unsigned int , const char *const *))*(void**)(__base - 1102))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_shape_plan_create_cached(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const char *const * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(hb_face_t *, const hb_segment_properties_t *, const hb_feature_t *, unsigned int , const char *const *))*(void**)(__base - 1108))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_shape_plan_create2(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const int * __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		const char *const * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(hb_face_t *, const hb_segment_properties_t *, const hb_feature_t *, unsigned int , const int *, unsigned int , const char *const *))*(void**)(__base - 1774))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_shape_plan_create_cached2(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const int * __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		const char *const * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(hb_face_t *, const hb_segment_properties_t *, const hb_feature_t *, unsigned int , const int *, unsigned int , const char *const *))*(void**)(__base - 1780))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_shape_plan_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(void))*(void**)(__base - 1114))());\
	})

#define hb_shape_plan_reference(__p0) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_shape_plan_t *(*)(hb_shape_plan_t *))*(void**)(__base - 1120))(__t__p0));\
	})

#define hb_shape_plan_destroy(__p0) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_shape_plan_t *))*(void**)(__base - 1126))(__t__p0));\
	})

#define hb_shape_plan_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_shape_plan_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 1132))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_shape_plan_get_user_data(__p0, __p1) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_shape_plan_t *, hb_user_data_key_t *))*(void**)(__base - 1138))(__t__p0, __t__p1));\
	})

#define hb_shape_plan_execute(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		hb_font_t * __t__p1 = __p1;\
		hb_buffer_t * __t__p2 = __p2;\
		const hb_feature_t * __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_shape_plan_t *, hb_font_t *, hb_buffer_t *, const hb_feature_t *, unsigned int ))*(void**)(__base - 1144))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_shape_plan_get_shaper(__p0) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(hb_shape_plan_t *))*(void**)(__base - 1150))(__t__p0));\
	})

#define hb_shape(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_buffer_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_buffer_t *, const hb_feature_t *, unsigned int ))*(void**)(__base - 1168))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_shape_full(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_buffer_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const char *const * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_buffer_t *, const hb_feature_t *, unsigned int , const char *const *))*(void**)(__base - 1174))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_shape_list_shapers() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char **(*)(void))*(void**)(__base - 1180))());\
	})

#define hb_unicode_funcs_get_default_REF() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(void))*(void**)(__base - 1186))());\
	})

#define hb_unicode_funcs_create(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(hb_unicode_funcs_t *))*(void**)(__base - 1192))(__t__p0));\
	})

#define hb_unicode_funcs_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(void))*(void**)(__base - 1198))());\
	})

#define hb_unicode_funcs_reference(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(hb_unicode_funcs_t *))*(void**)(__base - 1204))(__t__p0));\
	})

#define hb_unicode_funcs_destroy(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *))*(void**)(__base - 1210))(__t__p0));\
	})

#define hb_unicode_funcs_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_unicode_funcs_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 1216))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_unicode_funcs_get_user_data(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_unicode_funcs_t *, hb_user_data_key_t *))*(void**)(__base - 1222))(__t__p0, __t__p1));\
	})

#define hb_unicode_funcs_make_immutable(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *))*(void**)(__base - 1228))(__t__p0));\
	})

#define hb_unicode_funcs_is_immutable(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_unicode_funcs_t *))*(void**)(__base - 1234))(__t__p0));\
	})

#define hb_unicode_funcs_get_parent(__p0) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(hb_unicode_funcs_t *))*(void**)(__base - 1240))(__t__p0));\
	})

#define hb_unicode_funcs_set_combining_class_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_combining_class_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_combining_class_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1246))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_eastasian_width_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_eastasian_width_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_eastasian_width_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1252))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_general_category_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_general_category_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_general_category_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1258))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_mirroring_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_mirroring_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_mirroring_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1264))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_script_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_script_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_script_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1270))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_compose_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_compose_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_compose_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1276))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_decompose_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_decompose_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_decompose_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1282))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_funcs_set_decompose_compatibility_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_unicode_decompose_compatibility_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_unicode_funcs_t *, hb_unicode_decompose_compatibility_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1288))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_combining_class(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_combining_class_t (*)(hb_unicode_funcs_t *, hb_codepoint_t ))*(void**)(__base - 1294))(__t__p0, __t__p1));\
	})

#define hb_unicode_eastasian_width(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_unicode_funcs_t *, hb_codepoint_t ))*(void**)(__base - 1300))(__t__p0, __t__p1));\
	})

#define hb_unicode_general_category(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_general_category_t (*)(hb_unicode_funcs_t *, hb_codepoint_t ))*(void**)(__base - 1306))(__t__p0, __t__p1));\
	})

#define hb_unicode_mirroring(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(hb_unicode_funcs_t *, hb_codepoint_t ))*(void**)(__base - 1312))(__t__p0, __t__p1));\
	})

#define hb_unicode_script(__p0, __p1) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_script_t (*)(hb_unicode_funcs_t *, hb_codepoint_t ))*(void**)(__base - 1318))(__t__p0, __t__p1));\
	})

#define hb_unicode_compose(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_unicode_funcs_t *, hb_codepoint_t , hb_codepoint_t , hb_codepoint_t *))*(void**)(__base - 1324))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_decompose(__p0, __p1, __p2, __p3) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t * __t__p2 = __p2;\
		hb_codepoint_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_unicode_funcs_t *, hb_codepoint_t , hb_codepoint_t *, hb_codepoint_t *))*(void**)(__base - 1330))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_unicode_decompose_compatibility(__p0, __p1, __p2) \
	({ \
		hb_unicode_funcs_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_unicode_funcs_t *, hb_codepoint_t , hb_codepoint_t *))*(void**)(__base - 1336))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_version(__p0, __p1, __p2) \
	({ \
		unsigned int * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(unsigned int *, unsigned int *, unsigned int *))*(void**)(__base - 1342))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_version_string() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1348))());\
	})

#define hb_version_atleast(__p0, __p1, __p2) \
	({ \
		unsigned int  __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(unsigned int , unsigned int , unsigned int ))*(void**)(__base - 1354))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ft_face_create(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		hb_destroy_func_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(void *, hb_destroy_func_t ))*(void**)(__base - 1360))(__t__p0, __t__p1));\
	})

#define hb_ft_face_create_cached(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(void *))*(void**)(__base - 1366))(__t__p0));\
	})

#define hb_ft_face_create_referenced(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(void *))*(void**)(__base - 1372))(__t__p0));\
	})

#define hb_ft_font_create(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		hb_destroy_func_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(void *, hb_destroy_func_t ))*(void**)(__base - 1378))(__t__p0, __t__p1));\
	})

#define hb_ft_font_create_referenced(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_font_t *(*)(void *))*(void**)(__base - 1384))(__t__p0));\
	})

#define hb_ft_font_get_face(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_font_t *))*(void**)(__base - 1390))(__t__p0));\
	})

#define hb_ft_font_set_load_flags(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, int ))*(void**)(__base - 1396))(__t__p0, __t__p1));\
	})

#define hb_ft_font_get_load_flags(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(hb_font_t *))*(void**)(__base - 1402))(__t__p0));\
	})

#define hb_ft_font_set_funcs(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 1408))(__t__p0));\
	})

#define hb_ft_font_changed(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 1840))(__t__p0));\
	})

#define hb_ot_font_set_funcs(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 1414))(__t__p0));\
	})

#define hb_ot_layout_has_glyph_classes(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 1420))(__t__p0));\
	})

#define hb_ot_layout_get_glyph_class(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_layout_glyph_class_t (*)(hb_face_t *, hb_codepoint_t ))*(void**)(__base - 1426))(__t__p0, __t__p1));\
	})

#define hb_ot_layout_get_glyphs_in_class(__p0, __p1, __p2) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_ot_layout_glyph_class_t  __t__p1 = __p1;\
		hb_set_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_ot_layout_glyph_class_t , hb_set_t *))*(void**)(__base - 1432))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_layout_get_attach_points(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_codepoint_t , unsigned int , unsigned int *, unsigned int *))*(void**)(__base - 1438))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_get_ligature_carets(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_direction_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_position_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_font_t *, hb_direction_t , hb_codepoint_t , unsigned int , unsigned int *, hb_position_t *))*(void**)(__base - 1444))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_table_get_script_tags(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_tag_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1450))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_table_find_script(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		hb_tag_t  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , hb_tag_t , unsigned int *))*(void**)(__base - 1456))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_layout_table_choose_script(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		const hb_tag_t * __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_tag_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , const hb_tag_t *, unsigned int *, hb_tag_t *))*(void**)(__base - 1462))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_table_get_feature_tags(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_tag_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1468))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_script_get_language_tags(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_tag_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1474))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_script_find_language(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		hb_tag_t  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , hb_tag_t , unsigned int *))*(void**)(__base - 1480))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_language_get_required_feature_index(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int *))*(void**)(__base - 1486))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_language_get_required_feature(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_tag_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1492))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_language_get_feature_indexes(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		unsigned int * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int , unsigned int *, unsigned int *))*(void**)(__base - 1498))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_ot_layout_language_get_feature_tags(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		hb_tag_t * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int , unsigned int *, hb_tag_t *))*(void**)(__base - 1504))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_ot_layout_language_find_feature(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		hb_tag_t  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , hb_tag_t , unsigned int *))*(void**)(__base - 1510))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_feature_get_lookups(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int *, unsigned int *))*(void**)(__base - 1516))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_table_get_lookup_count(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t ))*(void**)(__base - 1522))(__t__p0, __t__p1));\
	})

#define hb_ot_layout_collect_lookups(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		const hb_tag_t * __t__p2 = __p2;\
		const hb_tag_t * __t__p3 = __p3;\
		const hb_tag_t * __t__p4 = __p4;\
		hb_set_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_tag_t , const hb_tag_t *, const hb_tag_t *, const hb_tag_t *, hb_set_t *))*(void**)(__base - 1528))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_lookup_collect_glyphs(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		hb_set_t * __t__p3 = __p3;\
		hb_set_t * __t__p4 = __p4;\
		hb_set_t * __t__p5 = __p5;\
		hb_set_t * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_tag_t , unsigned int , hb_set_t *, hb_set_t *, hb_set_t *, hb_set_t *))*(void**)(__base - 1534))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_ot_layout_table_find_feature_variations(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		const int * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , const int *, unsigned int , unsigned int *))*(void**)(__base - 1672))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_feature_with_variations_get_lookups(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		unsigned int * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int , unsigned int *, unsigned int *))*(void**)(__base - 1678))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_ot_layout_has_substitution(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 1540))(__t__p0));\
	})

#define hb_ot_layout_lookup_would_substitute(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		const hb_codepoint_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, unsigned int , const hb_codepoint_t *, unsigned int , hb_bool_t ))*(void**)(__base - 1546))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_layout_lookup_substitute_closure(__p0, __p1, __p2) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		hb_set_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, unsigned int , hb_set_t *))*(void**)(__base - 1552))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_layout_has_positioning(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 1558))(__t__p0));\
	})

#define hb_ot_layout_get_size_params(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, unsigned int *, unsigned int *, unsigned int *, unsigned int *, unsigned int *))*(void**)(__base - 1564))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_math_has_data(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 1684))(__t__p0));\
	})

#define hb_ot_math_get_constant(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_math_constant_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_ot_math_constant_t ))*(void**)(__base - 1690))(__t__p0, __t__p1));\
	})

#define hb_ot_math_get_glyph_italics_correction(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t ))*(void**)(__base - 1696))(__t__p0, __t__p1));\
	})

#define hb_ot_math_get_glyph_top_accent_attachment(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t ))*(void**)(__base - 1702))(__t__p0, __t__p1));\
	})

#define hb_ot_math_is_glyph_extended_shape(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_codepoint_t ))*(void**)(__base - 1708))(__t__p0, __t__p1));\
	})

#define hb_ot_math_get_glyph_kerning(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_ot_math_kern_t  __t__p2 = __p2;\
		hb_position_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_codepoint_t , hb_ot_math_kern_t , hb_position_t ))*(void**)(__base - 1714))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_math_get_glyph_variants(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_ot_math_glyph_variant_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , unsigned int , unsigned int *, hb_ot_math_glyph_variant_t *))*(void**)(__base - 1720))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_math_get_min_connector_overlap(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_direction_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_direction_t ))*(void**)(__base - 1726))(__t__p0, __t__p1));\
	})

#define hb_ot_math_get_glyph_assembly(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_ot_math_glyph_part_t * __t__p5 = __p5;\
		hb_position_t * __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_font_t *, hb_codepoint_t , hb_direction_t , unsigned int , unsigned int *, hb_ot_math_glyph_part_t *, hb_position_t *))*(void**)(__base - 1732))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_ot_shape_glyphs_closure(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_buffer_t * __t__p1 = __p1;\
		const hb_feature_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		hb_set_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_buffer_t *, const hb_feature_t *, unsigned int , hb_set_t *))*(void**)(__base - 1570))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_shape_plan_collect_lookups(__p0, __p1, __p2) \
	({ \
		hb_shape_plan_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		hb_set_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_shape_plan_t *, hb_tag_t , hb_set_t *))*(void**)(__base - 1576))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_tags_from_script(__p0, __p1, __p2) \
	({ \
		hb_script_t  __t__p0 = __p0;\
		hb_tag_t * __t__p1 = __p1;\
		hb_tag_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_script_t , hb_tag_t *, hb_tag_t *))*(void**)(__base - 1582))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_tag_to_script(__p0) \
	({ \
		hb_tag_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_script_t (*)(hb_tag_t ))*(void**)(__base - 1588))(__t__p0));\
	})

#define hb_ot_tag_from_language(__p0) \
	({ \
		hb_language_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_tag_t (*)(hb_language_t ))*(void**)(__base - 1594))(__t__p0));\
	})

#define hb_ot_tag_to_language(__p0) \
	({ \
		hb_tag_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_language_t (*)(hb_tag_t ))*(void**)(__base - 1600))(__t__p0));\
	})

#define hb_ot_var_has_data(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 1738))(__t__p0));\
	})

#define hb_ot_var_get_axis_count(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 1744))(__t__p0));\
	})

#define hb_ot_var_get_axes(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_ot_var_axis_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, hb_ot_var_axis_t *))*(void**)(__base - 1750))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_var_find_axis(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_ot_var_axis_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int *, hb_ot_var_axis_t *))*(void**)(__base - 1756))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_var_normalize_variations(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_variation_t * __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, const hb_variation_t *, unsigned int , int *, unsigned int ))*(void**)(__base - 1762))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_var_normalize_coords(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		const float * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, unsigned int , const float *, int *))*(void**)(__base - 1768))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_blob_create_from_file(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(const char *))*(void**)(__base - 1846))(__t__p0));\
	})

#define hb_face_count(__p0) \
	({ \
		hb_blob_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_blob_t *))*(void**)(__base - 1852))(__t__p0));\
	})

#define hb_map_create() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_map_t *(*)(void))*(void**)(__base - 1858))());\
	})

#define hb_map_get_empty() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_map_t *(*)(void))*(void**)(__base - 1864))());\
	})

#define hb_map_reference(__p0) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_map_t *(*)(hb_map_t *))*(void**)(__base - 1870))(__t__p0));\
	})

#define hb_map_destroy(__p0) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_map_t *))*(void**)(__base - 1876))(__t__p0));\
	})

#define hb_map_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_map_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 1882))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_map_get_user_data(__p0, __p1) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_map_t *, hb_user_data_key_t *))*(void**)(__base - 1888))(__t__p0, __t__p1));\
	})

#define hb_map_allocation_successful(__p0) \
	({ \
		const hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_map_t *))*(void**)(__base - 1894))(__t__p0));\
	})

#define hb_map_clear(__p0) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_map_t *))*(void**)(__base - 1900))(__t__p0));\
	})

#define hb_map_is_empty(__p0) \
	({ \
		const hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_map_t *))*(void**)(__base - 1906))(__t__p0));\
	})

#define hb_map_get_population(__p0) \
	({ \
		const hb_map_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(const hb_map_t *))*(void**)(__base - 1912))(__t__p0));\
	})

#define hb_map_set(__p0, __p1, __p2) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_map_t *, hb_codepoint_t , hb_codepoint_t ))*(void**)(__base - 1918))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_map_get(__p0, __p1) \
	({ \
		const hb_map_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(const hb_map_t *, hb_codepoint_t ))*(void**)(__base - 1924))(__t__p0, __t__p1));\
	})

#define hb_map_del(__p0, __p1) \
	({ \
		hb_map_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_map_t *, hb_codepoint_t ))*(void**)(__base - 1930))(__t__p0, __t__p1));\
	})

#define hb_map_has(__p0, __p1) \
	({ \
		const hb_map_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(const hb_map_t *, hb_codepoint_t ))*(void**)(__base - 1936))(__t__p0, __t__p1));\
	})

#define hb_font_funcs_set_glyph_h_advances_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_h_advances_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_h_advances_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1942))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_funcs_set_glyph_v_advances_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_glyph_v_advances_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_glyph_v_advances_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 1948))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_font_get_glyph_advances_for_direction(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_direction_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		const hb_codepoint_t * __t__p3 = __p3;\
		unsigned  __t__p4 = __p4;\
		hb_position_t * __t__p5 = __p5;\
		unsigned  __t__p6 = __p6;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, hb_direction_t , unsigned int , const hb_codepoint_t *, unsigned , hb_position_t *, unsigned ))*(void**)(__base - 1954))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define hb_font_get_glyph_h_advances(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		const hb_codepoint_t * __t__p2 = __p2;\
		unsigned  __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		unsigned  __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, unsigned int , const hb_codepoint_t *, unsigned , hb_position_t *, unsigned ))*(void**)(__base - 1960))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_font_get_glyph_v_advances(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		const hb_codepoint_t * __t__p2 = __p2;\
		unsigned  __t__p3 = __p3;\
		hb_position_t * __t__p4 = __p4;\
		unsigned  __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, unsigned int , const hb_codepoint_t *, unsigned , hb_position_t *, unsigned ))*(void**)(__base - 1966))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_unicode_funcs_get_default() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_unicode_funcs_t *(*)(void))*(void**)(__base - 1972))());\
	})

#define hb_face_collect_unicodes(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_set_t *))*(void**)(__base - 1978))(__t__p0, __t__p1));\
	})

#define hb_face_collect_variation_selectors(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_set_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_set_t *))*(void**)(__base - 1984))(__t__p0, __t__p1));\
	})

#define hb_face_collect_variation_unicodes(__p0, __p1, __p2) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		hb_set_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_face_t *, hb_codepoint_t , hb_set_t *))*(void**)(__base - 1990))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_face_builder_create() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(void))*(void**)(__base - 1996))());\
	})

#define hb_face_builder_add_table(__p0, __p1, __p2) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		hb_blob_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , hb_blob_t *))*(void**)(__base - 2002))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_buffer_set_invisible_glyph(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_codepoint_t ))*(void**)(__base - 2008))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_invisible_glyph(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(hb_buffer_t *))*(void**)(__base - 2014))(__t__p0));\
	})

#define hb_font_funcs_set_nominal_glyphs_func(__p0, __p1, __p2, __p3) \
	({ \
		hb_font_funcs_t * __t__p0 = __p0;\
		hb_font_get_nominal_glyphs_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_funcs_t *, hb_font_get_nominal_glyphs_func_t , void *, hb_destroy_func_t ))*(void**)(__base - 2020))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_layout_table_select_script(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		const hb_tag_t * __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_tag_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , const hb_tag_t *, unsigned int *, hb_tag_t *))*(void**)(__base - 2026))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_script_select_language(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		const hb_tag_t * __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , const hb_tag_t *, unsigned int *))*(void**)(__base - 2032))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_layout_feature_get_name_ids(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		hb_ot_name_id_t * __t__p3 = __p3;\
		hb_ot_name_id_t * __t__p4 = __p4;\
		hb_ot_name_id_t * __t__p5 = __p5;\
		unsigned int * __t__p6 = __p6;\
		hb_ot_name_id_t * __t__p7 = __p7;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , unsigned int , hb_ot_name_id_t *, hb_ot_name_id_t *, hb_ot_name_id_t *, unsigned int *, hb_ot_name_id_t *))*(void**)(__base - 2038))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define hb_ot_layout_feature_get_characters(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_codepoint_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_tag_t , unsigned int , unsigned int , unsigned int *, hb_codepoint_t *))*(void**)(__base - 2044))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_tags_from_script_and_language(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_script_t  __t__p0 = __p0;\
		hb_language_t  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_tag_t * __t__p3 = __p3;\
		unsigned int * __t__p4 = __p4;\
		hb_tag_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_script_t , hb_language_t , unsigned int *, hb_tag_t *, unsigned int *, hb_tag_t *))*(void**)(__base - 2050))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_tags_to_script_and_language(__p0, __p1, __p2, __p3) \
	({ \
		hb_tag_t  __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		hb_script_t * __t__p2 = __p2;\
		hb_language_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_tag_t , hb_tag_t , hb_script_t *, hb_language_t *))*(void**)(__base - 2056))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_color_get_alpha(__p0) \
	({ \
		hb_color_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint8_t (*)(hb_color_t ))*(void**)(__base - 2062))(__t__p0));\
	})

#define hb_color_get_red(__p0) \
	({ \
		hb_color_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint8_t (*)(hb_color_t ))*(void**)(__base - 2068))(__t__p0));\
	})

#define hb_color_get_green(__p0) \
	({ \
		hb_color_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint8_t (*)(hb_color_t ))*(void**)(__base - 2074))(__t__p0));\
	})

#define hb_color_get_blue(__p0) \
	({ \
		hb_color_t  __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint8_t (*)(hb_color_t ))*(void**)(__base - 2080))(__t__p0));\
	})

#define hb_ot_color_has_palettes(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2086))(__t__p0));\
	})

#define hb_ot_color_palette_get_count(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 2092))(__t__p0));\
	})

#define hb_ot_color_palette_get_name_id(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_name_id_t (*)(hb_face_t *, unsigned int ))*(void**)(__base - 2098))(__t__p0, __t__p1));\
	})

#define hb_ot_color_palette_color_get_name_id(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_name_id_t (*)(hb_face_t *, unsigned int ))*(void**)(__base - 2104))(__t__p0, __t__p1));\
	})

#define hb_ot_color_palette_get_flags(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_color_palette_flags_t (*)(hb_face_t *, unsigned int ))*(void**)(__base - 2110))(__t__p0, __t__p1));\
	})

#define hb_ot_color_palette_get_colors(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_color_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int , unsigned int *, hb_color_t *))*(void**)(__base - 2116))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_color_has_layers(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2122))(__t__p0));\
	})

#define hb_ot_color_glyph_get_layers(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_ot_color_layer_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_codepoint_t , unsigned int , unsigned int *, hb_ot_color_layer_t *))*(void**)(__base - 2128))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_color_has_svg(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2134))(__t__p0));\
	})

#define hb_ot_color_glyph_reference_svg(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_face_t *, hb_codepoint_t ))*(void**)(__base - 2140))(__t__p0, __t__p1));\
	})

#define hb_ot_color_has_png(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2146))(__t__p0));\
	})

#define hb_ot_color_glyph_reference_png(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_font_t *, hb_codepoint_t ))*(void**)(__base - 2152))(__t__p0, __t__p1));\
	})

#define hb_ot_name_list_names(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const hb_ot_name_entry_t *(*)(hb_face_t *, unsigned int *))*(void**)(__base - 2158))(__t__p0, __t__p1));\
	})

#define hb_ot_name_get_utf8(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_ot_name_id_t  __t__p1 = __p1;\
		hb_language_t  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		char * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_ot_name_id_t , hb_language_t , unsigned int *, char *))*(void**)(__base - 2164))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_name_get_utf16(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_ot_name_id_t  __t__p1 = __p1;\
		hb_language_t  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		uint16_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_ot_name_id_t , hb_language_t , unsigned int *, uint16_t *))*(void**)(__base - 2170))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_ot_name_get_utf32(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_ot_name_id_t  __t__p1 = __p1;\
		hb_language_t  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		uint32_t * __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_ot_name_id_t , hb_language_t , unsigned int *, uint32_t *))*(void**)(__base - 2176))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_aat_layout_get_feature_types(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_aat_layout_feature_type_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, hb_aat_layout_feature_type_t *))*(void**)(__base - 2182))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_aat_layout_feature_type_get_name_id(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_aat_layout_feature_type_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_name_id_t (*)(hb_face_t *, hb_aat_layout_feature_type_t ))*(void**)(__base - 2188))(__t__p0, __t__p1));\
	})

#define hb_aat_layout_feature_type_get_selector_infos(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_aat_layout_feature_type_t  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		unsigned int * __t__p3 = __p3;\
		hb_aat_layout_feature_selector_info_t * __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, hb_aat_layout_feature_type_t , unsigned int , unsigned int *, hb_aat_layout_feature_selector_info_t *, unsigned int *))*(void**)(__base - 2194))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_var_get_axis_infos(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_ot_var_axis_info_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, hb_ot_var_axis_info_t *))*(void**)(__base - 2200))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_var_find_axis_info(__p0, __p1, __p2) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_tag_t  __t__p1 = __p1;\
		hb_ot_var_axis_info_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *, hb_tag_t , hb_ot_var_axis_info_t *))*(void**)(__base - 2206))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_var_get_named_instance_count(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *))*(void**)(__base - 2212))(__t__p0));\
	})

#define hb_ot_var_named_instance_get_subfamily_name_id(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_name_id_t (*)(hb_face_t *, unsigned int ))*(void**)(__base - 2218))(__t__p0, __t__p1));\
	})

#define hb_ot_var_named_instance_get_postscript_name_id(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_ot_name_id_t (*)(hb_face_t *, unsigned int ))*(void**)(__base - 2224))(__t__p0, __t__p1));\
	})

#define hb_ot_var_named_instance_get_design_coords(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, float *))*(void**)(__base - 2230))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_aat_layout_has_substitution(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2236))(__t__p0));\
	})

#define hb_aat_layout_has_positioning(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2242))(__t__p0));\
	})

#define hb_aat_layout_has_tracking(__p0) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_face_t *))*(void**)(__base - 2248))(__t__p0));\
	})

#define hb_font_set_var_named_instance(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, unsigned ))*(void**)(__base - 2254))(__t__p0, __t__p1));\
	})

#define hb_ot_layout_get_baseline(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_layout_baseline_tag_t  __t__p1 = __p1;\
		hb_direction_t  __t__p2 = __p2;\
		hb_tag_t  __t__p3 = __p3;\
		hb_tag_t  __t__p4 = __p4;\
		hb_position_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_ot_layout_baseline_tag_t , hb_direction_t , hb_tag_t , hb_tag_t , hb_position_t *))*(void**)(__base - 2260))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ot_meta_get_entry_tags(__p0, __p1, __p2, __p3) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int * __t__p2 = __p2;\
		hb_ot_meta_tag_t * __t__p3 = __p3;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_face_t *, unsigned int , unsigned int *, hb_ot_meta_tag_t *))*(void**)(__base - 2266))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define hb_ot_meta_reference_entry(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		hb_ot_meta_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(hb_face_t *, hb_ot_meta_tag_t ))*(void**)(__base - 2272))(__t__p0, __t__p1));\
	})

#define hb_ot_metrics_get_position(__p0, __p1, __p2) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_metrics_tag_t  __t__p1 = __p1;\
		hb_position_t * __t__p2 = __p2;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_font_t *, hb_ot_metrics_tag_t , hb_position_t *))*(void**)(__base - 2278))(__t__p0, __t__p1, __t__p2));\
	})

#define hb_ot_metrics_get_variation(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_metrics_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(hb_font_t *, hb_ot_metrics_tag_t ))*(void**)(__base - 2284))(__t__p0, __t__p1));\
	})

#define hb_ot_metrics_get_x_variation(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_metrics_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_ot_metrics_tag_t ))*(void**)(__base - 2290))(__t__p0, __t__p1));\
	})

#define hb_ot_metrics_get_y_variation(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_ot_metrics_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_position_t (*)(hb_font_t *, hb_ot_metrics_tag_t ))*(void**)(__base - 2296))(__t__p0, __t__p1));\
	})

#define hb_font_get_nominal_glyphs(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		const hb_codepoint_t * __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		hb_codepoint_t * __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_font_t *, unsigned int , const hb_codepoint_t *, unsigned int , hb_codepoint_t *, unsigned int ))*(void**)(__base - 2302))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_ft_font_lock_face(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(hb_font_t *))*(void**)(__base - 2308))(__t__p0));\
	})

#define hb_ft_font_unlock_face(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *))*(void**)(__base - 2314))(__t__p0));\
	})

#define hb_ot_layout_lookup_get_glyph_alternates(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		unsigned  __t__p1 = __p1;\
		hb_codepoint_t  __t__p2 = __p2;\
		unsigned  __t__p3 = __p3;\
		unsigned * __t__p4 = __p4;\
		hb_codepoint_t * __t__p5 = __p5;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned (*)(hb_face_t *, unsigned , hb_codepoint_t , unsigned , unsigned *, hb_codepoint_t *))*(void**)(__base - 2320))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define hb_buffer_has_positions(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *))*(void**)(__base - 2326))(__t__p0));\
	})

#define hb_buffer_serialize(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		char * __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		hb_font_t * __t__p6 = __p6;\
		hb_buffer_serialize_format_t  __t__p7 = __p7;\
		hb_buffer_serialize_flags_t  __t__p8 = __p8;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_buffer_t *, unsigned int , unsigned int , char *, unsigned int , unsigned int *, hb_font_t *, hb_buffer_serialize_format_t , hb_buffer_serialize_flags_t ))*(void**)(__base - 2332))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define hb_buffer_serialize_unicode(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		unsigned int  __t__p2 = __p2;\
		char * __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int * __t__p5 = __p5;\
		hb_buffer_serialize_format_t  __t__p6 = __p6;\
		hb_buffer_serialize_flags_t  __t__p7 = __p7;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned int (*)(hb_buffer_t *, unsigned int , unsigned int , char *, unsigned int , unsigned int *, hb_buffer_serialize_format_t , hb_buffer_serialize_flags_t ))*(void**)(__base - 2338))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define hb_buffer_deserialize_unicode(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		const char ** __t__p3 = __p3;\
		hb_buffer_serialize_format_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_buffer_t *, const char *, int , const char **, hb_buffer_serialize_format_t ))*(void**)(__base - 2344))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_blob_create_or_fail(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const char * __t__p0 = __p0;\
		unsigned int  __t__p1 = __p1;\
		hb_memory_mode_t  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		hb_destroy_func_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(const char *, unsigned int , hb_memory_mode_t , void *, hb_destroy_func_t ))*(void**)(__base - 2350))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_blob_create_from_file_or_fail(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_blob_t *(*)(const char *))*(void**)(__base - 2356))(__t__p0));\
	})

#define hb_set_copy(__p0) \
	({ \
		const hb_set_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(const hb_set_t *))*(void**)(__base - 2362))(__t__p0));\
	})

#define hb_style_get_value(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		hb_style_tag_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(hb_font_t *, hb_style_tag_t ))*(void**)(__base - 2368))(__t__p0, __t__p1));\
	})

#define hb_subset_input_create_or_fail() \
	({ \
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_subset_input_t *(*)(void))*(void**)(__base - 2374))());\
	})

#define hb_subset_input_reference(__p0) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_subset_input_t *(*)(hb_subset_input_t *))*(void**)(__base - 2380))(__t__p0));\
	})

#define hb_subset_input_destroy(__p0) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_subset_input_t *))*(void**)(__base - 2386))(__t__p0));\
	})

#define hb_subset_input_set_user_data(__p0, __p1, __p2, __p3, __p4) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		hb_destroy_func_t  __t__p3 = __p3;\
		hb_bool_t  __t__p4 = __p4;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_bool_t (*)(hb_subset_input_t *, hb_user_data_key_t *, void *, hb_destroy_func_t , hb_bool_t ))*(void**)(__base - 2392))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define hb_subset_input_get_user_data(__p0, __p1) \
	({ \
		const hb_subset_input_t * __t__p0 = __p0;\
		hb_user_data_key_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(const hb_subset_input_t *, hb_user_data_key_t *))*(void**)(__base - 2398))(__t__p0, __t__p1));\
	})

#define hb_subset_input_unicode_set(__p0) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(hb_subset_input_t *))*(void**)(__base - 2404))(__t__p0));\
	})

#define hb_subset_input_glyph_set(__p0) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(hb_subset_input_t *))*(void**)(__base - 2410))(__t__p0));\
	})

#define hb_subset_input_set(__p0, __p1) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		hb_subset_sets_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_set_t *(*)(hb_subset_input_t *, hb_subset_sets_t ))*(void**)(__base - 2416))(__t__p0, __t__p1));\
	})

#define hb_subset_input_get_flags(__p0) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_subset_flags_t (*)(hb_subset_input_t *))*(void**)(__base - 2422))(__t__p0));\
	})

#define hb_subset_input_set_flags(__p0, __p1) \
	({ \
		hb_subset_input_t * __t__p0 = __p0;\
		unsigned  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_subset_input_t *, unsigned ))*(void**)(__base - 2428))(__t__p0, __t__p1));\
	})

#define hb_subset_or_fail(__p0, __p1) \
	({ \
		hb_face_t * __t__p0 = __p0;\
		const hb_subset_input_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_face_t *(*)(hb_face_t *, const hb_subset_input_t *))*(void**)(__base - 2434))(__t__p0, __t__p1));\
	})

#define hb_buffer_set_not_found_glyph(__p0, __p1) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		hb_codepoint_t  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_buffer_t *, hb_codepoint_t ))*(void**)(__base - 2440))(__t__p0, __t__p1));\
	})

#define hb_buffer_get_not_found_glyph(__p0) \
	({ \
		hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_codepoint_t (*)(hb_buffer_t *))*(void**)(__base - 2446))(__t__p0));\
	})

#define hb_segment_properties_overlay(__p0, __p1) \
	({ \
		hb_segment_properties_t * __t__p0 = __p0;\
		const hb_segment_properties_t * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_segment_properties_t *, const hb_segment_properties_t *))*(void**)(__base - 2452))(__t__p0, __t__p1));\
	})

#define hb_buffer_create_similar(__p0) \
	({ \
		const hb_buffer_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((hb_buffer_t *(*)(const hb_buffer_t *))*(void**)(__base - 2458))(__t__p0));\
	})

#define hb_font_set_synthetic_slant(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(hb_font_t *, float ))*(void**)(__base - 2464))(__t__p0, __t__p1));\
	})

#define hb_font_get_synthetic_slant(__p0) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(hb_font_t *))*(void**)(__base - 2470))(__t__p0));\
	})

#define hb_font_get_var_coords_design(__p0, __p1) \
	({ \
		hb_font_t * __t__p0 = __p0;\
		unsigned int * __t__p1 = __p1;\
		long __base = (long)(HARFBUZZ_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const float *(*)(hb_font_t *, unsigned int *))*(void**)(__base - 2476))(__t__p0, __t__p1));\
	})

#endif /* !_PPCINLINE_HARFBUZZ_H */
