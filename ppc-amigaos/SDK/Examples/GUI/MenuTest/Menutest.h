//
// Copyright (c) 2006 Hyperion Entertainment VOF & Amiga, Inc.
//
// Copyright (c) 2010 Hyperion Entertainment CVBA. All rights reserved.
//
// Written by Philippe-André Bourdin, http://www.Bourdin.ch/Philippe/
//
// AmigaOS 4.x NewMenu Demonstration Application

// Global Includes

#include <stdio.h>
#include <stdlib.h>


// Namespace

using namespace std;


// GUI Defines

#define ContainerLayout HLayoutObject, \
			LAYOUT_DeferLayout, TRUE, \
			LAYOUT_SpaceInner, TRUE, \
			LAYOUT_SpaceOuter, FALSE, \
			LAYOUT_VertAlignment, LALIGN_CENTER

#define ContainerGroup  VLayoutObject, \
			LAYOUT_DeferLayout, TRUE, \
			LAYOUT_SpaceInner, TRUE, \
			LAYOUT_SpaceOuter, TRUE, \
			LAYOUT_VertAlignment, LALIGN_CENTER


// Gadget IDs

enum {

	GID_OK,

	MID_PROJECT,
	MID_PROJECT_ABOUT,
	MID_PROJECT_QUIT,
	MID_EDIT,
	MID_EDIT_UNDO,
	MID_VIEW,
	MID_VIEW_FUNCTIONS,
	MID_VIEW_NUMERIC,
	MID_VIEW_BASIC,
	MID_VIEW_EXTENDED,

	NUM_GADGETS
};


// Defines

#define ALL_REACTION_CLASSES
#define ALL_REACTION_MACROS

#define CATCOMP_NUMBERS
#define CATCOMP_ARRAY


// Catalog and Version

#include "Menutest_cd.h"
#include "Menutest_rev.h"

static CONST_STRPTR verionString USED = VERSTAG;
