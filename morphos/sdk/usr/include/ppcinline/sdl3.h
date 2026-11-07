/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SDL3_H
#define _PPCINLINE_SDL3_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SDL3_BASE_NAME
#define SDL3_BASE_NAME SDL3Base
#endif /* !SDL3_BASE_NAME */

#ifndef SDL_InitTGL
#define SDL_InitTGL(__p0, __p1, __p2) \
	(((void (*)(void *, void **, struct Library **, unsigned int (*)(struct Library *TinyGLBase)))*(void**)((long)(SDL3_BASE_NAME) - 28))((void*)(SDL3_BASE_NAME), __p0, __p1, __p2))
#endif

#ifndef SDL_SetExitPointer
#define SDL_SetExitPointer(__p0) \
	(((void (*)(void *, void (*)(int)))*(void**)((long)(SDL3_BASE_NAME) - 34))((void*)(SDL3_BASE_NAME), __p0))
#endif

#ifndef SDL_AcquireCameraFrame
#define SDL_AcquireCameraFrame(__p0, __p1) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		Uint64 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Camera *, Uint64 *))*(void**)(__base - 64))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_AcquireGPUCommandBuffer
#define SDL_AcquireGPUCommandBuffer(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUCommandBuffer *(*)(SDL_GPUDevice *))*(void**)(__base - 70))(__t__p0));\
	})
#endif

#ifndef SDL_AcquireGPUSwapchainTexture
#define SDL_AcquireGPUSwapchainTexture(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		SDL_GPUTexture ** __t__p2 = __p2;\
		Uint32 * __t__p3 = __p3;\
		Uint32 * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUCommandBuffer *, SDL_Window *, SDL_GPUTexture **, Uint32 *, Uint32 *))*(void**)(__base - 76))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_AddAtomicInt
#define SDL_AddAtomicInt(__p0, __p1) \
	({ \
		SDL_AtomicInt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AtomicInt *, int ))*(void**)(__base - 82))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_AddEventWatch
#define SDL_AddEventWatch(__p0, __p1) \
	({ \
		SDL_EventFilter  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_EventFilter , void *))*(void**)(__base - 88))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_AddGamepadMapping
#define SDL_AddGamepadMapping(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 94))(__t__p0));\
	})
#endif

#ifndef SDL_AddGamepadMappingsFromFile
#define SDL_AddGamepadMappingsFromFile(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 100))(__t__p0));\
	})
#endif

#ifndef SDL_AddGamepadMappingsFromIO
#define SDL_AddGamepadMappingsFromIO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_IOStream *, bool ))*(void**)(__base - 106))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_AddHintCallback
#define SDL_AddHintCallback(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_HintCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, SDL_HintCallback , void *))*(void**)(__base - 112))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_AddSurfaceAlternateImage
#define SDL_AddSurfaceAlternateImage(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_Surface *))*(void**)(__base - 118))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_AddTimer
#define SDL_AddTimer(__p0, __p1, __p2) \
	({ \
		Uint32  __t__p0 = __p0;\
		SDL_TimerCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TimerID (*)(Uint32 , SDL_TimerCallback , void *))*(void**)(__base - 124))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_AddTimerNS
#define SDL_AddTimerNS(__p0, __p1, __p2) \
	({ \
		Uint64  __t__p0 = __p0;\
		SDL_NSTimerCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TimerID (*)(Uint64 , SDL_NSTimerCallback , void *))*(void**)(__base - 130))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_AddVulkanRenderSemaphores
#define SDL_AddVulkanRenderSemaphores(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Sint64  __t__p2 = __p2;\
		Sint64  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, Uint32 , Sint64 , Sint64 ))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_AttachVirtualJoystick
#define SDL_AttachVirtualJoystick(__p0) \
	({ \
		const SDL_VirtualJoystickDesc * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickID (*)(const SDL_VirtualJoystickDesc *))*(void**)(__base - 142))(__t__p0));\
	})
#endif

#ifndef SDL_AudioDevicePaused
#define SDL_AudioDevicePaused(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID ))*(void**)(__base - 148))(__t__p0));\
	})
#endif

#ifndef SDL_BeginGPUComputePass
#define SDL_BeginGPUComputePass(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		const SDL_GPUStorageTextureReadWriteBinding * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		const SDL_GPUStorageBufferReadWriteBinding * __t__p3 = __p3;\
		Uint32  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUComputePass *(*)(SDL_GPUCommandBuffer *, const SDL_GPUStorageTextureReadWriteBinding *, Uint32 , const SDL_GPUStorageBufferReadWriteBinding *, Uint32 ))*(void**)(__base - 154))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_BeginGPUCopyPass
#define SDL_BeginGPUCopyPass(__p0) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUCopyPass *(*)(SDL_GPUCommandBuffer *))*(void**)(__base - 160))(__t__p0));\
	})
#endif

#ifndef SDL_BeginGPURenderPass
#define SDL_BeginGPURenderPass(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		const SDL_GPUColorTargetInfo * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		const SDL_GPUDepthStencilTargetInfo * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPURenderPass *(*)(SDL_GPUCommandBuffer *, const SDL_GPUColorTargetInfo *, Uint32 , const SDL_GPUDepthStencilTargetInfo *))*(void**)(__base - 166))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindAudioStream
#define SDL_BindAudioStream(__p0, __p1) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		SDL_AudioStream * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID , SDL_AudioStream *))*(void**)(__base - 172))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_BindAudioStreams
#define SDL_BindAudioStreams(__p0, __p1, __p2) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		SDL_AudioStream *const * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID , SDL_AudioStream *const *, int ))*(void**)(__base - 178))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_BindGPUComputePipeline
#define SDL_BindGPUComputePipeline(__p0, __p1) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		SDL_GPUComputePipeline * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, SDL_GPUComputePipeline *))*(void**)(__base - 184))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_BindGPUComputeSamplers
#define SDL_BindGPUComputeSamplers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const SDL_GPUTextureSamplerBinding * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, Uint32 , const SDL_GPUTextureSamplerBinding *, Uint32 ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUComputeStorageBuffers
#define SDL_BindGPUComputeStorageBuffers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUBuffer *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, Uint32 , SDL_GPUBuffer *const *, Uint32 ))*(void**)(__base - 196))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUComputeStorageTextures
#define SDL_BindGPUComputeStorageTextures(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUTexture *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, Uint32 , SDL_GPUTexture *const *, Uint32 ))*(void**)(__base - 202))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUFragmentSamplers
#define SDL_BindGPUFragmentSamplers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const SDL_GPUTextureSamplerBinding * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , const SDL_GPUTextureSamplerBinding *, Uint32 ))*(void**)(__base - 208))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUFragmentStorageBuffers
#define SDL_BindGPUFragmentStorageBuffers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUBuffer *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , SDL_GPUBuffer *const *, Uint32 ))*(void**)(__base - 214))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUFragmentStorageTextures
#define SDL_BindGPUFragmentStorageTextures(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUTexture *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , SDL_GPUTexture *const *, Uint32 ))*(void**)(__base - 220))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUGraphicsPipeline
#define SDL_BindGPUGraphicsPipeline(__p0, __p1) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		SDL_GPUGraphicsPipeline * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, SDL_GPUGraphicsPipeline *))*(void**)(__base - 226))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_BindGPUIndexBuffer
#define SDL_BindGPUIndexBuffer(__p0, __p1, __p2) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		const SDL_GPUBufferBinding * __t__p1 = __p1;\
		SDL_GPUIndexElementSize  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, const SDL_GPUBufferBinding *, SDL_GPUIndexElementSize ))*(void**)(__base - 232))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_BindGPUVertexBuffers
#define SDL_BindGPUVertexBuffers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const SDL_GPUBufferBinding * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , const SDL_GPUBufferBinding *, Uint32 ))*(void**)(__base - 238))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUVertexSamplers
#define SDL_BindGPUVertexSamplers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const SDL_GPUTextureSamplerBinding * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , const SDL_GPUTextureSamplerBinding *, Uint32 ))*(void**)(__base - 244))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUVertexStorageBuffers
#define SDL_BindGPUVertexStorageBuffers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUBuffer *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , SDL_GPUBuffer *const *, Uint32 ))*(void**)(__base - 250))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BindGPUVertexStorageTextures
#define SDL_BindGPUVertexStorageTextures(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_GPUTexture *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , SDL_GPUTexture *const *, Uint32 ))*(void**)(__base - 256))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BlitGPUTexture
#define SDL_BlitGPUTexture(__p0, __p1) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		const SDL_GPUBlitInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, const SDL_GPUBlitInfo *))*(void**)(__base - 262))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_BlitSurface
#define SDL_BlitSurface(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *))*(void**)(__base - 268))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BlitSurface9Grid
#define SDL_BlitSurface9Grid(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		float  __t__p6 = __p6;\
		SDL_ScaleMode  __t__p7 = __p7;\
		SDL_Surface * __t__p8 = __p8;\
		const SDL_Rect * __t__p9 = __p9;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, int , int , int , int , float , SDL_ScaleMode , SDL_Surface *, const SDL_Rect *))*(void**)(__base - 274))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})
#endif

#ifndef SDL_BlitSurfaceScaled
#define SDL_BlitSurfaceScaled(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		SDL_ScaleMode  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *, SDL_ScaleMode ))*(void**)(__base - 280))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_BlitSurfaceTiled
#define SDL_BlitSurfaceTiled(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BlitSurfaceTiledWithScale
#define SDL_BlitSurfaceTiledWithScale(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		SDL_ScaleMode  __t__p3 = __p3;\
		SDL_Surface * __t__p4 = __p4;\
		const SDL_Rect * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, float , SDL_ScaleMode , SDL_Surface *, const SDL_Rect *))*(void**)(__base - 292))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_BlitSurfaceUnchecked
#define SDL_BlitSurfaceUnchecked(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *))*(void**)(__base - 298))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_BlitSurfaceUncheckedScaled
#define SDL_BlitSurfaceUncheckedScaled(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		SDL_ScaleMode  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *, SDL_ScaleMode ))*(void**)(__base - 304))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_BroadcastCondition
#define SDL_BroadcastCondition(__p0) \
	({ \
		SDL_Condition * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Condition *))*(void**)(__base - 310))(__t__p0));\
	})
#endif

#ifndef SDL_CaptureMouse
#define SDL_CaptureMouse(__p0) \
	({ \
		bool  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(bool ))*(void**)(__base - 316))(__t__p0));\
	})
#endif

#ifndef SDL_ClaimWindowForGPUDevice
#define SDL_ClaimWindowForGPUDevice(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_Window *))*(void**)(__base - 322))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CleanupTLS
#define SDL_CleanupTLS() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 328))());\
	})
#endif

#ifndef SDL_ClearAudioStream
#define SDL_ClearAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 334))(__t__p0));\
	})
#endif

#ifndef SDL_ClearClipboardData
#define SDL_ClearClipboardData() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 340))());\
	})
#endif

#ifndef SDL_ClearComposition
#define SDL_ClearComposition(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 346))(__t__p0));\
	})
#endif

#ifndef SDL_ClearError
#define SDL_ClearError() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 352))());\
	})
#endif

#ifndef SDL_ClearProperty
#define SDL_ClearProperty(__p0, __p1) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ClearSurface
#define SDL_ClearSurface(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, float , float , float , float ))*(void**)(__base - 364))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CloseAudioDevice
#define SDL_CloseAudioDevice(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AudioDeviceID ))*(void**)(__base - 370))(__t__p0));\
	})
#endif

#ifndef SDL_CloseCamera
#define SDL_CloseCamera(__p0) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Camera *))*(void**)(__base - 376))(__t__p0));\
	})
#endif

#ifndef SDL_CloseGamepad
#define SDL_CloseGamepad(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Gamepad *))*(void**)(__base - 382))(__t__p0));\
	})
#endif

#ifndef SDL_CloseHaptic
#define SDL_CloseHaptic(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Haptic *))*(void**)(__base - 388))(__t__p0));\
	})
#endif

#ifndef SDL_CloseIO
#define SDL_CloseIO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 394))(__t__p0));\
	})
#endif

#ifndef SDL_CloseJoystick
#define SDL_CloseJoystick(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Joystick *))*(void**)(__base - 400))(__t__p0));\
	})
#endif

#ifndef SDL_CloseSensor
#define SDL_CloseSensor(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Sensor *))*(void**)(__base - 406))(__t__p0));\
	})
#endif

#ifndef SDL_CloseStorage
#define SDL_CloseStorage(__p0) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *))*(void**)(__base - 412))(__t__p0));\
	})
#endif

#ifndef SDL_CompareAndSwapAtomicInt
#define SDL_CompareAndSwapAtomicInt(__p0, __p1, __p2) \
	({ \
		SDL_AtomicInt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AtomicInt *, int , int ))*(void**)(__base - 418))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CompareAndSwapAtomicPointer
#define SDL_CompareAndSwapAtomicPointer(__p0, __p1, __p2) \
	({ \
		void ** __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void **, void *, void *))*(void**)(__base - 424))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CompareAndSwapAtomicU32
#define SDL_CompareAndSwapAtomicU32(__p0, __p1, __p2) \
	({ \
		SDL_AtomicU32 * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AtomicU32 *, Uint32 , Uint32 ))*(void**)(__base - 430))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ComposeCustomBlendMode
#define SDL_ComposeCustomBlendMode(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_BlendFactor  __t__p0 = __p0;\
		SDL_BlendFactor  __t__p1 = __p1;\
		SDL_BlendOperation  __t__p2 = __p2;\
		SDL_BlendFactor  __t__p3 = __p3;\
		SDL_BlendFactor  __t__p4 = __p4;\
		SDL_BlendOperation  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_BlendMode (*)(SDL_BlendFactor , SDL_BlendFactor , SDL_BlendOperation , SDL_BlendFactor , SDL_BlendFactor , SDL_BlendOperation ))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_ConvertAudioSamples
#define SDL_ConvertAudioSamples(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const SDL_AudioSpec * __t__p0 = __p0;\
		const Uint8 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		const SDL_AudioSpec * __t__p3 = __p3;\
		Uint8 ** __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_AudioSpec *, const Uint8 *, int , const SDL_AudioSpec *, Uint8 **, int *))*(void**)(__base - 442))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_ConvertEventToRenderCoordinates
#define SDL_ConvertEventToRenderCoordinates(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Event * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Event *))*(void**)(__base - 448))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ConvertPixels
#define SDL_ConvertPixels(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_PixelFormat  __t__p2 = __p2;\
		const void * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		SDL_PixelFormat  __t__p5 = __p5;\
		void * __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(int , int , SDL_PixelFormat , const void *, int , SDL_PixelFormat , void *, int ))*(void**)(__base - 454))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})
#endif

#ifndef SDL_ConvertPixelsAndColorspace
#define SDL_ConvertPixelsAndColorspace(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_PixelFormat  __t__p2 = __p2;\
		SDL_Colorspace  __t__p3 = __p3;\
		SDL_PropertiesID  __t__p4 = __p4;\
		const void * __t__p5 = __p5;\
		int  __t__p6 = __p6;\
		SDL_PixelFormat  __t__p7 = __p7;\
		SDL_Colorspace  __t__p8 = __p8;\
		SDL_PropertiesID  __t__p9 = __p9;\
		void * __t__p10 = __p10;\
		int  __t__p11 = __p11;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(int , int , SDL_PixelFormat , SDL_Colorspace , SDL_PropertiesID , const void *, int , SDL_PixelFormat , SDL_Colorspace , SDL_PropertiesID , void *, int ))*(void**)(__base - 460))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})
#endif

#ifndef SDL_ConvertSurface
#define SDL_ConvertSurface(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_PixelFormat  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Surface *, SDL_PixelFormat ))*(void**)(__base - 466))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ConvertSurfaceAndColorspace
#define SDL_ConvertSurfaceAndColorspace(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_PixelFormat  __t__p1 = __p1;\
		SDL_Palette * __t__p2 = __p2;\
		SDL_Colorspace  __t__p3 = __p3;\
		SDL_PropertiesID  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Surface *, SDL_PixelFormat , SDL_Palette *, SDL_Colorspace , SDL_PropertiesID ))*(void**)(__base - 472))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CopyFile
#define SDL_CopyFile(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *))*(void**)(__base - 478))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CopyGPUBufferToBuffer
#define SDL_CopyGPUBufferToBuffer(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUBufferLocation * __t__p1 = __p1;\
		const SDL_GPUBufferLocation * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		bool  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUBufferLocation *, const SDL_GPUBufferLocation *, Uint32 , bool ))*(void**)(__base - 484))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CopyGPUTextureToTexture
#define SDL_CopyGPUTextureToTexture(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUTextureLocation * __t__p1 = __p1;\
		const SDL_GPUTextureLocation * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		Uint32  __t__p4 = __p4;\
		Uint32  __t__p5 = __p5;\
		bool  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUTextureLocation *, const SDL_GPUTextureLocation *, Uint32 , Uint32 , Uint32 , bool ))*(void**)(__base - 490))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_CopyProperties
#define SDL_CopyProperties(__p0, __p1) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , SDL_PropertiesID ))*(void**)(__base - 496))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CopyStorageFile
#define SDL_CopyStorageFile(__p0, __p1, __p2) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, const char *))*(void**)(__base - 502))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CreateAudioStream
#define SDL_CreateAudioStream(__p0, __p1) \
	({ \
		const SDL_AudioSpec * __t__p0 = __p0;\
		const SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioStream *(*)(const SDL_AudioSpec *, const SDL_AudioSpec *))*(void**)(__base - 508))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateColorCursor
#define SDL_CreateColorCursor(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(SDL_Surface *, int , int ))*(void**)(__base - 514))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CreateCondition
#define SDL_CreateCondition() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Condition *(*)(void))*(void**)(__base - 520))());\
	})
#endif

#ifndef SDL_CreateCursor
#define SDL_CreateCursor(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const Uint8 * __t__p0 = __p0;\
		const Uint8 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(const Uint8 *, const Uint8 *, int , int , int , int ))*(void**)(__base - 526))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_CreateDirectory
#define SDL_CreateDirectory(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 532))(__t__p0));\
	})
#endif

#ifndef SDL_CreateEnvironment
#define SDL_CreateEnvironment(__p0) \
	({ \
		bool  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Environment *(*)(bool ))*(void**)(__base - 538))(__t__p0));\
	})
#endif

#ifndef SDL_CreateGPUBuffer
#define SDL_CreateGPUBuffer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUBufferCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUBuffer *(*)(SDL_GPUDevice *, const SDL_GPUBufferCreateInfo *))*(void**)(__base - 544))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUComputePipeline
#define SDL_CreateGPUComputePipeline(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUComputePipelineCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUComputePipeline *(*)(SDL_GPUDevice *, const SDL_GPUComputePipelineCreateInfo *))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUDevice
#define SDL_CreateGPUDevice(__p0, __p1, __p2) \
	({ \
		SDL_GPUShaderFormat  __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUDevice *(*)(SDL_GPUShaderFormat , bool , const char *))*(void**)(__base - 556))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CreateGPUDeviceWithProperties
#define SDL_CreateGPUDeviceWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUDevice *(*)(SDL_PropertiesID ))*(void**)(__base - 562))(__t__p0));\
	})
#endif

#ifndef SDL_CreateGPUGraphicsPipeline
#define SDL_CreateGPUGraphicsPipeline(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUGraphicsPipelineCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUGraphicsPipeline *(*)(SDL_GPUDevice *, const SDL_GPUGraphicsPipelineCreateInfo *))*(void**)(__base - 568))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUSampler
#define SDL_CreateGPUSampler(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUSamplerCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUSampler *(*)(SDL_GPUDevice *, const SDL_GPUSamplerCreateInfo *))*(void**)(__base - 574))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUShader
#define SDL_CreateGPUShader(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUShaderCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUShader *(*)(SDL_GPUDevice *, const SDL_GPUShaderCreateInfo *))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUTexture
#define SDL_CreateGPUTexture(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUTextureCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTexture *(*)(SDL_GPUDevice *, const SDL_GPUTextureCreateInfo *))*(void**)(__base - 586))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPUTransferBuffer
#define SDL_CreateGPUTransferBuffer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		const SDL_GPUTransferBufferCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTransferBuffer *(*)(SDL_GPUDevice *, const SDL_GPUTransferBufferCreateInfo *))*(void**)(__base - 592))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateHapticEffect
#define SDL_CreateHapticEffect(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		const SDL_HapticEffect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_HapticEffectID (*)(SDL_Haptic *, const SDL_HapticEffect *))*(void**)(__base - 598))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateMutex
#define SDL_CreateMutex() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Mutex *(*)(void))*(void**)(__base - 604))());\
	})
#endif

#ifndef SDL_CreatePalette
#define SDL_CreatePalette(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Palette *(*)(int ))*(void**)(__base - 610))(__t__p0));\
	})
#endif

#ifndef SDL_CreatePopupWindow
#define SDL_CreatePopupWindow(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		SDL_WindowFlags  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(SDL_Window *, int , int , int , int , SDL_WindowFlags ))*(void**)(__base - 616))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_CreateProcess
#define SDL_CreateProcess(__p0, __p1) \
	({ \
		const char *const * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Process *(*)(const char *const *, bool ))*(void**)(__base - 622))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateProcessWithProperties
#define SDL_CreateProcessWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Process *(*)(SDL_PropertiesID ))*(void**)(__base - 628))(__t__p0));\
	})
#endif

#ifndef SDL_CreateProperties
#define SDL_CreateProperties() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(void))*(void**)(__base - 634))());\
	})
#endif

#ifndef SDL_CreateRWLock
#define SDL_CreateRWLock() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_RWLock *(*)(void))*(void**)(__base - 640))());\
	})
#endif

#ifndef SDL_CreateRenderer
#define SDL_CreateRenderer(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_Window *, const char *))*(void**)(__base - 646))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateRendererWithProperties
#define SDL_CreateRendererWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_PropertiesID ))*(void**)(__base - 652))(__t__p0));\
	})
#endif

#ifndef SDL_CreateSemaphore
#define SDL_CreateSemaphore(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Semaphore *(*)(Uint32 ))*(void**)(__base - 658))(__t__p0));\
	})
#endif

#ifndef SDL_CreateSoftwareRenderer
#define SDL_CreateSoftwareRenderer(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_Surface *))*(void**)(__base - 664))(__t__p0));\
	})
#endif

#ifndef SDL_CreateStorageDirectory
#define SDL_CreateStorageDirectory(__p0, __p1) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *))*(void**)(__base - 670))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateSurface
#define SDL_CreateSurface(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_PixelFormat  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(int , int , SDL_PixelFormat ))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CreateSurfaceFrom
#define SDL_CreateSurfaceFrom(__p0, __p1, __p2, __p3, __p4) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_PixelFormat  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(int , int , SDL_PixelFormat , void *, int ))*(void**)(__base - 682))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CreateSurfacePalette
#define SDL_CreateSurfacePalette(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Palette *(*)(SDL_Surface *))*(void**)(__base - 688))(__t__p0));\
	})
#endif

#ifndef SDL_CreateSystemCursor
#define SDL_CreateSystemCursor(__p0) \
	({ \
		SDL_SystemCursor  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(SDL_SystemCursor ))*(void**)(__base - 694))(__t__p0));\
	})
#endif

#ifndef SDL_CreateTexture
#define SDL_CreateTexture(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_PixelFormat  __t__p1 = __p1;\
		SDL_TextureAccess  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, SDL_PixelFormat , SDL_TextureAccess , int , int ))*(void**)(__base - 700))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CreateTextureFromSurface
#define SDL_CreateTextureFromSurface(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, SDL_Surface *))*(void**)(__base - 706))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateTextureWithProperties
#define SDL_CreateTextureWithProperties(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, SDL_PropertiesID ))*(void**)(__base - 712))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateThreadRuntime
#define SDL_CreateThreadRuntime(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_ThreadFunction  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		SDL_FunctionPointer  __t__p3 = __p3;\
		SDL_FunctionPointer  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Thread *(*)(SDL_ThreadFunction , const char *, void *, SDL_FunctionPointer , SDL_FunctionPointer ))*(void**)(__base - 718))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CreateThreadWithPropertiesRuntime
#define SDL_CreateThreadWithPropertiesRuntime(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		SDL_FunctionPointer  __t__p1 = __p1;\
		SDL_FunctionPointer  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Thread *(*)(SDL_PropertiesID , SDL_FunctionPointer , SDL_FunctionPointer ))*(void**)(__base - 724))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_CreateWindow
#define SDL_CreateWindow(__p0, __p1, __p2, __p3) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_WindowFlags  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(const char *, int , int , SDL_WindowFlags ))*(void**)(__base - 730))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_CreateWindowAndRenderer
#define SDL_CreateWindowAndRenderer(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_WindowFlags  __t__p3 = __p3;\
		SDL_Window ** __t__p4 = __p4;\
		SDL_Renderer ** __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, int , int , SDL_WindowFlags , SDL_Window **, SDL_Renderer **))*(void**)(__base - 736))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_CreateWindowWithProperties
#define SDL_CreateWindowWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(SDL_PropertiesID ))*(void**)(__base - 742))(__t__p0));\
	})
#endif

#ifndef SDL_CursorVisible
#define SDL_CursorVisible() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 748))());\
	})
#endif

#ifndef SDL_DateTimeToTime
#define SDL_DateTimeToTime(__p0, __p1) \
	({ \
		const SDL_DateTime * __t__p0 = __p0;\
		SDL_Time * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_DateTime *, SDL_Time *))*(void**)(__base - 754))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_Delay
