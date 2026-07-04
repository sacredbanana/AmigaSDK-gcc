#ifndef TGL_GLSTD_H
#define TGL_GLSTD_H

#ifdef __cplusplus
extern "C" {
#endif

#define GL_ARB_color_buffer_float 1
#define GL_ARB_depth_buffer_float 1
#define GL_ARB_depth_texture 1
#define GL_ARB_draw_buffers 1
#define GL_ARB_fragment_program 1
#define GL_ARB_fragment_program_shadow 1
#define GL_ARB_fragment_shader 1
#define GL_ARB_framebuffer_object 1
#define GL_ARB_half_float_pixel 1
#define GL_ARB_imaging 1
#define GL_ARB_matrix_palette 1
#define GL_ARB_multisample 1
#define GL_ARB_multitexture 1
#define GL_ARB_occlusion_query 1
#define GL_ARB_pixel_buffer_object 1
#define GL_ARB_point_parameters 1
#define GL_ARB_point_sprite 1
#define GL_ARB_shader_objects 1
#define GL_ARB_shading_language_100 1
#define GL_ARB_shadow 1
#define GL_ARB_shadow_ambient 1
#define GL_ARB_texture_border_clamp 1
#define GL_ARB_texture_compression 1
#define GL_ARB_texture_cube_map 1
#define GL_ARB_texture_env_add 1
#define GL_ARB_texture_env_combine 1
#define GL_ARB_texture_env_crossbar 1
#define GL_ARB_texture_env_dot3 1
#define GL_ARB_texture_float 1
#define GL_ARB_texture_mirrored_repeat 1
#define GL_ARB_texture_non_power_of_two 1
#define GL_ARB_texture_rectangle 1
#define GL_ARB_texture_rg 1
#define GL_ARB_texture_rgb10_a2ui 1
#define GL_ARB_transpose_matrix 1
#define GL_ARB_vertex_blend 1
#define GL_ARB_vertex_buffer_object 1
#define GL_ARB_vertex_program 1
#define GL_ARB_vertex_shader 1
#define GL_ARB_window_pos 1
#define GL_ATI_fragment_shader 1
#define GL_ATI_separate_stencil 1
#define GL_EXT_abgr 1
#define GL_EXT_bgra 1
#define GL_EXT_blend_color 1
#define GL_EXT_blend_equation_separate 1
#define GL_EXT_blend_func_separate 1
#define GL_EXT_blend_logic_op 1
#define GL_EXT_blend_minmax 1
#define GL_EXT_blend_subtract 1
#define GL_EXT_color_subtable 1
#define GL_EXT_color_table 1
#define GL_EXT_compiled_vertex_array 1
#define GL_EXT_convolution 1
#define GL_EXT_draw_range_elements 1
#define GL_EXT_fog_coord 1
#define GL_EXT_framebuffer_object 1
#define GL_EXT_histogram 1
#define GL_EXT_multi_draw_arrays 1
#define GL_EXT_packed_float 1
#define GL_EXT_packed_pixels 1
#define GL_EXT_paletted_texture 1
#define GL_EXT_point_parameters 1
#define GL_EXT_rescale_normal 1
#define GL_EXT_secondary_color 1
#define GL_EXT_separate_specular_color 1
#define GL_EXT_shadow_funcs 1
#define GL_EXT_shared_texture_palette 1
#define GL_EXT_stencil_two_side 1
#define GL_EXT_stencil_wrap 1
#define GL_EXT_texture3D 1
#define GL_EXT_texture_compression_s3tc 1
#define GL_EXT_texture_cube_map 1
#define GL_EXT_texture_env_add 1
#define GL_EXT_texture_env_combine 1
#define GL_EXT_texture_env_dot3 1
#define GL_EXT_texture_filter_anisotropic 1
#define GL_EXT_texture_integer 1
#define GL_EXT_texture_lod 1
#define GL_EXT_texture_lod_bias 1
#define GL_EXT_texture_sRGB 1
#define GL_EXT_texture_shared_exponent 1
#define GL_EXT_texture_snorm 1
#define GL_HP_convolution_border_modes 1
#define GL_MESA_ycbcr_texture 1
#define GL_NV_blend_square 1
#define GL_NV_texgen_reflection 1
#define GL_S3_s3tc 1
#define GL_SGIS_generate_mipmap 1
#define GL_SGIS_multitexture 1
#define GL_SGIS_texture_edge_clamp 1
#define GL_SGIS_texture_lod 1
#define GL_SGI_color_matrix 1
#define GL_SGI_color_table 1
#define GL_SUN_multi_draw_arrays 1

#define GL_2D                                                             0x0600
#define GL_2X_BIT_ATI                                                     0x00000001
#define GL_2_BYTES                                                        0x1407
#define GL_3D                                                             0x0601
#define GL_3D_COLOR                                                       0x0602
#define GL_3D_COLOR_TEXTURE                                               0x0603
#define GL_3_BYTES                                                        0x1408
#define GL_4D_COLOR_TEXTURE                                               0x0604
#define GL_4X_BIT_ATI                                                     0x00000002
#define GL_4_BYTES                                                        0x1409
#define GL_8X_BIT_ATI                                                     0x00000004
#define GL_ABGR_EXT                                                       0x8000
#define GL_ACCUM                                                          0x0100
#define GL_ACCUM_ALPHA_BITS                                               0x0D5B
#define GL_ACCUM_BLUE_BITS                                                0x0D5A
#define GL_ACCUM_BUFFER_BIT                                               0x00000200
#define GL_ACCUM_CLEAR_VALUE                                              0x0B80
#define GL_ACCUM_GREEN_BITS                                               0x0D59
#define GL_ACCUM_RED_BITS                                                 0x0D58
#define GL_ACTIVE_ATTRIBUTES                                              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                                    0x8B8A
#define GL_ACTIVE_STENCIL_FACE_EXT                                        0x8911
#define GL_ACTIVE_TEXTURE                                                 0x84E0
#define GL_ACTIVE_TEXTURE_ARB                                             0x84E0
#define GL_ACTIVE_UNIFORMS                                                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                                      0x8B87
#define GL_ACTIVE_VERTEX_UNITS_ARB                                        0x86A5
#define GL_ADD                                                            0x0104
#define GL_ADD_ATI                                                        0x8963
#define GL_ADD_SIGNED                                                     0x8574
#define GL_ADD_SIGNED_ARB                                                 0x8574
#define GL_ADD_SIGNED_EXT                                                 0x8574
#define GL_ALIASED_LINE_WIDTH_RANGE                                       0x846E
#define GL_ALIASED_POINT_SIZE_RANGE                                       0x846D
#define GL_ALL_ATTRIB_BITS                                                0xFFFFFFFF
#define GL_ALPHA                                                          0x1906
#define GL_ALPHA12                                                        0x803D
#define GL_ALPHA16                                                        0x803E
#define GL_ALPHA16F_ARB                                                   0x881C
#define GL_ALPHA16I_EXT                                                   0x8D8A
#define GL_ALPHA16UI_EXT                                                  0x8D78
#define GL_ALPHA16_SNORM                                                  0x9018
#define GL_ALPHA32F_ARB                                                   0x8816
#define GL_ALPHA32I_EXT                                                   0x8D84
#define GL_ALPHA32UI_EXT                                                  0x8D72
#define GL_ALPHA4                                                         0x803B
#define GL_ALPHA8                                                         0x803C
#define GL_ALPHA8I_EXT                                                    0x8D90
#define GL_ALPHA8UI_EXT                                                   0x8D7E
#define GL_ALPHA8_SNORM                                                   0x9014
#define GL_ALPHA_BIAS                                                     0x0D1D
#define GL_ALPHA_BITS                                                     0x0D55
#define GL_ALPHA_INTEGER_EXT                                              0x8D97
#define GL_ALPHA_SCALE                                                    0x0D1C
#define GL_ALPHA_SNORM                                                    0x9010
#define GL_ALPHA_TEST                                                     0x0BC0
#define GL_ALPHA_TEST_FUNC                                                0x0BC1
#define GL_ALPHA_TEST_REF                                                 0x0BC2
#define GL_ALWAYS                                                         0x0207
#define GL_AMBIENT                                                        0x1200
#define GL_AMBIENT_AND_DIFFUSE                                            0x1602
#define GL_AND                                                            0x1501
#define GL_AND_INVERTED                                                   0x1504
#define GL_AND_REVERSE                                                    0x1502
#define GL_ARRAY_BUFFER                                                   0x8892
#define GL_ARRAY_BUFFER_ARB                                               0x8892
#define GL_ARRAY_BUFFER_BINDING                                           0x8894
#define GL_ARRAY_BUFFER_BINDING_ARB                                       0x8894
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT                                   0x81A9
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT                                   0x81A8
#define GL_ATTACHED_SHADERS                                               0x8B85
#define GL_ATTRIB_STACK_DEPTH                                             0x0BB0
#define GL_AUTO_NORMAL                                                    0x0D80
#define GL_AUX0                                                           0x0409
#define GL_AUX1                                                           0x040A
#define GL_AUX2                                                           0x040B
#define GL_AUX3                                                           0x040C
#define GL_AUX_BUFFERS                                                    0x0C00
#define GL_BACK                                                           0x0405
#define GL_BACK_LEFT                                                      0x0402
#define GL_BACK_RIGHT                                                     0x0403
#define GL_BGR                                                            0x80E0
#define GL_BGRA                                                           0x80E1
#define GL_BGRA_EXT                                                       0x80E1
#define GL_BGRA_INTEGER_EXT                                               0x8D9B
#define GL_BGR_EXT                                                        0x80E0
#define GL_BGR_INTEGER_EXT                                                0x8D9A
#define GL_BIAS_BIT_ATI                                                   0x00000008
#define GL_BITMAP                                                         0x1A00
#define GL_BITMAP_TOKEN                                                   0x0704
#define GL_BLEND                                                          0x0BE2
#define GL_BLEND_COLOR                                                    0x8005
#define GL_BLEND_COLOR_EXT                                                0x8005
#define GL_BLEND_DST                                                      0x0BE0
#define GL_BLEND_DST_ALPHA                                                0x80CA
#define GL_BLEND_DST_ALPHA_EXT                                            0x80CA
#define GL_BLEND_DST_RGB                                                  0x80C8
#define GL_BLEND_DST_RGB_EXT                                              0x80C8
#define GL_BLEND_EQUATION                                                 0x8009
#define GL_BLEND_EQUATION_ALPHA                                           0x883D
#define GL_BLEND_EQUATION_ALPHA_EXT                                       0x883D
#define GL_BLEND_EQUATION_EXT                                             0x8009
#define GL_BLEND_EQUATION_RGB                                             0x8009
#define GL_BLEND_EQUATION_RGB_EXT                                         0x8009
#define GL_BLEND_SRC                                                      0x0BE1
#define GL_BLEND_SRC_ALPHA                                                0x80CB
#define GL_BLEND_SRC_ALPHA_EXT                                            0x80CB
#define GL_BLEND_SRC_RGB                                                  0x80C9
#define GL_BLEND_SRC_RGB_EXT                                              0x80C9
#define GL_BLUE                                                           0x1905
#define GL_BLUE_BIAS                                                      0x0D1B
#define GL_BLUE_BITS                                                      0x0D54
#define GL_BLUE_BIT_ATI                                                   0x00000004
#define GL_BLUE_INTEGER_EXT                                               0x8D96
#define GL_BLUE_SCALE                                                     0x0D1A
#define GL_BOOL                                                           0x8B56
#define GL_BOOL_ARB                                                       0x8B56
#define GL_BOOL_VEC2                                                      0x8B57
#define GL_BOOL_VEC2_ARB                                                  0x8B57
#define GL_BOOL_VEC3                                                      0x8B58
#define GL_BOOL_VEC3_ARB                                                  0x8B58
#define GL_BOOL_VEC4                                                      0x8B59
#define GL_BOOL_VEC4_ARB                                                  0x8B59
#define GL_BUFFER_ACCESS                                                  0x88BB
#define GL_BUFFER_ACCESS_ARB                                              0x88BB
#define GL_BUFFER_MAPPED                                                  0x88BC
#define GL_BUFFER_MAPPED_ARB                                              0x88BC
#define GL_BUFFER_MAP_POINTER                                             0x88BD
#define GL_BUFFER_MAP_POINTER_ARB                                         0x88BD
#define GL_BUFFER_SIZE                                                    0x8764
#define GL_BUFFER_SIZE_ARB                                                0x8764
#define GL_BUFFER_USAGE                                                   0x8765
#define GL_BUFFER_USAGE_ARB                                               0x8765
#define GL_BYTE                                                           0x1400
#define GL_C3F_V3F                                                        0x2A24
#define GL_C4F_N3F_V3F                                                    0x2A26
#define GL_C4UB_V2F                                                       0x2A22
#define GL_C4UB_V3F                                                       0x2A23
#define GL_CCW                                                            0x0901
#define GL_CLAMP                                                          0x2900
#define GL_CLAMP_FRAGMENT_COLOR_ARB                                       0x891B
#define GL_CLAMP_READ_COLOR_ARB                                           0x891C
#define GL_CLAMP_TO_BORDER                                                0x812D
#define GL_CLAMP_TO_BORDER_ARB                                            0x812D
#define GL_CLAMP_TO_EDGE                                                  0x812F
#define GL_CLAMP_TO_EDGE_SGIS                                             0x812F
#define GL_CLAMP_VERTEX_COLOR_ARB                                         0x891A
#define GL_CLEAR                                                          0x1500
#define GL_CLIENT_ACTIVE_TEXTURE                                          0x84E1
#define GL_CLIENT_ACTIVE_TEXTURE_ARB                                      0x84E1
#define GL_CLIENT_ALL_ATTRIB_BITS                                         0xFFFFFFFF
#define GL_CLIENT_ATTRIB_STACK_DEPTH                                      0x0BB1
#define GL_CLIENT_PIXEL_STORE_BIT                                         0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT                                        0x00000002
#define GL_CLIP_PLANE0                                                    0x3000
#define GL_CLIP_PLANE1                                                    0x3001
#define GL_CLIP_PLANE2                                                    0x3002
#define GL_CLIP_PLANE3                                                    0x3003
#define GL_CLIP_PLANE4                                                    0x3004
#define GL_CLIP_PLANE5                                                    0x3005
#define GL_CND0_ATI                                                       0x896B
#define GL_CND_ATI                                                        0x896A
#define GL_COEFF                                                          0x0A00
#define GL_COLOR                                                          0x1800
#define GL_COLOR_ALPHA_PAIRING_ATI                                        0x8975
#define GL_COLOR_ARRAY                                                    0x8076
#define GL_COLOR_ARRAY_BUFFER_BINDING                                     0x8898
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB                                 0x8898
#define GL_COLOR_ARRAY_POINTER                                            0x8090
#define GL_COLOR_ARRAY_SIZE                                               0x8081
#define GL_COLOR_ARRAY_STRIDE                                             0x8083
#define GL_COLOR_ARRAY_TYPE                                               0x8082
#define GL_COLOR_ATTACHMENT0                                              0x8CE0
#define GL_COLOR_ATTACHMENT0_EXT                                          0x8CE0
#define GL_COLOR_ATTACHMENT1                                              0x8CE1
#define GL_COLOR_ATTACHMENT10                                             0x8CEA
#define GL_COLOR_ATTACHMENT10_EXT                                         0x8CEA
#define GL_COLOR_ATTACHMENT11                                             0x8CEB
#define GL_COLOR_ATTACHMENT11_EXT                                         0x8CEB
#define GL_COLOR_ATTACHMENT12                                             0x8CEC
#define GL_COLOR_ATTACHMENT12_EXT                                         0x8CEC
#define GL_COLOR_ATTACHMENT13                                             0x8CED
#define GL_COLOR_ATTACHMENT13_EXT                                         0x8CED
#define GL_COLOR_ATTACHMENT14                                             0x8CEE
#define GL_COLOR_ATTACHMENT14_EXT                                         0x8CEE
#define GL_COLOR_ATTACHMENT15                                             0x8CEF
#define GL_COLOR_ATTACHMENT15_EXT                                         0x8CEF
#define GL_COLOR_ATTACHMENT1_EXT                                          0x8CE1
#define GL_COLOR_ATTACHMENT2                                              0x8CE2
#define GL_COLOR_ATTACHMENT2_EXT                                          0x8CE2
#define GL_COLOR_ATTACHMENT3                                              0x8CE3
#define GL_COLOR_ATTACHMENT3_EXT                                          0x8CE3
#define GL_COLOR_ATTACHMENT4                                              0x8CE4
#define GL_COLOR_ATTACHMENT4_EXT                                          0x8CE4
#define GL_COLOR_ATTACHMENT5                                              0x8CE5
#define GL_COLOR_ATTACHMENT5_EXT                                          0x8CE5
#define GL_COLOR_ATTACHMENT6                                              0x8CE6
#define GL_COLOR_ATTACHMENT6_EXT                                          0x8CE6
#define GL_COLOR_ATTACHMENT7                                              0x8CE7
#define GL_COLOR_ATTACHMENT7_EXT                                          0x8CE7
#define GL_COLOR_ATTACHMENT8                                              0x8CE8
#define GL_COLOR_ATTACHMENT8_EXT                                          0x8CE8
#define GL_COLOR_ATTACHMENT9                                              0x8CE9
#define GL_COLOR_ATTACHMENT9_EXT                                          0x8CE9
#define GL_COLOR_BUFFER_BIT                                               0x00004000
#define GL_COLOR_CLEAR_VALUE                                              0x0C22
#define GL_COLOR_INDEX                                                    0x1900
#define GL_COLOR_INDEX12_EXT                                              0x80E6
#define GL_COLOR_INDEX16_EXT                                              0x80E7
#define GL_COLOR_INDEX1_EXT                                               0x80E2
#define GL_COLOR_INDEX2_EXT                                               0x80E3
#define GL_COLOR_INDEX4_EXT                                               0x80E4
#define GL_COLOR_INDEX8_EXT                                               0x80E5
#define GL_COLOR_INDEXES                                                  0x1603
#define GL_COLOR_LOGIC_OP                                                 0x0BF2
#define GL_COLOR_MATERIAL                                                 0x0B57
#define GL_COLOR_MATERIAL_FACE                                            0x0B55
#define GL_COLOR_MATERIAL_PARAMETER                                       0x0B56
#define GL_COLOR_MATRIX                                                   0x80B1
#define GL_COLOR_MATRIX_SGI                                               0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH                                       0x80B2
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI                                   0x80B2
#define GL_COLOR_SUM                                                      0x8458
#define GL_COLOR_SUM_ARB                                                  0x8458
#define GL_COLOR_SUM_EXT                                                  0x8458
#define GL_COLOR_TABLE                                                    0x80D0
#define GL_COLOR_TABLE_ALPHA_SIZE                                         0x80DD
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI                                     0x80DD
#define GL_COLOR_TABLE_BIAS                                               0x80D7
#define GL_COLOR_TABLE_BIAS_SGI                                           0x80D7
#define GL_COLOR_TABLE_BLUE_SIZE                                          0x80DC
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                                      0x80DC
#define GL_COLOR_TABLE_FORMAT                                             0x80D8
#define GL_COLOR_TABLE_FORMAT_SGI                                         0x80D8
#define GL_COLOR_TABLE_GREEN_SIZE                                         0x80DB
#define GL_COLOR_TABLE_GREEN_SIZE_SGI                                     0x80DB
#define GL_COLOR_TABLE_INTENSITY_SIZE                                     0x80DF
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI                                 0x80DF
#define GL_COLOR_TABLE_LUMINANCE_SIZE                                     0x80DE
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI                                 0x80DE
#define GL_COLOR_TABLE_RED_SIZE                                           0x80DA
#define GL_COLOR_TABLE_RED_SIZE_SGI                                       0x80DA
#define GL_COLOR_TABLE_SCALE                                              0x80D6
#define GL_COLOR_TABLE_SCALE_SGI                                          0x80D6
#define GL_COLOR_TABLE_SGI                                                0x80D0
#define GL_COLOR_TABLE_WIDTH                                              0x80D9
#define GL_COLOR_TABLE_WIDTH_SGI                                          0x80D9
#define GL_COLOR_WRITEMASK                                                0x0C23
#define GL_COMBINE                                                        0x8570
#define GL_COMBINE_ALPHA                                                  0x8572
#define GL_COMBINE_ALPHA_ARB                                              0x8572
#define GL_COMBINE_ALPHA_EXT                                              0x8572
#define GL_COMBINE_ARB                                                    0x8570
#define GL_COMBINE_EXT                                                    0x8570
#define GL_COMBINE_RGB                                                    0x8571
#define GL_COMBINE_RGB_ARB                                                0x8571
#define GL_COMBINE_RGB_EXT                                                0x8571
#define GL_COMPARE_R_TO_TEXTURE                                           0x884E
#define GL_COMPARE_R_TO_TEXTURE_ARB                                       0x884E
#define GL_COMPILE                                                        0x1300
#define GL_COMPILE_AND_EXECUTE                                            0x1301
#define GL_COMPILE_STATUS                                                 0x8B81
#define GL_COMPRESSED_ALPHA                                               0x84E9
#define GL_COMPRESSED_ALPHA_ARB                                           0x84E9
#define GL_COMPRESSED_INTENSITY                                           0x84EC
#define GL_COMPRESSED_INTENSITY_ARB                                       0x84EC
#define GL_COMPRESSED_LUMINANCE                                           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA                                     0x84EB
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB                                 0x84EB
#define GL_COMPRESSED_LUMINANCE_ARB                                       0x84EA
#define GL_COMPRESSED_RGB                                                 0x84ED
#define GL_COMPRESSED_RGBA                                                0x84EE
#define GL_COMPRESSED_RGBA_ARB                                            0x84EE
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                                  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT                                  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT                                  0x83F3
#define GL_COMPRESSED_RGB_ARB                                             0x84ED
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                                   0x83F0
#define GL_COMPRESSED_SLUMINANCE                                          0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA                                    0x8C4B
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT                                0x8C4B
#define GL_COMPRESSED_SLUMINANCE_EXT                                      0x8C4A
#define GL_COMPRESSED_SRGB                                                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA                                          0x8C49
#define GL_COMPRESSED_SRGB_ALPHA_EXT                                      0x8C49
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT                            0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT                            0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT                            0x8C4F
#define GL_COMPRESSED_SRGB_EXT                                            0x8C48
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT                                  0x8C4C
#define GL_COMPRESSED_TEXTURE_FORMATS                                     0x86A3
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB                                 0x86A3
#define GL_COMP_BIT_ATI                                                   0x00000002
#define GL_CONSTANT                                                       0x8576
#define GL_CONSTANT_ALPHA                                                 0x8003
#define GL_CONSTANT_ALPHA_EXT                                             0x8003
#define GL_CONSTANT_ARB                                                   0x8576
#define GL_CONSTANT_ATTENUATION                                           0x1207
#define GL_CONSTANT_BORDER                                                0x8151
#define GL_CONSTANT_BORDER_HP                                             0x8151
#define GL_CONSTANT_COLOR                                                 0x8001
#define GL_CONSTANT_COLOR_EXT                                             0x8001
#define GL_CONSTANT_EXT                                                   0x8576
#define GL_CONVOLUTION_1D                                                 0x8010
#define GL_CONVOLUTION_1D_EXT                                             0x8010
#define GL_CONVOLUTION_2D                                                 0x8011
#define GL_CONVOLUTION_2D_EXT                                             0x8011
#define GL_CONVOLUTION_BORDER_COLOR                                       0x8154
#define GL_CONVOLUTION_BORDER_COLOR_HP                                    0x8154
#define GL_CONVOLUTION_BORDER_MODE                                        0x8013
#define GL_CONVOLUTION_BORDER_MODE_EXT                                    0x8013
#define GL_CONVOLUTION_FILTER_BIAS                                        0x8015
#define GL_CONVOLUTION_FILTER_BIAS_EXT                                    0x8015
#define GL_CONVOLUTION_FILTER_SCALE                                       0x8014
#define GL_CONVOLUTION_FILTER_SCALE_EXT                                   0x8014
#define GL_CONVOLUTION_FORMAT                                             0x8017
#define GL_CONVOLUTION_FORMAT_EXT                                         0x8017
#define GL_CONVOLUTION_HEIGHT                                             0x8019
#define GL_CONVOLUTION_HEIGHT_EXT                                         0x8019
#define GL_CONVOLUTION_WIDTH                                              0x8018
#define GL_CONVOLUTION_WIDTH_EXT                                          0x8018
#define GL_CON_0_ATI                                                      0x8941
#define GL_CON_10_ATI                                                     0x894B
#define GL_CON_11_ATI                                                     0x894C
#define GL_CON_12_ATI                                                     0x894D
#define GL_CON_13_ATI                                                     0x894E
#define GL_CON_14_ATI                                                     0x894F
#define GL_CON_15_ATI                                                     0x8950
#define GL_CON_16_ATI                                                     0x8951
#define GL_CON_17_ATI                                                     0x8952
#define GL_CON_18_ATI                                                     0x8953
#define GL_CON_19_ATI                                                     0x8954
#define GL_CON_1_ATI                                                      0x8942
#define GL_CON_20_ATI                                                     0x8955
#define GL_CON_21_ATI                                                     0x8956
#define GL_CON_22_ATI                                                     0x8957
#define GL_CON_23_ATI                                                     0x8958
#define GL_CON_24_ATI                                                     0x8959
#define GL_CON_25_ATI                                                     0x895A
#define GL_CON_26_ATI                                                     0x895B
#define GL_CON_27_ATI                                                     0x895C
#define GL_CON_28_ATI                                                     0x895D
#define GL_CON_29_ATI                                                     0x895E
#define GL_CON_2_ATI                                                      0x8943
#define GL_CON_30_ATI                                                     0x895F
#define GL_CON_31_ATI                                                     0x8960
#define GL_CON_3_ATI                                                      0x8944
#define GL_CON_4_ATI                                                      0x8945
#define GL_CON_5_ATI                                                      0x8946
#define GL_CON_6_ATI                                                      0x8947
#define GL_CON_7_ATI                                                      0x8948
#define GL_CON_8_ATI                                                      0x8949
#define GL_CON_9_ATI                                                      0x894A
#define GL_COORD_REPLACE                                                  0x8862
#define GL_COORD_REPLACE_ARB                                              0x8862
#define GL_COPY                                                           0x1503
#define GL_COPY_INVERTED                                                  0x150C
#define GL_COPY_PIXEL_TOKEN                                               0x0706
#define GL_CULL_FACE                                                      0x0B44
#define GL_CULL_FACE_MODE                                                 0x0B45
#define GL_CURRENT_BIT                                                    0x00000001
#define GL_CURRENT_COLOR                                                  0x0B00
#define GL_CURRENT_FOG_COORD                                              0x8453
#define GL_CURRENT_FOG_COORDINATE                                         0x8453
#define GL_CURRENT_FOG_COORDINATE_EXT                                     0x8453
#define GL_CURRENT_INDEX                                                  0x0B01
#define GL_CURRENT_MATRIX_ARB                                             0x8641
#define GL_CURRENT_MATRIX_INDEX_ARB                                       0x8845
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB                                 0x8640
#define GL_CURRENT_NORMAL                                                 0x0B02
#define GL_CURRENT_PALETTE_MATRIX_ARB                                     0x8843
#define GL_CURRENT_PROGRAM                                                0x8B8D
#define GL_CURRENT_QUERY                                                  0x8865
#define GL_CURRENT_QUERY_ARB                                              0x8865
#define GL_CURRENT_RASTER_COLOR                                           0x0B04
#define GL_CURRENT_RASTER_DISTANCE                                        0x0B09
#define GL_CURRENT_RASTER_INDEX                                           0x0B05
#define GL_CURRENT_RASTER_POSITION                                        0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID                                  0x0B08
#define GL_CURRENT_RASTER_SECONDARY_COLOR                                 0x845F
#define GL_CURRENT_RASTER_TEXTURE_COORDS                                  0x0B06
#define GL_CURRENT_SECONDARY_COLOR                                        0x8459
#define GL_CURRENT_SECONDARY_COLOR_EXT                                    0x8459
#define GL_CURRENT_TEXTURE_COORDS                                         0x0B03
#define GL_CURRENT_VERTEX_ATTRIB                                          0x8626
#define GL_CURRENT_VERTEX_ATTRIB_ARB                                      0x8626
#define GL_CURRENT_WEIGHT_ARB                                             0x86A8
#define GL_CW                                                             0x0900
#define GL_DECAL                                                          0x2101
#define GL_DECR                                                           0x1E03
#define GL_DECR_WRAP                                                      0x8508
#define GL_DECR_WRAP_EXT                                                  0x8508
#define GL_DELETE_STATUS                                                  0x8B80
#define GL_DEPTH                                                          0x1801
#define GL_DEPTH24_STENCIL8                                               0x88F0
#define GL_DEPTH32F_STENCIL8                                              0x8CAD
#define GL_DEPTH_ATTACHMENT                                               0x8D00
#define GL_DEPTH_ATTACHMENT_EXT                                           0x8D00
#define GL_DEPTH_BIAS                                                     0x0D1F
#define GL_DEPTH_BITS                                                     0x0D56
#define GL_DEPTH_BUFFER_BIT                                               0x00000100
#define GL_DEPTH_CLEAR_VALUE                                              0x0B73
#define GL_DEPTH_COMPONENT                                                0x1902
#define GL_DEPTH_COMPONENT16                                              0x81A5
#define GL_DEPTH_COMPONENT16_ARB                                          0x81A5
#define GL_DEPTH_COMPONENT24                                              0x81A6
#define GL_DEPTH_COMPONENT24_ARB                                          0x81A6
#define GL_DEPTH_COMPONENT32                                              0x81A7
#define GL_DEPTH_COMPONENT32F                                             0x8CAC
#define GL_DEPTH_COMPONENT32_ARB                                          0x81A7
#define GL_DEPTH_FUNC                                                     0x0B74
#define GL_DEPTH_RANGE                                                    0x0B70
#define GL_DEPTH_SCALE                                                    0x0D1E
#define GL_DEPTH_STENCIL                                                  0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT                                       0x821A
#define GL_DEPTH_TEST                                                     0x0B71
#define GL_DEPTH_TEXTURE_MODE                                             0x884B
#define GL_DEPTH_TEXTURE_MODE_ARB                                         0x884B
#define GL_DEPTH_WRITEMASK                                                0x0B72
#define GL_DIFFUSE                                                        0x1201
#define GL_DISTANCE_ATTENUATION_EXT                                       0x8129
#define GL_DITHER                                                         0x0BD0
#define GL_DOMAIN                                                         0x0A02
#define GL_DONT_CARE                                                      0x1100
#define GL_DOT2_ADD_ATI                                                   0x896C
#define GL_DOT3_ATI                                                       0x8966
#define GL_DOT3_RGB                                                       0x86AE
#define GL_DOT3_RGBA                                                      0x86AF
#define GL_DOT3_RGBA_ARB                                                  0x86AF
#define GL_DOT3_RGBA_EXT                                                  0x8741
#define GL_DOT3_RGB_ARB                                                   0x86AE
#define GL_DOT3_RGB_EXT                                                   0x8740
#define GL_DOT4_ATI                                                       0x8967
#define GL_DOUBLE                                                         0x140A
#define GL_DOUBLEBUFFER                                                   0x0C32
#define GL_DRAW_BUFFER                                                    0x0C01
#define GL_DRAW_BUFFER0                                                   0x8825
#define GL_DRAW_BUFFER0_ARB                                               0x8825
#define GL_DRAW_BUFFER1                                                   0x8826
#define GL_DRAW_BUFFER10                                                  0x882F
#define GL_DRAW_BUFFER10_ARB                                              0x882F
#define GL_DRAW_BUFFER11                                                  0x8830
#define GL_DRAW_BUFFER11_ARB                                              0x8830
#define GL_DRAW_BUFFER12                                                  0x8831
#define GL_DRAW_BUFFER12_ARB                                              0x8831
#define GL_DRAW_BUFFER13                                                  0x8832
#define GL_DRAW_BUFFER13_ARB                                              0x8832
#define GL_DRAW_BUFFER14                                                  0x8833
#define GL_DRAW_BUFFER14_ARB                                              0x8833
#define GL_DRAW_BUFFER15                                                  0x8834
#define GL_DRAW_BUFFER15_ARB                                              0x8834
#define GL_DRAW_BUFFER1_ARB                                               0x8826
#define GL_DRAW_BUFFER2                                                   0x8827
#define GL_DRAW_BUFFER2_ARB                                               0x8827
#define GL_DRAW_BUFFER3                                                   0x8828
#define GL_DRAW_BUFFER3_ARB                                               0x8828
#define GL_DRAW_BUFFER4                                                   0x8829
#define GL_DRAW_BUFFER4_ARB                                               0x8829
#define GL_DRAW_BUFFER5                                                   0x882A
#define GL_DRAW_BUFFER5_ARB                                               0x882A
#define GL_DRAW_BUFFER6                                                   0x882B
#define GL_DRAW_BUFFER6_ARB                                               0x882B
#define GL_DRAW_BUFFER7                                                   0x882C
#define GL_DRAW_BUFFER7_ARB                                               0x882C
#define GL_DRAW_BUFFER8                                                   0x882D
#define GL_DRAW_BUFFER8_ARB                                               0x882D
#define GL_DRAW_BUFFER9                                                   0x882E
#define GL_DRAW_BUFFER9_ARB                                               0x882E
#define GL_DRAW_FRAMEBUFFER                                               0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING                                       0x8CA6
#define GL_DRAW_PIXEL_TOKEN                                               0x0705
#define GL_DST_ALPHA                                                      0x0304
#define GL_DST_COLOR                                                      0x0306
#define GL_DYNAMIC_COPY                                                   0x88EA
#define GL_DYNAMIC_COPY_ARB                                               0x88EA
#define GL_DYNAMIC_DRAW                                                   0x88E8
#define GL_DYNAMIC_DRAW_ARB                                               0x88E8
#define GL_DYNAMIC_READ                                                   0x88E9
#define GL_DYNAMIC_READ_ARB                                               0x88E9
#define GL_EDGE_FLAG                                                      0x0B43
#define GL_EDGE_FLAG_ARRAY                                                0x8079
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING                                 0x889B
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB                             0x889B
#define GL_EDGE_FLAG_ARRAY_POINTER                                        0x8093
#define GL_EDGE_FLAG_ARRAY_STRIDE                                         0x808C
#define GL_EIGHTH_BIT_ATI                                                 0x00000020
#define GL_ELEMENT_ARRAY_BUFFER                                           0x8893
#define GL_ELEMENT_ARRAY_BUFFER_ARB                                       0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                                   0x8895
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                               0x8895
#define GL_EMISSION                                                       0x1600
#define GL_ENABLE_BIT                                                     0x00002000
#define GL_EQUAL                                                          0x0202
#define GL_EQUIV                                                          0x1509
#define GL_EVAL_BIT                                                       0x00010000
#define GL_EXP                                                            0x0800
#define GL_EXP2                                                           0x0801
#define GL_EXTENSIONS                                                     0x1F03
#define GL_EYE_LINEAR                                                     0x2400
#define GL_EYE_PLANE                                                      0x2502
#define GL_FALSE                                                          0
#define GL_FASTEST                                                        0x1101
#define GL_FEEDBACK                                                       0x1C01
#define GL_FEEDBACK_BUFFER_POINTER                                        0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE                                           0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE                                           0x0DF2
#define GL_FILL                                                           0x1B02
#define GL_FIXED_ONLY_ARB                                                 0x891D
#define GL_FLAT                                                           0x1D00
#define GL_FLOAT                                                          0x1406
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                                 0x8DAD
#define GL_FLOAT_MAT2                                                     0x8B5A
#define GL_FLOAT_MAT2_ARB                                                 0x8B5A
#define GL_FLOAT_MAT2x3                                                   0x8B65
#define GL_FLOAT_MAT2x4                                                   0x8B66
#define GL_FLOAT_MAT3                                                     0x8B5B
#define GL_FLOAT_MAT3_ARB                                                 0x8B5B
#define GL_FLOAT_MAT3x2                                                   0x8B67
#define GL_FLOAT_MAT3x4                                                   0x8B68
#define GL_FLOAT_MAT4                                                     0x8B5C
#define GL_FLOAT_MAT4_ARB                                                 0x8B5C
#define GL_FLOAT_MAT4x2                                                   0x8B69
#define GL_FLOAT_MAT4x3                                                   0x8B6A
#define GL_FLOAT_VEC2                                                     0x8B50
#define GL_FLOAT_VEC2_ARB                                                 0x8B50
#define GL_FLOAT_VEC3                                                     0x8B51
#define GL_FLOAT_VEC3_ARB                                                 0x8B51
#define GL_FLOAT_VEC4                                                     0x8B52
#define GL_FLOAT_VEC4_ARB                                                 0x8B52
#define GL_FOG                                                            0x0B60
#define GL_FOG_BIT                                                        0x00000080
#define GL_FOG_COLOR                                                      0x0B66
#define GL_FOG_COORD                                                      0x8451
#define GL_FOG_COORDINATE                                                 0x8451
#define GL_FOG_COORDINATE_ARRAY                                           0x8457
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING                            0x889D
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB                        0x889D
#define GL_FOG_COORDINATE_ARRAY_EXT                                       0x8457
#define GL_FOG_COORDINATE_ARRAY_POINTER                                   0x8456
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT                               0x8456
#define GL_FOG_COORDINATE_ARRAY_STRIDE                                    0x8455
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT                                0x8455
#define GL_FOG_COORDINATE_ARRAY_TYPE                                      0x8454
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT                                  0x8454
#define GL_FOG_COORDINATE_EXT                                             0x8451
#define GL_FOG_COORDINATE_SOURCE                                          0x8450
#define GL_FOG_COORDINATE_SOURCE_EXT                                      0x8450
#define GL_FOG_COORD_ARRAY                                                0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING                                 0x889D
#define GL_FOG_COORD_ARRAY_POINTER                                        0x8456
#define GL_FOG_COORD_ARRAY_STRIDE                                         0x8455
#define GL_FOG_COORD_ARRAY_TYPE                                           0x8454
#define GL_FOG_COORD_SRC                                                  0x8450
#define GL_FOG_DENSITY                                                    0x0B62
#define GL_FOG_END                                                        0x0B64
#define GL_FOG_HINT                                                       0x0C54
#define GL_FOG_INDEX                                                      0x0B61
#define GL_FOG_MODE                                                       0x0B65
#define GL_FOG_START                                                      0x0B63
#define GL_FRAGMENT_DEPTH                                                 0x8452
#define GL_FRAGMENT_DEPTH_EXT                                             0x8452
#define GL_FRAGMENT_PROGRAM_ARB                                           0x8804
#define GL_FRAGMENT_SHADER                                                0x8B30
#define GL_FRAGMENT_SHADER_ARB                                            0x8B30
#define GL_FRAGMENT_SHADER_ATI                                            0x8920
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                                0x8B8B
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB                            0x8B8B
#define GL_FRAMEBUFFER                                                    0x8D40
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                              0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                               0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING                          0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE                          0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                              0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                              0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME                             0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT                         0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE                             0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT                         0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                                0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE                            0x8217
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT                  0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE                   0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT               0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER                           0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL                           0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT                       0x8CD2
#define GL_FRAMEBUFFER_BINDING                                            0x8CA6
#define GL_FRAMEBUFFER_BINDING_EXT                                        0x8CA6
#define GL_FRAMEBUFFER_COMPLETE                                           0x8CD5
#define GL_FRAMEBUFFER_COMPLETE_EXT                                       0x8CD5
#define GL_FRAMEBUFFER_DEFAULT                                            0x8218
#define GL_FRAMEBUFFER_EXT                                                0x8D40
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                              0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT                          0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT                          0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER                             0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT                         0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT                             0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT                      0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT                  0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE                             0x8D56
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER                             0x8CDC
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT                         0x8CDC
#define GL_FRAMEBUFFER_UNDEFINED                                          0x8219
#define GL_FRAMEBUFFER_UNSUPPORTED                                        0x8CDD
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                                    0x8CDD
#define GL_FRONT                                                          0x0404
#define GL_FRONT_AND_BACK                                                 0x0408
#define GL_FRONT_FACE                                                     0x0B46
#define GL_FRONT_LEFT                                                     0x0400
#define GL_FRONT_RIGHT                                                    0x0401
#define GL_FUNC_ADD                                                       0x8006
#define GL_FUNC_ADD_EXT                                                   0x8006
#define GL_FUNC_REVERSE_SUBTRACT                                          0x800B
#define GL_FUNC_REVERSE_SUBTRACT_EXT                                      0x800B
#define GL_FUNC_SUBTRACT                                                  0x800A
#define GL_FUNC_SUBTRACT_EXT                                              0x800A
#define GL_GENERATE_MIPMAP                                                0x8191
#define GL_GENERATE_MIPMAP_HINT                                           0x8192
#define GL_GENERATE_MIPMAP_HINT_SGIS                                      0x8192
#define GL_GENERATE_MIPMAP_SGIS                                           0x8191
#define GL_GEQUAL                                                         0x0206
#define GL_GREATER                                                        0x0204
#define GL_GREEN                                                          0x1904
#define GL_GREEN_BIAS                                                     0x0D19
#define GL_GREEN_BITS                                                     0x0D53
#define GL_GREEN_BIT_ATI                                                  0x00000002
#define GL_GREEN_INTEGER_EXT                                              0x8D95
#define GL_GREEN_SCALE                                                    0x0D18
#define GL_HALF_BIT_ATI                                                   0x00000008
#define GL_HALF_FLOAT_ARB                                                 0x140B
#define GL_HINT_BIT                                                       0x00008000
#define GL_HISTOGRAM                                                      0x8024
#define GL_HISTOGRAM_ALPHA_SIZE                                           0x802B
#define GL_HISTOGRAM_ALPHA_SIZE_EXT                                       0x802B
#define GL_HISTOGRAM_BLUE_SIZE                                            0x802A
#define GL_HISTOGRAM_BLUE_SIZE_EXT                                        0x802A
#define GL_HISTOGRAM_EXT                                                  0x8024
#define GL_HISTOGRAM_FORMAT                                               0x8027
#define GL_HISTOGRAM_FORMAT_EXT                                           0x8027
#define GL_HISTOGRAM_GREEN_SIZE                                           0x8029
#define GL_HISTOGRAM_GREEN_SIZE_EXT                                       0x8029
#define GL_HISTOGRAM_LUMINANCE_SIZE                                       0x802C
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT                                   0x802C
#define GL_HISTOGRAM_RED_SIZE                                             0x8028
#define GL_HISTOGRAM_RED_SIZE_EXT                                         0x8028
#define GL_HISTOGRAM_SINK                                                 0x802D
#define GL_HISTOGRAM_SINK_EXT                                             0x802D
#define GL_HISTOGRAM_WIDTH                                                0x8026
#define GL_HISTOGRAM_WIDTH_EXT                                            0x8026
#define GL_IGNORE_BORDER_HP                                               0x8150
#define GL_INCR                                                           0x1E02
#define GL_INCR_WRAP                                                      0x8507
#define GL_INCR_WRAP_EXT                                                  0x8507
#define GL_INDEX                                                          0x8222
#define GL_INDEX_ARRAY                                                    0x8077
#define GL_INDEX_ARRAY_BUFFER_BINDING                                     0x8899
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB                                 0x8899
#define GL_INDEX_ARRAY_POINTER                                            0x8091
#define GL_INDEX_ARRAY_STRIDE                                             0x8086
#define GL_INDEX_ARRAY_TYPE                                               0x8085
#define GL_INDEX_BITS                                                     0x0D51
#define GL_INDEX_CLEAR_VALUE                                              0x0C20
#define GL_INDEX_LOGIC_OP                                                 0x0BF1
#define GL_INDEX_MODE                                                     0x0C30
#define GL_INDEX_OFFSET                                                   0x0D13
#define GL_INDEX_SHIFT                                                    0x0D12
#define GL_INDEX_WRITEMASK                                                0x0C21
#define GL_INFO_LOG_LENGTH                                                0x8B84
#define GL_INT                                                            0x1404
#define GL_INTENSITY                                                      0x8049
#define GL_INTENSITY12                                                    0x804C
#define GL_INTENSITY16                                                    0x804D
#define GL_INTENSITY16F_ARB                                               0x881D
#define GL_INTENSITY16I_EXT                                               0x8D8B
#define GL_INTENSITY16UI_EXT                                              0x8D79
#define GL_INTENSITY16_SNORM                                              0x901B
#define GL_INTENSITY32F_ARB                                               0x8817
#define GL_INTENSITY32I_EXT                                               0x8D85
#define GL_INTENSITY32UI_EXT                                              0x8D73
#define GL_INTENSITY4                                                     0x804A
#define GL_INTENSITY8                                                     0x804B
#define GL_INTENSITY8I_EXT                                                0x8D91
#define GL_INTENSITY8UI_EXT                                               0x8D7F
#define GL_INTENSITY8_SNORM                                               0x9017
#define GL_INTENSITY_SNORM                                                0x9013
#define GL_INTERPOLATE                                                    0x8575
#define GL_INTERPOLATE_ARB                                                0x8575
#define GL_INTERPOLATE_EXT                                                0x8575
#define GL_INT_VEC2                                                       0x8B53
#define GL_INT_VEC2_ARB                                                   0x8B53
#define GL_INT_VEC3                                                       0x8B54
#define GL_INT_VEC3_ARB                                                   0x8B54
#define GL_INT_VEC4                                                       0x8B55
#define GL_INT_VEC4_ARB                                                   0x8B55
#define GL_INVALID_ENUM                                                   0x0500
#define GL_INVALID_FRAMEBUFFER_OPERATION                                  0x0506
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT                              0x0506
#define GL_INVALID_OPERATION                                              0x0502
#define GL_INVALID_VALUE                                                  0x0501
#define GL_INVERT                                                         0x150A
#define GL_KEEP                                                           0x1E00
#define GL_LEFT                                                           0x0406
#define GL_LEQUAL                                                         0x0203
#define GL_LERP_ATI                                                       0x8969
#define GL_LESS                                                           0x0201
#define GL_LIGHT0                                                         0x4000
#define GL_LIGHT1                                                         0x4001
#define GL_LIGHT2                                                         0x4002
#define GL_LIGHT3                                                         0x4003
#define GL_LIGHT4                                                         0x4004
#define GL_LIGHT5                                                         0x4005
#define GL_LIGHT6                                                         0x4006
#define GL_LIGHT7                                                         0x4007
#define GL_LIGHTING                                                       0x0B50
#define GL_LIGHTING_BIT                                                   0x00000040
#define GL_LIGHT_MODEL_AMBIENT                                            0x0B53
#define GL_LIGHT_MODEL_COLOR_CONTROL                                      0x81F8
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT                                  0x81F8
#define GL_LIGHT_MODEL_LOCAL_VIEWER                                       0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE                                           0x0B52
#define GL_LINE                                                           0x1B01
#define GL_LINEAR                                                         0x2601
#define GL_LINEAR_ATTENUATION                                             0x1208
#define GL_LINEAR_MIPMAP_LINEAR                                           0x2703
#define GL_LINEAR_MIPMAP_NEAREST                                          0x2701
#define GL_LINES                                                          0x0001
#define GL_LINE_BIT                                                       0x00000004
#define GL_LINE_LOOP                                                      0x0002
#define GL_LINE_RESET_TOKEN                                               0x0707
#define GL_LINE_SMOOTH                                                    0x0B20
#define GL_LINE_SMOOTH_HINT                                               0x0C52
#define GL_LINE_STIPPLE                                                   0x0B24
#define GL_LINE_STIPPLE_PATTERN                                           0x0B25
#define GL_LINE_STIPPLE_REPEAT                                            0x0B26
#define GL_LINE_STRIP                                                     0x0003
#define GL_LINE_TOKEN                                                     0x0702
#define GL_LINE_WIDTH                                                     0x0B21
#define GL_LINE_WIDTH_GRANULARITY                                         0x0B23
#define GL_LINE_WIDTH_RANGE                                               0x0B22
#define GL_LINK_STATUS                                                    0x8B82
#define GL_LIST_BASE                                                      0x0B32
#define GL_LIST_BIT                                                       0x00020000
#define GL_LIST_INDEX                                                     0x0B33
#define GL_LIST_MODE                                                      0x0B30
#define GL_LOAD                                                           0x0101
#define GL_LOGIC_OP                                                       0x0BF1
#define GL_LOGIC_OP_MODE                                                  0x0BF0
#define GL_LOWER_LEFT                                                     0x8CA1
#define GL_LUMINANCE                                                      0x1909
#define GL_LUMINANCE12                                                    0x8041
#define GL_LUMINANCE12_ALPHA12                                            0x8047
#define GL_LUMINANCE12_ALPHA4                                             0x8046
#define GL_LUMINANCE16                                                    0x8042
#define GL_LUMINANCE16F_ARB                                               0x881E
#define GL_LUMINANCE16I_EXT                                               0x8D8C
#define GL_LUMINANCE16UI_EXT                                              0x8D7A
#define GL_LUMINANCE16_ALPHA16                                            0x8048
#define GL_LUMINANCE16_ALPHA16_SNORM                                      0x901A
#define GL_LUMINANCE16_SNORM                                              0x9019
#define GL_LUMINANCE32F_ARB                                               0x8818
#define GL_LUMINANCE32I_EXT                                               0x8D86
#define GL_LUMINANCE32UI_EXT                                              0x8D74
#define GL_LUMINANCE4                                                     0x803F
#define GL_LUMINANCE4_ALPHA4                                              0x8043
#define GL_LUMINANCE6_ALPHA2                                              0x8044
#define GL_LUMINANCE8                                                     0x8040
#define GL_LUMINANCE8I_EXT                                                0x8D92
#define GL_LUMINANCE8UI_EXT                                               0x8D80
#define GL_LUMINANCE8_ALPHA8                                              0x8045
#define GL_LUMINANCE8_ALPHA8_SNORM                                        0x9016
#define GL_LUMINANCE8_SNORM                                               0x9015
#define GL_LUMINANCE_ALPHA                                                0x190A
#define GL_LUMINANCE_ALPHA16F_ARB                                         0x881F
#define GL_LUMINANCE_ALPHA16I_EXT                                         0x8D8D
#define GL_LUMINANCE_ALPHA16UI_EXT                                        0x8D7B
#define GL_LUMINANCE_ALPHA32F_ARB                                         0x8819
#define GL_LUMINANCE_ALPHA32I_EXT                                         0x8D87
#define GL_LUMINANCE_ALPHA32UI_EXT                                        0x8D75
#define GL_LUMINANCE_ALPHA8I_EXT                                          0x8D93
#define GL_LUMINANCE_ALPHA8UI_EXT                                         0x8D81
#define GL_LUMINANCE_ALPHA_INTEGER_EXT                                    0x8D9D
#define GL_LUMINANCE_ALPHA_SNORM                                          0x9012
#define GL_LUMINANCE_INTEGER_EXT                                          0x8D9C
#define GL_LUMINANCE_SNORM                                                0x9011
#define GL_MAD_ATI                                                        0x8968
#define GL_MAP1_COLOR_4                                                   0x0D90
#define GL_MAP1_GRID_DOMAIN                                               0x0DD0
#define GL_MAP1_GRID_SEGMENTS                                             0x0DD1
#define GL_MAP1_INDEX                                                     0x0D91
#define GL_MAP1_NORMAL                                                    0x0D92
#define GL_MAP1_TEXTURE_COORD_1                                           0x0D93
#define GL_MAP1_TEXTURE_COORD_2                                           0x0D94
#define GL_MAP1_TEXTURE_COORD_3                                           0x0D95
#define GL_MAP1_TEXTURE_COORD_4                                           0x0D96
#define GL_MAP1_VERTEX_3                                                  0x0D97
#define GL_MAP1_VERTEX_4                                                  0x0D98
#define GL_MAP2_COLOR_4                                                   0x0DB0
#define GL_MAP2_GRID_DOMAIN                                               0x0DD2
#define GL_MAP2_GRID_SEGMENTS                                             0x0DD3
#define GL_MAP2_INDEX                                                     0x0DB1
#define GL_MAP2_NORMAL                                                    0x0DB2
#define GL_MAP2_TEXTURE_COORD_1                                           0x0DB3
#define GL_MAP2_TEXTURE_COORD_2                                           0x0DB4
#define GL_MAP2_TEXTURE_COORD_3                                           0x0DB5
#define GL_MAP2_TEXTURE_COORD_4                                           0x0DB6
#define GL_MAP2_VERTEX_3                                                  0x0DB7
#define GL_MAP2_VERTEX_4                                                  0x0DB8
#define GL_MAP_COLOR                                                      0x0D10
#define GL_MAP_STENCIL                                                    0x0D11
#define GL_MATRIX0_ARB                                                    0x88C0
#define GL_MATRIX10_ARB                                                   0x88CA
#define GL_MATRIX11_ARB                                                   0x88CB
#define GL_MATRIX12_ARB                                                   0x88CC
#define GL_MATRIX13_ARB                                                   0x88CD
#define GL_MATRIX14_ARB                                                   0x88CE
#define GL_MATRIX15_ARB                                                   0x88CF
#define GL_MATRIX16_ARB                                                   0x88D0
#define GL_MATRIX17_ARB                                                   0x88D1
#define GL_MATRIX18_ARB                                                   0x88D2
#define GL_MATRIX19_ARB                                                   0x88D3
#define GL_MATRIX1_ARB                                                    0x88C1
#define GL_MATRIX20_ARB                                                   0x88D4
#define GL_MATRIX21_ARB                                                   0x88D5
#define GL_MATRIX22_ARB                                                   0x88D6
#define GL_MATRIX23_ARB                                                   0x88D7
#define GL_MATRIX24_ARB                                                   0x88D8
#define GL_MATRIX25_ARB                                                   0x88D9
#define GL_MATRIX26_ARB                                                   0x88DA
#define GL_MATRIX27_ARB                                                   0x88DB
#define GL_MATRIX28_ARB                                                   0x88DC
#define GL_MATRIX29_ARB                                                   0x88DD
#define GL_MATRIX2_ARB                                                    0x88C2
#define GL_MATRIX30_ARB                                                   0x88DE
#define GL_MATRIX31_ARB                                                   0x88DF
#define GL_MATRIX3_ARB                                                    0x88C3
#define GL_MATRIX4_ARB                                                    0x88C4
#define GL_MATRIX5_ARB                                                    0x88C5
#define GL_MATRIX6_ARB                                                    0x88C6
#define GL_MATRIX7_ARB                                                    0x88C7
#define GL_MATRIX8_ARB                                                    0x88C8
#define GL_MATRIX9_ARB                                                    0x88C9
#define GL_MATRIX_INDEX_ARRAY_ARB                                         0x8844
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB                                 0x8849
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB                                    0x8846
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                                  0x8848
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB                                    0x8847
#define GL_MATRIX_MODE                                                    0x0BA0
#define GL_MATRIX_PALETTE_ARB                                             0x8840
#define GL_MAX                                                            0x8008
#define GL_MAX_3D_TEXTURE_SIZE                                            0x8073
#define GL_MAX_3D_TEXTURE_SIZE_EXT                                        0x8073
#define GL_MAX_ATTRIB_STACK_DEPTH                                         0x0D35
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH                                  0x0D3B
#define GL_MAX_CLIP_PLANES                                                0x0D32
#define GL_MAX_COLOR_ATTACHMENTS                                          0x8CDF
#define GL_MAX_COLOR_ATTACHMENTS_EXT                                      0x8CDF
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH                                   0x80B3
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI                               0x80B3
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                               0x8B4D
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB                           0x8B4D
#define GL_MAX_CONVOLUTION_HEIGHT                                         0x801B
#define GL_MAX_CONVOLUTION_HEIGHT_EXT                                     0x801B
#define GL_MAX_CONVOLUTION_WIDTH                                          0x801A
#define GL_MAX_CONVOLUTION_WIDTH_EXT                                      0x801A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                                      0x851C
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                                  0x851C
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT                                  0x851C
#define GL_MAX_DRAW_BUFFERS                                               0x8824
#define GL_MAX_DRAW_BUFFERS_ARB                                           0x8824
#define GL_MAX_ELEMENTS_INDICES                                           0x80E9
#define GL_MAX_ELEMENTS_INDICES_EXT                                       0x80E9
#define GL_MAX_ELEMENTS_VERTICES                                          0x80E8
#define GL_MAX_ELEMENTS_VERTICES_EXT                                      0x80E8
#define GL_MAX_EVAL_ORDER                                                 0x0D30
#define GL_MAX_EXT                                                        0x8008
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                                0x8B49
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB                            0x8B49
#define GL_MAX_LIGHTS                                                     0x0D31
#define GL_MAX_LIST_NESTING                                               0x0B31
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB                             0x8841
#define GL_MAX_MODELVIEW_STACK_DEPTH                                      0x0D36
#define GL_MAX_NAME_STACK_DEPTH                                           0x0D37
#define GL_MAX_PALETTE_MATRICES_ARB                                       0x8842
#define GL_MAX_PIXEL_MAP_TABLE                                            0x0D34
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB                              0x88B1
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                               0x880B
#define GL_MAX_PROGRAM_ATTRIBS_ARB                                        0x88AD
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                                 0x88B5
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB                                   0x88A1
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                               0x88B4
#define GL_MAX_PROGRAM_MATRICES_ARB                                       0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB                             0x862E
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB                       0x88B3
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB                        0x880E
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                                 0x88AF
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB                            0x88A3
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB                              0x88AB
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB                             0x88A7
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB                        0x8810
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB                        0x880F
#define GL_MAX_PROGRAM_PARAMETERS_ARB                                     0x88A9
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                                    0x88A5
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                               0x880D
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                               0x880C
#define GL_MAX_PROJECTION_STACK_DEPTH                                     0x0D38
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB                                 0x84F8
#define GL_MAX_RENDERBUFFER_SIZE                                          0x84E8
#define GL_MAX_RENDERBUFFER_SIZE_EXT                                      0x84E8
#define GL_MAX_SAMPLES                                                    0x8D57
#define GL_MAX_TEXTURE_COORDS                                             0x8871
#define GL_MAX_TEXTURE_COORDS_ARB                                         0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS                                        0x8872
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                                    0x8872
#define GL_MAX_TEXTURE_LOD_BIAS                                           0x84FD
#define GL_MAX_TEXTURE_LOD_BIAS_EXT                                       0x84FD
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT                                 0x84FF
#define GL_MAX_TEXTURE_SIZE                                               0x0D33
#define GL_MAX_TEXTURE_STACK_DEPTH                                        0x0D39
#define GL_MAX_TEXTURE_UNITS                                              0x84E2
#define GL_MAX_TEXTURE_UNITS_ARB                                          0x84E2
#define GL_MAX_VARYING_FLOATS                                             0x8B4B
#define GL_MAX_VARYING_FLOATS_ARB                                         0x8B4B
#define GL_MAX_VERTEX_ATTRIBS                                             0x8869
#define GL_MAX_VERTEX_ATTRIBS_ARB                                         0x8869
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                                 0x8B4C
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB                             0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                                  0x8B4A
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB                              0x8B4A
#define GL_MAX_VERTEX_UNITS_ARB                                           0x86A4
#define GL_MAX_VIEWPORT_DIMS                                              0x0D3A
#define GL_MIN                                                            0x8007
#define GL_MINMAX                                                         0x802E
#define GL_MINMAX_EXT                                                     0x802E
#define GL_MINMAX_FORMAT                                                  0x802F
#define GL_MINMAX_FORMAT_EXT                                              0x802F
#define GL_MINMAX_SINK                                                    0x8030
#define GL_MINMAX_SINK_EXT                                                0x8030
#define GL_MIN_EXT                                                        0x8007
#define GL_MIRRORED_REPEAT                                                0x8370
#define GL_MIRRORED_REPEAT_ARB                                            0x8370
#define GL_MODELVIEW                                                      0x1700
#define GL_MODELVIEW0_ARB                                                 0x1700
#define GL_MODELVIEW10_ARB                                                0x872A
#define GL_MODELVIEW11_ARB                                                0x872B
#define GL_MODELVIEW12_ARB                                                0x872C
#define GL_MODELVIEW13_ARB                                                0x872D
#define GL_MODELVIEW14_ARB                                                0x872E
#define GL_MODELVIEW15_ARB                                                0x872F
#define GL_MODELVIEW16_ARB                                                0x8730
#define GL_MODELVIEW17_ARB                                                0x8731
#define GL_MODELVIEW18_ARB                                                0x8732
#define GL_MODELVIEW19_ARB                                                0x8733
#define GL_MODELVIEW1_ARB                                                 0x850A
#define GL_MODELVIEW20_ARB                                                0x8734
#define GL_MODELVIEW21_ARB                                                0x8735
#define GL_MODELVIEW22_ARB                                                0x8736
#define GL_MODELVIEW23_ARB                                                0x8737
#define GL_MODELVIEW24_ARB                                                0x8738
#define GL_MODELVIEW25_ARB                                                0x8739
#define GL_MODELVIEW26_ARB                                                0x873A
#define GL_MODELVIEW27_ARB                                                0x873B
#define GL_MODELVIEW28_ARB                                                0x873C
#define GL_MODELVIEW29_ARB                                                0x873D
#define GL_MODELVIEW2_ARB                                                 0x8722
#define GL_MODELVIEW30_ARB                                                0x873E
#define GL_MODELVIEW31_ARB                                                0x873F
#define GL_MODELVIEW3_ARB                                                 0x8723
#define GL_MODELVIEW4_ARB                                                 0x8724
#define GL_MODELVIEW5_ARB                                                 0x8725
#define GL_MODELVIEW6_ARB                                                 0x8726
#define GL_MODELVIEW7_ARB                                                 0x8727
#define GL_MODELVIEW8_ARB                                                 0x8728
#define GL_MODELVIEW9_ARB                                                 0x8729
#define GL_MODELVIEW_MATRIX                                               0x0BA6
#define GL_MODELVIEW_STACK_DEPTH                                          0x0BA3
#define GL_MODULATE                                                       0x2100
#define GL_MOV_ATI                                                        0x8961
#define GL_MULT                                                           0x0103
#define GL_MULTISAMPLE                                                    0x809D
#define GL_MULTISAMPLE_ARB                                                0x809D
#define GL_MULTISAMPLE_BIT                                                0x20000000
#define GL_MULTISAMPLE_BIT_ARB                                            0x20000000
#define GL_MUL_ATI                                                        0x8964
#define GL_N3F_V3F                                                        0x2A25
#define GL_NAME_STACK_DEPTH                                               0x0D70
#define GL_NAND                                                           0x150E
#define GL_NEAREST                                                        0x2600
#define GL_NEAREST_MIPMAP_LINEAR                                          0x2702
#define GL_NEAREST_MIPMAP_NEAREST                                         0x2700
#define GL_NEGATE_BIT_ATI                                                 0x00000004
#define GL_NEVER                                                          0x0200
#define GL_NICEST                                                         0x1102
#define GL_NONE                                                           0
#define GL_NOOP                                                           0x1505
#define GL_NOR                                                            0x1508
#define GL_NORMALIZE                                                      0x0BA1
#define GL_NORMAL_ARRAY                                                   0x8075
#define GL_NORMAL_ARRAY_BUFFER_BINDING                                    0x8897
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                                0x8897
#define GL_NORMAL_ARRAY_POINTER                                           0x808F
#define GL_NORMAL_ARRAY_STRIDE                                            0x807F
#define GL_NORMAL_ARRAY_TYPE                                              0x807E
#define GL_NORMAL_MAP                                                     0x8511
#define GL_NORMAL_MAP_ARB                                                 0x8511
#define GL_NORMAL_MAP_EXT                                                 0x8511
#define GL_NORMAL_MAP_NV                                                  0x8511
#define GL_NOTEQUAL                                                       0x0205
#define GL_NO_ERROR                                                       0
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                                 0x86A2
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB                             0x86A2
#define GL_NUM_FRAGMENT_CONSTANTS_ATI                                     0x896F
#define GL_NUM_FRAGMENT_REGISTERS_ATI                                     0x896E
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI                          0x8973
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI                                  0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI                                     0x8972
#define GL_NUM_LOOPBACK_COMPONENTS_ATI                                    0x8974
#define GL_NUM_PASSES_ATI                                                 0x8970
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                                   0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB                         0x8B8A
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                                     0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB                           0x8B87
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                                    0x8B85
#define GL_OBJECT_COMPILE_STATUS_ARB                                      0x8B81
#define GL_OBJECT_DELETE_STATUS_ARB                                       0x8B80
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                                     0x8B84
#define GL_OBJECT_LINEAR                                                  0x2401
#define GL_OBJECT_LINK_STATUS_ARB                                         0x8B82
#define GL_OBJECT_PLANE                                                   0x2501
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                                0x8B88
#define GL_OBJECT_SUBTYPE_ARB                                             0x8B4F
#define GL_OBJECT_TYPE_ARB                                                0x8B4E
#define GL_OBJECT_VALIDATE_STATUS_ARB                                     0x8B83
#define GL_ONE                                                            1
#define GL_ONE_MINUS_CONSTANT_ALPHA                                       0x8004
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT                                   0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR                                       0x8002
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT                                   0x8002
#define GL_ONE_MINUS_DST_ALPHA                                            0x0305
#define GL_ONE_MINUS_DST_COLOR                                            0x0307
#define GL_ONE_MINUS_SRC_ALPHA                                            0x0303
#define GL_ONE_MINUS_SRC_COLOR                                            0x0301
#define GL_OPERAND0_ALPHA                                                 0x8598
#define GL_OPERAND0_ALPHA_ARB                                             0x8598
#define GL_OPERAND0_ALPHA_EXT                                             0x8598
#define GL_OPERAND0_RGB                                                   0x8590
#define GL_OPERAND0_RGB_ARB                                               0x8590
#define GL_OPERAND0_RGB_EXT                                               0x8590
#define GL_OPERAND1_ALPHA                                                 0x8599
#define GL_OPERAND1_ALPHA_ARB                                             0x8599
#define GL_OPERAND1_ALPHA_EXT                                             0x8599
#define GL_OPERAND1_RGB                                                   0x8591
#define GL_OPERAND1_RGB_ARB                                               0x8591
#define GL_OPERAND1_RGB_EXT                                               0x8591
#define GL_OPERAND2_ALPHA                                                 0x859A
#define GL_OPERAND2_ALPHA_ARB                                             0x859A
#define GL_OPERAND2_ALPHA_EXT                                             0x859A
#define GL_OPERAND2_RGB                                                   0x8592
#define GL_OPERAND2_RGB_ARB                                               0x8592
#define GL_OPERAND2_RGB_EXT                                               0x8592
#define GL_OR                                                             0x1507
#define GL_ORDER                                                          0x0A01
#define GL_OR_INVERTED                                                    0x150D
#define GL_OR_REVERSE                                                     0x150B
#define GL_OUT_OF_MEMORY                                                  0x0505
#define GL_PACK_ALIGNMENT                                                 0x0D05
#define GL_PACK_IMAGE_HEIGHT                                              0x806C
#define GL_PACK_IMAGE_HEIGHT_EXT                                          0x806C
#define GL_PACK_LSB_FIRST                                                 0x0D01
#define GL_PACK_ROW_LENGTH                                                0x0D02
#define GL_PACK_SKIP_IMAGES                                               0x806B
#define GL_PACK_SKIP_IMAGES_EXT                                           0x806B
#define GL_PACK_SKIP_PIXELS                                               0x0D04
#define GL_PACK_SKIP_ROWS                                                 0x0D03
#define GL_PACK_SWAP_BYTES                                                0x0D00
#define GL_PASS_THROUGH_TOKEN                                             0x0700
#define GL_PERSPECTIVE_CORRECTION_HINT                                    0x0C50
#define GL_PIXEL_MAP_A_TO_A                                               0x0C79
#define GL_PIXEL_MAP_A_TO_A_SIZE                                          0x0CB9
#define GL_PIXEL_MAP_B_TO_B                                               0x0C78
#define GL_PIXEL_MAP_B_TO_B_SIZE                                          0x0CB8
#define GL_PIXEL_MAP_G_TO_G                                               0x0C77
#define GL_PIXEL_MAP_G_TO_G_SIZE                                          0x0CB7
#define GL_PIXEL_MAP_I_TO_A                                               0x0C75
#define GL_PIXEL_MAP_I_TO_A_SIZE                                          0x0CB5
#define GL_PIXEL_MAP_I_TO_B                                               0x0C74
#define GL_PIXEL_MAP_I_TO_B_SIZE                                          0x0CB4
#define GL_PIXEL_MAP_I_TO_G                                               0x0C73
#define GL_PIXEL_MAP_I_TO_G_SIZE                                          0x0CB3
#define GL_PIXEL_MAP_I_TO_I                                               0x0C70
#define GL_PIXEL_MAP_I_TO_I_SIZE                                          0x0CB0
#define GL_PIXEL_MAP_I_TO_R                                               0x0C72
#define GL_PIXEL_MAP_I_TO_R_SIZE                                          0x0CB2
#define GL_PIXEL_MAP_R_TO_R                                               0x0C76
#define GL_PIXEL_MAP_R_TO_R_SIZE                                          0x0CB6
#define GL_PIXEL_MAP_S_TO_S                                               0x0C71
#define GL_PIXEL_MAP_S_TO_S_SIZE                                          0x0CB1
#define GL_PIXEL_MODE_BIT                                                 0x00000020
#define GL_PIXEL_PACK_BUFFER                                              0x88EB
#define GL_PIXEL_PACK_BUFFER_ARB                                          0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING                                      0x88ED
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                                  0x88ED
#define GL_PIXEL_UNPACK_BUFFER                                            0x88EC
#define GL_PIXEL_UNPACK_BUFFER_ARB                                        0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING                                    0x88EF
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB                                0x88EF
#define GL_POINT                                                          0x1B00
#define GL_POINTS                                                         0x0000
#define GL_POINT_BIT                                                      0x00000002
#define GL_POINT_DISTANCE_ATTENUATION                                     0x8129
#define GL_POINT_DISTANCE_ATTENUATION_ARB                                 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE                                      0x8128
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB                                  0x8128
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT                                  0x8128
#define GL_POINT_SIZE                                                     0x0B11
#define GL_POINT_SIZE_GRANULARITY                                         0x0B13
#define GL_POINT_SIZE_MAX                                                 0x8127
#define GL_POINT_SIZE_MAX_ARB                                             0x8127
#define GL_POINT_SIZE_MAX_EXT                                             0x8127
#define GL_POINT_SIZE_MIN                                                 0x8126
#define GL_POINT_SIZE_MIN_ARB                                             0x8126
#define GL_POINT_SIZE_MIN_EXT                                             0x8126
#define GL_POINT_SIZE_RANGE                                               0x0B12
#define GL_POINT_SMOOTH                                                   0x0B10
#define GL_POINT_SMOOTH_HINT                                              0x0C51
#define GL_POINT_SPRITE                                                   0x8861
#define GL_POINT_SPRITE_ARB                                               0x8861
#define GL_POINT_SPRITE_COORD_ORIGIN                                      0x8CA0
#define GL_POINT_TOKEN                                                    0x0701
#define GL_POLYGON                                                        0x0009
#define GL_POLYGON_BIT                                                    0x00000008
#define GL_POLYGON_MODE                                                   0x0B40
#define GL_POLYGON_OFFSET_FACTOR                                          0x8038
#define GL_POLYGON_OFFSET_FILL                                            0x8037
#define GL_POLYGON_OFFSET_LINE                                            0x2A02
#define GL_POLYGON_OFFSET_POINT                                           0x2A01
#define GL_POLYGON_OFFSET_UNITS                                           0x2A00
#define GL_POLYGON_SMOOTH                                                 0x0B41
#define GL_POLYGON_SMOOTH_HINT                                            0x0C53
#define GL_POLYGON_STIPPLE                                                0x0B42
#define GL_POLYGON_STIPPLE_BIT                                            0x00000010
#define GL_POLYGON_TOKEN                                                  0x0703
#define GL_POSITION                                                       0x1203
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS                                   0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI                               0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE                                  0x80B7
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI                              0x80B7
#define GL_POST_COLOR_MATRIX_BLUE_BIAS                                    0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI                                0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_SCALE                                   0x80B6
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI                               0x80B6
#define GL_POST_COLOR_MATRIX_COLOR_TABLE                                  0x80D2
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI                              0x80D2
#define GL_POST_COLOR_MATRIX_GREEN_BIAS                                   0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI                               0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_SCALE                                  0x80B5
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI                              0x80B5
#define GL_POST_COLOR_MATRIX_RED_BIAS                                     0x80B8
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI                                 0x80B8
#define GL_POST_COLOR_MATRIX_RED_SCALE                                    0x80B4
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI                                0x80B4
#define GL_POST_CONVOLUTION_ALPHA_BIAS                                    0x8023
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT                                0x8023
#define GL_POST_CONVOLUTION_ALPHA_SCALE                                   0x801F
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT                               0x801F
#define GL_POST_CONVOLUTION_BLUE_BIAS                                     0x8022
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT                                 0x8022
#define GL_POST_CONVOLUTION_BLUE_SCALE                                    0x801E
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT                                0x801E
#define GL_POST_CONVOLUTION_COLOR_TABLE                                   0x80D1
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI                               0x80D1
#define GL_POST_CONVOLUTION_GREEN_BIAS                                    0x8021
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT                                0x8021
#define GL_POST_CONVOLUTION_GREEN_SCALE                                   0x801D
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT                               0x801D
#define GL_POST_CONVOLUTION_RED_BIAS                                      0x8020
#define GL_POST_CONVOLUTION_RED_BIAS_EXT                                  0x8020
#define GL_POST_CONVOLUTION_RED_SCALE                                     0x801C
#define GL_POST_CONVOLUTION_RED_SCALE_EXT                                 0x801C
#define GL_PREVIOUS                                                       0x8578
#define GL_PREVIOUS_ARB                                                   0x8578
#define GL_PREVIOUS_EXT                                                   0x8578
#define GL_PRIMARY_COLOR                                                  0x8577
#define GL_PRIMARY_COLOR_ARB                                              0x8577
#define GL_PRIMARY_COLOR_EXT                                              0x8577
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                                  0x88B0
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB                                   0x8805
#define GL_PROGRAM_ATTRIBS_ARB                                            0x88AC
#define GL_PROGRAM_BINDING_ARB                                            0x8677
#define GL_PROGRAM_ERROR_POSITION_ARB                                     0x864B
#define GL_PROGRAM_ERROR_STRING_ARB                                       0x8874
#define GL_PROGRAM_FORMAT_ARB                                             0x8876
#define GL_PROGRAM_FORMAT_ASCII_ARB                                       0x8875
#define GL_PROGRAM_INSTRUCTIONS_ARB                                       0x88A0
#define GL_PROGRAM_LENGTH_ARB                                             0x8627
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB                           0x88B2
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB                            0x8808
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                                     0x88AE
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                                0x88A2
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB                                  0x88AA
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB                                 0x88A6
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB                            0x880A
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB                            0x8809
#define GL_PROGRAM_OBJECT_ARB                                             0x8B40
#define GL_PROGRAM_PARAMETERS_ARB                                         0x88A8
#define GL_PROGRAM_STRING_ARB                                             0x8628
#define GL_PROGRAM_TEMPORARIES_ARB                                        0x88A4
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB                                   0x8807
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB                                   0x8806
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                                0x88B6
#define GL_PROJECTION                                                     0x1701
#define GL_PROJECTION_MATRIX                                              0x0BA7
#define GL_PROJECTION_STACK_DEPTH                                         0x0BA4
#define GL_PROXY_COLOR_TABLE                                              0x80D3
#define GL_PROXY_COLOR_TABLE_SGI                                          0x80D3
#define GL_PROXY_HISTOGRAM                                                0x8025
#define GL_PROXY_HISTOGRAM_EXT                                            0x8025
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE                            0x80D5
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI                        0x80D5
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE                             0x80D4
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI                         0x80D4
#define GL_PROXY_TEXTURE_1D                                               0x8063
#define GL_PROXY_TEXTURE_2D                                               0x8064
#define GL_PROXY_TEXTURE_3D                                               0x8070
#define GL_PROXY_TEXTURE_3D_EXT                                           0x8070
#define GL_PROXY_TEXTURE_CUBE_MAP                                         0x851B
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB                                     0x851B
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT                                     0x851B
#define GL_PROXY_TEXTURE_RECTANGLE_ARB                                    0x84F7
#define GL_Q                                                              0x2003
#define GL_QUADRATIC_ATTENUATION                                          0x1209
#define GL_QUADS                                                          0x0007
#define GL_QUAD_STRIP                                                     0x0008
#define GL_QUARTER_BIT_ATI                                                0x00000010
#define GL_QUERY_COUNTER_BITS                                             0x8864
#define GL_QUERY_COUNTER_BITS_ARB                                         0x8864
#define GL_QUERY_RESULT                                                   0x8866
#define GL_QUERY_RESULT_ARB                                               0x8866
#define GL_QUERY_RESULT_AVAILABLE                                         0x8867
#define GL_QUERY_RESULT_AVAILABLE_ARB                                     0x8867
#define GL_R                                                              0x2002
#define GL_R11F_G11F_B10F_EXT                                             0x8C3A
#define GL_R16                                                            0x822A
#define GL_R16F                                                           0x822D
#define GL_R16I                                                           0x8233
#define GL_R16UI                                                          0x8234
#define GL_R16_SNORM                                                      0x8F98
#define GL_R32F                                                           0x822E
#define GL_R32I                                                           0x8235
#define GL_R32UI                                                          0x8236
#define GL_R3_G3_B2                                                       0x2A10
#define GL_R8                                                             0x8229
#define GL_R8I                                                            0x8231
#define GL_R8UI                                                           0x8232
#define GL_R8_SNORM                                                       0x8F94
#define GL_READ_BUFFER                                                    0x0C02
#define GL_READ_FRAMEBUFFER                                               0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING                                       0x8CAA
#define GL_READ_ONLY                                                      0x88B8
#define GL_READ_ONLY_ARB                                                  0x88B8
#define GL_READ_WRITE                                                     0x88BA
#define GL_READ_WRITE_ARB                                                 0x88BA
#define GL_RED                                                            0x1903
#define GL_REDUCE                                                         0x8016
#define GL_REDUCE_EXT                                                     0x8016
#define GL_RED_BIAS                                                       0x0D15
#define GL_RED_BITS                                                       0x0D52
#define GL_RED_BIT_ATI                                                    0x00000001
#define GL_RED_INTEGER_EXT                                                0x8D94
#define GL_RED_SCALE                                                      0x0D14
#define GL_RED_SNORM                                                      0x8F90
#define GL_REFLECTION_MAP                                                 0x8512
#define GL_REFLECTION_MAP_ARB                                             0x8512
#define GL_REFLECTION_MAP_EXT                                             0x8512
#define GL_REFLECTION_MAP_NV                                              0x8512
#define GL_REG_0_ATI                                                      0x8921
#define GL_REG_10_ATI                                                     0x892B
#define GL_REG_11_ATI                                                     0x892C
#define GL_REG_12_ATI                                                     0x892D
#define GL_REG_13_ATI                                                     0x892E
#define GL_REG_14_ATI                                                     0x892F
#define GL_REG_15_ATI                                                     0x8930
#define GL_REG_16_ATI                                                     0x8931
#define GL_REG_17_ATI                                                     0x8932
#define GL_REG_18_ATI                                                     0x8933
#define GL_REG_19_ATI                                                     0x8934
#define GL_REG_1_ATI                                                      0x8922
#define GL_REG_20_ATI                                                     0x8935
#define GL_REG_21_ATI                                                     0x8936
#define GL_REG_22_ATI                                                     0x8937
#define GL_REG_23_ATI                                                     0x8938
#define GL_REG_24_ATI                                                     0x8939
#define GL_REG_25_ATI                                                     0x893A
#define GL_REG_26_ATI                                                     0x893B
#define GL_REG_27_ATI                                                     0x893C
#define GL_REG_28_ATI                                                     0x893D
#define GL_REG_29_ATI                                                     0x893E
#define GL_REG_2_ATI                                                      0x8923
#define GL_REG_30_ATI                                                     0x893F
#define GL_REG_31_ATI                                                     0x8940
#define GL_REG_3_ATI                                                      0x8924
#define GL_REG_4_ATI                                                      0x8925
#define GL_REG_5_ATI                                                      0x8926
#define GL_REG_6_ATI                                                      0x8927
#define GL_REG_7_ATI                                                      0x8928
#define GL_REG_8_ATI                                                      0x8929
#define GL_REG_9_ATI                                                      0x892A
#define GL_RENDER                                                         0x1C00
#define GL_RENDERBUFFER                                                   0x8D41
#define GL_RENDERBUFFER_ALPHA_SIZE                                        0x8D53
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                                    0x8D53
#define GL_RENDERBUFFER_BINDING                                           0x8CA7
#define GL_RENDERBUFFER_BINDING_EXT                                       0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE                                         0x8D52
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                                     0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE                                        0x8D54
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                                    0x8D54
#define GL_RENDERBUFFER_EXT                                               0x8D41
#define GL_RENDERBUFFER_GREEN_SIZE                                        0x8D51
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                                    0x8D51
#define GL_RENDERBUFFER_HEIGHT                                            0x8D43
#define GL_RENDERBUFFER_HEIGHT_EXT                                        0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                                   0x8D44
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                               0x8D44
#define GL_RENDERBUFFER_RED_SIZE                                          0x8D50
#define GL_RENDERBUFFER_RED_SIZE_EXT                                      0x8D50
#define GL_RENDERBUFFER_SAMPLES                                           0x8CAB
#define GL_RENDERBUFFER_STENCIL_SIZE                                      0x8D55
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                                  0x8D55
#define GL_RENDERBUFFER_WIDTH                                             0x8D42
#define GL_RENDERBUFFER_WIDTH_EXT                                         0x8D42
#define GL_RENDERER                                                       0x1F01
#define GL_RENDER_MODE                                                    0x0C40
#define GL_REPEAT                                                         0x2901
#define GL_REPLACE                                                        0x1E01
#define GL_REPLICATE_BORDER                                               0x8153
#define GL_REPLICATE_BORDER_HP                                            0x8153
#define GL_RESCALE_NORMAL                                                 0x803A
#define GL_RESCALE_NORMAL_EXT                                             0x803A
#define GL_RETURN                                                         0x0102
#define GL_RG                                                             0x8227
#define GL_RG16                                                           0x822C
#define GL_RG16F                                                          0x822F
#define GL_RG16I                                                          0x8239
#define GL_RG16UI                                                         0x823A
#define GL_RG16_SNORM                                                     0x8F99
#define GL_RG32F                                                          0x8230
#define GL_RG32I                                                          0x823B
#define GL_RG32UI                                                         0x823C
#define GL_RG8                                                            0x822B
#define GL_RG8I                                                           0x8237
#define GL_RG8UI                                                          0x8238
#define GL_RG8_SNORM                                                      0x8F95
#define GL_RGB                                                            0x1907
#define GL_RGB10                                                          0x8052
#define GL_RGB10_A2                                                       0x8059
#define GL_RGB10_A2UI                                                     0x906F
#define GL_RGB12                                                          0x8053
#define GL_RGB16                                                          0x8054
#define GL_RGB16F_ARB                                                     0x881B
#define GL_RGB16I_EXT                                                     0x8D89
#define GL_RGB16UI_EXT                                                    0x8D77
#define GL_RGB16_SNORM                                                    0x8F9A
#define GL_RGB32F_ARB                                                     0x8815
#define GL_RGB32I_EXT                                                     0x8D83
#define GL_RGB32UI_EXT                                                    0x8D71
#define GL_RGB4                                                           0x804F
#define GL_RGB4_S3TC                                                      0x83A1
#define GL_RGB5                                                           0x8050
#define GL_RGB5_A1                                                        0x8057
#define GL_RGB8                                                           0x8051
#define GL_RGB8I_EXT                                                      0x8D8F
#define GL_RGB8UI_EXT                                                     0x8D7D
#define GL_RGB8_SNORM                                                     0x8F96
#define GL_RGB9_E5_EXT                                                    0x8C3D
#define GL_RGBA                                                           0x1908
#define GL_RGBA12                                                         0x805A
#define GL_RGBA16                                                         0x805B
#define GL_RGBA16F_ARB                                                    0x881A
#define GL_RGBA16I_EXT                                                    0x8D88
#define GL_RGBA16UI_EXT                                                   0x8D76
#define GL_RGBA16_SNORM                                                   0x8F9B
#define GL_RGBA2                                                          0x8055
#define GL_RGBA32F_ARB                                                    0x8814
#define GL_RGBA32I_EXT                                                    0x8D82
#define GL_RGBA32UI_EXT                                                   0x8D70
#define GL_RGBA4                                                          0x8056
#define GL_RGBA4_DXT5_S3TC                                                0x83A5
#define GL_RGBA4_S3TC                                                     0x83A3
#define GL_RGBA8                                                          0x8058
#define GL_RGBA8I_EXT                                                     0x8D8E
#define GL_RGBA8UI_EXT                                                    0x8D7C
#define GL_RGBA8_SNORM                                                    0x8F97
#define GL_RGBA_DXT5_S3TC                                                 0x83A4
#define GL_RGBA_FLOAT_MODE_ARB                                            0x8820
#define GL_RGBA_INTEGER_EXT                                               0x8D99
#define GL_RGBA_INTEGER_MODE_EXT                                          0x8D9E
#define GL_RGBA_MODE                                                      0x0C31
#define GL_RGBA_S3TC                                                      0x83A2
#define GL_RGBA_SIGNED_COMPONENTS_EXT                                     0x8C3C
#define GL_RGBA_SNORM                                                     0x8F93
#define GL_RGB_INTEGER_EXT                                                0x8D98
#define GL_RGB_S3TC                                                       0x83A0
#define GL_RGB_SCALE                                                      0x8573
#define GL_RGB_SCALE_ARB                                                  0x8573
#define GL_RGB_SCALE_EXT                                                  0x8573
#define GL_RGB_SNORM                                                      0x8F92
#define GL_RG_INTEGER                                                     0x8228
#define GL_RG_SNORM                                                       0x8F91
#define GL_RIGHT                                                          0x0407
#define GL_S                                                              0x2000
#define GL_SAMPLER_1D                                                     0x8B5D
#define GL_SAMPLER_1D_ARB                                                 0x8B5D
#define GL_SAMPLER_1D_SHADOW                                              0x8B61
#define GL_SAMPLER_1D_SHADOW_ARB                                          0x8B61
#define GL_SAMPLER_2D                                                     0x8B5E
#define GL_SAMPLER_2D_ARB                                                 0x8B5E
#define GL_SAMPLER_2D_RECT_ARB                                            0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB                                     0x8B64
#define GL_SAMPLER_2D_SHADOW                                              0x8B62
#define GL_SAMPLER_2D_SHADOW_ARB                                          0x8B62
#define GL_SAMPLER_3D                                                     0x8B5F
#define GL_SAMPLER_3D_ARB                                                 0x8B5F
#define GL_SAMPLER_CUBE                                                   0x8B60
#define GL_SAMPLER_CUBE_ARB                                               0x8B60
#define GL_SAMPLES                                                        0x80A9
#define GL_SAMPLES_ARB                                                    0x80A9
#define GL_SAMPLES_PASSED                                                 0x8914
#define GL_SAMPLES_PASSED_ARB                                             0x8914
#define GL_SAMPLE_ALPHA_TO_COVERAGE                                       0x809E
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                                   0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                                            0x809F
#define GL_SAMPLE_ALPHA_TO_ONE_ARB                                        0x809F
#define GL_SAMPLE_BUFFERS                                                 0x80A8
#define GL_SAMPLE_BUFFERS_ARB                                             0x80A8
#define GL_SAMPLE_COVERAGE                                                0x80A0
#define GL_SAMPLE_COVERAGE_ARB                                            0x80A0
#define GL_SAMPLE_COVERAGE_INVERT                                         0x80AB
#define GL_SAMPLE_COVERAGE_INVERT_ARB                                     0x80AB
#define GL_SAMPLE_COVERAGE_VALUE                                          0x80AA
#define GL_SAMPLE_COVERAGE_VALUE_ARB                                      0x80AA
#define GL_SATURATE_BIT_ATI                                               0x00000040
#define GL_SCISSOR_BIT                                                    0x00080000
#define GL_SCISSOR_BOX                                                    0x0C10
#define GL_SCISSOR_TEST                                                   0x0C11
#define GL_SECONDARY_COLOR_ARRAY                                          0x845E
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING                           0x889C
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB                       0x889C
#define GL_SECONDARY_COLOR_ARRAY_EXT                                      0x845E
#define GL_SECONDARY_COLOR_ARRAY_POINTER                                  0x845D
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT                              0x845D
#define GL_SECONDARY_COLOR_ARRAY_SIZE                                     0x845A
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT                                 0x845A
#define GL_SECONDARY_COLOR_ARRAY_STRIDE                                   0x845C
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT                               0x845C
#define GL_SECONDARY_COLOR_ARRAY_TYPE                                     0x845B
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT                                 0x845B
#define GL_SECONDARY_INTERPOLATOR_ATI                                     0x896D
#define GL_SELECT                                                         0x1C02
#define GL_SELECTION_BUFFER_POINTER                                       0x0DF3
#define GL_SELECTION_BUFFER_SIZE                                          0x0DF4
#define GL_SEPARABLE_2D                                                   0x8012
#define GL_SEPARABLE_2D_EXT                                               0x8012
#define GL_SEPARATE_SPECULAR_COLOR                                        0x81FA
#define GL_SEPARATE_SPECULAR_COLOR_EXT                                    0x81FA
#define GL_SET                                                            0x150F
#define GL_SHADER_OBJECT_ARB                                              0x8B48
#define GL_SHADER_SOURCE_LENGTH                                           0x8B88
#define GL_SHADER_TYPE                                                    0x8B4F
#define GL_SHADE_MODEL                                                    0x0B54
#define GL_SHADING_LANGUAGE_VERSION                                       0x8B8C
#define GL_SHADING_LANGUAGE_VERSION_ARB                                   0x8B8C
#define GL_SHARED_TEXTURE_PALETTE_EXT                                     0x81FB
#define GL_SHININESS                                                      0x1601
#define GL_SHORT                                                          0x1402
#define GL_SIGNED_NORMALIZED                                              0x8F9C
#define GL_SINGLE_COLOR                                                   0x81F9
#define GL_SINGLE_COLOR_EXT                                               0x81F9
#define GL_SLUMINANCE                                                     0x8C46
#define GL_SLUMINANCE8                                                    0x8C47
#define GL_SLUMINANCE8_ALPHA8                                             0x8C45
#define GL_SLUMINANCE8_ALPHA8_EXT                                         0x8C45
#define GL_SLUMINANCE8_EXT                                                0x8C47
#define GL_SLUMINANCE_ALPHA                                               0x8C44
#define GL_SLUMINANCE_ALPHA_EXT                                           0x8C44
#define GL_SLUMINANCE_EXT                                                 0x8C46
#define GL_SMOOTH                                                         0x1D01
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY                                  0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE                                        0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY                                  0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE                                        0x0B12
#define GL_SOURCE0_ALPHA                                                  0x8588
#define GL_SOURCE0_ALPHA_ARB                                              0x8588
#define GL_SOURCE0_ALPHA_EXT                                              0x8588
#define GL_SOURCE0_RGB                                                    0x8580
#define GL_SOURCE0_RGB_ARB                                                0x8580
#define GL_SOURCE0_RGB_EXT                                                0x8580
#define GL_SOURCE1_ALPHA                                                  0x8589
#define GL_SOURCE1_ALPHA_ARB                                              0x8589
#define GL_SOURCE1_ALPHA_EXT                                              0x8589
#define GL_SOURCE1_RGB                                                    0x8581
#define GL_SOURCE1_RGB_ARB                                                0x8581
#define GL_SOURCE1_RGB_EXT                                                0x8581
#define GL_SOURCE2_ALPHA                                                  0x858A
#define GL_SOURCE2_ALPHA_ARB                                              0x858A
#define GL_SOURCE2_ALPHA_EXT                                              0x858A
#define GL_SOURCE2_RGB                                                    0x8582
#define GL_SOURCE2_RGB_ARB                                                0x8582
#define GL_SOURCE2_RGB_EXT                                                0x8582
#define GL_SPECULAR                                                       0x1202
#define GL_SPHERE_MAP                                                     0x2402
#define GL_SPOT_CUTOFF                                                    0x1206
#define GL_SPOT_DIRECTION                                                 0x1204
#define GL_SPOT_EXPONENT                                                  0x1205
#define GL_SRC0_ALPHA                                                     0x8588
#define GL_SRC0_RGB                                                       0x8580
#define GL_SRC1_ALPHA                                                     0x8589
#define GL_SRC1_RGB                                                       0x8581
#define GL_SRC2_ALPHA                                                     0x858A
#define GL_SRC2_RGB                                                       0x8582
#define GL_SRC_ALPHA                                                      0x0302
#define GL_SRC_ALPHA_SATURATE                                             0x0308
#define GL_SRC_COLOR                                                      0x0300
#define GL_SRGB                                                           0x8C40
#define GL_SRGB8                                                          0x8C41
#define GL_SRGB8_ALPHA8                                                   0x8C43
#define GL_SRGB8_ALPHA8_EXT                                               0x8C43
#define GL_SRGB8_EXT                                                      0x8C41
#define GL_SRGB_ALPHA                                                     0x8C42
#define GL_SRGB_ALPHA_EXT                                                 0x8C42
#define GL_SRGB_EXT                                                       0x8C40
#define GL_STACK_OVERFLOW                                                 0x0503
#define GL_STACK_UNDERFLOW                                                0x0504
#define GL_STATIC_COPY                                                    0x88E6
#define GL_STATIC_COPY_ARB                                                0x88E6
#define GL_STATIC_DRAW                                                    0x88E4
#define GL_STATIC_DRAW_ARB                                                0x88E4
#define GL_STATIC_READ                                                    0x88E5
#define GL_STATIC_READ_ARB                                                0x88E5
#define GL_STENCIL                                                        0x1802
#define GL_STENCIL_ATTACHMENT                                             0x8D20
#define GL_STENCIL_ATTACHMENT_EXT                                         0x8D20
#define GL_STENCIL_BACK_FAIL                                              0x8801
#define GL_STENCIL_BACK_FAIL_ATI                                          0x8801
#define GL_STENCIL_BACK_FUNC                                              0x8800
#define GL_STENCIL_BACK_FUNC_ATI                                          0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                                   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI                               0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                                   0x8803
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI                               0x8803
#define GL_STENCIL_BACK_REF                                               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                                        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                                         0x8CA5
#define GL_STENCIL_BITS                                                   0x0D57
#define GL_STENCIL_BUFFER_BIT                                             0x00000400
#define GL_STENCIL_CLEAR_VALUE                                            0x0B91
#define GL_STENCIL_FAIL                                                   0x0B94
#define GL_STENCIL_FUNC                                                   0x0B92
#define GL_STENCIL_INDEX                                                  0x1901
#define GL_STENCIL_INDEX1                                                 0x8D46
#define GL_STENCIL_INDEX16                                                0x8D49
#define GL_STENCIL_INDEX16_EXT                                            0x8D49
#define GL_STENCIL_INDEX1_EXT                                             0x8D46
#define GL_STENCIL_INDEX4                                                 0x8D47
#define GL_STENCIL_INDEX4_EXT                                             0x8D47
#define GL_STENCIL_INDEX8                                                 0x8D48
#define GL_STENCIL_INDEX8_EXT                                             0x8D48
#define GL_STENCIL_PASS_DEPTH_FAIL                                        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS                                        0x0B96
#define GL_STENCIL_REF                                                    0x0B97
#define GL_STENCIL_TEST                                                   0x0B90
#define GL_STENCIL_TEST_TWO_SIDE_EXT                                      0x8910
#define GL_STENCIL_VALUE_MASK                                             0x0B93
#define GL_STENCIL_WRITEMASK                                              0x0B98
#define GL_STEREO                                                         0x0C33
#define GL_STREAM_COPY                                                    0x88E2
#define GL_STREAM_COPY_ARB                                                0x88E2
#define GL_STREAM_DRAW                                                    0x88E0
#define GL_STREAM_DRAW_ARB                                                0x88E0
#define GL_STREAM_READ                                                    0x88E1
#define GL_STREAM_READ_ARB                                                0x88E1
#define GL_SUBPIXEL_BITS                                                  0x0D50
#define GL_SUBTRACT                                                       0x84E7
#define GL_SUBTRACT_ARB                                                   0x84E7
#define GL_SUB_ATI                                                        0x8965
#define GL_SWIZZLE_STQ_ATI                                                0x8977
#define GL_SWIZZLE_STQ_DQ_ATI                                             0x8979
#define GL_SWIZZLE_STRQ_ATI                                               0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                                            0x897B
#define GL_SWIZZLE_STR_ATI                                                0x8976
#define GL_SWIZZLE_STR_DR_ATI                                             0x8978
#define GL_T                                                              0x2001
#define GL_T2F_C3F_V3F                                                    0x2A2A
#define GL_T2F_C4F_N3F_V3F                                                0x2A2C
#define GL_T2F_C4UB_V3F                                                   0x2A29
#define GL_T2F_N3F_V3F                                                    0x2A2B
#define GL_T2F_V3F                                                        0x2A27
#define GL_T4F_C4F_N3F_V4F                                                0x2A2D
#define GL_T4F_V4F                                                        0x2A28
#define GL_TABLE_TOO_LARGE                                                0x8031
#define GL_TABLE_TOO_LARGE_EXT                                            0x8031
#define GL_TEXTURE                                                        0x1702
#define GL_TEXTURE0                                                       0x84C0
#define GL_TEXTURE0_ARB                                                   0x84C0
#define GL_TEXTURE1                                                       0x84C1
#define GL_TEXTURE10                                                      0x84CA
#define GL_TEXTURE10_ARB                                                  0x84CA
#define GL_TEXTURE11                                                      0x84CB
#define GL_TEXTURE11_ARB                                                  0x84CB
#define GL_TEXTURE12                                                      0x84CC
#define GL_TEXTURE12_ARB                                                  0x84CC
#define GL_TEXTURE13                                                      0x84CD
#define GL_TEXTURE13_ARB                                                  0x84CD
#define GL_TEXTURE14                                                      0x84CE
#define GL_TEXTURE14_ARB                                                  0x84CE
#define GL_TEXTURE15                                                      0x84CF
#define GL_TEXTURE15_ARB                                                  0x84CF
#define GL_TEXTURE16                                                      0x84D0
#define GL_TEXTURE16_ARB                                                  0x84D0
#define GL_TEXTURE17                                                      0x84D1
#define GL_TEXTURE17_ARB                                                  0x84D1
#define GL_TEXTURE18                                                      0x84D2
#define GL_TEXTURE18_ARB                                                  0x84D2
#define GL_TEXTURE19                                                      0x84D3
#define GL_TEXTURE19_ARB                                                  0x84D3
#define GL_TEXTURE1_ARB                                                   0x84C1
#define GL_TEXTURE2                                                       0x84C2
#define GL_TEXTURE20                                                      0x84D4
#define GL_TEXTURE20_ARB                                                  0x84D4
#define GL_TEXTURE21                                                      0x84D5
#define GL_TEXTURE21_ARB                                                  0x84D5
#define GL_TEXTURE22                                                      0x84D6
#define GL_TEXTURE22_ARB                                                  0x84D6
#define GL_TEXTURE23                                                      0x84D7
#define GL_TEXTURE23_ARB                                                  0x84D7
#define GL_TEXTURE24                                                      0x84D8
#define GL_TEXTURE24_ARB                                                  0x84D8
#define GL_TEXTURE25                                                      0x84D9
#define GL_TEXTURE25_ARB                                                  0x84D9
#define GL_TEXTURE26                                                      0x84DA
#define GL_TEXTURE26_ARB                                                  0x84DA
#define GL_TEXTURE27                                                      0x84DB
#define GL_TEXTURE27_ARB                                                  0x84DB
#define GL_TEXTURE28                                                      0x84DC
#define GL_TEXTURE28_ARB                                                  0x84DC
#define GL_TEXTURE29                                                      0x84DD
#define GL_TEXTURE29_ARB                                                  0x84DD
#define GL_TEXTURE2_ARB                                                   0x84C2
#define GL_TEXTURE3                                                       0x84C3
#define GL_TEXTURE30                                                      0x84DE
#define GL_TEXTURE30_ARB                                                  0x84DE
#define GL_TEXTURE31                                                      0x84DF
#define GL_TEXTURE31_ARB                                                  0x84DF
#define GL_TEXTURE3_ARB                                                   0x84C3
#define GL_TEXTURE4                                                       0x84C4
#define GL_TEXTURE4_ARB                                                   0x84C4
#define GL_TEXTURE5                                                       0x84C5
#define GL_TEXTURE5_ARB                                                   0x84C5
#define GL_TEXTURE6                                                       0x84C6
#define GL_TEXTURE6_ARB                                                   0x84C6
#define GL_TEXTURE7                                                       0x84C7
#define GL_TEXTURE7_ARB                                                   0x84C7
#define GL_TEXTURE8                                                       0x84C8
#define GL_TEXTURE8_ARB                                                   0x84C8
#define GL_TEXTURE9                                                       0x84C9
#define GL_TEXTURE9_ARB                                                   0x84C9
#define GL_TEXTURE_1D                                                     0x0DE0
#define GL_TEXTURE_2D                                                     0x0DE1
#define GL_TEXTURE_3D                                                     0x806F
#define GL_TEXTURE_3D_EXT                                                 0x806F
#define GL_TEXTURE_ALPHA_SIZE                                             0x805F
#define GL_TEXTURE_ALPHA_TYPE_ARB                                         0x8C13
#define GL_TEXTURE_BASE_LEVEL                                             0x813C
#define GL_TEXTURE_BASE_LEVEL_SGIS                                        0x813C
#define GL_TEXTURE_BINDING_1D                                             0x8068
#define GL_TEXTURE_BINDING_2D                                             0x8069
#define GL_TEXTURE_BINDING_3D                                             0x806A
#define GL_TEXTURE_BINDING_CUBE_MAP                                       0x8514
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB                                   0x8514
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT                                   0x8514
#define GL_TEXTURE_BINDING_RECTANGLE_ARB                                  0x84F6
#define GL_TEXTURE_BIT                                                    0x00040000
#define GL_TEXTURE_BLUE_SIZE                                              0x805E
#define GL_TEXTURE_BLUE_TYPE_ARB                                          0x8C12
#define GL_TEXTURE_BORDER                                                 0x1005
#define GL_TEXTURE_BORDER_COLOR                                           0x1004
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                                 0x80BF
#define GL_TEXTURE_COMPARE_FUNC                                           0x884D
#define GL_TEXTURE_COMPARE_FUNC_ARB                                       0x884D
#define GL_TEXTURE_COMPARE_MODE                                           0x884C
#define GL_TEXTURE_COMPARE_MODE_ARB                                       0x884C
#define GL_TEXTURE_COMPONENTS                                             0x1003
#define GL_TEXTURE_COMPRESSED                                             0x86A1
#define GL_TEXTURE_COMPRESSED_ARB                                         0x86A1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                                  0x86A0
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB                              0x86A0
#define GL_TEXTURE_COMPRESSION_HINT                                       0x84EF
#define GL_TEXTURE_COMPRESSION_HINT_ARB                                   0x84EF
#define GL_TEXTURE_COORD_ARRAY                                            0x8078
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING                             0x889A
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB                         0x889A
#define GL_TEXTURE_COORD_ARRAY_POINTER                                    0x8092
#define GL_TEXTURE_COORD_ARRAY_SIZE                                       0x8088
#define GL_TEXTURE_COORD_ARRAY_STRIDE                                     0x808A
#define GL_TEXTURE_COORD_ARRAY_TYPE                                       0x8089
#define GL_TEXTURE_CUBE_MAP                                               0x8513
#define GL_TEXTURE_CUBE_MAP_ARB                                           0x8513
#define GL_TEXTURE_CUBE_MAP_EXT                                           0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                                    0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                                0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT                                0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                                    0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                                0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT                                0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                                    0x851A
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                                0x851A
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT                                0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                                    0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                                0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT                                0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                                    0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                                0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT                                0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                                    0x8519
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                                0x8519
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT                                0x8519
#define GL_TEXTURE_DEPTH                                                  0x8071
#define GL_TEXTURE_DEPTH_EXT                                              0x8071
#define GL_TEXTURE_DEPTH_SIZE                                             0x884A
#define GL_TEXTURE_DEPTH_SIZE_ARB                                         0x884A
#define GL_TEXTURE_DEPTH_TYPE_ARB                                         0x8C16
#define GL_TEXTURE_ENV                                                    0x2300
#define GL_TEXTURE_ENV_COLOR                                              0x2201
#define GL_TEXTURE_ENV_MODE                                               0x2200
#define GL_TEXTURE_FILTER_CONTROL                                         0x8500
#define GL_TEXTURE_FILTER_CONTROL_EXT                                     0x8500
#define GL_TEXTURE_GEN_MODE                                               0x2500
#define GL_TEXTURE_GEN_Q                                                  0x0C63
#define GL_TEXTURE_GEN_R                                                  0x0C62
#define GL_TEXTURE_GEN_S                                                  0x0C60
#define GL_TEXTURE_GEN_T                                                  0x0C61
#define GL_TEXTURE_GREEN_SIZE                                             0x805D
#define GL_TEXTURE_GREEN_TYPE_ARB                                         0x8C11
#define GL_TEXTURE_HEIGHT                                                 0x1001
#define GL_TEXTURE_INDEX_SIZE_EXT                                         0x80ED
#define GL_TEXTURE_INTENSITY_SIZE                                         0x8061
#define GL_TEXTURE_INTENSITY_TYPE_ARB                                     0x8C15
#define GL_TEXTURE_INTERNAL_FORMAT                                        0x1003
#define GL_TEXTURE_LOD_BIAS                                               0x8501
#define GL_TEXTURE_LOD_BIAS_EXT                                           0x8501
#define GL_TEXTURE_LUMINANCE_SIZE                                         0x8060
#define GL_TEXTURE_LUMINANCE_TYPE_ARB                                     0x8C14
#define GL_TEXTURE_MAG_FILTER                                             0x2800
#define GL_TEXTURE_MATRIX                                                 0x0BA8
#define GL_TEXTURE_MAX_ANISOTROPY_EXT                                     0x84FE
#define GL_TEXTURE_MAX_LEVEL                                              0x813D
#define GL_TEXTURE_MAX_LEVEL_SGIS                                         0x813D
#define GL_TEXTURE_MAX_LOD                                                0x813B
#define GL_TEXTURE_MAX_LOD_SGIS                                           0x813B
#define GL_TEXTURE_MIN_FILTER                                             0x2801
#define GL_TEXTURE_MIN_LOD                                                0x813A
#define GL_TEXTURE_MIN_LOD_SGIS                                           0x813A
#define GL_TEXTURE_PRIORITY                                               0x8066
#define GL_TEXTURE_RECTANGLE_ARB                                          0x84F5
#define GL_TEXTURE_RED_SIZE                                               0x805C
#define GL_TEXTURE_RED_TYPE_ARB                                           0x8C10
#define GL_TEXTURE_RESIDENT                                               0x8067
#define GL_TEXTURE_SHARED_SIZE_EXT                                        0x8C3F
#define GL_TEXTURE_STACK_DEPTH                                            0x0BA5
#define GL_TEXTURE_STENCIL_SIZE                                           0x88F1
#define GL_TEXTURE_WIDTH                                                  0x1000
#define GL_TEXTURE_WRAP_R                                                 0x8072
#define GL_TEXTURE_WRAP_R_EXT                                             0x8072
#define GL_TEXTURE_WRAP_S                                                 0x2802
#define GL_TEXTURE_WRAP_T                                                 0x2803
#define GL_TRANSFORM_BIT                                                  0x00001000
#define GL_TRANSPOSE_COLOR_MATRIX                                         0x84E6
#define GL_TRANSPOSE_COLOR_MATRIX_ARB                                     0x84E6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB                                   0x88B7
#define GL_TRANSPOSE_MODELVIEW_MATRIX                                     0x84E3
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                                 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX                                    0x84E4
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB                                0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX                                       0x84E5
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB                                   0x84E5
#define GL_TRIANGLES                                                      0x0004
#define GL_TRIANGLE_FAN                                                   0x0006
#define GL_TRIANGLE_STRIP                                                 0x0005
#define GL_TRUE                                                           1
#define GL_UNPACK_ALIGNMENT                                               0x0CF5
#define GL_UNPACK_IMAGE_HEIGHT                                            0x806E
#define GL_UNPACK_IMAGE_HEIGHT_EXT                                        0x806E
#define GL_UNPACK_LSB_FIRST                                               0x0CF1
#define GL_UNPACK_ROW_LENGTH                                              0x0CF2
#define GL_UNPACK_SKIP_IMAGES                                             0x806D
#define GL_UNPACK_SKIP_IMAGES_EXT                                         0x806D
#define GL_UNPACK_SKIP_PIXELS                                             0x0CF4
#define GL_UNPACK_SKIP_ROWS                                               0x0CF3
#define GL_UNPACK_SWAP_BYTES                                              0x0CF0
#define GL_UNSIGNED_BYTE                                                  0x1401
#define GL_UNSIGNED_BYTE_2_3_3_REV                                        0x8362
#define GL_UNSIGNED_BYTE_3_3_2                                            0x8032
#define GL_UNSIGNED_BYTE_3_3_2_EXT                                        0x8032
#define GL_UNSIGNED_INT                                                   0x1405
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT                               0x8C3B
#define GL_UNSIGNED_INT_10_10_10_2                                        0x8036
#define GL_UNSIGNED_INT_10_10_10_2_EXT                                    0x8036
#define GL_UNSIGNED_INT_24_8                                              0x84FA
#define GL_UNSIGNED_INT_2_10_10_10_REV                                    0x8368
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT                                   0x8C3E
#define GL_UNSIGNED_INT_8_8_8_8                                           0x8035
#define GL_UNSIGNED_INT_8_8_8_8_EXT                                       0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV                                       0x8367
#define GL_UNSIGNED_NORMALIZED                                            0x8C17
#define GL_UNSIGNED_NORMALIZED_ARB                                        0x8C17
#define GL_UNSIGNED_SHORT                                                 0x1403
#define GL_UNSIGNED_SHORT_1_5_5_5_REV                                     0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4                                         0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT                                     0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV                                     0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1                                         0x8034
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT                                     0x8034
#define GL_UNSIGNED_SHORT_5_6_5                                           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV                                       0x8364
#define GL_UNSIGNED_SHORT_8_8_MESA                                        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA                                    0x85BB
#define GL_UPPER_LEFT                                                     0x8CA2
#define GL_V2F                                                            0x2A20
#define GL_V3F                                                            0x2A21
#define GL_VALIDATE_STATUS                                                0x8B83
#define GL_VENDOR                                                         0x1F00
#define GL_VERSION                                                        0x1F02
#define GL_VERTEX_ARRAY                                                   0x8074
#define GL_VERTEX_ARRAY_BUFFER_BINDING                                    0x8896
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                                0x8896
#define GL_VERTEX_ARRAY_POINTER                                           0x808E
#define GL_VERTEX_ARRAY_SIZE                                              0x807A
#define GL_VERTEX_ARRAY_STRIDE                                            0x807C
#define GL_VERTEX_ARRAY_TYPE                                              0x807B
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING                             0x889F
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB                         0x889F
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                                    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                                0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                                 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB                             0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                                    0x8645
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                                0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                                       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                                   0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                                     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                                 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                                       0x8625
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                                   0x8625
#define GL_VERTEX_BLEND_ARB                                               0x86A7
#define GL_VERTEX_PROGRAM_ARB                                             0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE                                      0x8642
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                                  0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE                                        0x8643
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                                    0x8643
#define GL_VERTEX_SHADER                                                  0x8B31
#define GL_VERTEX_SHADER_ARB                                              0x8B31
#define GL_VIEWPORT                                                       0x0BA2
#define GL_VIEWPORT_BIT                                                   0x00000800
#define GL_WEIGHT_ARRAY_ARB                                               0x86AD
#define GL_WEIGHT_ARRAY_BUFFER_BINDING                                    0x889E
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                                0x889E
#define GL_WEIGHT_ARRAY_POINTER_ARB                                       0x86AC
#define GL_WEIGHT_ARRAY_SIZE_ARB                                          0x86AB
#define GL_WEIGHT_ARRAY_STRIDE_ARB                                        0x86AA
#define GL_WEIGHT_ARRAY_TYPE_ARB                                          0x86A9
#define GL_WEIGHT_SUM_UNITY_ARB                                           0x86A6
#define GL_WRITE_ONLY                                                     0x88B9
#define GL_WRITE_ONLY_ARB                                                 0x88B9
#define GL_XOR                                                            0x1506
#define GL_YCBCR_MESA                                                     0x8757
#define GL_ZERO                                                           0
#define GL_ZOOM_X                                                         0x0D16
#define GL_ZOOM_Y                                                         0x0D17

void glAccum(GLenum op, GLfloat value);
void glActiveStencilFaceEXT(GLenum face);
void glActiveTexture(GLenum texture);
void glActiveTextureARB(GLenum texture);
void glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void glAlphaFunc(GLenum func, GLfloat ref);
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences);
void glArrayElement(GLint i);
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
void glAttachShader(GLuint program, GLuint shader);
void glBegin(GLenum mode);
void glBeginFragmentShaderATI(void);
void glBeginQuery(GLenum target, GLuint id);
void glBeginQueryARB(GLenum target, GLuint id);
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB *name);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindBufferARB(GLenum target, GLuint buffer);
void glBindFragmentShaderATI(GLuint id);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
void glBindProgramARB(GLenum target, GLuint program);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
void glBindTexture(GLenum target, GLuint texture);
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendEquation(GLenum mode);
void glBlendEquationEXT(GLenum mode);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
void glBufferDataARB(GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const void *lists);
GLenum glCheckFramebufferStatus(GLenum target);
GLenum glCheckFramebufferStatusEXT(GLenum target);
void glClampColorARB(GLenum target, GLenum clamp);
void glClear(GLbitfield mask);
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glClearDepth(GLdouble depth);
void glClearIndex(GLfloat c);
void glClearStencil(GLint s);
void glClientActiveTexture(GLenum texture);
void glClientActiveTextureARB(GLenum texture);
void glClipPlane(GLenum plane, const GLdouble *equation);
void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glColor3bv(const GLbyte *v);
void glColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glColor3dv(const GLdouble *v);
void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glColor3fv(const GLfloat *v);
void glColor3i(GLint red, GLint green, GLint blue);
void glColor3iv(const GLint *v);
void glColor3s(GLshort red, GLshort green, GLshort blue);
void glColor3sv(const GLshort *v);
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glColor3ubv(const GLubyte *v);
void glColor3ui(GLuint red, GLuint green, GLuint blue);
void glColor3uiv(const GLuint *v);
void glColor3us(GLushort red, GLushort green, GLushort blue);
void glColor3usv(const GLushort *v);
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void glColor4bv(const GLbyte *v);
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void glColor4dv(const GLdouble *v);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glColor4fv(const GLfloat *v);
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
void glColor4iv(const GLint *v);
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void glColor4sv(const GLshort *v);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4ubv(const GLubyte *v);
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glColor4uiv(const GLuint *v);
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void glColor4usv(const GLushort *v);
void glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorMaterial(GLenum face, GLenum mode);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params);
void glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat *params);
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params);
void glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint *params);
void glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
void glCompileShader(GLuint shader);
void glCompileShaderARB(GLhandleARB shaderObj);
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params);
void glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat *params);
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params);
void glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint *params);
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLuint glCreateProgram(void);
GLhandleARB glCreateProgramObjectARB(void);
GLuint glCreateShader(GLenum type);
GLhandleARB glCreateShaderObjectARB(GLenum shaderType);
void glCullFace(GLenum mode);
void glCurrentPaletteMatrixARB(GLint index);
void glDeleteBuffers(GLsizei n, const GLuint *buffers);
void glDeleteBuffersARB(GLsizei n, const GLuint *buffers);
void glDeleteFragmentShaderATI(GLuint id);
void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
void glDeleteFramebuffersEXT(GLsizei n, const GLuint *framebuffers);
void glDeleteLists(GLuint list, GLsizei range);
void glDeleteObjectARB(GLhandleARB obj);
void glDeleteProgram(GLuint program);
void glDeleteProgramsARB(GLsizei n, const GLuint *programs);
void glDeleteQueries(GLsizei n, const GLuint *ids);
void glDeleteQueriesARB(GLsizei n, const GLuint *ids);
void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
void glDeleteRenderbuffersEXT(GLsizei n, const GLuint *renderbuffers);
void glDeleteShader(GLuint shader);
void glDeleteTextures(GLsizei n, const GLuint *textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRange(GLdouble n, GLdouble f);
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
void glDetachShader(GLuint program, GLuint shader);
void glDisable(GLenum cap);
void glDisableClientState(GLenum array);
void glDisableVertexAttribArray(GLuint index);
void glDisableVertexAttribArrayARB(GLuint index);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawBuffer(GLenum buf);
void glDrawBuffers(GLsizei n, const GLenum *bufs);
void glDrawBuffersARB(GLsizei n, const GLenum *bufs);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
void glEdgeFlag(GLboolean flag);
void glEdgeFlagPointer(GLsizei stride, const void *pointer);
void glEdgeFlagv(const GLboolean *flag);
void glEnable(GLenum cap);
void glEnableClientState(GLenum array);
void glEnableVertexAttribArray(GLuint index);
void glEnableVertexAttribArrayARB(GLuint index);
void glEnd(void);
void glEndFragmentShaderATI(void);
void glEndList(void);
void glEndQuery(GLenum target);
void glEndQueryARB(GLenum target);
void glEvalCoord1d(GLdouble u);
void glEvalCoord1dv(const GLdouble *u);
void glEvalCoord1f(GLfloat u);
void glEvalCoord1fv(const GLfloat *u);
void glEvalCoord2d(GLdouble u, GLdouble v);
void glEvalCoord2dv(const GLdouble *u);
void glEvalCoord2f(GLfloat u, GLfloat v);
void glEvalCoord2fv(const GLfloat *u);
void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glEvalPoint1(GLint i);
void glEvalPoint2(GLint i, GLint j);
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer);
void glFinish(void);
void glFlush(void);
void glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer);
void glFogCoordPointerEXT(GLenum type, GLsizei stride, const void *pointer);
void glFogCoordd(GLdouble coord);
void glFogCoorddEXT(GLdouble coord);
void glFogCoorddv(const GLdouble *coord);
void glFogCoorddvEXT(const GLdouble *coord);
void glFogCoordf(GLfloat coord);
void glFogCoordfEXT(GLfloat coord);
void glFogCoordfv(const GLfloat *coord);
void glFogCoordfvEXT(const GLfloat *coord);
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, const GLfloat *params);
void glFogi(GLenum pname, GLint param);
void glFogiv(GLenum pname, const GLint *params);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFrontFace(GLenum mode);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glGenBuffers(GLsizei n, GLuint *buffers);
void glGenBuffersARB(GLsizei n, GLuint *buffers);
GLuint glGenFragmentShadersATI(GLuint range);
void glGenFramebuffers(GLsizei n, GLuint *framebuffers);
void glGenFramebuffersEXT(GLsizei n, GLuint *framebuffers);
GLuint glGenLists(GLsizei range);
void glGenProgramsARB(GLsizei n, GLuint *programs);
void glGenQueries(GLsizei n, GLuint *ids);
void glGenQueriesARB(GLsizei n, GLuint *ids);
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers);
void glGenTextures(GLsizei n, GLuint *textures);
void glGenerateMipmap(GLenum target);
void glGenerateMipmapEXT(GLenum target);
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLint glGetAttribLocation(GLuint program, const GLchar *name);
GLint glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB *name);
void glGetBooleanv(GLenum pname, GLboolean *data);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint *params);
void glGetBufferPointerv(GLenum target, GLenum pname, void **params);
void glGetBufferPointervARB(GLenum target, GLenum pname, void **params);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
void glGetClipPlane(GLenum plane, GLdouble *equation);
void glGetColorTable(GLenum target, GLenum format, GLenum type, void *table);
void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void *data);
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
void glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat *params);
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint *params);
void glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint *params);
void glGetColorTableSGI(GLenum target, GLenum format, GLenum type, void *table);
void glGetCompressedTexImage(GLenum target, GLint level, void *img);
void glGetCompressedTexImageARB(GLenum target, GLint level, void *img);
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void *image);
void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void *image);
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint *params);
void glGetDoublev(GLenum pname, GLdouble *data);
GLenum glGetError(void);
void glGetFloatv(GLenum pname, GLfloat *data);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLhandleARB glGetHandleARB(GLenum pname);
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint *params);
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
void glGetIntegerv(GLenum pname, GLint *data);
void glGetLightfv(GLenum light, GLenum pname, GLfloat *params);
void glGetLightiv(GLenum light, GLenum pname, GLint *params);
void glGetMapdv(GLenum target, GLenum query, GLdouble *v);
void glGetMapfv(GLenum target, GLenum query, GLfloat *v);
void glGetMapiv(GLenum target, GLenum query, GLint *v);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params);
void glGetMaterialiv(GLenum face, GLenum pname, GLint *params);
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint *params);
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params);
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params);
void glGetPixelMapfv(GLenum map, GLfloat *values);
void glGetPixelMapuiv(GLenum map, GLuint *values);
void glGetPixelMapusv(GLenum map, GLushort *values);
void glGetPointerv(GLenum pname, void **params);
void glGetPolygonStipple(GLubyte *mask);
void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble *params);
void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat *params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble *params);
void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat *params);
void glGetProgramStringARB(GLenum target, GLenum pname, void *string);
void glGetProgramiv(GLuint program, GLenum pname, GLint *params);
void glGetProgramivARB(GLenum target, GLenum pname, GLint *params);
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params);
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint *params);
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params);
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint *params);
void glGetQueryiv(GLenum target, GLenum pname, GLint *params);
void glGetQueryivARB(GLenum target, GLenum pname, GLint *params);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint *params);
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
void glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
const GLubyte *glGetString(GLenum name);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params);
void glGetTexEnviv(GLenum target, GLenum pname, GLint *params);
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params);
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
void glGetTexGeniv(GLenum coord, GLenum pname, GLint *params);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint *params);
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint *params);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);
GLint glGetUniformLocation(GLuint program, const GLchar *name);
GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name);
void glGetUniformfv(GLuint program, GLint location, GLfloat *params);
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params);
void glGetUniformiv(GLuint program, GLint location, GLint *params);
void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint *params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer);
void glGetVertexAttribPointervARB(GLuint index, GLenum pname, void **pointer);
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params);
void glHint(GLenum target, GLenum mode);
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glIndexMask(GLuint mask);
void glIndexPointer(GLenum type, GLsizei stride, const void *pointer);
void glIndexd(GLdouble c);
void glIndexdv(const GLdouble *c);
void glIndexf(GLfloat c);
void glIndexfv(const GLfloat *c);
void glIndexi(GLint c);
void glIndexiv(const GLint *c);
void glIndexs(GLshort c);
void glIndexsv(const GLshort *c);
void glIndexub(GLubyte c);
void glIndexubv(const GLubyte *c);
void glInitNames(void);
void glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer);
GLboolean glIsBuffer(GLuint buffer);
GLboolean glIsBufferARB(GLuint buffer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsFramebuffer(GLuint framebuffer);
GLboolean glIsFramebufferEXT(GLuint framebuffer);
GLboolean glIsList(GLuint list);
GLboolean glIsProgram(GLuint program);
GLboolean glIsProgramARB(GLuint program);
GLboolean glIsQuery(GLuint id);
GLboolean glIsQueryARB(GLuint id);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
GLboolean glIsRenderbufferEXT(GLuint renderbuffer);
GLboolean glIsShader(GLuint shader);
GLboolean glIsTexture(GLuint texture);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, const GLfloat *params);
void glLightModeli(GLenum pname, GLint param);
void glLightModeliv(GLenum pname, const GLint *params);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, const GLfloat *params);
void glLighti(GLenum light, GLenum pname, GLint param);
void glLightiv(GLenum light, GLenum pname, const GLint *params);
void glLineStipple(GLint factor, GLushort pattern);
void glLineWidth(GLfloat width);
void glLinkProgram(GLuint program);
void glLinkProgramARB(GLhandleARB programObj);
void glListBase(GLuint base);
void glLoadIdentity(void);
void glLoadMatrixd(const GLdouble *m);
void glLoadMatrixf(const GLfloat *m);
void glLoadName(GLuint name);
void glLoadTransposeMatrixd(const GLdouble *m);
void glLoadTransposeMatrixdARB(const GLdouble *m);
void glLoadTransposeMatrixf(const GLfloat *m);
void glLoadTransposeMatrixfARB(const GLfloat *m);
void glLockArraysEXT(GLint first, GLsizei count);
void glLogicOp(GLenum opcode);
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
void *glMapBuffer(GLenum target, GLenum access);
void *glMapBufferARB(GLenum target, GLenum access);
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
void glMateriali(GLenum face, GLenum pname, GLint param);
void glMaterialiv(GLenum face, GLenum pname, const GLint *params);
void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glMatrixIndexubvARB(GLint size, const GLubyte *indices);
void glMatrixIndexuivARB(GLint size, const GLuint *indices);
void glMatrixIndexusvARB(GLint size, const GLushort *indices);
void glMatrixMode(GLenum mode);
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink);
void glMultMatrixd(const GLdouble *m);
void glMultMatrixf(const GLfloat *m);
void glMultTransposeMatrixd(const GLdouble *m);
void glMultTransposeMatrixdARB(const GLdouble *m);
void glMultTransposeMatrixf(const GLfloat *m);
void glMultTransposeMatrixfARB(const GLfloat *m);
void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
void glMultiDrawArraysEXT(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
void glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
void glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);
void glMultiTexCoord1d(GLenum target, GLdouble s);
void glMultiTexCoord1dARB(GLenum target, GLdouble s);
void glMultiTexCoord1dv(GLenum target, const GLdouble *v);
void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v);
void glMultiTexCoord1f(GLenum target, GLfloat s);
void glMultiTexCoord1fARB(GLenum target, GLfloat s);
void glMultiTexCoord1fv(GLenum target, const GLfloat *v);
void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v);
void glMultiTexCoord1i(GLenum target, GLint s);
void glMultiTexCoord1iARB(GLenum target, GLint s);
void glMultiTexCoord1iv(GLenum target, const GLint *v);
void glMultiTexCoord1ivARB(GLenum target, const GLint *v);
void glMultiTexCoord1s(GLenum target, GLshort s);
void glMultiTexCoord1sARB(GLenum target, GLshort s);
void glMultiTexCoord1sv(GLenum target, const GLshort *v);
void glMultiTexCoord1svARB(GLenum target, const GLshort *v);
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dv(GLenum target, const GLdouble *v);
void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v);
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fv(GLenum target, const GLfloat *v);
void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v);
void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iv(GLenum target, const GLint *v);
void glMultiTexCoord2ivARB(GLenum target, const GLint *v);
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sv(GLenum target, const GLshort *v);
void glMultiTexCoord2svARB(GLenum target, const GLshort *v);
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dv(GLenum target, const GLdouble *v);
void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v);
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fv(GLenum target, const GLfloat *v);
void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v);
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iv(GLenum target, const GLint *v);
void glMultiTexCoord3ivARB(GLenum target, const GLint *v);
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sv(GLenum target, const GLshort *v);
void glMultiTexCoord3svARB(GLenum target, const GLshort *v);
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dv(GLenum target, const GLdouble *v);
void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fv(GLenum target, const GLfloat *v);
void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v);
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iv(GLenum target, const GLint *v);
void glMultiTexCoord4ivARB(GLenum target, const GLint *v);
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sv(GLenum target, const GLshort *v);
void glMultiTexCoord4svARB(GLenum target, const GLshort *v);
void glNewList(GLuint list, GLenum mode);
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
void glNormal3bv(const GLbyte *v);
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void glNormal3dv(const GLdouble *v);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glNormal3fv(const GLfloat *v);
void glNormal3i(GLint nx, GLint ny, GLint nz);
void glNormal3iv(const GLint *v);
void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
void glNormal3sv(const GLshort *v);
void glNormalPointer(GLenum type, GLsizei stride, const void *pointer);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle);
void glPassThrough(GLfloat token);
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values);
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values);
void glPixelStoref(GLenum pname, GLfloat param);
void glPixelStorei(GLenum pname, GLint param);
void glPixelTransferf(GLenum pname, GLfloat param);
void glPixelTransferi(GLenum pname, GLint param);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfARB(GLenum pname, GLfloat param);
void glPointParameterfEXT(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, const GLfloat *params);
void glPointParameterfvARB(GLenum pname, const GLfloat *params);
void glPointParameterfvEXT(GLenum pname, const GLfloat *params);
void glPointParameteri(GLenum pname, GLint param);
void glPointParameteriv(GLenum pname, const GLint *params);
void glPointSize(GLfloat size);
void glPolygonMode(GLenum face, GLenum mode);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glPolygonStipple(const GLubyte *mask);
void glPopAttrib(void);
void glPopClientAttrib(void);
void glPopMatrix(void);
void glPopName(void);
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities);
void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void *string);
void glPushAttrib(GLbitfield mask);
void glPushClientAttrib(GLbitfield mask);
void glPushMatrix(void);
void glPushName(GLuint name);
void glRasterPos2d(GLdouble x, GLdouble y);
void glRasterPos2dv(const GLdouble *v);
void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos2fv(const GLfloat *v);
void glRasterPos2i(GLint x, GLint y);
void glRasterPos2iv(const GLint *v);
void glRasterPos2s(GLshort x, GLshort y);
void glRasterPos2sv(const GLshort *v);
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
void glRasterPos3dv(const GLdouble *v);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glRasterPos3fv(const GLfloat *v);
void glRasterPos3i(GLint x, GLint y, GLint z);
void glRasterPos3iv(const GLint *v);
void glRasterPos3s(GLshort x, GLshort y, GLshort z);
void glRasterPos3sv(const GLshort *v);
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glRasterPos4dv(const GLdouble *v);
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glRasterPos4fv(const GLfloat *v);
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
void glRasterPos4iv(const GLint *v);
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glRasterPos4sv(const GLshort *v);
void glReadBuffer(GLenum src);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void glRectdv(const GLdouble *v1, const GLdouble *v2);
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void glRectfv(const GLfloat *v1, const GLfloat *v2);
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
void glRectiv(const GLint *v1, const GLint *v2);
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void glRectsv(const GLshort *v1, const GLshort *v2);
GLint glRenderMode(GLenum mode);
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glResetHistogram(GLenum target);
void glResetHistogramEXT(GLenum target);
void glResetMinmax(GLenum target);
void glResetMinmaxEXT(GLenum target);
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glSampleCoverageARB(GLfloat value, GLboolean invert);
void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle);
void glScaled(GLdouble x, GLdouble y, GLdouble z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bv(const GLbyte *v);
void glSecondaryColor3bvEXT(const GLbyte *v);
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dv(const GLdouble *v);
void glSecondaryColor3dvEXT(const GLdouble *v);
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fv(const GLfloat *v);
void glSecondaryColor3fvEXT(const GLfloat *v);
void glSecondaryColor3i(GLint red, GLint green, GLint blue);
void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
void glSecondaryColor3iv(const GLint *v);
void glSecondaryColor3ivEXT(const GLint *v);
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sv(const GLshort *v);
void glSecondaryColor3svEXT(const GLshort *v);
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubv(const GLubyte *v);
void glSecondaryColor3ubvEXT(const GLubyte *v);
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiv(const GLuint *v);
void glSecondaryColor3uivEXT(const GLuint *v);
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usv(const GLushort *v);
void glSecondaryColor3usvEXT(const GLushort *v);
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glSelectBuffer(GLsizei size, GLuint *buffer);
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
void glSetFragmentShaderConstantATI(GLuint dst, const GLfloat *value);
void glShadeModel(GLenum mode);
void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glTexCoord1d(GLdouble s);
void glTexCoord1dv(const GLdouble *v);
void glTexCoord1f(GLfloat s);
void glTexCoord1fv(const GLfloat *v);
void glTexCoord1i(GLint s);
void glTexCoord1iv(const GLint *v);
void glTexCoord1s(GLshort s);
void glTexCoord1sv(const GLshort *v);
void glTexCoord2d(GLdouble s, GLdouble t);
void glTexCoord2dv(const GLdouble *v);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexCoord2fv(const GLfloat *v);
void glTexCoord2i(GLint s, GLint t);
void glTexCoord2iv(const GLint *v);
void glTexCoord2s(GLshort s, GLshort t);
void glTexCoord2sv(const GLshort *v);
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
void glTexCoord3dv(const GLdouble *v);
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glTexCoord3fv(const GLfloat *v);
void glTexCoord3i(GLint s, GLint t, GLint r);
void glTexCoord3iv(const GLint *v);
void glTexCoord3s(GLshort s, GLshort t, GLshort r);
void glTexCoord3sv(const GLshort *v);
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glTexCoord4dv(const GLdouble *v);
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glTexCoord4fv(const GLfloat *v);
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
void glTexCoord4iv(const GLint *v);
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
void glTexCoord4sv(const GLshort *v);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnviv(GLenum target, GLenum pname, const GLint *params);
void glTexGend(GLenum coord, GLenum pname, GLdouble param);
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params);
void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexParameterIivEXT(GLenum target, GLenum pname, const GLint *params);
void glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint *params);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint *params);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void glUniform1f(GLint location, GLfloat v0);
void glUniform1fARB(GLint location, GLfloat v0);
void glUniform1fv(GLint location, GLsizei count, const GLfloat *value);
void glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform1i(GLint location, GLint v0);
void glUniform1iARB(GLint location, GLint v0);
void glUniform1iv(GLint location, GLsizei count, const GLint *value);
void glUniform1ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform1ui(GLint location, GLuint v0);
void glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value);
void glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform2iARB(GLint location, GLint v0, GLint v1);
void glUniform2iv(GLint location, GLsizei count, const GLint *value);
void glUniform2ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform2ui(GLint location, GLuint v0, GLuint v1);
void glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
void glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3iv(GLint location, GLsizei count, const GLint *value);
void glUniform3ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
void glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4iv(GLint location, GLsizei count, const GLint *value);
void glUniform4ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUnlockArraysEXT(void);
GLboolean glUnmapBuffer(GLenum target);
GLboolean glUnmapBufferARB(GLenum target);
void glUseProgram(GLuint program);
void glUseProgramObjectARB(GLhandleARB programObj);
void glValidateProgram(GLuint program);
void glValidateProgramARB(GLhandleARB programObj);
void glVertex2d(GLdouble x, GLdouble y);
void glVertex2dv(const GLdouble *v);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2fv(const GLfloat *v);
void glVertex2i(GLint x, GLint y);
void glVertex2iv(const GLint *v);
void glVertex2s(GLshort x, GLshort y);
void glVertex2sv(const GLshort *v);
void glVertex3d(GLdouble x, GLdouble y, GLdouble z);
void glVertex3dv(const GLdouble *v);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex3fv(const GLfloat *v);
void glVertex3i(GLint x, GLint y, GLint z);
void glVertex3iv(const GLint *v);
void glVertex3s(GLshort x, GLshort y, GLshort z);
void glVertex3sv(const GLshort *v);
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertex4dv(const GLdouble *v);
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertex4fv(const GLfloat *v);
void glVertex4i(GLint x, GLint y, GLint z, GLint w);
void glVertex4iv(const GLint *v);
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glVertex4sv(const GLshort *v);
void glVertexAttrib1d(GLuint index, GLdouble x);
void glVertexAttrib1dARB(GLuint index, GLdouble x);
void glVertexAttrib1dv(GLuint index, const GLdouble *v);
void glVertexAttrib1dvARB(GLuint index, const GLdouble *v);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fARB(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, const GLfloat *v);
void glVertexAttrib1fvARB(GLuint index, const GLfloat *v);
void glVertexAttrib1s(GLuint index, GLshort x);
void glVertexAttrib1sARB(GLuint index, GLshort x);
void glVertexAttrib1sv(GLuint index, const GLshort *v);
void glVertexAttrib1svARB(GLuint index, const GLshort *v);
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dv(GLuint index, const GLdouble *v);
void glVertexAttrib2dvARB(GLuint index, const GLdouble *v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, const GLfloat *v);
void glVertexAttrib2fvARB(GLuint index, const GLfloat *v);
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sv(GLuint index, const GLshort *v);
void glVertexAttrib2svARB(GLuint index, const GLshort *v);
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dv(GLuint index, const GLdouble *v);
void glVertexAttrib3dvARB(GLuint index, const GLdouble *v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, const GLfloat *v);
void glVertexAttrib3fvARB(GLuint index, const GLfloat *v);
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sv(GLuint index, const GLshort *v);
void glVertexAttrib3svARB(GLuint index, const GLshort *v);
void glVertexAttrib4Nbv(GLuint index, const GLbyte *v);
void glVertexAttrib4NbvARB(GLuint index, const GLbyte *v);
void glVertexAttrib4Niv(GLuint index, const GLint *v);
void glVertexAttrib4NivARB(GLuint index, const GLint *v);
void glVertexAttrib4Nsv(GLuint index, const GLshort *v);
void glVertexAttrib4NsvARB(GLuint index, const GLshort *v);
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4Nubv(GLuint index, const GLubyte *v);
void glVertexAttrib4NubvARB(GLuint index, const GLubyte *v);
void glVertexAttrib4Nuiv(GLuint index, const GLuint *v);
void glVertexAttrib4NuivARB(GLuint index, const GLuint *v);
void glVertexAttrib4Nusv(GLuint index, const GLushort *v);
void glVertexAttrib4NusvARB(GLuint index, const GLushort *v);
void glVertexAttrib4bv(GLuint index, const GLbyte *v);
void glVertexAttrib4bvARB(GLuint index, const GLbyte *v);
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dv(GLuint index, const GLdouble *v);
void glVertexAttrib4dvARB(GLuint index, const GLdouble *v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, const GLfloat *v);
void glVertexAttrib4fvARB(GLuint index, const GLfloat *v);
void glVertexAttrib4iv(GLuint index, const GLint *v);
void glVertexAttrib4ivARB(GLuint index, const GLint *v);
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sv(GLuint index, const GLshort *v);
void glVertexAttrib4svARB(GLuint index, const GLshort *v);
void glVertexAttrib4ubv(GLuint index, const GLubyte *v);
void glVertexAttrib4ubvARB(GLuint index, const GLubyte *v);
void glVertexAttrib4uiv(GLuint index, const GLuint *v);
void glVertexAttrib4uivARB(GLuint index, const GLuint *v);
void glVertexAttrib4usv(GLuint index, const GLushort *v);
void glVertexAttrib4usvARB(GLuint index, const GLushort *v);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
void glVertexBlendARB(GLint count);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void *pointer);
void glWeightbvARB(GLint size, const GLbyte *weights);
void glWeightdvARB(GLint size, const GLdouble *weights);
void glWeightfvARB(GLint size, const GLfloat *weights);
void glWeightivARB(GLint size, const GLint *weights);
void glWeightsvARB(GLint size, const GLshort *weights);
void glWeightubvARB(GLint size, const GLubyte *weights);
void glWeightuivARB(GLint size, const GLuint *weights);
void glWeightusvARB(GLint size, const GLushort *weights);
void glWindowPos2d(GLdouble x, GLdouble y);
void glWindowPos2dARB(GLdouble x, GLdouble y);
void glWindowPos2dv(const GLdouble *v);
void glWindowPos2dvARB(const GLdouble *v);
void glWindowPos2f(GLfloat x, GLfloat y);
void glWindowPos2fARB(GLfloat x, GLfloat y);
void glWindowPos2fv(const GLfloat *v);
void glWindowPos2fvARB(const GLfloat *v);
void glWindowPos2i(GLint x, GLint y);
void glWindowPos2iARB(GLint x, GLint y);
void glWindowPos2iv(const GLint *v);
void glWindowPos2ivARB(const GLint *v);
void glWindowPos2s(GLshort x, GLshort y);
void glWindowPos2sARB(GLshort x, GLshort y);
void glWindowPos2sv(const GLshort *v);
void glWindowPos2svARB(const GLshort *v);
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dv(const GLdouble *v);
void glWindowPos3dvARB(const GLdouble *v);
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fv(const GLfloat *v);
void glWindowPos3fvARB(const GLfloat *v);
void glWindowPos3i(GLint x, GLint y, GLint z);
void glWindowPos3iARB(GLint x, GLint y, GLint z);
void glWindowPos3iv(const GLint *v);
void glWindowPos3ivARB(const GLint *v);
void glWindowPos3s(GLshort x, GLshort y, GLshort z);
void glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
void glWindowPos3sv(const GLshort *v);
void glWindowPos3svARB(const GLshort *v);

