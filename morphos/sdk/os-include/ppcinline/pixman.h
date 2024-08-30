/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PIXMAN_H
#define _PPCINLINE_PIXMAN_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PIXMAN_BASE_NAME
#define PIXMAN_BASE_NAME PixManBase
#endif /* !PIXMAN_BASE_NAME */

#define pixman_region32_init_with_extents(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_box32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *, pixman_box32_t *))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})

#define pixman_image_set_clip_region(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *, pixman_region16_t *))*(void**)(__base - 544))(__t__p0, __t__p1));\
	})

#define pixman_image_set_filter(__p0, __p1, __p2, __p3) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_filter_t  __t__p1 = __p1;\
		const pixman_fixed_t * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *, pixman_filter_t , const pixman_fixed_t *, int ))*(void**)(__base - 574))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_glyph_cache_lookup(__p0, __p1, __p2) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(pixman_glyph_cache_t *, void *, void *))*(void**)(__base - 844))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_get_format(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_format_code_t (*)(pixman_image_t *))*(void**)(__base - 760))(__t__p0));\
	})

#define pixman_region32_union_rect(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 394))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_transform_invert(__p0, __p1) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		const struct pixman_transform * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, const struct pixman_transform *))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define pixman_glyph_cache_create() \
	({ \
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_glyph_cache_t *(*)(void))*(void**)(__base - 820))());\
	})

#define pixman_format_supported_destination(__p0) \
	({ \
		pixman_format_code_t  __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_format_code_t ))*(void**)(__base - 490))(__t__p0));\
	})

#define pixman_image_set_destroy_function(__p0, __p1, __p2) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_image_destroy_func_t  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_image_destroy_func_t , void *))*(void**)(__base - 712))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_line_fixed_edge_init(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_edge_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		const pixman_line_fixed_t * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_edge_t *, int , pixman_fixed_t , const pixman_line_fixed_t *, int , int ))*(void**)(__base - 682))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_region32_n_rects(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_region32_t *))*(void**)(__base - 436))(__t__p0));\
	})

#define pixman_f_transform_multiply(__p0, __p1, __p2) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		const struct pixman_f_transform * __t__p1 = __p1;\
		const struct pixman_f_transform * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *, const struct pixman_f_transform *, const struct pixman_f_transform *))*(void**)(__base - 154))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_init_from_image(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *, pixman_image_t *))*(void**)(__base - 724))(__t__p0, __t__p1));\
	})

#define pixman_glyph_cache_freeze(__p0) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_glyph_cache_t *))*(void**)(__base - 832))(__t__p0));\
	})

#define pixman_sample_ceil_y(__p0, __p1) \
	({ \
		pixman_fixed_t  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_fixed_t (*)(pixman_fixed_t , int ))*(void**)(__base - 658))(__t__p0, __t__p1));\
	})

#define pixman_version() \
	({ \
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 478))());\
	})

#define pixman_region32_subtract(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		pixman_region32_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, pixman_region32_t *))*(void**)(__base - 400))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_copy(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *))*(void**)(__base - 250))(__t__p0, __t__p1));\
	})

#define pixman_image_create_bits_no_clear(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_format_code_t  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		uint32_t * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(pixman_format_code_t , int , int , uint32_t *, int ))*(void**)(__base - 814))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_region32_equal(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *))*(void**)(__base - 448))(__t__p0, __t__p1));\
	})

#define pixman_transform_point_3d(__p0, __p1) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		struct pixman_vector * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *, struct pixman_vector *))*(void**)(__base - 34))(__t__p0, __t__p1));\
	})

#define pixman_f_transform_rotate(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_f_transform * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		double  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_f_transform *, struct pixman_f_transform *, double , double ))*(void**)(__base - 178))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_composite_glyphs_no_mask(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		int32_t  __t__p3 = __p3;\
		int32_t  __t__p4 = __p4;\
		int32_t  __t__p5 = __p5;\
		int32_t  __t__p6 = __p6;\
		pixman_glyph_cache_t * __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		const pixman_glyph_t * __t__p9 = __p9;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, int32_t , int32_t , int32_t , int32_t , pixman_glyph_cache_t *, int , const pixman_glyph_t *))*(void**)(__base - 880))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})