#define SDL_Delay(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 ))*(void**)(__base - 760))(__t__p0));\
	})
#endif

#ifndef SDL_DelayNS
#define SDL_DelayNS(__p0) \
	({ \
		Uint64  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint64 ))*(void**)(__base - 766))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyAudioStream
#define SDL_DestroyAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AudioStream *))*(void**)(__base - 772))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyCondition
#define SDL_DestroyCondition(__p0) \
	({ \
		SDL_Condition * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Condition *))*(void**)(__base - 778))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyCursor
#define SDL_DestroyCursor(__p0) \
	({ \
		SDL_Cursor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Cursor *))*(void**)(__base - 784))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyEnvironment
#define SDL_DestroyEnvironment(__p0) \
	({ \
		SDL_Environment * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Environment *))*(void**)(__base - 790))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyGPUDevice
#define SDL_DestroyGPUDevice(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *))*(void**)(__base - 796))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyHapticEffect
#define SDL_DestroyHapticEffect(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		SDL_HapticEffectID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Haptic *, SDL_HapticEffectID ))*(void**)(__base - 802))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_DestroyMutex
#define SDL_DestroyMutex(__p0) \
	({ \
		SDL_Mutex * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Mutex *))*(void**)(__base - 808))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyPalette
#define SDL_DestroyPalette(__p0) \
	({ \
		SDL_Palette * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Palette *))*(void**)(__base - 814))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyProcess
#define SDL_DestroyProcess(__p0) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Process *))*(void**)(__base - 820))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyProperties
#define SDL_DestroyProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_PropertiesID ))*(void**)(__base - 826))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyRWLock
#define SDL_DestroyRWLock(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_RWLock *))*(void**)(__base - 832))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyRenderer
#define SDL_DestroyRenderer(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Renderer *))*(void**)(__base - 838))(__t__p0));\
	})
#endif

#ifndef SDL_DestroySemaphore
#define SDL_DestroySemaphore(__p0) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Semaphore *))*(void**)(__base - 844))(__t__p0));\
	})
#endif

#ifndef SDL_DestroySurface
#define SDL_DestroySurface(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Surface *))*(void**)(__base - 850))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyTexture
#define SDL_DestroyTexture(__p0) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Texture *))*(void**)(__base - 856))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyWindow
#define SDL_DestroyWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Window *))*(void**)(__base - 862))(__t__p0));\
	})
#endif

#ifndef SDL_DestroyWindowSurface
#define SDL_DestroyWindowSurface(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 868))(__t__p0));\
	})
#endif

#ifndef SDL_DetachThread
#define SDL_DetachThread(__p0) \
	({ \
		SDL_Thread * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Thread *))*(void**)(__base - 874))(__t__p0));\
	})
#endif

#ifndef SDL_DetachVirtualJoystick
#define SDL_DetachVirtualJoystick(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_JoystickID ))*(void**)(__base - 880))(__t__p0));\
	})
#endif

#ifndef SDL_DisableScreenSaver
#define SDL_DisableScreenSaver() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 886))());\
	})
#endif

#ifndef SDL_DispatchGPUCompute
#define SDL_DispatchGPUCompute(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, Uint32 , Uint32 , Uint32 ))*(void**)(__base - 892))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_DispatchGPUComputeIndirect
#define SDL_DispatchGPUComputeIndirect(__p0, __p1, __p2) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		SDL_GPUBuffer * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *, SDL_GPUBuffer *, Uint32 ))*(void**)(__base - 898))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_DownloadFromGPUBuffer
#define SDL_DownloadFromGPUBuffer(__p0, __p1, __p2) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUBufferRegion * __t__p1 = __p1;\
		const SDL_GPUTransferBufferLocation * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUBufferRegion *, const SDL_GPUTransferBufferLocation *))*(void**)(__base - 904))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_DownloadFromGPUTexture
#define SDL_DownloadFromGPUTexture(__p0, __p1, __p2) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUTextureRegion * __t__p1 = __p1;\
		const SDL_GPUTextureTransferInfo * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUTextureRegion *, const SDL_GPUTextureTransferInfo *))*(void**)(__base - 910))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_DrawGPUIndexedPrimitives
#define SDL_DrawGPUIndexedPrimitives(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		Sint32  __t__p4 = __p4;\
		Uint32  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , Uint32 , Uint32 , Sint32 , Uint32 ))*(void**)(__base - 916))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_DrawGPUIndexedPrimitivesIndirect
#define SDL_DrawGPUIndexedPrimitivesIndirect(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		SDL_GPUBuffer * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, SDL_GPUBuffer *, Uint32 , Uint32 ))*(void**)(__base - 922))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_DrawGPUPrimitives
#define SDL_DrawGPUPrimitives(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		Uint32  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint32 , Uint32 , Uint32 , Uint32 ))*(void**)(__base - 928))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_DrawGPUPrimitivesIndirect
#define SDL_DrawGPUPrimitivesIndirect(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		SDL_GPUBuffer * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, SDL_GPUBuffer *, Uint32 , Uint32 ))*(void**)(__base - 934))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_DuplicateSurface
#define SDL_DuplicateSurface(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Surface *))*(void**)(__base - 940))(__t__p0));\
	})
#endif

#ifndef SDL_EGL_GetCurrentConfig
#define SDL_EGL_GetCurrentConfig() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_EGLConfig (*)(void))*(void**)(__base - 946))());\
	})
#endif

#ifndef SDL_EGL_GetCurrentDisplay
#define SDL_EGL_GetCurrentDisplay() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_EGLDisplay (*)(void))*(void**)(__base - 952))());\
	})
#endif

#ifndef SDL_EGL_GetProcAddress
#define SDL_EGL_GetProcAddress(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_FunctionPointer (*)(const char *))*(void**)(__base - 958))(__t__p0));\
	})
#endif

#ifndef SDL_EGL_GetWindowSurface
#define SDL_EGL_GetWindowSurface(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_EGLSurface (*)(SDL_Window *))*(void**)(__base - 964))(__t__p0));\
	})
#endif

#ifndef SDL_EGL_SetAttributeCallbacks
#define SDL_EGL_SetAttributeCallbacks(__p0, __p1, __p2, __p3) \
	({ \
		SDL_EGLAttribArrayCallback  __t__p0 = __p0;\
		SDL_EGLIntArrayCallback  __t__p1 = __p1;\
		SDL_EGLIntArrayCallback  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_EGLAttribArrayCallback , SDL_EGLIntArrayCallback , SDL_EGLIntArrayCallback , void *))*(void**)(__base - 970))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_EnableScreenSaver
#define SDL_EnableScreenSaver() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 976))());\
	})
#endif

#ifndef SDL_EndGPUComputePass
#define SDL_EndGPUComputePass(__p0) \
	({ \
		SDL_GPUComputePass * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUComputePass *))*(void**)(__base - 982))(__t__p0));\
	})
#endif

#ifndef SDL_EndGPUCopyPass
#define SDL_EndGPUCopyPass(__p0) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *))*(void**)(__base - 988))(__t__p0));\
	})
#endif

#ifndef SDL_EndGPURenderPass
#define SDL_EndGPURenderPass(__p0) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *))*(void**)(__base - 994))(__t__p0));\
	})
#endif

#ifndef SDL_EnterAppMainCallbacks
#define SDL_EnterAppMainCallbacks(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		int  __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		SDL_AppInit_func  __t__p2 = __p2;\
		SDL_AppIterate_func  __t__p3 = __p3;\
		SDL_AppEvent_func  __t__p4 = __p4;\
		SDL_AppQuit_func  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , char **, SDL_AppInit_func , SDL_AppIterate_func , SDL_AppEvent_func , SDL_AppQuit_func ))*(void**)(__base - 1000))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_EnumerateDirectory
#define SDL_EnumerateDirectory(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_EnumerateDirectoryCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, SDL_EnumerateDirectoryCallback , void *))*(void**)(__base - 1006))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_EnumerateProperties
#define SDL_EnumerateProperties(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		SDL_EnumeratePropertiesCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , SDL_EnumeratePropertiesCallback , void *))*(void**)(__base - 1012))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_EnumerateStorageDirectory
#define SDL_EnumerateStorageDirectory(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_EnumerateDirectoryCallback  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, SDL_EnumerateDirectoryCallback , void *))*(void**)(__base - 1018))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_EventEnabled
#define SDL_EventEnabled(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(Uint32 ))*(void**)(__base - 1024))(__t__p0));\
	})
#endif

#ifndef SDL_FillSurfaceRect
#define SDL_FillSurfaceRect(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, Uint32 ))*(void**)(__base - 1030))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_FillSurfaceRects
#define SDL_FillSurfaceRects(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, int , Uint32 ))*(void**)(__base - 1036))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_FilterEvents
#define SDL_FilterEvents(__p0, __p1) \
	({ \
		SDL_EventFilter  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_EventFilter , void *))*(void**)(__base - 1042))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_FlashWindow
#define SDL_FlashWindow(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_FlashOperation  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_FlashOperation ))*(void**)(__base - 1048))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_FlipSurface
#define SDL_FlipSurface(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_FlipMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_FlipMode ))*(void**)(__base - 1054))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_FlushAudioStream
#define SDL_FlushAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 1060))(__t__p0));\
	})
#endif

#ifndef SDL_FlushEvent
#define SDL_FlushEvent(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 ))*(void**)(__base - 1066))(__t__p0));\
	})
#endif

#ifndef SDL_FlushEvents
#define SDL_FlushEvents(__p0, __p1) \
	({ \
		Uint32  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 , Uint32 ))*(void**)(__base - 1072))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_FlushIO
#define SDL_FlushIO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 1078))(__t__p0));\
	})
#endif

#ifndef SDL_FlushRenderer
#define SDL_FlushRenderer(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *))*(void**)(__base - 1084))(__t__p0));\
	})
#endif

#ifndef SDL_GL_CreateContext
#define SDL_GL_CreateContext(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GLContext (*)(SDL_Window *))*(void**)(__base - 1108))(__t__p0));\
	})
#endif

#ifndef SDL_GL_DestroyContext
#define SDL_GL_DestroyContext(__p0) \
	({ \
		SDL_GLContext  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GLContext ))*(void**)(__base - 1114))(__t__p0));\
	})
#endif

#ifndef SDL_GL_ExtensionSupported
#define SDL_GL_ExtensionSupported(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 1120))(__t__p0));\
	})
#endif

#ifndef SDL_GL_GetAttribute
#define SDL_GL_GetAttribute(__p0, __p1) \
	({ \
		SDL_GLAttr  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GLAttr , int *))*(void**)(__base - 1126))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GL_GetCurrentContext
#define SDL_GL_GetCurrentContext() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GLContext (*)(void))*(void**)(__base - 1132))());\
	})
#endif

#ifndef SDL_GL_GetCurrentWindow
#define SDL_GL_GetCurrentWindow() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(void))*(void**)(__base - 1138))());\
	})
#endif

#ifndef SDL_GL_GetSwapInterval
#define SDL_GL_GetSwapInterval(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(int *))*(void**)(__base - 1150))(__t__p0));\
	})
#endif

#ifndef SDL_GL_LoadLibrary
#define SDL_GL_LoadLibrary(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 1156))(__t__p0));\
	})
#endif

#ifndef SDL_GL_MakeCurrent
#define SDL_GL_MakeCurrent(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_GLContext  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_GLContext ))*(void**)(__base - 1162))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GL_ResetAttributes
#define SDL_GL_ResetAttributes() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1168))());\
	})
#endif

#ifndef SDL_GL_SetAttribute
#define SDL_GL_SetAttribute(__p0, __p1) \
	({ \
		SDL_GLAttr  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GLAttr , int ))*(void**)(__base - 1174))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GL_SetSwapInterval
#define SDL_GL_SetSwapInterval(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(int ))*(void**)(__base - 1180))(__t__p0));\
	})
#endif

#ifndef SDL_GL_SwapWindow
#define SDL_GL_SwapWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 1186))(__t__p0));\
	})
#endif

#ifndef SDL_GL_UnloadLibrary
#define SDL_GL_UnloadLibrary() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1192))());\
	})
#endif

#ifndef SDL_GPUSupportsProperties
#define SDL_GPUSupportsProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID ))*(void**)(__base - 1198))(__t__p0));\
	})
#endif

#ifndef SDL_GPUSupportsShaderFormats
#define SDL_GPUSupportsShaderFormats(__p0, __p1) \
	({ \
		SDL_GPUShaderFormat  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUShaderFormat , const char *))*(void**)(__base - 1204))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GPUTextureFormatTexelBlockSize
#define SDL_GPUTextureFormatTexelBlockSize(__p0) \
	({ \
		SDL_GPUTextureFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_GPUTextureFormat ))*(void**)(__base - 1210))(__t__p0));\
	})
#endif

#ifndef SDL_GPUTextureSupportsFormat
#define SDL_GPUTextureSupportsFormat(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTextureFormat  __t__p1 = __p1;\
		SDL_GPUTextureType  __t__p2 = __p2;\
		SDL_GPUTextureUsageFlags  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_GPUTextureFormat , SDL_GPUTextureType , SDL_GPUTextureUsageFlags ))*(void**)(__base - 1216))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GPUTextureSupportsSampleCount
#define SDL_GPUTextureSupportsSampleCount(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTextureFormat  __t__p1 = __p1;\
		SDL_GPUSampleCount  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_GPUTextureFormat , SDL_GPUSampleCount ))*(void**)(__base - 1222))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GUIDToString
#define SDL_GUIDToString(__p0, __p1, __p2) \
	({ \
		SDL_GUID  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GUID , char *, int ))*(void**)(__base - 1228))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GamepadConnected
#define SDL_GamepadConnected(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *))*(void**)(__base - 1234))(__t__p0));\
	})
#endif

#ifndef SDL_GamepadEventsEnabled
#define SDL_GamepadEventsEnabled() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 1240))());\
	})
#endif

#ifndef SDL_GamepadHasAxis
#define SDL_GamepadHasAxis(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadAxis  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_GamepadAxis ))*(void**)(__base - 1246))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GamepadHasButton
#define SDL_GamepadHasButton(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadButton  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_GamepadButton ))*(void**)(__base - 1252))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GamepadHasSensor
#define SDL_GamepadHasSensor(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_SensorType ))*(void**)(__base - 1258))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GamepadSensorEnabled
#define SDL_GamepadSensorEnabled(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_SensorType ))*(void**)(__base - 1264))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GenerateMipmapsForGPUTexture
#define SDL_GenerateMipmapsForGPUTexture(__p0, __p1) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		SDL_GPUTexture * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, SDL_GPUTexture *))*(void**)(__base - 1270))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetAppMetadataProperty
#define SDL_GetAppMetadataProperty(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const char *))*(void**)(__base - 1318))(__t__p0));\
	})
#endif

#ifndef SDL_GetAssertionHandler
#define SDL_GetAssertionHandler(__p0) \
	({ \
		void ** __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AssertionHandler (*)(void **))*(void**)(__base - 1324))(__t__p0));\
	})
#endif

#ifndef SDL_GetAssertionReport
#define SDL_GetAssertionReport() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_AssertData *(*)(void))*(void**)(__base - 1330))());\
	})
#endif

#ifndef SDL_GetAtomicInt
#define SDL_GetAtomicInt(__p0) \
	({ \
		SDL_AtomicInt * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AtomicInt *))*(void**)(__base - 1336))(__t__p0));\
	})
#endif

#ifndef SDL_GetAtomicPointer
#define SDL_GetAtomicPointer(__p0) \
	({ \
		void ** __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void **))*(void**)(__base - 1342))(__t__p0));\
	})
#endif

#ifndef SDL_GetAtomicU32
#define SDL_GetAtomicU32(__p0) \
	({ \
		SDL_AtomicU32 * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_AtomicU32 *))*(void**)(__base - 1348))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioDeviceChannelMap
#define SDL_GetAudioDeviceChannelMap(__p0, __p1) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int *(*)(SDL_AudioDeviceID , int *))*(void**)(__base - 1354))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetAudioDeviceFormat
#define SDL_GetAudioDeviceFormat(__p0, __p1, __p2) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID , SDL_AudioSpec *, int *))*(void**)(__base - 1360))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetAudioDeviceGain
#define SDL_GetAudioDeviceGain(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_AudioDeviceID ))*(void**)(__base - 1366))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioDeviceName
#define SDL_GetAudioDeviceName(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_AudioDeviceID ))*(void**)(__base - 1372))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioDriver
#define SDL_GetAudioDriver(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 1378))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioFormatName
#define SDL_GetAudioFormatName(__p0) \
	({ \
		SDL_AudioFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_AudioFormat ))*(void**)(__base - 1384))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioPlaybackDevices
#define SDL_GetAudioPlaybackDevices(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioDeviceID *(*)(int *))*(void**)(__base - 1390))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioRecordingDevices
#define SDL_GetAudioRecordingDevices(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioDeviceID *(*)(int *))*(void**)(__base - 1396))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamAvailable
#define SDL_GetAudioStreamAvailable(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AudioStream *))*(void**)(__base - 1402))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamData
#define SDL_GetAudioStreamData(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AudioStream *, void *, int ))*(void**)(__base - 1408))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetAudioStreamDevice
#define SDL_GetAudioStreamDevice(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioDeviceID (*)(SDL_AudioStream *))*(void**)(__base - 1414))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamFormat
#define SDL_GetAudioStreamFormat(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		SDL_AudioSpec * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, SDL_AudioSpec *, SDL_AudioSpec *))*(void**)(__base - 1420))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetAudioStreamFrequencyRatio
#define SDL_GetAudioStreamFrequencyRatio(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_AudioStream *))*(void**)(__base - 1426))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamGain
#define SDL_GetAudioStreamGain(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_AudioStream *))*(void**)(__base - 1432))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamInputChannelMap
#define SDL_GetAudioStreamInputChannelMap(__p0, __p1) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int *(*)(SDL_AudioStream *, int *))*(void**)(__base - 1438))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetAudioStreamOutputChannelMap
#define SDL_GetAudioStreamOutputChannelMap(__p0, __p1) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int *(*)(SDL_AudioStream *, int *))*(void**)(__base - 1444))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetAudioStreamProperties
#define SDL_GetAudioStreamProperties(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_AudioStream *))*(void**)(__base - 1450))(__t__p0));\
	})
#endif

#ifndef SDL_GetAudioStreamQueued
#define SDL_GetAudioStreamQueued(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AudioStream *))*(void**)(__base - 1456))(__t__p0));\
	})
#endif

#ifndef SDL_GetBasePath
#define SDL_GetBasePath() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1462))());\
	})
#endif

#ifndef SDL_GetBooleanProperty
#define SDL_GetBooleanProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, bool ))*(void**)(__base - 1468))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetCPUCacheLineSize
#define SDL_GetCPUCacheLineSize() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 1474))());\
	})
#endif

#ifndef SDL_GetCameraDriver
#define SDL_GetCameraDriver(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 1480))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraFormat
#define SDL_GetCameraFormat(__p0, __p1) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		SDL_CameraSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Camera *, SDL_CameraSpec *))*(void**)(__base - 1486))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetCameraID
#define SDL_GetCameraID(__p0) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_CameraID (*)(SDL_Camera *))*(void**)(__base - 1492))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraName
#define SDL_GetCameraName(__p0) \
	({ \
		SDL_CameraID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_CameraID ))*(void**)(__base - 1498))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraPermissionState
#define SDL_GetCameraPermissionState(__p0) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_CameraPermissionState (*)(SDL_Camera *))*(void**)(__base - 1504))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraPosition
#define SDL_GetCameraPosition(__p0) \
	({ \
		SDL_CameraID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_CameraPosition (*)(SDL_CameraID ))*(void**)(__base - 1510))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraProperties
#define SDL_GetCameraProperties(__p0) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Camera *))*(void**)(__base - 1516))(__t__p0));\
	})
#endif

#ifndef SDL_GetCameraSupportedFormats
#define SDL_GetCameraSupportedFormats(__p0, __p1) \
	({ \
		SDL_CameraID  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_CameraSpec **(*)(SDL_CameraID , int *))*(void**)(__base - 1522))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetCameras
#define SDL_GetCameras(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_CameraID *(*)(int *))*(void**)(__base - 1528))(__t__p0));\
	})
#endif

#ifndef SDL_GetClipboardData
#define SDL_GetClipboardData(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(const char *, size_t *))*(void**)(__base - 1534))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetClipboardMimeTypes
#define SDL_GetClipboardMimeTypes(__p0) \
	({ \
		size_t * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(size_t *))*(void**)(__base - 1540))(__t__p0));\
	})
#endif

#ifndef SDL_GetClipboardText
#define SDL_GetClipboardText() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(void))*(void**)(__base - 1546))());\
	})
#endif

#ifndef SDL_GetClosestFullscreenDisplayMode
#define SDL_GetClosestFullscreenDisplayMode(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		bool  __t__p4 = __p4;\
		SDL_DisplayMode * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_DisplayID , int , int , float , bool , SDL_DisplayMode *))*(void**)(__base - 1552))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_GetCurrentAudioDriver
#define SDL_GetCurrentAudioDriver() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1558))());\
	})
#endif

#ifndef SDL_GetCurrentCameraDriver
#define SDL_GetCurrentCameraDriver() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1564))());\
	})
#endif

#ifndef SDL_GetCurrentDisplayMode
#define SDL_GetCurrentDisplayMode(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_DisplayMode *(*)(SDL_DisplayID ))*(void**)(__base - 1570))(__t__p0));\
	})
#endif

#ifndef SDL_GetCurrentDisplayOrientation
#define SDL_GetCurrentDisplayOrientation(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayOrientation (*)(SDL_DisplayID ))*(void**)(__base - 1576))(__t__p0));\
	})
#endif

#ifndef SDL_GetCurrentRenderOutputSize
#define SDL_GetCurrentRenderOutputSize(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int *, int *))*(void**)(__base - 1582))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetCurrentThreadID
#define SDL_GetCurrentThreadID() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_ThreadID (*)(void))*(void**)(__base - 1588))());\
	})
#endif

#ifndef SDL_GetCurrentTime
#define SDL_GetCurrentTime(__p0) \
	({ \
		SDL_Time * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Time *))*(void**)(__base - 1594))(__t__p0));\
	})
#endif

#ifndef SDL_GetCurrentVideoDriver
#define SDL_GetCurrentVideoDriver() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1600))());\
	})
#endif

#ifndef SDL_GetCursor
#define SDL_GetCursor() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(void))*(void**)(__base - 1606))());\
	})
#endif

#ifndef SDL_GetDXGIOutputInfo
#define SDL_GetDXGIOutputInfo(__p0, __p1, __p2) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_DisplayID , int *, int *))*(void**)(__base - 1612))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetDateTimeLocalePreferences
#define SDL_GetDateTimeLocalePreferences(__p0, __p1) \
	({ \
		SDL_DateFormat * __t__p0 = __p0;\
		SDL_TimeFormat * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_DateFormat *, SDL_TimeFormat *))*(void**)(__base - 1618))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDayOfWeek
#define SDL_GetDayOfWeek(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int , int ))*(void**)(__base - 1624))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetDayOfYear
#define SDL_GetDayOfYear(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int , int ))*(void**)(__base - 1630))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetDaysInMonth
#define SDL_GetDaysInMonth(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 1636))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDefaultAssertionHandler
#define SDL_GetDefaultAssertionHandler() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AssertionHandler (*)(void))*(void**)(__base - 1642))());\
	})
#endif

#ifndef SDL_GetDefaultCursor
#define SDL_GetDefaultCursor() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(void))*(void**)(__base - 1648))());\
	})
#endif

#ifndef SDL_GetDesktopDisplayMode
#define SDL_GetDesktopDisplayMode(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_DisplayMode *(*)(SDL_DisplayID ))*(void**)(__base - 1654))(__t__p0));\
	})
#endif

#ifndef SDL_GetDirect3D9AdapterIndex
#define SDL_GetDirect3D9AdapterIndex(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_DisplayID ))*(void**)(__base - 1660))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayBounds
#define SDL_GetDisplayBounds(__p0, __p1) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_DisplayID , SDL_Rect *))*(void**)(__base - 1666))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDisplayContentScale
#define SDL_GetDisplayContentScale(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_DisplayID ))*(void**)(__base - 1672))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayForPoint
#define SDL_GetDisplayForPoint(__p0) \
	({ \
		const SDL_Point * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayID (*)(const SDL_Point *))*(void**)(__base - 1678))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayForRect
#define SDL_GetDisplayForRect(__p0) \
	({ \
		const SDL_Rect * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayID (*)(const SDL_Rect *))*(void**)(__base - 1684))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayForWindow
#define SDL_GetDisplayForWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayID (*)(SDL_Window *))*(void**)(__base - 1690))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayName
#define SDL_GetDisplayName(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_DisplayID ))*(void**)(__base - 1696))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayProperties
#define SDL_GetDisplayProperties(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_DisplayID ))*(void**)(__base - 1702))(__t__p0));\
	})
#endif

#ifndef SDL_GetDisplayUsableBounds
#define SDL_GetDisplayUsableBounds(__p0, __p1) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_DisplayID , SDL_Rect *))*(void**)(__base - 1708))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDisplays
#define SDL_GetDisplays(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayID *(*)(int *))*(void**)(__base - 1714))(__t__p0));\
	})
