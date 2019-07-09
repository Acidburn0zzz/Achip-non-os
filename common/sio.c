/*******************************************************************************

Copyright (c) 2012 Sunplus technology co. Ltd.All right reserved!

********************************************************************************
File Name        	: 	Monitor.c
Version          	:               release 0.1
Author           	:	henry.liou
Created          	:	2015.11.3
Last Modified    	:
Description      	:  
public functions 	:

History Information Description
Date				Author				Modification
2015.11.3          henry.liou           	Created function     
*******************************************************************************/
/*---------------------------------------------------------------------------*
*                   	 INCLUDE   DECLARATIONS 		                            *
*---------------------------------------------------------------------------*/
#include "common_all.h"
#include <stdarg.h> 

/*---------------------------------------------------------------------------*
*                            EXTERNAL   REFERENCES                                                                *
*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
*	              MACRO	 DECLARATIONS                                                       *
*---------------------------------------------------------------------------*/
#define CONVERT_SIGN            (1 << 0)
#define CONVERT_SIGN_FORCED     (1 << 1)
#define CONVERT_LONG            (1 << 2)
#define CONVERT_LONGLONG        (1 << 3)
#define CONVERT_LEADING_ZERO    (1 << 4)
#define CONVERT_LEFT_ADJUST     (1 << 5)
#define CONVERT_START           (1 << 15)

