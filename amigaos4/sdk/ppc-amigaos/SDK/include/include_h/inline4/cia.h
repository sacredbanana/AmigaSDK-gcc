#ifndef INLINE4_CIA_H
#define INLINE4_CIA_H
/*
** CIA Inline functions
*/ 

#include <exec/types.h>
#include <exec/exec.h>
#include <exec/libraries.h>
#include <exec/interfaces.h>

#include <resources/cia.h>
#include <exec/types.h>
#include <exec/interrupts.h>
#include <interfaces/cia.h>

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

struct _CIAResource
{
    struct Library cr_Library;
    APTR           private1;
    APTR           private2;
};

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#define ICIA_GET struct CIAIFace *Icia = (struct CIAIFace *)((struct _CIAResource *)resourcebase)->private2;

static inline struct Interrupt *AddICRVector(struct Library *resourcebase, WORD icrBit, struct Interrupt *interrupt)
{
    ICIA_GET
    return Icia->AddICRVector(resourcebase, icrBit, interrupt);
}

static inline VOID RemICRVector(struct Library *resourcebase, WORD icrBit, struct Interrupt *Interrupt)
{
    ICIA_GET
    Icia->RemICRVector(resourcebase, icrBit, Interrupt);
}

static inline WORD AbleICR(struct Library *resourcebase, WORD mask)
{
    ICIA_GET
    return Icia->AbleICR(resourcebase, mask);
}

static inline WORD SetICR(struct Library *resourcebase, WORD mask)
{
    ICIA_GET
    return Icia->SetICR(resourcebase, mask);
}
#endif