#endif

#ifndef SDL_GetEnvironment
#define SDL_GetEnvironment() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Environment *(*)(void))*(void**)(__base - 1720))());\
	})
#endif

#ifndef SDL_GetEnvironmentVariable
#define SDL_GetEnvironmentVariable(__p0, __p1) \
	({ \
		SDL_Environment * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Environment *, const char *))*(void**)(__base - 1726))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetEnvironmentVariables
#define SDL_GetEnvironmentVariables(__p0) \
	({ \
		SDL_Environment * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(SDL_Environment *))*(void**)(__base - 1732))(__t__p0));\
	})
#endif

#ifndef SDL_GetError
#define SDL_GetError() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 1738))());\
	})
#endif

#ifndef SDL_GetEventFilter
#define SDL_GetEventFilter(__p0, __p1) \
	({ \
		SDL_EventFilter * __t__p0 = __p0;\
		void ** __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_EventFilter *, void **))*(void**)(__base - 1744))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetFloatProperty
#define SDL_GetFloatProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_PropertiesID , const char *, float ))*(void**)(__base - 1750))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetFullscreenDisplayModes
#define SDL_GetFullscreenDisplayModes(__p0, __p1) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayMode **(*)(SDL_DisplayID , int *))*(void**)(__base - 1756))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGDKTaskQueue
#define SDL_GetGDKTaskQueue(__p0) \
	({ \
		XTaskQueueHandle * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(XTaskQueueHandle *))*(void**)(__base - 1768))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPUDeviceDriver
#define SDL_GetGPUDeviceDriver(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_GPUDevice *))*(void**)(__base - 1774))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPUDriver
#define SDL_GetGPUDriver(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 1780))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPUShaderFormats
#define SDL_GetGPUShaderFormats(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUShaderFormat (*)(SDL_GPUDevice *))*(void**)(__base - 1786))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPUSwapchainTextureFormat
#define SDL_GetGPUSwapchainTextureFormat(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTextureFormat (*)(SDL_GPUDevice *, SDL_Window *))*(void**)(__base - 1792))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadAppleSFSymbolsNameForAxis
#define SDL_GetGamepadAppleSFSymbolsNameForAxis(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadAxis  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Gamepad *, SDL_GamepadAxis ))*(void**)(__base - 1798))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadAppleSFSymbolsNameForButton
#define SDL_GetGamepadAppleSFSymbolsNameForButton(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadButton  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Gamepad *, SDL_GamepadButton ))*(void**)(__base - 1804))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadAxis
#define SDL_GetGamepadAxis(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadAxis  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint16 (*)(SDL_Gamepad *, SDL_GamepadAxis ))*(void**)(__base - 1810))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadAxisFromString
#define SDL_GetGamepadAxisFromString(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadAxis (*)(const char *))*(void**)(__base - 1816))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadBindings
#define SDL_GetGamepadBindings(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadBinding **(*)(SDL_Gamepad *, int *))*(void**)(__base - 1822))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadButton
#define SDL_GetGamepadButton(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadButton  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_GamepadButton ))*(void**)(__base - 1828))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadButtonFromString
#define SDL_GetGamepadButtonFromString(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadButton (*)(const char *))*(void**)(__base - 1834))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadButtonLabel
#define SDL_GetGamepadButtonLabel(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_GamepadButton  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadButtonLabel (*)(SDL_Gamepad *, SDL_GamepadButton ))*(void**)(__base - 1840))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadButtonLabelForType
#define SDL_GetGamepadButtonLabelForType(__p0, __p1) \
	({ \
		SDL_GamepadType  __t__p0 = __p0;\
		SDL_GamepadButton  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadButtonLabel (*)(SDL_GamepadType , SDL_GamepadButton ))*(void**)(__base - 1846))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadConnectionState
#define SDL_GetGamepadConnectionState(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickConnectionState (*)(SDL_Gamepad *))*(void**)(__base - 1852))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadFirmwareVersion
#define SDL_GetGamepadFirmwareVersion(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Gamepad *))*(void**)(__base - 1858))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadFromID
#define SDL_GetGamepadFromID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Gamepad *(*)(SDL_JoystickID ))*(void**)(__base - 1864))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadFromPlayerIndex
#define SDL_GetGamepadFromPlayerIndex(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Gamepad *(*)(int ))*(void**)(__base - 1870))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadGUIDForID
#define SDL_GetGamepadGUIDForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GUID (*)(SDL_JoystickID ))*(void**)(__base - 1876))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadID
#define SDL_GetGamepadID(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickID (*)(SDL_Gamepad *))*(void**)(__base - 1882))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadJoystick
#define SDL_GetGamepadJoystick(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Joystick *(*)(SDL_Gamepad *))*(void**)(__base - 1888))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadMapping
#define SDL_GetGamepadMapping(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(SDL_Gamepad *))*(void**)(__base - 1894))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadMappingForGUID
#define SDL_GetGamepadMappingForGUID(__p0) \
	({ \
		SDL_GUID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(SDL_GUID ))*(void**)(__base - 1900))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadMappingForID
#define SDL_GetGamepadMappingForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(SDL_JoystickID ))*(void**)(__base - 1906))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadMappings
#define SDL_GetGamepadMappings(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(int *))*(void**)(__base - 1912))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadName
#define SDL_GetGamepadName(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Gamepad *))*(void**)(__base - 1918))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadNameForID
#define SDL_GetGamepadNameForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_JoystickID ))*(void**)(__base - 1924))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadPath
#define SDL_GetGamepadPath(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Gamepad *))*(void**)(__base - 1930))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadPathForID
#define SDL_GetGamepadPathForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_JoystickID ))*(void**)(__base - 1936))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadPlayerIndex
#define SDL_GetGamepadPlayerIndex(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Gamepad *))*(void**)(__base - 1942))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadPlayerIndexForID
#define SDL_GetGamepadPlayerIndexForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_JoystickID ))*(void**)(__base - 1948))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadPowerInfo
#define SDL_GetGamepadPowerInfo(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PowerState (*)(SDL_Gamepad *, int *))*(void**)(__base - 1954))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadProduct
#define SDL_GetGamepadProduct(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Gamepad *))*(void**)(__base - 1960))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadProductForID
#define SDL_GetGamepadProductForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 1966))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadProductVersion
#define SDL_GetGamepadProductVersion(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Gamepad *))*(void**)(__base - 1972))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadProductVersionForID
#define SDL_GetGamepadProductVersionForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 1978))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadProperties
#define SDL_GetGamepadProperties(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Gamepad *))*(void**)(__base - 1984))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadSensorData
#define SDL_GetGamepadSensorData(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_SensorType , float *, int ))*(void**)(__base - 1990))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetGamepadSensorDataRate
#define SDL_GetGamepadSensorDataRate(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_Gamepad *, SDL_SensorType ))*(void**)(__base - 1996))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGamepadSerial
#define SDL_GetGamepadSerial(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Gamepad *))*(void**)(__base - 2002))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadSteamHandle
#define SDL_GetGamepadSteamHandle(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(SDL_Gamepad *))*(void**)(__base - 2008))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadStringForAxis
#define SDL_GetGamepadStringForAxis(__p0) \
	({ \
		SDL_GamepadAxis  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_GamepadAxis ))*(void**)(__base - 2014))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadStringForButton
#define SDL_GetGamepadStringForButton(__p0) \
	({ \
		SDL_GamepadButton  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_GamepadButton ))*(void**)(__base - 2020))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadStringForType
#define SDL_GetGamepadStringForType(__p0) \
	({ \
		SDL_GamepadType  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_GamepadType ))*(void**)(__base - 2026))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadTouchpadFinger
#define SDL_GetGamepadTouchpadFinger(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		bool * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		float * __t__p5 = __p5;\
		float * __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, int , int , bool *, float *, float *, float *))*(void**)(__base - 2032))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_GetGamepadType
#define SDL_GetGamepadType(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadType (*)(SDL_Gamepad *))*(void**)(__base - 2038))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadTypeForID
#define SDL_GetGamepadTypeForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadType (*)(SDL_JoystickID ))*(void**)(__base - 2044))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadTypeFromString
#define SDL_GetGamepadTypeFromString(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadType (*)(const char *))*(void**)(__base - 2050))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadVendor
#define SDL_GetGamepadVendor(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Gamepad *))*(void**)(__base - 2056))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepadVendorForID
#define SDL_GetGamepadVendorForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 2062))(__t__p0));\
	})
#endif

#ifndef SDL_GetGamepads
#define SDL_GetGamepads(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickID *(*)(int *))*(void**)(__base - 2068))(__t__p0));\
	})
#endif

#ifndef SDL_GetGlobalMouseState
#define SDL_GetGlobalMouseState(__p0, __p1) \
	({ \
		float * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_MouseButtonFlags (*)(float *, float *))*(void**)(__base - 2074))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetGlobalProperties
#define SDL_GetGlobalProperties() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(void))*(void**)(__base - 2080))());\
	})
#endif

#ifndef SDL_GetGrabbedWindow
#define SDL_GetGrabbedWindow() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(void))*(void**)(__base - 2086))());\
	})
#endif

#ifndef SDL_GetHapticEffectStatus
#define SDL_GetHapticEffectStatus(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		SDL_HapticEffectID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, SDL_HapticEffectID ))*(void**)(__base - 2092))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetHapticFeatures
#define SDL_GetHapticFeatures(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_Haptic *))*(void**)(__base - 2098))(__t__p0));\
	})
#endif

#ifndef SDL_GetHapticFromID
#define SDL_GetHapticFromID(__p0) \
	({ \
		SDL_HapticID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Haptic *(*)(SDL_HapticID ))*(void**)(__base - 2104))(__t__p0));\
	})
#endif

#ifndef SDL_GetHapticID
#define SDL_GetHapticID(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_HapticID (*)(SDL_Haptic *))*(void**)(__base - 2110))(__t__p0));\
	})
#endif

#ifndef SDL_GetHapticName
#define SDL_GetHapticName(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Haptic *))*(void**)(__base - 2116))(__t__p0));\
	})
#endif

#ifndef SDL_GetHapticNameForID
#define SDL_GetHapticNameForID(__p0) \
	({ \
		SDL_HapticID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_HapticID ))*(void**)(__base - 2122))(__t__p0));\
	})
#endif

#ifndef SDL_GetHaptics
#define SDL_GetHaptics(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_HapticID *(*)(int *))*(void**)(__base - 2128))(__t__p0));\
	})
#endif

#ifndef SDL_GetHint
#define SDL_GetHint(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const char *))*(void**)(__base - 2134))(__t__p0));\
	})
#endif

#ifndef SDL_GetHintBoolean
#define SDL_GetHintBoolean(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, bool ))*(void**)(__base - 2140))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetIOProperties
#define SDL_GetIOProperties(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_IOStream *))*(void**)(__base - 2146))(__t__p0));\
	})
#endif

#ifndef SDL_GetIOSize
#define SDL_GetIOSize(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(SDL_IOStream *))*(void**)(__base - 2152))(__t__p0));\
	})
#endif

#ifndef SDL_GetIOStatus
#define SDL_GetIOStatus(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStatus (*)(SDL_IOStream *))*(void**)(__base - 2158))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickAxis
#define SDL_GetJoystickAxis(__p0, __p1) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint16 (*)(SDL_Joystick *, int ))*(void**)(__base - 2164))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetJoystickAxisInitialState
#define SDL_GetJoystickAxisInitialState(__p0, __p1, __p2) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		Sint16 * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , Sint16 *))*(void**)(__base - 2170))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetJoystickBall
#define SDL_GetJoystickBall(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , int *, int *))*(void**)(__base - 2176))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetJoystickButton
#define SDL_GetJoystickButton(__p0, __p1) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int ))*(void**)(__base - 2182))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetJoystickConnectionState
#define SDL_GetJoystickConnectionState(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickConnectionState (*)(SDL_Joystick *))*(void**)(__base - 2188))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickFirmwareVersion
#define SDL_GetJoystickFirmwareVersion(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Joystick *))*(void**)(__base - 2194))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickFromID
#define SDL_GetJoystickFromID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Joystick *(*)(SDL_JoystickID ))*(void**)(__base - 2200))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickFromPlayerIndex
#define SDL_GetJoystickFromPlayerIndex(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Joystick *(*)(int ))*(void**)(__base - 2206))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickGUID
#define SDL_GetJoystickGUID(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GUID (*)(SDL_Joystick *))*(void**)(__base - 2212))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickGUIDForID
#define SDL_GetJoystickGUIDForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GUID (*)(SDL_JoystickID ))*(void**)(__base - 2218))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickGUIDInfo
#define SDL_GetJoystickGUIDInfo(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GUID  __t__p0 = __p0;\
		Uint16 * __t__p1 = __p1;\
		Uint16 * __t__p2 = __p2;\
		Uint16 * __t__p3 = __p3;\
		Uint16 * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GUID , Uint16 *, Uint16 *, Uint16 *, Uint16 *))*(void**)(__base - 2224))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetJoystickHat
#define SDL_GetJoystickHat(__p0, __p1) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint8 (*)(SDL_Joystick *, int ))*(void**)(__base - 2230))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetJoystickID
#define SDL_GetJoystickID(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickID (*)(SDL_Joystick *))*(void**)(__base - 2236))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickName
#define SDL_GetJoystickName(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Joystick *))*(void**)(__base - 2242))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickNameForID
#define SDL_GetJoystickNameForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_JoystickID ))*(void**)(__base - 2248))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickPath
#define SDL_GetJoystickPath(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Joystick *))*(void**)(__base - 2254))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickPathForID
#define SDL_GetJoystickPathForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_JoystickID ))*(void**)(__base - 2260))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickPlayerIndex
#define SDL_GetJoystickPlayerIndex(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Joystick *))*(void**)(__base - 2266))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickPlayerIndexForID
#define SDL_GetJoystickPlayerIndexForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_JoystickID ))*(void**)(__base - 2272))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickPowerInfo
#define SDL_GetJoystickPowerInfo(__p0, __p1) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PowerState (*)(SDL_Joystick *, int *))*(void**)(__base - 2278))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetJoystickProduct
#define SDL_GetJoystickProduct(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Joystick *))*(void**)(__base - 2284))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickProductForID
#define SDL_GetJoystickProductForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 2290))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickProductVersion
#define SDL_GetJoystickProductVersion(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Joystick *))*(void**)(__base - 2296))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickProductVersionForID
#define SDL_GetJoystickProductVersionForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 2302))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickProperties
#define SDL_GetJoystickProperties(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Joystick *))*(void**)(__base - 2308))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickSerial
#define SDL_GetJoystickSerial(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Joystick *))*(void**)(__base - 2314))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickType
#define SDL_GetJoystickType(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickType (*)(SDL_Joystick *))*(void**)(__base - 2320))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickTypeForID
#define SDL_GetJoystickTypeForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickType (*)(SDL_JoystickID ))*(void**)(__base - 2326))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickVendor
#define SDL_GetJoystickVendor(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_Joystick *))*(void**)(__base - 2332))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoystickVendorForID
#define SDL_GetJoystickVendorForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(SDL_JoystickID ))*(void**)(__base - 2338))(__t__p0));\
	})
#endif

#ifndef SDL_GetJoysticks
#define SDL_GetJoysticks(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_JoystickID *(*)(int *))*(void**)(__base - 2344))(__t__p0));\
	})
#endif

#ifndef SDL_GetKeyFromName
#define SDL_GetKeyFromName(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Keycode (*)(const char *))*(void**)(__base - 2350))(__t__p0));\
	})
#endif

#ifndef SDL_GetKeyFromScancode
#define SDL_GetKeyFromScancode(__p0, __p1, __p2) \
	({ \
		SDL_Scancode  __t__p0 = __p0;\
		SDL_Keymod  __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Keycode (*)(SDL_Scancode , SDL_Keymod , bool ))*(void**)(__base - 2356))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetKeyName
#define SDL_GetKeyName(__p0) \
	({ \
		SDL_Keycode  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Keycode ))*(void**)(__base - 2362))(__t__p0));\
	})
#endif

#ifndef SDL_GetKeyboardFocus
#define SDL_GetKeyboardFocus() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(void))*(void**)(__base - 2368))());\
	})
#endif

#ifndef SDL_GetKeyboardNameForID
#define SDL_GetKeyboardNameForID(__p0) \
	({ \
		SDL_KeyboardID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_KeyboardID ))*(void**)(__base - 2374))(__t__p0));\
	})
#endif

#ifndef SDL_GetKeyboardState
#define SDL_GetKeyboardState(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const bool *(*)(int *))*(void**)(__base - 2380))(__t__p0));\
	})
#endif

#ifndef SDL_GetKeyboards
#define SDL_GetKeyboards(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_KeyboardID *(*)(int *))*(void**)(__base - 2386))(__t__p0));\
	})
#endif

#ifndef SDL_GetLogOutputFunction
#define SDL_GetLogOutputFunction(__p0, __p1) \
	({ \
		SDL_LogOutputFunction * __t__p0 = __p0;\
		void ** __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_LogOutputFunction *, void **))*(void**)(__base - 2392))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetLogPriority
#define SDL_GetLogPriority(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_LogPriority (*)(int ))*(void**)(__base - 2398))(__t__p0));\
	})
#endif

#ifndef SDL_GetMasksForPixelFormat
#define SDL_GetMasksForPixelFormat(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_PixelFormat  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		Uint32 * __t__p2 = __p2;\
		Uint32 * __t__p3 = __p3;\
		Uint32 * __t__p4 = __p4;\
		Uint32 * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PixelFormat , int *, Uint32 *, Uint32 *, Uint32 *, Uint32 *))*(void**)(__base - 2404))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_GetMaxHapticEffects
#define SDL_GetMaxHapticEffects(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Haptic *))*(void**)(__base - 2410))(__t__p0));\
	})
#endif

#ifndef SDL_GetMaxHapticEffectsPlaying
#define SDL_GetMaxHapticEffectsPlaying(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Haptic *))*(void**)(__base - 2416))(__t__p0));\
	})
#endif

#ifndef SDL_GetMemoryFunctions
#define SDL_GetMemoryFunctions(__p0, __p1, __p2, __p3) \
	({ \
		SDL_malloc_func * __t__p0 = __p0;\
		SDL_calloc_func * __t__p1 = __p1;\
		SDL_realloc_func * __t__p2 = __p2;\
		SDL_free_func * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_malloc_func *, SDL_calloc_func *, SDL_realloc_func *, SDL_free_func *))*(void**)(__base - 2422))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetMice
#define SDL_GetMice(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_MouseID *(*)(int *))*(void**)(__base - 2428))(__t__p0));\
	})
#endif

#ifndef SDL_GetModState
#define SDL_GetModState() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Keymod (*)(void))*(void**)(__base - 2434))());\
	})
#endif

#ifndef SDL_GetMouseFocus
#define SDL_GetMouseFocus() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(void))*(void**)(__base - 2440))());\
	})
#endif

#ifndef SDL_GetMouseNameForID
#define SDL_GetMouseNameForID(__p0) \
	({ \
		SDL_MouseID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_MouseID ))*(void**)(__base - 2446))(__t__p0));\
	})
#endif

#ifndef SDL_GetMouseState
#define SDL_GetMouseState(__p0, __p1) \
	({ \
		float * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_MouseButtonFlags (*)(float *, float *))*(void**)(__base - 2452))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetNaturalDisplayOrientation
#define SDL_GetNaturalDisplayOrientation(__p0) \
	({ \
		SDL_DisplayID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayOrientation (*)(SDL_DisplayID ))*(void**)(__base - 2458))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumAllocations
#define SDL_GetNumAllocations() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2464))());\
	})
#endif

#ifndef SDL_GetNumAudioDrivers
#define SDL_GetNumAudioDrivers() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2470))());\
	})
#endif

#ifndef SDL_GetNumCameraDrivers
#define SDL_GetNumCameraDrivers() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2476))());\
	})
#endif

#ifndef SDL_GetNumGPUDrivers
#define SDL_GetNumGPUDrivers() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2482))());\
	})
#endif

#ifndef SDL_GetNumGamepadTouchpadFingers
#define SDL_GetNumGamepadTouchpadFingers(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Gamepad *, int ))*(void**)(__base - 2488))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetNumGamepadTouchpads
#define SDL_GetNumGamepadTouchpads(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Gamepad *))*(void**)(__base - 2494))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumHapticAxes
#define SDL_GetNumHapticAxes(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Haptic *))*(void**)(__base - 2500))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumJoystickAxes
#define SDL_GetNumJoystickAxes(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Joystick *))*(void**)(__base - 2506))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumJoystickBalls
#define SDL_GetNumJoystickBalls(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Joystick *))*(void**)(__base - 2512))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumJoystickButtons
#define SDL_GetNumJoystickButtons(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Joystick *))*(void**)(__base - 2518))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumJoystickHats
#define SDL_GetNumJoystickHats(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Joystick *))*(void**)(__base - 2524))(__t__p0));\
	})
#endif

#ifndef SDL_GetNumLogicalCPUCores
#define SDL_GetNumLogicalCPUCores() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2530))());\
	})
#endif

#ifndef SDL_GetNumRenderDrivers
#define SDL_GetNumRenderDrivers() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2536))());\
	})
#endif

#ifndef SDL_GetNumVideoDrivers
#define SDL_GetNumVideoDrivers() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 2542))());\
	})
#endif

#ifndef SDL_GetNumberProperty
#define SDL_GetNumberProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Sint64  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(SDL_PropertiesID , const char *, Sint64 ))*(void**)(__base - 2548))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetOriginalMemoryFunctions
#define SDL_GetOriginalMemoryFunctions(__p0, __p1, __p2, __p3) \
	({ \
		SDL_malloc_func * __t__p0 = __p0;\
		SDL_calloc_func * __t__p1 = __p1;\
		SDL_realloc_func * __t__p2 = __p2;\
		SDL_free_func * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_malloc_func *, SDL_calloc_func *, SDL_realloc_func *, SDL_free_func *))*(void**)(__base - 2554))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetPathInfo
#define SDL_GetPathInfo(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_PathInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, SDL_PathInfo *))*(void**)(__base - 2560))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetPerformanceCounter
#define SDL_GetPerformanceCounter() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(void))*(void**)(__base - 2566))());\
	})
#endif

#ifndef SDL_GetPerformanceFrequency
#define SDL_GetPerformanceFrequency() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(void))*(void**)(__base - 2572))());\
	})
#endif

#ifndef SDL_GetPixelFormatDetails
#define SDL_GetPixelFormatDetails(__p0) \
	({ \
		SDL_PixelFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_PixelFormatDetails *(*)(SDL_PixelFormat ))*(void**)(__base - 2578))(__t__p0));\
	})
#endif

#ifndef SDL_GetPixelFormatForMasks
#define SDL_GetPixelFormatForMasks(__p0, __p1, __p2, __p3, __p4) \
	({ \
		int  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		Uint32  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PixelFormat (*)(int , Uint32 , Uint32 , Uint32 , Uint32 ))*(void**)(__base - 2584))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetPixelFormatName
#define SDL_GetPixelFormatName(__p0) \
	({ \
		SDL_PixelFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_PixelFormat ))*(void**)(__base - 2590))(__t__p0));\
	})
#endif

#ifndef SDL_GetPlatform
#define SDL_GetPlatform() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 2596))());\
	})
#endif

#ifndef SDL_GetPointerProperty
#define SDL_GetPointerProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_PropertiesID , const char *, void *))*(void**)(__base - 2602))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetPowerInfo
#define SDL_GetPowerInfo(__p0, __p1) \
	({ \
		int * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PowerState (*)(int *, int *))*(void**)(__base - 2608))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetPrefPath
#define SDL_GetPrefPath(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *))*(void**)(__base - 2614))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetPreferredLocales
#define SDL_GetPreferredLocales(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Locale **(*)(int *))*(void**)(__base - 2620))(__t__p0));\
	})
#endif

#ifndef SDL_GetPrimaryDisplay
#define SDL_GetPrimaryDisplay() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_DisplayID (*)(void))*(void**)(__base - 2626))());\
	})
#endif

#ifndef SDL_GetPrimarySelectionText
#define SDL_GetPrimarySelectionText() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(void))*(void**)(__base - 2632))());\
	})
#endif

#ifndef SDL_GetProcessInput
#define SDL_GetProcessInput(__p0) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(SDL_Process *))*(void**)(__base - 2638))(__t__p0));\
	})
#endif

#ifndef SDL_GetProcessOutput
#define SDL_GetProcessOutput(__p0) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(SDL_Process *))*(void**)(__base - 2644))(__t__p0));\
	})
#endif

#ifndef SDL_GetProcessProperties
#define SDL_GetProcessProperties(__p0) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Process *))*(void**)(__base - 2650))(__t__p0));\
	})
#endif

#ifndef SDL_GetPropertyType
#define SDL_GetPropertyType(__p0, __p1) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertyType (*)(SDL_PropertiesID , const char *))*(void**)(__base - 2656))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRGB
#define SDL_GetRGB(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		Uint32  __t__p0 = __p0;\
		const SDL_PixelFormatDetails * __t__p1 = __p1;\
		const SDL_Palette * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		Uint8 * __t__p4 = __p4;\
		Uint8 * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 , const SDL_PixelFormatDetails *, const SDL_Palette *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 2662))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_GetRGBA
