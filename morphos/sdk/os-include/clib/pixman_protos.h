#ifndef CLIB_PIXMAN_PROTOS_H
#define CLIB_PIXMAN_PROTOS_H

/*
	pixman.library C prototypes

	Copyright � 2009-2020 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_PIXMAN_H
# include <libraries/pixman.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

void          pixman_transform_init_identity    (struct pixman_transform       *matrix);
pixman_bool_t pixman_transform_point_3d         (const struct pixman_transform *transform,
						 struct pixman_vector          *vector);
pixman_bool_t pixman_transform_point            (const struct pixman_transform *transform,
						 struct pixman_vector          *vector);
pixman_bool_t pixman_transform_multiply         (struct pixman_transform       *dst,
						 const struct pixman_transform *l,
						 const struct pixman_transform *r);
void          pixman_transform_init_scale       (struct pixman_transform       *t,
						 pixman_fixed_t                 sx,
						 pixman_fixed_t                 sy);
pixman_bool_t pixman_transform_scale            (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 sx,
						 pixman_fixed_t                 sy);
void          pixman_transform_init_rotate      (struct pixman_transform       *t,
						 pixman_fixed_t                 cos,
						 pixman_fixed_t                 sin);
pixman_bool_t pixman_transform_rotate           (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 c,
						 pixman_fixed_t                 s);
void          pixman_transform_init_translate   (struct pixman_transform       *t,
						 pixman_fixed_t                 tx,
						 pixman_fixed_t                 ty);
pixman_bool_t pixman_transform_translate        (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 tx,
						 pixman_fixed_t                 ty);
pixman_bool_t pixman_transform_bounds           (const struct pixman_transform *matrix,
						 struct pixman_box16           *b);
pixman_bool_t pixman_transform_invert           (struct pixman_transform       *dst,
						 const struct pixman_transform *src);
pixman_bool_t pixman_transform_is_identity      (const struct pixman_transform *t);
pixman_bool_t pixman_transform_is_scale         (const struct pixman_transform *t);
pixman_bool_t pixman_transform_is_int_translate (const struct pixman_transform *t);
pixman_bool_t pixman_transform_is_inverse       (const struct pixman_transform *a,
						 const struct pixman_transform *b);

pixman_bool_t pixman_transform_from_pixman_f_transform (struct pixman_transform         *t,
							const struct pixman_f_transform *ft);
void          pixman_f_transform_from_pixman_transform (struct pixman_f_transform       *ft,
							const struct pixman_transform   *t);
pixman_bool_t pixman_f_transform_invert                (struct pixman_f_transform       *dst,
							const struct pixman_f_transform *src);
pixman_bool_t pixman_f_transform_point                 (const struct pixman_f_transform *t,
							struct pixman_f_vector          *v);
void          pixman_f_transform_point_3d              (const struct pixman_f_transform *t,
							struct pixman_f_vector          *v);
void          pixman_f_transform_multiply              (struct pixman_f_transform       *dst,
							const struct pixman_f_transform *l,
							const struct pixman_f_transform *r);
void          pixman_f_transform_init_scale            (struct pixman_f_transform       *t,
							double                           sx,
							double                           sy);
pixman_bool_t pixman_f_transform_scale                 (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           sx,
							double                           sy);
void          pixman_f_transform_init_rotate           (struct pixman_f_transform       *t,
							double                           cos,
							double                           sin);
pixman_bool_t pixman_f_transform_rotate                (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           c,
							double                           s);
void          pixman_f_transform_init_translate        (struct pixman_f_transform       *t,
							double                           tx,
							double                           ty);
pixman_bool_t pixman_f_transform_translate             (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           tx,
							double                           ty);
pixman_bool_t pixman_f_transform_bounds                (const struct pixman_f_transform *t,
							struct pixman_box16             *b);
void          pixman_f_transform_init_identity         (struct pixman_f_transform       *t);

void                    pixman_region_init               (pixman_region16_t *region);
void                    pixman_region_init_rect          (pixman_region16_t *region,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);
pixman_bool_t           pixman_region_init_rects         (pixman_region16_t *region,
							  const pixman_box16_t *boxes,
							  int                count);
void                    pixman_region_init_with_extents  (pixman_region16_t *region,
							  pixman_box16_t    *extents);
void                    pixman_region_init_from_image    (pixman_region16_t *region,
							  pixman_image_t    *image);
void                    pixman_region_fini               (pixman_region16_t *region);

void                    pixman_region_translate          (pixman_region16_t *region,
							  int                x,
							  int                y);
pixman_bool_t           pixman_region_copy               (pixman_region16_t *dest,
							  pixman_region16_t *source);
pixman_bool_t           pixman_region_intersect          (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_region16_t *reg2);
pixman_bool_t           pixman_region_union              (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_region16_t *reg2);
pixman_bool_t           pixman_region_union_rect         (pixman_region16_t *dest,
							  pixman_region16_t *source,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);
pixman_bool_t		pixman_region_intersect_rect     (pixman_region16_t *dest,
							  pixman_region16_t *source,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);
pixman_bool_t           pixman_region_subtract           (pixman_region16_t *reg_d,
							  pixman_region16_t *reg_m,
							  pixman_region16_t *reg_s);
pixman_bool_t           pixman_region_inverse            (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_box16_t    *inv_rect);
pixman_bool_t           pixman_region_contains_point     (pixman_region16_t *region,
							  int                x,
							  int                y,
							  pixman_box16_t    *box);
pixman_region_overlap_t pixman_region_contains_rectangle (pixman_region16_t *region,
							  pixman_box16_t    *prect);
pixman_bool_t           pixman_region_not_empty          (pixman_region16_t *region);
pixman_box16_t *        pixman_region_extents            (pixman_region16_t *region);
int                     pixman_region_n_rects            (pixman_region16_t *region);
pixman_box16_t *        pixman_region_rectangles         (pixman_region16_t *region,
							  int               *n_rects);
pixman_bool_t           pixman_region_equal              (pixman_region16_t *region1,
							  pixman_region16_t *region2);
pixman_bool_t           pixman_region_selfcheck          (pixman_region16_t *region);
void                    pixman_region_reset              (pixman_region16_t *region,
							  pixman_box16_t    *box);

void                    pixman_region32_init               (pixman_region32_t *region);
void                    pixman_region32_init_rect          (pixman_region32_t *region,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);
pixman_bool_t           pixman_region32_init_rects         (pixman_region32_t *region,
							    const pixman_box32_t *boxes,
							    int                count);
void                    pixman_region32_init_with_extents  (pixman_region32_t *region,
							    pixman_box32_t    *extents);
void                    pixman_region32_init_from_image    (pixman_region32_t *region,
							    pixman_image_t    *image);
void                    pixman_region32_fini               (pixman_region32_t *region);

void                    pixman_region32_translate          (pixman_region32_t *region,
							    int                x,
							    int                y);
pixman_bool_t           pixman_region32_copy               (pixman_region32_t *dest,
							    pixman_region32_t *source);
pixman_bool_t           pixman_region32_intersect          (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_region32_t *reg2);
pixman_bool_t           pixman_region32_union              (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_region32_t *reg2);
pixman_bool_t		pixman_region32_intersect_rect     (pixman_region32_t *dest,
							    pixman_region32_t *source,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);
pixman_bool_t           pixman_region32_union_rect         (pixman_region32_t *dest,
							    pixman_region32_t *source,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);
pixman_bool_t           pixman_region32_subtract           (pixman_region32_t *reg_d,
							    pixman_region32_t *reg_m,
							    pixman_region32_t *reg_s);
pixman_bool_t           pixman_region32_inverse            (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_box32_t    *inv_rect);
pixman_bool_t           pixman_region32_contains_point     (pixman_region32_t *region,
							    int                x,
							    int                y,
							    pixman_box32_t    *box);
pixman_region_overlap_t pixman_region32_contains_rectangle (pixman_region32_t *region,
							    pixman_box32_t    *prect);
pixman_bool_t           pixman_region32_not_empty          (pixman_region32_t *region);
pixman_box32_t *        pixman_region32_extents            (pixman_region32_t *region);
int                     pixman_region32_n_rects            (pixman_region32_t *region);
pixman_box32_t *        pixman_region32_rectangles         (pixman_region32_t *region,
							    int               *n_rects);
pixman_bool_t           pixman_region32_equal              (pixman_region32_t *region1,
							    pixman_region32_t *region2);
pixman_bool_t           pixman_region32_selfcheck          (pixman_region32_t *region);
void                    pixman_region32_reset              (pixman_region32_t *region,
							    pixman_box32_t    *box);

pixman_bool_t pixman_blt                (uint32_t           *src_bits,
					 uint32_t           *dst_bits,
					 int                 src_stride,
					 int                 dst_stride,
					 int                 src_bpp,
					 int                 dst_bpp,
					 int                 src_x,
					 int                 src_y,
					 int                 dest_x,
					 int                 dest_y,
					 int                 width,
					 int                 height);
pixman_bool_t pixman_fill               (uint32_t           *bits,
					 int                 stride,
					 int                 bpp,
					 int                 x,
					 int                 y,
					 int                 width,
					 int                 height,
					 uint32_t            _xor);

int           pixman_version            (void);
const char*   pixman_version_string     (void);

pixman_bool_t pixman_format_supported_destination (pixman_format_code_t format);
pixman_bool_t pixman_format_supported_source      (pixman_format_code_t format);

pixman_image_t *pixman_image_create_solid_fill       (const pixman_color_t         *color);
pixman_image_t *pixman_image_create_linear_gradient  (const pixman_point_fixed_t   *p1,
						      const pixman_point_fixed_t   *p2,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);
pixman_image_t *pixman_image_create_radial_gradient  (const pixman_point_fixed_t   *inner,
						      const pixman_point_fixed_t   *outer,
						      pixman_fixed_t                inner_radius,
						      pixman_fixed_t                outer_radius,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);
pixman_image_t *pixman_image_create_conical_gradient (const pixman_point_fixed_t   *center,
						      pixman_fixed_t                angle,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);
pixman_image_t *pixman_image_create_bits             (pixman_format_code_t          format,
						      int                           width,
						      int                           height,
						      uint32_t                     *bits,
						      int                           rowstride_bytes);

pixman_image_t *pixman_image_ref                     (pixman_image_t               *image);
pixman_bool_t   pixman_image_unref                   (pixman_image_t               *image);

void		pixman_image_set_destroy_function    (pixman_image_t		   *image,
						      pixman_image_destroy_func_t   function,
						      void			   *data);
void *		pixman_image_get_destroy_data        (pixman_image_t		   *image);

pixman_bool_t   pixman_image_set_clip_region         (pixman_image_t               *image,
						      pixman_region16_t            *region);
pixman_bool_t   pixman_image_set_clip_region32       (pixman_image_t               *image,
						      pixman_region32_t            *region);
void		pixman_image_set_has_client_clip     (pixman_image_t               *image,
						      pixman_bool_t		    clien_clip);
pixman_bool_t   pixman_image_set_transform           (pixman_image_t               *image,
						      const pixman_transform_t     *transform);
void            pixman_image_set_repeat              (pixman_image_t               *image,
						      pixman_repeat_t               repeat);
void            pixman_image_set_dither              (pixman_image_t               *image,
						      pixman_dither_t               dither);
void            pixman_image_set_dither_offset       (pixman_image_t               *image,
						      int                           offset_x,
						      int                           offset_y);
pixman_bool_t   pixman_image_set_filter              (pixman_image_t               *image,
						      pixman_filter_t               filter,
						      const pixman_fixed_t         *filter_params,
						      int                           n_filter_params);
void		pixman_image_set_source_clipping     (pixman_image_t		   *image,
						      pixman_bool_t                 source_clipping);
void            pixman_image_set_alpha_map           (pixman_image_t               *image,
						      pixman_image_t               *alpha_map,
						      int16_t                       x,
						      int16_t                       y);
void            pixman_image_set_component_alpha     (pixman_image_t               *image,
						      pixman_bool_t                 component_alpha);
pixman_bool_t   pixman_image_get_component_alpha     (pixman_image_t               *image);
void		pixman_image_set_accessors	     (pixman_image_t		   *image,
						      pixman_read_memory_func_t	    read_func,
						      pixman_write_memory_func_t    write_func);
void		pixman_image_set_indexed	     (pixman_image_t		   *image,
						      const pixman_indexed_t	   *indexed);
uint32_t       *pixman_image_get_data                (pixman_image_t               *image);
int		pixman_image_get_width               (pixman_image_t               *image);
int             pixman_image_get_height              (pixman_image_t               *image);
int		pixman_image_get_stride              (pixman_image_t               *image); /* in bytes */
int		pixman_image_get_depth               (pixman_image_t		   *image);
pixman_format_code_t pixman_image_get_format	     (pixman_image_t		   *image);
pixman_bool_t	pixman_image_fill_rectangles	     (pixman_op_t		    op,
						      pixman_image_t		   *image,
						      const pixman_color_t	   *color,
						      int			    n_rects,
						      const pixman_rectangle16_t   *rects);