#define pixman_image_create_radial_gradient(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const pixman_point_fixed_t * __t__p0 = __p0;\
		const pixman_point_fixed_t * __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		const pixman_gradient_stop_t * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(const pixman_point_fixed_t *, const pixman_point_fixed_t *, pixman_fixed_t , pixman_fixed_t , const pixman_gradient_stop_t *, int ))*(void**)(__base - 514))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_transform_point_31_16(__p0, __p1, __p2) \
	({ \
		const pixman_transform_t * __t__p0 = __p0;\
		const pixman_vector_48_16_t * __t__p1 = __p1;\
		pixman_vector_48_16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const pixman_transform_t *, const pixman_vector_48_16_t *, pixman_vector_48_16_t *))*(void**)(__base - 886))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_rasterize_trapezoid(__p0, __p1, __p2, __p3) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		const pixman_trapezoid_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, const pixman_trapezoid_t *, int , int ))*(void**)(__base - 706))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_region32_intersect(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		pixman_region32_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, pixman_region32_t *))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_transform_init_identity(__p0) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_transform *))*(void**)(__base - 28))(__t__p0));\
	})

#define pixman_region32_copy(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *))*(void**)(__base - 376))(__t__p0, __t__p1));\
	})

#define pixman_region_contains_point(__p0, __p1, __p2, __p3) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		pixman_box16_t * __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, int , int , pixman_box16_t *))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_region_subtract(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		pixman_region16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, pixman_region16_t *))*(void**)(__base - 274))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_add_traps(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		int16_t  __t__p1 = __p1;\
		int16_t  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const pixman_trap_t * __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, int16_t , int16_t , int , const pixman_trap_t *))*(void**)(__base - 694))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_f_transform_translate(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_f_transform * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		double  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_f_transform *, struct pixman_f_transform *, double , double ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_region32_rectangles(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_box32_t *(*)(pixman_region32_t *, int *))*(void**)(__base - 442))(__t__p0, __t__p1));\
	})

#define pixman_image_set_has_client_clip(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_bool_t  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_bool_t ))*(void**)(__base - 556))(__t__p0, __t__p1));\
	})

#define pixman_region32_reset(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_box32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *, pixman_box32_t *))*(void**)(__base - 460))(__t__p0, __t__p1));\
	})

#define pixman_image_get_width(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_image_t *))*(void**)(__base - 616))(__t__p0));\
	})

#define pixman_edge_init(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		pixman_edge_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		pixman_fixed_t  __t__p4 = __p4;\
		pixman_fixed_t  __t__p5 = __p5;\
		pixman_fixed_t  __t__p6 = __p6;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_edge_t *, int , pixman_fixed_t , pixman_fixed_t , pixman_fixed_t , pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define pixman_region_intersect(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		pixman_region16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, pixman_region16_t *))*(void**)(__base - 256))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_set_source_clipping(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_bool_t  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_bool_t ))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})

#define pixman_region32_init_from_image(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *, pixman_image_t *))*(void**)(__base - 736))(__t__p0, __t__p1));\
	})

#define pixman_image_create_linear_gradient(__p0, __p1, __p2, __p3) \
	({ \
		const pixman_point_fixed_t * __t__p0 = __p0;\
		const pixman_point_fixed_t * __t__p1 = __p1;\
		const pixman_gradient_stop_t * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(const pixman_point_fixed_t *, const pixman_point_fixed_t *, const pixman_gradient_stop_t *, int ))*(void**)(__base - 508))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_image_create_bits(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_format_code_t  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		uint32_t * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(pixman_format_code_t , int , int , uint32_t *, int ))*(void**)(__base - 526))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_transform_translate(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		struct pixman_transform * __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 82))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_image_get_data(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint32_t *(*)(pixman_image_t *))*(void**)(__base - 610))(__t__p0));\
	})