#define SDL_GetRGBA(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		Uint32  __t__p0 = __p0;\
		const SDL_PixelFormatDetails * __t__p1 = __p1;\
		const SDL_Palette * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		Uint8 * __t__p4 = __p4;\
		Uint8 * __t__p5 = __p5;\
		Uint8 * __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 , const SDL_PixelFormatDetails *, const SDL_Palette *, Uint8 *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 2668))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_GetRealGamepadType
#define SDL_GetRealGamepadType(__p0) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadType (*)(SDL_Gamepad *))*(void**)(__base - 2674))(__t__p0));\
	})
#endif

#ifndef SDL_GetRealGamepadTypeForID
#define SDL_GetRealGamepadTypeForID(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GamepadType (*)(SDL_JoystickID ))*(void**)(__base - 2680))(__t__p0));\
	})
#endif

#ifndef SDL_GetRectAndLineIntersection
#define SDL_GetRectAndLineIntersection(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const SDL_Rect * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_Rect *, int *, int *, int *, int *))*(void**)(__base - 2686))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetRectAndLineIntersectionFloat
#define SDL_GetRectAndLineIntersectionFloat(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const SDL_FRect * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_FRect *, float *, float *, float *, float *))*(void**)(__base - 2692))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetRectEnclosingPoints
#define SDL_GetRectEnclosingPoints(__p0, __p1, __p2, __p3) \
	({ \
		const SDL_Point * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const SDL_Rect * __t__p2 = __p2;\
		SDL_Rect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_Point *, int , const SDL_Rect *, SDL_Rect *))*(void**)(__base - 2698))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetRectEnclosingPointsFloat
#define SDL_GetRectEnclosingPointsFloat(__p0, __p1, __p2, __p3) \
	({ \
		const SDL_FPoint * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		SDL_FRect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_FPoint *, int , const SDL_FRect *, SDL_FRect *))*(void**)(__base - 2704))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetRectIntersection
#define SDL_GetRectIntersection(__p0, __p1, __p2) \
	({ \
		const SDL_Rect * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Rect * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_Rect *, const SDL_Rect *, SDL_Rect *))*(void**)(__base - 2710))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRectIntersectionFloat
#define SDL_GetRectIntersectionFloat(__p0, __p1, __p2) \
	({ \
		const SDL_FRect * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		SDL_FRect * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_FRect *, const SDL_FRect *, SDL_FRect *))*(void**)(__base - 2716))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRectUnion
#define SDL_GetRectUnion(__p0, __p1, __p2) \
	({ \
		const SDL_Rect * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Rect * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_Rect *, const SDL_Rect *, SDL_Rect *))*(void**)(__base - 2722))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRectUnionFloat
#define SDL_GetRectUnionFloat(__p0, __p1, __p2) \
	({ \
		const SDL_FRect * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		SDL_FRect * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_FRect *, const SDL_FRect *, SDL_FRect *))*(void**)(__base - 2728))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRelativeMouseState
#define SDL_GetRelativeMouseState(__p0, __p1) \
	({ \
		float * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_MouseButtonFlags (*)(float *, float *))*(void**)(__base - 2734))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderClipRect
#define SDL_GetRenderClipRect(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Rect *))*(void**)(__base - 2740))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderColorScale
#define SDL_GetRenderColorScale(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float *))*(void**)(__base - 2746))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderDrawBlendMode
#define SDL_GetRenderDrawBlendMode(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_BlendMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_BlendMode *))*(void**)(__base - 2752))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderDrawColor
#define SDL_GetRenderDrawColor(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		Uint8 * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		Uint8 * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, Uint8 *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 2758))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetRenderDrawColorFloat
#define SDL_GetRenderDrawColorFloat(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float *, float *, float *, float *))*(void**)(__base - 2764))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetRenderDriver
#define SDL_GetRenderDriver(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 2770))(__t__p0));\
	})
#endif

#ifndef SDL_GetRenderLogicalPresentation
#define SDL_GetRenderLogicalPresentation(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		SDL_RendererLogicalPresentation * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int *, int *, SDL_RendererLogicalPresentation *))*(void**)(__base - 2776))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetRenderLogicalPresentationRect
#define SDL_GetRenderLogicalPresentationRect(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_FRect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_FRect *))*(void**)(__base - 2782))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderMetalCommandEncoder
#define SDL_GetRenderMetalCommandEncoder(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_Renderer *))*(void**)(__base - 2788))(__t__p0));\
	})
#endif

#ifndef SDL_GetRenderMetalLayer
#define SDL_GetRenderMetalLayer(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_Renderer *))*(void**)(__base - 2794))(__t__p0));\
	})
#endif

#ifndef SDL_GetRenderOutputSize
#define SDL_GetRenderOutputSize(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int *, int *))*(void**)(__base - 2800))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRenderSafeArea
#define SDL_GetRenderSafeArea(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Rect *))*(void**)(__base - 2806))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderScale
#define SDL_GetRenderScale(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float *, float *))*(void**)(__base - 2812))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRenderTarget
#define SDL_GetRenderTarget(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *))*(void**)(__base - 2818))(__t__p0));\
	})
#endif

#ifndef SDL_GetRenderVSync
#define SDL_GetRenderVSync(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int *))*(void**)(__base - 2824))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderViewport
#define SDL_GetRenderViewport(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Rect *))*(void**)(__base - 2830))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetRenderWindow
#define SDL_GetRenderWindow(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(SDL_Renderer *))*(void**)(__base - 2836))(__t__p0));\
	})
#endif

#ifndef SDL_GetRenderer
#define SDL_GetRenderer(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_Window *))*(void**)(__base - 2842))(__t__p0));\
	})
#endif

#ifndef SDL_GetRendererFromTexture
#define SDL_GetRendererFromTexture(__p0) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_Texture *))*(void**)(__base - 2848))(__t__p0));\
	})
#endif

#ifndef SDL_GetRendererName
#define SDL_GetRendererName(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Renderer *))*(void**)(__base - 2854))(__t__p0));\
	})
#endif

#ifndef SDL_GetRendererProperties
#define SDL_GetRendererProperties(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Renderer *))*(void**)(__base - 2860))(__t__p0));\
	})
#endif

#ifndef SDL_GetRevision
#define SDL_GetRevision() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 2866))());\
	})
#endif

#ifndef SDL_GetSIMDAlignment
#define SDL_GetSIMDAlignment() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(void))*(void**)(__base - 2872))());\
	})
#endif

#ifndef SDL_GetScancodeFromKey
#define SDL_GetScancodeFromKey(__p0, __p1) \
	({ \
		SDL_Keycode  __t__p0 = __p0;\
		SDL_Keymod * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Scancode (*)(SDL_Keycode , SDL_Keymod *))*(void**)(__base - 2878))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetScancodeFromName
#define SDL_GetScancodeFromName(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Scancode (*)(const char *))*(void**)(__base - 2884))(__t__p0));\
	})
#endif

#ifndef SDL_GetScancodeName
#define SDL_GetScancodeName(__p0) \
	({ \
		SDL_Scancode  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Scancode ))*(void**)(__base - 2890))(__t__p0));\
	})
#endif

#ifndef SDL_GetSemaphoreValue
#define SDL_GetSemaphoreValue(__p0) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_Semaphore *))*(void**)(__base - 2896))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorData
#define SDL_GetSensorData(__p0, __p1, __p2) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Sensor *, float *, int ))*(void**)(__base - 2902))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetSensorFromID
#define SDL_GetSensorFromID(__p0) \
	({ \
		SDL_SensorID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Sensor *(*)(SDL_SensorID ))*(void**)(__base - 2908))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorID
#define SDL_GetSensorID(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_SensorID (*)(SDL_Sensor *))*(void**)(__base - 2914))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorName
#define SDL_GetSensorName(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Sensor *))*(void**)(__base - 2920))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorNameForID
#define SDL_GetSensorNameForID(__p0) \
	({ \
		SDL_SensorID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_SensorID ))*(void**)(__base - 2926))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorNonPortableType
#define SDL_GetSensorNonPortableType(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Sensor *))*(void**)(__base - 2932))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorNonPortableTypeForID
#define SDL_GetSensorNonPortableTypeForID(__p0) \
	({ \
		SDL_SensorID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_SensorID ))*(void**)(__base - 2938))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorProperties
#define SDL_GetSensorProperties(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Sensor *))*(void**)(__base - 2944))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorType
#define SDL_GetSensorType(__p0) \
	({ \
		SDL_Sensor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_SensorType (*)(SDL_Sensor *))*(void**)(__base - 2950))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensorTypeForID
#define SDL_GetSensorTypeForID(__p0) \
	({ \
		SDL_SensorID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_SensorType (*)(SDL_SensorID ))*(void**)(__base - 2956))(__t__p0));\
	})
#endif

#ifndef SDL_GetSensors
#define SDL_GetSensors(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_SensorID *(*)(int *))*(void**)(__base - 2962))(__t__p0));\
	})
#endif

#ifndef SDL_GetSilenceValueForFormat
#define SDL_GetSilenceValueForFormat(__p0) \
	({ \
		SDL_AudioFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AudioFormat ))*(void**)(__base - 2968))(__t__p0));\
	})
#endif

#ifndef SDL_GetStorageFileSize
#define SDL_GetStorageFileSize(__p0, __p1, __p2) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Uint64 * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, Uint64 *))*(void**)(__base - 2974))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetStoragePathInfo
#define SDL_GetStoragePathInfo(__p0, __p1, __p2) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_PathInfo * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, SDL_PathInfo *))*(void**)(__base - 2980))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetStorageSpaceRemaining
#define SDL_GetStorageSpaceRemaining(__p0) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(SDL_Storage *))*(void**)(__base - 2986))(__t__p0));\
	})
#endif

#ifndef SDL_GetStringProperty
#define SDL_GetStringProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_PropertiesID , const char *, const char *))*(void**)(__base - 2992))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetSurfaceAlphaMod
#define SDL_GetSurfaceAlphaMod(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, Uint8 *))*(void**)(__base - 2998))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSurfaceBlendMode
#define SDL_GetSurfaceBlendMode(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_BlendMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_BlendMode *))*(void**)(__base - 3004))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSurfaceClipRect
#define SDL_GetSurfaceClipRect(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_Rect *))*(void**)(__base - 3010))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSurfaceColorKey
#define SDL_GetSurfaceColorKey(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint32 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, Uint32 *))*(void**)(__base - 3016))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSurfaceColorMod
#define SDL_GetSurfaceColorMod(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		Uint8 * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 3022))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetSurfaceColorspace
#define SDL_GetSurfaceColorspace(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Colorspace (*)(SDL_Surface *))*(void**)(__base - 3028))(__t__p0));\
	})
#endif

#ifndef SDL_GetSurfaceImages
#define SDL_GetSurfaceImages(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface **(*)(SDL_Surface *, int *))*(void**)(__base - 3034))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSurfacePalette
#define SDL_GetSurfacePalette(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Palette *(*)(SDL_Surface *))*(void**)(__base - 3040))(__t__p0));\
	})
#endif

#ifndef SDL_GetSurfaceProperties
#define SDL_GetSurfaceProperties(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Surface *))*(void**)(__base - 3046))(__t__p0));\
	})
#endif

#ifndef SDL_GetSystemRAM
#define SDL_GetSystemRAM() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 3052))());\
	})
#endif

#ifndef SDL_GetSystemTheme
#define SDL_GetSystemTheme() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_SystemTheme (*)(void))*(void**)(__base - 3058))());\
	})
#endif

#ifndef SDL_GetTLS
#define SDL_GetTLS(__p0) \
	({ \
		SDL_TLSID * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_TLSID *))*(void**)(__base - 3064))(__t__p0));\
	})
#endif

#ifndef SDL_GetTextInputArea
#define SDL_GetTextInputArea(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_Rect *, int *))*(void**)(__base - 3070))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetTextureAlphaMod
#define SDL_GetTextureAlphaMod(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, Uint8 *))*(void**)(__base - 3076))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTextureAlphaModFloat
#define SDL_GetTextureAlphaModFloat(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, float *))*(void**)(__base - 3082))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTextureBlendMode
#define SDL_GetTextureBlendMode(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		SDL_BlendMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, SDL_BlendMode *))*(void**)(__base - 3088))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTextureColorMod
#define SDL_GetTextureColorMod(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		Uint8 * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 3094))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetTextureColorModFloat
#define SDL_GetTextureColorModFloat(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, float *, float *, float *))*(void**)(__base - 3100))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetTextureProperties
#define SDL_GetTextureProperties(__p0) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Texture *))*(void**)(__base - 3106))(__t__p0));\
	})
#endif

#ifndef SDL_GetTextureScaleMode
#define SDL_GetTextureScaleMode(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		SDL_ScaleMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, SDL_ScaleMode *))*(void**)(__base - 3112))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTextureSize
#define SDL_GetTextureSize(__p0, __p1, __p2) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, float *, float *))*(void**)(__base - 3118))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetThreadID
#define SDL_GetThreadID(__p0) \
	({ \
		SDL_Thread * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_ThreadID (*)(SDL_Thread *))*(void**)(__base - 3124))(__t__p0));\
	})
#endif

#ifndef SDL_GetThreadName
#define SDL_GetThreadName(__p0) \
	({ \
		SDL_Thread * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Thread *))*(void**)(__base - 3130))(__t__p0));\
	})
#endif

#ifndef SDL_GetTicks
#define SDL_GetTicks() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(void))*(void**)(__base - 3136))());\
	})
#endif

#ifndef SDL_GetTicksNS
#define SDL_GetTicksNS() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint64 (*)(void))*(void**)(__base - 3142))());\
	})
#endif

#ifndef SDL_GetTouchDeviceName
#define SDL_GetTouchDeviceName(__p0) \
	({ \
		SDL_TouchID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_TouchID ))*(void**)(__base - 3148))(__t__p0));\
	})
#endif

#ifndef SDL_GetTouchDeviceType
#define SDL_GetTouchDeviceType(__p0) \
	({ \
		SDL_TouchID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TouchDeviceType (*)(SDL_TouchID ))*(void**)(__base - 3154))(__t__p0));\
	})
#endif

#ifndef SDL_GetTouchDevices
#define SDL_GetTouchDevices(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TouchID *(*)(int *))*(void**)(__base - 3160))(__t__p0));\
	})
#endif

#ifndef SDL_GetTouchFingers
#define SDL_GetTouchFingers(__p0, __p1) \
	({ \
		SDL_TouchID  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Finger **(*)(SDL_TouchID , int *))*(void**)(__base - 3166))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetUserFolder
#define SDL_GetUserFolder(__p0) \
	({ \
		SDL_Folder  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Folder ))*(void**)(__base - 3172))(__t__p0));\
	})
#endif

#ifndef SDL_GetVersion
#define SDL_GetVersion() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 3178))());\
	})
#endif

#ifndef SDL_GetVideoDriver
#define SDL_GetVideoDriver(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 3184))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowAspectRatio
#define SDL_GetWindowAspectRatio(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, float *, float *))*(void**)(__base - 3190))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowBordersSize
#define SDL_GetWindowBordersSize(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *, int *, int *))*(void**)(__base - 3196))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_GetWindowDisplayScale
#define SDL_GetWindowDisplayScale(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_Window *))*(void**)(__base - 3202))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowFlags
#define SDL_GetWindowFlags(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_WindowFlags (*)(SDL_Window *))*(void**)(__base - 3208))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowFromEvent
#define SDL_GetWindowFromEvent(__p0) \
	({ \
		const SDL_Event * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(const SDL_Event *))*(void**)(__base - 3214))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowFromID
#define SDL_GetWindowFromID(__p0) \
	({ \
		SDL_WindowID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(SDL_WindowID ))*(void**)(__base - 3220))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowFullscreenMode
#define SDL_GetWindowFullscreenMode(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_DisplayMode *(*)(SDL_Window *))*(void**)(__base - 3226))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowICCProfile
#define SDL_GetWindowICCProfile(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_Window *, size_t *))*(void**)(__base - 3232))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetWindowID
#define SDL_GetWindowID(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_WindowID (*)(SDL_Window *))*(void**)(__base - 3238))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowKeyboardGrab
#define SDL_GetWindowKeyboardGrab(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3244))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowMaximumSize
#define SDL_GetWindowMaximumSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *))*(void**)(__base - 3250))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowMinimumSize
#define SDL_GetWindowMinimumSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *))*(void**)(__base - 3256))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowMouseGrab
#define SDL_GetWindowMouseGrab(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3262))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowMouseRect
#define SDL_GetWindowMouseRect(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_Rect *(*)(SDL_Window *))*(void**)(__base - 3268))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowOpacity
#define SDL_GetWindowOpacity(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_Window *))*(void**)(__base - 3274))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowParent
#define SDL_GetWindowParent(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window *(*)(SDL_Window *))*(void**)(__base - 3280))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowPixelDensity
#define SDL_GetWindowPixelDensity(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_Window *))*(void**)(__base - 3286))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowPixelFormat
#define SDL_GetWindowPixelFormat(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PixelFormat (*)(SDL_Window *))*(void**)(__base - 3292))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowPosition
#define SDL_GetWindowPosition(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *))*(void**)(__base - 3298))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowProperties
#define SDL_GetWindowProperties(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_Window *))*(void**)(__base - 3304))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowRelativeMouseMode
#define SDL_GetWindowRelativeMouseMode(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3310))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowSafeArea
#define SDL_GetWindowSafeArea(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_Rect *))*(void**)(__base - 3316))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetWindowSize
#define SDL_GetWindowSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *))*(void**)(__base - 3322))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowSizeInPixels
#define SDL_GetWindowSizeInPixels(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *, int *))*(void**)(__base - 3328))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetWindowSurface
#define SDL_GetWindowSurface(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Window *))*(void**)(__base - 3334))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowSurfaceVSync
#define SDL_GetWindowSurfaceVSync(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int *))*(void**)(__base - 3340))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetWindowTitle
#define SDL_GetWindowTitle(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_Window *))*(void**)(__base - 3346))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindows
#define SDL_GetWindows(__p0) \
	({ \
		int * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Window **(*)(int *))*(void**)(__base - 3352))(__t__p0));\
	})
#endif

#ifndef SDL_GlobDirectory
#define SDL_GlobDirectory(__p0, __p1, __p2, __p3) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_GlobFlags  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(const char *, const char *, SDL_GlobFlags , int *))*(void**)(__base - 3358))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GlobStorageDirectory
#define SDL_GlobStorageDirectory(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		SDL_GlobFlags  __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char **(*)(SDL_Storage *, const char *, const char *, SDL_GlobFlags , int *))*(void**)(__base - 3364))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_HapticEffectSupported
#define SDL_HapticEffectSupported(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		const SDL_HapticEffect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, const SDL_HapticEffect *))*(void**)(__base - 3370))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_HapticRumbleSupported
#define SDL_HapticRumbleSupported(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 3376))(__t__p0));\
	})
#endif

#ifndef SDL_HasARMSIMD
#define SDL_HasARMSIMD() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3382))());\
	})
#endif

#ifndef SDL_HasAVX
#define SDL_HasAVX() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3388))());\
	})
#endif

#ifndef SDL_HasAVX2
#define SDL_HasAVX2() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3394))());\
	})
#endif

#ifndef SDL_HasAVX512F
#define SDL_HasAVX512F() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3400))());\
	})
#endif

#ifndef SDL_HasAltiVec
#define SDL_HasAltiVec() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3406))());\
	})
#endif

#ifndef SDL_HasClipboardData
#define SDL_HasClipboardData(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 3412))(__t__p0));\
	})
#endif

#ifndef SDL_HasClipboardText
#define SDL_HasClipboardText() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3418))());\
	})
#endif

#ifndef SDL_HasEvent
#define SDL_HasEvent(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(Uint32 ))*(void**)(__base - 3424))(__t__p0));\
	})
#endif

#ifndef SDL_HasEvents
#define SDL_HasEvents(__p0, __p1) \
	({ \
		Uint32  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(Uint32 , Uint32 ))*(void**)(__base - 3430))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_HasGamepad
#define SDL_HasGamepad() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3436))());\
	})
#endif

#ifndef SDL_HasJoystick
#define SDL_HasJoystick() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3442))());\
	})
#endif

#ifndef SDL_HasKeyboard
#define SDL_HasKeyboard() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3448))());\
	})
#endif

#ifndef SDL_HasLASX
#define SDL_HasLASX() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3454))());\
	})
#endif

#ifndef SDL_HasLSX
#define SDL_HasLSX() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3460))());\
	})
#endif

#ifndef SDL_HasMMX
#define SDL_HasMMX() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3466))());\
	})
#endif

#ifndef SDL_HasMouse
#define SDL_HasMouse() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3472))());\
	})
#endif

#ifndef SDL_HasNEON
#define SDL_HasNEON() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3478))());\
	})
#endif

#ifndef SDL_HasPrimarySelectionText
#define SDL_HasPrimarySelectionText() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3484))());\
	})
#endif

#ifndef SDL_HasProperty
#define SDL_HasProperty(__p0, __p1) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *))*(void**)(__base - 3490))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_HasRectIntersection
#define SDL_HasRectIntersection(__p0, __p1) \
	({ \
		const SDL_Rect * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_Rect *, const SDL_Rect *))*(void**)(__base - 3496))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_HasRectIntersectionFloat
#define SDL_HasRectIntersectionFloat(__p0, __p1) \
	({ \
		const SDL_FRect * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_FRect *, const SDL_FRect *))*(void**)(__base - 3502))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_HasSSE
#define SDL_HasSSE() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3508))());\
	})
#endif

#ifndef SDL_HasSSE2
#define SDL_HasSSE2() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3514))());\
	})
#endif

#ifndef SDL_HasSSE3
#define SDL_HasSSE3() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3520))());\
	})
#endif

#ifndef SDL_HasSSE41
#define SDL_HasSSE41() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3526))());\
	})
#endif

#ifndef SDL_HasSSE42
#define SDL_HasSSE42() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3532))());\
	})
#endif

#ifndef SDL_HasScreenKeyboardSupport
#define SDL_HasScreenKeyboardSupport() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3538))());\
	})
#endif

#ifndef SDL_HideCursor
#define SDL_HideCursor() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3544))());\
	})
#endif

#ifndef SDL_HideWindow
#define SDL_HideWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3550))(__t__p0));\
	})
#endif

#ifndef SDL_IOFromConstMem
#define SDL_IOFromConstMem(__p0, __p1) \
	({ \
		const void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(const void *, size_t ))*(void**)(__base - 3556))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_IOFromDynamicMem
#define SDL_IOFromDynamicMem() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(void))*(void**)(__base - 3562))());\
	})
#endif

#ifndef SDL_IOFromFile
#define SDL_IOFromFile(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(const char *, const char *))*(void**)(__base - 3568))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_IOFromMem
#define SDL_IOFromMem(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(void *, size_t ))*(void**)(__base - 3574))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_IOvprintf
#define SDL_IOvprintf(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		va_list __t__p2;\
		va_copy(__t__p2, __p2);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(SDL_IOStream *, const char *, va_list ))*(void**)(__base - 3580))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_Init
#define SDL_Init(__p0) \
	({ \
		SDL_InitFlags  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_InitFlags ))*(void**)(__base - 3586))(__t__p0));\
	})
#endif

#ifndef SDL_InitHapticRumble
#define SDL_InitHapticRumble(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 3592))(__t__p0));\
	})
#endif

#ifndef SDL_InitSubSystem
#define SDL_InitSubSystem(__p0) \
	({ \
		SDL_InitFlags  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_InitFlags ))*(void**)(__base - 3598))(__t__p0));\
	})
#endif

#ifndef SDL_InsertGPUDebugLabel
#define SDL_InsertGPUDebugLabel(__p0, __p1) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, const char *))*(void**)(__base - 3604))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_IsGamepad
#define SDL_IsGamepad(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_JoystickID ))*(void**)(__base - 3622))(__t__p0));\
	})
#endif

#ifndef SDL_IsJoystickHaptic
#define SDL_IsJoystickHaptic(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *))*(void**)(__base - 3628))(__t__p0));\
	})
#endif

#ifndef SDL_IsJoystickVirtual
#define SDL_IsJoystickVirtual(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_JoystickID ))*(void**)(__base - 3634))(__t__p0));\
	})
#endif

#ifndef SDL_IsMouseHaptic
#define SDL_IsMouseHaptic() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3640))());\
	})
#endif

#ifndef SDL_IsTV
#define SDL_IsTV() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3646))());\
	})
#endif

#ifndef SDL_IsTablet
#define SDL_IsTablet() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3652))());\
	})
#endif

#ifndef SDL_JoystickConnected
#define SDL_JoystickConnected(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *))*(void**)(__base - 3658))(__t__p0));\
	})
#endif

#ifndef SDL_JoystickEventsEnabled
#define SDL_JoystickEventsEnabled() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 3664))());\
	})
#endif

#ifndef SDL_KillProcess
#define SDL_KillProcess(__p0, __p1) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Process *, bool ))*(void**)(__base - 3670))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadBMP
#define SDL_LoadBMP(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(const char *))*(void**)(__base - 3676))(__t__p0));\
	})
#endif

#ifndef SDL_LoadBMP_IO
#define SDL_LoadBMP_IO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, bool ))*(void**)(__base - 3682))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadFile
#define SDL_LoadFile(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(const char *, size_t *))*(void**)(__base - 3688))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadFile_IO
#define SDL_LoadFile_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_IOStream *, size_t *, bool ))*(void**)(__base - 3694))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_LoadWAV
#define SDL_LoadWAV(__p0, __p1, __p2, __p3) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		Uint8 ** __t__p2 = __p2;\
		Uint32 * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, SDL_AudioSpec *, Uint8 **, Uint32 *))*(void**)(__base - 3712))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_LoadWAV_IO