pixman_bool_t   pixman_image_fill_boxes              (pixman_op_t                   op,
                                                      pixman_image_t               *dest,
                                                      const pixman_color_t         *color,
                                                      int                           n_boxes,
                                                      const pixman_box32_t         *boxes);

pixman_bool_t pixman_compute_composite_region (pixman_region16_t *region,
					       pixman_image_t    *src_image,
					       pixman_image_t    *mask_image,
					       pixman_image_t    *dest_image,
					       int16_t            src_x,
					       int16_t            src_y,
					       int16_t            mask_x,
					       int16_t            mask_y,
					       int16_t            dest_x,
					       int16_t            dest_y,
					       uint16_t           width,
					       uint16_t           height);
void          pixman_image_composite          (pixman_op_t        op,
					       pixman_image_t    *src,
					       pixman_image_t    *mask,
					       pixman_image_t    *dest,
					       int16_t            src_x,
					       int16_t            src_y,
					       int16_t            mask_x,
					       int16_t            mask_y,
					       int16_t            dest_x,
					       int16_t            dest_y,
					       uint16_t           width,
					       uint16_t           height);
void          pixman_image_composite32        (pixman_op_t        op,
					       pixman_image_t    *src,
					       pixman_image_t    *mask,
					       pixman_image_t    *dest,
					       int32_t            src_x,
					       int32_t            src_y,
					       int32_t            mask_x,
					       int32_t            mask_y,
					       int32_t            dest_x,
					       int32_t            dest_y,
					       int32_t            width,
					       int32_t            height);

