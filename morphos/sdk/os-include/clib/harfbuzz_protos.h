#ifndef CLIB_HARFBUZZ_PROTOS_H
#define CLIB_HARFBUZZ_PROTOS_H

/*
	harfbuzz.library C prototypes

	Copyright © 2016-2022 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_HARFBUZZ_H
# include <libraries/harfbuzz.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

hb_tag_t hb_tag_from_string (const char *str, int len);
void hb_tag_to_string (hb_tag_t tag, char *buf);
hb_direction_t hb_direction_from_string (const char *str, int len);
const char *hb_direction_to_string (hb_direction_t direction);
hb_language_t hb_language_from_string (const char *str, int len);
const char *hb_language_to_string (hb_language_t language);
hb_language_t hb_language_get_default (void);
hb_script_t hb_script_from_iso15924_tag (hb_tag_t tag);
hb_script_t hb_script_from_string (const char *str, int len);
hb_tag_t hb_script_to_iso15924_tag (hb_script_t script);
hb_direction_t hb_script_get_horizontal_direction (hb_script_t script);
hb_bool_t hb_feature_from_string (const char *str, int len, hb_feature_t *feature);
void hb_feature_to_string (hb_feature_t *feature, char *buf, unsigned int size);
hb_bool_t hb_variation_from_string (const char *str, int len, hb_variation_t *variation);
void hb_variation_to_string (hb_variation_t *variation, char *buf, unsigned int size);

hb_blob_t *hb_blob_create (const char *data, unsigned int length, hb_memory_mode_t mode, void *user_data, hb_destroy_func_t destroy);
hb_blob_t *hb_blob_create_sub_blob (hb_blob_t *parent, unsigned int offset, unsigned int length);
hb_blob_t *hb_blob_get_empty (void);
hb_blob_t *hb_blob_reference (hb_blob_t *blob);
void hb_blob_destroy (hb_blob_t *blob);
hb_bool_t hb_blob_set_user_data (hb_blob_t *blob, hb_user_data_key_t *key, void * data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_blob_get_user_data (hb_blob_t *blob, hb_user_data_key_t *key);
void hb_blob_make_immutable (hb_blob_t *blob);
hb_bool_t hb_blob_is_immutable (hb_blob_t *blob);
unsigned int hb_blob_get_length (hb_blob_t *blob);
const char *hb_blob_get_data (hb_blob_t *blob, unsigned int *length);
char *hb_blob_get_data_writable (hb_blob_t *blob, unsigned int *length);
hb_blob_t *hb_blob_copy_writable_or_fail (hb_blob_t *blob);

hb_bool_t hb_segment_properties_equal (const hb_segment_properties_t *a, const hb_segment_properties_t *b);
unsigned int hb_segment_properties_hash (const hb_segment_properties_t *p);
hb_buffer_t *hb_buffer_create (void);
hb_buffer_t *hb_buffer_get_empty (void);
hb_buffer_t *hb_buffer_reference (hb_buffer_t *buffer);
void hb_buffer_destroy (hb_buffer_t *buffer);
hb_bool_t hb_buffer_set_user_data (hb_buffer_t *buffer, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_buffer_get_user_data (hb_buffer_t *buffer, hb_user_data_key_t *key);
void hb_buffer_set_content_type (hb_buffer_t *buffer, hb_buffer_content_type_t content_type);
hb_buffer_content_type_t hb_buffer_get_content_type (hb_buffer_t *buffer);
void hb_buffer_set_unicode_funcs (hb_buffer_t *buffer, hb_unicode_funcs_t *unicode_funcs);
hb_unicode_funcs_t *hb_buffer_get_unicode_funcs (hb_buffer_t *buffer);
void hb_buffer_set_direction (hb_buffer_t *buffer, hb_direction_t direction);
hb_direction_t hb_buffer_get_direction (hb_buffer_t *buffer);
void hb_buffer_set_script (hb_buffer_t *buffer, hb_script_t script);
hb_script_t hb_buffer_get_script (hb_buffer_t *buffer);
void hb_buffer_set_language (hb_buffer_t *buffer, hb_language_t language);
hb_language_t hb_buffer_get_language (hb_buffer_t *buffer);
void hb_buffer_set_segment_properties (hb_buffer_t *buffer, const hb_segment_properties_t *props);
void hb_buffer_get_segment_properties (hb_buffer_t *buffer, hb_segment_properties_t *props);
void hb_buffer_guess_segment_properties (hb_buffer_t *buffer);
void hb_buffer_set_flags (hb_buffer_t *buffer, hb_buffer_flags_t flags);
hb_buffer_flags_t hb_buffer_get_flags (hb_buffer_t *buffer);
void hb_buffer_set_cluster_level (hb_buffer_t *buffer, hb_buffer_cluster_level_t cluster_level);
hb_buffer_cluster_level_t hb_buffer_get_cluster_level (hb_buffer_t *buffer);
void hb_buffer_set_replacement_codepoint (hb_buffer_t *buffer, hb_codepoint_t replacement);
hb_codepoint_t hb_buffer_get_replacement_codepoint (hb_buffer_t *buffer);
void hb_buffer_reset (hb_buffer_t *buffer);
void hb_buffer_clear_contents (hb_buffer_t *buffer);
hb_bool_t hb_buffer_pre_allocate (hb_buffer_t *buffer, unsigned int size);
hb_bool_t hb_buffer_allocation_successful (hb_buffer_t *buffer);
void hb_buffer_reverse (hb_buffer_t *buffer);
void hb_buffer_reverse_range (hb_buffer_t *buffer, unsigned int start, unsigned int end);
void hb_buffer_reverse_clusters (hb_buffer_t *buffer);
void hb_buffer_add (hb_buffer_t *buffer, hb_codepoint_t codepoint, unsigned int cluster);
void hb_buffer_add_utf8 (hb_buffer_t *buffer, const char *text, int text_length, unsigned int item_offset, int item_length);
void hb_buffer_add_utf16 (hb_buffer_t *buffer, const uint16_t *text, int text_length, unsigned int item_offset, int item_length);
void hb_buffer_add_utf32 (hb_buffer_t *buffer, const uint32_t *text, int text_length, unsigned int item_offset, int item_length);
void hb_buffer_add_latin1 (hb_buffer_t *buffer, const uint8_t *text, int text_length, unsigned int item_offset, int item_length);
void hb_buffer_add_codepoints (hb_buffer_t *buffer, const hb_codepoint_t *text, int text_length, unsigned int item_offset, int item_length);
hb_bool_t hb_buffer_set_length (hb_buffer_t *buffer, unsigned int length);
unsigned int hb_buffer_get_length (hb_buffer_t *buffer);
hb_glyph_info_t *hb_buffer_get_glyph_infos (hb_buffer_t *buffer, unsigned int *length);
hb_glyph_position_t *hb_buffer_get_glyph_positions (hb_buffer_t *buffer, unsigned int *length);
void hb_buffer_normalize_glyphs (hb_buffer_t *buffer);
hb_buffer_serialize_format_t hb_buffer_serialize_format_from_string (const char *str, int len);
const char *hb_buffer_serialize_format_to_string (hb_buffer_serialize_format_t format);
const char **hb_buffer_serialize_list_formats (void);
unsigned int hb_buffer_serialize_glyphs (hb_buffer_t *buffer, unsigned int start, unsigned int end, char *buf, unsigned int buf_size, unsigned int *buf_consumed, hb_font_t *font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags);
hb_bool_t hb_buffer_deserialize_glyphs (hb_buffer_t *buffer, const char *buf, int buf_len, const char **end_ptr, hb_font_t *font, hb_buffer_serialize_format_t format);
void hb_buffer_set_message_func (hb_buffer_t *buffer, hb_buffer_message_func_t func, void *user_data, hb_destroy_func_t destroy);
#undef hb_glyph_info_get_glyph_flags
hb_glyph_flags_t hb_glyph_info_get_glyph_flags (const hb_glyph_info_t *info);
void hb_buffer_append (hb_buffer_t *buffer, hb_buffer_t *source, unsigned int start, unsigned int end);
hb_buffer_diff_flags_t hb_buffer_diff (hb_buffer_t *buffer, hb_buffer_t *reference, hb_codepoint_t dottedcircle_glyph, unsigned int position_fuzz);

hb_face_t *hb_face_create (hb_blob_t *blob, unsigned int index);
hb_face_t *hb_face_create_for_tables (hb_reference_table_func_t reference_table_func, void *user_data, hb_destroy_func_t destroy);
hb_face_t *hb_face_get_empty (void);
hb_face_t *hb_face_reference (hb_face_t *face);
void hb_face_destroy (hb_face_t *face);
hb_bool_t hb_face_set_user_data (hb_face_t *face, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_face_get_user_data (hb_face_t *face, hb_user_data_key_t *key);
void hb_face_make_immutable (hb_face_t *face);
hb_bool_t hb_face_is_immutable (hb_face_t *face);
hb_blob_t *hb_face_reference_table (hb_face_t *face, hb_tag_t tag);
hb_blob_t *hb_face_reference_blob (hb_face_t *face);
void hb_face_set_index (hb_face_t *face, unsigned int index);
unsigned int hb_face_get_index (hb_face_t *face);
void hb_face_set_upem (hb_face_t *face, unsigned int upem);
unsigned int hb_face_get_upem (hb_face_t *face);
void hb_face_set_glyph_count (hb_face_t *face, unsigned int glyph_count);
unsigned int hb_face_get_glyph_count (hb_face_t *face);
unsigned int hb_face_get_table_tags (hb_face_t *face, unsigned int start_offset, unsigned int *table_count, hb_tag_t *table_tags);

hb_font_funcs_t *hb_font_funcs_create (void);
hb_font_funcs_t *hb_font_funcs_get_empty (void);
hb_font_funcs_t *hb_font_funcs_reference (hb_font_funcs_t *ffuncs);
void hb_font_funcs_destroy (hb_font_funcs_t *ffuncs);
hb_bool_t hb_font_funcs_set_user_data (hb_font_funcs_t *ffuncs, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_font_funcs_get_user_data (hb_font_funcs_t *ffuncs, hb_user_data_key_t *key);
void hb_font_funcs_make_immutable (hb_font_funcs_t *ffuncs);
hb_bool_t hb_font_funcs_is_immutable (hb_font_funcs_t *ffuncs);
void hb_font_funcs_set_font_h_extents_func (hb_font_funcs_t *ffuncs, hb_font_get_font_h_extents_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_font_v_extents_func (hb_font_funcs_t *ffuncs, hb_font_get_font_v_extents_func_t func, void *user_data, hb_destroy_func_t destroy);
HB_DEPRECATED_FOR (hb_font_funcs_set_nominal_glyph_func and hb_font_funcs_set_variation_glyph_func) void hb_font_funcs_set_glyph_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_nominal_glyph_func (hb_font_funcs_t *ffuncs, hb_font_get_nominal_glyph_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_variation_glyph_func (hb_font_funcs_t *ffuncs, hb_font_get_variation_glyph_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_h_advance_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_h_advance_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_v_advance_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_v_advance_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_h_origin_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_h_origin_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_v_origin_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_v_origin_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_h_kerning_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_h_kerning_func_t func, void *user_data, hb_destroy_func_t destroy);
HB_DEPRECATED void hb_font_funcs_set_glyph_v_kerning_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_v_kerning_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_extents_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_extents_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_contour_point_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_contour_point_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_name_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_name_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_from_name_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_from_name_func_t func, void *user_data, hb_destroy_func_t destroy);
hb_bool_t hb_font_get_h_extents (hb_font_t *font, hb_font_extents_t *extents);
hb_bool_t hb_font_get_v_extents (hb_font_t *font, hb_font_extents_t *extents);
hb_bool_t hb_font_get_glyph (hb_font_t *font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t *glyph);
hb_bool_t hb_font_get_nominal_glyph (hb_font_t *font, hb_codepoint_t unicode, hb_codepoint_t *glyph);
hb_bool_t hb_font_get_variation_glyph (hb_font_t *font, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t *glyph);
hb_position_t hb_font_get_glyph_h_advance (hb_font_t *font, hb_codepoint_t glyph);
hb_position_t hb_font_get_glyph_v_advance (hb_font_t *font, hb_codepoint_t glyph);
hb_bool_t hb_font_get_glyph_h_origin (hb_font_t *font, hb_codepoint_t glyph, hb_position_t *x, hb_position_t *y);
hb_bool_t hb_font_get_glyph_v_origin (hb_font_t *font, hb_codepoint_t glyph, hb_position_t *x, hb_position_t *y);
hb_position_t hb_font_get_glyph_h_kerning (hb_font_t *font, hb_codepoint_t left_glyph, hb_codepoint_t right_glyph);
HB_DEPRECATED hb_position_t hb_font_get_glyph_v_kerning (hb_font_t *font, hb_codepoint_t top_glyph, hb_codepoint_t bottom_glyph);
hb_bool_t hb_font_get_glyph_extents (hb_font_t *font, hb_codepoint_t glyph, hb_glyph_extents_t *extents);
hb_bool_t hb_font_get_glyph_contour_point (hb_font_t *font, hb_codepoint_t glyph, unsigned int point_index, hb_position_t *x, hb_position_t *y);
hb_bool_t hb_font_get_glyph_name (hb_font_t *font, hb_codepoint_t glyph, char *name, unsigned int size);
hb_bool_t hb_font_get_glyph_from_name (hb_font_t *font, const char *name, int len, hb_codepoint_t *glyph);
void hb_font_get_extents_for_direction (hb_font_t *font, hb_direction_t direction, hb_font_extents_t *extents);
void hb_font_get_glyph_advance_for_direction (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
void hb_font_get_glyph_origin_for_direction (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
void hb_font_add_glyph_origin_for_direction (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
void hb_font_subtract_glyph_origin_for_direction (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
void hb_font_get_glyph_kerning_for_direction (hb_font_t *font, hb_codepoint_t first_glyph, hb_codepoint_t second_glyph, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
hb_bool_t hb_font_get_glyph_extents_for_origin (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, hb_glyph_extents_t *extents);
hb_bool_t hb_font_get_glyph_contour_point_for_origin (hb_font_t *font, hb_codepoint_t glyph, unsigned int point_index, hb_direction_t direction, hb_position_t *x, hb_position_t *y);
void hb_font_glyph_to_string (hb_font_t *font, hb_codepoint_t glyph, char *s, unsigned int size);
hb_bool_t hb_font_glyph_from_string (hb_font_t *font, const char *s, int len, hb_codepoint_t *glyph);
hb_font_t *hb_font_create (hb_face_t *face);
hb_font_t *hb_font_create_sub_font (hb_font_t *parent);
hb_font_t *hb_font_get_empty (void);
hb_font_t *hb_font_reference (hb_font_t *font);
void hb_font_destroy (hb_font_t *font);
hb_bool_t hb_font_set_user_data (hb_font_t *font, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_font_get_user_data (hb_font_t *font, hb_user_data_key_t *key);
void hb_font_make_immutable (hb_font_t *font);
hb_bool_t hb_font_is_immutable (hb_font_t *font);
void hb_font_set_parent (hb_font_t *font, hb_font_t *parent);
hb_font_t *hb_font_get_parent (hb_font_t *font);
void hb_font_set_face (hb_font_t *font, hb_face_t *face);
hb_face_t *hb_font_get_face (hb_font_t *font);
void hb_font_set_funcs (hb_font_t *font, hb_font_funcs_t *klass, void *font_data, hb_destroy_func_t destroy);
void hb_font_set_funcs_data (hb_font_t *font, void *font_data, hb_destroy_func_t destroy);
void hb_font_set_scale (hb_font_t *font, int x_scale, int y_scale);
void hb_font_get_scale (hb_font_t *font, int *x_scale, int *y_scale);
void hb_font_set_ppem (hb_font_t *font, unsigned int x_ppem, unsigned int y_ppem);
void hb_font_get_ppem (hb_font_t *font, unsigned int *x_ppem, unsigned int *y_ppem);
void hb_font_set_variations (hb_font_t *font, const hb_variation_t *variations, unsigned int variations_length);
void hb_font_set_var_coords_design (hb_font_t *font, const float *coords, unsigned int coords_length);
void hb_font_set_var_coords_normalized (hb_font_t *font, const int *coords, unsigned int coords_length);
const int *hb_font_get_var_coords_normalized (hb_font_t *font, unsigned int *length);
void hb_font_set_ptem (hb_font_t *font, float ptem);
float hb_font_get_ptem (hb_font_t *font);

hb_set_t *hb_set_create (void);
hb_set_t *hb_set_get_empty (void);
hb_set_t *hb_set_reference (hb_set_t *set);
void hb_set_destroy (hb_set_t *set);
hb_bool_t hb_set_set_user_data (hb_set_t *set, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_set_get_user_data (hb_set_t *set, hb_user_data_key_t *key);
hb_bool_t hb_set_allocation_successful (const hb_set_t *set);
void hb_set_clear (hb_set_t *set);
hb_bool_t hb_set_is_empty (const hb_set_t *set);
hb_bool_t hb_set_has (const hb_set_t *set, hb_codepoint_t codepoint);
void hb_set_add (hb_set_t *set, hb_codepoint_t codepoint);
void hb_set_add_range (hb_set_t *set, hb_codepoint_t first, hb_codepoint_t last);
void hb_set_del (hb_set_t *set, hb_codepoint_t codepoint);
void hb_set_del_range (hb_set_t *set, hb_codepoint_t first, hb_codepoint_t last);
hb_bool_t hb_set_is_equal (const hb_set_t *set, const hb_set_t *other);
void hb_set_set (hb_set_t *set, const hb_set_t *other);
void hb_set_union (hb_set_t *set, const hb_set_t *other);
void hb_set_intersect (hb_set_t *set, const hb_set_t *other);
void hb_set_subtract (hb_set_t *set, const hb_set_t *other);
void hb_set_symmetric_difference (hb_set_t *set, const hb_set_t *other);
void hb_set_invert (hb_set_t *set);
unsigned int hb_set_get_population (const hb_set_t *set);
hb_codepoint_t hb_set_get_min (const hb_set_t *set);
hb_codepoint_t hb_set_get_max (const hb_set_t *set);
hb_bool_t hb_set_next (const hb_set_t *set, hb_codepoint_t *codepoint);
hb_bool_t hb_set_next_range (const hb_set_t *set, hb_codepoint_t *first, hb_codepoint_t *last);
hb_bool_t hb_set_previous (const hb_set_t *set, hb_codepoint_t *codepoint);
hb_bool_t hb_set_previous_range (const hb_set_t *set, hb_codepoint_t *first, hb_codepoint_t *last);

hb_shape_plan_t *hb_shape_plan_create (hb_face_t *face, const hb_segment_properties_t *props, const hb_feature_t *user_features, unsigned int num_user_features, const char * const *shaper_list);
hb_shape_plan_t *hb_shape_plan_create_cached (hb_face_t *face, const hb_segment_properties_t *props, const hb_feature_t *user_features, unsigned int num_user_features, const char * const *shaper_list);
hb_shape_plan_t *hb_shape_plan_create2 (hb_face_t *face, const hb_segment_properties_t *props, const hb_feature_t *user_features, unsigned int num_user_features, const int *coords, unsigned int num_coords, const char * const *shaper_list);
hb_shape_plan_t *hb_shape_plan_create_cached2 (hb_face_t *face, const hb_segment_properties_t *props, const hb_feature_t *user_features, unsigned int num_user_features, const int *coords, unsigned int num_coords, const char * const *shaper_list);
hb_shape_plan_t *hb_shape_plan_get_empty (void);
hb_shape_plan_t *hb_shape_plan_reference (hb_shape_plan_t *shape_plan);
void hb_shape_plan_destroy (hb_shape_plan_t *shape_plan);
hb_bool_t hb_shape_plan_set_user_data (hb_shape_plan_t *shape_plan, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_shape_plan_get_user_data (hb_shape_plan_t *shape_plan, hb_user_data_key_t *key);
hb_bool_t hb_shape_plan_execute (hb_shape_plan_t *shape_plan, hb_font_t *font, hb_buffer_t *buffer, const hb_feature_t *features, unsigned int num_features);
const char *hb_shape_plan_get_shaper (hb_shape_plan_t *shape_plan);

void hb_shape (hb_font_t *font, hb_buffer_t *buffer, const hb_feature_t *features, unsigned int num_features);
hb_bool_t hb_shape_full (hb_font_t *font, hb_buffer_t *buffer, const hb_feature_t *features, unsigned int num_features, const char * const *shaper_list);
const char **hb_shape_list_shapers (void);

hb_unicode_funcs_t *hb_unicode_funcs_get_default_REF (void);
hb_unicode_funcs_t *hb_unicode_funcs_create (hb_unicode_funcs_t *parent);
hb_unicode_funcs_t *hb_unicode_funcs_get_empty (void);
hb_unicode_funcs_t *hb_unicode_funcs_reference (hb_unicode_funcs_t *ufuncs);
void hb_unicode_funcs_destroy (hb_unicode_funcs_t *ufuncs);
hb_bool_t hb_unicode_funcs_set_user_data (hb_unicode_funcs_t *ufuncs, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_unicode_funcs_get_user_data (hb_unicode_funcs_t *ufuncs, hb_user_data_key_t *key);
void hb_unicode_funcs_make_immutable (hb_unicode_funcs_t *ufuncs);
hb_bool_t hb_unicode_funcs_is_immutable (hb_unicode_funcs_t *ufuncs);
hb_unicode_funcs_t *hb_unicode_funcs_get_parent (hb_unicode_funcs_t *ufuncs);
void hb_unicode_funcs_set_combining_class_func (hb_unicode_funcs_t *ufuncs, hb_unicode_combining_class_func_t func, void *user_data, hb_destroy_func_t destroy);
HB_DEPRECATED void hb_unicode_funcs_set_eastasian_width_func (hb_unicode_funcs_t *ufuncs, hb_unicode_eastasian_width_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_unicode_funcs_set_general_category_func (hb_unicode_funcs_t *ufuncs, hb_unicode_general_category_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_unicode_funcs_set_mirroring_func (hb_unicode_funcs_t *ufuncs, hb_unicode_mirroring_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_unicode_funcs_set_script_func (hb_unicode_funcs_t *ufuncs, hb_unicode_script_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_unicode_funcs_set_compose_func (hb_unicode_funcs_t *ufuncs, hb_unicode_compose_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_unicode_funcs_set_decompose_func (hb_unicode_funcs_t *ufuncs, hb_unicode_decompose_func_t func, void *user_data, hb_destroy_func_t destroy);
HB_DEPRECATED void hb_unicode_funcs_set_decompose_compatibility_func (hb_unicode_funcs_t *ufuncs, hb_unicode_decompose_compatibility_func_t func, void *user_data, hb_destroy_func_t destroy);
hb_unicode_combining_class_t hb_unicode_combining_class (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode);
HB_DEPRECATED unsigned int hb_unicode_eastasian_width (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode);
hb_unicode_general_category_t hb_unicode_general_category (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode);
hb_codepoint_t hb_unicode_mirroring (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode);
hb_script_t hb_unicode_script (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode);
hb_bool_t hb_unicode_compose (hb_unicode_funcs_t *ufuncs, hb_codepoint_t a, hb_codepoint_t b, hb_codepoint_t *ab);
hb_bool_t hb_unicode_decompose (hb_unicode_funcs_t *ufuncs, hb_codepoint_t ab, hb_codepoint_t *a, hb_codepoint_t *b);
HB_DEPRECATED unsigned int hb_unicode_decompose_compatibility (hb_unicode_funcs_t *ufuncs, hb_codepoint_t u, hb_codepoint_t *decomposed);

void hb_version (unsigned int *major, unsigned int *minor, unsigned int *micro);
const char *hb_version_string (void);
hb_bool_t hb_version_atleast (unsigned int major, unsigned int minor, unsigned int micro);

hb_face_t *hb_ft_face_create (void *ft_face, hb_destroy_func_t destroy);
hb_face_t *hb_ft_face_create_cached (void *ft_face);
hb_face_t *hb_ft_face_create_referenced (void *ft_face);
hb_font_t *hb_ft_font_create (void *ft_face, hb_destroy_func_t destroy);
hb_font_t *hb_ft_font_create_referenced (void *ft_face);
void *hb_ft_font_get_face (hb_font_t *font);
void hb_ft_font_set_load_flags (hb_font_t *font, int load_flags);
int hb_ft_font_get_load_flags (hb_font_t *font);
void hb_ft_font_set_funcs (hb_font_t *font);
void hb_ft_font_changed (hb_font_t *font);

void hb_ot_font_set_funcs (hb_font_t *font);
hb_bool_t hb_ot_layout_has_glyph_classes (hb_face_t *face);
hb_ot_layout_glyph_class_t hb_ot_layout_get_glyph_class (hb_face_t *face, hb_codepoint_t glyph);
void hb_ot_layout_get_glyphs_in_class (hb_face_t *face, hb_ot_layout_glyph_class_t klass, hb_set_t *glyphs);
unsigned int hb_ot_layout_get_attach_points (hb_face_t *face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int *point_count, unsigned int *point_array);
unsigned int hb_ot_layout_get_ligature_carets (hb_font_t *font, hb_direction_t direction, hb_codepoint_t glyph, unsigned int start_offset, unsigned int *caret_count, hb_position_t *caret_array);
unsigned int hb_ot_layout_table_get_script_tags (hb_face_t *face, hb_tag_t table_tag, unsigned int start_offset, unsigned int *script_count, hb_tag_t *script_tags);
hb_bool_t hb_ot_layout_table_find_script (hb_face_t *face, hb_tag_t table_tag, hb_tag_t script_tag, unsigned int *script_index);
HB_DEPRECATED_FOR (hb_ot_layout_table_select_script) hb_bool_t hb_ot_layout_table_choose_script (hb_face_t *face, hb_tag_t table_tag, const hb_tag_t *script_tags, unsigned int *script_index, hb_tag_t *chosen_script);
unsigned int hb_ot_layout_table_get_feature_tags (hb_face_t *face, hb_tag_t table_tag, unsigned int start_offset, unsigned int *feature_count, hb_tag_t *feature_tags);
unsigned int hb_ot_layout_script_get_language_tags (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int start_offset, unsigned int *language_count, hb_tag_t *language_tags);
HB_DEPRECATED_FOR (hb_ot_layout_script_select_language) hb_bool_t hb_ot_layout_script_find_language (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, hb_tag_t language_tag, unsigned int *language_index);
hb_bool_t hb_ot_layout_language_get_required_feature_index (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int *feature_index);
hb_bool_t hb_ot_layout_language_get_required_feature (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int *feature_index, hb_tag_t *feature_tag);
unsigned int hb_ot_layout_language_get_feature_indexes (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int *feature_count, unsigned int *feature_indexes);
unsigned int hb_ot_layout_language_get_feature_tags (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, unsigned int start_offset, unsigned int *feature_count, hb_tag_t *feature_tags);
hb_bool_t hb_ot_layout_language_find_feature (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_index, hb_tag_t feature_tag, unsigned int *feature_index);
unsigned int hb_ot_layout_feature_get_lookups (hb_face_t *face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int *lookup_count, unsigned int *lookup_indexes);
unsigned int hb_ot_layout_table_get_lookup_count (hb_face_t *face, hb_tag_t table_tag);
void hb_ot_layout_collect_lookups (hb_face_t *face, hb_tag_t table_tag, const hb_tag_t *scripts, const hb_tag_t *languages, const hb_tag_t *features, hb_set_t *lookup_indexes);
void hb_ot_layout_lookup_collect_glyphs (hb_face_t *face, hb_tag_t table_tag, unsigned int lookup_index, hb_set_t *glyphs_before, hb_set_t *glyphs_input, hb_set_t *glyphs_after, hb_set_t *glyphs_output);
hb_bool_t hb_ot_layout_table_find_feature_variations (hb_face_t *face, hb_tag_t table_tag, const int *coords, unsigned int num_coords, unsigned int *variations_index);
unsigned int hb_ot_layout_feature_with_variations_get_lookups (hb_face_t *face, hb_tag_t table_tag, unsigned int feature_index, unsigned int variations_index, unsigned int start_offset, unsigned int *lookup_count, unsigned int *lookup_indexes);
hb_bool_t hb_ot_layout_has_substitution (hb_face_t *face);
hb_bool_t hb_ot_layout_lookup_would_substitute (hb_face_t *face, unsigned int lookup_index, const hb_codepoint_t *glyphs, unsigned int glyphs_length, hb_bool_t zero_context);
void hb_ot_layout_lookup_substitute_closure (hb_face_t *face, unsigned int lookup_index, hb_set_t *glyphs);
hb_bool_t hb_ot_layout_has_positioning (hb_face_t *face);
hb_bool_t hb_ot_layout_get_size_params (hb_face_t *face, unsigned int *design_size, unsigned int *subfamily_id, unsigned int *subfamily_name_id, unsigned int *range_start, unsigned int *range_end);
hb_bool_t hb_ot_math_has_data (hb_face_t *face);
hb_position_t hb_ot_math_get_constant (hb_font_t *font, hb_ot_math_constant_t constant);
hb_position_t hb_ot_math_get_glyph_italics_correction (hb_font_t *font, hb_codepoint_t glyph);
hb_position_t hb_ot_math_get_glyph_top_accent_attachment (hb_font_t *font, hb_codepoint_t glyph);
hb_bool_t hb_ot_math_is_glyph_extended_shape (hb_face_t *face, hb_codepoint_t glyph);
hb_position_t hb_ot_math_get_glyph_kerning (hb_font_t *font, hb_codepoint_t glyph, hb_ot_math_kern_t kern, hb_position_t correction_height);
unsigned int hb_ot_math_get_glyph_variants (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int *variants_count, hb_ot_math_glyph_variant_t *variants);
hb_position_t hb_ot_math_get_min_connector_overlap (hb_font_t *font, hb_direction_t direction);
unsigned int hb_ot_math_get_glyph_assembly (hb_font_t *font, hb_codepoint_t glyph, hb_direction_t direction, unsigned int start_offset, unsigned int *parts_count, hb_ot_math_glyph_part_t *parts, hb_position_t *italics_correction);
void hb_ot_shape_glyphs_closure (hb_font_t *font, hb_buffer_t *buffer, const hb_feature_t *features, unsigned int num_features, hb_set_t *glyphs);
void hb_ot_shape_plan_collect_lookups (hb_shape_plan_t *shape_plan, hb_tag_t table_tag, hb_set_t *lookup_indexes);
HB_DEPRECATED_FOR (hb_ot_tags_from_script_and_language) void hb_ot_tags_from_script (hb_script_t script, hb_tag_t *script_tag_1, hb_tag_t *script_tag_2);
hb_script_t hb_ot_tag_to_script (hb_tag_t tag);
HB_DEPRECATED_FOR (hb_ot_tags_from_script_and_language) hb_tag_t hb_ot_tag_from_language (hb_language_t language);
hb_language_t hb_ot_tag_to_language (hb_tag_t tag);
hb_bool_t hb_ot_var_has_data (hb_face_t *face);
unsigned int hb_ot_var_get_axis_count (hb_face_t *face);
HB_DEPRECATED_FOR (hb_ot_var_get_axis_infos) unsigned int hb_ot_var_get_axes (hb_face_t *face, unsigned int start_offset, unsigned int *axes_count, hb_ot_var_axis_t *axes_array);
HB_DEPRECATED_FOR (hb_ot_var_find_axis_info) hb_bool_t hb_ot_var_find_axis (hb_face_t *face, hb_tag_t axis_tag, unsigned int *axis_index, hb_ot_var_axis_t *axis_info);
void hb_ot_var_normalize_variations (hb_face_t *face, const hb_variation_t *variations, unsigned int variations_length, int *coords, unsigned int coords_length);
void hb_ot_var_normalize_coords (hb_face_t *face, unsigned int coords_length, const float *design_coords, int *normalized_coords);

/* 1.7.7 */