#define pixman_image_create_conical_gradient(__p0, __p1, __p2, __p3) \
	({ \
		const pixman_point_fixed_t * __t__p0 = __p0;\
		pixman_fixed_t  __t__p1 = __p1;\
		const pixman_gradient_stop_t * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(const pixman_point_fixed_t *, pixman_fixed_t , const pixman_gradient_stop_t *, int ))*(void**)(__base - 520))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_region32_union(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		pixman_region32_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, pixman_region32_t *))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_init(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *))*(void**)(__base - 214))(__t__p0));\
	})

#define pixman_image_set_component_alpha(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_bool_t  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_bool_t ))*(void**)(__base - 592))(__t__p0, __t__p1));\
	})

#define pixman_region32_intersect_rect(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 742))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_version_string() \
	({ \
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 484))());\
	})

#define pixman_region32_not_empty(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *))*(void**)(__base - 424))(__t__p0));\
	})

#define pixman_transform_is_inverse(__p0, __p1) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		const struct pixman_transform * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *, const struct pixman_transform *))*(void**)(__base - 118))(__t__p0, __t__p1));\
	})

#define pixman_glyph_cache_insert(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		pixman_image_t * __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(pixman_glyph_cache_t *, void *, void *, int , int , pixman_image_t *))*(void**)(__base - 850))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_image_fill_boxes(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		const pixman_color_t * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const pixman_box32_t * __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_op_t , pixman_image_t *, const pixman_color_t *, int , const pixman_box32_t *))*(void**)(__base - 766))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_region32_translate(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *, int , int ))*(void**)(__base - 370))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region32_init(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *))*(void**)(__base - 340))(__t__p0));\
	})

#define pixman_region_init_with_extents(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_box16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *, pixman_box16_t *))*(void**)(__base - 232))(__t__p0, __t__p1));\
	})

#define pixman_region32_extents(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_box32_t *(*)(pixman_region32_t *))*(void**)(__base - 430))(__t__p0));\
	})

#define pixman_region_inverse(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		pixman_box16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, pixman_box16_t *))*(void**)(__base - 280))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_get_destroy_data(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(pixman_image_t *))*(void**)(__base - 748))(__t__p0));\
	})

#define pixman_image_set_repeat(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_repeat_t  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_repeat_t ))*(void**)(__base - 568))(__t__p0, __t__p1));\
	})

#define pixman_region_union_rect(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 268))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_f_transform_bounds(__p0, __p1) \
	({ \
		const struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_box16 * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_f_transform *, struct pixman_box16 *))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define pixman_transform_point(__p0, __p1) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		struct pixman_vector * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *, struct pixman_vector *))*(void**)(__base - 40))(__t__p0, __t__p1));\
	})

#define pixman_region_not_empty(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *))*(void**)(__base - 298))(__t__p0));\
	})

#define pixman_region32_init_rects(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		const pixman_box32_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, const pixman_box32_t *, int ))*(void**)(__base - 352))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_translate(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *, int , int ))*(void**)(__base - 244))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_equal(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *))*(void**)(__base - 322))(__t__p0, __t__p1));\
	})

#define pixman_image_set_alpha_map(__p0, __p1, __p2, __p3) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		int16_t  __t__p2 = __p2;\
		int16_t  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_image_t *, int16_t , int16_t ))*(void**)(__base - 586))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_f_transform_init_rotate(__p0, __p1, __p2) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *, double , double ))*(void**)(__base - 172))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_sample_floor_y(__p0, __p1) \
	({ \
		pixman_fixed_t  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_fixed_t (*)(pixman_fixed_t , int ))*(void**)(__base - 664))(__t__p0, __t__p1));\
	})

