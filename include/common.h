#include <regmap.h>
#include <config.h>

void prn_string(char *);
void prn_byte(unsigned char);
void prn_dword(unsigned int);
void prn_decimal(unsigned int);
void prn_dump_buffer(unsigned char *buf, int len);

#define dbg_stamp(value) //{ *(volatile unsigned int *)RF_GRP(0, 0) = (unsigned int)(value); }

#if 0

#define dbg()				\
	do {						\
		prn_string("[DBG] ");	\
		prn_string(__FILE__);	\
		prn_string(" :");		\
		prn_decimal(__LINE__);	\
		prn_string("\n");		\
	} while (0)

#endif

#define uart0_nl()			\
	uart0_putc(0x0D);		\
	uart0_putc(0x0A);

extern void uart0_wait(void);
extern void uart0_putc(unsigned char c);

#define PRINTF uart_printf
extern void uart_printf( const char *ctrl1, ...);