#define SDL_LoadWAV_IO(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		SDL_AudioSpec * __t__p2 = __p2;\
		Uint8 ** __t__p3 = __p3;\
		Uint32 * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, bool , SDL_AudioSpec *, Uint8 **, Uint32 *))*(void**)(__base - 3718))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_LockAudioStream
#define SDL_LockAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 3724))(__t__p0));\
	})
#endif

#ifndef SDL_LockJoysticks
#define SDL_LockJoysticks() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3730))());\
	})
#endif

#ifndef SDL_LockMutex
#define SDL_LockMutex(__p0) \
	({ \
		SDL_Mutex * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Mutex *))*(void**)(__base - 3736))(__t__p0));\
	})
#endif

#ifndef SDL_LockProperties
#define SDL_LockProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID ))*(void**)(__base - 3742))(__t__p0));\
	})
#endif

#ifndef SDL_LockRWLockForReading
#define SDL_LockRWLockForReading(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_RWLock *))*(void**)(__base - 3748))(__t__p0));\
	})
#endif

#ifndef SDL_LockRWLockForWriting
#define SDL_LockRWLockForWriting(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_RWLock *))*(void**)(__base - 3754))(__t__p0));\
	})
#endif

#ifndef SDL_LockSpinlock
#define SDL_LockSpinlock(__p0) \
	({ \
		SDL_SpinLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_SpinLock *))*(void**)(__base - 3760))(__t__p0));\
	})
#endif

#ifndef SDL_LockSurface
#define SDL_LockSurface(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *))*(void**)(__base - 3766))(__t__p0));\
	})
#endif

#ifndef SDL_LockTexture
#define SDL_LockTexture(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		void ** __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, const SDL_Rect *, void **, int *))*(void**)(__base - 3772))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_LockTextureToSurface
#define SDL_LockTextureToSurface(__p0, __p1, __p2) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface ** __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, const SDL_Rect *, SDL_Surface **))*(void**)(__base - 3778))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_LogMessageV
#define SDL_LogMessageV(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		SDL_LogPriority  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		va_list __t__p3;\
		va_copy(__t__p3, __p3);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , SDL_LogPriority , const char *, va_list ))*(void**)(__base - 3784))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_MapGPUTransferBuffer
#define SDL_MapGPUTransferBuffer(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTransferBuffer * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_GPUDevice *, SDL_GPUTransferBuffer *, bool ))*(void**)(__base - 3790))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_MapRGB
#define SDL_MapRGB(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const SDL_PixelFormatDetails * __t__p0 = __p0;\
		const SDL_Palette * __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const SDL_PixelFormatDetails *, const SDL_Palette *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 3796))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_MapRGBA
#define SDL_MapRGBA(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const SDL_PixelFormatDetails * __t__p0 = __p0;\
		const SDL_Palette * __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		Uint8  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const SDL_PixelFormatDetails *, const SDL_Palette *, Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)(__base - 3802))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_MapSurfaceRGB
#define SDL_MapSurfaceRGB(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_Surface *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 3808))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_MapSurfaceRGBA
#define SDL_MapSurfaceRGBA(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_Surface *, Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)(__base - 3814))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_MaximizeWindow
#define SDL_MaximizeWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3820))(__t__p0));\
	})
#endif

#ifndef SDL_MemoryBarrierAcquireFunction
#define SDL_MemoryBarrierAcquireFunction() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3826))());\
	})
#endif

#ifndef SDL_MemoryBarrierReleaseFunction
#define SDL_MemoryBarrierReleaseFunction() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3832))());\
	})
#endif

#ifndef SDL_Metal_CreateView
#define SDL_Metal_CreateView(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_MetalView (*)(SDL_Window *))*(void**)(__base - 3838))(__t__p0));\
	})
#endif

#ifndef SDL_Metal_DestroyView
#define SDL_Metal_DestroyView(__p0) \
	({ \
		SDL_MetalView  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_MetalView ))*(void**)(__base - 3844))(__t__p0));\
	})
#endif

#ifndef SDL_Metal_GetLayer
#define SDL_Metal_GetLayer(__p0) \
	({ \
		SDL_MetalView  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_MetalView ))*(void**)(__base - 3850))(__t__p0));\
	})
#endif

#ifndef SDL_MinimizeWindow
#define SDL_MinimizeWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 3856))(__t__p0));\
	})
#endif

#ifndef SDL_MixAudio
#define SDL_MixAudio(__p0, __p1, __p2, __p3, __p4) \
	({ \
		Uint8 * __t__p0 = __p0;\
		const Uint8 * __t__p1 = __p1;\
		SDL_AudioFormat  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(Uint8 *, const Uint8 *, SDL_AudioFormat , Uint32 , float ))*(void**)(__base - 3862))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_OnApplicationDidChangeStatusBarOrientation
#define SDL_OnApplicationDidChangeStatusBarOrientation() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3868))());\
	})
#endif

#ifndef SDL_OnApplicationDidEnterBackground
#define SDL_OnApplicationDidEnterBackground() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3874))());\
	})
#endif

#ifndef SDL_OnApplicationDidEnterForeground
#define SDL_OnApplicationDidEnterForeground() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3880))());\
	})
#endif

#ifndef SDL_OnApplicationDidReceiveMemoryWarning
#define SDL_OnApplicationDidReceiveMemoryWarning() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3886))());\
	})
#endif

#ifndef SDL_OnApplicationWillEnterBackground
#define SDL_OnApplicationWillEnterBackground() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3892))());\
	})
#endif

#ifndef SDL_OnApplicationWillEnterForeground
#define SDL_OnApplicationWillEnterForeground() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3898))());\
	})
#endif

#ifndef SDL_OnApplicationWillTerminate
#define SDL_OnApplicationWillTerminate() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 3904))());\
	})
#endif

#ifndef SDL_OpenAudioDevice
#define SDL_OpenAudioDevice(__p0, __p1) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		const SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioDeviceID (*)(SDL_AudioDeviceID , const SDL_AudioSpec *))*(void**)(__base - 3910))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_OpenAudioDeviceStream
#define SDL_OpenAudioDeviceStream(__p0, __p1, __p2, __p3) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		const SDL_AudioSpec * __t__p1 = __p1;\
		SDL_AudioStreamCallback  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AudioStream *(*)(SDL_AudioDeviceID , const SDL_AudioSpec *, SDL_AudioStreamCallback , void *))*(void**)(__base - 3916))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_OpenCamera
#define SDL_OpenCamera(__p0, __p1) \
	({ \
		SDL_CameraID  __t__p0 = __p0;\
		const SDL_CameraSpec * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Camera *(*)(SDL_CameraID , const SDL_CameraSpec *))*(void**)(__base - 3922))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_OpenFileStorage
#define SDL_OpenFileStorage(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Storage *(*)(const char *))*(void**)(__base - 3928))(__t__p0));\
	})
#endif

#ifndef SDL_OpenGamepad
#define SDL_OpenGamepad(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Gamepad *(*)(SDL_JoystickID ))*(void**)(__base - 3934))(__t__p0));\
	})
#endif

#ifndef SDL_OpenHaptic
#define SDL_OpenHaptic(__p0) \
	({ \
		SDL_HapticID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Haptic *(*)(SDL_HapticID ))*(void**)(__base - 3940))(__t__p0));\
	})
#endif

#ifndef SDL_OpenHapticFromJoystick
#define SDL_OpenHapticFromJoystick(__p0) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Haptic *(*)(SDL_Joystick *))*(void**)(__base - 3946))(__t__p0));\
	})
#endif

#ifndef SDL_OpenHapticFromMouse
#define SDL_OpenHapticFromMouse() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Haptic *(*)(void))*(void**)(__base - 3952))());\
	})
#endif

#ifndef SDL_OpenIO
#define SDL_OpenIO(__p0, __p1) \
	({ \
		const SDL_IOStreamInterface * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_IOStream *(*)(const SDL_IOStreamInterface *, void *))*(void**)(__base - 3958))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_OpenJoystick
#define SDL_OpenJoystick(__p0) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Joystick *(*)(SDL_JoystickID ))*(void**)(__base - 3964))(__t__p0));\
	})
#endif

#ifndef SDL_OpenSensor
#define SDL_OpenSensor(__p0) \
	({ \
		SDL_SensorID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Sensor *(*)(SDL_SensorID ))*(void**)(__base - 3970))(__t__p0));\
	})
#endif

#ifndef SDL_OpenStorage
#define SDL_OpenStorage(__p0, __p1) \
	({ \
		const SDL_StorageInterface * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Storage *(*)(const SDL_StorageInterface *, void *))*(void**)(__base - 3976))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_OpenTitleStorage
#define SDL_OpenTitleStorage(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Storage *(*)(const char *, SDL_PropertiesID ))*(void**)(__base - 3982))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_OpenURL
#define SDL_OpenURL(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 3988))(__t__p0));\
	})
#endif

#ifndef SDL_OpenUserStorage
#define SDL_OpenUserStorage(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_PropertiesID  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Storage *(*)(const char *, const char *, SDL_PropertiesID ))*(void**)(__base - 3994))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_OutOfMemory
#define SDL_OutOfMemory() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 4000))());\
	})
#endif

#ifndef SDL_PauseAudioDevice
#define SDL_PauseAudioDevice(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID ))*(void**)(__base - 4006))(__t__p0));\
	})
#endif

#ifndef SDL_PauseAudioStreamDevice
#define SDL_PauseAudioStreamDevice(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 4012))(__t__p0));\
	})
#endif

#ifndef SDL_PauseHaptic
#define SDL_PauseHaptic(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 4018))(__t__p0));\
	})
#endif

#ifndef SDL_PeepEvents
#define SDL_PeepEvents(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Event * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_EventAction  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		Uint32  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_Event *, int , SDL_EventAction , Uint32 , Uint32 ))*(void**)(__base - 4024))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_PlayHapticRumble
#define SDL_PlayHapticRumble(__p0, __p1, __p2) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, float , Uint32 ))*(void**)(__base - 4030))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_PollEvent
#define SDL_PollEvent(__p0) \
	({ \
		SDL_Event * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Event *))*(void**)(__base - 4036))(__t__p0));\
	})
#endif

#ifndef SDL_PopGPUDebugGroup
#define SDL_PopGPUDebugGroup(__p0) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *))*(void**)(__base - 4042))(__t__p0));\
	})
#endif

#ifndef SDL_PremultiplyAlpha
#define SDL_PremultiplyAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_PixelFormat  __t__p2 = __p2;\
		const void * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		SDL_PixelFormat  __t__p5 = __p5;\
		void * __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		bool  __t__p8 = __p8;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(int , int , SDL_PixelFormat , const void *, int , SDL_PixelFormat , void *, int , bool ))*(void**)(__base - 4048))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})
#endif

#ifndef SDL_PremultiplySurfaceAlpha
#define SDL_PremultiplySurfaceAlpha(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, bool ))*(void**)(__base - 4054))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_PumpEvents
#define SDL_PumpEvents() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4060))());\
	})
#endif

#ifndef SDL_PushEvent
#define SDL_PushEvent(__p0) \
	({ \
		SDL_Event * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Event *))*(void**)(__base - 4066))(__t__p0));\
	})
#endif

#ifndef SDL_PushGPUComputeUniformData
#define SDL_PushGPUComputeUniformData(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, Uint32 , const void *, Uint32 ))*(void**)(__base - 4072))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_PushGPUDebugGroup
#define SDL_PushGPUDebugGroup(__p0, __p1) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, const char *))*(void**)(__base - 4078))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_PushGPUFragmentUniformData
#define SDL_PushGPUFragmentUniformData(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, Uint32 , const void *, Uint32 ))*(void**)(__base - 4084))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_PushGPUVertexUniformData
#define SDL_PushGPUVertexUniformData(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCommandBuffer *, Uint32 , const void *, Uint32 ))*(void**)(__base - 4090))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_PutAudioStreamData
#define SDL_PutAudioStreamData(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const void *, int ))*(void**)(__base - 4096))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_QueryGPUFence
#define SDL_QueryGPUFence(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUFence * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_GPUFence *))*(void**)(__base - 4102))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_Quit
#define SDL_Quit() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4108))());\
	})
#endif

#ifndef SDL_QuitSubSystem
#define SDL_QuitSubSystem(__p0) \
	({ \
		SDL_InitFlags  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_InitFlags ))*(void**)(__base - 4114))(__t__p0));\
	})
#endif

#ifndef SDL_RaiseWindow
#define SDL_RaiseWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 4120))(__t__p0));\
	})
#endif

#ifndef SDL_ReadIO
#define SDL_ReadIO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(SDL_IOStream *, void *, size_t ))*(void**)(__base - 4126))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ReadProcess
#define SDL_ReadProcess(__p0, __p1, __p2) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(SDL_Process *, size_t *, int *))*(void**)(__base - 4132))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ReadS16BE
#define SDL_ReadS16BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint16 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint16 *))*(void**)(__base - 4138))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS16LE
#define SDL_ReadS16LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint16 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint16 *))*(void**)(__base - 4144))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS32BE
#define SDL_ReadS32BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint32 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint32 *))*(void**)(__base - 4150))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS32LE
#define SDL_ReadS32LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint32 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint32 *))*(void**)(__base - 4156))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS64BE
#define SDL_ReadS64BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint64 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint64 *))*(void**)(__base - 4162))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS64LE
#define SDL_ReadS64LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint64 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint64 *))*(void**)(__base - 4168))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadS8
#define SDL_ReadS8(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint8 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint8 *))*(void**)(__base - 4174))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadStorageFile
#define SDL_ReadStorageFile(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		Uint64  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, void *, Uint64 ))*(void**)(__base - 4180))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_ReadSurfacePixel
#define SDL_ReadSurfacePixel(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		Uint8 * __t__p4 = __p4;\
		Uint8 * __t__p5 = __p5;\
		Uint8 * __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, int , int , Uint8 *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 4186))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_ReadSurfacePixelFloat
#define SDL_ReadSurfacePixelFloat(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		float * __t__p5 = __p5;\
		float * __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, int , int , float *, float *, float *, float *))*(void**)(__base - 4192))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_ReadU16BE
#define SDL_ReadU16BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint16 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint16 *))*(void**)(__base - 4198))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU16LE
#define SDL_ReadU16LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint16 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint16 *))*(void**)(__base - 4204))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU32BE
#define SDL_ReadU32BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint32 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint32 *))*(void**)(__base - 4210))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU32LE
#define SDL_ReadU32LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint32 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint32 *))*(void**)(__base - 4216))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU64BE
#define SDL_ReadU64BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint64 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint64 *))*(void**)(__base - 4222))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU64LE
#define SDL_ReadU64LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint64 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint64 *))*(void**)(__base - 4228))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReadU8
#define SDL_ReadU8(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint8 *))*(void**)(__base - 4234))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RegisterEvents
#define SDL_RegisterEvents(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(int ))*(void**)(__base - 4246))(__t__p0));\
	})
#endif

#ifndef SDL_ReleaseCameraFrame
#define SDL_ReleaseCameraFrame(__p0, __p1) \
	({ \
		SDL_Camera * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Camera *, SDL_Surface *))*(void**)(__base - 4252))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUBuffer
#define SDL_ReleaseGPUBuffer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUBuffer * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUBuffer *))*(void**)(__base - 4258))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUComputePipeline
#define SDL_ReleaseGPUComputePipeline(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUComputePipeline * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUComputePipeline *))*(void**)(__base - 4264))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUFence
#define SDL_ReleaseGPUFence(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUFence * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUFence *))*(void**)(__base - 4270))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUGraphicsPipeline
#define SDL_ReleaseGPUGraphicsPipeline(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUGraphicsPipeline * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUGraphicsPipeline *))*(void**)(__base - 4276))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUSampler
#define SDL_ReleaseGPUSampler(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUSampler * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUSampler *))*(void**)(__base - 4282))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUShader
#define SDL_ReleaseGPUShader(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUShader * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUShader *))*(void**)(__base - 4288))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUTexture
#define SDL_ReleaseGPUTexture(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTexture * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUTexture *))*(void**)(__base - 4294))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseGPUTransferBuffer
#define SDL_ReleaseGPUTransferBuffer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTransferBuffer * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUTransferBuffer *))*(void**)(__base - 4300))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReleaseWindowFromGPUDevice
#define SDL_ReleaseWindowFromGPUDevice(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_Window *))*(void**)(__base - 4306))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ReloadGamepadMappings
#define SDL_ReloadGamepadMappings() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 4312))());\
	})
#endif

#ifndef SDL_RemoveEventWatch
#define SDL_RemoveEventWatch(__p0, __p1) \
	({ \
		SDL_EventFilter  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_EventFilter , void *))*(void**)(__base - 4318))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RemoveHintCallback
#define SDL_RemoveHintCallback(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_HintCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *, SDL_HintCallback , void *))*(void**)(__base - 4324))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RemovePath
#define SDL_RemovePath(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 4330))(__t__p0));\
	})
#endif

#ifndef SDL_RemoveStoragePath
#define SDL_RemoveStoragePath(__p0, __p1) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *))*(void**)(__base - 4336))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RemoveSurfaceAlternateImages
#define SDL_RemoveSurfaceAlternateImages(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Surface *))*(void**)(__base - 4342))(__t__p0));\
	})
#endif

#ifndef SDL_RemoveTimer
#define SDL_RemoveTimer(__p0) \
	({ \
		SDL_TimerID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_TimerID ))*(void**)(__base - 4348))(__t__p0));\
	})
#endif

#ifndef SDL_RenamePath
#define SDL_RenamePath(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *))*(void**)(__base - 4354))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenameStoragePath
#define SDL_RenameStoragePath(__p0, __p1, __p2) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, const char *))*(void**)(__base - 4360))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderClear
#define SDL_RenderClear(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *))*(void**)(__base - 4366))(__t__p0));\
	})
#endif

#ifndef SDL_RenderClipEnabled
#define SDL_RenderClipEnabled(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *))*(void**)(__base - 4372))(__t__p0));\
	})
#endif

#ifndef SDL_RenderCoordinatesFromWindow
#define SDL_RenderCoordinatesFromWindow(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float , float *, float *))*(void**)(__base - 4378))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_RenderCoordinatesToWindow
#define SDL_RenderCoordinatesToWindow(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float , float *, float *))*(void**)(__base - 4384))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_RenderFillRect
#define SDL_RenderFillRect(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FRect *))*(void**)(__base - 4390))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenderFillRects
#define SDL_RenderFillRects(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FRect *, int ))*(void**)(__base - 4396))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderGeometry
#define SDL_RenderGeometry(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_Vertex * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const int * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_Vertex *, int , const int *, int ))*(void**)(__base - 4402))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_RenderGeometryRaw
#define SDL_RenderGeometryRaw(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const float * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const SDL_FColor * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		const float * __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		int  __t__p8 = __p8;\
		const void * __t__p9 = __p9;\
		int  __t__p10 = __p10;\
		int  __t__p11 = __p11;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const float *, int , const SDL_FColor *, int , const float *, int , int , const void *, int , int ))*(void**)(__base - 4408))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9, __t__p10, __t__p11));\
	})
#endif

#ifndef SDL_RenderLine
#define SDL_RenderLine(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float , float , float ))*(void**)(__base - 4414))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_RenderLines
#define SDL_RenderLines(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FPoint * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FPoint *, int ))*(void**)(__base - 4420))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderPoint
#define SDL_RenderPoint(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float ))*(void**)(__base - 4426))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderPoints
#define SDL_RenderPoints(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FPoint * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FPoint *, int ))*(void**)(__base - 4432))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderPresent
#define SDL_RenderPresent(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *))*(void**)(__base - 4438))(__t__p0));\
	})
#endif

#ifndef SDL_RenderReadPixels
#define SDL_RenderReadPixels(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Renderer *, const SDL_Rect *))*(void**)(__base - 4444))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenderRect
#define SDL_RenderRect(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FRect *))*(void**)(__base - 4450))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenderRects
#define SDL_RenderRects(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_FRect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_FRect *, int ))*(void**)(__base - 4456))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_RenderTexture
#define SDL_RenderTexture(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		const SDL_FRect * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, const SDL_FRect *))*(void**)(__base - 4462))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RenderTexture9Grid
#define SDL_RenderTexture9Grid(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		float  __t__p5 = __p5;\
		float  __t__p6 = __p6;\
		float  __t__p7 = __p7;\
		const SDL_FRect * __t__p8 = __p8;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, float , float , float , float , float , const SDL_FRect *))*(void**)(__base - 4468))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})
#endif

#ifndef SDL_RenderTextureRotated
#define SDL_RenderTextureRotated(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		const SDL_FRect * __t__p3 = __p3;\
		double  __t__p4 = __p4;\
		const SDL_FPoint * __t__p5 = __p5;\
		SDL_FlipMode  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, const SDL_FRect *, double , const SDL_FPoint *, SDL_FlipMode ))*(void**)(__base - 4474))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_RenderTextureTiled
#define SDL_RenderTextureTiled(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		const SDL_FRect * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, float , const SDL_FRect *))*(void**)(__base - 4480))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_RenderViewportSet
#define SDL_RenderViewportSet(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *))*(void**)(__base - 4486))(__t__p0));\
	})
#endif

#ifndef SDL_ReportAssertion
#define SDL_ReportAssertion(__p0, __p1, __p2, __p3) \
	({ \
		SDL_AssertData * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AssertState (*)(SDL_AssertData *, const char *, const char *, int ))*(void**)(__base - 4492))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_ResetAssertionReport
#define SDL_ResetAssertionReport() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4504))());\
	})
#endif

#ifndef SDL_ResetHint
#define SDL_ResetHint(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 4510))(__t__p0));\
	})
#endif

#ifndef SDL_ResetHints
#define SDL_ResetHints() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4516))());\
	})
#endif

#ifndef SDL_ResetKeyboard
#define SDL_ResetKeyboard() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4522))());\
	})
#endif

#ifndef SDL_ResetLogPriorities
#define SDL_ResetLogPriorities() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4528))());\
	})
#endif

#ifndef SDL_RestoreWindow
#define SDL_RestoreWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 4534))(__t__p0));\
	})
#endif

#ifndef SDL_ResumeAudioDevice
#define SDL_ResumeAudioDevice(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID ))*(void**)(__base - 4540))(__t__p0));\
	})
#endif

#ifndef SDL_ResumeAudioStreamDevice
#define SDL_ResumeAudioStreamDevice(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 4546))(__t__p0));\
	})
#endif

#ifndef SDL_ResumeHaptic
#define SDL_ResumeHaptic(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 4552))(__t__p0));\
	})
#endif

#ifndef SDL_RumbleGamepad
#define SDL_RumbleGamepad(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		Uint16  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, Uint16 , Uint16 , Uint32 ))*(void**)(__base - 4558))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RumbleGamepadTriggers
#define SDL_RumbleGamepadTriggers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		Uint16  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, Uint16 , Uint16 , Uint32 ))*(void**)(__base - 4564))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RumbleJoystick
#define SDL_RumbleJoystick(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		Uint16  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, Uint16 , Uint16 , Uint32 ))*(void**)(__base - 4570))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RumbleJoystickTriggers
#define SDL_RumbleJoystickTriggers(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		Uint16  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, Uint16 , Uint16 , Uint32 ))*(void**)(__base - 4576))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RunApp
#define SDL_RunApp(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		SDL_main_func  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , char **, SDL_main_func , void *))*(void**)(__base - 4582))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RunHapticEffect
#define SDL_RunHapticEffect(__p0, __p1, __p2) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		SDL_HapticEffectID  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, SDL_HapticEffectID , Uint32 ))*(void**)(__base - 4588))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SaveBMP
#define SDL_SaveBMP(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 4594))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SaveBMP_IO
#define SDL_SaveBMP_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 4600))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ScaleSurface
#define SDL_ScaleSurface(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_ScaleMode  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Surface *, int , int , SDL_ScaleMode ))*(void**)(__base - 4606))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_ScreenKeyboardShown
#define SDL_ScreenKeyboardShown(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 4612))(__t__p0));\
	})
#endif

#ifndef SDL_ScreenSaverEnabled
#define SDL_ScreenSaverEnabled() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 4618))());\
	})
#endif

#ifndef SDL_SeekIO
#define SDL_SeekIO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		SDL_IOWhence  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(SDL_IOStream *, Sint64 , SDL_IOWhence ))*(void**)(__base - 4624))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SendGamepadEffect
#define SDL_SendGamepadEffect(__p0, __p1, __p2) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, const void *, int ))*(void**)(__base - 4642))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SendJoystickEffect
#define SDL_SendJoystickEffect(__p0, __p1, __p2) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, const void *, int ))*(void**)(__base - 4648))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SendJoystickVirtualSensorData
#define SDL_SendJoystickVirtualSensorData(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		Uint64  __t__p2 = __p2;\
		const float * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, SDL_SensorType , Uint64 , const float *, int ))*(void**)(__base - 4654))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetAppMetadata
#define SDL_SetAppMetadata(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *, const char *))*(void**)(__base - 4660))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAppMetadataProperty
#define SDL_SetAppMetadataProperty(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *))*(void**)(__base - 4666))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAssertionHandler
#define SDL_SetAssertionHandler(__p0, __p1) \
	({ \
		SDL_AssertionHandler  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AssertionHandler , void *))*(void**)(__base - 4672))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAtomicInt
