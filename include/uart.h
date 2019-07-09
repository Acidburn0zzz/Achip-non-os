#ifndef __UART_H
#define __UART_H

#include <common.h>
#include <types.h>

#define UART_RESET	 (MOON0_REG->reset[0])
#define UART_CLKE	 (MOON0_REG->clken[0])
#define DMA_INT            		(31)
#define DMA_SW_RST_B			(7)
#define DMA_INIT				(6)
#define DMA_GO					(5)
#define DMA_TIMEOUT_INT_EN		(3)
#define DMA_AUTO_ENABLE			(4)
#define DMA_P_SAFE_DISABLE		(2)
#define DMA_ENABLE				(0)
#define UADMA_LENGTH			(128)
#define DMA_MSI_ID				(12)
#define UART_USE_POLLING_MODE	(0)
#define UART_USE_INT_MODE		(1)
#define UART_USE_DMA_MODE		(2)

#define DMA_SDMS_THRESHOLD_FIFO_OVFLOW	(24)
#define DMA_ISSUE_ST					(20)
#define DMA_C_DMA_RUNING				(19)
#define DMA_SDATABYTE_TIMEOUT 			(18)
#define DMA_SMON_DMA_FIFO_OVFLOW		(17)
#define DMA_SDMS_FIFO_OVFLOW			(16)
#define DMA_D_BYTES_BUF_VEC				(8)
#define DMA_S_UPDATE_DONE				(7)
#define DMA_P_ISSUE_MSI_DONE			(6)
#define DMA_SEND_TRANSACT				(5)
#define DMA_S_TIMOUT					(4)
#define DMA_DMA_STATE					(0)

extern int cmp_counter;

static inline int uart_strcmp(const char *str1, const char *str2)
{
	while(*str1 != '\0' && *str1++ == *str2++)
		;
	return (*(unsigned char *)str1) - (*(unsigned char *)str2);
}

static inline char *uart_strcpy(char *dest, const char *src)
{
	char *dest0 = dest;
	const char *src0 = src;

	while((*dest0++ = *src0++))
		;
	return dest;
}

UINT8 uartWriteByte(UINT8 id, unsigned char c);
UINT8 uartReadByte(UINT8 id, unsigned char *c);
size_t uartWriteBytes(UINT8 id, const unsigned char *buf, size_t len);
size_t uartReadBytes(UINT8 id, unsigned char *buf, size_t len);
void uartConfiguration();

void uartSender();
void uartReceiver();
void uart_tasklet(void);

#endif
