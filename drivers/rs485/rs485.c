/********************************************************
 * Copyright (c) 2020 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co., Ltd.19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  rs485 for sp7021
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2020/03/05    tony.huang   initial version
 */

#include <emuio.h>
#include "common_all.h"

#ifdef RS485_TEST

#define Gpio_pin 0
void rs485_init(int TX_pin, int RX_pin)
{
    
	/* uart2 pinmux : x3,UA2_TX, X4,UA2_RX */
	TX_pin -= 7;
	RX_pin -= 7;
	MOON3_REG->sft_cfg[16] = RF_MASK_V((0x7f << 0), (TX_pin << 0));
	MOON3_REG->sft_cfg[16] = RF_MASK_V((0x7f << 8), (RX_pin << 8));
	MOON0_REG->reset[1] = RF_MASK_V_CLR(1 << 10); /* release UA2 */
	UART2_REG->div_l = UART_BAUD_DIV_L(BAUDRATE, UART_SRC_CLK);
	UART2_REG->div_h = UART_BAUD_DIV_H(BAUDRATE, UART_SRC_CLK);
	GP6_REG->sft_cfg[8] = RF_MASK_V((0x7f << 0), (1 << Gpio_pin)); 
}

void _RS485_write(int argc, char *argv[])
{
	char *cmd;	
	unsigned int value, cmd_len;
	DE_RE_High(Gpio_pin);	

	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
		UA2_printf("w: %s \n", cmd);
	}
	else {
		printf("help\n");
	}	
}

void _RS485_read(int argc, char *argv[])
{
	char *cmd;	
	unsigned int value, cmd_len;
	int c;
	DE_RE_Low(Gpio_pin);

	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
	}
				
	printf("Receive data: \n");
	while (1) {
		while (UART2_rx_rdy()) {
			c = UART2_getc();
			printf("%c \n",c);			
		}

		if (c == 'q')
			break;
	}		
}



#endif 
/**************************************************************************
 *             F U N C T I O N    I M P L E M E N T A T I O N S           *
 **************************************************************************/
