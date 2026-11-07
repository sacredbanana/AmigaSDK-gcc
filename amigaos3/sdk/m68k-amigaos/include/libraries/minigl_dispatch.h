#ifndef LIBRARIES_MINIGL_DISPATCH_H
#define LIBRARIES_MINIGL_DISPATCH_H

#include <exec/types.h>

#ifdef MINIGL_DISPATCH_ABI_TYPES
/* The Amiberry guest backend uses only the ABI-sized declarations. */
#include <libraries/minigl_abi_types.h>
#else
/* Import MiniGL types/prototypes but suppress its normal static API macros. */
#ifndef USE_MGLAPI
#define USE_MGLAPI
#define MINIGL_DIRECT_RESTORE_USE_MGLAPI
#endif
#include <mgl/gl.h>
#include <mgl/context.h>
/* GLUT, for the 22 GLUT entry points appended for 28.0. USE_MGLAPI is defined
 * above, which suppresses this header's own direct-call glut* macros so the
 * dispatch wrappers below win instead. */
#include <mgl/glut.h>
#ifdef MINIGL_DIRECT_RESTORE_USE_MGLAPI
#undef USE_MGLAPI
#undef MINIGL_DIRECT_RESTORE_USE_MGLAPI
#endif
#endif

/*
 * C LINKAGE. glxsglut is the one C++ client, and without this the dispatch table
 * pointer and MiniGLOpen get C++ mangling and fail to resolve against the
 * C-compiled import lib. Mirrors what <mgl/gl.h> already does. Benign for C
 * clients, which never see it.
 */