#define pixman_transform_rotate(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		struct pixman_transform * __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 70))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_image_composite(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_image_t * __t__p3 = __p3;\
		int16_t  __t__p4 = __p4;\
		int16_t  __t__p5 = __p5;\
		int16_t  __t__p6 = __p6;\
		int16_t  __t__p7 = __p7;\
		int16_t  __t__p8 = __p8;\
		int16_t  __t__p9 = __p9;\
		uint16_t  __t__p10 = __p10;\
		uint16_t  __t__p11 = __p11;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, pixman_image_t *, int16_t , int16_t , int16_t , int16_t , int16_t , int16_t , uint16_t , uint16_t ))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})

#define pixman_region_n_rects(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_region16_t *))*(void**)(__base - 310))(__t__p0));\
	})

#define pixman_transform_is_identity(__p0) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *))*(void**)(__base - 100))(__t__p0));\
	})

#define pixman_f_transform_point(__p0, __p1) \
	({ \
		const struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_f_vector * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_f_transform *, struct pixman_f_vector *))*(void**)(__base - 142))(__t__p0, __t__p1));\
	})

#define pixman_transform_multiply(__p0, __p1, __p2) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		const struct pixman_transform * __t__p1 = __p1;\
		const struct pixman_transform * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, const struct pixman_transform *, const struct pixman_transform *))*(void**)(__base - 46))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_create_solid_fill(__p0) \
	({ \
		const pixman_color_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(const pixman_color_t *))*(void**)(__base - 502))(__t__p0));\
	})

#define pixman_transform_init_translate(__p0, __p1, __p2) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		pixman_fixed_t  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 76))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_glyph_cache_thaw(__p0) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_glyph_cache_t *))*(void**)(__base - 838))(__t__p0));\
	})

#define pixman_region32_init_rect(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 346))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_region32_clear(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *))*(void**)(__base - 808))(__t__p0));\
	})

#define pixman_rasterize_edges(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_edge_t * __t__p1 = __p1;\
		pixman_edge_t * __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		pixman_fixed_t  __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_edge_t *, pixman_edge_t *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 688))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_region32_contains_point(__p0, __p1, __p2, __p3) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		pixman_box32_t * __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, int , int , pixman_box32_t *))*(void**)(__base - 412))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_add_trapezoids(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		int16_t  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const pixman_trapezoid_t * __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, int16_t , int , int , const pixman_trapezoid_t *))*(void**)(__base - 700))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_add_triangles(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		int32_t  __t__p1 = __p1;\
		int32_t  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const pixman_triangle_t * __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, int32_t , int32_t , int , const pixman_triangle_t *))*(void**)(__base - 790))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_image_set_indexed(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		const pixman_indexed_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, const pixman_indexed_t *))*(void**)(__base - 604))(__t__p0, __t__p1));\
	})

#define pixman_transform_point_31_16_affine(__p0, __p1, __p2) \
	({ \
		const pixman_transform_t * __t__p0 = __p0;\
		const pixman_vector_48_16_t * __t__p1 = __p1;\
		pixman_vector_48_16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const pixman_transform_t *, const pixman_vector_48_16_t *, pixman_vector_48_16_t *))*(void**)(__base - 892))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_reset(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_box16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *, pixman_box16_t *))*(void**)(__base - 334))(__t__p0, __t__p1));\
	})

#define pixman_f_transform_point_3d(__p0, __p1) \
	({ \
		const struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_f_vector * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const struct pixman_f_transform *, struct pixman_f_vector *))*(void**)(__base - 148))(__t__p0, __t__p1));\
	})

#define pixman_transform_from_pixman_f_transform(__p0, __p1) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		const struct pixman_f_transform * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, const struct pixman_f_transform *))*(void**)(__base - 124))(__t__p0, __t__p1));\
	})

#define pixman_region_rectangles(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_box16_t *(*)(pixman_region16_t *, int *))*(void**)(__base - 316))(__t__p0, __t__p1));\
	})

