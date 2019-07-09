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
 * Description :  simple cbdma driver
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2018/06/28    nz.lu          initial version
 */
#include "common_all.h"
#include "cache.h"
#include "sp_interrupt.h"

#define RF_GRP(_grp, _reg) ((((_grp) * 32 + (_reg)) * 4) + REG_BASE)

#define CBDMA0_REG      ((volatile struct cbdma_regs *)RF_GRP(26, 0))
#define CBDMA1_REG      ((volatile struct cbdma_regs *)RF_GRP(27, 0))


void cbdma_memset(int id, void *dst, unsigned int pattern , unsigned length)
{
	printf("[CBDMA:%d]: Memset %d Bytes to address: 0x%08x, pattern:0x%08x\n", id, length, (unsigned) dst, pattern);
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;

	// clear all int status
	cbdma->int_status = 0x7f;
	// set memset mode
	cbdma->config = 0x00030000;
	// pattern
	cbdma->memset_value = pattern;
	// set write data length
	cbdma->dma_length = length;
	cbdma->src_adr = 0;
	cbdma->des_adr = (unsigned) dst;
}


void cbdma_memcpy(int id, void *dst, void *src, unsigned length)
{
	printf("[CBDMA:%d]: Copy %d KB from 0x%08x to 0x%08x\n", id, length>>10, (unsigned) src, (unsigned)dst);
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;

	// clear all int status
	cbdma->int_status = 0x7f;
	// set copy mode
	cbdma->config = 0x00030003;
	// set write data length
	cbdma->dma_length = length;
	// set write start address
	cbdma->src_adr = (unsigned) src;
	// set write end address
	cbdma->des_adr = (unsigned) dst;
}

void cbdma_kick_go(int id)
{
	printf("[CBDMA:%d]: Start\n", id);
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;

	cbdma->config |= 0x00000100;
}

unsigned int cbdma_get_interrupt_status(int id)
{
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;
	return cbdma->int_status;
}

void cbdma_clear_interrupt_status(int id)
{
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;
	cbdma->int_status = 0x7f;
}


void cbdma_enable_interrupt(int id, int enable)
{
	volatile struct cbdma_regs *cbdma;
	if (id)
		cbdma = CBDMA1_REG;
	else
		cbdma = CBDMA0_REG;

	cbdma->int_en = (enable == 0)?0:1;
}


void cbdma_interrupt_control_mask(int id, int enable)
{
	unsigned int int_num = (id == 0)?128:129;

	if (enable != 0) {
		hal_interrupt_acknowledge(int_num);
		hal_interrupt_unmask(int_num);
	} else {
		hal_interrupt_mask(int_num);
	}
}


void create_sequential_pattern(unsigned int *dst, unsigned int len)
{
	unsigned int *ptr = dst;
	unsigned int *end_ptr = (unsigned int *) ((unsigned int)dst + len);
	unsigned int pattern = 0;
	unsigned int err_cnt = 0;

	printf("[Create sequential pattern from 0x%08x, len=%d]: start.\n", (unsigned int)ptr, len);
	while (ptr < end_ptr)
		*ptr++ = pattern++;

	HAL_DCACHE_SYNC();
	printf("[Create sequential pattern]: done.\n");
}

unsigned int check_sequential_pattern(unsigned int *dst, unsigned int len)
{
	unsigned int *ptr = dst;
	unsigned int *end_ptr = (unsigned int *) ((unsigned int)dst + len);
	unsigned int pattern = 0;
	unsigned int err_cnt = 0;

	printf("[check sequential pattern from 0x%08x]: start.\n", (unsigned int)ptr);
	while (ptr < end_ptr) {
		if (*ptr != pattern) {
			err_cnt++;
			printf("[Err][%d] %d != %d\n", err_cnt, *ptr, pattern);
		}
		pattern++;
		ptr++;

		if (err_cnt > 20) {
			break;
		}
	}
	if (err_cnt == 0) {
		printf("\n[check sequential pattern]: Data Identity.\n");
	}
	printf("\n[check sequential pattern]: done.\n");

	return err_cnt;
}


// ===================== TEST ==============================

void cbdma0_isr_cfg()
{
	printf("[CFG] CBDMA0 ISR\n");
	cbdma_clear_interrupt_status(0);
	cbdma_enable_interrupt(0, 1);
	hal_interrupt_configure(128, 0, 1);
	// why
	hal_interrupt_acknowledge(128);
}

void cbdma1_isr_cfg()
{
	printf("[CFG] CBDMA1 ISR\n");
	cbdma_clear_interrupt_status(1);
	cbdma_enable_interrupt(1, 1);
	hal_interrupt_configure(129, 0, 1);
	// why
	hal_interrupt_acknowledge(128);
}


int g_cbmda_finished = 0;

void cbdma0_isr(void)
{
	hal_interrupt_acknowledge(128);

	printf("[CBDMA_%d]: Finished, status: 0x%x\n", 0, cbdma_get_interrupt_status(0));
	g_cbmda_finished = 1;

	cbdma_clear_interrupt_status(0);
}

void cbdma1_isr(void)
{
	hal_interrupt_acknowledge(129);
	printf("[CBDMA_%d]: Finished, status: 0x%x\n", 0, cbdma_get_interrupt_status(1));
	g_cbmda_finished = 1;

	cbdma_clear_interrupt_status(1);
}


void cbdma_test_init()
{
	static interrupt_operation cbdma_opt[2];

	memcpy(cbdma_opt[0].dev_name, "CBDMA0", strlen("CBDMA0"));
	cbdma_opt[0].vector = 128;
	cbdma_opt[0].device_config = cbdma0_isr_cfg;
	cbdma_opt[0].interrupt_handler = cbdma0_isr;
	interrupt_register(&cbdma_opt[0]);

	memcpy(cbdma_opt[1].dev_name, "CBDMA1", strlen("CBDMA1"));
	cbdma_opt[1].vector = 129;
	cbdma_opt[1].device_config = cbdma1_isr_cfg;
	cbdma_opt[1].interrupt_handler = cbdma1_isr;
	interrupt_register(&cbdma_opt[1]);

}


#define CBDMA_TEST_SOURCE      ((void *) 0x00400000)
#define CBDMA_TEST_DESTINATION ((void *) 0x00C00000)
// #define CBDMA_TEST_SIZE        (128 << 10)
#define CBDMA_TEST_SIZE        (8 << 20)


void cbdma_test()
{
	// create_sequential_pattern(CBDMA_TEST_SOURCE, CBDMA_TEST_SIZE);

	// cbdma 0 test
	cbdma_memcpy(0, CBDMA_TEST_DESTINATION, CBDMA_TEST_SOURCE, CBDMA_TEST_SIZE);


// polling
#if 0
	printf("[DBG] cbdma_get_interrupt_status(0) : 0x%08x\n", cbdma_get_interrupt_status(0));
	cbdma_enable_interrupt(0, 0);
	cbdma_kick_go(0);

	while(cbdma_get_interrupt_status(0) & 0x1 == 0)
		printf(".");
	printf("\n");

	printf("[DBG] cbdma_get_interrupt_status(0) : 0x%08x\n", cbdma_get_interrupt_status(0));
	cbdma_clear_interrupt_status(0);

#else
	g_cbmda_finished = 0;
	cbdma_interrupt_control_mask(0, 1);
	cbdma_kick_go(0);

	while(g_cbmda_finished == 0);
#endif

	// check_sequential_pattern(CBDMA_TEST_DESTINATION, CBDMA_TEST_SIZE);

	printf("CBDMA test finished.\n");
}














