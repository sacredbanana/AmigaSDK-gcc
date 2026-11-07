/*
 * SPDX-FileCopyrightText: 1999-2000 Pawel W. Olszta
 * SPDX-License-Identifier: MIT
 *
 * GLUT token values used by the MiniGL 29.1 ABI, taken from freeglut
 * include/GL/freeglut_std.h (https://github.com/freeglut/freeglut commit
 * 4302631ed9227b659d3ea8abe9d3c54b202a4d16).
 * Include <libraries/minigl_abi_types.h> rather than this file.
 *
 * Copyright (c) 1999-2000 Pawel W. Olszta. All Rights Reserved.
 * Written by Pawel W. Olszta, <olszta@sourceforge.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef LIBRARIES_MINIGL_GLUT_TOKENS_H
#define LIBRARIES_MINIGL_GLUT_TOKENS_H

#define GLUT_RGB                       0x0000
#define GLUT_RGBA                      0x0000
#define GLUT_INDEX                     0x0001
#define GLUT_SINGLE                    0x0000
#define GLUT_DOUBLE                    0x0002
#define GLUT_ACCUM                     0x0004
#define GLUT_ALPHA                     0x0008
#define GLUT_DEPTH                     0x0010
#define GLUT_STENCIL                   0x0020
#define GLUT_MULTISAMPLE               0x0080
#define GLUT_STEREO                    0x0100
#define GLUT_LUMINANCE                 0x0200
#define GLUT_GAME_MODE_ACTIVE          0x0000
#define GLUT_GAME_MODE_POSSIBLE        0x0001
#define GLUT_GAME_MODE_WIDTH           0x0002
#define GLUT_GAME_MODE_HEIGHT          0x0003
#define GLUT_GAME_MODE_PIXEL_DEPTH     0x0004
#define GLUT_GAME_MODE_REFRESH_RATE    0x0005
#define GLUT_GAME_MODE_DISPLAY_CHANGED 0x0006
#define GLUT_WINDOW_X                  0x0064
#define GLUT_WINDOW_Y                  0x0065
#define GLUT_WINDOW_WIDTH              0x0066
#define GLUT_WINDOW_HEIGHT             0x0067
#define GLUT_WINDOW_BUFFER_SIZE        0x0068
#define GLUT_WINDOW_STENCIL_SIZE       0x0069
#define GLUT_WINDOW_DEPTH_SIZE         0x006A
#define GLUT_WINDOW_RED_SIZE           0x006B
#define GLUT_WINDOW_GREEN_SIZE         0x006C
#define GLUT_WINDOW_BLUE_SIZE          0x006D
#define GLUT_WINDOW_ALPHA_SIZE         0x006E
#define GLUT_WINDOW_ACCUM_RED_SIZE     0x006F
#define GLUT_WINDOW_ACCUM_GREEN_SIZE   0x0070
#define GLUT_WINDOW_ACCUM_BLUE_SIZE    0x0071
#define GLUT_WINDOW_ACCUM_ALPHA_SIZE   0x0072
#define GLUT_WINDOW_DOUBLEBUFFER       0x0073
#define GLUT_WINDOW_RGBA               0x0074
#define GLUT_WINDOW_PARENT             0x0075
#define GLUT_WINDOW_NUM_CHILDREN       0x0076
#define GLUT_WINDOW_COLORMAP_SIZE      0x0077
#define GLUT_WINDOW_NUM_SAMPLES        0x0078
#define GLUT_WINDOW_STEREO             0x0079
#define GLUT_WINDOW_CURSOR             0x007A
#define GLUT_WINDOW_FORMAT_ID          0x007B
#define GLUT_SCREEN_WIDTH              0x00C8
#define GLUT_SCREEN_HEIGHT             0x00C9
#define GLUT_SCREEN_WIDTH_MM           0x00CA
#define GLUT_SCREEN_HEIGHT_MM          0x00CB
#define GLUT_MENU_NUM_ITEMS            0x012C
#define GLUT_DISPLAY_MODE_POSSIBLE     0x0190
#define GLUT_INIT_WINDOW_X             0x01F4
#define GLUT_INIT_WINDOW_Y             0x01F5
#define GLUT_INIT_WINDOW_WIDTH         0x01F6
#define GLUT_INIT_WINDOW_HEIGHT        0x01F7
#define GLUT_INIT_DISPLAY_MODE         0x01F8
#define GLUT_CURSOR_INHERIT            0x0064
#define GLUT_ELAPSED_TIME              0x02BC

#endif