#define pixman_compute_composite_region(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_image_t * __t__p3 = __p3;\
		int16_t  __t__p4 = __p4;\
		int16_t  __t__p5 = __p5;\
		int16_t  __t__p6 = __p6;\
		int16_t  __t__p7 = __p7;\
		int16_t  __t__p8 = __p8;\
		int16_t  __t__p9 = __p9;\
		uint16_t  __t__p10 = __p10;\
		uint16_t  __t__p11 = __p11;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_image_t *, pixman_image_t *, pixman_image_t *, int16_t , int16_t , int16_t , int16_t , int16_t , int16_t , uint16_t , uint16_t ))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})

#define pixman_filter_create_separable_convolution(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		int * __t__p0 = __p0;\
		pixman_fixed_t  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_kernel_t  __t__p3 = __p3;\
		pixman_kernel_t  __t__p4 = __p4;\
		pixman_kernel_t  __t__p5 = __p5;\
		pixman_kernel_t  __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_fixed_t *(*)(int *, pixman_fixed_t , pixman_fixed_t , pixman_kernel_t , pixman_kernel_t , pixman_kernel_t , pixman_kernel_t , int , int ))*(void**)(__base - 904))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define pixman_f_transform_invert(__p0, __p1) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		const struct pixman_f_transform * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_f_transform *, const struct pixman_f_transform *))*(void**)(__base - 136))(__t__p0, __t__p1));\
	})

#define pixman_composite_glyphs(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11, __p12, __p13, __p14) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_format_code_t  __t__p3 = __p3;\
		int32_t  __t__p4 = __p4;\
		int32_t  __t__p5 = __p5;\
		int32_t  __t__p6 = __p6;\
		int32_t  __t__p7 = __p7;\
		int32_t  __t__p8 = __p8;\
		int32_t  __t__p9 = __p9;\
		int32_t  __t__p10 = __p10;\
		int32_t  __t__p11 = __p11;\
		pixman_glyph_cache_t * __t__p12 = __p12;\
		int  __t__p13 = __p13;\
		const pixman_glyph_t * __t__p14 = __p14;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, pixman_format_code_t , int32_t , int32_t , int32_t , int32_t , int32_t , int32_t , int32_t , int32_t , pixman_glyph_cache_t *, int , const pixman_glyph_t *))*(void**)(__base - 874))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11, __t__p12, __t__p13, __t__p14));\
	})

#define pixman_region_init_rect(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		unsigned int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 220))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})


#define pixman_edge_step(__p0, __p1) \
	({ \
		pixman_edge_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_edge_t *, int ))*(void**)(__base - 670))(__t__p0, __t__p1));\
	})

#define pixman_image_get_depth(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_image_t *))*(void**)(__base - 634))(__t__p0));\
	})

#define pixman_transform_scale(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		struct pixman_transform * __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		pixman_fixed_t  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_transform *, struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_glyph_get_mask_format(__p0, __p1, __p2) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const pixman_glyph_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_format_code_t (*)(pixman_glyph_cache_t *, int , const pixman_glyph_t *))*(void**)(__base - 868))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_transform_is_scale(__p0) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *))*(void**)(__base - 106))(__t__p0));\
	})

#define pixman_image_set_transform(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		const pixman_transform_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *, const pixman_transform_t *))*(void**)(__base - 562))(__t__p0, __t__p1));\
	})

#define pixman_f_transform_from_pixman_transform(__p0, __p1) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		const struct pixman_transform * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *, const struct pixman_transform *))*(void**)(__base - 130))(__t__p0, __t__p1));\
	})

#define pixman_format_supported_source(__p0) \
	({ \
		pixman_format_code_t  __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_format_code_t ))*(void**)(__base - 496))(__t__p0));\
	})

