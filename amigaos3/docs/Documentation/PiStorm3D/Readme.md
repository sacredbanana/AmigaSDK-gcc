# PiStorm3D

PiStorm3D is a hardware-accelerated MiniGL implementation for classic Amiga systems using the Raspberry Pi VideoCore V3D GPU through PiStorm systems based on Raspberry Pi 4 / CM4 / 4B hardware.

The project implements a substantial subset of the classic Amiga MiniGL API and translates rendering directly to the V3D hardware.

It is primarily intended for accelerating existing and newly ported 68k OpenGL/MiniGL software on PiStorm-equipped Amigas.

The MiniGLV3D sources, V3D backend, GCC build support and development test and demo programs will be provided through the source repository described below.

PLEASE NOTE THE PUBLIC RELEASE VERSION NO LONGER SUPPORTS EXECUTABLES COMPILED FOR THE BETA VERSION. THESE EXECUTABLES NEED TO GET RECOMPILED WITH THE LATEST SDK !!!

## Source Code

The source repository for this release is:

[PiStorm3D source repository](https://github.com/SteffenHaeuser/MiniGL_Library_68k)

The build instructions and references to source directories below apply to a checkout of that repository.

## Status

PiStorm3D is based on MiniGL V1.2 and implements its API together with independently developed extensions that provide functionality equivalent to the additions in MiniGLQ3. No MiniGLQ3 code was used in PiStorm3D.

MiniGL V1.2 operates under the Hyperion MiniGL Open Source License. The complete license is included as a separate file with this distribution.

PiStorm3D is included in two forms:

* A static linker library for creating executables which run directly on PiStorm systems using Raspberry Pi 4 / CM4 / 4B hardware.
* An implementation using the shared `minigl.library` interface. This allows software to run both on PiStorm Pi4/CM4/4B systems
* and on other supported hardware by installing a suitable 'minigl.library' implementation for the target hardware.

A `minigl.library` implementation for classic MiniGL-compatible hardware is available on Aminet.

A minigl.library implementation for Radeon 9200 hardware is currently under development by an independent third-party developer and is not part of the PiStorm3D project.

A minigl.library implementation for PiStorm systems with Pi3 is in development by an independent third-party developer and is not part of the PiStorm3D project.

A minigl.library for the Copperline Amiga Emulator (communicating with the Host systems GL Implementation) is in development by a independent third-party developer.

A minigl.library for AmiBerry is currently in development by Dimitris "Midwan" Panokostas

Direct minigl.library for QuarkTex NG is in development by Serkan Dursun, a Betaversion already released.

Also minigl.library Sources were provided to a developer considering an implementation for Matrox Graphics Cards.

Versions for WarpOS are being developed for the Classic and Radeon Variants.

A version of the source code was also provided to Apollo Computer. This is not only about PiStorm3D. It is a new OpenSource 3D Standard for AmigaOS 68k.

minigl.library is distributed under the Hyperion MiniGL Open Source License, except for incorporated third-party components which remain under their respective original licenses.

This includes V3D-related code derived from or based on work by Macoy Madson, Broadcom, VMware and Mesa. Those components retain their original copyright notices and license terms.

## Requirements

PiStorm3D requires:

* A compatible PiStorm setup with access to the Raspberry Pi VideoCore V3D GPU using Raspberry Pi 4 / CM4 / 4B hardware.
* AmigaOS 3.x
* RTG graphics
* `cybergraphics.library` or Picasso96, using BGRA32 as your only 32 Bit Screenmodes
* *not* using the fast_page_zero option in your config.txt of PiStorm

PiStorm systems using Raspberry Pi 3 are not supported by this implementation because their GPU requires a different backend.

## MiniGL API

PiStorm3D follows the classic MiniGL programming model.

Typical initialization for the statically linked PiStorm3D version is:

```c
if (!MGLInit())
    return 1;

mglChoosePixelDepth(16);
mglChooseWindowMode(GL_FALSE);

if (!mglCreateContext(0, 0, 640, 480))
{
    MGLTerm();
    return 1;
}

/* OpenGL/MiniGL rendering */

mglDeleteContext();
MGLTerm();
```

Applications using the shared `minigl.library` use `MiniGLOpen()` and `MiniGLClose()` instead of calling `MGLInit()` and `MGLTerm()` directly.

When adapting an existing MiniGL application to `minigl.library`, the following changes are normally required:

* Replace `MGLInit()` with `MiniGLOpen()`.
* Replace `MGLTerm()` with `MiniGLClose()`.
* Replace MiniGL includes such as `mgl/gl.h` with:

```c
#include <proto/minigl.h>
```

* Link against `libminigl.a` instead of `libmgl.a`.

`MiniGLOpen()` and `MiniGLClose()` also take care of opening and closing the shared `minigl.library`.

Alternatively, SDL1, SDL2 and SDL3 versions are available which use `minigl.library` for OpenGL/MiniGL support.

## API Functions and Extensions

PiStorm3D follows the classic MiniGL programming model. The current SDK headers expose the functions below through the shared-library dispatch interface as well as the corresponding static API. This is a selection, not a complete API reference. An exposed entry point does not by itself imply support for every OpenGL mode, parameter or operation on every backend.

* Multitexturing: `glActiveTextureARB()`, `glClientActiveTextureARB()`, `glMultiTexCoord2fARB()` and `glMultiTexCoord2fvARB()`.
* Vertex arrays and indexed rendering: `glVertexPointer()`, `glColorPointer()`, `glTexCoordPointer()`, `glInterleavedArrays()`, `glDrawArrays()`, `glDrawElements()`, `glMultiDrawArrays()`, `glLockArrays()` and `glUnlockArrays()`.
* Blending and colour writes: `glBlendFunc()`, `glBlendEquation()`, `glBlendFuncSeparate()` and `glColorMask()`.
* Texture operations: `glTexImage2D()`, `glTexSubImage2D()`, `glCopyTexImage2D()`, `glCopyTexSubImage2D()`, `glIsTexture()`, `glAreTexturesResident()` and `glPrioritizeTextures()`.
* Texture coordinate generation: `glTexGeni()` and `glTexGenfv()`.
* Rasterization and depth: `glPointSize()`, `glLineWidth()`, `glPolygonMode()`, `glPolygonOffset()`, `glDepthFunc()`, `glDepthMask()` and `glDepthRange()`.
* State queries and framebuffer access: `glGetBooleanv()`, `glGetIntegerv()`, `glGetFloatv()`, `glGetDoublev()`, `glGetPointerv()`, `glReadBuffer()` and `glReadPixels()`.
* Additional compatibility entry points: `glEdgeFlag()`, `glEdgeFlagv()`, `glEdgeFlagPointer()`, `glIndexi()`, `glIndexiv()` and `glIndexPointer()`. Their presence does not establish support for colour-index rendering or every edge-flag operation.

The API also includes fog, alpha testing, texture environment controls, clipping and depth buffering.

MiniGL-specific context and configuration functions include:

* `mglChooseZBufferDepth(int bits)`.
* `mglCreateContextFromWindow(struct Window *window)` for an application-owned window.
* `mglCreateContextFromBitMap(struct BitMap *bitmap)` for an application-owned bitmap, with presentation handled by the application.
* `mglGetWindowHandle()`, `mglGetInputWindowHandle()`, `mglResizeContext()` and `mglSwitchDisplay()`.
* `mglSetZOffset()` for the MiniGL depth-offset convention, which is distinct from the factor/units convention of `glPolygonOffset()`.

The supplied headers document that application-owned windows and bitmaps must outlive their contexts. For the PiStorm3D bitmap path, they specify a CGX-lockable bitmap with four bytes per pixel suitable for RGBA8 output; a reported depth of 24 alone does not exclude such a bitmap.

See `mgl/gl.h` for declarations and static API macros, and `libraries/minigl_dispatch.h` for the shared-library API wrappers. Shared-library applications should include `<proto/minigl.h>`.

## Building the GCC Static Library

From a source checkout, run make

This builds the static GCC PiStorm3D MiniGL library without diagnostic logging.

A logging-enabled GCC build script is also included for debugging purposes.

## Building minigl.library

The `minigl.library` implementation is built separately.

Use the Makefile contained in the corresponding `minigl.library` source directory.

Applications using the shared library should link against the provided `libminigl.a` import library.

## Demos and Tests

The source repository's `demos/` directory contains a collection of programs used to test individual parts of the implementation.

The demos cover areas such as:

* basic rendering
* texture mapping
* depth buffering
* blending
* alpha testing
* fog
* vertex arrays
* indexed rendering
* multitexturing
* clipping
* polygon-offset testing
* windowed rendering
* regression and stress testing

## Credits

PiStorm3D was conceived and implemented by Dennis Boon.

`minigl.library` was conceived and implemented by Steffen "MagicSN" Haeuser.

We would like to take this opportunity to thank everyone involved in the project:

* Claude Schwarz and Michal Schulz for many hints and information regarding PiStorm and Raspberry Pi hardware.
* paraj for his proof-of-concept of 3D Hardware on Pi3
* Macoy Madson and Mike, the Wandering Hacker, for extensive information, documentation and examples regarding programming of the VideoCore VI V3D GPU.
* Hans-Jörg Frieden, Thomas Frieden and Christian "Surgeon" Michael for developing MiniGL V1.2.
* CowCat for developing the MiniGLQ3 extensions, whose functionality PiStorm3D implements independently.
* Artur "arczi" Jarosik and Serkan Dursun for supporting PiStorm3D with their games, including during the early development stages.
* flype, Mr-Z, mbo77, vitosky70, Joacim Strand and Justin Webb for beta testing.
* All people who donated money for PiStorm3D, especially Ben Hermans and Justin Webb for their initial substantial donations, which helped the crowdfunding campaign take off.
* Alinea Computer and Claude for donating hardware to the project.
* Everybody who tested, reported bugs, provided information or otherwise helped the project.

## License

PiStorm3D is based on MiniGL V1.2.

The MiniGL-derived portions of PiStorm3D, including our modifications and extensions, are distributed under the Hyperion MiniGL Open Source License.

Original PiStorm3D code, including independently written V3D backend code, is also distributed under the Hyperion MiniGL Open Source License. Incorporated third-party code retains its original licence terms.

The complete MiniGL license is included as a separate file with this distribution.

PiStorm3D also contains third-party V3D code and headers which are not covered by the MiniGL license.

These components retain their original copyright notices and license terms.

In particular, parts of the V3D implementation contain or are derived from code by Macoy Madson, Broadcom and VMware, including code originating from or based on the Mesa V3D implementation.

The corresponding copyright notices and license terms are contained in the respective source files and must be retained when redistributing those components or substantial portions of them.

Other third-party components included in the source tree remain subject to their respective licenses and copyright notices.

## Disclaimer

PiStorm3D is provided without warranty, to the extent permitted by applicable law.

The authors and contributors accept no liability for loss of data, software malfunction, system instability, hardware damage or other direct or indirect damages resulting from the use or inability to use PiStorm3D, except where such liability cannot legally be excluded.

The warranty and liability provisions contained in the Hyperion MiniGL Open Source License and in the licenses of third-party components remain applicable to their respective parts of the software.

