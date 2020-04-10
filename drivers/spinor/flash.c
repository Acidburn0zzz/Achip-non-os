/********************************************************
 * Copyright (c) 2018 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co. 19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  nonos spi nor function
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2020/03/13    chingchouhuang   initial version
 */
#include <stdarg.h>
#include <string.h>
#include <common_all.h>
#include "drivers/sp_spi_nor.h"

void FlashErase(unsigned long para1, unsigned long para2, unsigned long para3)
{
	unsigned int i, j; 

	memset(data_pool, 0, SPI_DATA64_MAX_LEN);
	j = para2 / 0x1000;
	sp_spi_nor_claim_bus(50000000);
	for (i = 0; i < j; i++)
	{
		data_pool[0] = 0x6;
		sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_ONCE);
	
		data_pool[0] = 0x20;
		sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_BEGIN);
		diag_printf("i 0x%x\n", i);
		para1 += (i * 0x1000);
		data_pool[0] = para1 >> 16;
		data_pool[1] = para1 >> 8;
		data_pool[2] = para1;
		sp_spi_nor_xfer(0x18, data_pool, NULL, SPI_XFER_END);
	
		data_pool[0] = 0x5;
		sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_BEGIN);
		sp_spi_nor_xfer(8, NULL, data_pool, SPI_XFER_END);
	}
	data_pool[0] = 0x4;
	sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_ONCE);
	diag_printf("erase end\n");
}

void FlashRead(unsigned long para1, unsigned long para2, unsigned long para3)
{
	memset(data_pool, 0, SPI_DATA64_MAX_LEN);		
	data_pool[1] = para2 >> 16;
	data_pool[2] = para2 >> 8;
	data_pool[3] = para2;
	data_pool[0] = 0xb;
	sp_spi_nor_claim_bus(50000000);
	sp_spi_nor_xfer(40, data_pool, NULL, SPI_XFER_BEGIN);
	sp_spi_nor_xfer(para3 * 8, NULL, (void *) para1, SPI_XFER_END);
	diag_printf("read end\n");
	//data_pool = para1;
	//prinf("%x %x %x %x\n", data_pool[0], data_pool[1], data_pool[2], data_pool[3]);	
}

void FlashWrite(unsigned long para1, unsigned long para2, unsigned long para3)
{	
	data_pool[0] = 0x6;
	sp_spi_nor_claim_bus(50000000);
	sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_ONCE);

	data_pool[0] = 0x2;
	data_pool[1] = para2 >> 16;
	data_pool[2] = para2 >> 8;
	data_pool[3] = para2;
	sp_spi_nor_xfer(32, data_pool, NULL, SPI_XFER_BEGIN);	
	sp_spi_nor_xfer(para3 * 8, (void *) para1, NULL, SPI_XFER_END);

	data_pool[0] = 0x5;
	sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_BEGIN);
	sp_spi_nor_xfer(8, NULL, data_pool, SPI_XFER_END);	
	diag_printf("write end\n");
}

void Flash_Init(void)
{	
	sp_spi_nor_init();
}
void FlashCommand(int argc, char *argv[])
{
	char *cmd;
	unsigned int cmd_len, i, j; 
	unsigned long para1, para2, para3;
        
	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
		mon_readhex(argv[1], &para1);
		mon_readhex(argv[2], &para2);
		mon_readhex(argv[3], &para3);

		diag_printf("argc 0x%x , cmd %s\n", argc, cmd);
		diag_printf("argv[1] %s , argv[2] %s, argv[3] %s\n", argv[1], argv[2], argv[3]);
		diag_printf("para1 0x%x, para2 0x%x, para3 0x%x\n", para1, para2, para3);
	
		if (_strncmp(cmd, "-i", cmd_len) == 0) {
			diag_printf("init\n");
			Flash_Init();
		} else if (_strncmp(cmd, "-e", cmd_len) == 0) {
			diag_printf("erase\n");
			FlashErase(para1, para2, para3);
		} else if (_strncmp(cmd, "-r", cmd_len) == 0) {
			diag_printf("read\n");
			FlashRead(para1, para2, para3);
		} else if (_strncmp(cmd, "-w", cmd_len) == 0) {
			diag_printf("write\n");
			FlashWrite(para1, para2, para3);
		} else
			printf("-i:init\n-e:erase, -e offset len\n-r:read,  -r memaddr offset len\n-w:write, -w memaddr offset len\n");
	} else {
		printf("-i:init\n-e:erase, -e offset len\n-r:read,  -r memaddr offset len\n-w:write, -w memaddr offset len\n");
	}
}

void FlashDelay(int iCnt)
{
	#if 0
    while (iCnt--)
    {
        asm volatile ("  \
        .set noreorder;  \
        li $2, 32;  \
    1:  addiu $2, -1;  \
        nop;   \
        bnez $2, 1b; \
        nop;   \
        .set reorder  \
        " : : : "$2");
    }
    	#endif
}