#define pixman_transform_point_31_16_3d(__p0, __p1, __p2) \
	({ \
		const pixman_transform_t * __t__p0 = __p0;\
		const pixman_vector_48_16_t * __t__p1 = __p1;\
		pixman_vector_48_16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const pixman_transform_t *, const pixman_vector_48_16_t *, pixman_vector_48_16_t *))*(void**)(__base - 898))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_fini(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *))*(void**)(__base - 238))(__t__p0));\
	})

#define pixman_region_contains_rectangle(__p0, __p1) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_box16_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_region_overlap_t (*)(pixman_region16_t *, pixman_box16_t *))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})

#define pixman_region_union(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		pixman_region16_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, pixman_region16_t *))*(void**)(__base - 262))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_f_transform_scale(__p0, __p1, __p2, __p3) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		struct pixman_f_transform * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		double  __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(struct pixman_f_transform *, struct pixman_f_transform *, double , double ))*(void**)(__base - 166))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_image_set_accessors(__p0, __p1, __p2) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_read_memory_func_t  __t__p1 = __p1;\
		pixman_write_memory_func_t  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_image_t *, pixman_read_memory_func_t , pixman_write_memory_func_t ))*(void**)(__base - 598))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_fill_rectangles(__p0, __p1, __p2, __p3, __p4) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		const pixman_color_t * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const pixman_rectangle16_t * __t__p4 = __p4;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_op_t , pixman_image_t *, const pixman_color_t *, int , const pixman_rectangle16_t *))*(void**)(__base - 640))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define pixman_blt(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		uint32_t * __t__p0 = __p0;\
		uint32_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		int  __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		int  __t__p9 = __p9;\
		int  __t__p10 = __p10;\
		int  __t__p11 = __p11;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(uint32_t *, uint32_t *, int , int , int , int , int , int , int , int , int , int ))*(void**)(__base - 466))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})

#define pixman_image_set_clip_region32(__p0, __p1) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *, pixman_region32_t *))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})

#define pixman_region32_fini(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region32_t *))*(void**)(__base - 364))(__t__p0));\
	})

#define pixman_f_transform_init_translate(__p0, __p1, __p2) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *, double , double ))*(void**)(__base - 184))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_glyph_cache_remove(__p0, __p1, __p2) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_glyph_cache_t *, void *, void *))*(void**)(__base - 856))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_f_transform_init_scale(__p0, __p1, __p2) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *, double , double ))*(void**)(__base - 160))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_unref(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *))*(void**)(__base - 538))(__t__p0));\
	})

#define pixman_image_get_height(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_image_t *))*(void**)(__base - 622))(__t__p0));\
	})

#define pixman_image_get_stride(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(pixman_image_t *))*(void**)(__base - 628))(__t__p0));\
	})

#define pixman_transform_bounds(__p0, __p1) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		struct pixman_box16 * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *, struct pixman_box16 *))*(void**)(__base - 88))(__t__p0, __t__p1));\
	})

#define pixman_transform_is_int_translate(__p0) \
	({ \
		const struct pixman_transform * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(const struct pixman_transform *))*(void**)(__base - 112))(__t__p0));\
	})

#define pixman_image_composite32(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_image_t * __t__p3 = __p3;\
		int32_t  __t__p4 = __p4;\
		int32_t  __t__p5 = __p5;\
		int32_t  __t__p6 = __p6;\
		int32_t  __t__p7 = __p7;\
		int32_t  __t__p8 = __p8;\
		int32_t  __t__p9 = __p9;\
		int32_t  __t__p10 = __p10;\
		int32_t  __t__p11 = __p11;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, pixman_image_t *, int32_t , int32_t , int32_t , int32_t , int32_t , int32_t , int32_t , int32_t ))*(void**)(__base - 772))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})

#define pixman_composite_trapezoids(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_format_code_t  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		int  __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		const pixman_trapezoid_t * __t__p9 = __p9;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, pixman_format_code_t , int , int , int , int , int , const pixman_trapezoid_t *))*(void**)(__base - 778))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})