#ifdef __cplusplus
extern "C"
{
#endif

/*
 * 3 -> 4 (2026-10-01): the GL tokens in mgl/gl.h carry OpenGL's own values now
 * instead of being auto-numbered, so a client compiled against the old header
 * passes different integers for the same name. structSize cannot catch that --
 * it only guards the other direction, a NEW client refusing an OLD library, and
 * an old client's smaller structSize sails through. Nothing fails to link
 * either; the values are simply wrong at runtime. The ABI version is the only
 * thing that can refuse such a pairing out loud, which is what it is for.
 *
 * 4 -> 5 (2026-10-05): minigl.library 29.0, on the user's word, together with
 * MINIGL_VERSION 28 -> 29. Nothing in the ABI's own shape forced this one --
 * no token value moved and no field changed -- so it is a DECLARED RELEASE
 * BOUNDARY rather than a repair: it refuses every old pairing in both
 * directions at once, which is what makes 29.0 a clean line to ship from.
 *
 * The consequence is the point of it and has to be honoured: minigl_open.c
 * tests this for EQUALITY, so every client must be rebuilt against this header
 * and shipped with the 29.0 library. There are FIVE -- glquakelib, Quake 2's
 * ref_gl_shared.dll, Heretic II's ref_minigl.dll, ioq3's minigllib build and
 * glxsglut -- and minigl.h names the build script for each, because every one
 * of those games ALSO has a static build that is unaffected. An APPENDED
 * dispatch slot still does not move this number; structSize stays the guard
 * for that direction.
 */
#define MINIGL_DISPATCH_ABI_VERSION 5UL
#define MINIGL_BACKEND_FLAG_STUB      (1UL << 0)
#define MINIGL_BACKEND_FLAG_CLASSIC   (1UL << 1)
#define MINIGL_BACKEND_FLAG_PISTORM3D (1UL << 2)

typedef struct MGLDispatchTable {
    ULONG abiVersion;
    ULONG structSize;
    ULONG backendFlags;
    ULONG reserved;
    GLcontext *currentContext;
    void (*GLActiveTextureARB)(GLcontext context, GLenum unit);
    void (*GLAlphaFunc)(GLcontext context, GLenum func, GLclampf ref);
    void (*GLArrayElement)(GLcontext context, GLint i);
    void (*GLBegin)(GLcontext context, GLenum mode);
    void (*GLBindTexture)(GLcontext context, GLenum target, GLuint texture);
    void (*GLBlendFunc)(GLcontext context, GLenum sfactor, GLenum dfactor);
    void (*GLClear)(GLcontext context, GLbitfield mask);
    void (*GLClearColor)(GLcontext context, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void (*GLClearDepth)(GLcontext context, GLclampd depth);
    void (*GLColor3fv)(GLcontext context, GLfloat *v);
    void (*GLColor3ubv)(GLcontext context, GLubyte *v);
    void (*GLColor4f)(GLcontext context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void (*GLColor4fv)(GLcontext context, GLfloat *v);
    void (*GLColor4ub)(GLcontext context, GLubyte red, GLubyte green, GLubyte blue, GLubyte alhpa);
    void (*GLColor4ubv)(GLcontext context, GLubyte *v);
    void (*GLColorMask)(GLcontext context, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void (*GLColorPointer)(GLcontext context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    void (*GLColorTable)(GLcontext context, GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, GLvoid *data);
    void (*GLCullFace)(GLcontext context, GLenum mode);
    void (*GLDeleteTextures)(GLcontext context, GLsizei n, const GLuint *textures);
    void (*GLDepthFunc)(GLcontext context, GLenum func);
    void (*GLDepthMask)(GLcontext context, GLboolean flag);
    void (*GLDepthRange)(GLcontext context, GLclampd n, GLclampd f);
    void (*GLDisableClientState)(GLcontext context, GLenum cap);
    void (*GLDrawArrays)(GLcontext context, GLenum mode, GLint first, GLsizei count);
    void (*GLDrawBuffer)(GLcontext context, GLenum mode);
    void (*GLDrawElements)(GLcontext context, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
    void (*GLEnableClientState)(GLcontext context, GLenum cap);
    void (*GLEnd)(GLcontext context);
    void (*GLFinish)(GLcontext context);
    void (*GLFlush)(GLcontext context);
    void (*GLFogf)(GLcontext context, GLenum pname, GLfloat param);
    void (*GLFogfv)(GLcontext context, GLenum pname, GLfloat *param);
    void (*GLFrontFace)(GLcontext context, GLenum mode);
    void (*GLFrustum)(GLcontext context, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    void (*GLGenTextures)(GLcontext context, GLsizei n, GLuint *textures);
    void (*GLGetBooleanv)(GLcontext context, GLenum pname, GLboolean *params);
    GLenum (*GLGetError)(GLcontext context);
    void (*GLGetFloatv)(GLcontext context, GLenum pname, GLfloat *params);
    void (*GLGetIntegerv)(GLcontext context, GLenum pname, GLint *params);
    const GLubyte* (*GLGetString)(GLcontext context, GLenum name);
    void (*GLHint)(GLcontext context, GLenum target, GLenum mode);
    GLboolean (*GLIsEnabled)(GLcontext context, GLenum cap);
    void (*GLLoadIdentity)(GLcontext context);
    void (*GLLoadMatrixd)(GLcontext context, const GLdouble *m);
    void (*GLLoadMatrixf)(GLcontext context, const GLfloat *m);
    void (*GLLockArrays)(GLcontext context, GLuint first, GLsizei count);
    void (*GLMatrixMode)(GLcontext context, GLenum mode);
    void (*GLMultMatrixd)(GLcontext context, const GLdouble *m);
    void (*GLMultMatrixf)(GLcontext context, const GLfloat *m);
    void (*GLMultiTexCoord2fARB)(GLcontext context, GLenum unit, GLfloat s, GLfloat t);
    void (*GLMultiTexCoord2fvARB)(GLcontext context, GLenum unit, GLfloat *v);
    void (*GLNormal3f)(GLcontext context, GLfloat x, GLfloat y, GLfloat z);
    void (*GLOrtho)(GLcontext context, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    void (*GLPixelStorei)(GLcontext context, GLenum pname, GLint param);
    void (*GLPointSize)(GLcontext context, GLfloat size);
    void (*GLPolygonMode)(GLcontext context, GLenum face, GLenum mode);
    void (*GLPopMatrix)(GLcontext context);
    void (*GLPushMatrix)(GLcontext context);
    void (*GLReadPixels)(GLcontext context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
    void (*GLRotated)(GLcontext context, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    void (*GLRotatef)(GLcontext context, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    void (*GLRotatefEXT)(GLcontext context, GLfloat angle, const GLint xyz);
    void (*GLRotatefEXTs)(GLcontext context, GLfloat sin_an, GLfloat cos_an, const GLint xyz);
    void (*GLScaled)(GLcontext context, GLdouble x, GLdouble y, GLdouble z);
    void (*GLScalef)(GLcontext context, GLfloat x, GLfloat y, GLfloat z);
    void (*GLScissor)(GLcontext context, GLint x, GLint y, GLsizei width, GLsizei height);
    void (*GLShadeModel)(GLcontext context, GLenum mode);
    void (*GLTexCoord2f)(GLcontext context, GLfloat s, GLfloat t);
    void (*GLTexCoord2fv)(GLcontext context, GLfloat *v);
    void (*GLTexCoord4f)(GLcontext context, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    void (*GLTexCoord4fv)(GLcontext context, GLfloat *v);
    void (*GLTexCoordPointer)(GLcontext context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    void (*GLTexEnvi)(GLcontext context, GLenum target, GLenum pname, GLint param);
    void (*GLTexGeni)(GLcontext context, GLenum coord, GLenum mode, GLenum map);
    void (*GLTexImage2D)(GLcontext context, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
    void (*GLTexParameteri)(GLcontext context, GLenum target, GLenum pname, GLint param);
    void (*GLTexSubImage2D)(GLcontext context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
    void (*GLTranslated)(GLcontext context, GLdouble x, GLdouble y, GLdouble z);
    void (*GLTranslatef)(GLcontext context, GLfloat x, GLfloat y, GLfloat z);
    void (*GLULookAt)(GLfloat ex, GLfloat ey, GLfloat ez, GLfloat cx, GLfloat cy, GLfloat cz, GLfloat ux, GLfloat uy, GLfloat uz);
    void (*GLUPerspective)(GLfloat fovy, GLfloat aspect, GLfloat znear, GLfloat zfar);
    void (*GLUnlockArrays)(GLcontext context);
    void (*GLVertex2fv)(GLcontext context, GLfloat *v);
    void (*GLVertex3fv)(GLcontext context, GLfloat *v);
    void (*GLVertex4f)(GLcontext context, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void (*GLVertex4fv)(GLcontext context, GLfloat *v);
    void (*GLVertexPointer)(GLcontext context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    void (*GLViewport)(GLcontext context, GLint x, GLint y, GLsizei width, GLsizei height);
    void (*MGLClearPointer)(GLcontext context);
    void * (*MGLCreateContext)(int offx, int offy, int w, int h);
    void * (*MGLCreateContextFromID)(GLint ID, GLint *w, GLint *h);
    void (*MGLDeleteContext)(GLcontext context);
    void (*MGLDrawMultitexBuffer)(GLcontext context, GLenum BSrc, GLenum BDst, GLenum TexEnv);
    void (*MGLEnableSync)(GLcontext context, GLboolean enable);
    void (*MGLExit)(GLcontext context);
    void * (*MGLGetInputWindowHandle)(GLcontext context);
    void * (*MGLGetWindowHandle)(GLcontext context);
    void (*MGLIdleFunc)(GLcontext context, IdleFn i);
    void (*MGLKeyFunc)(GLcontext context, KeyHandlerFn k);
    GLboolean (*MGLLockBack)(GLcontext context, MGLLockInfo *info);
    GLboolean (*MGLLockDisplay)(GLcontext context);
    void (*MGLLockMode)(GLcontext context, GLenum lockMode);
    void (*MGLMainLoop)(GLcontext context);
    void (*MGLMinTriArea)(GLcontext context, GLfloat area);
    void (*MGLMouseFunc)(GLcontext context, MouseHandlerFn m);
    void (*MGLPrintMatrix)(GLcontext context, int mode);
    void (*MGLPrintMatrixStack)(GLcontext context, int mode);
    GLboolean (*MGLResizeContext)(GLcontext context, GLsizei width, GLsizei height);
    void (*MGLSetPointer)(GLcontext context);
    void (*MGLSetState)(GLcontext context, GLenum cap, GLboolean state);
    void (*MGLSetZOffset)(GLcontext context, GLfloat offset);
    void (*MGLSpecialFunc)(GLcontext context, SpecialHandlerFn s);
    void (*MGLSwitchDisplay)(GLcontext context);
    void (*MGLTexMemStat)(GLcontext context, GLint *Current, GLint *Peak);
    void (*MGLUnlockDisplay)(GLcontext context);
    void (*MGLWriteShotPPM)(GLcontext context, char *filename);
    void (*mglChooseGuardBand)(GLboolean flag);
    void (*mglChooseMtexBufferSize)(int size);
    void (*mglChooseNumberOfBuffers)(int number);
    void (*mglChoosePixelDepth)(int depth);
    void (*mglChooseTextureBufferSize)(int size);
    void (*mglChooseVertexBufferSize)(int size);
    void (*mglChooseWindowMode)(GLboolean flag);
    GLint (*mglGetSupportedScreenModes)(MGLScreenModeCallback CallbackFn);
    void (*mglProhibitAlphaFallback)(GLboolean flag);
    void (*mglProhibitMipMapping)(GLboolean flag);
    void (*mglProposeCloseDesktop)(GLboolean closeme);
    void (*GLPolygonOffset)(GLcontext context, GLfloat factor, GLfloat units);

    /* APPENDED 2026-09-08. New entries go at the END, never in the middle:
     * MiniGLDispatchTable's initialiser is POSITIONAL, so inserting anywhere
     * else silently shifts every later pointer. Appending keeps all existing
     * offsets stable, and MiniGLOpen's guard is
     *   dispatch->structSize < sizeof(MGLDispatchTable)
     * i.e. the client compares the LIBRARY's size against its OWN -- so an
     * existing client built on the shorter struct still accepts this longer
     * library untouched, while a client rebuilt on this header correctly
     * refuses an older library. ABI version stays 3; structSize is the real
     * guard and already behaves correctly. */
    /* ORDER FIXED 2026-09-11 to match the PUBLISHED V23 ABI (Steffen's
     * minigl-shared-library branch, commit 0081bda): the seven entries after
     * GLPolygonOffset are, in this order, ClientActiveTextureARB,
     * InterleavedArrays, MultiDrawArrays, BlendEquation, BlendFuncSeparate,
     * IsTexture, mglChooseZBufferDepth. The 2026-09-08 growth of this header
     * had appended them in a different order and without MultiDrawArrays, so
     * a client built on that header (glquakelib v185 and earlier) called the
     * wrong slot from the third appended entry on against a V23 library built
     * from the published tree. Any client compiled against the old order must
     * be rebuilt. The prefix up to GLPolygonOffset is unchanged. */
    void (*GLClientActiveTextureARB)(GLcontext context, GLenum unit);
    void (*GLInterleavedArrays)(GLcontext context, GLenum format, GLsizei stride, const GLvoid *pointer);
    void (*GLMultiDrawArrays)(GLcontext context, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
    void (*GLBlendEquation)(GLcontext context, GLenum mode);
    void (*GLBlendFuncSeparate)(GLcontext context, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    GLboolean (*GLIsTexture)(GLcontext context, GLuint texture);
    void (*mglChooseZBufferDepth)(int bits);
    /* APPENDED 2026-09-12 (GL 1.1 audit fix 4). glLineWidth had no entry
     * point at all until today, so shared-library clients had no way to ask
     * for a line wider than one pixel. At the END for the reason spelled out
     * above -- this table grows to 137 entries and every existing offset is
     * untouched, so a customer binary built on the 136-entry struct keeps
     * working against this library unchanged; only a client rebuilt on THIS
     * header needs a library at least this new, which is what structSize
     * already enforces. */
    void (*GLLineWidth)(GLcontext context, GLfloat width);
    /* APPENDED 2026-09-12 (audit fix 7). glTexGenfv is what makes
     * GL_OBJECT_LINEAR and GL_EYE_LINEAR reachable at all -- they are
     * defined by plane equations, and without this there is no way to
     * supply one. 138th entry, at the END for the reason above: every
     * existing offset is untouched. */
    void (*GLTexGenfv)(GLcontext context, GLenum coord, GLenum pname, const GLfloat *params);
    /* APPENDED 2026-09-12 (audit fix 9), entries 139 and 140. The two
     * framebuffer-to-texture copies: without these a shared-library client
     * cannot reach the one capability the audit says a game cannot work
     * around. Order matches the audit row and the GL spec, defining form
     * first. At the END, so every existing offset is untouched. */
    void (*GLCopyTexImage2D)(GLcontext context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void (*GLCopyTexSubImage2D)(GLcontext context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    /* APPENDED 2026-09-12 (GL 1.1 audit item 10), entries 141 to 151. The
     * eleven entry points whose gl* macros had no function behind them: the
     * static archive has had real ones since that fix, and without these
     * slots a shared-library client still cannot reach any of them. Order is
     * gl.h's own prototype order. At the END, so every existing offset is
     * untouched and a client built on the 140-entry struct keeps working. */
    GLboolean (*GLAreTexturesResident)(GLcontext context, GLsizei n, const GLuint *textures, GLboolean *residences);
    void (*GLEdgeFlag)(GLcontext context, GLboolean flag);
    void (*GLEdgeFlagPointer)(GLcontext context, GLsizei stride, const GLvoid *pointer);
    void (*GLEdgeFlagv)(GLcontext context, const GLboolean *flag);
    void (*GLGetDoublev)(GLcontext context, GLenum pname, GLdouble *params);
    void (*GLGetPointerv)(GLcontext context, GLenum pname, GLvoid **params);
    void (*GLIndexi)(GLcontext context, GLint c);
    void (*GLIndexiv)(GLcontext context, const GLint *c);
    void (*GLIndexPointer)(GLcontext context, GLenum type, GLsizei stride, const GLvoid *pointer);
    void (*GLPrioritizeTextures)(GLcontext context, GLsizei n, const GLuint *textures, const GLclampf *priorities);
    void (*GLReadBuffer)(GLcontext context, GLenum mode);

    /* APPENDED 2026-09-20. Every existing offset stays put; a positional
     * initialiser rebinds silently if anything is inserted above. ABI version
     * deliberately NOT bumped -- structSize is the real guard, and its direction
     * is already right (new library + old client passes untouched, old library +
     * client built on this header is cleanly refused). */
    void * (*MGLCreateContextFromWindow)(struct Window *window);

    /* APPENDED 2026-09-20, after MGLCreateContextFromWindow. Same rule: end of
     * the struct, all three tables together, ABI version untouched. */
    void * (*MGLCreateContextFromBitMap)(struct BitMap *bitmap);

    /* APPENDED 2026-09-27 for minigl.library 28.0 -- 47 entries, slots 153..199,
     * taking the table from 153 to 200. Everything before this block is
     * untouched, which is what keeps existing clients working: MiniGLOpen's
     * guard is `dispatch->structSize < sizeof(MGLDispatchTable)`, so a client
     * built on the shorter struct still accepts this longer library, while one
     * rebuilt on this header correctly refuses an older one. ABI version stays
     * 3; structSize is the real guard.
     *
     * ALL THREE TABLES GROW TOGETHER. A short positional initialiser zero-fills
     * the trailing slots while sizeof still reports the full struct, so the ABI
     * check passes and the call NULL-derefs.
     *
     * These 47 are what made GL, GLU and GLUT reachable through the library
     * rather than only through the static archive: fixed-function lighting,
     * display lists, the GLU quadrics and mipmap builder, and GLUT. Base MiniGL
     * has none of them, so the classic table answers every one with a stub. */

    /* core GL -- fixed-function lighting */
    void (*GLLightf)(GLcontext context, GLenum light, GLenum pname, GLfloat param);
    void (*GLLightfv)(GLcontext context, GLenum light, GLenum pname, const GLfloat *params);
    void (*GLMaterialf)(GLcontext context, GLenum face, GLenum pname, GLfloat param);
    void (*GLMaterialfv)(GLcontext context, GLenum face, GLenum pname, const GLfloat *params);
    void (*GLLightModelf)(GLcontext context, GLenum pname, GLfloat param);
    void (*GLLightModelfv)(GLcontext context, GLenum pname, const GLfloat *params);
    void (*GLGetLightfv)(GLcontext context, GLenum light, GLenum pname, GLfloat *params);
    void (*GLGetMaterialfv)(GLcontext context, GLenum face, GLenum pname, GLfloat *params);

    /* core GL -- display lists */
    GLuint (*GLGenLists)(GLcontext context, GLsizei range);
    void (*GLDeleteLists)(GLcontext context, GLuint list, GLsizei range);
    GLboolean (*GLIsList)(GLcontext context, GLuint list);
    void (*GLNewList)(GLcontext context, GLuint list, GLenum mode);
    void (*GLEndList)(GLcontext context);
    void (*GLCallList)(GLcontext context, GLuint list);

    /* GLU */
    GLint (*GLUBuild2DMipmaps)(GLcontext context, GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data);
    const GLubyte * (*GLUErrorString)(GLenum errCode);
    GLUquadricObj * (*GLUNewQuadric)(void);
    void (*GLUDeleteQuadric)(GLUquadricObj *q);
    void (*GLUQuadricNormals)(GLUquadricObj *q, GLenum normals);
    void (*GLUQuadricTexture)(GLUquadricObj *q, GLboolean textureCoords);
    void (*GLUQuadricDrawStyle)(GLUquadricObj *q, GLenum drawStyle);
    void (*GLUQuadricOrientation)(GLUquadricObj *q, GLenum orientation);
    void (*GLUCylinder)(GLUquadricObj *q, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
    void (*GLUSphere)(GLUquadricObj *q, GLdouble radius, GLint slices, GLint stacks);
    void (*GLUDisk)(GLUquadricObj *q, GLdouble inner, GLdouble outer, GLint slices, GLint loops);

    /* GLUT */
    void (*GLUTInit)(int *argcp, char **argv);
    void (*GLUTInitDisplayMode)(unsigned int mode);
    void (*GLUTInitWindowSize)(int width, int height);
    void (*GLUTInitWindowPosition)(int x, int y);
    int (*GLUTCreateWindow)(const char *title);
    void (*GLUTMainLoop)(void);
    void (*GLUTDisplayFunc)(void (*func)(void));
    void (*GLUTIdleFunc)(void (*func)(void));
    void (*GLUTKeyboardFunc)(void (*func)(unsigned char key, int x, int y));
    void (*GLUTReshapeFunc)(void (*func)(int width, int height));
    void (*GLUTSwapBuffers)(void);
    void (*GLUTPostRedisplay)(void);
    int (*GLUTGet)(GLenum state);
    void (*GLUTGameModeString)(const char *string);
    int (*GLUTEnterGameMode)(void);
    void (*GLUTLeaveGameMode)(void);
    int (*GLUTGameModeGet)(GLenum query);
    void (*GLUTSolidCube)(GLdouble size);
    void (*GLUTSolidSphere)(GLdouble radius, GLint slices, GLint stacks);
    void (*GLUTSolidCone)(GLdouble base, GLdouble height, GLint slices, GLint stacks);
    void (*GLUTSolidTorus)(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    void (*GLUTSolidDodecahedron)(void);
    /* APPENDED, and it must stay last: this table is a POSITIONAL initialiser,
     * so a member inserted anywhere above shifts every pointer after it in all
     * three tables at once. structSize is what lets an older library be
     * refused; the ABI version does not move for an append. */
    void (*GLNormalPointer)(GLcontext context, GLenum type, GLsizei stride, const GLvoid *pointer);
    /* Slot 202, appended 2026-10-03. A quadric's GLU_ERROR callback, which is
     * the only error channel GLU gives a quadric -- every argument rejection in
     * gluCylinder, gluSphere, gluDisk and the three validating setters reports
     * through it. Takes no GLcontext: a quadric is not context state. */
    void (*GLUQuadricCallback)(GLUquadricObj *q, GLenum which, MGLUfuncptr fn);
    /* Slot 203, appended 2026-10-04. GL_COLOR_MATERIAL's parameter: which
     * material component tracks the per-vertex colour. The capability itself
     * goes through glEnable and needs no slot. */
    void (*GLColorMaterial)(GLcontext context, GLenum face, GLenum mode);
    /* Slot 204, appended 2026-10-04. GL_TEXTURE_ENV_COLOR, the constant
     * GL_BLEND's equation blends toward. The integer GLTexEnvi cannot carry
     * four floats and refuses that pname. */
    void (*GLTexEnvfv)(GLcontext context, GLenum target, GLenum pname, const GLfloat *params);
    /* Slot 205, appended 2026-10-05. glNormal3fv reaches its own entry point
     * rather than expanding to GLNormal3f in the header, so the NULL guard the
     * driver carries is reachable from both linkages. */
    void (*GLNormal3fv)(GLcontext context, GLfloat *n);
    /* Slots 206-214, appended 2026-10-24 (minigl-build): buffer objects,
     * GL_ARB_vertex_buffer_object / GL 1.5. One slot per entry point; the
     * ARB names are macros onto the same slots. */
    void (*GLGenBuffers)(GLcontext context, GLsizei n, GLuint *buffers);
    void (*GLDeleteBuffers)(GLcontext context, GLsizei n, const GLuint *buffers);
    GLboolean (*GLIsBuffer)(GLcontext context, GLuint buffer);
    void (*GLBindBuffer)(GLcontext context, GLenum target, GLuint buffer);
    void (*GLBufferData)(GLcontext context, GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
    void (*GLBufferSubData)(GLcontext context, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
    void (*GLGetBufferParameteriv)(GLcontext context, GLenum target, GLenum pname, GLint *params);
    GLvoid * (*GLMapBuffer)(GLcontext context, GLenum target, GLenum access);
    GLboolean (*GLUnmapBuffer)(GLcontext context, GLenum target);
} MGLDispatchTable;

extern const MGLDispatchTable *MiniGLDispatch;

#ifndef MINIGL_LIBRARY_BUILD
#define MGLD_CTX (*MiniGLDispatch->currentContext)

static __inline__ void MGLD_glActiveTextureARB(GLenum unit)
{
    MiniGLDispatch->GLActiveTextureARB(MGLD_CTX, unit);
}
/*
 * EVERY dispatch name is #undef'd before it is defined. <mgl/gl.h> has already
 * defined 173 of these as function-like macros calling the entry points
 * directly, and redefining a macro with a different body is a diagnostic --
 * one warning per name per translation unit, which buried real warnings under
 * hundreds of lines of noise in every library-client build. The dispatch
 * wrappers are meant to win here; saying so explicitly is the difference
 * between winning quietly and winning loudly.
 */
#undef glActiveTextureARB
#define glActiveTextureARB MGLD_glActiveTextureARB

static __inline__ void MGLD_glAlphaFunc(GLenum func, GLclampf ref)
{
    MiniGLDispatch->GLAlphaFunc(MGLD_CTX, func, ref);
}
#undef glAlphaFunc
#define glAlphaFunc MGLD_glAlphaFunc

static __inline__ void MGLD_glArrayElement(GLint i)
{
    MiniGLDispatch->GLArrayElement(MGLD_CTX, i);
}
#undef glArrayElement
#define glArrayElement MGLD_glArrayElement

static __inline__ void MGLD_glBegin(GLenum mode)
{
    MiniGLDispatch->GLBegin(MGLD_CTX, mode);
}
#undef glBegin
#define glBegin MGLD_glBegin

static __inline__ void MGLD_glBindTexture(GLenum target, GLuint texture)
{
    MiniGLDispatch->GLBindTexture(MGLD_CTX, target, texture);
}
#undef glBindTexture
#define glBindTexture MGLD_glBindTexture

static __inline__ void MGLD_glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    MiniGLDispatch->GLBlendFunc(MGLD_CTX, sfactor, dfactor);
}
#undef glBlendFunc
#define glBlendFunc MGLD_glBlendFunc

static __inline__ void MGLD_glClear(GLbitfield mask)
{
    MiniGLDispatch->GLClear(MGLD_CTX, mask);
}
#undef glClear
#define glClear MGLD_glClear

static __inline__ void MGLD_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    MiniGLDispatch->GLClearColor(MGLD_CTX, red, green, blue, alpha);
}
#undef glClearColor
#define glClearColor MGLD_glClearColor

static __inline__ void MGLD_glClearDepth(GLclampd depth)
{
    MiniGLDispatch->GLClearDepth(MGLD_CTX, depth);
}
#undef glClearDepth
#define glClearDepth MGLD_glClearDepth

static __inline__ void MGLD_glColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
    MiniGLDispatch->GLColor4f(MGLD_CTX, red, green, blue, 1.0f);
}
#undef glColor3f
#define glColor3f MGLD_glColor3f

static __inline__ void MGLD_glColor3fv(GLfloat *v)
{
    MiniGLDispatch->GLColor3fv(MGLD_CTX, v);
}
#undef glColor3fv
#define glColor3fv MGLD_glColor3fv

static __inline__ void MGLD_glColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
    MiniGLDispatch->GLColor4ub(MGLD_CTX, red, green, blue, 255);
}
#undef glColor3ub
#define glColor3ub MGLD_glColor3ub

static __inline__ void MGLD_glColor3ubv(GLubyte *v)
{
    MiniGLDispatch->GLColor3ubv(MGLD_CTX, v);
}
#undef glColor3ubv
#define glColor3ubv MGLD_glColor3ubv

static __inline__ void MGLD_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    MiniGLDispatch->GLColor4f(MGLD_CTX, red, green, blue, alpha);
}
#undef glColor4f
#define glColor4f MGLD_glColor4f

static __inline__ void MGLD_glColor4fv(GLfloat *v)
{
    MiniGLDispatch->GLColor4fv(MGLD_CTX, v);
}
#undef glColor4fv
#define glColor4fv MGLD_glColor4fv

static __inline__ void MGLD_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
    MiniGLDispatch->GLColor4ub(MGLD_CTX, red, green, blue, alpha);
}
#undef glColor4ub
#define glColor4ub MGLD_glColor4ub

static __inline__ void MGLD_glColor4ubv(GLubyte *v)
{
    MiniGLDispatch->GLColor4ubv(MGLD_CTX, v);
}
#undef glColor4ubv
#define glColor4ubv MGLD_glColor4ubv

static __inline__ void MGLD_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    MiniGLDispatch->GLColorMask(MGLD_CTX, red, green, blue, alpha);
}
#undef glColorMask
#define glColorMask MGLD_glColorMask

static __inline__ void MGLD_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLColorPointer(MGLD_CTX, size, type, stride, pointer);
}
#undef glColorPointer
#define glColorPointer MGLD_glColorPointer

static __inline__ void MGLD_glColorTable(GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, GLvoid *data)
{
    MiniGLDispatch->GLColorTable(MGLD_CTX, target, internalformat, width, format, type, data);
}
#undef glColorTable
#define glColorTable MGLD_glColorTable

static __inline__ void MGLD_glColorTableEXT(GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, GLvoid *data)
{
    MiniGLDispatch->GLColorTable(MGLD_CTX, target, internalformat, width, format, type, data);
}
#undef glColorTableEXT
#define glColorTableEXT MGLD_glColorTableEXT

static __inline__ void MGLD_glCullFace(GLenum mode)
{
    MiniGLDispatch->GLCullFace(MGLD_CTX, mode);
}
#undef glCullFace
#define glCullFace MGLD_glCullFace

static __inline__ void MGLD_glDeleteTextures(GLsizei n, const GLuint *textures)
{
    MiniGLDispatch->GLDeleteTextures(MGLD_CTX, n, textures);
}
#undef glDeleteTextures
#define glDeleteTextures MGLD_glDeleteTextures

static __inline__ void MGLD_glDepthFunc(GLenum func)
{
    MiniGLDispatch->GLDepthFunc(MGLD_CTX, func);
}
#undef glDepthFunc
#define glDepthFunc MGLD_glDepthFunc

static __inline__ void MGLD_glDepthMask(GLboolean flag)
{
    MiniGLDispatch->GLDepthMask(MGLD_CTX, flag);
}
#undef glDepthMask
#define glDepthMask MGLD_glDepthMask

static __inline__ void MGLD_glDepthRange(GLclampd n, GLclampd f)
{
    MiniGLDispatch->GLDepthRange(MGLD_CTX, n, f);
}
#undef glDepthRange
#define glDepthRange MGLD_glDepthRange

static __inline__ void MGLD_glDisable(GLenum cap)
{
    MiniGLDispatch->MGLSetState(MGLD_CTX, cap, GL_FALSE);
}
#undef glDisable
#define glDisable MGLD_glDisable

static __inline__ void MGLD_glDisableClientState(GLenum cap)
{
    MiniGLDispatch->GLDisableClientState(MGLD_CTX, cap);
}
#undef glDisableClientState
#define glDisableClientState MGLD_glDisableClientState

static __inline__ void MGLD_glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    MiniGLDispatch->GLDrawArrays(MGLD_CTX, mode, first, count);
}
#undef glDrawArrays
#define glDrawArrays MGLD_glDrawArrays

static __inline__ void MGLD_glDrawBuffer(GLenum mode)
{
    MiniGLDispatch->GLDrawBuffer(MGLD_CTX, mode);
}
#undef glDrawBuffer
#define glDrawBuffer MGLD_glDrawBuffer

static __inline__ void MGLD_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *pointer)
{
    MiniGLDispatch->GLDrawElements(MGLD_CTX, mode, count, type, pointer);
}
#undef glDrawElements
#define glDrawElements MGLD_glDrawElements

static __inline__ void MGLD_glEnable(GLenum cap)
{
    MiniGLDispatch->MGLSetState(MGLD_CTX, cap, GL_TRUE);
}
#undef glEnable
#define glEnable MGLD_glEnable

static __inline__ void MGLD_glEnableClientState(GLenum cap)
{
    MiniGLDispatch->GLEnableClientState(MGLD_CTX, cap);
}
#undef glEnableClientState
#define glEnableClientState MGLD_glEnableClientState

static __inline__ void MGLD_glEnd(void)
{
    MiniGLDispatch->GLEnd(MGLD_CTX);
    
}
#undef glEnd
#define glEnd MGLD_glEnd

static __inline__ void MGLD_glFinish(void)
{
    MiniGLDispatch->GLFinish(MGLD_CTX);
}
#undef glFinish
#define glFinish MGLD_glFinish

static __inline__ void MGLD_glFlush(void)
{
    MiniGLDispatch->GLFlush(MGLD_CTX);
}
#undef glFlush
#define glFlush MGLD_glFlush

static __inline__ void MGLD_glFogf(GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLFogf(MGLD_CTX, pname, param);
}
#undef glFogf
#define glFogf MGLD_glFogf

static __inline__ void MGLD_glFogfv(GLenum pname, GLfloat *param)
{
    MiniGLDispatch->GLFogfv(MGLD_CTX, pname, param);
}
#undef glFogfv
#define glFogfv MGLD_glFogfv

static __inline__ void MGLD_glFogi(GLenum pname, GLint param)
{
    MiniGLDispatch->GLFogf(MGLD_CTX, pname, (GLfloat)param);
}
#undef glFogi
#define glFogi MGLD_glFogi

static __inline__ void MGLD_glFrontFace(GLenum mode)
{
    MiniGLDispatch->GLFrontFace(MGLD_CTX, mode);
}
#undef glFrontFace
#define glFrontFace MGLD_glFrontFace

static __inline__ void MGLD_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    MiniGLDispatch->GLFrustum(MGLD_CTX, left, right, bottom, top, zNear, zFar);
}
#undef glFrustum
#define glFrustum MGLD_glFrustum

static __inline__ void MGLD_glGenTextures(GLsizei n, GLuint *textures)
{
    MiniGLDispatch->GLGenTextures(MGLD_CTX, n, textures);
}
#undef glGenTextures
#define glGenTextures MGLD_glGenTextures

static __inline__ void MGLD_glGetBooleanv(GLenum pname, GLboolean *params)
{
    MiniGLDispatch->GLGetBooleanv(MGLD_CTX, pname, params);
}
#undef glGetBooleanv
#define glGetBooleanv MGLD_glGetBooleanv

static __inline__ GLenum MGLD_glGetError(void)
{
    return MiniGLDispatch->GLGetError(MGLD_CTX);
}
#undef glGetError
#define glGetError MGLD_glGetError

static __inline__ void MGLD_glGetFloatv(GLenum pname, GLfloat *params)
{
    MiniGLDispatch->GLGetFloatv(MGLD_CTX, pname, params);
}
#undef glGetFloatv
#define glGetFloatv MGLD_glGetFloatv

static __inline__ void MGLD_glGetIntegerv(GLenum pname, GLint *params)
{
    MiniGLDispatch->GLGetIntegerv(MGLD_CTX, pname, params);
}
#undef glGetIntegerv
#define glGetIntegerv MGLD_glGetIntegerv

static __inline__ const GLubyte * MGLD_glGetString(GLenum name)
{
    return MiniGLDispatch->GLGetString(MGLD_CTX, name);
}
#undef glGetString
#define glGetString MGLD_glGetString

static __inline__ void MGLD_glHint(GLenum target, GLenum mode)
{
    MiniGLDispatch->GLHint(MGLD_CTX, target, mode);
}
#undef glHint
#define glHint MGLD_glHint

static __inline__ GLboolean MGLD_glIsEnabled(GLenum cap)
{
    return MiniGLDispatch->GLIsEnabled(MGLD_CTX, cap);
}
#undef glIsEnabled
#define glIsEnabled MGLD_glIsEnabled

static __inline__ void MGLD_glLoadIdentity(void)
{
    MiniGLDispatch->GLLoadIdentity(MGLD_CTX);
}
#undef glLoadIdentity
#define glLoadIdentity MGLD_glLoadIdentity

static __inline__ void MGLD_glLoadMatrixd(const GLdouble *m)
{
    MiniGLDispatch->GLLoadMatrixd(MGLD_CTX, m);
}
#undef glLoadMatrixd
#define glLoadMatrixd MGLD_glLoadMatrixd

static __inline__ void MGLD_glLoadMatrixf(const GLfloat *m)
{
    MiniGLDispatch->GLLoadMatrixf(MGLD_CTX, m);
}
#undef glLoadMatrixf
#define glLoadMatrixf MGLD_glLoadMatrixf

static __inline__ void MGLD_glLockArrays(GLuint first, GLsizei count)
{
    MiniGLDispatch->GLLockArrays(MGLD_CTX, first, count);
}
#undef glLockArrays
#define glLockArrays MGLD_glLockArrays

static __inline__ void MGLD_glMatrixMode(GLenum mode)
{
    MiniGLDispatch->GLMatrixMode(MGLD_CTX, mode);
}
#undef glMatrixMode
#define glMatrixMode MGLD_glMatrixMode

static __inline__ void MGLD_glMultiTexCoord2fARB(GLenum unit, GLfloat s, GLfloat t)
{
    MiniGLDispatch->GLMultiTexCoord2fARB(MGLD_CTX, unit, s, t);
}
#undef glMultiTexCoord2fARB
#define glMultiTexCoord2fARB MGLD_glMultiTexCoord2fARB

static __inline__ void MGLD_glMultiTexCoord2fvARB(GLenum unit, GLfloat *v)
{
    MiniGLDispatch->GLMultiTexCoord2fvARB(MGLD_CTX, unit, v);
}
#undef glMultiTexCoord2fvARB
#define glMultiTexCoord2fvARB MGLD_glMultiTexCoord2fvARB

static __inline__ void MGLD_glMultMatrixd(const GLdouble *m)
{
    MiniGLDispatch->GLMultMatrixd(MGLD_CTX, m);
}
#undef glMultMatrixd
#define glMultMatrixd MGLD_glMultMatrixd

static __inline__ void MGLD_glMultMatrixf(const GLfloat *m)
{
    MiniGLDispatch->GLMultMatrixf(MGLD_CTX, m);
}
#undef glMultMatrixf
#define glMultMatrixf MGLD_glMultMatrixf

static __inline__ void MGLD_glNormal3f(GLfloat x, GLfloat y, GLfloat z)
{
    MiniGLDispatch->GLNormal3f(MGLD_CTX, x, y, z);
}
#undef glNormal3f
#define glNormal3f MGLD_glNormal3f

/* Its own slot rather than an expansion onto glNormal3f, so a library client
 * reaches the driver's NULL guard. A static inline, so `v` is evaluated once. */
static __inline__ void MGLD_glNormal3fv(GLfloat *v)
{
    MiniGLDispatch->GLNormal3fv(MGLD_CTX, v);
}
#undef glNormal3fv
#define glNormal3fv MGLD_glNormal3fv

/* Buffer objects (slots 206-214), GL 1.5 and ARB names. */
static __inline__ void MGLD_glGenBuffers(GLsizei n, GLuint *buffers)
{
    MiniGLDispatch->GLGenBuffers(MGLD_CTX, n, buffers);
}
#undef glGenBuffers
#define glGenBuffers MGLD_glGenBuffers
#undef glGenBuffersARB
#define glGenBuffersARB MGLD_glGenBuffers

static __inline__ void MGLD_glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
    MiniGLDispatch->GLDeleteBuffers(MGLD_CTX, n, buffers);
}
#undef glDeleteBuffers
#define glDeleteBuffers MGLD_glDeleteBuffers
#undef glDeleteBuffersARB
#define glDeleteBuffersARB MGLD_glDeleteBuffers

static __inline__ GLboolean MGLD_glIsBuffer(GLuint buffer)
{
    return MiniGLDispatch->GLIsBuffer(MGLD_CTX, buffer);
}
#undef glIsBuffer
#define glIsBuffer MGLD_glIsBuffer
#undef glIsBufferARB
#define glIsBufferARB MGLD_glIsBuffer

static __inline__ void MGLD_glBindBuffer(GLenum target, GLuint buffer)
{
    MiniGLDispatch->GLBindBuffer(MGLD_CTX, target, buffer);
}
#undef glBindBuffer
#define glBindBuffer MGLD_glBindBuffer
#undef glBindBufferARB
#define glBindBufferARB MGLD_glBindBuffer

static __inline__ void MGLD_glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
    MiniGLDispatch->GLBufferData(MGLD_CTX, target, size, data, usage);
}
#undef glBufferData
#define glBufferData MGLD_glBufferData
#undef glBufferDataARB
#define glBufferDataARB MGLD_glBufferData

static __inline__ void MGLD_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
    MiniGLDispatch->GLBufferSubData(MGLD_CTX, target, offset, size, data);
}
#undef glBufferSubData
#define glBufferSubData MGLD_glBufferSubData
#undef glBufferSubDataARB
#define glBufferSubDataARB MGLD_glBufferSubData

static __inline__ void MGLD_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    MiniGLDispatch->GLGetBufferParameteriv(MGLD_CTX, target, pname, params);
}
#undef glGetBufferParameteriv
#define glGetBufferParameteriv MGLD_glGetBufferParameteriv
#undef glGetBufferParameterivARB
#define glGetBufferParameterivARB MGLD_glGetBufferParameteriv

static __inline__ GLvoid * MGLD_glMapBuffer(GLenum target, GLenum access)
{
    return MiniGLDispatch->GLMapBuffer(MGLD_CTX, target, access);
}
#undef glMapBuffer
#define glMapBuffer MGLD_glMapBuffer
#undef glMapBufferARB
#define glMapBufferARB MGLD_glMapBuffer

static __inline__ GLboolean MGLD_glUnmapBuffer(GLenum target)
{
    return MiniGLDispatch->GLUnmapBuffer(MGLD_CTX, target);
}
#undef glUnmapBuffer
#define glUnmapBuffer MGLD_glUnmapBuffer
#undef glUnmapBufferARB
#define glUnmapBufferARB MGLD_glUnmapBuffer


static __inline__ void MGLD_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    MiniGLDispatch->GLOrtho(MGLD_CTX, left, right, bottom, top, zNear, zFar);
}
#undef glOrtho
#define glOrtho MGLD_glOrtho

static __inline__ void MGLD_glPixelStorei(GLenum pname, GLint param)
{
    MiniGLDispatch->GLPixelStorei(MGLD_CTX, pname, param);
}
#undef glPixelStorei
#define glPixelStorei MGLD_glPixelStorei

static __inline__ void MGLD_glPointSize(GLfloat s)
{
    MiniGLDispatch->GLPointSize(MGLD_CTX, s);
}
#undef glPointSize
#define glPointSize MGLD_glPointSize

/* Beside its sibling for discoverability. Only the STRUCT above is
 * order-sensitive; these wrappers are ordinary inlines. */
static __inline__ void MGLD_glLineWidth(GLfloat w)
{
    MiniGLDispatch->GLLineWidth(MGLD_CTX, w);
}
#undef glLineWidth
#define glLineWidth MGLD_glLineWidth

static __inline__ void MGLD_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params)
{
    MiniGLDispatch->GLTexGenfv(MGLD_CTX, coord, pname, params);
}
#undef glTexGenfv
#define glTexGenfv MGLD_glTexGenfv

static __inline__ void MGLD_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    MiniGLDispatch->GLCopyTexImage2D(MGLD_CTX, target, level, internalformat, x, y, width, height, border);
}
#undef glCopyTexImage2D
#define glCopyTexImage2D MGLD_glCopyTexImage2D

static __inline__ void MGLD_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    MiniGLDispatch->GLCopyTexSubImage2D(MGLD_CTX, target, level, xoffset, yoffset, x, y, width, height);
}
#undef glCopyTexSubImage2D
#define glCopyTexSubImage2D MGLD_glCopyTexSubImage2D

static __inline__ void MGLD_glPolygonMode(GLenum face, GLenum mode)
{
    MiniGLDispatch->GLPolygonMode(MGLD_CTX, face, mode);
}
#undef glPolygonMode
#define glPolygonMode MGLD_glPolygonMode

static __inline__ void MGLD_glPolygonOffset(GLfloat factor, GLfloat units)
{
    MiniGLDispatch->GLPolygonOffset(MGLD_CTX, factor, units);
}
#undef glPolygonOffset
#define glPolygonOffset MGLD_glPolygonOffset

static __inline__ void MGLD_glPopMatrix(void)
{
    MiniGLDispatch->GLPopMatrix(MGLD_CTX);
}
#undef glPopMatrix
#define glPopMatrix MGLD_glPopMatrix

static __inline__ void MGLD_glPushMatrix(void)
{
    MiniGLDispatch->GLPushMatrix(MGLD_CTX);
}
#undef glPushMatrix
#define glPushMatrix MGLD_glPushMatrix

static __inline__ void MGLD_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
    MiniGLDispatch->GLReadPixels(MGLD_CTX, x, y, width, height, format, type, pixels);
}
#undef glReadPixels
#define glReadPixels MGLD_glReadPixels

static __inline__ void MGLD_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
    MiniGLDispatch->GLRotated(MGLD_CTX, angle, x, y, z);
}
#undef glRotated
#define glRotated MGLD_glRotated

static __inline__ void MGLD_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    MiniGLDispatch->GLRotatef(MGLD_CTX, angle, x, y, z);
}
#undef glRotatef
#define glRotatef MGLD_glRotatef

static __inline__ void MGLD_glRotatefEXT(GLfloat angle, const GLint xyz)
{
    MiniGLDispatch->GLRotatefEXT(MGLD_CTX, angle, xyz);
}
#undef glRotatefEXT
#define glRotatefEXT MGLD_glRotatefEXT

static __inline__ void MGLD_glRotatefEXTs(GLfloat sin_an, GLfloat cos_an, const GLint xyz)
{
    MiniGLDispatch->GLRotatefEXTs(MGLD_CTX, sin_an, cos_an, xyz);
}
#undef glRotatefEXTs
#define glRotatefEXTs MGLD_glRotatefEXTs

static __inline__ void MGLD_glScaled(GLdouble x, GLdouble y, GLdouble z)
{
    MiniGLDispatch->GLScaled(MGLD_CTX, x, y, z);
}
#undef glScaled
#define glScaled MGLD_glScaled

static __inline__ void MGLD_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
    MiniGLDispatch->GLScalef(MGLD_CTX, x, y, z);
}
#undef glScalef
#define glScalef MGLD_glScalef

static __inline__ void MGLD_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    MiniGLDispatch->GLScissor(MGLD_CTX, x, y, width, height);
}
#undef glScissor
#define glScissor MGLD_glScissor

static __inline__ void MGLD_glShadeModel(GLenum mode)
{
    MiniGLDispatch->GLShadeModel(MGLD_CTX, mode);
}
#undef glShadeModel
#define glShadeModel MGLD_glShadeModel

static __inline__ void MGLD_glTexCoord2f(GLfloat s, GLfloat t)
{
    MiniGLDispatch->GLTexCoord2f(MGLD_CTX, s, t);
}
#undef glTexCoord2f
#define glTexCoord2f MGLD_glTexCoord2f

static __inline__ void MGLD_glTexCoord2fv(GLfloat *v)
{
    MiniGLDispatch->GLTexCoord2fv(MGLD_CTX, v);
}
#undef glTexCoord2fv
#define glTexCoord2fv MGLD_glTexCoord2fv

static __inline__ void MGLD_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    MiniGLDispatch->GLTexCoord4f(MGLD_CTX, s, t, r, q);
}
#undef glTexCoord4f
#define glTexCoord4f MGLD_glTexCoord4f