pixman_fixed_t pixman_sample_ceil_y        (pixman_fixed_t             y,
					    int                        bpp);
pixman_fixed_t pixman_sample_floor_y       (pixman_fixed_t             y,
					    int                        bpp);
void           pixman_edge_step            (pixman_edge_t             *e,
					    int                        n);
void           pixman_edge_init            (pixman_edge_t             *e,
					    int                        bpp,
					    pixman_fixed_t             y_start,
					    pixman_fixed_t             x_top,
					    pixman_fixed_t             y_top,
					    pixman_fixed_t             x_bot,
					    pixman_fixed_t             y_bot);
void           pixman_line_fixed_edge_init (pixman_edge_t             *e,
					    int                        bpp,
					    pixman_fixed_t             y,
					    const pixman_line_fixed_t *line,
					    int                        x_off,
					    int                        y_off);
void           pixman_rasterize_edges      (pixman_image_t            *image,
					    pixman_edge_t             *l,
					    pixman_edge_t             *r,
					    pixman_fixed_t             t,
					    pixman_fixed_t             b);
void           pixman_add_traps            (pixman_image_t            *image,
					    int16_t                    x_off,
					    int16_t                    y_off,
					    int                        ntrap,
					    const pixman_trap_t       *traps);
void           pixman_add_trapezoids       (pixman_image_t            *image,
					    int16_t                    x_off,
					    int                        y_off,
					    int                        ntraps,
					    const pixman_trapezoid_t  *traps);