typedef union
{
    INT64 i64;
    INT32 i32;
    UINT64 u64;
    UINT32 u32;
} t_num;
/*---------------------------------------------------------------------------*
*                                GLOBAL   VARIABLES 	                                                             *
*---------------------------------------------------------------------------*/
const  char radix_table[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*---------------------------------------------------------------------------*
*                               FUNCTION   DECLARATIONS                                                        *
*---------------------------------------------------------------------------*/
void io_write_wait(const char *s)
{
	int c;

	while ((c = *s++) != 0)
	{
		UART0_putc(c);
		if (c == 10) UART0_putc(13);
	}
}

static char    *__ltoa16__(char *dest, t_num *X, unsigned conversion, int width)
{
    int size = 0;
    char  *src, *src2;
    char c;

    /* check long */
    if (conversion & CONVERT_LONGLONG)
    {
        UINT64 num = X->u64;
        /* conversion sign */
        if (conversion & CONVERT_SIGN)
        {
            if (((INT64)num) < 0)
            {
                num = (UINT64)(-(INT64)num);
                *dest++ = '-';
                size++;
            }
        }
        /* generating bytes. */
        src = dest;

        do
        {
            int frac;
            frac     = (int)(num & 0x0f);
            num      = num >> 4;
            src2     = dest;
            *dest++  = radix_table [frac];
            size++;
        }
        while (num);
    }
    else
    {
        UINT32 num = X->u32;
        /* conversion sign */
        if (conversion & CONVERT_SIGN)
        {
            if (((INT32)num) < 0)
            {
                num = (UINT32)(-(INT32)num);
                *dest++ = '-';
                size++;
            }
        }
        /* generating bytes. */
        src = dest;

        do
        {
            int frac;
            frac     = (int)(num & 0x0f);
            num      = num >> 4;
            src2     = dest;
            *dest++  = radix_table [frac];
            size++;
        }
        while (num);
    }

    /* Now fill leadings (or trailing) ZEROs or SPACEs */
    c = (conversion & CONVERT_LEADING_ZERO) ? '0' : ' ';

    while (width > size)
    {
        if ((conversion & CONVERT_LEFT_ADJUST) == 0)
            src2 = dest;
        *dest++ = c;
        size++;
    }

    /* reverse bytes */
    while (src < src2)
    {
        c     = *src2;
        *src2 = *src;
        *src  = c;
        src++;
        src2--;
    }

    return dest;
}

static char    *__ltoa__(char *dest, t_num *X, unsigned base, int conversion, int width)
{
    int size = 0;
    char  *src, *src2;
    char c;

    /* check long */
    if (conversion & CONVERT_LONGLONG)
    {
        UINT64 num = X->u64;
        /* conversion sign */
        if (conversion & CONVERT_SIGN)
        {
            if (((INT64)num) < 0)
            {
                num = (UINT64)(-(INT64)num);
                *dest++ = '-';
                size++;
            }
        }
        /* generating bytes. */
        src = dest;

        do
        {
            int frac;
            frac     = ((UINT32)num) % base;
            num      = ((UINT32)num)/ base;
            src2     = dest;
            *dest++  = radix_table [frac];
            size++;
        }
        while (num);
    }
    else
    {
        UINT32 num = X->u32;
        /* conversion sign */
        if (conversion & CONVERT_SIGN)
        {
            if (((INT32)num) < 0)
            {
                num = (UINT32)(-(INT32)num);
                *dest++ = '-';
                size++;
            }
        }
        /* generating bytes. */
        src = dest;

        do
        {
            int frac;
            frac     = num % base;
            num      = num / base;
            src2     = dest;
            *dest++  = radix_table [frac];
            size++;
        }
        while (num);
    }

    /* Now fill leadings (or trailing) ZEROs or SPACEs */
    c = ((conversion & (CONVERT_LEADING_ZERO | CONVERT_LEFT_ADJUST)) == CONVERT_LEADING_ZERO) ? '0' : ' ';

    while (width > size)
    {
        if ((conversion & CONVERT_LEFT_ADJUST) == 0)
            src2    = dest;
        *dest++ = c;
        size++;
    }

    /* reverse bytes */
    while (src < src2)
    {
        c     = *src2;
        *src2 = *src;
        *src  = c;
        src++;
        src2--;
    }

    return dest;
}

int vprintf1(char *dest, const char *format, va_list ap)
{
    int width           = 0;
    unsigned conversion      = 0;

    while (1)
    {
        int c = *format++;
        *dest = c;
        if (c == '\0') break;
        if (conversion & CONVERT_START)
        {
            if (c >= '0' && c <= '9')
            {
                width = width * 10 + (c - '0');
                if (width == 0)
                    conversion |= CONVERT_LEADING_ZERO;
            }
            else if (c == 'l')
            {
                if (conversion & CONVERT_LONG) conversion |= CONVERT_LONGLONG;
                conversion |= CONVERT_LONG;
            }
            else if (c == '+')
            {
                conversion |= CONVERT_SIGN_FORCED;
            }
            else if (c == '-')
            {
                conversion = (conversion & (~CONVERT_LEADING_ZERO)) | CONVERT_LEFT_ADJUST;
            }
            else if (c == '%')
            {
                *dest++ = '%';
            }
            else if (c == 'b')
            {
                //terry,2003/3/4 11:50AM,for 51 dbg code
            }
            else
            {
                t_num X;
				
                if (conversion & CONVERT_LONGLONG)
                    X.u64 = va_arg(ap, UINT64);
                else
                    X.u32 = va_arg(ap, UINT32);
					
                switch (c)
                {
                    case 'd':
                        conversion |= CONVERT_SIGN;     // fall to 'u'

                    case 'u':
                        dest = __ltoa__(dest, &X, 10, conversion, width);
                        break;

                    case 'y':
                        conversion |= CONVERT_SIGN;     // fall to 'x'

                    case 'x':
                        dest = __ltoa16__(dest, &X, conversion, width);
                        break;

                    case 's':
                    {
                        char *src = (char *)X.u32;

                        while (*src)
                            *dest++ = *src++;
                    }
                    break;

                    case 'c':
                        *dest++ = (char) X.u32;
                        break;
                }

                /* conversion finished */
                conversion = 0;
            }
        }
        else if (c == '%')
        {
            conversion        = CONVERT_START;
            width             = 0;
        }
        else
        {
            dest++;
        }
    }

    return 0;
}

int psprintf(char *dest, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    vprintf1(dest, format, ap);
    va_end(ap);

    return 0;
}

