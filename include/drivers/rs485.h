
#ifndef __RS485_H__
#define __RS485_H__

#ifdef RS485_TEST
#define XTAL_CLK               (27 * 1000 * 1000)
#define UART_SRC_CLK        (XTAL_CLK)
/*
 * X = ((sclk + baud/2) / baud)
 * DIV_H = X  >> 12
 * DIV_L = (X & 0xf) << 12 | ((X >> 4) & 0xff - 1)
 */
#define UART_BAUD_DIV_H(baud, sclk)     ((((sclk) + ((baud) / 2)) / (baud)) >> 12)
#define UART_BAUD_DIV_L(baud, sclk)     ((((((sclk) + ((baud) / 2)) / (baud)) & 0xf) << 12) | \
					 ((((((sclk) + ((baud) / 2)) / (baud)) >> 4) & 0xff) - 1))
#define BAUDRATE            115200

// UART2
#define UA2_REG            UART2_REG
#define UART2_tx_rdy()       (UA2_REG->lsr & UART_LSR_TX_RDY)
#define UART2_rx_rdy()       (UA2_REG->lsr & UART_LSR_RX_RDY)
#define UART2_tx_empty()     (UA2_REG->lsr & UART_TX_EMPTY)
#define UART2_putc_nw(c)     (UA2_REG->dr = (c))
#define UART2_getc()         (UA2_REG->dr)
	
#define UART2_wait()         do { while (!UART2_tx_rdy()) ;} while (0)
#define UART2_flush()        do { while (!UART2_tx_empty()) ;} while (0)
#define UART2_putc(c)        do { UART2_wait(); UART2_putc_nw(c); } while (0)
#define UART2_putc_nl(c)     do { UART2_putc(c); if (c == 0x0a) UART2_putc(0x0d);} while (0)
#define UART2_puts(s) \
	do { \
		int __c; \
		const char *__s = (const char *)(s); \
		while ((__c = *__s++)) { \
			UART2_putc_nl(__c); \
		} \
	} while (0)
	
#define UA2_printf(s...) \
		do { psprintf(linebuf, ## s); UART2_puts(linebuf); } while (0)




#endif


