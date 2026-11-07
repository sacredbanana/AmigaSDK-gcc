minigl.library 29.1 -- client SDK, 2026-10-06
============================================================================

Everything needed to COMPILE and LINK a program against minigl.library 29.1.

  minigl-shared-library/include/   the client headers
      proto/minigl.h               the one header a client includes
      clib/minigl_protos.h
      libraries/minigl.h           MINIGL_VERSION 29
      libraries/minigl_dispatch.h  dispatch ABI 5, the table, the MGLD_ inlines
      mgl/*.h                      the GL, GLU and GLUT surface
  backend/include/                 v3d_*.h, reached by mgl/vertexbuffer.h
  lib/libminigl.a                  the import library -- MiniGLOpen lives here
  lib/libminigl_dispatch.a         the same archive under the other name

HOW TO BUILD AGAINST IT. One include path and one library path:

    -I<sdk>/minigl-shared-library/include
    -L<sdk>/lib -lminigl

THE FOLDER LAYOUT IS NOT DECORATIVE. mgl/vertexbuffer.h reaches the backend
headers as "../../../backend/include/v3d_vertex.h", so backend/ has to stay a
sibling of minigl-shared-library/. Moving either one breaks the include.

#include <proto/minigl.h> is the entry point; it pulls in everything else.
Call MiniGLOpen() before any gl* call and MiniGLClose() at the end.


READ THIS FIRST IF YOU ARE COMING FROM THE 29.0 SDK
----------------------------------------------------------------------------

A PROGRAM BUILT WITH THIS SDK WILL NOT RUN ON A 29.0 LIBRARY, AND IT FAILS
SILENTLY. MiniGLOpen() returns FALSE and nothing says why, which looks exactly
like the library not being installed at all.

The reason is not the version number. Nothing reads the revision: OpenLibrary
checks the VERSION field, which is 29 for both 29.0 and 29.1, and the ".1"
exists only in the $VER string for humans. What refuses the client is the
dispatch table SIZE check in MiniGLOpen():

    dispatch->structSize < sizeof(MGLDispatchTable)

29.1 appended one slot, so this SDK compiles in sizeof = 840 while a 29.0
library reports 836, and 836 < 840 refuses. The check is right -- slot 205
genuinely is not there in 29.0, and calling through it would jump past the end
of the table -- but the failure carries no diagnostic.

SO: SHIP THE 29.1 LIBRARY WITH ANYTHING YOU BUILD FROM THIS SDK. The library
and its clients are one set. The other direction is fine: a program built with
the 29.0 SDK runs on a 29.1 library unchanged, because the size test is "at
least mine" and the ABI number has not moved.


WHAT CHANGED SINCE THE 29.0 SDK
----------------------------------------------------------------------------

SOURCE-BREAKING, two of them:

  - MGL_FLATFAN (0x7013) and MGL_FLATSTRIP (0x7014) ARE DELETED from mgl/gl.h.
    They were MiniGL modes that took device coordinates with the matrices and
    viewport bypassed. That bypass no longer exists, so the names were being
    accepted and drawn as ordinary fans and strips -- window coordinates
    multiplied by whatever matrix happened to be current. Refusing the name
    turns a silent misdraw into a compile error.

    Use GL_TRIANGLE_FAN or GL_TRIANGLE_STRIP. For 2D work set a window-space
    projection first:

        glMatrixMode(GL_PROJECTION); glPushMatrix(); glLoadIdentity();
        glOrtho(0.0, (GLdouble)width, (GLdouble)height, 0.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);  glPushMatrix(); glLoadIdentity();
        ... draw in pixels ...
        glMatrixMode(GL_PROJECTION); glPopMatrix();
        glMatrixMode(GL_MODELVIEW);  glPopMatrix();

    A vertex then lands at the pixel it names. If your 2D path already sets up
    an glOrtho like this, changing the mode name is the whole job.

  - MGLD_glNormal3fv() takes GLfloat * where it took const GLfloat *. Passing
    a const GLfloat * compiled clean against 29.0 and now warns or errors.

NOT BREAKING:

  - glNormal3fv has a dispatch slot of its own (205) instead of expanding onto
    glNormal3f in the header, so both linkages reach the same function. It also
    stopped evaluating its argument three times.
  - A NULL POINTER IS NOW IGNORED by thirteen entry points rather than
    dereferenced: glVertex2fv/3fv/4fv, glColor3fv/4fv, glColor3ubv/4ubv,
    glTexCoord2fv/4fv, glMultiTexCoord2fvARB, glEdgeFlagv, glIndexiv and
    glNormal3fv. Each returns having stored nothing, so the current vertex,
    colour, texture coordinate, edge flag, index or normal keeps its value.
    GL leaves this undefined; on 68k address 0 is readable, so the old
    behaviour was not a clean crash but twelve bytes of the exception vector
    table drawn as geometry.
  - glBegin flags GL_INVALID_ENUM for an unrecognised mode, where it flagged
    GL_INVALID_OPERATION. GL 1.1 reserves the latter for a nested glBegin,
    which this driver does not detect.
  - MINIGL_DISPATCH_ABI_VERSION is unchanged at 5.

Both numbers may be overridden on a compile line -- libraries/minigl.h guards
MINIGL_VERSION with #ifndef for that -- but overriding them to an older value
does not make an older library work; it only moves where the refusal happens.