static __inline__ void MGLD_glTexCoord4fv(GLfloat *v)
{
    MiniGLDispatch->GLTexCoord4fv(MGLD_CTX, v);
}
#undef glTexCoord4fv
#define glTexCoord4fv MGLD_glTexCoord4fv

static __inline__ void MGLD_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLTexCoordPointer(MGLD_CTX, size, type, stride, pointer);
}
#undef glTexCoordPointer
#define glTexCoordPointer MGLD_glTexCoordPointer

static __inline__ void MGLD_glTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLTexEnvi(MGLD_CTX, target, pname, (GLint)param);
}
#undef glTexEnvf
#define glTexEnvf MGLD_glTexEnvf

/* glTexEnvfv is NOT here: it has a real dispatch slot further down, which
 * forwards all four floats. The version that used to sit here passed only
 * (GLint)*param to GLTexEnvi, so GL_TEXTURE_ENV_COLOR could not be expressed
 * at all -- and leaving both in place is two conflicting definitions of one
 * static inline, which is a hard error for every library client. */

static __inline__ void MGLD_glTexEnvi(GLenum target, GLenum pname, GLint param)
{
    MiniGLDispatch->GLTexEnvi(MGLD_CTX, target, pname, param);
}
#undef glTexEnvi
#define glTexEnvi MGLD_glTexEnvi

