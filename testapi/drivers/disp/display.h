#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define ALIGNED(x, n)			((x) & (~(n - 1)))
#define DISP_ALIGN(x, n)		(((x) + ((n)-1)) & ~((n)-1))
#define EXTENDED_ALIGNED(x, n)	(((x) + ((n) - 1)) & (~(n - 1)))

#define SWAP32(x)	((((UINT32)(x)) & 0x000000ff) << 24 \
					| (((UINT32)(x)) & 0x0000ff00) << 8 \
					| (((UINT32)(x)) & 0x00ff0000) >> 8 \
					| (((UINT32)(x)) & 0xff000000) >> 24)
#define SWAP16(x)	(((x) & 0x00ff) << 8 | ((x) >> 8))

//#define FETCH_OFF
#define DDFCH_FETCH_EN
//#define OSD0_FETCH_EN

#endif	//__DISPLAY_H__

