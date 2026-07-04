/****************************************************************************/
/* Clock.mcc (c) Copyright 2002-2004 by Michal Rybinski                     */
/* Registered MUI class, Serial Num: fecd                                   */
/****************************************************************************/

#ifndef MUI_Clock_MCC_H
#define MUI_Clock_MCC_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif



#define MUIC_Clock "Clock.mcc"
#define ClockObject MUI_NewObject(MUIC_Clock


/* Attributes */

#define	MUIA_Clock_Hour                    0xfecd0030 /* GM gs. LONG  */
#define	MUIA_Clock_Minute                  0xfecd0031 /* GM gs. LONG  */
#define	MUIA_Clock_Second                  0xfecd0032 /* GM gs. LONG  */
/* set a MUIV_Everytime notification to hear about a wrap to next day (hour = 0) */
#define MUIA_Clock_Wrapped                 0xfecd0033 /* GM g.. BOOL  */

/* Methods */

#define MUIM_Clock_OffsetFromTime          0xfecd0070 /* GM */
struct  MUIP_Clock_OffsetFromTime          { ULONG MethodID; LONG hour; LONG min; LONG sec; };

#endif /* MUI_Clock_MCC_H */
