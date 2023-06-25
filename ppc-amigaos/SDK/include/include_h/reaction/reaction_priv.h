#ifndef REACTION_REACTION_PRIV_H
#define REACTION_REACTION_PRIV_H
/*
**    $VER: reaction_priv.h 54.16 (22.08.2022)
**
**    reaction class private definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/**************************************************************************/

/* This helps decide if a given backfill hook is to be installed or not */

#define BACKFILL_OK(rp,hook) ((rp)->Layer && \
                              ((hook) != (rp)->Layer->BackFill) && \
                              (((hook) == LAYERS_BACKFILL) || \
                               ((hook) > (struct Hook *)2)))

/**************************************************************************/

#endif /* REACTION_REACTION_PRIV_H */
