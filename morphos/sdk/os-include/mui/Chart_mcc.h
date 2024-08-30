#ifndef CHART_MCC_H
#define CHART_MCC_H

/*
 *  Chart.mcc
 *
 *  Copyright © 2012-2013 Ilkka Lehtoranta
 *  All rights reserved.
 *
 *  $Id: Chart_mcc.h,v 1.9 2016/07/26 21:18:18 itix Exp $
 */

#ifndef _SYS_TYPES_H
#include <sys/types.h>
#endif

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define MUIC_Chart  "Chart.mcc"
#define ChartObject MUI_NewObject(MUIC_Chart

#define CHART_MCC_MBASE 0xfece1000
#define CHART_MCC_ABASE 0xfece2000

/*
 *   Methods
 */
#define MUIM_Chart_ClearGroup         (CHART_MCC_MBASE + 0)
#define MUIM_Chart_GetGroup           (CHART_MCC_MBASE + 1)
#define MUIM_Chart_InsertGroup        (CHART_MCC_MBASE + 2)
#define MUIM_Chart_GetMinMax          (CHART_MCC_MBASE + 3)
#define MUIM_Chart_RemoveGroup        (CHART_MCC_MBASE + 4)
#define MUIM_Chart_ReplaceInGroup     (CHART_MCC_MBASE + 5)
#define MUIM_Chart_SetMax             (CHART_MCC_MBASE + 6)

struct MUIP_Chart_ClearGroup
{
	size_t        MethodID;
	size_t        GroupNumber;
};

struct MUIP_Chart_GetGroup
{
	size_t        MethodID;
	size_t        GroupNumber;
	CONST_STRPTR *Label;
	CONST_APTR   *Values;
};

struct MUIP_Chart_InsertGroup
{
	size_t        MethodID;
	size_t        GroupNumber;
	CONST_STRPTR  Label;
	CONST_APTR    Values;
};

struct MUIP_Chart_GetMinMax
{
	size_t       MethodID;
	DOUBLE      *MinimumValue;
	DOUBLE      *MaximumValue;
};

struct MUIP_Chart_RemoveGroup
{
	size_t        MethodID;
	size_t        GroupNumber;
};

struct MUIP_Chart_ReplaceInGroup
{
	size_t       MethodID;
	size_t       GroupNumber;
	size_t       Index;
	size_t       Count;
	DOUBLE      *NewValue;
};

struct MUIP_Chart_SetMax
{
	size_t       MethodID;
	DOUBLE      *MaximumValue;
};

/*
 *   Attributes
 */
#define MUIA_Chart_Colors              (CHART_MCC_ABASE + 0) /* I.G CONST_STRPTR  */
#define MUIA_Chart_Count               (CHART_MCC_ABASE + 1) /* ..G size_t        */
#define MUIA_Chart_GroupSize           (CHART_MCC_ABASE + 2) /* ISG size_t        */
#define MUIA_Chart_InitialMinValue     (CHART_MCC_ABASE + 3) /* I.. DOUBLE *      */
#define MUIA_Chart_InitialMaxValue     (CHART_MCC_ABASE + 4) /* I.. DOUBLE *      */
#define MUIA_Chart_Unit                (CHART_MCC_ABASE + 5) /* I.G CONST_STRPTR  */
#define MUIA_Chart_Title               (CHART_MCC_ABASE + 6) /* I.G CONST_STRPTR  */
#define MUIA_Chart_Type                (CHART_MCC_ABASE + 7) /* I.. size_t        */


#endif /* CHART_MCC_H */