static __inline__ void MGLD_glTexEnviv(GLenum target, GLenum pname, GLint *param)
{
    MiniGLDispatch->GLTexEnvi(MGLD_CTX, target, pname, *param);
}
#undef glTexEnviv
#define glTexEnviv MGLD_glTexEnviv

static __inline__ void MGLD_glTexGeni(GLenum coord, GLenum mode, GLenum map)
{
    MiniGLDispatch->GLTexGeni(MGLD_CTX, coord, mode, map);
}
#undef glTexGeni
#define glTexGeni MGLD_glTexGeni

static __inline__ void MGLD_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
    MiniGLDispatch->GLTexImage2D(MGLD_CTX, target, level, internalformat, width, height, border, format, type, pixels);
}
#undef glTexImage2D
#define glTexImage2D MGLD_glTexImage2D

static __inline__ void MGLD_glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLTexParameteri(MGLD_CTX, target, pname, (GLint)param);
}
#undef glTexParameterf
#define glTexParameterf MGLD_glTexParameterf

static __inline__ void MGLD_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    MiniGLDispatch->GLTexParameteri(MGLD_CTX, target, pname, param);
}
#undef glTexParameteri
#define glTexParameteri MGLD_glTexParameteri

static __inline__ void MGLD_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
    MiniGLDispatch->GLTexSubImage2D(MGLD_CTX, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
#undef glTexSubImage2D
#define glTexSubImage2D MGLD_glTexSubImage2D

static __inline__ void MGLD_glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
    MiniGLDispatch->GLTranslated(MGLD_CTX, x, y, z);
}
#undef glTranslated
#define glTranslated MGLD_glTranslated

