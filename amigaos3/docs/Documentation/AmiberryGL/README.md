<!--
SPDX-FileCopyrightText: 2026 Dimitris Panokostas
SPDX-License-Identifier: MIT
-->
# Amiberry GL SDK

Headers and import library sources for AmigaOS 3 (m68k) programs that use
the 3D libraries of Amiberry's renderer plugin:

- `minigl.library`: MiniGL V30 interface. Programs made for MiniGL V29,
  V29.1 or V30 run unchanged.
- `ogles3.library` (OpenGL ES 2.0, 3.0 and 3.1) and `ogles2.library` (OpenGL
  ES 2.0): binary compatible with ladislawv's
  [ogles3](https://github.com/ladislawv/ogles3) and
  [ogles2](https://github.com/ladislawv/ogles2) for PiStorm, whose SDKs work
  as well.

The libraries and the renderer plugin are available from
https://ko-fi.com/midwan. Their release archives contain this SDK with
prebuilt import libraries.

## Layout

| Path | Contents |
|---|---|
| `minigl/include` | `<proto/minigl.h>`, `<libraries/minigl.h>`, the dispatch ABI and the ABI-sized GL, GLU and GLUT declarations |
| `minigl/client` | import library sources (`MiniGLOpen()` opens `minigl.library` and checks its ABI) |
| `ogles/include` | `<proto/ogles3.h>`, `<proto/ogles2.h>`, the dispatch tables, the Khronos GLES2/GLES3/KHR headers |
| `ogles/ogles3-interface`, `ogles/ogles2-interface` | ladislawv's interface headers and autodocs (`ogles3.doc`, `ogles2.doc`, `GettingStarted.txt`) |
| `ogles/client` | import library sources for both libraries |
| `LICENSES/` | licence texts |

## Building the import libraries

With AmigaPorts' m68k-amigaos-gcc, for example from the
`amigadev/crosstools:m68k-amigaos-gcc10` Docker image:

```sh
make
```

builds `lib/libminigl_dispatch.a`, `lib/libogles2.a` and `lib/libogles3.a`.

## Using it

| Library | Compile with | Link |
|---|---|---|
| `minigl.library` | `-Iminigl/include -DMINIGL_DISPATCH_ABI_TYPES` | `lib/libminigl_dispatch.a` |
| `ogles3.library` | `-Iogles/include -Iogles/ogles3-interface/include` | `lib/libogles3.a` |
| `ogles2.library` | `-Iogles/include -Iogles/ogles2-interface/include` | `lib/libogles2.a` |

```c
#include <proto/ogles3.h>

int main(void)
{
    void *context;
    ULONG error = 0;

    if (!OGLES3Open())
        return 20;
    /* The highest OpenGL ES version the host offers, in a 320x240 window on
     * the default public screen. Add OGLES3_CCT_PISTORM_ES_VERSION, 20 for
     * OpenGL ES 2.0. */
    context = aglCreateContextTags2(&error,
                                    OGLES3_CCT_PISTORM_WIDTH, 320,
                                    OGLES3_CCT_PISTORM_HEIGHT, 240,
                                    TAG_DONE);
    if (context) {
        aglMakeCurrent(context);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        aglSwapBuffers();
        aglDestroyContext(context);
    }
    OGLES3Close();
    return context ? 0 : 10;
}
```

`ogles/ogles3-interface/ogles3.doc` and `ogles/ogles2-interface/ogles2.doc`
describe every function and context tag of the OpenGL ES libraries.

## Licensing

Every file states its copyright holders and licence in an SPDX header, or in
`REUSE.toml` for files that cannot carry one. Licence texts are in
`LICENSES/`.

| Files | Licence |
|---|---|
| `ogles/include` (except Khronos), `ogles/client`, build and CI files | MIT, Dimitris Panokostas |
| `ogles/include/GLES2`, `GLES3`, `KHR` | MIT / Apache-2.0, The Khronos Group |
| `ogles/ogles3-interface`, `ogles/ogles2-interface` | MIT, R-Typer and Ladislawv (`LICENSE` in each) |
| `minigl/client`, `minigl/include/libraries/minigl.h`, `minigl_dispatch.h`, `proto/minigl.h`, `clib/minigl_protos.h` | Hyperion MiniGL Open Source License or zlib, at your choice, Steffen Haeuser (with Amiberry changes by Dimitris Panokostas) |
| `minigl/include/libraries/minigl_abi_types.h` (declarations from the MiniGL V30 SDK headers) | Hyperion MiniGL Open Source License |
| `minigl/include/libraries/minigl_gl_tokens.h` | Apache-2.0, The Khronos Group |
| `minigl/include/libraries/minigl_glu_tokens.h` | SGI-B-2.0, Silicon Graphics |
| `minigl/include/libraries/minigl_glut_tokens.h` | MIT, Pawel W. Olszta |

The MiniGL files here include the source of every change made to MiniGL
interface files for the Amiberry `minigl.library`, as the Hyperion MiniGL
licence asks of modifications.