#define pixman_f_transform_init_identity(__p0) \
	({ \
		struct pixman_f_transform * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_f_transform *))*(void**)(__base - 202))(__t__p0));\
	})

#define pixman_region32_selfcheck(__p0) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *))*(void**)(__base - 454))(__t__p0));\
	})

#define pixman_transform_init_scale(__p0, __p1, __p2) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		pixman_fixed_t  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 52))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_init_rects(__p0, __p1, __p2) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		const pixman_box16_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, const pixman_box16_t *, int ))*(void**)(__base - 226))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_region_extents(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_box16_t *(*)(pixman_region16_t *))*(void**)(__base - 304))(__t__p0));\
	})

#define pixman_glyph_get_extents(__p0, __p1, __p2, __p3) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		pixman_glyph_t * __t__p2 = __p2;\
		pixman_box32_t * __t__p3 = __p3;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_glyph_cache_t *, int , pixman_glyph_t *, pixman_box32_t *))*(void**)(__base - 862))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define pixman_transform_init_rotate(__p0, __p1, __p2) \
	({ \
		struct pixman_transform * __t__p0 = __p0;\
		pixman_fixed_t  __t__p1 = __p1;\
		pixman_fixed_t  __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(struct pixman_transform *, pixman_fixed_t , pixman_fixed_t ))*(void**)(__base - 64))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_image_ref(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_image_t *(*)(pixman_image_t *))*(void**)(__base - 532))(__t__p0));\
	})

#define pixman_region32_inverse(__p0, __p1, __p2) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_region32_t * __t__p1 = __p1;\
		pixman_box32_t * __t__p2 = __p2;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region32_t *, pixman_region32_t *, pixman_box32_t *))*(void**)(__base - 406))(__t__p0, __t__p1, __t__p2));\
	})

#define pixman_composite_triangles(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		pixman_op_t  __t__p0 = __p0;\
		pixman_image_t * __t__p1 = __p1;\
		pixman_image_t * __t__p2 = __p2;\
		pixman_format_code_t  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		int  __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		const pixman_triangle_t * __t__p9 = __p9;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_op_t , pixman_image_t *, pixman_image_t *, pixman_format_code_t , int , int , int , int , int , const pixman_triangle_t *))*(void**)(__base - 784))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})

#define pixman_image_get_component_alpha(__p0) \
	({ \
		pixman_image_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_image_t *))*(void**)(__base - 754))(__t__p0));\
	})

#define pixman_region_intersect_rect(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		pixman_region16_t * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		unsigned int  __t__p4 = __p4;\
		unsigned int  __t__p5 = __p5;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *, pixman_region16_t *, int , int , unsigned int , unsigned int ))*(void**)(__base - 730))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define pixman_glyph_cache_destroy(__p0) \
	({ \
		pixman_glyph_cache_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_glyph_cache_t *))*(void**)(__base - 826))(__t__p0));\
	})

#define pixman_region_clear(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(pixman_region16_t *))*(void**)(__base - 802))(__t__p0));\
	})

#define pixman_region32_contains_rectangle(__p0, __p1) \
	({ \
		pixman_region32_t * __t__p0 = __p0;\
		pixman_box32_t * __t__p1 = __p1;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_region_overlap_t (*)(pixman_region32_t *, pixman_box32_t *))*(void**)(__base - 418))(__t__p0, __t__p1));\
	})

#define pixman_fill(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		uint32_t * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		int  __t__p6 = __p6;\
		uint32_t  __t__p7 = __p7;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(uint32_t *, int , int , int , int , int , int , uint32_t ))*(void**)(__base - 472))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define pixman_region_selfcheck(__p0) \
	({ \
		pixman_region16_t * __t__p0 = __p0;\
		long __base = (long)(PIXMAN_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((pixman_bool_t (*)(pixman_region16_t *))*(void**)(__base - 328))(__t__p0));\
	})

#endif /* !_PPCINLINE_PIXMAN_H */