static __inline__ void MGLD_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
    MiniGLDispatch->GLTranslatef(MGLD_CTX, x, y, z);
}
#undef glTranslatef
#define glTranslatef MGLD_glTranslatef

static __inline__ void MGLD_gluLookAt(GLfloat ex, GLfloat ey, GLfloat ez, GLfloat cx, GLfloat cy, GLfloat cz, GLfloat ux, GLfloat uy, GLfloat uz)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLULookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz);
}
#undef gluLookAt
#define gluLookAt MGLD_gluLookAt

static __inline__ void MGLD_glUnlockArrays(void)
{
    MiniGLDispatch->GLUnlockArrays(MGLD_CTX);
}
#undef glUnlockArrays
#define glUnlockArrays MGLD_glUnlockArrays

static __inline__ void MGLD_gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat znear, GLfloat zfar)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUPerspective(fovy, aspect, znear, zfar);
}
#undef gluPerspective
#define gluPerspective MGLD_gluPerspective

static __inline__ void MGLD_glVertex2f(GLfloat x, GLfloat y)
{
    MiniGLDispatch->GLVertex4f(MGLD_CTX, x, y, 0.0f, 1.0f);
}
#undef glVertex2f
#define glVertex2f MGLD_glVertex2f

static __inline__ void MGLD_glVertex2fv(GLfloat *v)
{
    MiniGLDispatch->GLVertex2fv(MGLD_CTX, v);
}
#undef glVertex2fv
#define glVertex2fv MGLD_glVertex2fv

static __inline__ void MGLD_glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
    MiniGLDispatch->GLVertex4f(MGLD_CTX, x, y, z, 1.0f);
}
#undef glVertex3f
#define glVertex3f MGLD_glVertex3f

static __inline__ void MGLD_glVertex3fv(GLfloat *v)
{
    MiniGLDispatch->GLVertex3fv(MGLD_CTX, v);
}
#undef glVertex3fv
#define glVertex3fv MGLD_glVertex3fv

static __inline__ void MGLD_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    MiniGLDispatch->GLVertex4f(MGLD_CTX, x, y, z, w);
}
#undef glVertex4f
#define glVertex4f MGLD_glVertex4f

static __inline__ void MGLD_glVertex4fv(GLfloat *v)
{
    MiniGLDispatch->GLVertex4fv(MGLD_CTX, v);
}
#undef glVertex4fv
#define glVertex4fv MGLD_glVertex4fv

static __inline__ void MGLD_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLVertexPointer(MGLD_CTX, size, type, stride, pointer);
}
#undef glVertexPointer
#define glVertexPointer MGLD_glVertexPointer

/* GL_NORMAL_ARRAY. No size argument: GL fixes a normal at 3 components. */
static __inline__ void MGLD_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLNormalPointer(MGLD_CTX, type, stride, pointer);
}
#undef glNormalPointer
#define glNormalPointer MGLD_glNormalPointer

/* A quadric's GLU_ERROR callback. fn stays unprototyped all the way through, as
 * GLU's _GLUfuncptr is, so the application's own void f(GLenum) needs no cast
 * at the call site. */
static __inline__ void MGLD_gluQuadricCallback(GLUquadricObj *q, GLenum which, MGLUfuncptr fn)
{
    MiniGLDispatch->GLUQuadricCallback(q, which, fn);
}
#undef gluQuadricCallback
#define gluQuadricCallback MGLD_gluQuadricCallback

/* GL_COLOR_MATERIAL's parameter. GL names five modes; the driver refuses
 * GL_SHININESS, a scalar having no vertex colour to track. */
static __inline__ void MGLD_glColorMaterial(GLenum face, GLenum mode)
{
    MiniGLDispatch->GLColorMaterial(MGLD_CTX, face, mode);
}
#undef glColorMaterial
#define glColorMaterial MGLD_glColorMaterial

/* The four-float texture-environment setter. GL_TEXTURE_ENV_MODE is accepted
 * here too and forwarded, so there is one implementation of the mode. */
static __inline__ void MGLD_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
    MiniGLDispatch->GLTexEnvfv(MGLD_CTX, target, pname, params);
}
#undef glTexEnvfv
#define glTexEnvfv MGLD_glTexEnvfv

#ifndef GL_NORMAL_ARRAY
#define GL_NORMAL_ARRAY          0x8075
#define GL_NORMAL_ARRAY_TYPE     0x807E
#define GL_NORMAL_ARRAY_STRIDE   0x807F
#define GL_NORMAL_ARRAY_POINTER  0x808F
#endif

static __inline__ void MGLD_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    MiniGLDispatch->GLViewport(MGLD_CTX, x, y, width, height);
}
#undef glViewport
#define glViewport MGLD_glViewport

static __inline__ void MGLD_mglChoosePixelDepth(int depth)
{
    if ((MiniGLDispatch->backendFlags & MINIGL_BACKEND_FLAG_PISTORM3D) && depth == 32)
        depth = 24;
    MiniGLDispatch->mglChoosePixelDepth(depth);
}
#undef mglChoosePixelDepth
#define mglChoosePixelDepth MGLD_mglChoosePixelDepth

static __inline__ void MGLD_mglClearPointer(void)
{
    MiniGLDispatch->MGLClearPointer(MGLD_CTX);
}
#undef mglClearPointer
#define mglClearPointer MGLD_mglClearPointer

static __inline__ void * MGLD_mglCreateContext(int offx, int offy, int w, int h)
{
    GLcontext context = (GLcontext)MiniGLDispatch->MGLCreateContext(offx, offy, w, h);
    if (context) (*MiniGLDispatch->currentContext) = context;
    return (void *)context;
}
#undef mglCreateContext
#define mglCreateContext MGLD_mglCreateContext