void           pixman_rasterize_trapezoid  (pixman_image_t            *image,
					    const pixman_trapezoid_t  *trap,
					    int                        x_off,
					    int                        y_off);
void          pixman_composite_trapezoids (pixman_op_t		       op,
					   pixman_image_t *	       src,
					   pixman_image_t *	       dst,
					   pixman_format_code_t	       mask_format,
					   int			       x_src,
					   int			       y_src,
					   int			       x_dst,
					   int			       y_dst,
					   int			       n_traps,
					   const pixman_trapezoid_t *  traps);
void          pixman_composite_triangles (pixman_op_t		       op,
					  pixman_image_t *	       src,
					  pixman_image_t *	       dst,
					  pixman_format_code_t	       mask_format,
					  int			       x_src,
					  int			       y_src,
					  int			       x_dst,
					  int			       y_dst,
					  int			       n_tris,
					  const pixman_triangle_t *    tris);
void	      pixman_add_triangles       (pixman_image_t              *image,
					  int32_t	               x_off,
					  int32_t	               y_off,
					  int	                       n_tris,
					  const pixman_triangle_t     *tris);


pixman_fixed_t *
pixman_filter_create_separable_convolution (int             *n_values,
					    pixman_fixed_t   scale_x,
					    pixman_fixed_t   scale_y,
					    pixman_kernel_t  reconstruct_x,
					    pixman_kernel_t  reconstruct_y,
					    pixman_kernel_t  sample_x,
					    pixman_kernel_t  sample_y,
					    int              subsample_bits_x,
					    int              subsample_bits_y);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_PIXMAN_PROTOS_H */
