#ifndef EXEC_INITIALIZERS_H
#define EXEC_INITIALIZERS_H
/*
**    $VER: initializers.h 53.29 (10.8.2015)
**
**    Macros for use with the InitStruct() function and the
**    V50 InitData function.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define OFFSET(structName, structEntry) \
                (&(((struct structName *) 0)->structEntry))

#define INITBYTE(offset,value) 0xe000, (uint16)(offset), (uint16)((value)<<8)
#define INITWORD(offset,value) 0xd000, (uint16)(offset), (uint16)(value)
#define INITLONG(offset,value) 0xc000, (uint16)(offset), \
                               (uint16)((value)>>16), \
                               (uint16)((value) & 0xffff)
#define INITSTRUCT(size,offset,value,count) \
                (uint16) (0xc000|(size<<12)|(count<<8)| \
                ((uint16) ((offset)>>16)), \
                ((uint16) (offset)) & 0xffff)

/****************************************************************************/

/* These macros are used for the new InitData function */
#define IDATA_QUIT        ((uint32)(0xff000000))
#define IDATA_CMOVE(n)    ((uint32)(0x01000000|(uint32)n))
#define IDATA_CSET(n)     ((uint32)(0x02000000|(uint32)n))
#define IDATA_COPY(n)     ((uint32)(0x03000000|(uint32)n))
#define IDATA_RPL(n)      ((uint32)(0x04000000|(uint32)n))
#define IDATA_RPW(n)      ((uint32)(0x05000000|(uint32)n))
#define IDATA_RPB(n)      ((uint32)(0x06000000|(uint32)n))
#define IDATA_OFFS(n)     ((uint32)(0x07000000|(uint32)n))

#define IDATA_B1(a)       ((uint32)((uint32)(a)<<24) )
#define IDATA_B2(a,b)     ((uint32)(((uint32)(a)<<24) | ((uint32)(b)<<16) ) )
#define IDATA_B3(a,b,c)   ((uint32)(((uint32)(a)<<24) | ((uint32)(b)<<16) | ((uint32)(c)<<8) ) )
#define IDATA_B4(a,b,c,d) ((uint32)(((uint32)(a)<<24) | ((uint32)(b)<<16) | ((uint32)(c)<<8) | (uint32)(d) ) )

#define IDATA_W1(a)       ((uint32)((uint32)(a)<<16))
#define IDATA_W2(a,b)     ((uint32)(((uint32)(a)<<16) | ((uint32)(b))))

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_INITIALIZERS_H */