#define SDL_SetAtomicInt(__p0, __p1) \
	({ \
		SDL_AtomicInt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_AtomicInt *, int ))*(void**)(__base - 4678))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAtomicPointer
#define SDL_SetAtomicPointer(__p0, __p1) \
	({ \
		void ** __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void **, void *))*(void**)(__base - 4684))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAtomicU32
#define SDL_SetAtomicU32(__p0, __p1) \
	({ \
		SDL_AtomicU32 * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_AtomicU32 *, Uint32 ))*(void**)(__base - 4690))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAudioDeviceGain
#define SDL_SetAudioDeviceGain(__p0, __p1) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID , float ))*(void**)(__base - 4696))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAudioPostmixCallback
#define SDL_SetAudioPostmixCallback(__p0, __p1, __p2) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		SDL_AudioPostmixCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID , SDL_AudioPostmixCallback , void *))*(void**)(__base - 4702))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAudioStreamFormat
#define SDL_SetAudioStreamFormat(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const SDL_AudioSpec * __t__p1 = __p1;\
		const SDL_AudioSpec * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const SDL_AudioSpec *, const SDL_AudioSpec *))*(void**)(__base - 4708))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAudioStreamFrequencyRatio
#define SDL_SetAudioStreamFrequencyRatio(__p0, __p1) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, float ))*(void**)(__base - 4714))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAudioStreamGain
#define SDL_SetAudioStreamGain(__p0, __p1) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, float ))*(void**)(__base - 4720))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetAudioStreamGetCallback
#define SDL_SetAudioStreamGetCallback(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		SDL_AudioStreamCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, SDL_AudioStreamCallback , void *))*(void**)(__base - 4726))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAudioStreamInputChannelMap
#define SDL_SetAudioStreamInputChannelMap(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const int * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const int *, int ))*(void**)(__base - 4732))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAudioStreamOutputChannelMap
#define SDL_SetAudioStreamOutputChannelMap(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const int * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const int *, int ))*(void**)(__base - 4738))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetAudioStreamPutCallback
#define SDL_SetAudioStreamPutCallback(__p0, __p1, __p2) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		SDL_AudioStreamCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, SDL_AudioStreamCallback , void *))*(void**)(__base - 4744))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetBooleanProperty
#define SDL_SetBooleanProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, bool ))*(void**)(__base - 4750))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetClipboardData
#define SDL_SetClipboardData(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_ClipboardDataCallback  __t__p0 = __p0;\
		SDL_ClipboardCleanupCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		const char *const * __t__p3 = __p3;\
		size_t  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_ClipboardDataCallback , SDL_ClipboardCleanupCallback , void *, const char *const *, size_t ))*(void**)(__base - 4756))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetClipboardText
#define SDL_SetClipboardText(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 4762))(__t__p0));\
	})
#endif

#ifndef SDL_SetCurrentThreadPriority
#define SDL_SetCurrentThreadPriority(__p0) \
	({ \
		SDL_ThreadPriority  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_ThreadPriority ))*(void**)(__base - 4768))(__t__p0));\
	})
#endif

#ifndef SDL_SetCursor
#define SDL_SetCursor(__p0) \
	({ \
		SDL_Cursor * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Cursor *))*(void**)(__base - 4774))(__t__p0));\
	})
#endif

#ifndef SDL_SetEnvironmentVariable
#define SDL_SetEnvironmentVariable(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Environment * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Environment *, const char *, const char *, bool ))*(void**)(__base - 4780))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetEventEnabled
#define SDL_SetEventEnabled(__p0, __p1) \
	({ \
		Uint32  __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 , bool ))*(void**)(__base - 4786))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetEventFilter
#define SDL_SetEventFilter(__p0, __p1) \
	({ \
		SDL_EventFilter  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_EventFilter , void *))*(void**)(__base - 4792))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetFloatProperty
#define SDL_SetFloatProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, float ))*(void**)(__base - 4798))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetGPUBlendConstants
#define SDL_SetGPUBlendConstants(__p0, __p1) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		SDL_FColor  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, SDL_FColor ))*(void**)(__base - 4804))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGPUBufferName
#define SDL_SetGPUBufferName(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUBuffer * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUBuffer *, const char *))*(void**)(__base - 4810))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetGPUScissor
#define SDL_SetGPUScissor(__p0, __p1) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, const SDL_Rect *))*(void**)(__base - 4816))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGPUStencilReference
#define SDL_SetGPUStencilReference(__p0, __p1) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, Uint8 ))*(void**)(__base - 4822))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGPUSwapchainParameters
#define SDL_SetGPUSwapchainParameters(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		SDL_GPUSwapchainComposition  __t__p2 = __p2;\
		SDL_GPUPresentMode  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_Window *, SDL_GPUSwapchainComposition , SDL_GPUPresentMode ))*(void**)(__base - 4828))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetGPUTextureName
#define SDL_SetGPUTextureName(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTexture * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUTexture *, const char *))*(void**)(__base - 4834))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetGPUViewport
#define SDL_SetGPUViewport(__p0, __p1) \
	({ \
		SDL_GPURenderPass * __t__p0 = __p0;\
		const SDL_GPUViewport * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderPass *, const SDL_GPUViewport *))*(void**)(__base - 4840))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGamepadEventsEnabled
#define SDL_SetGamepadEventsEnabled(__p0) \
	({ \
		bool  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(bool ))*(void**)(__base - 4846))(__t__p0));\
	})
#endif

#ifndef SDL_SetGamepadLED
#define SDL_SetGamepadLED(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 4852))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetGamepadMapping
#define SDL_SetGamepadMapping(__p0, __p1) \
	({ \
		SDL_JoystickID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_JoystickID , const char *))*(void**)(__base - 4858))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGamepadPlayerIndex
#define SDL_SetGamepadPlayerIndex(__p0, __p1) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, int ))*(void**)(__base - 4864))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGamepadSensorEnabled
#define SDL_SetGamepadSensorEnabled(__p0, __p1, __p2) \
	({ \
		SDL_Gamepad * __t__p0 = __p0;\
		SDL_SensorType  __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Gamepad *, SDL_SensorType , bool ))*(void**)(__base - 4870))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetHapticAutocenter
#define SDL_SetHapticAutocenter(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, int ))*(void**)(__base - 4876))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetHapticGain
#define SDL_SetHapticGain(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, int ))*(void**)(__base - 4882))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetHint
#define SDL_SetHint(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *))*(void**)(__base - 4888))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetHintWithPriority
#define SDL_SetHintWithPriority(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_HintPriority  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const char *, SDL_HintPriority ))*(void**)(__base - 4894))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetInitialized
#define SDL_SetInitialized(__p0, __p1) \
	({ \
		SDL_InitState * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_InitState *, bool ))*(void**)(__base - 4900))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetJoystickEventsEnabled
#define SDL_SetJoystickEventsEnabled(__p0) \
	({ \
		bool  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(bool ))*(void**)(__base - 4906))(__t__p0));\
	})
#endif

#ifndef SDL_SetJoystickLED
#define SDL_SetJoystickLED(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 4912))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetJoystickPlayerIndex
#define SDL_SetJoystickPlayerIndex(__p0, __p1) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int ))*(void**)(__base - 4918))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetJoystickVirtualAxis
#define SDL_SetJoystickVirtualAxis(__p0, __p1, __p2) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		Sint16  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , Sint16 ))*(void**)(__base - 4924))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetJoystickVirtualBall
#define SDL_SetJoystickVirtualBall(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		Sint16  __t__p2 = __p2;\
		Sint16  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , Sint16 , Sint16 ))*(void**)(__base - 4930))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetJoystickVirtualButton
#define SDL_SetJoystickVirtualButton(__p0, __p1, __p2) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , bool ))*(void**)(__base - 4936))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetJoystickVirtualHat
#define SDL_SetJoystickVirtualHat(__p0, __p1, __p2) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , Uint8 ))*(void**)(__base - 4942))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetJoystickVirtualTouchpad
#define SDL_SetJoystickVirtualTouchpad(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Joystick * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		float  __t__p5 = __p5;\
		float  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Joystick *, int , int , bool , float , float , float ))*(void**)(__base - 4948))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_SetLogOutputFunction
#define SDL_SetLogOutputFunction(__p0, __p1) \
	({ \
		SDL_LogOutputFunction  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_LogOutputFunction , void *))*(void**)(__base - 4966))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetLogPriorities
#define SDL_SetLogPriorities(__p0) \
	({ \
		SDL_LogPriority  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_LogPriority ))*(void**)(__base - 4972))(__t__p0));\
	})
#endif

#ifndef SDL_SetLogPriority
#define SDL_SetLogPriority(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		SDL_LogPriority  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , SDL_LogPriority ))*(void**)(__base - 4978))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetLogPriorityPrefix
#define SDL_SetLogPriorityPrefix(__p0, __p1) \
	({ \
		SDL_LogPriority  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_LogPriority , const char *))*(void**)(__base - 4984))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetMainReady
#define SDL_SetMainReady() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 4990))());\
	})
#endif

#ifndef SDL_SetMemoryFunctions
#define SDL_SetMemoryFunctions(__p0, __p1, __p2, __p3) \
	({ \
		SDL_malloc_func  __t__p0 = __p0;\
		SDL_calloc_func  __t__p1 = __p1;\
		SDL_realloc_func  __t__p2 = __p2;\
		SDL_free_func  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_malloc_func , SDL_calloc_func , SDL_realloc_func , SDL_free_func ))*(void**)(__base - 4996))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetModState
#define SDL_SetModState(__p0) \
	({ \
		SDL_Keymod  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Keymod ))*(void**)(__base - 5002))(__t__p0));\
	})
#endif

#ifndef SDL_SetNumberProperty
#define SDL_SetNumberProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Sint64  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, Sint64 ))*(void**)(__base - 5008))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetPaletteColors
#define SDL_SetPaletteColors(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Palette * __t__p0 = __p0;\
		const SDL_Color * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Palette *, const SDL_Color *, int , int ))*(void**)(__base - 5014))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetPointerProperty
#define SDL_SetPointerProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, void *))*(void**)(__base - 5020))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetPointerPropertyWithCleanup
#define SDL_SetPointerPropertyWithCleanup(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		SDL_CleanupPropertyCallback  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, void *, SDL_CleanupPropertyCallback , void *))*(void**)(__base - 5026))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetPrimarySelectionText
#define SDL_SetPrimarySelectionText(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 5032))(__t__p0));\
	})
#endif

#ifndef SDL_SetRenderClipRect
#define SDL_SetRenderClipRect(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_Rect *))*(void**)(__base - 5038))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetRenderColorScale
#define SDL_SetRenderColorScale(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float ))*(void**)(__base - 5044))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetRenderDrawBlendMode
#define SDL_SetRenderDrawBlendMode(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_BlendMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_BlendMode ))*(void**)(__base - 5050))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetRenderDrawColor
#define SDL_SetRenderDrawColor(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)(__base - 5056))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetRenderDrawColorFloat
#define SDL_SetRenderDrawColorFloat(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float , float , float ))*(void**)(__base - 5062))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetRenderLogicalPresentation
#define SDL_SetRenderLogicalPresentation(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_RendererLogicalPresentation  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int , int , SDL_RendererLogicalPresentation ))*(void**)(__base - 5068))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetRenderScale
#define SDL_SetRenderScale(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float ))*(void**)(__base - 5074))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetRenderTarget
#define SDL_SetRenderTarget(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *))*(void**)(__base - 5080))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetRenderVSync
#define SDL_SetRenderVSync(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, int ))*(void**)(__base - 5086))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetRenderViewport
#define SDL_SetRenderViewport(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, const SDL_Rect *))*(void**)(__base - 5092))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetScancodeName
#define SDL_SetScancodeName(__p0, __p1) \
	({ \
		SDL_Scancode  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Scancode , const char *))*(void**)(__base - 5098))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetStringProperty
#define SDL_SetStringProperty(__p0, __p1, __p2) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_PropertiesID , const char *, const char *))*(void**)(__base - 5104))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetSurfaceAlphaMod
#define SDL_SetSurfaceAlphaMod(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, Uint8 ))*(void**)(__base - 5110))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetSurfaceBlendMode
#define SDL_SetSurfaceBlendMode(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_BlendMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_BlendMode ))*(void**)(__base - 5116))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetSurfaceClipRect
#define SDL_SetSurfaceClipRect(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *))*(void**)(__base - 5122))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetSurfaceColorKey
#define SDL_SetSurfaceColorKey(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, bool , Uint32 ))*(void**)(__base - 5128))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetSurfaceColorMod
#define SDL_SetSurfaceColorMod(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 5134))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetSurfaceColorspace
#define SDL_SetSurfaceColorspace(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_Colorspace  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_Colorspace ))*(void**)(__base - 5140))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetSurfacePalette
#define SDL_SetSurfacePalette(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_Palette * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_Palette *))*(void**)(__base - 5146))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetSurfaceRLE
#define SDL_SetSurfaceRLE(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, bool ))*(void**)(__base - 5152))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTLS
#define SDL_SetTLS(__p0, __p1, __p2) \
	({ \
		SDL_TLSID * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		SDL_TLSDestructorCallback  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_TLSID *, const void *, SDL_TLSDestructorCallback ))*(void**)(__base - 5158))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetTextInputArea
#define SDL_SetTextInputArea(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, const SDL_Rect *, int ))*(void**)(__base - 5164))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetTextureAlphaMod
#define SDL_SetTextureAlphaMod(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, Uint8 ))*(void**)(__base - 5170))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTextureAlphaModFloat
#define SDL_SetTextureAlphaModFloat(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, float ))*(void**)(__base - 5176))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTextureBlendMode
#define SDL_SetTextureBlendMode(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		SDL_BlendMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, SDL_BlendMode ))*(void**)(__base - 5182))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTextureColorMod
#define SDL_SetTextureColorMod(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, Uint8 , Uint8 , Uint8 ))*(void**)(__base - 5188))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetTextureColorModFloat
#define SDL_SetTextureColorModFloat(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, float , float , float ))*(void**)(__base - 5194))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetTextureScaleMode
#define SDL_SetTextureScaleMode(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		SDL_ScaleMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, SDL_ScaleMode ))*(void**)(__base - 5200))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowAlwaysOnTop
#define SDL_SetWindowAlwaysOnTop(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5206))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowAspectRatio
#define SDL_SetWindowAspectRatio(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, float , float ))*(void**)(__base - 5212))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowBordered
#define SDL_SetWindowBordered(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5218))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowFocusable
#define SDL_SetWindowFocusable(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5224))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowFullscreen
#define SDL_SetWindowFullscreen(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5230))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowFullscreenMode
#define SDL_SetWindowFullscreenMode(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const SDL_DisplayMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, const SDL_DisplayMode *))*(void**)(__base - 5236))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowHitTest
#define SDL_SetWindowHitTest(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_HitTest  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_HitTest , void *))*(void**)(__base - 5242))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowIcon
#define SDL_SetWindowIcon(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_Surface *))*(void**)(__base - 5248))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowKeyboardGrab
#define SDL_SetWindowKeyboardGrab(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5254))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowMaximumSize
#define SDL_SetWindowMaximumSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , int ))*(void**)(__base - 5260))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowMinimumSize
#define SDL_SetWindowMinimumSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , int ))*(void**)(__base - 5266))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowModal
#define SDL_SetWindowModal(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5272))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowMouseGrab
#define SDL_SetWindowMouseGrab(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5278))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowMouseRect
#define SDL_SetWindowMouseRect(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, const SDL_Rect *))*(void**)(__base - 5284))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowOpacity
#define SDL_SetWindowOpacity(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, float ))*(void**)(__base - 5290))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowParent
#define SDL_SetWindowParent(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_Window *))*(void**)(__base - 5296))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowPosition
#define SDL_SetWindowPosition(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , int ))*(void**)(__base - 5302))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowRelativeMouseMode
#define SDL_SetWindowRelativeMouseMode(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5308))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowResizable
#define SDL_SetWindowResizable(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 5314))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowShape
#define SDL_SetWindowShape(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_Surface *))*(void**)(__base - 5320))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowSize
#define SDL_SetWindowSize(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , int ))*(void**)(__base - 5326))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetWindowSurfaceVSync
#define SDL_SetWindowSurfaceVSync(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int ))*(void**)(__base - 5332))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowTitle
#define SDL_SetWindowTitle(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, const char *))*(void**)(__base - 5338))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetiOSAnimationCallback
#define SDL_SetiOSAnimationCallback(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SDL_iOSAnimationCallback  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , SDL_iOSAnimationCallback , void *))*(void**)(__base - 5356))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetiOSEventPump
#define SDL_SetiOSEventPump(__p0) \
	({ \
		bool  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(bool ))*(void**)(__base - 5362))(__t__p0));\
	})
#endif

#ifndef SDL_ShouldInit
#define SDL_ShouldInit(__p0) \
	({ \
		SDL_InitState * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_InitState *))*(void**)(__base - 5368))(__t__p0));\
	})
#endif

#ifndef SDL_ShouldQuit
#define SDL_ShouldQuit(__p0) \
	({ \
		SDL_InitState * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_InitState *))*(void**)(__base - 5374))(__t__p0));\
	})
#endif

#ifndef SDL_ShowCursor
#define SDL_ShowCursor() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 5386))());\
	})
#endif

#ifndef SDL_ShowMessageBox
#define SDL_ShowMessageBox(__p0, __p1) \
	({ \
		const SDL_MessageBoxData * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const SDL_MessageBoxData *, int *))*(void**)(__base - 5392))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ShowOpenFileDialog
#define SDL_ShowOpenFileDialog(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_DialogFileCallback  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		SDL_Window * __t__p2 = __p2;\
		const SDL_DialogFileFilter * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		const char * __t__p5 = __p5;\
		bool  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_DialogFileCallback , void *, SDL_Window *, const SDL_DialogFileFilter *, int , const char *, bool ))*(void**)(__base - 5398))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_ShowOpenFolderDialog
#define SDL_ShowOpenFolderDialog(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_DialogFileCallback  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		SDL_Window * __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		bool  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_DialogFileCallback , void *, SDL_Window *, const char *, bool ))*(void**)(__base - 5404))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_ShowSaveFileDialog
#define SDL_ShowSaveFileDialog(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_DialogFileCallback  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		SDL_Window * __t__p2 = __p2;\
		const SDL_DialogFileFilter * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		const char * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_DialogFileCallback , void *, SDL_Window *, const SDL_DialogFileFilter *, int , const char *))*(void**)(__base - 5410))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_ShowSimpleMessageBox
#define SDL_ShowSimpleMessageBox(__p0, __p1, __p2, __p3) \
	({ \
		SDL_MessageBoxFlags  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		SDL_Window * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_MessageBoxFlags , const char *, const char *, SDL_Window *))*(void**)(__base - 5416))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_ShowWindow
#define SDL_ShowWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5422))(__t__p0));\
	})
#endif

#ifndef SDL_ShowWindowSystemMenu
#define SDL_ShowWindowSystemMenu(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, int , int ))*(void**)(__base - 5428))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SignalCondition
#define SDL_SignalCondition(__p0) \
	({ \
		SDL_Condition * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Condition *))*(void**)(__base - 5434))(__t__p0));\
	})
#endif

#ifndef SDL_SignalSemaphore
#define SDL_SignalSemaphore(__p0) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Semaphore *))*(void**)(__base - 5440))(__t__p0));\
	})
#endif

#ifndef SDL_StartTextInput
#define SDL_StartTextInput(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5446))(__t__p0));\
	})
#endif

#ifndef SDL_StartTextInputWithProperties
#define SDL_StartTextInputWithProperties(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_PropertiesID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_PropertiesID ))*(void**)(__base - 5452))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_StepUTF8
#define SDL_StepUTF8(__p0, __p1) \
	({ \
		const char ** __t__p0 = __p0;\
		size_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const char **, size_t *))*(void**)(__base - 5458))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_StopHapticEffect
#define SDL_StopHapticEffect(__p0, __p1) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		SDL_HapticEffectID  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, SDL_HapticEffectID ))*(void**)(__base - 5464))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_StopHapticEffects
#define SDL_StopHapticEffects(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 5470))(__t__p0));\
	})
#endif

#ifndef SDL_StopHapticRumble
#define SDL_StopHapticRumble(__p0) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *))*(void**)(__base - 5476))(__t__p0));\
	})
#endif

#ifndef SDL_StopTextInput
#define SDL_StopTextInput(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5482))(__t__p0));\
	})
#endif

#ifndef SDL_StorageReady
#define SDL_StorageReady(__p0) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *))*(void**)(__base - 5488))(__t__p0));\
	})
#endif

#ifndef SDL_StringToGUID
#define SDL_StringToGUID(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GUID (*)(const char *))*(void**)(__base - 5494))(__t__p0));\
	})
#endif

#ifndef SDL_SubmitGPUCommandBuffer
#define SDL_SubmitGPUCommandBuffer(__p0) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUCommandBuffer *))*(void**)(__base - 5500))(__t__p0));\
	})
#endif

#ifndef SDL_SubmitGPUCommandBufferAndAcquireFence
#define SDL_SubmitGPUCommandBufferAndAcquireFence(__p0) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUFence *(*)(SDL_GPUCommandBuffer *))*(void**)(__base - 5506))(__t__p0));\
	})
#endif

#ifndef SDL_SurfaceHasAlternateImages
#define SDL_SurfaceHasAlternateImages(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *))*(void**)(__base - 5512))(__t__p0));\
	})
#endif

#ifndef SDL_SurfaceHasColorKey
#define SDL_SurfaceHasColorKey(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *))*(void**)(__base - 5518))(__t__p0));\
	})
#endif

#ifndef SDL_SurfaceHasRLE
#define SDL_SurfaceHasRLE(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *))*(void**)(__base - 5524))(__t__p0));\
	})
#endif

#ifndef SDL_SyncWindow
#define SDL_SyncWindow(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5530))(__t__p0));\
	})
#endif

#ifndef SDL_TellIO
#define SDL_TellIO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(SDL_IOStream *))*(void**)(__base - 5536))(__t__p0));\
	})
#endif

#ifndef SDL_TextInputActive
#define SDL_TextInputActive(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5542))(__t__p0));\
	})
#endif

#ifndef SDL_TimeFromWindows
#define SDL_TimeFromWindows(__p0, __p1) \
	({ \
		Uint32  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Time (*)(Uint32 , Uint32 ))*(void**)(__base - 5548))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_TimeToDateTime
#define SDL_TimeToDateTime(__p0, __p1, __p2) \
	({ \
		SDL_Time  __t__p0 = __p0;\
		SDL_DateTime * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Time , SDL_DateTime *, bool ))*(void**)(__base - 5554))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_TimeToWindows
#define SDL_TimeToWindows(__p0, __p1, __p2) \
	({ \
		SDL_Time  __t__p0 = __p0;\
		Uint32 * __t__p1 = __p1;\
		Uint32 * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Time , Uint32 *, Uint32 *))*(void**)(__base - 5560))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_TryLockMutex
#define SDL_TryLockMutex(__p0) \
	({ \
		SDL_Mutex * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Mutex *))*(void**)(__base - 5566))(__t__p0));\
	})
#endif

#ifndef SDL_TryLockRWLockForReading
#define SDL_TryLockRWLockForReading(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_RWLock *))*(void**)(__base - 5572))(__t__p0));\
	})
#endif

#ifndef SDL_TryLockRWLockForWriting
#define SDL_TryLockRWLockForWriting(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_RWLock *))*(void**)(__base - 5578))(__t__p0));\
	})
#endif

#ifndef SDL_TryLockSpinlock
#define SDL_TryLockSpinlock(__p0) \
	({ \
		SDL_SpinLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_SpinLock *))*(void**)(__base - 5584))(__t__p0));\
	})
#endif

#ifndef SDL_TryWaitSemaphore
#define SDL_TryWaitSemaphore(__p0) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Semaphore *))*(void**)(__base - 5590))(__t__p0));\
	})
#endif

#ifndef SDL_UCS4ToUTF8
#define SDL_UCS4ToUTF8(__p0, __p1) \
	({ \
		Uint32  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(Uint32 , char *))*(void**)(__base - 5596))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_UnbindAudioStream
#define SDL_UnbindAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AudioStream *))*(void**)(__base - 5602))(__t__p0));\
	})
#endif

#ifndef SDL_UnbindAudioStreams
#define SDL_UnbindAudioStreams(__p0, __p1) \
	({ \
		SDL_AudioStream *const * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AudioStream *const *, int ))*(void**)(__base - 5608))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_UnlockAudioStream
#define SDL_UnlockAudioStream(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 5620))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockJoysticks
#define SDL_UnlockJoysticks() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 5626))());\
	})
#endif

#ifndef SDL_UnlockMutex
#define SDL_UnlockMutex(__p0) \
	({ \
		SDL_Mutex * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Mutex *))*(void**)(__base - 5632))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockProperties
#define SDL_UnlockProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_PropertiesID ))*(void**)(__base - 5638))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockRWLock
#define SDL_UnlockRWLock(__p0) \
	({ \
		SDL_RWLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_RWLock *))*(void**)(__base - 5644))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockSpinlock
#define SDL_UnlockSpinlock(__p0) \
	({ \
		SDL_SpinLock * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_SpinLock *))*(void**)(__base - 5650))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockSurface
