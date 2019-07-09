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

#ifndef __CBDMA_H__
#define __CBDMA_H__


/**
 * id: [0, 1]
 */

void cbdma_memset(int id, void *dst, unsigned int pattern , unsigned length);
void cbdma_memcpy(int id, void *dst, void *src, unsigned length);
void cbdma_kick_go(int id);

unsigned int cbdma_get_interrupt_status(int id);
void cbdma_clear_interrupt_status(int id);

void cbdma_enable_interrupt(int id, int enable);
void cbdma_interrupt_control_mask(int id, int enable);

unsigned int check_sequential_pattern(unsigned int *dst, unsigned int len);
// for self testing

void cbdma_test_init();
// mon cbdma
void cbdma_test();

extern int g_cbmda_finished;
#endif // __CBDMA_H__