static __inline__ void * MGLD_mglCreateContextFromID(GLint id, GLint *w, GLint *h)
{
    GLcontext context = (GLcontext)MiniGLDispatch->MGLCreateContextFromID(id, w, h);
    if (context) (*MiniGLDispatch->currentContext) = context;
    return (void *)context;
}
#undef mglCreateContextFromID
#define mglCreateContextFromID MGLD_mglCreateContextFromID

/* Render into a window the host already opened. Sets the client's current
 * context on success, exactly like the two above -- without this the caller
 * would get a valid context back and every subsequent gl* call would still go
 * to whatever was current before. (2026-09-20) */
static __inline__ void * MGLD_mglCreateContextFromWindow(struct Window *window)
{
    GLcontext context = (GLcontext)MiniGLDispatch->MGLCreateContextFromWindow(window);
    if (context) (*MiniGLDispatch->currentContext) = context;
    return (void *)context;
}
#undef mglCreateContextFromWindow
#define mglCreateContextFromWindow MGLD_mglCreateContextFromWindow

/* Render into a bitmap the host owns and presents itself. Sets the client's
 * current context, like every other creator here. (2026-09-20) */
static __inline__ void * MGLD_mglCreateContextFromBitMap(struct BitMap *bitmap)
{
    GLcontext context = (GLcontext)MiniGLDispatch->MGLCreateContextFromBitMap(bitmap);
    if (context) (*MiniGLDispatch->currentContext) = context;
    return (void *)context;
}
#undef mglCreateContextFromBitMap
#define mglCreateContextFromBitMap MGLD_mglCreateContextFromBitMap

static __inline__ void MGLD_mglDeleteContext(void)
{
    if ((*MiniGLDispatch->currentContext)) {
        GLcontext context = (*MiniGLDispatch->currentContext);
        (*MiniGLDispatch->currentContext) = (GLcontext)0;
        MiniGLDispatch->MGLDeleteContext(context);
    }
}
#undef mglDeleteContext
#define mglDeleteContext MGLD_mglDeleteContext

static __inline__ void MGLD_mglDrawMultitexBuffer(GLenum s, GLenum d, GLenum env)
{
    MiniGLDispatch->MGLDrawMultitexBuffer(MGLD_CTX, s, d, env);
}
#undef mglDrawMultitexBuffer
#define mglDrawMultitexBuffer MGLD_mglDrawMultitexBuffer

static __inline__ void MGLD_mglEnableSync(GLboolean enable)
{
    MiniGLDispatch->MGLEnableSync(MGLD_CTX, enable);
}
#undef mglEnableSync
#define mglEnableSync MGLD_mglEnableSync

static __inline__ void MGLD_mglExit(void)
{
    MiniGLDispatch->MGLExit(MGLD_CTX);
}
#undef mglExit
#define mglExit MGLD_mglExit

static __inline__ void * MGLD_mglGetWindowHandle(void)
{
    return MiniGLDispatch->MGLGetWindowHandle(MGLD_CTX);
}
#undef mglGetWindowHandle
#define mglGetWindowHandle MGLD_mglGetWindowHandle

static __inline__ void MGLD_mglIdleFunc(IdleFn i)
{
    MiniGLDispatch->MGLIdleFunc(MGLD_CTX, i);
}
#undef mglIdleFunc
#define mglIdleFunc MGLD_mglIdleFunc

static __inline__ void MGLD_mglKeyFunc(KeyHandlerFn k)
{
    MiniGLDispatch->MGLKeyFunc(MGLD_CTX, k);
}
#undef mglKeyFunc
#define mglKeyFunc MGLD_mglKeyFunc

static __inline__ GLboolean MGLD_mglLockBack(MGLLockInfo *info)
{
    return MiniGLDispatch->MGLLockBack(MGLD_CTX, info);
}
#undef mglLockBack
#define mglLockBack MGLD_mglLockBack

static __inline__ GLboolean MGLD_mglLockDisplay(void)
{
    return MiniGLDispatch->MGLLockDisplay(MGLD_CTX);
}
#undef mglLockDisplay
#define mglLockDisplay MGLD_mglLockDisplay

static __inline__ void MGLD_mglLockMode(GLenum lockMode)
{
    MiniGLDispatch->MGLLockMode(MGLD_CTX, lockMode);
}
#undef mglLockMode
#define mglLockMode MGLD_mglLockMode

static __inline__ void MGLD_mglMainLoop(void)
{
    MiniGLDispatch->MGLMainLoop(MGLD_CTX);
}
#undef mglMainLoop
#define mglMainLoop MGLD_mglMainLoop

static __inline__ void MGLD_mglMinTriArea(GLfloat area)
{
    MiniGLDispatch->MGLMinTriArea(MGLD_CTX, area);
}
#undef mglMinTriArea
#define mglMinTriArea MGLD_mglMinTriArea

static __inline__ void MGLD_mglMouseFunc(MouseHandlerFn m)
{
    MiniGLDispatch->MGLMouseFunc(MGLD_CTX, m);
}
#undef mglMouseFunc
#define mglMouseFunc MGLD_mglMouseFunc

static __inline__ void MGLD_mglPrintMatrix(GLenum mode)
{
    MiniGLDispatch->MGLPrintMatrix(MGLD_CTX, mode);
}
#undef mglPrintMatrix
#define mglPrintMatrix MGLD_mglPrintMatrix

static __inline__ void MGLD_mglPrintMatrixStack(GLenum mode)
{
    MiniGLDispatch->MGLPrintMatrixStack(MGLD_CTX, mode);
}
#undef mglPrintMatrixStack
#define mglPrintMatrixStack MGLD_mglPrintMatrixStack

/* Returns GL_FALSE when the reopen failed and the display is now closed. The
 * table holds a POINTER, so widening the return moved no field and structSize
 * is unchanged; a caller built against the old void declaration ignores d0. */
static __inline__ GLboolean MGLD_mglResizeContext(GLsizei width, GLsizei height)
{
    return MiniGLDispatch->MGLResizeContext(MGLD_CTX, width, height);
}
#undef mglResizeContext
#define mglResizeContext MGLD_mglResizeContext

static __inline__ void MGLD_mglSetPointer(void)
{
    MiniGLDispatch->MGLSetPointer(MGLD_CTX);
}
#undef mglSetPointer
#define mglSetPointer MGLD_mglSetPointer

static __inline__ void MGLD_mglSetZOffset(GLfloat offset)
{
    MiniGLDispatch->MGLSetZOffset(MGLD_CTX, offset);
}
#undef mglSetZOffset
#define mglSetZOffset MGLD_mglSetZOffset

static __inline__ void MGLD_mglSpecialFunc(SpecialHandlerFn s)
{
    MiniGLDispatch->MGLSpecialFunc(MGLD_CTX, s);
}
#undef mglSpecialFunc
#define mglSpecialFunc MGLD_mglSpecialFunc

static __inline__ void MGLD_mglSwitchDisplay(void)
{
    MiniGLDispatch->MGLSwitchDisplay(MGLD_CTX);
}
#undef mglSwitchDisplay
#define mglSwitchDisplay MGLD_mglSwitchDisplay

static __inline__ void MGLD_mglTexMemStat(GLint *Current, GLint *Peak)
{
    MiniGLDispatch->MGLTexMemStat(MGLD_CTX, Current, Peak);
}
#undef mglTexMemStat
#define mglTexMemStat MGLD_mglTexMemStat

static __inline__ void MGLD_mglUnlockDisplay(void)
{
    MiniGLDispatch->MGLUnlockDisplay(MGLD_CTX);
}
#undef mglUnlockDisplay
#define mglUnlockDisplay MGLD_mglUnlockDisplay

static __inline__ void MGLD_mglWriteShotPPM(char *filename)
{
    MiniGLDispatch->MGLWriteShotPPM(MGLD_CTX, filename);
}
#undef mglWriteShotPPM
#define mglWriteShotPPM MGLD_mglWriteShotPPM

static __inline__ void MGLD_mglChooseNumberOfBuffers(int number)
{
    MiniGLDispatch->mglChooseNumberOfBuffers(number);
}
#undef mglChooseNumberOfBuffers
#define mglChooseNumberOfBuffers MGLD_mglChooseNumberOfBuffers

static __inline__ void MGLD_mglChooseVertexBufferSize(int size)
{
    MiniGLDispatch->mglChooseVertexBufferSize(size);
}
#undef mglChooseVertexBufferSize
#define mglChooseVertexBufferSize MGLD_mglChooseVertexBufferSize

static __inline__ void MGLD_mglChooseWindowMode(GLboolean flag)
{
    MiniGLDispatch->mglChooseWindowMode(flag);
}
#undef mglChooseWindowMode
#define mglChooseWindowMode MGLD_mglChooseWindowMode

static __inline__ void MGLD_mglProposeCloseDesktop(GLboolean closeme)
{
    MiniGLDispatch->mglProposeCloseDesktop(closeme);
}
#undef mglProposeCloseDesktop
#define mglProposeCloseDesktop MGLD_mglProposeCloseDesktop

static __inline__ void MGLD_mglChooseGuardBand(GLboolean flag)
{
    MiniGLDispatch->mglChooseGuardBand(flag);
}
#undef mglChooseGuardBand
#define mglChooseGuardBand MGLD_mglChooseGuardBand

static __inline__ void MGLD_mglChooseMtexBufferSize(int size)
{
    MiniGLDispatch->mglChooseMtexBufferSize(size);
}
#undef mglChooseMtexBufferSize
#define mglChooseMtexBufferSize MGLD_mglChooseMtexBufferSize

static __inline__ void MGLD_mglChooseTextureBufferSize(int size)
{
    MiniGLDispatch->mglChooseTextureBufferSize(size);
}
#undef mglChooseTextureBufferSize
#define mglChooseTextureBufferSize MGLD_mglChooseTextureBufferSize

static __inline__ void MGLD_mglProhibitAlphaFallback(GLboolean flag)
{
    MiniGLDispatch->mglProhibitAlphaFallback(flag);
}
#undef mglProhibitAlphaFallback
#define mglProhibitAlphaFallback MGLD_mglProhibitAlphaFallback

static __inline__ void MGLD_mglProhibitMipMapping(GLboolean flag)
{
    MiniGLDispatch->mglProhibitMipMapping(flag);
}
#undef mglProhibitMipMapping
#define mglProhibitMipMapping MGLD_mglProhibitMipMapping

static __inline__ GLint MGLD_mglGetSupportedScreenModes(MGLScreenModeCallback CallbackFn)
{
    return MiniGLDispatch->mglGetSupportedScreenModes(CallbackFn);
}
#undef mglGetSupportedScreenModes
#define mglGetSupportedScreenModes MGLD_mglGetSupportedScreenModes

static __inline__ void * MGLD_mglGetInputWindowHandle(void)
{
    return MiniGLDispatch->MGLGetInputWindowHandle(MGLD_CTX);
}
#undef mglGetInputWindowHandle
#define mglGetInputWindowHandle MGLD_mglGetInputWindowHandle

/* --- APPENDED 2026-09-08, matching the four new table entries --- */

static __inline__ void MGLD_glClientActiveTextureARB(GLenum unit)
{
    MiniGLDispatch->GLClientActiveTextureARB(MGLD_CTX, unit);
}
#undef glClientActiveTextureARB
#define glClientActiveTextureARB MGLD_glClientActiveTextureARB

static __inline__ void MGLD_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLInterleavedArrays(MGLD_CTX, format, stride, pointer);
}
#undef glInterleavedArrays
#define glInterleavedArrays MGLD_glInterleavedArrays

static __inline__ void MGLD_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
    MiniGLDispatch->GLMultiDrawArrays(MGLD_CTX, mode, first, count, primcount);
}
#undef glMultiDrawArrays
#define glMultiDrawArrays MGLD_glMultiDrawArrays

