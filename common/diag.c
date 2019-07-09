/**************************************************************************
*                    I N C L U D E   F I L E S                            *
 **************************************************************************/
#include <common.h>

/**************************************************************************
 *                   G E N E R A L    C O N S T A N T S                   *
 **************************************************************************/
#define UART_put_byte(x) uart0_putc(x)

unsigned int mp = 0;

//----------------------------------------------------------------------------
void prn_string(char *str)
{
        if (mp) {
                return;
        }	
	
    while(*str) {
        if (*str == '\n')
            UART_put_byte('\r');
        UART_put_byte(*str);
        str++;
    }
}

//----------------------------------------------------------------------------
void prn_byte(unsigned char b)
{
	char c;
        if (mp) {
                return;
        }	
	
	UART_put_byte('0');
	UART_put_byte('x');
	c = (b >> 4);
	if(c < 0xA) UART_put_byte(c + 0x30);
	else		UART_put_byte(c + 0x37);
	c = (b & 0xF);
	if(c < 0xA) UART_put_byte(c + 0x30);
	else		UART_put_byte(c + 0x37);
	//UART_put_byte(' ');
	UART_put_byte(',');
}

//----------------------------------------------------------------------------
void prn_byten(unsigned char *b)
{
	char c;
        if (mp) {
                return;
        }
        	
	UART_put_byte('0');
	UART_put_byte('x');
	c = (*b >> 4);
	if(c < 0xA) UART_put_byte(c + 0x30);
	else		UART_put_byte(c + 0x37);
	c = (*b & 0xF);
	if(c < 0xA) UART_put_byte(c + 0x30);
	else		UART_put_byte(c + 0x37);
	//UART_put_byte(' ');
	UART_put_byte(',');

	UART_put_byte('\n');
	UART_put_byte('\r');
}

//----------------------------------------------------------------------------
void prn_dword(unsigned int w)
{
	char c, i;
        if (mp) {
                return;
        }	
	
	UART_put_byte('0');
	UART_put_byte('x');
	for(i=1; i<=8; i++) {
		c = (w >> (32 - (i<<2)) ) & 0xF;
		if(c < 0xA) UART_put_byte(c + 0x30);
		else		UART_put_byte(c + 0x37);
	}
	UART_put_byte('\n');
	UART_put_byte('\r');
}

//----------------------------------------------------------------------------
void prn_decimal(unsigned int num)
{
    char a[16];
    int  i = 0;

        if (mp) {
                return;
        }

    do {
        a[i] = num % 10;
        num /= 10;
        i++;
    } while (num);

    while(i > 0) {
        UART_put_byte(a[i-1] + 0x30);
        i--;
    }
    UART_put_byte(' ');
}

//----------------------------------------------------------------------------
void prn_dump_buffer(unsigned char *buf, int len)
{
    int i;

        if (mp) {
                return;
        }

    prn_dword(len);
    for (i = 0; i < len; i++)
    {
        prn_byte(buf[i]);

        if (i % 16 == 15)
        {
           prn_string("\n");
        }
    }
    prn_string("\n");
}

