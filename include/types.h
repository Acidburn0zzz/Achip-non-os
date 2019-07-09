#ifndef __TYPE_H__
#define __TYPE_H__



typedef unsigned long long  u64;
typedef unsigned int        u32;
typedef unsigned short      u16;
typedef unsigned char       u8;
typedef unsigned char       u08;

typedef long long           s64;
typedef int                 s32;
typedef short               s16;
typedef signed char         s8;

typedef unsigned char		BYTE;
typedef unsigned short		WORD;
typedef unsigned long		DWORD;

typedef unsigned long long 	UINT64;
typedef unsigned int   		UINT32;
typedef unsigned short 		UINT16;
typedef unsigned char 		UINT8;

typedef long long 			INT64;
typedef int   				INT32;
typedef short 				INT16;
typedef signed char			INT8;

typedef int					SINT32;
typedef short               SINT16;
typedef char                SINT8;

#define PASS 				0
#define PASS2				1
#define FAIL				2
#define SUCCESS			3
#define WAIT_FLAG_FAIL	4
#define PACKAGE_216	5
#define PACKAGE_216_PIN	6
#define BY_PASS_TEST	7
#define ROM_SUCCESS         PASS
#define ROM_FAIL           	FAIL

#define DEV_READ            2
#define DEV_WRITE           3

typedef UINT32				FOURCC;

//extern void *memcpy(UINT8 *s1, UINT8 *s2, int n);
extern void *memcpy16(UINT16 *s1, UINT16 *s2, int n);
extern void *memcpy32(UINT32 *s1, UINT32 *s2, int n);
extern void *memcpy128(UINT32 *s1, UINT32 *s2, int n);
// extern int memcmp(UINT8 *s1, UINT8 *s2, int n);
// extern void *memset(UINT8 *s1, int c, int n);

/*
#define prn_byte(b)
#define prn_dword(w)
#define prn_decimal(num)
#define prn_string(str)
#define prn_dump_buffer(buf, len)
#define wait_prn()
*/

#define fastcpy(dst, src, len) memcpy(dst, src, len)

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL    ((void *)0)
#endif

#endif // __TYPES_H__

