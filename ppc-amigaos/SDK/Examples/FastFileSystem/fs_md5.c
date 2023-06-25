/*
 * $Id: fs_md5.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 *
 * Amiga ROM file system reimplementation
 * Copyright © 2001-2005 by Olaf Barthel
 * All Rights Reserved
 */

/****************************************************************************/

#include "fs_md5.h"

/****************************************************************************/

/* What follows is a home-grown implementation of the MD5 message digest
 * algorithm, devised by Ron L. Rivest, as defined in RFC1321. Unlike
 * most others, this implementation was not designed for maximum data
 * throughput, but for minimum implementation size.
 */

/****************************************************************************/

#define ROTATE_LEFT(value,distance) \
	(((value) << (distance)) | ((value) >> (32 - (distance))))

/****************************************************************************/

/* This routine implements the MD5 compression loop, which
 * packs 512 bits into 128 bits. Normally, this is done through
 * a long, long list of function invocations which implements
 * an unrolled version of the loop. What follows below is the
 * 'rolled' version, which takes advantage of the fact that
 * most of the time, the auxiliary functions stay the same
 * and only the number of positions by which the function
 * result is rotated changes.
 */
static void
md5_compress(struct md5_context * md5)
{
	static const ULONG T[64] =
	{
		0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
		0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
		0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
		0x6b901122,0xfd987193,0xa679438e,0x49b40821,

		0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,
		0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
		0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,
		0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,

		0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,
		0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
		0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
		0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,

		0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
		0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
		0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,
		0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
	};

	static const UBYTE k[64] =
	{
		0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
		0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
		0x01,0x06,0x0b,0x00,0x05,0x0a,0x0f,0x04,
		0x09,0x0e,0x03,0x08,0x0d,0x02,0x07,0x0c,
		0x05,0x08,0x0b,0x0e,0x01,0x04,0x07,0x0a,
		0x0d,0x00,0x03,0x06,0x09,0x0c,0x0f,0x02,
		0x00,0x07,0x0e,0x05,0x0c,0x03,0x0a,0x01,
		0x08,0x0f,0x06,0x0d,0x04,0x0b,0x02,0x09
	};

	static const UBYTE s[64] =
	{
		0x07,0x0c,0x11,0x16,0x07,0x0c,0x11,0x16,
		0x07,0x0c,0x11,0x16,0x07,0x0c,0x11,0x16,
		0x05,0x09,0x0e,0x14,0x05,0x09,0x0e,0x14,
		0x05,0x09,0x0e,0x14,0x05,0x09,0x0e,0x14,
		0x04,0x0b,0x10,0x17,0x04,0x0b,0x10,0x17,
		0x04,0x0b,0x10,0x17,0x04,0x0b,0x10,0x17,
		0x06,0x0a,0x0f,0x15,0x06,0x0a,0x0f,0x15,
		0x06,0x0a,0x0f,0x15,0x06,0x0a,0x0f,0x15
	};

	const ULONG * const X = md5->md5_X;
	ULONG A,B,C,D;
	ULONG v;
	LONG i;

	A = md5->md5_ABCD[0];
	B = md5->md5_ABCD[1];
	C = md5->md5_ABCD[2];
	D = md5->md5_ABCD[3];

	for(i = 0 ; i < 64 ; i++)
	{
		v = A + X[k[i]] + T[i];

		if(i < 16)
			v += (B & C) | (~B & D);
		else if (i < 32)
			v += (B & D) | (C & ~D);
		else if (i < 48)
			v += B ^ C ^ D;
		else
			v += C ^ (B | ~D);

		A = D;
		D = C;
		C = B;
		B = B + ROTATE_LEFT(v,s[i]);
	}

	md5->md5_ABCD[0] += A;
	md5->md5_ABCD[1] += B;
	md5->md5_ABCD[2] += C;
	md5->md5_ABCD[3] += D;
}

/****************************************************************************/

/* This primes the MD5 calculation. */
void
md5_init(struct md5_context * md5)
{
	/* The initial configuration of the four-word buffer. */
	md5->md5_ABCD[0] = 0x67452301;
	md5->md5_ABCD[1] = 0xefcdab89;
	md5->md5_ABCD[2] = 0x98badcfe;
	md5->md5_ABCD[3] = 0x10325476;

	md5->md5_NumBytesProcessed	= 0;
	md5->md5_NumBytesInBuffer	= 0;
}

/****************************************************************************/

/* This adds another byte to the MD5 buffer, and if the buffer is full,
 * updates the digest value.
 */
void
md5_update(struct md5_context * md5,UBYTE * data,LONG len)
{
	UBYTE * b = (UBYTE *)md5->md5_X;
	LONG num_bytes_in_buffer = md5->md5_NumBytesInBuffer;
	LONG x,y,i;

	for(i = 0 ; i < len ; i++)
	{
		x = num_bytes_in_buffer & 3;
		y = num_bytes_in_buffer & (~3);

		/* Add the data in little-endian order.
		 * This assumes that the md5_X[..] array is
		 * a table of long words.
		 */
		b[y | (3 - x)] = data[i];

		num_bytes_in_buffer++;
		if(num_bytes_in_buffer == 64)
		{
			md5_compress(md5);

			num_bytes_in_buffer = 0;
		}
	}

	md5->md5_NumBytesInBuffer = num_bytes_in_buffer;
	md5->md5_NumBytesProcessed += len;
}

/****************************************************************************/

/* This routine takes the data stuffed into the MD5 digest
 * buffer so far, adds a bit of padding and produces the
 * final 128 bit message digest value.
 */
void
md5_final(struct md5_context * md5,UBYTE * digest)
{
	LONG num_bits_processed_hi;
	LONG num_bits_processed_lo;
	LONG i,j,k;
	ULONG t;
	UBYTE c;

	/* Figure out how many bits we processed so far. */
	num_bits_processed_hi = md5->md5_NumBytesProcessed >> (32 - 3);
	num_bits_processed_lo = md5->md5_NumBytesProcessed << 3;

	/* Append a single '1' bit, followed by zero bits. */
	c = 0x80;
	md5_update(md5,&c,1);

	/* We need to add a few padding bytes to make sure that the
	 * buffer is just 64 bits short of being filled with 512
	 * bits of data.
	 */
	c = 0x00;
	while(md5->md5_NumBytesInBuffer != 56)
		md5_update(md5,&c,1);

	/* Now append the length of the message (in bits), as a 64 bit
	 * little endian number.
	 */
	for(i = 0 ; i < 4 ; i++)
	{
		c = (UBYTE)(num_bits_processed_lo & 0xFF);
		num_bits_processed_lo >>= 8;

		md5_update(md5,&c,1);
	}

	for(i = 0 ; i < 4 ; i++)
	{
		c = (UBYTE)(num_bits_processed_hi & 0xFF);
		num_bits_processed_hi >>= 8;

		md5_update(md5,&c,1);
	}

	/* And that's it. The last step involves copying the digest off
	 * the 64 bit table the compression routine filled in. The
	 * data must be stored in little endian order.
	 */
	for(i = 0, k = 0 ; i < 4 ; i++)
	{
		t = md5->md5_ABCD[i];

		for(j = 0 ; j < 4 ; j++, k++)
		{
			c = (UBYTE)(t & 0xFF);
			t >>= 8;

			digest[k] = c;
		}
	}
}
