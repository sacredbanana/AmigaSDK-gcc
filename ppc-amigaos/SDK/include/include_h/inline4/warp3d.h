#ifndef INLINE4_WARP3D_H
#define INLINE4_WARP3D_H

/*
** This file was auto generated by idltool 53.1.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef WARP3D_WARP3D_H
#include <Warp3D/Warp3D.h>
#endif
#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif
#include <interfaces/warp3d.h>

/* Inline macros for Interface "main" */
#define W3D_CreateContext(error, CCTags) IWarp3D->W3D_CreateContext((error), (CCTags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define W3D_CreateContextTags(...) IWarp3D->W3D_CreateContextTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define W3D_CreateContextTags(vargs...) IWarp3D->W3D_CreateContextTags(## vargs) 
#endif
#define W3D_DestroyContext(context) IWarp3D->W3D_DestroyContext((context)) 
#define W3D_GetState(context, state) IWarp3D->W3D_GetState((context), (state)) 
#define W3D_SetState(context, state, action) IWarp3D->W3D_SetState((context), (state), (action)) 
#define W3D_CheckDriver() IWarp3D->W3D_CheckDriver() 
#define W3D_LockHardware(context) IWarp3D->W3D_LockHardware((context)) 
#define W3D_UnLockHardware(context) IWarp3D->W3D_UnLockHardware((context)) 
#define W3D_WaitIdle(context) IWarp3D->W3D_WaitIdle((context)) 
#define W3D_CheckIdle(context) IWarp3D->W3D_CheckIdle((context)) 
#define W3D_Query(context, query, destfmt) IWarp3D->W3D_Query((context), (query), (destfmt)) 
#define W3D_GetTexFmtInfo(context, format, destfmt) IWarp3D->W3D_GetTexFmtInfo((context), (format), (destfmt)) 
#define W3D_AllocTexObj(context, error, ATOTags) IWarp3D->W3D_AllocTexObj((context), (error), (ATOTags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define W3D_AllocTexObjTags(context, ...) IWarp3D->W3D_AllocTexObjTags((context), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define W3D_AllocTexObjTags(context, vargs...) IWarp3D->W3D_AllocTexObjTags(context, ## vargs) 
#endif
#define W3D_FreeTexObj(context, texture) IWarp3D->W3D_FreeTexObj((context), (texture)) 
#define W3D_ReleaseTexture(context, texture) IWarp3D->W3D_ReleaseTexture((context), (texture)) 
#define W3D_FlushTextures(context) IWarp3D->W3D_FlushTextures((context)) 
#define W3D_SetFilter(context, texture, min, mag) IWarp3D->W3D_SetFilter((context), (texture), (min), (mag)) 
#define W3D_SetTexEnv(context, texture, envparam, envcolor) IWarp3D->W3D_SetTexEnv((context), (texture), (envparam), (envcolor)) 
#define W3D_SetWrapMode(context, texture, mode_s, mode_t, bordercolor) IWarp3D->W3D_SetWrapMode((context), (texture), (mode_s), (mode_t), (bordercolor)) 
#define W3D_UpdateTexImage(context, texture, teximage, level, palette) IWarp3D->W3D_UpdateTexImage((context), (texture), (teximage), (level), (palette)) 
#define W3D_UploadTexture(context, texture) IWarp3D->W3D_UploadTexture((context), (texture)) 
#define W3D_DrawLine(context, line) IWarp3D->W3D_DrawLine((context), (line)) 
#define W3D_DrawPoint(context, point) IWarp3D->W3D_DrawPoint((context), (point)) 
#define W3D_DrawTriangle(context, triangle) IWarp3D->W3D_DrawTriangle((context), (triangle)) 
#define W3D_DrawTriFan(context, triangles) IWarp3D->W3D_DrawTriFan((context), (triangles)) 
#define W3D_DrawTriStrip(context, triangles) IWarp3D->W3D_DrawTriStrip((context), (triangles)) 
#define W3D_SetAlphaMode(context, mode, refval) IWarp3D->W3D_SetAlphaMode((context), (mode), (refval)) 
#define W3D_SetBlendMode(context, srcfunc, dstfunc) IWarp3D->W3D_SetBlendMode((context), (srcfunc), (dstfunc)) 
#define W3D_SetDrawRegion(context, bm, yoffset, scissor) IWarp3D->W3D_SetDrawRegion((context), (bm), (yoffset), (scissor)) 
#define W3D_SetFogParams(context, fogparams, fogmode) IWarp3D->W3D_SetFogParams((context), (fogparams), (fogmode)) 
#define W3D_SetColorMask(context, red, green, blue, alpha) IWarp3D->W3D_SetColorMask((context), (red), (green), (blue), (alpha)) 
#define W3D_SetStencilFunc(context, func, refvalue, mask) IWarp3D->W3D_SetStencilFunc((context), (func), (refvalue), (mask)) 
#define W3D_AllocZBuffer(context) IWarp3D->W3D_AllocZBuffer((context)) 
#define W3D_FreeZBuffer(context) IWarp3D->W3D_FreeZBuffer((context)) 
#define W3D_ClearZBuffer(context, clearvalue) IWarp3D->W3D_ClearZBuffer((context), (clearvalue)) 
#define W3D_ReadZPixel(context, x, y, z) IWarp3D->W3D_ReadZPixel((context), (x), (y), (z)) 
#define W3D_ReadZSpan(context, x, y, n, z) IWarp3D->W3D_ReadZSpan((context), (x), (y), (n), (z)) 
#define W3D_SetZCompareMode(context, mode) IWarp3D->W3D_SetZCompareMode((context), (mode)) 
#define W3D_AllocStencilBuffer(context) IWarp3D->W3D_AllocStencilBuffer((context)) 
#define W3D_ClearStencilBuffer(context, clearval) IWarp3D->W3D_ClearStencilBuffer((context), (clearval)) 
#define W3D_FillStencilBuffer(context, x, y, width, height, depth, data) IWarp3D->W3D_FillStencilBuffer((context), (x), (y), (width), (height), (depth), (data)) 
#define W3D_FreeStencilBuffer(context) IWarp3D->W3D_FreeStencilBuffer((context)) 
#define W3D_ReadStencilPixel(context, x, y, st) IWarp3D->W3D_ReadStencilPixel((context), (x), (y), (st)) 
#define W3D_ReadStencilSpan(context, x, y, n, st) IWarp3D->W3D_ReadStencilSpan((context), (x), (y), (n), (st)) 
#define W3D_SetLogicOp(context, operation) IWarp3D->W3D_SetLogicOp((context), (operation)) 
#define W3D_Hint(context, mode, quality) IWarp3D->W3D_Hint((context), (mode), (quality)) 
#define W3D_SetDrawRegionWBM(context, bitmap, scissor) IWarp3D->W3D_SetDrawRegionWBM((context), (bitmap), (scissor)) 
#define W3D_GetDriverState(context) IWarp3D->W3D_GetDriverState((context)) 
#define W3D_Flush(context) IWarp3D->W3D_Flush((context)) 
#define W3D_SetPenMask(context, pen) IWarp3D->W3D_SetPenMask((context), (pen)) 
#define W3D_SetStencilOp(context, sfail, dpfail, dppass) IWarp3D->W3D_SetStencilOp((context), (sfail), (dpfail), (dppass)) 
#define W3D_SetWriteMask(context, mask) IWarp3D->W3D_SetWriteMask((context), (mask)) 
#define W3D_WriteStencilPixel(context, x, y, st) IWarp3D->W3D_WriteStencilPixel((context), (x), (y), (st)) 
#define W3D_WriteStencilSpan(context, x, y, n, st, mask) IWarp3D->W3D_WriteStencilSpan((context), (x), (y), (n), (st), (mask)) 
#define W3D_WriteZPixel(context, x, y, z) IWarp3D->W3D_WriteZPixel((context), (x), (y), (z)) 
#define W3D_WriteZSpan(context, x, y, n, z, maks) IWarp3D->W3D_WriteZSpan((context), (x), (y), (n), (z), (maks)) 
#define W3D_SetCurrentColor(context, color) IWarp3D->W3D_SetCurrentColor((context), (color)) 
#define W3D_SetCurrentPen(context, pen) IWarp3D->W3D_SetCurrentPen((context), (pen)) 
#define W3D_UpdateTexSubImage(context, texture, teximage, lev, palette, scissor, srcbpr) IWarp3D->W3D_UpdateTexSubImage((context), (texture), (teximage), (lev), (palette), (scissor), (srcbpr)) 
#define W3D_FreeAllTexObj(context) IWarp3D->W3D_FreeAllTexObj((context)) 
#define W3D_GetDestFmt() IWarp3D->W3D_GetDestFmt() 
#define W3D_DrawLineStrip(context, lines) IWarp3D->W3D_DrawLineStrip((context), (lines)) 
#define W3D_DrawLineLoop(context, lines) IWarp3D->W3D_DrawLineLoop((context), (lines)) 
#define W3D_GetDrivers() IWarp3D->W3D_GetDrivers() 
#define W3D_QueryDriver(driver, query, destfmt) IWarp3D->W3D_QueryDriver((driver), (query), (destfmt)) 
#define W3D_GetDriverTexFmtInfo(driver, format, destfmt) IWarp3D->W3D_GetDriverTexFmtInfo((driver), (format), (destfmt)) 
#define W3D_RequestMode(taglist) IWarp3D->W3D_RequestMode((taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define W3D_RequestModeTags(...) IWarp3D->W3D_RequestModeTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define W3D_RequestModeTags(...) IWarp3D->W3D_RequestModeTags(## vargs) 
#endif
#define W3D_SetScissor(context, scissor) IWarp3D->W3D_SetScissor((context), (scissor)) 
#define W3D_FlushFrame(context) IWarp3D->W3D_FlushFrame((context)) 
#define W3D_TestMode(ModeID) IWarp3D->W3D_TestMode((ModeID)) 
#define W3D_SetChromaTestBounds(context, texture, rgba_lower, rgba_upper, mode) IWarp3D->W3D_SetChromaTestBounds((context), (texture), (rgba_lower), (rgba_upper), (mode)) 
#define W3D_ClearDrawRegion(context, color) IWarp3D->W3D_ClearDrawRegion((context), (color)) 
#define W3D_DrawTriangleV(context, triangle) IWarp3D->W3D_DrawTriangleV((context), (triangle)) 
#define W3D_DrawTriFanV(context, triangles) IWarp3D->W3D_DrawTriFanV((context), (triangles)) 
#define W3D_DrawTriStripV(context, triangles) IWarp3D->W3D_DrawTriStripV((context), (triangles)) 
#define W3D_GetScreenmodeList() IWarp3D->W3D_GetScreenmodeList() 
#define W3D_FreeScreenmodeList(list) IWarp3D->W3D_FreeScreenmodeList((list)) 
#define W3D_BestModeID(tags) IWarp3D->W3D_BestModeID((tags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define W3D_BestModeIDTags(...) IWarp3D->W3D_BestModeIDTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define W3D_BestModeIDTags(...) IWarp3D->W3D_BestModeIDTags(## vargs) 
#endif
#define W3D_VertexPointer(context, pointer, stride, mode, flags) IWarp3D->W3D_VertexPointer((context), (pointer), (stride), (mode), (flags)) 
#define W3D_TexCoordPointer(context, pointer, stride, unit, off_v, off_w, flags) IWarp3D->W3D_TexCoordPointer((context), (pointer), (stride), (unit), (off_v), (off_w), (flags)) 
#define W3D_ColorPointer(context, pointer, stride, format, mode, flags) IWarp3D->W3D_ColorPointer((context), (pointer), (stride), (format), (mode), (flags)) 
#define W3D_BindTexture(context, tmu, texture) IWarp3D->W3D_BindTexture((context), (tmu), (texture)) 
#define W3D_DrawArray(context, primitive, base, count) IWarp3D->W3D_DrawArray((context), (primitive), (base), (count)) 
#define W3D_DrawElements(context, primitive, type, count, indices) IWarp3D->W3D_DrawElements((context), (primitive), (type), (count), (indices)) 
#define W3D_SetFrontFace(context, direction) IWarp3D->W3D_SetFrontFace((context), (direction)) 
#define W3D_SetTextureBlend(context, tagList) IWarp3D->W3D_SetTextureBlend((context), (tagList)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define W3D_SetTextureBlendTags(...) IWarp3D->W3D_SetTextureBlendTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define W3D_SetTextureBlendTags(vargs...) IWarp3D->W3D_SetTextureBlendTags(## vargs) 
#endif
#define W3D_SecondaryColorPointer(context, pointer, stride, format, mode, flags) IWarp3D->W3D_SecondaryColorPointer((context), (pointer), (stride), (format), (mode), (flags)) 
#define W3D_FogCoordPointer(context, pointer, stride, mode, flags) IWarp3D->W3D_FogCoordPointer((context), (pointer), (stride), (mode), (flags)) 
#define W3D_InterleavedArray(context, pointer, stride, format, flags) IWarp3D->W3D_InterleavedArray((context), (pointer), (stride), (format), (flags)) 
#define W3D_ClearBuffers(context, color, depth, stencil) IWarp3D->W3D_ClearBuffers((context), (color), (depth), (stencil)) 
#define W3D_SetParameter(context, target, pattern) IWarp3D->W3D_SetParameter((context), (target), (pattern)) 
#define W3D_SetMaxAnisotropy(context, texture, level) IWarp3D->W3D_SetMaxAnisotropy((context), (texture), (level)) 

#endif /* INLINE4_WARP3D_H */
