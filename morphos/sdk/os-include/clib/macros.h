#ifndef CLIB_MACROS_H
#define CLIB_MACROS_H

/*
	MIN, MAX and ABS macros

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#if defined(__GNUC__)

#define MIN(a,b)          \
  ({typeof(a) _a = (a);   \
    typeof(b) _b = (b);   \
    _a < _b ? _a : _b; })

#define MAX(a,b)          \
  ({typeof(a) _a = (a);   \
    typeof(b) _b = (b);   \
    _a > _b ? _a : _b; })

#define ABS(a)            \
  ({typeof(a) _a = (a);   \
    _a < 0 ? -_a : _a; })

#else /* defined(__GNUC__) */

#if defined(__cplusplus)

#define MIN(a,b)    min(a,b)
#define MAX(a,b)    max(a,b)

#else /* defined(__cplusplus) */

#warning MIN and MAX macros have side-effects
#define MIN(a,b)    ((a)<(b)?(a):(b))
#define MAX(a,b)    ((a)>(b)?(a):(b))

#endif /* defined(__cplusplus) */

#warning ABS macro has side-effects
#define ABS(x)      ((x<0)?(-(x)):(x))

#endif /* defined(__GNUC__) */

#endif /* CLIB_MACROS_H */
