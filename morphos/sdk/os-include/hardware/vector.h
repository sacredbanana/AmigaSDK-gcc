#ifndef HARDWARE_VECTOR_H
#define HARDWARE_VECTOR_H

/*
	useful macros for AltiVec(tm) programming

	Copyright © 2004 The MorphOS Development Team, All Rights Reserved.
*/


/*
 * Macro for creating a vector value assignment (for compiler abstraction).
 *
 *  vector float foo = (vector float)VEC_VALUE(1.0, 2.0, 3.0, 4.0);
 *
 */

#if (__GNUC__ == 2)
# define VEC_VALUE(...) (__VA_ARGS__)
#else
# define VEC_VALUE(...) {__VA_ARGS__}
#endif


/*
 * Macro for creating magic value to describe datastreaming blocks.
 *
 *  vec_dst[st][t](<addr>, VEC_DST_BLOCKS(<size>, <num>, <stride>), <streamid>);
 *
 *   <size>   - Size of blocks to stream, will be rounded to multiple of 16 and cropped at 512 (496 (0 == 512)).
 *   <num>    - Number of blocks to stream, will be cropped at 256 (255 (0 == 256)).
 *   <stride> - Blockstride, should be >= blocksize (can be negative for reverse stride), *you* must crop at (-)32768 (+32767 (0 == +32768)).
 *
 */

#define VEC_DST_BLOCKS(size,num,stride) (((((size) + 15) & 0x1F0) << 20) | (((num) & 0xFF) << 16) | (unsigned short)((signed short)(stride)))


#endif /* HARDWARE_VECTOR_H */