static __inline__ GLboolean MGLD_glIsTexture(GLuint texture)
{
    return MiniGLDispatch->GLIsTexture(MGLD_CTX, texture);
}
#undef glIsTexture
#define glIsTexture MGLD_glIsTexture

static __inline__ void MGLD_mglChooseZBufferDepth(int bits)
{
    MiniGLDispatch->mglChooseZBufferDepth(bits);
}
#undef mglChooseZBufferDepth
#define mglChooseZBufferDepth MGLD_mglChooseZBufferDepth

static __inline__ void MGLD_glBlendEquation(GLenum mode)
{
    MiniGLDispatch->GLBlendEquation(MGLD_CTX, mode);
}
#undef glBlendEquation
#define glBlendEquation MGLD_glBlendEquation

static __inline__ void MGLD_glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    MiniGLDispatch->GLBlendFuncSeparate(MGLD_CTX, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
#undef glBlendFuncSeparate
#define glBlendFuncSeparate MGLD_glBlendFuncSeparate

/* --- APPENDED 2026-09-12 (audit item 10), matching table entries 141 to 151 --- */

static __inline__ GLboolean MGLD_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences)
{
    return MiniGLDispatch->GLAreTexturesResident(MGLD_CTX, n, textures, residences);
}
#undef glAreTexturesResident
#define glAreTexturesResident MGLD_glAreTexturesResident

static __inline__ void MGLD_glEdgeFlag(GLboolean flag)
{
    MiniGLDispatch->GLEdgeFlag(MGLD_CTX, flag);
}
#undef glEdgeFlag
#define glEdgeFlag MGLD_glEdgeFlag

static __inline__ void MGLD_glEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLEdgeFlagPointer(MGLD_CTX, stride, pointer);
}
#undef glEdgeFlagPointer
#define glEdgeFlagPointer MGLD_glEdgeFlagPointer

static __inline__ void MGLD_glEdgeFlagv(const GLboolean *flag)
{
    MiniGLDispatch->GLEdgeFlagv(MGLD_CTX, flag);
}
#undef glEdgeFlagv
#define glEdgeFlagv MGLD_glEdgeFlagv

static __inline__ void MGLD_glGetDoublev(GLenum pname, GLdouble *params)
{
    MiniGLDispatch->GLGetDoublev(MGLD_CTX, pname, params);
}
#undef glGetDoublev
#define glGetDoublev MGLD_glGetDoublev

static __inline__ void MGLD_glGetPointerv(GLenum pname, GLvoid **params)
{
    MiniGLDispatch->GLGetPointerv(MGLD_CTX, pname, params);
}
#undef glGetPointerv
#define glGetPointerv MGLD_glGetPointerv

static __inline__ void MGLD_glIndexi(GLint c)
{
    MiniGLDispatch->GLIndexi(MGLD_CTX, c);
}
#undef glIndexi
#define glIndexi MGLD_glIndexi

static __inline__ void MGLD_glIndexiv(const GLint *c)
{
    MiniGLDispatch->GLIndexiv(MGLD_CTX, c);
}
#undef glIndexiv
#define glIndexiv MGLD_glIndexiv

static __inline__ void MGLD_glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    MiniGLDispatch->GLIndexPointer(MGLD_CTX, type, stride, pointer);
}
#undef glIndexPointer
#define glIndexPointer MGLD_glIndexPointer

static __inline__ void MGLD_glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
    MiniGLDispatch->GLPrioritizeTextures(MGLD_CTX, n, textures, priorities);
}
#undef glPrioritizeTextures
#define glPrioritizeTextures MGLD_glPrioritizeTextures

static __inline__ void MGLD_glReadBuffer(GLenum mode)
{
    MiniGLDispatch->GLReadBuffer(MGLD_CTX, mode);
}
#undef glReadBuffer
#define glReadBuffer MGLD_glReadBuffer


/* Client wrappers for the 47 entries appended for 28.0. Same shape as every
 * wrapper above: the context-taking ones inject MGLD_CTX, and the void ones that
 * DRAW are guarded on a current context the way gluPerspective is. The GLUT
 * lifecycle calls are deliberately NOT guarded -- glutInit runs before a context
 * exists, being what creates one. */

static __inline__ void MGLD_glLightf(GLenum light, GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLLightf(MGLD_CTX, light, pname, param);
}
#undef glLightf
#define glLightf MGLD_glLightf

static __inline__ void MGLD_glLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
    MiniGLDispatch->GLLightfv(MGLD_CTX, light, pname, params);
}
#undef glLightfv
#define glLightfv MGLD_glLightfv

static __inline__ void MGLD_glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLMaterialf(MGLD_CTX, face, pname, param);
}
#undef glMaterialf
#define glMaterialf MGLD_glMaterialf

static __inline__ void MGLD_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
    MiniGLDispatch->GLMaterialfv(MGLD_CTX, face, pname, params);
}
#undef glMaterialfv
#define glMaterialfv MGLD_glMaterialfv

static __inline__ void MGLD_glLightModelf(GLenum pname, GLfloat param)
{
    MiniGLDispatch->GLLightModelf(MGLD_CTX, pname, param);
}
#undef glLightModelf
#define glLightModelf MGLD_glLightModelf

static __inline__ void MGLD_glLightModelfv(GLenum pname, const GLfloat *params)
{
    MiniGLDispatch->GLLightModelfv(MGLD_CTX, pname, params);
}
#undef glLightModelfv
#define glLightModelfv MGLD_glLightModelfv

static __inline__ void MGLD_glGetLightfv(GLenum light, GLenum pname, GLfloat *params)
{
    MiniGLDispatch->GLGetLightfv(MGLD_CTX, light, pname, params);
}
#undef glGetLightfv
#define glGetLightfv MGLD_glGetLightfv

static __inline__ void MGLD_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params)
{
    MiniGLDispatch->GLGetMaterialfv(MGLD_CTX, face, pname, params);
}
#undef glGetMaterialfv
#define glGetMaterialfv MGLD_glGetMaterialfv

static __inline__ GLuint MGLD_glGenLists(GLsizei range)
{
    return MiniGLDispatch->GLGenLists(MGLD_CTX, range);
}
#undef glGenLists
#define glGenLists MGLD_glGenLists

static __inline__ void MGLD_glDeleteLists(GLuint list, GLsizei range)
{
    MiniGLDispatch->GLDeleteLists(MGLD_CTX, list, range);
}
#undef glDeleteLists
#define glDeleteLists MGLD_glDeleteLists

static __inline__ GLboolean MGLD_glIsList(GLuint list)
{
    return MiniGLDispatch->GLIsList(MGLD_CTX, list);
}
#undef glIsList
#define glIsList MGLD_glIsList

static __inline__ void MGLD_glNewList(GLuint list, GLenum mode)
{
    MiniGLDispatch->GLNewList(MGLD_CTX, list, mode);
}
#undef glNewList
#define glNewList MGLD_glNewList

static __inline__ void MGLD_glEndList(void)
{
    MiniGLDispatch->GLEndList(MGLD_CTX);
}
#undef glEndList
#define glEndList MGLD_glEndList

static __inline__ void MGLD_glCallList(GLuint list)
{
    MiniGLDispatch->GLCallList(MGLD_CTX, list);
}
#undef glCallList
#define glCallList MGLD_glCallList

static __inline__ GLint MGLD_gluBuild2DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data)
{
    return MiniGLDispatch->GLUBuild2DMipmaps(MGLD_CTX, target, internalFormat, width, height, format, type, data);
}
#undef gluBuild2DMipmaps
#define gluBuild2DMipmaps MGLD_gluBuild2DMipmaps

static __inline__ const GLubyte * MGLD_gluErrorString(GLenum errCode)
{
    return MiniGLDispatch->GLUErrorString(errCode);
}
#undef gluErrorString
#define gluErrorString MGLD_gluErrorString

static __inline__ GLUquadricObj * MGLD_gluNewQuadric(void)
{
    return MiniGLDispatch->GLUNewQuadric();
}
#undef gluNewQuadric
#define gluNewQuadric MGLD_gluNewQuadric

static __inline__ void MGLD_gluDeleteQuadric(GLUquadricObj *q)
{
    MiniGLDispatch->GLUDeleteQuadric(q);
}
#undef gluDeleteQuadric
#define gluDeleteQuadric MGLD_gluDeleteQuadric

static __inline__ void MGLD_gluQuadricNormals(GLUquadricObj *q, GLenum normals)
{
    MiniGLDispatch->GLUQuadricNormals(q, normals);
}
#undef gluQuadricNormals
#define gluQuadricNormals MGLD_gluQuadricNormals

static __inline__ void MGLD_gluQuadricTexture(GLUquadricObj *q, GLboolean textureCoords)
{
    MiniGLDispatch->GLUQuadricTexture(q, textureCoords);
}
#undef gluQuadricTexture
#define gluQuadricTexture MGLD_gluQuadricTexture

static __inline__ void MGLD_gluQuadricDrawStyle(GLUquadricObj *q, GLenum drawStyle)
{
    MiniGLDispatch->GLUQuadricDrawStyle(q, drawStyle);
}
#undef gluQuadricDrawStyle
#define gluQuadricDrawStyle MGLD_gluQuadricDrawStyle

static __inline__ void MGLD_gluQuadricOrientation(GLUquadricObj *q, GLenum orientation)
{
    MiniGLDispatch->GLUQuadricOrientation(q, orientation);
}
#undef gluQuadricOrientation
#define gluQuadricOrientation MGLD_gluQuadricOrientation

static __inline__ void MGLD_gluCylinder(GLUquadricObj *q, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUCylinder(q, base, top, height, slices, stacks);
}
#undef gluCylinder
#define gluCylinder MGLD_gluCylinder

static __inline__ void MGLD_gluSphere(GLUquadricObj *q, GLdouble radius, GLint slices, GLint stacks)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUSphere(q, radius, slices, stacks);
}
#undef gluSphere
#define gluSphere MGLD_gluSphere

static __inline__ void MGLD_gluDisk(GLUquadricObj *q, GLdouble inner, GLdouble outer, GLint slices, GLint loops)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUDisk(q, inner, outer, slices, loops);
}
#undef gluDisk
#define gluDisk MGLD_gluDisk

/*
 * glutInit is the ONE hand-written wrapper here, and the atexit call is why.
 *
 * GLUT applications end by calling exit() from a keyboard callback -- that is
 * normal GLUT style, not an edge case -- and exit() runs the atexit handlers of
 * whoever's CRT it belongs to. In the static-archive build that is the
 * application's, so the driver's own atexit(mglglut_Cleanup) inside GLUTInit
 * works. In a LIBRARY build it is not: minigl.library is linked -nostdlib and
 * has no CRT, so a handler registered inside it is registered with nothing that
 * will ever run, and the screen stays open when the application exits. That
 * costs a reboot.
 *
 * Registering HERE fixes it, because this wrapper is compiled into the
 * application, where atexit is the real one.
 *
 * The handler releases the DISPLAY and nothing more, using only entry points
 * that already exist -- deliberately, so that no non-GLUT function has to be
 * added to the ABI for it. MGLTerm and the timer device close are skipped: they
 * are not in the dispatch table, and the library owns its own teardown. The gap
 * that leaves is one timer.device open count at process exit, against a screen
 * that would otherwise never be released.
 *
 * Double teardown cannot happen. If the application exits, this runs and nulls
 * the context. If GLUTMainLoop returns instead, the driver's own cleanup runs
 * first (it is idempotent, guarded by g_cleanupDone) and nulls the context too,
 * so this handler finds NULL at process exit and does nothing.
 */