#ifndef _NO_PPCINLINE
#define glAccum(op, value) GLAccum(__tglContext, op, value)
#define glActiveStencilFaceEXT(face) GLActiveStencilFaceEXT(__tglContext, face)
#define glActiveTexture(texture) GLActiveTexture(__tglContext, texture)
#define glActiveTextureARB(texture) GLActiveTexture(__tglContext, texture)
#define glAlphaFragmentOp1ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod) GLAlphaFragmentOp1ATI(__tglContext, op, dst, dstMod, arg1, arg1Rep, arg1Mod)
#define glAlphaFragmentOp2ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) GLAlphaFragmentOp2ATI(__tglContext, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod)
#define glAlphaFragmentOp3ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) GLAlphaFragmentOp3ATI(__tglContext, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
#define glAlphaFunc(func, ref) GLAlphaFunc(__tglContext, func, ref)
#define glAreTexturesResident(n, textures, residences) GLAreTexturesResident(__tglContext, n, textures, residences)
#define glArrayElement(i) GLArrayElement(__tglContext, i)
#define glAttachObjectARB(containerObj, obj) GLAttachShader(__tglContext, containerObj, obj)
#define glAttachShader(program, shader) GLAttachShader(__tglContext, program, shader)
#define glBegin(mode) GLBegin(__tglContext, mode)
#define glBeginFragmentShaderATI() GLBeginFragmentShaderATI(__tglContext)
#define glBeginQuery(target, id) GLBeginQuery(__tglContext, target, id)
#define glBeginQueryARB(target, id) GLBeginQuery(__tglContext, target, id)
#define glBindAttribLocation(program, index, name) GLBindAttribLocation(__tglContext, program, index, name)
#define glBindAttribLocationARB(programObj, index, name) GLBindAttribLocation(__tglContext, programObj, index, name)
#define glBindBuffer(target, buffer) GLBindBuffer(__tglContext, target, buffer)
#define glBindBufferARB(target, buffer) GLBindBuffer(__tglContext, target, buffer)
#define glBindFragmentShaderATI(id) GLBindFragmentShaderATI(__tglContext, id)
#define glBindFramebuffer(target, framebuffer) GLBindFramebuffer(__tglContext, target, framebuffer)
#define glBindFramebufferEXT(target, framebuffer) GLBindFramebufferEXT(__tglContext, target, framebuffer)
#define glBindProgramARB(target, program) GLBindProgramARB(__tglContext, target, program)
#define glBindRenderbuffer(target, renderbuffer) GLBindRenderbuffer(__tglContext, target, renderbuffer)
#define glBindRenderbufferEXT(target, renderbuffer) GLBindRenderbufferEXT(__tglContext, target, renderbuffer)
#define glBindTexture(target, texture) GLBindTexture(__tglContext, target, texture)
#define glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap) GLBitmap(__tglContext, width, height, xorig, yorig, xmove, ymove, bitmap)
#define glBlendColor(red, green, blue, alpha) GLBlendColor(__tglContext, red, green, blue, alpha)
#define glBlendColorEXT(red, green, blue, alpha) GLBlendColor(__tglContext, red, green, blue, alpha)
#define glBlendEquation(mode) GLBlendEquation(__tglContext, mode)
#define glBlendEquationEXT(mode) GLBlendEquation(__tglContext, mode)
#define glBlendEquationSeparate(modeRGB, modeAlpha) GLBlendEquationSeparate(__tglContext, modeRGB, modeAlpha)
#define glBlendEquationSeparateEXT(modeRGB, modeAlpha) GLBlendEquationSeparate(__tglContext, modeRGB, modeAlpha)
#define glBlendFunc(sfactor, dfactor) GLBlendFunc(__tglContext, sfactor, dfactor)
#define glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) GLBlendFuncSeparate(__tglContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
#define glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) GLBlendFuncSeparate(__tglContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
#define glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter) GLBlitFramebuffer(__tglContext, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter)
#define glBufferData(target, size, data, usage) GLBufferData(__tglContext, target, size, data, usage)
#define glBufferDataARB(target, size, data, usage) GLBufferData(__tglContext, target, size, data, usage)
#define glBufferSubData(target, offset, size, data) GLBufferSubData(__tglContext, target, offset, size, data)
#define glBufferSubDataARB(target, offset, size, data) GLBufferSubData(__tglContext, target, offset, size, data)
#define glCallList(list) GLCallList(__tglContext, list)
#define glCallLists(n, type, lists) GLCallLists(__tglContext, n, type, lists)
#define glCheckFramebufferStatus(target) GLCheckFramebufferStatus(__tglContext, target)
#define glCheckFramebufferStatusEXT(target) GLCheckFramebufferStatus(__tglContext, target)
#define glClampColorARB(target, clamp) GLClampColor(__tglContext, target, clamp)
#define glClear(mask) GLClear(__tglContext, mask)
#define glClearAccum(red, green, blue, alpha) GLClearAccum(__tglContext, red, green, blue, alpha)
#define glClearColor(red, green, blue, alpha) GLClearColor(__tglContext, red, green, blue, alpha)
#define glClearColorIiEXT(red, green, blue, alpha) GLClearColorIiEXT(__tglContext, red, green, blue, alpha)
#define glClearColorIuiEXT(red, green, blue, alpha) GLClearColorIuiEXT(__tglContext, red, green, blue, alpha)
#define glClearDepth(depth) GLClearDepth(__tglContext, depth)
#define glClearIndex(c) GLClearIndex(__tglContext, c)
#define glClearStencil(s) GLClearStencil(__tglContext, s)
#define glClientActiveTexture(texture) GLClientActiveTexture(__tglContext, texture)
#define glClientActiveTextureARB(texture) GLClientActiveTexture(__tglContext, texture)
#define glClipPlane(plane, equation) GLClipPlane(__tglContext, plane, equation)
#define glColor3b(red, green, blue) GLColor3b(__tglContext, red, green, blue)
#define glColor3bv(v) GLColor3bv(__tglContext, v)
#define glColor3d(red, green, blue) GLColor3d(__tglContext, red, green, blue)
#define glColor3dv(v) GLColor3dv(__tglContext, v)
#define glColor3f(red, green, blue) GLColor3f(__tglContext, red, green, blue)
#define glColor3fv(v) GLColor3fv(__tglContext, v)
#define glColor3i(red, green, blue) GLColor3i(__tglContext, red, green, blue)
#define glColor3iv(v) GLColor3iv(__tglContext, v)
#define glColor3s(red, green, blue) GLColor3s(__tglContext, red, green, blue)
#define glColor3sv(v) GLColor3sv(__tglContext, v)
#define glColor3ub(red, green, blue) GLColor3ub(__tglContext, red, green, blue)
#define glColor3ubv(v) GLColor3ubv(__tglContext, v)
#define glColor3ui(red, green, blue) GLColor3ui(__tglContext, red, green, blue)
#define glColor3uiv(v) GLColor3uiv(__tglContext, v)
#define glColor3us(red, green, blue) GLColor3us(__tglContext, red, green, blue)
#define glColor3usv(v) GLColor3usv(__tglContext, v)
#define glColor4b(red, green, blue, alpha) GLColor4b(__tglContext, red, green, blue, alpha)
#define glColor4bv(v) GLColor4bv(__tglContext, v)
#define glColor4d(red, green, blue, alpha) GLColor4d(__tglContext, red, green, blue, alpha)
#define glColor4dv(v) GLColor4dv(__tglContext, v)
#define glColor4f(red, green, blue, alpha) GLColor4f(__tglContext, red, green, blue, alpha)
#define glColor4fv(v) GLColor4fv(__tglContext, v)
#define glColor4i(red, green, blue, alpha) GLColor4i(__tglContext, red, green, blue, alpha)
#define glColor4iv(v) GLColor4iv(__tglContext, v)
#define glColor4s(red, green, blue, alpha) GLColor4s(__tglContext, red, green, blue, alpha)
#define glColor4sv(v) GLColor4sv(__tglContext, v)
#define glColor4ub(red, green, blue, alpha) GLColor4ub(__tglContext, red, green, blue, alpha)
#define glColor4ubv(v) GLColor4ubv(__tglContext, v)
#define glColor4ui(red, green, blue, alpha) GLColor4ui(__tglContext, red, green, blue, alpha)
#define glColor4uiv(v) GLColor4uiv(__tglContext, v)
#define glColor4us(red, green, blue, alpha) GLColor4us(__tglContext, red, green, blue, alpha)
#define glColor4usv(v) GLColor4usv(__tglContext, v)
#define glColorFragmentOp1ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod) GLColorFragmentOp1ATI(__tglContext, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod)
#define glColorFragmentOp2ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) GLColorFragmentOp2ATI(__tglContext, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod)
#define glColorFragmentOp3ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) GLColorFragmentOp3ATI(__tglContext, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
#define glColorMask(red, green, blue, alpha) GLColorMask(__tglContext, red, green, blue, alpha)
#define glColorMaterial(face, mode) GLColorMaterial(__tglContext, face, mode)
#define glColorPointer(size, type, stride, pointer) GLColorPointer(__tglContext, size, type, stride, pointer)
#define glColorSubTable(target, start, count, format, type, data) GLColorSubTable(__tglContext, target, start, count, format, type, data)
#define glColorSubTableEXT(target, start, count, format, type, data) GLColorSubTable(__tglContext, target, start, count, format, type, data)
#define glColorTable(target, internalformat, width, format, type, table) GLColorTable(__tglContext, target, internalformat, width, format, type, table)
#define glColorTableEXT(target, internalFormat, width, format, type, table) GLColorTable(__tglContext, target, internalFormat, width, format, type, table)
#define glColorTableParameterfv(target, pname, params) GLColorTableParameterfv(__tglContext, target, pname, params)
#define glColorTableParameterfvSGI(target, pname, params) GLColorTableParameterfv(__tglContext, target, pname, params)
#define glColorTableParameteriv(target, pname, params) GLColorTableParameteriv(__tglContext, target, pname, params)
#define glColorTableParameterivSGI(target, pname, params) GLColorTableParameteriv(__tglContext, target, pname, params)
#define glColorTableSGI(target, internalformat, width, format, type, table) GLColorTable(__tglContext, target, internalformat, width, format, type, table)
#define glCompileShader(shader) GLCompileShader(__tglContext, shader)
#define glCompileShaderARB(shaderObj) GLCompileShader(__tglContext, shaderObj)
#define glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data) GLCompressedTexImage1D(__tglContext, target, level, internalformat, width, border, imageSize, data)
#define glCompressedTexImage1DARB(target, level, internalformat, width, border, imageSize, data) GLCompressedTexImage1D(__tglContext, target, level, internalformat, width, border, imageSize, data)
#define glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data) GLCompressedTexImage2D(__tglContext, target, level, internalformat, width, height, border, imageSize, data)
#define glCompressedTexImage2DARB(target, level, internalformat, width, height, border, imageSize, data) GLCompressedTexImage2D(__tglContext, target, level, internalformat, width, height, border, imageSize, data)
#define glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data) GLCompressedTexImage3D(__tglContext, target, level, internalformat, width, height, depth, border, imageSize, data)
#define glCompressedTexImage3DARB(target, level, internalformat, width, height, depth, border, imageSize, data) GLCompressedTexImage3D(__tglContext, target, level, internalformat, width, height, depth, border, imageSize, data)
#define glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data) GLCompressedTexSubImage1D(__tglContext, target, level, xoffset, width, format, imageSize, data)
#define glCompressedTexSubImage1DARB(target, level, xoffset, width, format, imageSize, data) GLCompressedTexSubImage1D(__tglContext, target, level, xoffset, width, format, imageSize, data)
#define glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data) GLCompressedTexSubImage2D(__tglContext, target, level, xoffset, yoffset, width, height, format, imageSize, data)
#define glCompressedTexSubImage2DARB(target, level, xoffset, yoffset, width, height, format, imageSize, data) GLCompressedTexSubImage2D(__tglContext, target, level, xoffset, yoffset, width, height, format, imageSize, data)
#define glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) GLCompressedTexSubImage3D(__tglContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
#define glCompressedTexSubImage3DARB(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) GLCompressedTexSubImage3D(__tglContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
#define glConvolutionFilter1D(target, internalformat, width, format, type, image) GLConvolutionFilter1D(__tglContext, target, internalformat, width, format, type, image)
#define glConvolutionFilter1DEXT(target, internalformat, width, format, type, image) GLConvolutionFilter1D(__tglContext, target, internalformat, width, format, type, image)
#define glConvolutionFilter2D(target, internalformat, width, height, format, type, image) GLConvolutionFilter2D(__tglContext, target, internalformat, width, height, format, type, image)
#define glConvolutionFilter2DEXT(target, internalformat, width, height, format, type, image) GLConvolutionFilter2D(__tglContext, target, internalformat, width, height, format, type, image)
#define glConvolutionParameterf(target, pname, params) GLConvolutionParameterf(__tglContext, target, pname, params)
#define glConvolutionParameterfEXT(target, pname, params) GLConvolutionParameterf(__tglContext, target, pname, params)
#define glConvolutionParameterfv(target, pname, params) GLConvolutionParameterfv(__tglContext, target, pname, params)
#define glConvolutionParameterfvEXT(target, pname, params) GLConvolutionParameterfv(__tglContext, target, pname, params)
#define glConvolutionParameteri(target, pname, params) GLConvolutionParameteri(__tglContext, target, pname, params)
#define glConvolutionParameteriEXT(target, pname, params) GLConvolutionParameteri(__tglContext, target, pname, params)
#define glConvolutionParameteriv(target, pname, params) GLConvolutionParameteriv(__tglContext, target, pname, params)
#define glConvolutionParameterivEXT(target, pname, params) GLConvolutionParameteriv(__tglContext, target, pname, params)
#define glCopyColorSubTable(target, start, x, y, width) GLCopyColorSubTable(__tglContext, target, start, x, y, width)
#define glCopyColorSubTableEXT(target, start, x, y, width) GLCopyColorSubTable(__tglContext, target, start, x, y, width)
#define glCopyColorTable(target, internalformat, x, y, width) GLCopyColorTable(__tglContext, target, internalformat, x, y, width)
#define glCopyColorTableSGI(target, internalformat, x, y, width) GLCopyColorTable(__tglContext, target, internalformat, x, y, width)
#define glCopyConvolutionFilter1D(target, internalformat, x, y, width) GLCopyConvolutionFilter1D(__tglContext, target, internalformat, x, y, width)
#define glCopyConvolutionFilter1DEXT(target, internalformat, x, y, width) GLCopyConvolutionFilter1D(__tglContext, target, internalformat, x, y, width)
#define glCopyConvolutionFilter2D(target, internalformat, x, y, width, height) GLCopyConvolutionFilter2D(__tglContext, target, internalformat, x, y, width, height)
#define glCopyConvolutionFilter2DEXT(target, internalformat, x, y, width, height) GLCopyConvolutionFilter2D(__tglContext, target, internalformat, x, y, width, height)
#define glCopyPixels(x, y, width, height, type) GLCopyPixels(__tglContext, x, y, width, height, type)
#define glCopyTexImage1D(target, level, internalformat, x, y, width, border) GLCopyTexImage1D(__tglContext, target, level, internalformat, x, y, width, border)
#define glCopyTexImage2D(target, level, internalformat, x, y, width, height, border) GLCopyTexImage2D(__tglContext, target, level, internalformat, x, y, width, height, border)
#define glCopyTexSubImage1D(target, level, xoffset, x, y, width) GLCopyTexSubImage1D(__tglContext, target, level, xoffset, x, y, width)
#define glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height) GLCopyTexSubImage2D(__tglContext, target, level, xoffset, yoffset, x, y, width, height)
#define glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height) GLCopyTexSubImage3D(__tglContext, target, level, xoffset, yoffset, zoffset, x, y, width, height)
#define glCreateProgram() GLCreateProgram(__tglContext)
#define glCreateProgramObjectARB() GLCreateProgram(__tglContext)
#define glCreateShader(type) GLCreateShader(__tglContext, type)
#define glCreateShaderObjectARB(shaderType) GLCreateShader(__tglContext, shaderType)
#define glCullFace(mode) GLCullFace(__tglContext, mode)
#define glCurrentPaletteMatrixARB(index) GLCurrentPaletteMatrixARB(__tglContext, index)
#define glDeleteBuffers(n, buffers) GLDeleteBuffers(__tglContext, n, buffers)
#define glDeleteBuffersARB(n, buffers) GLDeleteBuffers(__tglContext, n, buffers)
#define glDeleteFragmentShaderATI(id) GLDeleteFragmentShaderATI(__tglContext, id)
#define glDeleteFramebuffers(n, framebuffers) GLDeleteFramebuffers(__tglContext, n, framebuffers)
#define glDeleteFramebuffersEXT(n, framebuffers) GLDeleteFramebuffers(__tglContext, n, framebuffers)
#define glDeleteLists(list, range) GLDeleteLists(__tglContext, list, range)
#define glDeleteObjectARB(obj) GLDeleteObjectARB(__tglContext, obj)
#define glDeleteProgram(program) GLDeleteProgram(__tglContext, program)
#define glDeleteProgramsARB(n, programs) GLDeleteProgramsARB(__tglContext, n, programs)
#define glDeleteQueries(n, ids) GLDeleteQueries(__tglContext, n, ids)
#define glDeleteQueriesARB(n, ids) GLDeleteQueries(__tglContext, n, ids)
#define glDeleteRenderbuffers(n, renderbuffers) GLDeleteRenderbuffers(__tglContext, n, renderbuffers)
#define glDeleteRenderbuffersEXT(n, renderbuffers) GLDeleteRenderbuffers(__tglContext, n, renderbuffers)
#define glDeleteShader(shader) GLDeleteShader(__tglContext, shader)
#define glDeleteTextures(n, textures) GLDeleteTextures(__tglContext, n, textures)
#define glDepthFunc(func) GLDepthFunc(__tglContext, func)
#define glDepthMask(flag) GLDepthMask(__tglContext, flag)
#define glDepthRange(n, f) GLDepthRange(__tglContext, n, f)
#define glDetachObjectARB(containerObj, attachedObj) GLDetachShader(__tglContext, containerObj, attachedObj)
#define glDetachShader(program, shader) GLDetachShader(__tglContext, program, shader)
#define glDisable(cap) GLDisable(__tglContext, cap)
#define glDisableClientState(array) GLDisableClientState(__tglContext, array)
#define glDisableVertexAttribArray(index) GLDisableVertexAttribArray(__tglContext, index)
#define glDisableVertexAttribArrayARB(index) GLDisableVertexAttribArray(__tglContext, index)
#define glDrawArrays(mode, first, count) GLDrawArrays(__tglContext, mode, first, count)
#define glDrawBuffer(buf) GLDrawBuffer(__tglContext, buf)
#define glDrawBuffers(n, bufs) GLDrawBuffers(__tglContext, n, bufs)
#define glDrawBuffersARB(n, bufs) GLDrawBuffers(__tglContext, n, bufs)
#define glDrawElements(mode, count, type, indices) GLDrawElements(__tglContext, mode, count, type, indices)
#define glDrawPixels(width, height, format, type, pixels) GLDrawPixels(__tglContext, width, height, format, type, pixels)
#define glDrawRangeElements(mode, start, end, count, type, indices) GLDrawRangeElements(__tglContext, mode, start, end, count, type, indices)
#define glDrawRangeElementsEXT(mode, start, end, count, type, indices) GLDrawRangeElements(__tglContext, mode, start, end, count, type, indices)
#define glEdgeFlag(flag) GLEdgeFlag(__tglContext, flag)
#define glEdgeFlagPointer(stride, pointer) GLEdgeFlagPointer(__tglContext, stride, pointer)
#define glEdgeFlagv(flag) GLEdgeFlagv(__tglContext, flag)
#define glEnable(cap) GLEnable(__tglContext, cap)
#define glEnableClientState(array) GLEnableClientState(__tglContext, array)
#define glEnableVertexAttribArray(index) GLEnableVertexAttribArray(__tglContext, index)
#define glEnableVertexAttribArrayARB(index) GLEnableVertexAttribArray(__tglContext, index)
#define glEnd() GLEnd(__tglContext)
#define glEndFragmentShaderATI() GLEndFragmentShaderATI(__tglContext)
#define glEndList() GLEndList(__tglContext)
#define glEndQuery(target) GLEndQuery(__tglContext, target)
#define glEndQueryARB(target) GLEndQuery(__tglContext, target)
#define glEvalCoord1d(u) GLEvalCoord1d(__tglContext, u)
#define glEvalCoord1dv(u) GLEvalCoord1dv(__tglContext, u)
#define glEvalCoord1f(u) GLEvalCoord1f(__tglContext, u)
#define glEvalCoord1fv(u) GLEvalCoord1fv(__tglContext, u)
#define glEvalCoord2d(u, v) GLEvalCoord2d(__tglContext, u, v)
#define glEvalCoord2dv(u) GLEvalCoord2dv(__tglContext, u)
#define glEvalCoord2f(u, v) GLEvalCoord2f(__tglContext, u, v)
#define glEvalCoord2fv(u) GLEvalCoord2fv(__tglContext, u)
#define glEvalMesh1(mode, i1, i2) GLEvalMesh1(__tglContext, mode, i1, i2)
#define glEvalMesh2(mode, i1, i2, j1, j2) GLEvalMesh2(__tglContext, mode, i1, i2, j1, j2)
#define glEvalPoint1(i) GLEvalPoint1(__tglContext, i)
#define glEvalPoint2(i, j) GLEvalPoint2(__tglContext, i, j)
#define glFeedbackBuffer(size, type, buffer) GLFeedbackBuffer(__tglContext, size, type, buffer)
#define glFinish() GLFinish(__tglContext)
#define glFlush() GLFlush(__tglContext)
#define glFogCoordPointer(type, stride, pointer) GLFogCoordPointer(__tglContext, type, stride, pointer)
#define glFogCoordPointerEXT(type, stride, pointer) GLFogCoordPointer(__tglContext, type, stride, pointer)
#define glFogCoordd(coord) GLFogCoordd(__tglContext, coord)
#define glFogCoorddEXT(coord) GLFogCoordd(__tglContext, coord)
#define glFogCoorddv(coord) GLFogCoorddv(__tglContext, coord)
#define glFogCoorddvEXT(coord) GLFogCoorddv(__tglContext, coord)
#define glFogCoordf(coord) GLFogCoordf(__tglContext, coord)
#define glFogCoordfEXT(coord) GLFogCoordf(__tglContext, coord)
#define glFogCoordfv(coord) GLFogCoordfv(__tglContext, coord)
#define glFogCoordfvEXT(coord) GLFogCoordfv(__tglContext, coord)
#define glFogf(pname, param) GLFogf(__tglContext, pname, param)
#define glFogfv(pname, params) GLFogfv(__tglContext, pname, params)
#define glFogi(pname, param) GLFogi(__tglContext, pname, param)
#define glFogiv(pname, params) GLFogiv(__tglContext, pname, params)
#define glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer) GLFramebufferRenderbuffer(__tglContext, target, attachment, renderbuffertarget, renderbuffer)
#define glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer) GLFramebufferRenderbuffer(__tglContext, target, attachment, renderbuffertarget, renderbuffer)
#define glFramebufferTexture1D(target, attachment, textarget, texture, level) GLFramebufferTexture1D(__tglContext, target, attachment, textarget, texture, level)
#define glFramebufferTexture1DEXT(target, attachment, textarget, texture, level) GLFramebufferTexture1D(__tglContext, target, attachment, textarget, texture, level)
#define glFramebufferTexture2D(target, attachment, textarget, texture, level) GLFramebufferTexture2D(__tglContext, target, attachment, textarget, texture, level)
#define glFramebufferTexture2DEXT(target, attachment, textarget, texture, level) GLFramebufferTexture2D(__tglContext, target, attachment, textarget, texture, level)
#define glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset) GLFramebufferTexture3D(__tglContext, target, attachment, textarget, texture, level, zoffset)
#define glFramebufferTexture3DEXT(target, attachment, textarget, texture, level, zoffset) GLFramebufferTexture3D(__tglContext, target, attachment, textarget, texture, level, zoffset)
#define glFramebufferTextureLayer(target, attachment, texture, level, layer) GLFramebufferTextureLayer(__tglContext, target, attachment, texture, level, layer)
#define glFrontFace(mode) GLFrontFace(__tglContext, mode)
#define glFrustum(left, right, bottom, top, zNear, zFar) GLFrustum(__tglContext, left, right, bottom, top, zNear, zFar)
#define glGenBuffers(n, buffers) GLGenBuffers(__tglContext, n, buffers)
#define glGenBuffersARB(n, buffers) GLGenBuffers(__tglContext, n, buffers)
#define glGenFragmentShadersATI(range) GLGenFragmentShadersATI(__tglContext, range)
#define glGenFramebuffers(n, framebuffers) GLGenFramebuffers(__tglContext, n, framebuffers)
#define glGenFramebuffersEXT(n, framebuffers) GLGenFramebuffers(__tglContext, n, framebuffers)
#define glGenLists(range) GLGenLists(__tglContext, range)
#define glGenProgramsARB(n, programs) GLGenProgramsARB(__tglContext, n, programs)
#define glGenQueries(n, ids) GLGenQueries(__tglContext, n, ids)
#define glGenQueriesARB(n, ids) GLGenQueries(__tglContext, n, ids)
#define glGenRenderbuffers(n, renderbuffers) GLGenRenderbuffers(__tglContext, n, renderbuffers)
#define glGenRenderbuffersEXT(n, renderbuffers) GLGenRenderbuffers(__tglContext, n, renderbuffers)
#define glGenTextures(n, textures) GLGenTextures(__tglContext, n, textures)
#define glGenerateMipmap(target) GLGenerateMipmap(__tglContext, target)
#define glGenerateMipmapEXT(target) GLGenerateMipmap(__tglContext, target)
#define glGetActiveAttrib(program, index, bufSize, length, size, type, name) GLGetActiveAttrib(__tglContext, program, index, bufSize, length, size, type, name)
#define glGetActiveAttribARB(programObj, index, maxLength, length, size, type, name) GLGetActiveAttrib(__tglContext, programObj, index, maxLength, length, size, type, name)
#define glGetActiveUniform(program, index, bufSize, length, size, type, name) GLGetActiveUniform(__tglContext, program, index, bufSize, length, size, type, name)
#define glGetActiveUniformARB(programObj, index, maxLength, length, size, type, name) GLGetActiveUniform(__tglContext, programObj, index, maxLength, length, size, type, name)
#define glGetAttachedObjectsARB(containerObj, maxCount, count, obj) GLGetAttachedObjectsARB(__tglContext, containerObj, maxCount, count, obj)
#define glGetAttachedShaders(program, maxCount, count, shaders) GLGetAttachedShaders(__tglContext, program, maxCount, count, shaders)
#define glGetAttribLocation(program, name) GLGetAttribLocation(__tglContext, program, name)
#define glGetAttribLocationARB(programObj, name) GLGetAttribLocation(__tglContext, programObj, name)
#define glGetBooleanv(pname, data) GLGetBooleanv(__tglContext, pname, data)
#define glGetBufferParameteriv(target, pname, params) GLGetBufferParameteriv(__tglContext, target, pname, params)
#define glGetBufferParameterivARB(target, pname, params) GLGetBufferParameteriv(__tglContext, target, pname, params)
#define glGetBufferPointerv(target, pname, params) GLGetBufferPointerv(__tglContext, target, pname, params)
#define glGetBufferPointervARB(target, pname, params) GLGetBufferPointerv(__tglContext, target, pname, params)
#define glGetBufferSubData(target, offset, size, data) GLGetBufferSubData(__tglContext, target, offset, size, data)
#define glGetBufferSubDataARB(target, offset, size, data) GLGetBufferSubData(__tglContext, target, offset, size, data)
#define glGetClipPlane(plane, equation) GLGetClipPlane(__tglContext, plane, equation)
#define glGetColorTable(target, format, type, table) GLGetColorTable(__tglContext, target, format, type, table)
#define glGetColorTableEXT(target, format, type, data) GLGetColorTable(__tglContext, target, format, type, data)
#define glGetColorTableParameterfv(target, pname, params) GLGetColorTableParameterfv(__tglContext, target, pname, params)
#define glGetColorTableParameterfvEXT(target, pname, params) GLGetColorTableParameterfv(__tglContext, target, pname, params)
#define glGetColorTableParameterfvSGI(target, pname, params) GLGetColorTableParameterfvSGI(__tglContext, target, pname, params)
#define glGetColorTableParameteriv(target, pname, params) GLGetColorTableParameteriv(__tglContext, target, pname, params)
#define glGetColorTableParameterivEXT(target, pname, params) GLGetColorTableParameteriv(__tglContext, target, pname, params)
#define glGetColorTableParameterivSGI(target, pname, params) GLGetColorTableParameterivSGI(__tglContext, target, pname, params)
#define glGetColorTableSGI(target, format, type, table) GLGetColorTableSGI(__tglContext, target, format, type, table)
#define glGetCompressedTexImage(target, level, img) GLGetCompressedTexImage(__tglContext, target, level, img)
#define glGetCompressedTexImageARB(target, level, img) GLGetCompressedTexImage(__tglContext, target, level, img)
#define glGetConvolutionFilter(target, format, type, image) GLGetConvolutionFilter(__tglContext, target, format, type, image)
#define glGetConvolutionFilterEXT(target, format, type, image) GLGetConvolutionFilterEXT(__tglContext, target, format, type, image)
#define glGetConvolutionParameterfv(target, pname, params) GLGetConvolutionParameterfv(__tglContext, target, pname, params)
#define glGetConvolutionParameterfvEXT(target, pname, params) GLGetConvolutionParameterfvEXT(__tglContext, target, pname, params)
#define glGetConvolutionParameteriv(target, pname, params) GLGetConvolutionParameteriv(__tglContext, target, pname, params)
#define glGetConvolutionParameterivEXT(target, pname, params) GLGetConvolutionParameterivEXT(__tglContext, target, pname, params)
#define glGetDoublev(pname, data) GLGetDoublev(__tglContext, pname, data)
#define glGetError() GLGetError(__tglContext)
#define glGetFloatv(pname, data) GLGetFloatv(__tglContext, pname, data)
#define glGetFramebufferAttachmentParameteriv(target, attachment, pname, params) GLGetFramebufferAttachmentParameteriv(__tglContext, target, attachment, pname, params)
#define glGetFramebufferAttachmentParameterivEXT(target, attachment, pname, params) GLGetFramebufferAttachmentParameteriv(__tglContext, target, attachment, pname, params)
#define glGetHandleARB(pname) GLGetHandleARB(__tglContext, pname)
#define glGetHistogram(target, reset, format, type, values) GLGetHistogram(__tglContext, target, reset, format, type, values)
#define glGetHistogramEXT(target, reset, format, type, values) GLGetHistogramEXT(__tglContext, target, reset, format, type, values)
#define glGetHistogramParameterfv(target, pname, params) GLGetHistogramParameterfv(__tglContext, target, pname, params)
#define glGetHistogramParameterfvEXT(target, pname, params) GLGetHistogramParameterfvEXT(__tglContext, target, pname, params)
#define glGetHistogramParameteriv(target, pname, params) GLGetHistogramParameteriv(__tglContext, target, pname, params)
#define glGetHistogramParameterivEXT(target, pname, params) GLGetHistogramParameterivEXT(__tglContext, target, pname, params)
#define glGetInfoLogARB(obj, maxLength, length, infoLog) GLGetInfoLogARB(__tglContext, obj, maxLength, length, infoLog)
#define glGetIntegerv(pname, data) GLGetIntegerv(__tglContext, pname, data)
#define glGetLightfv(light, pname, params) GLGetLightfv(__tglContext, light, pname, params)
#define glGetLightiv(light, pname, params) GLGetLightiv(__tglContext, light, pname, params)
#define glGetMapdv(target, query, v) GLGetMapdv(__tglContext, target, query, v)
#define glGetMapfv(target, query, v) GLGetMapfv(__tglContext, target, query, v)
#define glGetMapiv(target, query, v) GLGetMapiv(__tglContext, target, query, v)
#define glGetMaterialfv(face, pname, params) GLGetMaterialfv(__tglContext, face, pname, params)
#define glGetMaterialiv(face, pname, params) GLGetMaterialiv(__tglContext, face, pname, params)
#define glGetMinmax(target, reset, format, type, values) GLGetMinmax(__tglContext, target, reset, format, type, values)
#define glGetMinmaxEXT(target, reset, format, type, values) GLGetMinmaxEXT(__tglContext, target, reset, format, type, values)
#define glGetMinmaxParameterfv(target, pname, params) GLGetMinmaxParameterfv(__tglContext, target, pname, params)
#define glGetMinmaxParameterfvEXT(target, pname, params) GLGetMinmaxParameterfvEXT(__tglContext, target, pname, params)
#define glGetMinmaxParameteriv(target, pname, params) GLGetMinmaxParameteriv(__tglContext, target, pname, params)
#define glGetMinmaxParameterivEXT(target, pname, params) GLGetMinmaxParameterivEXT(__tglContext, target, pname, params)
#define glGetObjectParameterfvARB(obj, pname, params) GLGetObjectParameterfvARB(__tglContext, obj, pname, params)
#define glGetObjectParameterivARB(obj, pname, params) GLGetObjectParameterivARB(__tglContext, obj, pname, params)
#define glGetPixelMapfv(map, values) GLGetPixelMapfv(__tglContext, map, values)
#define glGetPixelMapuiv(map, values) GLGetPixelMapuiv(__tglContext, map, values)
#define glGetPixelMapusv(map, values) GLGetPixelMapusv(__tglContext, map, values)
#define glGetPointerv(pname, params) GLGetPointerv(__tglContext, pname, params)
#define glGetPolygonStipple(mask) GLGetPolygonStipple(__tglContext, mask)
#define glGetProgramEnvParameterdvARB(target, index, params) GLGetProgramEnvParameterdvARB(__tglContext, target, index, params)
#define glGetProgramEnvParameterfvARB(target, index, params) GLGetProgramEnvParameterfvARB(__tglContext, target, index, params)
#define glGetProgramInfoLog(program, bufSize, length, infoLog) GLGetProgramInfoLog(__tglContext, program, bufSize, length, infoLog)
#define glGetProgramLocalParameterdvARB(target, index, params) GLGetProgramLocalParameterdvARB(__tglContext, target, index, params)
#define glGetProgramLocalParameterfvARB(target, index, params) GLGetProgramLocalParameterfvARB(__tglContext, target, index, params)
#define glGetProgramStringARB(target, pname, string) GLGetProgramStringARB(__tglContext, target, pname, string)
#define glGetProgramiv(program, pname, params) GLGetProgramiv(__tglContext, program, pname, params)
#define glGetProgramivARB(target, pname, params) GLGetProgramivARB(__tglContext, target, pname, params)
#define glGetQueryObjectiv(id, pname, params) GLGetQueryObjectiv(__tglContext, id, pname, params)
#define glGetQueryObjectivARB(id, pname, params) GLGetQueryObjectiv(__tglContext, id, pname, params)
#define glGetQueryObjectuiv(id, pname, params) GLGetQueryObjectuiv(__tglContext, id, pname, params)
#define glGetQueryObjectuivARB(id, pname, params) GLGetQueryObjectuiv(__tglContext, id, pname, params)
#define glGetQueryiv(target, pname, params) GLGetQueryiv(__tglContext, target, pname, params)
#define glGetQueryivARB(target, pname, params) GLGetQueryiv(__tglContext, target, pname, params)
#define glGetRenderbufferParameteriv(target, pname, params) GLGetRenderbufferParameteriv(__tglContext, target, pname, params)
#define glGetRenderbufferParameterivEXT(target, pname, params) GLGetRenderbufferParameteriv(__tglContext, target, pname, params)
#define glGetSeparableFilter(target, format, type, row, column, span) GLGetSeparableFilter(__tglContext, target, format, type, row, column, span)
#define glGetSeparableFilterEXT(target, format, type, row, column, span) GLGetSeparableFilterEXT(__tglContext, target, format, type, row, column, span)
#define glGetShaderInfoLog(shader, bufSize, length, infoLog) GLGetShaderInfoLog(__tglContext, shader, bufSize, length, infoLog)
#define glGetShaderSource(shader, bufSize, length, source) GLGetShaderSource(__tglContext, shader, bufSize, length, source)
#define glGetShaderSourceARB(obj, maxLength, length, source) GLGetShaderSource(__tglContext, obj, maxLength, length, source)
#define glGetShaderiv(shader, pname, params) GLGetShaderiv(__tglContext, shader, pname, params)
#define glGetString(name) GLGetString(__tglContext, name)
#define glGetTexEnvfv(target, pname, params) GLGetTexEnvfv(__tglContext, target, pname, params)
#define glGetTexEnviv(target, pname, params) GLGetTexEnviv(__tglContext, target, pname, params)
#define glGetTexGendv(coord, pname, params) GLGetTexGendv(__tglContext, coord, pname, params)
#define glGetTexGenfv(coord, pname, params) GLGetTexGenfv(__tglContext, coord, pname, params)
#define glGetTexGeniv(coord, pname, params) GLGetTexGeniv(__tglContext, coord, pname, params)
#define glGetTexImage(target, level, format, type, pixels) GLGetTexImage(__tglContext, target, level, format, type, pixels)
#define glGetTexLevelParameterfv(target, level, pname, params) GLGetTexLevelParameterfv(__tglContext, target, level, pname, params)
#define glGetTexLevelParameteriv(target, level, pname, params) GLGetTexLevelParameteriv(__tglContext, target, level, pname, params)
#define glGetTexParameterIivEXT(target, pname, params) GLGetTexParameterIiv(__tglContext, target, pname, params)
#define glGetTexParameterIuivEXT(target, pname, params) GLGetTexParameterIuiv(__tglContext, target, pname, params)
#define glGetTexParameterfv(target, pname, params) GLGetTexParameterfv(__tglContext, target, pname, params)
#define glGetTexParameteriv(target, pname, params) GLGetTexParameteriv(__tglContext, target, pname, params)
#define glGetUniformLocation(program, name) GLGetUniformLocation(__tglContext, program, name)
#define glGetUniformLocationARB(programObj, name) GLGetUniformLocation(__tglContext, programObj, name)
#define glGetUniformfv(program, location, params) GLGetUniformfv(__tglContext, program, location, params)
#define glGetUniformfvARB(programObj, location, params) GLGetUniformfv(__tglContext, programObj, location, params)
#define glGetUniformiv(program, location, params) GLGetUniformiv(__tglContext, program, location, params)
#define glGetUniformivARB(programObj, location, params) GLGetUniformiv(__tglContext, programObj, location, params)
#define glGetVertexAttribPointerv(index, pname, pointer) GLGetVertexAttribPointerv(__tglContext, index, pname, pointer)
#define glGetVertexAttribPointervARB(index, pname, pointer) GLGetVertexAttribPointerv(__tglContext, index, pname, pointer)
#define glGetVertexAttribdv(index, pname, params) GLGetVertexAttribdv(__tglContext, index, pname, params)
#define glGetVertexAttribdvARB(index, pname, params) GLGetVertexAttribdv(__tglContext, index, pname, params)
#define glGetVertexAttribfv(index, pname, params) GLGetVertexAttribfv(__tglContext, index, pname, params)
#define glGetVertexAttribfvARB(index, pname, params) GLGetVertexAttribfv(__tglContext, index, pname, params)
#define glGetVertexAttribiv(index, pname, params) GLGetVertexAttribiv(__tglContext, index, pname, params)
#define glGetVertexAttribivARB(index, pname, params) GLGetVertexAttribiv(__tglContext, index, pname, params)
#define glHint(target, mode) GLHint(__tglContext, target, mode)
#define glHistogram(target, width, internalformat, sink) GLHistogram(__tglContext, target, width, internalformat, sink)
#define glHistogramEXT(target, width, internalformat, sink) GLHistogram(__tglContext, target, width, internalformat, sink)
#define glIndexMask(mask) GLIndexMask(__tglContext, mask)
#define glIndexPointer(type, stride, pointer) GLIndexPointer(__tglContext, type, stride, pointer)
#define glIndexd(c) GLIndexd(__tglContext, c)
#define glIndexdv(c) GLIndexdv(__tglContext, c)
#define glIndexf(c) GLIndexf(__tglContext, c)
#define glIndexfv(c) GLIndexfv(__tglContext, c)
#define glIndexi(c) GLIndexi(__tglContext, c)
#define glIndexiv(c) GLIndexiv(__tglContext, c)
#define glIndexs(c) GLIndexs(__tglContext, c)
#define glIndexsv(c) GLIndexsv(__tglContext, c)
#define glIndexub(c) GLIndexub(__tglContext, c)
#define glIndexubv(c) GLIndexubv(__tglContext, c)
#define glInitNames() GLInitNames(__tglContext)
#define glInterleavedArrays(format, stride, pointer) GLInterleavedArrays(__tglContext, format, stride, pointer)
#define glIsBuffer(buffer) GLIsBuffer(__tglContext, buffer)
#define glIsBufferARB(buffer) GLIsBuffer(__tglContext, buffer)
#define glIsEnabled(cap) GLIsEnabled(__tglContext, cap)
#define glIsFramebuffer(framebuffer) GLIsFramebuffer(__tglContext, framebuffer)
#define glIsFramebufferEXT(framebuffer) GLIsFramebuffer(__tglContext, framebuffer)
#define glIsList(list) GLIsList(__tglContext, list)
#define glIsProgram(program) GLIsProgram(__tglContext, program)
#define glIsProgramARB(program) GLIsProgramARB(__tglContext, program)
#define glIsQuery(id) GLIsQuery(__tglContext, id)
#define glIsQueryARB(id) GLIsQuery(__tglContext, id)
#define glIsRenderbuffer(renderbuffer) GLIsRenderbuffer(__tglContext, renderbuffer)
#define glIsRenderbufferEXT(renderbuffer) GLIsRenderbuffer(__tglContext, renderbuffer)
#define glIsShader(shader) GLIsShader(__tglContext, shader)
#define glIsTexture(texture) GLIsTexture(__tglContext, texture)
#define glLightModelf(pname, param) GLLightModelf(__tglContext, pname, param)
#define glLightModelfv(pname, params) GLLightModelfv(__tglContext, pname, params)
#define glLightModeli(pname, param) GLLightModeli(__tglContext, pname, param)
#define glLightModeliv(pname, params) GLLightModeliv(__tglContext, pname, params)
#define glLightf(light, pname, param) GLLightf(__tglContext, light, pname, param)
#define glLightfv(light, pname, params) GLLightfv(__tglContext, light, pname, params)
#define glLighti(light, pname, param) GLLighti(__tglContext, light, pname, param)
#define glLightiv(light, pname, params) GLLightiv(__tglContext, light, pname, params)
#define glLineStipple(factor, pattern) GLLineStipple(__tglContext, factor, pattern)
#define glLineWidth(width) GLLineWidth(__tglContext, width)
#define glLinkProgram(program) GLLinkProgram(__tglContext, program)
#define glLinkProgramARB(programObj) GLLinkProgram(__tglContext, programObj)
#define glListBase(base) GLListBase(__tglContext, base)
#define glLoadIdentity() GLLoadIdentity(__tglContext)
#define glLoadMatrixd(m) GLLoadMatrixd(__tglContext, m)
#define glLoadMatrixf(m) GLLoadMatrixf(__tglContext, m)
#define glLoadName(name) GLLoadName(__tglContext, name)
#define glLoadTransposeMatrixd(m) GLLoadTransposeMatrixd(__tglContext, m)
#define glLoadTransposeMatrixdARB(m) GLLoadTransposeMatrixd(__tglContext, m)
#define glLoadTransposeMatrixf(m) GLLoadTransposeMatrixf(__tglContext, m)
#define glLoadTransposeMatrixfARB(m) GLLoadTransposeMatrixf(__tglContext, m)
#define glLockArraysEXT(first, count) GLLockArraysEXT(__tglContext, first, count)
#define glLogicOp(opcode) GLLogicOp(__tglContext, opcode)
#define glMap1d(target, u1, u2, stride, order, points) GLMap1d(__tglContext, target, u1, u2, stride, order, points)
#define glMap1f(target, u1, u2, stride, order, points) GLMap1f(__tglContext, target, u1, u2, stride, order, points)
#define glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) GLMap2d(__tglContext, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points)
#define glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) GLMap2f(__tglContext, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points)
#define glMapBuffer(target, access) GLMapBuffer(__tglContext, target, access)
#define glMapBufferARB(target, access) GLMapBuffer(__tglContext, target, access)
#define glMapGrid1d(un, u1, u2) GLMapGrid1d(__tglContext, un, u1, u2)
#define glMapGrid1f(un, u1, u2) GLMapGrid1f(__tglContext, un, u1, u2)
#define glMapGrid2d(un, u1, u2, vn, v1, v2) GLMapGrid2d(__tglContext, un, u1, u2, vn, v1, v2)
#define glMapGrid2f(un, u1, u2, vn, v1, v2) GLMapGrid2f(__tglContext, un, u1, u2, vn, v1, v2)
#define glMaterialf(face, pname, param) GLMaterialf(__tglContext, face, pname, param)
#define glMaterialfv(face, pname, params) GLMaterialfv(__tglContext, face, pname, params)
#define glMateriali(face, pname, param) GLMateriali(__tglContext, face, pname, param)
#define glMaterialiv(face, pname, params) GLMaterialiv(__tglContext, face, pname, params)
#define glMatrixIndexPointerARB(size, type, stride, pointer) GLMatrixIndexPointerARB(__tglContext, size, type, stride, pointer)
#define glMatrixIndexubvARB(size, indices) GLMatrixIndexubvARB(__tglContext, size, indices)
#define glMatrixIndexuivARB(size, indices) GLMatrixIndexuivARB(__tglContext, size, indices)
#define glMatrixIndexusvARB(size, indices) GLMatrixIndexusvARB(__tglContext, size, indices)
#define glMatrixMode(mode) GLMatrixMode(__tglContext, mode)
#define glMinmax(target, internalformat, sink) GLMinmax(__tglContext, target, internalformat, sink)
#define glMinmaxEXT(target, internalformat, sink) GLMinmax(__tglContext, target, internalformat, sink)
#define glMultMatrixd(m) GLMultMatrixd(__tglContext, m)
#define glMultMatrixf(m) GLMultMatrixf(__tglContext, m)
#define glMultTransposeMatrixd(m) GLMultTransposeMatrixd(__tglContext, m)
#define glMultTransposeMatrixdARB(m) GLMultTransposeMatrixd(__tglContext, m)
#define glMultTransposeMatrixf(m) GLMultTransposeMatrixf(__tglContext, m)
#define glMultTransposeMatrixfARB(m) GLMultTransposeMatrixf(__tglContext, m)
#define glMultiDrawArrays(mode, first, count, drawcount) GLMultiDrawArrays(__tglContext, mode, first, count, drawcount)
#define glMultiDrawArraysEXT(mode, first, count, primcount) GLMultiDrawArrays(__tglContext, mode, first, count, primcount)
#define glMultiDrawElements(mode, count, type, indices, drawcount) GLMultiDrawElements(__tglContext, mode, count, type, indices, drawcount)
#define glMultiDrawElementsEXT(mode, count, type, indices, primcount) GLMultiDrawElements(__tglContext, mode, count, type, indices, primcount)
#define glMultiTexCoord1d(target, s) GLMultiTexCoord1d(__tglContext, target, s)
#define glMultiTexCoord1dARB(target, s) GLMultiTexCoord1d(__tglContext, target, s)
#define glMultiTexCoord1dv(target, v) GLMultiTexCoord1dv(__tglContext, target, v)
#define glMultiTexCoord1dvARB(target, v) GLMultiTexCoord1dv(__tglContext, target, v)
#define glMultiTexCoord1f(target, s) GLMultiTexCoord1f(__tglContext, target, s)
#define glMultiTexCoord1fARB(target, s) GLMultiTexCoord1f(__tglContext, target, s)
#define glMultiTexCoord1fv(target, v) GLMultiTexCoord1fv(__tglContext, target, v)
#define glMultiTexCoord1fvARB(target, v) GLMultiTexCoord1fv(__tglContext, target, v)
#define glMultiTexCoord1i(target, s) GLMultiTexCoord1i(__tglContext, target, s)
#define glMultiTexCoord1iARB(target, s) GLMultiTexCoord1i(__tglContext, target, s)
#define glMultiTexCoord1iv(target, v) GLMultiTexCoord1iv(__tglContext, target, v)
#define glMultiTexCoord1ivARB(target, v) GLMultiTexCoord1iv(__tglContext, target, v)
#define glMultiTexCoord1s(target, s) GLMultiTexCoord1s(__tglContext, target, s)
#define glMultiTexCoord1sARB(target, s) GLMultiTexCoord1s(__tglContext, target, s)
#define glMultiTexCoord1sv(target, v) GLMultiTexCoord1sv(__tglContext, target, v)
#define glMultiTexCoord1svARB(target, v) GLMultiTexCoord1sv(__tglContext, target, v)
#define glMultiTexCoord2d(target, s, t) GLMultiTexCoord2d(__tglContext, target, s, t)
#define glMultiTexCoord2dARB(target, s, t) GLMultiTexCoord2d(__tglContext, target, s, t)
#define glMultiTexCoord2dv(target, v) GLMultiTexCoord2dv(__tglContext, target, v)
#define glMultiTexCoord2dvARB(target, v) GLMultiTexCoord2dv(__tglContext, target, v)
#define glMultiTexCoord2f(target, s, t) GLMultiTexCoord2f(__tglContext, target, s, t)
#define glMultiTexCoord2fARB(target, s, t) GLMultiTexCoord2f(__tglContext, target, s, t)
#define glMultiTexCoord2fv(target, v) GLMultiTexCoord2fv(__tglContext, target, v)
#define glMultiTexCoord2fvARB(target, v) GLMultiTexCoord2fv(__tglContext, target, v)
#define glMultiTexCoord2i(target, s, t) GLMultiTexCoord2i(__tglContext, target, s, t)
#define glMultiTexCoord2iARB(target, s, t) GLMultiTexCoord2i(__tglContext, target, s, t)
#define glMultiTexCoord2iv(target, v) GLMultiTexCoord2iv(__tglContext, target, v)
#define glMultiTexCoord2ivARB(target, v) GLMultiTexCoord2iv(__tglContext, target, v)
#define glMultiTexCoord2s(target, s, t) GLMultiTexCoord2s(__tglContext, target, s, t)
#define glMultiTexCoord2sARB(target, s, t) GLMultiTexCoord2s(__tglContext, target, s, t)
#define glMultiTexCoord2sv(target, v) GLMultiTexCoord2sv(__tglContext, target, v)
#define glMultiTexCoord2svARB(target, v) GLMultiTexCoord2sv(__tglContext, target, v)
#define glMultiTexCoord3d(target, s, t, r) GLMultiTexCoord3d(__tglContext, target, s, t, r)
#define glMultiTexCoord3dARB(target, s, t, r) GLMultiTexCoord3d(__tglContext, target, s, t, r)
#define glMultiTexCoord3dv(target, v) GLMultiTexCoord3dv(__tglContext, target, v)
#define glMultiTexCoord3dvARB(target, v) GLMultiTexCoord3dv(__tglContext, target, v)
#define glMultiTexCoord3f(target, s, t, r) GLMultiTexCoord3f(__tglContext, target, s, t, r)
#define glMultiTexCoord3fARB(target, s, t, r) GLMultiTexCoord3f(__tglContext, target, s, t, r)
#define glMultiTexCoord3fv(target, v) GLMultiTexCoord3fv(__tglContext, target, v)
#define glMultiTexCoord3fvARB(target, v) GLMultiTexCoord3fv(__tglContext, target, v)
#define glMultiTexCoord3i(target, s, t, r) GLMultiTexCoord3i(__tglContext, target, s, t, r)
#define glMultiTexCoord3iARB(target, s, t, r) GLMultiTexCoord3i(__tglContext, target, s, t, r)
#define glMultiTexCoord3iv(target, v) GLMultiTexCoord3iv(__tglContext, target, v)
#define glMultiTexCoord3ivARB(target, v) GLMultiTexCoord3iv(__tglContext, target, v)
#define glMultiTexCoord3s(target, s, t, r) GLMultiTexCoord3s(__tglContext, target, s, t, r)
#define glMultiTexCoord3sARB(target, s, t, r) GLMultiTexCoord3s(__tglContext, target, s, t, r)
#define glMultiTexCoord3sv(target, v) GLMultiTexCoord3sv(__tglContext, target, v)
#define glMultiTexCoord3svARB(target, v) GLMultiTexCoord3sv(__tglContext, target, v)
#define glMultiTexCoord4d(target, s, t, r, q) GLMultiTexCoord4d(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4dARB(target, s, t, r, q) GLMultiTexCoord4d(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4dv(target, v) GLMultiTexCoord4dv(__tglContext, target, v)
#define glMultiTexCoord4dvARB(target, v) GLMultiTexCoord4dv(__tglContext, target, v)
#define glMultiTexCoord4f(target, s, t, r, q) GLMultiTexCoord4f(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4fARB(target, s, t, r, q) GLMultiTexCoord4f(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4fv(target, v) GLMultiTexCoord4fv(__tglContext, target, v)
#define glMultiTexCoord4fvARB(target, v) GLMultiTexCoord4fv(__tglContext, target, v)
#define glMultiTexCoord4i(target, s, t, r, q) GLMultiTexCoord4i(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4iARB(target, s, t, r, q) GLMultiTexCoord4i(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4iv(target, v) GLMultiTexCoord4iv(__tglContext, target, v)
#define glMultiTexCoord4ivARB(target, v) GLMultiTexCoord4iv(__tglContext, target, v)
#define glMultiTexCoord4s(target, s, t, r, q) GLMultiTexCoord4s(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4sARB(target, s, t, r, q) GLMultiTexCoord4s(__tglContext, target, s, t, r, q)
#define glMultiTexCoord4sv(target, v) GLMultiTexCoord4sv(__tglContext, target, v)
#define glMultiTexCoord4svARB(target, v) GLMultiTexCoord4sv(__tglContext, target, v)
#define glNewList(list, mode) GLNewList(__tglContext, list, mode)
#define glNormal3b(nx, ny, nz) GLNormal3b(__tglContext, nx, ny, nz)
#define glNormal3bv(v) GLNormal3bv(__tglContext, v)
#define glNormal3d(nx, ny, nz) GLNormal3d(__tglContext, nx, ny, nz)
#define glNormal3dv(v) GLNormal3dv(__tglContext, v)
#define glNormal3f(nx, ny, nz) GLNormal3f(__tglContext, nx, ny, nz)
#define glNormal3fv(v) GLNormal3fv(__tglContext, v)
#define glNormal3i(nx, ny, nz) GLNormal3i(__tglContext, nx, ny, nz)
#define glNormal3iv(v) GLNormal3iv(__tglContext, v)
#define glNormal3s(nx, ny, nz) GLNormal3s(__tglContext, nx, ny, nz)
#define glNormal3sv(v) GLNormal3sv(__tglContext, v)
#define glNormalPointer(type, stride, pointer) GLNormalPointer(__tglContext, type, stride, pointer)
#define glOrtho(left, right, bottom, top, zNear, zFar) GLOrtho(__tglContext, left, right, bottom, top, zNear, zFar)
#define glPassTexCoordATI(dst, coord, swizzle) GLPassTexCoordATI(__tglContext, dst, coord, swizzle)
#define glPassThrough(token) GLPassThrough(__tglContext, token)
#define glPixelMapfv(map, mapsize, values) GLPixelMapfv(__tglContext, map, mapsize, values)
#define glPixelMapuiv(map, mapsize, values) GLPixelMapuiv(__tglContext, map, mapsize, values)
#define glPixelMapusv(map, mapsize, values) GLPixelMapusv(__tglContext, map, mapsize, values)
#define glPixelStoref(pname, param) GLPixelStoref(__tglContext, pname, param)
#define glPixelStorei(pname, param) GLPixelStorei(__tglContext, pname, param)
#define glPixelTransferf(pname, param) GLPixelTransferf(__tglContext, pname, param)
#define glPixelTransferi(pname, param) GLPixelTransferi(__tglContext, pname, param)
#define glPixelZoom(xfactor, yfactor) GLPixelZoom(__tglContext, xfactor, yfactor)
#define glPointParameterf(pname, param) GLPointParameterf(__tglContext, pname, param)
#define glPointParameterfARB(pname, param) GLPointParameterf(__tglContext, pname, param)
#define glPointParameterfEXT(pname, param) GLPointParameterf(__tglContext, pname, param)
#define glPointParameterfv(pname, params) GLPointParameterfv(__tglContext, pname, params)
#define glPointParameterfvARB(pname, params) GLPointParameterfv(__tglContext, pname, params)
#define glPointParameterfvEXT(pname, params) GLPointParameterfv(__tglContext, pname, params)
#define glPointParameteri(pname, param) GLPointParameteri(__tglContext, pname, param)
#define glPointParameteriv(pname, params) GLPointParameteriv(__tglContext, pname, params)
#define glPointSize(size) GLPointSize(__tglContext, size)
#define glPolygonMode(face, mode) GLPolygonMode(__tglContext, face, mode)
#define glPolygonOffset(factor, units) GLPolygonOffset(__tglContext, factor, units)
#define glPolygonStipple(mask) GLPolygonStipple(__tglContext, mask)
#define glPopAttrib() GLPopAttrib(__tglContext)
#define glPopClientAttrib() GLPopClientAttrib(__tglContext)
#define glPopMatrix() GLPopMatrix(__tglContext)
#define glPopName() GLPopName(__tglContext)
#define glPrioritizeTextures(n, textures, priorities) GLPrioritizeTextures(__tglContext, n, textures, priorities)
#define glProgramEnvParameter4dARB(target, index, x, y, z, w) GLProgramEnvParameter4dARB(__tglContext, target, index, x, y, z, w)
#define glProgramEnvParameter4dvARB(target, index, params) GLProgramEnvParameter4dvARB(__tglContext, target, index, params)
#define glProgramEnvParameter4fARB(target, index, x, y, z, w) GLProgramEnvParameter4fARB(__tglContext, target, index, x, y, z, w)
#define glProgramEnvParameter4fvARB(target, index, params) GLProgramEnvParameter4fvARB(__tglContext, target, index, params)
#define glProgramLocalParameter4dARB(target, index, x, y, z, w) GLProgramLocalParameter4dARB(__tglContext, target, index, x, y, z, w)
#define glProgramLocalParameter4dvARB(target, index, params) GLProgramLocalParameter4dvARB(__tglContext, target, index, params)
#define glProgramLocalParameter4fARB(target, index, x, y, z, w) GLProgramLocalParameter4fARB(__tglContext, target, index, x, y, z, w)
#define glProgramLocalParameter4fvARB(target, index, params) GLProgramLocalParameter4fvARB(__tglContext, target, index, params)
#define glProgramStringARB(target, format, len, string) GLProgramStringARB(__tglContext, target, format, len, string)
#define glPushAttrib(mask) GLPushAttrib(__tglContext, mask)
#define glPushClientAttrib(mask) GLPushClientAttrib(__tglContext, mask)
#define glPushMatrix() GLPushMatrix(__tglContext)
#define glPushName(name) GLPushName(__tglContext, name)
#define glRasterPos2d(x, y) GLRasterPos2d(__tglContext, x, y)
#define glRasterPos2dv(v) GLRasterPos2dv(__tglContext, v)
#define glRasterPos2f(x, y) GLRasterPos2f(__tglContext, x, y)
#define glRasterPos2fv(v) GLRasterPos2fv(__tglContext, v)
#define glRasterPos2i(x, y) GLRasterPos2i(__tglContext, x, y)
#define glRasterPos2iv(v) GLRasterPos2iv(__tglContext, v)
#define glRasterPos2s(x, y) GLRasterPos2s(__tglContext, x, y)
#define glRasterPos2sv(v) GLRasterPos2sv(__tglContext, v)
#define glRasterPos3d(x, y, z) GLRasterPos3d(__tglContext, x, y, z)
#define glRasterPos3dv(v) GLRasterPos3dv(__tglContext, v)
#define glRasterPos3f(x, y, z) GLRasterPos3f(__tglContext, x, y, z)
#define glRasterPos3fv(v) GLRasterPos3fv(__tglContext, v)
#define glRasterPos3i(x, y, z) GLRasterPos3i(__tglContext, x, y, z)
#define glRasterPos3iv(v) GLRasterPos3iv(__tglContext, v)
#define glRasterPos3s(x, y, z) GLRasterPos3s(__tglContext, x, y, z)
#define glRasterPos3sv(v) GLRasterPos3sv(__tglContext, v)
#define glRasterPos4d(x, y, z, w) GLRasterPos4d(__tglContext, x, y, z, w)
#define glRasterPos4dv(v) GLRasterPos4dv(__tglContext, v)
#define glRasterPos4f(x, y, z, w) GLRasterPos4f(__tglContext, x, y, z, w)
#define glRasterPos4fv(v) GLRasterPos4fv(__tglContext, v)
#define glRasterPos4i(x, y, z, w) GLRasterPos4i(__tglContext, x, y, z, w)
#define glRasterPos4iv(v) GLRasterPos4iv(__tglContext, v)
#define glRasterPos4s(x, y, z, w) GLRasterPos4s(__tglContext, x, y, z, w)
#define glRasterPos4sv(v) GLRasterPos4sv(__tglContext, v)
#define glReadBuffer(src) GLReadBuffer(__tglContext, src)
#define glReadPixels(x, y, width, height, format, type, pixels) GLReadPixels(__tglContext, x, y, width, height, format, type, pixels)
#define glRectd(x1, y1, x2, y2) GLRectd(__tglContext, x1, y1, x2, y2)
#define glRectdv(v1, v2) GLRectdv(__tglContext, v1, v2)
#define glRectf(x1, y1, x2, y2) GLRectf(__tglContext, x1, y1, x2, y2)
#define glRectfv(v1, v2) GLRectfv(__tglContext, v1, v2)
#define glRecti(x1, y1, x2, y2) GLRecti(__tglContext, x1, y1, x2, y2)
#define glRectiv(v1, v2) GLRectiv(__tglContext, v1, v2)
#define glRects(x1, y1, x2, y2) GLRects(__tglContext, x1, y1, x2, y2)
#define glRectsv(v1, v2) GLRectsv(__tglContext, v1, v2)
#define glRenderMode(mode) GLRenderMode(__tglContext, mode)
#define glRenderbufferStorage(target, internalformat, width, height) GLRenderbufferStorage(__tglContext, target, internalformat, width, height)
#define glRenderbufferStorageEXT(target, internalformat, width, height) GLRenderbufferStorage(__tglContext, target, internalformat, width, height)
#define glRenderbufferStorageMultisample(target, samples, internalformat, width, height) GLRenderbufferStorageMultisample(__tglContext, target, samples, internalformat, width, height)
#define glResetHistogram(target) GLResetHistogram(__tglContext, target)
#define glResetHistogramEXT(target) GLResetHistogram(__tglContext, target)
#define glResetMinmax(target) GLResetMinmax(__tglContext, target)
#define glResetMinmaxEXT(target) GLResetMinmax(__tglContext, target)
#define glRotated(angle, x, y, z) GLRotated(__tglContext, angle, x, y, z)
#define glRotatef(angle, x, y, z) GLRotatef(__tglContext, angle, x, y, z)
#define glSampleCoverage(value, invert) GLSampleCoverage(__tglContext, value, invert)
#define glSampleCoverageARB(value, invert) GLSampleCoverage(__tglContext, value, invert)
#define glSampleMapATI(dst, interp, swizzle) GLSampleMapATI(__tglContext, dst, interp, swizzle)
#define glScaled(x, y, z) GLScaled(__tglContext, x, y, z)
#define glScalef(x, y, z) GLScalef(__tglContext, x, y, z)
#define glScissor(x, y, width, height) GLScissor(__tglContext, x, y, width, height)
#define glSecondaryColor3b(red, green, blue) GLSecondaryColor3b(__tglContext, red, green, blue)
#define glSecondaryColor3bEXT(red, green, blue) GLSecondaryColor3b(__tglContext, red, green, blue)
#define glSecondaryColor3bv(v) GLSecondaryColor3bv(__tglContext, v)
#define glSecondaryColor3bvEXT(v) GLSecondaryColor3bv(__tglContext, v)
#define glSecondaryColor3d(red, green, blue) GLSecondaryColor3d(__tglContext, red, green, blue)
#define glSecondaryColor3dEXT(red, green, blue) GLSecondaryColor3d(__tglContext, red, green, blue)
#define glSecondaryColor3dv(v) GLSecondaryColor3dv(__tglContext, v)
#define glSecondaryColor3dvEXT(v) GLSecondaryColor3dv(__tglContext, v)
#define glSecondaryColor3f(red, green, blue) GLSecondaryColor3f(__tglContext, red, green, blue)
#define glSecondaryColor3fEXT(red, green, blue) GLSecondaryColor3f(__tglContext, red, green, blue)
#define glSecondaryColor3fv(v) GLSecondaryColor3fv(__tglContext, v)
#define glSecondaryColor3fvEXT(v) GLSecondaryColor3fv(__tglContext, v)
#define glSecondaryColor3i(red, green, blue) GLSecondaryColor3i(__tglContext, red, green, blue)
#define glSecondaryColor3iEXT(red, green, blue) GLSecondaryColor3i(__tglContext, red, green, blue)
#define glSecondaryColor3iv(v) GLSecondaryColor3iv(__tglContext, v)
#define glSecondaryColor3ivEXT(v) GLSecondaryColor3iv(__tglContext, v)
#define glSecondaryColor3s(red, green, blue) GLSecondaryColor3s(__tglContext, red, green, blue)
#define glSecondaryColor3sEXT(red, green, blue) GLSecondaryColor3s(__tglContext, red, green, blue)
#define glSecondaryColor3sv(v) GLSecondaryColor3sv(__tglContext, v)
#define glSecondaryColor3svEXT(v) GLSecondaryColor3sv(__tglContext, v)
#define glSecondaryColor3ub(red, green, blue) GLSecondaryColor3ub(__tglContext, red, green, blue)
#define glSecondaryColor3ubEXT(red, green, blue) GLSecondaryColor3ub(__tglContext, red, green, blue)
#define glSecondaryColor3ubv(v) GLSecondaryColor3ubv(__tglContext, v)
#define glSecondaryColor3ubvEXT(v) GLSecondaryColor3ubv(__tglContext, v)
#define glSecondaryColor3ui(red, green, blue) GLSecondaryColor3ui(__tglContext, red, green, blue)
#define glSecondaryColor3uiEXT(red, green, blue) GLSecondaryColor3ui(__tglContext, red, green, blue)
#define glSecondaryColor3uiv(v) GLSecondaryColor3uiv(__tglContext, v)
#define glSecondaryColor3uivEXT(v) GLSecondaryColor3uiv(__tglContext, v)
#define glSecondaryColor3us(red, green, blue) GLSecondaryColor3us(__tglContext, red, green, blue)
#define glSecondaryColor3usEXT(red, green, blue) GLSecondaryColor3us(__tglContext, red, green, blue)
#define glSecondaryColor3usv(v) GLSecondaryColor3usv(__tglContext, v)
#define glSecondaryColor3usvEXT(v) GLSecondaryColor3usv(__tglContext, v)
#define glSecondaryColorPointer(size, type, stride, pointer) GLSecondaryColorPointer(__tglContext, size, type, stride, pointer)
#define glSecondaryColorPointerEXT(size, type, stride, pointer) GLSecondaryColorPointer(__tglContext, size, type, stride, pointer)
#define glSelectBuffer(size, buffer) GLSelectBuffer(__tglContext, size, buffer)
#define glSeparableFilter2D(target, internalformat, width, height, format, type, row, column) GLSeparableFilter2D(__tglContext, target, internalformat, width, height, format, type, row, column)
#define glSeparableFilter2DEXT(target, internalformat, width, height, format, type, row, column) GLSeparableFilter2D(__tglContext, target, internalformat, width, height, format, type, row, column)
#define glSetFragmentShaderConstantATI(dst, value) GLSetFragmentShaderConstantATI(__tglContext, dst, value)
#define glShadeModel(mode) GLShadeModel(__tglContext, mode)
#define glShaderSource(shader, count, string, length) GLShaderSource(__tglContext, shader, count, string, length)
#define glShaderSourceARB(shaderObj, count, string, length) GLShaderSource(__tglContext, shaderObj, count, string, length)
#define glStencilFunc(func, ref, mask) GLStencilFunc(__tglContext, func, ref, mask)
#define glStencilFuncSeparate(face, func, ref, mask) GLStencilFuncSeparate(__tglContext, face, func, ref, mask)
#define glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask) GLStencilFuncSeparateATI(__tglContext, frontfunc, backfunc, ref, mask)
#define glStencilMask(mask) GLStencilMask(__tglContext, mask)
#define glStencilMaskSeparate(face, mask) GLStencilMaskSeparate(__tglContext, face, mask)
#define glStencilOp(fail, zfail, zpass) GLStencilOp(__tglContext, fail, zfail, zpass)
#define glStencilOpSeparate(face, sfail, dpfail, dppass) GLStencilOpSeparate(__tglContext, face, sfail, dpfail, dppass)
#define glStencilOpSeparateATI(face, sfail, dpfail, dppass) GLStencilOpSeparate(__tglContext, face, sfail, dpfail, dppass)
#define glTexCoord1d(s) GLTexCoord1d(__tglContext, s)
#define glTexCoord1dv(v) GLTexCoord1dv(__tglContext, v)
#define glTexCoord1f(s) GLTexCoord1f(__tglContext, s)
#define glTexCoord1fv(v) GLTexCoord1fv(__tglContext, v)
#define glTexCoord1i(s) GLTexCoord1i(__tglContext, s)
#define glTexCoord1iv(v) GLTexCoord1iv(__tglContext, v)
#define glTexCoord1s(s) GLTexCoord1s(__tglContext, s)
#define glTexCoord1sv(v) GLTexCoord1sv(__tglContext, v)
#define glTexCoord2d(s, t) GLTexCoord2d(__tglContext, s, t)
#define glTexCoord2dv(v) GLTexCoord2dv(__tglContext, v)
#define glTexCoord2f(s, t) GLTexCoord2f(__tglContext, s, t)
#define glTexCoord2fv(v) GLTexCoord2fv(__tglContext, v)
#define glTexCoord2i(s, t) GLTexCoord2i(__tglContext, s, t)
#define glTexCoord2iv(v) GLTexCoord2iv(__tglContext, v)
#define glTexCoord2s(s, t) GLTexCoord2s(__tglContext, s, t)
#define glTexCoord2sv(v) GLTexCoord2sv(__tglContext, v)
#define glTexCoord3d(s, t, r) GLTexCoord3d(__tglContext, s, t, r)
#define glTexCoord3dv(v) GLTexCoord3dv(__tglContext, v)
#define glTexCoord3f(s, t, r) GLTexCoord3f(__tglContext, s, t, r)
#define glTexCoord3fv(v) GLTexCoord3fv(__tglContext, v)
#define glTexCoord3i(s, t, r) GLTexCoord3i(__tglContext, s, t, r)
#define glTexCoord3iv(v) GLTexCoord3iv(__tglContext, v)
#define glTexCoord3s(s, t, r) GLTexCoord3s(__tglContext, s, t, r)
#define glTexCoord3sv(v) GLTexCoord3sv(__tglContext, v)
#define glTexCoord4d(s, t, r, q) GLTexCoord4d(__tglContext, s, t, r, q)
#define glTexCoord4dv(v) GLTexCoord4dv(__tglContext, v)
#define glTexCoord4f(s, t, r, q) GLTexCoord4f(__tglContext, s, t, r, q)
#define glTexCoord4fv(v) GLTexCoord4fv(__tglContext, v)
#define glTexCoord4i(s, t, r, q) GLTexCoord4i(__tglContext, s, t, r, q)
#define glTexCoord4iv(v) GLTexCoord4iv(__tglContext, v)
#define glTexCoord4s(s, t, r, q) GLTexCoord4s(__tglContext, s, t, r, q)
#define glTexCoord4sv(v) GLTexCoord4sv(__tglContext, v)
#define glTexCoordPointer(size, type, stride, pointer) GLTexCoordPointer(__tglContext, size, type, stride, pointer)
#define glTexEnvf(target, pname, param) GLTexEnvf(__tglContext, target, pname, param)
#define glTexEnvfv(target, pname, params) GLTexEnvfv(__tglContext, target, pname, params)
#define glTexEnvi(target, pname, param) GLTexEnvi(__tglContext, target, pname, param)
#define glTexEnviv(target, pname, params) GLTexEnviv(__tglContext, target, pname, params)
#define glTexGend(coord, pname, param) GLTexGend(__tglContext, coord, pname, param)
#define glTexGendv(coord, pname, params) GLTexGendv(__tglContext, coord, pname, params)
#define glTexGenf(coord, pname, param) GLTexGenf(__tglContext, coord, pname, param)
#define glTexGenfv(coord, pname, params) GLTexGenfv(__tglContext, coord, pname, params)
#define glTexGeni(coord, pname, param) GLTexGeni(__tglContext, coord, pname, param)
#define glTexGeniv(coord, pname, params) GLTexGeniv(__tglContext, coord, pname, params)
#define glTexImage1D(target, level, internalformat, width, border, format, type, pixels) GLTexImage1D(__tglContext, target, level, internalformat, width, border, format, type, pixels)
#define glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels) GLTexImage2D(__tglContext, target, level, internalformat, width, height, border, format, type, pixels)
#define glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels) GLTexImage3D(__tglContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
#define glTexImage3DEXT(target, level, internalformat, width, height, depth, border, format, type, pixels) GLTexImage3D(__tglContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
#define glTexParameterIivEXT(target, pname, params) GLTexParameterIiv(__tglContext, target, pname, params)
#define glTexParameterIuivEXT(target, pname, params) GLTexParameterIuiv(__tglContext, target, pname, params)
#define glTexParameterf(target, pname, param) GLTexParameterf(__tglContext, target, pname, param)
#define glTexParameterfv(target, pname, params) GLTexParameterfv(__tglContext, target, pname, params)
#define glTexParameteri(target, pname, param) GLTexParameteri(__tglContext, target, pname, param)
#define glTexParameteriv(target, pname, params) GLTexParameteriv(__tglContext, target, pname, params)
#define glTexSubImage1D(target, level, xoffset, width, format, type, pixels) GLTexSubImage1D(__tglContext, target, level, xoffset, width, format, type, pixels)
#define glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) GLTexSubImage2D(__tglContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
#define glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) GLTexSubImage3D(__tglContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
#define glTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) GLTexSubImage3D(__tglContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
#define glTranslated(x, y, z) GLTranslated(__tglContext, x, y, z)
#define glTranslatef(x, y, z) GLTranslatef(__tglContext, x, y, z)
#define glUniform1f(location, v0) GLUniform1f(__tglContext, location, v0)
#define glUniform1fARB(location, v0) GLUniform1f(__tglContext, location, v0)
#define glUniform1fv(location, count, value) GLUniform1fv(__tglContext, location, count, value)
#define glUniform1fvARB(location, count, value) GLUniform1fv(__tglContext, location, count, value)
#define glUniform1i(location, v0) GLUniform1i(__tglContext, location, v0)
#define glUniform1iARB(location, v0) GLUniform1i(__tglContext, location, v0)
#define glUniform1iv(location, count, value) GLUniform1iv(__tglContext, location, count, value)
#define glUniform1ivARB(location, count, value) GLUniform1iv(__tglContext, location, count, value)
#define glUniform1ui(location, v0) GLUniform1ui(__tglContext, location, v0)
#define glUniform1uiv(location, count, value) GLUniform1uiv(__tglContext, location, count, value)
#define glUniform2f(location, v0, v1) GLUniform2f(__tglContext, location, v0, v1)
#define glUniform2fARB(location, v0, v1) GLUniform2f(__tglContext, location, v0, v1)
#define glUniform2fv(location, count, value) GLUniform2fv(__tglContext, location, count, value)
#define glUniform2fvARB(location, count, value) GLUniform2fv(__tglContext, location, count, value)
#define glUniform2i(location, v0, v1) GLUniform2i(__tglContext, location, v0, v1)
#define glUniform2iARB(location, v0, v1) GLUniform2i(__tglContext, location, v0, v1)
#define glUniform2iv(location, count, value) GLUniform2iv(__tglContext, location, count, value)
#define glUniform2ivARB(location, count, value) GLUniform2iv(__tglContext, location, count, value)
#define glUniform2ui(location, v0, v1) GLUniform2ui(__tglContext, location, v0, v1)
#define glUniform2uiv(location, count, value) GLUniform2uiv(__tglContext, location, count, value)
#define glUniform3f(location, v0, v1, v2) GLUniform3f(__tglContext, location, v0, v1, v2)
#define glUniform3fARB(location, v0, v1, v2) GLUniform3f(__tglContext, location, v0, v1, v2)
#define glUniform3fv(location, count, value) GLUniform3fv(__tglContext, location, count, value)
#define glUniform3fvARB(location, count, value) GLUniform3fv(__tglContext, location, count, value)
#define glUniform3i(location, v0, v1, v2) GLUniform3i(__tglContext, location, v0, v1, v2)
#define glUniform3iARB(location, v0, v1, v2) GLUniform3i(__tglContext, location, v0, v1, v2)
#define glUniform3iv(location, count, value) GLUniform3iv(__tglContext, location, count, value)
#define glUniform3ivARB(location, count, value) GLUniform3iv(__tglContext, location, count, value)
#define glUniform3ui(location, v0, v1, v2) GLUniform3ui(__tglContext, location, v0, v1, v2)
#define glUniform3uiv(location, count, value) GLUniform3uiv(__tglContext, location, count, value)
#define glUniform4f(location, v0, v1, v2, v3) GLUniform4f(__tglContext, location, v0, v1, v2, v3)
#define glUniform4fARB(location, v0, v1, v2, v3) GLUniform4f(__tglContext, location, v0, v1, v2, v3)
#define glUniform4fv(location, count, value) GLUniform4fv(__tglContext, location, count, value)
#define glUniform4fvARB(location, count, value) GLUniform4fv(__tglContext, location, count, value)
#define glUniform4i(location, v0, v1, v2, v3) GLUniform4i(__tglContext, location, v0, v1, v2, v3)
#define glUniform4iARB(location, v0, v1, v2, v3) GLUniform4i(__tglContext, location, v0, v1, v2, v3)
#define glUniform4iv(location, count, value) GLUniform4iv(__tglContext, location, count, value)
#define glUniform4ivARB(location, count, value) GLUniform4iv(__tglContext, location, count, value)
#define glUniform4ui(location, v0, v1, v2, v3) GLUniform4ui(__tglContext, location, v0, v1, v2, v3)
#define glUniform4uiv(location, count, value) GLUniform4uiv(__tglContext, location, count, value)
#define glUniformMatrix2fv(location, count, transpose, value) GLUniformMatrix2fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix2fvARB(location, count, transpose, value) GLUniformMatrix2fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix2x3fv(location, count, transpose, value) GLUniformMatrix2x3fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix2x4fv(location, count, transpose, value) GLUniformMatrix2x4fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix3fv(location, count, transpose, value) GLUniformMatrix3fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix3fvARB(location, count, transpose, value) GLUniformMatrix3fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix3x2fv(location, count, transpose, value) GLUniformMatrix3x2fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix3x4fv(location, count, transpose, value) GLUniformMatrix3x4fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix4fv(location, count, transpose, value) GLUniformMatrix4fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix4fvARB(location, count, transpose, value) GLUniformMatrix4fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix4x2fv(location, count, transpose, value) GLUniformMatrix4x2fv(__tglContext, location, count, transpose, value)
#define glUniformMatrix4x3fv(location, count, transpose, value) GLUniformMatrix4x3fv(__tglContext, location, count, transpose, value)
#define glUnlockArraysEXT() GLUnlockArraysEXT(__tglContext)
#define glUnmapBuffer(target) GLUnmapBuffer(__tglContext, target)
#define glUnmapBufferARB(target) GLUnmapBuffer(__tglContext, target)
#define glUseProgram(program) GLUseProgram(__tglContext, program)
#define glUseProgramObjectARB(programObj) GLUseProgram(__tglContext, programObj)
#define glValidateProgram(program) GLValidateProgram(__tglContext, program)
#define glValidateProgramARB(programObj) GLValidateProgram(__tglContext, programObj)
#define glVertex2d(x, y) GLVertex2d(__tglContext, x, y)
#define glVertex2dv(v) GLVertex2dv(__tglContext, v)
#define glVertex2f(x, y) GLVertex2f(__tglContext, x, y)
#define glVertex2fv(v) GLVertex2fv(__tglContext, v)
#define glVertex2i(x, y) GLVertex2i(__tglContext, x, y)
#define glVertex2iv(v) GLVertex2iv(__tglContext, v)
#define glVertex2s(x, y) GLVertex2s(__tglContext, x, y)
#define glVertex2sv(v) GLVertex2sv(__tglContext, v)
#define glVertex3d(x, y, z) GLVertex3d(__tglContext, x, y, z)
#define glVertex3dv(v) GLVertex3dv(__tglContext, v)
#define glVertex3f(x, y, z) GLVertex3f(__tglContext, x, y, z)
#define glVertex3fv(v) GLVertex3fv(__tglContext, v)
#define glVertex3i(x, y, z) GLVertex3i(__tglContext, x, y, z)
#define glVertex3iv(v) GLVertex3iv(__tglContext, v)
#define glVertex3s(x, y, z) GLVertex3s(__tglContext, x, y, z)
#define glVertex3sv(v) GLVertex3sv(__tglContext, v)
#define glVertex4d(x, y, z, w) GLVertex4d(__tglContext, x, y, z, w)
#define glVertex4dv(v) GLVertex4dv(__tglContext, v)
#define glVertex4f(x, y, z, w) GLVertex4f(__tglContext, x, y, z, w)
#define glVertex4fv(v) GLVertex4fv(__tglContext, v)
#define glVertex4i(x, y, z, w) GLVertex4i(__tglContext, x, y, z, w)
#define glVertex4iv(v) GLVertex4iv(__tglContext, v)
#define glVertex4s(x, y, z, w) GLVertex4s(__tglContext, x, y, z, w)
#define glVertex4sv(v) GLVertex4sv(__tglContext, v)
#define glVertexAttrib1d(index, x) GLVertexAttrib1d(__tglContext, index, x)
#define glVertexAttrib1dARB(index, x) GLVertexAttrib1d(__tglContext, index, x)
#define glVertexAttrib1dv(index, v) GLVertexAttrib1dv(__tglContext, index, v)
#define glVertexAttrib1dvARB(index, v) GLVertexAttrib1dv(__tglContext, index, v)
#define glVertexAttrib1f(index, x) GLVertexAttrib1f(__tglContext, index, x)
#define glVertexAttrib1fARB(index, x) GLVertexAttrib1f(__tglContext, index, x)
#define glVertexAttrib1fv(index, v) GLVertexAttrib1fv(__tglContext, index, v)
#define glVertexAttrib1fvARB(index, v) GLVertexAttrib1fv(__tglContext, index, v)
#define glVertexAttrib1s(index, x) GLVertexAttrib1s(__tglContext, index, x)
#define glVertexAttrib1sARB(index, x) GLVertexAttrib1s(__tglContext, index, x)
#define glVertexAttrib1sv(index, v) GLVertexAttrib1sv(__tglContext, index, v)
#define glVertexAttrib1svARB(index, v) GLVertexAttrib1sv(__tglContext, index, v)
#define glVertexAttrib2d(index, x, y) GLVertexAttrib2d(__tglContext, index, x, y)
#define glVertexAttrib2dARB(index, x, y) GLVertexAttrib2d(__tglContext, index, x, y)
#define glVertexAttrib2dv(index, v) GLVertexAttrib2dv(__tglContext, index, v)
#define glVertexAttrib2dvARB(index, v) GLVertexAttrib2dv(__tglContext, index, v)
#define glVertexAttrib2f(index, x, y) GLVertexAttrib2f(__tglContext, index, x, y)
#define glVertexAttrib2fARB(index, x, y) GLVertexAttrib2f(__tglContext, index, x, y)
#define glVertexAttrib2fv(index, v) GLVertexAttrib2fv(__tglContext, index, v)
#define glVertexAttrib2fvARB(index, v) GLVertexAttrib2fv(__tglContext, index, v)
#define glVertexAttrib2s(index, x, y) GLVertexAttrib2s(__tglContext, index, x, y)
#define glVertexAttrib2sARB(index, x, y) GLVertexAttrib2s(__tglContext, index, x, y)
#define glVertexAttrib2sv(index, v) GLVertexAttrib2sv(__tglContext, index, v)
#define glVertexAttrib2svARB(index, v) GLVertexAttrib2sv(__tglContext, index, v)
#define glVertexAttrib3d(index, x, y, z) GLVertexAttrib3d(__tglContext, index, x, y, z)
#define glVertexAttrib3dARB(index, x, y, z) GLVertexAttrib3d(__tglContext, index, x, y, z)
#define glVertexAttrib3dv(index, v) GLVertexAttrib3dv(__tglContext, index, v)
#define glVertexAttrib3dvARB(index, v) GLVertexAttrib3dv(__tglContext, index, v)
#define glVertexAttrib3f(index, x, y, z) GLVertexAttrib3f(__tglContext, index, x, y, z)
#define glVertexAttrib3fARB(index, x, y, z) GLVertexAttrib3f(__tglContext, index, x, y, z)
#define glVertexAttrib3fv(index, v) GLVertexAttrib3fv(__tglContext, index, v)
#define glVertexAttrib3fvARB(index, v) GLVertexAttrib3fv(__tglContext, index, v)
#define glVertexAttrib3s(index, x, y, z) GLVertexAttrib3s(__tglContext, index, x, y, z)
#define glVertexAttrib3sARB(index, x, y, z) GLVertexAttrib3s(__tglContext, index, x, y, z)
#define glVertexAttrib3sv(index, v) GLVertexAttrib3sv(__tglContext, index, v)
#define glVertexAttrib3svARB(index, v) GLVertexAttrib3sv(__tglContext, index, v)
#define glVertexAttrib4Nbv(index, v) GLVertexAttrib4Nbv(__tglContext, index, v)
#define glVertexAttrib4NbvARB(index, v) GLVertexAttrib4Nbv(__tglContext, index, v)
#define glVertexAttrib4Niv(index, v) GLVertexAttrib4Niv(__tglContext, index, v)
#define glVertexAttrib4NivARB(index, v) GLVertexAttrib4Niv(__tglContext, index, v)
#define glVertexAttrib4Nsv(index, v) GLVertexAttrib4Nsv(__tglContext, index, v)
#define glVertexAttrib4NsvARB(index, v) GLVertexAttrib4Nsv(__tglContext, index, v)
#define glVertexAttrib4Nub(index, x, y, z, w) GLVertexAttrib4Nub(__tglContext, index, x, y, z, w)
#define glVertexAttrib4NubARB(index, x, y, z, w) GLVertexAttrib4Nub(__tglContext, index, x, y, z, w)
#define glVertexAttrib4Nubv(index, v) GLVertexAttrib4Nubv(__tglContext, index, v)
#define glVertexAttrib4NubvARB(index, v) GLVertexAttrib4Nubv(__tglContext, index, v)
#define glVertexAttrib4Nuiv(index, v) GLVertexAttrib4Nuiv(__tglContext, index, v)
#define glVertexAttrib4NuivARB(index, v) GLVertexAttrib4Nuiv(__tglContext, index, v)
#define glVertexAttrib4Nusv(index, v) GLVertexAttrib4Nusv(__tglContext, index, v)
#define glVertexAttrib4NusvARB(index, v) GLVertexAttrib4Nusv(__tglContext, index, v)
#define glVertexAttrib4bv(index, v) GLVertexAttrib4bv(__tglContext, index, v)
#define glVertexAttrib4bvARB(index, v) GLVertexAttrib4bv(__tglContext, index, v)
#define glVertexAttrib4d(index, x, y, z, w) GLVertexAttrib4d(__tglContext, index, x, y, z, w)
#define glVertexAttrib4dARB(index, x, y, z, w) GLVertexAttrib4d(__tglContext, index, x, y, z, w)
#define glVertexAttrib4dv(index, v) GLVertexAttrib4dv(__tglContext, index, v)
#define glVertexAttrib4dvARB(index, v) GLVertexAttrib4dv(__tglContext, index, v)
#define glVertexAttrib4f(index, x, y, z, w) GLVertexAttrib4f(__tglContext, index, x, y, z, w)
#define glVertexAttrib4fARB(index, x, y, z, w) GLVertexAttrib4f(__tglContext, index, x, y, z, w)
#define glVertexAttrib4fv(index, v) GLVertexAttrib4fv(__tglContext, index, v)
#define glVertexAttrib4fvARB(index, v) GLVertexAttrib4fv(__tglContext, index, v)
#define glVertexAttrib4iv(index, v) GLVertexAttrib4iv(__tglContext, index, v)
#define glVertexAttrib4ivARB(index, v) GLVertexAttrib4iv(__tglContext, index, v)
#define glVertexAttrib4s(index, x, y, z, w) GLVertexAttrib4s(__tglContext, index, x, y, z, w)
#define glVertexAttrib4sARB(index, x, y, z, w) GLVertexAttrib4s(__tglContext, index, x, y, z, w)
#define glVertexAttrib4sv(index, v) GLVertexAttrib4sv(__tglContext, index, v)
#define glVertexAttrib4svARB(index, v) GLVertexAttrib4sv(__tglContext, index, v)
#define glVertexAttrib4ubv(index, v) GLVertexAttrib4ubv(__tglContext, index, v)
#define glVertexAttrib4ubvARB(index, v) GLVertexAttrib4ubv(__tglContext, index, v)
#define glVertexAttrib4uiv(index, v) GLVertexAttrib4uiv(__tglContext, index, v)
#define glVertexAttrib4uivARB(index, v) GLVertexAttrib4uiv(__tglContext, index, v)
#define glVertexAttrib4usv(index, v) GLVertexAttrib4usv(__tglContext, index, v)
#define glVertexAttrib4usvARB(index, v) GLVertexAttrib4usv(__tglContext, index, v)
#define glVertexAttribPointer(index, size, type, normalized, stride, pointer) GLVertexAttribPointer(__tglContext, index, size, type, normalized, stride, pointer)
#define glVertexAttribPointerARB(index, size, type, normalized, stride, pointer) GLVertexAttribPointer(__tglContext, index, size, type, normalized, stride, pointer)
#define glVertexBlendARB(count) GLVertexBlendARB(__tglContext, count)
#define glVertexPointer(size, type, stride, pointer) GLVertexPointer(__tglContext, size, type, stride, pointer)
#define glViewport(x, y, width, height) GLViewport(__tglContext, x, y, width, height)
#define glWeightPointerARB(size, type, stride, pointer) GLWeightPointerARB(__tglContext, size, type, stride, pointer)
#define glWeightbvARB(size, weights) GLWeightbvARB(__tglContext, size, weights)
#define glWeightdvARB(size, weights) GLWeightdvARB(__tglContext, size, weights)
#define glWeightfvARB(size, weights) GLWeightfvARB(__tglContext, size, weights)
#define glWeightivARB(size, weights) GLWeightivARB(__tglContext, size, weights)
#define glWeightsvARB(size, weights) GLWeightsvARB(__tglContext, size, weights)
#define glWeightubvARB(size, weights) GLWeightubvARB(__tglContext, size, weights)
#define glWeightuivARB(size, weights) GLWeightuivARB(__tglContext, size, weights)
#define glWeightusvARB(size, weights) GLWeightusvARB(__tglContext, size, weights)
#define glWindowPos2d(x, y) GLWindowPos2d(__tglContext, x, y)
#define glWindowPos2dARB(x, y) GLWindowPos2d(__tglContext, x, y)
#define glWindowPos2dv(v) GLWindowPos2dv(__tglContext, v)
#define glWindowPos2dvARB(v) GLWindowPos2dv(__tglContext, v)
#define glWindowPos2f(x, y) GLWindowPos2f(__tglContext, x, y)
#define glWindowPos2fARB(x, y) GLWindowPos2f(__tglContext, x, y)
#define glWindowPos2fv(v) GLWindowPos2fv(__tglContext, v)
#define glWindowPos2fvARB(v) GLWindowPos2fv(__tglContext, v)
#define glWindowPos2i(x, y) GLWindowPos2i(__tglContext, x, y)
#define glWindowPos2iARB(x, y) GLWindowPos2i(__tglContext, x, y)
#define glWindowPos2iv(v) GLWindowPos2iv(__tglContext, v)
#define glWindowPos2ivARB(v) GLWindowPos2iv(__tglContext, v)
#define glWindowPos2s(x, y) GLWindowPos2s(__tglContext, x, y)
#define glWindowPos2sARB(x, y) GLWindowPos2s(__tglContext, x, y)
#define glWindowPos2sv(v) GLWindowPos2sv(__tglContext, v)
#define glWindowPos2svARB(v) GLWindowPos2sv(__tglContext, v)
#define glWindowPos3d(x, y, z) GLWindowPos3d(__tglContext, x, y, z)
#define glWindowPos3dARB(x, y, z) GLWindowPos3d(__tglContext, x, y, z)
#define glWindowPos3dv(v) GLWindowPos3dv(__tglContext, v)
#define glWindowPos3dvARB(v) GLWindowPos3dv(__tglContext, v)
#define glWindowPos3f(x, y, z) GLWindowPos3f(__tglContext, x, y, z)
#define glWindowPos3fARB(x, y, z) GLWindowPos3f(__tglContext, x, y, z)
#define glWindowPos3fv(v) GLWindowPos3fv(__tglContext, v)
#define glWindowPos3fvARB(v) GLWindowPos3fv(__tglContext, v)
#define glWindowPos3i(x, y, z) GLWindowPos3i(__tglContext, x, y, z)
#define glWindowPos3iARB(x, y, z) GLWindowPos3i(__tglContext, x, y, z)
#define glWindowPos3iv(v) GLWindowPos3iv(__tglContext, v)
#define glWindowPos3ivARB(v) GLWindowPos3iv(__tglContext, v)
#define glWindowPos3s(x, y, z) GLWindowPos3s(__tglContext, x, y, z)
#define glWindowPos3sARB(x, y, z) GLWindowPos3s(__tglContext, x, y, z)
#define glWindowPos3sv(v) GLWindowPos3sv(__tglContext, v)
#define glWindowPos3svARB(v) GLWindowPos3sv(__tglContext, v)
#endif /* _NO_PPCINLINE */

