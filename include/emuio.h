#ifndef _EMUIO_H_
#define _EMUIO_H_

extern int psprintf(char *dest, const char *format, ...);
extern void io_write_wait(const char *s);

char linebuf[300];

#define dbg_info()	_dbg_info(__FILE__, __LINE__)
#define dbg()		_dbg_info(__FILE__, __LINE__)
#define dbg_stamp(value) //{ *(volatile unsigned int *)RF_GRP(0, 0) = (unsigned int)(value); }

#define UART_LSR_TX_RDY     (1 << 0)
#define UART_LSR_RX_RDY     (1 << 1)
#define UART_TX_EMPTY       (1 << 6)

// UART0
#define UART0_tx_rdy()          (UART0_REG->lsr& UART_LSR_TX_RDY)
#define UART0_rx_rdy()          (UART0_REG->lsr & UART_LSR_RX_RDY)
#define UART0_tx_empty()        (UART0_REG->lsr & UART_TX_EMPTY)
#define UART0_putc_nw(c)       (UART0_REG->dr = (c))
#define UART0_getc()                    (UART0_REG->dr)

#define UART0_wait()            do { while (!UART0_tx_rdy()) ;} while (0)
#define UART0_flush()           do { while (!UART0_tx_empty()) ;} while (0)
#define UART0_putc(c)           do { UART0_wait(); UART0_putc_nw(c); } while (0)
#define UART0_putc_nl(c)        do { UART0_putc(c); if (c == 0x0a) UART0_putc(0x0d);} while (0)
#define UART0_puts(s)           do {                            \
	int __c;                    \
	const char *__s = (const char *)(s); \
	while ((__c = *__s++))        \
	        {                           \
	                UART0_putc_nl(__c);     \
		}                           \
		} while (0)
//UART0
#define printf(s...) \
	do { psprintf(linebuf, ## s); io_write_wait(linebuf); } while (0)


#endif /* _EMUIO_H_ */