hb_blob_t *hb_blob_create_from_file (const char *file_name);
unsigned int hb_face_count (hb_blob_t *blob);
hb_map_t *hb_map_create (void);
hb_map_t *hb_map_get_empty (void);
hb_map_t *hb_map_reference (hb_map_t *map);
void hb_map_destroy (hb_map_t *map);
hb_bool_t hb_map_set_user_data (hb_map_t *map, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_map_get_user_data (hb_map_t *map, hb_user_data_key_t *key);
hb_bool_t hb_map_allocation_successful (const hb_map_t *map);
void hb_map_clear (hb_map_t *map);
hb_bool_t hb_map_is_empty (const hb_map_t *map);
unsigned int hb_map_get_population (const hb_map_t *map);
void hb_map_set (hb_map_t *map, hb_codepoint_t key, hb_codepoint_t value);
hb_codepoint_t hb_map_get (const hb_map_t *map, hb_codepoint_t key);
void hb_map_del (hb_map_t *map, hb_codepoint_t key);
hb_bool_t hb_map_has (const hb_map_t *map, hb_codepoint_t key);

/* 1.8.6 */

void hb_font_funcs_set_glyph_h_advances_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_h_advances_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_funcs_set_glyph_v_advances_func (hb_font_funcs_t *ffuncs, hb_font_get_glyph_v_advances_func_t func, void *user_data, hb_destroy_func_t destroy);
void hb_font_get_glyph_advances_for_direction (hb_font_t *font, hb_direction_t direction, unsigned int count, const hb_codepoint_t *first_glyph, unsigned glyph_stride, hb_position_t *first_advance, unsigned advance_stride);
void hb_font_get_glyph_h_advances (hb_font_t *font, unsigned int count, const hb_codepoint_t *first_glyph, unsigned glyph_stride, hb_position_t *first_advance, unsigned advance_stride);
void hb_font_get_glyph_v_advances (hb_font_t *font, unsigned int count, const hb_codepoint_t *first_glyph, unsigned glyph_stride, hb_position_t *first_advance, unsigned advance_stride);

/* 1.8.8 */

hb_unicode_funcs_t *hb_unicode_funcs_get_default (void);

/* 1.9.0 */

void hb_face_collect_unicodes (hb_face_t *face, hb_set_t *out);
void hb_face_collect_variation_selectors (hb_face_t *face, hb_set_t *out);
void hb_face_collect_variation_unicodes (hb_face_t *face, hb_codepoint_t variation_selector, hb_set_t *out);
hb_face_t *hb_face_builder_create (void);
hb_bool_t hb_face_builder_add_table (hb_face_t *face, hb_tag_t tag, hb_blob_t *blob);

/* 2.0.0 */

void hb_buffer_set_invisible_glyph (hb_buffer_t *buffer, hb_codepoint_t invisible);
hb_codepoint_t hb_buffer_get_invisible_glyph (hb_buffer_t *buffer);
void hb_font_funcs_set_nominal_glyphs_func (hb_font_funcs_t *ffuncs, hb_font_get_nominal_glyphs_func_t func, void *user_data, hb_destroy_func_t destroy);
hb_bool_t hb_ot_layout_table_select_script (hb_face_t *face, hb_tag_t table_tag, unsigned int script_count, const hb_tag_t *script_tags, unsigned int *script_index, hb_tag_t *chosen_script);
hb_bool_t hb_ot_layout_script_select_language (hb_face_t *face, hb_tag_t table_tag, unsigned int script_index, unsigned int language_count, const hb_tag_t *language_tags, unsigned int *language_index);
hb_bool_t hb_ot_layout_feature_get_name_ids (hb_face_t *face, hb_tag_t table_tag, unsigned int feature_index, hb_ot_name_id_t *label_id, hb_ot_name_id_t *tooltip_id, hb_ot_name_id_t *sample_id, unsigned int *num_named_parameters, hb_ot_name_id_t *first_param_id);
unsigned int hb_ot_layout_feature_get_characters (hb_face_t *face, hb_tag_t table_tag, unsigned int feature_index, unsigned int start_offset, unsigned int *char_count, hb_codepoint_t *characters);
void hb_ot_tags_from_script_and_language (hb_script_t script, hb_language_t language, unsigned int *script_count, hb_tag_t *script_tags, unsigned int *language_count, hb_tag_t *language_tags);
void hb_ot_tags_to_script_and_language (hb_tag_t script_tag, hb_tag_t language_tag, hb_script_t *script, hb_language_t *language);

/* 2.1.0 */

uint8_t hb_color_get_alpha (hb_color_t color);
uint8_t hb_color_get_red (hb_color_t color);
uint8_t hb_color_get_green (hb_color_t color);
uint8_t hb_color_get_blue (hb_color_t color);
hb_bool_t hb_ot_color_has_palettes (hb_face_t *face);
unsigned int hb_ot_color_palette_get_count (hb_face_t *face);
hb_ot_name_id_t hb_ot_color_palette_get_name_id (hb_face_t *face, unsigned int palette_index);
hb_ot_name_id_t hb_ot_color_palette_color_get_name_id (hb_face_t *face, unsigned int color_index);
hb_ot_color_palette_flags_t hb_ot_color_palette_get_flags (hb_face_t *face, unsigned int palette_index);
unsigned int hb_ot_color_palette_get_colors (hb_face_t *face, unsigned int palette_index, unsigned int start_offset, unsigned int *color_count, hb_color_t *colors);
hb_bool_t hb_ot_color_has_layers (hb_face_t *face);
unsigned int hb_ot_color_glyph_get_layers (hb_face_t *face, hb_codepoint_t glyph, unsigned int start_offset, unsigned int *layer_count, hb_ot_color_layer_t *layers);
hb_bool_t hb_ot_color_has_svg (hb_face_t *face);
hb_blob_t *hb_ot_color_glyph_reference_svg (hb_face_t *face, hb_codepoint_t glyph);
hb_bool_t hb_ot_color_has_png (hb_face_t *face);
hb_blob_t *hb_ot_color_glyph_reference_png (hb_font_t *font, hb_codepoint_t glyph);
const hb_ot_name_entry_t *hb_ot_name_list_names (hb_face_t *face, unsigned int *num_entries);
unsigned int hb_ot_name_get_utf8 (hb_face_t *face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int *text_size, char *text);
unsigned int hb_ot_name_get_utf16 (hb_face_t *face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int *text_size, uint16_t *text);
unsigned int hb_ot_name_get_utf32 (hb_face_t *face, hb_ot_name_id_t name_id, hb_language_t language, unsigned int *text_size, uint32_t *text);

/* 2.2.0 */

unsigned int hb_aat_layout_get_feature_types (hb_face_t *face, unsigned int start_offset, unsigned int *feature_count, hb_aat_layout_feature_type_t *features);
hb_ot_name_id_t hb_aat_layout_feature_type_get_name_id (hb_face_t *face, hb_aat_layout_feature_type_t feature_type);
unsigned int hb_aat_layout_feature_type_get_selector_infos (hb_face_t *face, hb_aat_layout_feature_type_t feature_type, unsigned int start_offset, unsigned int *selector_count, hb_aat_layout_feature_selector_info_t *selectors, unsigned int *default_index);
unsigned int hb_ot_var_get_axis_infos (hb_face_t *face, unsigned int start_offset, unsigned int *axes_count, hb_ot_var_axis_info_t *axes_array);
hb_bool_t hb_ot_var_find_axis_info (hb_face_t *face, hb_tag_t axis_tag, hb_ot_var_axis_info_t *axis_info);
unsigned int hb_ot_var_get_named_instance_count (hb_face_t *face);
hb_ot_name_id_t hb_ot_var_named_instance_get_subfamily_name_id (hb_face_t *face, unsigned int instance_index);
hb_ot_name_id_t hb_ot_var_named_instance_get_postscript_name_id (hb_face_t *face, unsigned int instance_index);
unsigned int hb_ot_var_named_instance_get_design_coords (hb_face_t *face, unsigned int instance_index, unsigned int *coords_length, float *coords);

/* 2.3.0 */

hb_bool_t hb_aat_layout_has_substitution (hb_face_t *face);
hb_bool_t hb_aat_layout_has_positioning (hb_face_t *face);
hb_bool_t hb_aat_layout_has_tracking (hb_face_t *face);

/* 2.6.0 */

void hb_font_set_var_named_instance (hb_font_t *font, unsigned instance_index);
hb_bool_t hb_ot_layout_get_baseline (hb_font_t *font, hb_ot_layout_baseline_tag_t baseline_tag, hb_direction_t direction, hb_tag_t script_tag, hb_tag_t language_tag, hb_position_t *coord);
unsigned int hb_ot_meta_get_entry_tags (hb_face_t *face, unsigned int start_offset, unsigned int *entries_count, hb_ot_meta_tag_t *entries);
hb_blob_t *hb_ot_meta_reference_entry (hb_face_t *face, hb_ot_meta_tag_t meta_tag);
hb_bool_t hb_ot_metrics_get_position (hb_font_t *font, hb_ot_metrics_tag_t metrics_tag, hb_position_t *position);
float hb_ot_metrics_get_variation (hb_font_t *font, hb_ot_metrics_tag_t metrics_tag);
hb_position_t hb_ot_metrics_get_x_variation (hb_font_t *font, hb_ot_metrics_tag_t metrics_tag);
hb_position_t hb_ot_metrics_get_y_variation (hb_font_t *font, hb_ot_metrics_tag_t metrics_tag);

/* 2.6.3 */

unsigned int hb_font_get_nominal_glyphs (hb_font_t *font, unsigned int count, const hb_codepoint_t *first_unicode, unsigned int unicode_stride, hb_codepoint_t *first_glyph, unsigned int glyph_stride);

/* 2.6.5 */

void *hb_ft_font_lock_face (hb_font_t *font);
void hb_ft_font_unlock_face (hb_font_t *font);

/* 2.6.8 */

unsigned hb_ot_layout_lookup_get_glyph_alternates (hb_face_t *face, unsigned lookup_index, hb_codepoint_t glyph, unsigned start_offset, unsigned *alternate_count, hb_codepoint_t *alternate_glyphs);

/* 2.7.3 */

hb_bool_t hb_buffer_has_positions (hb_buffer_t *buffer);
unsigned int hb_buffer_serialize (hb_buffer_t *buffer, unsigned int start, unsigned int end, char *buf, unsigned int buf_size, unsigned int *buf_consumed, hb_font_t *font, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags);
unsigned int hb_buffer_serialize_unicode (hb_buffer_t *buffer, unsigned int start, unsigned int end, char *buf, unsigned int buf_size, unsigned int *buf_consumed, hb_buffer_serialize_format_t format, hb_buffer_serialize_flags_t flags);
hb_bool_t hb_buffer_deserialize_unicode (hb_buffer_t *buffer, const char *buf, int buf_len, const char **end_ptr, hb_buffer_serialize_format_t format);

/* 2.8.2 */

hb_blob_t *hb_blob_create_or_fail (const char *data, unsigned int length, hb_memory_mode_t mode, void *user_data, hb_destroy_func_t destroy);
hb_blob_t *hb_blob_create_from_file_or_fail (const char *file_name);
hb_set_t *hb_set_copy (const hb_set_t *set);

/* 3.0.0 */

float hb_style_get_value (hb_font_t *font, hb_style_tag_t style_tag);
hb_subset_input_t *hb_subset_input_create_or_fail (void);
hb_subset_input_t *hb_subset_input_reference (hb_subset_input_t *input);
void hb_subset_input_destroy (hb_subset_input_t *input);
hb_bool_t hb_subset_input_set_user_data (hb_subset_input_t *input, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
void *hb_subset_input_get_user_data (const hb_subset_input_t *input, hb_user_data_key_t *key);
hb_set_t *hb_subset_input_unicode_set (hb_subset_input_t *input);
hb_set_t *hb_subset_input_glyph_set (hb_subset_input_t *input);
hb_set_t *hb_subset_input_set (hb_subset_input_t *input, hb_subset_sets_t set_type);
hb_subset_flags_t hb_subset_input_get_flags (hb_subset_input_t *input);
void hb_subset_input_set_flags (hb_subset_input_t *input, unsigned value);
hb_face_t *hb_subset_or_fail (hb_face_t *source, const hb_subset_input_t *input);

/* 3.1.1 */

void hb_buffer_set_not_found_glyph (hb_buffer_t *buffer, hb_codepoint_t not_found);
hb_codepoint_t hb_buffer_get_not_found_glyph (hb_buffer_t *buffer);

/* 3.3.0 */

void hb_segment_properties_overlay (hb_segment_properties_t *p, const hb_segment_properties_t *src);
hb_buffer_t *hb_buffer_create_similar (const hb_buffer_t *src);
void hb_font_set_synthetic_slant (hb_font_t *font, float slant);
float hb_font_get_synthetic_slant (hb_font_t *font);
const float *hb_font_get_var_coords_design (hb_font_t *font, unsigned int *length);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_HARFBUZZ_PROTOS_H */