typedef void (*PFNGLACCUMPROC)(GLenum op, GLfloat value);
typedef void (*PFNGLACTIVESTENCILFACEEXTPROC)(GLenum face);
typedef void (*PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (*PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (*PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (*PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef void (*PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (*PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
typedef GLboolean (*PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (*PFNGLARRAYELEMENTPROC)(GLint i);
typedef void (*PFNGLATTACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB obj);
typedef void (*PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (*PFNGLBEGINPROC)(GLenum mode);
typedef void (*PFNGLBEGINFRAGMENTSHADERATIPROC)(void);
typedef void (*PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
typedef void (*PFNGLBEGINQUERYARBPROC)(GLenum target, GLuint id);
typedef void (*PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
typedef void (*PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB programObj, GLuint index, const GLcharARB *name);
typedef void (*PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (*PFNGLBINDBUFFERARBPROC)(GLenum target, GLuint buffer);
typedef void (*PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint id);
typedef void (*PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (*PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum target, GLuint framebuffer);
typedef void (*PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
typedef void (*PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (*PFNGLBINDRENDERBUFFEREXTPROC)(GLenum target, GLuint renderbuffer);
typedef void (*PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (*PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (*PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLBLENDCOLOREXTPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (*PFNGLBLENDEQUATIONEXTPROC)(GLenum mode);
typedef void (*PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (*PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (*PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (*PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (*PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (*PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (*PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (*PFNGLBUFFERDATAARBPROC)(GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
typedef void (*PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (*PFNGLBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
typedef void (*PFNGLCALLLISTPROC)(GLuint list);
typedef void (*PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void *lists);
typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum target);
typedef void (*PFNGLCLAMPCOLORARBPROC)(GLenum target, GLenum clamp);
typedef void (*PFNGLCLEARPROC)(GLbitfield mask);
typedef void (*PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLCLEARCOLORIIEXTPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (*PFNGLCLEARCOLORIUIEXTPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (*PFNGLCLEARDEPTHPROC)(GLdouble depth);
typedef void (*PFNGLCLEARINDEXPROC)(GLfloat c);
typedef void (*PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (*PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
typedef void (*PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (*PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble *equation);
typedef void (*PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (*PFNGLCOLOR3BVPROC)(const GLbyte *v);
typedef void (*PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (*PFNGLCOLOR3DVPROC)(const GLdouble *v);
typedef void (*PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (*PFNGLCOLOR3FVPROC)(const GLfloat *v);
typedef void (*PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (*PFNGLCOLOR3IVPROC)(const GLint *v);
typedef void (*PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (*PFNGLCOLOR3SVPROC)(const GLshort *v);
typedef void (*PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (*PFNGLCOLOR3UBVPROC)(const GLubyte *v);
typedef void (*PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (*PFNGLCOLOR3UIVPROC)(const GLuint *v);
typedef void (*PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (*PFNGLCOLOR3USVPROC)(const GLushort *v);
typedef void (*PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (*PFNGLCOLOR4BVPROC)(const GLbyte *v);
typedef void (*PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (*PFNGLCOLOR4DVPROC)(const GLdouble *v);
typedef void (*PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLCOLOR4FVPROC)(const GLfloat *v);
typedef void (*PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (*PFNGLCOLOR4IVPROC)(const GLint *v);
typedef void (*PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (*PFNGLCOLOR4SVPROC)(const GLshort *v);
typedef void (*PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (*PFNGLCOLOR4UBVPROC)(const GLubyte *v);
typedef void (*PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (*PFNGLCOLOR4UIVPROC)(const GLuint *v);
typedef void (*PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (*PFNGLCOLOR4USVPROC)(const GLushort *v);
typedef void (*PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (*PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef void (*PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (*PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (*PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
typedef void (*PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (*PFNGLCOLORTABLEEXTPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (*PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (*PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (*PFNGLCOMPILESHADERARBPROC)(GLhandleARB shaderObj);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (*PFNGLCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
typedef void (*PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
typedef void (*PFNGLCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
typedef void (*PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
typedef void (*PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat params);
typedef void (*PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum target, GLenum pname, GLfloat params);
typedef void (*PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum target, GLenum pname, GLint params);
typedef void (*PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum target, GLenum pname, GLint params);
typedef void (*PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLCOPYCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (*PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (*PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (*PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (*PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef GLuint (*PFNGLCREATEPROGRAMPROC)(void);
typedef GLhandleARB (*PFNGLCREATEPROGRAMOBJECTARBPROC)(void);
typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum type);
typedef GLhandleARB (*PFNGLCREATESHADEROBJECTARBPROC)(GLenum shaderType);
typedef void (*PFNGLCULLFACEPROC)(GLenum mode);
typedef void (*PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint index);
typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void (*PFNGLDELETEBUFFERSARBPROC)(GLsizei n, const GLuint *buffers);
typedef void (*PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint id);
typedef void (*PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (*PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (*PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
typedef void (*PFNGLDELETEOBJECTARBPROC)(GLhandleARB obj);
typedef void (*PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (*PFNGLDELETEPROGRAMSARBPROC)(GLsizei n, const GLuint *programs);
typedef void (*PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint *ids);
typedef void (*PFNGLDELETEQUERIESARBPROC)(GLsizei n, const GLuint *ids);
typedef void (*PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (*PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (*PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (*PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (*PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (*PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (*PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
typedef void (*PFNGLDETACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB attachedObj);
typedef void (*PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (*PFNGLDISABLEPROC)(GLenum cap);
typedef void (*PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (*PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (*PFNGLDRAWBUFFERPROC)(GLenum buf);
typedef void (*PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum *bufs);
typedef void (*PFNGLDRAWBUFFERSARBPROC)(GLsizei n, const GLenum *bufs);
typedef void (*PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (*PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (*PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (*PFNGLEDGEFLAGPROC)(GLboolean flag);
typedef void (*PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void *pointer);
typedef void (*PFNGLEDGEFLAGVPROC)(const GLboolean *flag);
typedef void (*PFNGLENABLEPROC)(GLenum cap);
typedef void (*PFNGLENABLECLIENTSTATEPROC)(GLenum array);
typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (*PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (*PFNGLENDPROC)(void);
typedef void (*PFNGLENDFRAGMENTSHADERATIPROC)(void);
typedef void (*PFNGLENDLISTPROC)(void);
typedef void (*PFNGLENDQUERYPROC)(GLenum target);
typedef void (*PFNGLENDQUERYARBPROC)(GLenum target);
typedef void (*PFNGLEVALCOORD1DPROC)(GLdouble u);
typedef void (*PFNGLEVALCOORD1DVPROC)(const GLdouble *u);
typedef void (*PFNGLEVALCOORD1FPROC)(GLfloat u);
typedef void (*PFNGLEVALCOORD1FVPROC)(const GLfloat *u);
typedef void (*PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
typedef void (*PFNGLEVALCOORD2DVPROC)(const GLdouble *u);
typedef void (*PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
typedef void (*PFNGLEVALCOORD2FVPROC)(const GLfloat *u);
typedef void (*PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
typedef void (*PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (*PFNGLEVALPOINT1PROC)(GLint i);
typedef void (*PFNGLEVALPOINT2PROC)(GLint i, GLint j);
typedef void (*PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat *buffer);
typedef void (*PFNGLFINISHPROC)(void);
typedef void (*PFNGLFLUSHPROC)(void);
typedef void (*PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLFOGCOORDPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLFOGCOORDDPROC)(GLdouble coord);
typedef void (*PFNGLFOGCOORDDEXTPROC)(GLdouble coord);
typedef void (*PFNGLFOGCOORDDVPROC)(const GLdouble *coord);
typedef void (*PFNGLFOGCOORDDVEXTPROC)(const GLdouble *coord);
typedef void (*PFNGLFOGCOORDFPROC)(GLfloat coord);
typedef void (*PFNGLFOGCOORDFEXTPROC)(GLfloat coord);
typedef void (*PFNGLFOGCOORDFVPROC)(const GLfloat *coord);
typedef void (*PFNGLFOGCOORDFVEXTPROC)(const GLfloat *coord);
typedef void (*PFNGLFOGFPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
typedef void (*PFNGLFOGIPROC)(GLenum pname, GLint param);
typedef void (*PFNGLFOGIVPROC)(GLenum pname, const GLint *params);
typedef void (*PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (*PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (*PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (*PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (*PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (*PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (*PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (*PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (*PFNGLGENBUFFERSARBPROC)(GLsizei n, GLuint *buffers);
typedef GLuint (*PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint range);
typedef void (*PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (*PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei n, GLuint *framebuffers);
typedef GLuint (*PFNGLGENLISTSPROC)(GLsizei range);
typedef void (*PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint *programs);
typedef void (*PFNGLGENQUERIESPROC)(GLsizei n, GLuint *ids);
typedef void (*PFNGLGENQUERIESARBPROC)(GLsizei n, GLuint *ids);
typedef void (*PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (*PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (*PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef void (*PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (*PFNGLGENERATEMIPMAPEXTPROC)(GLenum target);
typedef void (*PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
typedef void (*PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
typedef void (*PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
typedef void (*PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (*PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
typedef GLint (*PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
typedef void (*PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
typedef void (*PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void **params);
typedef void (*PFNGLGETBUFFERPOINTERVARBPROC)(GLenum target, GLenum pname, void **params);
typedef void (*PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void (*PFNGLGETBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
typedef void (*PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble *equation);
typedef void (*PFNGLGETCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, void *table);
typedef void (*PFNGLGETCOLORTABLEEXTPROC)(GLenum target, GLenum format, GLenum type, void *data);
typedef void (*PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETCOLORTABLESGIPROC)(GLenum target, GLenum format, GLenum type, void *table);
typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void *img);
typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint level, void *img);
typedef void (*PFNGLGETCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, void *image);
typedef void (*PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *image);
typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *data);
typedef GLenum (*PFNGLGETERRORPROC)(void);
typedef void (*PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef GLhandleARB (*PFNGLGETHANDLEARBPROC)(GLenum pname);
typedef void (*PFNGLGETHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (*PFNGLGETHISTOGRAMEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (*PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETINFOLOGARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
typedef void (*PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
typedef void (*PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint *params);
typedef void (*PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble *v);
typedef void (*PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat *v);
typedef void (*PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint *v);
typedef void (*PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint *params);
typedef void (*PFNGLGETMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (*PFNGLGETMINMAXEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (*PFNGLGETMINMAXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETMINMAXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB obj, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB obj, GLenum pname, GLint *params);
typedef void (*PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat *values);
typedef void (*PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint *values);
typedef void (*PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort *values);
typedef void (*PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
typedef void (*PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *mask);
typedef void (*PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
typedef void (*PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
typedef void (*PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
typedef void (*PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, void *string);
typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void (*PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (*PFNGLGETQUERYOBJECTIVARBPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (*PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint *params);
typedef void (*PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint id, GLenum pname, GLuint *params);
typedef void (*PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETQUERYIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
typedef void (*PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef void (*PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
typedef void (*PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef const GLubyte *(*PFNGLGETSTRINGPROC)(GLenum name);
typedef void (*PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble *params);
typedef void (*PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint *params);
typedef void (*PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (*PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (*PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, GLuint *params);
typedef void (*PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLint (*PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef GLint (*PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
typedef void (*PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
typedef void (*PFNGLGETUNIFORMFVARBPROC)(GLhandleARB programObj, GLint location, GLfloat *params);
typedef void (*PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
typedef void (*PFNGLGETUNIFORMIVARBPROC)(GLhandleARB programObj, GLint location, GLint *params);
typedef void (*PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
typedef void (*PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname, void **pointer);
typedef void (*PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (*PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (*PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (*PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (*PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (*PFNGLHISTOGRAMPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (*PFNGLHISTOGRAMEXTPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (*PFNGLINDEXMASKPROC)(GLuint mask);
typedef void (*PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLINDEXDPROC)(GLdouble c);
typedef void (*PFNGLINDEXDVPROC)(const GLdouble *c);
typedef void (*PFNGLINDEXFPROC)(GLfloat c);
typedef void (*PFNGLINDEXFVPROC)(const GLfloat *c);
typedef void (*PFNGLINDEXIPROC)(GLint c);
typedef void (*PFNGLINDEXIVPROC)(const GLint *c);
typedef void (*PFNGLINDEXSPROC)(GLshort c);
typedef void (*PFNGLINDEXSVPROC)(const GLshort *c);
typedef void (*PFNGLINDEXUBPROC)(GLubyte c);
typedef void (*PFNGLINDEXUBVPROC)(const GLubyte *c);
typedef void (*PFNGLINITNAMESPROC)(void);
typedef void (*PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void *pointer);
typedef GLboolean (*PFNGLISBUFFERPROC)(GLuint buffer);
typedef GLboolean (*PFNGLISBUFFERARBPROC)(GLuint buffer);
typedef GLboolean (*PFNGLISENABLEDPROC)(GLenum cap);
typedef GLboolean (*PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef GLboolean (*PFNGLISFRAMEBUFFEREXTPROC)(GLuint framebuffer);
typedef GLboolean (*PFNGLISLISTPROC)(GLuint list);
typedef GLboolean (*PFNGLISPROGRAMPROC)(GLuint program);
typedef GLboolean (*PFNGLISPROGRAMARBPROC)(GLuint program);
typedef GLboolean (*PFNGLISQUERYPROC)(GLuint id);
typedef GLboolean (*PFNGLISQUERYARBPROC)(GLuint id);
typedef GLboolean (*PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef GLboolean (*PFNGLISRENDERBUFFEREXTPROC)(GLuint renderbuffer);
typedef GLboolean (*PFNGLISSHADERPROC)(GLuint shader);
typedef GLboolean (*PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (*PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
typedef void (*PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
typedef void (*PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint *params);
typedef void (*PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (*PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
typedef void (*PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
typedef void (*PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint *params);
typedef void (*PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
typedef void (*PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (*PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (*PFNGLLINKPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (*PFNGLLISTBASEPROC)(GLuint base);
typedef void (*PFNGLLOADIDENTITYPROC)(void);
typedef void (*PFNGLLOADMATRIXDPROC)(const GLdouble *m);
typedef void (*PFNGLLOADMATRIXFPROC)(const GLfloat *m);
typedef void (*PFNGLLOADNAMEPROC)(GLuint name);
typedef void (*PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *m);
typedef void (*PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
typedef void (*PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *m);
typedef void (*PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
typedef void (*PFNGLLOCKARRAYSEXTPROC)(GLint first, GLsizei count);
typedef void (*PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (*PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (*PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (*PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (*PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void *(*PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
typedef void *(*PFNGLMAPBUFFERARBPROC)(GLenum target, GLenum access);
typedef void (*PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
typedef void (*PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
typedef void (*PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (*PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (*PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (*PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
typedef void (*PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
typedef void (*PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint *params);
typedef void (*PFNGLMATRIXINDEXPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLMATRIXINDEXUBVARBPROC)(GLint size, const GLubyte *indices);
typedef void (*PFNGLMATRIXINDEXUIVARBPROC)(GLint size, const GLuint *indices);
typedef void (*PFNGLMATRIXINDEXUSVARBPROC)(GLint size, const GLushort *indices);
typedef void (*PFNGLMATRIXMODEPROC)(GLenum mode);
typedef void (*PFNGLMINMAXPROC)(GLenum target, GLenum internalformat, GLboolean sink);
typedef void (*PFNGLMINMAXEXTPROC)(GLenum target, GLenum internalformat, GLboolean sink);
typedef void (*PFNGLMULTMATRIXDPROC)(const GLdouble *m);
typedef void (*PFNGLMULTMATRIXFPROC)(const GLfloat *m);
typedef void (*PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *m);
typedef void (*PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
typedef void (*PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *m);
typedef void (*PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
typedef void (*PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (*PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (*PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (*PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);
typedef void (*PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
typedef void (*PFNGLMULTITEXCOORD1DARBPROC)(GLenum target, GLdouble s);
typedef void (*PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD1DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
typedef void (*PFNGLMULTITEXCOORD1FARBPROC)(GLenum target, GLfloat s);
typedef void (*PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD1FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
typedef void (*PFNGLMULTITEXCOORD1IARBPROC)(GLenum target, GLint s);
typedef void (*PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD1IVARBPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
typedef void (*PFNGLMULTITEXCOORD1SARBPROC)(GLenum target, GLshort s);
typedef void (*PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD1SVARBPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (*PFNGLMULTITEXCOORD2DARBPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (*PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD2DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void (*PFNGLMULTITEXCOORD2FARBPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void (*PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD2FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
typedef void (*PFNGLMULTITEXCOORD2IARBPROC)(GLenum target, GLint s, GLint t);
typedef void (*PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD2IVARBPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
typedef void (*PFNGLMULTITEXCOORD2SARBPROC)(GLenum target, GLshort s, GLshort t);
typedef void (*PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD2SVARBPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (*PFNGLMULTITEXCOORD3DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (*PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD3DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (*PFNGLMULTITEXCOORD3FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (*PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD3FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (*PFNGLMULTITEXCOORD3IARBPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (*PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD3IVARBPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (*PFNGLMULTITEXCOORD3SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (*PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD3SVARBPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (*PFNGLMULTITEXCOORD4DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (*PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD4DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (*PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (*PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (*PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD4FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (*PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (*PFNGLMULTITEXCOORD4IARBPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (*PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD4IVARBPROC)(GLenum target, const GLint *v);
typedef void (*PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (*PFNGLMULTITEXCOORD4SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (*PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLMULTITEXCOORD4SVARBPROC)(GLenum target, const GLshort *v);
typedef void (*PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
typedef void (*PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (*PFNGLNORMAL3BVPROC)(const GLbyte *v);
typedef void (*PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (*PFNGLNORMAL3DVPROC)(const GLdouble *v);
typedef void (*PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (*PFNGLNORMAL3FVPROC)(const GLfloat *v);
typedef void (*PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
typedef void (*PFNGLNORMAL3IVPROC)(const GLint *v);
typedef void (*PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
typedef void (*PFNGLNORMAL3SVPROC)(const GLshort *v);
typedef void (*PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (*PFNGLPASSTEXCOORDATIPROC)(GLuint dst, GLuint coord, GLenum swizzle);
typedef void (*PFNGLPASSTHROUGHPROC)(GLfloat token);
typedef void (*PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (*PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (*PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (*PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (*PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
typedef void (*PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
typedef void (*PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLPOINTPARAMETERFARBPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLPOINTPARAMETERFEXTPROC)(GLenum pname, GLfloat param);
typedef void (*PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat *params);
typedef void (*PFNGLPOINTPARAMETERFVARBPROC)(GLenum pname, const GLfloat *params);
typedef void (*PFNGLPOINTPARAMETERFVEXTPROC)(GLenum pname, const GLfloat *params);
typedef void (*PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
typedef void (*PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint *params);
typedef void (*PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (*PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (*PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (*PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *mask);
typedef void (*PFNGLPOPATTRIBPROC)(void);
typedef void (*PFNGLPOPCLIENTATTRIBPROC)(void);
typedef void (*PFNGLPOPMATRIXPROC)(void);
typedef void (*PFNGLPOPNAMEPROC)(void);
typedef void (*PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
typedef void (*PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
typedef void (*PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
typedef void (*PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
typedef void (*PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
typedef void (*PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (*PFNGLPUSHATTRIBPROC)(GLbitfield mask);
typedef void (*PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
typedef void (*PFNGLPUSHMATRIXPROC)(void);
typedef void (*PFNGLPUSHNAMEPROC)(GLuint name);
typedef void (*PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (*PFNGLRASTERPOS2DVPROC)(const GLdouble *v);
typedef void (*PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (*PFNGLRASTERPOS2FVPROC)(const GLfloat *v);
typedef void (*PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
typedef void (*PFNGLRASTERPOS2IVPROC)(const GLint *v);
typedef void (*PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
typedef void (*PFNGLRASTERPOS2SVPROC)(const GLshort *v);
typedef void (*PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLRASTERPOS3DVPROC)(const GLdouble *v);
typedef void (*PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLRASTERPOS3FVPROC)(const GLfloat *v);
typedef void (*PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (*PFNGLRASTERPOS3IVPROC)(const GLint *v);
typedef void (*PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLRASTERPOS3SVPROC)(const GLshort *v);
typedef void (*PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLRASTERPOS4DVPROC)(const GLdouble *v);
typedef void (*PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLRASTERPOS4FVPROC)(const GLfloat *v);
typedef void (*PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (*PFNGLRASTERPOS4IVPROC)(const GLint *v);
typedef void (*PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*PFNGLRASTERPOS4SVPROC)(const GLshort *v);
typedef void (*PFNGLREADBUFFERPROC)(GLenum src);
typedef void (*PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (*PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (*PFNGLRECTDVPROC)(const GLdouble *v1, const GLdouble *v2);
typedef void (*PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (*PFNGLRECTFVPROC)(const GLfloat *v1, const GLfloat *v2);
typedef void (*PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (*PFNGLRECTIVPROC)(const GLint *v1, const GLint *v2);
typedef void (*PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (*PFNGLRECTSVPROC)(const GLshort *v1, const GLshort *v2);
typedef GLint (*PFNGLRENDERMODEPROC)(GLenum mode);
typedef void (*PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (*PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (*PFNGLRESETHISTOGRAMPROC)(GLenum target);
typedef void (*PFNGLRESETHISTOGRAMEXTPROC)(GLenum target);
typedef void (*PFNGLRESETMINMAXPROC)(GLenum target);
typedef void (*PFNGLRESETMINMAXEXTPROC)(GLenum target);
typedef void (*PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
typedef void (*PFNGLSAMPLECOVERAGEARBPROC)(GLfloat value, GLboolean invert);
typedef void (*PFNGLSAMPLEMAPATIPROC)(GLuint dst, GLuint interp, GLenum swizzle);
typedef void (*PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (*PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (*PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *v);
typedef void (*PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *v);
typedef void (*PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (*PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (*PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *v);
typedef void (*PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *v);
typedef void (*PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (*PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (*PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *v);
typedef void (*PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *v);
typedef void (*PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (*PFNGLSECONDARYCOLOR3IEXTPROC)(GLint red, GLint green, GLint blue);
typedef void (*PFNGLSECONDARYCOLOR3IVPROC)(const GLint *v);
typedef void (*PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *v);
typedef void (*PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (*PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (*PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *v);
typedef void (*PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *v);
typedef void (*PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (*PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (*PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *v);
typedef void (*PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *v);
typedef void (*PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (*PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (*PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *v);
typedef void (*PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *v);
typedef void (*PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (*PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (*PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *v);
typedef void (*PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *v);
typedef void (*PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint *buffer);
typedef void (*PFNGLSEPARABLEFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
typedef void (*PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
typedef void (*PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint dst, const GLfloat *value);
typedef void (*PFNGLSHADEMODELPROC)(GLenum mode);
typedef void (*PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (*PFNGLSHADERSOURCEARBPROC)(GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
typedef void (*PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (*PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (*PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
typedef void (*PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (*PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (*PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (*PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (*PFNGLSTENCILOPSEPARATEATIPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (*PFNGLTEXCOORD1DPROC)(GLdouble s);
typedef void (*PFNGLTEXCOORD1DVPROC)(const GLdouble *v);
typedef void (*PFNGLTEXCOORD1FPROC)(GLfloat s);
typedef void (*PFNGLTEXCOORD1FVPROC)(const GLfloat *v);
typedef void (*PFNGLTEXCOORD1IPROC)(GLint s);
typedef void (*PFNGLTEXCOORD1IVPROC)(const GLint *v);
typedef void (*PFNGLTEXCOORD1SPROC)(GLshort s);
typedef void (*PFNGLTEXCOORD1SVPROC)(const GLshort *v);
typedef void (*PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
typedef void (*PFNGLTEXCOORD2DVPROC)(const GLdouble *v);
typedef void (*PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
typedef void (*PFNGLTEXCOORD2FVPROC)(const GLfloat *v);
typedef void (*PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
typedef void (*PFNGLTEXCOORD2IVPROC)(const GLint *v);
typedef void (*PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
typedef void (*PFNGLTEXCOORD2SVPROC)(const GLshort *v);
typedef void (*PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
typedef void (*PFNGLTEXCOORD3DVPROC)(const GLdouble *v);
typedef void (*PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
typedef void (*PFNGLTEXCOORD3FVPROC)(const GLfloat *v);
typedef void (*PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
typedef void (*PFNGLTEXCOORD3IVPROC)(const GLint *v);
typedef void (*PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
typedef void (*PFNGLTEXCOORD3SVPROC)(const GLshort *v);
typedef void (*PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (*PFNGLTEXCOORD4DVPROC)(const GLdouble *v);
typedef void (*PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (*PFNGLTEXCOORD4FVPROC)(const GLfloat *v);
typedef void (*PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
typedef void (*PFNGLTEXCOORD4IVPROC)(const GLint *v);
typedef void (*PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (*PFNGLTEXCOORD4SVPROC)(const GLshort *v);
typedef void (*PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (*PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (*PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
typedef void (*PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble *params);
typedef void (*PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (*PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat *params);
typedef void (*PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (*PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint *params);
typedef void (*PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXIMAGE3DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, const GLuint *params);
typedef void (*PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (*PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (*PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (*PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (*PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (*PFNGLUNIFORM1FARBPROC)(GLint location, GLfloat v0);
typedef void (*PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM1FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (*PFNGLUNIFORM1IARBPROC)(GLint location, GLint v0);
typedef void (*PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM1IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (*PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (*PFNGLUNIFORM2FARBPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (*PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM2FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (*PFNGLUNIFORM2IARBPROC)(GLint location, GLint v0, GLint v1);
typedef void (*PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM2IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (*PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*PFNGLUNIFORM3FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM3FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*PFNGLUNIFORM3IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM3IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (*PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*PFNGLUNIFORM4FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM4FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*PFNGLUNIFORM4IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM4IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (*PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX2FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX3FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX4FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNLOCKARRAYSEXTPROC)(void);
typedef GLboolean (*PFNGLUNMAPBUFFERPROC)(GLenum target);
typedef GLboolean (*PFNGLUNMAPBUFFERARBPROC)(GLenum target);
typedef void (*PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (*PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB programObj);
typedef void (*PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (*PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (*PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
typedef void (*PFNGLVERTEX2DVPROC)(const GLdouble *v);
typedef void (*PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
typedef void (*PFNGLVERTEX2FVPROC)(const GLfloat *v);
typedef void (*PFNGLVERTEX2IPROC)(GLint x, GLint y);
typedef void (*PFNGLVERTEX2IVPROC)(const GLint *v);
typedef void (*PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
typedef void (*PFNGLVERTEX2SVPROC)(const GLshort *v);
typedef void (*PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLVERTEX3DVPROC)(const GLdouble *v);
typedef void (*PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLVERTEX3FVPROC)(const GLfloat *v);
typedef void (*PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
typedef void (*PFNGLVERTEX3IVPROC)(const GLint *v);
typedef void (*PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLVERTEX3SVPROC)(const GLshort *v);
typedef void (*PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLVERTEX4DVPROC)(const GLdouble *v);
typedef void (*PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLVERTEX4FVPROC)(const GLfloat *v);
typedef void (*PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (*PFNGLVERTEX4IVPROC)(const GLint *v);
typedef void (*PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*PFNGLVERTEX4SVPROC)(const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
typedef void (*PFNGLVERTEXATTRIB1DARBPROC)(GLuint index, GLdouble x);
typedef void (*PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (*PFNGLVERTEXATTRIB1FARBPROC)(GLuint index, GLfloat x);
typedef void (*PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
typedef void (*PFNGLVERTEXATTRIB1SARBPROC)(GLuint index, GLshort x);
typedef void (*PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (*PFNGLVERTEXATTRIB2DARBPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (*PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (*PFNGLVERTEXATTRIB2FARBPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (*PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
typedef void (*PFNGLVERTEXATTRIB2SARBPROC)(GLuint index, GLshort x, GLshort y);
typedef void (*PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLVERTEXATTRIB3DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLVERTEXATTRIB3FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLVERTEXATTRIB3SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte *v);
typedef void (*PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index, const GLbyte *v);
typedef void (*PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint *v);
typedef void (*PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index, const GLint *v);
typedef void (*PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (*PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (*PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte *v);
typedef void (*PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index, const GLubyte *v);
typedef void (*PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint *v);
typedef void (*PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index, const GLuint *v);
typedef void (*PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort *v);
typedef void (*PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index, const GLushort *v);
typedef void (*PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte *v);
typedef void (*PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index, const GLbyte *v);
typedef void (*PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLVERTEXATTRIB4DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLVERTEXATTRIB4FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (*PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint *v);
typedef void (*PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index, const GLint *v);
typedef void (*PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*PFNGLVERTEXATTRIB4SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index, const GLshort *v);
typedef void (*PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (*PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index, const GLubyte *v);
typedef void (*PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint *v);
typedef void (*PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index, const GLuint *v);
typedef void (*PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort *v);
typedef void (*PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index, const GLushort *v);
typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (*PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (*PFNGLVERTEXBLENDARBPROC)(GLint count);
typedef void (*PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLWEIGHTPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLWEIGHTBVARBPROC)(GLint size, const GLbyte *weights);
typedef void (*PFNGLWEIGHTDVARBPROC)(GLint size, const GLdouble *weights);
typedef void (*PFNGLWEIGHTFVARBPROC)(GLint size, const GLfloat *weights);
typedef void (*PFNGLWEIGHTIVARBPROC)(GLint size, const GLint *weights);
typedef void (*PFNGLWEIGHTSVARBPROC)(GLint size, const GLshort *weights);
typedef void (*PFNGLWEIGHTUBVARBPROC)(GLint size, const GLubyte *weights);
typedef void (*PFNGLWEIGHTUIVARBPROC)(GLint size, const GLuint *weights);
typedef void (*PFNGLWEIGHTUSVARBPROC)(GLint size, const GLushort *weights);
typedef void (*PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (*PFNGLWINDOWPOS2DARBPROC)(GLdouble x, GLdouble y);
typedef void (*PFNGLWINDOWPOS2DVPROC)(const GLdouble *v);
typedef void (*PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *v);
typedef void (*PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (*PFNGLWINDOWPOS2FARBPROC)(GLfloat x, GLfloat y);
typedef void (*PFNGLWINDOWPOS2FVPROC)(const GLfloat *v);
typedef void (*PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *v);
typedef void (*PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
typedef void (*PFNGLWINDOWPOS2IARBPROC)(GLint x, GLint y);
typedef void (*PFNGLWINDOWPOS2IVPROC)(const GLint *v);
typedef void (*PFNGLWINDOWPOS2IVARBPROC)(const GLint *v);
typedef void (*PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
typedef void (*PFNGLWINDOWPOS2SARBPROC)(GLshort x, GLshort y);
typedef void (*PFNGLWINDOWPOS2SVPROC)(const GLshort *v);
typedef void (*PFNGLWINDOWPOS2SVARBPROC)(const GLshort *v);
typedef void (*PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLWINDOWPOS3DARBPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLWINDOWPOS3DVPROC)(const GLdouble *v);
typedef void (*PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *v);
typedef void (*PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLWINDOWPOS3FARBPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (*PFNGLWINDOWPOS3FVPROC)(const GLfloat *v);
typedef void (*PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *v);
typedef void (*PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (*PFNGLWINDOWPOS3IARBPROC)(GLint x, GLint y, GLint z);
typedef void (*PFNGLWINDOWPOS3IVPROC)(const GLint *v);
typedef void (*PFNGLWINDOWPOS3IVARBPROC)(const GLint *v);
typedef void (*PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLWINDOWPOS3SARBPROC)(GLshort x, GLshort y, GLshort z);
typedef void (*PFNGLWINDOWPOS3SVPROC)(const GLshort *v);
typedef void (*PFNGLWINDOWPOS3SVARBPROC)(const GLshort *v);

#ifdef __cplusplus
}
#endif

#endif /* TGL_GLSTD_H */