/*
 * glTexCoord2d has NO dispatch slot of its own and needs none -- it is the
 * double-precision spelling of glTexCoord2f, and <mgl/gl.h> provides it as a
 * macro onto that. But that macro lives inside the driver header's
 * #ifndef USE_MGLAPI block, which this header defines USE_MGLAPI to suppress, so
 * without an equivalent here a LIBRARY client simply loses the name. glxsglut's
 * scene08 uses it, and the failure is a compile error rather than anything subtle.
 *
 * Any other gl* name that exists only as a macro in the driver header, rather
 * than as an entry point, needs the same treatment.
 */
#define glTexCoord2d(s, t) MGLD_glTexCoord2f((GLfloat)(s), (GLfloat)(t))

/*
 * THE REMAINING GL 1.1 SPELLINGS of glTexCoord and glVertex. GL names every
 * combination of 1-4 components and d/f/i/s, each with a vector form; this
 * header carried five and seven of them, so a program written against standard
 * GL headers failed to compile rather than failing at run time.
 *
 * Pure aliases onto entry points that already exist, which is why they need no
 * dispatch slot: 1-component texcoords default t to 0, 3-component ones pass r
 * and the driver drops it, 2-component vertices go to the 2f entry point and
 * 3-component ones default w to 1. Vector forms expand elementwise, there being
 * no GL*4dv entry point to call.
 *
 * Generated rather than typed, and every one of them is called once by
 * D:\tmp\alias_probe\probe_spellings.c on both linkages -- 44 macros here and
 * 44 more in <libraries/minigl_dispatch.h> cannot be checked by eye.
 */
#define glTexCoord1d(s) MGLD_glTexCoord2f((GLfloat)(s), 0.f)
#define glTexCoord1dv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], 0.f)
#define glTexCoord1f(s) MGLD_glTexCoord2f((GLfloat)(s), 0.f)
#define glTexCoord1fv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], 0.f)
#define glTexCoord1i(s) MGLD_glTexCoord2f((GLfloat)(s), 0.f)
#define glTexCoord1iv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], 0.f)
#define glTexCoord1s(s) MGLD_glTexCoord2f((GLfloat)(s), 0.f)
#define glTexCoord1sv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], 0.f)
#define glTexCoord2dv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glTexCoord2i(s, t) MGLD_glTexCoord2f((GLfloat)(s), (GLfloat)(t))
#define glTexCoord2iv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glTexCoord2s(s, t) MGLD_glTexCoord2f((GLfloat)(s), (GLfloat)(t))
#define glTexCoord2sv(v) MGLD_glTexCoord2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glTexCoord3d(s, t, r) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), 1.f)
#define glTexCoord3dv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glTexCoord3f(s, t, r) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), 1.f)
#define glTexCoord3fv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glTexCoord3i(s, t, r) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), 1.f)
#define glTexCoord3iv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glTexCoord3s(s, t, r) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), 1.f)
#define glTexCoord3sv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glTexCoord4d(s, t, r, q) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), (GLfloat)(q))
#define glTexCoord4dv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])
#define glTexCoord4i(s, t, r, q) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), (GLfloat)(q))
#define glTexCoord4iv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])
#define glTexCoord4s(s, t, r, q) MGLD_glTexCoord4f((GLfloat)(s), (GLfloat)(t), (GLfloat)(r), (GLfloat)(q))
#define glTexCoord4sv(v) MGLD_glTexCoord4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])

#define glVertex2d(x, y) MGLD_glVertex2f((GLfloat)(x), (GLfloat)(y))
#define glVertex2dv(v) MGLD_glVertex2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glVertex2iv(v) MGLD_glVertex2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glVertex2s(x, y) MGLD_glVertex2f((GLfloat)(x), (GLfloat)(y))
#define glVertex2sv(v) MGLD_glVertex2f((GLfloat)(v)[0], (GLfloat)(v)[1])
#define glVertex3d(x, y, z) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), 1.f)
#define glVertex3dv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glVertex3i(x, y, z) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), 1.f)
#define glVertex3iv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glVertex3s(x, y, z) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), 1.f)
#define glVertex3sv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], 1.f)
#define glVertex4d(x, y, z, w) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), (GLfloat)(w))
#define glVertex4dv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])
#define glVertex4i(x, y, z, w) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), (GLfloat)(w))
#define glVertex4iv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])
#define glVertex4s(x, y, z, w) MGLD_glVertex4f((GLfloat)(x), (GLfloat)(y), (GLfloat)(z), (GLfloat)(w))
#define glVertex4sv(v) MGLD_glVertex4f((GLfloat)(v)[0], (GLfloat)(v)[1], (GLfloat)(v)[2], (GLfloat)(v)[3])

/* The EXT spellings of the compiled-vertex-array lock. Same wrappers. */
#define glLockArraysEXT(f, c) MGLD_glLockArrays(f, c)
#define glUnlockArraysEXT()   MGLD_glUnlockArrays()

/*
 * Three more of exactly that kind, added with the unsuffixed multitexture
 * tokens GL_TEXTURE0..3. The tokens themselves come from <mgl/gl.h> and are
 * not suppressed -- only its gl* macro block is -- so they need nothing here.
 *
 * glActiveTexture and glClientActiveTexture are the names multitexture took
 * core in GL 1.3; the driver has one entry point per pair, so these are
 * aliases and not new slots.
 */
#define glActiveTexture(unit)       MGLD_glActiveTextureARB(unit)
#define glClientActiveTexture(unit) MGLD_glClientActiveTextureARB(unit)

/* Declared rather than pulled from <stdlib.h>: this header is included by every
 * client TU and should not drag a CRT header in behind it. The whole block is
 * inside #ifndef MINIGL_LIBRARY_BUILD, so the library's own -nostdlib build never
 * sees this and never needs an atexit at all. */
extern int atexit(void (*func)(void));

static void MGLD_glut_release_display(void)
{
    if (MiniGLDispatch && MiniGLDispatch->currentContext && MGLD_CTX)
    {
        MiniGLDispatch->MGLDeleteContext(MGLD_CTX);
        /* MGLDeleteContext takes the context as a parameter and never touches
         * the global, and every gl* macro below dereferences that global. */
        MGLD_CTX = 0;
    }
}

static __inline__ void MGLD_glutInit(int *argcp, char **argv)
{
    atexit(MGLD_glut_release_display);
    MiniGLDispatch->GLUTInit(argcp, argv);
}
#undef glutInit
#define glutInit MGLD_glutInit

static __inline__ void MGLD_glutInitDisplayMode(unsigned int mode)
{
    MiniGLDispatch->GLUTInitDisplayMode(mode);
}
#undef glutInitDisplayMode
#define glutInitDisplayMode MGLD_glutInitDisplayMode

static __inline__ void MGLD_glutInitWindowSize(int width, int height)
{
    MiniGLDispatch->GLUTInitWindowSize(width, height);
}
#undef glutInitWindowSize
#define glutInitWindowSize MGLD_glutInitWindowSize

static __inline__ void MGLD_glutInitWindowPosition(int x, int y)
{
    MiniGLDispatch->GLUTInitWindowPosition(x, y);
}
#undef glutInitWindowPosition
#define glutInitWindowPosition MGLD_glutInitWindowPosition

static __inline__ int MGLD_glutCreateWindow(const char *title)
{
    return MiniGLDispatch->GLUTCreateWindow(title);
}
#undef glutCreateWindow
#define glutCreateWindow MGLD_glutCreateWindow

static __inline__ void MGLD_glutMainLoop(void)
{
    MiniGLDispatch->GLUTMainLoop();
}
#undef glutMainLoop
#define glutMainLoop MGLD_glutMainLoop

/* freeglut's name for leaving the main loop, which GLUT 3.7 had no way to do.
 * GLUTMainLoop ends when the context's Running flag clears and MGLExit clears
 * it, so this is the existing mechanism under the name a freeglut program
 * expects -- no dispatch slot of its own. MGLD_mglExit is defined above. */
#undef glutLeaveMainLoop
#define glutLeaveMainLoop() MGLD_mglExit()

static __inline__ void MGLD_glutDisplayFunc(void (*func)(void))
{
    MiniGLDispatch->GLUTDisplayFunc(func);
}
#undef glutDisplayFunc
#define glutDisplayFunc MGLD_glutDisplayFunc

static __inline__ void MGLD_glutIdleFunc(void (*func)(void))
{
    MiniGLDispatch->GLUTIdleFunc(func);
}
#undef glutIdleFunc
#define glutIdleFunc MGLD_glutIdleFunc

static __inline__ void MGLD_glutKeyboardFunc(void (*func)(unsigned char key, int x, int y))
{
    MiniGLDispatch->GLUTKeyboardFunc(func);
}
#undef glutKeyboardFunc
#define glutKeyboardFunc MGLD_glutKeyboardFunc

static __inline__ void MGLD_glutReshapeFunc(void (*func)(int width, int height))
{
    MiniGLDispatch->GLUTReshapeFunc(func);
}
#undef glutReshapeFunc
#define glutReshapeFunc MGLD_glutReshapeFunc

static __inline__ void MGLD_glutSwapBuffers(void)
{
    MiniGLDispatch->GLUTSwapBuffers();
}
#undef glutSwapBuffers
#define glutSwapBuffers MGLD_glutSwapBuffers

static __inline__ void MGLD_glutPostRedisplay(void)
{
    MiniGLDispatch->GLUTPostRedisplay();
}
#undef glutPostRedisplay
#define glutPostRedisplay MGLD_glutPostRedisplay

static __inline__ int MGLD_glutGet(GLenum state)
{
    return MiniGLDispatch->GLUTGet(state);
}
#undef glutGet
#define glutGet MGLD_glutGet

static __inline__ void MGLD_glutGameModeString(const char *string)
{
    MiniGLDispatch->GLUTGameModeString(string);
}
#undef glutGameModeString
#define glutGameModeString MGLD_glutGameModeString

static __inline__ int MGLD_glutEnterGameMode(void)
{
    return MiniGLDispatch->GLUTEnterGameMode();
}
#undef glutEnterGameMode
#define glutEnterGameMode MGLD_glutEnterGameMode

static __inline__ void MGLD_glutLeaveGameMode(void)
{
    MiniGLDispatch->GLUTLeaveGameMode();
}
#undef glutLeaveGameMode
#define glutLeaveGameMode MGLD_glutLeaveGameMode

static __inline__ int MGLD_glutGameModeGet(GLenum query)
{
    return MiniGLDispatch->GLUTGameModeGet(query);
}
#undef glutGameModeGet
#define glutGameModeGet MGLD_glutGameModeGet

static __inline__ void MGLD_glutSolidCube(GLdouble size)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUTSolidCube(size);
}
#undef glutSolidCube
#define glutSolidCube MGLD_glutSolidCube

static __inline__ void MGLD_glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUTSolidSphere(radius, slices, stacks);
}
#undef glutSolidSphere
#define glutSolidSphere MGLD_glutSolidSphere

static __inline__ void MGLD_glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUTSolidCone(base, height, slices, stacks);
}
#undef glutSolidCone
#define glutSolidCone MGLD_glutSolidCone

static __inline__ void MGLD_glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUTSolidTorus(innerRadius, outerRadius, sides, rings);
}
#undef glutSolidTorus
#define glutSolidTorus MGLD_glutSolidTorus

static __inline__ void MGLD_glutSolidDodecahedron(void)
{
    if ((*MiniGLDispatch->currentContext)) MiniGLDispatch->GLUTSolidDodecahedron();
}
#undef glutSolidDodecahedron
#define glutSolidDodecahedron MGLD_glutSolidDodecahedron
#endif /* !MINIGL_LIBRARY_BUILD */

#ifdef __cplusplus
}
#endif

#endif