#define SDL_UnlockSurface(__p0) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Surface *))*(void**)(__base - 5656))(__t__p0));\
	})
#endif

#ifndef SDL_UnlockTexture
#define SDL_UnlockTexture(__p0) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Texture *))*(void**)(__base - 5662))(__t__p0));\
	})
#endif

#ifndef SDL_UnmapGPUTransferBuffer
#define SDL_UnmapGPUTransferBuffer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUTransferBuffer * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUDevice *, SDL_GPUTransferBuffer *))*(void**)(__base - 5668))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_UnsetEnvironmentVariable
#define SDL_UnsetEnvironmentVariable(__p0, __p1) \
	({ \
		SDL_Environment * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Environment *, const char *))*(void**)(__base - 5680))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_UpdateGamepads
#define SDL_UpdateGamepads() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 5686))());\
	})
#endif

#ifndef SDL_UpdateHapticEffect
#define SDL_UpdateHapticEffect(__p0, __p1, __p2) \
	({ \
		SDL_Haptic * __t__p0 = __p0;\
		SDL_HapticEffectID  __t__p1 = __p1;\
		const SDL_HapticEffect * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Haptic *, SDL_HapticEffectID , const SDL_HapticEffect *))*(void**)(__base - 5692))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_UpdateJoysticks
#define SDL_UpdateJoysticks() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 5698))());\
	})
#endif

#ifndef SDL_UpdateNVTexture
#define SDL_UpdateNVTexture(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		const Uint8 * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const Uint8 * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, const SDL_Rect *, const Uint8 *, int , const Uint8 *, int ))*(void**)(__base - 5704))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_UpdateSensors
#define SDL_UpdateSensors() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 5710))());\
	})
#endif

#ifndef SDL_UpdateTexture
#define SDL_UpdateTexture(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, const SDL_Rect *, const void *, int ))*(void**)(__base - 5716))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_UpdateWindowSurface
#define SDL_UpdateWindowSurface(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5722))(__t__p0));\
	})
#endif

#ifndef SDL_UpdateWindowSurfaceRects
#define SDL_UpdateWindowSurfaceRects(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, const SDL_Rect *, int ))*(void**)(__base - 5728))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_UpdateYUVTexture
#define SDL_UpdateYUVTexture(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		const Uint8 * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const Uint8 * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		const Uint8 * __t__p6 = __p6;\
		int  __t__p7 = __p7;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, const SDL_Rect *, const Uint8 *, int , const Uint8 *, int , const Uint8 *, int ))*(void**)(__base - 5734))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})
#endif

#ifndef SDL_UploadToGPUBuffer
#define SDL_UploadToGPUBuffer(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUTransferBufferLocation * __t__p1 = __p1;\
		const SDL_GPUBufferRegion * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUTransferBufferLocation *, const SDL_GPUBufferRegion *, bool ))*(void**)(__base - 5740))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_UploadToGPUTexture
#define SDL_UploadToGPUTexture(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUCopyPass * __t__p0 = __p0;\
		const SDL_GPUTextureTransferInfo * __t__p1 = __p1;\
		const SDL_GPUTextureRegion * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPUCopyPass *, const SDL_GPUTextureTransferInfo *, const SDL_GPUTextureRegion *, bool ))*(void**)(__base - 5746))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_Vulkan_CreateSurface
#define SDL_Vulkan_CreateSurface(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		VkInstance  __t__p1 = __p1;\
		const struct VkAllocationCallbacks * __t__p2 = __p2;\
		VkSurfaceKHR * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, VkInstance , const struct VkAllocationCallbacks *, VkSurfaceKHR *))*(void**)(__base - 5752))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_Vulkan_DestroySurface
#define SDL_Vulkan_DestroySurface(__p0, __p1, __p2) \
	({ \
		VkInstance  __t__p0 = __p0;\
		VkSurfaceKHR  __t__p1 = __p1;\
		const struct VkAllocationCallbacks * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(VkInstance , VkSurfaceKHR , const struct VkAllocationCallbacks *))*(void**)(__base - 5758))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_Vulkan_GetInstanceExtensions
#define SDL_Vulkan_GetInstanceExtensions(__p0) \
	({ \
		Uint32 * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char const *const *(*)(Uint32 *))*(void**)(__base - 5764))(__t__p0));\
	})
#endif

#ifndef SDL_Vulkan_GetPresentationSupport
#define SDL_Vulkan_GetPresentationSupport(__p0, __p1, __p2) \
	({ \
		VkInstance  __t__p0 = __p0;\
		VkPhysicalDevice  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(VkInstance , VkPhysicalDevice , Uint32 ))*(void**)(__base - 5770))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_Vulkan_GetVkGetInstanceProcAddr
#define SDL_Vulkan_GetVkGetInstanceProcAddr() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_FunctionPointer (*)(void))*(void**)(__base - 5776))());\
	})
#endif

#ifndef SDL_Vulkan_LoadLibrary
#define SDL_Vulkan_LoadLibrary(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *))*(void**)(__base - 5782))(__t__p0));\
	})
#endif

#ifndef SDL_Vulkan_UnloadLibrary
#define SDL_Vulkan_UnloadLibrary() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 5788))());\
	})
#endif

#ifndef SDL_WaitCondition
#define SDL_WaitCondition(__p0, __p1) \
	({ \
		SDL_Condition * __t__p0 = __p0;\
		SDL_Mutex * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Condition *, SDL_Mutex *))*(void**)(__base - 5794))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WaitConditionTimeout
#define SDL_WaitConditionTimeout(__p0, __p1, __p2) \
	({ \
		SDL_Condition * __t__p0 = __p0;\
		SDL_Mutex * __t__p1 = __p1;\
		Sint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Condition *, SDL_Mutex *, Sint32 ))*(void**)(__base - 5800))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WaitEvent
#define SDL_WaitEvent(__p0) \
	({ \
		SDL_Event * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Event *))*(void**)(__base - 5806))(__t__p0));\
	})
#endif

#ifndef SDL_WaitEventTimeout
#define SDL_WaitEventTimeout(__p0, __p1) \
	({ \
		SDL_Event * __t__p0 = __p0;\
		Sint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Event *, Sint32 ))*(void**)(__base - 5812))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WaitForGPUFences
#define SDL_WaitForGPUFences(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		SDL_GPUFence *const * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, bool , SDL_GPUFence *const *, Uint32 ))*(void**)(__base - 5818))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_WaitForGPUIdle
#define SDL_WaitForGPUIdle(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *))*(void**)(__base - 5824))(__t__p0));\
	})
#endif

#ifndef SDL_WaitProcess
#define SDL_WaitProcess(__p0, __p1, __p2) \
	({ \
		SDL_Process * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Process *, bool , int *))*(void**)(__base - 5830))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WaitSemaphore
#define SDL_WaitSemaphore(__p0) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Semaphore *))*(void**)(__base - 5836))(__t__p0));\
	})
#endif

#ifndef SDL_WaitSemaphoreTimeout
#define SDL_WaitSemaphoreTimeout(__p0, __p1) \
	({ \
		SDL_Semaphore * __t__p0 = __p0;\
		Sint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Semaphore *, Sint32 ))*(void**)(__base - 5842))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WaitThread
#define SDL_WaitThread(__p0, __p1) \
	({ \
		SDL_Thread * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Thread *, int *))*(void**)(__base - 5848))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WarpMouseGlobal
#define SDL_WarpMouseGlobal(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(float , float ))*(void**)(__base - 5854))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WarpMouseInWindow
#define SDL_WarpMouseInWindow(__p0, __p1, __p2) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Window *, float , float ))*(void**)(__base - 5860))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WasInit
#define SDL_WasInit(__p0) \
	({ \
		SDL_InitFlags  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_InitFlags (*)(SDL_InitFlags ))*(void**)(__base - 5866))(__t__p0));\
	})
#endif

#ifndef SDL_WindowHasSurface
#define SDL_WindowHasSurface(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *))*(void**)(__base - 5872))(__t__p0));\
	})
#endif

#ifndef SDL_WindowSupportsGPUPresentMode
#define SDL_WindowSupportsGPUPresentMode(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		SDL_GPUPresentMode  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_Window *, SDL_GPUPresentMode ))*(void**)(__base - 5878))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WindowSupportsGPUSwapchainComposition
#define SDL_WindowSupportsGPUSwapchainComposition(__p0, __p1, __p2) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		SDL_GPUSwapchainComposition  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_Window *, SDL_GPUSwapchainComposition ))*(void**)(__base - 5884))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WriteIO
#define SDL_WriteIO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(SDL_IOStream *, const void *, size_t ))*(void**)(__base - 5890))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_WriteS16BE
#define SDL_WriteS16BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint16  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint16 ))*(void**)(__base - 5896))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS16LE
#define SDL_WriteS16LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint16  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint16 ))*(void**)(__base - 5902))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS32BE
#define SDL_WriteS32BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint32 ))*(void**)(__base - 5908))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS32LE
#define SDL_WriteS32LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint32 ))*(void**)(__base - 5914))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS64BE
#define SDL_WriteS64BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint64 ))*(void**)(__base - 5920))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS64LE
#define SDL_WriteS64LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint64 ))*(void**)(__base - 5926))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteS8
#define SDL_WriteS8(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Sint8  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Sint8 ))*(void**)(__base - 5932))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteStorageFile
#define SDL_WriteStorageFile(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Storage * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		Uint64  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Storage *, const char *, const void *, Uint64 ))*(void**)(__base - 5938))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_WriteSurfacePixel
#define SDL_WriteSurfacePixel(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		Uint8  __t__p5 = __p5;\
		Uint8  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, int , int , Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)(__base - 5944))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_WriteSurfacePixelFloat
#define SDL_WriteSurfacePixelFloat(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		float  __t__p5 = __p5;\
		float  __t__p6 = __p6;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, int , int , float , float , float , float ))*(void**)(__base - 5950))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef SDL_WriteU16BE
#define SDL_WriteU16BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint16 ))*(void**)(__base - 5956))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU16LE
#define SDL_WriteU16LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint16 ))*(void**)(__base - 5962))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU32BE
#define SDL_WriteU32BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint32 ))*(void**)(__base - 5968))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU32LE
#define SDL_WriteU32LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint32 ))*(void**)(__base - 5974))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU64BE
#define SDL_WriteU64BE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint64 ))*(void**)(__base - 5980))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU64LE
#define SDL_WriteU64LE(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint64  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint64 ))*(void**)(__base - 5986))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WriteU8
#define SDL_WriteU8(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, Uint8 ))*(void**)(__base - 5992))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_abs
#define SDL_abs(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 5998))(__t__p0));\
	})
#endif

#ifndef SDL_acos
#define SDL_acos(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6004))(__t__p0));\
	})
#endif

#ifndef SDL_acosf
#define SDL_acosf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6010))(__t__p0));\
	})
#endif

#ifndef SDL_aligned_alloc
#define SDL_aligned_alloc(__p0, __p1) \
	({ \
		size_t  __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(size_t , size_t ))*(void**)(__base - 6016))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_aligned_free
#define SDL_aligned_free(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *))*(void**)(__base - 6022))(__t__p0));\
	})
#endif

#ifndef SDL_asin
#define SDL_asin(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6028))(__t__p0));\
	})
#endif

#ifndef SDL_asinf
#define SDL_asinf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6034))(__t__p0));\
	})
#endif

#ifndef SDL_atan
#define SDL_atan(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6040))(__t__p0));\
	})
#endif

#ifndef SDL_atan2
#define SDL_atan2(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , double ))*(void**)(__base - 6046))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_atan2f
#define SDL_atan2f(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , float ))*(void**)(__base - 6052))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_atanf
#define SDL_atanf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6058))(__t__p0));\
	})
#endif

#ifndef SDL_atof
#define SDL_atof(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(const char *))*(void**)(__base - 6064))(__t__p0));\
	})
#endif

#ifndef SDL_atoi
#define SDL_atoi(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 6070))(__t__p0));\
	})
#endif

#ifndef SDL_bsearch
#define SDL_bsearch(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const void * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		SDL_CompareCallback  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(const void *, const void *, size_t , size_t , SDL_CompareCallback ))*(void**)(__base - 6076))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_bsearch_r
#define SDL_bsearch_r(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		const void * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		SDL_CompareCallback_r  __t__p4 = __p4;\
		void * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(const void *, const void *, size_t , size_t , SDL_CompareCallback_r , void *))*(void**)(__base - 6082))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_calloc
#define SDL_calloc(__p0, __p1) \
	({ \
		size_t  __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(size_t , size_t ))*(void**)(__base - 6088))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_ceil
#define SDL_ceil(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6094))(__t__p0));\
	})
#endif

#ifndef SDL_ceilf
#define SDL_ceilf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6100))(__t__p0));\
	})
#endif

#ifndef SDL_copysign
#define SDL_copysign(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , double ))*(void**)(__base - 6106))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_copysignf
#define SDL_copysignf(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , float ))*(void**)(__base - 6112))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_cos
#define SDL_cos(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6118))(__t__p0));\
	})
#endif

#ifndef SDL_cosf
#define SDL_cosf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6124))(__t__p0));\
	})
#endif

#ifndef SDL_crc16
#define SDL_crc16(__p0, __p1, __p2) \
	({ \
		Uint16  __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint16 (*)(Uint16 , const void *, size_t ))*(void**)(__base - 6130))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_crc32
#define SDL_crc32(__p0, __p1, __p2) \
	({ \
		Uint32  __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(Uint32 , const void *, size_t ))*(void**)(__base - 6136))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_exp
#define SDL_exp(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6142))(__t__p0));\
	})
#endif

#ifndef SDL_expf
#define SDL_expf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6148))(__t__p0));\
	})
#endif

#ifndef SDL_fabs
#define SDL_fabs(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6154))(__t__p0));\
	})
#endif

#ifndef SDL_fabsf
#define SDL_fabsf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6160))(__t__p0));\
	})
#endif

#ifndef SDL_floor
#define SDL_floor(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6166))(__t__p0));\
	})
#endif

#ifndef SDL_floorf
#define SDL_floorf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6172))(__t__p0));\
	})
#endif

#ifndef SDL_fmod
#define SDL_fmod(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , double ))*(void**)(__base - 6178))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_fmodf
#define SDL_fmodf(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , float ))*(void**)(__base - 6184))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_free
#define SDL_free(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *))*(void**)(__base - 6190))(__t__p0));\
	})
#endif

#ifndef SDL_getenv
#define SDL_getenv(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const char *))*(void**)(__base - 6196))(__t__p0));\
	})
#endif

#ifndef SDL_getenv_unsafe
#define SDL_getenv_unsafe(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const char *))*(void**)(__base - 6202))(__t__p0));\
	})
#endif

#ifndef SDL_iconv
#define SDL_iconv(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_iconv_t  __t__p0 = __p0;\
		const char ** __t__p1 = __p1;\
		size_t * __t__p2 = __p2;\
		char ** __t__p3 = __p3;\
		size_t * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(SDL_iconv_t , const char **, size_t *, char **, size_t *))*(void**)(__base - 6340))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_iconv_close
#define SDL_iconv_close(__p0) \
	({ \
		SDL_iconv_t  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_iconv_t ))*(void**)(__base - 6346))(__t__p0));\
	})
#endif

#ifndef SDL_iconv_open
#define SDL_iconv_open(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_iconv_t (*)(const char *, const char *))*(void**)(__base - 6352))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_iconv_string
#define SDL_iconv_string(__p0, __p1, __p2, __p3) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *, const char *, size_t ))*(void**)(__base - 6358))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_isalnum
#define SDL_isalnum(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6364))(__t__p0));\
	})
#endif

#ifndef SDL_isalpha
#define SDL_isalpha(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6370))(__t__p0));\
	})
#endif

#ifndef SDL_isblank
#define SDL_isblank(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6376))(__t__p0));\
	})
#endif

#ifndef SDL_iscntrl
#define SDL_iscntrl(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6382))(__t__p0));\
	})
#endif

#ifndef SDL_isdigit
#define SDL_isdigit(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6388))(__t__p0));\
	})
#endif

#ifndef SDL_isgraph
#define SDL_isgraph(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6394))(__t__p0));\
	})
#endif

#ifndef SDL_isinf
#define SDL_isinf(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(double ))*(void**)(__base - 6400))(__t__p0));\
	})
#endif

#ifndef SDL_isinff
#define SDL_isinff(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(float ))*(void**)(__base - 6406))(__t__p0));\
	})
#endif

#ifndef SDL_islower
#define SDL_islower(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6412))(__t__p0));\
	})
#endif

#ifndef SDL_isnan
#define SDL_isnan(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(double ))*(void**)(__base - 6418))(__t__p0));\
	})
#endif

#ifndef SDL_isnanf
#define SDL_isnanf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(float ))*(void**)(__base - 6424))(__t__p0));\
	})
#endif

#ifndef SDL_isprint
#define SDL_isprint(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6430))(__t__p0));\
	})
#endif

#ifndef SDL_ispunct
#define SDL_ispunct(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6436))(__t__p0));\
	})
#endif

#ifndef SDL_isspace
#define SDL_isspace(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6442))(__t__p0));\
	})
#endif

#ifndef SDL_isupper
#define SDL_isupper(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6448))(__t__p0));\
	})
#endif

#ifndef SDL_isxdigit
#define SDL_isxdigit(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6454))(__t__p0));\
	})
#endif

#ifndef SDL_itoa
#define SDL_itoa(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(int , char *, int ))*(void**)(__base - 6460))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_lltoa
#define SDL_lltoa(__p0, __p1, __p2) \
	({ \
		long long  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(long long , char *, int ))*(void**)(__base - 6466))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_log
#define SDL_log(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6472))(__t__p0));\
	})
#endif

#ifndef SDL_log10
#define SDL_log10(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6478))(__t__p0));\
	})
#endif

#ifndef SDL_log10f
#define SDL_log10f(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6484))(__t__p0));\
	})
#endif

#ifndef SDL_logf
#define SDL_logf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6490))(__t__p0));\
	})
#endif

#ifndef SDL_lround
#define SDL_lround(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long (*)(double ))*(void**)(__base - 6496))(__t__p0));\
	})
#endif

#ifndef SDL_lroundf
#define SDL_lroundf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long (*)(float ))*(void**)(__base - 6502))(__t__p0));\
	})
#endif

#ifndef SDL_ltoa
#define SDL_ltoa(__p0, __p1, __p2) \
	({ \
		long  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(long , char *, int ))*(void**)(__base - 6508))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_malloc
#define SDL_malloc(__p0) \
	({ \
		size_t  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(size_t ))*(void**)(__base - 6514))(__t__p0));\
	})
#endif

#ifndef SDL_memcmp
#define SDL_memcmp(__p0, __p1, __p2) \
	({ \
		const void * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const void *, const void *, size_t ))*(void**)(__base - 6520))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_memcpy
#define SDL_memcpy(__p0, __p1, __p2) \
	({ \
		void * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, const void *, size_t ))*(void**)(__base - 6526))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_memmove
#define SDL_memmove(__p0, __p1, __p2) \
	({ \
		void * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, const void *, size_t ))*(void**)(__base - 6532))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_memset
#define SDL_memset(__p0, __p1, __p2) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, int , size_t ))*(void**)(__base - 6538))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_memset4
#define SDL_memset4(__p0, __p1, __p2) \
	({ \
		void * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, Uint32 , size_t ))*(void**)(__base - 6544))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_modf
#define SDL_modf(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		double * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , double *))*(void**)(__base - 6550))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_modff
#define SDL_modff(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , float *))*(void**)(__base - 6556))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_murmur3_32
#define SDL_murmur3_32(__p0, __p1, __p2) \
	({ \
		const void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const void *, size_t , Uint32 ))*(void**)(__base - 6562))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_pow
#define SDL_pow(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , double ))*(void**)(__base - 6568))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_powf
#define SDL_powf(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , float ))*(void**)(__base - 6574))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_qsort
#define SDL_qsort(__p0, __p1, __p2, __p3) \
	({ \
		void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_CompareCallback  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, size_t , size_t , SDL_CompareCallback ))*(void**)(__base - 6580))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_qsort_r
#define SDL_qsort_r(__p0, __p1, __p2, __p3, __p4) \
	({ \
		void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_CompareCallback_r  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, size_t , size_t , SDL_CompareCallback_r , void *))*(void**)(__base - 6586))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_rand
#define SDL_rand(__p0) \
	({ \
		Sint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint32 (*)(Sint32 ))*(void**)(__base - 6592))(__t__p0));\
	})
#endif

#ifndef SDL_rand_bits
#define SDL_rand_bits() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(void))*(void**)(__base - 6598))());\
	})
#endif

#ifndef SDL_rand_bits_r
#define SDL_rand_bits_r(__p0) \
	({ \
		Uint64 * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(Uint64 *))*(void**)(__base - 6604))(__t__p0));\
	})
#endif

#ifndef SDL_rand_r
#define SDL_rand_r(__p0, __p1) \
	({ \
		Uint64 * __t__p0 = __p0;\
		Sint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint32 (*)(Uint64 *, Sint32 ))*(void**)(__base - 6610))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_randf
#define SDL_randf() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(void))*(void**)(__base - 6616))());\
	})
#endif

#ifndef SDL_randf_r
#define SDL_randf_r(__p0) \
	({ \
		Uint64 * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(Uint64 *))*(void**)(__base - 6622))(__t__p0));\
	})
#endif

#ifndef SDL_realloc
#define SDL_realloc(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, size_t ))*(void**)(__base - 6628))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_round
#define SDL_round(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6634))(__t__p0));\
	})
#endif

#ifndef SDL_roundf
#define SDL_roundf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6640))(__t__p0));\
	})
#endif

#ifndef SDL_scalbn
#define SDL_scalbn(__p0, __p1) \
	({ \
		double  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double , int ))*(void**)(__base - 6646))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_scalbnf
#define SDL_scalbnf(__p0, __p1) \
	({ \
		float  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float , int ))*(void**)(__base - 6652))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_setenv_unsafe
#define SDL_setenv_unsafe(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, int ))*(void**)(__base - 6658))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_sin
#define SDL_sin(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6664))(__t__p0));\
	})
#endif

#ifndef SDL_sinf
#define SDL_sinf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6670))(__t__p0));\
	})
#endif

#ifndef SDL_sqrt
#define SDL_sqrt(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6676))(__t__p0));\
	})
#endif

#ifndef SDL_sqrtf
#define SDL_sqrtf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6682))(__t__p0));\
	})
#endif

#ifndef SDL_srand
#define SDL_srand(__p0) \
	({ \
		Uint64  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint64 ))*(void**)(__base - 6688))(__t__p0));\
	})
#endif

#ifndef SDL_strcasecmp
#define SDL_strcasecmp(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *))*(void**)(__base - 6694))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strcasestr
#define SDL_strcasestr(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *))*(void**)(__base - 6700))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strchr
#define SDL_strchr(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, int ))*(void**)(__base - 6706))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strcmp
#define SDL_strcmp(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *))*(void**)(__base - 6712))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strdup
#define SDL_strdup(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *))*(void**)(__base - 6718))(__t__p0));\
	})
#endif

#ifndef SDL_strlcat
#define SDL_strlcat(__p0, __p1, __p2) \
	({ \
		char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(char *, const char *, size_t ))*(void**)(__base - 6724))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strlcpy
#define SDL_strlcpy(__p0, __p1, __p2) \
	({ \
		char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(char *, const char *, size_t ))*(void**)(__base - 6730))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strlen
#define SDL_strlen(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const char *))*(void**)(__base - 6736))(__t__p0));\
	})
#endif

#ifndef SDL_strlwr
#define SDL_strlwr(__p0) \
	({ \
		char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(char *))*(void**)(__base - 6742))(__t__p0));\
	})
#endif

#ifndef SDL_strncasecmp
#define SDL_strncasecmp(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, size_t ))*(void**)(__base - 6748))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strncmp
#define SDL_strncmp(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, size_t ))*(void**)(__base - 6754))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strndup
#define SDL_strndup(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, size_t ))*(void**)(__base - 6760))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strnlen
#define SDL_strnlen(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const char *, size_t ))*(void**)(__base - 6766))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strnstr
#define SDL_strnstr(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *, size_t ))*(void**)(__base - 6772))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strpbrk
#define SDL_strpbrk(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *))*(void**)(__base - 6778))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strrchr
#define SDL_strrchr(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, int ))*(void**)(__base - 6784))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strrev
#define SDL_strrev(__p0) \
	({ \
		char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(char *))*(void**)(__base - 6790))(__t__p0));\
	})
#endif

#ifndef SDL_strstr
#define SDL_strstr(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, const char *))*(void**)(__base - 6796))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strtod
#define SDL_strtod(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(const char *, char **))*(void**)(__base - 6802))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_strtok_r
#define SDL_strtok_r(__p0, __p1, __p2) \
	({ \
		char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		char ** __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(char *, const char *, char **))*(void**)(__base - 6808))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strtol
#define SDL_strtol(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long (*)(const char *, char **, int ))*(void**)(__base - 6814))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strtoll
#define SDL_strtoll(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long long (*)(const char *, char **, int ))*(void**)(__base - 6820))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strtoul
#define SDL_strtoul(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned long (*)(const char *, char **, int ))*(void**)(__base - 6826))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strtoull
#define SDL_strtoull(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((unsigned long long (*)(const char *, char **, int ))*(void**)(__base - 6832))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_strupr
#define SDL_strupr(__p0) \
	({ \
		char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(char *))*(void**)(__base - 6838))(__t__p0));\
	})
