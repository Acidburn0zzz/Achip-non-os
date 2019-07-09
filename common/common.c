/**************************************************************************
*                    I N C L U D E   F I L E S                            *
 **************************************************************************/
#include <types.h>
#include <regmap.h>


void uart0_wait(void)
{
        unsigned int lsr = 0;

        while (!lsr) {
                lsr = UART0_REG->lsr;
                lsr &= 1;
        }
}

void uart0_putc(unsigned char c)
{
        uart0_wait();
        UART0_REG->dr = c;
}

//----------------------------------------------------------------------------
int memcmp(UINT8 *s1, UINT8 *s2, int n)
{
	int ret = 0;
	UINT8 *s1_end = s1 + n;

	while(s1 != s1_end) {
		if (*s1++ != *s2++)
			ret = 1;
	}

	return ret;
}

void *memset(UINT8 *s1, int c, int n)
{
	UINT8 *s1_end = s1 + n;

	while (s1 != s1_end)
		*s1++ = c;

	return s1;
}

void *memcpy(UINT8 *s1, const UINT8 *s2, int n)
{
	UINT8 *s1_end = s1 + n;

	while(s1 != s1_end)
		*s1++ = *s2++;

	return s1;
}

int strlen(const char * str)
{
	const char *start = str;
	while (*str) str++;
	return str - start;
}