#endif

#ifndef SDL_tan
#define SDL_tan(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6844))(__t__p0));\
	})
#endif

#ifndef SDL_tanf
#define SDL_tanf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6850))(__t__p0));\
	})
#endif

#ifndef SDL_tolower
#define SDL_tolower(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6856))(__t__p0));\
	})
#endif

#ifndef SDL_toupper
#define SDL_toupper(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 6862))(__t__p0));\
	})
#endif

#ifndef SDL_trunc
#define SDL_trunc(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(double ))*(void**)(__base - 6868))(__t__p0));\
	})
#endif

#ifndef SDL_truncf
#define SDL_truncf(__p0) \
	({ \
		float  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(float ))*(void**)(__base - 6874))(__t__p0));\
	})
#endif

#ifndef SDL_uitoa
#define SDL_uitoa(__p0, __p1, __p2) \
	({ \
		unsigned int  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(unsigned int , char *, int ))*(void**)(__base - 6880))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ulltoa
#define SDL_ulltoa(__p0, __p1, __p2) \
	({ \
		unsigned long long  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(unsigned long long , char *, int ))*(void**)(__base - 6886))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ultoa
#define SDL_ultoa(__p0, __p1, __p2) \
	({ \
		unsigned long  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(unsigned long , char *, int ))*(void**)(__base - 6892))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_unsetenv_unsafe
#define SDL_unsetenv_unsafe(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 6898))(__t__p0));\
	})
#endif

#ifndef SDL_utf8strlcpy
#define SDL_utf8strlcpy(__p0, __p1, __p2) \
	({ \
		char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(char *, const char *, size_t ))*(void**)(__base - 6904))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_utf8strlen
#define SDL_utf8strlen(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const char *))*(void**)(__base - 6910))(__t__p0));\
	})
#endif

#ifndef SDL_utf8strnlen
#define SDL_utf8strnlen(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const char *, size_t ))*(void**)(__base - 6916))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_vasprintf
#define SDL_vasprintf(__p0, __p1, __p2) \
	({ \
		char ** __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		va_list __t__p2;\
		va_copy(__t__p2, __p2);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(char **, const char *, va_list ))*(void**)(__base - 6922))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_vsnprintf
#define SDL_vsnprintf(__p0, __p1, __p2, __p3) \
	({ \
		char * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		va_list __t__p3;\
		va_copy(__t__p3, __p3);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(char *, size_t , const char *, va_list ))*(void**)(__base - 6928))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_vsscanf
#define SDL_vsscanf(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		va_list __t__p2;\
		va_copy(__t__p2, __p2);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, va_list ))*(void**)(__base - 6934))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_vswprintf
#define SDL_vswprintf(__p0, __p1, __p2, __p3) \
	({ \
		wchar_t * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		const wchar_t * __t__p2 = __p2;\
		va_list __t__p3;\
		va_copy(__t__p3, __p3);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(wchar_t *, size_t , const wchar_t *, va_list ))*(void**)(__base - 6940))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_wcscasecmp
#define SDL_wcscasecmp(__p0, __p1) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const wchar_t *, const wchar_t *))*(void**)(__base - 6946))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_wcscmp
#define SDL_wcscmp(__p0, __p1) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const wchar_t *, const wchar_t *))*(void**)(__base - 6952))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_wcsdup
#define SDL_wcsdup(__p0) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((wchar_t *(*)(const wchar_t *))*(void**)(__base - 6958))(__t__p0));\
	})
#endif

#ifndef SDL_wcslcat
#define SDL_wcslcat(__p0, __p1, __p2) \
	({ \
		wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(wchar_t *, const wchar_t *, size_t ))*(void**)(__base - 6964))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_wcslcpy
#define SDL_wcslcpy(__p0, __p1, __p2) \
	({ \
		wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(wchar_t *, const wchar_t *, size_t ))*(void**)(__base - 6970))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_wcslen
#define SDL_wcslen(__p0) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const wchar_t *))*(void**)(__base - 6976))(__t__p0));\
	})
#endif

#ifndef SDL_wcsncasecmp
#define SDL_wcsncasecmp(__p0, __p1, __p2) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const wchar_t *, const wchar_t *, size_t ))*(void**)(__base - 6982))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_wcsncmp
#define SDL_wcsncmp(__p0, __p1, __p2) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const wchar_t *, const wchar_t *, size_t ))*(void**)(__base - 6988))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_wcsnlen
#define SDL_wcsnlen(__p0, __p1) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		size_t  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((size_t (*)(const wchar_t *, size_t ))*(void**)(__base - 6994))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_wcsnstr
#define SDL_wcsnstr(__p0, __p1, __p2) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((wchar_t *(*)(const wchar_t *, const wchar_t *, size_t ))*(void**)(__base - 7000))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_wcsstr
#define SDL_wcsstr(__p0, __p1) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		const wchar_t * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((wchar_t *(*)(const wchar_t *, const wchar_t *))*(void**)(__base - 7006))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_wcstol
#define SDL_wcstol(__p0, __p1, __p2) \
	({ \
		const wchar_t * __t__p0 = __p0;\
		wchar_t ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long (*)(const wchar_t *, wchar_t **, int ))*(void**)(__base - 7012))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_StepBackUTF8
#define SDL_StepBackUTF8(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char ** __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const char *, const char **))*(void**)(__base - 7018))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_DelayPrecise
#define SDL_DelayPrecise(__p0) \
	({ \
		Uint64  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint64 ))*(void**)(__base - 7024))(__t__p0));\
	})
#endif

#ifndef SDL_CalculateGPUTextureFormatSize
#define SDL_CalculateGPUTextureFormatSize(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPUTextureFormat  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_GPUTextureFormat , Uint32 , Uint32 , Uint32 ))*(void**)(__base - 7030))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetErrorV
#define SDL_SetErrorV(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		va_list __t__p1;\
		va_copy(__t__p1, __p1);\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, va_list ))*(void**)(__base - 7036))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDefaultLogOutputFunction
#define SDL_GetDefaultLogOutputFunction() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_LogOutputFunction (*)(void))*(void**)(__base - 7042))());\
	})
#endif

#ifndef SDL_RenderDebugText
#define SDL_RenderDebugText(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, float , float , const char *))*(void**)(__base - 7048))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetSandbox
#define SDL_GetSandbox() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Sandbox (*)(void))*(void**)(__base - 7054))());\
	})
#endif

#ifndef SDL_CancelGPUCommandBuffer
#define SDL_CancelGPUCommandBuffer(__p0) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUCommandBuffer *))*(void**)(__base - 7060))(__t__p0));\
	})
#endif

#ifndef SDL_SaveFile_IO
#define SDL_SaveFile_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *, const void *, size_t , bool ))*(void**)(__base - 7066))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SaveFile
#define SDL_SaveFile(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, const void *, size_t ))*(void**)(__base - 7072))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetCurrentDirectory
#define SDL_GetCurrentDirectory() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(void))*(void**)(__base - 7078))());\
	})
#endif

#ifndef SDL_IsAudioDevicePhysical
#define SDL_IsAudioDevicePhysical(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID ))*(void**)(__base - 7084))(__t__p0));\
	})
#endif

#ifndef SDL_IsAudioDevicePlayback
#define SDL_IsAudioDevicePlayback(__p0) \
	({ \
		SDL_AudioDeviceID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioDeviceID ))*(void**)(__base - 7090))(__t__p0));\
	})
#endif

#ifndef SDL_AsyncIOFromFile
#define SDL_AsyncIOFromFile(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AsyncIO *(*)(const char *, const char *))*(void**)(__base - 7096))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetAsyncIOSize
#define SDL_GetAsyncIOSize(__p0) \
	({ \
		SDL_AsyncIO * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sint64 (*)(SDL_AsyncIO *))*(void**)(__base - 7102))(__t__p0));\
	})
#endif

#ifndef SDL_ReadAsyncIO
#define SDL_ReadAsyncIO(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_AsyncIO * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		Uint64  __t__p2 = __p2;\
		Uint64  __t__p3 = __p3;\
		SDL_AsyncIOQueue * __t__p4 = __p4;\
		void * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AsyncIO *, void *, Uint64 , Uint64 , SDL_AsyncIOQueue *, void *))*(void**)(__base - 7108))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_WriteAsyncIO
#define SDL_WriteAsyncIO(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_AsyncIO * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		Uint64  __t__p2 = __p2;\
		Uint64  __t__p3 = __p3;\
		SDL_AsyncIOQueue * __t__p4 = __p4;\
		void * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AsyncIO *, void *, Uint64 , Uint64 , SDL_AsyncIOQueue *, void *))*(void**)(__base - 7114))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_CloseAsyncIO
#define SDL_CloseAsyncIO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_AsyncIO * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		SDL_AsyncIOQueue * __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AsyncIO *, bool , SDL_AsyncIOQueue *, void *))*(void**)(__base - 7120))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_CreateAsyncIOQueue
#define SDL_CreateAsyncIOQueue() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_AsyncIOQueue *(*)(void))*(void**)(__base - 7126))());\
	})
#endif

#ifndef SDL_DestroyAsyncIOQueue
#define SDL_DestroyAsyncIOQueue(__p0) \
	({ \
		SDL_AsyncIOQueue * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AsyncIOQueue *))*(void**)(__base - 7132))(__t__p0));\
	})
#endif

#ifndef SDL_GetAsyncIOResult
#define SDL_GetAsyncIOResult(__p0, __p1) \
	({ \
		SDL_AsyncIOQueue * __t__p0 = __p0;\
		SDL_AsyncIOOutcome * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AsyncIOQueue *, SDL_AsyncIOOutcome *))*(void**)(__base - 7138))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WaitAsyncIOResult
#define SDL_WaitAsyncIOResult(__p0, __p1, __p2) \
	({ \
		SDL_AsyncIOQueue * __t__p0 = __p0;\
		SDL_AsyncIOOutcome * __t__p1 = __p1;\
		Sint32  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AsyncIOQueue *, SDL_AsyncIOOutcome *, Sint32 ))*(void**)(__base - 7144))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SignalAsyncIOQueue
#define SDL_SignalAsyncIOQueue(__p0) \
	({ \
		SDL_AsyncIOQueue * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_AsyncIOQueue *))*(void**)(__base - 7150))(__t__p0));\
	})
#endif

#ifndef SDL_LoadFileAsync
#define SDL_LoadFileAsync(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		SDL_AsyncIOQueue * __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const char *, SDL_AsyncIOQueue *, void *))*(void**)(__base - 7156))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_ShowFileDialogWithProperties
#define SDL_ShowFileDialogWithProperties(__p0, __p1, __p2, __p3) \
	({ \
		SDL_FileDialogType  __t__p0 = __p0;\
		SDL_DialogFileCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		SDL_PropertiesID  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_FileDialogType , SDL_DialogFileCallback , void *, SDL_PropertiesID ))*(void**)(__base - 7162))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_IsMainThread
#define SDL_IsMainThread() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 7168))());\
	})
#endif

#ifndef SDL_RunOnMainThread
#define SDL_RunOnMainThread(__p0, __p1, __p2) \
	({ \
		SDL_MainThreadCallback  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_MainThreadCallback , void *, bool ))*(void**)(__base - 7174))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SetGPUAllowedFramesInFlight
#define SDL_SetGPUAllowedFramesInFlight(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, Uint32 ))*(void**)(__base - 7180))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenderTextureAffine
#define SDL_RenderTextureAffine(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		const SDL_FPoint * __t__p3 = __p3;\
		const SDL_FPoint * __t__p4 = __p4;\
		const SDL_FPoint * __t__p5 = __p5;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, const SDL_FPoint *, const SDL_FPoint *, const SDL_FPoint *))*(void**)(__base - 7186))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef SDL_WaitForGPUSwapchain
#define SDL_WaitForGPUSwapchain(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUDevice *, SDL_Window *))*(void**)(__base - 7192))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_WaitAndAcquireGPUSwapchainTexture
#define SDL_WaitAndAcquireGPUSwapchainTexture(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPUCommandBuffer * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		SDL_GPUTexture ** __t__p2 = __p2;\
		Uint32 * __t__p3 = __p3;\
		Uint32 * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPUCommandBuffer *, SDL_Window *, SDL_GPUTexture **, Uint32 *, Uint32 *))*(void**)(__base - 7198))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_CreateTray
#define SDL_CreateTray(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Tray *(*)(SDL_Surface *, const char *))*(void**)(__base - 7204))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTrayIcon
#define SDL_SetTrayIcon(__p0, __p1) \
	({ \
		SDL_Tray * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Tray *, SDL_Surface *))*(void**)(__base - 7210))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetTrayTooltip
#define SDL_SetTrayTooltip(__p0, __p1) \
	({ \
		SDL_Tray * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Tray *, const char *))*(void**)(__base - 7216))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateTrayMenu
#define SDL_CreateTrayMenu(__p0) \
	({ \
		SDL_Tray * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayMenu *(*)(SDL_Tray *))*(void**)(__base - 7222))(__t__p0));\
	})
#endif

#ifndef SDL_CreateTraySubmenu
#define SDL_CreateTraySubmenu(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayMenu *(*)(SDL_TrayEntry *))*(void**)(__base - 7228))(__t__p0));\
	})
#endif

#ifndef SDL_GetTrayMenu
#define SDL_GetTrayMenu(__p0) \
	({ \
		SDL_Tray * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayMenu *(*)(SDL_Tray *))*(void**)(__base - 7234))(__t__p0));\
	})
#endif

#ifndef SDL_GetTraySubmenu
#define SDL_GetTraySubmenu(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayMenu *(*)(SDL_TrayEntry *))*(void**)(__base - 7240))(__t__p0));\
	})
#endif

#ifndef SDL_GetTrayEntries
#define SDL_GetTrayEntries(__p0, __p1) \
	({ \
		SDL_TrayMenu * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_TrayEntry **(*)(SDL_TrayMenu *, int *))*(void**)(__base - 7246))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RemoveTrayEntry
#define SDL_RemoveTrayEntry(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *))*(void**)(__base - 7252))(__t__p0));\
	})
#endif

#ifndef SDL_InsertTrayEntryAt
#define SDL_InsertTrayEntryAt(__p0, __p1, __p2, __p3) \
	({ \
		SDL_TrayMenu * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		SDL_TrayEntryFlags  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayEntry *(*)(SDL_TrayMenu *, int , const char *, SDL_TrayEntryFlags ))*(void**)(__base - 7258))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetTrayEntryLabel
#define SDL_SetTrayEntryLabel(__p0, __p1) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *, const char *))*(void**)(__base - 7264))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTrayEntryLabel
#define SDL_GetTrayEntryLabel(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(SDL_TrayEntry *))*(void**)(__base - 7270))(__t__p0));\
	})
#endif

#ifndef SDL_SetTrayEntryChecked
#define SDL_SetTrayEntryChecked(__p0, __p1) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *, bool ))*(void**)(__base - 7276))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTrayEntryChecked
#define SDL_GetTrayEntryChecked(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_TrayEntry *))*(void**)(__base - 7282))(__t__p0));\
	})
#endif

#ifndef SDL_SetTrayEntryEnabled
#define SDL_SetTrayEntryEnabled(__p0, __p1) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *, bool ))*(void**)(__base - 7288))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTrayEntryEnabled
#define SDL_GetTrayEntryEnabled(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_TrayEntry *))*(void**)(__base - 7294))(__t__p0));\
	})
#endif

#ifndef SDL_SetTrayEntryCallback
#define SDL_SetTrayEntryCallback(__p0, __p1, __p2) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		SDL_TrayCallback  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *, SDL_TrayCallback , void *))*(void**)(__base - 7300))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_DestroyTray
#define SDL_DestroyTray(__p0) \
	({ \
		SDL_Tray * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_Tray *))*(void**)(__base - 7306))(__t__p0));\
	})
#endif

#ifndef SDL_GetTrayEntryParent
#define SDL_GetTrayEntryParent(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayMenu *(*)(SDL_TrayEntry *))*(void**)(__base - 7312))(__t__p0));\
	})
#endif

#ifndef SDL_GetTrayMenuParentEntry
#define SDL_GetTrayMenuParentEntry(__p0) \
	({ \
		SDL_TrayMenu * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_TrayEntry *(*)(SDL_TrayMenu *))*(void**)(__base - 7318))(__t__p0));\
	})
#endif

#ifndef SDL_GetTrayMenuParentTray
#define SDL_GetTrayMenuParentTray(__p0) \
	({ \
		SDL_TrayMenu * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Tray *(*)(SDL_TrayMenu *))*(void**)(__base - 7324))(__t__p0));\
	})
#endif

#ifndef SDL_GetThreadState
#define SDL_GetThreadState(__p0) \
	({ \
		SDL_Thread * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_ThreadState (*)(SDL_Thread *))*(void**)(__base - 7330))(__t__p0));\
	})
#endif

#ifndef SDL_AudioStreamDevicePaused
#define SDL_AudioStreamDevicePaused(__p0) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *))*(void**)(__base - 7336))(__t__p0));\
	})
#endif

#ifndef SDL_ClickTrayEntry
#define SDL_ClickTrayEntry(__p0) \
	({ \
		SDL_TrayEntry * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_TrayEntry *))*(void**)(__base - 7342))(__t__p0));\
	})
#endif

#ifndef SDL_UpdateTrays
#define SDL_UpdateTrays() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 7348))());\
	})
#endif

#ifndef SDL_StretchSurface
#define SDL_StretchSurface(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const SDL_Rect * __t__p1 = __p1;\
		SDL_Surface * __t__p2 = __p2;\
		const SDL_Rect * __t__p3 = __p3;\
		SDL_ScaleMode  __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const SDL_Rect *, SDL_Surface *, const SDL_Rect *, SDL_ScaleMode ))*(void**)(__base - 7354))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_SetRelativeMouseTransform
#define SDL_SetRelativeMouseTransform(__p0, __p1) \
	({ \
		SDL_MouseMotionTransformCallback  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_MouseMotionTransformCallback , void *))*(void**)(__base - 7360))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_RenderTexture9GridTiled
#define SDL_RenderTexture9GridTiled(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_Texture * __t__p1 = __p1;\
		const SDL_FRect * __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		float  __t__p5 = __p5;\
		float  __t__p6 = __p6;\
		float  __t__p7 = __p7;\
		const SDL_FRect * __t__p8 = __p8;\
		float  __t__p9 = __p9;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_Texture *, const SDL_FRect *, float , float , float , float , float , const SDL_FRect *, float ))*(void**)(__base - 7366))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})
#endif

#ifndef SDL_SetDefaultTextureScaleMode
#define SDL_SetDefaultTextureScaleMode(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_ScaleMode  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_ScaleMode ))*(void**)(__base - 7372))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetDefaultTextureScaleMode
#define SDL_GetDefaultTextureScaleMode(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_ScaleMode * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_ScaleMode *))*(void**)(__base - 7378))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_CreateGPURenderState
#define SDL_CreateGPURenderState(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const SDL_GPURenderStateCreateInfo * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPURenderState *(*)(SDL_Renderer *, const SDL_GPURenderStateCreateInfo *))*(void**)(__base - 7384))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetGPURenderStateFragmentUniforms
#define SDL_SetGPURenderStateFragmentUniforms(__p0, __p1, __p2, __p3) \
	({ \
		SDL_GPURenderState * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_GPURenderState *, Uint32 , const void *, Uint32 ))*(void**)(__base - 7390))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_SetGPURenderState
#define SDL_SetGPURenderState(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_GPURenderState * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_GPURenderState *))*(void**)(__base - 7396))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_DestroyGPURenderState
#define SDL_DestroyGPURenderState(__p0) \
	({ \
		SDL_GPURenderState * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDL_GPURenderState *))*(void**)(__base - 7402))(__t__p0));\
	})
#endif

#ifndef SDL_SetWindowProgressState
#define SDL_SetWindowProgressState(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		SDL_ProgressState  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, SDL_ProgressState ))*(void**)(__base - 7408))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_SetWindowProgressValue
#define SDL_SetWindowProgressValue(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, float ))*(void**)(__base - 7414))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetWindowProgressState
#define SDL_GetWindowProgressState(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_ProgressState (*)(SDL_Window *))*(void**)(__base - 7420))(__t__p0));\
	})
#endif

#ifndef SDL_GetWindowProgressValue
#define SDL_GetWindowProgressValue(__p0) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(SDL_Window *))*(void**)(__base - 7426))(__t__p0));\
	})
#endif

#ifndef SDL_SetRenderTextureAddressMode
#define SDL_SetRenderTextureAddressMode(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_TextureAddressMode  __t__p1 = __p1;\
		SDL_TextureAddressMode  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_TextureAddressMode , SDL_TextureAddressMode ))*(void**)(__base - 7432))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetRenderTextureAddressMode
#define SDL_GetRenderTextureAddressMode(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_TextureAddressMode * __t__p1 = __p1;\
		SDL_TextureAddressMode * __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Renderer *, SDL_TextureAddressMode *, SDL_TextureAddressMode *))*(void**)(__base - 7438))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_GetGPUDeviceProperties
#define SDL_GetGPUDeviceProperties(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(SDL_GPUDevice *))*(void**)(__base - 7444))(__t__p0));\
	})
#endif

#ifndef SDL_CreateGPURenderer
#define SDL_CreateGPURenderer(__p0, __p1) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_Window * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Renderer *(*)(SDL_GPUDevice *, SDL_Window *))*(void**)(__base - 7450))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_PutAudioStreamPlanarData
#define SDL_PutAudioStreamPlanarData(__p0, __p1, __p2, __p3) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const void *const * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const void *const *, int , int ))*(void**)(__base - 7456))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_GetEventDescription
#define SDL_GetEventDescription(__p0, __p1, __p2) \
	({ \
		const SDL_Event * __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const SDL_Event *, char *, int ))*(void**)(__base - 7462))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_PutAudioStreamDataNoCopy
#define SDL_PutAudioStreamDataNoCopy(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_AudioStream * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_AudioStreamDataCompleteCallback  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_AudioStream *, const void *, int , SDL_AudioStreamDataCompleteCallback , void *))*(void**)(__base - 7468))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef SDL_AddAtomicU32
#define SDL_AddAtomicU32(__p0, __p1) \
	({ \
		SDL_AtomicU32 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(SDL_AtomicU32 *, int ))*(void**)(__base - 7474))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetPixelFormatFromGPUTextureFormat
#define SDL_GetPixelFormatFromGPUTextureFormat(__p0) \
	({ \
		SDL_GPUTextureFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PixelFormat (*)(SDL_GPUTextureFormat ))*(void**)(__base - 7486))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPUTextureFormatFromPixelFormat
#define SDL_GetGPUTextureFormatFromPixelFormat(__p0) \
	({ \
		SDL_PixelFormat  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTextureFormat (*)(SDL_PixelFormat ))*(void**)(__base - 7492))(__t__p0));\
	})
#endif

#ifndef SDL_SetTexturePalette
#define SDL_SetTexturePalette(__p0, __p1) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		SDL_Palette * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Texture *, SDL_Palette *))*(void**)(__base - 7504))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetTexturePalette
#define SDL_GetTexturePalette(__p0) \
	({ \
		SDL_Texture * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Palette *(*)(SDL_Texture *))*(void**)(__base - 7510))(__t__p0));\
	})
#endif

#ifndef SDL_GetGPURendererDevice
#define SDL_GetGPURendererDevice(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUDevice *(*)(SDL_Renderer *))*(void**)(__base - 7516))(__t__p0));\
	})
#endif

#ifndef SDL_LoadPNG_IO
#define SDL_LoadPNG_IO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, bool ))*(void**)(__base - 7522))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadPNG
#define SDL_LoadPNG(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(const char *))*(void**)(__base - 7528))(__t__p0));\
	})
#endif

#ifndef SDL_SavePNG_IO
#define SDL_SavePNG_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 7534))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef SDL_SavePNG
#define SDL_SavePNG(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 7540))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_GetSystemPageSize
#define SDL_GetSystemPageSize() \
	({ \
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 7546))());\
	})
#endif

#ifndef SDL_GetPenDeviceType
#define SDL_GetPenDeviceType(__p0) \
	({ \
		SDL_PenID  __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PenDeviceType (*)(SDL_PenID ))*(void**)(__base - 7552))(__t__p0));\
	})
#endif

#ifndef SDL_CreateAnimatedCursor
#define SDL_CreateAnimatedCursor(__p0, __p1, __p2, __p3) \
	({ \
		SDL_CursorFrameInfo * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(SDL_CursorFrameInfo *, int , int , int ))*(void**)(__base - 7558))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef SDL_RotateSurface
#define SDL_RotateSurface(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_Surface *, float ))*(void**)(__base - 7564))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadSurface_IO
#define SDL_LoadSurface_IO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, bool ))*(void**)(__base - 7570))(__t__p0, __t__p1));\
	})
#endif

#ifndef SDL_LoadSurface
#define SDL_LoadSurface(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(const char *))*(void**)(__base - 7576))(__t__p0));\
	})
#endif

#ifndef SDL_SetWindowFillDocument
#define SDL_SetWindowFillDocument(__p0, __p1) \
	({ \
		SDL_Window * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Window *, bool ))*(void**)(__base - 7582))(__t__p0, __t__p1));\
	})
#endif

#endif /* !_PPCINLINE_SDL3_H */
